.set LOCALID_LUGIA, 8
.set LOCALID_KIMONO_MID, 4
.set LOCALID_KIMONO_1, 3
.set LOCALID_KIMONO_2, 6
.set LOCALID_KIMONO_3, 7
.set LOCALID_KIMONO_4, 5

WhirlIslands1_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, WhirlIslands1_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, WhirlIslands1_OnResume
	.byte 0

WhirlIslands1_OnTransition:
	call_if_set FLAG_CAUGHT_LUGIA, WhirlIslands1_EventScript_HideLugia
	call_if_unset FLAG_CAUGHT_LUGIA, WhirlIslands1_EventScript_TryShowLugia
	end

WhirlIslands1_EventScript_HideLugia::
	setvar VAR_TEMP_1, 1
	setflag FLAG_HIDE_LUGIA
	return

WhirlIslands1_EventScript_TryShowLugia::
	setvar VAR_TEMP_1, 1
	goto_if_set FLAG_DEFEATED_LUGIA, Common_EventScript_NopReturn
	setvar VAR_TEMP_1, 0
	clearflag FLAG_HIDE_LUGIA
	return

WhirlIslands1_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, WhirlIslands1_EventScript_TryRemoveLugia
	end

WhirlIslands1_EventScript_TryRemoveLugia::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject LOCALID_LUGIA
	return

WhirlIslands1_EventScript_Lugia::
	lockall
	setvar VAR_TEMP_1, 1
	special SpawnCameraObject
	setvar VAR_0x8004, 3  @ num loops
	setvar VAR_0x8005, 35 @ delay
	special LoopWingFlapSE
	applymovement LOCALID_LUGIA, WhirlIslands1_Movement_LugiaAppear
	applymovement OBJ_EVENT_ID_CAMERA, WhirlIslands1_Movement_CameraPanUp
	waitmovement 0
	delay 50
	setweather WEATHER_NONE
	doweather
	waitse
	playmoncry SPECIES_LUGIA, CRY_MODE_ENCOUNTER
	delay 30
	waitmoncry
	delay 60
	setvar VAR_0x8004, 3  @ num loops
	setvar VAR_0x8005, 35 @ delay
	special LoopWingFlapSE
	applymovement OBJ_EVENT_ID_CAMERA, WhirlIslands1_Movement_CameraPanDown
	applymovement LOCALID_LUGIA, WhirlIslands1_Movement_LugiaApproach
	waitmovement 0
	special RemoveCameraObject
	seteventmon SPECIES_LUGIA, 70
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	setvar VAR_LAST_TALKED, LOCALID_LUGIA
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, WhirlIslands1_EventScript_DefeatedLugia
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, WhirlIslands1_EventScript_RanFromLugia
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, WhirlIslands1_EventScript_RanFromLugia
	setflag FLAG_CAUGHT_LUGIA
	setvar VAR_COMPLETED_LUGIA, 1
	applymovement LOCALID_KIMONO_MID, WhirlIslands1_Movement_Kimono_Dance_Shift_Right
	call_if_set FLAG_EXTRA_LEGENDARIES, WhirlIslands1_Enable_Kanto_Legendaries
	releaseall
	end

