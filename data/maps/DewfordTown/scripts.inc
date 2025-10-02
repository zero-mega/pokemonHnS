@ Sailing to and from Dewford uses local IDs from different maps
@ e.g. Route 104's sail to Dewford script references local IDs from Dewford's map
@ All of these local IDs are labeled here
.equ LOCALID_BRINEY_DEWFORD, 2
.equ LOCALID_BOAT_DEWFORD, 4

.equ LOCALID_BOAT_R109, 1
.equ LOCALID_BRINEY_R109, 2

.equ LOCALID_BOAT_R104, 7
.equ LOCALID_BRINEY_R104, 8

DewfordTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DewfordTown_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

DewfordTown_OnTransition:
	callnative SetTimeBasedEncounters
	setflag FLAG_VISITED_AZALEA_TOWN
	end

DewfordTown_EventScript_Briney::
	lock
	faceplayer
	goto_if_unset FLAG_DELIVERED_STEVEN_LETTER, DewfordTown_EventScript_ReturnToPetalburgPrompt
	message DewfordTown_Text_WhereAreWeBound
	waitmessage
	multichoicedefault 21, 6, MULTI_BRINEY_ON_DEWFORD, 2, FALSE
	switch VAR_RESULT
	case 0, DewfordTown_EventScript_ChoosePetalburg
	case 1, DewfordTown_EventScript_ChooseSlateport
	case 2, DewfordTown_EventScript_CancelSailSelect
	case MULTI_B_PRESSED, DewfordTown_EventScript_CancelSailSelect
	end

DewfordTown_EventScript_ChoosePetalburg::
	msgbox DewfordTown_Text_PetalburgWereSettingSail, MSGBOX_DEFAULT
	closemessage
	goto DewfordTown_EventScript_SailToPetalburg
	release
	end

DewfordTown_EventScript_ChooseSlateport::
	msgbox DewfordTown_Text_SlateportWereSettingSail, MSGBOX_DEFAULT
	closemessage
	goto DewfordTown_EventScript_SailToSlateport
	release
	end

DewfordTown_EventScript_CancelSailSelect::
	msgbox DewfordTown_Text_JustTellMeWhenYouNeedToSetSail, MSGBOX_DEFAULT
	closemessage
	release
	end

DewfordTown_EventScript_ReturnToPetalburgPrompt::
	msgbox DewfordTown_Text_SetSailBackToPetalburg, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, DewfordTown_EventScript_SailBackToPetalburg
	msgbox DewfordTown_Text_GoDeliverIllBeWaiting, MSGBOX_DEFAULT
	release
	end

DewfordTown_EventScript_SailBackToPetalburg::
	msgbox DewfordTown_Text_PetalburgWereSettingSail2, MSGBOX_DEFAULT
	closemessage
	goto DewfordTown_EventScript_SailToPetalburg
	end

DewfordTown_EventScript_Woman::
	msgbox DewfordTown_Text_TinyIslandCommunity, MSGBOX_NPC
	end

DewfordTown_EventScript_TownSign::
	msgbox DewfordTown_Text_TownSign, MSGBOX_SIGN
	end

DewfordTown_EventScript_GymSign::
	msgbox DewfordTown_Text_GymSign, MSGBOX_SIGN
	end

DewfordTown_EventScript_HallSign::
	msgbox DewfordTown_Text_HallSign, MSGBOX_SIGN
	end

DewfordTown_EventScript_OldRodFisherman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_OLD_ROD, DewfordTown_EventScript_HowsFishing
	msgbox DewfordTown_Text_GettingItchToFish, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, DewfordTown_EventScript_GiveOldRod
	goto_if_eq VAR_RESULT, NO, DewfordTown_EventScript_NotGettingItchToFish
	end

DewfordTown_EventScript_GiveOldRod::
	msgbox DewfordTown_Text_GiveYouOneOfMyRods, MSGBOX_DEFAULT
	giveitem ITEM_OLD_ROD
	setflag FLAG_RECEIVED_OLD_ROD
	msgbox DewfordTown_Text_ThrowInFishingAdvice, MSGBOX_DEFAULT
	release
	end

DewfordTown_EventScript_NotGettingItchToFish::
	msgbox DewfordTown_Text_ThatsTooBadThen, MSGBOX_DEFAULT
	release
	end

