MossdeepCity_Mart_MapScripts::
	.byte 0

MossdeepCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart 0
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

MossdeepCity_Mart_EventScript_Clerk2::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart MossdeepCity_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
MossdeepCity_Mart_Pokemart:
	.2byte ITEM_NET_BALL
	.2byte ITEM_DIVE_BALL
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFEND
	.2byte ITEM_NONE
	release
	end

MossdeepCity_Mart_EventScript_Woman::
	msgbox MossdeepCity_Mart_Text_ReviveIsFantastic, MSGBOX_NPC
	end

MossdeepCity_Mart_EventScript_Boy::
	msgbox MossdeepCity_Mart_Text_MaxRepelLastsLongest, MSGBOX_NPC
	end

MossdeepCity_Mart_EventScript_Sailor::
	msgbox MossdeepCity_Mart_Text_NetAndDiveBallsRare, MSGBOX_NPC
	end

MossdeepCity_Mart_Text_ReviveIsFantastic:
	.string "La RÉVIVE est fantastique !\p"
	.string "Donnez-la à un POKéMON K.O.,\n"
	.string "et il reviendra à la vie.\p"
	.string "Mais attention, la RÉVIVE ne restaure pas\n"
	.string "les PP utilisés des capacités.$"

MossdeepCity_Mart_Text_MaxRepelLastsLongest:
	.string "Le MAX REPOUSSE éloigne tous les POKéMON faibles.\p"
	.string "Parmi tous les sprays REPOUSSE, il dure\n"
	.string "le plus longtemps.$"

MossdeepCity_Mart_Text_NetAndDiveBallsRare:
	.string "Les FILET et SCUBA BALL sont des POKé BALLS rares\n"
	.string "fabriquées uniquement à ALGATIA.\p"
	.string "Une FILET BALL est efficace contre\n"
	.string "les POKéMON de type INSECTE et EAU.\p"
	.string "Une SCUBA BALL marche mieux sur les POKéMON\n"
	.string "au fond de la mer.$"
