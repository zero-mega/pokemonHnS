.set LOCALID_GOLDENROD_UNDERGROUND_KIMONO, 12

GoldenrodCity_UndergroundTunnel_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, GoldenrodCity_UndergroundTunnel_OnLoad
	.byte 0

GoldenrodCity_UndergroundTunnel_OnLoad::
	goto GoldenrodCity_UndergroundTunnel_MapScript_TryOpenDoor
	end
	
GoldenrodCity_UndergroundTunnel_EventScript_KimonoTriggerBot::
	lock
	playbgm MUS_HG_KIMONO_GIRL, TRUE
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, GoldenrodCity_UndergroundTunnel_Movement_Kimono_WalkToPlayerBot
	waitmovement 0
	msgbox GoldenrodCity_UndergroundTunnel_Text_Kimono1, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, Common_Movement_ExclamationMark
	delay 60
	msgbox GoldenrodCity_UndergroundTunnel_Text_Kimono2, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, Common_Movement_WalkUp1
	waitmovement 0
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, GoldenrodCity_UndergroundTunnel_Movement_Kimono_Leave1
	waitmovement 0
	playse SE_M_PETAL_DANCE
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, GoldenrodCity_UndergroundTunnel_Movement_Kimono_Spin
	waitmovement 0
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, GoldenrodCity_UndergroundTunnel_Movement_Kimono_Leave2
	waitmovement 0
	setflag FLAG_HIDE_GOLDENROD_UNDERGROUND_KIMONO
	removeobject LOCALID_GOLDENROD_UNDERGROUND_KIMONO
	fadedefaultbgm
	setvar VAR_GOLDENROD_CITY_STATE, 8
	end

GoldenrodCity_UndergroundTunnel_EventScript_KimonoTriggerTop::
	lock
	playbgm MUS_HG_KIMONO_GIRL, TRUE
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, GoldenrodCity_UndergroundTunnel_Movement_Kimono_WalkToPlayerTop
	waitmovement 0
	msgbox GoldenrodCity_UndergroundTunnel_Text_Kimono1, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, Common_Movement_ExclamationMark
	delay 60
	msgbox GoldenrodCity_UndergroundTunnel_Text_Kimono2, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, Common_Movement_WalkDown1
	waitmovement 0
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, GoldenrodCity_UndergroundTunnel_Movement_Kimono_Leave1
	waitmovement 0
	playse SE_M_PETAL_DANCE
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, GoldenrodCity_UndergroundTunnel_Movement_Kimono_Spin
	waitmovement 0
	applymovement LOCALID_GOLDENROD_UNDERGROUND_KIMONO, GoldenrodCity_UndergroundTunnel_Movement_Kimono_Leave2
	waitmovement 0
	setflag FLAG_HIDE_GOLDENROD_UNDERGROUND_KIMONO
	removeobject LOCALID_GOLDENROD_UNDERGROUND_KIMONO
	fadedefaultbgm
	setvar VAR_GOLDENROD_CITY_STATE, 8
	end


GoldenrodCity_UndergroundTunnel_Movement_Kimono_WalkToPlayerBot:
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

GoldenrodCity_UndergroundTunnel_Movement_Kimono_WalkToPlayerTop:
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

GoldenrodCity_UndergroundTunnel_Movement_Kimono_Leave1:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

GoldenrodCity_UndergroundTunnel_Movement_Kimono_Spin:
	face_down
	face_right
	face_up
	face_left
	face_down
	face_right
	face_up
	step_end

GoldenrodCity_UndergroundTunnel_Movement_Kimono_Leave2:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end


GoldenrodCity_UndergroundTunnel_Text_Kimono1:
	.string "Les membres de la Team Rocket en costumes noirs\n"
	.string "courent partout...\p"
	.string "Je me demandais ce qu'il se passait.\n"
	.string "Alors, tu as affronté la Team Rocket ?\l"
	.string "Tu es impressionnant !\p"
	.string "Tu pourrais être capable d'affronter le\n"
	.string "légendaire POKé...$"

GoldenrodCity_UndergroundTunnel_Text_Kimono2:
	.string "Hahaha ! Laisse tomber.\n"
	.string "Je dois y aller maintenant.$"

GoldenrodUnderground_EventScript_Eric::
	trainerbattle_single TRAINER_ERIC GoldenrodUnderground_Text_SupernerdEricSeen, GoldenrodUnderground_Text_SupernerdEricBeaten
	msgbox GoldenrodUnderground_Text_SupernerdEricAfterBattle, MSGBOX_AUTOCLOSE
	end

