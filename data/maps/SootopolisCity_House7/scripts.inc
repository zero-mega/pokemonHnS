SootopolisCity_House7_MapScripts::
	.byte 0

SootopolisCity_House7_EventScript_OldMan::
	msgbox SootopolisCity_House7_Text_CityFromEruptedVolcano, MSGBOX_NPC
	end

SootopolisCity_House7_EventScript_PokefanF::
	msgbox SootopolisCity_House7_Text_CaveMadeToKeepSomething, MSGBOX_NPC
	end

SootopolisCity_House7_Text_CityFromEruptedVolcano:
	.string "Un volcan sous-marin est entré en\n"
	.string "éruption et a surgi des profondeurs.\p"
	.string "Son cratère a émergé de la mer et\n"
	.string "s'est rempli d'eau de pluie.\p"
	.string "C'est ainsi que la VILLE de ATALANOPOLIS\n"
	.string "est née.$"

SootopolisCity_House7_Text_CaveMadeToKeepSomething:
	.string "La grotte qui relie ATALANOPOLIS au\n"
	.string "monde extérieur…\p"
	.string "On dirait que cette grotte a été créée\n"
	.string "pour empêcher quelque chose de sortir.\p"
	.string "Ou bien est-ce que je me fais des idées ?$"

