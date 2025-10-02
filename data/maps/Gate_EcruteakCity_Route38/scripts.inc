Gate_EcruteakCity_Route38_MapScripts::
	.byte 0

Route38_EventScript_Officer::
	lock
	faceplayer
	msgbox Route38_Text_EcruteakGateOfficer, MSGBOX_DEFAULT
	closemessage
	release
	end

Route38_Text_EcruteakGateOfficer:
	.string "D'où as-tu dit que tu viens ?\p"
	.string "BOURG GEON ?\p"
	.string "Le PROF.ORME habite là-bas,\n"
	.string "n'est-ce pas ?\p"
	.string "Tu as fait un long chemin pour\n"
	.string "arriver ici.$"
