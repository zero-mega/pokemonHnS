LavenderTown_House1_MapScripts::
	.byte 0

LavenderTown_House1_EventScript_Girl::
	msgbox LavenderTown_House1_Text_Girl, MSGBOX_NPC
	end

LavenderTown_House1_EventScript_Guy::
	msgbox LavenderTown_House1_Text_Guy, MSGBOX_NPC
	end

LavenderTown_House1_EventScript_Marowak::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MAROWAK, CRY_MODE_NORMAL
	msgbox LavenderTown_House1_Text_Marowak, MSGBOX_DEFAULT
	waitmoncry
	msgbox LavenderTown_House1_Text_Marowak2, MSGBOX_DEFAULT
	closemessage
	release
	end

LavenderTown_House1_Text_Girl:
	.string "Tu peux le croire ?\p"
	.string "Certaines personnes se lassent de\n"
	.string "s'occuper des POKéMON.\p"
	.string "GRAND-PÈRE recueille ces pauvres\n"
	.string "POKéMON sans abri et s'en occupe.$"
LavenderTown_House1_Text_Guy:
	.string "MR. FUJI vit bien ici mais il est\n"
	.string "parti en ce moment. Il doit être à la\l"
	.string "MAISON DES ÂMES.$"
LavenderTown_House1_Text_Marowak:
	.string ".............................$"

LavenderTown_House1_Text_Marowak2:
	.string "Le OSSELAIT est silencieux, mais il\n"
	.string "semble plutôt heureux.$"

