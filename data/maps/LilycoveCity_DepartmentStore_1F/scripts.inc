.set LOCALID_LOTTERY_CLERK, 2

LilycoveCity_DepartmentStore_1F_MapScripts::
	.byte 0

LilycoveCity_DepartmentStore_1F_EventScript_Greeter::
	msgbox LilycoveCity_DepartmentStore_1F_Text_WelcomeToDeptStore, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_1F_EventScript_LotteryClerk::
	lock
	faceplayer
	dotimebasedevents
	goto_if_ne VAR_POKELOT_PRIZE_ITEM, ITEM_NONE, LilycoveCity_DepartmentStore_1F_EventScript_GivePrizeFromEarlier
	goto_if_set FLAG_DAILY_PICKED_LOTO_TICKET, LilycoveCity_DepartmentStore_1F_EventScript_ComeBackTomorrow
	msgbox LilycoveCity_DepartmentStore_1F_Text_LotteryCornerDrawTicket, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LilycoveCity_DepartmentStore_1F_EventScript_PleaseVisitAgain
	setflag FLAG_DAILY_PICKED_LOTO_TICKET
	message LilycoveCity_DepartmentStore_1F_Text_PleasePickTicket
	waitmessage
	special RetrieveLotteryNumber
	copyvar VAR_0x8008, VAR_RESULT
	special BufferLottoTicketNumber
	msgbox LilycoveCity_DepartmentStore_1F_Text_TicketNumberIsXPleaseWait, MSGBOX_DEFAULT
	applymovement 4, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	playse SE_PC_ON
	@special DoLotteryCornerComputerEffect
	special PickLotteryCornerTicket
	delay 220
	@special EndLotteryCornerComputerEffect
	delay 10
	applymovement 4, Common_Movement_FacePlayer
	waitmovement 0
	goto_if_eq VAR_0x8004, 0, LilycoveCity_DepartmentStore_1F_EventScript_NoMatch
	incrementgamestat GAME_STAT_WON_POKEMON_LOTTERY
	call_if_eq VAR_0x8006, 0, LilycoveCity_DepartmentStore_1F_EventScript_TicketMatchPartyMon
	call_if_eq VAR_0x8006, 1, LilycoveCity_DepartmentStore_1F_EventScript_TicketMatchPCMon
	bufferitemname STR_VAR_1, VAR_0x8005
	call_if_eq VAR_0x8004, 1, LilycoveCity_DepartmentStore_1F_EventScript_TwoDigitMatch
	call_if_eq VAR_0x8004, 2, LilycoveCity_DepartmentStore_1F_EventScript_ThreeDigitMatch
	call_if_eq VAR_0x8004, 3, LilycoveCity_DepartmentStore_1F_EventScript_FourDigitMatch
	call_if_eq VAR_0x8004, 4, LilycoveCity_DepartmentStore_1F_EventScript_FullMatch
	giveitem VAR_0x8005
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_DepartmentStore_1F_EventScript_RecordPrizeNoRoom
	special TryPutLotteryWinnerReportOnAir
	goto LilycoveCity_DepartmentStore_1F_EventScript_PleaseVisitAgain2
	end

LilycoveCity_DepartmentStore_1F_EventScript_TicketMatchPartyMon::
	msgbox LilycoveCity_DepartmentStore_1F_Text_TicketMatchesPartyMon, MSGBOX_DEFAULT
	return

LilycoveCity_DepartmentStore_1F_EventScript_TicketMatchPCMon::
	msgbox LilycoveCity_DepartmentStore_1F_Text_TicketMatchesPCMon, MSGBOX_DEFAULT
	return

LilycoveCity_DepartmentStore_1F_EventScript_ComeBackTomorrow::
	msgbox LilycoveCity_DepartmentStore_1F_Text_ComeBackTomorrow, MSGBOX_DEFAULT
	release
	end

LilycoveCity_DepartmentStore_1F_EventScript_PleaseVisitAgain::
	msgbox LilycoveCity_DepartmentStore_1F_Text_PleaseVisitAgain, MSGBOX_DEFAULT
	release
	end

LilycoveCity_DepartmentStore_1F_EventScript_NoMatch::
	msgbox LilycoveCity_DepartmentStore_1F_Text_NoNumbersMatched, MSGBOX_DEFAULT
	goto LilycoveCity_DepartmentStore_1F_EventScript_PleaseVisitAgain2
	end

LilycoveCity_DepartmentStore_1F_EventScript_PleaseVisitAgain2::
	msgbox LilycoveCity_DepartmentStore_1F_Text_PleaseVisitAgain2, MSGBOX_DEFAULT
	release
	end

LilycoveCity_DepartmentStore_1F_EventScript_TwoDigitMatch::
	msgbox LilycoveCity_DepartmentStore_1F_Text_TwoDigitsMatched, MSGBOX_DEFAULT
	return

