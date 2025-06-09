BugContest_EventScript_Start::
	end

BugContest_EventScript_TimesUp::
	lockall
	msgbox BugContest_Text_TimesUp, MSGBOX_DEFAULT
	special ExitBugContestMode
	closemessage
	releaseall
	end

BugContest_Text_TimesUp:
	.string "Time's up!$"