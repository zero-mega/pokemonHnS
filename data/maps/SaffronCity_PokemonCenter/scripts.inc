.set LOCALID_NURSE, 1

SaffronCity_PokemonCenter_MapScripts::
map_script MAP_SCRIPT_ON_TRANSITION, SaffronCity_PokemonCenter_OnTransition
	.byte 0

SaffronCity_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_SAFFRON_CITY
	end

SaffronCity_PokemonCenter_EventScript_Teacher::
	msgbox SaffronCity_PokemonCenter1F_Text_Teacher, MSGBOX_NPC	
	end

SaffronCity_PokemonCenter_EventScript_Fisher::
	goto_if_set FLAG_RETURNED_MACHINE_PART, SaffronCity_PokemonCenter_EventScript_FisherReturnedMachinePart
	msgbox SaffronCity_PokemonCenter1F_Text_Fisher, MSGBOX_NPC	
	end
SaffronCity_PokemonCenter_EventScript_FisherReturnedMachinePart::
	msgbox SaffronCity_PokemonCenter1F_Text_Fisher_ReturnedPart, MSGBOX_NPC
	end

SaffronCity_PokemonCenter_EventScript_Youngster::
	msgbox SaffronCity_PokemonCenter1F_Text_Youngster, MSGBOX_NPC
	end

SaffronCity_PokemonCenter1F_Text_Teacher:
	.string "À quoi ressemblent les CENTRES\n"
	.string "POKéMON de JOHTO ?\p"
	.string "…Ah, je vois. Donc ils ne sont pas\n"
	.string "très différents de ceux de KANTO.\p"
	.string "Je peux aller à JOHTO sans\n"
	.string "m'inquiéter, alors !$"

SaffronCity_PokemonCenter1F_Text_Fisher:
	.string "Je viens juste de traverser la\n"
	.string "GROTTE.\p"
	.string "Il y avait de l'agitation à la\n"
	.string "CENTRALE.$"

SaffronCity_PokemonCenter1F_Text_Fisher_ReturnedPart:
	.string "Il y a une grotte étrange à AZURIA.\p"
	.string "En tant que pro de la RANDONNÉE, je\n"
	.string "devrais l'explorer, mais cet endroit\n"
	.string "me fait même peur à moi.$"

SaffronCity_PokemonCenter1F_Text_Youngster:
	.string "Le SIÈGE de la SYLPHE SARL et la\n"
	.string "GARE DU TRAIN MAGNÉTIQUE--ce sont\l"
	.string "les lieux à voir à SAFRANIA.$"
