.set LOCALID_WALLY, 6
.set LOCALID_WALLYS_UNCLE, 7
.set LOCALID_SCOTT, 11

MauvilleCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MauvilleCity_OnTransition
	.byte 0

MauvilleCity_OnTransition:
	setflag FLAG_VISITED_BLACKTHORN_CITY
	clearflag FLAG_FORCE_MIRAGE_TOWER_VISIBLE
	clearflag FLAG_GARBAGEFLAG
	setflag FLAG_SYS_TV_START
	clearflag FLAG_MAUVILLE_GYM_BARRIERS_STATE
	setvar VAR_GARBAGEVAR, 0
	call_if_set FLAG_GOT_TM_THUNDERBOLT_FROM_WATTSON, MauvilleCity_EventScript_MoveWattsonBackToGym
	end

MauvilleCity_EventScript_MoveWattsonBackToGym::
	clearflag FLAG_GARBAGEFLAG
	setflag FLAG_GARBAGEFLAG
	setflag FLAG_WATTSON_REMATCH_AVAILABLE
	return

MauvilleCity_EventScript_MagnezoneEvo::
	msgbox MauvilleCity_EventScript_MagnezoneEvo_Text, MSGBOX_NPC
	end

MauvilleCity_EventScript_MagnezoneEvo_Text:
	.string "Savais-tu que MAGNETON peut évoluer ?\n"
	.string "Tu sais comment ?\p"
	.string "Parce que… j'aimerais bien le savoir.\p"
	.string "Je sais que c'est lié à une\n"
	.string "PIERRE. Une PIERRE FOUDRE, pour être précis !\p"
	.string "Mais il ne fallait pas l'utiliser.\n"
	.string "C'était en combattant ? En la tenant ?\l"
	.string "Je n'en ai vraiment aucune idée…$"

MauvilleCity_EventScript_Boy::
	msgbox MauvilleCity_Text_NurseHurtMonBackToHealth, MSGBOX_NPC
	end

MauvilleCity_EventScript_Maniac::
	msgbox MauvilleCity_Text_AllSortsOfPeopleComeThrough, MSGBOX_NPC
	end

MauvilleCity_EventScript_Woman::
	msgbox MauvilleCity_Text_RydelVeryGenerous, MSGBOX_NPC
	end

MauvilleCity_EventScript_RichBoy::
	msgbox MauvilleCity_Text_PokemonCanJumpYouOnBike, MSGBOX_NPC
	end

MauvilleCity_EventScript_CitySign::
	msgbox MauvilleCity_Text_CitySign, MSGBOX_SIGN
	end

MauvilleCity_EventScript_GymSign::
	msgbox MauvilleCity_Text_GymSign, MSGBOX_SIGN
	end

MauvilleCity_EventScript_BikeShopSign::
	msgbox MauvilleCity_Text_BikeShopSign, MSGBOX_SIGN
	end

MauvilleCity_EventScript_GameCornerSign::
	msgbox MauvilleCity_Text_GameCornerSign, MSGBOX_SIGN
	end

MauvilleCity_EventScript_SchoolKidM::
	lock
	faceplayer
	goto_if_set FLAG_TV_EXPLAINED, MauvilleCity_EventScript_TVExplained
	msgbox MauvilleCity_Text_ExplainTV, MSGBOX_DEFAULT
	setflag FLAG_TV_EXPLAINED
	release
	end

