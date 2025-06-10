BugContest_EventScript_Start::
	end

BugContest_EventScript_TimesUp::
	lockall
	msgbox BugContest_Text_TimesUp, MSGBOX_DEFAULT
	special ExitBugContestMode

	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, VioletCityHouse1_EventScript_DeclineTrade
	special JudgeBugContestMon
	call_if_eq VAR_RESULT, 1, BugContest_EventScript_First
	call_if_eq VAR_RESULT, 2, BugContest_EventScript_Second
	call_if_eq VAR_RESULT, 3, BugContest_EventScript_Third
	special TransferBugContestMon
	delay 20
	giveitem VAR_0x8005
	msgbox BugContest_Text_TimesUp, MSGBOX_DEFAULT
	closemessage
	releaseall
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

BugContest_Text_TimesUp:
	.string "Time's up!$"

BugContest_Text_First:
	.string "First$"
BugContest_Text_Second:
	.string "Second$"
BugContest_Text_Third:
	.string "Third$"