GoldenrodUnderground_EventScript_Teru::
	trainerbattle_single TRAINER_TERU GoldenrodUnderground_Text_SupernerdTeruSeen, GoldenrodUnderground_Text_SupernerdTeruBeaten
	msgbox GoldenrodUnderground_Text_SupernerdTeruAfterBattle, MSGBOX_AUTOCLOSE
	end

GoldenrodUnderground_EventScript_Issac::
	trainerbattle_single TRAINER_ISSAC GoldenrodUnderground_Text_PokemaniacIssacSeen, GoldenrodUnderground_Text_PokemaniacIssacBeaten
	msgbox GoldenrodUnderground_Text_PokemaniacIssacAfterBattle, MSGBOX_AUTOCLOSE
	end

GoldenrodUnderground_EventScript_Donald::
	trainerbattle_single TRAINER_DONALD GoldenrodUnderground_Text_PokemaniacDonaldSeen, GoldenrodUnderground_Text_PokemaniacDonaldBeaten
	msgbox GoldenrodUnderground_Text_PokemaniacDonaldAfterBattle, MSGBOX_AUTOCLOSE
	end

GoldenrodUnderground_EventScript_Brother_Haircut1::
	lock
	faceplayer
	goto_if_set FLAG_DAILY_HAIRCUT1_RECEIVED, GoldenrodUnderground_EventScript_Already_Got_Haircut1
	showmoneybox 0, 0
	msgbox GoldenrodUnderground_Text_OlderBrotherOffer, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, GoldenrodUnderground_EventScript_Haircut1
	msgbox GoldenrodUnderground_Text_OlderBrotherThatsAShame, MSGBOX_DEFAULT
	hidemoneybox
	closemessage
	end

GoldenrodUnderground_EventScript_Haircut1::
	msgbox GoldenrodUnderground_Text_OlderBrotherAskWhich
	special ChoosePartyMon
	waitstate
	showmoneybox 0, 0
	lock
	faceplayer
	goto_if_ge VAR_0x8004, PARTY_SIZE, GoldenrodUnderground_EventScript_Declined_Haircut1
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, GoldenrodUnderground_EventScript_Declined_Haircut1
	checkmoney 500, 0
	goto_if_eq VAR_RESULT, FALSE, GoldenrodUnderground_EventScript_NotEnough_Haircut1
	removemoney 500
	updatemoneybox 0
	playse SE_SHOP
	msgbox GoldenrodUnderground_Text_OlderBrotherWatchItBeautiful
	closemessage
	fadescreen FADE_TO_BLACK
	playfanfare MUS_HEAL
	waitfanfare
	special HaircutBrother1
	fadescreen FADE_FROM_BLACK
	special BufferMonNickname
	msgbox GoldenrodUnderground_Text_OlderBrotherAllDone
	hidemoneybox
	setflag FLAG_DAILY_HAIRCUT1_RECEIVED
	release
	end

GoldenrodUnderground_EventScript_Declined_Haircut1::
	msgbox GoldenrodUnderground_Text_OlderBrotherThatsAShame, MSGBOX_DEFAULT
	hidemoneybox
	closemessage
	release
	end

GoldenrodUnderground_EventScript_Already_Got_Haircut1::
	msgbox GoldenrodUnderground_Text_OlderBrotherOnePerDay, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodUnderground_EventScript_NotEnough_Haircut1::
	msgbox GoldenrodUnderground_Text_OlderBrotherNeedMoreMoney, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	release
	end


GoldenrodUnderground_EventScript_Brother_Haircut2::
	lock
	faceplayer
	goto_if_set FLAG_DAILY_HAIRCUT2_RECEIVED, GoldenrodUnderground_EventScript_Already_Got_Haircut2
	showmoneybox 0, 0
	msgbox GoldenrodUnderground_Text_YoungerBrotherOffer, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, GoldenrodUnderground_EventScript_Haircut2
	msgbox GoldenrodUnderground_Text_YoungerBrotherDisappointed, MSGBOX_DEFAULT
	hidemoneybox
	closemessage
	end

