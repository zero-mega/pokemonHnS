Route6_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route6_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route6_OnTransition:
	callnative SetTimeBasedEncounters
	end

Route6_EventScript_Rex::
	trainerbattle_single TRAINER_REX PokefanM_Text_RexSeen, PokefanM_Text_RexBeaten
	msgbox PokefanM_Text_RexAfter, MSGBOX_AUTOCLOSE
	end

Route6_EventScript_Allan::
	trainerbattle_single TRAINER_ALLAN PokefanM_Text_AllanSeen, PokefanM_Text_AllanBeaten
	msgbox PokefanM_Text_AllanAfter, MSGBOX_AUTOCLOSE
	end

Route6_EventScript_Pokefan::
	msgbox Route6_Text_PokefanM, MSGBOX_NPC
	end

Route6_EventScript_Sign::
	msgbox PokefanM_Text_AllanAfter, MSGBOX_SIGN
	end

Route6_Text_PokefanM:
	.string "La route est fermée jusqu'à ce que\n"
	.string "le problème à la CENTRALE soit\l"
	.string "résolu.$"

Route6_Text_UndergroundPathSign:
	.string "PASSAGE SOUTERRAIN\p"
	.string "AZURIA - CARAMELARIVILLE$"

PokefanM_Text_RexSeen:
	.string "Mon GIRAFARIG est le plus mignon\n"
	.string "du monde.$"

PokefanM_Text_RexBeaten:
	.string "Mon GIRAFARIG !$"

PokefanM_Text_RexAfter:
	.string "Regarde comme mon GIRAFARIG agit\n"
	.string "de façon adorable !\p"
	.string "N'est-il pas assez mignon pour\n"
	.string "te faire fondre le cœur ?$"

PokefanM_Text_AllanSeen:
	.string "Mon GRANBULL est le plus mignon\n"
	.string "du monde.$"

PokefanM_Text_AllanBeaten:
	.string "Mon GRANBULL !$"

PokefanM_Text_AllanAfter:
	.string "Regarde comme mon GRANBULL agit\n"
	.string "de façon adorable !\p"
	.string "N'est-il pas assez mignon pour\n"
	.string "te faire fondre le cœur ?$"
