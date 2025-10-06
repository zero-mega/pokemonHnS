MtPyre_4F_MapScripts::
	.byte 0

@ Seems like the scripts for the 4F and 5F were swapped

MtPyre_5F_EventScript_Atsushi::
	trainerbattle_single TRAINER_CINDY, MtPyre_5F_Text_AtsushiIntro, MtPyre_5F_Text_AtsushiDefeat
	msgbox MtPyre_5F_Text_AtsushiPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_5F_Text_AtsushiIntro:
	.string "Professeur…\n"
	.string "S'il te plaît, veille sur mes progrès !$"

MtPyre_5F_Text_AtsushiDefeat:
	.string "Professeur…\n"
	.string "Pardonne-moi, s'il te plaît !$"

MtPyre_5F_Text_AtsushiPostBattle:
	.string "Tant que je ne m'améliore pas, mon professeur\n"
	.string "qui repose ici ne trouvera jamais la paix…$"