LilycoveCity_DepartmentStore_1F_EventScript_ThreeDigitMatch::
	msgbox LilycoveCity_DepartmentStore_1F_Text_ThreeDigitsMatched, MSGBOX_DEFAULT
	return

LilycoveCity_DepartmentStore_1F_EventScript_FourDigitMatch::
	msgbox LilycoveCity_DepartmentStore_1F_Text_FourDigitsMatched, MSGBOX_DEFAULT
	return

LilycoveCity_DepartmentStore_1F_EventScript_FullMatch::
	msgbox LilycoveCity_DepartmentStore_1F_Text_AllFiveDigitsMatched, MSGBOX_DEFAULT
	return

LilycoveCity_DepartmentStore_1F_EventScript_RecordPrizeNoRoom::
	copyvar VAR_POKELOT_PRIZE_PLACE, VAR_0x8004
	copyvar VAR_POKELOT_PRIZE_ITEM, VAR_0x8005
	goto LilycoveCity_DepartmentStore_1F_EventScript_NoRoomForPrize
	end

LilycoveCity_DepartmentStore_1F_EventScript_NoRoomForPrize::
	msgbox LilycoveCity_DepartmentStore_1F_Text_NoRoomForThis, MSGBOX_DEFAULT
	release
	end

LilycoveCity_DepartmentStore_1F_EventScript_GivePrizeFromEarlier::
	msgbox LilycoveCity_DepartmentStore_1F_Text_PrizeWeveBeenHolding, MSGBOX_DEFAULT
	giveitem VAR_POKELOT_PRIZE_ITEM
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_DepartmentStore_1F_EventScript_NoRoomForPrize
	copyvar VAR_0x8004, VAR_POKELOT_PRIZE_PLACE
	copyvar VAR_0x8005, VAR_POKELOT_PRIZE_ITEM
	special TryPutLotteryWinnerReportOnAir
	setvar VAR_POKELOT_PRIZE_ITEM, ITEM_NONE
	setvar VAR_POKELOT_PRIZE_PLACE, 0
	release
	end

LilycoveCity_DepartmentStore_1F_EventScript_PokefanF::
	msgbox LilycoveCity_DepartmentStore_1F_Text_IBuyAllSortsOfThings, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_1F_EventScript_LittleGirl::
	msgbox LilycoveCity_DepartmentStore_1F_Text_MomBuyingMeFurniture, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_1F_EventScript_PokefanM::
	msgbox LilycoveCity_DepartmentStore_1F_Text_BuyingSomethingForAzumarill, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_1F_EventScript_Azumarill::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZUMARILL, CRY_MODE_NORMAL
	msgbox LilycoveCity_DepartmentStore_1F_Text_Azumarill, MSGBOX_DEFAULT
	waitmoncry
	release
	end

LilycoveCity_DepartmentStore_1F_EventScript_FloorNamesSign::
	msgbox LilycoveCity_DepartmentStore_1F_Text_FloorNamesSign, MSGBOX_SIGN
	end

LilycoveCity_DepartmentStore_1F_TraderWoman::
	msgbox LilycoveCity_DepartmentStore_1F_TraderWoman_Text, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_1F_Machine::
	playse SE_PC_ON
	delay 40
	checkmoney 10000, 0
	compare VAR_RESULT, TRUE
	goto_if_eq SCRIPT_SelfTrade_V1
	compare VAR_RESULT, FALSE
	goto_if_eq LilycoveCity_DepartmentStore_1F_Machine_NoMoney
	end

LilycoveCity_DepartmentStore_1F_Machine_NoMoney::
	msgbox LilycoveCity_DepartmentStore_1F_Machine_NoMoney_Text, MSGBOX_NPC
	end

SCRIPT_SelfTrade_V1::
	lock
	faceplayer
	msgbox SCRIPT_SelfTrade_Text_IllTradeIfYouWant, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq SCRIPT_SelfTrade_DeclineTrade
	special ChoosePartyMon
	waitstate
	compare VAR_0x8004, 255
	goto_if_eq SCRIPT_SelfTrade_DeclineTrade
	copyvar VAR_0x8005, VAR_0x8004
	setvar VAR_0x8004, 6
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	removemoney 10000, 0
	msgbox SCRIPT_SelfTrade_Text_ComeBack, MSGBOX_DEFAULT
	release
	end

SCRIPT_SelfTrade_V2::
	lock
	faceplayer
	msgbox SCRIPT_SelfTrade_Text_IllTradeIfYouWant, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq SCRIPT_SelfTrade_DeclineTrade
	special ChoosePartyMon
	waitstate
	compare VAR_0x8004, 255
	goto_if_eq SCRIPT_SelfTrade_DeclineTrade
	copyvar VAR_0x8005, VAR_0x8004
	setvar VAR_0x8004, 7
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	setvar VAR_0x8004, 8
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	msgbox SCRIPT_SelfTrade_Text_ComeBack, MSGBOX_DEFAULT
	release
	end

