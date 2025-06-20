.set LOCALID_ECRUTEAK_ROCKET, 12
.set LOCALID_ECRUTEAK_ZUKI, 5
.set LOCALID_SURF_GUY, 7

EcruteakTheater_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EcruteakTheater_OnTransition
	.byte 0

EcruteakTheater_OnTransition::
	call_if_eq VAR_ECRUTEAK_THEATER, 1, EcruteakTheater_MapScript_SetRocketSceneActive
	end

EcruteakTheater_MapScript_SetRocketSceneActive::
	setobjectxyperm LOCALID_ECRUTEAK_ZUKI, 10, 2
	setobjectmovementtype LOCALID_ECRUTEAK_ROCKET, MOVEMENT_TYPE_TOWER_BEAM
	return

EcruteakTheater_EventScript_RocketEventTrigger::
	lockall
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	delay 60
	turnobject LOCALID_ECRUTEAK_ROCKET, DIR_NORTH
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, EcruteakTheater_Movement_CameraPanUp
	waitmovement 0
	msgbox EcruteakTheater_Text_Rocket1, MSGBOX_DEFAULT
	closemessage
	msgbox EcruteakTheater_Text_KimonoRocket1, MSGBOX_DEFAULT
	closemessage
	msgbox EcruteakTheater_Text_Rocket2, MSGBOX_DEFAULT
	applymovement LOCALID_ECRUTEAK_ZUKI, EcruteakTheater_Movement_KimonoGirlMoveBack
	waitmovement 0
	msgbox EcruteakTheater_Text_Rocket3, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ECRUTEAK_ROCKET, EcruteakTheater_Movement_RocketDance
	delay 50
	applymovement OBJ_EVENT_ID_CAMERA, EcruteakTheater_Movement_CameraPanDown
	waitmovement 0
	special RemoveCameraObject
	setobjectmovementtype LOCALID_ECRUTEAK_ROCKET, MOVEMENT_TYPE_TOWER_BEAM
	setobjectxyperm LOCALID_ECRUTEAK_ZUKI, 10, 2
	setvar VAR_ECRUTEAK_THEATER, 1
	releaseall
	end

EcruteakTheater_Movement_RocketDance:
	walk_in_place_down
	delay_2
	walk_in_place_right
	delay_2
	face_up
	delay_2
	face_left
	delay_8
	walk_in_place_down
	delay_2
	walk_in_place_left
	delay_2
	face_up
	delay_8
	face_right
	step_end

EcruteakTheater_Movement_CameraPanUp:
	slide_up
	slide_up
	slide_up
	slide_up
	slide_up
	slide_up
	slide_up
	slide_up
	slide_up
	slide_up
	slide_up
	slide_up
	step_end

EcruteakTheater_Movement_CameraPanDown:
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	step_end

EcruteakTheater_Movement_KimonoGirlMoveBack:
	lock_facing_direction
	walk_up
	unlock_facing_direction
	step_end

EcruteakTheater_Text_Rocket1:
	.string "ROCKET: Stop dancing such a serious\n"
	.string "dance! Show me something like\l"
	.string "a hula dance!$"

EcruteakTheater_Text_KimonoRocket1:
	.string "KIMONO GIRL:...You mustn't push\n"
	.string "such a request on me.$"

EcruteakTheater_Text_Rocket2:
	.string "ROCKET: Huh?\p"
	.string "Are you telling me you don't\n"
	.string "respect what the customer\l"
	.string "wants?$"

EcruteakTheater_Text_Rocket3:
	.string "Well, then I'll show you how\n"
	.string "to dance. I'll show you a\l"
	.string "great one.\p"
	.string "Wahahaha!$"

EcruteakTheater_EventScript_Rocket::
	lock
	faceplayer
	msgbox EcruteakTheater_Text_RocketSeen, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_15, EcruteakTheater_Text_RocketBeaten
	msgbox EcruteakTheater_Text_RocketAfter, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ECRUTEAK_ROCKET, EcruteakTheater_Movement_RocketLeave
	waitmovement 0
	setflag FLAG_HIDE_ECRUTEAK_ROCKET
	removeobject LOCALID_ECRUTEAK_ROCKET
	call_if_eq VAR_FACING, DIR_EAST, EcruteakTheater_EventScript_PostRocketLeft
	call_if_eq VAR_FACING, DIR_WEST, EcruteakTheater_EventScript_PostRocketRight
	call_if_eq VAR_FACING, DIR_SOUTH, EcruteakTheater_EventScript_PostRocketTop
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	msgbox EcruteakTheater_Text_KimonoRocket3, MSGBOX_DEFAULT
	closemessage	
	setvar VAR_ECRUTEAK_THEATER, 2
	release
	end
	
