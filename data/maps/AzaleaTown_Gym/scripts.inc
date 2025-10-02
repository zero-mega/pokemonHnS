.set LOCALID_AZALEA_ARIADOS_LEFT1, 8
.set LOCALID_AZALEA_ARIADOS_MID1, 9
.set LOCALID_AZALEA_ARIADOS_RIGHT1, 10

.set LOCALID_AZALEA_ARIADOS_LEFT2, 11
.set LOCALID_AZALEA_ARIADOS_MID2, 12
.set LOCALID_AZALEA_ARIADOS_RIGHT2, 13

AzaleaTown_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, AzaleaTown_Gym_OnTransition
	.byte 0

AzaleaTown_Gym_OnTransition::
	setflag FLAG_HIDE_AZALEA_ARIADOS_LEFT
	setflag FLAG_HIDE_AZALEA_ARIADOS_MID
	setflag FLAG_HIDE_AZALEA_ARIADOS_RIGHT
	end

@ 1-8->5,  5-9->1
AzaleaTown_Gym_EventScript_Trigger_1::
	lock
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	clearflag FLAG_HIDE_AZALEA_ARIADOS_LEFT
	addobject LOCALID_AZALEA_ARIADOS_LEFT1
	SetObjectSubpriority OBJ_EVENT_ID_PLAYER, MAP_AZALEA_TOWN_GYM, 0
	applymovement LOCALID_AZALEA_ARIADOS_LEFT1, AzaleaTown_Gym_Movement_Ariados_Down
	waitmovement 0
	turnobject LOCALID_AZALEA_ARIADOS_LEFT1, DIR_NORTH
	delay 30
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_JumpUp1
	playse SE_LEDGE
	waitmovement 0
	waitmovement 0
	applymovement LOCALID_AZALEA_ARIADOS_LEFT1, AzaleaTown_Gym_Movement_Ariados_Up
	applymovement OBJ_EVENT_ID_PLAYER, AzaleaTown_Gym_Movement_Player_Up
	waitmovement 0
	waitmovement 0
	@turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	applymovement LOCALID_AZALEA_ARIADOS_LEFT1, AzaleaTown_Gym_Movement_Ariados_Right
	applymovement OBJ_EVENT_ID_PLAYER, AzaleaTown_Gym_Movement_Player_Right
	waitmovement 0
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	applymovement LOCALID_AZALEA_ARIADOS_LEFT1, AzaleaTown_Gym_Movement_Ariados_Up
	applymovement OBJ_EVENT_ID_PLAYER, AzaleaTown_Gym_Movement_Player_Up
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_JumpUp1
	waitmovement 0
	applymovement LOCALID_AZALEA_ARIADOS_LEFT1, AzaleaTown_Gym_Movement_Ariados_Down
	waitmovement 0
	setflag FLAG_HIDE_AZALEA_ARIADOS_LEFT
	removeobject LOCALID_AZALEA_ARIADOS_LEFT1
	resetobjectsubpriority OBJ_EVENT_ID_PLAYER, MAP_AZALEA_TOWN_GYM
	release
	end

AzaleaTown_Gym_EventScript_Trigger_5::
	lock
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	clearflag FLAG_HIDE_AZALEA_ARIADOS_MID
	addobject LOCALID_AZALEA_ARIADOS_MID1
	SetObjectSubpriority OBJ_EVENT_ID_PLAYER, MAP_AZALEA_TOWN_GYM, 0
	applymovement LOCALID_AZALEA_ARIADOS_MID1, AzaleaTown_Gym_Movement_Ariados_Up
	waitmovement 0
	turnobject LOCALID_AZALEA_ARIADOS_MID1, DIR_SOUTH
	delay 30
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_JumpDown1
	playse SE_LEDGE
	waitmovement 0
	waitmovement 0
	applymovement LOCALID_AZALEA_ARIADOS_MID1, AzaleaTown_Gym_Movement_Ariados_Down
	delay 3
	applymovement OBJ_EVENT_ID_PLAYER, AzaleaTown_Gym_Movement_Player_Down
	waitmovement 0
	waitmovement 0
	@turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	applymovement LOCALID_AZALEA_ARIADOS_MID1, AzaleaTown_Gym_Movement_Ariados_Left
	applymovement OBJ_EVENT_ID_PLAYER, AzaleaTown_Gym_Movement_Player_Left
	waitmovement 0
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	applymovement LOCALID_AZALEA_ARIADOS_MID1, AzaleaTown_Gym_Movement_Ariados_Down
	delay 3
	applymovement OBJ_EVENT_ID_PLAYER, AzaleaTown_Gym_Movement_Player_Down
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_JumpDown1
	playse SE_LEDGE
	waitmovement 0
	applymovement LOCALID_AZALEA_ARIADOS_MID1, AzaleaTown_Gym_Movement_Ariados_Up
	waitmovement 0
	setflag FLAG_HIDE_AZALEA_ARIADOS_MID
	removeobject LOCALID_AZALEA_ARIADOS_MID1
	resetobjectsubpriority OBJ_EVENT_ID_PLAYER, MAP_AZALEA_TOWN_GYM
	release
	end

