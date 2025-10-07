Route30_House_MapScripts::
	.byte 0

Route30_House_EventScript_BaldMan::
	lock
	faceplayer
	goto_if_set FLAG_GOT_BERRY_ROUTE_30_HOUSE, Route30_House_EventScript_BaldMan2
	msgbox Route30_BerryHouse_Text_MonEatBerries, MSGBOX_DEFAULT
	giveitem ITEM_CHERI_BERRY
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	closemessage
	setflag FLAG_GOT_BERRY_ROUTE_30_HOUSE
Route30_House_EventScript_BaldMan2::
	msgbox Route30_BerryHouse_Text_CheckTrees MSGBOX_DEFAULT
	closemessage
	release
	end

Route30_BerryHouse_Text_MonEatBerries:
	.string "Lorsque tu suis ce chemin vers le nord,\n"
	.string "tu verras la maison de MR. POKéMON.\p"
	.string "Mais avant d’y aller, permets-moi de\n"
	.string "te parler des BAIES !\p"
	.string "Les POKéMON deviennent plus en santé\n"
	.string "en mangeant des BAIES.\p"
	.string "Ils peuvent même manger les BAIES\n"
	.string "qu’ils tiennent pendant un combat.\p"
	.string "Les BAIES peuvent aussi être transformées\n"
	.string "en BALLS par KURT à ÉCORCIA.\p"
	.string "Tiens. Je t’en donne une !$"

Route30_BerryHouse_Text_CheckTrees:
	.string "Vérifie les arbres pour des BAIES.\n"
	.string "Elles repoussent après quelques heures.$"