MauvilleCity_EventScript_TVExplained::
	msgbox MauvilleCity_Text_BeenCheckingOutTV, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_WallysUncle::
	lock
	faceplayer
	goto_if_set FLAG_DECLINED_WALLY_BATTLE_MAUVILLE, MauvilleCity_EventScript_UncleAskPlayerToBattleWally
	msgbox MauvilleCity_Text_UncleHesTooPeppy, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_WALLYS_UNCLE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MauvilleCity_EventScript_UncleAskPlayerToBattleWally::
	msgbox MauvilleCity_Text_UncleCanYouBattleWally, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_WALLYS_UNCLE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MauvilleCity_EventScript_Wally::
	lockall
	goto_if_set FLAG_DECLINED_WALLY_BATTLE_MAUVILLE, MauvilleCity_EventScript_WallyRequestBattleAgain
	applymovement LOCALID_WALLY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox MauvilleCity_Text_WallyWantToChallengeGym, MSGBOX_DEFAULT
	msgbox MauvilleCity_Text_UncleYourePushingIt, MSGBOX_DEFAULT
	msgbox MauvilleCity_Text_WallyWeCanBeatAnyone, MSGBOX_DEFAULT
	applymovement LOCALID_WALLY, Common_Movement_FacePlayer
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_WALLY, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_WALLY, Common_Movement_Delay48
	waitmovement 0
	msgbox MauvilleCity_Text_WallyWillYouBattleMe, MSGBOX_YESNO
	goto MauvilleCity_EventScript_BattleWallyPrompt
	end

MauvilleCity_EventScript_BattleWallyPrompt::
	call_if_eq VAR_RESULT, YES, MauvilleCity_EventScript_BattleWally
	goto_if_eq VAR_RESULT, NO, MauvilleCity_EventScript_DeclineWallyBattle
	closemessage
	switch VAR_FACING
	case DIR_NORTH, MauvilleCity_EventScript_WallyAndUncleExitNorth
	case DIR_EAST, MauvilleCity_EventScript_WallyAndUncleExitEast
	end

MauvilleCity_EventScript_WallyAndUncleExitNorth::
	applymovement OBJ_EVENT_ID_PLAYER, MauvilleCity_Movement_PlayerWatchWallyExitNorth1
	applymovement LOCALID_WALLY, MauvilleCity_Movement_WallyExitNorth1
	applymovement LOCALID_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleExitNorth1
	waitmovement 0
	applymovement LOCALID_WALLY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 30
	applymovement OBJ_EVENT_ID_PLAYER, MauvilleCity_Movement_PlayerFaceUncleNorth
	applymovement LOCALID_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleApproachPlayerNorth
	waitmovement 0
	msgbox MauvilleCity_Text_UncleVisitUsSometime, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, MauvilleCity_Movement_PlayerWatchWallyExitNorth2
	applymovement LOCALID_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleExitNorth2
	applymovement LOCALID_WALLY, MauvilleCity_Movement_WallyExitNorth2
	waitmovement 0
	goto MauvilleCity_EventScript_DefeatedWally
	end

MauvilleCity_EventScript_WallyAndUncleExitEast::
	applymovement OBJ_EVENT_ID_PLAYER, MauvilleCity_Movement_PlayerWatchWallyExitEast1
	applymovement LOCALID_WALLY, MauvilleCity_Movement_WallyExitEast1
	applymovement LOCALID_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleExitEast1
	waitmovement 0
	applymovement LOCALID_WALLY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 30
	applymovement LOCALID_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleApproachPlayerEast
	waitmovement 0
	msgbox MauvilleCity_Text_UncleVisitUsSometime, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, MauvilleCity_Movement_PlayerWatchWallyExitEast2
	applymovement LOCALID_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleExitEast2
	applymovement LOCALID_WALLY, MauvilleCity_Movement_WallyExitEast2
	waitmovement 0
	goto MauvilleCity_EventScript_DefeatedWally
	end

MauvilleCity_EventScript_DefeatedWally::
	removeobject LOCALID_WALLY
	removeobject LOCALID_WALLYS_UNCLE
	clearflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLY
	clearflag FLAG_GARBAGEFLAG
	setflag FLAG_DEFEATED_WALLY_MAUVILLE
	setvar VAR_WALLY_CALL_STEP_COUNTER, 0
	setflag FLAG_ENABLE_FIRST_WALLY_POKENAV_CALL
	call_if_eq VAR_FACING, DIR_NORTH, MauvilleCity_EventScript_ScottApproachPlayerNorth
	call_if_eq VAR_FACING, DIR_EAST, MauvilleCity_EventScript_ScottApproachPlayerEast
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox MauvilleCity_Text_ScottYouDidntHoldBack, MSGBOX_DEFAULT
	closemessage
	addvar VAR_SCOTT_STATE, 1
	call_if_eq VAR_FACING, DIR_NORTH, MauvilleCity_EventScript_ScottExitNorth
	call_if_eq VAR_FACING, DIR_EAST, MauvilleCity_EventScript_ScottExitEast
	removeobject LOCALID_SCOTT
	releaseall
	end

