.set LOCALID_ROCKETHIDEOUT3_LANCE, 3
.set LOCALID_ROCKETHIDEOUT3_DRAGONITE, 2
.set LOCALID_ROCKETHIDEOUT3_SILVER, 5

RocketHideout3_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RocketHideout3_OnFrame
	map_script MAP_SCRIPT_ON_LOAD, RocketHideout3_OnLoad
	.byte 0

RocketHideout3_OnLoad::
	call_if_set FLAG_HIDE_ROCKETHIDEOUT3_GATE, RocketHideout3_HideGate
	end
	
RocketHideout3_HideGate::
	setmetatile 11, 11, 0x378, FALSE
	setmetatile 11, 12, 0x380, FALSE
	setmetatile 12, 11, 0x379, FALSE
	setmetatile 12, 12, 0x379, FALSE
	setmetatile 13, 11, 0x379, FALSE
	setmetatile 13, 12, 0x379, FALSE
	return

RocketHideout3_OnFrame::
	map_script_2 VAR_MAHOGANY_TOWN_STATE, 6, RocketHideout3_EventScript_LancePassword
	.2byte 0


RocketHideout3_EventScript_LancePassword::
	lock
	delay 55
	playse SE_PIN
	applymovement LOCALID_ROCKETHIDEOUT3_LANCE, Common_Movement_ExclamationMark
	delay 20
	applymovement LOCALID_ROCKETHIDEOUT3_LANCE, Common_Movement_WalkRight1
	msgbox RocketHideout3_Text_LanceGetPassword, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROCKETHIDEOUT3_LANCE, RocketHideout3_Movement_LanceLeave
	applymovement LOCALID_ROCKETHIDEOUT3_DRAGONITE, RocketHideout3_Movement_DragoniteLeave
	waitmovement LOCALID_ROCKETHIDEOUT3_LANCE
	waitmovement LOCALID_ROCKETHIDEOUT3_DRAGONITE
	setflag FLAG_HIDE_ROCKETHIDEOUT3_LANCE_DRAGONITE
	removeobject LOCALID_ROCKETHIDEOUT3_DRAGONITE
	removeobject LOCALID_ROCKETHIDEOUT3_LANCE
	setvar VAR_MAHOGANY_TOWN_STATE, 7
	release
	end

RocketHideout3_Movement_LanceLeave:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	delay_2
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

RocketHideout3_Movement_DragoniteLeave:
	delay_8
	delay_8
	delay_8
	delay_8
	delay_8
	delay_8
	delay_8
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

RocketHideout3_Text_LanceGetPassword:
    .string "LANCE: It takes two passwords\n"
    .string "to get into the boss's quarters.\p"
    .string "Those passwords are known only\n"
    .string "to a few ROCKETS.\p"
    .string "That ROCKET there very graciously\n"
    .string "told me so.\p"
    .string "{PLAYER}, let's go get the\n"
    .string "passwords.$"

RocketHideout3_EventScript_RocketKO::
	lock
	msgbox RocketHideout3_Text_B3FRocket, MSGBOX_DEFAULT
	release
	end

RocketHideout3_Text_B3FRocket:
    .string "Urrggh… The guy in the cape is\n"
    .string "incredibly tough…$"

RocketHideout3_Trigger_Silver::
	lock
	clearflag FLAG_HIDE_ROCKETHIDEOUT3_SILVER
	addobject LOCALID_ROCKETHIDEOUT3_SILVER
	playbgm MUS_HG_ENCOUNTER_RIVAL, TRUE
	applymovement LOCALID_ROCKETHIDEOUT3_SILVER, RocketHideout3_Movement_SilverEnter
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	msgbox RocketHideout3_Text_Rival, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROCKETHIDEOUT3_SILVER, RocketHideout3_Movement_SilverLeave
	waitmovement 0
	setflag FLAG_HIDE_ROCKETHIDEOUT3_SILVER
	removeobject LOCALID_ROCKETHIDEOUT3_SILVER
	setvar VAR_MAHOGANY_TOWN_STATE, 8
	fadedefaultbgm
	release
	end

RocketHideout3_Movement_SilverEnter:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

