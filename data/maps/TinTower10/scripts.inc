.set LOCALID_HO_OH, 8
.set LOCALID_KIMONO_MID, 4
.set LOCALID_KIMONO_1, 3
.set LOCALID_KIMONO_2, 6
.set LOCALID_KIMONO_3, 7
.set LOCALID_KIMONO_4, 5

TinTower10_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, TinTower10_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, TinTower10_OnResume
	.byte 0

TinTower10_OnTransition:
	call_if_set FLAG_CAUGHT_HO_OH, TinTower10_EventScript_HideHoOh
	call_if_unset FLAG_CAUGHT_HO_OH, TinTower10_EventScript_TryShowHoOh
	end

TinTower10_EventScript_HideHoOh::
	setvar VAR_TEMP_1, 1
	setflag FLAG_HIDE_HO_OH
	return

TinTower10_EventScript_TryShowHoOh::
	setvar VAR_TEMP_1, 1
	goto_if_set FLAG_DEFEATED_HO_OH, Common_EventScript_NopReturn
	setvar VAR_TEMP_1, 0
	clearflag FLAG_HIDE_HO_OH
	goto_if_eq VAR_LUGIA_OR_HOOH, 0, Common_EventScript_NopReturn
	setobjectxyperm LOCALID_HO_OH, 10, 6
	return

TinTower10_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, TinTower10_EventScript_TryRemoveHoOh
	end

TinTower10_EventScript_TryRemoveHoOh::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject LOCALID_HO_OH
	return

TinTower10_EventScript_HoOh::
	lockall
	setvar VAR_TEMP_1, 1
	special SpawnCameraObject
	setvar VAR_0x8004, 3  @ num loops
	setvar VAR_0x8005, 35 @ delay
	special LoopWingFlapSE
	applymovement LOCALID_HO_OH, TinTower10_Movement_HoOhAppear
	applymovement OBJ_EVENT_ID_CAMERA, TinTower10_Movement_CameraPanUp
	waitmovement 0
	delay 50
	setweather WEATHER_NONE
	doweather
	waitse
	playmoncry SPECIES_HO_OH, CRY_MODE_ENCOUNTER
	delay 30
	waitmoncry
	delay 60
	setvar VAR_0x8004, 3  @ num loops
	setvar VAR_0x8005, 35 @ delay
	special LoopWingFlapSE
	applymovement OBJ_EVENT_ID_CAMERA, TinTower10_Movement_CameraPanDown
	applymovement LOCALID_HO_OH, TinTower10_Movement_HoOhApproach
	waitmovement 0
	special RemoveCameraObject
	seteventmon SPECIES_HO_OH, 70
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	setvar VAR_LAST_TALKED, LOCALID_HO_OH
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, TinTower10_EventScript_DefeatedHoOh
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, TinTower10_EventScript_RanFromHoOh
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, TinTower10_EventScript_RanFromHoOh
	setflag FLAG_CAUGHT_HO_OH
	setvar VAR_COMPLETED_HO_OH, 1
	applymovement LOCALID_KIMONO_MID, TinTower10_Movement_Kimono_Dance_Shift_Right
	releaseall
	end

