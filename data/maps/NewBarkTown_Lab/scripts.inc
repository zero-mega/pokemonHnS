.set LOCALID_ELM, 2
.set LOCALID_AIDE1, 1
.set LOCALID_AIDE2, 3
.set LOCALID_COP, 7
.set PLAYER_STARTER_SPECIES,  VAR_TEMP_2

NewBarkTown_Lab_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, NewBarkTown_Lab_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, NewBarkTown_Lab_OnFrame
	.byte 0

NewBarkTown_Lab_OnTransition::
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 6, NewBarkTown_Lab_EventScript_ElmAtComputer
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 2, NewBarkTown_Lab_EventScript_ElmAtComputer
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 3, NewBarkTown_Lab_EventScript_ElmAtComputer
	end
	
NewBarkTown_Lab_OnFrame::
	map_script_2 VAR_NEWBARKTOWN_LABSTATE, 4, NewBarkTown_Lab_EventScript_PoliceEpisode
	.2byte 0

NewBarkTown_Lab_EventScript_ElmAtComputer::
	setobjectxyperm LOCALID_ELM, 3, 2
	setobjectmovementtype LOCALID_ELM, MOVEMENT_TYPE_FACE_UP
	end

NewBarkTown_Lab_EventScript_TriggerStartLabLeft::	
	lock
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_Lab_Movement_WalkRight
	waitmovement 0
	goto NewBarkTown_Lab_EventScript_TriggerStartLab
	end

NewBarkTown_Lab_EventScript_TriggerStartLabRight::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_Lab_Movement_WalkLeft
	waitmovement 0
	goto NewBarkTown_Lab_EventScript_TriggerStartLab
	end

NewBarkTown_Lab_EventScript_TriggerStartLab::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_LabMovement_WalkToElm
	waitmovement 0
	goto NewBarkTown_Lab_EventScript_ElmIntro
	end

NewBarkTown_EventScript_Aide1::
	lock
	faceplayer
	msgbox NewBarkTown_Lab_Text_AideAlwaysBusy, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_EventScript_Aide2::
	lock
	faceplayer
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 5, NewBarkTown_EventScript_Aide2Testimony
	msgbox NewBarkTown_Lab_Text_AideSave, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_EventScript_Aide2Testimony::
	msgbox NewBarkTown_Lab_Text_AideTheftTestimony, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_Lab_EventScript_Elm::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_NEWBARKTOWN_LAB_AIDE, NewBarkTown_Lab_EventScript_ElmAideIsWaiting
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 7, NewBarkTown_Lab_EventScript_ElmMasterBall
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 8, NewBarkTown_Lab_EventScript_ElmKimono
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 9, NewBarkTown_Lab_EventScript_ElmLeague
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 10, NewBarkTown_Lab_EventScript_ElmSSTicket

	goto_if_set FLAG_SHOWN_ELM_TOGEPI, NewBarkTown_Lab_EventScript_Elm_CallMe
	call_if_unset FLAG_SHOWN_ELM_TOGEPI, NewBarkTown_Lab_EventScript_Elm_Check_Togepi
	goto_if_ge VAR_GOLDENROD_CITY_STATE, 1, NewBarkTown_Lab_EventScript_Elm_Check_WhereIsEgg
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 5, NewBarkTown_Lab_EventScript_ElmState5

	goto_if_ge VAR_NEWBARKTOWN_LABSTATE, 6, NewBarkTown_Lab_EventScript_ElmState5
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 2, CopNewBarkTown_Lab_EventScript_ElmState2
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 3, CopNewBarkTown_Lab_EventScript_ElmState2
	goto_if_set FLAG_SYS_POKEMON_GET, NewBarkTown_Lab_EventScript_MrPokemon
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 1, NewBarkTown_Lab_EventScript_ElmChoosePokemon
	end

NewBarkTown_Lab_EventScript_ElmAideIsWaiting::
	msgbox NewBarkTown_Lab_Text_ElmAideIsWaiting, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_Lab_Text_ElmAideIsWaiting:
	.string "{PLAYER}!\p"
	.string "Que fais-tu ici ?\p"
	.string "Mon assistant t'attend encore\n"
	.string "à MAUVILLE !$"

NewBarkTown_Lab_EventScript_ElmIntro::
	msgbox NewBarkTown_Lab_Text_ElmIntro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_ElmAccepted
	goto_if_eq VAR_RESULT, NO, NewBarkTown_Lab_EventScript_ElmRefused
	end

NewBarkTown_Lab_EventScript_ElmRefused::
	msgbox NewBarkTown_Lab_Text_ElmRefused, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_ElmAccepted
	goto_if_eq VAR_RESULT, NO, NewBarkTown_Lab_EventScript_ElmRefused
	end