@ 2-9->6,  6-10->2
AzaleaTown_Gym_EventScript_Trigger_2::
	lock
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	clearflag FLAG_HIDE_AZALEA_ARIADOS_MID
	addobject LOCALID_AZALEA_ARIADOS_MID1
	SetObjectSubpriority OBJ_EVENT_ID_PLAYER, MAP_AZALEA_TOWN_GYM, 0
	applymovement LOCALID_AZALEA_ARIADOS_MID1, AzaleaTown_Gym_Movement_Ariados_Down
	waitmovement 0
	turnobject LOCALID_AZALEA_ARIADOS_MID1, DIR_NORTH
	delay 30
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_JumpUp1
	playse SE_LEDGE
	waitmovement 0
	waitmovement 0
	applymovement LOCALID_AZALEA_ARIADOS_MID1, AzaleaTown_Gym_Movement_Ariados_Up
	applymovement OBJ_EVENT_ID_PLAYER, AzaleaTown_Gym_Movement_Player_Up
	waitmovement 0
	waitmovement 0
	@turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	applymovement LOCALID_AZALEA_ARIADOS_MID1, AzaleaTown_Gym_Movement_Ariados_Right
	applymovement OBJ_EVENT_ID_PLAYER, AzaleaTown_Gym_Movement_Player_Right
	waitmovement 0
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	applymovement LOCALID_AZALEA_ARIADOS_MID1, AzaleaTown_Gym_Movement_Ariados_Up
	applymovement OBJ_EVENT_ID_PLAYER, AzaleaTown_Gym_Movement_Player_Up
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_JumpUp1
	playse SE_LEDGE
	waitmovement 0
	applymovement LOCALID_AZALEA_ARIADOS_MID1, AzaleaTown_Gym_Movement_Ariados_Down
	waitmovement 0
	setflag FLAG_HIDE_AZALEA_ARIADOS_MID
	removeobject LOCALID_AZALEA_ARIADOS_MID1
	resetobjectsubpriority OBJ_EVENT_ID_PLAYER, MAP_AZALEA_TOWN_GYM
	release
	end

AzaleaTown_Gym_EventScript_Trigger_6::
	lock
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	clearflag FLAG_HIDE_AZALEA_ARIADOS_RIGHT
	addobject LOCALID_AZALEA_ARIADOS_RIGHT1
	SetObjectSubpriority OBJ_EVENT_ID_PLAYER, MAP_AZALEA_TOWN_GYM, 0
	applymovement LOCALID_AZALEA_ARIADOS_RIGHT1, AzaleaTown_Gym_Movement_Ariados_Up
	waitmovement 0
	turnobject LOCALID_AZALEA_ARIADOS_RIGHT1, DIR_SOUTH
	delay 30
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_JumpDown1
	playse SE_LEDGE
	waitmovement 0
	waitmovement 0
	applymovement LOCALID_AZALEA_ARIADOS_RIGHT1, AzaleaTown_Gym_Movement_Ariados_Down
	delay 3
	applymovement OBJ_EVENT_ID_PLAYER, AzaleaTown_Gym_Movement_Player_Down
	waitmovement 0
	waitmovement 0
	@turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	applymovement LOCALID_AZALEA_ARIADOS_RIGHT1, AzaleaTown_Gym_Movement_Ariados_Left
	applymovement OBJ_EVENT_ID_PLAYER, AzaleaTown_Gym_Movement_Player_Left
	waitmovement 0
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	applymovement LOCALID_AZALEA_ARIADOS_RIGHT1, AzaleaTown_Gym_Movement_Ariados_Down
	delay 3
	applymovement OBJ_EVENT_ID_PLAYER, AzaleaTown_Gym_Movement_Player_Down
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_JumpDown1
	playse SE_LEDGE
	waitmovement 0
	applymovement LOCALID_AZALEA_ARIADOS_RIGHT1, AzaleaTown_Gym_Movement_Ariados_Up
	waitmovement 0
	setflag FLAG_HIDE_AZALEA_ARIADOS_RIGHT
	removeobject LOCALID_AZALEA_ARIADOS_RIGHT1
	resetobjectsubpriority OBJ_EVENT_ID_PLAYER, MAP_AZALEA_TOWN_GYM
	release
	end

