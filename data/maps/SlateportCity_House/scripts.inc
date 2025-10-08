SlateportCity_House_MapScripts::
	.byte 0

SlateportCity_House_EventScript_PokefanM::
	msgbox SlateportCity_House_Text_NatureToDoWithStatGains, MSGBOX_NPC
	end

SlateportCity_House_EventScript_Girl::
	msgbox SlateportCity_House_Text_MustBeGoingToBattleTent, MSGBOX_NPC
	end

SlateportCity_House_Text_NatureToDoWithStatGains:
	.string "Mon POKéMON a une nature PRESSÉE.\p"
	.string "Sa VITESSE est plus élevée que celle\n"
	.string "de mes autres POKéMON.\p"
	.string "Peut-être que la nature a un lien avec\n"
	.string "l’augmentation des stats des POKéMON.$"

SlateportCity_House_Text_MustBeGoingToBattleTent:
	.string "Tu es un DRESSEUR, n’est-ce pas ?\p"
	.string "Puisque tu es venu à POIVRESSEL,\n"
	.string "tu dois aller au DÔME DE COMBAT.$"

