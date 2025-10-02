.set LOCALID_BELLCHIME_MORTY, 52

BellchimeTrail_MapScripts::
	.byte 0


BellchimeTrail_EventScript_Morty::
	lock
	faceplayer
	msgbox BellchimeTrail_Text_Morty, MSGBOX_DEFAULT
	closemessage
	fadescreenswapbuffers FADE_TO_BLACK
	setflag FLAG_HIDE_BELLCHIME_MORTY
	removeobject LOCALID_BELLCHIME_MORTY
	fadescreenswapbuffers FADE_FROM_BLACK
	clearflag FLAG_HIDE_DOJO_MORTY
	release
	end

BellchimeTrail_Text_Morty:
	.string "MORTIMER : Le POKéMON légendaire\n"
	.string "ne m'a pas choisi...\p"
	.string "Mais cela ne veut pas dire que\n"
	.string "j'ai perdu mon avenir.\p"
	.string "Je poursuivrai mon entraînement\n"
	.string "jusqu'à ce que je découvre un nouvel avenir.\p"
	.string "Si tu veux un autre combat, retrouve-\n"
	.string "moi au DOJO KARATÉ.$"

EcruteakBellchimeTrail_EventScript_Item_BigMushroom::
	finditem ITEM_BIG_MUSHROOM
	end

EcruteakBellchimeTrail_EventScript_DoorTrigger::
	lock
	opendoor 28, 12
	waitdooranim
	addobject OBJ_EVENT_ID_CAMERA
	removeobject OBJ_EVENT_ID_PLAYER
	closedoor 28, 12
	applymovement OBJ_EVENT_ID_CAMERA, EcruteakBellchimeTrail_Movement_CameraPanUp
	waitmovement 0
	warp MAP_TIN_TOWER_1F, 1
	release
	end

EcruteakBellchimeTrail_Movement_CameraPanUp::
	slide_up
	slide_up
	slide_up
	slide_up
	slide_up
	slide_up
	slide_up
	step_end
