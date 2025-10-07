.set LOCALID_GRUNT, 3
.set LOCALID_DEVON_EMPLOYEE, 4
.set LOCALID_CELEBI, 17
.set LOCALID_OLD_MAN, 15
.set LOCALID_DUSCLOPS, 16

PetalburgWoods_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PetalburgWoods_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

PetalburgWoods_OnTransition::
	callnative SetTimeBasedEncounters
	goto_if_unset FLAG_EXTRA_LEGENDARIES, PetalburgWoods_SwitchToOld
	call_if_unset FLAG_SYS_GAME_CLEAR, PetalburgWoods_NoCelebiEvent
	call_if_set FLAG_SYS_GAME_CLEAR, PetalburgWoods_YesCelebiEvent
	end

PetalburgWoods_SwitchToOld::
	setmaplayoutindex LAYOUT_PETALBURG_WOODS_OLD
	setflag FLAG_OLD_MAN_AND_DUSCLOPS
	removeobject LOCALID_OLD_MAN
	removeobject LOCALID_DUSCLOPS
	return
	end

PetalburgWoods_NoCelebiEvent::
	checkflag FLAG_GARBAGEFLAG
	call_if_unset FLAG_GARBAGEFLAG, PetalburgWoods_CelebiEvent_End
	end

PetalburgWoods_YesCelebiEvent::
	checkflag FLAG_DEFEATEDCELEBI
	call_if_set FLAG_DEFEATEDCELEBI, PetalburgWoods_CelebiEvent_End
	call_if_unset FLAG_DEFEATEDCELEBI, PetalburgWoods_YesCelebiEvent2
	end

PetalburgWoods_YesCelebiEvent2::
	setflag FLAG_GARBAGEFLAG
	end

PetalburgWoods_CelebiEvent::
	lock
	playse SE_SUDOWOODO_SHAKE
	waitse
	msgbox Text_PetalburgWoods_Celebi0, MSGBOX_SIGN
	closemessage
	checkflag FLAG_GARBAGEFLAG
	call_if_unset FLAG_GARBAGEFLAG, PetalburgWoods_CelebiEvent_End
	call_if_set FLAG_GARBAGEFLAG, PetalburgWoods_CelebiEventGo
	end

PetalburgWoods_CelebiEventGo::
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PetalburgWoods_Celebi1
	waitmovement 0
	msgbox Text_PetalburgWoods_Celebi1, MSGBOX_SIGN
	special ChoosePartyMon
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, PetalburgWoods_CelebiEvent_End
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_RAIKOU, PetalburgWoods_CelebiEvent_Continue1
	msgbox Text_PetalburgWoods_Celebi_Donthave, MSGBOX_SIGN
	end

PetalburgWoods_CelebiEvent_Continue1::
	msgbox Text_PetalburgWoods_Celebi2, MSGBOX_SIGN
	special ChoosePartyMon
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, PetalburgWoods_CelebiEvent_End
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_ENTEI, PetalburgWoods_CelebiEvent_Continue2
	msgbox Text_PetalburgWoods_Celebi_Donthave, MSGBOX_SIGN
	end

PetalburgWoods_CelebiEvent_Continue2::
	msgbox Text_PetalburgWoods_Celebi3, MSGBOX_SIGN
	special ChoosePartyMon
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, PetalburgWoods_CelebiEvent_End
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_SUICUNE, PetalburgWoods_CelebiBattle
	msgbox Text_PetalburgWoods_Celebi_Donthave, MSGBOX_SIGN
	end

PetalburgWoods_CelebiEvent_End::
	releaseall
	end

PetalburgWoods_CelebiBattle::
	faceplayer
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PetalburgWoods_Celebi1
	waitmovement 0
	msgbox Text_PetalburgWoods_Celebi4, MSGBOX_DEFAULT
	setwildbattle SPECIES_CELEBI, 50
	waitse
	playmoncry SPECIES_CELEBI, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	applymovement LOCALID_CELEBI, PetalburgWoods_EventScript_CelebiMoves
	waitmovement 0
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, PetalburgWoods_CelebiEvent_Won
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, PetalburgWoods_CelebiEvent_Won
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, PetalburgWoods_CelebiEvent_Ran
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, PetalburgWoods_CelebiEvent_Ran
	releaseall
	end

