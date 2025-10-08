.set LOCALID_CAPT_STERN, 4
.set LOCALID_SS_TIDAL, 5
.set LOCALID_GRUNT, 6
.set LOCALID_ARCHIE, 7
.set LOCALID_SUBMARINE, 8

SlateportCity_Harbor_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SlateportCity_Harbor_OnTransition
	.byte 0

SlateportCity_Harbor_OnTransition:
	setescapewarp MAP_SLATEPORT_CITY, 28, 13
	setvar VAR_TEMP_1, 0
	call_if_eq VAR_SLATEPORT_HARBOR_STATE, 1, SlateportCity_Harbor_EventScript_ReadyAquaEscapeScene
	call_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_Harbor_EventScript_ShowSSTidal
	end

SlateportCity_Harbor_EventScript_ShowSSTidal::
	clearflag FLAG_GARBAGEFLAG
	return

SlateportCity_Harbor_EventScript_ReadyAquaEscapeScene::
	savebgm MUS_ENCOUNTER_AQUA
	setobjectxyperm LOCALID_CAPT_STERN, 12, 13
	setobjectmovementtype LOCALID_CAPT_STERN, MOVEMENT_TYPE_FACE_LEFT
	setflag FLAG_GARBAGEFLAG
	return

SlateportCity_Harbor_EventScript_AquaEscapeTrigger0::
	lockall
	setvar VAR_0x8008, 0
	goto SlateportCity_Harbor_EventScript_AquaEscapeScene
	end

SlateportCity_Harbor_EventScript_AquaEscapeTrigger1::
	lockall
	setvar VAR_0x8008, 1
	goto SlateportCity_Harbor_EventScript_AquaEscapeScene
	end

SlateportCity_Harbor_EventScript_AquaEscapeTrigger2::
	lockall
	setvar VAR_0x8008, 2
	goto SlateportCity_Harbor_EventScript_AquaEscapeScene
	end

SlateportCity_Harbor_EventScript_AquaEscapeTrigger3::
	lockall
	setvar VAR_0x8008, 3
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_Harbor_Movement_PlayerWalkUp
	waitmovement 0
	goto SlateportCity_Harbor_EventScript_AquaEscapeScene
	end

SlateportCity_Harbor_EventScript_AquaEscapeScene::
	applymovement LOCALID_ARCHIE, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	applymovement LOCALID_GRUNT, Common_Movement_WalkInPlaceFasterDown
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox SlateportCity_Harbor_Text_ArchieYouAgainHideoutInLilycove, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT, SlateportCity_Harbor_Movement_AquaBoardSub
	applymovement LOCALID_ARCHIE, SlateportCity_Harbor_Movement_AquaBoardSub
	applymovement LOCALID_SUBMARINE, SlateportCity_Harbor_Movement_SubmarineExit
	waitmovement 0
	removeobject LOCALID_GRUNT
	removeobject LOCALID_ARCHIE
	removeobject LOCALID_SUBMARINE
	setvar VAR_SLATEPORT_HARBOR_STATE, 2
	setflag FLAG_MET_TEAM_AQUA_HARBOR
	setflag FLAG_GARBAGEFLAG
	call_if_eq VAR_0x8008, 0, SlateportCity_Harbor_EventScript_SternApproachPlayer0
	call_if_eq VAR_0x8008, 1, SlateportCity_Harbor_EventScript_SternApproachPlayer1
	call_if_eq VAR_0x8008, 2, SlateportCity_Harbor_EventScript_SternApproachPlayer
	call_if_eq VAR_0x8008, 3, SlateportCity_Harbor_EventScript_SternApproachPlayer
	msgbox SlateportCity_Harbor_Text_CaptSternWhyStealMySubmarine, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_GARBAGEFLAG
	setflag FLAG_GARBAGEFLAG
	copyobjectxytoperm LOCALID_CAPT_STERN
	setobjectmovementtype LOCALID_CAPT_STERN, MOVEMENT_TYPE_FACE_RIGHT
	releaseall
	end

