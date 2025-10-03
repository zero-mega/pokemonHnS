MauvilleCity_BikeShop_MapScripts::
	.byte 0

MauvilleCity_BikeShop_EventScript_Rydel::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_BIKE, MauvilleCity_BikeShop_EventScript_AskSwitchBikes
	goto_if_set FLAG_DECLINED_BIKE, MauvilleCity_BikeShop_EventScript_SkipGreeting
	msgbox MauvilleCity_BikeShop_Text_RydelGreeting, MSGBOX_DEFAULT
	msgbox MauvilleCity_BikeShop_Text_DidYouComeFromFarAway, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_BikeShop_EventScript_YesFar
	goto_if_eq VAR_RESULT, NO, MauvilleCity_BikeShop_EventScript_NotFar
	end

MauvilleCity_BikeShop_EventScript_SkipGreeting::
	msgbox MauvilleCity_BikeShop_Text_DidYouComeFromFarAway, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_BikeShop_EventScript_YesFar
	goto_if_eq VAR_RESULT, NO, MauvilleCity_BikeShop_EventScript_NotFar
	end

MauvilleCity_BikeShop_EventScript_ChooseBike::
	msgbox MauvilleCity_BikeShop_Text_ExplainBikesChooseWhichOne, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_BikeShop_EventScript_GetAcroBike
	goto_if_eq VAR_RESULT, NO, MauvilleCity_BikeShop_EventScript_GetMachBike
	@waitmessage
	@multichoice 21, 8, MULTI_BIKE, TRUE
	@switch VAR_RESULT
	@case 0, MauvilleCity_BikeShop_EventScript_GetMachBike
	@case 1, MauvilleCity_BikeShop_EventScript_GetMachBike
	end

MauvilleCity_BikeShop_EventScript_NotFar::
	setflag FLAG_DECLINED_BIKE
	msgbox MauvilleCity_BikeShop_Text_GuessYouDontNeedBike, MSGBOX_DEFAULT
	release
	end

MauvilleCity_BikeShop_EventScript_YesFar::
	goto MauvilleCity_BikeShop_EventScript_ChooseBike
	end

MauvilleCity_BikeShop_EventScript_GetMachBike::
	msgbox MauvilleCity_BikeShop_Text_GuessYouDontNeedBike2, MSGBOX_DEFAULT
	@giveitem ITEM_MACH_BIKE
	@goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
	release
	end

MauvilleCity_BikeShop_EventScript_GetAcroBike::
	msgbox MauvilleCity_BikeShop_Text_ChoseAcroBike, MSGBOX_DEFAULT
	giveitem ITEM_MACH_BIKE
	setflag FLAG_RECEIVED_BIKE
	goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
	end

MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes::
	msgbox MauvilleCity_BikeShop_Text_ComeBackToSwitchBikes, MSGBOX_DEFAULT
	release
	end

MauvilleCity_BikeShop_EventScript_AskSwitchBikes::
	msgbox MauvilleCity_BikeShop_Text_WantToSwitchBikes, MSGBOX_NPC
	@goto_if_eq VAR_RESULT, YES, MauvilleCity_BikeShop_EventScript_SwitchBikes
	@goto_if_eq VAR_RESULT, NO, MauvilleCity_BikeShop_EventScript_KeepBike
	end

@ If the player does not have a bike on them Rydel assumes its stored in the PC
MauvilleCity_BikeShop_EventScript_SwitchBikes::
	msgbox MauvilleCity_BikeShop_Text_IllSwitchBikes, MSGBOX_DEFAULT
	checkitem ITEM_ACRO_BIKE
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_BikeShop_EventScript_SwitchAcroForMach
	checkitem ITEM_MACH_BIKE
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_BikeShop_EventScript_SwitchMachForAcro
	msgbox MauvilleCity_BikeShop_Text_OhYourBikeIsInPC, MSGBOX_DEFAULT
	release
	end

MauvilleCity_BikeShop_EventScript_KeepBike::
	msgbox MauvilleCity_BikeShop_Text_HappyYouLikeIt, MSGBOX_DEFAULT
	release
	end

MauvilleCity_BikeShop_EventScript_SwitchAcroForMach::
	incrementgamestat GAME_STAT_TRADED_BIKES
	msgbox MauvilleCity_BikeShop_Text_ExchangedAcroForMach, MSGBOX_DEFAULT
	removeitem ITEM_ACRO_BIKE
	giveitem ITEM_MACH_BIKE
	goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
	end

MauvilleCity_BikeShop_EventScript_SwitchMachForAcro::
	incrementgamestat GAME_STAT_TRADED_BIKES
	msgbox MauvilleCity_BikeShop_Text_ExchangedMachForAcro, MSGBOX_DEFAULT
	removeitem ITEM_MACH_BIKE
	giveitem ITEM_ACRO_BIKE
	goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
	end

MauvilleCity_BikeShop_EventScript_Assistant::
	msgbox MauvilleCity_BikeShop_Text_HandbooksAreInBack, MSGBOX_NPC
	end

