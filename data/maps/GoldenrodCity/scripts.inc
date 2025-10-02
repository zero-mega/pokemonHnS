.set LOCALID_GOLDENROD_ROCKET_SCOUT, 11

GoldenrodCity_MapScripts::
	.byte 0

GoldenrodCity_EventScript_Trigger:: @flagheap
	call_if_unset FLAG_SHOWN_ELM_TOGEPI, GoldenrodCity_Elm_Togepi_Call
	setflag FLAG_VISITED_GOLDENROD_CITY
	setflag FLAG_HIDE_GOLDENROD_ROCKETS
	setflag FLAG_HIDE_GOLDENROD_BILL
	setflag FLAG_HIDE_GOLDENROD_UNDERGROUND_KIMONO
	setflag FLAG_HIDE_GOLDENROD_UNDERGROUND_SILVER
	setflag FLAG_HIDE_ROCKET_GOLDENROD_RADIOTOWER_1
	setflag FLAG_HIDE_GOLDENROD_RADIOTOWER_PETREL
	setflag FLAG_HIDE_GOLDENROD_RADIOTOWER_DIRECTOR_2
	
	clearflag FLAG_HIDE_GOLDENROD_BEAUTY
	clearflag FLAG_HIDE_GOLDENROD_ROCKET_SCOUT
	clearflag FLAG_HIDE_GOLDENROD_NPCS
	clearflag FLAG_GOT_RETURN
	clearflag FLAG_GOT_FRUSTRATION
	clearflag FLAG_RECEIVED_BIKE
	clearflag FLAG_RECEIVED_SQUIRTBOTTLE
	clearflag FLAG_GOT_EEVEE
	clearflag FLAG_SYS_PC_BILL
	clearflag FLAG_RETURNED_MACHINE_PART
	clearflag FLAG_UNLOCKED_GOLDENROD_UNDERGROUND_DOOR
	clearflag FLAG_GOLDENROD_MACHOKE_1
	clearflag FLAG_GOLDENROD_MACHOKE_2
	clearflag FLAG_GOLDENROD_MACHOKE_3
	clearflag FLAG_COMPLETED_SWITCHES
	clearflag FLAG_ENABLE_RADIO
	clearflag FLAG_KANTO_RADIO_GOT
	clearflag FLAG_GOLDENROD_NPC_TRADE_COMPLETED
	clearflag FLAG_GOT_SKILL_SWAP
	clearflag FLAG_HIDE_RADIOTOWER_GATE
	clearflag FLAG_HIDE_GOLDENROD_RADIOTOWER_DIRECTOR
	clearflag FLAG_GOT_MARY_BRIGHT_POWDER
	clearflag FLAG_GOT_QUICK_CLAW
	clearflag FLAG_GOT_MAGNET

	setvar VAR_BUG_CONTEST_STATE, 0
	setvar VAR_KENYA, 0
	setvar VAR_LUGIA_OR_HOOH, 0
	setvar VAR_TRAIN, 0
	setvar VAR_ELEVATOR, 0
	setvar VAR_GOLDENROD_CITY_STATE, 1
	release
	end

GoldenrodCity_Trigger_Music::
	goto_if_lt VAR_GOLDENROD_CITY_STATE, 6, GoldenrodCity_Trigger_MusicNotYet
	goto_if_ge VAR_GOLDENROD_CITY_STATE, 11, GoldenrodCity_Trigger_MusicNotYet
	playbgm MUS_HG_ROCKET_TAKEOVER, TRUE
	setvar VAR_TEMP_0, 1 
	end

GoldenrodCity_Trigger_MusicNotYet::
	setvar VAR_TEMP_0, 1
	end

GoldenrodCity_Elm_Togepi_Call::
	lock
	pokenavcall GoldenrodCity_Text_ElmCall
	waitmessage
	delay 30
	release
	return

GoldenrodCity_EventScript_PokefanM::
	lock
	faceplayer
	msgbox GoldenrodCity_Text_PokefanM, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_Youngster::
	msgbox GoldenrodCity_Text_Youngster1, MSGBOX_NPC
	end

