SaffronCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SaffronCity_EventScript_CityEnter
	.byte 0

SaffronCity_OnFrame::
	map_script_2 VAR_SAFFRON_CITY_STATE, 0,  SaffronCity_EventScript_BaobaCall
	.2byte 0

SaffronCity_EventScript_CityEnter::
	setflag FLAG_VISITED_SAFFRON_CITY
	end

SaffronCity_EventScript_BaobaCall::
	pokenavcall SaffronCity_Text_Baoba
	waitmessage
	delay 30
	setflag FLAG_SAFARI_ZONE_EAST_EXPANSION
	setvar VAR_SAFFRON_CITY_STATE, 1
	end

SaffronCity_Text_Baoba:
	.string "GARDIEN BAOBA: {PLAYER} !\p"
	.string "C'est le GARDIEN BAOBA.\p"
	.string "Je t'appelle pour te dire que la\n"
	.string "ZONE SAFARI s'est encore agrandie !\p"
	.string "Enfin, ma ZONE SAFARI a été\n"
	.string "entièrement réalisée !\p"
	.string "Tu te souviens où elle se trouve, n'est-ce pas ?\p"
	.string "Juste à l'ouest d'IRISIA !\n"
	.string "À bientôt !$"

SaffronCity_EventScript_Lass1A::
	goto_if_set FLAG_RETURNED_MACHINE_PART, SaffronCity_EventScript_Lass1B
	msgbox SaffronCity_Text_Lass1, MSGBOX_NPC
	end

SaffronCity_EventScript_Lass1B::
	msgbox SaffronCity_Text_Lass1_ReturnedPart, MSGBOX_NPC
	end

SaffronCity_EventScript_Lass2::
	msgbox SaffronCity_Text_Lass2, MSGBOX_NPC
	end

SaffronCity_EventScript_PokefanM::
	goto_if_set FLAG_RETURNED_MACHINE_PART, SaffronCity_EventScript_PokefanM2
	msgbox SaffronCity_Text_PokefanM, MSGBOX_NPC
	end

SaffronCity_EventScript_PokefanM2::
	msgbox SaffronCity_Text_PokefanM_ReturnedPart, MSGBOX_NPC
	end

SaffronCity_EventScript_CooltrainerM::
	msgbox SaffronCity_Text_CooltrainerM, MSGBOX_NPC
	end

SaffronCity_EventScript_CooltrainerF::
	msgbox SaffronCity_Text_CooltrainerF, MSGBOX_NPC
	end

SaffronCity_EventScript_Fisher::
	goto_if_set FLAG_RETURNED_MACHINE_PART, SaffronCity_EventScript_Fisher2
	msgbox SaffronCity_Text_Fisher, MSGBOX_NPC
	end

SaffronCity_EventScript_Fisher2::
	msgbox SaffronCity_Text_Fisher_ReturnedPart, MSGBOX_NPC
	end

SaffronCity_EventScript_Youngster1::
	msgbox SaffronCity_Text_Youngster1, MSGBOX_NPC
	end

SaffronCity_EventScript_Youngster2::
	msgbox SaffronCity_Text_Youngster2, MSGBOX_NPC
	end
SaffronCity_EventScript_CitySign::
	msgbox SaffronCity_Text_Sign, MSGBOX_SIGN
	end

SaffronCity_EventScript_GymSign::
	msgbox SaffronCity_Text_GymSign, MSGBOX_SIGN
	end

SaffronCity_EventScript_DojoSign::
	msgbox SaffronCity_Text_FightingDojoSign, MSGBOX_SIGN
	end

SaffronCity_EventScript_SilphCoSign::
	msgbox SaffronCity_Text_SilphCoSign, MSGBOX_SIGN
	end

SaffronCity_EventScript_MrPsychicSign::
	msgbox SaffronCity_Text_MrPsychicHouseSign, MSGBOX_SIGN
	end

SaffronCity_EventScript_MagnetTrainSign::
	msgbox SaffronCity_Text_MagnetTrainStationSign, MSGBOX_SIGN
	end

