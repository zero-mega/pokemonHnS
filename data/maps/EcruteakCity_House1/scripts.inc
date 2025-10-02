EcruteakCity_House1_MapScripts::
	.byte 0

EcruteakCity_House1_EventScript_Gramps::
	lock
	faceplayer
	msgbox EcruteakLugiaSpeechHouse_Text_Gramps, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_House1_EventScript_Youngster::
	lock
	faceplayer
	msgbox EcruteakLugiaSpeechHouse_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakLugiaSpeechHouse_Text_Gramps:
	.string "C'est arrivé quand j'étais jeune.\p"
	.string "Le ciel est soudainement devenu noir. Un\n"
	.string "énorme POKéMON volant bloquait\l"
	.string "le soleil.\p"
	.string "Je me demande quel était ce POKéMON ?\p"
	.string "Il ressemblait à un oiseau et à un dragon.$"

EcruteakLugiaSpeechHouse_Text_Youngster:
	.string "Il existe vraiment un POKéMON aussi grand ?\p"
	.string "S'il existe, il doit être puissant.$"
