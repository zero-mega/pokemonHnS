MagmaHideout_2F_1R_MapScripts::
	.byte 0

MagmaHideout_2F_1R_EventScript_Grunt14::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_14, MagmaHideout_2F_1R_Text_Grunt14Intro, MagmaHideout_2F_1R_Text_Grunt14Defeat
	msgbox MagmaHideout_2F_1R_Text_Grunt14PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_1R_EventScript_Grunt3::
	trainerbattle_single TRAINER_NARD, MagmaHideout_2F_1R_Text_Grunt3Intro, MagmaHideout_2F_1R_Text_Grunt3Defeat
	msgbox MagmaHideout_2F_1R_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_1R_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_4, MagmaHideout_2F_1R_Text_Grunt4Intro, MagmaHideout_2F_1R_Text_Grunt4Defeat
	msgbox MagmaHideout_2F_1R_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_1R_EventScript_Grunt5::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_5, MagmaHideout_2F_1R_Text_Grunt5Intro, MagmaHideout_2F_1R_Text_Grunt5Defeat
	msgbox MagmaHideout_2F_1R_Text_Grunt5PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_1R_Text_Grunt14Intro:
	.string "Quoi, quoi, quoi ?\p"
	.string "Seuls les membres de la TEAM MAGMA\n"
	.string "sont censés être ici !\p"
	.string "Mais tu ne portes pas l'uniforme de\n"
	.string "la TEAM MAGMA…\p"
	.string "Tu éveilles mes soupçons !\n"
	.string "Bats-toi contre moi !$"

MagmaHideout_2F_1R_Text_Grunt14Defeat:
	.string "Aïe aïe aïe…\n"
	.string "Ma fierté de membre de la TEAM MAGMA…$"

MagmaHideout_2F_1R_Text_Grunt14PostBattle:
	.string "Si tu as froid, tu devrais rejoindre\n"
	.string "la TEAM MAGMA.$"

MagmaHideout_2F_1R_Text_Grunt3Intro:
	.string "Halte-là !\p"
	.string "Tu ne t'attends tout de même pas à ce\n"
	.string "que je me taise et te laisse passer ?$"

MagmaHideout_2F_1R_Text_Grunt3Defeat:
	.string "Oh, waouh !\n"
	.string "Je cède !$"

MagmaHideout_2F_1R_Text_Grunt3PostBattle:
	.string "Peut-être que j'aurais dû te laisser\n"
	.string "passer sans te défier…$"

MagmaHideout_2F_1R_Text_Grunt4Intro:
	.string "Ahah !\n"
	.string "Un intrus !$"

MagmaHideout_2F_1R_Text_Grunt4Defeat:
	.string "Graaah !$"

MagmaHideout_2F_1R_Text_Grunt4PostBattle:
	.string "J'ai déjà perdu.\p"
	.string "Dois-je vraiment continuer à tourner\n"
	.string "en rond ?$"

MagmaHideout_2F_1R_Text_Grunt5Intro:
	.string "Oh, oh !\n"
	.string "Un intrus !$"

MagmaHideout_2F_1R_Text_Grunt5Defeat:
	.string "Grommelle…$"

MagmaHideout_2F_1R_Text_Grunt5PostBattle:
	.string "En fait, je ne suis pas un expert en\n"
	.string "combats…$"
