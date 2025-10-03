MagmaHideout_2F_2R_MapScripts::
	.byte 0

MagmaHideout_2F_2R_EventScript_Grunt15::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_15, MagmaHideout_2F_2R_Text_Grunt15Intro, MagmaHideout_2F_2R_Text_Grunt15Defeat
	msgbox MagmaHideout_2F_2R_Text_Grunt15PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_2R_EventScript_Grunt6::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_6, MagmaHideout_2F_2R_Text_Grunt6Intro, MagmaHideout_2F_2R_Text_Grunt6Defeat
	msgbox MagmaHideout_2F_2R_Text_Grunt6PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_2R_EventScript_Grunt7::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_7, MagmaHideout_2F_2R_Text_Grunt7Intro, MagmaHideout_2F_2R_Text_Grunt7Defeat
	msgbox MagmaHideout_2F_2R_Text_Grunt7PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_2R_EventScript_Grunt8::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_8, MagmaHideout_2F_2R_Text_Grunt8Intro, MagmaHideout_2F_2R_Text_Grunt8Defeat
	msgbox MagmaHideout_2F_2R_Text_Grunt8PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_2R_Text_Grunt15Intro:
	.string "Je n'ai rien contre toi personnellement.\n"
	.string "Je fais juste ce qu'on m'ordonne !$"

MagmaHideout_2F_2R_Text_Grunt15Defeat:
	.string "J'ai peut-être perdu, mais…$"

MagmaHideout_2F_2R_Text_Grunt15PostBattle:
	.string "On a déterré quelque chose d'incroyable !\n"
	.string "Et on a obtenu l'ORBE BLEU !\p"
	.string "Il ne reste plus qu'à notre chef de…\n"
	.string "Fufufu… Fwahahaha !$"

MagmaHideout_2F_2R_Text_Grunt6Intro:
	.string "Je ne supporte pas la chaleur. J'aurais\n"
	.string "peut-être dû rejoindre la TEAM AQUA…$"

MagmaHideout_2F_2R_Text_Grunt6Defeat:
	.string "Oui, je ne suis peut-être pas fait pour\n"
	.string "la TEAM MAGMA…$"

MagmaHideout_2F_2R_Text_Grunt6PostBattle:
	.string "Tu ne trouves pas la mer trop loin\n"
	.string "dans un endroit comme ça ?$"

MagmaHideout_2F_2R_Text_Grunt7Intro:
	.string "On entend parfois des secousses ici.\p"
	.string "Est-ce le volcan qui gronde ?\n"
	.string "Ou alors, c'est GROU…\p"
	.string "Oups !\n"
	.string "Non, non, laisse tomber !$"

MagmaHideout_2F_2R_Text_Grunt7Defeat:
	.string "Tu es un combattant ardent.\n"
	.string "Comme un volcan !$"

MagmaHideout_2F_2R_Text_Grunt7PostBattle:
	.string "Tu as juste gagné cette fois,\n"
	.string "mais ça ne change rien.\p"
	.string "L'objectif de la TEAM MAGMA va bientôt\n"
	.string "être atteint !$"

MagmaHideout_2F_2R_Text_Grunt8Intro:
	.string "Un de nos gars paniquait parce qu'il a\n"
	.string "perdu son EMBLÈME MAGMA…\p"
	.string "Attends une minute !\n"
	.string "C'est toi qui l'as trouvé ?$"

MagmaHideout_2F_2R_Text_Grunt8Defeat:
	.string "J'ai du mal à y croire…$"

MagmaHideout_2F_2R_Text_Grunt8PostBattle:
	.string "J'ai le sentiment que notre plan\n"
	.string "va finir par échouer…$"