MauvilleCity_BikeShop_EventScript_MachBikeHandbook::
	message MauvilleCity_BikeShop_Text_MachHandbookWhichPage
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage::
	multichoice 0, 0, MULTI_MACH_BIKE_INFO, FALSE
	switch VAR_RESULT
	case 0, MauvilleCity_BikeShop_EventScript_HowToRide
	case 1, MauvilleCity_BikeShop_EventScript_HowToTurn
	case 2, MauvilleCity_BikeShop_EventScript_SandySlopes
	case 3, MauvilleCity_BikeShop_EventScript_ExitMachHandbook
	case MULTI_B_PRESSED, MauvilleCity_BikeShop_EventScript_ExitMachHandbook
	end

MauvilleCity_BikeShop_EventScript_HowToRide::
	message MauvilleCity_BikeShop_Text_HowToRideMachBike
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_HowToTurn::
	message MauvilleCity_BikeShop_Text_HowToTurnMachBike
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_SandySlopes::
	message MauvilleCity_BikeShop_Text_SandySlopes
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ExitMachHandbook::
	release
	end

MauvilleCity_BikeShop_EventScript_AcroBikeHandbook::
	message MauvilleCity_BikeShop_Text_AcroHandbookWhichPage
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage::
	multichoice 0, 0, MULTI_ACRO_BIKE_INFO, FALSE
	switch VAR_RESULT
	case 0, MauvilleCity_BikeShop_EventScript_Wheelies
	case 1, MauvilleCity_BikeShop_EventScript_BunnyHops
	case 2, MauvilleCity_BikeShop_EventScript_Jumps
	case 3, MauvilleCity_BikeShop_EventScript_ExitAcroHandbook
	case MULTI_B_PRESSED, MauvilleCity_BikeShop_EventScript_ExitAcroHandbook
	end

MauvilleCity_BikeShop_EventScript_Wheelies::
	message MauvilleCity_BikeShop_Text_Wheelies
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_BunnyHops::
	message MauvilleCity_BikeShop_Text_BunnyHops
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_Jumps::
	message MauvilleCity_BikeShop_Text_Jumps
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ExitAcroHandbook::
	release
	end

MauvilleCity_BikeShop_Text_RydelGreeting:
	.string "Eh bien, eh bien, qui avons-nous là ?\n"
	.string "Un client plein d'énergie !\p"
	.string "Moi ? Vous pouvez m'appeler RYDEL.\n"
	.string "Je suis le propriétaire de ce magasin de vélos.$"

MauvilleCity_BikeShop_Text_DidYouComeFromFarAway:
	.string "RYDEL : Tes CHAUSSURES DE COURSE…\n"
	.string "Elles sont vraiment sales.\p"
	.string "Tu viens de loin ?$"

MauvilleCity_BikeShop_Text_GuessYouDontNeedBike:
	.string "RYDEL : C'est vrai ?\p"
	.string "Alors, je suppose que tu n'as pas besoin\n"
	.string "d'un de mes VÉLOS.$"

MauvilleCity_BikeShop_Text_GuessYouDontNeedBike2:
	.string "RYDEL : C'est vrai ?\p"
	.string "D'accord, c'est comme tu veux.$"

MauvilleCity_BikeShop_Text_ExplainBikesChooseWhichOne:
	.string "RYDEL : Hum, hum… … … … …\p"
	.string "Tu dis que tu es venu tout ce chemin\n"
	.string "depuis BOURG-EN-VOL ?\p"
	.string "Oh là là !\n"
	.string "C'est incroyablement loin !\p"
	.string "Si tu avais un de mes VÉLOS, tu pourrais\n"
	.string "aller partout facilement en sentant la\l"
	.string "douce caresse du vent !\p"
	.string "Voilà ce que je vais faire !\n"
	.string "Je vais t'offrir un VÉLO !\p"
	.string "Oh, attends une seconde !\p"
	.string "J'ai oublié de te dire qu'il y a\n"
	.string "deux types de VÉLOS !\p"
	.string "Il y a le VÉLO MACH et\n"
	.string "le VÉLO ACRO !\p"
	.string "Le VÉLO MACH est pour les cyclistes qui veulent\n"
	.string "sentir le vent sur leur corps !\p"
	.string "Et le VÉLO ACRO est pour ceux qui\n"
	.string "préfèrent les parcours techniques !\p"
	.string "Et tu sais le meilleur ?\p"
	.string "Les VÉLOS ACRO et MACH sont en fait\n"
	.string "un seul VÉLO ! Tout-en-un !\p"
	.string "Alors, veux-tu un VÉLO ?$"

MauvilleCity_BikeShop_Text_ChoseMachBike:
	.string "{PLAYER} a choisi le VÉLO MACH.$"

MauvilleCity_BikeShop_Text_ChoseAcroBike:
	.string "{PLAYER} a obtenu un VÉLO.$"

MauvilleCity_BikeShop_Text_ComeBackToSwitchBikes:
	.string "RYDEL : Profite bien de ton nouveau VÉLO !\p"
	.string "RYDEL : N'oublie pas d'appuyer sur le\n"
	.string "bouton R pour changer le mode du VÉLO.$"

