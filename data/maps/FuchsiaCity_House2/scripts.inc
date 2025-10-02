FuchsiaCity_House2_MapScripts::
	.byte 0

FuchsiaCity_House2_EventScript_Granddaughter::	
	goto_if_set FLAG_TEMP_1, FuchsiaCity_House2_EventScript_Granddaughter2
	msgbox FuchsiaCity_House2_Text_WardensGranddaughter1, MSGBOX_NPC
	setflag FLAG_TEMP_1
	end

FuchsiaCity_House2_EventScript_Granddaughter2::
	msgbox FuchsiaCity_House2_Text_WardensGranddaughter2, MSGBOX_NPC
	end

FuchsiaCity_House2_EventScript_Photo::
	msgbox FuchsiaCity_House2_Text_WardenPhoto, MSGBOX_NPC
	end

FuchsiaCity_House2_Text_WardensGranddaughter1:
	.string "Mon grand-père était le GARDIEN\n"
	.string "de la SAFARI ZONE.\p"
	.string "Enfin, il l'était…\p"
	.string "Il a décidé de partir en vacances\n"
	.string "et il est parti à l'étranger tout seul.\p"
	.string "Il a arrêté de gérer la SAFARI ZONE\n"
	.string "juste comme ça.$"

FuchsiaCity_House2_Text_WardensGranddaughter2:
	.string "Beaucoup de gens ont été déçus que\n"
	.string "la SAFARI ZONE ait fermé, mais\n"
	.string "Grand-père est tellement têtu…$"

FuchsiaCity_House2_Text_WardenPhoto:
	.string "C'est une photo d'un vieil homme\n"
	.string "souriant entouré de POKéMON.$"

FuchsiaCity_House2_Text_SafariZonePhoto:
	.string "C'est une photo d'une immense plaine\n"
	.string "herbeuse où gambadent de rares POKéMON.$"