SlateportCity_Harbor_EventScript_SternApproachPlayer0::
	applymovement LOCALID_CAPT_STERN, SlateportCity_Harbor_Movement_SternApproachPlayer0
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

SlateportCity_Harbor_EventScript_SternApproachPlayer1::
	applymovement LOCALID_CAPT_STERN, SlateportCity_Harbor_Movement_SternApproachPlayer1
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

SlateportCity_Harbor_EventScript_SternApproachPlayer::
	applymovement LOCALID_CAPT_STERN, SlateportCity_Harbor_Movement_SternApproachPlayer
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

SlateportCity_Harbor_Movement_AquaBoardSub:
	delay_16
	delay_16
	jump_up
	set_invisible
	step_end

@ Unused, Archie instead shares above identical movement script with Grunt
SlateportCity_Harbor_Movement_ArchieBoardSub:
	delay_16
	delay_16
	jump_up
	set_invisible
	step_end

SlateportCity_Harbor_Movement_SubmarineExit:
	delay_16
	delay_16
	delay_16
	delay_16
	walk_right
	walk_right
	walk_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

SlateportCity_Harbor_Movement_SternApproachPlayer0:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

SlateportCity_Harbor_Movement_SternApproachPlayer1:
	walk_left
	walk_left
	walk_up
	walk_left
	step_end

SlateportCity_Harbor_Movement_SternApproachPlayer:
	walk_left
	walk_left
	walk_left
	step_end

SlateportCity_Harbor_Movement_PlayerWalkUp:
	walk_up
	step_end

SlateportCity_Harbor_EventScript_FerryAttendant::
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_Harbor_EventScript_AskForTicket
	msgbox SlateportCity_Harbor_Text_FerryServiceUnavailable, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_AskForTicket::
	msgbox SlateportCity_Harbor_Text_MayISeeYourTicket, MSGBOX_DEFAULT
	message SlateportCity_Harbor_Text_FlashedTicketWhereTo
	waitmessage
	goto SlateportCity_Harbor_EventScript_ChooseDestination
	end

SlateportCity_Harbor_EventScript_ChooseDestination::
	goto_if_set FLAG_MET_SCOTT_ON_SS_TIDAL, SlateportCity_Harbor_EventScript_ChooseDestinationWithBattleFrontier
	multichoicedefault 18, 8, MULTI_SSTIDAL_SLATEPORT_NO_BF, 2, FALSE
	switch VAR_RESULT
	case 0, SlateportCity_Harbor_EventScript_Lilycove
	case 1, SlateportCity_Harbor_EventScript_CancelDestinationSelect
	case MULTI_B_PRESSED, SlateportCity_Harbor_EventScript_CancelDestinationSelect
	end

SlateportCity_Harbor_EventScript_ChooseDestinationWithBattleFrontier::
	multichoicedefault 17, 6, MULTI_SSTIDAL_SLATEPORT_WITH_BF, 2, FALSE
	switch VAR_RESULT
	case 0, SlateportCity_Harbor_EventScript_Lilycove
	case 1, SlateportCity_Harbor_EventScript_BattleFrontier
	case 2, SlateportCity_Harbor_EventScript_CancelDestinationSelect
	case MULTI_B_PRESSED, SlateportCity_Harbor_EventScript_CancelDestinationSelect
	end

@ Unused. Should be impossible for player to reach Ferry without having received SS Tidal ticket
SlateportCity_Harbor_EventScript_NoTicket::
	msgbox SlateportCity_Harbor_Text_YouMustHaveTicket, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_Lilycove::
	msgbox SlateportCity_Harbor_Text_LilycoveItIs, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SlateportCity_Harbor_EventScript_ChooseNewDestination
	setvar VAR_SS_TIDAL_STATE, SS_TIDAL_BOARD_SLATEPORT
	call SlateportCity_Harbor_EventScript_BoardFerry
	warp MAP_SS_TIDAL_CORRIDOR, 1, 10
	waitstate
	release
	end