GoldenrodUnderground_EventScript_Haircut2::
	msgbox GoldenrodUnderground_Text_YoungerBrotherAskWhich
	special ChoosePartyMon
	waitstate
	showmoneybox 0, 0
	lock
	faceplayer
	goto_if_ge VAR_0x8004, PARTY_SIZE, GoldenrodUnderground_EventScript_Declined_Haircut2
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, GoldenrodUnderground_EventScript_Declined_Haircut2
	checkmoney 300, 0
	goto_if_eq VAR_RESULT, FALSE, GoldenrodUnderground_EventScript_NotEnough_Haircut2
	removemoney 300
	updatemoneybox 0
	playse SE_SHOP
	msgbox GoldenrodUnderground_Text_YoungerBrotherLookCool
	closemessage
	fadescreen FADE_TO_BLACK
	playfanfare MUS_HEAL
	waitfanfare
	special HaircutBrother1
	fadescreen FADE_FROM_BLACK
	special BufferMonNickname
	msgbox GoldenrodUnderground_Text_YoungerBrotherAllDone
	hidemoneybox
	setflag FLAG_DAILY_HAIRCUT2_RECEIVED
	release
	end

GoldenrodUnderground_EventScript_Declined_Haircut2::
	msgbox GoldenrodUnderground_Text_YoungerBrotherDisappointed, MSGBOX_DEFAULT
	hidemoneybox
	closemessage
	release
	end

GoldenrodUnderground_EventScript_Already_Got_Haircut2::
	msgbox GoldenrodUnderground_Text_YoungerBrotherOnePerDay, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodUnderground_EventScript_NotEnough_Haircut2::
	msgbox GoldenrodUnderground_Text_YoungerBrotherShortOnFunds, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	release
	end


GoldenrodCity_UndergroundTunnel_MapScript_TryOpenDoor::
	goto_if_set FLAG_UNLOCKED_GOLDENROD_UNDERGROUND_DOOR, GoldenrodCity_UndergroundTunnel_MapScript_OpenDoor
	end

GoldenrodCity_UndergroundTunnel_MapScript_OpenDoor::
	setmetatile 12, 10, 0x2DD, FALSE
	end

GoldenrodCity_UndergroundTunnel_EventScript_Door::
	lock
	goto_if_set FLAG_UNLOCKED_GOLDENROD_UNDERGROUND_DOOR, GoldenrodCity_UndergroundTunnel_EventScript_DoorAlreadyOpened
	checkitem ITEM_BASEMENT_KEY
	goto_if_eq VAR_RESULT, TRUE, GoldenrodCity_UndergroundTunnel_EventScript_OpenDoor
	msgbox GoldenrodUnderground_Text_DoorsLocked, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_UndergroundTunnel_EventScript_OpenDoor::
	msgbox GoldenrodUnderground_Text_KeyOpenedDoor, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_UNLOCKED_GOLDENROD_UNDERGROUND_DOOR
	setmetatile 12, 10, 0x2DD, FALSE
	playse SE_BANG
	special DrawWholeMapView
	waitse
	release
	end

GoldenrodCity_UndergroundTunnel_EventScript_DoorAlreadyOpened::
	msgbox GoldenrodUnderground_Text_DoorIsOpen, MSGBOX_DEFAULT
	closemessage
	release
	end


GoldenrodCity_UndergroundTunnel_EventScript_Item_CoinCase::
	finditem ITEM_COIN_CASE
	end

GoldenrodCity_UndergroundTunnel_EventScript_Item_SuperPotion::
	finditem ITEM_SUPER_POTION
	end

GoldenrodCity_UndergroundTunnel_EventScript_Item_ParalyzeHeal::
	finditem ITEM_PARALYZE_HEAL
	end

GoldenrodCity_UndergroundTunnel_EventScript_Item_Antidote::
	finditem ITEM_ANTIDOTE
	end


GoldenrodUnderground_Text_YoungerBrotherOffer:
    .string "Bienvenue au SALON POKéMON !\p"
    .string "Je suis le plus jeune et le moins cher\n"
    .string "des deux FRÈRES COIFFEUR.\p"
    .string "Je peux embellir ton POKéMON pour\n"
    .string "seulement ¥300.\p"
    .string "Alors ? Qu'en dis-tu ?$"

GoldenrodUnderground_Text_YoungerBrotherAskWhich:
    .string "D'accord, quel POKéMON dois-je coiffer ?$"

GoldenrodUnderground_Text_YoungerBrotherLookCool:
    .string "OK ! Je vais le rendre super cool !$"

GoldenrodUnderground_Text_YoungerBrotherAllDone:
    .string "Voilà ! C'est terminé !$"

GoldenrodUnderground_Text_YoungerBrotherDisappointed:
    .string "Non ? Comme c'est décevant !$"

GoldenrodUnderground_Text_YoungerBrotherShortOnFunds:
    .string "Tu n'as pas assez d'argent.$"

