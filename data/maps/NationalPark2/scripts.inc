.set LOCALID_BUGCONTEST_ATTENDANT, 11
.set LOCALID_BUGCONTEST_GIRL, 13
.set LOCALID_BUGCONTEST_BC1, 1
.set LOCALID_BUGCONTEST_BC2, 2
.set LOCALID_BUGCONTEST_BOY, 12

NationalPark2_MapScripts::
	@map_script MAP_SCRIPT_ON_TRANSITION, NationalPark2_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, NationalPark2_OnFrame
	.byte 0

@NationalPark2_OnTransition::
@	goto_if_eq VAR_BUG_CONTEST_STATE, 1, NationalPark2_EventScript_Enter
@	end
	
NationalPark2_OnFrame::
	map_script_2 VAR_BUG_CONTEST_STATE, 1, NationalPark2_EventScript_Enter
	.2byte 0

NationalPark2_EventScript_Enter::
	lock
	msgbox NationlParkBugContest_Text_EnjoyTheContest, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp1
	waitmovement 0
	setvar VAR_BUG_CONTEST_STATE, 2
	release
	end

NationalPark2_EventScript_Trigger::
	lock
	turnobject LOCALID_BUGCONTEST_ATTENDANT, DIR_EAST
	goto NationalPark2_EventScript_RetireChoice
NationalPark2_EventScript_Attendant::
	lock
	faceplayer
NationalPark2_EventScript_RetireChoice::
	msgbox NationalParkBugContest_Text_Attendant, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, BugContest_EventScript_TimesUp
	msgbox NationlParkBugContest_Text_EnjoyTheContest, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp1
	waitmovement 0
	release
	end

NationlParkBugContest_Text_EnjoyTheContest:
	.string "ATTENDANT: Enjoy the contest!$"

NationalParkBugContest_Text_Attendant:
	.string "ATTENDANT: Would you like to end\n"
	.string "the contest?$"

NationalParkBugContest_Text_Contestant1A:
	.string "DON: I'm going to win!\n"
	.string "Don't bother me.$"

NationalParkBugContest_Text_Contestant2A:
	.string "ED: My PARASECT puts POKéMON to\n"
	.string "sleep with SPORE.$"

NationalParkBugContest_Text_Contestant3A:
	.string "NICK: I'm raising fast POKéMON for\n"
	.string "battles.$"

NationalParkBugContest_Text_Contestant4A:
	.string "WILLIAM: I'm not concerned about\n"
	.string "winning.\p"
	.string "I'm just looking for rare POKéMON.$"

NationalParkBugContest_Text_Contestant5A:
	.string "BENNY: Ssh! You'll scare off\n"
	.string "SCYTHER.\p"
	.string "I'll talk to you later.$"

NationalParkBugContest_Text_Contestant6A:
	.string "BARRY: You should weaken bug\n"
	.string "POKéMON first,\p"
	.string "then throw a BALL.$"

NationalParkBugContest_Text_Contestant7A:
	.string "CINDY: I love bug POKéMON.\p"
	.string "I guess you must like them too.$"

NationalParkBugContest_Text_Contestant8A:
	.string "JOSH: I've been collecting bug\n"
	.string "POKéMON since I was just a baby.\p"
	.string "There's no way I'm going to lose!$"

NationalParkBugContest_Text_Contestant9A:
	.string "SAMUEL: If you've got the time to\n"
	.string "chat, go find some bug POKéMON.$"

NationalParkBugContest_Text_Contestant10A:
	.string "KIPP: I've studied about bug\n"
	.string "POKéMON a lot.\p"
	.string "I'm going to win for sure.$"

NationalParkBugContest_Text_Sign_RelaxationSquare:
	.string "RELAXATION SQUARE\n"
	.string "NATIONAL PARK$"

NationalParkBugContest_Text_Sign_BattleNotice:
	.string "What is this notice?\p"
	.string "Please battle only in the grass.\p"
	.string "NATIONAL PARK WARDEN'S OFFICE$"

NationalParkBugContest_Text_TrainerTips:
	.string "TRAINER TIPS\p"
	.string "Print out MAIL by opening it then\n"
	.string "pressing START.$"
