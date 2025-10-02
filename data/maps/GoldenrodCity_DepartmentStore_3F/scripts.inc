GoldenrodCity_DepartmentStore_3F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, GoldenrodDeptElevator_OnFrame
	.byte 0

GoldenrodDeptStore3_EventScript_Nerd::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_3FSuperNerd, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore3_EventScript_Sign::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_3FDirectory, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore3_EventScript_Rocker::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_3FRocker, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore_Text_3FSuperNerd:
    .string "Je, je, je suis vraiment impatient !\p"
    .string "J'utilise VIT. + en combat pour\n"
    .string "accélérer mes POKéMON.$"

GoldenrodDeptStore_Text_3FRocker:
    .string "Hé ! Quand tu combats, utilises-tu\n"
    .string "ATQ. SPÉCIAL ?\p"
    .string "C'est génial. Ça augmente vraiment\n"
    .string "l'ATTAQUE SPÉCIALE !$"

GoldenrodDeptStore_Text_3FDirectory:
    .string "Pour les chercheurs de victoire\p"
    .string "3F COLLECTION DE COMBAT$"