NewBarkTown_Lab_EventScript_ElmAccepted::
	msgbox NewBarkTown_Lab_Text_ElmAccepted, MSGBOX_DEFAULT
	msgbox NewBarkTown_Lab_Text_ElmResearchAmbitions, MSGBOX_DEFAULT
	delay 30
	playse SE_PC_LOGIN
	waitse
	playse SE_PIN
	applymovement LOCALID_ELM, Common_Movement_QuestionMark
	delay 60
	applymovement LOCALID_ELM, NewBarkTown_Lab_Movement_CheckEmail
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_Lab_Movement_Look_Left
	waitmovement 0
	waitmovement 0
	msgbox NewBarkTown_Lab_Text_ElmGotAnEmail, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ELM, NewBarkTown_Lab_Movement_ReturnFromEmail
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_Lab_Movement_Look_Up
	waitmovement 0
	delay 30
	msgbox NewBarkTown_Lab_Text_ElmMissionFromMrPokemon, MSGBOX_DEFAULT
	goto NewBarkTown_Lab_EventScript_ElmChoosePokemon
	end

NewBarkTown_Lab_EventScript_ElmChoosePokemon::
	msgbox NewBarkTown_Lab_Text_ElmChooseAPokemon, MSGBOX_DEFAULT
	closemessage
	setvar VAR_NEWBARKTOWN_LABSTATE, 1
	release
	end

NewBarkTown_Lab_EventScript_TriggerReturnPlayer::
	lock
	msgbox NewBarkTown_Lab_Text_ElmWhereGoing, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_Lab_Movement_ReturnPlayer
	waitmovement 0
	release
	end

NewBarkTown_Lab_EventScript_ShouldntTouch::
	msgbox NewBarkTown_Lab_Text_ShouldntTouch, MSGBOX_DEFAULT
	closemessage
	end


NewBarkTown_Lab_EventScript_ChikoritaBall::
	lock
	goto_if_set FLAG_SYS_POKEMON_GET, NewBarkTown_Lab_EventScript_ShouldntTouch
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 1, NewBarkTown_Lab_EventScript_ChikoritaBall_Choice
	msgbox NewBarkTown_Lab_Text_ShouldntTouch, MSGBOX_DEFAULT
	release
	closemessage
	end

NewBarkTown_Lab_EventScript_ChikoritaBall_Choice::
	setvar PLAYER_STARTER_SPECIES, SPECIES_CHIKORITA
	showmonpic PLAYER_STARTER_SPECIES, 10, 3
	playmoncry PLAYER_STARTER_SPECIES, CRY_MODE_NORMAL
	msgbox NewBarkTown_Lab_Text_ChooseChikorita, MSGBOX_YESNO
	setvar VAR_STARTER_MON, 0
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_ChoseStarter
	goto_if_eq VAR_RESULT, NO, NewBarkTown_Lab_EventScript_DeclinedStarter
	end

NewBarkTown_Lab_EventScript_CyndaquilBall::
	lock
	goto_if_set FLAG_SYS_POKEMON_GET, NewBarkTown_Lab_EventScript_ShouldntTouch
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 1, NewBarkTown_Lab_EventScript_CyndaquilBall_Choice
	msgbox NewBarkTown_Lab_Text_ShouldntTouch, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_Lab_EventScript_CyndaquilBall_Choice::
	setvar PLAYER_STARTER_SPECIES, SPECIES_CYNDAQUIL
	showmonpic PLAYER_STARTER_SPECIES, 10, 3
	playmoncry PLAYER_STARTER_SPECIES, CRY_MODE_NORMAL
	msgbox NewBarkTown_Lab_Text_ChooseCyndaquil, MSGBOX_YESNO
	setvar VAR_STARTER_MON, 1
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_ChoseStarter
	goto_if_eq VAR_RESULT, NO, NewBarkTown_Lab_EventScript_DeclinedStarter
	end

NewBarkTown_Lab_EventScript_TotodileBall::
	lock
	goto_if_set FLAG_SYS_POKEMON_GET, NewBarkTown_Lab_EventScript_ShouldntTouch
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 1, NewBarkTown_Lab_EventScript_TotodileBall_Choice
	msgbox NewBarkTown_Lab_Text_ShouldntTouch, MSGBOX_DEFAULT
	release
	closemessage
	end

NewBarkTown_Lab_EventScript_TotodileBall_Choice::
	setvar PLAYER_STARTER_SPECIES, SPECIES_TOTODILE
	showmonpic PLAYER_STARTER_SPECIES, 10, 3
	playmoncry PLAYER_STARTER_SPECIES, CRY_MODE_NORMAL
	msgbox NewBarkTown_Lab_Text_ChooseTotodile, MSGBOX_YESNO
	setvar VAR_STARTER_MON, 2
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_ChoseStarter
	goto_if_eq VAR_RESULT, NO, NewBarkTown_Lab_EventScript_DeclinedStarter
	end