EcruteakTheater_EventScript_PostRocketLeft::
	applymovement LOCALID_ECRUTEAK_ZUKI, Common_Movement_WalkLeft1
	waitmovement 0
	applymovement LOCALID_ECRUTEAK_ZUKI, Common_Movement_WalkDown1
	waitmovement 0
	return

EcruteakTheater_EventScript_PostRocketRight::
	applymovement LOCALID_ECRUTEAK_ZUKI, Common_Movement_WalkRight1
	waitmovement 0
	applymovement LOCALID_ECRUTEAK_ZUKI, Common_Movement_WalkDown1
	waitmovement 0
	return

EcruteakTheater_EventScript_PostRocketTop::
	turnobject LOCALID_ECRUTEAK_ZUKI, DIR_SOUTH
	return

EcruteakTheater_Movement_RocketLeave:
	jump_2_down
	walk_fast_left
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

EcruteakTheater_Text_RocketSeen:
	.string "Huh? Who are you?\n"
	.string "You dare to get in my way?$"

EcruteakTheater_Text_RocketBeaten:
	.string "Oh, no!\n"
	.string "You make me look like a\l"
	.string "villain!$"

EcruteakTheater_Text_RocketAfter:
	.string "Oops! I have an important mission\n"
	.string "If they find out I was wasting\l"
	.string "time here, they'll make me start\l"
	.string "over as the lowest ROCKET GRUNT!\p"
	.string "I better leave now!$"

EcruteakTheater_Text_KimonoRocket3:
	.string "You must be {PLAYER},\n"
	.string "correct? That was indeed\l"
	.string "excellent.\p"
	.string "Kind and strong... Good at\n"
	.string "raising POKéMON as well...\p"
	.string "That person does know what\n"
	.string "to look for in people...\p"
	.string "Ohoho! That was just me\n"
	.string "talking to myself.\l"
	.string "Never mind.$"

EcruteakTheater_EventScript_Zuki::
	lock
	faceplayer
	goto_if_eq VAR_ECRUTEAK_THEATER, 1, EcruteakTheater_EventScript_ZukiDuringRocket
	msgbox EcruteakTheater_Text_Kimono, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakTheater_EventScript_ZukiDuringRocket::
	msgbox EcruteakTheater_Text_KimonoGirlBeaten, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakTheater_Text_Kimono:
	.string "For Kimono Girls like me,\n"
	.string "dancing is everything.\p"
	.string "I have never gone a day\n"
	.string "without a dance practice.\p"
	.string "POKéMON are the same.\n"
	.string "They grow with you little\l"
	.string "by little each day.$"

EcruteakTheater_Text_KimonoGirlBeaten:
	.string "...$"

EcruteakTheater_Text_ZukiSeen:
	.string "Welcome. My name is ZUKI.\n"
	.string "I met you previously in\l"
	.string "VIOLET CITY.\p"
	.string "To bring back HO-OH, we\n"
	.string "needed someone with the\l"
	.string "right bond with POKéMON.\p"
	.string "We asked Mr. POKéMON to\n"
	.string "give this Mystery Egg to\l"
	.string "whoever showed potential.\p"
	.string "The Egg went from MR.\n"
	.string "POKéMON to PROF. ELM, then\l"
	.string "to you.\p"
	.string "But being pure alone is not\n"
	.string "enough to face the power\l"
	.string "of this POKéMON.\p"
	.string "I must test you.\n"
	.string "Are you ready? {PLAYER}$"

EcruteakTheater_Text_ZukiSeenAgain:
	.string "I will test you to see if\n"
	.string "you are a good Trainer.\l"
	.string "Are you ready? {PLAYER}$"

EcruteakTheater_Text_ZukiNo:
	.string "That is fine...\n"
	.string "I will wait for you to get\l"
	.string "ready.$"

EcruteakTheater_Text_NaokoSeen:
	.string "You are quite strong. You\n"
	.string "helped me in the ILEX FOREST.\p"
	.string "I'm NAOKO--not so good with\n"
	.string "directions.\p"
	.string "I saw you defeat Team Rocket\n"
	.string "when Kurt was in trouble at\l"
	.string "the SLOWPOKE Well.\p"
	.string "Let me challenge you and your\n"
	.string "POKéMON!$"

EcruteakTheater_Text_MikiSeen:
	.string "You're quite the Trainer. I\n"
	.string "remember you chased off that\l"
	.string "Rocket Grunt from right here.\p"
	.string "Thank you for that.\p"
	.string "Though, I'm a Trainer too.\n"
	.string "She who knows the most speaks\l"
	.string "the least!\p"
	.string "I am MIKI--the Kimono Girl!\p"
	.string "Let me challenge you and your\n"
	.string "POKéMON!$"

