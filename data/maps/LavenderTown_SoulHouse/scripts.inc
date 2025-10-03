LavenderTown_SoulHouse_MapScripts::
	.byte 0

LavenderTownSoulHouse_EventScript_MrFuji::
	msgbox MrFuji_Text_Main, MSGBOX_NPC
	end
LavenderTownSoulHouse_EventScript_Lass::
	msgbox SoulHouse_Text_Lass, MSGBOX_NPC
	end
LavenderTownSoulHouse_EventScript_Teacher::
	msgbox SoulHouse_Text_Teacher, MSGBOX_NPC
	end
LavenderTownSoulHouse_EventScript_Granny::
	msgbox SoulHouse_Text_Granny, MSGBOX_NPC
	end

MrFuji_Text_Main:
	.string "MR.FUJI : Bienvenue.\p"
	.string "Hmm… Tu sembles élever tes\n"
	.string "POKéMON avec gentillesse\l"
	.string "et amour.\p"
	.string "Les amoureux des POKéMON viennent\n"
	.string "ici pour rendre hommage aux\l"
	.string "POKéMON disparus.\p"
	.string "Merci d'offrir tes condoléances\n"
	.string "aux âmes des POKéMON défunts.\p"
	.string "Je suis sûr que cela les rendra\n"
	.string "heureux.$"

SoulHouse_Text_Teacher:
	.string "Je crois qu'il y a d'autres tombes\n"
	.string "de POKéMON ici.\p"
	.string "Il y a de nombreuses salles où seul\n"
	.string "MR.FUJI peut entrer.$"

SoulHouse_Text_Lass:
	.string "Je suis venue avec ma maman pour\n"
	.string "visiter les tombes des POKéMON…$"

SoulHouse_Text_Granny:
	.string "Les POKéMON qui ont vécu avec moi…\p"
	.string "Je les aimais comme mes\n"
	.string "petits-enfants…$"
