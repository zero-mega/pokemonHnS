SootopolisCity_House4_MapScripts::
	.byte 0

SootopolisCity_House4_EventScript_Man::
	msgbox SootopolisCity_House4_Text_AncientTreasuresWaitingInSea, MSGBOX_NPC
	end

SootopolisCity_House4_EventScript_Woman::
	msgbox SootopolisCity_House4_Text_StrollUnderwaterWithPokemon, MSGBOX_NPC
	end

SootopolisCity_House4_EventScript_Azumarill::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZUMARILL, CRY_MODE_NORMAL
	msgbox SootopolisCity_House4_Text_Azumarill, MSGBOX_DEFAULT
	waitmoncry
	release
	end

SootopolisCity_House4_Text_AncientTreasuresWaitingInSea:
	.string "Écoute-moi bien, je vais te dire\n"
	.string "quelque chose d'intéressant.\p"
	.string "On raconte qu'il y aurait une ruine\n"
	.string "ancienne dans la mer, par ici.\p"
	.string "Il y a peut-être des trésors qui\n"
	.string "n'attendent qu'à être découverts là-bas.$"

SootopolisCity_House4_Text_StrollUnderwaterWithPokemon:
	.string "Des trésors anciens…\p"
	.string "Ce serait bien s'ils existaient, mais\n"
	.string "même s'ils n'existaient pas, ce serait\l"
	.string "si beau de se promener sous l'eau\l"
	.string "avec mes POKéMON.$"

SootopolisCity_House4_Text_Azumarill:
	.string "AZUMARILL : Marurii.$"

