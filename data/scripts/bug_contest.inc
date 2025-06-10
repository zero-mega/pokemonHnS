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

	transferbugcontestmon
	closemessage
	releaseall
	end

BugContest_Text_TimesUp:
	.string "Time's up!$"