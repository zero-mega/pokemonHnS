.set LOCALID_NURSE, 1

LavenderTown_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavenderTown_PokemonCenter_OnTransition
	.byte 0

LavenderTown_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_LAVENDER_TOWN
	end

LavenderTown_PokemonCenter_EventScript_Gent::
	msgbox LavenderTown_PokemonCenter1F_Text_Gentleman, MSGBOX_NPC
	end

LavenderTown_PokemonCenter_EventScript_Teacher::
	msgbox LavenderTown_PokemonCenter1F_Text_Teacher, MSGBOX_NPC
	end

LavenderTown_PokemonCenter_EventScript_Youngster::
	goto_if_set FLAG_RETURNED_MACHINE_PART, LavenderTown_PokemonCenter_EventScript_YoungsterReturnedMachinePart
	msgbox LavenderTown_PokemonCenter1F_Text_Youngster, MSGBOX_NPC
	end

LavenderTown_PokemonCenter_EventScript_YoungsterReturnedMachinePart::
	msgbox LavenderTown_PokemonCenter1F_Text_Youngster_ReturnedMachinePart, MSGBOX_NPC
	end

LavenderTown_PokemonCenter1F_Text_Gentleman:
	.string "Au nord de LAVANVILLE se trouve la\n"
	.string "GROTTE. Traverse-la pour aller à la\l"
	.string "CENTRALE ÉLECTRIQUE.$"

LavenderTown_PokemonCenter1F_Text_Teacher:
	.string "Il y a une émission de radio qui passe\n"
	.string "de la musique de la POKé FLÛTE.\p"
	.string "Oh ? Ah, il te faut une CARTE EXPN\n"
	.string "pour pouvoir l'écouter sur ta radio.$"

LavenderTown_PokemonCenter1F_Text_Youngster:
	.string "Si la CENTRALE ÉLECTRIQUE ne marche\n"
	.string "pas, le TRAIN MAGNÉTIQUE ne marche pas\p"
	.string "non plus… Ça veut aussi dire que la\n"
	.string "STATION RADIO ne peut pas émettre…$"

LavenderTown_PokemonCenter1F_Text_Youngster_ReturnedMachinePart:
	.string "Le DIRECTEUR de la STATION RADIO\n"
	.string "était vraiment content.\p"
	.string "Il a dit qu'ils pouvaient à nouveau\n"
	.string "émettre car la CENTRALE ÉLECTRIQUE\l"
	.string "fonctionne de nouveau.$"
