GoldenrodCity_DepartmentStore_4F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, GoldenrodDeptElevator_OnFrame
	.byte 0

GoldenrodDeptStore4_EventScript_Cooltrainer::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_4FCooltrainerM, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore4_EventScript_BugCatcher::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_4FBugCatcher, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore4_EventScript_GBAKid::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_4FGameboyKid, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore4_EventScript_Sign::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_4FDirectory, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore_Text_4FCooltrainerM:
    .string "Salut. J'adore les POKéMON forts.\p"
    .string "Je leur donne des PROTÉINES pour\n"
    .string "augmenter leur ATTAQUE.$"

GoldenrodDeptStore_Text_4FBugCatcher:
    .string "Le FER augmente la DÉFENSE\n"
    .string "de tes POKéMON.$"

GoldenrodDeptStore_Text_4FGameboyKid:
    .string "Il y avait des rumeurs que certains\n"
    .string "POKéMON évoluent seulement en\l"
    .string "étant échangés via un câble Game Link.\p"
    .string "Pff...\p"
    .string "Quelle désinformation.\p"
    .string "Je connais certains des POKéMON\n"
    .string "concernés :\l"
    .string "MACHOPEUR, KADABRA, SPECTRE et,\l"
    .string "euh, GRAVALANCH,\l"
    .string "mais ils évoluent tous en montant\l"
    .string "de niveau.$"

GoldenrodDeptStore_Text_4FDirectory:
    .string "Faisons grandir tes POKéMON !\p"
    .string "4e ÉTAGE BOÎTE À MÉDICAMENTS$"