@ 3-10->4,  4-8->3
AzaleaTown_Gym_EventScript_Trigger_3::
	lock
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	clearflag FLAG_HIDE_AZALEA_ARIADOS_RIGHT
	addobject LOCALID_AZALEA_ARIADOS_RIGHT1
	SetObjectSubpriority OBJ_EVENT_ID_PLAYER, MAP_AZALEA_TOWN_GYM, 0
	applymovement LOCALID_AZALEA_ARIADOS_RIGHT1, AzaleaTown_Gym_Movement_Ariados_Down
	waitmovement 0
	turnobject LOCALID_AZALEA_ARIADOS_RIGHT1, DIR_NORTH
	delay 30
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_JumpUp1
	playse SE_LEDGE
	waitmovement 0
	waitmovement 0
	applymovement LOCALID_AZALEA_ARIADOS_RIGHT1, AzaleaTown_Gym_Movement_Ariados_Up
	applymovement OBJ_EVENT_ID_PLAYER, AzaleaTown_Gym_Movement_Player_Up
	waitmovement 0
	waitmovement 0
	@turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	applymovement LOCALID_AZALEA_ARIADOS_RIGHT1, AzaleaTown_Gym_Movement_Ariados_Left
	applymovement OBJ_EVENT_ID_PLAYER, AzaleaTown_Gym_Movement_Player_Left
	waitmovement 0
	waitmovement 0
	applymovement LOCALID_AZALEA_ARIADOS_RIGHT1, AzaleaTown_Gym_Movement_Ariados_Left
	applymovement OBJ_EVENT_ID_PLAYER, AzaleaTown_Gym_Movement_Player_Left
	waitmovement 0
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	applymovement LOCALID_AZALEA_ARIADOS_RIGHT1, AzaleaTown_Gym_Movement_Ariados_Up
	applymovement OBJ_EVENT_ID_PLAYER, AzaleaTown_Gym_Movement_Player_Up
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_JumpUp1
	playse SE_LEDGE
	waitmovement 0
	applymovement LOCALID_AZALEA_ARIADOS_RIGHT1, AzaleaTown_Gym_Movement_Ariados_Down
	waitmovement 0
	setflag FLAG_HIDE_AZALEA_ARIADOS_RIGHT
	removeobject LOCALID_AZALEA_ARIADOS_RIGHT1
	resetobjectsubpriority OBJ_EVENT_ID_PLAYER, MAP_AZALEA_TOWN_GYM
	release
	end

AzaleaTown_Gym_EventScript_Trigger_4::
	lock
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	clearflag FLAG_HIDE_AZALEA_ARIADOS_LEFT
	addobject LOCALID_AZALEA_ARIADOS_LEFT1
	SetObjectSubpriority OBJ_EVENT_ID_PLAYER, MAP_AZALEA_TOWN_GYM, 0
	applymovement LOCALID_AZALEA_ARIADOS_LEFT1, AzaleaTown_Gym_Movement_Ariados_Up
	waitmovement 0
	turnobject LOCALID_AZALEA_ARIADOS_LEFT1, DIR_SOUTH
	delay 30
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_JumpDown1
	playse SE_LEDGE
	waitmovement 0
	waitmovement 0
	applymovement LOCALID_AZALEA_ARIADOS_LEFT1, AzaleaTown_Gym_Movement_Ariados_Down
	delay 3
	applymovement OBJ_EVENT_ID_PLAYER, AzaleaTown_Gym_Movement_Player_Down
	waitmovement 0
	waitmovement 0
	@turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	applymovement LOCALID_AZALEA_ARIADOS_LEFT1, AzaleaTown_Gym_Movement_Ariados_Right
	applymovement OBJ_EVENT_ID_PLAYER, AzaleaTown_Gym_Movement_Player_Right
	waitmovement 0
	waitmovement 0
	applymovement LOCALID_AZALEA_ARIADOS_LEFT1, AzaleaTown_Gym_Movement_Ariados_Right
	applymovement OBJ_EVENT_ID_PLAYER, AzaleaTown_Gym_Movement_Player_Right
	waitmovement 0
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	applymovement LOCALID_AZALEA_ARIADOS_LEFT1, AzaleaTown_Gym_Movement_Ariados_Down
	delay 3
	applymovement OBJ_EVENT_ID_PLAYER, AzaleaTown_Gym_Movement_Player_Down
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_JumpDown1
	playse SE_LEDGE
	waitmovement 0
	applymovement LOCALID_AZALEA_ARIADOS_LEFT1, AzaleaTown_Gym_Movement_Ariados_Up
	waitmovement 0
	setflag FLAG_HIDE_AZALEA_ARIADOS_LEFT
	removeobject LOCALID_AZALEA_ARIADOS_LEFT1
	resetobjectsubpriority OBJ_EVENT_ID_PLAYER, MAP_AZALEA_TOWN_GYM
	release
	end