DewfordTown_EventScript_HowsFishing::
	message DewfordTown_Text_HowsYourFishing
	waitmessage
	multichoice 20, 8, MULTI_HOWS_FISHING, TRUE
	goto_if_eq VAR_RESULT, 0, DewfordTown_EventScript_FishingExcellent
	goto_if_eq VAR_RESULT, 1, DewfordTown_EventScript_FishingNotSoGood
	end

DewfordTown_EventScript_FishingExcellent::
	msgbox DewfordTown_Text_GreatHaulInSomeBigOnes, MSGBOX_DEFAULT
	release
	end

DewfordTown_EventScript_FishingNotSoGood::
	msgbox DewfordTown_Text_FishingAdvice, MSGBOX_DEFAULT
	release
	end

DewfordTown_EventScript_SailToPetalburg::
	call EventScript_BackupMrBrineyLocation
	setobjectsubpriority LOCALID_BRINEY_DEWFORD, MAP_DEWFORD_TOWN, 0
	setobjectsubpriority OBJ_EVENT_ID_PLAYER, MAP_DEWFORD_TOWN, 0
	applymovement LOCALID_BRINEY_DEWFORD, DewfordTown_Movement_BrineyBoardBoat
	waitmovement 0
	removeobject LOCALID_BRINEY_DEWFORD
	applymovement OBJ_EVENT_ID_PLAYER, DewfordTown_Movement_PlayerBoardBoat
	waitmovement 0
	hideobjectat OBJ_EVENT_ID_PLAYER, MAP_DEWFORD_TOWN
	call Common_EventScript_PlayBrineysBoatMusic
	applymovement LOCALID_BOAT_DEWFORD, DewfordTown_Movement_SailToPetalburg
	applymovement OBJ_EVENT_ID_PLAYER, DewfordTown_Movement_SailToPetalburg
	waitmovement 0
	showobjectat OBJ_EVENT_ID_PLAYER, MAP_ROUTE104
	call Common_EventScript_StopBrineysBoatMusic
	applymovement OBJ_EVENT_ID_PLAYER, DewfordTown_Movement_ExitBoatPetalburg
	waitmovement 0
	showobjectat OBJ_EVENT_ID_PLAYER, MAP_ROUTE104
	clearflag FLAG_GARBAGEFLAG
	clearflag FLAG_GARBAGEFLAG
	clearflag FLAG_GARBAGEFLAG
	setflag FLAG_GARBAGEFLAG
	hideobjectat LOCALID_BOAT_DEWFORD, MAP_DEWFORD_TOWN
	setvar VAR_GARBAGEVAR, 2
	resetobjectsubpriority OBJ_EVENT_ID_PLAYER, MAP_DEWFORD_TOWN
	warp MAP_ROUTE104_MR_BRINEYS_HOUSE, 5, 4
	copyvar VAR_GARBAGEVAR, VAR_0x8008
	waitstate
	release
	end

