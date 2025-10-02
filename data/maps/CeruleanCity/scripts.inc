.set LOCALID_CERULEAN_WOMAN, 2
.set LOCALID_CERULEAN_SLOWBRO, 3

CeruleanCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeruleanCity_EventScript_CityEnter
	.byte 0

CeruleanCity_EventScript_CityEnter::
	setflag FLAG_VISITED_CERULEAN_CITY
	end

CeruleanCity_EventScript_CooltrainerM1::
	goto_if_set FLAG_RETURNED_MACHINE_PART, CeruleanCity_EventScript_CooltrainerMReturnedPart
	msgbox CeruleanCity_Text_CooltrainerM1, MSGBOX_NPC
	end

CeruleanCity_EventScript_CooltrainerMReturnedPart::
	msgbox CeruleanCity_Text_CooltrainerM2, MSGBOX_NPC
	end

CeruleanCity_EventScript_Boy::
	msgbox CeruleanCity_Text_SuperNerd, MSGBOX_NPC
	end

CeruleanCity_EventScript_Guard::
	msgbox CeruleanCity_Text_ThisIsCeruleanCave, MSGBOX_NPC
	end

CeruleanCity_Text_ThisIsCeruleanCave::
    .string "C'est la GROTTE AZURÉE.\p"
    .string "Des POKéMON terriblement forts vivent\n"
    .string "là-dedans.\p"
    .string "Il faut un DRESSEUR très spécial pour\n"
    .string "être autorisé à y entrer.\p"
    .string "Tu devrais être assez fort pour\n"
    .string "devenir CHAMPION de la LIGUE POKéMON\l"
    .string "de KANTO pour commencer.\p"
    .string "Et tu devrais avoir\n"
	.string "accompli un grand exploit.$"

CeruleanCity_Text_CooltrainerM1:
	.string "La CENTRALE de KANTO ?\p"
	.string "Elle est près de la fin de la ROUTE 9, la\n"
	.string "route qui va vers l'est d'ici.\p"
	.string "Je pense qu'il y a eu un accident\n"
	.string "de quelque sorte là-bas.$"

CeruleanCity_Text_CooltrainerM2:
	.string "Tu collectionnes chaque\n"
	.string "type de POKéMON ?\p"
	.string "Ça doit être un vrai défi,\n"
	.string "mais ça a l'air amusant aussi.$"

CeruleanCity_Text_SuperNerd:
	.string "Le CAP au nord est un bon\n"
	.string "endroit pour des rendez-vous.\p"
	.string "Les filles aiment ça !$"

CeruleanCity_EventScript_Slowbro::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SLOWBRO, CRY_MODE_NORMAL
	msgbox CeruleanCity_Text_Slowbro, MSGBOX_DEFAULT
	waitmoncry
	release
	end

CeruleanCity_Text_Slowbro:
	.string "FLAGADOSS: Yarah ?$"

CeruleanCity_EventScript_SlowbroWoman::
	msgbox CeruleanCity_Text_CooltrainerF1, MSGBOX_NPC
	turnobject LOCALID_CERULEAN_WOMAN, DIR_EAST
	msgbox CeruleanCity_Text_CooltrainerF2, MSGBOX_DEFAULT
	delay 20
	playmoncry SPECIES_SLOWBRO, CRY_MODE_NORMAL
	applymovement2 LOCALID_CERULEAN_SLOWBRO, Common_Movement_QuestionMark
	turnobject LOCALID_CERULEAN_SLOWBRO DIR_WEST
	delay 30
	turnobject LOCALID_CERULEAN_SLOWBRO, DIR_EAST
	delay 30
	turnobject LOCALID_CERULEAN_SLOWBRO, DIR_SOUTH
	delay 70
	msgbox CeruleanCity_Text_CooltrainerF3, MSGBOX_NPC
	end

CeruleanCity_Text_CooltrainerF1:
	.string "Mon FLAGADOSS et moi formons une\n"
	.string "combinaison géniale !$"

CeruleanCity_Text_CooltrainerF2:
	.string "FLAGADOSS, montre-moi ton CONFUSION !$"

CeruleanCity_Text_CooltrainerF3:
	.string "…$"

CeruleanCity_EventScript_Fisher::
	goto_if_eq VAR_CERULEAN_CITY_STATE, 2, CeruleanCity_EventScript_FisherDuringRocket
	msgbox CeruleanCity_Text_Fisher, MSGBOX_NPC
	end

CeruleanCity_EventScript_FisherDuringRocket::
	msgbox CeruleanCity_Text_Fisher_RocketTip, MSGBOX_NPC
	end

CeruleanCity_Text_Fisher:
	.string "Je suis un grand fan de l'ARÈNE D'AZURIA,\n"
	.string "ONDINE.$"

CeruleanCity_Text_Fisher_RocketTip:
	.string "J'ai vu ce type louche partir vers\n"
	.string "le CAP D'AZURIA.$"

CeruleanCity_EventScript_Youngster::
	msgbox CeruleanCity_Text_Youngster1, MSGBOX_NPC
	end

CeruleanCity_Text_Youngster1:
	.string "La grotte au nord de la ville contient\n"
	.string "des POKéMON terriblement puissants.$"

CeruleanCity_Text_Youngster2:
	.string "Ayuh ?\p"
	.string "Mon CHERCHE-OBJET réagit…$"

CeruleanCity_EventScript_Sign::
	msgbox CeruleanCity_Text_Sign, MSGBOX_SIGN
	end

CeruleanCity_EventScript_GymSign::
	msgbox CeruleanCity_Text_GymSign, MSGBOX_SIGN
	end

CeruleanCity_EventScript_BikeShopSign::
	msgbox CeruleanCity_Text_BikeShopSign, MSGBOX_SIGN
	end

CeruleanCity_EventScript_PoliceSign::
	msgbox CeruleanCity_Text_PoliceSign, MSGBOX_SIGN
	end

CeruleanCity_EventScript_CapeSign::
	msgbox CeruleanCity_Text_CapeSign, MSGBOX_SIGN
	end

CeruleanCity_Text_Sign:
	.string "AZURIA\p"
	.string "Une Mystérieuse Aura Bleue L'Entoure$"

CeruleanCity_Text_GymSign:
	.string "AZURIA\n"
	.string "ARÈNE POKéMON\n"
	.string "CHAMPION: ONDINE\p"
	.string "La Sirène Garçon Manqué$"

CeruleanCity_Text_BikeShopSign:
	.string "Il y a un avis ici…\p"
	.string "La BOUTIQUE DE VÉLOS a déménagé à\n"
	.string "DOUBLANE dans JOHTO…$"

CeruleanCity_Text_PoliceSign:
	.string "Il y a un avis ici…\p"
	.string "Éliminez le vol et rendez la\n"
	.string "ville plus amicale et plus joyeuse\l"
	.string "!\p"
	.string "POLICE D'AZURIA$"

CeruleanCity_Text_CapeSign:
	.string "CAP D'AZURIA\n"
	.string "TOUT DROIT$"

CeruleanCity_Text_LockedDoor:
	.string "C'est verrouillé…$"

