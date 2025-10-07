.set LOCALID_BRINEY, 1
.set LOCALID_PEEKO, 2

Route104_MrBrineysHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route104_MrBrineysHouse_OnTransition
	.byte 0

Route104_MrBrineysHouse_OnTransition:
	setflag FLAG_LANDMARK_MR_BRINEY_HOUSE
	call_if_eq VAR_GARBAGEVAR, 1, Route104_MrBrineysHouse_EventScript_SetBrineyPeekoPos
	call_if_set FLAG_RECEIVED_POKENAV, Route104_MrBrineysHouse_EventScript_HideRustboroRival
	end

Route104_MrBrineysHouse_EventScript_HideRustboroRival::
	setflag FLAG_GARBAGEFLAG
	return

Route104_MrBrineysHouse_EventScript_SetBrineyPeekoPos::
	setobjectxyperm LOCALID_BRINEY, 9, 3
	setobjectmovementtype LOCALID_BRINEY, MOVEMENT_TYPE_WALK_SEQUENCE_DOWN_LEFT_UP_RIGHT
	setobjectxyperm LOCALID_PEEKO, 9, 6
	setobjectmovementtype LOCALID_PEEKO, MOVEMENT_TYPE_WALK_SEQUENCE_LEFT_UP_RIGHT_DOWN
	return

Route104_MrBrineysHouse_EventScript_Briney::
	lock
	faceplayer
	call_if_unset FLAG_MR_BRINEY_SAILING_INTRO, Route104_MrBrineysHouse_EventScript_SailingIntro
	goto_if_unset FLAG_DELIVERED_STEVEN_LETTER, Route104_MrBrineysHouse_EventScript_SailBothDeliveries
	goto_if_unset FLAG_DELIVERED_DEVON_GOODS, Route104_MrBrineysHouse_EventScript_SailDeliverPackage
	goto Route104_MrBrineysHouse_EventScript_WhereAreWeBound
	end

Route104_MrBrineysHouse_EventScript_SailingIntro::
	setflag FLAG_MR_BRINEY_SAILING_INTRO
	msgbox Route104_MrBrineysHouse_Text_WaitUpPeeko, MSGBOX_DEFAULT
	msgbox Route104_MrBrineysHouse_Text_ItsYouLetsSailToDewford, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route104_MrBrineysHouse_EventScript_DeclineDeliverySailing
	goto Route104_MrBrineysHouse_EventScript_SailToDewford
	end

Route104_MrBrineysHouse_EventScript_WhereAreWeBound::
	message Route104_MrBrineysHouse_Text_WhereAreWeBound
	waitmessage
	multichoicedefault 20, 8, MULTI_BRINEY_OFF_DEWFORD, 1, FALSE
	switch VAR_RESULT
	case 0, Route104_MrBrineysHouse_EventScript_SailToDewford
	case 1, Route104_MrBrineysHouse_EventScript_DeclineSailing
	case MULTI_B_PRESSED, Route104_MrBrineysHouse_EventScript_DeclineSailing
	end

Route104_MrBrineysHouse_EventScript_SailBothDeliveries::
	msgbox Route104_MrBrineysHouse_Text_NeedToMakeDeliveriesSailToDewford, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route104_MrBrineysHouse_EventScript_DeclineDeliverySailing
	goto Route104_MrBrineysHouse_EventScript_SailToDewford
	end

Route104_MrBrineysHouse_EventScript_SailDeliverPackage::
	msgbox Route104_MrBrineysHouse_Text_NeedToDeliverPackageSailToDewford, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route104_MrBrineysHouse_EventScript_DeclineDeliverySailing
	goto Route104_MrBrineysHouse_EventScript_SailToDewford
	end

Route104_MrBrineysHouse_EventScript_DeclineDeliverySailing::
	msgbox Route104_MrBrineysHouse_Text_DeclineDeliverySail, MSGBOX_DEFAULT
	release
	end

Route104_MrBrineysHouse_EventScript_DeclineSailing::
	msgbox Route104_MrBrineysHouse_Text_TellMeWheneverYouWantToSail, MSGBOX_DEFAULT
	release
	end

