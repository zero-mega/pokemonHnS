EverGrandeCity_PhoebesRoom_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, EverGrandeCity_PhoebesRoom_OnLoad
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_PhoebesRoom_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_PhoebesRoom_OnFrame
	.byte 0

EverGrandeCity_PhoebesRoom_OnWarp:
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_PhoebesRoom_EventScript_PlayerTurnNorth
	.2byte 0

EverGrandeCity_PhoebesRoom_EventScript_PlayerTurnNorth::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

EverGrandeCity_PhoebesRoom_OnFrame:
	map_script_2 VAR_GARBAGEVAR, 1, EverGrandeCity_PhoebesRoom_EventScript_WalkInCloseDoor
	.2byte 0

EverGrandeCity_PhoebesRoom_EventScript_WalkInCloseDoor::
	lockall
	call PokemonLeague_EliteFour_EventScript_WalkInCloseDoor
	setvar VAR_GARBAGEVAR, 2
	releaseall
	end

EverGrandeCity_PhoebesRoom_OnLoad:
	call_if_set FLAG_DEFEATED_ELITE_4_KOGA, EverGrandeCity_PhoebesRoom_EventScript_ResetAdvanceToNextRoom
	call_if_eq VAR_GARBAGEVAR, 2, EverGrandeCity_PhoebesRoom_EventScript_CloseDoor
	end

EverGrandeCity_PhoebesRoom_EventScript_ResetAdvanceToNextRoom::
	call PokemonLeague_EliteFour_EventScript_ResetAdvanceToNextRoom
	return

EverGrandeCity_PhoebesRoom_EventScript_CloseDoor::
	call PokemonLeague_EliteFour_EventScript_CloseDoor
	return

EverGrandeCity_PhoebesRoom_EventScript_Phoebe::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_ELITE_4_KOGA, EverGrandeCity_PhoebesRoom_EventScript_PostBattleSpeech
	goto_if_set FLAG_PHOEBE_REMATCH, EverGrandeCity_PhoebesRoom_EventScript_PhoebeRematch
	playbgm MUS_ENCOUNTER_ELITE_FOUR, FALSE
	msgbox EverGrandeCity_PhoebesRoom_Text_IntroSpeech, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_PHOEBE, EverGrandeCity_PhoebesRoom_Text_Defeat
	goto EverGrandeCity_PhoebesRoom_EventScript_Defeated
	end

EverGrandeCity_PhoebesRoom_EventScript_PhoebeRematch::
	playbgm MUS_ENCOUNTER_ELITE_FOUR, FALSE
	msgbox EverGrandeCity_PhoebesRoom_Text_IntroSpeech2, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_PHOEBE2, EverGrandeCity_PhoebesRoom_Text_Defeat2
	goto EverGrandeCity_PhoebesRoom_EventScript_Defeated
	end

EverGrandeCity_PhoebesRoom_EventScript_PostBattleSpeech::
	msgbox EverGrandeCity_PhoebesRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_PhoebesRoom_EventScript_Defeated::
	setflag FLAG_DEFEATED_ELITE_4_KOGA
	call PokemonLeague_EliteFour_SetAdvanceToNextRoomMetatiles
	msgbox EverGrandeCity_PhoebesRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_PhoebesRoom_Text_IntroSpeech:
	.string "Ahahaha !\p"
	.string "Je suis PHOEBE du CONSEIL 4.\n"
	.string "Je me suis entraînée au MT. PYRE.\p"
	.string "Pendant mon entraînement, j'ai acquis la capacité\n"
	.string "de communiquer avec les POKéMON de type SPECTRE.\p"
	.string "Oui, le lien que j'ai développé avec mes POKéMON\n"
	.string "est extrêmement fort.\p"
	.string "Alors, vas-y, essaie donc de voir si tu peux\n"
	.string "même infliger des dégâts à mes POKéMON !$"

EverGrandeCity_PhoebesRoom_Text_IntroSpeech2:
	.string "Ahahaha ! C'est encore toi !\p"
	.string "Je suis PHOEBE du CONSEIL 4.\n"
	.string "Le lien que j'ai développé avec mes POKéMON\l"
	.string "est devenu encore plus fort !\p"
	.string "Alors essaie donc de voir si tu peux\n"
	.string "infliger des dégâts à mes POKéMON.\p"
	.string "Parce que cette fois, ce ne sera pas comme la dernière !$"

EverGrandeCity_PhoebesRoom_Text_Defeat:
	.string "Oh, mince.\n"
	.string "J'ai perdu.$"

EverGrandeCity_PhoebesRoom_Text_Defeat2:
	.string "Oh, mince…\n"
	.string "C'est encore arrivé.$"

EverGrandeCity_PhoebesRoom_Text_PostBattleSpeech:
	.string "Il y a un lien certain entre toi\n"
	.string "et tes POKéMON aussi.\p"
	.string "Je ne l'avais pas reconnu, donc il est\n"
	.string "normal que j'aie perdu.\p"
	.string "Oui, j'aimerais voir jusqu'où ton lien\n"
	.string "pourra t'emmener.\p"
	.string "Vas-y, passe dans la salle suivante.$"
