.set LOCALID_NURSE, 1

CinnabarIsland_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CinnabarIsland_PokemonCenter_OnTransition
	.byte 0

CinnabarIsland_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_CINNABAR_ISLAND
	end

CinnabarIsland_PokemonCenter_EventScript_Cooltrainer::
	msgbox CinnabarIsland_PokemonCenter1F_Text_CooltrainerF, MSGBOX_NPC
	end

CinnabarIsland_PokemonCenter_EventScript_Fisher::
	msgbox CinnabarIsland_PokemonCenter1F_Text_Fisher, MSGBOX_NPC
	end

CinnabarIsland_PokemonCenter1F_Text_CooltrainerF:
	.string "On dirait que BLAINE de l'ARÈNE de\n"
	.string "CRAMOIS'ÎLE vit seul dans la grotte\n"
	.string "des ÎLES ÉCUME…$"

CinnabarIsland_PokemonCenter1F_Text_Fisher:
	.string "Cela fait un an que le volcan\n"
	.string "est entré en éruption.$"
