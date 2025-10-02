Gate_MahoganyTown_Route43_MapScripts::
	.byte 0

Gate_MahoganyTown_Route43_EventScript_Cop::
	goto_if_ge VAR_GOLDENROD_CITY_STATE, 11, Gate_MahoganyTown_Route43_EventScript_CopAfter
	msgbox Route43MahoganyGate_Text_Officer, MSGBOX_NPC
	end

Gate_MahoganyTown_Route43_EventScript_CopAfter::
	msgbox Route43MahoganyGate_Text_Officer_RocketsCleared, MSGBOX_NPC
	end

Route43MahoganyGate_Text_Officer:
    .string "Seules les personnes se rendant au\n"
    .string "LAC COLÈRE sont passées ici récemment.$"

Route43MahoganyGate_Text_Officer_RocketsCleared:
    .string "Personne ne va au LAC COLÈRE\n"
    .string "ces jours-ci.$"

