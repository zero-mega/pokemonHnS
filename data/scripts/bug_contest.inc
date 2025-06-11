BugContest_EventScript_Start::
	end

BugContest_EventScript_WhiteOut::
	lockall
	delay 200
	msgbox BugContest_Text_WhiteOut, MSGBOX_DEFAULT
	closemessage
	goto BugContest_EventScript_End
	end

BugContest_EventScript_TimesUp::
	lockall
	msgbox BugContest_Text_TimesUp, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK

	setobjectxyperm OBJ_EVENT_ID_PLAYER, 19, 28
	setobjectxyperm LOCALID_BUGCONTEST_GIRL, 17, 28
	setobjectxyperm LOCALID_BUGCONTEST_BC1, 21, 28
	setobjectxyperm LOCALID_BUGCONTEST_BC2, 23, 28
	setobjectxyperm LOCALID_BUGCONTEST_BOY, 15, 28
	setobjectxyperm LOCALID_BUGCONTEST_ATTENDANT, 20, 26
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	turnobject LOCALID_BUGCONTEST_GIRL, DIR_NORTH
	turnobject LOCALID_BUGCONTEST_BC1, DIR_NORTH
	turnobject LOCALID_BUGCONTEST_BC2, DIR_NORTH
	turnobject LOCALID_BUGCONTEST_BOY, DIR_NORTH
	turnobject LOCALID_BUGCONTEST_ATTENDANT, DIR_SOUTH
	fadescreen FADE_FROM_BLACK
	getpartysize
	goto_if_eq VAR_RESULT, 1, BugContest_EventScript_Didntcatch
	@fallthrough
BugContestEventScript_Judging::
	msgbox BugContest_Text_Judging0, MSGBOX_DEFAULT
	closemessage
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, BugContestEventScript_Judging
	goto_if_eq VAR_0x8004, 0, BugContestEventScript_Judging
	msgbox BugContest_Text_Judging1, MSGBOX_DEFAULT
	closemessage
	special JudgeBugContestMon
	call_if_eq VAR_RESULT, 1, BugContest_EventScript_First
	call_if_eq VAR_RESULT, 2, BugContest_EventScript_Second
	call_if_eq VAR_RESULT, 3, BugContest_EventScript_Third
	special TransferBugContestMon
	delay 20
	giveitem VAR_0x8005
	msgbox BugContest_Text_TimesUp, MSGBOX_DEFAULT
	goto BugContest_EventScript_End
	end

BugContest_EventScript_Didntcatch::
	msgbox BugContest_Text_DidntCatch, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_POKE_BALL
	closemessage
	fadescreen FADE_TO_BLACK
	goto BugContest_EventScript_End
	end

BugContest_EventScript_First::
	msgbox BugContest_Text_First, MSGBOX_DEFAULT
	closemessage
	return
BugContest_EventScript_Second::
	msgbox BugContest_Text_Second, MSGBOX_DEFAULT
	closemessage
	return
BugContest_EventScript_Third::
	msgbox BugContest_Text_Third, MSGBOX_DEFAULT
	closemessage
	return

BugContest_EventScript_End::
	special HealPlayerParty
	special LoadPlayerParty
	special ExitBugContestMode
	setvar VAR_BUG_CONTEST_STATE, 0
	special RemoveSafariBalls
	warp MAP_NATIONAL_PARK_GATES, 7, 2
	releaseall
	end

BugContest_Text_Judging0::
	.string "The contest has now concluded.\n"
	.string "Please pick the POKéMON you would\l"
	.string "like to keep and have judged.$"

BugContest_Text_Judging1::
	.string "We will now judge the POKéMON\n"
	.string "you've caught.\p"
	.string "...................\n"
	.string "...................\p"
	.string "We have chosen the winners! Are\n"
	.string "ready for this?\p"

BugContest_Text_DidntCatch:
	.string "Placing third is {PLAYER}, with\n"
	.string "no POKéMON caught.$"

BugContest_Text_TimesUp:
	.string "Time's up!$"

BugContest_Text_WhiteOut:
	.string "{PLAYER} is out of useable POKéMON.\n"
	.string "{PLAYER} forfeited the contest.$"

BugContest_Text_First:
	.string "First$"
BugContest_Text_Second:
	.string "Second$"
BugContest_Text_Third:
	.string "Third$"