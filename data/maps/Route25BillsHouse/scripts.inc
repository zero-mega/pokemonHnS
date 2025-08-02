Route25BillsHouse_MapScripts::
	.byte 0


@VAR_BILLS_GRANDPA

Route25BillsHouse_EventScript_Gramps::
	lock
	faceplayer
	goto_if_eq VAR_BILLS_GRANDPA, 1, Route25BillsHouse_EventScript_Gramps_Lickitung
	goto_if_eq VAR_BILLS_GRANDPA, 2, Route25BillsHouse_EventScript_Gramps_Oddish
	goto_if_eq VAR_BILLS_GRANDPA, 3, Route25BillsHouse_EventScript_Gramps_Growlithe
	goto_if_eq VAR_BILLS_GRANDPA, 4, Route25BillsHouse_EventScript_Gramps_Vulpix
	goto_if_eq VAR_BILLS_GRANDPA, 5, Route25BillsHouse_EventScript_Gramps_Pichu
	goto_if_eq VAR_BILLS_GRANDPA, 6, Route25BillsHouse_EventScript_Gramps_ShownAll
	msgbox Route25BillsHouse_Text_GrandpaIntro, MSGBOX_DEFAULT
	setvar VAR_BILLS_GRANDPA, 1
	goto Route25BillsHouse_EventScript_Gramps_Lickitung

Route25BillsHouse_EventScript_Gramps_Declined::
	msgbox Route25BillsHouse_Text_YouDontHaveIt, MSGBOX_DEFAULT
	closemessage
	release
	end

Route25BillsHouse_EventScript_Gramps_WrongMon::
	msgbox Route25BillsHouse_Text_WrongPokemon, MSGBOX_DEFAULT
	closemessage
	release
	end

Route25BillsHouse_EventScript_Gramps_Lickitung::
	msgbox Route25BillsHouse_Text_Lickitung, MSGBOX_DEFAULT
	msgbox Route25BillsHouse_Text_AskToSeeMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, Route25BillsHouse_EventScript_Gramps_Declined
	msgbox Route25BillsHouse_Text_ExcitedToSee, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	@ Store selected slot in VAR_0x800A
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, Route25BillsHouse_EventScript_Gramps_Declined
	@ Get the species of the selected Pokémon
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	@ Check if it's Lickitung
	goto_if_ne VAR_RESULT, SPECIES_LICKITUNG, Route25BillsHouse_EventScript_Gramps_WrongMon
	bufferspeciesname STR_VAR_1, SPECIES_LICKITUNG
	setvar VAR_TEMP_0, ITEM_EVERSTONE
	goto Route25BillsHouse_EventScript_Gramps_Correctmon

Route25BillsHouse_EventScript_Gramps_Oddish::
	msgbox Route25BillsHouse_Text_Oddish, MSGBOX_DEFAULT
	msgbox Route25BillsHouse_Text_AskToSeeMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, Route25BillsHouse_EventScript_Gramps_Declined
	msgbox Route25BillsHouse_Text_ExcitedToSee, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, Route25BillsHouse_EventScript_Gramps_Declined
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, SPECIES_ODDISH, Route25BillsHouse_EventScript_Gramps_WrongMon
	bufferspeciesname STR_VAR_1, SPECIES_ODDISH
	setvar VAR_TEMP_0, ITEM_LEAF_STONE
	goto Route25BillsHouse_EventScript_Gramps_Correctmon

Route25BillsHouse_EventScript_Gramps_Staryu::
	msgbox Route25BillsHouse_Text_Staryu, MSGBOX_DEFAULT
	msgbox Route25BillsHouse_Text_AskToSeeMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, Route25BillsHouse_EventScript_Gramps_Declined
	msgbox Route25BillsHouse_Text_ExcitedToSee, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, Route25BillsHouse_EventScript_Gramps_Declined
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, SPECIES_STARYU, Route25BillsHouse_EventScript_Gramps_WrongMon
	bufferspeciesname STR_VAR_1, SPECIES_STARYU
	setvar VAR_TEMP_0, ITEM_WATER_STONE
	goto Route25BillsHouse_EventScript_Gramps_Correctmon

Route25BillsHouse_EventScript_Gramps_Growlithe::
	msgbox Route25BillsHouse_Text_Growlithe, MSGBOX_DEFAULT
	msgbox Route25BillsHouse_Text_AskToSeeMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, Route25BillsHouse_EventScript_Gramps_Declined
	msgbox Route25BillsHouse_Text_ExcitedToSee, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, Route25BillsHouse_EventScript_Gramps_Declined
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, SPECIES_GROWLITHE, Route25BillsHouse_EventScript_Gramps_WrongMon
	bufferspeciesname STR_VAR_1, SPECIES_GROWLITHE
	setvar VAR_TEMP_0, ITEM_FIRE_STONE
	goto Route25BillsHouse_EventScript_Gramps_Correctmon

