Gate_AzaleaTown_IlexForest_MapScripts::
	.byte 0

Gate_AzaleaTown_IlexForest_EventScript_Officer::
	lock
	faceplayer
	msgbox Gate_AzaleaTown_IlexForest_Text_Officer, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_AzaleaTown_IlexForest_EventScript_Granny::
	lock
	faceplayer
	msgbox Gate_AzaleaTown_IlexForest_Text_Granny, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_AzaleaTown_IlexForest_Text_Officer:
	.string "LA FORÊT ILEX est grande.\n"
	.string "Fais attention !\n"
	.string "Ne te perds pas.$"

Gate_AzaleaTown_IlexForest_Text_Granny:
	.string "La FORÊT est surveillée\n"
	.string "par son protecteur.\p"
	.string "Ne fais pas de bêtises !$"