DewfordTown_EventScript_SailToSlateport::
	call EventScript_BackupMrBrineyLocation
	setobjectsubpriority LOCALID_BRINEY_DEWFORD, MAP_DEWFORD_TOWN, 0
	setobjectsubpriority OBJ_EVENT_ID_PLAYER, MAP_DEWFORD_TOWN, 1
	applymovement LOCALID_BRINEY_DEWFORD, DewfordTown_Movement_BrineyBoardBoat
	waitmovement 0
	removeobject LOCALID_BRINEY_DEWFORD
	applymovement OBJ_EVENT_ID_PLAYER, DewfordTown_Movement_PlayerBoardBoat
	waitmovement 0
	hideobjectat OBJ_EVENT_ID_PLAYER, MAP_DEWFORD_TOWN
	call Common_EventScript_PlayBrineysBoatMusic
	applymovement LOCALID_BOAT_DEWFORD, DewfordTown_Movement_SailToSlateport
	applymovement OBJ_EVENT_ID_PLAYER, DewfordTown_Movement_SailToSlateport
	waitmovement 0
	call Common_EventScript_StopBrineysBoatMusic
	showobjectat OBJ_EVENT_ID_PLAYER, MAP_ROUTE109
	applymovement OBJ_EVENT_ID_PLAYER, DewfordTown_Movement_ExitBoatSlateport
	waitmovement 0
	setobjectxyperm LOCALID_BRINEY_R109, 21, 26
	addobject LOCALID_BRINEY_R109
	setobjectsubpriority LOCALID_BRINEY_R109, MAP_ROUTE109, 0
	applymovement LOCALID_BRINEY_R109, DewfordTown_Movement_BrineyExitBoat
	waitmovement 0
	clearflag FLAG_GARBAGEFLAG
	addobject LOCALID_BOAT_R109
	clearflag FLAG_GARBAGEFLAG
	setflag FLAG_GARBAGEFLAG
	hideobjectat LOCALID_BOAT_DEWFORD, MAP_DEWFORD_TOWN
	call_if_unset FLAG_DELIVERED_DEVON_GOODS, DewfordTown_EventScript_LandedSlateportDeliverGoods
	call_if_set FLAG_DELIVERED_DEVON_GOODS, DewfordTown_EventScript_LandedSlateport
	closemessage
	copyvar VAR_GARBAGEVAR, VAR_0x8008
	resetobjectsubpriority OBJ_EVENT_ID_PLAYER, MAP_DEWFORD_TOWN
	resetobjectsubpriority LOCALID_BRINEY_R109, MAP_ROUTE109
	copyobjectxytoperm LOCALID_BRINEY_R109
	release
	end

DewfordTown_EventScript_LandedSlateportDeliverGoods::
	msgbox DewfordTown_Text_BrineyLandedInSlateportDeliverGoods, MSGBOX_DEFAULT
	return

DewfordTown_EventScript_LandedSlateport::
	msgbox DewfordTown_Text_BrineyLandedInSlateport, MSGBOX_DEFAULT
	return

DewfordTown_Movement_SailToPetalburg:
	walk_up
	walk_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_left
	walk_fast_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

DewfordTown_Movement_SailToSlateport:
	walk_right
	walk_fast_right
	walk_fast_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

DewfordTown_Movement_PlayerBoardBoat:
	walk_right
	walk_up
	step_end

DewfordTown_Movement_ExitBoatPetalburg:
	walk_up
	walk_up
	walk_up
	step_end

DewfordTown_Movement_ExitBoatSlateport:
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_down
	step_end

DewfordTown_Movement_BrineyBoardBoat:
	walk_up
	step_end

DewfordTown_Movement_BrineyExitBoat:
	walk_up
	walk_up
	step_end

DewfordTown_EventScript_TrendyPhraseBoy::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Text_XIsTheBiggestHappeningThingRight, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, DewfordTown_EventScript_ConfirmTrendyPhrase
	goto_if_eq VAR_RESULT, NO, DewfordTown_EventScript_RejectTrendyPhrase
	end

DewfordTown_EventScript_ConfirmTrendyPhrase::
	msgbox DewfordTown_Text_YeahDefinitionOfInRightNow, MSGBOX_DEFAULT
	release
	end

DewfordTown_EventScript_RejectTrendyPhrase::
	msgbox DewfordTown_Text_TellMeWhatsNewAndIn, MSGBOX_DEFAULT
	setvar VAR_0x8004, EASY_CHAT_TYPE_TRENDY_PHRASE
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	goto_if_eq VAR_RESULT, TRUE, DewfordTown_EventScript_GiveNewTrendyPhrase
	goto_if_eq VAR_RESULT, FALSE, DewfordTown_EventScript_CancelNewTrendyPhrase
	end

DewfordTown_EventScript_GiveNewTrendyPhrase::
	incrementgamestat GAME_STAT_STARTED_TRENDS
	goto_if_eq VAR_0x8004, FALSE, DewfordTown_EventScript_PhraseNotTrendyEnough
	msgbox DewfordTown_Text_OfCourseIKnowAboutThat, MSGBOX_DEFAULT
	release
	end

DewfordTown_EventScript_CancelNewTrendyPhrase::
	msgbox DewfordTown_Text_HearOfAnyTrendsComeShareWithMe, MSGBOX_DEFAULT
	release
	end

DewfordTown_EventScript_PhraseNotTrendyEnough::
	msgbox DewfordTown_Text_XHuhIThinkYIsCool, MSGBOX_DEFAULT
	release
	end