SCRIPT_SelfTrade_DeclineTrade::
	msgbox SCRIPT_SelfTrade_Text_YouDontWantToThatsOkay, MSGBOX_DEFAULT
	release
	end

SCRIPT_SelfTrade_Text_IllTradeIfYouWant:
	.string "Bienvenue dans l'application\n"
	.string "SELF-TRADER de la DEVON CORPORATION.\p"
	.string "Un de vos POKéMON sera auto-échangé.\n"
	.string "Une opération coûte 10 000¥.\p"
	.string "Voulez-vous continuer vers\n"
	.string "la sélection du POKéMON ?$"

SCRIPT_SelfTrade_Text_ComeBack:
	.string "Merci d'utiliser les produits\n"
	.string "de DEVON CORP.$"

SCRIPT_SelfTrade_Text_YouDontWantToThatsOkay:
	.string "Merci d'utiliser les produits\n"
	.string "de DEVON CORP.$"

LilycoveCity_DepartmentStore_1F_Machine_NoMoney_Text:
	.string "Désolé, vous n'avez pas assez d'argent.\n"
	.string "10 000¥ sont nécessaires pour une utilisation.\p"
	.string "Merci d'utiliser les produits\n"
	.string "de DEVON CORP.$"

LilycoveCity_DepartmentStore_1F_TraderWoman_Text:
	.string "Bienvenue au GRAND MAGASIN de NENUCRIQUE !\p"
	.string "Voulez-vous en savoir plus sur la nouvelle\n"
	.string "technologie développée par DEVON CORP. ?\p"
	.string "C'est une application SELF-TRADER !\p"
	.string "Grâce à un simple programme informatique,\n"
	.string "vous pouvez envoyer un POKéMON sur un\l"
	.string "serveur DEVON CORP. et le récupérer\l"
	.string "en quelques secondes seulement !\p"
	.string "Cela peut déclencher les conditions\n"
	.string "d'ÉVOLUTION de certaines espèces.\p"
	.string "Cependant, maintenir un système aussi\n"
	.string "complexe peut être coûteux.\p"
	.string "Vous pouvez payer une licence à vie pour\n"
	.string "1 000 000¥,\l"
	.string "ou payer à chaque utilisation, ce qui coûte\l"
	.string "10 000¥.\p"
	.string "Si vous voulez essayer, utilisez simplement\n"
	.string "l'ordinateur à votre droite !\p"
	.string "Merci d'utiliser les produits\n"
	.string "de DEVON CORP. !$"

LilycoveCity_DepartmentStore_1F_Text_WelcomeToDeptStore:
	.string "Bienvenue au GRAND MAGASIN de NENUCRIQUE.$"

LilycoveCity_DepartmentStore_1F_Text_IBuyAllSortsOfThings:
	.string "Chaque fois que je viens au GRAND MAGASIN,\n"
	.string "je finis toujours par acheter toutes sortes\l"
	.string "de choses parce que c'est tellement amusant.$"

LilycoveCity_DepartmentStore_1F_Text_MomBuyingMeFurniture:
	.string "Aujourd'hui, ma maman va m'acheter\n"
	.string "de jolis meubles.$"

LilycoveCity_DepartmentStore_1F_Text_BuyingSomethingForAzumarill:
	.string "J'achète quelque chose pour mon AZUMARILL\n"
	.string "en récompense pour avoir gagné un CONCOURS.$"

LilycoveCity_DepartmentStore_1F_Text_Azumarill:
	.string "AZUMARILL : Maririroo !$"

LilycoveCity_DepartmentStore_1F_Text_FloorNamesSign:
	.string "1F : COMPTOIR DE SERVICE\n"
	.string "     COIN LOTERIE\p"
	.string "2F : ZONE DES DRESSEURS\p"
	.string "3F : COLLECTION DE COMBAT\p"
	.string "4F : COIN CT\p"
	.string "5F : ÉTAGE DES POUPÉES POKé\p"
	.string "TOIT : PLAZA DU TOIT$"

@ Unused
LilycoveCity_DepartmentStore_1F_Text_WirelessCommIsFun:
	.string "La communication sans fil, c'est\n"
	.string "vraiment amusant, non ?\p"
	.string "Je pense que ça permet de faire des choses\n"
	.string "qui n'étaient pas possibles avant.\p"
	.string "Par exemple, vous pouvez maintenant échanger\n"
	.string "avec des personnes avec qui ce n'était pas possible.\p"
	.string "Je pense que ça va être passionnant !$"

@ Unused
LilycoveCity_DepartmentStore_1F_Text_SpreadWordAboutWirelessComm:
	.string "Je veux faire connaître à quel point\n"
	.string "la communication sans fil peut être amusante.$"
