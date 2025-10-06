NewBarkTown_House1_MapScripts::
	.byte 0

NewBarkTown_House1_EventScript_Mother::
	lock
	faceplayer
	msgbox NewBarkTown_House1_Text_Neighbor, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_House1_EventScript_Daughter::
	lock
	faceplayer
	msgbox NewBarkTown_House1_Text_NeighborsDaughter, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_House1_Text_NeighborsDaughter:
	.string "PIKACHU est un POKéMON évolué.\p"
	.string "J'ai été étonnée par les\n"
	.string "découvertes du PROF.ORME.\p"
	.string "Il est tellement célèbre pour ses\n"
	.string "recherches sur l'évolution des POKéMON.\p"
	.string "…soupir…\p"
	.string "J'aimerais tant être chercheuse\n"
	.string "comme lui…$"


NewBarkTown_House1_Text_Neighbor:
	.string "Ma fille est déterminée à devenir\n"
	.string "l'assistante du PROF.ORME.\p"
	.string "Elle adore vraiment les POKéMON !\p"
	.string "Mais moi aussi, d'ailleurs !$"