GoldenrodUnderground_Text_YoungerBrotherOnePerDay:
    .string "Je ne peux faire qu'une seule coupe par jour.\p"
    .string "Désolé, mais j'ai déjà fini pour aujourd'hui.$"



GoldenrodUnderground_Text_OlderBrotherOffer:
    .string "Bienvenue !\p"
    .string "Je tiens le SALON POKéMON !\p"
    .string "Je suis le plus âgé et le meilleur des deux\n"
    .string "FRÈRES COIFFEUR.\p"
    .string "Je peux rendre ton POKéMON magnifique\n"
    .string "pour seulement ¥500.\p"
    .string "Veux-tu que je m'en occupe ?$"

GoldenrodUnderground_Text_OlderBrotherAskWhich:
    .string "Quel POKéMON dois-je coiffer ?$"

GoldenrodUnderground_Text_OlderBrotherWatchItBeautiful:
    .string "OK ! Regarde-le devenir magnifique !$"

GoldenrodUnderground_Text_OlderBrotherAllDone:
    .string "Voilà ! C'est terminé !$"

GoldenrodUnderground_Text_OlderBrotherThatsAShame:
    .string "Vraiment ? Quel dommage !$"

GoldenrodUnderground_Text_OlderBrotherNeedMoreMoney:
    .string "Il te faut plus d'argent que ça.$"

GoldenrodUnderground_Text_OlderBrotherOnePerDay:
    .string "Je ne fais qu'une seule coupe par jour.\n"
    .string "J'ai fini pour aujourd'hui.$"

GoldenrodUnderground_Text_SupernerdEricSeen:
    .string "Je me suis fait virer du CASINO.\p"
    .string "J'essayais de tricher avec mes\n"
    .string "POKéMON…$"

GoldenrodUnderground_Text_SupernerdEricBeaten:
    .string "…Grommelle…$"

GoldenrodUnderground_Text_SupernerdEricAfterBattle:
    .string "Je suppose que je dois jouer\n"
    .string "honnêtement…$"

GoldenrodUnderground_Text_SupernerdTeruSeen:
    .string "Tu prends en compte les types en\n"
    .string "combat ?\p"
    .string "Si tu connais les avantages de type,\n"
    .string "tu t'en sortiras mieux.$"

GoldenrodUnderground_Text_SupernerdTeruBeaten:
    .string "Aïe, aïe, aïe !$"

GoldenrodUnderground_Text_SupernerdTeruAfterBattle:
    .string "Je connais les types de mes POKéMON.\p"
    .string "Mais je n'utilise qu'un seul type.$"

GoldenrodUnderground_Text_PokemaniacIssacSeen:
    .string "Mon POKéMON vient de se faire coiffer !\p"
    .string "Je vais te montrer comme il est fort !$"

GoldenrodUnderground_Text_PokemaniacIssacBeaten:
    .string "Aïe aïe aïe !$"

GoldenrodUnderground_Text_PokemaniacIssacAfterBattle:
    .string "Tes POKéMON t'aimeront plus si\n"
    .string "tu leur fais faire des coupes.$"

GoldenrodUnderground_Text_PokemaniacDonaldSeen:
    .string "Je crois que tu as des POKéMON rares\n"
    .string "avec toi.\p"
    .string "Montre-les-moi !$"

GoldenrodUnderground_Text_PokemaniacDonaldBeaten:
    .string "Grrr ! J'ai perdu ! Ça m'énerve !$"

GoldenrodUnderground_Text_PokemaniacDonaldAfterBattle:
	.string "Hier soir, en passant près du MAGASIN\n"
	.string "DE VÉLOS, j'ai eu l'impression\l"
	.string "d'être observé depuis les toits...$"

GoldenrodUnderground_Text_PokemaniacDonaldAfterBattleOld:
    .string "Tu complètes un POKéDEX ? Voici un\n"
    .string "petit conseil.\p"
    .string "Le MONTAGNARD ANTOINE sur la ROUTE 33\n"
    .string "est un bon gars.\p"
    .string "Il t'appellera s'il voit un POKéMON rare.$"

GoldenrodUnderground_Text_DoorsLocked:
    .string "La porte est verrouillée…$"

GoldenrodUnderground_Text_DoorIsOpen:
    .string "La porte est ouverte.$"

GoldenrodUnderground_Text_KeyOpenedDoor:
    .string "La CLÉ DU SOUS-SOL a ouvert la porte.$"

GoldenrodUnderground_Text_NoEntry:
    .string "ENTRÉE INTERDITE AU-DELÀ DE CE POINT$"
