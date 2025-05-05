Route31_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route31_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route31_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route31_EventScript_Bugcatcher_Wade::
	trainerbattle_single TRAINER_WADE, Route31_Text_BugCatcherWade1_Seen, Route31_Text_BugCatcherWade1_Beaten
	msgbox Route31_Text_BugCatcherWade1_After, MSGBOX_AUTOCLOSE
	end

Route31_EventScript_Youngster::
	lock
	faceplayer
	msgbox Route31_Text_CooltrainerM, MSGBOX_DEFAULT
	closemessage
	release
	end

Route31_EventScript_SleepyMan::
	lock
	faceplayer
	msgbox Route31_Text_SleepyMan, MSGBOX_DEFAULT
	closemessage
	release
	end

Route31_EventScript_Boy::
	lock
	faceplayer
	msgbox Route31_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end

Route31_EventScript_DarkCaveSign::
	lock
	msgbox Route31_Text_DarkCaveSign, MSGBOX_SIGN
	closemessage
	release
	end

Route31_EventScript_Sign::
	lock
	msgbox Route31_Text_Sign, MSGBOX_SIGN
	closemessage
	release
	end

Route31_EventScript_ItemPokeBall::
	finditem ITEM_POKE_BALL
	end

Route31_EventScript_ItemAntidote::
	finditem ITEM_ANTIDOTE
	end

Route31_Text_CooltrainerM:
	.string "DARK CAVE…\p"
	.string "If POKéMON could light it up,\n"
	.string "I'd explore it.$"

Route31_Text_BugCatcherWade1_Seen:
	.string "I caught a bunch of POKéMON.\n"
	.string "Let me battle with you!$"

Route31_Text_BugCatcherWade1_Beaten:
	.string "Awwwww…$"

Route31_Text_BugCatcherWade1_After:
	.string "You can catch POKéMON even if\n"
	.string "you have six with you.\p"
	.string "If you catch one, it'll go to\n"
	.string "your BOX automatically.$"

Route31_Text_SleepyMan:
	.string "… Hnuurg… Huh?\p"
	.string "I walked too far today looking\n"
	.string "for POKéMON.\p"
	.string "My feet hurt and I'm sleepy…\p"
	.string "If I were a wild POKéMON, I'd\n"
	.string "be easy to catch…\p"
	.string "…Zzzz…$"

Route31_Text_SleepyManGotMail:
	.string "…Zzzz… Huh?\p"
	.string "What's that? You have MAIL\n"
	.string "for me?$"

Route31_Text_HandOverMailMon:
	.string "{PLAYER} handed over the\n"
	.string "POKéMON holding the MAIL.$"

Route31_Text_ReadingMail:
	.string "Let's see…\p"
	.string "…DARK CAVE leads to another\n"
	.string "road…\p"
	.string "That's good to know.\p"
	.string "Thanks for bringing this to\n"
	.string "me.\p"
	.string "My friend's a good guy, and\n"
	.string "you're swell too!\p"
	.string "I'd like to do something good\n"
	.string "in return too!\p"
	.string "I know! I want you to have\n"
	.string "this!$"

Route31_Text_DescribeNightmare:
	.string "TM50 is NIGHTMARE.\p"
	.string "It's a wicked move that\n"
	.string "steadily cuts the HP of a\n"
	.string "sleeping enemy.\p"
	.string "Ooooh… That's scary…\p"
	.string "I don't want to have bad\n"
	.string "dreams.$"

Route31_Text_WrongMail:
	.string "This MAIL isn't for me.$"

Route31_Text_MissingMail:
	.string "Why is this POKéMON so special?\p"
	.string "It doesn't have any MAIL.$"

Route31_Text_DeclinedToHandOverMail:
	.string "What? You don't want\n"
	.string "anything?$"

Route31_Text_CantTakeLastMon:
	.string "If I take that POKéMON from\n"
	.string "you,\p"
	.string "what are you going to use in\n"
	.string "battle?$"

Route31_Text_Youngster:
	.string "I found a good POKéMON in DARK\n"
	.string "CAVE.\p"
	.string "I'm going to raise it to take\n"
	.string "on FALKNER.\p"
	.string "He's the leader of VIOLET\n"
	.string "CITY's GYM.$"

Route31_Text_Sign:
	.string "ROUTE 31\p"
	.string "VIOLET CITY - CHERRYGROVE CITY$"

Route31_Text_DarkCaveSign:
	.string "DARK CAVE$"
