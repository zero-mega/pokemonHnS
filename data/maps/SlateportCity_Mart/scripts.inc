SlateportCity_Mart_MapScripts::
	.byte 0

SlateportCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart 0
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

SlateportCity_Mart_EventScript_Clerk2::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	goto_if_unset FLAG_RECEIVED_EXP_SHARE, SlateportCity_Mart_EventScript_ClerkNoExp
	pokemart SlateportCity_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_Mart_Pokemart:
	.2byte ITEM_HARBOR_MAIL
	.2byte ITEM_EXP_SHARE_SMALL
	.2byte ITEM_NONE
	release
	end

SlateportCity_Mart_EventScript_ClerkNoExp::
	pokemart SlateportCity_Mart_PokemartNoExp
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_Mart_PokemartNoExp:
	.2byte ITEM_HARBOR_MAIL
	.2byte ITEM_NONE
	release
	end

SlateportCity_Mart_EventScript_BlackBelt::
	msgbox SlateportCity_Mart_Text_SomeItemsOnlyAtMart, MSGBOX_NPC
	end

SlateportCity_Mart_EventScript_Man::
	msgbox SlateportCity_Mart_Text_GreatBallIsBetter, MSGBOX_NPC
	end

SlateportCity_Mart_Text_SomeItemsOnlyAtMart:
	.string "Le MARCHÉ propose des articles\n"
	.string "intéressants.\p"
	.string "Mais certains objets ne sont disponibles\n"
	.string "qu'à la BOUTIQUE POKéMON.$"

SlateportCity_Mart_Text_GreatBallIsBetter:
	.string "Une SUPER BALL est meilleure qu'une\n"
	.string "POKé BALL pour attraper des POKéMON.\p"
	.string "Avec ça, je devrais pouvoir attraper ce\n"
	.string "POKéMON insaisissable…$"