DewfordTown_Text_TinyIslandCommunity:
	.string "POURTOUR est une petite communauté insulaire.\n"
	.string "Si quelque chose devient à la mode ici,\l"
	.string "tout le monde s'y met tout de suite.$"

DewfordTown_Text_TownSign:
	.string "POURTOUR\n"
	.string "« Une petite île dans la mer bleue. »$"

DewfordTown_Text_GymSign:
	.string "SALLE POKéMON DE POURTOUR\n"
	.string "CHAMPION : BASTIEN\l"
	.string "« Une grande vague dans le combat ! »$"

DewfordTown_Text_HallSign:
	.string "SALLE DE POURTOUR\n"
	.string "« L'échange d'informations de tous ! »$"

Route104_Text_LandedInDewfordDeliverLetter:
	.string "M. MARIN : Ohé !\n"
	.string "On a accosté à POURTOUR.\p"
	.string "Je suppose que tu vas livrer cette\n"
	.string "LETTRE à... comment il s'appelle déjà, PIERRE !$"

DewfordTown_Text_SetSailBackToPetalburg:
	.string "M. MARIN : As-tu livré ta\n"
	.string "LETTRE ?\p"
	.string "Ou voulais-tu retourner à\n"
	.string "BOURG-EN-VOL ?$"

DewfordTown_Text_PetalburgWereSettingSail2:
	.string "M. MARIN : BOURG-EN-VOL alors !\p"
	.string "Levez l'ancre !\n"
	.string "PEEKO, on met les voiles, ma chérie !$"

DewfordTown_Text_GoDeliverIllBeWaiting:
	.string "M. MARIN : Alors va livrer\n"
	.string "la LETTRE. Je t'attendrai.$"

DewfordTown_Text_BrineyLandedInDewford:
	.string "M. MARIN : Ohé !\n"
	.string "On a accosté à POURTOUR !\p"
	.string "Tu n'as qu'à me dire quand tu veux\n"
	.string "reprendre la mer !$"

DewfordTown_Text_WhereAreWeBound:
	.string "M. MARIN : Ohé !\n"
	.string "Pour toi, je prends la mer quand tu veux !\p"
	.string "Alors, mon ami, où allons-nous ?$"

DewfordTown_Text_PetalburgWereSettingSail:
	.string "M. MARIN : BOURG-EN-VOL, c'est ça ?\p"
	.string "Levez l'ancre !\n"
	.string "PEEKO, on met les voiles, ma chérie !$"

DewfordTown_Text_SlateportWereSettingSail:
	.string "M. MARIN : POIVRESSEL, c'est ça ?\p"
	.string "Levez l'ancre !\n"
	.string "PEEKO, on met les voiles, ma chérie !$"

DewfordTown_Text_JustTellMeWhenYouNeedToSetSail:
	.string "M. MARIN : Tu n'as qu'à me dire quand\n"
	.string "tu veux reprendre la mer !$"

DewfordTown_Text_GettingItchToFish:
	.string "C'est un endroit réputé pour la pêche.\n"
	.string "Tu as envie de pêcher, non ?$"

DewfordTown_Text_GiveYouOneOfMyRods:
	.string "Je t'entends, et j'aime ce que\n"
	.string "tu dis !\p"
	.string "Je vais te donner une de mes CANNES à pêche.$"

DewfordTown_Text_ThrowInFishingAdvice:
	.string "Et, en bonus, je vais même te donner\n"
	.string "quelques conseils de pêche !\p"
	.string "D'abord, il faut faire face à l'eau,\n"
	.string "puis utiliser la CANNE.\p"
	.string "Concentre-toi…\n"
	.string "Si ça mord, tire sur la CANNE.\p"
	.string "Parfois tu peux attraper quelque chose\n"
	.string "immédiatement, mais pour les plus gros,\l"
	.string "il faut bien synchroniser les tirages\l"
	.string "pour les sortir de l'eau.\p"
	.string "Aussi, si tu enchaînes les prises,\n"
	.string "tu pourrais rencontrer des POKéMON\l"
	.string "de couleur différente.\p"
	.string "Enchaîner les prises veut dire vaincre\n"
	.string "le POKéMON sauvage et recommencer\l"
	.string "une nouvelle pêche.\p"
	.string "Si tu fuis ou perds le combat,\n"
	.string "tu perds ta série de prises !$"