@ 7-11->10,  10-11->7
AzaleaTown_Gym_EventScript_Trigger_7::
	lock
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	clearflag FLAG_HIDE_AZALEA_ARIADOS_LEFT
	addobject LOCALID_AZALEA_ARIADOS_LEFT2
	SetObjectSubpriority OBJ_EVENT_ID_PLAYER, MAP_AZALEA_TOWN_GYM, 0
	applymovement LOCALID_AZALEA_ARIADOS_LEFT2, AzaleaTown_Gym_Movement_Ariados_Down
	waitmovement 0
	turnobject LOCALID_AZALEA_ARIADOS_LEFT2, DIR_NORTH
	delay 30
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_JumpUp1
	playse SE_LEDGE
	waitmovement 0
	waitmovement 0
	applymovement LOCALID_AZALEA_ARIADOS_LEFT2, AzaleaTown_Gym_Movement_Ariados_Up
	applymovement OBJ_EVENT_ID_PLAYER, AzaleaTown_Gym_Movement_Player_Up
	waitmovement 0
	waitmovement 0
	applymovement LOCALID_AZALEA_ARIADOS_LEFT2, AzaleaTown_Gym_Movement_Ariados_Up
	applymovement OBJ_EVENT_ID_PLAYER, AzaleaTown_Gym_Movement_Player_Up
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_JumpUp1
	playse SE_LEDGE
	waitmovement 0
	applymovement LOCALID_AZALEA_ARIADOS_LEFT2, AzaleaTown_Gym_Movement_Ariados_Down
	waitmovement 0
	setflag FLAG_HIDE_AZALEA_ARIADOS_LEFT
	removeobject LOCALID_AZALEA_ARIADOS_LEFT2
	resetobjectsubpriority OBJ_EVENT_ID_PLAYER, MAP_AZALEA_TOWN_GYM
	release
	end

AzaleaTown_Gym_EventScript_Trigger_10::
	lock
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	clearflag FLAG_HIDE_AZALEA_ARIADOS_LEFT
	addobject LOCALID_AZALEA_ARIADOS_LEFT2
	SetObjectSubpriority OBJ_EVENT_ID_PLAYER, MAP_AZALEA_TOWN_GYM, 0
	applymovement LOCALID_AZALEA_ARIADOS_LEFT2, AzaleaTown_Gym_Movement_Ariados_Up
	waitmovement 0
	turnobject LOCALID_AZALEA_ARIADOS_LEFT2, DIR_SOUTH
	delay 30
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_JumpDown1
	playse SE_LEDGE
	waitmovement 0
	waitmovement 0
	applymovement LOCALID_AZALEA_ARIADOS_LEFT2, AzaleaTown_Gym_Movement_Ariados_Down
	delay 3
	applymovement OBJ_EVENT_ID_PLAYER, AzaleaTown_Gym_Movement_Player_Down
	waitmovement 0
	waitmovement 0
	applymovement LOCALID_AZALEA_ARIADOS_LEFT2, AzaleaTown_Gym_Movement_Ariados_Down
	delay 3
	applymovement OBJ_EVENT_ID_PLAYER, AzaleaTown_Gym_Movement_Player_Down
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_JumpDown1
	playse SE_LEDGE
	waitmovement 0
	applymovement LOCALID_AZALEA_ARIADOS_LEFT2, AzaleaTown_Gym_Movement_Ariados_Up
	waitmovement 0
	setflag FLAG_HIDE_AZALEA_ARIADOS_LEFT
	removeobject LOCALID_AZALEA_ARIADOS_LEFT2
	resetobjectsubpriority OBJ_EVENT_ID_PLAYER, MAP_AZALEA_TOWN_GYM
	release
	end


@ 8-12->12,  12-13->8
AzaleaTown_Gym_EventScript_Trigger_8::
	lock
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	clearflag FLAG_HIDE_AZALEA_ARIADOS_MID
	addobject LOCALID_AZALEA_ARIADOS_MID2
	SetObjectSubpriority OBJ_EVENT_ID_PLAYER, MAP_AZALEA_TOWN_GYM, 0
	applymovement LOCALID_AZALEA_ARIADOS_MID2, AzaleaTown_Gym_Movement_Ariados_Down
	waitmovement 0
	turnobject LOCALID_AZALEA_ARIADOS_MID2, DIR_NORTH
	delay 30
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_JumpUp1
	playse SE_LEDGE
	waitmovement 0
	waitmovement 0
	applymovement LOCALID_AZALEA_ARIADOS_MID2, AzaleaTown_Gym_Movement_Ariados_Up
	applymovement OBJ_EVENT_ID_PLAYER, AzaleaTown_Gym_Movement_Player_Up
	waitmovement 0
	waitmovement 0
	@turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	applymovement LOCALID_AZALEA_ARIADOS_MID2, AzaleaTown_Gym_Movement_Ariados_Right
	applymovement OBJ_EVENT_ID_PLAYER, AzaleaTown_Gym_Movement_Player_Right
	waitmovement 0
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	applymovement LOCALID_AZALEA_ARIADOS_MID2, AzaleaTown_Gym_Movement_Ariados_Up
	applymovement OBJ_EVENT_ID_PLAYER, AzaleaTown_Gym_Movement_Player_Up
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_JumpUp1
	playse SE_LEDGE
	waitmovement 0
	applymovement LOCALID_AZALEA_ARIADOS_MID2, AzaleaTown_Gym_Movement_Ariados_Down
	waitmovement 0
	setflag FLAG_HIDE_AZALEA_ARIADOS_MID
	removeobject LOCALID_AZALEA_ARIADOS_MID2
	resetobjectsubpriority OBJ_EVENT_ID_PLAYER, MAP_AZALEA_TOWN_GYM
	release
	end

