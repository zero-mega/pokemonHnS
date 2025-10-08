SproutTower_1F_MapScripts::
	.byte 0

SproutTower_1F_EventScript_SageChow::
	trainerbattle_single TRAINER_CHOW, SproutTower_Text_SageChow_Seen, SproutTower_Text_SageChow_Beaten
	msgbox SproutTower_Text_SageChow_AfterBattle, MSGBOX_AUTOCLOSE
	end

SproutTower_1F_EventScript_Sage1::
	lock
	faceplayer
	msgbox SproutTower_Text_1F_Sage1, MSGBOX_DEFAULT
	closemessage
	release
	end

SproutTower_1F_EventScript_Sage2::
	lock
	faceplayer
	msgbox SproutTower_Text_1F_Sage2, MSGBOX_DEFAULT
	closemessage
	release
	end

SproutTower_1F_EventScript_Granny::
	lock
	faceplayer
	msgbox SproutTower_Text_1F_Granny, MSGBOX_DEFAULT
	closemessage
	release
	end

SproutTower_1F_EventScript_Teacher::
	lock
	faceplayer
	msgbox SproutTower_Text_1F_Teacher, MSGBOX_DEFAULT
	closemessage
	release
	end

SproutTower_1F_EventScript_ItemParalyzeHeal::
	finditem ITEM_PARALYZE_HEAL
	end

SproutTower_Text_SageChow_Seen:
	.string "Nous montons la garde dans cette tour.\p"
	.string "Ici, nous exprimons notre gratitude\n"
	.string "pour honorer tous les POKéMON.$"

SproutTower_Text_SageChow_Beaten:
	.string "M-Merci beaucoup !$"

SproutTower_Text_SageChow_AfterBattle:
	.string "Tous les êtres vivants coexistent\n"
	.string "grâce à la coopération.\p"
	.string "Nous devons toujours être reconnaissants\n"
	.string "pour cela.$"

SproutTower_Text_1F_Sage1:
	.string "Ce n'est qu'en atteignant le sommet\n"
	.string "que tu obtiendras une CS.$"

SproutTower_Text_1F_Sage2:
	.string "La TOUR CHÉTIFLOR a été construite\n"
	.string "il y a longtemps pour l'entraînement\n"
	.string "des POKéMON.$"

SproutTower_Text_1F_Granny:
	.string "Un CHÉTIFLOR de plus de 30 mètres\n"
	.string "de haut…\p"
	.string "On raconte qu'il est devenu le\n"
	.string "pilier central ici.$"

SproutTower_Text_1F_Teacher:
	.string "Tu vois le pilier qui bouge ?\p"
	.string "Des gens s'entraînent à l'étage.$"

SproutTower_Text_1F_Statue:
	.string "Une statue de POKéMON…\p"
	.string "Elle a l'air très distinguée.$"