MauvilleCity_BikeShop_Text_WantToSwitchBikes:
	.string "RYDEL : Tu apprécies\n"
	.string "ton VÉLO ?\p"
	.string "RYDEL : N'oublie pas d'appuyer sur le\n"
	.string "bouton R pour changer le mode du VÉLO.$"

MauvilleCity_BikeShop_Text_IllSwitchBikes:
	.string "RYDEL : D'accord, pas de problème !\n"
	.string "Je vais échanger les VÉLOS pour toi !$"

MauvilleCity_BikeShop_Text_ExchangedMachForAcro:
	.string "{PLAYER} a échangé le VÉLO MACH\n"
	.string "contre un VÉLO ACRO.$"

MauvilleCity_BikeShop_Text_ExchangedAcroForMach:
	.string "{PLAYER} a échangé le VÉLO ACRO\n"
	.string "contre un VÉLO MACH.$"

MauvilleCity_BikeShop_Text_HappyYouLikeIt:
	.string "RYDEL : Bien, bien !\n"
	.string "Je suis content que tu l'aimes !$"

MauvilleCity_BikeShop_Text_OhYourBikeIsInPC:
	.string "Oh ? Qu'est-il arrivé au VÉLO\n"
	.string "que je t'ai donné ?\p"
	.string "Ah, je comprends, tu l'as rangé dans ton PC.\p"
	.string "Eh bien, sors-le du stockage PC,\n"
	.string "et je serai heureux de l'échanger !\p"
	.string "Que le vent soit toujours dans ton dos\n"
	.string "lors de ton aventure !$"

MauvilleCity_BikeShop_Text_HandbooksAreInBack:
	.string "J'apprends des choses sur les VÉLOS\n"
	.string "pendant que je travaille ici.\p"
	.string "Si tu as besoin de conseils pour utiliser ton\n"
	.string "VÉLO, il y a quelques manuels à\l"
	.string "l'arrière.$"

MauvilleCity_BikeShop_Text_MachHandbookWhichPage:
	.string "C'est un manuel sur le VÉLO MACH.\p"
	.string "Quelle page veux-tu lire ?$"

MauvilleCity_BikeShop_Text_HowToRideMachBike:
	.string "Un VÉLO avance dans la direction où\n"
	.string "la croix directionnelle est pressée.\p"
	.string "Il accélère une fois lancé.\p"
	.string "Pour t'arrêter, relâche la croix directionnelle.\n"
	.string "Le VÉLO ralentira jusqu'à s'arrêter.\p"
	.string "Veux-tu lire une autre page ?$"

MauvilleCity_BikeShop_Text_HowToTurnMachBike:
	.string "Un VÉLO MACH est rapide, mais il ne peut pas\n"
	.string "s'arrêter très vite.\p"
	.string "C'est un peu difficile de prendre\n"
	.string "un virage.\p"
	.string "Relâche la croix directionnelle un peu\n"
	.string "avant le virage pour ralentir.\p"
	.string "Veux-tu lire une autre page ?$"

MauvilleCity_BikeShop_Text_SandySlopes:
	.string "Il y a de petites pentes sablonneuses\n"
	.string "partout dans la région de HOENN.\p"
	.string "Le sable meuble et friable rend\n"
	.string "l'escalade impossible normalement.\p"
	.string "Mais si tu as un VÉLO MACH, tu peux\n"
	.string "grimper rapidement une pente sablonneuse.\p"
	.string "Veux-tu lire une autre page ?$"

MauvilleCity_BikeShop_Text_AcroHandbookWhichPage:
	.string "C'est un manuel sur le VÉLO ACRO.\p"
	.string "Quelle page veux-tu lire ?$"

MauvilleCity_BikeShop_Text_Wheelies:
	.string "Appuie sur le bouton B en roulant,\n"
	.string "et la roue avant se soulève.\p"
	.string "Tu peux rouler avec la roue avant levée\n"
	.string "en utilisant la croix directionnelle.\p"
	.string "Cette technique s'appelle une roue arrière.\p"
	.string "Veux-tu lire une autre page ?$"

MauvilleCity_BikeShop_Text_BunnyHops:
	.string "En gardant le bouton B enfoncé,\n"
	.string "ton VÉLO peut sauter sur place.\p"
	.string "Cette technique s'appelle un bunny hop.\p"
	.string "Tu peux aussi rouler en sautant.\p"
	.string "Veux-tu lire une autre page ?$"

MauvilleCity_BikeShop_Text_Jumps:
	.string "Appuie sur le bouton B et la croix\n"
	.string "directionnelle en même temps pour sauter.\p"
	.string "Appuie sur la croix directionnelle sur le côté\n"
	.string "pour sauter sur le côté.\p"
	.string "Appuie en arrière pour faire changer de direction\n"
	.string "au VÉLO pendant le saut.\p"
	.string "Veux-tu lire une autre page ?$"
