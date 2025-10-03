.set LOCALID_WOMAN, 8
.set LOCALID_GRUNT_1, 10
.set LOCALID_GRUNT_2, 11
.set LOCALID_GRUNT_3, 12
.set LOCALID_GRUNT_4, 13
.set LOCALID_MAXIE, 14
.set LOCALID_SCOTT, 16
.set LOCALID_JIRACHI, 18

MossdeepCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

MossdeepCity_OnTransition:
	callnative SetTimeBasedEncounters
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_1
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_2
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_3
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_4
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
	end

MossdeepCity_EventScript_Evo::
	msgbox MossdeepCity_EventScript_Evo_Text, MSGBOX_NPC
	end

MossdeepCity_EventScript_Evo_Text:
	.string "Le POKéMON ÉVOLI évolue\n"
	.string "de plusieurs façons différentes.\p"
	.string "Avec une PIERRE FOUDRE, PIERRE FEU,\n"
	.string "PIERRE EAU… Comme, par exemple,\l"
	.string "ÉLEKTEK et MAGMAR.\p"
	.string "Eux aussi évoluent avec des PIERRES.$"

MossdeepCity_EventScript_Evo2::
	msgbox MossdeepCity_EventScript_Evo2_Text, MSGBOX_NPC
	end

MossdeepCity_EventScript_Evo2_Text:
	.string "Ma femme adore le POKéMON ÉVOLI.\p"
	.string "Elle connaît toutes les façons dont\n"
	.string "il peut évoluer. Par exemple, en TENANT\l"
	.string "une PIERRE EAU ou une PIERRE PLANTE.\p"
	.string "Oui, en TENANT, pas en utilisant !\n"
	.string "Tu le savais ? Moi, non.\p"
	.string "Ou en étant HEUREUX le jour ou la nuit.\p"
	.string "Ou en étant mignon tout en utilisant\n"
	.string "une capacité de type FÉE !\p"
	.string "…\p"
	.string "Tu sais où trouver des ÉVOLI ?\n"
	.string "Je devrais peut-être en attraper un pour elle.\p"
	.string "Elle va adorer !$"

MossdeepCity_EventScript_PokefanF::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_DIVE, MossdeepCity_EventScript_PokefanFMagmaGone
	msgbox MossdeepCity_Text_SpaceCenterReceivedLetter, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_PokefanFMagmaGone::
	msgbox MossdeepCity_Text_SpaceCenterLaunchingRockets, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_Sailor::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_DIVE, MossdeepCity_EventScript_SailorMagmaGone
	msgbox MossdeepCity_Text_MossdeepTargetedByMagma, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_SailorMagmaGone::
	msgbox MossdeepCity_Text_FeelReliefOnLand, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_NinjaBoy::
	msgbox MossdeepCity_Text_WailmerWatching, MSGBOX_NPC
	end

MossdeepCity_EventScript_ExpertM::
	msgbox MossdeepCity_Text_LifeNeedsSeaToLive, MSGBOX_NPC
	end

MossdeepCity_EventScript_Girl::
	msgbox MossdeepCity_Text_NiceIfWorldCoveredByFlowers, MSGBOX_NPC
	end

MossdeepCity_EventScript_Woman::
	goto_if_set FLAG_JIRACHI, MossdeepCity_EventScript_Woman2
	msgbox MossdeepCity_Text_SpecialSpaceCenterRock, MSGBOX_NPC
	end

MossdeepCity_EventScript_Woman2::
	msgbox MossdeepCity_Text_SpecialSpaceCenterRock2, MSGBOX_NPC
	end

MossdeepCity_EventScript_WhiteRock::
	msgbox MossdeepCity_Text_ItsAWhiteRock, MSGBOX_SIGN
	closemessage
	goto_if_set FLAG_JIRACHI, MossdeepCity_EventScript_WhiteRockEnd
	goto_if_unset FLAG_EXTRA_LEGENDARIES, MossdeepCity_EventScript_WhiteRockEnd
	goto_if_set FLAG_SYS_GAME_CLEAR, MossdeepCity_EventScript_Jirachi
	end

MossdeepCity_EventScript_WhiteRockEnd::
	end