NewBarkTown_Lab_EventScript_DeclinedStarter::
	hidemonpic
	msgbox NewBarkTown_Lab_Text_DidntChooseStarter, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_Lab_EventScript_ChoseStarter::
	hidemonpic
	removeobject VAR_LAST_TALKED
	setflag FLAG_SYS_POKEMON_GET
	msgbox NewBarkTown_Lab_Text_ChoseStarter, MSGBOX_DEFAULT
	givemon PLAYER_STARTER_SPECIES, 5
	playfanfare MUS_OBTAIN_ITEM
	bufferspeciesname STR_VAR_1, PLAYER_STARTER_SPECIES
	message NewBarkTown_Lab_Text_ReceivedStarter
	waitfanfare
	msgbox NewBarkTown_Lab_Text_Nickname, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_NicknameStarter
	release
	end

NewBarkTown_Lab_EventScript_NicknameStarter::
	setvar VAR_0x8004, 0
	call Common_EventScript_NameReceivedPartyMon
	end

NewBarkTown_Lab_EventScript_MrPokemon::
	setvar VAR_NEWBARKTOWN_LABSTATE, 2
	setvar VAR_NEWBARK_TOWN_STATE, 3
	msgbox NewBarkTown_Lab_Text_ElmDirections1, MSGBOX_DEFAULT
	setflag FLAG_ENABLE_PROF_BIRCH_MATCH_CALL
	msgbox NewBarkTown_Lab_Text_ElmDirections2, MSGBOX_DEFAULT
	closemessage
	goto_if_eq VAR_FACING, DIR_EAST, NewBarkTown_Lab_EventScript_MrPokemonMovementSafe
	applymovement LOCALID_ELM, NewBarkTown_Lab_Movement_CheckEmailSlow
	waitmovement 0
	clearflag FLAG_RECEIVED_FIRST_BALLS
	clearflag FLAG_RECEIVED_FIRST_POTION
	setvar VAR_NEWBARK_TOWN_STATE, 3
	release
	end

NewBarkTown_Lab_EventScript_MrPokemonMovementSafe::
	applymovement LOCALID_ELM, NewBarkTown_Lab_Movement_GotoComputerSafe
	waitmovement 0
	clearflag FLAG_RECEIVED_FIRST_BALLS
	clearflag FLAG_RECEIVED_FIRST_POTION
	setvar VAR_NEWBARK_TOWN_STATE, 3
	release
	end

CopNewBarkTown_Lab_EventScript_ElmState2::
	msgbox NewBarkTown_Lab_Text_ElmDirections1, MSGBOX_DEFAULT
	msgbox NewBarkTown_Lab_Text_ElmDirections2, MSGBOX_DEFAULT
	applymovement LOCALID_ELM, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	closemessage
	release
	end

NewBarkTown_Lab_EventScript_HealingMachine1::
	lock
	goto_if_set FLAG_SYS_POKEMON_GET, NewBarkTown_Lab_EventScript_HealingMachine2
	msgbox LittlerootTown_ProfessorBirchsLab_Text_SeriousLookingMachine, MSGBOX_SIGN
	closemessage
	release
	end

NewBarkTown_Lab_EventScript_HealingMachine2::
	call Common_EventScript_OutOfCenterPartyHeal
	release
	end



NewBarkTown_Lab_EventScript_TriggerAideGivePotion::
	lock
	applymovement LOCALID_AIDE1, NewBarkTown_Lab_Movement_Aide1WalkToPlayer
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	msgbox NewBarkTown_Lab_Text_AideGivePotion, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_POTION
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_FIRST_POTION
	setvar VAR_NEWBARKTOWN_LABSTATE, 3
	applymovement LOCALID_AIDE1, NewBarkTown_Lab_Movement_Aide1LeavePlayer
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	release
	end

NewBarkTown_Lab_EventScript_HideCyndaquil::
	setflag FLAG_HIDE_CYNDAQUILBALL
	return
NewBarkTown_Lab_EventScript_HideTotodile::
	setflag FLAG_HIDE_TOTODILEBALL
	return
NewBarkTown_Lab_EventScript_HideChikorita::
	setflag FLAG_HIDE_CHIKORITABALL
	return

NewBarkTown_Lab_EventScript_PoliceEpisode::
	lock
	setmetatile 7, 1, METATILE_R26_21_Broken_Window, TRUE
	call_if_eq VAR_STARTER_MON, 0 NewBarkTown_Lab_EventScript_HideCyndaquil
	call_if_eq VAR_STARTER_MON, 1 NewBarkTown_Lab_EventScript_HideTotodile
	call_if_eq VAR_STARTER_MON, 2 NewBarkTown_Lab_EventScript_HideChikorita
	applymovement OBJ_EVENT_ID_PLAYER, NeBarkTownLab_Movement_PlayerWalkToCop
	waitmovement 0
	setflag FLAG_HIDE_LAB_POLICEMAN
	turnobject LOCALID_COP DIR_WEST
	msgbox NewBarkTown_Lab_Text_Officer1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_PoliceYes
	goto_if_eq VAR_RESULT, NO, NewBarkTown_Lab_EventScript_PoliceNo
	end

