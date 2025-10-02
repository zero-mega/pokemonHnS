CeladonCity_DepartmentStore_1F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CeladonDeptElevator_OnFrame
	.byte 0

CeladonDept1_EventScript_Receptionsit::
    msgbox CeladonDeptStore_Text_1FReceptionist, MSGBOX_NPC
    end

CeladonDept1_EventScript_Gent::
    msgbox CeladonDeptStore_Text_1FGentleman, MSGBOX_NPC
    end

CeladonDept1_EventScript_Teacher::
    msgbox CeladonDeptStore_Text_1FTeacher, MSGBOX_NPC
    end

CeladonDept1_EventScript_Directory::
    msgbox CeladonDeptStore_Text_1FDirectory, MSGBOX_SIGN
    end

CeladonDeptStore_Text_1FReceptionist:
    .string "Bonjour ! Bienvenue au GRAND MAGASIN\n"
    .string "de CELADOPOLE !\p"
    .string "L'annuaire est sur le mur.$"

CeladonDeptStore_Text_1FGentleman:
    .string "Ce GRAND MAGASIN fait partie de la\n"
    .string "même chaîne que celui de DOUBLONVILLE.\p"
    .string "Ils ont tous deux été rénovés en même\n"
    .string "temps.$"

CeladonDeptStore_Text_1FTeacher:
    .string "C'est ma première visite ici.\p"
    .string "C'est tellement grand…\p"
    .string "J'ai peur de me perdre.$"

CeladonDeptStore_Text_1FDirectory:
    .string "1F : COMPTOIR D'ACCUEIL\p"
    .string "2F : MARCHÉ DES DRESSEURS\p"
    .string "3F : BOUTIQUE CT\p"
    .string "4F : CADEAUX SAGE\p"
    .string "5F : PHARMACIE\p"
    .string "6F : TERRASSE$"
