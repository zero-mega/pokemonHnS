.set LOCALID_ROUTE22_GIOVANNI, 6
.set LOCALID_ROUTE22_SILVER, 7

Route22_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route22_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route22_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route22_EventScript_Sign::
	msgbox Route22_Text_VictoryRoadEntranceSign, MSGBOX_NPC
	end

Route22_Text_VictoryRoadEntranceSign:
	.string "POKéMON LEAGUE\p"
	.string "VICTORY ROAD ENTRANCE$"

Route22_EventScript_ResetActivation::
	setvar VAR_TEMP_0, 0
	end

Route22_EventScript_DoNothing::
	setvar VAR_TEMP_0, 1
	end

Route22_EventScript_TriggerBottom::
	goto_if_ne VAR_ROUTE22_GIOVANNI_STATE, 0, Route22_EventScript_DoNothing
	specialvar VAR_RESULT, CheckCelebi
	goto_if_eq VAR_RESULT, FALSE, Route22_EventScript_DoNothing
	goto Route22_EventScript_Scene
	
Route22_EventScript_TriggerTop::
	goto_if_ne VAR_ROUTE22_GIOVANNI_STATE, 0, Route22_EventScript_DoNothing
	specialvar VAR_RESULT, CheckCelebi
	goto_if_eq VAR_RESULT, FALSE, Route22_EventScript_DoNothing
	goto Route22_EventScript_Scene

Route22_EventScript_TriggerMid::
	goto_if_ne VAR_ROUTE22_GIOVANNI_STATE, 0, Route22_EventScript_DoNothing
	specialvar VAR_RESULT, CheckCelebi
	goto_if_eq VAR_RESULT, FALSE, Route22_EventScript_DoNothing
	goto Route22_EventScript_Scene

Route22_EventScript_Scene::
	lock
	applymovement2 OBJ_EVENT_ID_FOLLOWER, Route22_Movement_CelebiBegin
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitse
	waitmovement 0
	playse SE_PIN
	applymovement2 OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	delay 60
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	playse SE_PIN
	applymovement2 OBJ_EVENT_ID_PLAYER, Common_Movement_QuestionMark
	delay 60
	applymovement2 OBJ_EVENT_ID_FOLLOWER, Route22_Movement_CelebiSpin1
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitmovement 0
	fadescreenswapbuffers FADE_TO_WHITE
	playse SE_M_TELEPORT
	waitse
	delay 60
	playse SE_M_TELEPORT
	waitse
	clearflag FLAG_HIDE_ROUTE22_GIOVANNI_SILVER
	addobject LOCALID_ROUTE22_GIOVANNI
	addobject LOCALID_ROUTE22_SILVER
	waitse
	playbgm MUS_RG_ROUTE3, TRUE
	fadescreenswapbuffers FADE_FROM_WHITE
	delay 50
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	special SpawnCameraObject
	applymovement2 OBJ_EVENT_ID_CAMERA, Route22_Movement_CameraPanLeft
	waitmovement 0
	delay 30
	applymovement2 LOCALID_ROUTE22_SILVER, Common_Movement_WalkLeft1
	waitmovement 0
	msgbox Route22_Text_Silver1, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement2 LOCALID_ROUTE22_GIOVANNI, Route22_Movement_WalkInPlaceRight
	waitmovement 0
	msgbox Route22_Text_Giovanni1, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement2 LOCALID_ROUTE22_SILVER, Route22_Movement_WalkInPlaceLeft
	waitmovement 0
	msgbox Route22_Text_Silver2, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement2 LOCALID_ROUTE22_GIOVANNI, Route22_Movement_WalkInPlaceRight
	waitmovement 0
	msgbox Route22_Text_Giovanni2, MSGBOX_DEFAULT
	closemessage
	delay 10
	applymovement2 LOCALID_ROUTE22_SILVER, Common_Movement_WalkLeft1
	waitmovement 0
	msgbox Route22_Text_Silver3, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement2 LOCALID_ROUTE22_GIOVANNI, Route22_Movement_WalkInPlaceLeft
	waitmovement 0
	msgbox Route22_Text_Giovanni3, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement2 LOCALID_ROUTE22_GIOVANNI, Route22_Movement_GiovanniLeave
	waitmovement 0
	msgbox Route22_Text_Silver4, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement2 LOCALID_ROUTE22_SILVER, Common_Movement_WalkLeft1
	waitmovement 0
	msgbox Route22_Text_Silver5, MSGBOX_DEFAULT
	closemessage
	delay 20
	playbgm MUS_HG_ENCOUNTER_RIVAL, TRUE
	applymovement2 LOCALID_ROUTE22_SILVER, Route22_Movement_SilverStartLeave
	applymovement2 OBJ_EVENT_ID_CAMERA, Route22_Movement_CameraPanRight
	waitmovement LOCALID_ROUTE22_SILVER
	waitmovement OBJ_EVENT_ID_CAMERA
	special RemoveCameraObject
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	playse SE_PIN
	applymovement2 LOCALID_ROUTE22_SILVER, Common_Movement_ExclamationMark
	delay 60
	msgbox Route22_Text_Silver6, MSGBOX_DEFAULT
	closemessage
	applymovement2 LOCALID_ROUTE22_SILVER, Common_Movement_WalkRight1
	applymovement2 OBJ_EVENT_ID_PLAYER, Route22_Movement_PlayerPushed
	applymovement2 OBJ_EVENT_ID_FOLLOWER, Route22_Movement_CelebiPush
	playse SE_LEDGE
	waitmovement LOCALID_ROUTE22_SILVER
	waitmovement OBJ_EVENT_ID_PLAYER
	waitmovement OBJ_EVENT_ID_FOLLOWER
	waitse
	applymovement2 LOCALID_ROUTE22_SILVER, Route22_Movement_SilverFinishLeave
	waitmovement 0
	setflag FLAG_HIDE_ROUTE22_GIOVANNI_SILVER
	removeobject LOCALID_ROUTE22_SILVER
	removeobject LOCALID_ROUTE22_GIOVANNI

	applymovement2 OBJ_EVENT_ID_FOLLOWER, Route22_Movement_CelebiBegin
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitse
	waitmovement 0
	playse SE_PIN
	applymovement2 OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	delay 60
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	delay 20
	playse SE_PIN
	applymovement2 OBJ_EVENT_ID_PLAYER, Common_Movement_QuestionMark
	delay 60
	applymovement2 OBJ_EVENT_ID_FOLLOWER, Route22_Movement_CelebiSpin1
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitse
	@playse SE_M_PETAL_DANCE
	@delay 10
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitmovement 0
	fadescreenswapbuffers FADE_TO_WHITE
	playse SE_M_TELEPORT
	waitse
	delay 60
	playse SE_M_TELEPORT
	waitse
	fadedefaultbgm
	fadescreenswapbuffers FADE_FROM_WHITE
	setvar VAR_ROUTE22_GIOVANNI_STATE, 2
	setvar VAR_TEMP_0, 2
	release
	end



