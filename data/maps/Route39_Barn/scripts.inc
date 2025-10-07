Route39_Barn_MapScripts::
	.byte 0

Route39_Barn_EventScript_Miltank::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MILTANK, CRY_MODE_NORMAL
	goto_if_eq VAR_ROUTE39_BARN, 0, Route39_Barn_EventScript_Miltank_NeedBerries5
	goto_if_eq VAR_ROUTE39_BARN, 1, Route39_Barn_EventScript_Miltank_NeedBerries4
	goto_if_eq VAR_ROUTE39_BARN, 2, Route39_Barn_EventScript_Miltank_NeedBerries3
	goto_if_eq VAR_ROUTE39_BARN, 3, Route39_Barn_EventScript_Miltank_NeedBerries2
	goto_if_eq VAR_ROUTE39_BARN, 4, Route39_Barn_EventScript_Miltank_NeedBerries1
	msgbox Route39_Text_MoomooHappyMoo, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route39_Barn_EventScript_Miltank_NeedBerries5::
	msgbox Route39_Text_MoomooWeakMoo, MSGBOX_DEFAULT
	waitmoncry
	closemessage
	delay 10
	msgbox Route39_Text_BarnCryIsWeak, MSGBOX_YESNO
	call_if_eq VAR_RESULT, FALSE, Route39_Barn_EventScript_Miltank_Refused

	checkitem ITEM_ORAN_BERRY
	goto_if_eq VAR_RESULT, FALSE, Route39_Barn_EventScript_Miltank_NoBerries
	removeitem ITEM_ORAN_BERRY, 1
	playse SE_USE_ITEM
	msgbox Route39_Text_BarnGaveBerry, MSGBOX_AUTOCLOSE
	waitse
	msgbox Route39_Text_BarnLittleHealthier, MSGBOX_DEFAULT
	closemessage

	setvar VAR_ROUTE39_BARN, 1
	release
	end
Route39_Barn_EventScript_Miltank_NeedBerries4::
	msgbox Route39_Text_MoomooWeakMoo, MSGBOX_DEFAULT
	waitmoncry
	closemessage
	delay 10
	msgbox Route39_Text_BarnCryIsWeak, MSGBOX_YESNO
	call_if_eq VAR_RESULT, FALSE, Route39_Barn_EventScript_Miltank_Refused

	checkitem ITEM_ORAN_BERRY
	goto_if_eq VAR_RESULT, FALSE, Route39_Barn_EventScript_Miltank_NoBerries
	removeitem ITEM_ORAN_BERRY, 1
	playse SE_USE_ITEM
	msgbox Route39_Text_BarnGaveBerry, MSGBOX_AUTOCLOSE
	waitse
	msgbox Route39_Text_BarnLittleHealthier, MSGBOX_DEFAULT
	closemessage

	setvar VAR_ROUTE39_BARN, 2
	release
	end
Route39_Barn_EventScript_Miltank_NeedBerries3::
	msgbox Route39_Text_MoomooWeakMoo, MSGBOX_DEFAULT
	waitmoncry
	closemessage
	delay 10
	msgbox Route39_Text_BarnCryIsWeak, MSGBOX_YESNO
	call_if_eq VAR_RESULT, FALSE, Route39_Barn_EventScript_Miltank_Refused
	checkitem ITEM_ORAN_BERRY
	goto_if_eq VAR_RESULT, FALSE, Route39_Barn_EventScript_Miltank_NoBerries
	removeitem ITEM_ORAN_BERRY, 1
	playse SE_USE_ITEM
	msgbox Route39_Text_BarnGaveBerry, MSGBOX_AUTOCLOSE
	waitse
	msgbox Route39_Text_BarnQuiteHealthy, MSGBOX_DEFAULT
	closemessage
	setvar VAR_ROUTE39_BARN, 3
	release
	end
