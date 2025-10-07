Route2_House_MapScripts::
	.byte 0

Route2_House_EventScript_Man::
	lock
	faceplayer
	goto_if_set FLAG_GOT_ROUTE2_NUGGET, Route2_House_EventScript_ManAfter
	msgbox Route2_House_Text_Fisher, MSGBOX_DEFAULT 
	giveitem ITEM_NUGGET
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox Route2_House_Text_Fisher_GotNugget, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_GOT_ROUTE2_NUGGET
	release
	end

Route2_House_EventScript_ManAfter::
	msgbox Route2_House_Text_Fisher_GotNugget, MSGBOX_DEFAULT
	closemessage
	release
	end

Route2_House_Text_Fisher:
	.string "Salut ! Waouh, je suis content de te voir.\p"
	.string "Tu es le premier visiteur que j'ai eu\n"
	.string "depuis longtemps.\p"
	.string "Je suis super heureux ! Laisse-moi te donner\n"
	.string "un petit cadeau.$"

Route2_House_Text_Fisher_GotNugget:
	.string "C'est un MORCEAU D'OR.\p"
	.string "Je ne peux pas te donner de pépites de\n"
	.string "sagesse, alors ça devra suffire !$"
