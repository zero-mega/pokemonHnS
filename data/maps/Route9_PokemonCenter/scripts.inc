.set LOCALID_NURSE, 1

Route9_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

Route9_PokemonCenter_EventScript_Engineer1::
	msgbox Route9_PokemonCenter_Text_Engineer1, MSGBOX_NPC
	end

Route9_PokemonCenter_EventScript_Engineer2::
	msgbox Route9_PokemonCenter_Text_Engineer2, MSGBOX_NPC
	end

Route9_PokemonCenter_Text_Engineer1:
	.string "Parfois, nous les ingénieurs venons ici\n"
	.string "pour faire une pause. Ou juste pour\l"
	.string "échapper à notre CHEF.\p"
	.string "Ce type est fou.$"

Route9_PokemonCenter_Text_Engineer2:
	.string "La CENTRALE est très isolée, alors\n"
	.string "je fais beaucoup de route pour le travail.$"