NewBarkTown_Lab_EventScript_PoliceNo::
	msgbox NewBarkTown_Lab_Text_OfficerNo, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_PoliceYes
	goto_if_eq VAR_RESULT, NO, NewBarkTown_Lab_EventScript_PoliceNo
	end

NewBarkTown_Lab_EventScript_PoliceYes::
	msgbox NewBarkTown_Lab_Text_Officer2, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_COP, NewBarkTown_Lab_Movement_CopLeaves
	waitmovement 0
	removeobject LOCALID_COP

	@ setobjectxyperm LOCALID_COP, 25, 4
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_Lab_Movement_PlayerStepsToElm
	waitmovement 0
	msgbox NewBarkTown_Lab_Text_ElmAfterTheft1, MSGBOX_DEFAULT
	msgbox NewBarkTown_Lab_Text_ElmAfterTheft2, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ELM, NewBarkTown_Lab_Movement_ElmStepBack
	waitmovement 0
	msgbox NewBarkTown_Lab_Text_ElmAfterTheft3, MSGBOX_DEFAULT
	delay 20
	closemessage
	applymovement LOCALID_ELM, NewBarkTown_Lab_Movement_ElmStepForward
	waitmovement 0
	msgbox NewBarkTown_Lab_Text_ElmAfterTheft4, MSGBOX_DEFAULT
	closemessage
	setvar VAR_NEWBARKTOWN_LABSTATE, 5
	setvar VAR_NEWBARK_TOWN_STATE, 4
	setflag FLAG_HIDE_MOMS_FRIEND
	clearflag FLAG_HIDE_MOMS_FRIEND2
	setflag FLAG_ADVENTURE_STARTED
	setflag FLAG_EXP_SHARE
	removeitem ITEM_MYSTERY_EGG
	end

NewBarkTown_Lab_EventScript_ElmState5::
	lock
	faceplayer
	msgbox NewBarkTown_Lab_Text_ElmStudyingEgg, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ELM Common_Movement_FaceOriginalDirection
	release
	end
	
NewBarkTown_Lab_EventScript_ElmMasterBall::
	lock
	faceplayer
	msgbox NewBarkTown_Lab_Text_ElmGiveMasterBall1, MSGBOX_DEFAULT
	giveitem ITEM_MASTER_BALL
	msgbox NewBarkTown_Lab_Text_ElmGiveMasterBall2, MSGBOX_DEFAULT
	closemessage
	delay 20
	playse SE_PIN
	applymovement LOCALID_ELM, Common_Movement_ExclamationMark
	delay 60
	msgbox NewBarkTown_Lab_Text_KimonoGirls, MSGBOX_DEFAULT
	closemessage
	setvar VAR_NEWBARKTOWN_LABSTATE, 8
	setvar VAR_ECRUTEAK_CITY_THEATER, 4
	setflag FLAG_HIDE_ECRUTEAK_SILVER
	setflag FLAG_HIDE_ECRUTEAK_CITY_THEATER_NPCS
	clearflag FLAG_HIDE_ECRUTEAK_CITY_THEATER_KIMONOS
	release
	end

NewBarkTown_Lab_EventScript_ElmKimono::
	lock
	faceplayer
	msgbox NewBarkTown_Lab_Text_KimonoWaiting, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_Lab_EventScript_ElmLeague::
	lock
	faceplayer
	msgbox NewBarkTown_Lab_Text_League, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_Lab_EventScript_ElmSSTicket::
	msgbox NewBarkTown_Lab_Text_ElmGiveTicket1, MSGBOX_DEFAULT
	giveitem ITEM_SS_TICKET
	msgbox NewBarkTown_Lab_Text_ElmGiveTicket2, MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_HIDE_SSAQUA_1F_GRANDPA
	setvar VAR_NEWBARKTOWN_LABSTATE, 11
	clearflag FLAG_HIDE_OLIVINE_PORT_OAK
	release
	end

NewBarkTown_Lab_EventScript_TriggerAideGiveBalls::
	lock
	applymovement LOCALID_AIDE1, NewBarkTown_Lab_Movement_Aide1WalkToPlayer
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	msgbox NewBarkTown_Lab_Text_AideGiveBalls, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_POKE_BALL, 5
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_FIRST_BALLS
	setvar VAR_NEWBARKTOWN_LABSTATE, 6
	applymovement LOCALID_AIDE1, NewBarkTown_Lab_Movement_Aide1LeavePlayer
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	release
	end

NewBarkTown_Lab_EventScript_Elm_Check_WhereIsEgg::
	msgbox NewBarkTown_Lab_Text_ElmWaitingEggHatch, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_Lab_EventScript_Elm_Check_Togepi::
	specialvar VAR_RESULT, CheckTogepi
	goto_if_eq VAR_RESULT, TRUE, NewBarkTown_Lab_EventScript_Elm_Togepi_Seen
	return