AzaleaTown_Gym_EventScript_Trigger_12::
	lock
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	clearflag FLAG_HIDE_AZALEA_ARIADOS_RIGHT
	addobject LOCALID_AZALEA_ARIADOS_RIGHT2
	SetObjectSubpriority OBJ_EVENT_ID_PLAYER, MAP_AZALEA_TOWN_GYM, 0
	applymovement LOCALID_AZALEA_ARIADOS_RIGHT2, AzaleaTown_Gym_Movement_Ariados_Up
	waitmovement 0
	turnobject LOCALID_AZALEA_ARIADOS_RIGHT2, DIR_SOUTH
	delay 30
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_JumpDown1
	playse SE_LEDGE
	waitmovement 0
	waitmovement 0
	applymovement LOCALID_AZALEA_ARIADOS_RIGHT2, AzaleaTown_Gym_Movement_Ariados_Down
	delay 3
	applymovement OBJ_EVENT_ID_PLAYER, AzaleaTown_Gym_Movement_Player_Down
	waitmovement 0
	waitmovement 0
	@turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	applymovement LOCALID_AZALEA_ARIADOS_RIGHT2, AzaleaTown_Gym_Movement_Ariados_Left
	applymovement OBJ_EVENT_ID_PLAYER, AzaleaTown_Gym_Movement_Player_Left
	waitmovement 0
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	applymovement LOCALID_AZALEA_ARIADOS_RIGHT2, AzaleaTown_Gym_Movement_Ariados_Down
	delay 3
	applymovement OBJ_EVENT_ID_PLAYER, AzaleaTown_Gym_Movement_Player_Down
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_JumpDown1
	playse SE_LEDGE
	waitmovement 0
	applymovement LOCALID_AZALEA_ARIADOS_RIGHT2, AzaleaTown_Gym_Movement_Ariados_Up
	waitmovement 0
	setflag FLAG_HIDE_AZALEA_ARIADOS_RIGHT
	removeobject LOCALID_AZALEA_ARIADOS_RIGHT2
	resetobjectsubpriority OBJ_EVENT_ID_PLAYER, MAP_AZALEA_TOWN_GYM
	release
	end

@ 9-13->11,  11-12->9
AzaleaTown_Gym_EventScript_Trigger_9::
	lock
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	clearflag FLAG_HIDE_AZALEA_ARIADOS_RIGHT
	addobject LOCALID_AZALEA_ARIADOS_RIGHT2
	SetObjectSubpriority OBJ_EVENT_ID_PLAYER, MAP_AZALEA_TOWN_GYM, 0
	applymovement LOCALID_AZALEA_ARIADOS_RIGHT2, AzaleaTown_Gym_Movement_Ariados_Down
	waitmovement 0
	turnobject LOCALID_AZALEA_ARIADOS_RIGHT2, DIR_NORTH
	delay 30
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_JumpUp1
	playse SE_LEDGE
	waitmovement 0
	waitmovement 0
	applymovement LOCALID_AZALEA_ARIADOS_RIGHT2, AzaleaTown_Gym_Movement_Ariados_Up
	applymovement OBJ_EVENT_ID_PLAYER, AzaleaTown_Gym_Movement_Player_Up
	waitmovement 0
	waitmovement 0
	@turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	applymovement LOCALID_AZALEA_ARIADOS_RIGHT2, AzaleaTown_Gym_Movement_Ariados_Left
	applymovement OBJ_EVENT_ID_PLAYER, AzaleaTown_Gym_Movement_Player_Left
	waitmovement 0
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	applymovement LOCALID_AZALEA_ARIADOS_RIGHT2, AzaleaTown_Gym_Movement_Ariados_Up
	applymovement OBJ_EVENT_ID_PLAYER, AzaleaTown_Gym_Movement_Player_Up
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_JumpUp1
	playse SE_LEDGE
	waitmovement 0
	applymovement LOCALID_AZALEA_ARIADOS_RIGHT2, AzaleaTown_Gym_Movement_Ariados_Down
	waitmovement 0
	setflag FLAG_HIDE_AZALEA_ARIADOS_RIGHT
	removeobject LOCALID_AZALEA_ARIADOS_RIGHT2
	resetobjectsubpriority OBJ_EVENT_ID_PLAYER, MAP_AZALEA_TOWN_GYM
	release
	end

