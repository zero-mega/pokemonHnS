.set LOCALID_NURSE, 1

SootopolisCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SootopolisCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

SootopolisCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_SOOTOPOLIS_CITY
	end

SootopolisCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

SootopolisCity_PokemonCenter_1F_EventScript_Gentleman::
	lock
	faceplayer
	goto_if_ge VAR_SKY_PILLAR_STATE, 2, SootopolisCity_PokemonCenter_1F_EventScript_GentlemanNoLegendaries
	goto_if_unset FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, SootopolisCity_PokemonCenter_1F_EventScript_GentlemanNoLegendaries
	msgbox SootopolisCity_PokemonCenter_1F_Text_EveryoneTakenRefuge, MSGBOX_DEFAULT
	release
	end

SootopolisCity_PokemonCenter_1F_EventScript_GentlemanNoLegendaries::
	msgbox SootopolisCity_PokemonCenter_1F_Text_WallaceToughestInHoenn, MSGBOX_DEFAULT
	release
	end

SootopolisCity_PokemonCenter_1F_EventScript_Woman::
	lock
	faceplayer
	goto_if_ge VAR_SKY_PILLAR_STATE, 2, SootopolisCity_PokemonCenter_1F_EventScript_WomanNoLegendaries
	goto_if_unset FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, SootopolisCity_PokemonCenter_1F_EventScript_WomanNoLegendaries
	msgbox SootopolisCity_PokemonCenter_1F_Text_ArentPokemonOurFriends, MSGBOX_DEFAULT
	release
	end

SootopolisCity_PokemonCenter_1F_EventScript_WomanNoLegendaries::
	msgbox SootopolisCity_PokemonCenter_1F_Text_AlwaysBeFriendsWithPokemon, MSGBOX_DEFAULT
	release
	end

SootopolisCity_PokemonCenter_1F_Text_WallaceToughestInHoenn:
	.string "On raconte que JUAN est le DRESSEUR\n"
	.string "le plus fort de toute la région de HOENN.\p"
	.string "L'ARÈNE de cette ville est dirigée par\n"
	.string "le DRESSEUR qui a formé JUAN.\p"
	.string "Mais le CONSEIL 4… On dit qu'ils sont\n"
	.string "encore plus forts que le mentor de JUAN.\p"
	.string "À quel point peuvent-ils être puissants?$"

SootopolisCity_PokemonCenter_1F_Text_EveryoneTakenRefuge:
	.string "Tous les habitants de la ville se sont\n"
	.string "réfugiés chez eux et n'osent pas sortir.\p"
	.string "Même moi, je préfère ne pas m'aventurer\n"
	.string "dehors.$"

SootopolisCity_PokemonCenter_1F_Text_AlwaysBeFriendsWithPokemon:
	.string "Quoi qu'il arrive, où que j'aille, je serai\n"
	.string "toujours ami avec les POKéMON.\p"
	.string "Parce que c'est amusant d'être avec eux !$"

SootopolisCity_PokemonCenter_1F_Text_ArentPokemonOurFriends:
	.string "Les POKéMON ne sont-ils pas nos amis ?\p"
	.string "Pourquoi deviennent-ils fous comme ça ?$"

