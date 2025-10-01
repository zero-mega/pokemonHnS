AquaHideout_1F_MapScripts::
	.byte 0

@ The below two entrance guards give hints about what to do to progress the story
AquaHideout_1F_EventScript_HideoutEntranceGrunt1::
	lock
	faceplayer
	goto_if_set FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT, AquaHideout_1F_EventScript_SlateportHint1
	goto_if_set FLAG_RECEIVED_RED_OR_BLUE_ORB, AquaHideout_1F_EventScript_MagmaHideoutHint1
	msgbox AquaHideout_1F_Text_OurBossIsSnatchingSomething, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_MagmaHideoutHint1::
	msgbox AquaHideout_1F_Text_WhereMightMagmaHideoutBe, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_SlateportHint1::
	msgbox AquaHideout_1F_Text_BossWentToJackASubmarine, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_HideoutEntranceGrunt2::
	lock
	faceplayer
	goto_if_set FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT, AquaHideout_1F_EventScript_SlateportHint2
	goto_if_set FLAG_RECEIVED_RED_OR_BLUE_ORB, AquaHideout_1F_EventScript_MagmaHideoutHint2
	msgbox AquaHideout_1F_Text_BossIsOnRoute122, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_MagmaHideoutHint2::
	msgbox AquaHideout_1F_Text_TeamMagmaAtMtChimney, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_SlateportHint2::
	msgbox AquaHideout_1F_Text_BossIsInSlateportCity, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_Grunt1::
	trainerbattle_single TRAINER_SAYO, AquaHideout_1F_Text_Grunt1Intro, AquaHideout_1F_Text_Grunt1Defeat, AquaHideout_1F_EventScript_Grunt1Defeated
	msgbox AquaHideout_1F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_1F_EventScript_Grunt1Defeated::
	msgbox AquaHideout_1F_Text_Grunt1PostBattle, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_Text_OurBossIsSnatchingSomething:
	.string "Quoi ? Quoi ? Que veux-tu à la\n"
	.string "TEAM AQUA ?\p"
	.string "Notre CHEF n'est pas là ! Il est parti\n"
	.string "voler quelque chose d'important !\p"
	.string "… …\n"
	.string "Où est-il allé ?\p"
	.string "Wahaha ! Tu crois vraiment que je vais\n"
	.string "te dire quelque chose d'aussi crucial ?$"

AquaHideout_1F_Text_WhereMightMagmaHideoutBe:
	.string "Quoi ? Quoi ?\n"
	.string "Tu es un sbire de la TEAM MAGMA ?\p"
	.string "J'ai entendu dire que la TEAM MAGMA\n"
	.string "essaie de réveiller un POKéMON génial\l"
	.string "dans leur REPÈRE.\p"
	.string "Mais où se trouve leur REPÈRE ?$"

AquaHideout_1F_Text_BossWentToJackASubmarine:
	.string "Quoi ? Quoi ? Que veux-tu à la\n"
	.string "TEAM AQUA ?\p"
	.string "Notre CHEF n'est pas là !\n"
	.string "Il est parti voler un sous-marin !\p"
	.string "… …\n"
	.string "Où est-il allé ?\p"
	.string "Wahaha ! Tu crois vraiment que je vais\n"
	.string "te dire quelque chose d'aussi crucial ?$"

AquaHideout_1F_Text_BossIsOnRoute122:
	.string "Quoi ? Quoi ? Que veux-tu à la\n"
	.string "TEAM AQUA ?\p"
	.string "Notre CHEF n'est pas là ! Il est en route\n"
	.string "pour le MT. PYRHE sur la ROUTE 122 !\p"
	.string "… …\n"
	.string "Pourquoi est-il parti ?\p"
	.string "Wahaha ! Tu crois vraiment que je vais\n"
	.string "te dire quelque chose d'aussi crucial ?$"

AquaHideout_1F_Text_TeamMagmaAtMtChimney:
	.string "Quoi ? Quoi ?\n"
	.string "Tu es un sbire de la TEAM MAGMA ?\p"
	.string "J'ai entendu dire que la TEAM MAGMA\n"
	.string "cherche un POKéMON génial au MT. CHIMNÉE.\p"
	.string "Mais à quoi ressemble ce POKéMON ?$"

AquaHideout_1F_Text_BossIsInSlateportCity:
	.string "Quoi ? Quoi ? Que veux-tu à la\n"
	.string "TEAM AQUA ?\p"
	.string "Notre CHEF n'est pas là !\n"
	.string "Il est en route pour POIVRESSEL !\p"
	.string "… …\n"
	.string "Pourquoi est-il parti ?\p"
	.string "Wahaha ! Tu crois vraiment que je vais\n"
	.string "te dire quelque chose d'aussi crucial ?$"

AquaHideout_1F_Text_Grunt1Intro:
	.string "Ayiyiyi !\n"
	.string "Personne louche repérée !$"

AquaHideout_1F_Text_Grunt1Defeat:
	.string "Grrrrr…\n"
	.string "J'ai perdu !$"

AquaHideout_1F_Text_Grunt1PostBattle:
	.string "J'ai perdu pour l'ÉQUIPE,\n"
	.string "mais j'ai fait mon boulot…$"