SlateportCity_Harbor_EventScript_BattleFrontier::
	msgbox SlateportCity_Harbor_Text_BattleFrontierItIs, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SlateportCity_Harbor_EventScript_ChooseNewDestination
	call SlateportCity_Harbor_EventScript_BoardFerry
	warp MAP_BATTLE_FRONTIER_OUTSIDE_WEST, 19, 67
	waitstate
	release
	end

SlateportCity_Harbor_EventScript_ChooseNewDestination::
	message SlateportCity_Harbor_Text_WhereWouldYouLikeToGo
	waitmessage
	goto SlateportCity_Harbor_EventScript_ChooseDestination
	end

SlateportCity_Harbor_EventScript_BoardFerry::
	msgbox SlateportCity_Harbor_Text_PleaseBoardFerry, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 30
	hideobjectat VAR_LAST_TALKED, MAP_SLATEPORT_CITY_HARBOR
	call_if_eq VAR_FACING, DIR_NORTH, SlateportCity_Harbor_EventScript_BoardFerryNorth
	call_if_eq VAR_FACING, DIR_EAST, SlateportCity_Harbor_EventScript_BoardFerryEast
	delay 30
	hideobjectat OBJ_EVENT_ID_PLAYER, 0
	setvar VAR_0x8004, LOCALID_SS_TIDAL
	call Common_EventScript_FerryDepart
	return

SlateportCity_Harbor_EventScript_CancelDestinationSelect::
	msgbox SlateportCity_Harbor_Text_SailAnotherTime, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_BoardFerryEast::
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_Harbor_Movement_BoardFerryEast
	waitmovement 0
	return

SlateportCity_Harbor_EventScript_BoardFerryNorth::
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_Harbor_Movement_BoardFerryNorth
	waitmovement 0
	return

SlateportCity_Harbor_Movement_BoardFerryEast:
	walk_right
	walk_in_place_faster_up
	step_end

SlateportCity_Harbor_Movement_BoardFerryNorth:
	walk_up
	step_end

SlateportCity_Harbor_EventScript_Sailor::
	lock
	faceplayer
	goto_if_unset FLAG_SYS_GAME_CLEAR, SlateportCity_Harbor_EventScript_SailorNoAbnormalWeather
	setvar VAR_0x8004, 0
	call_if_set FLAG_DEFEATED_KYOGRE, SlateportCity_Harbor_EventScript_CountDefeatedLegendary
	call_if_set FLAG_DEFEATED_GROUDON, SlateportCity_Harbor_EventScript_CountDefeatedLegendary
	goto_if_eq VAR_0x8004, 2, SlateportCity_Harbor_EventScript_SailorNoAbnormalWeather  @ Defeated both
	msgbox SlateportCity_Harbor_Text_AbnormalWeather, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_SailorNoAbnormalWeather::
	msgbox SlateportCity_Harbor_Text_LoveToGoDeepUnderwaterSomeday, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_CountDefeatedLegendary::
	addvar VAR_0x8004, 1
	return

SlateportCity_Harbor_EventScript_FatMan::
	msgbox SlateportCity_Harbor_Text_SubTooSmallForMe, MSGBOX_NPC
	end