PetalburgWoods_CelebiEvent_Won::
	applymovement LOCALID_CELEBI, PetalburgWoods_EventScript_CelebiMoves2
	waitmovement 0
	setflag FLAG_DEFEATEDCELEBI
	clearflag FLAG_GARBAGEFLAG
	end

PetalburgWoods_CelebiEvent_Ran::
	applymovement LOCALID_CELEBI, PetalburgWoods_EventScript_CelebiMoves2
	waitmovement 0
	end

PetalburgWoods_EventScript_CelebiMoves:
	delay_16
	delay_16
	delay_16
	walk_down
	set_visible
	step_end

PetalburgWoods_EventScript_CelebiMoves2:
	set_invisible
	walk_up
	step_end

Text_PetalburgWoods_Celebi0:
	.string "L'arbre tremble.\p"
	.string "Tu as aussi l'impression que quelqu'un\n"
	.string "ou quelque chose t'observe…\p"
	.string "Mais… tu ne vois aucun POKéMON…$"

Text_PetalburgWoods_Celebi1:
	.string ". . . \p"
	.string ". . . \p"
	.string "Tu entends une voix faible.\p"
	.string "M..nt..e m.. . . .ÉR . K. MON\p"
	.string ". . . \p"
	.string "M..ntre-moi le POKéMON FOUDRE…$"

Text_PetalburgWoods_Celebi2:
	.string ". . . \p"
	.string ". . . \p"
	.string "Montre-moi le POKéMON VOLCAN…$"

Text_PetalburgWoods_Celebi3:
	.string ". . . \p"
	.string ". . . \p"
	.string "Montre-moi le POKéMON AURORA…$"

Text_PetalburgWoods_Celebi4:
	.string ". . . \p"
	.string "Quelque chose s'approche…\p"
	.string ". . . $"

Text_PetalburgWoods_Celebi_Donthave:
	.string ". . . \p"
	.string "Tu ne l'as p…\p"
	.string "Tu ne l'as pas…$"

Movement_PetalburgWoods_Celebi1:
	emote_exclamation_mark
	delay_16
	delay_16
	delay_16
	delay_16
	step_end

PetalburgWoods_Dusclops::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_DUSCLOPS, CRY_MODE_NORMAL
	msgbox PetalburgWoods_Text_Dusclops, MSGBOX_DEFAULT
	waitmoncry
	release
	end

PetalburgWoods_Text_Dusclops:
	.string "DUSKY: Dusk, dusk!$"

PetalburgWoods_Celebi_Sign::
	faceplayer
	goto_if_unset FLAG_ROBERTO1, PetalburgWoods_Celebi_SignFirstTime
	goto_if_set FLAG_DEFEATEDCELEBI, PetalburgWoods_Celebi_SignEventFinished
	goto_if_set FLAG_SYS_GAME_CLEAR, PetalburgWoods_Celebi_SignChampion
	msgbox Text_PetalburgWoods_Celebi_Sign, MSGBOX_NPC
	end

PetalburgWoods_Celebi_SignFirstTime::
	faceplayer
	msgbox Text_PetalburgWoods_Celebi_SignFirstTime, MSGBOX_NPC
	setflag FLAG_ROBERTO1
	end

PetalburgWoods_Celebi_SignEventFinished::
	faceplayer
	msgbox Text_PetalburgWoods_Celebi_SignEventFinished, MSGBOX_NPC
	end

PetalburgWoods_Celebi_SignChampion::
	faceplayer
	msgbox Text_PetalburgWoods_Celebi_SignEventChampion, MSGBOX_NPC
	end

Text_PetalburgWoods_Celebi_Sign:
	.string "Salut, dresseur.\p"
	.string "Dangereux ? Non, non. Ne t'inquiète pas.\l"
	.string "DUSKY patrouille dans les environs.\p"
	.string "Et toi ? Comment se passe ton aventure\n"
	.string "jusqu'ici ?$"