GoldenrodCity_EventScript_Youngster2::
	msgbox GoldenrodCity_Text_Youngster2, MSGBOX_NPC
	end

GoldenrodCity_EventScript_CooltrainerF::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_GOLDENROD_ROCKET_SCOUT, GoldenrodCity_EventScript_CooltrainerFCleared
	msgbox GoldenrodCity_Text_CooltrainerF1, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_CooltrainerFCleared::
	msgbox GoldenrodCity_Text_CooltrainerF1_Cleared, MSGBOX_NPC
	end

GoldenrodCity_EventScript_Lass::
	lock
	faceplayer
	msgbox GoldenrodCity_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_Gramps::
	lock
	faceplayer
	msgbox GoldenrodCity_Text_Gramps, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_NameRaterSign::
	msgbox GoldenrodCity_Text_NameRaterSign, MSGBOX_SIGN
	end

GoldenrodCity_EventScript_RocketScout::
	lock
	msgbox GoldenrodCity_Text_RocketScout1, MSGBOX_DEFAULT
	closemessage
	PLAYSE SE_PIN
	applymovement LOCALID_GOLDENROD_ROCKET_SCOUT, Common_Movement_ExclamationMark
	delay 20
	faceplayer
	msgbox GoldenrodCity_Text_RocketScout2, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_GOLDENROD_ROCKET_SCOUT, DIR_NORTH
	release
	end

GoldenrodCity_EventScript_Rocket1::
	lock
	faceplayer
	msgbox GoldenrodCity_Text_Rocket1, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_Rocket2::
	lock
	faceplayer
	msgbox GoldenrodCity_Text_Rocket2, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_Rocket3::
	lock
	faceplayer
	msgbox GoldenrodCity_Text_Rocket3, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_Rocket4::
	lock
	faceplayer
	msgbox GoldenrodCity_Text_Rocket4, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_Rocket5::
	lock
	faceplayer
	msgbox GoldenrodCity_Text_Rocket5, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_Rocket6::
	lock
	faceplayer
	msgbox GoldenrodCity_Text_Rocket6, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_Woman::
	lock
	faceplayer
	msgbox GoldenrodCity_Text_Woman, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_Hiker::
	lock
	faceplayer
	goto_if_set FLAG_DAY_POKEMON, GoldenrodCity_EventScript_Hiker2
	msgbox GoldenrodCity_Text_HikerDay, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_Hiker2::
	msgbox GoldenrodCity_Text_HikerNight, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_Snubbull::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SNUBBULL, CRY_MODE_NORMAL
	msgbox GoldenrodCity_Text_Snubbull, MSGBOX_DEFAULT
	waitmoncry
	release
	end

GoldenrodCity_EventScript_Mime::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MR_MIME, CRY_MODE_NORMAL
	msgbox GoldenrodCity_Text_MrMime, MSGBOX_DEFAULT
	waitmoncry
	release
	end

GoldenrodCity_EventScript_SignUnderground::
	lock
	msgbox GoldenrodCity_Text_UndergroundSouthSign, MSGBOX_SIGN
	closemessage
	release
	end
GoldenrodCity_EventScript_SignDept::
	lock
	msgbox GoldenrodCity_Text_DeptStoreSign, MSGBOX_SIGN
	closemessage
	release
	end
GoldenrodCity_EventScript_SignBike::
	lock
	msgbox GoldenrodCity_Text_BikeShopSign, MSGBOX_SIGN
	closemessage
	release
	end
GoldenrodCity_EventScript_SignTrain::
	lock
	msgbox GoldenrodCity_Text_StationSign, MSGBOX_SIGN
	closemessage
	release
	end
GoldenrodCity_EventScript_SignGym::
	lock
	msgbox GoldenrodCity_Text_GymSign, MSGBOX_SIGN
	closemessage
	release
	end
GoldenrodCity_EventScript_SignFlower::
	lock
	msgbox GoldenrodCity_Text_FlowerShopSign, MSGBOX_SIGN
	closemessage
	release
	end
