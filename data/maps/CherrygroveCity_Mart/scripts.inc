CherrygroveCity_Mart_MapScripts::
	.byte 0

Cherrygrove_Pokemart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	goto_if_ge VAR_NEWBARK_TOWN_STATE, 5, Cherrygrove_Pokemart_EventScript_Clerk2
	pokemart Cherrygrove_Pokemart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

Cherrygrove_Pokemart_EventScript_Youngster::
	lock
	faceplayer
	msgbox Cherrygrove_Pokemart_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end

Cherrygrove_Pokemart_EventScript_Bugcatcher::
	lock
	faceplayer
	goto_if_eq VAR_NEWBARK_TOWN_STATE, 5, Cherrygrove_Pokemart_EventScript_Bugcatcher2
	msgbox Cherrygrove_Pokemart_Text_CooltrainerM, MSGBOX_DEFAULT
	closemessage
	release
	end
	
Cherrygrove_Pokemart_EventScript_Bugcatcher2::
	msgbox Cherrygrove_Pokemart_Text_CooltrainerM_PokeBallsInStock, MSGBOX_DEFAULT
	closemessage
	release
	end

Cherrygrove_Pokemart_EventScript_Clerk2::
	pokemart 0
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 3
Cherrygrove_Pokemart_Pokemart:
	.2byte ITEM_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_NONE
	release
	end

Cherrygrove_Pokemart_Text_CooltrainerM:
	.string "Ils sont à court de POKé BALLS !\p"
	.string "Quand en auront-ils de nouveau ?$"

Cherrygrove_Pokemart_Text_CooltrainerM_PokeBallsInStock:
	.string "Des POKé BALLS sont en stock !\n"
	.string "Je peux enfin attraper des POKéMON !$"

Cherrygrove_Pokemart_Text_Youngster:
	.string "Quand je marchais dans l'herbe, un\n"
	.string "POKéMON insecte a empoisonné mon POKéMON !\p"
	.string "J'ai continué, mais ensuite mon\n"
	.string "POKéMON s'est évanoui.\p"
	.string "Tu devrais toujours avoir un ANTIDOTE\n"
	.string "sur toi.$"
