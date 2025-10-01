ViridianCity_House1_MapScripts::
	.byte 0

ViridianCity_House1_EventScript_Pokefan::
	msgbox ViridianCity_House1_Text_PokefanM, MSGBOX_NPC
	end

ViridianCity_House1_EventScript_Lass::
	msgbox ViridianCity_House1_Text_Lass, MSGBOX_NPC
	end


ViridianCity_House1_EventScript_Speary::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SPEAROW, CRY_MODE_NORMAL
	msgbox ViridianCity_House1_Text_Speary, MSGBOX_DEFAULT
	waitmoncry
	release
	end

ViridianCity_House1_EventScript_Rattey::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_RATTATA, CRY_MODE_NORMAL
	msgbox ViridianCity_House1_Text_Rattey, MSGBOX_DEFAULT
	waitmoncry
	release
	end

ViridianCity_House1_Text_PokefanM:
	.string "Tu réfléchis beaucoup pour\n"
	.string "nommer tes POKéMON ?\p"
	.string "Leur donner de bons surnoms ajoute\n"
	.string "au plaisir d'échanger avec les autres.$"

ViridianCity_House1_Text_Lass:
	.string "Ils s'appellent PIAFFY--un RAPASDEPIC--et\n"
	.string "RATTI--un RATTATA.$"

ViridianCity_House1_Text_Speary:
	.string "SPEARY: Ch-chun!$"

ViridianCity_House1_Text_Rattey:
	.string "RATTEY: Kikiii!$"