GoldenrodCity_EventScript_SignRadio::
	lock
	msgbox GoldenrodCity_Text_RadioTowerSign, MSGBOX_SIGN
	closemessage
	release
	end
GoldenrodCity_EventScript_SignGameCorner::
	lock
	msgbox GoldenrodCity_Text_GameCornerSign, MSGBOX_SIGN
	closemessage
	release
	end

GoldenrodCity_EventScript_Beauty::
	lock
	faceplayer
	msgbox GoldenrodCity_Text_Beauty, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_Text_Beauty:
	.string "C'est l'ARÈNE DE DOUBLONVILLE !\p"
	.string "Notre championne BLANCHE n'est pas ici\n"
	.string "en ce moment. Elle pourrait être à la\l"
	.string "TOUR RADIO.$"

GoldenrodCity_Text_Woman:
	.string "Je m'entraînais dans l'ARÈNE de BLANCHE,\n"
	.string "mais tous ses pleurs me donnaient\l"
	.string "mal à la tête.$"

GoldenrodCity_Text_HikerDay:
	.string "Quand je suis entré au CASINO\n"
	.string "c'était la nuit... Combien de temps suis-je\l"
	.string "resté là-dedans ?!$"

GoldenrodCity_Text_HikerNight:
	.string "Quand je suis entré au CASINO\n"
	.string "c'était le jour... Combien de temps suis-je\l"
	.string "resté là-dedans ?!$"

GoldenrodCity_Text_Snubbull:
	.string "SNUBBULL: SNUUUBUUUULL!$"

GoldenrodCity_Text_MrMime:
	.string "............................$"

GoldenrodCity_Text_ElmCall:
	.string "ORME: Salut, {PLAYER} ?\n"
	.string "Cet œuf a-t-il éclos ?\p"
	.string "Une fois éclos, n'oublie pas de\n"
	.string "l'apporter au labo ! Je dois\l"
	.string "le voir !$"

GoldenrodCity_Text_PokefanM:
	.string "Ils ont construit la nouvelle TOUR RADIO\n"
	.string "pour remplacer l'ancienne qui grinçait.$"

GoldenrodCity_Text_Youngster1:
	.string "Je sais qu'il y a une nouvelle BOUTIQUE DE VÉLOS,\n"
	.string "mais je ne peux la trouver nulle part.$"

GoldenrodCity_Text_CooltrainerF1:
	.string "Cet homme en noir est-il déguisé\n"
	.string "en membre de la TEAM ROCKET ?\p"
	.string "Comme c'est ridicule !$"

GoldenrodCity_Text_CooltrainerF1_Cleared:
	.string "Cet homme en noir faisait-il vraiment\n"
	.string "partie de la TEAM ROCKET ? Je n'arrive pas à y croire !$"

GoldenrodCity_Text_CooltrainerF2:
	.string "La TOUR RADIO de DOUBLONVILLE est vraiment\n"
	.string "un monument de la ville.\p"
	.string "Ils organisent une campagne en ce moment.\p"
	.string "Ils t'offrent une RADIO toute neuve\n"
	.string "si tu réussis leur quiz.$"

GoldenrodCity_Text_CooltrainerF2_GotCard:
	.string "Oh, ton POKéMATO fait déjà\n"
	.string "radio !$"

GoldenrodCity_Text_Youngster2:
	.string "E-he-he-he…\p"
	.string "J'ai eu des ennuis pour avoir joué\n"
	.string "dans le sous-sol du MAGASIN.$"

GoldenrodCity_Text_Lass:
	.string "Cet homme à l'intérieur évalue les\n"
	.string "surnoms de tes POKéMON.\p"
	.string "Il peut même les renommer.$"

GoldenrodCity_Text_Gramps:
	.string "Ouf ! Cette ville est si grande,\n"
	.string "je n'arrive à rien trouver !$"

GoldenrodCity_Text_RocketScout1:
	.string "Alors c'est ça, la TOUR RADIO…$"