Text_PetalburgWoods_Celebi_SignFirstTime:
	.string "Oh, un jeune…\p"
	.string "Que fais-tu ici dans ces bois\n"
	.string "sombres et mystérieux ?\p"
	.string ". . .\p"
	.string "Oh, je vois. Tu ne fais que passer.\p"
	.string "Quoi ? Ah, moi ?\p"
	.string "J'arrose simplement l'arbre sacré\n"
	.string "comme je l'ai toujours fait.\p"
	.string "Ah, tu te demandes pourquoi j'arrose\n"
	.string "un arbre innocent au milieu de la forêt, n'est-ce pas ?\p"
	.string "Mais tu vois, cet arbre est spécial.\n"
	.string "Dans ces bois vit un POKéMON MYTHIQUE.\l"
	.string "C'est le GARDIEN DE LA FORÊT.\p"
	.string "J'arrose cet arbre depuis plus de\n"
	.string "vingt ans de ma vie.\p"
	.string "Et je peux t'assurer que cette histoire\n"
	.string "est aussi réelle que l'air que l'on respire.\l"
	.string "Le GARDIEN DE LA FORÊT est petit, VERT,\l"
	.string "et le regarder donne l'impression…\p"
	.string "De voir un esprit de la forêt.\n"
	.string "Malheureusement, la dernière fois que je l'ai vu\l"
	.string "remonte à de très nombreuses années…\p"
	.string "Où peut bien être le GARDIEN ?\p"
	.string "Peut-être dois-je devenir PLUS FORT pour\n"
	.string "le faire apparaître…\p"
	.string "Cela me rend vraiment triste de voir\n"
	.string "à quel point je suis devenu faible avec les années.\p"
	.string "Enfin, je vais continuer mes tâches.\n"
	.string "À bientôt, jeune dresseur.$"

Text_PetalburgWoods_Celebi_SignEventFinished:
	.string ". . . \p"
	.string "Je n'en crois pas mes yeux !\n"
	.string "Tu as combattu le GARDIEN !?\p"
	.string "Je n'oublierai jamais ce moment.\n"
	.string "Je continuerai d'arroser ce sanctuaire\l"
	.string "jusqu'à son retour un jour.$"

Text_PetalburgWoods_Celebi_SignEventChampion:
	.string "Te revoilà, jeune dresseur.\p"
	.string "Il se passe quelque chose avec l'arbre\n"
	.string "du GARDIEN.\p"
	.string "J'entends de petits murmures autour\n"
	.string "depuis des heures.\p"
	.string "Quelque chose à propos d'un POKéMON TONNERRE,\n"
	.string "d'un VOLCAN et d'une AURORA…\p"
	.string "Attends… Je connais ces descriptions…\n"
	.string "Trois bêtes ? Mais…\p"
	.string "Pas de cette région…? D'où viennent-elles ?\n"
	.string "GIOTO ? HOJO ? JONO ? JOHTO ?\p"
	.string "Et si elles sont ici, à HOENN…\n"
	.string "Peut-être qu'elles se cachent dans des lieux liés\l"
	.string "à leurs descriptions ?\p"
	.string "Si tu as le temps, tu pourrais peut-être\n"
	.string "aller voir. Qu'en penses-tu ?$"

PetalburgWoods_EventScript_DevonResearcherLeft::
	lockall
	call PetalburgWoods_EventScript_DevonResearcherIntro
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherApproachPlayerLeft
	waitmovement 0
	msgbox PetalburgWoods_Text_HaveYouSeenShroomish, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaEntrance
	waitmovement 0
	msgbox PetalburgWoods_Text_IWasGoingToAmbushYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaApproachResearcherLeft
	waitmovement 0
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox PetalburgWoods_Text_HandOverThosePapers, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherFleeToPlayerLeft
	waitmovement 0
	msgbox PetalburgWoods_Text_YouHaveToHelpMe, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaApproachPlayer
	waitmovement 0
	msgbox PetalburgWoods_Text_NoOneCrossesTeamAqua, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_TONY, PetalburgWoods_Text_YoureKiddingMe
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaBackOff
	waitmovement 0
	call PetalburgWoods_EventScript_DevonResearcherPostBattle
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgWoods_Movement_WatchResearcherLeave
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherExitLeft
	waitmovement 0
	goto PetalburgWoods_EventScript_RemoveDevonResearcher
	end

