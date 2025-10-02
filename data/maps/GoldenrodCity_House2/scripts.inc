GoldenrodCity_House2_MapScripts::
	.byte 0

GoldenrodCity_House2_EventScript_Man::
	faceplayer
	lock
	msgbox GoldenrodPPSpeechHouse_Text_Man, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_House2_EventScript_Woman::
	faceplayer
	lock
	msgbox GoldenrodPPSpeechHouse_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodPPSpeechHouse_Text_Man:
    .string "Une fois, pendant un combat, mon\n"
    .string "POKéMON ne pouvait plus attaquer.\p"
    .string "Les POINTS DE POUVOIR, ou PP, de\n"
    .string "ses capacités étaient tous épuisés.$"

GoldenrodPPSpeechHouse_Text_Lass:
    .string "Parfois, un POKéMON en bonne santé\n"
    .string "peut ne plus pouvoir utiliser ses attaques.\p"
    .string "Si cela arrive, soigne-le dans un\n"
    .string "CENTRE POKéMON ou utilise un objet.$"
