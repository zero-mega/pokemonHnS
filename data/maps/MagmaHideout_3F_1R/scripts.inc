MagmaHideout_3F_1R_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MagmaHideout_3F_1R_OnTransition
	.byte 0

MagmaHideout_3F_1R_OnTransition:
	goto_if_set FLAG_UNLOCK_DOGS, MagmaHideout_3F_1R_SwitchToModern
	end

MagmaHideout_3F_1R_SwitchToModern::
	setmaplayoutindex LAYOUT_MAGMA_HIDEOUT_3F_1R_MODERN
	goto_if_set FLAG_DEFEATED_ENTEI, MagmaHideout_End
	goto MagmaHideout_Entei_CryStrong
	end

MagmaHideout_Entei_CryStrong::
	playmoncry SPECIES_ENTEI, CRY_MODE_ENCOUNTER
	release
	end

MagmaHideout_3F_1R_EventScript_Grunt9::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_9, MagmaHideout_3F_1R_Text_Grunt9Intro, MagmaHideout_3F_1R_Text_Grunt9Defeat
	msgbox MagmaHideout_3F_1R_Text_Grunt9PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_3F_1R_EventScript_Grunt16::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_16, MagmaHideout_3F_1R_Text_Grunt16Intro, MagmaHideout_3F_1R_Text_Grunt16Defeat
	msgbox MagmaHideout_3F_1R_Text_Grunt16PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_3F_1R_Text_Grunt9Intro:
	.string "Qu'est-ce que j'ai fait pour mériter\n"
	.string "ce poste de garde ?\p"
	.string "Mon oreille gauche brûle !$"

MagmaHideout_3F_1R_Text_Grunt9Defeat:
	.string "Je fais une insolation…$"

MagmaHideout_3F_1R_Text_Grunt9PostBattle:
	.string "Tu ne trouves pas ça bizarre qu'on porte\n"
	.string "des capuches dans ce volcan rempli de magma ?$"

MagmaHideout_3F_1R_Text_Grunt16Intro:
	.string "On a rejoint la TEAM MAGMA pour aider\n"
	.string "notre chef à réaliser sa vision fantastique.\p"
	.string "Je me fiche que tu sois avec la TEAM AQUA\n"
	.string "ou juste un gamin de passage.\p"
	.string "Personne ne s'interpose entre nous\n"
	.string "et s'en sort comme ça !$"

MagmaHideout_3F_1R_Text_Grunt16Defeat:
	.string "Oh, non !\n"
	.string "On ne peut vraiment pas te faire confiance !$"

MagmaHideout_3F_1R_Text_Grunt16PostBattle:
	.string "Écoute-moi bien.\n"
	.string "La TEAM MAGMA a raison !\p"
	.string "N'écoute pas la TEAM AQUA.\n"
	.string "Ne crois pas à leurs mensonges !$"
