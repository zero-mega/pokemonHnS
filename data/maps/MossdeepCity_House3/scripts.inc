MossdeepCity_House3_MapScripts::
	.byte 0

MossdeepCity_House3_EventScript_SuperRodFisherman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_SUPER_ROD, MossdeepCity_House3_EventScript_ReceivedSuperRod
	msgbox MossdeepCity_House3_Text_YouWantSuperRod, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MossdeepCity_House3_EventScript_DeclineSuperRod
	msgbox MossdeepCity_House3_Text_SuperRodIsSuper, MSGBOX_DEFAULT
	giveitem ITEM_SUPER_ROD
	setflag FLAG_RECEIVED_SUPER_ROD
	msgbox MossdeepCity_House3_Text_TryDroppingRodInWater, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House3_EventScript_ReceivedSuperRod::
	msgbox MossdeepCity_House3_Text_GoAfterSeafloorPokemon, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House3_EventScript_DeclineSuperRod::
	msgbox MossdeepCity_House3_Text_DontYouLikeToFish, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House3_Text_YouWantSuperRod:
	.string "Salut, DRESSEUR !\n"
	.string "Une SUPER CANNE, c'est vraiment super !\p"
	.string "Dis ce que tu veux, mais ce bijou peut\n"
	.string "attraper des POKéMON au fond de la mer !\p"
	.string "Qu'en penses-tu ?\n"
	.string "Tu la veux, n'est-ce pas ?$"

MossdeepCity_House3_Text_SuperRodIsSuper:
	.string "Bien sûr, bien sûr !\n"
	.string "Après tout, une SUPER CANNE, c'est vraiment super !$"

MossdeepCity_House3_Text_TryDroppingRodInWater:
	.string "S'il y a de l'eau, essaie de lancer\n"
	.string "ta CANNE et vois ce qui mord !$"

MossdeepCity_House3_Text_DontYouLikeToFish:
	.string "Hein ?\n"
	.string "Tu n'aimes pas pêcher ?$"

MossdeepCity_House3_Text_GoAfterSeafloorPokemon:
	.string "Pars à la recherche des POKéMON du fond\n"
	.string "de la mer avec ta SUPER CANNE.$"
