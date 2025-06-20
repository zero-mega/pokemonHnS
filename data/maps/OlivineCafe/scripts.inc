OlivineCafe_MapScripts::
	.byte 0

OlivineCity_EventScript_SailorA::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_STRENGTH, OlivineCity_EventScript_SailorA2
	msgbox OlivineCity_Text_CafeSailorStrength, MSGBOX_DEFAULT
	giveitem ITEM_HM_STRENGTH
	setflag FLAG_RECEIVED_HM_STRENGTH
OlivineCity_EventScript_SailorA2::
	msgbox OlivineCity_Text_CafeSailorGotStrength, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_EventScript_Cook::
	lock
	faceplayer
	msgbox OlivineCity_Text_CafeFishingGuru, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_EventScript_SailorB::
	lock
	faceplayer
	msgbox OlivineCity_Text_CafeSailor, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_Text_CafeSailorStrength:
	.string "Hah! Your POKéMON sure look like\n"
	.string "lightweights!\p"
	.string "They don't have the power to\n"
	.string "move boulders aside.\p"
	.string "Here, use this and teach them\n"
	.string "STRENGTH!$"

OlivineCity_Text_CafeSailorGotStrength:
	.string "On the sea, the only thing you\n"
	.string "can count on is your own self!\p"
	.string "I'm so proud of my buff bod!\n"
	.string "You should train like me!$"

OlivineCity_Text_CafeFishingGuru:
	.string "OLIVINE CAFE's menu is packed\n"
	.string "with hearty fare for beefy\l"
	.string "SAILORS like me!$"

OlivineCity_Text_CafeSailor:
	.string "Whenever I roll into this town,\n"
	.string "I always visit the OLIVINE CAFE.\p"
	.string "Everything on the menu makes me\n"
	.string "feel stronger. I can't stop eating!$"

