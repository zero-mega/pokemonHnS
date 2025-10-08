.set LOCALID_NURSE, 1

RustboroCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

RustboroCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_RUSTBORO_CITY
	call Common_EventScript_UpdateBrineyLocation
	end

RustboroCity_PokemonCenter_1F_ProbopassEvo::
	msgbox RustboroCity_PokemonCenter_1F_ProbopassEvo_Text, MSGBOX_NPC
	end

RustboroCity_PokemonCenter_1F_ProbopassEvo_Text:
	.string "TARINOR évolue et change de type\n"
	.string "pour devenir ROC et ACIER.\p"
	.string "Mais pour évoluer, il doit être\n"
	.string "exposé à un champ magnétique fort.\p"
	.string "Il est difficile de trouver un endroit\n"
	.string "comme ça à HOENN, alors les scientifiques\l"
	.string "ont découvert qu’en faisant tenir à\n"
	.string "TARINOR une PIERRE FOUDRE, il évolue\n"
	.string "plus facilement en multipliant son\n"
	.string "propre champ magnétique par deux !\p"
	.string "Je me demande de quoi sont faites\n"
	.string "les PIERRES FOUDRE.$"

RustboroCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

RustboroCity_PokemonCenter_1F_EventScript_Man::
	msgbox RustboroCity_PokemonCenter_1F_Text_PokemonHavePersonalities, MSGBOX_NPC
	end

RustboroCity_PokemonCenter_1F_EventScript_Boy::
	msgbox RustboroCity_PokemonCenter_1F_Text_MaleAndFemalePokemon, MSGBOX_NPC
	end

RustboroCity_PokemonCenter_1F_EventScript_Girl::
	msgbox RustboroCity_PokemonCenter_1F_Text_HMCutNextDoor, MSGBOX_NPC
	end

RustboroCity_PokemonCenter_1F_Text_PokemonHavePersonalities:
	.string "Mon POKéMON a une nature NAÏVE, et celui\n"
	.string "de mon ami a une nature JOVIAL.\p"
	.string "C'est fascinant de voir que les POKéMON\n"
	.string "ont des personnalités !$"

RustboroCity_PokemonCenter_1F_Text_MaleAndFemalePokemon:
	.string "Comme les gens, il y a des POKéMON mâles\n"
	.string "et des POKéMON femelles.\p"
	.string "Mais personne ne semble savoir en quoi\n"
	.string "ils sont différents.$"

RustboroCity_PokemonCenter_1F_Text_HMCutNextDoor:
	.string "L'homme d'à côté m'a donné une CS !\p"
	.string "Je l'ai utilisée pour apprendre à mon\n"
	.string "POKéMON à COUPER les petits arbres.$"