PetalburgWoods_EventScript_DevonResearcherRight::
	lockall
	call PetalburgWoods_EventScript_DevonResearcherIntro
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherApproachPlayerRight
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox PetalburgWoods_Text_HaveYouSeenShroomish, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaEntrance
	waitmovement 0
	msgbox PetalburgWoods_Text_IWasGoingToAmbushYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaApproachResearcherRight
	waitmovement 0
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox PetalburgWoods_Text_HandOverThosePapers, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherFleeToPlayerRight
	waitmovement 0
	msgbox PetalburgWoods_Text_YouHaveToHelpMe, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox PetalburgWoods_Text_NoOneCrossesTeamAqua, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_TONY, PetalburgWoods_Text_YoureKiddingMe
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaBackOff
	waitmovement 0
	call PetalburgWoods_EventScript_DevonResearcherPostBattle
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgWoods_Movement_WatchResearcherLeave
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherExitRight
	waitmovement 0
	goto PetalburgWoods_EventScript_RemoveDevonResearcher
	end

PetalburgWoods_EventScript_DevonResearcherIntro::
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherLookAround
	waitmovement 0
	msgbox PetalburgWoods_Text_NotAOneToBeFound, MSGBOX_DEFAULT
	closemessage
	return

PetalburgWoods_EventScript_DevonResearcherPostBattle::
	msgbox PetalburgWoods_Text_YouveGotSomeNerve, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaRunAway
	waitmovement 0
	removeobject LOCALID_GRUNT
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox PetalburgWoods_Text_ThatWasAwfullyClose, MSGBOX_DEFAULT
	giveitem ITEM_GREAT_BALL
	goto_if_eq VAR_RESULT, FALSE, PetalburgWoods_EventScript_BagFull
	goto PetalburgWoods_EventScript_DevonResearcherFinish
	end

PetalburgWoods_EventScript_BagFull::
	msgbox PetalburgWoods_Text_YoureLoadedWithItems, MSGBOX_DEFAULT
	goto PetalburgWoods_EventScript_DevonResearcherFinish
	end

PetalburgWoods_EventScript_DevonResearcherFinish::
	msgbox PetalburgWoods_Text_TeamAquaAfterSomethingInRustboro, MSGBOX_DEFAULT
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherStartExit
	waitmovement 0
	msgbox PetalburgWoods_Text_ICantBeWastingTime, MSGBOX_DEFAULT
	closemessage
	return

PetalburgWoods_EventScript_RemoveDevonResearcher::
	removeobject LOCALID_DEVON_EMPLOYEE
	setvar VAR_GARBAGEVAR, 1
	releaseall
	end

PetalburgWoods_Movement_DevonResearcherLookAround:
	face_up
	delay_16
	delay_4
	face_right
	delay_16
	delay_8
	face_left
	delay_16
	delay_8
	face_down
	delay_16
	face_right
	delay_16
	delay_8
	face_up
	delay_16
	step_end

PetalburgWoods_Movement_DevonResearcherExitLeft:
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

PetalburgWoods_Movement_DevonResearcherApproachPlayerLeft:
	delay_16
	face_player
	walk_down
	walk_down
	step_end

PetalburgWoods_Movement_DevonResearcherApproachPlayerRight:
	delay_16
	face_player
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_right
	step_end

PetalburgWoods_Movement_DevonResearcherExitRight:
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

PetalburgWoods_Movement_WatchResearcherLeave:
	delay_16
	delay_16
	walk_in_place_faster_up
	step_end

PetalburgWoods_Movement_DevonResearcherFleeToPlayerLeft:
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_in_place_faster_up
	step_end

