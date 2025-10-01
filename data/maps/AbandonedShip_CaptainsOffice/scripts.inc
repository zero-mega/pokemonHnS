AbandonedShip_CaptainsOffice_MapScripts::
	.byte 0

AbandonedShip_CaptainsOffice_EventScript_CaptSternAide::
	lock
	faceplayer
	goto_if_set FLAG_EXCHANGED_SCANNER, AbandonedShip_CaptainsOffice_EventScript_ThisIsSSCactus
	checkitem ITEM_SCANNER
	goto_if_eq VAR_RESULT, TRUE, AbandonedShip_CaptainsOffice_EventScript_CanYouDeliverScanner
	goto_if_set FLAG_ITEM_GARBAGEFLAG, AbandonedShip_CaptainsOffice_EventScript_ThisIsSSCactus
	msgbox AbandonedShip_CaptainsOffice_Text_NoSuccessFindingScanner, MSGBOX_DEFAULT
	release
	end

AbandonedShip_CaptainsOffice_EventScript_CanYouDeliverScanner::
	msgbox AbandonedShip_CaptainsOffice_Text_OhCanYouDeliverScanner, MSGBOX_DEFAULT
	release
	end

AbandonedShip_CaptainsOffice_EventScript_ThisIsSSCactus::
	msgbox AbandonedShip_CaptainsOffice_Text_ThisIsSSCactus, MSGBOX_DEFAULT
	release
	end

AbandonedShip_CaptainsOffice_Text_NoSuccessFindingScanner:
	.string "J’enquête sur ce navire au nom du\n"
	.string "CAPT. STERN.\p"
	.string "Il m’a aussi demandé de trouver un SCANNER,\n"
	.string "mais je n’ai pas eu de succès…$"

AbandonedShip_CaptainsOffice_Text_OhCanYouDeliverScanner:
	.string "Oh ! C’est un SCANNER !\p"
	.string "Dis, pourrais-tu le remettre au\n"
	.string "CAPT. STERN ?\p"
	.string "Je veux encore examiner ce navire\n"
	.string "un peu plus.$"

AbandonedShip_CaptainsOffice_Text_ThisIsSSCactus:
	.string "Ce navire s’appelle S.S. CACTUS.\n"
	.string "Il semble venir d’une époque ancienne.$"