GoldenrodCity_Text_RocketScout2:
	.string "Qu'est-ce que tu veux, sale gosse ?\n"
	.string "Dégage, maintenant !$"

GoldenrodCity_Text_Rocket1:
	.string "Ne te mets pas en travers !\n"
	.string "Dégage, gamin !$"

GoldenrodCity_Text_Rocket2:
	.string "Prendre le contrôle de la TOUR RADIO…\p"
	.string "Quoi ? Ça ne te regarde pas !$"

GoldenrodCity_Text_Rocket3:
	.string "Les POKéMON ? Ce ne sont que des outils\n"
	.string "pour gagner de l'argent !$"

GoldenrodCity_Text_Rocket4:
	.string "Notre rêve va bientôt se réaliser…\p"
	.string "Ça a été une longue lutte…$"

GoldenrodCity_Text_Rocket5:
	.string "Hé, morveux ! Tu n'as rien à faire ici !\n"
	.string "Dégage, maintenant !$"

GoldenrodCity_Text_Rocket6:
	.string "Viens goûter à la terreur de\n"
	.string "la TEAM ROCKET !$"

GoldenrodCity_Text_StationSign:
	.string "GARE DE DOUBLONVILLE$"

GoldenrodCity_Text_RadioTowerSign:
	.string "TOUR RADIO DE DOUBLONVILLE$"

GoldenrodCity_Text_DeptStoreSign:
	.string "Grand choix d'articles POKéMON !\p"
	.string "GRAND MAGASIN DE DOUBLONVILLE$"

GoldenrodCity_Text_GymSign:
	.string "ARÈNE POKéMON DE DOUBLONVILLE\n"
	.string "CHAMPIONNE : BLANCHE\p"
	.string "La fille incroyablement jolie !$"

GoldenrodCity_Text_CitySign:
	.string  DOUBLONVILLE\p"
	.string "La ville festive au charme opulent$"

GoldenrodCity_Text_BikeShopSign:
	.string "Le monde est une piste cyclable !\n"
	.string "MAGASIN DE VÉLOS$"

GoldenrodCity_Text_GameCornerSign:
	.string "Votre terrain de jeu !\p"
	.string "CASINO DE DOUBLONVILLE$"

GoldenrodCity_Text_NameRaterSign:
	.string "JUGE-SURNOM\p"
	.string "Faites évaluer les surnoms de vos POKéMON$"

GoldenrodCity_Text_UndergroundNorthSign:
	.string "ENTRÉE DU SOUS-SOL$"

GoldenrodCity_Text_UndergroundSouthSign:
	.string "ENTRÉE DU SOUS-SOL$"

GoldenrodCity_Text_FlowerShopSign:
	.string "MAGASIN DE FLEURS resplendissant$"

GoldenrodCity_Text_MoveTutorAsk:
	.string "Je peux apprendre à ton POKéMON\n"
	.string "des capacités incroyables !\p"
	.string "Veux-tu que j'en enseigne une ?$"

GoldenrodCity_Text_MoveTutorCost:
	.string "Ça te coûtera 1000 jetons.\n"
	.string "D'accord ?$"

GoldenrodCity_Text_MoveTutorDecline:
	.string "Oh… Mais ces capacités sont géniales !$"

GoldenrodCity_Text_MoveTutorWhich:
	.string "Wahahah ! Tu ne le regretteras pas !\p"
	.string "Quelle capacité veux-tu que j'enseigne ?$"

GoldenrodCity_Text_MoveTutorNoCash:
	.string "Dommage. Je vais devoir aller\n"
	.string "chercher de l'argent chez moi…$"

GoldenrodCity_Text_MoveTutorUnderstand:
	.string "Si tu comprends cette capacité,\n"
	.string "tu es un vrai dresseur.$"

GoldenrodCity_Text_MoveTutorFarewell:
	.string "Wahahah ! Adieu, gamin !$"

GoldenrodCity_Text_MoveTutorBut:
	.string "M-mais…$"

GoldenrodCity_Text_MoveTutorNotEnoughCoins:
	.string "…Tu n'as pas assez de jetons…$"