SlateportCity_Harbor_EventScript_CaptStern::
	lock
	faceplayer
	goto_if_set FLAG_BADGE07_GET, SlateportCity_Harbor_EventScript_CaptSternFerryOrScannerComment
	goto_if_set FLAG_EVIL_TEAM_ESCAPED_STERN_SPOKE, SlateportCity_Harbor_EventScript_NeedDive
	goto_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, SlateportCity_Harbor_EventScript_TeamAquaLeftNeedDive
	goto_if_eq VAR_SLATEPORT_HARBOR_STATE, 2, SlateportCity_Harbor_EventScript_WhyStealSubmarine
	msgbox SlateportCity_Harbor_Text_SameThugsTriedToRobAtMuseum, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_Harbor_EventScript_WhyStealSubmarine::
	msgbox SlateportCity_Harbor_Text_CaptSternWhyStealMySubmarine, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_TeamAquaLeftNeedDive::
	setflag FLAG_EVIL_TEAM_ESCAPED_STERN_SPOKE
	msgbox SlateportCity_Harbor_Text_TeamAquaLeftNeedDive, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_NeedDive::
	msgbox SlateportCity_Harbor_Text_NeedDiveToCatchSub, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_CaptSternFerryOrScannerComment::
	goto_if_eq VAR_TEMP_1, 1, SlateportCity_Harbor_EventScript_TradedScanner
	checkitem ITEM_SCANNER
	goto_if_eq VAR_RESULT, TRUE, SlateportCity_Harbor_EventScript_AskToTradeScanner
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_Harbor_EventScript_FerryFinished
	msgbox SlateportCity_Harbor_Text_WontBeLongBeforeWeFinishFerry, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_FerryFinished::
	msgbox SlateportCity_Harbor_Text_FinishedMakingFerry, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_AskToTradeScanner::
	message SlateportCity_Harbor_Text_WouldYouTradeScanner
	waitmessage
	goto SlateportCity_Harbor_EventScript_ChooseScannerTrade
	end

SlateportCity_Harbor_EventScript_ChooseScannerTrade::
	multichoice 0, 0, MULTI_STERN_DEEPSEA, FALSE
	switch VAR_RESULT
	case 0, SlateportCity_Harbor_EventScript_DeepSeaTooth
	case 1, SlateportCity_Harbor_EventScript_DeepSeaScale
	case 2, SlateportCity_Harbor_EventScript_DeclineTrade
	case MULTI_B_PRESSED, SlateportCity_Harbor_EventScript_DeclineTrade
	end

SlateportCity_Harbor_EventScript_DeepSeaTooth::
	msgbox SlateportCity_Harbor_Text_TradeForDeepSeaTooth, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SlateportCity_Harbor_EventScript_ChooseDifferentTrade
	giveitem ITEM_DEEP_SEA_TOOTH
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	removeitem ITEM_SCANNER
	msgbox SlateportCity_Harbor_Text_HandedScannerToStern, MSGBOX_DEFAULT
	setflag FLAG_EXCHANGED_SCANNER
	goto SlateportCity_Harbor_EventScript_TradedScanner
	end

SlateportCity_Harbor_EventScript_DeepSeaScale::
	msgbox SlateportCity_Harbor_Text_TradeForDeepSeaScale, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SlateportCity_Harbor_EventScript_ChooseDifferentTrade
	giveitem ITEM_DEEP_SEA_SCALE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	removeitem ITEM_SCANNER
	msgbox SlateportCity_Harbor_Text_HandedScannerToStern, MSGBOX_DEFAULT
	setflag FLAG_EXCHANGED_SCANNER
	goto SlateportCity_Harbor_EventScript_TradedScanner
	end

SlateportCity_Harbor_EventScript_DeclineTrade::
	msgbox SlateportCity_Harbor_Text_IfYouWantToTradeLetMeKnow, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_ChooseDifferentTrade::
	message SlateportCity_Harbor_Text_WhichOneDoYouWant
	waitmessage
	goto SlateportCity_Harbor_EventScript_ChooseScannerTrade
	end

SlateportCity_Harbor_EventScript_TradedScanner::
	setvar VAR_TEMP_1, 1
	msgbox SlateportCity_Harbor_Text_ThisWillHelpResearch, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_Text_FerryServiceUnavailable:
	.string "Je vous demande pardon ?\n"
	.string "Vous cherchez un bateau ?\p"
	.string "Je suis désolé, le service de ferry\n"
	.string "n'est pas disponible pour le moment…$"

SlateportCity_Harbor_Text_MayISeeYourTicket:
	.string "Bonjour, vous venez pour le ferry ?\n"
	.string "Puis-je voir votre TICKET ?$"

