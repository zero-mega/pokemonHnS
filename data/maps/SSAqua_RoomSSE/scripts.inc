.set LOCALID_SSAQUA_ROOM_SSE_GRANDDAUGTHER, 2
.set LOCALID_SSAQUA_ROOM_SSE_GRANDFATHER, 1

SSAqua_RoomSSE_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SSAqua_RoomSSE_OnFrame
    map_script MAP_SCRIPT_ON_TRANSITION, SSAqua_RoomSSE_OnTransition
	.byte 0

SSAqua_RoomSSE_OnTransition::
    goto_if_ge VAR_SSAQUA_STATE, 5, SSAqua_RoomSSE_SetGirlPos
    end

SSAqua_RoomSSE_OnFrame::
	map_script_2 VAR_SSAQUA_STATE, 4, SSAqua_RoomSSE_EventScript_ReuinionScene
	.2byte 0

SSAqua_RoomSSE_SetGirlPos::
    setobjectxyperm LOCALID_SSAQUA_ROOM_SSE_GRANDDAUGTHER, 2, 4
    setobjectmovementtype LOCALID_SSAQUA_ROOM_SSE_GRANDDAUGTHER, MOVEMENT_TYPE_FACE_LEFT
    end

SSAqua_RoomSSE_EventScript_ReuinionScene::
	lock
    turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
    turnobject LOCALID_SSAQUA_ROOM_SSE_GRANDFATHER, DIR_SOUTH
    playse SE_PIN
    applymovement LOCALID_SSAQUA_ROOM_SSE_GRANDFATHER, Common_Movement_ExclamationMark
    delay 60
	applymovement LOCALID_SSAQUA_ROOM_SSE_GRANDDAUGTHER, SSAqua_RoomSSE_Movement_GirlEnter
    waitmovement 0
    turnobject LOCALID_SSAQUA_ROOM_SSE_GRANDFATHER, DIR_EAST
    msgbox SSAqua_RoomSSE_Text_GranddaughterWasPlaying, MSGBOX_DEFAULT
    closemessage
    applymovement OBJ_EVENT_ID_PLAYER, SSAqua_RoomSSE_Movement_PlayerEnter
    waitmovement 0
    turnobject LOCALID_SSAQUA_ROOM_SSE_GRANDFATHER, DIR_SOUTH
    msgbox SSAqua_RoomSSE_Text_EntertainedGranddaughter, MSGBOX_DEFAULT
    msgbox SSAqua_RoomSSE_Text_GrandpaHaveThis, MSGBOX_DEFAULT
    giveitem ITEM_METAL_COAT
    closemessage
	setvar VAR_SSAQUA_STATE, 5
	release
	end

SSAqua_RoomSSE_EventScript_Grandpa::
	lock
	faceplayer
	goto_if_ge VAR_SSAQUA_STATE, 4, SSAqua_RoomSSE_EventScript_GrandpaAfter
	msgbox SSAqua_RoomSSE_Text_CantFindGranddaughter, MSGBOX_DEFAULT
	closemessage
	release
	end

SSAqua_RoomSSE_EventScript_GrandpaAfter::
	msgbox SSAqua_RoomSSE_Text_GrandpaTravelling, MSGBOX_DEFAULT
	closemessage
	release
	end

SSAqua_RoomSSE_EventScript_GrandDaughter::
	msgbox SSAqua_RoomSSE_Text_GranddaughterHadFun, MSGBOX_NPC
	end

SSAqua_RoomSSE_Movement_GirlEnter:
    walk_up
    walk_up
    walk_left
    step_end

SSAqua_RoomSSE_Movement_PlayerEnter:
    walk_up
    walk_left
    walk_left
    walk_up
    step_end

SSAqua_RoomSSE_Text_CantFindGranddaughter:
    .string "Oh, bonjour…\p"
    .string "Je n'arrive toujours pas à\n"
    .string "trouver ma petite-fille.\p"
    .string "Si elle est sur le bateau,\n"
    .string "ça va.\p"
    .string "C'est une enfant pleine d'énergie,\n"
    .string "elle doit sûrement déranger quelqu'un\l"
    .string "Je m'inquiète…$"

SSAqua_RoomSSE_Text_EntertainedGranddaughter:
    .string "{PLAYER}, c'est bien ça ?\n"
    .string "J'ai entendu dire que tu as\l"
    .string "tenu compagnie à ma petite-fille.\p"
    .string "Je tiens à te remercier.$"

SSAqua_RoomSSE_Text_GrandpaHaveThis:
    .string "Tiens ! J'aimerais que tu\n"
    .string "acceptes ceci !$"

SSAqua_RoomSSE_Text_GrandpaTravelling:
    .string "Nous voyageons à travers\n"
    .string "le monde.$"

SSAqua_RoomSSE_Text_GranddaughterWasPlaying:
    .string "Grand-père, me voilà !\n"
    .string "Je jouais avec le CAPITAINE\l"
    .string "et cette personne !$"

SSAqua_RoomSSE_Text_GranddaughterHadFun:
    .string "Je me suis bien amusée en jouant !$"