TinTower10_eventScript_TalkToKimono::
	lockall
	playbgm MUS_HG_KIMONO_GIRL_DANCE, TRUE
	msgbox TinTower10_Text_Kimono_Opening, MSGBOX_DEFAULT
	closemessage

	applymovement LOCALID_KIMONO_MID, TinTower10_Movement_Kimono_Step_Aside
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, TinTower10_Walk_To_Center
	waitmovement 0
	applymovement LOCALID_KIMONO_MID, TinTower10_Movement_Kimono_Step_In
	applymovement LOCALID_KIMONO_1, TinTower10_Movement_Kimono_Step_Start_Left
	applymovement LOCALID_KIMONO_4, TinTower10_Movement_Kimono_Step_Start_Right
	waitmovement 5
	playse SE_M_PETAL_DANCE
	applymovement LOCALID_KIMONO_MID, TinTower10_Movement_Kimono_Dance_Mid
	waitmovement 0
	playse SE_M_PETAL_DANCE
	applymovement LOCALID_KIMONO_1, TinTower10_Movement_Kimono_Dance_Mid
	applymovement LOCALID_KIMONO_2, TinTower10_Movement_Kimono_Dance_Mid
	applymovement LOCALID_KIMONO_3, TinTower10_Movement_Kimono_Dance_Mid
	applymovement LOCALID_KIMONO_4, TinTower10_Movement_Kimono_Dance_Mid
	applymovement LOCALID_KIMONO_MID, TinTower10_Movement_Kimono_Dance_Mid	
	waitmovement 0
	playse SE_M_PETAL_DANCE
	setweather WEATHER_DROUGHT
	doweather
	@ 1
	applymovement LOCALID_KIMONO_1, TinTower10_Movement_Kimono_Dance_Shift_Down
	applymovement LOCALID_KIMONO_2, TinTower10_Movement_Kimono_Dance_Shift_Right
	applymovement LOCALID_KIMONO_3, TinTower10_Movement_Kimono_Dance_Shift_Up
	applymovement LOCALID_KIMONO_4, TinTower10_Movement_Kimono_Dance_Shift_Left
	waitmovement LOCALID_KIMONO_4
	delay 30
	applymovement LOCALID_KIMONO_1, TinTower10_Movement_Kimono_Dance_Mid
	applymovement LOCALID_KIMONO_2, TinTower10_Movement_Kimono_Dance_Mid
	applymovement LOCALID_KIMONO_3, TinTower10_Movement_Kimono_Dance_Mid
	applymovement LOCALID_KIMONO_4, TinTower10_Movement_Kimono_Dance_Mid
	applymovement LOCALID_KIMONO_MID, TinTower10_Movement_Kimono_Dance_Mid
	waitmovement 0
	playse SE_M_PETAL_DANCE
	@ 2
	applymovement LOCALID_KIMONO_1, TinTower10_Movement_Kimono_Dance_Shift_Down
	applymovement LOCALID_KIMONO_2, TinTower10_Movement_Kimono_Dance_Shift_Far_Right
	applymovement LOCALID_KIMONO_3, TinTower10_Movement_Kimono_Dance_Shift_Up
	applymovement LOCALID_KIMONO_4, TinTower10_Movement_Kimono_Dance_Shift_Far_Left
	waitmovement LOCALID_KIMONO_4
	delay 30
	applymovement LOCALID_KIMONO_1, TinTower10_Movement_Kimono_Dance_Mid
	applymovement LOCALID_KIMONO_2, TinTower10_Movement_Kimono_Dance_Mid
	applymovement LOCALID_KIMONO_3, TinTower10_Movement_Kimono_Dance_Mid
	applymovement LOCALID_KIMONO_4, TinTower10_Movement_Kimono_Dance_Mid
	applymovement LOCALID_KIMONO_MID, TinTower10_Movement_Kimono_Dance_Mid
	waitmovement 0
	playse SE_M_PETAL_DANCE
	@ 3
	applymovement LOCALID_KIMONO_1, TinTower10_Movement_Kimono_Dance_Shift_Right
	applymovement LOCALID_KIMONO_2, TinTower10_Movement_Kimono_Dance_Shift_Up
	applymovement LOCALID_KIMONO_3, TinTower10_Movement_Kimono_Dance_Shift_Left
	applymovement LOCALID_KIMONO_4, TinTower10_Movement_Kimono_Dance_Shift_Down
	waitmovement LOCALID_KIMONO_3
	delay 30
	applymovement LOCALID_KIMONO_1, TinTower10_Movement_Kimono_Dance_Mid
	applymovement LOCALID_KIMONO_2, TinTower10_Movement_Kimono_Dance_Mid
	applymovement LOCALID_KIMONO_3, TinTower10_Movement_Kimono_Dance_Mid
	applymovement LOCALID_KIMONO_4, TinTower10_Movement_Kimono_Dance_Mid
	applymovement LOCALID_KIMONO_MID, TinTower10_Movement_Kimono_Dance_Mid
	waitmovement 0
	playse SE_M_PETAL_DANCE
	@ 4
	applymovement LOCALID_KIMONO_1, TinTower10_Movement_Kimono_Dance_Shift_Far_Right
	applymovement LOCALID_KIMONO_2, TinTower10_Movement_Kimono_Dance_Shift_Up
	applymovement LOCALID_KIMONO_3, TinTower10_Movement_Kimono_Dance_Shift_Far_Left
	applymovement LOCALID_KIMONO_4, TinTower10_Movement_Kimono_Dance_Shift_Down
	waitmovement LOCALID_KIMONO_3
	delay 30
	applymovement LOCALID_KIMONO_1, TinTower10_Movement_Kimono_Dance_Mid
	applymovement LOCALID_KIMONO_2, TinTower10_Movement_Kimono_Dance_Mid
	applymovement LOCALID_KIMONO_3, TinTower10_Movement_Kimono_Dance_Mid
	applymovement LOCALID_KIMONO_4, TinTower10_Movement_Kimono_Dance_Mid
	applymovement LOCALID_KIMONO_MID, TinTower10_Movement_Kimono_Dance_Mid
	waitmovement 0
	playse SE_M_PETAL_DANCE
	@ 5
	applymovement LOCALID_KIMONO_1, TinTower10_Movement_Kimono_Dance_Shift_Left_Up
	applymovement LOCALID_KIMONO_4, TinTower10_Movement_Kimono_Dance_Shift_Right_Up
	applymovement LOCALID_KIMONO_MID, TinTower10_Movement_Kimono_Dance_Step_Up
	waitmovement LOCALID_KIMONO_1
	delay 30
	applymovement LOCALID_KIMONO_1, TinTower10_Movement_Kimono_Dance_Mid
	applymovement LOCALID_KIMONO_2, TinTower10_Movement_Kimono_Dance_Mid
	applymovement LOCALID_KIMONO_3, TinTower10_Movement_Kimono_Dance_Mid
	applymovement LOCALID_KIMONO_4, TinTower10_Movement_Kimono_Dance_Mid
	applymovement LOCALID_KIMONO_MID, TinTower10_Movement_Kimono_Dance_Mid
	waitmovement 0
	playse SE_M_PETAL_DANCE
	waitse


	setvar VAR_TEMP_1, 1
	special SpawnCameraObject
	setvar VAR_0x8004, 3  @ num loops
	setvar VAR_0x8005, 35 @ delay
	special LoopWingFlapSE
	applymovement LOCALID_HO_OH, TinTower10_Movement_HoOhAppear
	applymovement OBJ_EVENT_ID_CAMERA, TinTower10_Movement_CameraPanUp
	waitmovement 0
	delay 50
	@ setweather WEATHER_NONE
	@ doweather
	waitse
	playmoncry SPECIES_HO_OH, CRY_MODE_ENCOUNTER
	delay 30
	waitmoncry
	delay 60
	setvar VAR_0x8004, 3  @ num loops
	setvar VAR_0x8005, 35 @ delay
	special LoopWingFlapSE
	applymovement LOCALID_HO_OH, TinTower10_Movement_HoOhApproach
	waitmovement 0
	applymovement OBJ_EVENT_ID_CAMERA, TinTower10_Movement_CameraPanDown
	waitmovement 0
	special RemoveCameraObject



	applymovement LOCALID_KIMONO_MID, TinTower10_Movement_Kimono_Dance_Look_Up
	applymovement LOCALID_KIMONO_1, TinTower10_Movement_Kimono_Dance_Look_Up
	applymovement LOCALID_KIMONO_2, TinTower10_Movement_Kimono_Dance_Look_Up
	applymovement LOCALID_KIMONO_3, TinTower10_Movement_Kimono_Dance_Look_Up
	applymovement LOCALID_KIMONO_4, TinTower10_Movement_Kimono_Dance_Look_Up
	waitmovement 0
	msgbox TinTower10_Text_Kimono_Closing1, MSGBOX_DEFAULT
	waitmessage
	closemessage


	releaseall
	end

