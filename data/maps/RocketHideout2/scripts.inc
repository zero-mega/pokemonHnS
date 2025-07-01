.set LOCALID_ROCKETHIDEOUT2_LANCE, 7
.set LOCALID_ROCKETHIDEOUT2_DRAGONITE, 8
.set LOCALID_ROCKETHIDEOUT2_MURKROWSTAIRS, 15
.set LOCALID_ROCKETHIDEOUT2_MURKROWGATE, 16

RocketHideout2_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, RocketHideout2_OnLoad
	.byte 0

RocketHideout2_OnLoad::
	call_if_set FLAG_HIDE_ROCKETHIDEOUT2_GATE, RocketHideout2_HideGate
	end

RocketHideout2_HideGate::
	setmetatile 14, 19, 0x378, FALSE
	setmetatile 14, 20, 0x380, FALSE
	setmetatile 15, 19, 0x379, FALSE
	setmetatile 15, 20, 0x379, FALSE
	setmetatile 16, 19, 0x379, FALSE
	setmetatile 16, 20, 0x379, FALSE
	return

RocketHideout2_Trigger_MurkrowStairs::
	lock
	applymovement LOCALID_ROCKETHIDEOUT2_MURKROWSTAIRS, RocketHideout2_Movement_MurkrowStairs1
	waitmovement 0
	playmoncry SPECIES_MURKROW, CRY_MODE_NORMAL
	msgbox RocketHideout3_Text_MurkrowSpeak1, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROCKETHIDEOUT2_MURKROWSTAIRS, RocketHideout2_Movement_MurkrowStairs2
	waitmovement 0
	setflag FLAG_HIDE_ROCKETHIDEOUT2_MURKROWSTAIRS
	removeobject LOCALID_ROCKETHIDEOUT2_MURKROWSTAIRS
	clearflag FLAG_HIDE_ROCKETHIDEOUT3_MURKROWSTAIRS
	setvar VAR_MAHOGANY_TOWN_STATE, 10
	release
	end

RocketHideout2_Movement_MurkrowStairs1:
	jump_in_place_left
	jump_in_place_left
	step_end

RocketHideout2_Movement_MurkrowStairs2:
	jump_in_place_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end


RocketHideout3_Trigger_MurkrowGate::
	lock
	applymovement LOCALID_ROCKETHIDEOUT3_MURKROWGATE, RocketHideout3_Movement_MurkrowStairs1
	waitmovement 0
	playmoncry SPECIES_MURKROW, CRY_MODE_NORMAL
	msgbox RocketHideout3_Text_MurkrowSpeak1, MSGBOX_DEFAULT
	closemessage




	@RESUME
	applymovement LOCALID_ROCKETHIDEOUT3_MURKROWGATE, RocketHideout3_Movement_MurkrowGate2
	waitmovement 0
	setflag FLAG_HIDE_ROCKETHIDEOUT3_MURKROWGATE
	removeobject LOCALID_ROCKETHIDEOUT3_MURKROWGATE
	setvar VAR_MAHOGANY_TOWN_STATE, 12
	release
	end

RocketHideout3_Movement_MurkrowGate2:
	jump_in_place_right
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

RocketHideout_EventScript_Item_Thief::
	finditem ITEM_TM_THIEF
	end

RocketHideout2_EventScript_LanceTriggerLeft::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight1
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	goto RocketHideout2_EventScript_Lance

RocketHideout2_EventScript_LanceTriggerRight::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft1
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	goto RocketHideout2_EventScript_Lance

RocketHideout2_EventScript_Lance::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp1
	waitmovement 0
	msgbox RocketHideout2_Text_LanceHeals1, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox RocketHideout2_Text_LanceHeals2, MSGBOX_DEFAULT
	closemessage
	applymovement2 LOCALID_ROCKETHIDEOUT2_LANCE, RocketHideout2_Movement_LanceGoDeeper
	applymovement2 LOCALID_ROCKETHIDEOUT2_DRAGONITE, RocketHideout2_Movement_DragoniteGoDeeper
	waitmovement LOCALID_ROCKETHIDEOUT2_LANCE
	waitmovement LOCALID_ROCKETHIDEOUT2_DRAGONITE
	setflag FLAG_HIDE_ROCKETHIDEOUT2_LANCE_DRAGONITE
	removeobject LOCALID_ROCKETHIDEOUT2_LANCE
	setvar VAR_MAHOGANY_TOWN_STATE, 6
	removeobject LOCALID_ROCKETHIDEOUT2_DRAGONITE
	release
	end