WhirlIslands1_eventScript_TalkToKimono::
	lockall
	playbgm MUS_HG_KIMONO_GIRL_DANCE, TRUE
	msgbox WhirlIslands1_Text_Kimono_Opening, MSGBOX_DEFAULT
	closemessage

	applymovement LOCALID_KIMONO_MID, WhirlIslands1_Movement_Kimono_Step_Aside
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, WhirlIslands1_Walk_To_Center
	waitmovement 0
	applymovement LOCALID_KIMONO_MID, WhirlIslands1_Movement_Kimono_Step_In
	applymovement LOCALID_KIMONO_1, WhirlIslands1_Movement_Kimono_Step_Start_Left
	applymovement LOCALID_KIMONO_4, WhirlIslands1_Movement_Kimono_Step_Start_Right
	waitmovement 5
	playse SE_M_PETAL_DANCE
	applymovement LOCALID_KIMONO_MID, WhirlIslands1_Movement_Kimono_Dance_Mid
	waitmovement 0
	playse SE_M_PETAL_DANCE
	applymovement LOCALID_KIMONO_1, WhirlIslands1_Movement_Kimono_Dance_Mid
	applymovement LOCALID_KIMONO_2, WhirlIslands1_Movement_Kimono_Dance_Mid
	applymovement LOCALID_KIMONO_3, WhirlIslands1_Movement_Kimono_Dance_Mid
	applymovement LOCALID_KIMONO_4, WhirlIslands1_Movement_Kimono_Dance_Mid
	applymovement LOCALID_KIMONO_MID, WhirlIslands1_Movement_Kimono_Dance_Mid	
	waitmovement 0
	playse SE_M_PETAL_DANCE
	setweather WEATHER_FOG_HORIZONTAL
	doweather
	@ 1
	applymovement LOCALID_KIMONO_1, WhirlIslands1_Movement_Kimono_Dance_Shift_Down
	applymovement LOCALID_KIMONO_2, WhirlIslands1_Movement_Kimono_Dance_Shift_Right
	applymovement LOCALID_KIMONO_3, WhirlIslands1_Movement_Kimono_Dance_Shift_Up
	applymovement LOCALID_KIMONO_4, WhirlIslands1_Movement_Kimono_Dance_Shift_Left
	waitmovement LOCALID_KIMONO_4
	delay 30
	applymovement LOCALID_KIMONO_1, WhirlIslands1_Movement_Kimono_Dance_Mid
	applymovement LOCALID_KIMONO_2, WhirlIslands1_Movement_Kimono_Dance_Mid
	applymovement LOCALID_KIMONO_3, WhirlIslands1_Movement_Kimono_Dance_Mid
	applymovement LOCALID_KIMONO_4, WhirlIslands1_Movement_Kimono_Dance_Mid
	applymovement LOCALID_KIMONO_MID, WhirlIslands1_Movement_Kimono_Dance_Mid
	waitmovement 0
	playse SE_M_PETAL_DANCE
	@ 2
	applymovement LOCALID_KIMONO_1, WhirlIslands1_Movement_Kimono_Dance_Shift_Down
	applymovement LOCALID_KIMONO_2, WhirlIslands1_Movement_Kimono_Dance_Shift_Far_Right
	applymovement LOCALID_KIMONO_3, WhirlIslands1_Movement_Kimono_Dance_Shift_Up
	applymovement LOCALID_KIMONO_4, WhirlIslands1_Movement_Kimono_Dance_Shift_Far_Left
	waitmovement LOCALID_KIMONO_4
	delay 30
	applymovement LOCALID_KIMONO_1, WhirlIslands1_Movement_Kimono_Dance_Mid
	applymovement LOCALID_KIMONO_2, WhirlIslands1_Movement_Kimono_Dance_Mid
	applymovement LOCALID_KIMONO_3, WhirlIslands1_Movement_Kimono_Dance_Mid
	applymovement LOCALID_KIMONO_4, WhirlIslands1_Movement_Kimono_Dance_Mid
	applymovement LOCALID_KIMONO_MID, WhirlIslands1_Movement_Kimono_Dance_Mid
	waitmovement 0
	playse SE_M_PETAL_DANCE
	@ 3
	applymovement LOCALID_KIMONO_1, WhirlIslands1_Movement_Kimono_Dance_Shift_Right
	applymovement LOCALID_KIMONO_2, WhirlIslands1_Movement_Kimono_Dance_Shift_Up
	applymovement LOCALID_KIMONO_3, WhirlIslands1_Movement_Kimono_Dance_Shift_Left
	applymovement LOCALID_KIMONO_4, WhirlIslands1_Movement_Kimono_Dance_Shift_Down
	waitmovement LOCALID_KIMONO_3
	delay 30
	applymovement LOCALID_KIMONO_1, WhirlIslands1_Movement_Kimono_Dance_Mid
	applymovement LOCALID_KIMONO_2, WhirlIslands1_Movement_Kimono_Dance_Mid
	applymovement LOCALID_KIMONO_3, WhirlIslands1_Movement_Kimono_Dance_Mid
	applymovement LOCALID_KIMONO_4, WhirlIslands1_Movement_Kimono_Dance_Mid
	applymovement LOCALID_KIMONO_MID, WhirlIslands1_Movement_Kimono_Dance_Mid
	waitmovement 0
	playse SE_M_PETAL_DANCE
	@ 4
	applymovement LOCALID_KIMONO_1, WhirlIslands1_Movement_Kimono_Dance_Shift_Far_Right
	applymovement LOCALID_KIMONO_2, WhirlIslands1_Movement_Kimono_Dance_Shift_Up
	applymovement LOCALID_KIMONO_3, WhirlIslands1_Movement_Kimono_Dance_Shift_Far_Left
	applymovement LOCALID_KIMONO_4, WhirlIslands1_Movement_Kimono_Dance_Shift_Down
	waitmovement LOCALID_KIMONO_3
	delay 30
	applymovement LOCALID_KIMONO_1, WhirlIslands1_Movement_Kimono_Dance_Mid
	applymovement LOCALID_KIMONO_2, WhirlIslands1_Movement_Kimono_Dance_Mid
	applymovement LOCALID_KIMONO_3, WhirlIslands1_Movement_Kimono_Dance_Mid
	applymovement LOCALID_KIMONO_4, WhirlIslands1_Movement_Kimono_Dance_Mid
	applymovement LOCALID_KIMONO_MID, WhirlIslands1_Movement_Kimono_Dance_Mid
	waitmovement 0
	playse SE_M_PETAL_DANCE
	@ 5
	applymovement LOCALID_KIMONO_1, WhirlIslands1_Movement_Kimono_Dance_Shift_Left_Up
	applymovement LOCALID_KIMONO_4, WhirlIslands1_Movement_Kimono_Dance_Shift_Right_Up
	applymovement LOCALID_KIMONO_MID, WhirlIslands1_Movement_Kimono_Dance_Step_Up
	waitmovement LOCALID_KIMONO_1
	delay 30
	applymovement LOCALID_KIMONO_1, WhirlIslands1_Movement_Kimono_Dance_Mid
	applymovement LOCALID_KIMONO_2, WhirlIslands1_Movement_Kimono_Dance_Mid
	applymovement LOCALID_KIMONO_3, WhirlIslands1_Movement_Kimono_Dance_Mid
	applymovement LOCALID_KIMONO_4, WhirlIslands1_Movement_Kimono_Dance_Mid
	applymovement LOCALID_KIMONO_MID, WhirlIslands1_Movement_Kimono_Dance_Mid
	waitmovement 0
	playse SE_M_PETAL_DANCE
	waitse


	setvar VAR_TEMP_1, 1
	special SpawnCameraObject
	setvar VAR_0x8004, 3  @ num loops
	setvar VAR_0x8005, 35 @ delay
	special LoopWingFlapSE
	applymovement LOCALID_LUGIA, WhirlIslands1_Movement_LugiaAppear
	applymovement OBJ_EVENT_ID_CAMERA, WhirlIslands1_Movement_CameraPanUp
	waitmovement 0
	delay 50
	@ setweather WEATHER_NONE
	@ doweather
	waitse
	playmoncry SPECIES_LUGIA, CRY_MODE_ENCOUNTER
	delay 30
	waitmoncry
	delay 60
	setvar VAR_0x8004, 3  @ num loops
	setvar VAR_0x8005, 35 @ delay
	special LoopWingFlapSE
	applymovement LOCALID_LUGIA, WhirlIslands1_Movement_LugiaApproach
	waitmovement 0
	applymovement OBJ_EVENT_ID_CAMERA, WhirlIslands1_Movement_CameraPanDown
	waitmovement 0
	special RemoveCameraObject



	applymovement LOCALID_KIMONO_MID, WhirlIslands1_Movement_Kimono_Dance_Look_Up
	applymovement LOCALID_KIMONO_1, WhirlIslands1_Movement_Kimono_Dance_Look_Up
	applymovement LOCALID_KIMONO_2, WhirlIslands1_Movement_Kimono_Dance_Look_Up
	applymovement LOCALID_KIMONO_3, WhirlIslands1_Movement_Kimono_Dance_Look_Up
	applymovement LOCALID_KIMONO_4, WhirlIslands1_Movement_Kimono_Dance_Look_Up
	waitmovement 0
	msgbox WhirlIslands1_Text_Kimono_Closing1, MSGBOX_DEFAULT
	waitmessage
	closemessage


	releaseall
	end