TinTower10_EventScript_TalkToHoOh::
	lockall
	setweather WEATHER_NONE
	doweather
	waitse
	playmoncry SPECIES_HO_OH, CRY_MODE_ENCOUNTER
	delay 30
	waitmoncry
	playbgm MUS_HG_VS_HO_OH, 0
	seteventmon SPECIES_HO_OH, 70
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE

	setvar VAR_LAST_TALKED, LOCALID_HO_OH
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, TinTower10_EventScript_DefeatedHoOh
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, TinTower10_EventScript_RanFromHoOh
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, TinTower10_EventScript_RanFromHoOh
	setflag FLAG_HIDE_TIN_TOWER_KIMONO_GIRLS
	applymovement LOCALID_KIMONO_MID, TinTower10_Movement_Kimono_Dance_Shift_Right2
	waitmovement 0
	setflag FLAG_CAUGHT_HO_OH
	setvar VAR_COMPLETED_HO_OH, 1
	setvar VAR_ECRUTEAK_CITY_STATE, 12
	releaseall
	end

TinTower10_EventScript_DefeatedHoOh::
	setflag FLAG_DEFEATED_HO_OH
	setvar VAR_0x8004, SPECIES_HO_OH
	setvar VAR_COMPLETED_HO_OH, 1
	setvar VAR_ECRUTEAK_CITY_STATE, 12
	setflag FLAG_HIDE_TIN_TOWER_KIMONO_GIRLS
	applymovement LOCALID_KIMONO_MID, TinTower10_Movement_Kimono_Dance_Shift_Right2
	waitmovement 0
	goto Common_EventScript_LegendaryFlewAway
	end

TinTower10_EventScript_RanFromHoOh::
	@setflag FLAG_DEFEATED_HO_OH
	@setvar VAR_0x8004, SPECIES_HO_OH
	@setvar VAR_COMPLETED_HO_OH, 1
	@goto Common_EventScript_LegendaryFlewAway
	releaseall
	end