DewfordTown_Text_ThatsTooBadThen:
	.string "Ah, c'est comme ça ?\n"
	.string "Dommage, alors.$"

DewfordTown_Text_HowsYourFishing:
	.string "Yo !\n"
	.string "Alors, la pêche, ça mord ?$"

DewfordTown_Text_GreatHaulInSomeBigOnes:
	.string "Ah oui ? Super !\n"
	.string "Attrape-en des gros !$"

DewfordTown_Text_FishingAdvice:
	.string "Oh, ne te décourage pas !\n"
	.string "Je vais te donner un petit conseil de pêche.\p"
	.string "D'abord, il faut faire face à l'eau,\n"
	.string "puis utiliser la CANNE.\p"
	.string "Concentre-toi…\n"
	.string "Si ça mord, tire sur la CANNE.\p"
	.string "Parfois tu peux attraper quelque chose\n"
	.string "immédiatement, mais pour les plus gros,\l"
	.string "il faut bien synchroniser les tirages\l"
	.string "pour les sortir de l'eau.\p"
	.string "Aussi, si tu enchaînes les prises,\n"
	.string "tu pourrais rencontrer des POKéMON\l"
	.string "de couleur différente.\p"
	.string "Enchaîner les prises veut dire vaincre\n"
	.string "le POKéMON sauvage et recommencer\l"
	.string "une nouvelle pêche.\p"
	.string "Si tu fuis ou perds le combat,\n"
	.string "tu perds ta série de prises !$"

DewfordTown_Text_XIsTheBiggestHappeningThingRight:
	.string "J'aime ce qui est branché, tendance et à la mode.\n"
	.string "Je surveille toujours ce qui se fait.\p"
	.string "Dis, tu as entendu parler de ce nouveau\n"
	.string "« {STR_VAR_1} » ?\p"
	.string "C'est vrai !\n"
	.string "Bien sûr que tu connais !\p"
	.string "Franchement,\n"
	.string "« {STR_VAR_1} »…\l"
	.string "C'est le truc le plus cool du moment !\p"
	.string "D'où que tu viennes,\n"
	.string "« {STR_VAR_1} »\l"
	.string "c'est ce qui fait le plus sensation, non ?$"

DewfordTown_Text_TellMeWhatsNewAndIn:
	.string "Hein ?\n"
	.string "C'est pas ce qui est branché et tendance ?\p"
	.string "Eh bien, tu dois me dire\n"
	.string "ce qui est nouveau et « in » !$"

DewfordTown_Text_OfCourseIKnowAboutThat:
	.string "Hein ?\n"
	.string "« {STR_VAR_2} » ?\p"
	.string "… …\p"
	.string "…Euh… Oui ! C'est ça !\n"
	.string "Oui, je le savais ! Je l'ai toujours su !\p"
	.string "Bien sûr que je connais ça !\n"
	.string "« {STR_VAR_2} », pas vrai ?\p"
	.string "Oui, c'est ça, c'est bien ça !\n"
	.string "C'est pas « {STR_VAR_2} »\l"
	.string "le truc le plus cool ?\p"
	.string "C'est le top du top.\n"
	.string "Tu crois que je ne saurais pas ?\p"
	.string "« {STR_VAR_1} »…\n"
	.string "C'est déjà dépassé, tu sais.\p"
	.string "Maintenant, « {STR_VAR_2} »\n"
	.string "c'est ce qui est vital et à la page !$"

DewfordTown_Text_XHuhIThinkYIsCool:
	.string "Hmm…\n"
	.string "« {STR_VAR_2} », hein ?\p"
	.string "Mais moi, je pense que\n"
	.string "« {STR_VAR_1} »\l"
	.string "c'est ce qui est vraiment cool.$"

DewfordTown_Text_HearOfAnyTrendsComeShareWithMe:
	.string "Si tu entends parler d'une nouvelle\n"
	.string "tendance, viens me la raconter, d'accord ?$"

DewfordTown_Text_YeahDefinitionOfInRightNow:
	.string "Oui, tout à fait !\p"
	.string "« {STR_VAR_1} » est la\n"
	.string "définition même de « in » en ce moment.$"