RocketHideout2_Movement_LanceGoDeeper:
	walk_right
	walk_right
	delay_2
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

RocketHideout2_Movement_DragoniteGoDeeper:
	delay_8
	delay_8
	delay_8
	delay_8
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

RocketHideout2_Text_LanceHeals1:
    .string "LANCE: Are you all right?\p"
    .string "Your POKéMON are hurt and tired.\p"
    .string "Here, give them some of my\n"
    .string "medicine.$"

RocketHideout2_Text_LanceHeals2:
    .string "LANCE: {PLAYER}, let's give it\n"
    .string "our best for POKéMON.$"

RocketHideout2_Text_GruntM17Seen:
    .string "The door won't open?\p"
    .string "Well, duh. It has to have a\n"
    .string "password that only TEAM ROCKET\l"
    .string "knows.$"

RocketHideout2_Text_GruntM17Beaten:
    .string "What? I lost?$"

RocketHideout2_Text_GruntM17After:
    .string "Heh, I'm just a GRUNT.\p"
    .string "I don't know the password.\n"
    .string "Too bad for you.$"

RocketHideout2_EventScript_Grunt14::
	trainerbattle_single TRAINER_GRUNT_14 RocketHideout2_Text_GruntM17Seen, RocketHideout2_Text_GruntM17Beaten
	msgbox RocketHideout2_Text_GruntM17After, MSGBOX_AUTOCLOSE
	end

RocketHideout2_Text_GruntM18Seen:
    .string "Oh, a kid? I don't really like\n"
    .string "this, but eliminate you I must.$"

RocketHideout2_Text_GruntM18Beaten:
    .string "I knew I'd lose…$"

RocketHideout2_Text_GruntM18After:
    .string "I got wiped out on the last\n"
    .string "mission by a kid too.\p"
    .string "When we were abducting POKéMON,\l"
    .string "this kid with long red hair and\l"
    .string "mean-looking eyes just\n"
    .string "creamed me…$"

RocketHideout2_EventScript_Grunt15::
	trainerbattle_single TRAINER_GRUNT_15 RocketHideout2_Text_GruntM18Seen, RocketHideout2_Text_GruntM18Beaten
	msgbox RocketHideout2_Text_GruntM18After, MSGBOX_AUTOCLOSE
	end

RocketHideout2_Text_GruntM19Seen:
    .string "You rotten little pest!$"

RocketHideout2_Text_GruntM19Beaten:
    .string "Grrrr…$"

RocketHideout2_Text_GruntM19After:
    .string "Heh, only the boss knows the\n"
    .string "password for that door.\p"
    .string "Where's the boss? Who knows?\n"
    .string "Go look for yourself.$"

RocketHideout2_EventScript_Grunt16::
	trainerbattle_single TRAINER_GRUNT_16 RocketHideout2_Text_GruntM19Seen, RocketHideout2_Text_GruntM19Beaten
	msgbox RocketHideout2_Text_GruntM19After, MSGBOX_AUTOCLOSE
	end

RocketHideout2_Text_DoorNoPassword:
    .string "The door's closed…\p"
    .string "It needs a password to open.$"

RocketHideout2_Text_DoorKnowPassword:
    .string "The door's closed…\p"
    .string "{PLAYER} entered the password.\p"
    .string "The door opened!$"




RocketHideout2_Text_ExecutiveFHoldIt:
    .string "Hold it right there!$"

RocketHideout2_Text_BossFThrash:
    .string "We can't have a brat like you\n"
    .string "on the loose.\p"
    .string "It's harmful to TEAM ROCKET's\n"
    .string "pride, you see.\p"
    .string "However strong you may be, you\n"
    .string "can't take both of us at the\l"
    .string "same time.\p"
    .string "Sorry, baby. Now get ready to\n"
    .string "be thrashed.$"