AzaleaTown_Gym_EventScript_Trigger_11::
	lock
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	clearflag FLAG_HIDE_AZALEA_ARIADOS_MID
	addobject LOCALID_AZALEA_ARIADOS_MID2
	SetObjectSubpriority OBJ_EVENT_ID_PLAYER, MAP_AZALEA_TOWN_GYM, 0
	applymovement LOCALID_AZALEA_ARIADOS_MID2, AzaleaTown_Gym_Movement_Ariados_Up
	waitmovement 0
	turnobject LOCALID_AZALEA_ARIADOS_MID2, DIR_SOUTH
	delay 30
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_JumpDown1
	playse SE_LEDGE
	waitmovement 0
	waitmovement 0
	applymovement LOCALID_AZALEA_ARIADOS_MID2, AzaleaTown_Gym_Movement_Ariados_Down
	delay 3
	applymovement OBJ_EVENT_ID_PLAYER, AzaleaTown_Gym_Movement_Player_Down
	waitmovement 0
	waitmovement 0
	@turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	applymovement LOCALID_AZALEA_ARIADOS_MID2, AzaleaTown_Gym_Movement_Ariados_Right
	applymovement OBJ_EVENT_ID_PLAYER, AzaleaTown_Gym_Movement_Player_Right
	waitmovement 0
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	applymovement LOCALID_AZALEA_ARIADOS_MID2, AzaleaTown_Gym_Movement_Ariados_Down
	delay 3
	applymovement OBJ_EVENT_ID_PLAYER, AzaleaTown_Gym_Movement_Player_Down
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_JumpDown1
	playse SE_LEDGE
	waitmovement 0
	applymovement LOCALID_AZALEA_ARIADOS_MID2, AzaleaTown_Gym_Movement_Ariados_Up
	waitmovement 0
	setflag FLAG_HIDE_AZALEA_ARIADOS_MID
	removeobject LOCALID_AZALEA_ARIADOS_MID2
	resetobjectsubpriority OBJ_EVENT_ID_PLAYER, MAP_AZALEA_TOWN_GYM
	release
	end

AzaleaTown_Gym_EventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_BADGE02_GET, AzaleaTown_Gym_EventScript_GymGuy2
	msgbox AzaleaTown_Gym_Text_GymGuide, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_Gym_EventScript_GymGuy2::
	msgbox AzaleaTown_Gym_Text_GymGuideWin, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_Gym_EventScript_Al::
	trainerbattle_single TRAINER_AL AzaleaTown_Gym_Text_BugCatcherAlSeen, AzaleaTown_Gym_Text_BugCatcherAlBeaten
	msgbox AzaleaTown_Gym_Text_BugCatcherAlAfter, MSGBOX_AUTOCLOSE
	end

AzaleaTown_Gym_EventScript_Josh::
	trainerbattle_single TRAINER_JOSH AzaleaTown_Gym_Text_BugCatcherJoshSeen, AzaleaTown_Gym_Text_BugCatcherJoshBeaten
	msgbox AzaleaTown_Gym_Text_BugCatcherJoshAfter, MSGBOX_AUTOCLOSE
	end

AzaleaTown_Gym_EventScript_Benny::
	trainerbattle_single TRAINER_BENNY AzaleaTown_Gym_Text_BugCatcherBennySeen, AzaleaTown_Gym_Text_BugCatcherBennyBeaten
	msgbox AzaleaTown_Gym_Text_BugCatcherBennyAfter, MSGBOX_AUTOCLOSE
	end

AzaleaTown_Gym_EventScript_Amy::
	trainerbattle_double TRAINER_AMY_AND_MAY, AzaleaTown_Gym_Text_TwinsAmyMay1Seen, AzaleaTown_Gym_Text_TwinsAmyMay1Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox AzaleaTown_Gym_Text_TwinsAmyMay1After, MSGBOX_DEFAULT
	release
	end
	
AzaleaTown_Gym_EventScript_May::
	trainerbattle_double TRAINER_AMY_AND_MAY, AzaleaTown_Gym_Text_TwinsAmyMay2Seen, AzaleaTown_Gym_Text_TwinsAmyMay2Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox AzaleaTown_Gym_Text_TwinsAmyMay2After, MSGBOX_DEFAULT
	release
	end