EcruteakTheater_Text_SayoSeen:
	.string "Excellent spirit! You got me\n"
	.string "off the ice by pushing me.\p"
	.string "I skate in sandals.\n"
	.string "I am SAYO--the Kimono Girl!\p"
	.string "I listened in the Dragon's Den\n"
	.string "when you passed the Elder's\l"
	.string "test.\p"
	.string "Let me challenge you and your\n"
	.string "POKéMON!$"

EcruteakTheater_Text_KuniSeen:
	.string "I'm the last one.\n"
	.string "You were dependable at the\n"
	.string "Goldenrod Tunnel.\p"
	.string "I'm the one who twirls even\n"
	.string "underground--Kuni!\p"
	.string "I saw you thwart Rocket's\n"
	.string "plan to take the Radio Tower.\p"
	.string "Now show me your strength!\n"
	.string "Let me challenge you and your\l"
	.string "POKéMON!$"

EcruteakTheater_Text_KuniAfter:
	.string "Talk to Zuki in the middle\n"
	.string "when you are ready.$"

EcruteakTheater_Text_ZukiDone:
	.string "We were not wrong about you.\n"
	.string "You are indeed worthy of this...\p"
	.string "Please take it.$"

EcruteakTheater_Text_GirlHooh:
	.string "Big sisters! I just saw the\n"
	.string "big shadow of a POKéMON over\l"
	.string "the Bell Tower!\p"
	.string "It could be...$"

EcruteakTheater_Text_GirlLugia:
	.string "Big sisters! I just saw the\n"
	.string "big shadow of a POKéMON in the\l"
	.string "Whirl Islands' waters!\p"
	.string "It could be...$"

EcruteakTheater_Text_ZukiHooh:
	.string "ZUKI: {PLAYER}!\n"
	.string "We'll be at the Bell Tower.\n"
	.string "See you there!$"

EcruteakTheater_Text_ZukiLugia:
	.string "ZUKI: {PLAYER}!\n"
	.string "We'll be at the Whirl Islands.\l"
	.string "See you there!$"

EcruteakTheater_Text_KimonoDone:
	.string "We are rehearsing a dance.$"

EcruteakTheater_Text_ZukiAfterAll:
	.string "Thank you for your help the\n"
	.string "other day.\p"
	.string "You've shown the bond between\n"
	.string "people can grow with POKéMON...\p"
	.string "We appreciate how you lived up\n"
	.string "to our hopes, VAR(259, 0, 0)!\p"
	.string "If you learned anything from\n"
	.string "this, thank Mr. POKéMON and\l"
	.string "Professor Elm...$"

EcruteakTheater_EventScript_SurfGuy::
	lock
	faceplayer
	goto_if_eq VAR_ECRUTEAK_THEATER, 1, EcruteakTheater_EventScript_SurfGuyDuringRocket
	goto_if_unset FLAG_RECEIVED_HM_SURF, EcruteakTheater_EventScript_SurfGuy_GiveSurf
	msgbox EcruteakTheater_Text_SurfGuyAfter, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakTheater_EventScript_SurfGuy_GiveSurf::
	msgbox EcruteakTheater_Text_SurfGuyGiveSurf, MSGBOX_DEFAULT
	giveitem ITEM_HM_SURF
	setflag FLAG_RECEIVED_HM_SURF
	msgbox EcruteakTheater_Text_SurfGuyGaveSurf
	closemessage
	setflag FLAG_RECEIVED_HM_SURF
	setvar VAR_ECRUTEAK_THEATER, 3
	release
	end

EcruteakTheater_EventScript_SurfGuyDuringRocket::
	msgbox EcruteakTheater_Text_SurfGuyRocket, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakTheater_EventScript_TriggerSurfGuy::
	lock
	applymovement LOCALID_SURF_GUY, EcruteakTheater_Movement_SurfGuy1
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	msgbox EcruteakTheater_Text_SurfGuyGiveSurf, MSGBOX_DEFAULT
	giveitem ITEM_HM_SURF
	setflag FLAG_RECEIVED_HM_SURF
	msgbox EcruteakTheater_Text_SurfGuyGaveSurf
	closemessage
	setflag FLAG_RECEIVED_HM_SURF
	setvar VAR_ECRUTEAK_THEATER, 3
	applymovement LOCALID_SURF_GUY, EcruteakTheater_Movement_SurfGuy2
	waitmovement 0 
	release
	end

EcruteakTheater_Movement_SurfGuy1:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

EcruteakTheater_Movement_SurfGuy2:
	walk_up
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

EcruteakTheater_Text_SurfGuyRocket:
	.string "What's the deal with that\n"
	.string "Team Rocket Grunt, messing\l"
	.string "with that Kimono Girl?\p"
	.string "You are a Trainer, right?\n"
	.string "Please help her!$"

