PalletTown_RedsHouse_1F_MapScripts::
	.byte 0

PalletTown_RedsHouse_1F_EventScript_Mom::
	lock
	faceplayer
	goto_if_ge VAR_TEMP_0, 1, PalletTown_RedsHouse_1F_EventScript_MomAfter
	msgbox RedsHouse_Text_Mom1, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_0, 1
	release
	end

PalletTown_RedsHouse_1F_EventScript_MomAfter::
	msgbox RedsHouse_Text_Mom2, MSGBOX_DEFAULT
	closemessage
	release
	end

PalletTown_RedsHouse_1F_EventScript_TV::
	msgbox RedsHouse_Text_TV, MSGBOX_SIGN
	end

RedsHouse_Text_Mom1:
	.string "Bonjour !\p"
	.string "ROUGE est parti depuis longtemps.\p"
	.string "Il n'a pas appelé non plus, donc je\n"
	.string "n'ai aucune idée d'où il est ni ce\l"
	.string "qu'il fait.\p"
	.string "On dit que pas de nouvelles, bonnes\n"
	.string "nouvelles, mais je m'inquiète\l"
	.string "quand même pour lui.$"

RedsHouse_Text_Mom2:
	.string "Je m'inquiète que ROUGE se blesse ou\n"
	.string "tombe malade, mais c'est un garçon.\p"
	.string "Je suis fière qu'il fasse ce qu'il\n"
	.string "a envie de faire.$"

RedsHouse_Text_TV:
	.string "Ils ont des programmes qui ne sont\n"
	.string "pas diffusés à JOHTO…$"