MossdeepCity_EventScript_Jirachi::
	lockall
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_EventScript_JirachiMoves
	applymovement LOCALID_WOMAN, MossdeepCity_EventScript_JirachiMoves2
	waitmovement 0
	msgbox MossdeepCity_Text_ItsAWhiteRock2, MSGBOX_DEFAULT
	waitmessage
	waitse
	playmoncry SPECIES_JIRACHI, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_JIRACHI, 50
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	applymovement LOCALID_JIRACHI, MossdeepCity_EventScript_JirachiMoves3
	waitmovement 0
	msgbox MossdeepCity_Text_ItsAWhiteRock3, MSGBOX_DEFAULT
	closemessage
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, MossdeepCity_EventScript_JirachiWon
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, MossdeepCity_EventScript_JirachiWon
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, MossdeepCity_EventScript_JirachiRan
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, MossdeepCity_EventScript_JirachiRan
	release
	end

MossdeepCity_EventScript_JirachiWon::
	setflag FLAG_JIRACHI
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	callnative UpdateFollowingPokemon
	goto Common_EventScript_RemoveStaticPokemon
	releaseall
	end

MossdeepCity_EventScript_JirachiRan::
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	applymovement LOCALID_JIRACHI, MossdeepCity_EventScript_JirachiMoves4
	waitmovement 0
	releaseall
	end

MossdeepCity_EventScript_JirachiMoves:
	emote_exclamation_mark
	delay_16
	delay_16
	delay_16
	jump_in_place_up
	delay_16
	delay_16
	delay_16
	delay_16
	step_end

MossdeepCity_EventScript_JirachiMoves2:
	emote_exclamation_mark
	delay_16
	delay_16
	delay_16
	jump_in_place_right
	delay_16
	delay_16
	delay_16
	delay_16
	step_end

MossdeepCity_EventScript_JirachiMoves3:
	delay_16
	delay_16
	delay_16
	set_visible
	walk_down
	step_end

MossdeepCity_EventScript_JirachiMoves4:
	set_invisible
	walk_up
	step_end

MossdeepCity_Text_ItsAWhiteRock2:
	.string "Quelque chose…\p"
	.string "…\p"
	.string "Quelque chose bouge…\n"
	.string "…$"

MossdeepCity_Text_ItsAWhiteRock3:
	.string "Quelque chose t'a sauté dessus\n"
	.string "derrière le rocher blanc !$"

MossdeepCity_EventScript_GymSign::
	msgbox MossdeepCity_Text_GymSign, MSGBOX_SIGN
	end

MossdeepCity_EventScript_CitySign::
	msgbox MossdeepCity_Text_CitySign, MSGBOX_SIGN
	end

MossdeepCity_EventScript_SpaceCenterSign::
	msgbox MossdeepCity_Text_SpaceCenterSign, MSGBOX_SIGN
	end

MossdeepCity_EventScript_VisitedMossdeep::
	setflag FLAG_VISITED_CELADON_CITY
	setvar VAR_TEMP_1, 1
	end

MossdeepCity_EventScript_TeamMagmaEnterSpaceCenter::
	lockall
	applymovement LOCALID_MAXIE, MossdeepCity_Movement_MaxieGestureToSpaceCenter
	waitmovement 0
	applymovement LOCALID_GRUNT_1, MossdeepCity_Movement_GruntFaceSpaceCenter
	applymovement LOCALID_GRUNT_2, MossdeepCity_Movement_GruntFaceSpaceCenter
	applymovement LOCALID_GRUNT_3, MossdeepCity_Movement_GruntFaceSpaceCenter
	applymovement LOCALID_GRUNT_4, MossdeepCity_Movement_GruntFaceSpaceCenter
	waitmovement 0
	applymovement LOCALID_MAXIE, MossdeepCity_Movement_MaxieEnterSpaceCenter
	applymovement LOCALID_GRUNT_1, MossdeepCity_Movement_Grunt1EnterSpaceCenter
	applymovement LOCALID_GRUNT_2, MossdeepCity_Movement_Grunt2EnterSpaceCenter
	applymovement LOCALID_GRUNT_3, MossdeepCity_Movement_Grunt3EnterSpaceCenter
	applymovement LOCALID_GRUNT_4, MossdeepCity_Movement_Grunt4EnterSpaceCenter
	waitmovement 0
	removeobject LOCALID_MAXIE
	removeobject LOCALID_GRUNT_1
	removeobject LOCALID_GRUNT_2
	removeobject LOCALID_GRUNT_3
	removeobject LOCALID_GRUNT_4
	delay 30
	setvar VAR_GARBAGEVAR, 2
	setflag FLAG_GARBAGEFLAG
	releaseall
	end

MossdeepCity_Movement_MaxieGestureToSpaceCenter:
	delay_16
	face_right
	delay_16
	delay_16
	delay_16
	delay_16
	face_left
	delay_16
	delay_16
	step_end