Route39_Barn_EventScript_Miltank_NeedBerries2::
	msgbox Route39_Text_MoomooWeakMoo, MSGBOX_DEFAULT
	waitmoncry
	closemessage
	delay 10
	msgbox Route39_Text_BarnCryIsWeak, MSGBOX_YESNO
	call_if_eq VAR_RESULT, FALSE, Route39_Barn_EventScript_Miltank_Refused
	checkitem ITEM_ORAN_BERRY
	goto_if_eq VAR_RESULT, FALSE, Route39_Barn_EventScript_Miltank_NoBerries
	removeitem ITEM_ORAN_BERRY, 1
	playse SE_USE_ITEM
	msgbox Route39_Text_BarnGaveBerry, MSGBOX_AUTOCLOSE
	waitse
	msgbox Route39_Text_BarnQuiteHealthy, MSGBOX_DEFAULT
	closemessage
	setvar VAR_ROUTE39_BARN, 4
	release
	end
Route39_Barn_EventScript_Miltank_NeedBerries1::
	msgbox Route39_Text_MoomooWeakMoo, MSGBOX_DEFAULT
	waitmoncry
	closemessage
	delay 10
	msgbox Route39_Text_BarnCryIsWeak, MSGBOX_YESNO
	call_if_eq VAR_RESULT, FALSE, Route39_Barn_EventScript_Miltank_Refused
	checkitem ITEM_ORAN_BERRY
	goto_if_eq VAR_RESULT, FALSE, Route39_Barn_EventScript_Miltank_NoBerries
	removeitem ITEM_ORAN_BERRY, 1
	playse SE_USE_ITEM
	msgbox Route39_Text_BarnGaveBerry, MSGBOX_AUTOCLOSE
	waitse
	msgbox Route39_Text_BarnTotallyHealthy, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_BADGE 
	waitfanfare
	closemessage
	setvar VAR_ROUTE39_BARN, 5
	release
	end

Route39_Barn_EventScript_Miltank_Refused::
	msgbox Route39_Text_BarnRefusedBerry, MSGBOX_DEFAULT
	closemessage
	release
	end

Route39_Barn_EventScript_Miltank_NoBerries::
	msgbox Route39_Text_BarnNoBerries, MSGBOX_DEFAULT
	release
	end

Route39_Barn_EventScript_Twins::
	lock
	faceplayer
	goto_if_eq VAR_ROUTE39_BARN, 5, Route39_Barn_EventScript_TwinsAfter
	msgbox Route39_Text_BarnTwinMoomooIsSick, MSGBOX_DEFAULT
	closemessage
	release
	end

Route39_Barn_EventScript_TwinsAfter::
	msgbox Route39_Text_BarnTwinFeedingMoomoo
	closemessage
	release
	end

Route39_Text_BarnTwinMoomooIsSick:
	.string "ÉCRÉMEUH est malade…\p"
	.string "Elle a besoin de beaucoup de BAIES ORAN.$"

Route39_Text_BarnTwinFeedingMoomoo:
	.string "ÉCRÉMEUH va beaucoup mieux !\n"
	.string "Merci !$"

Route39_Text_MoomooWeakMoo:
	.string "ÉCRÉMEUH : …Moo…$"

Route39_Text_BarnCryIsWeak:
	.string "Son cri est faible…\n"
	.string "Donner une BAIE ORAN à ÉCRÉMEUH ?$"

Route39_Text_MoomooHappyMoo:
	.string "ÉCRÉMEUH : Mooo !$"

Route39_Text_BarnGaveBerry:
	.string "{PLAYER} donne une BAIE ORAN à\n"
	.string "ÉCRÉMEUH.$"

Route39_Text_BarnLittleHealthier:
	.string "ÉCRÉMEUH est un peu\n"
	.string "plus en forme !$"

Route39_Text_BarnQuiteHealthy:
	.string "ÉCRÉMEUH est en bien\n"
	.string "meilleure santé !$"

Route39_Text_BarnTotallyHealthy:
	.string "ÉCRÉMEUH est totalement\n"
	.string "remise !$"

Route39_Text_BarnNoBerries:
	.string "{PLAYER} n'a pas de BAIES ORAN…$"

Route39_Text_BarnRefusedBerry:
	.string "{PLAYER} ne veut pas donner de\n"
	.string "BAIE ORAN.\p"
	.string "ÉCRÉMEUH a l'air triste.$"