MauvilleCity_EventScript_ScottApproachPlayerNorth::
	addobject LOCALID_SCOTT
	applymovement LOCALID_SCOTT, MauvilleCity_Movement_ScottApproachPlayerNorth
	waitmovement 0
	return

MauvilleCity_EventScript_ScottApproachPlayerEast::
	setobjectxyperm LOCALID_SCOTT, 12, 13
	addobject LOCALID_SCOTT
	applymovement LOCALID_SCOTT, MauvilleCity_Movement_ScottApproachPlayerEast
	waitmovement 0
	return

MauvilleCity_EventScript_ScottExitNorth::
	applymovement OBJ_EVENT_ID_PLAYER, MauvilleCity_Movement_PlayerWatchScottExitNorth
	applymovement LOCALID_SCOTT, MauvilleCity_Movement_ScottExitNorth
	waitmovement 0
	return

MauvilleCity_EventScript_ScottExitEast::
	applymovement OBJ_EVENT_ID_PLAYER, MauvilleCity_Movement_PlayerWatchScottExitEast
	applymovement LOCALID_SCOTT, MauvilleCity_Movement_ScottExitEast
	waitmovement 0
	return

MauvilleCity_EventScript_BattleWally::
	msgbox MauvilleCity_Text_WallyHereICome, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_WALLY_MAUVILLE, MauvilleCity_Text_WallyDefeat
	applymovement LOCALID_WALLY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox MauvilleCity_Text_WallyIllGoBackToVerdanturf, MSGBOX_DEFAULT
	applymovement LOCALID_WALLY, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MauvilleCity_Text_ThankYouNotEnoughToBattle, MSGBOX_DEFAULT
	applymovement LOCALID_WALLY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox MauvilleCity_Text_UncleNoNeedToBeDown, MSGBOX_DEFAULT
	return

MauvilleCity_EventScript_DeclineWallyBattle::
	setflag FLAG_DECLINED_WALLY_BATTLE_MAUVILLE
	msgbox MauvilleCity_Text_WallyMyUncleWontKnowImStrong, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_WallyRequestBattleAgain::
	applymovement LOCALID_WALLY, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MauvilleCity_Text_WallyPleaseBattleMe, MSGBOX_YESNO
	goto MauvilleCity_EventScript_BattleWallyPrompt
	end

MauvilleCity_Movement_WallyExitNorth1:
	walk_left
	walk_left
	walk_down
	walk_down
	walk_left
	step_end

MauvilleCity_Movement_WallyExitEast1:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	step_end

MauvilleCity_Movement_WallyExitNorth2:
	delay_16
	delay_16
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	delay_8
	step_end

MauvilleCity_Movement_WallyExitEast2:
	delay_16
	delay_16
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	delay_8
	step_end

MauvilleCity_Movement_PlayerWatchWallyExitNorth2:
	delay_16
	delay_8
	walk_in_place_faster_left
	step_end

MauvilleCity_Movement_PlayerWatchWallyExitEast2:
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

MauvilleCity_Movement_PlayerWatchScottExitNorth:
	delay_16
	walk_in_place_faster_left
	step_end

MauvilleCity_Movement_PlayerWatchScottExitEast:
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

MauvilleCity_Movement_PlayerWatchWallyExitEast1:
	delay_16
	walk_in_place_faster_down
	step_end

MauvilleCity_Movement_PlayerWatchWallyExitNorth1:
	delay_16
	walk_in_place_faster_left
	step_end

MauvilleCity_Movement_WallysUncleExitNorth1:
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

MauvilleCity_Movement_WallysUncleExitEast1:
	walk_left
	walk_down
	walk_down
	walk_left
	walk_left
	step_end

MauvilleCity_Movement_PlayerFaceUncleNorth:
	delay_16
	delay_8
	delay_4
	walk_in_place_faster_down
	step_end

