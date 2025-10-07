.set LOCALID_NURSE, 1

PewterCity_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PewterCity_PokemonCenter_OnTransition
	.byte 0

PewterCity_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_PEWTER_CITY
	end

PewterCity_PokemonCenter_EventScript_Teacher::
	msgbox PewterCity_PokemonCenter1F_Text_Teacher, MSGBOX_NPC
	end

PewterCity_PokemonCenter_EventScript_BugCatcher::
	msgbox PewterCity_PokemonCenter1F_Text_BugCatcher, MSGBOX_NPC
	end

PewterCity_PokemonCenter1F_Text_Teacher:
	.string "…Oui, et l'ARÈNE de CINNABAR a disparu.\p"
	.string "J'étais vraiment étonnée.\p"
	.string "…Oui ? Je suis au téléphone. Va-t'en !$"

PewterCity_PokemonCenter1F_Text_Jigglypuff:
	.string "RONDOUDOU : Pouu poupouu.$"

PewterCity_PokemonCenter1F_Text_BugCatcher:
	.string "La plupart des POKéMON deviennent somnolents\n"
	.string "s'ils entendent un RONDOUDOU chanter.\p"
	.string "Il y a plusieurs capacités qui ne peuvent être\n"
	.string "utilisées que lorsqu'un POKéMON dort.$"