Route25BillsHouse_EventScript_Gramps_Vulpix::
	msgbox Route25BillsHouse_Text_Vulpix, MSGBOX_DEFAULT
	msgbox Route25BillsHouse_Text_AskToSeeMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, Route25BillsHouse_EventScript_Gramps_Declined
	msgbox Route25BillsHouse_Text_ExcitedToSee, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, Route25BillsHouse_EventScript_Gramps_Declined
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, SPECIES_VULPIX, Route25BillsHouse_EventScript_Gramps_WrongMon
	bufferspeciesname STR_VAR_1, SPECIES_VULPIX
	setvar VAR_TEMP_0, ITEM_FIRE_STONE
	goto Route25BillsHouse_EventScript_Gramps_Correctmon

Route25BillsHouse_EventScript_Gramps_Pichu::
	msgbox Route25BillsHouse_Text_Pichu, MSGBOX_DEFAULT
	msgbox Route25BillsHouse_Text_AskToSeeMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, Route25BillsHouse_EventScript_Gramps_Declined
	msgbox Route25BillsHouse_Text_ExcitedToSee, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, Route25BillsHouse_EventScript_Gramps_Declined
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, SPECIES_PICHU, Route25BillsHouse_EventScript_Gramps_WrongMon
	bufferspeciesname STR_VAR_1, SPECIES_PICHU
	setvar VAR_TEMP_0, ITEM_THUNDER_STONE
	goto Route25BillsHouse_EventScript_Gramps_Correctmon

Route25BillsHouse_EventScript_Gramps_ShownAll::
	msgbox Route25BillsHouse_Text_ShownAll, MSGBOX_DEFAULT
	closemessage
	release
	end

Route25BillsHouse_EventScript_Gramps_Correctmon::
	msgbox Route25BillsHouse_Text_ShownPokemon, MSGBOX_DEFAULT
	msgbox Route25BillsHouse_Text_Appreciation, MSGBOX_DEFAULT
	giveitem VAR_TEMP_0
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox Route25BillsHouse_Text_ComeAgain, MSGBOX_DEFAULT
	addvar VAR_BILLS_GRANDPA, 1
	closemessage
	release
	end

Route25BillsHouse_Test::
	givemon SPECIES_LICKITUNG, 10
	givemon SPECIES_STARYU, 10
	givemon SPECIES_ODDISH, 10
	givemon SPECIES_VULPIX, 10
	givemon SPECIES_GROWLITHE, 10
	givemon SPECIES_PICHU, 10
	end

Route25BillsHouse_Text_GrandpaIntro:
	.string "Hm? You know BILL? He's my\n"
	.string "grandson.\p"
	.string "He's in JOHTO. He does\n"
	.string "something with PCs, so I'm\l"
	.string "housesitting.$"

Route25BillsHouse_Text_Lickitung:
	.string "My grandson BILL told me about\n"
	.string "a POKéMON that has a\l"
	.string "long tongue.$"

Route25BillsHouse_Text_Oddish:
	.string "Ah, my grandson mentioned a\n"
	.string "round,\l"
	.string "green POKéMON that has leaves\n"
	.string "growing on its head.$"

Route25BillsHouse_Text_Staryu:
	.string "Do you know of a sea POKéMON\n"
	.string "that\l"
	.string "has a red sphere in its body?\p"
	.string "You know, the one that's shaped\n"
	.string "like a star?\p"
	.string "I heard that it appears at\n"
	.string "night.\p"
	.string "I would surely like to see it.$"

Route25BillsHouse_Text_Growlithe:
	.string "BILL told me about a POKéMON\n"
	.string "that is\l"
	.string "very loyal to its trainer.\p"
	.string "It's supposed to ROAR well.$"

Route25BillsHouse_Text_Vulpix:
	.string "I heard about a cute POKéMON\n"
	.string "that has six tails.\p"
	.string "I would love to hug a cute\n"
	.string "POKéMON like that.$"

Route25BillsHouse_Text_Pichu:
	.string "Do you know that hugely popular\n"
	.string "POKéMON?\p"
	.string "The POKéMON that has a yellow\n"
	.string "body and red cheeks.\p"
	.string "I would love to see what it\n"
	.string "looks like before it evolves$"

Route25BillsHouse_Text_AskToSeeMon:
	.string "If you have that POKéMON, may I\n"
	.string "see it, please?$"

Route25BillsHouse_Text_ExcitedToSee:
	.string "You will show me? How good of\n"
	.string "you!$"

Route25BillsHouse_Text_YouDontHaveIt:
	.string "You don't have it?\n"
	.string "That's too bad…$"

Route25BillsHouse_Text_ShownPokemon:
	.string "Ah, so that is {STR_VAR_1}?\p"
	.string "Isn't it cute! That's so kind\n"
	.string "of you.$"

Route25BillsHouse_Text_Appreciation:
	.string "Thanks!\p"
	.string "This is a token of my\n"
	.string "appreciation.$"

Route25BillsHouse_Text_ComeAgain:
	.string "Come visit again sometime.$"

Route25BillsHouse_Text_ShownAll:
	.string "Thanks for showing me so many\n"
	.string "cute POKéMON.\p"
	.string "I really enjoyed myself. I'm\n"
	.string "glad\l"
	.string "I've lived such a long life.$"

Route25BillsHouse_Text_WrongPokemon:
	.string "Hm?\p"
	.string "That's not the POKéMON that I\n"
	.string "was told about.$"


