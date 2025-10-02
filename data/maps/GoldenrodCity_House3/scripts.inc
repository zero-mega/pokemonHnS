GoldenrodCity_House3_MapScripts::
	.byte 0

GoldenrodCity_House3_EventScript_PokefanM::
	lock
	faceplayer
	msgbox GoldenrodHappinessRater_Text_PokefanM, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_House3_EventScript_Twin::
	lock
	faceplayer
	msgbox GoldenrodHappinessRater_Text_Twin, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodHappinessRater_Text_PokefanM:
    .string "Je perds tout le temps en combat, et\n"
    .string "mes POKéMON finissent K.O.…\p"
    .string "C'est peut-être pour ça que mes\n"
    .string "POKéMON ne m'aiment pas trop…$"

GoldenrodHappinessRater_Text_Twin:
    .string "Quand j'utilise un objet sur mon\n"
    .string "POKéMON, il a l'air très content !$"