MossdeepCity_Movement_GruntFaceSpaceCenter:
	face_right
	delay_16
	delay_16
	delay_16
	step_end

MossdeepCity_Movement_MaxieEnterSpaceCenter:
	walk_down
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_Movement_Grunt1EnterSpaceCenter:
	delay_16
	delay_8
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_Movement_Grunt2EnterSpaceCenter:
	delay_16
	delay_8
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_Movement_Grunt3EnterSpaceCenter:
	delay_16
	delay_8
	walk_down
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_Movement_Grunt4EnterSpaceCenter:
	delay_16
	delay_8
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_EventScript_Man::
	lock
	faceplayer
	msgbox MossdeepCity_Text_SurfExhilarating, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MossdeepCity_EventScript_KingsRockBoy::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_KINGS_ROCK, MossdeepCity_EventScript_ReceivedKingsRock
	msgbox MossdeepCity_Text_WantKingsRockStevenGaveMe, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MossdeepCity_EventScript_DeclineKingsRock
	msgbox MossdeepCity_Text_YouCanKeepIt, MSGBOX_DEFAULT
	giveitem ITEM_KINGS_ROCK
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_KINGS_ROCK
	release
	end

MossdeepCity_EventScript_ReceivedKingsRock::
	msgbox MossdeepCity_Text_StevensHouseOverThere, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_DeclineKingsRock::
	msgbox MossdeepCity_Text_WhatToDoWithWeirdRock, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_BlackBelt::
	msgbox MossdeepCity_Text_SootopolisNewGymLeader, MSGBOX_NPC
	end

MossdeepCity_EventScript_Scott::
	lock
	faceplayer
	msgbox MossdeepCity_Text_ScottSomethingWrongWithTown, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_NORTH, MossdeepCity_EventScript_ScottExitNorth
	call_if_eq VAR_FACING, DIR_EAST, MossdeepCity_EventScript_ScottExitEast
	addvar VAR_SCOTT_STATE, 1
	removeobject LOCALID_SCOTT
	release
	end

MossdeepCity_EventScript_ScottExitNorth::
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Movement_PlayerWatchScottExit
	applymovement LOCALID_SCOTT, MossdeepCity_Movement_ScottExitNorth
	waitmovement 0
	return

MossdeepCity_EventScript_ScottExitEast::
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Movement_PlayerWatchScottExit
	applymovement LOCALID_SCOTT, MossdeepCity_Movement_ScottExitEast
	waitmovement 0
	return

MossdeepCity_Movement_PlayerWatchScottExit:
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

MossdeepCity_Movement_ScottExitNorth:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MossdeepCity_Movement_ScottExitEast:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MossdeepCity_Text_WantKingsRockStevenGaveMe:
	.string "J'ai eu ça de STEVEN, mais je ne sais\n"
	.string "pas à quoi ça sert.\p"
	.string "Je crois que ça s'appelle ROCHE ROYALE.\n"
	.string "Tu la veux ?$"

MossdeepCity_Text_YouCanKeepIt:
	.string "Pourquoi tu la voudrais ?\n"
	.string "Tu es bizarre.\p"
	.string "Tu peux la garder, mais garde-le secret\n"
	.string "pour STEVEN.$"

MossdeepCity_Text_StevensHouseOverThere:
	.string "La maison de STEVEN est juste là-bas !$"

MossdeepCity_Text_WhatToDoWithWeirdRock:
	.string "Oui, tu penses ça aussi ! Qu'est-ce qu'on\n"
	.string "est censé faire avec une pierre bizarre ?$"

MossdeepCity_Text_WailmerWatching:
	.string "Autour de MOSSDEEP, tu peux voir des\n"
	.string "WAILMER sauvages.\p"
	.string "Ça s'appelle, euh…\n"
	.string "Comment ça s'appelait déjà…\p"
	.string "WAI, WAI, WAI…\p"
	.string "Observation de WAILMER !$"

MossdeepCity_Text_SpaceCenterReceivedLetter:
	.string "Le CENTRE SPATIAL de l'île a lancé de\n"
	.string "grandes fusées.\p"
	.string "Il y a eu une sorte de remue-ménage\n"
	.string "à propos d'une lettre reçue récemment.$"

MossdeepCity_Text_SpaceCenterLaunchingRockets:
	.string "Le CENTRE SPATIAL de l'île a lancé de\n"
	.string "grandes fusées.$"