Route22_Movement_PlayerPushed:
	lock_facing_direction
	jump_up
	unlock_facing_direction
	step_end

Route22_EventScript_PlayerFaceSouth::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	return

Route22_EventScript_PlayerFaceWest::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	return
	
Route22_EventScript_PlayerFaceNorth::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	return
	
Route22_EventScript_PlayerFaceEast::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	return
	
Route22_Movement_CameraPanLeft:
	walk_up
	walk_left
	walk_left
	step_end

Route22_Movement_CameraPanRight:
	walk_down
	walk_right
	walk_right
	step_end

Route22_Movement_WalkInPlaceLeft:
	walk_in_place_left
	step_end

Route22_Movement_WalkInPlaceRight:
	walk_in_place_right
	step_end

Route22_Movement_GiovanniLeave:
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Route22_Movement_SilverStartLeave:
	walk_fast_down
	jump_2_down
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

Route22_Movement_SilverFinishLeave:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

Route22_Movement_CelebiBegin:
	jump_in_place_left
	jump_in_place_left
	step_end

Route22_Movement_CelebiSpin1:
	jump_in_place_left
	jump_in_place_left
	jump_in_place_left
	jump_in_place_left
	step_end

Route22_Movement_CelebiPush:
	walk_up
	face_down
	walk_in_place_down
	step_end

Route22_Text_Silver1:
	.string "SILVER : Tu m'as dit...\n"
	.string "que tu étais le numéro un dans le\l"
	.string "monde entier !\p"
	.string "Tu vas abandonner ?\p"
	.string "Qu'est-ce que tu vas faire maintenant ?$"

Route22_Text_Giovanni1:
	.string "....................\p"
	.string "GIOVANNI : Il faut reconnaître sa\n"
	.string "défaite avant de pouvoir avancer...\p"
	.string "Je vais partir seul... pour l'instant...\p"
	.string "Pour qu'un jour je puisse former une\n"
	.string "organisation encore plus forte !$"

Route22_Text_Silver2:
	.string "SILVER : En quoi étais-tu\n"
	.string "le numéro un ?\p"
	.string "Rassembler autant de monde pour être\n"
	.string "battu par un simple enfant !$"

Route22_Text_Giovanni2:
	.string "GIOVANNI : Réunir le potentiel de\n"
	.string "plusieurs, c'est ainsi qu'on\l"
	.string "crée une grande puissance...\l"
	.string "C'est ça, une organisation...\l"
	.string "C'est la force d'une organisation\p"
	.string "J'ai échoué... à tirer le meilleur de\n"
	.string "mes subordonnés... !\p"
	.string "Mais tu verras un jour le retour de\n"
	.string "moi et de ma TEAM ROCKET !$"

Route22_Text_Silver3:
	.string "SILVER : Je ne te comprends pas !\p"
	.string "Tu ne veux rien dire pour moi !$"

Route22_Text_Giovanni3:
	.string ".......................\p"
	.string "GIOVANNI : Un jour, tu\n"
	.string "comprendras.$"

Route22_Text_Silver4:
	.string "SILVER : Je ne veux pas\n"
	.string "te comprendre !\p"
	.string "Je ne deviendrai jamais quelqu'un\n"
	.string "comme toi.\p"
	.string "Un lâche quand tu es seul et\n"
	.string "un tyran devant d'autres lâches !\p"
	.string "Je deviendrai fort !\p"
	.string "Je deviendrai un homme plus fort\n"
	.string "par moi-même !$"

Route22_Text_Silver5:
	.string "PAR MOI-MÊME !$"

Route22_Text_Silver6:
	.string "SILVER : ... Qu'est-ce que tu regardes ?$"
