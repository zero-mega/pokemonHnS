DewfordTown_House1_MapScripts::
	.byte 0

DewfordTown_House1_EventScript_Man::
	msgbox DewfordTown_House1_Text_LotToBeSaidForLivingOnIsland, MSGBOX_NPC
	end

DewfordTown_House1_EventScript_Woman::
	msgbox DewfordTown_House1_Text_LifeGoesSlowlyOnIsland, MSGBOX_NPC
	end

DewfordTown_House1_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox DewfordTown_House1_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

DewfordTown_House1_Text_LotToBeSaidForLivingOnIsland:
	.string "Il y a beaucoup à dire sur le fait de vivre\n"
	.string "sur une petite île comme celle-ci, en harmonie\l"
	.string "avec les POKéMON et la famille.$"

DewfordTown_House1_Text_LifeGoesSlowlyOnIsland:
	.string "J'ai quitté le grand port de POIVRESSEL\n"
	.string "quand j'ai épousé mon mari ici.\p"
	.string "La vie s'écoule lentement sur cette petite\n"
	.string "île. Mais être entourée par la belle mer--\l"
	.string "c'est aussi ça, le bonheur.$"

DewfordTown_House1_Text_Zigzagoon:
	.string "ZIGZAGOON : Guguuh !$"