RocketHideout3_Movement_SilverLeave:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

RocketHideout3_EventScript_Door::
	lock
	goto_if_set FLAG_HIDE_ROCKETHIDEOUT3_GATE, RocketHideout3_EventScript_DoorIsOpen
	goto_if_eq VAR_ROCKET_PASSWORD, 2, RocketHideout3_EventScript_OpenDoor
	msgbox RocketHideout3_Text_B3FLockedDoorNeedsPassword, MSGBOX_DEFAULT
	closemessage
	release
	end

RocketHideout3_EventScript_OpenDoor::
	msgbox RocketHideout3_Text_B3FLockedDoorOpenSesame, MSGBOX_DEFAULT
	closemessage
	playse SE_CLICK
	setmetatile 11, 11, 0x378, FALSE
	setmetatile 11, 12, 0x380, FALSE
	setmetatile 12, 11, 0x379, FALSE
	setmetatile 12, 12, 0x379, FALSE
	setmetatile 13, 11, 0x379, FALSE
	setmetatile 13, 12, 0x379, FALSE
	special DrawWholeMapView
	setflag FLAG_HIDE_ROCKETHIDEOUT3_GATE
	release
	end

RocketHideout3_EventScript_DoorIsOpen::
	end

RocketHideout3_EventScript_GruntF5::
	trainerbattle_single TRAINER_GRUNT_29 RocketHideout3_Text_GruntF5Seen, RocketHideout3_Text_GruntF5Beaten
	msgbox RocketHideout3_Text_GruntF5After, MSGBOX_NPC
	goto_if_unset FLAG_GOT_PASSWORD_FROM_GRUNTF, RocketHideout3_EventScript_IncrementPasswordGruntF
	end

RocketHideout3_EventScript_IncrementPasswordGruntF::
	addvar VAR_ROCKET_PASSWORD, 1
	setflag FLAG_GOT_PASSWORD_FROM_GRUNTF
	end

RocketHideout3_EventScript_Eto::
	trainerbattle_single TRAINER_ETO_2 RocketHideout3_Text_GruntM28Seen, RocketHideout3_Text_GruntM28Beaten
	msgbox RocketHideout3_Text_GruntM28After, MSGBOX_NPC
	goto_if_unset FLAG_GOT_PASSWORD_FROM_ETO, RocketHideout3_EventScript_IncrementPasswordEto
	end

RocketHideout3_EventScript_IncrementPasswordEto::
	addvar VAR_ROCKET_PASSWORD, 1
	setflag FLAG_GOT_PASSWORD_FROM_ETO
	end

RocketHideout3_EventScript_Ross::
	trainerbattle_single TRAINER_ROSS RocketHideout3_Text_ScientistRossSeen, RocketHideout3_Text_ScientistRossBeaten
	msgbox RocketHideout3_Text_ScientistRossAfter, MSGBOX_AUTOCLOSE
	end

RocketHideout3_EventScript_Mitch::
	trainerbattle_single TRAINER_MITCH RocketHideout3_Text_ScientistMitchSeen, RocketHideout3_Text_ScientistMitchBeaten
	msgbox RocketHideout3_Text_ScientistMitchAfter, MSGBOX_AUTOCLOSE
	end

RocketHideout3_EventScript_Item_IceHeal::
	finditem ITEM_ICE_HEAL
	end

RocketHideout3_EventScript_Item_Protein::
	finditem ITEM_PROTEIN
	end

RocketHideout3_EventScript_Item_FullHeal::
	finditem ITEM_FULL_HEAL
	end

RocketHideout3_EventScript_Item_GuardSpec::
	finditem ITEM_GUARD_SPEC
	end

RocketHideout3_EventScript_Item_HyperPotion::
	finditem ITEM_HYPER_POTION
	end

RocketHideout3_Text_B3FLockedDoorNeedsPassword:
    .string "The door's closed…\p"
    .string "It needs two passwords to open.$"

RocketHideout3_Text_B3FLockedDoorOpenSesame:
    .string "The door's closed…\p"
    .string "{PLAYER} entered the two passwords.\p"
    .string "The door opened!$"