EcruteakTheater_Text_SurfGuyGiveSurf:
	.string "Wonderful! You were so\n"
	.string "courageous for your age!\p"
	.string "It was a rare sight to see!\n"
	.string "I want you to have this.\p"
	.string "Don't be shy--take it!$"

EcruteakTheater_Text_SurfGuyGaveSurf:
	.string "That's Surf.\n"
	.string "It's a move that lets POKéMON\l"
	.string "swim across water with ease.$"

EcruteakTheater_Text_SurfGuyAfter:
	.string "Not only are the Kimono Girls\n"
	.string "great dancers, they're also\l"
	.string "skilled at POKéMON.\p"
	.string "But they battle only for good\n"
	.string "reasons.\p"
	.string "I don't know if you could beat\n"
	.string "them if they showed their skill...$"

EcruteakTheater_EventScript_Psyduck::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PSYDUCK, CRY_MODE_NORMAL
	msgbox EcruteakTheater_Text_Psyduck, MSGBOX_DEFAULT
	waitmoncry
	release
	end

EcruteakTheater_Text_Psyduck:
	.string "PSYDUCK: Dau dau!$"


EcruteakTheater_EventScript_Boy::
	lock
	faceplayer
	goto_if_eq VAR_ECRUTEAK_THEATER, 1, EcruteakTheater_EventScript_BoyDuringRocket
	msgbox EcruteakTheater_Text_Boy, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakTheater_EventScript_BoyDuringRocket::
	msgbox EcruteakTheater_Text_BoyBefore, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakTheater_Text_BoyBefore:
	.string "eeeeek!$"

EcruteakTheater_Text_Boy:
	.string "I was supposed to be the hero...!\n"
	.string "So much for getting close to\l"
	.string "a Kimono Girl!$"


EcruteakTheater_EventScript_Granny::
	lock
	faceplayer
	goto_if_eq VAR_ECRUTEAK_THEATER, 1, EcruteakTheater_EventScript_GrannyDuringRocket
	msgbox EcruteakTheater_Text_Granny, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakTheater_EventScript_GrannyDuringRocket::
	msgbox EcruteakTheater_Text_GrannyBefore, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakTheater_Text_Granny:
	.string "That man's always with his\n"
	.string "PSYDUCK.\p"
	.string "Says he wants a POKéMON that\n"
	.string "can Surf and dance.\p"
	.string "Is he trying to make a POKéMON\n"
	.string "that stars in synchronized\l"
	.string "swimming?$"

EcruteakTheater_Text_GrannyBefore:
	.string "Oh... Ouch...!\n"
	.string "This stomachache!\p"
	.string "I wouldn't let this guy act like\n"
	.string "that if not for this pain...!$"


EcruteakTheater_EventScript_Gramps::
	lock
	faceplayer
	goto_if_eq VAR_ECRUTEAK_THEATER, 1, EcruteakTheater_EventScript_GrampsDuringRocket
	msgbox EcruteakTheater_Text_Gramps, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakTheater_EventScript_GrampsDuringRocket::
	msgbox EcruteakTheater_Text_GrampsBefore, MSGBOX_DEFAULT
	closemessage
	release
	end


EcruteakTheater_Text_Gramps:
	.string "The Kimono Girls are so\n"
	.string "beautiful...\p"
	.string "But they have to go through\n"
	.string "rigorous training.\p"
	.string "And they have to learn to follow\n"
	.string "customs before appearing in\l"
	.string "public.\p"
	.string "But if you love something,\n"
	.string "anything is possible.$"

EcruteakTheater_Text_GrampsBefore:
	.string "Oh... Ouch...!\n"
	.string "This back pain!\p"
	.string "I wouldn't let this guy act like\n"
	.string "that if not for this pain...!$"

EcruteakTheater_EventScript_Girl::
	lock
	faceplayer
	goto_if_eq VAR_ECRUTEAK_THEATER, 1, EcruteakTheater_EventScript_GirlDuringRocket
	msgbox EcruteakTheater_Text_Girl, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakTheater_EventScript_GirlDuringRocket::
	msgbox EcruteakTheater_Text_GirlBefore, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakTheater_Text_Girl:
	.string "The KIMONO GIRLS are my big\n"
	.string "sisters! I'll be like them one\l"
	.string "day!$"

EcruteakTheater_Text_GirlBefore:
	.string "I like that funny dance!$"

EcruteakTheater_EventScript_FancyPanel::
	lock
	msgbox EcruteakTheater_Text_FancyPanel, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakTheater_Text_FancyPanel:
	.string "It's a fancy panel that's\n"
	.string "decorated with flowers.$"

