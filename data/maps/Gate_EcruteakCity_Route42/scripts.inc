Gate_EcruteakCity_Route42_MapScripts::
	.byte 0

Gate_EcruteakCity_Route42_EventScript_Policeman::
	lock
	faceplayer
	msgbox Route42_Text_EcruteakGateOfficer, MSGBOX_DEFAULT
	closemessage
	release
	end

Route42_Text_EcruteakGateOfficer:
	.string "Le MT.MORTAR est comme un labyrinthe\n"
	.string "à l'intérieur.\p"
	.string "Fais attention. Ne te perds pas\n"
	.string "là-dedans.$"
