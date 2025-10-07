Route119_House_MapScripts::
	.byte 0

Route119_House_EventScript_Woman::
	msgbox Route119_House_Text_RumorAboutCaveOfOrigin, MSGBOX_NPC
	end

Route119_House_EventScript_Wingull::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_WINGULL, CRY_MODE_NORMAL
	msgbox Route119_House_Text_Wingull, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route119_House_Text_RumorAboutCaveOfOrigin:
	.string "J'ai entendu parler d'une grotte appelée\n"
	.string "la GROTTE ORIGINE.\p"
	.string "On raconte que les esprits des POKéMON\n"
	.string "y sont ramenés à la vie. Est-ce que\l"
	.string "quelque chose comme ça peut vraiment arriver?$"

Route119_House_Text_Wingull:
	.string "GOELISE: Pihyoh!$"

