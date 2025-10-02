EverGrandeCity_GlaciasRoom_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_GlaciasRoom_OnFrame
	map_script MAP_SCRIPT_ON_LOAD, EverGrandeCity_GlaciasRoom_OnLoad
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_GlaciasRoom_OnWarp
	.byte 0

EverGrandeCity_GlaciasRoom_OnWarp:
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_GlaciasRoom_EventScript_PlayerTurnNorth
	.2byte 0

EverGrandeCity_GlaciasRoom_EventScript_PlayerTurnNorth::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

EverGrandeCity_GlaciasRoom_OnFrame:
	map_script_2 VAR_GARBAGEVAR, 2, EverGrandeCity_GlaciasRoom_EventScript_WalkInCloseDoor
	.2byte 0

EverGrandeCity_GlaciasRoom_EventScript_WalkInCloseDoor::
	lockall
	call PokemonLeague_EliteFour_EventScript_WalkInCloseDoor
	setvar VAR_GARBAGEVAR, 3
	releaseall
	end

EverGrandeCity_GlaciasRoom_OnLoad:
	call_if_set FLAG_DEFEATED_ELITE_4_BRUNO, EverGrandeCity_GlaciasRoom_EventScript_ResetAdvanceToNextRoom
	call_if_eq VAR_GARBAGEVAR, 3, EverGrandeCity_GlaciasRoom_EventScript_CloseDoor
	end

EverGrandeCity_GlaciasRoom_EventScript_ResetAdvanceToNextRoom::
	call PokemonLeague_EliteFour_EventScript_ResetAdvanceToNextRoom
	return

EverGrandeCity_GlaciasRoom_EventScript_CloseDoor::
	call PokemonLeague_EliteFour_EventScript_CloseDoor
	return

EverGrandeCity_GlaciasRoom_EventScript_Glacia::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_ELITE_4_BRUNO, EverGrandeCity_GlaciasRoom_EventScript_PostBattleSpeech
	goto_if_set FLAG_GLACIA_REMATCH, EverGrandeCity_GlaciasRoom_EventScript_GlaciaRematch
	playbgm MUS_ENCOUNTER_ELITE_FOUR, FALSE
	msgbox EverGrandeCity_GlaciasRoom_Text_IntroSpeech, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GLACIA, EverGrandeCity_GlaciasRoom_Text_Defeat
	goto EverGrandeCity_GlaciasRoom_EventScript_Defeated
	end

EverGrandeCity_GlaciasRoom_EventScript_GlaciaRematch::
	msgbox EverGrandeCity_GlaciasRoom_Text_IntroSpeech2, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_PHOEBE2, EverGrandeCity_GlaciasRoom_Text_Defeat2
	goto EverGrandeCity_GlaciasRoom_EventScript_Defeated
	end

EverGrandeCity_GlaciasRoom_EventScript_PostBattleSpeech::
	msgbox EverGrandeCity_GlaciasRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_GlaciasRoom_EventScript_Defeated::
	setflag FLAG_DEFEATED_ELITE_4_BRUNO
	call PokemonLeague_EliteFour_SetAdvanceToNextRoomMetatiles
	msgbox EverGrandeCity_GlaciasRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_GlaciasRoom_Text_IntroSpeech:
	.string "Bienvenue, je m'appelle GLACIA\n"
	.string "du CONSEIL 4.\p"
	.string "J'ai voyagé de loin jusqu'à HOENN\n"
	.string "pour perfectionner mes talents de glace.\p"
	.string "Mais tout ce que j'ai rencontré, ce sont\n"
	.string "des défis lancés par des DRESSEURS faibles et leurs POKéMON.\p"
	.string "Et toi, alors ?\p"
	.string "Ce serait un immense plaisir pour moi\n"
	.string "de pouvoir me donner à fond contre toi !$"

EverGrandeCity_GlaciasRoom_Text_IntroSpeech2:
	.string "Te revoilà, je suis GLACIA. Je ne vais pas\n"
	.string "me représenter, tu me connais déjà.\p"
	.string "Je n'ai pas eu de véritable défi depuis\n"
	.string "notre dernier combat, toi et tes POKéMON.\p"
	.string "Et toi, alors ?\n"
	.string "As-tu affiné tes compétences ?\p"
	.string "Ce serait un immense plaisir pour moi\n"
	.string "de pouvoir me donner à fond contre toi !\p"
	.string "Mais cette fois… je gagnerai !$"

EverGrandeCity_GlaciasRoom_Text_Defeat:
	.string "Toi et tes POKéMON…\n"
	.string "Quel feu anime vos esprits !\p"
	.string "Cette chaleur dévorante m'a submergée.\p"
	.string "Il n'est pas surprenant que mes talents glacés\n"
	.string "n'aient pas pu t'atteindre.$"

EverGrandeCity_GlaciasRoom_Text_Defeat2:
	.string "Ton esprit brûle toujours ! Mais\p"
	.string "je me retrouve encore laissée dans le froid…$"

EverGrandeCity_GlaciasRoom_Text_PostBattleSpeech:
	.string "Avance dans la pièce suivante.\p"
	.string "Et là, découvre le côté vraiment redoutable\n"
	.string "de la LIGUE POKéMON.$"