WhirlIslands1_EventScript_TalkToLugia::
	lockall
	waitse
	playmoncry SPECIES_LUGIA, CRY_MODE_ENCOUNTER
	delay 30
	waitmoncry
	playbgm MUS_HG_VS_LUGIA, 0
	seteventmon SPECIES_LUGIA, 70
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	setflag FLAG_HIDE_WHIRL_ISLANDS_KIMONO_GIRLS
	applymovement LOCALID_KIMONO_MID, WhirlIslands1_Movement_Kimono_Dance_Shift_Right2
	waitmovement 0
	setvar VAR_LAST_TALKED, LOCALID_LUGIA
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, WhirlIslands1_EventScript_DefeatedLugia
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, WhirlIslands1_EventScript_RanFromLugia
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, WhirlIslands1_EventScript_RanFromLugia
	setflag FLAG_CAUGHT_LUGIA
	setvar VAR_COMPLETED_LUGIA, 1
	call_if_set FLAG_EXTRA_LEGENDARIES, WhirlIslands1_Enable_Kanto_Legendaries
	releaseall
	end

WhirlIslands1_Enable_Kanto_Legendaries::
	setflag FLAG_UNLOCK_BIRDS
	playmoncry SPECIES_ARTICUNO, CRY_MODE_NORMAL
	waitmoncry
	playmoncry SPECIES_ZAPDOS, CRY_MODE_NORMAL
	waitmoncry
	playmoncry SPECIES_MOLTRES, CRY_MODE_NORMAL
	waitmoncry
	return

