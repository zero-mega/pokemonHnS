.set LOCALID_NURSE, 1

CeruleanCity_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeruleanCity_PokemonCenter_OnTransition
	.byte 0

CeruleanCity_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_CERULEAN_CITY
	end

CeruleanCity_PokemonCenter_EventScript_Nerd::
	msgbox CeruleanCity_PokemonCenter1F_Text_SuperNerd, MSGBOX_NPC
	end

CeruleanCity_PokemonCenter_EventScript_Guy::
	msgbox CeruleanCity_PokemonCenter1F_Text_GymGuide, MSGBOX_NPC
	end

CeruleanCity_PokemonCenter1F_Text_SuperNerd:
	.string "Pour les combats, je préfère utiliser\n"
	.string "des POKéMON que j'ai élevés, même si\p"
	.string "ils sont plus faibles que certains\n"
	.string "POKéMON nouvellement attrapés.$"

CeruleanCity_PokemonCenter1F_Text_GymGuide:
	.string "Le TRAIN MAGNÉTIQUE roule à plus de\n"
	.string "550 km/h. Il va de KANTO à JOHTO\l"
	.string "en un rien de temps.\p"
	.string "Ça rend JOHTO vraiment accessible.$"
