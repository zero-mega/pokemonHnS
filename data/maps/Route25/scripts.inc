Route25_MapScripts::
	.byte 0

Route25_EventScript_Dudley::
	trainerbattle_single TRAINER_DUDLEY Route25_Text_SchoolboyDudleySeen, Route25_Text_SchoolboyDudleyBeaten
	msgbox Route25_Text_SchoolboyDudleyAfter, MSGBOX_AUTOCLOSE
	end

Route25_EventScript_Ellen::
	trainerbattle_single TRAINER_ELLEN Route25_Text_LassEllenSeen, Route25_Text_LassEllenBeaten
	msgbox Route25_Text_LassEllenAfter, MSGBOX_AUTOCLOSE
	end

Route25_EventScript_Joe::
	trainerbattle_single TRAINER_JOE Route25_Text_SchoolboyJoeSeen, Route25_Text_SchoolboyJoeBeaten
	msgbox Route25_Text_SchoolboyJoeAfter, MSGBOX_AUTOCLOSE
	end

Route25_EventScript_Laura::
	trainerbattle_single TRAINER_LAURA Route25_Text_LassLauraSeen, Route25_Text_LassLauraBeaten
	msgbox Route25_Text_LassLauraAfter, MSGBOX_AUTOCLOSE
	end

Route25_EventScript_Lloyd::
	trainerbattle_single TRAINER_LLOYD Route25_Text_CamperLloydSeen, Route25_Text_CamperLloydBeaten
	msgbox Route25_Text_CamperLloydAfter, MSGBOX_AUTOCLOSE
	end

Route25_EventScript_Shannon::
	trainerbattle_single TRAINER_SHANNON Route25_Text_LassShannonSeen, Route25_Text_LassShannonBeaten
	msgbox Route25_Text_LassShannonAfter, MSGBOX_AUTOCLOSE
	end

Route25_EventScript_Pat::
	trainerbattle_single TRAINER_PAT Route25_Text_SupernerdPatSeen, Route25_Text_SupernerdPatBeaten
	msgbox Route25_Text_SupernerdPatAfter, MSGBOX_AUTOCLOSE
	end

Route25_EventScript_Kevin::
	lock
	faceplayer
	goto_if_set FLAG_ROUTE25_GOT_NUGGET, Route25_EventScript_KevinAfter
	msgbox Route25_Text_CooltrainerKevinNugget, MSGBOX_DEFAULT
	giveitem ITEM_BIG_NUGGET
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_ROUTE25_GOT_NUGGET
	msgbox Route25_Text_CooltrainerKevinSeen, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_KEVIN, Route25_Text_CooltrainerKevinBeaten
	msgbox Route25_Text_CooltrainerKevinAfter, MSGBOX_DEFAULT
	closemessage
	release
	end
Route25_EventScript_KevinAfter::
	msgbox Route25_Text_CooltrainerKevinAfter, MSGBOX_NPC
	end

Route25_EventScript_BillsHouseSign::
	msgbox Route25_Text_BillsHouseSign, MSGBOX_SIGN
	end

Route25_Text_MistyDate:
	.string "MISTY: Aww! Why did you have to\n"
	.string "show up and bug us now?\p"
	.string "Do you know what they call\n"
	.string "people like you?\p"
	.string "Pests! You heard me right,\n"
	.string "pest!\p"
	.string "…\p"
	.string "…Oh? Those BADGES you have…\n"
	.string "Are they JOHTO GYM BADGES?\p"
	.string "If you have eight, you must be\n"
	.string "good.\p"
	.string "OK, then. Come to CERULEAN GYM.\p"
	.string "I'll be happy to take you on.\p"
	.string "I'm MISTY, the GYM LEADER in\n"
	.string "CERULEAN.$"

Route25_Text_SchoolboyDudleySeen:
	.string "Beat the six of us trainers to\n"
	.string "win a fabulous prize!\p"
	.string "Think you've got what it takes?$"

Route25_Text_SchoolboyDudleyBeaten:
	.string "Whoo! Good stuff.$"

Route25_Text_SchoolboyDudleyAfter:
	.string "I did my best.\n"
	.string "I have no regrets.$"

Route25_Text_LassEllenSeen:
	.string "I'm second.\n"
	.string "Now it's serious!$"

Route25_Text_LassEllenBeaten:
	.string "How could I lose?$"

Route25_Text_LassEllenAfter:
	.string "I did my best.\n"
	.string "I have no regrets.$"

Route25_Text_SchoolboyJoeSeen:
	.string "Here's No. 3!\n"
	.string "I won't be easy.$"

Route25_Text_SchoolboyJoeBeaten:
	.string "Ow! Stomped flat!$"

Route25_Text_SchoolboyJoeAfter:
	.string "I did my best.\n"
	.string "I have no regrets.$"

Route25_Text_LassLauraSeen:
	.string "I'm No. 4!\n"
	.string "Getting tired?$"

Route25_Text_LassLauraBeaten:
	.string "I lost too…$"

Route25_Text_LassLauraAfter:
	.string "I did my best.\n"
	.string "I have no regrets.$"

Route25_Text_CamperLloydSeen:
	.string "OK! I'm No. 5.\n"
	.string "I'll stomp you!$"

Route25_Text_CamperLloydBeaten:
	.string "Whoa! Too much.$"

Route25_Text_CamperLloydAfter:
	.string "I did my best.\n"
	.string "I have no regrets.$"

Route25_Text_LassShannonSeen:
	.string "I'm the last in line, but I tell\n"
	.string "you, I'm tough!$"

Route25_Text_LassShannonBeaten:
	.string "You're kidding.$"

Route25_Text_LassShannonAfter:
	.string "I did my best.\n"
	.string "I have no regrets.$"

Route25_Text_SupernerdPatSeen:
	.string "Mufufufu…\p"
	.string "I have nothing to do with the\n"
	.string "six-pack trainers.\p"
	.string "I waited here to beat you when\n"
	.string "you were tired out by all the\l"
	.string "battles.$"

Route25_Text_SupernerdPatBeaten:
	.string "Aren't you tired at all?$"

Route25_Text_SupernerdPatAfter:
	.string "I'm sorry… I won't cheat\n"
	.string "anymore…$"

Route25_Text_CooltrainerKevinNugget:
	.string "You took on one more battle than\n"
	.string "you expected, but you won\l"
	.string "anyway.\p"
	.string "As promised, you win a prize.$"

Route25_Text_CooltrainerKevinSeen:
	.string "But after seeing how you battle,\n"
	.string "I want to see how I'll fare.\p"
	.string "How about it? Let me take you\n"
	.string "on.$"

Route25_Text_CooltrainerKevinBeaten:
	.string "I've never had a battle this\n"
	.string "good!$"

Route25_Text_CooltrainerKevinAfter:
	.string "That was a great battle!\p"
	.string "You and your POKéMON are truly\n"
	.string "outstanding!$"

Route25_Text_BillsHouseSign:
	.string "SEA COTTAGE\n"
	.string "BILL'S HOUSE$"

