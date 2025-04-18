RuinsOfAlphOffice_MapScripts::
	.byte 0


RuinsOfAlphOffice_EventScript_Scientist1::
	lock
	faceplayer
	msgbox RuinsOfAlphOffice_Text_Scientist1, MSGBOX_DEFAULT
	release
	end
RuinsOfAlphOffice_EventScript_Scientist2::
	lock
	faceplayer
	msgbox RuinsOfAlphOffice_Text_Scientist2, MSGBOX_DEFAULT
	release
	end
RuinsOfAlphOffice_Text_Scientist1:
	.string "The RUINS are about 1500 years old.\p"
	.string "But it's not known why they were\n"
	.string "built--or by whom.$"

RuinsOfAlphOffice_Text_Scientist2:
	.string "There are odd patterns drawn on\n"
	.string "on the walls of the RUINS.\p"
	.string "They must be the keys for\n"
	.string "unraveling the mystery of the\p"
	.string "RUINS.$"
