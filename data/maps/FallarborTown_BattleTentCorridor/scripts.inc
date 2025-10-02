.set LOCALID_ATTENDANT, 1

FallarborTown_BattleTentCorridor_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, FallarborTown_BattleTentCorridor_OnFrame
	.byte 0

FallarborTown_BattleTentCorridor_OnFrame:
	map_script_2 VAR_TEMP_0, 0, FallarborTown_BattleTentCorridor_EventScript_EnterCorridor
	.2byte 0

FallarborTown_BattleTentCorridor_EventScript_EnterCorridor::
	lockall
	setvar VAR_TEMP_0, 1
	applymovement LOCALID_ATTENDANT, FallarborTown_BattleTentCorridor_Movement_WalkToDoor
	applymovement OBJ_EVENT_ID_PLAYER, FallarborTown_BattleTentCorridor_Movement_WalkToDoor
	waitmovement 0
	opendoor 2, 1
	waitdooranim
	applymovement LOCALID_ATTENDANT, FallarborTown_BattleTentCorridor_Movement_AttendantEnterDoor
	applymovement OBJ_EVENT_ID_PLAYER, FallarborTown_BattleTentCorridor_Movement_PlayerEnterDoor
	waitmovement 0
	closedoor 2, 1
	waitdooranim
	setvar VAR_0x8006, 0
	warp MAP_FALLARBOR_TOWN_BATTLE_TENT_BATTLE_ROOM, 4, 4
	waitstate
	releaseall
	end

FallarborTown_BattleTentCorridor_Movement_WalkToDoor:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

FallarborTown_BattleTentCorridor_Movement_PlayerEnterDoor:
	walk_up
FallarborTown_BattleTentCorridor_Movement_AttendantEnterDoor:
	walk_up
	set_invisible
	step_end

@ Leftover text from when this was a Contest Hall in R/S
@ Unused
FallarborTown_ContestHall_Text_DoAllRightInPreliminary:
	.string "On s'en sort bien lors du tour préliminaire,\n"
	.string "mais on ne gagne jamais les évaluations…\p"
	.string "Peut-être que je devrais observer ce que\n"
	.string "font les autres concurrents…$"

@ Unused
FallarborTown_ContestHall_Text_MonAllTheseRibbons:
	.string "Regarde !\n"
	.string "Mon POKéMON a gagné tous ces RUBANS !\p"
	.string "Tes POKéMON ont-ils gagné des RUBANS ?\n"
	.string "Tu peux les vérifier sur ton POKéNAV.$"

@ Unused
FallarborTown_ContestHall_Text_CantWinEverywhere:
	.string "Je n'arrive pas à battre les CHAMPIONS D'ARÈNE…\p"
	.string "Je ne gagne aucun CONCOURS…\p"
	.string "Je suis allé partout, mais tout ça\n"
	.string "n'a servi à rien…$"

@ Unused
FallarborTown_ContestHall_Text_SuperRankStage:
	.string "CONCOURS POKéMON\n"
	.string "SCÈNE SUPER RANG !$"