PetalburgWoods_Movement_DevonResearcherFleeToPlayerRight:
	walk_fast_down
	walk_fast_right
	walk_in_place_faster_up
	step_end

PetalburgWoods_Movement_DevonResearcherStartExit:
	walk_in_place_faster_down
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	face_up
	step_end

PetalburgWoods_Movement_AquaApproachResearcherLeft:
	walk_fast_down
	walk_fast_down
	step_end

PetalburgWoods_Movement_AquaBackOff:
	lock_facing_direction
	walk_up
	unlock_facing_direction
	step_end

PetalburgWoods_Movement_AquaRunAway:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	delay_16
	delay_16
	step_end

PetalburgWoods_Movement_AquaApproachResearcherRight:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

PetalburgWoods_Movement_AquaEntrance:
	walk_down
	walk_down
	delay_16
	delay_16
	step_end

PetalburgWoods_Movement_AquaApproachPlayer:
	walk_down
	step_end

PetalburgWoods_EventScript_Boy1::
	msgbox PetalburgWoods_Text_StayOutOfTallGrass, MSGBOX_NPC
	end

PetalburgWoods_EventScript_Boy2::
	msgbox PetalburgWoods_Text_HiddenItemsExplanation, MSGBOX_NPC
	end

PetalburgWoods_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_MIRACLE_SEED, PetalburgWoods_EventScript_ExplainMiracleSeed
	msgbox PetalburgWoods_Text_TryUsingThisItem, MSGBOX_DEFAULT
	giveitem ITEM_MIRACLE_SEED
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_MIRACLE_SEED
	release
	end

PetalburgWoods_EventScript_ExplainMiracleSeed::
	msgbox PetalburgWoods_Text_MiracleSeedExplanation, MSGBOX_DEFAULT
	release
	end

PetalburgWoods_EventScript_Sign1::
	msgbox PetalburgWoods_Text_TrainerTipsExperience, MSGBOX_SIGN
	end

PetalburgWoods_EventScript_Sign2::
	msgbox PetalburgWoods_Text_TrainerTipsPP, MSGBOX_SIGN
	end

PetalburgWoods_EventScript_Lyle::
	trainerbattle_single TRAINER_LYLE, PetalburgWoods_Text_GoBugPokemonTeam, PetalburgWoods_Text_ICouldntWin
	msgbox PetalburgWoods_Text_ImOutOfPokeBalls, MSGBOX_AUTOCLOSE
	end

PetalburgWoods_EventScript_James::
	trainerbattle_single TRAINER_RIVAL_CYNDAQUIL_4, PetalburgWoods_Text_InstantlyPopularWithBugPokemon, PetalburgWoods_Text_CantBePopularIfILose, PetalburgWoods_EventScript_TryRegisterJames
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, PetalburgWoods_EventScript_JamesRematch
	setvar VAR_0x8004, TRAINER_RIVAL_CYNDAQUIL_4
	specialvar VAR_RESULT, IsTrainerRegistered
	goto_if_eq VAR_RESULT, FALSE, PetalburgWoods_EventScript_TryRegisterJames2
	msgbox PetalburgWoods_Text_PeopleRespectYou, MSGBOX_DEFAULT
	release
	end

PetalburgWoods_EventScript_TryRegisterJames::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	goto_if_set FLAG_HAS_MATCH_CALL, PetalburgWoods_EventScript_RegisterJames
	release
	end

PetalburgWoods_EventScript_RegisterJames::
	msgbox PetalburgWoods_Text_IWantRematch1, MSGBOX_DEFAULT
	register_matchcall TRAINER_RIVAL_CYNDAQUIL_4
	release
	end

PetalburgWoods_EventScript_TryRegisterJames2::
	goto_if_set FLAG_HAS_MATCH_CALL, PetalburgWoods_EventScript_RegisterJames2
	msgbox PetalburgWoods_Text_PeopleRespectYou, MSGBOX_DEFAULT
	release
	end