NewBarkTown_Lab_EventScript_Elm_Togepi_Seen::
	msgbox NewBarkTown_Lab_Text_ShowTogepi1, MSGBOX_DEFAULT
	waitmessage
	msgbox NewBarkTown_Lab_Text_ShowTogepi2, MSGBOX_DEFAULT
	waitmessage
	msgbox NewBarkTown_Lab_Text_ShowTogepi3, MSGBOX_DEFAULT
	waitmessage
	msgbox NewBarkTown_Lab_Text_ElmGiveEverstone1, MSGBOX_DEFAULT
	waitmessage
	giveitem ITEM_EVERSTONE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox NewBarkTown_Lab_Text_ElmGiveEverstone2, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_SHOWN_ELM_TOGEPI
	release
	end

NewBarkTown_Lab_EventScript_Elm_CallMe::
	msgbox NewBarkTown_Lab_Text_Elm_CallMe, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_Lab_Movement_WalkRight:
	walk_right
	step_end

NewBarkTown_Lab_Movement_WalkLeft:
	walk_left
	step_end

NewBarkTown_LabMovement_WalkToElm:
	walk_up
	walk_up
	walk_up
	step_end

NewBarkTown_Lab_Movement_ReturnPlayer:
	walk_up
	step_end

NewBarkTown_Lab_Movement_CheckEmail:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	step_end

NewBarkTown_Lab_Movement_CheckEmailSlow:
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

NewBarkTown_Lab_Movement_GotoComputerSafe:
	walk_up
	walk_left
	walk_left
	walk_left
	face_up
	step_end

NewBarkTown_Lab_Movement_ReturnFromEmail:
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	face_down
	step_end

NewBarkTown_Lab_Movement_Look_Left:
	face_left
	step_end

NewBarkTown_Lab_Movement_Look_Up:
	face_up
	step_end


NewBarkTown_Lab_Movement_Aide1WalkToPlayer:
	walk_down
	walk_down
	walk_right
	walk_right
	step_end

NewBarkTown_Lab_Movement_Aide1LeavePlayer:
	walk_left
	walk_left
	walk_up
	walk_up
	face_down
	step_end

NeBarkTownLab_Movement_PlayerWalkToCop:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_left
	walk_fast_up
	face_right
	step_end

NewBarkTown_Lab_Movement_CopLeaves:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

NewBarkTown_Lab_Movement_PlayerStepsToElm:
	walk_right
	face_up
	step_end

NewBarkTown_Lab_Movement_ElmStepBack:
	lock_facing_direction
	walk_fast_up
	unlock_facing_direction
	step_end

NewBarkTown_Lab_Movement_ElmStepForward:
	walk_fast_down
	step_end

NewBarkTown_Lab_Text_ShouldntTouch:
	.string "Il ne vaut mieux pas toucher !$"

NewBarkTown_Lab_Text_ElmIntro:
	.string "ELM : {PLAYER} ! Te voilà !\p"
	.string "J'avais besoin de te demander un service.\p"
	.string "Je mène actuellement de nouvelles recherches\n"
	.string "sur les POKéMON. Je me demandais si tu\l"
	.string "pourrais m'aider, {PLAYER}.\p"
	.string "Tu vois…\p"
	.string "J'écris un article que je veux présenter\n"
	.string "à une conférence.\p"
	.string "Mais il y a encore des choses que je\n"
	.string "ne comprends pas tout à fait.\p"
	.string "Alors !\p"
	.string "J'aimerais que tu élèves un POKéMON\n"
	.string "que je viens de capturer.$"

NewBarkTown_Lab_Text_ElmAccepted:
	.string "Merci, {PLAYER} !\n"
	.string "Tu es d'une grande aide !$"

NewBarkTown_Lab_Text_ElmRefused:
	.string "Mais… S'il te plaît, j'ai besoin\n"
	.string "de ton aide !$"

NewBarkTown_Lab_Text_ElmResearchAmbitions:
	.string "Quand j'annoncerai mes découvertes,\n"
	.string "je suis sûr que nous percerons\p"
	.string "davantage les nombreux mystères\n"
	.string "des POKéMON.\p"
	.string "Tu peux compter là-dessus !$"

NewBarkTown_Lab_Text_ElmGotAnEmail:
	.string "Oh, attends ! J'ai reçu un e-mail !\p"
	.string "… … … … … … … …\n"
	.string "Hmm… Uh-huh…\p"
	.string "D'accord…$"

NewBarkTown_Lab_Text_ElmMissionFromMrPokemon:
	.string "Écoute-moi.\p"
	.string "J'ai une connaissance qui s'appelle\n"
	.string "MR. POKéMON.\p"
	.string "Il trouve toujours des choses bizarres et\n"
	.string "s'extasie sur ses découvertes.\p"
	.string "Bref, je viens de recevoir un e-mail\n"
	.string "de lui disant que cette fois, c'est\l"
	.string "du sérieux.\p"
	.string "C'est intriguant, mais nous sommes\n"
	.string "occupés par nos recherches sur les POKéMON...\p"
	.string "Attends !\n"
	.string "Je sais !\p"
	.string "{PLAYER}, peux-tu y aller à notre\n"
	.string "place ?$"

