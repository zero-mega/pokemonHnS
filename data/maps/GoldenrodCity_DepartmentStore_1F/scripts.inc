GoldenrodCity_DepartmentStore_1F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, GoldenrodDeptElevator_OnFrame
	.byte 0

GoldenrodDeptStore1_EventScript_Receptionist::
	lock
	faceplayer
	msgbox GoldenrodDeptStor1_Text_Receptionist, MSGBOX_DEFAULT
	closemessage
	release
	end
GoldenrodDeptStore1_EventScript_Gentleman::
	lock
	faceplayer
	msgbox GoldenrodDeptStore1_Text_Gentleman, MSGBOX_DEFAULT
	closemessage
	release
	end
GoldenrodDeptStore1_EventScript_PokefanF::
	lock
	faceplayer
	msgbox GoldenrodDeptStore1_Text_PokefanF, MSGBOX_DEFAULT
	closemessage
	release
	end
GoldenrodDeptStore1_EventScript_BugCatcher::
	lock
	faceplayer
	msgbox GoldenrodDeptStore1_Text_BugCatcher, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore1_EventScript_Directory::
	lock
	msgbox GoldenrodDeptStore1_Text_Directory, MSGBOX_SIGN
	closemessage
	release
	end

GoldenrodDeptStor1_Text_Receptionist:
    .string "Bienvenue au MAGASIN DE DOUBLONVILLE.$"

GoldenrodDeptStore1_Text_Gentleman:
    .string "Le MAGASIN a un bon choix.\n"
    .string "Mais certains objets ne sont\p"
    .string "disponibles qu'en tant que prix\n"
    .string "au CASINO.$"

GoldenrodDeptStore1_Text_PokefanF:
    .string "Je suis prête à faire du shopping\n"
    .string "encore aujourd'hui !$"

GoldenrodDeptStore1_Text_BugCatcher:
    .string "Maman est douée pour dénicher\n"
    .string "les bonnes affaires.\p"
    .string "Elle achète toujours des choses\n"
    .string "à des prix plus bas.$"

GoldenrodDeptStore1_Text_Directory:
    .string "<1F COMPTOIR DE SERVICE>\p"
    .string "2F MARCHÉ DES DRESSEURS\p"
    .string "3F COLLECTION DE COMBAT\p"
    .string "4F BOÎTE À MÉDICAMENTS\p"
    .string "5F COIN CT\p"
    .string "6F PLACE TRANQUILLE\p"
    .string "TERRASSE PANORAMIQUE$"
