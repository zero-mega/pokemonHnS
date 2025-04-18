RuinsOfAlph1_MapScripts::
	.byte 0

RuinsOfAlph1_EventScript_Teacher::
	lock
	faceplayer
	msgbox RuinsOfAlph1_Text_Teacher, MSGBOX_DEFAULT
	release
	end

RuinsOfAlph1_EventScript_Hiker::
	lock
	faceplayer
	msgbox RuinsOfAlph1_Text_Hiker, MSGBOX_DEFAULT
	release
	end

RuinsOfAlph1_EventScript_Gramps::
	lock
	faceplayer
	msgbox RuinsOfAlph1_Text_Gramps, MSGBOX_DEFAULT
	release
	end


RuinsOfAlph1_Text_Hiker:
	.string "This is a big room, but there's\n"
	.string "nothing here.$"

RuinsOfAlph1_Text_Teacher:
	.string "This place has a mystical\n"
	.string "quality to it.\p"
	.string "It feels sort of ethereal\n"
	.string "even.$"

RuinsOfAlph1_Text_Gramps:
	.string "Ancient buildings are often\n"
	.string "tombs of kings.\p"
	.string "Like the pyramids, for\n"
	.string "instance.$"