NewBarkTown_Lab_Text_ElmChooseAPokemon:
	.string "Je veux que tu élèves l'un des\n"
	.string "POKéMON contenus dans ces Balls.\p"
	.string "Tu seras le premier partenaire de ce\n"
	.string "POKéMON, {PLAYER} !\p"
	.string "Vas-y. Choisis-en un !$"

NewBarkTown_Lab_Text_ElmWhereGoing:
	.string "ELM : Attends ! Où vas-tu ?$"

NewBarkTown_Lab_Text_ChooseCyndaquil:
	.string "ELM : Tu veux prendre HÉRICENDRE,\n"
	.string "le POKéMON de feu ?$"

NewBarkTown_Lab_Text_ChooseTotodile:
	.string "ELM : Tu veux Kaiminus,\n"
	.string "le POKéMON d'eau ?$"

NewBarkTown_Lab_Text_ChooseChikorita:
	.string "ELM : Alors, tu aimes Germignon,\n"
	.string "le POKéMON plante ?$"

NewBarkTown_Lab_Text_DidntChooseStarter:
	.string "ELM : Réfléchis bien.\p"
	.string "Ton partenaire est important.$"

NewBarkTown_Lab_Text_ChoseStarter:
	.string "ELM : Je pense que c'est aussi un\n"
	.string "excellent POKéMON !$"

NewBarkTown_Lab_Text_ReceivedStarter:
	.string "{PLAYER} a reçu {STR_VAR_1} !$"

NewBarkTown_Lab_Text_Nickname:
	.string "Veux-tu donner un surnom à ton\n"
	.string "{STR_VAR_1} ?$"

NewBarkTown_Lab_Text_ElmDirections1:
	.string "MR. POKéMON habite un peu après\n"
	.string "ÉCORCIA, la ville voisine.\p"
	.string "C'est presque une route directe\n"
	.string "jusqu'à là-bas, tu ne peux pas te tromper.\p"
	.string "Mais au cas où, tu as mon numéro\n"
	.string "de téléphone. Appelle-moi si\l"
	.string "quelque chose arrive !$"

NewBarkTown_Lab_Text_ElmLetYourMonBattle:
	.string "Si un POKéMON sauvage apparaît,\n"
	.string "laisse ton POKéMON se battre !$"

NewBarkTown_Lab_Text_ElmDirections2:
	.string "Si un POKéMON sauvage apparaît, laisse\n"
	.string "ton POKéMON se battre !\p"
	.string "Si ton POKéMON est blessé, tu\n"
	.string "devrais le soigner avec la machine\l"
	.string "à ma droite, ou au CENTRE POKéMON.\p"
	.string "Je compte sur toi !$"

NewBarkTown_Lab_Text_GotElmsNumber:
	.string "{PLAYER} a reçu le numéro de\n"
	.string "téléphone du PROF. ELM.$"

NewBarkTown_Lab_Text_ElmDescribesMrPokemon:
	.string "MR. POKéMON va partout et\n"
	.string "trouve des raretés.\p"
	.string "Dommage qu'elles soient juste rares et\n"
	.string "pas très utiles…$"

NewBarkTown_Lab_Text_ElmPokeBall:
	.string "Elle contient un POKéMON capturé\n"
	.string "par le PROF. ELM.$"

@THEFT================================================================================

NewBarkTown_Lab_Text_ElmAfterTheft1:
	.string "ELM : {PLAYER}, c'est terrible…\p"
	.string "Ah, oui, quelle était la grande\n"
	.string "découverte de MR. POKéMON ?$"

NewBarkTown_Lab_Text_ElmAfterTheft2:
	.string "{PLAYER} a remis l'ŒUF MYSTÈRE\n"
	.string "au PROF. ELM.$"

NewBarkTown_Lab_Text_ElmAfterTheft3:
	.string "ELM : Ceci ?$"

NewBarkTown_Lab_Text_ElmAfterTheft4:
	.string "Mais… C'est un ŒUF de POKéMON ?\p"
	.string "Si c'est le cas, c'est une grande\n"
	.string "découverte !\p"
	.string "ELM : Quoi ?!?\p"
	.string "PROF. CHEN t'a donné un Pokédex ?\p"
	.string "{PLAYER}, c'est vrai ?\n"
	.string "C-c'est incroyable !\p"
	.string "Il est excellent pour voir le\n"
	.string "potentiel des gens comme dresseurs.\p"
	.string "Wow, {PLAYER}. Tu as peut-être ce\n"
	.string "qu'il faut pour devenir CHAMPION.\p"
	.string "Tu sembles aussi bien t'entendre\n"
	.string "avec les POKéMON.\p"
	.string "Tu devrais tenter le défi des\n"
	.string "ARÈNES POKéMON.\p"
	.string "La plus proche est celle de\n"
	.string "MAUVILLE.\p"
	.string "…{PLAYER}. La route vers le\n"
	.string "titre sera longue.\p"
	.string "Avant de partir, assure-toi de\n"
	.string "parler à ta mère.$"