AzaleaTown_Gym_EventScript_Bugsy::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_AZALEA_TOWN_GYM, AzaleaTown_Gym_EventScript_Bugsy_Defeated
	msgbox AzaleaTown_Gym_Text_BugsyIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_BUGSY_1, AzaleaTown_Gym_Text_BugsyBeaten
	message AzaleaTown_Gym_Text_ReceivedHiveBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox AzaleaTown_Gym_Text_HiveBadgeSpeech, MSGBOX_DEFAULT
	setflag FLAG_BADGE02_GET
	setflag FLAG_DEFEATED_AZALEA_TOWN_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 2
	call Common_EventScript_SetGymTrainers
	giveitem ITEM_TM_BULLET_SEED
	msgbox AzaleaTown_Gym_Text_FuryCutterSpeech, MSGBOX_DEFAULT
	setvar VAR_AZALEA_TOWN_STATE, 5
	closemessage
	setflag FLAG_HIDE_AZALEA_TOWN_FARFETCHD
	setflag FLAG_GET_HEADBUTT
	clearflag FLAG_HIDE_ILEX_FOREST_APPRENTICE
	clearflag FLAG_HIDE_ILEX_FOREST_FARFETCHD_1
	release
	end

AzaleaTown_Gym_EventScript_Bugsy_Defeated::
	msgbox AzaleaTown_Gym_Text_BugsyAdvice, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_Gym_Movement_Ariados_Down:
	delay_8
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

AzaleaTown_Gym_Movement_Ariados_Up:
	delay_8
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

AzaleaTown_Gym_Movement_Ariados_Right:
	lock_facing_direction
	delay_8
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	unlock_facing_direction
	step_end

AzaleaTown_Gym_Movement_Ariados_Left:
	lock_facing_direction
	delay_8
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	unlock_facing_direction
	step_end

AzaleaTown_Gym_Movement_Player_Down:
	lock_anim
	delay_8
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	unlock_anim
	unlock_facing_direction
	step_end

AzaleaTown_Gym_Movement_Player_Up:
	lock_anim
	delay_8
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	unlock_anim
	unlock_facing_direction
	step_end

AzaleaTown_Gym_Movement_Player_Right:
	lock_facing_direction
	lock_anim
	delay_8
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	unlock_anim
	unlock_facing_direction
	step_end

AzaleaTown_Gym_Movement_Player_Left:
	lock_facing_direction
	lock_anim
	delay_8
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	unlock_anim
	unlock_facing_direction
	step_end

AzaleaTown_Gym_EventScript_Statue::
	lock
	goto_if_set FLAG_DEFEATED_AZALEA_TOWN_GYM, AzaleaTown_Gym_EventScript_Statue2
	msgbox AzaleaTown_Gym_Text_GymStatue, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_Gym_EventScript_Statue2::
	msgbox AzaleaTown_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_Gym_Text_GymStatue:
	.string "AZALEA POKéMON GYM$"

AzaleaTown_Gym_Text_GymStatueCertified:
	.string "AZALEA TOWN POKéMON GYM\p"
	.string "BUGSY'S CERTIFIED TRAINERS:\n"
	.string "{PLAYER}$"

AzaleaTown_Gym_Text_BugsyIntro:
	.string "Je suis HECTOR !\p"
	.string "Je ne perds jamais quand il s'agit\n"
	.string "de POKéMON de type Insecte.\p"
	.string "Mes recherches vont faire de moi\n"
	.string "l'autorité sur les POKéMON Insecte !\p"
	.string "Par exemple, savais-tu que\n"
	.string "la capacité COUPE est en fait\l"
	.string "de type INSECTE ?\p"
	.string "Laisse-moi te montrer tout ce que\n"
	.string "j'ai appris de mes études.$"

AzaleaTown_Gym_Text_BugsyBeaten:
	.string "Ouah, incroyable ! Tu es un\n"
	.string "expert en POKéMON !\p"
	.string "Mes recherches ne sont pas encore\n"
	.string "terminées.\p"
	.string "OK, tu as gagné. Prends ce\n"
	.string "BADGE.$"

AzaleaTown_Gym_Text_ReceivedHiveBadge:
	.string "{PLAYER} reçoit le BADGE RUCHE.$"

AzaleaTown_Gym_Text_HiveBadgeSpeech:
	.string "Tu connais les avantages\n"
	.string "du BADGE RUCHE ?\p"
	.string "Si tu l'as, les POKéMON jusqu'au\n"
	.string "niveau 30 t'obéiront,\l"
	.string "même ceux échangés.\p"
	.string "Les POKéMON connaissant COUPE pourront\n"
	.string "l'utiliser aussi hors combat.\p"
	.string "Tiens, je veux aussi que tu\n"
	.string "prennes ceci.$"

AzaleaTown_Gym_Text_FuryCutterSpeech:
	.string "CT09 contient BALLE GRAINE.\p"
	.string "Elle lance une pluie de graines\n"
	.string "2 à 5 fois à chaque tour.\p"
	.string "Donc même si la puissance est de 25,\n"
	.string "ça fait en réalité entre 50 et 125 !\p"
	.string "N'est-ce pas génial ?\n"
	.string "C'est moi qui l'ai découverte !$"

AzaleaTown_Gym_Text_BugsyAdvice:
	.string "Les POKéMON Insecte sont profonds.\n"
	.string "Il y a beaucoup de mystères à explorer.\p"
	.string "Étudie bien tes préférés.$"

