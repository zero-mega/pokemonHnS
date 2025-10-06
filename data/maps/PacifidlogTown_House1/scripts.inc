PacifidlogTown_House1_MapScripts::
	.byte 0

PacifidlogTown_House1_EventScript_Man::
	msgbox PacifidlogTown_House1_Text_RegiStory, MSGBOX_NPC
	end

PacifidlogTown_House1_EventScript_Woman::
	msgbox PacifidlogTown_House1_Text_SixDotsOpenThreeDoors, MSGBOX_NPC
	end

PacifidlogTown_House1_Text_RegiStory:
	.string "Dans la région de HOENN, il y a cinq\n"
	.string "POKéMON qui représentent la puissance\l"
	.string "de la roche, de la glace, de l'acier,\l"
	.string "de l'électricité et de l'énergie\l"
	.string "draconique.\p"
	.string "On dit que chacun d'eux se cache\n"
	.string "au fond de grottes.\p"
	.string "C'est l'histoire que j'ai entendue\n"
	.string "quand j'étais petit.$"

PacifidlogTown_House1_Text_SixDotsOpenThreeDoors:
	.string "« Six points ouvrent cinq portes. »\p"
	.string "Grand-père disait ça, mais je ne sais\n"
	.string "pas ce qu'il voulait dire.$"