SaffronCity_EventScript_Elli::
	msgbox SaffronCity_Text_Elli, MSGBOX_NPC
	end

SaffronCity_Text_Elli:
	.string "J'adore GOUPIX ! :D$"

SaffronCity_Text_Lass1:
	.string "Une petite fille experte pour\n"
	.string "imiter les gens vit ici.\p"
	.string "Elle imite même les personnes avec qui elle\n"
	.string "converse. C'est déroutant.$"

SaffronCity_Text_Lass1_ReturnedPart:
	.string "La fille COPIEUSE avait l'air malheureuse.\p"
	.string "Elle a dit qu'elle avait perdu sa\n"
	.string "POKé POUPÉE préférée--MÉLOFÉE.$"

SaffronCity_Text_PokefanM:
	.string "Tu viens de JOHTO ?\p"
	.string "Tu peux rentrer chez toi si le\n"
	.string "TRAIN MAGNÉTIQUE fonctionne.$"

SaffronCity_Text_PokefanM_ReturnedPart:
	.string "Tu viens de JOHTO ?\p"
	.string "Tu peux rentrer chez toi en prenant\n"
	.string "le TRAIN MAGNÉTIQUE.$"

SaffronCity_Text_CooltrainerM:
	.string "Je suis allé à l'ARÈNE, impatient de\n"
	.string "combattre des dresseurs…\p"
	.string "Il s'avère que je suis tombé dans l'\n"
	.string "ARÈNE inutilisée d'à côté.\p"
	.string "Bon sang, j'étais assez embarrassé.$"

SaffronCity_Text_CooltrainerF:
	.string "C'est SILPH SARL, célèbre pour\n"
	.string "ses produits POKéMON.\p"
	.string "Dans le passé, la TEAM ROCKET voulait\n"
	.string "l'entreprise à cause de ça.$"

SaffronCity_Text_Fisher:
	.string "Mâche… Mâche…\p"
	.string "J'entends dire qu'il y a de gros problèmes\n"
	.string "à la CENTRALE.\p"
	.string "Mâche… Mâche…$"

SaffronCity_Text_Fisher_ReturnedPart:
	.string "Mâche… Mâche…\p"
	.string "J'entends dire qu'il y a eu de gros problèmes\n"
	.string "à la CENTRALE.\p"
	.string "Mâche… Mâche… Haaah, je suis rassasié !$"

SaffronCity_Text_Youngster1:
	.string "Aller dans une ruelle pour la première\n"
	.string "fois me rend un peu anxieux.$"

SaffronCity_Text_Youngster2:
	.string "Il y a un endroit appelé MAISON\n"
	.string "DES DRESSEURS à JADIELLE où les dresseurs\p"
	.string "se rassemblent de partout.$"

SaffronCity_Text_Lass2:
	.string "Notre ville a été mise en vedette dans une\n"
	.string "émission de radio.\p"
	.string "C'est bien d'entendre des éloges pour votre\n"
	.string "ville, mais c'est un peu embarrassant\l"
	.string "aussi.$"

SaffronCity_Text_Sign:
	.string "SAFRANIA\p"
	.string "Terre Brillante et Dorée du Commerce$"

SaffronCity_Text_GymSign:
	.string "SAFRANIA\n"
	.string "ARÈNE POKéMON\l"
	.string "CHAMPION: MORGANE\p"
	.string "La Maîtresse des POKéMON PSY !$"

SaffronCity_Text_FightingDojoSign:
	.string "Tous Bienvenus !\n"
	.string "DOJO DE COMBAT$"

SaffronCity_Text_SilphCoSign:
	.string "SILPH SARL\n"
	.string "BÂTIMENT DE BUREAUX$"

SaffronCity_Text_MrPsychicHouseSign:
	.string "MAISON DE\n"
	.string "M. PSY$"

SaffronCity_Text_MagnetTrainStationSign:
	.string "SAFRANIA\n"
	.string "GARE DU TRAIN MAGNÉTIQUE$"
