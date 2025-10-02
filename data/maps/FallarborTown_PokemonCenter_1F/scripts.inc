.set LOCALID_NURSE, 1
.set LOCALID_Bill, 4

FallarborTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FallarborTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

FallarborTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_FALLARBOR_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

FallarborTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

FallarborTown_PokemonCenter_1F_EventScript_Girl::
	msgbox FallarborTown_PokemonCenter_1F_Text_FossilManiacEdgeOfTown, MSGBOX_NPC
	end

FallarborTown_PokemonCenter_1F_EventScript_ExpertM::
	msgbox FallarborTown_PokemonCenter_1F_Text_PlantHardyTrees, MSGBOX_NPC
	end

FallarborTown_PokemonCenter_1F_EventScript_Bill::
	lock
	faceplayer
	msgbox FallarborTown_PokemonCenter_1F_Text_BillGreeting, MSGBOX_DEFAULT
	closemessage
	switch VAR_FACING
	case DIR_NORTH, FallarborTown_PokemonCenter_1F_EventScript_BillExitNorth
	case DIR_WEST, FallarborTown_PokemonCenter_1F_EventScript_BillExitWest
	end

FallarborTown_PokemonCenter_1F_EventScript_BillExitNorth::
	applymovement LOCALID_Bill, FallarborTown_PokemonCenter_1F_Movement_BillExitNorth
	waitmovement 0
	goto FallarborTown_PokemonCenter_1F_EventScript_BillExited
	end

FallarborTown_PokemonCenter_1F_EventScript_BillExitWest::
	applymovement LOCALID_Bill, FallarborTown_PokemonCenter_1F_Movement_BillExitWest
	waitmovement 0
	goto FallarborTown_PokemonCenter_1F_EventScript_BillExited
	end

FallarborTown_PokemonCenter_1F_EventScript_BillExited::
	playse SE_SLIDING_DOOR
	removeobject LOCALID_Bill
	clearflag FLAG_GARBAGEFLAG
	release
	end

FallarborTown_PokemonCenter_1F_Movement_BillExitNorth:
	walk_right
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	delay_8
	step_end

FallarborTown_PokemonCenter_1F_Movement_BillExitWest:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	delay_8
	step_end

FallarborTown_PokemonCenter_1F_Text_BillGreeting:
	.string "Oh, bonjour.\n"
	.string "Tu es ?\p"
	.string "D'accord, tu t'appelles {PLAYER}{KUN}.\n"
	.string "Je vois que tu es un DRESSEUR.\p"
	.string "Donc, cela veut dire que tu utilises\n"
	.string "le Système de Stockage POKéMON que j'ai développé.\p"
	.string "Comment j'en suis arrivé à cette conclusion ?\n"
	.string "C'est un simple raisonnement déductif.\p"
	.string "Tu m'as parlé parce que tu voulais\n"
	.string "accéder à quelque chose sur ce PC.\p"
	.string "Oh, pardon. Je suis Léo.\p"
	.string "Honnêtement, je suis content de te rencontrer--\n"
	.string "c'est super que tu utilises le Système de Stockage.\p"
	.string "Si tu peux, viens me rendre visite chez moi.\n"
	.string "Ma maison est sur la ROUTE 114.$"

FallarborTown_PokemonCenter_1F_Text_FossilManiacEdgeOfTown:
	.string "Je me demande à quoi ressemblaient les POKéMON\n"
	.string "il y a très, très longtemps ?\p"
	.string "Peut-être que le MANIAQUE DES FOSSILES\n"
	.string "au bout de la ville le saura.$"

FallarborTown_PokemonCenter_1F_Text_PlantHardyTrees:
	.string "Dans les champs de FALLARBOR, nous plantons\n"
	.string "des semis d'arbres robustes qui prospèrent\l"
	.string "même dans la cendre volcanique.$"
