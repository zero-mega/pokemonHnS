PokemonLeague_KogasRoom_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EliteFourRoom_OnFrame
	map_script MAP_SCRIPT_ON_RESUME, PokemonLeague_KogasRoom_OnResume
	map_script MAP_SCRIPT_ON_LOAD, EliteFourRoom_OnLoad
	.byte 0

PokemonLeague_KogasRoom_OnResume::
	setvar VAR_0x8004, 1
	special DoPokemonLeagueLightingEffect
	end

PokemonLeague_KogasRoom_EventScript_Koga::
	lock 
	faceplayer
	goto_if_ge VAR_LEAGUE_STATE, 3, PokemonLeague_KogasRoom_EventScript_KogaDefeated
	goto_if_set FLAG_IS_CHAMPION, PokemonLeague_KogasRoom_EventScript_KogaRematch
	msgbox PokemonLeague_KogasRoom_Text_Before, MSGBOX_DEFAULT
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	trainerbattle_no_intro TRAINER_KOGA_1, PokemonLeague_KogasRoom_Text_Beaten
	goto PokemonLeague_KogasRoom_EventScript_KogaOnDefeat

PokemonLeague_KogasRoom_EventScript_KogaRematch::
	msgbox PokemonLeague_KogasRoom_Text_RematchBefore, MSGBOX_DEFAULT
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	trainerbattle_no_intro TRAINER_KOGA_2, PokemonLeague_KogasRoom_Text_Beaten
	goto PokemonLeague_KogasRoom_EventScript_KogaOnDefeat

PokemonLeague_KogasRoom_EventScript_KogaOnDefeat::
	clearflag FLAG_TEMP_5
	msgbox PokemonLeague_KogasRoom_Text_Defeat, MSGBOX_DEFAULT
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
	setvar VAR_LEAGUE_STATE, 3
	release
	end

PokemonLeague_KogasRoom_EventScript_KogaDefeated::
	msgbox PokemonLeague_KogasRoom_Text_Defeat, MSGBOX_DEFAULT
	closemessage
	release
	end

PokemonLeague_KogasRoom_Text_RematchBefore:
    .string "KOGA : Fwahahahaha !\p"
    .string "Tu reviens, courageux challenger.\p"
    .string "Mes talents de ninja se sont aiguisés.\p"
    .string "De nouveaux pièges sinistres t’attendent.\p"
    .string "Poison, sommeil, et plus encore...\n"
    .string "Prépare-toi !\p"
    .string "Fwahahahaha !\p"
    .string "Montre-moi tes progrès !$"

PokemonLeague_KogasRoom_Text_Before:
    .string "Fwahahahaha !\p"
    .string "Je suis KOGA du CONSEIL 4.\p"
    .string "Je vis dans l’ombre, tel un ninja !\p"
    .string "Mon style complexe va te troubler\n"
    .string "et te détruire !\p"
    .string "Confusion, sommeil, poison…\p"
    .string "Prépare-toi à être la victime de ma\n"
    .string "technique sinistre !\p"
    .string "Fwahahahaha !\p"
    .string "Les POKéMON, ce n’est pas que la force\n"
    .string "brute—tu vas vite le comprendre !$"

PokemonLeague_KogasRoom_Text_Beaten:
    .string "Ah !\n"
    .string "Tu as prouvé ta valeur !$"

PokemonLeague_KogasRoom_Text_Defeat:
    .string "Je t’ai soumis à tout ce que\n"
    .string "je pouvais faire.\p"
    .string "Mais mes efforts ont échoué. Je dois\n"
    .string "affûter mes compétences.\p"
    .string "Va dans la salle suivante et mets\n"
    .string "tes capacités à l’épreuve !$"
