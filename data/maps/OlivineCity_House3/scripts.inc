OlivineCity_House3_MapScripts::
	.byte 0

OlivineCityHouse3_EventScriptFishingGuru::
	lock
	faceplayer
	checkitem ITEM_GOOD_ROD
	goto_if_eq VAR_RESULT, TRUE, OlivineCityHouse3_EventScriptFishingGuru2
	msgbox OlivineCity_Text_OfferGoodRod, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, OlivineCityHouse3_EventScriptFishingGuruRefused
	msgbox OlivineCity_Text_GiveGoodRod, MSGBOX_DEFAULT
	giveitem ITEM_GOOD_ROD
	msgbox OlivineCity_Text_GaveGoodRod, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCityHouse3_EventScriptFishingGuru2::
	msgbox OlivineCity_Text_HaveGoodRod, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCityHouse3_EventScriptFishingGuruRefused::
	msgbox OlivineCity_Text_DontWantGoodRod, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_Text_OfferGoodRod:
	.string "OLIVINE est au bord de la mer !\p"
	.string "Et s'il y a la mer, il y a\n"
	.string "forcément des poissons !\p"
	.string "Je pêche ici depuis 30 ans.\p"
	.string "Veux-tu faire face à la mer\n"
	.string "et essayer la pêche ?$"

OlivineCity_Text_GiveGoodRod:
	.string "Ah, hahaha ! Nous avons un\n"
	.string "nouvel apprenti pêcheur !$"

OlivineCity_Text_GaveGoodRod:
	.string "Les poissons ne vivent pas\n"
	.string "que dans la mer—il y en a\l"
	.string "partout où il y a de l'eau.\p"
	.string "D'ailleurs, ton POKéDEX indique\n"
	.string "les groupes de pêche de POKéMON.\p"
	.string "Différents endroits peuvent\n"
	.string "avoir des types de poissons similaires.$"

OlivineCity_Text_DontWantGoodRod:
	.string "Quoi ? Tu n'aimes pas pêcher !?\n"
	.string "C'est incompréhensible !$"

OlivineCity_Text_HaveGoodRod:
	.string "Comment ça va ?\n"
	.string "As-tu attrapé une grosse prise ?$"