SlateportCity_Harbor_Text_YouMustHaveTicket:
	.string "{PLAYER} n'a pas de TICKET…\p"
	.string "Je suis vraiment désolé.\p"
	.string "Vous devez avoir un TICKET pour\n"
	.string "monter à bord du ferry.$"

SlateportCity_Harbor_Text_FlashedTicketWhereTo:
	.string "{PLAYER} montre le TICKET.\p"
	.string "Parfait ! C'est tout ce qu'il faut !\p"
	.string "Et où souhaitez-vous aller ?$"

SlateportCity_Harbor_Text_SailAnotherTime:
	.string "Veuillez voyager avec nous une autre fois !$"

SlateportCity_Harbor_Text_LilycoveItIs:
	.string "POURTOURDEMER, alors !$"

SlateportCity_Harbor_Text_BattleFrontierItIs:
	.string "ZONE DE COMBAT, alors !$"

SlateportCity_Harbor_Text_PleaseBoardFerry:
	.string "Veuillez monter à bord du ferry et\n"
	.string "attendre le départ.$"

SlateportCity_Harbor_Text_WhereWouldYouLikeToGo:
	.string "Alors, où souhaitez-vous aller ?$"

SlateportCity_Harbor_Text_LoveToGoDeepUnderwaterSomeday:
	.string "Un voyage au fond de la mer…\n"
	.string "Je me demande ce que ça fait ?\p"
	.string "J'aimerais tant aller sous l'eau\n"
	.string "comme ça un jour.$"

SlateportCity_Harbor_Text_AbnormalWeather:
	.string "Pour qu'un bateau navigue en sécurité,\n"
	.string "il faut connaître la météo !\p"
	.string "À propos, j'ai entendu quelque chose\n"
	.string "d'un gars à l'INSTITUT Météo.\p"
	.string "Il disait que des phénomènes météo\n"
	.string "anormaux ont été signalés partout !\p"
	.string "Vous devriez aller à l'INSTITUT Météo\n"
	.string "et vous renseigner !$"

SlateportCity_Harbor_Text_SubTooSmallForMe:
	.string "Je voulais accompagner le CAPT. PORTO\n"
	.string "pour explorer le plancher océanique.\p"
	.string "Mais le sous-marin est trop petit pour moi.\p"
	.string "Si je rentrais dedans, il n'y aurait plus\n"
	.string "de place pour le CAPITAINE…$"

SlateportCity_Harbor_Text_SameThugsTriedToRobAtMuseum:
	.string "CAPT. PORTO : Ces voyous…\p"
	.string "Ce sont les mêmes qui ont essayé de voler\n"
	.string "le COLIS DEVON au MUSÉE.$"

SlateportCity_Harbor_Text_ArchieYouAgainHideoutInLilycove:
	.string "ARTHUR : Oh ?\n"
	.string "Encore toi…\p"
	.string "Tu es tenace pour nous avoir retrouvés ici,\n"
	.string "je te l'accorde.\p"
	.string "Mais maintenant…\n"
	.string "Personne ne peut nous arrêter ! Personne !\p"
	.string "Ou alors, tu vas nous suivre jusqu'à notre\n"
	.string "PLANQUE à POURTOURDEMER ?\p"
	.string "Fwahahahaha…$"

SlateportCity_Harbor_Text_CaptSternWhyStealMySubmarine:
	.string "CAPT. PORTO : Pourquoi…\p"
	.string "Pourquoi la TEAM AQUA volerait-elle mon\n"
	.string "SOUS-MARIN EXPLORATEUR 1 ?\p"
	.string "Ils ne peuvent pas vouloir le POKéMON\n"
	.string "endormi au fond de la mer…\p"
	.string "Mais même si je les poursuivais,\n"
	.string "je n'aurais aucune chance contre eux…$"

