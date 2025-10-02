AzaleaTown_Mart_MapScripts::
	.byte 0

AzaleaTown_Mart_EventScriptCooltrainerM::
	lock
	faceplayer
	msgbox AzaleaMart_Text_CooltrainerM, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_Mart_EventScriptBugCatcher::
	lock
	faceplayer
	msgbox AzaleaMart_Text_BugCatcher, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaMart_Text_CooltrainerM:
	.string "Tu peux acheter une SUPER BALL ?\n"
	.string "Moi, je ne peux acheter que des POKé BALL.\p"
	.string "J'ai entendu dire que plus tu gagnes\n"
	.string "de BADGES, plus il y a d'objets\l"
	.string "disponibles en boutique !\p"
	.string "J'aimerais bien que FARGAS me fabrique\n"
	.string "ses BALLS spéciales.$"

AzaleaMart_Text_BugCatcher:
	.string "Une SUPER BALL est meilleure pour\n"
	.string "attraper des POKéMON qu'une POKé BALL.\p"
	.string "Mais celles de FARGAS sont parfois\n"
	.string "encore meilleures.$"
