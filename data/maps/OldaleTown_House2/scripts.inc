OldaleTown_House2_MapScripts::
	.byte 0

OldaleTown_House2_EventScript_Woman::
	msgbox OldaleTown_House2_Text_PokemonLevelUp, MSGBOX_NPC
	end

OldaleTown_House2_EventScript_Man::
	msgbox OldaleTown_House2_Text_YoullGoFurtherWithStrongPokemon, MSGBOX_NPC
	end

OldaleTown_House2_Text_PokemonLevelUp:
	.string "Quand les POKéMON combattent, ils finissent\n"
	.string "par gagner des niveaux et devenir plus forts.$"

OldaleTown_House2_Text_YoullGoFurtherWithStrongPokemon:
	.string "Si les POKéMON avec toi deviennent\n"
	.string "plus forts, tu pourras aller plus loin\l"
	.string "à partir d'ici.$"

