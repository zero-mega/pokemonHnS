EverGrandeCity_SidneysRoom_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, EverGrandeCity_SidneysRoom_OnLoad
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_SidneysRoom_OnWarp
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_SidneysRoom_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_SidneysRoom_OnFrame
	.byte 0

EverGrandeCity_SidneysRoom_OnTransition:
	setflag FLAG_MET_SCOTT_IN_EVERGRANDE
	setflag FLAG_GARBAGEFLAG
	end

EverGrandeCity_SidneysRoom_OnLoad:
	call_if_set FLAG_DEFEATED_ELITE_4_WILL, EverGrandeCity_SidneysRoom_EventScript_ResetAdvanceToNextRoom
	call_if_eq VAR_GARBAGEVAR, 1, EverGrandeCity_SidneysRoom_EventScript_CloseDoor
	end

EverGrandeCity_SidneysRoom_EventScript_ResetAdvanceToNextRoom::
	call PokemonLeague_EliteFour_EventScript_ResetAdvanceToNextRoom
	return

EverGrandeCity_SidneysRoom_EventScript_CloseDoor::
	call PokemonLeague_EliteFour_EventScript_CloseDoor
	return

EverGrandeCity_SidneysRoom_OnWarp:
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_SidneysRoom_EventScript_PlayerTurnNorth
	.2byte 0

EverGrandeCity_SidneysRoom_EventScript_PlayerTurnNorth::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

EverGrandeCity_SidneysRoom_OnFrame:
	map_script_2 VAR_GARBAGEVAR, 0, EverGrandeCity_SidneysRoom_EventScript_WalkInCloseDoor
	.2byte 0

EverGrandeCity_SidneysRoom_EventScript_WalkInCloseDoor::
	lockall
	call PokemonLeague_EliteFour_EventScript_WalkInCloseDoor
	setvar VAR_GARBAGEVAR, 1
	releaseall
	end

EverGrandeCity_SidneysRoom_EventScript_Sidney::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_ELITE_4_WILL, EverGrandeCity_SidneysRoom_EventScript_PostBattleSpeech
	goto_if_set FLAG_SIDNEY_REMATCH, EverGrandeCity_SidneysRoom_EventScript_SidneyRematch
	playbgm MUS_ENCOUNTER_ELITE_FOUR, FALSE
	msgbox EverGrandeCity_SidneysRoom_Text_IntroSpeech, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_SIDNEY, EverGrandeCity_SidneysRoom_Text_Defeat
	goto EverGrandeCity_SidneysRoom_EventScript_Defeated
	end

EverGrandeCity_SidneysRoom_EventScript_SidneyRematch::
	playbgm MUS_ENCOUNTER_ELITE_FOUR, FALSE
	msgbox EverGrandeCity_SidneysRoom_Text_IntroSpeech2, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_SIDNEY2, EverGrandeCity_SidneysRoom_Text_Defeat2
	goto EverGrandeCity_SidneysRoom_EventScript_Defeated
	end

EverGrandeCity_SidneysRoom_EventScript_PostBattleSpeech::
	msgbox EverGrandeCity_SidneysRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_SidneysRoom_EventScript_Defeated::
	setflag FLAG_DEFEATED_ELITE_4_WILL
	call PokemonLeague_EliteFour_SetAdvanceToNextRoomMetatiles
	msgbox EverGrandeCity_SidneysRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_SidneysRoom_Text_IntroSpeech:
	.string "Bienvenue, challenger !\n"
	.string "Je suis SIDNEY du CONSEIL 4.\p"
	.string "J'aime ce regard que tu me lances.\n"
	.string "Je pense que tu vas bien te battre.\l"
	.string "C'est bien ! Tu as l'air en forme !\p"
	.string "Très bien ! Toi et moi, profitons\n"
	.string "d'un combat qui ne peut avoir lieu\l"
	.string "qu'ici, à la LIGUE POKéMON !$"

EverGrandeCity_SidneysRoom_Text_IntroSpeech2:
	.string "Te revoilà, challenger !\n"
	.string "Je suis SIDNEY du CONSEIL 4.\p"
	.string "Mais tu me connais déjà !\n"
	.string "Je pense que tu vas encore bien te battre.\l"
	.string "Tu as l'air en forme !\p"
	.string "Très bien ! Toi et moi, profitons\n"
	.string "d'un combat qui ne peut avoir lieu\l"
	.string "qu'ici, à la LIGUE POKéMON !\p"
	.string "Cette fois, je ne perdrai pas.$"

EverGrandeCity_SidneysRoom_Text_Defeat:
	.string "Alors, qu'en dis-tu ? J'ai perdu !\n"
	.string "Bah, c'était amusant, donc ce n'est pas grave.$"

EverGrandeCity_SidneysRoom_Text_Defeat2:
	.string "Alors, qu'en dis-tu ? J'ai perdu !\n"
	.string "Encore ! Ce n'est pas grave. C'était amusant.$"

EverGrandeCity_SidneysRoom_Text_PostBattleSpeech:
	.string "Bon, écoute ce que ce perdant a\n"
	.string "à dire.\p"
	.string "Tu as ce qu'il faut pour aller loin.\n"
	.string "Maintenant, va dans la pièce suivante et\l"
	.string "profite de ton prochain combat !$"