WhirlIslands1_EventScript_DefeatedLugia::
	setflag FLAG_DEFEATED_LUGIA
	call_if_set FLAG_EXTRA_LEGENDARIES, WhirlIslands1_Enable_Kanto_Legendaries
	setvar VAR_0x8004, SPECIES_LUGIA
	setvar VAR_COMPLETED_LUGIA, 1
	goto Common_EventScript_LegendaryFlewAway
	end

WhirlIslands1_EventScript_RanFromLugia::
	setflag FLAG_DEFEATED_LUGIA
	setvar VAR_0x8004, SPECIES_LUGIA
	setvar VAR_COMPLETED_LUGIA, 1
	goto Common_EventScript_LegendaryFlewAway
	end

WhirlIslands1_EventScript_Kimono::
	lock
	faceplayer
	goto_if_eq VAR_COMPLETED_LUGIA, 1, WhirlIslands1_EventScript_Kimono_After
	msgbox WhirlIslands1_Text_Kimono_Before, MSGBOX_DEFAULT 
	closemessage
	release
	end


WhirlIslands1_EventScript_Kimono_After::
	msgbox WhirlIslands1_Text_Kimono_After, MSGBOX_DEFAULT
	closemessage
	release
	end


WhirlIslands1_Movement_CameraPanUp:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

WhirlIslands1_Movement_CameraPanDown:
	delay_16
	delay_16
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

WhirlIslands1_Movement_LugiaApproach:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_in_place_down
	delay_16
	delay_16
	step_end

WhirlIslands1_Movement_LugiaAppear:
	delay_16
	delay_16
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	step_end


WhirlIslands1_Movement_Kimono_Step_Aside:
	face_right
	delay_16
	walk_right
	delay_16
	face_left
	step_end

WhirlIslands1_Walk_To_Center:
	walk_up
	walk_up
	walk_up
	delay_16
	face_down
	step_end

WhirlIslands1_Movement_Kimono_Step_In:
	walk_left
	delay_16
	face_down
	step_end


WhirlIslands1_Movement_Kimono_Step_Start_Left:
	face_right
	delay_16
	face_up
	delay_16
	walk_up
	walk_up
	delay_16
	face_left
	delay_16
	walk_left
	delay_16
	face_down
	step_end

WhirlIslands1_Movement_Kimono_Step_Start_Right:
	face_right
	delay_16
	face_up
	delay_16
	walk_up
	walk_up
	delay_16
	face_right
	delay_16
	walk_right
	delay_16
	face_down
	step_end

