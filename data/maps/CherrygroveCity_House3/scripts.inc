CherrygroveCity_House3_MapScripts::
	.byte 0

CherrygroveCity_House3_EventScript_Boy::
	lock
	faceplayer
	msgbox CherrygroveCity_EvolutionHouse_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end

CherrygroveCity_House3_EventScript_Girl::
	lock
	faceplayer
	msgbox CherrygroveCity_EvolutionHouse_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

CherrygroveCity_EvolutionHouse_Text_Youngster:
	.string "Les POKéMON gagnent de l'expérience\n"
	.string "en combat et changent de forme.$"

CherrygroveCity_EvolutionHouse_Text_Lass:
	.string "Les POKéMON changent ?\p"
	.string "Je serais choquée si l'un d'eux\n"
	.string "faisait ça !$"