AzaleaTown_Gym_Text_BugsyRematch:
	.string "Wow, tu es le CHAMPION de JOHTO maintenant !\p"
	.string "Tes compétences sont vraiment impressionnantes !\p"
	.string "J'ai été occupé par mes recherches.\p"
	.string "Je suis prêt à te montrer mes\n"
	.string "nouvelles découvertes.\p"
	.string "Veux-tu faire un match revanche avec moi ?$"

AzaleaTown_Gym_Text_BugsyRematchDefeat:
	.string "Wow, tu dois être un dresseur expert.\n"
	.string "Mes recherches ne doivent pas être terminées...$"

AzaleaTown_Gym_Text_BugCatcherBennySeen:
	.string "Les POKéMON Insecte évoluent jeunes.\n"
	.string "Ils deviennent donc plus forts plus vite.$"

AzaleaTown_Gym_Text_BugCatcherBennyBeaten:
	.string "Évoluer ne suffit pas !$"

AzaleaTown_Gym_Text_BugCatcherBennyAfter:
	.string "Les POKéMON deviennent plus forts\n"
	.string "s'ils évoluent. C'est vrai !$"

AzaleaTown_Gym_Text_BugCatcherAlSeen:
	.string "Les POKéMON Insecte sont cool et costauds !\n"
	.string "Je vais te le prouver !$"

AzaleaTown_Gym_Text_BugCatcherAlBeaten:
	.string "Tu as prouvé à quel point tu es fort…$"

AzaleaTown_Gym_Text_BugCatcherAlAfter:
	.string "Ils sont trop cool, mais la plupart des filles\n"
	.string "n'aiment pas les POKéMON Insecte.\p"
	.string "Je ne sais pas pourquoi…$"

AzaleaTown_Gym_Text_BugCatcherJoshSeen:
	.string "Tu as sauvé tous les RAMOLOSS ?\n"
	.string "Ouf, tu es vraiment fort !\p"
	.string "Mais mes POKéMON adultes sont\n"
	.string "aussi très costauds !$"

AzaleaTown_Gym_Text_BugCatcherJoshBeaten:
	.string "Urrgggh !$"

AzaleaTown_Gym_Text_BugCatcherJoshAfter:
	.string "Je devrais peut-être leur apprendre\n"
	.string "de meilleures attaques…$"

AzaleaTown_Gym_Text_TwinsAmyMay1Seen:
	.string "AMY : Salut ! Tu défies\n"
	.string "le CHAMPION ? Pas question !$"

AzaleaTown_Gym_Text_TwinsAmyMay1Beaten:
	.string "AMY & MAY : Oh, double\n"
	.string "surprise !$"

AzaleaTown_Gym_Text_TwinsAmyMay1After:
	.string "AMY : Tu es vraiment fort !\p"
	.string "Mais HECTOR est encore plus fort !\n"
	.string "Son SCARHINO utilise COUPE qui\l"
	.string "fait presque toujours des coups critiques !$"

AzaleaTown_Gym_Text_TwinsAmyMay2Seen:
	.string "MAY : Tu veux voir le\n"
	.string "CHAMPION ? Bonne chance !\p"
	.string "HECTOR est si fort !\n"
	.string "Son SCARHINO utilise COUPE qui\l"
	.string "semble toujours faire un critique !$"

AzaleaTown_Gym_Text_TwinsAmyMay2Beaten:
	.string "AMY & MAY : Oh, double\n"
	.string "surprise !$"

AzaleaTown_Gym_Text_TwinsAmyMay2After:
	.string "MAY : Nos POKéMON Insecte ont perdu !\n"
	.string "Oh, quel dommage.\p"
	.string "Mais ceux d'HECTOR ne perdront pas !\p"
	.string "Son POMDEPIC bat facilement\n"
	.string "les POKéMON de type ROCHE !$"

AzaleaTown_Gym_Text_GymGuide:
	.string "Yo, challenger !\p"
	.string "HECTOR est jeune, mais ses connaissances\n"
	.string "sur les POKéMON Insecte sont réelles.\p"
	.string "Ça va être dur sans mes conseils.\p"
	.string "Voyons voir… Le POKéMON sac de HECTOR\n"
	.string "connaît une attaque qui couvre sa\l"
	.string "faiblesse au type ROCHE.\p"
	.string "Il a aussi développé une nouvelle version\n"
	.string "de COUPE de type INSECTE.\p"
	.string "Et n'oublie pas ces vilains coups critiques !\n"
	.string "Bonne chance !$"

AzaleaTown_Gym_Text_GymGuideWin:
	.string "Bravo ! C'était un superbe\n"
	.string "duel de jeunes dresseurs talentueux.\p"
	.string "Avec des gens comme toi, le\n"
	.string "futur des POKéMON est radieux !$"