MauvilleCity_Movement_WallysUncleApproachPlayerNorth:
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

MauvilleCity_Movement_WallysUncleApproachPlayerEast:
	walk_right
	walk_up
	step_end

MauvilleCity_Movement_WallysUncleExitNorth2:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MauvilleCity_Movement_WallysUncleExitEast2:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MauvilleCity_Movement_ScottApproachPlayerNorth:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_up
	step_end

MauvilleCity_Movement_ScottApproachPlayerEast:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

MauvilleCity_Movement_ScottExitNorth:
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

MauvilleCity_Movement_ScottExitEast:
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

MauvilleCity_EventScript_Wattson::
	lock
	faceplayer
	goto_if_set FLAG_GOT_TM_THUNDERBOLT_FROM_WATTSON, MauvilleCity_EventScript_ReceivedThunderbolt
	goto_if_eq VAR_NEW_MAUVILLE_STATE, 2, MauvilleCity_EventScript_CompletedNewMauville
	goto_if_set FLAG_GOT_BASEMENT_KEY_FROM_WATTSON, MauvilleCity_EventScript_BegunNewMauville
	msgbox MauvilleCity_Text_WattsonNeedFavorTakeKey, MSGBOX_DEFAULT
	giveitem ITEM_BASEMENT_KEY
	setflag FLAG_GOT_BASEMENT_KEY_FROM_WATTSON
	msgbox MauvilleCity_Text_WattsonWontBeChallenge, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_BegunNewMauville::
	msgbox MauvilleCity_Text_WattsonWontBeChallenge, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_CompletedNewMauville::
	msgbox MauvilleCity_Text_WattsonThanksTakeTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_THUNDERBOLT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_TM_THUNDERBOLT_FROM_WATTSON
	msgbox MauvilleCity_Text_WattsonYoungTakeCharge, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_ReceivedThunderbolt::
	msgbox MauvilleCity_Text_WattsonYoungTakeCharge, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_RegisterWallyCall::
	lockall
	pokenavcall MauvilleCity_Text_WallyPokenavCall
	waitmessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox MauvilleCity_Text_RegisteredWally, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_WALLY_MATCH_CALL
	clearflag FLAG_ENABLE_FIRST_WALLY_POKENAV_CALL
	releaseall
	end

MauvilleCity_Text_UncleHesTooPeppy:
	.string "ONCLE : C'est grâce aux POKéMON que\n"
	.string "ce garçon a plus d'énergie, je suppose…\l"
	.string "Mais il est devenu un peu trop énergique…$"

MauvilleCity_Text_WallyWantToChallengeGym:
	.string "WALLY : Oh, ONCLE, s'il te plaît ?\p"
	.string "Je veux défier cette ARENE et voir\n"
	.string "à quel point je me suis amélioré.\p"
	.string "S'il te plaît ? Je peux, s'il te plaît ?$"

MauvilleCity_Text_UncleYourePushingIt:
	.string "ONCLE : Attends un peu, WALLY.\p"
	.string "Depuis que tu vis avec des POKéMON,\n"
	.string "tu es devenu beaucoup plus fort.\p"
	.string "Mais tu ne crois pas que tu vas un peu\n"
	.string "vite à vouloir défier une ARENE ?$"

MauvilleCity_Text_WallyWeCanBeatAnyone:
	.string "WALLY : Je ne vais pas trop vite.\p"
	.string "Si je m'allie avec TARSAL,\n"
	.string "on peut battre n'importe qui !$"

MauvilleCity_Text_WallyWillYouBattleMe:
	.string "WALLY : Oh ! Salut, {PLAYER} !\p"
	.string "Je suis devenu beaucoup plus fort\n"
	.string "depuis notre rencontre.\p"
	.string "{PLAYER}, je veux que toi et mon ONCLE\n"
	.string "le compreniez.\p"
	.string "{PLAYER}, s'il te plaît, veux-tu faire\n"
	.string "un combat avec moi ?$"

MauvilleCity_Text_WallyMyUncleWontKnowImStrong:
	.string "WALLY : Oh… Si tu ne veux pas te battre\n"
	.string "avec moi, {PLAYER}, mon ONCLE ne saura\l"
	.string "pas que je suis vraiment devenu fort.$"

