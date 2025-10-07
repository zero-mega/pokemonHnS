Route39_FarmHouse_MapScripts::
	.byte 0


Route39House_EventScript_FarmerF::
	lock
	faceplayer
	goto_if_eq VAR_ROUTE39_BARN, 5, Route39House_EventScript_FarmerFAfter
	msgbox Route39_Text_FarmerFInTrouble, MSGBOX_DEFAULT
	closemessage
	release
	end

Route39House_EventScript_FarmerFAfter::
	goto_if_set FLAG_GOT_TM_SNATCH, Route39House_EventScript_FarmerFAfterTM
	msgbox Route39_Text_FarmerFHealedMiltank, MSGBOX_DEFAULT
	giveitem ITEM_TM_SNATCH
	msgbox Route39_Text_FarmerFSnatchSpeech, MSGBOX_DEFAULT
	closemessage 
	setflag FLAG_GOT_TM_SNATCH
	release
	end

Route39House_EventScript_FarmerFAfterTM::
	msgbox Route39_Text_FarmerFSnatchSpeech, MSGBOX_DEFAULT
	closemessage
	release
	end

Route39_FarmHouse_EventScript_FarmerM::
	lock
	faceplayer
	goto_if_lt VAR_ROUTE39_BARN, 5, Route39_FarmHouse_EventScript_FarmerM_Sick
	showmoneybox 0, 0
	msgbox Route39_Text_FarmerMBuyMilk, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, Route39_FarmHouse_EventScript_FarmerMBuyMilk
	msgbox Route39_Text_FarmerMNoSale, MSGBOX_DEFAULT
	hidemoneybox
	closemessage
	end

Route39_FarmHouse_EventScript_FarmerMBuyMilk::
	checkmoney 500, 0
	goto_if_eq VAR_RESULT, FALSE, Route39_FarmHouse_EventScript_FarmerM_NotEnough
	additem ITEM_MOOMOO_MILK
	goto_if_eq VAR_RESULT, FALSE, Route39_FarmHouse_EventScript_FarmerM_BagFull
	removemoney 500
	updatemoneybox 0
	msgbox Route39FarmHouse_Text_WouldYouLikeAnother, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, Route39_FarmHouse_EventScript_FarmerMBuyMilk

	
	msgbox Route39_Text_FarmerMGotMilk, MSGBOX_DEFAULT
	closemessage
	playse MUS_OBTAIN_ITEM
	msgbox Route39_Text_GotMilk, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	release
	end

Route39_FarmHouse_EventScript_FarmerM_Sick::
	msgbox Route39_Text_FarmerMSickCow, MSGBOX_DEFAULT
	closemessage
	release
	end

Route39_FarmHouse_EventScript_FarmerM_BagFull::
	msgbox Route39_Text_FarmerMNoRoom, MSGBOX_DEFAULT
	hidemoneybox
	closemessage
	release
	end

Route39_FarmHouse_EventScript_FarmerM_NotEnough::
	msgbox Route39_Text_FarmerMNoMoney, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	release
	end

Route39_Text_FarmerMSickCow:
	.string "Ma Écrémeuh ne me donne plus\n"
	.string "de lait.\p"
	.string "Cette FERME est connue pour son lait.\p"
	.string "Presque tout le monde en veut.\p"
	.string "Elle me donnera plein de lait si\n"
	.string "je lui donne plein de BAIES,\l"
	.string "j'parie.$"

Route39_Text_FarmerMBuyMilk:
	.string "Tu veux mon LAIT MEUMEU ?\p"
	.string "C'est ma fierté, tu sais.\p"
	.string "Donne-le à un POKéMON pour soigner ses PV !\p"
	.string "Je t'en donne pour seulement\n"
	.string "¥500.$"

Route39_Text_FarmerMGotMilk:
	.string "Tiens !\n"
	.string "Savoure-le bien !$"

Route39_Text_FarmerMNoMoney:
	.string "Désolé.\n"
	.string "Pas d'argent, pas de vente !$"

Route39_Text_FarmerMNoRoom:
	.string "J'crois que ton SAC est plein.$"

Route39_Text_FarmerMNoSale:
	.string "T'en veux pas ?\n"
	.string "Reviens quand tu veux !$"

Route39FarmHouse_Text_WouldYouLikeAnother:
	.string "Tu en veux un autre ?$"

Route39_Text_GotMilk:
	.string "{PLAYER} obtient du LAIT MEUMEU.$"

Route39_Text_FarmerMMilking:
	.string "J'vais aller traire mes vaches.$"

Route39_Text_FarmerFInTrouble:
	.string "Notre lait part même jusqu'à\n"
	.string "KANTO.\p"
	.string "Si notre propre Écrémeuh ne\n"
	.string "nous donne plus de lait, on est fichus.$"

Route39_Text_FarmerFHealedMiltank:
	.string "Tu as soigné notre Écrémeuh, chéri(e).\n"
	.string "Maintenant elle donne du LAIT MEUMEU à nouveau.\p"
	.string "Tiens, c'est pour te remercier.$"

Route39_Text_FarmerFSnatchSpeech:
	.string "Ça, c'est RAPINE.\p"
	.string "C'est une capacité rusée qui permet\n"
	.string "à un POKéMON de voler la capacité\l"
	.string "de l'adversaire juste avant qu'il l'utilise.\p"
	.string "Si plusieurs POKéMON utilisent\n"
	.string "RAPINE, seul le plus lent\l"
	.string "réussira à voler la capacité.\p"
	.string "Utilise-la intelligemment, chéri(e).\n"
	.string "Le timing, c'est tout.$"
