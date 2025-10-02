.set LOCALID_NURSE, 1

BlackthornCity_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, BlackthornCity_PokemonCenter_OnTransition
	.byte 0

BlackthornCity_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_BLACKTHORN_CITY
	end

BlackthornCity_PokemonCenter_EventScript_Gent::
	msgbox BlackthornCity_PokemonCenter1FGentlemanText, MSGBOX_NPC
	end

BlackthornCity_PokemonCenter_EventScript_Twin::
	msgbox BlackthornCity_PokemonCenter1FTwinText, MSGBOX_NPC
	end

BlackthornCity_PokemonCenter1FGentlemanText:
	.string "Au cœur du lointain PLATEAU\n"
	.string "INDIGO se trouve la LIGUE POKéMON.\p"
	.string "J'ai entendu dire que les meilleurs\n"
	.string "dresseurs du pays s'y rassemblent.$"

BlackthornCity_PokemonCenter1FTwinText:
	.string "Il y avait cette capacité que je\n"
	.string "devais absolument apprendre à mon POKéMON.\p"
	.string "Alors j'ai demandé à l'EFFACEUR de\n"
	.string "capacités d'oublier une CS.$"
