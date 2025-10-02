GoldenrodCity_DepartmentStore_2F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, GoldenrodDeptElevator_OnFrame
	.byte 0

GoldenrodDeptStore2_EventScript_Youngster::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_2FYoungster, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore2_EventScript_CooltrainerF::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_2FCooltrainerF, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore2_EventScript_Gent::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_2FGentleman, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore2_EventScript_Sign::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_2FDirectory, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore_Text_2FYoungster:
    .string "Le POKéGEAR peut stocker jusqu'à 25\n"
    .string "numéros de téléphone.\p"
    .string "C'est difficile de choisir quels\n"
    .string "numéros garder.$"

GoldenrodDeptStore_Text_2FCooltrainerF:
    .string "J'ai eu mon ABRA au CASINO.\p"
    .string "Maintenant, c'est mon meilleur partenaire.$"

GoldenrodDeptStore_Text_2FGentleman:
    .string "Ce MAGASIN me fait réaliser que\n"
    .string "DOUBLONVILLE est une grande ville.\p"
    .string "La sélection ici est inégalée\n"
    .string "ailleurs.$"

GoldenrodDeptStore_Text_2FDirectory:
    .string "Votre compagnon de voyage\p"
    .string "2F MARCHÉ DES DRESSEURS$"