PetalburgWoods_EventScript_RegisterJames2::
	msgbox PetalburgWoods_Text_IWantRematch2, MSGBOX_DEFAULT
	register_matchcall TRAINER_RIVAL_CYNDAQUIL_4
	release
	end

PetalburgWoods_EventScript_JamesRematch::
	trainerbattle_rematch TRAINER_RIVAL_CYNDAQUIL_4, PetalburgWoods_Text_MyPokemonHaveGrown, PetalburgWoods_Text_CantBePopularIfLose
	msgbox PetalburgWoods_Text_IveBeenTrainingHard, MSGBOX_AUTOCLOSE
	end

PetalburgWoods_Text_NotAOneToBeFound:
	.string "Hmm…\n"
	.string "Pas un seul à trouver…$"

PetalburgWoods_Text_HaveYouSeenShroomish:
	.string "Bonjour, as-tu vu un POKéMON\n"
	.string "appelé BALINÉA dans le coin ?\p"
	.string "J'adore vraiment ce POKéMON.$"

PetalburgWoods_Text_IWasGoingToAmbushYou:
	.string "J'allais te tendre une embuscade, mais tu\n"
	.string "as traîné dans la FORÊT DE CLÉMENTI\l"
	.string "pendant une éternité, pas vrai ?\p"
	.string "J'en ai eu marre d'attendre, alors me voilà !$"

PetalburgWoods_Text_HandOverThosePapers:
	.string "Toi ! CHERCHEUR DE DEVON !\p"
	.string "Donne-moi ces papiers !$"

PetalburgWoods_Text_YouHaveToHelpMe:
	.string "Aïe aïe aïe !\p"
	.string "Tu es un DRESSEUR POKéMON, non ?\n"
	.string "Tu dois m'aider, s'il te plaît !$"

PetalburgWoods_Text_NoOneCrossesTeamAqua:
	.string "Hein ? Qu'est-ce que tu fais ?\n"
	.string "Tu veux le protéger ?\p"
	.string "Personne ne défie la TEAM AQUA\n"
	.string "sans en payer le prix, même pas un gosse !\p"
	.string "Allez, viens te battre !$"

PetalburgWoods_Text_YoureKiddingMe:
	.string "Tu plaisantes ! Tu es fort !$"

PetalburgWoods_Text_YouveGotSomeNerve:
	.string "Grrr… Tu as du cran\n"
	.string "à t'en prendre à la TEAM AQUA !\l"
	.string "Viens te battre encore une fois !\p"
	.string "J'aimerais bien, mais je n'ai plus de\n"
	.string "POKéMON…\p"
	.string "Et, hé, nous de la TEAM AQUA, on cherche\n"
	.string "aussi quelque chose à MÉROVILLE.\p"
	.string "Je te laisse partir pour aujourd'hui !$"

PetalburgWoods_Text_ThatWasAwfullyClose:
	.string "Ouf…\n"
	.string "C'était vraiment juste !\p"
	.string "Grâce à toi, il ne m'a pas volé\n"
	.string "ces papiers importants.\p"
	.string "Tiens, je vais te donner une SUPER BALL\n"
	.string "pour te remercier !$"

PetalburgWoods_Text_TeamAquaAfterSomethingInRustboro:
	.string "Ce sbire de la TEAM AQUA n'a-t-il pas dit\n"
	.string "qu'ils cherchaient aussi quelque chose à\l"
	.string "MÉROVILLE ?$"

PetalburgWoods_Text_ICantBeWastingTime:
	.string "Oh non ! C'est la panique !\n"
	.string "Je ne peux pas perdre de temps !$"

PetalburgWoods_Text_YoureLoadedWithItems:
	.string "Tu as trop d'objets.\n"
	.string "Je ne peux pas te donner cette SUPER BALL.$"

PetalburgWoods_Text_GoBugPokemonTeam:
	.string "J'ai attrapé plein de POKéMON !\p"
	.string "Allez, allez, allez !\n"
	.string "Mon équipe d'INSECTE !$"

