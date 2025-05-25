GoldenrodDepartmentStore6_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, GoldenrodDeptElevator_OnFrame
	.byte 0

GoldenrodDeptStore6_EventScript_SetWarp::
	lock
	goto_if_set FLAG_NIGHT_POKEMON, GoldenrodDeptStore6_EventScript_SetWarpDay
	setdynamicwarp MAP_GOLDENROD_DEPARTMENT_STORE7NIGHT, 22, 5
	release
	end

GoldenrodDeptStore6_EventScript_SetWarpDay::
	setdynamicwarp MAP_GOLDENROD_DEPARTMENT_STORE7, 22, 5
	release
	end

GoldenrodDeptStore6_EventScript_Lass::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_6FLass, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore6_EventScript_Nerd::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_6FSuperNerd, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore6_EventScript_Sign::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_6FDirectory, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore_Text_6FLass:
    .string "Do you listen to LUCKY CHANNEL?\p"
    .string "If you want to win, trade POKéMON\n"
    .string "with as many people as possible to\l"
    .string "get different ID numbers.$"

GoldenrodDeptStore_Text_6FSuperNerd:
    .string "If you're tired, try the vending\n"
    .string "machine's drinks.\p"
    .string "Your POKéMON will love them too.$"

GoldenrodDeptStore_Text_6FDirectory:
    .string "Take a Break from Shopping!\p"
    .string "6F TRANQUIL SQUARE$"