RocketHideout2_Text_LanceShareFun:
    .string "Hey! Don't be so selfish.\n"
    .string "Spread the fun around.$"

RocketHideout2_Text_BossDontMeddle:
    .string "What? You had an accomplice?\p"
    .string "Where is your sense of honor?\p"
    .string "As the interim boss in place of\n"
    .string "GIOVANNI, I'll show you how wrong\l"
    .string "it is to meddle with TEAM ROCKET!$"

RocketHideout2_Text_BossWin:
    .string "Tch, you really are strong.\p"
    .string "It's too bad.\p"
    .string "If you were to join TEAM ROCKET,\n"
    .string "you could become an EXECUTIVE.$"

RocketHideout2_Text_BossRetreat:
    .string "…This hideout is done for…\p"
    .string "But that's fine. The broadcast\n"
    .string "experiment was a total success.\p"
    .string "It doesn't matter what happens\n"
    .string "to this hideout now.\p"
    .string "We have much bigger plans.\p"
    .string "You'll come to appreciate TEAM\n"
    .string "ROCKET's true power soon enough.\p"
    .string "Enjoy yourself while you can…\p"
    .string "Fufufufu…$"

RocketHideout2_Text_LancePostBattle:
    .string "LANCE: That did it. We defeated\n"
    .string "all the ROCKETS here.\p"
    .string "But I'm concerned about the\n"
    .string "young guy I battled in the\l"
    .string "process…$"

RocketHideout2_Text_LancePowerOff:
    .string "Sorry, {PLAYER}. I saw how well\n"
    .string "you were doing, so I just hung\l"
    .string "back.\p"
    .string "Now all there is left to do is\n"
    .string "to turn off that odd radio\n"
    .string "signal.$"

RocketHideout2_Text_LanceElectrodeFaint:
    .string "It's this machine that's causing\n"
    .string "all the problems.\p"
    .string "I don't see a switch on it…\p"
    .string "We have no choice. We have to\n"
    .string "make all the ELECTRODE faint.\p"
    .string "That should stop this machine\n"
    .string "from transmitting that strange\l"
    .string "signal.\p"
    .string "It's no fault of the POKéMON, so\n"
    .string "it makes me feel guilty.\p"
    .string "{PLAYER}, let's split the job.$"

RocketHideout2_Text_LanceSide:
    .string "LANCE: Leave this side to me.$"

RocketHideout2_Text_LanceElectrodeDone:
    .string "LANCE: That odd signal has\n"
    .string "finally stopped.\p"
    .string "The LAKE should be back to\n"
    .string "normal.\p"
    .string "You're the hero! Let me thank\n"
    .string "you on behalf of all the\l"
    .string "POKéMON.\p"
    .string "Oh, yes. You should take this.\n"
    .string "I found it here, but I don't\l"
    .string "have any need for it.$"

RocketHideout2_Text_ReceivedHM06:
    .string "{PLAYER} received HM06.$"

RocketHideout2_Text_LanceWhirlpool:
    .string "That's WHIRLPOOL. Teach it to a\n"
    .string "POKéMON to get across wild water.\p"
    .string "But keep this in mind.\p"
    .string "You can use that out of battle\n"
    .string "only with the BADGE from\l"
    .string "MAHOGANY GYM.$"

RocketHideout2_Text_LanceMonMaster:
    .string "{PLAYER}…\p"
    .string "The journey to becoming the\n"
    .string "POKéMON MASTER is long and\l"
    .string "difficult.\p"
    .string "Knowing that, will you keep\n"
    .string "going?\p"
    .string "…\p"
    .string "I see. No, you're right.\p"
    .string "If you would give up that easily,\n"
    .string "you would have never chased that\l"
    .string "dream in the first place.\p"
    .string "I look forward to seeing you\n"
    .string "again!$"

RocketHideout2_Text_B2FTransmitter:
    .string "It's the radio transmitter that's\n"
    .string "sending the sinister signal.\p"
    .string "It's working at full capacity.$"

RocketHideout2_Text_B2FDeactivateTransmitter:
    .string "The radio transmitter has finally\n"
    .string "stopped its evil broadcast.$"