PetalburgWoods_Text_ICouldntWin:
	.string "J'ai tous ces POKéMON,\n"
	.string "mais je n'ai pas pu gagner…$"

PetalburgWoods_Text_ImOutOfPokeBalls:
	.string "J'ai attrapé plein de POKéMON.\n"
	.string "Maintenant, je n'ai plus de POKé BALL.$"

PetalburgWoods_Text_InstantlyPopularWithBugPokemon:
	.string "Si tu emmènes des POKéMON INSECTE à l'école,\n"
	.string "tu deviens tout de suite populaire !$"

PetalburgWoods_Text_CantBePopularIfILose:
	.string "Je ne peux pas être populaire si je perds.$"

PetalburgWoods_Text_PeopleRespectYou:
	.string "Si tu as un gros POKéMON INSECTE,\n"
	.string "les gens te respectent pour ça.$"

PetalburgWoods_Text_IWantRematch1:
	.string "Je veux une revanche quand mes\n"
	.string "POKéMON INSECTE auront grandi !\p"
	.string "Je t'enregistre dans mon POKéNAV !$"

PetalburgWoods_Text_IWantRematch2:
	.string "Je veux une revanche quand mes\n"
	.string "POKéMON INSECTE auront grandi !\p"
	.string "Je t'enregistre dans mon POKéNAV !$"

PetalburgWoods_Text_MyPokemonHaveGrown:
	.string "Mes POKéMON INSECTE ont grandi.\n"
	.string "Je vais redevenir populaire !$"

PetalburgWoods_Text_CantBePopularIfLose:
	.string "Je ne peux pas être populaire si je perds.$"

PetalburgWoods_Text_IveBeenTrainingHard:
	.string "On devient populaire si on a des\n"
	.string "POKéMON forts, non ?\l"
	.string "Alors, je m'entraîne dur !$"

PetalburgWoods_Text_StayOutOfTallGrass:
	.string "Hé, toi !\n"
	.string "Tes POKéMON vont bien ?\p"
	.string "Si tes POKéMON sont faibles et que tu veux\n"
	.string "éviter les combats, reste hors\l"
	.string "des hautes herbes !$"

PetalburgWoods_Text_HiddenItemsExplanation:
	.string "Parfois, il y a des objets au sol\n"
	.string "même si tu ne les vois pas.\p"
	.string "C'est pour ça que je vérifie toujours\n"
	.string "où je marche.$"

PetalburgWoods_Text_TryUsingThisItem:
	.string "Oh, super !\n"
	.string "C'est le BADGE de l'ARENE DE MÉROVILLE !\p"
	.string "Tu dois être un DRESSEUR.\n"
	.string "Tu devrais essayer d'utiliser cet objet.$"

PetalburgWoods_Text_MiracleSeedExplanation:
	.string "C'est une GRAINE MIRACLE.\n"
	.string "Si un POKéMON tient cet objet, ses\l"
	.string "attaques de type PLANTE sont plus fortes.\p"
	.string "En plus de la GRAINE MIRACLE, je pense\n"
	.string "qu'il y a d'autres objets utiles que les\l"
	.string "POKéMON peuvent tenir.$"

PetalburgWoods_Text_TrainerTipsExperience:
	.string "ASTUCE DRESSEUR\p"
	.string "Tout POKéMON qui participe au moins une fois\n"
	.string "à un combat reçoit des Points EXP.\p"
	.string "Pour faire monter un POKéMON faible, place-le\n"
	.string "à gauche dans la liste de l'équipe.\p"
	.string "Dès que le combat commence, change-le\n"
	.string "et il gagnera des Points EXP sans\l"
	.string "être exposé au danger.$"

PetalburgWoods_Text_TrainerTipsPP:
	.string "ASTUCE DRESSEUR\p"
	.string "En plus des Points de Vie (PV), les POKéMON\n"
	.string "ont des Points de Pouvoir (PP) utilisés pour\l"
	.string "lancer des attaques en combat.\p"
	.string "Si un POKéMON n'a plus de PP, il doit être\n"
	.string "soigné dans un CENTRE POKéMON.$"
