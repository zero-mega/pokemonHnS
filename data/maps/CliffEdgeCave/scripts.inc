CliffEdgeCave_MapScripts::
	.byte 0

CliffEdgeCave_EventScript_BaldMan::
	lock
	faceplayer
	msgbox CliffEdgeCave_Text_Baldman, MSGBOX_DEFAULT
	closemessage
	release
	end

CliffEdgeCave_Text_Baldman:
	.string "Si tu vois un embranchement dans\n"
	.string "une grotte, il y a de grandes chances\l"
	.string "qu'un chemin soit le bon et que l'autre\l"
	.string "mène à une impasse.\p"
	.string "Mais on ne peut pas s'empêcher d'essayer les deux.$"
