EverGrandeCity_DrakesRoom_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_DrakesRoom_OnFrame
	map_script MAP_SCRIPT_ON_LOAD, EverGrandeCity_DrakesRoom_OnLoad
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_SidneysRoom_OnWarp
	.byte 0

@ Unused, Drake uses Sidneys identical OnWarp for some reason
EverGrandeCity_DrakesRoom_OnWarp:
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_DrakesRoom_EventScript_PlayerTurnNorth
	.2byte 0

EverGrandeCity_DrakesRoom_EventScript_PlayerTurnNorth::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

EverGrandeCity_DrakesRoom_OnFrame:
	map_script_2 VAR_GARBAGEVAR, 3, EverGrandeCity_DrakesRoom_EventScript_WalkInCloseDoor
	.2byte 0

EverGrandeCity_DrakesRoom_EventScript_WalkInCloseDoor::
	lockall
	call PokemonLeague_EliteFour_EventScript_WalkInCloseDoor
	setvar VAR_GARBAGEVAR, 4
	releaseall
	end

EverGrandeCity_DrakesRoom_OnLoad:
	call_if_set FLAG_DEFEATED_ELITE_4_KAREN, EverGrandeCity_DrakesRoom_EventScript_ResetAdvanceToNextRoom
	call_if_eq VAR_GARBAGEVAR, 4, EverGrandeCity_DrakesRoom_EventScript_CloseDoor
	end

EverGrandeCity_DrakesRoom_EventScript_ResetAdvanceToNextRoom::
	call PokemonLeague_EliteFour_EventScript_ResetAdvanceToNextRoom
	return

EverGrandeCity_DrakesRoom_EventScript_CloseDoor::
	call PokemonLeague_EliteFour_EventScript_CloseDoor
	return

EverGrandeCity_DrakesRoom_EventScript_Drake::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_ELITE_4_KAREN, EverGrandeCity_DrakesRoom_EventScript_PostBattleSpeech
	goto_if_set FLAG_DRAKE_REMATCH, EverGrandeCity_DrakesRoom_EventScript_DrakeRematch
	playbgm MUS_ENCOUNTER_ELITE_FOUR, FALSE
	msgbox EverGrandeCity_DrakesRoom_Text_IntroSpeech, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_KIP, EverGrandeCity_DrakesRoom_Text_Defeat
	goto EverGrandeCity_DrakesRoom_EventScript_Defeated
	end

EverGrandeCity_DrakesRoom_EventScript_DrakeRematch::
	playbgm MUS_ENCOUNTER_ELITE_FOUR, FALSE
	msgbox EverGrandeCity_DrakesRoom_Text_IntroSpeech2, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_KIP2, EverGrandeCity_DrakesRoom_Text_Defeat2
	goto EverGrandeCity_DrakesRoom_EventScript_Defeated
	end

EverGrandeCity_DrakesRoom_EventScript_PostBattleSpeech::
	msgbox EverGrandeCity_DrakesRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_DrakesRoom_EventScript_Defeated::
	setvar VAR_0x8004, FANCOUNTER_DEFEATED_DRAKE
	special Script_TryGainNewFanFromCounter
	setflag FLAG_DEFEATED_ELITE_4_KAREN
	call PokemonLeague_EliteFour_SetAdvanceToNextRoomMetatiles
	msgbox EverGrandeCity_DrakesRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_DrakesRoom_Text_IntroSpeech:
	.string "Je suis le dernier du CONSEIL 4\n"
	.string "de la LIGUE POKéMON, DRAKE, le maître des DRAGONS !\p"
	.string "À l'état naturel, les POKéMON sont\n"
	.string "des êtres sauvages. Ils sont libres.\p"
	.string "Parfois, ils nous gênent.\n"
	.string "Parfois, ils nous aident.\p"
	.string "Pour combattre avec les POKéMON comme\n"
	.string "partenaires, sais-tu ce qu'il faut ?\p"
	.string "Sais-tu ce qui est nécessaire ?\p"
	.string "Si tu ne le sais pas, tu ne pourras\n"
	.string "jamais me vaincre !$"

EverGrandeCity_DrakesRoom_Text_IntroSpeech2:
	.string "Je suis le dernier du CONSEIL 4\n"
	.string "de la LIGUE POKéMON, DRAKE, le maître des DRAGONS !\p"
	.string "Comment vont tes partenaires POKéMON ?\n"
	.string "T'ont-ils aidé à devenir plus fort ?\p"
	.string "Je suis sûr que oui !\p"
	.string "Tu sembles déjà prêt à en découdre. Les\n"
	.string "autres membres du CONSEIL 4 t'ont-ils\p"
	.string "épuisé ? Ne faiblis pas maintenant !\p"
	.string "Vaincs-moi ! Dansons !$"

EverGrandeCity_DrakesRoom_Text_Defeat:
	.string "Superbe, il faut le dire.$"

EverGrandeCity_DrakesRoom_Text_Defeat2:
	.string "Ha, ha, ha !\n"
	.string "Je ne peux m'empêcher de rire !\p"
	.string "Incroyable. Superbe.\n"
	.string "Tu es vraiment le meilleur.$"

EverGrandeCity_DrakesRoom_Text_PostBattleSpeech:
	.string "Tu mérites tous les honneurs d'être\n"
	.string "arrivé aussi loin en tant que DRESSEUR de POKéMON.\p"
	.string "Tu sembles vraiment savoir ce qu'il faut.\p"
	.string "Oui, ce qu'il faut à un DRESSEUR, c'est\n"
	.string "un cœur vertueux.\p"
	.string "Les POKéMON touchent le bon cœur des\n"
	.string "DRESSEURS et apprennent le bien du mal.\p"
	.string "Ils touchent le bon cœur des\n"
	.string "DRESSEURS et deviennent plus forts.\p"
	.string "Vas-y ! En avant !\n"
	.string "Le CHAMPION t'attend !$"
