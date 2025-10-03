.set LOCALID_NURSE, 1

MahoganyTown_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MahoganyTown_PokemonCenter_OnTransition
	.byte 0

MahoganyTown_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_MAHOGANYTOWN
	end

MahoganyTown_PokemonCenter_EventScript_Hiker::
	msgbox MahoganyTown_PokemonCenter_Text_PokefanM, MSGBOX_NPC
	end
	
MahoganyTown_PokemonCenter_EventScript_Boy::
	msgbox MahoganyTown_PokemonCenter_Text_Youngster, MSGBOX_NPC
	end

MahoganyTown_PokemonCenter_EventScript_Girl::
	msgbox MahoganyTown_PokemonCenter_Text_CooltrainerF, MSGBOX_NPC
	end

MahoganyTown_PokemonCenter_Text_PokefanM:
    .string "Quoi ? LA TEAM ROCKET est de retour ?\n"
    .string "\p"
    .string "J'ai vu des hommes en noir au LAC\n"
    .string "COLÈRE…$"

MahoganyTown_PokemonCenter_Text_Youngster:
    .string "J'empêche mes POKéMON d'évoluer trop\n"
    .string "tôt.\p"
    .string "Je leur fais apprendre certaines\n"
    .string "capacités avant de les faire évoluer.$"

MahoganyTown_PokemonCenter_Text_CooltrainerF:
    .string "Les POKéMON deviennent plus forts\n"
    .string "quand ils évoluent,\p"
    .string "mais ils apprennent aussi des attaques\n"
    .string "plus lentement.$"
