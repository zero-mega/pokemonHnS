MahoganyTown_House1_MapScripts::
	.byte 0

MahoganyTown_House1_EventScript_BlackBelt::
	msgbox MahoganyRedGyaradosHouse_Text_BlackBelt, MSGBOX_NPC
	end

MahoganyTown_House1_EventScript_Teacher::
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 5, MahoganyTown_House1_EventScript_TeacherBeforeAfter
	goto_if_lt VAR_GOLDENROD_CITY_STATE, 14, MahoganyTown_House1_EventScript_TeacherDuring
MahoganyTown_House1_EventScript_TeacherBeforeAfter::
	msgbox MahoganyRedGyaradosHouse_Text_Teacher MSGBOX_NPC
	end

MahoganyTown_House1_EventScript_TeacherDuring::
	msgbox MahoganyRedGyaradosHouse_Text_Teacher_Rockets, MSGBOX_NPC
	end


MahoganyRedGyaradosHouse_Text_BlackBelt:
    .string "J'ai entendu dire qu'un GYARADOS rouge\n"
    .string "est apparu au LAC.\p"
    .string "C'est étrange, car même les GYARADOS\n"
    .string "ordinaires sont rares dans ce lac…$"

MahoganyRedGyaradosHouse_Text_Teacher:
    .string "Mon émission de radio préférée ? Je dirais\n"
    .string "POKéMON MUSIQUE.$"

MahoganyRedGyaradosHouse_Text_Teacher_Rockets:
    .string "J'entends des rires à la radio…\p"
    .string "C'est inquiétant.$"
