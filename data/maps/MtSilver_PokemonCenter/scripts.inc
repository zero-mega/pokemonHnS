.set LOCALID_NURSE, 1

MtSilver_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtSilver_PokemonCenter_OnTransition
	.byte 0

MtSilver_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_MT_SILVER
	end

MtSilver_PokemonCenter_EventScript_Meara::
	msgbox MtSilver_PokemonCenter_Text_Meara, MSGBOX_NPC
	end

MtSilver_PokemonCenter_Text_Meara:
	.string "Je suis chercheuse au musée de\n"
	.string "la ville d'ARGENTA.\p"
	.string "Une quantité inhabituelle d'artefacts\n"
	.string "a été découverte dans cette région,\l"
	.string "alors je suis venue enquêter.\p"
	.string "Il n'existe aucune trace d'une\n"
	.string "civilisation autour de la montagne,\l"
	.string "mais les artefacts sont presque\n"
	.string "certainement fabriqués par l'homme.\p"
	.string "C'est vraiment très mystérieux.$"
