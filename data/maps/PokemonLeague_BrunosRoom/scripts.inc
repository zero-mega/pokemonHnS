PokemonLeague_BrunosRoom_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EliteFourRoom_OnFrame
	map_script MAP_SCRIPT_ON_RESUME, PokemonLeague_BrunosRoom_OnResume
	map_script MAP_SCRIPT_ON_LOAD, EliteFourRoom_OnLoad
	.byte 0

PokemonLeague_BrunosRoom_OnResume::
	setvar VAR_0x8004, 2
	special DoPokemonLeagueLightingEffect
	end

PokemonLeague_BrunosRoom_EventScript_Bruno::
	lock 
	faceplayer
	goto_if_ge VAR_LEAGUE_STATE, 4, PokemonLeague_BrunosRoom_EventScript_BrunoDefeated
	goto_if_set FLAG_IS_CHAMPION, PokemonLeague_BrunosRoom_EventScript_BrunoRematch
	msgbox PokemonLeague_BrunosRoom_Text_Before, MSGBOX_DEFAULT
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	trainerbattle_no_intro TRAINER_BRUNO_1, PokemonLeague_BrunosRoom_Text_Beaten
	goto PokemonLeague_BrunosRoom_EventScript_BrunoOnDefeat

PokemonLeague_BrunosRoom_EventScript_BrunoRematch::
	msgbox PokemonLeague_BrunosRoom_Text_RematchBefore, MSGBOX_DEFAULT
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	trainerbattle_no_intro TRAINER_BRUNO_2, PokemonLeague_BrunosRoom_Text_Beaten
	goto PokemonLeague_BrunosRoom_EventScript_BrunoOnDefeat

PokemonLeague_BrunosRoom_EventScript_BrunoOnDefeat::
	clearflag FLAG_TEMP_5	
	msgbox PokemonLeague_BrunosRoom_Text_Defeat, MSGBOX_DEFAULT
	closemessage
	setmetatile 6, 1, 0x28E, FALSE
	setmetatile 6, 2, 0x296, FALSE	
	playse SE_BANG
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 4  @ num shakes
	setvar VAR_0x8007, 4  @ shake delay
	special ShakeCamera
	waitstate
	special DrawWholeMapView
	setvar VAR_LEAGUE_STATE, 4
	release
	end

PokemonLeague_BrunosRoom_EventScript_BrunoDefeated::
	msgbox PokemonLeague_BrunosRoom_Text_Defeat, MSGBOX_DEFAULT
	closemessage
	release
	end

PokemonLeague_BrunosRoom_Text_RematchBefore:
    .string "BRUNO : Te revoilà, jeune\n"
    .string "guerrier.\p"
    .string "Grâce à un entraînement rigoureux,\n"
    .string "nous sommes devenus plus forts.\p"
    .string "Ma volonté de fer est encore plus\n"
    .string "solide et inébranlable.\p"
    .string "Es-tu prêt à affronter un défi\n"
    .string "encore plus grand ?\p"
    .string "Montre-moi les résultats de ton\n"
    .string "entraînement.\p"
    .string "Hou ha !$"

PokemonLeague_BrunosRoom_Text_Before:
    .string "Je suis BRUNO du CONSEIL 4.\p"
    .string "Je m'entraîne toujours à l'extrême\n"
    .string "car je crois en notre potentiel.\p"
    .string "C'est ainsi que nous sommes devenus\n"
    .string "forts.\p"
    .string "Peux-tu résister à notre puissance ?\p"
    .string "Hm ? Je ne vois aucune peur en toi.\n"
    .string "Tu as l'air déterminé. Parfait pour\n"
    .string "le combat !\p"
    .string "Prêt, {PLAYER} ? Tu vas t'incliner\n"
    .string "devant notre puissance écrasante !\p"
    .string "Hou ha !$"

PokemonLeague_BrunosRoom_Text_Beaten:
    .string "Pourquoi ? Comment avons-nous pu\n"
    .string "perdre ?$"

PokemonLeague_BrunosRoom_Text_Defeat:
    .string "Ayant perdu, je n'ai pas le droit de\n"
    .string "dire quoi que ce soit…\p"
    .string "Va affronter ton prochain défi !$"