NewBarkTown_Lab_Text_ElmStudyingEgg:
	.string "ELM : N'abandonne pas !\n"
	.string "Je t'appellerai si j'apprends\l"
	.string "quelque chose sur cet ŒUF !$"

NewBarkTown_Lab_Text_ElmAideHasEgg:
	.string "ELM : {PLAYER} ? Tu n'as pas vu\n"
	.string "mon assistant ?\p"
	.string "Il aurait dû te retrouver avec\n"
	.string "l'ŒUF au CENTRE POKéMON de MAUVILLE.\p"
	.string "Tu as dû le rater de peu.\n"
	.string "Essaie de le retrouver là-bas.$"

NewBarkTown_Lab_Text_ElmWaitingEggHatch:
	.string "ELM : Dis, cet ŒUF a-t-il changé\n"
	.string "un peu ?$"

NewBarkTown_Lab_Text_ElmThoughtEggHatched:
	.string "{PLAYER} ? Je croyais que l'ŒUF\n"
	.string "avait éclos.\p"
	.string "Où est le POKéMON ?$"

NewBarkTown_Lab_Text_ShowTogepi1:
	.string "ELM : {PLAYER}, tu as l'air en forme !$"

NewBarkTown_Lab_Text_ShowTogepi2:
	.string "Quoi ? Ce POKéMON !?!$"

NewBarkTown_Lab_Text_ShowTogepi3:
	.string "L'ŒUF a éclos ! Donc, les POKéMON\n"
	.string "naissent des ŒUFS…\p"
	.string "Non, peut-être que ce n'est pas le cas\n"
	.string "pour tous les POKéMON.\p"
	.string "Wow, il reste encore beaucoup de\n"
	.string "recherches à faire.$"

NewBarkTown_Lab_Text_ElmGiveEverstone1:
	.string "Merci, {PLAYER} ! Tu nous aides à\n"
	.string "percer les mystères des POKéMON !\p"
	.string "Je veux que tu prennes ceci en\n"
	.string "signe de notre reconnaissance.$"

NewBarkTown_Lab_Text_ElmGiveEverstone2:
	.string "C'est une PIERRE STASE.\p"
	.string "Certaines espèces de POKéMON évoluent\n"
	.string "quand elles atteignent certains niveaux.\p"
	.string "Un POKéMON tenant la PIERRE STASE\n"
	.string "n'évoluera pas.\p"
	.string "Donne-la à un POKéMON que tu ne veux\n"
	.string "pas voir évoluer.$"

NewBarkTown_Lab_Text_ElmCallYou:
	.string "ELM : {PLAYER}, je t'appellerai si\n"
	.string "quelque chose arrive.$"

NewBarkTown_Lab_Text_AideAfterTheft:
	.string "…soupir… Ce POKéMON volé…\p"
	.string "Je me demande comment il va.\p"
	.string "On dit qu'un POKéMON élevé par une\n"
	.string "mauvaise personne devient mauvais lui-même.$"

NewBarkTown_Lab_Text_ElmGiveMasterBall1:
	.string "ELM : Salut, {PLAYER} !\p"
	.string "Grâce à toi, mes recherches\n"
	.string "avancent bien !\p"
	.string "Prends ceci en signe de ma\n"
	.string "reconnaissance.$"

NewBarkTown_Lab_Text_ElmGiveMasterBall2:
	.string "La MASTER BALL est la meilleure !\p"
	.string "C'est la BALL ultime ! Elle attrapera\n"
	.string "n'importe quel POKéMON sans faute.\p"
	.string "Elle n'est donnée qu'aux chercheurs\n"
	.string "POKéMON reconnus.\p"
	.string "Je pense que tu en feras bien meilleur\n"
	.string "usage que moi, {PLAYER} !$"

NewBarkTown_Lab_Text_KimonoGirls:
	.string "Au fait...\n"
	.string "Un groupe de magnifiques KIMONO\l"
	.string "GIRLS te cherchait.\p"
	.string "Elles m'ont dit qu'elles\n"
	.string "t'attendaient au\l"
	.string "THÉÂTRE DANSANT d'IRISIA.\p"
	.string "Je sais que tu as traversé beaucoup\n"
	.string "de choses depuis que cet ŒUF t'a\l"
	.string "impliqué dans tout ça...\p"
	.string "J'espère que tu iras jusqu'au bout !$"

