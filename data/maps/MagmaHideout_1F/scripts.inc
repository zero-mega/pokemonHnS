MagmaHideout_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MagmaHideout_1F_OnTransition
	.byte 0

MagmaHideout_1F_OnTransition:
	setvar VAR_JAGGED_PASS_ASH_WEATHER, 0
	goto_if_set FLAG_DEFEATED_ENTEI, MagmaHideout_End
	goto_if_set FLAG_UNLOCK_DOGS, MagmaHideout_Entei_CryFaint
	end

MagmaHideout_Entei_CryFaint::
	playmoncry SPECIES_ENTEI, CRY_MODE_FAINT
	release
	end

MagmaHideout_End::
	end

MagmaHideout_1F_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_1, MagmaHideout_1F_Text_Grunt1Intro, MagmaHideout_1F_Text_Grunt1Defeat
	msgbox MagmaHideout_1F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_1F_EventScript_Grunt2::
	trainerbattle_single TRAINER_RICHARDO, MagmaHideout_1F_Text_Grunt2Intro, MagmaHideout_1F_Text_Grunt2Defeat
	msgbox MagmaHideout_1F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_1F_Text_Grunt1Intro:
	.string "Quand la TEAM MAGMA fait l'appel, on reçoit\n"
	.string "des missions de garde importantes dans\l"
	.string "l'ordre dans lequel on se range.\p"
	.string "C'est pour ça que je suis coincé dans ce coin.\n"
	.string "Je suis toujours en retard à l'appel !$"

MagmaHideout_1F_Text_Grunt1Defeat:
	.string "Je suis aussi toujours en retard aux séances\n"
	.string "d'entraînement !\p"
	.string "Je déteste l'admettre, mais je suis un peu nul…$"

MagmaHideout_1F_Text_Grunt1PostBattle:
	.string "Bon, je vais essayer de faire un peu plus\n"
	.string "d'efforts à partir de maintenant…$"

MagmaHideout_1F_Text_Grunt2Intro:
	.string "Notre chef nous a dit de creuser dans\n"
	.string "le MT. CHIMNÉE, alors on a creusé et creusé.\p"
	.string "Et en creusant, on est tombés sur quelque\n"
	.string "chose qui nous a complètement bluffés !\p"
	.string "Qu'est-ce qu'on a trouvé ?\p"
	.string "Fuhahaha !\n"
	.string "Je te le dirai si tu me bats !$"

MagmaHideout_1F_Text_Grunt2Defeat:
	.string "Arrgh !\n"
	.string "Je suis battu !$"

MagmaHideout_1F_Text_Grunt2PostBattle:
	.string "Finalement, je ne te dirai rien.\n"
	.string "Tu le découvriras en avançant !\p"
	.string "C'est mieux de garder les surprises\n"
	.string "pour la fin, tu ne crois pas ?$"