RocketHideout3_Text_Rival:
    .string "…\p"
    .string "Didn't I tell you that I was\n"
    .string "going to destroy TEAM ROCKET?\p"
    .string "…Tell me, who was the guy in the\n"
    .string "cape who used dragon POKéMON?\p"
    .string "My POKéMON were no match at all.\p"
    .string "It's what he said that bothers\n"
    .string "me…\p"
    .string "He told me that I don't love and\n"
    .string "trust my POKéMON enough.\p"
    .string "It's not my fault my team is so\n"
    .string "useless.\p"
    .string "I'm furious that I lost to a\n"
    .string "bleeding heart like him.\p"
    .string "But it makes me question myself.\p"
    .string "Is there something I'm doing\n"
    .string "wrong?\p"
    .string "Could it be that love made his\n"
    .string "team so powerful?$"

RocketHideout3_Text_ExecutiveM4Before:
    .string "What? Who are you? This is the\n"
    .string "office of our leader, GIOVANNI.\p"
    .string "Since disbanding TEAM ROCKET\n"
    .string "three years ago, he has been in\l"
    .string "hiding.\p"
    .string "But we're certain he will be\n"
    .string "back some day to assume command\l"
    .string "again.\p"
    .string "I won't let you interfere with\n"
    .string "our plans!$"

RocketHideout3_Text_ExecutiveM4Beaten:
    .string "I… I couldn't do a thing…\p"
    .string "GIOVANNI, please forgive me…$"

RocketHideout3_Text_ExecutiveM4After:
    .string "No, I can't let this affect me.\p"
    .string "I have to inform the others…$"

RocketHideout3_Text_Murkrow:
    .string "MURKROW: The password is…\p"
    .string "HAIL GIOVANNI.$"

RocketHideout3_Text_GruntF5Seen:
    .string "Do I know the password?\p"
    .string "Maybe.\p"
    .string "But no weakling's going to get\n"
    .string "it!$"

RocketHideout3_Text_GruntF5Beaten:
    .string "All right. Stop. I'll tell you.$"

RocketHideout3_Text_GruntF5After:
    .string "The password to the boss's room\n"
    .string "is SLOWPOKETAIL.\p"
    .string "But it's useless unless you have\n"
    .string "two passwords.$"

RocketHideout3_Text_GruntM28Seen:
    .string "Hyuck-hyuck-hyuck!\p"
    .string "I remember you from the well!\p"
    .string "You're challenging me again?\p"
    .string "Hah! You're nuts, but you have\n"
    .string "guts!\p"
    .string "I'll warn you, I got better!\p"
    .string "If you can beat me, I'll tell\l"
    .string "you a password to the boss's\n"
    .string "room!$"

RocketHideout3_Text_GruntM28Beaten:
    .string "Hyuck-hyuck-hyuck! You're good!$"

RocketHideout3_Text_GruntM28After:
    .string "Hyuck-hyuck-hyuck!\p"
    .string "The password to the boss's room…\p"
    .string "Uh…, I think it is RATICATE TAIL.$"

RocketHideout3_Text_ScientistRossSeen:
    .string "I used to work for SILPH, but now\n"
    .string "I run research for TEAM ROCKET.\p"
    .string "A meddlesome child like you needs\n"
    .string "to be punished.$"

RocketHideout3_Text_ScientistRossBeaten:
    .string "A mere tactical error cost me…$"

RocketHideout3_Text_ScientistRossAfter:
    .string "A radio signal that drives\n"
    .string "POKéMON mad…\p"
    .string "My experiment is a complete\n"
    .string "success.\p"
    .string "My promotion is assured. This\n"
    .string "loss means absolutely nothing.$"

RocketHideout3_Text_ScientistMitchSeen:
    .string "I don't care that POKéMON are hurt\n"
    .string "by our experiment.$"

RocketHideout3_Text_ScientistMitchBeaten:
    .string "Thinking is my strong suit, not\n"
    .string "battling.$"

RocketHideout3_Text_ScientistMitchAfter:
    .string "If we turn up the power of our\n"
    .string "radio signal for broadcast\l"
    .string "nationwide…\p"
    .string "The very thought excites me!$"