NewBarkTown_Lab_Text_KimonoWaiting:
	.string "PROF. ELM : Les KIMONO\n"
	.string "GIRLS t'attendent au\l"
	.string "THÉÂTRE DANSANT d'IRISIA.$"

NewBarkTown_Lab_Text_League:
	.string "PROF. ELM : Hahaha...\n"
	.string "Bien joué !\p"
	.string "Ce rare Œuf t'a causé pas mal de\n"
	.string "problèmes, hein ?\p"
	.string "Les KIMONO GIRLS ont dit quelque chose\n"
	.string "à mon sujet ?\p"
	.string "Je n'ai rien à voir avec ça.\p"
	.string "Tu as pris ta décision et tu es\n"
	.string "allé jusqu'au bout.\p"
	.string "Après tout ce que tu as fait, tu devrais\n"
	.string "pouvoir affronter la Ligue maintenant !\p"
	.string "Tu devrais te diriger vers le Plateau\n"
	.string "Indigo !\p"
	.string "Tu sais comment y aller ?\n"
	.string "Suis la ROUTE 27 jusqu'à la ROUTE 26.\p"
	.string "Une fois là-bas, va tout droit vers le nord !$"

NewBarkTown_Lab_Text_ElmGiveTicket1:
	.string "ELM : {PLAYER} ! Te voilà !\p"
	.string "Je t'ai appelé car j'ai\n"
	.string "quelque chose pour toi.\p"
	.string "Regarde ! C'est un S.S.TICKET.\p"
	.string "Maintenant tu peux attraper des POKéMON\n"
	.string "à KANTO.$"

NewBarkTown_Lab_Text_ElmGiveTicket2:
	.string "Le bateau part d'OLIVILLE\n"
	.string "VILLE.\p"
	.string "Mais tu le savais déjà,\n"
	.string "{PLAYER}.\p"
	.string "Après tout, tu as voyagé partout\n"
	.string "avec tes POKéMON.\p"
	.string "Donne le bonjour au PROF. CHEN à\n"
	.string "KANTO !$"

NewBarkTown_Lab_Text_LabMonEgg:
	.string "C'est l'ŒUF de POKéMON étudié\n"
	.string "par le PROF. ELM.$"

NewBarkTown_Lab_Text_AideGivePotion:
	.string "{PLAYER}, je veux que tu prennes\n"
	.string "ça pour ta mission.$"

NewBarkTown_Lab_Text_AideAlwaysBusy:
	.string "Nous ne sommes que trois, alors\n"
	.string "nous sommes toujours occupés.$"

NewBarkTown_Lab_Text_AideSave:
	.string "N'oublie pas de sauvegarder ta partie\n"
	.string "régulièrement !\p"
	.string "Appuie sur le bouton START, puis\n"
	.string "SAUVEGARDE la partie !$"

NewBarkTown_Lab_Text_AideTheftTestimony:
	.string "Il y a eu un grand bruit\n"
	.string "dehors…\p"
	.string "Quand nous sommes sortis voir,\n"
	.string "quelqu'un a volé un POKéMON.\p"
	.string "C'est incroyable que quelqu'un\n"
	.string "puisse faire ça !\p"
	.string "…soupir… Ce POKéMON volé…\p"
	.string "Je me demande comment il va.\p"
	.string "On dit qu'un POKéMON élevé par une\n"
	.string "mauvaise personne devient mauvais lui-même.$"

NewBarkTown_Lab_Text_AideGiveBalls:
	.string "{PLAYER} !\p"
	.string "Utilise ceci pour ta quête Pokédex !$"

NewBarkTown_Lab_Text_AideExplainBalls:
	.string "Pour compléter ton Pokédex, tu\n"
	.string "dois attraper des POKéMON.\p"
	.string "Lance des POKé BALLS sur les POKéMON\n"
	.string "sauvages pour les attraper.$"

NewBarkTown_Lab_Text_Officer1:
	.string "J'ai entendu dire qu'un POKéMON a été volé\n"
	.string "ici…\p"
	.string "Je recueillais justement des\n"
	.string "informations auprès du PROF. ELM.\p"
	.string "Apparemment, c'était un jeune\n"
	.string "homme aux longs cheveux rouges…\p"
	.string "Quoi ?\p"
	.string "Tu as affronté un dresseur comme\n"
	.string "ça ?\p"
	.string "As-tu par hasard obtenu son\n"
	.string "nom ?$"

NewBarkTown_Lab_Text_Officer2:
	.string "OK ! Donc SILVER était son nom.\p"
	.string "Merci d'aider mon\n"
	.string "enquête !$"

NewBarkTown_Lab_Text_OfficerNo:
	.string "Tu as forcément eu son nom ?!$"

NewBarkTown_Lab_Text_Elm_CallMe:
	.string "Ah, {PLAYER} !\p"
	.string "Comment avance ton POKéDEX ?\n"
	.string "Je suis occupé pour l'instant, mais appelle-moi\l"
	.string "quand tu veux et je vérifierai tes progrès !$"