MauvilleCity_Text_UncleCanYouBattleWally:
	.string "ONCLE : {PLAYER}{KUN}, c'est bien ça ?\n"
	.string "Pour WALLY, puis-je te demander de\l"
	.string "combattre avec lui juste cette fois ?\p"
	.string "Je ne pense pas qu'il écoutera la raison\n"
	.string "dans l'état où il est.$"

MauvilleCity_Text_WallyPleaseBattleMe:
	.string "WALLY : {PLAYER}, s'il te plaît !\n"
	.string "Combats-moi, s'il te plaît.$"

MauvilleCity_Text_WallyHereICome:
	.string "WALLY : {PLAYER}, merci.\p"
	.string "D'accord… Me voilà !$"

MauvilleCity_Text_WallyDefeat:
	.string "WALLY : … … … … … … …\p"
	.string "… … … … … … … …\p"
	.string "J'ai perdu…$"

MauvilleCity_Text_WallyIllGoBackToVerdanturf:
	.string "WALLY : ONCLE…\n"
	.string "Je vais retourner à VERDURANDE…$"

MauvilleCity_Text_ThankYouNotEnoughToBattle:
	.string "{PLAYER}, merci.\n"
	.string "Être DRESSEUR, c'est difficile, non ?\p"
	.string "Ce n'est pas suffisant d'avoir des POKéMON\n"
	.string "et de les faire combattre. Ce n'est pas\l"
	.string "ça, être un vrai DRESSEUR.$"

MauvilleCity_Text_UncleNoNeedToBeDown:
	.string "ONCLE : WALLY, il ne faut pas être\n"
	.string "aussi dur avec toi-même.\p"
	.string "Qu'est-ce qui t'empêche de devenir\n"
	.string "de plus en plus fort ?\p"
	.string "Allez, rentrons à la maison.\n"
	.string "Tout le monde t'attend.$"

MauvilleCity_Text_UncleVisitUsSometime:
	.string "ONCLE : {PLAYER}{KUN}, je viens de réaliser\n"
	.string "que tu dois être le DRESSEUR qui a veillé\l"
	.string "sur WALLY quand il a attrapé son POKéMON.\p"
	.string "Pourquoi ne viendrais-tu pas nous voir à\n"
	.string "VERDURANDE un de ces jours ?\l"
	.string "Je suis sûr que WALLY en serait ravi.$"


MauvilleCity_Text_WallyPokenavCall:
	.string "… … … … … …\n"
	.string "… … … … … Bip !\p"
	.string "WALLY : Oh, bonjour, {PLAYER} !\p"
	.string "Je voulais juste te dire que\n"
	.string "mon oncle m'a acheté un POKéNAV !\p"
	.string "Maintenant, je peux te contacter\n"
	.string "quand je veux, {PLAYER} !\p"
	.string "… … … … … …\n"
	.string "… … … … … Clic !$"

MauvilleCity_Text_RegisteredWally:
	.string "WALLY enregistré\n"
	.string "dans le POKéNAV.$"

MauvilleCity_Text_ScottYouDidntHoldBack:
	.string "SCOTT : Hé hé…\n"
	.string "J'ai regardé ce match !\p"
	.string "Tu es ami avec ce garçon, WALLY,\n"
	.string "n'est-ce pas ?\p"
	.string "Mais tu ne t'es pas retenu et tu l'as\n"
	.string "battu de façon impressionnante.\p"
	.string "Oui ! Voilà ce qu'est un vrai combat\n"
	.string "de POKéMON !\p"
	.string "J'idolâtre les DRESSEURS comme ça !\p"
	.string "… … … … … …\n"
	.string "Je t'encouragerai !$"