Route104_MrBrineysHouse_EventScript_SailToDewford::
	msgbox Route104_MrBrineysHouse_Text_SetSailForDewford, MSGBOX_DEFAULT
	call EventScript_BackupMrBrineyLocation
	setvar VAR_GARBAGEVAR, 1
	clearflag FLAG_GARBAGEFLAG
	setflag FLAG_GARBAGEFLAG
	setflag FLAG_GARBAGEFLAG
	setvar VAR_GARBAGEVAR, 8
	setvar VAR_GARBAGEVAR, 2
	setflag FLAG_GARBAGEFLAG
	setflag FLAG_HIDE_ROUTE_104_RIVAL
	warp MAP_ROUTE104, 13, 51
	waitstate
	releaseall
	end

Route104_MrBrineysHouse_EventScript_Peeko::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_WINGULL, CRY_MODE_NORMAL
	msgbox Route104_MrBrineysHouse_Text_Peeko, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route104_MrBrineysHouse_Text_WaitUpPeeko:
	.string "MR. BRINEY : Attends, fillette !\n"
	.string "Attends-moi, PEEKO !$"

Route104_MrBrineysHouse_Text_ItsYouLetsSailToDewford:
	.string "Hein ? Tu es {PLAYER}{KUN} !\n"
	.string "Tu as sauvé ma chère PEEKO !\l"
	.string "Nous te devons tant !\p"
	.string "Quoi ?\n"
	.string "Tu veux naviguer avec moi ?\p"
	.string "Hmhm…\p"
	.string "Tu dois livrer une LETTRE à MYOKARA\n"
	.string "et un colis à POIVRESSEL, c'est ça ?\p"
	.string "Quelle vie bien remplie tu mènes !\p"
	.string "Mais, bien sûr, ce que tu demandes\n"
	.string "n'est pas un problème du tout.\p"
	.string "Tu es tombé sur le bon marin !\n"
	.string "Nous mettons le cap sur MYOKARA !$"

Route104_MrBrineysHouse_Text_SetSailForDewford:
	.string "MR. BRINEY : MYOKARA, alors !\p"
	.string "Levez l'ancre !\n"
	.string "PEEKO, on part en mer, ma chérie !$"

Route104_MrBrineysHouse_Text_DeclineDeliverySail:
	.string "MR. BRINEY : Ah bon ?\n"
	.string "Tes livraisons peuvent attendre ?\p"
	.string "Dis-moi simplement quand tu voudras\n"
	.string "prendre la mer !$"

Route104_MrBrineysHouse_Text_NeedToMakeDeliveriesSailToDewford:
	.string "MR. BRINEY : Ohé !\n"
	.string "Je sais exactement ce que tu veux dire !\p"
	.string "Tu dois livrer une LETTRE à MYOKARA\n"
	.string "et un colis à POIVRESSEL.\p"
	.string "Ce que tu me demandes n'est pas un souci\n"
	.string "du tout—je suis l'homme de la situation !\p"
	.string "D'abord, cap sur MYOKARA !$"

Route104_MrBrineysHouse_Text_NeedToDeliverPackageSailToDewford:
	.string "MR. BRINEY : Ohé !\n"
	.string "Je sais exactement ce que tu veux dire !\p"
	.string "Tu dois livrer un colis au\n"
	.string "CAPT. PORTUA à POIVRESSEL.\p"
	.string "Ce que tu me demandes n'est pas un souci\n"
	.string "du tout—je suis l'homme de la situation !\p"
	.string "D'abord, cap sur MYOKARA !$"

Route104_MrBrineysHouse_Text_WhereAreWeBound:
	.string "MR. BRINEY : Ohé !\n"
	.string "Pour toi, je prends la mer quand tu veux !\p"
	.string "Alors, mon ami, où allons-nous ?$"

Route104_MrBrineysHouse_Text_TellMeWheneverYouWantToSail:
	.string "MR. BRINEY : Ah bon ?\n"
	.string "Eh bien, PEEKO te doit la vie.\p"
	.string "Dis-moi simplement quand tu voudras\n"
	.string "prendre la mer !$"

Route104_MrBrineysHouse_Text_Peeko:
	.string "PEEKO : Pii piihyoro !$"
