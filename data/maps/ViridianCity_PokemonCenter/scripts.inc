.set LOCALID_NURSE, 1

ViridianCity_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ViridianCity_PokemonCenter_OnTransition
	.byte 0

ViridianCity_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_VIRIDIAN_CITY
	end

ViridianCity_PokemonCenter_EventScript_CooltrainerM::
	goto_if_set FLAG_HIDE_CINNABAR_BLUE, VirianCity_EventScript_GymGrampsBlue
	msgbox ViridianCity_PokemonCenter_Text_1FCooltrainerM, MSGBOX_NPC
	end

ViridianCity_PokemonCenter_EventScript_CooltrainerMBlue::
	msgbox ViridianCity_PokemonCenter_Text_1FCooltrainerM_BlueReturned, MSGBOX_NPC
	end

ViridianCity_PokemonCenter_EventScript_CooltrainerF::
	msgbox ViridianCity_PokemonCenter_Text_1FCooltrainerF, MSGBOX_NPC
	end

ViridianCity_PokemonCenter_EventScript_BugCatcher::
	msgbox ViridianCity_PokemonCenter_Text_1FBugCatcher, MSGBOX_NPC
	end

ViridianCity_PokemonCenter_Text_1FCooltrainerM:
	.string "Où diable se trouve le CHAMPION\n"
	.string "de l'ARÈNE DE JADIELLE ? Je voulais le défier.$"

ViridianCity_PokemonCenter_Text_1FCooltrainerM_BlueReturned:
	.string "Il n'y a pas de DRESSEURS D'ARÈNE à\n"
	.string "l'ARÈNE DE JADIELLE.\p"
	.string "Le CHAMPION prétend que sa politique\n"
	.string "est de gagner sans avoir de subordonnés.$"

ViridianCity_PokemonCenter_Text_1FCooltrainerF:
	.string "J'ai entendu dire que l'ARÈNE de CANNELAGE\n"
	.string "a disparu.\p"
	.string "Je me demande ce qui est arrivé à AUGUSTE,\n"
	.string "le CHAMPION D'ARÈNE.$"

ViridianCity_PokemonCenter_Text_1FBugCatcher:
	.string "Mon rêve est de devenir CHAMPION D'ARÈNE.$"
