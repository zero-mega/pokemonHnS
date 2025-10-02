Gate_Route29_Route46_MapScripts::
	.byte 0

Gate_Route29_Route46_EventScript_Officer::
	lock
	faceplayer
	msgbox Gate_Route29_Route46_Text_Officer, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_Route29_Route46_EventScript_Youngster::
	lock
	faceplayer
	msgbox Gate_Route29_Route46_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_Route29_Route46_Text_Officer:
	.string "Tu ne peux pas escalader les rebords.\p"
	.string "Mais tu peux sauter en bas\n"
	.string "pour prendre un raccourci.$"

Gate_Route29_Route46_Text_Youngster:
	.string "Différents types de POKéMON\n"
	.string "apparaissent après ici.\p"
	.string "Si tu veux tous les attraper,\n"
	.string "il faut chercher partout.$"