TinTower10_EventScript_Kimono::
	lock
	faceplayer
	goto_if_set FLAG_CAUGHT_HO_OH, TinTower10_EventScript_Kimono_AfterCaught
	goto_if_eq VAR_COMPLETED_HO_OH, 1, TinTower10_EventScript_Kimono_After
	msgbox TinTower10_Text_Kimono_Before, MSGBOX_DEFAULT 
	closemessage
	release
	end


TinTower10_EventScript_Kimono_After::
	msgbox TinTower10_Text_Kimono_After, MSGBOX_DEFAULT
	closemessage
	release
	end

TinTower10_EventScript_Kimono_AfterCaught::
	msgbox TinTower10_Text_Kimono_AfterCaught, MSGBOX_DEFAULT
	closemessage
	release
	end

TinTower10_Text_Kimono_AfterCaught:
	.string "You have not only made HO-OH\n"
	.string "appear, but you have also caught\l"
	.string "it...\p"
	.string "There is nothing more for us to\n"
	.string "say. Take care of yourself in your\l"
	.string "journey...$"

TinTower10_Movement_CameraPanUp:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

TinTower10_Movement_CameraPanDown:
	delay_16
	delay_16
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

TinTower10_Movement_HoOhApproach:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_in_place_down
	delay_16
	delay_16
	step_end

TinTower10_Movement_HoOhAppear:
	delay_16
	delay_16
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	step_end


TinTower10_Movement_Kimono_Step_Aside:
	face_right
	delay_16
	walk_right
	delay_16
	face_left
	step_end

TinTower10_Walk_To_Center:
	walk_up
	walk_up
	walk_up
	delay_16
	face_down
	step_end

TinTower10_Movement_Kimono_Step_In:
	walk_left
	delay_16
	face_down
	step_end


TinTower10_Movement_Kimono_Step_Start_Left:
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

TinTower10_Movement_Kimono_Step_Start_Right:
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

TinTower10_Movement_Kimono_Dance_Mid:
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

TinTower10_Movement_Kimono_Dance_Shift_Down:
	face_down
	delay_8
	walk_down
	delay_8
	face_down
	delay_16
	step_end

TinTower10_Movement_Kimono_Dance_Shift_Right:
	face_right
	delay_8
	walk_right
	delay_8
	face_down
	delay_16
	step_end

TinTower10_Movement_Kimono_Dance_Shift_Up:
	face_right
	delay_8
	face_up
	delay_8
	walk_up
	delay_8
	face_down
	delay_16
	step_end

TinTower10_Movement_Kimono_Dance_Shift_Left:
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

TinTower10_Movement_Kimono_Dance_Shift_Far_Right:
	face_right
	delay_8
	walk_right
	walk_right
	walk_right
	face_down
	delay_16
	step_end

TinTower10_Movement_Kimono_Dance_Shift_Far_Left:
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

TinTower10_Movement_Kimono_Dance_Shift_Left_Up:
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

TinTower10_Movement_Kimono_Dance_Shift_Right_Up:
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

TinTower10_Movement_Kimono_Dance_Look_Up:
	face_right
	delay_8
	face_up
	delay_16
	step_end

TinTower10_Movement_Kimono_Dance_Step_Up:
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

TinTower10_Movement_Kimono_Dance_Shift_Right2:
	face_right
	delay_8
	walk_right
	delay_8
	face_down
	delay_16
	face_left
	step_end

TinTower10_Text_Kimono_Before::
	.string "KIMONO GIRL: Go, face HO-OH. $"

TinTower10_Text_Kimono_Opening::
	.string "KIMONO GIRL: That's right.\n"
	.string "This is where we welcome HO-OH.\p"
	.string "When the dance we practiced many\n"
	.string "days becomes one with the sound of the\p"
	.string "Clear Bell we entrusted to you, then\n"
	.string "HO-OH shall come down from the great\p"
	.string "arch of the sky once again. $"

TinTower10_Text_Kimono_Closing1::
	.string "That is indeed HO-OH...\n"
	.string "The guardian of the sky from\p"
	.string "ancient times... \p"
	.string "So many have tried again and again,\n"
	.string "only to fail...\p"
	.string "{PLAYER}, your heart in complete\n"
	.string "harmony with the Clear Bell has finally\p"
	.string "allowed it to appear...\n"
	.string "{PLAYER}, don't you see?\p"
	.string "HO-OH... It must have been waiting for\n"
	.string "someone like you all this time.\p"
	.string "Wouldn't you agree? $"

TinTower10_Text_Kimono_After::
	.string "You have done a great job.\n"
	.string "Say hello to PROF. ELM for us.$"
