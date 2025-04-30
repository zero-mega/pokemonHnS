CherrygroveCity_MapScripts::
	.byte 0

CherryGroveCity_EventScript_Fisherman::
	lock
	faceplayer
	msgbox CherrygroveCity_Text_MysticWaterGuyBefore, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, CherryGroveCity_EventScript_Fisherman2
	closemessage
	release
	end

CherryGroveCity_EventScript_Fisherman2::
	msgbox CherrygroveCity_Text_MysticWaterGuyAfter, MSGBOX_DEFAULT
	waitmessage
	release
	end

CherryGroveCity_EventScript_Lass::

CherryGroveCity_EventScript_Boy::
	lock
	faceplayer
	msgbox
	closemessage
	release
	end

CherryGroveCity_EventScript_Corsola::
	lock
	faceplayer
	msgbox CherryGroveCity_Text_Corsola, MSGBOX_DEFAULT
	playmoncry SPECIES_CORSOLA, CRY_MODE_NORMAL
	delay 40
	waitmoncry
	closemessage
	end

CherryGroveCity_EventScript_Krabby::
	lock
	faceplayer
	msgbox CherryGroveCity_Text_Krabby, MSGBOX_DEFAULT
	playmoncry SPECIES_KRABBY, CRY_MODE_NORMAL
	delay 40
	waitmoncry
	closemessage
	end

CherrygroveCity_Text_GuideGentIntro:
	.string "You're a rookie trainer,\n"
	.string "aren't you? I can tell!\p"
	.string "That's OK! Everyone is a\n"
	.string "rookie at some point!\p"
	.string "If you'd like, I can teach\n"
	.string "you a few things.$"

CherrygroveCity_Text_GuideGentTourStart:
	.string "OK, then!\n"
	.string "Follow me!$"

CherrygroveCity_Text_GuideGentPokecenter:
	.string "This is a POKéMON CENTER.\p"
	.string "They heal your POKéMON in no\n"
	.string "time at all.\p"
	.string "You'll be relying on them a\n"
	.string "lot, so you better learn\p"
	.string "about them.$"

CherrygroveCity_Text_GuideGentMart:
	.string "This is a POKéMON MART.\p"
	.string "They sell BALLS for catching\n"
	.string "wild POKéMON and other\p"
	.string "useful items.$"

CherrygroveCity_Text_GuideGentRoute30:
	.string "ROUTE 30 is out this way.\p"
	.string "Trainers will be battling\n"
	.string "their prized POKéMON there.$"

CherrygroveCity_Text_GuideGentSea:
	.string "This is the sea, as you can\n"
	.string "see.\p"
	.string "Some POKéMON are found only\n"
	.string "in water.$"

CherrygroveCity_Text_GuideGentGift:
	.string "Here…\p"
	.string "It's my house! Thanks for\n"
	.string "your company.\p"
	.string "Let me give you a small gift.$"

CherrygroveCity_Text_GotMapCard:
	.string "{PLAYER}'s POKéGEAR now has\n"
	.string "a MAP!$"

CherrygroveCity_Text_GuideGentPokegear:
	.string "POKéGEAR becomes more useful\n"
	.string "as you add CARDS.\p"
	.string "I wish you luck on your\n"
	.string "journey!$"

CherrygroveCity_Text_GuideGentDecline:
	.string "Oh… It's something I enjoy\n"
	.string "doing…\p"
	.string "Fine. Come see me whenever\n"
	.string "you like.$"

CherrygroveCity_Text_RivalSeen:
	.string "<……> <……> <……>\p"
	.string "You got a POKéMON at the LAB.\p"
	.string "What a waste.\n"
	.string "A wimp like you.\p"
	.string "<……> <……> <……>\p"
	.string "Don't you get what I'm\n"
	.string "saying?\p"
	.string "Well, I too, have a good\n"
	.string "POKéMON.\p"
	.string "I'll show you what I mean!$"

CherrygroveCity_Text_SilverWin:
	.string "Humph. Are you happy you won?$"

CherrygroveCity_Text_RivalYouLost:
	.string "<……> <……> <……>\p"
	.string "My name's ???.\p"
	.string "I'm going to be the world's\n"
	.string "greatest POKéMON trainer.$"

CherrygroveCity_Text_SilverLoss:
	.string "Humph. That was a waste of\n"
	.string "time.$"

CherrygroveCity_Text_RivalYouWon:
	.string "<……> <……> <……>\p"
	.string "My name's ???.\p"
	.string "I'm going to be the world's\n"
	.string "greatest POKéMON trainer.$"

CherrygroveCity_Text_TeacherNoMapCard:
	.string "Did you talk to the old man\n"
	.string "by the POKéMON CENTER?\p"
	.string "He'll put a MAP of JOHTO on\n"
	.string "your POKéGEAR.$"

CherrygroveCity_Text_TeacherHaveMapCard:
	.string "When you're with POKéMON,\n"
	.string "going anywhere is fun.$"

CherrygroveCity_Text_YoungsterNoPokedex:
	.string "MR. POKéMON's house is still\n"
	.string "farther up ahead.$"

CherrygroveCity_Text_YoungsterHavePokedex:
	.string "I battled the trainers on the\n"
	.string "road.\p"
	.string "My POKéMON lost. They're a\n"
	.string "mess! I must take them to a\p"
	.string "POKéMON CENTER.$"

CherrygroveCity_Text_MysticWaterGuyBefore:
	.string "A POKéMON I caught had an\n"
	.string "item.\p"
	.string "I think it's MYSTIC WATER.\p"
	.string "I don't need it, so do you\n"
	.string "want it?$"

CherrygroveCity_Text_MysticWaterGuyAfter:
	.string "Back to fishing for me, then.$"

CherrygroveCity_Text_CitySign:
	.string "CHERRYGROVE CITY\p"
	.string "The City of Cute, Fragrant\n"
	.string "Flowers$"

CherrygroveCity_Text_GuideGentsHouseSign:
	.string "GUIDE GENT'S HOUSE$"

CherryGroveCity_Text_Corsola:
	.string "CORSOLA! LA!$"

CherryGroveCity_Text_Krabby:
	.string "KOOOKEEE$"