SlateportCity_Harbor_Text_TeamAquaLeftNeedDive:
	.string "CAPT. PORTO : Oh, {PLAYER}{KUN}…\p"
	.string "Bon… La TEAM AQUA est partie avant que tu\n"
	.string "ne puisses les arrêter…\p"
	.string "Oh, non, ne t'en veux pas.\n"
	.string "Tu n'es pas responsable de ça.\p"
	.string "Essayer de rattraper un sous-marin…\n"
	.string "C'est impossible pour la plupart des gens.\p"
	.string "Il te faudrait un POKéMON qui connaît\n"
	.string "PLONGÉE…\p"
	.string "Peut-être si tu allais à ALGATIA…\p"
	.string "Beaucoup de plongeurs vivent là-bas, alors\n"
	.string "quelqu'un pourrait t'apprendre…$"

SlateportCity_Harbor_Text_NeedDiveToCatchSub:
	.string "CAPT. PORTO : Essayer de rattraper un\n"
	.string "sous-marin… C'est impossible.\p"
	.string "Il te faudrait un POKéMON qui connaît\n"
	.string "PLONGÉE…\p"
	.string "Peut-être si tu allais à ALGATIA…\p"
	.string "Beaucoup de plongeurs vivent là-bas, alors\n"
	.string "quelqu'un pourrait t'apprendre…$"

SlateportCity_Harbor_Text_WontBeLongBeforeWeFinishFerry:
	.string "CAPT. PORTO : Ah, oui.\n"
	.string "MR. MARCO est venu à notre CHANTIER NAVAL.\p"
	.string "Ce ne sera plus très long avant que nous\n"
	.string "ayons fini de construire le ferry !$"

SlateportCity_Harbor_Text_FinishedMakingFerry:
	.string "CAPT. PORTO : {PLAYER}{KUN} !\p"
	.string "Nous avons enfin terminé la construction\n"
	.string "du ferry M.S. MARÉE !\p"
	.string "Nous n'aurions pas pu le faire sans\n"
	.string "ton ami MR. MARCO.\p"
	.string "Va donc faire une petite croisière dessus !$"

SlateportCity_Harbor_Text_WouldYouTradeScanner:
	.string "CAPT. PORTO : Oh ?\n"
	.string "{PLAYER}{KUN}, cet objet que tu as…\p"
	.string "C'est un SCANNER ! Ça nous aiderait\n"
	.string "beaucoup dans nos explorations.\p"
	.string "{PLAYER}{KUN}, échangerais-tu ton\n"
	.string "SCANNER contre quelque chose ?\p"
	.string "Par exemple, une DENT OCÉAN ou\n"
	.string "une ÉCAILLE OCÉAN que j'ai ?$"

SlateportCity_Harbor_Text_IfYouWantToTradeLetMeKnow:
	.string "CAPT. PORTO : Tu es sûr ?\n"
	.string "Ça ne te sert à rien, {PLAYER}{KUN}…\p"
	.string "Bon, d'accord. Si tu veux échanger\n"
	.string "ton SCANNER, fais-le moi savoir.$"

SlateportCity_Harbor_Text_TradeForDeepSeaTooth:
	.string "CAPT. PORTO : Tu veux donc l'échanger\n"
	.string "contre ma DENT OCÉAN ?$"

SlateportCity_Harbor_Text_TradeForDeepSeaScale:
	.string "CAPT. PORTO : Tu veux donc l'échanger\n"
	.string "contre mon ÉCAILLE OCÉAN ?$"

SlateportCity_Harbor_Text_WhichOneDoYouWant:
	.string "CAPT. PORTO : Laquelle veux-tu ?$"

SlateportCity_Harbor_Text_HandedScannerToStern:
	.string "{PLAYER} donne le SCANNER à\n"
	.string "CAPT. PORTO.$"

SlateportCity_Harbor_Text_ThisWillHelpResearch:
	.string "CAPT. PORTO : Merci, {PLAYER}{KUN} !\n"
	.string "Ça va beaucoup aider nos recherches !$"
