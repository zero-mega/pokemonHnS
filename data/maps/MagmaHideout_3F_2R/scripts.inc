MagmaHideout_3F_2R_MapScripts::
	.byte 0

MagmaHideout_3F_2R_EventScript_Grunt10::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_10, MagmaHideout_3F_2R_Text_Grunt10Intro, MagmaHideout_3F_2R_Text_Grunt10Defeat
	msgbox MagmaHideout_3F_2R_Text_Grunt10PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_3F_2R_Text_Grunt10Intro:
	.string "Je comprends tout ce que notre chef\n"
	.string "dit. Mais tu sais quoi ?\p"
	.string "Faire des trucs comme déterrer un\n"
	.string "POKéMON très ancien et voler\l"
	.string "la MÉTÉORITE de quelqu'un…\p"
	.string "Je pense qu'on va un peu trop loin.\n"
	.string "Qu'en penses-tu ?$"

MagmaHideout_3F_2R_Text_Grunt10Defeat:
	.string "Oui, je crois qu'on fait quelque chose\n"
	.string "de mal, d'une certaine façon.$"

MagmaHideout_3F_2R_Text_Grunt10PostBattle:
	.string "Tu sais, perdre contre toi m'a éclairci l'esprit.\p"
	.string "La prochaine fois que je verrai notre chef,\n"
	.string "je vais lui demander ce qu'on fait vraiment.$"