MossdeepCity_Text_MossdeepTargetedByMagma:
	.string "J'ai entendu d'un copain MARIN que\n"
	.string "la TEAM AQUA s'est installée à NENCRAN.\p"
	.string "J'ai aussi entendu que quelqu'un est venu\n"
	.string "et les a tous battus !\p"
	.string "Mais ici à MOSSDEEP, on est visés par\n"
	.string "la TEAM MAGMA.\p"
	.string "Si tu veux savoir ce qu'ils préparent,\n"
	.string "va visiter le CENTRE SPATIAL.$"

MossdeepCity_Text_FeelReliefOnLand:
	.string "Je suis MARIN, donc la mer est\n"
	.string "évidemment plus importante pour moi.\p"
	.string "Mais tu sais ? Quand je reviens sur la terre\n"
	.string "après un long voyage, je me sens soulagé !$"

MossdeepCity_Text_NiceIfWorldCoveredByFlowers:
	.string "Ce serait bien, non ?\p"
	.string "Si le monde entier était couvert de\n"
	.string "plantes et de fleurs comme cette île ?$"

MossdeepCity_Text_LifeNeedsSeaToLive:
	.string "Toute vie a besoin de la mer pour vivre,\n"
	.string "même si elle vit sur la terre.\p"
	.string "La vie, après son cycle, devient\n"
	.string "terre et retourne à la terre.\p"
	.string "Et la mer est toujours reliée à\n"
	.string "la terre.\p"
	.string "Oui, comme le rivage ici.$"

MossdeepCity_Text_SurfExhilarating:
	.string "Un voyage en bateau, c'est bien.\p"
	.string "Mais traverser la mer avec un POKéMON\n"
	.string "en utilisant SURF…\p"
	.string "Ça, c'est un voyage exaltant !\n"
	.string "Tu n'es pas d'accord, jeune ?$"

MossdeepCity_Text_SpecialSpaceCenterRock:
	.string "Cette pierre a une signification spéciale\n"
	.string "pour les gens du CENTRE SPATIAL.\p"
	.string "Ils l'ont placée ici pour souhaiter que\n"
	.string "leurs fusées volent en sécurité.\p"
	.string "Quand tu fais un vœu, tu utilises quoi ?\n"
	.string "Tu fais un vœu à une étoile ?\p"
	.string "J'utilise un porte-bonheur pour ça.\n"
	.string "C'est ce que je fais.$"

MossdeepCity_Text_SpecialSpaceCenterRock2:
	.string "Quoi ? Ce n'était pas mon vœu !$"

MossdeepCity_Text_ItsAWhiteRock:
	.string "C'est une pierre blanche.\p"
	.string "Elle dégage une énergie mystérieuse…$"

MossdeepCity_Text_GymSign:
	.string "ARÈNE POKéMON DE MOSSDEEP\n"
	.string "CHAMPIONS : LIZA & TATE\p"
	.string "« La combinaison mystique ! »$"

MossdeepCity_Text_CitySign:
	.string "MOSSDEEP CITY\n"
	.string "« Notre slogan : Chérissez les POKéMON ! »$"

MossdeepCity_Text_SpaceCenterSign:
	.string "CENTRE SPATIAL DE MOSSDEEP\n"
	.string "« L'endroit le plus proche de l'espace. »$"

MossdeepCity_Text_ScottSomethingWrongWithTown:
	.string "SCOTT : {PLAYER}{KUN}, tu vas bien ?\n"
	.string "Moi, je vais super !\p"
	.string "J'ai entendu dire que le CHAMPION de\n"
	.string "l'ARÈNE de MOSSDEEP est très fort, alors\l"
	.string "j'ai décidé de venir voir par moi-même.\p"
	.string "Mais il y a quelque chose qui cloche\n"
	.string "dans cette ville.\p"
	.string "Les gens parlent d'une lettre d'avertissement\n"
	.string "et du CENTRE SPATIAL…\p"
	.string "Je ne pense pas que ça me concerne\n"
	.string "de toute façon.$"

MossdeepCity_Text_SootopolisNewGymLeader:
	.string "Ahh… Ça fait du bien de laisser les vagues\n"
	.string "me laver les pieds…\p"
	.string "En parlant des vagues, tu connais la ville\n"
	.string "île SOOTOPOLIS ?\p"
	.string "Je crois que l'ARÈNE là-bas a un nouveau\n"
	.string "CHAMPION.\p"
	.string "On m'a dit que le nouveau CHAMPION a\n"
	.string "déjà été le mentor de WALLACE.$"
