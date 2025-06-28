MahoganyShop_MapScripts::
	.byte 0

MahoganyShop_EventScript_Granny::
	lock
	faceplayer
	goto_if_ge VAR_MAHOGANY_TOWN_STATE, 11, MahoganyShop_EventScript_GrannyShop @changelater
	msgbox MahoganyShop_Text_Granny, MSGBOX_NPC
	release
	end

MahoganyShop_EventScript_GrannyShop::
	message gText_HowMayIServeYou
	waitmessage
	pokemart MahoganyTown_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
MahoganyTown_Pokemart:
	.2byte ITEM_METAL_COAT
	.2byte ITEM_DRAGON_SCALE
	.2byte ITEM_KINGS_ROCK
	.2byte ITEM_UP_GRADE
	.2byte ITEM_SPELL_TAG
	.2byte ITEM_NEVER_MELT_ICE
	.2byte ITEM_NONE
	release
	end

MahoganyShop_Text_Granny:
	.string "Please come back another time,\n"
	.string "kiddo. The store is... closed\l"
	.string "right now.$"

MahoganyMart1F_Text_RageCandyBar: @ unreferenced
    .string "Hello, kiddo!\p"
    .string "You wouldn't all the things I found\n"
    .string "in the basement!$"

MahoganyMart1F_Text_Pharmacist_Lance:
    .string "Arrgh… You found the secret stair-\n"
    .string "way…$"

MahoganyMart1F_Text_BlackBelt:
    .string "Heheh! The experi- ment worked like\n"
    .string "a charm.\p"
    .string "MAGIKARP are just worthless, but\n"
    .string "GYARADOS are big moneymakers.$"

MahoganyMart1F_Text_BlackBelt_Lance:
    .string "Urrgh…\p"
    .string "That guy's POKéMON are tough…$"

MahoganyMart1F_Text_Lance_HyperBeam:
    .string "LANCE: DRAGONITE, HYPER BEAM.$"

MahoganyMart1F_Text_Lance_Radio:
    .string "What took you, {PLAYER}?\p"
    .string "Just as we thought, that strange\n"
    .string "radio signal is coming from here.$"

MahoganyMart1F_Text_Lance_Stairs:
    .string "The stairs are right here.$"

MahoganyMart1F_Text_Lance_SplitUp:
    .string "LANCE: {PLAYER}, we should split up\n"
    .string "to check this place.\p"
    .string "I'll go first.$"
