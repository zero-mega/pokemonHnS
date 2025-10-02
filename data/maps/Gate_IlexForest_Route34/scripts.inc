Gate_IlexForest_Route34_MapScripts::
	.byte 0

Route34IlexForestGate_EventScript_Lass::
	lock
	faceplayer
	msgbox Route34IlexForestGate_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

Route34IlexForestGate_EventScript_Butterfree::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_BUTTERFREE, CRY_MODE_NORMAL
	msgbox Route34IlexForestGate_Text_Butterfree, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route34IlexForestGate_Text_Lass:
	.string "As-tu vu le sanctuaire en l'honneur\n"
	.string "du protecteur ?\p"
	.string "Il veille sur la FORÊT à travers\n"
	.string "le temps.\p"
	.string "Je pense que ça doit être un\n"
	.string "POKéMON de type PLANTE.$"

Route34IlexForestGate_Text_Butterfree:
	.string "PAPILUSION : Freeh!$"