MauvilleCity_Text_WattsonNeedFavorTakeKey:
	.string "WATTSON : Oh, {PLAYER}{KUN} !\n"
	.string "Tu as l'air plein d'énergie !\l"
	.string "C'est une bonne chose, wahahahaha !\p"
	.string "Bien ! J'ai décidé !\n"
	.string "J'ai besoin d'un service, {PLAYER}{KUN} !\p"
	.string "MAUVILLE possède un secteur souterrain\n"
	.string "appelé NOUVELLE MAUVILLE.\p"
	.string "{PLAYER}{KUN}, j'aimerais que tu y ailles et\n"
	.string "que tu éteignes le GÉNÉRATEUR.\p"
	.string "Le GÉNÉRATEUR fonctionne un peu\n"
	.string "n'importe comment. Ça devient dangereux.\p"
	.string "Tiens, voici la CLEF pour entrer dans\n"
	.string "NOUVELLE MAUVILLE.$"

MauvilleCity_Text_WattsonWontBeChallenge:
	.string "WATTSON : Ne t'inquiète pas pour ça.\n"
	.string "Ce ne sera pas un défi pour toi.\p"
	.string "L'entrée de NOUVELLE MAUVILLE est juste\n"
	.string "à une courte SURF de la ROUTE 110.\p"
	.string "Voilà, tu as ma confiance !\n"
	.string "Wahahahaha !$"

MauvilleCity_Text_WattsonThanksTakeTM:
	.string "WATTSON : Wahahahaha !\p"
	.string "Je le savais, {PLAYER}{KUN} ! Je savais que\n"
	.string "j'avais fait le bon choix en te demandant !\p"
	.string "Voici ma récompense : une CT contenant\n"
	.string "TONNERRE !\p"
	.string "Vas-y, tu l'as bien mérité !$"

MauvilleCity_Text_WattsonYoungTakeCharge:
	.string "WATTSON : Wahahahaha !\p"
	.string "Ça me fait tellement plaisir de voir\n"
	.string "les jeunes prendre les choses en main !$"

MauvilleCity_Text_NurseHurtMonBackToHealth:
	.string "Tu sais, c'est cool d'avoir des combats\n"
	.string "de POKéMON et tout…\p"
	.string "Mais si ton POKéMON est blessé,\n"
	.string "il faut le soigner pour qu'il aille mieux.$"

MauvilleCity_Text_AllSortsOfPeopleComeThrough:
	.string "Les routes de cette ville vont au nord,\n"
	.string "au sud, à l'est et à l'ouest.\p"
	.string "À cause de ça, on voit passer toutes\n"
	.string "sortes de gens ici.$"

MauvilleCity_Text_RydelVeryGenerous:
	.string "Tu es déjà allé chez CYCLES RYDEL ?\p"
	.string "RYDEL, le propriétaire, est un homme\n"
	.string "très généreux.$"

MauvilleCity_Text_PokemonCanJumpYouOnBike:
	.string "Même si tu es à vélo,\n"
	.string "des POKéMON sauvages peuvent t'attaquer.$"

MauvilleCity_Text_CitySign:
	.string "MAUVILLE\n"
	.string "« La ville brillante et pleine de fun ! »$"

MauvilleCity_Text_GymSign:
	.string "ARENE POKéMON DE MAUVILLE\n"
	.string "CHAMPION : WATTSON\l"
	.string "« L'homme joyeusement électrisant ! »$"

MauvilleCity_Text_BikeShopSign:
	.string "« Roule sur le gravier et secoue\n"
	.string "ton âme ! »\l"
	.string "CYCLES RYDEL$"

MauvilleCity_Text_GameCornerSign:
	.string "« L'endroit pour s'amuser ! »\n"
	.string "CASINO DE MAUVILLE$"

MauvilleCity_Text_ExplainTV:
	.string "Salut, tu regardes la télé parfois ?\p"
	.string "Ils ont ajouté plein de nouvelles\n"
	.string "émissions sympas récemment.\p"
	.string "La télé, c'est génial. J'ai vu mes amis\n"
	.string "à la télé par hasard.\p"
	.string "Et parfois, ils te mettent à la télé\n"
	.string "sans te prévenir.\p"
	.string "J'aimerais bien passer à la télé un jour.\p"
	.string "C'est pour ça que tu devrais regarder\n"
	.string "la télé dès que tu peux.$"

MauvilleCity_Text_BeenCheckingOutTV:
	.string "Salut, tu as regardé la télé récemment ?$"