WhirlIslands1_Movement_Kimono_Dance_Mid:
	face_down
	delay_8
	face_right
	delay_8
	face_up
	delay_8
	face_left
	delay_8
	face_down
	delay_8
	delay_8
	delay_8
	delay_8
	delay_8
	delay_16
	face_down
	delay_8
	face_right
	delay_8
	face_up
	delay_8
	face_left
	delay_8
	face_down
	delay_16
	step_end

WhirlIslands1_Movement_Kimono_Dance_Shift_Down:
	face_down
	delay_8
	walk_down
	delay_8
	face_down
	delay_16
	step_end

WhirlIslands1_Movement_Kimono_Dance_Shift_Right:
	face_right
	delay_8
	walk_right
	delay_8
	face_down
	delay_16
	step_end

WhirlIslands1_Movement_Kimono_Dance_Shift_Up:
	face_right
	delay_8
	face_up
	delay_8
	walk_up
	delay_8
	face_down
	delay_16
	step_end

WhirlIslands1_Movement_Kimono_Dance_Shift_Left:
	face_right
	delay_8
	face_up
	delay_8
	face_left
	delay_8
	walk_left
	delay_8
	face_down
	delay_16
	step_end

WhirlIslands1_Movement_Kimono_Dance_Shift_Far_Right:
	face_right
	delay_8
	walk_right
	walk_right
	walk_right
	face_down
	delay_16
	step_end

WhirlIslands1_Movement_Kimono_Dance_Shift_Far_Left:
	face_right
	delay_8
	face_up
	delay_8
	face_left
	delay_8
	walk_left
	walk_left
	walk_left
	face_down
	delay_16
	step_end

WhirlIslands1_Movement_Kimono_Dance_Shift_Left_Up:
	face_right
	delay_8
	face_up
	delay_8
	face_left
	delay_8
	walk_left
	delay_8
	face_up
	delay_8
	walk_up
	delay_8
	face_left
	delay_8
	face_down
	delay_16
	step_end

WhirlIslands1_Movement_Kimono_Dance_Shift_Right_Up:
	face_right
	delay_8
	walk_right
	delay_8
	face_up
	delay_8
	walk_up
	delay_8
	face_right
	delay_8
	face_down
	delay_16
	step_end

WhirlIslands1_Movement_Kimono_Dance_Look_Up:
	face_right
	delay_8
	face_up
	delay_16
	step_end

WhirlIslands1_Movement_Kimono_Dance_Step_Up:
	face_right
	delay_8
	face_up
	delay_8
	walk_up
	delay_8
	face_left
	delay_8
	face_down
	delay_16
	step_end

WhirlIslands1_Movement_Kimono_Dance_Shift_Right2:
	face_right
	delay_8
	walk_right
	delay_8
	face_down
	delay_16
	face_left
	step_end

WhirlIslands1_Text_Kimono_Before::
	.string "KIMONO GIRL: Go, face LUGIA.$"

WhirlIslands1_Text_Kimono_Opening::
	.string "KIMONO GIRL: That's right.\n"
	.string "This is where we welcome LUGIA.\p"
	.string "When the dance we practiced many\n"
	.string "days becomes one with the sound of the\p"
	.string "Tidal Bell we entrusted to you, then\n"
	.string "LUGIA shall come out from deep within\p"
	.string "the waterfall basin once again. $"

WhirlIslands1_Text_Kimono_Closing1::
	.string "That is indeed LUGIA...\n"
	.string "The guardian of these islands from\p"
	.string "ancient times... \p"
	.string "So many have tried again and again,\n"
	.string "only to fail...\p"
	.string "{PLAYER}, your heart in complete\n"
	.string "harmony with the Tidal Bell has finally\p"
	.string "allowed it to appear...\n"
	.string "{PLAYER}, don't you see?\p"
	.string "LUGIA... It must have been waiting for\n"
	.string "someone like you all this time.\p"
	.string "Wouldn't you agree? $"

WhirlIslands1_Text_Kimono_After::
	.string "KIMONO GIRL: You've proven yourself\n"
	.string "today, {PLAYER}.$"
