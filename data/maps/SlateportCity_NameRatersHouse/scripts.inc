SlateportCity_NameRatersHouse_MapScripts::
	.byte 0

SlateportCity_NameRatersHouse_EventScript_NameRater::
	lock
	faceplayer
	msgbox SlateportCity_NameRatersHouse_Text_PleasedToRateMonNickname, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SlateportCity_NameRatersHouse_EventScript_ChooseMonToRate
	goto_if_eq VAR_RESULT, NO, SlateportCity_NameRatersHouse_EventScript_DeclineNameRate
	end

SlateportCity_NameRatersHouse_EventScript_ChooseMonToRate::
	msgbox SlateportCity_NameRatersHouse_Text_CritiqueWhichMonNickname, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	goto_if_ne VAR_0x8004, PARTY_NOTHING_CHOSEN, SlateportCity_NameRatersHouse_EventScript_RateMonNickname
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, SlateportCity_NameRatersHouse_EventScript_DeclineNameRate
	end

SlateportCity_NameRatersHouse_EventScript_DeclineNameRate::
	msgbox SlateportCity_NameRatersHouse_Text_DoVisitAgain, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_RateMonNickname::
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, SlateportCity_NameRatersHouse_EventScript_CantRateEgg
	special BufferMonNickname
	@special IsMonOTIDNotPlayers
	@goto_if_eq VAR_RESULT, TRUE, SlateportCity_NameRatersHouse_EventScript_PlayerNotMonsOT
	@specialvar VAR_RESULT, MonOTNameNotPlayer
	special BufferMonNickname
	@goto_if_eq VAR_RESULT, TRUE, SlateportCity_NameRatersHouse_EventScript_PlayerNotMonsOT
	msgbox SlateportCity_NameRatersHouse_Text_FineNameSuggestBetterOne, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SlateportCity_NameRatersHouse_EventScript_ChangeNickname
	goto_if_eq VAR_RESULT, NO, SlateportCity_NameRatersHouse_EventScript_DeclineNameRate
	end

SlateportCity_NameRatersHouse_EventScript_CantRateEgg::
	msgbox SlateportCity_NameRatersHouse_Text_ThatIsMerelyAnEgg, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_PlayerNotMonsOT::
	msgbox SlateportCity_NameRatersHouse_Text_MagnificentName, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_ChangeNickname::
	msgbox SlateportCity_NameRatersHouse_Text_WhatShallNewNameBe, MSGBOX_DEFAULT
	call Common_EventScript_NameReceivedPartyMon
	specialvar VAR_RESULT, TryPutNameRaterShowOnTheAir
	special BufferMonNickname
	goto_if_eq VAR_RESULT, TRUE, SlateportCity_NameRatersHouse_EventScript_NewNameDifferent
	msgbox SlateportCity_NameRatersHouse_Text_NameNoDifferentYetSuperior, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_NewNameDifferent::
	msgbox SlateportCity_NameRatersHouse_Text_MonShallBeKnownAsName, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_Text_PleasedToRateMonNickname:
	.string "Bonjour, bonjour ! Je suis le JUGE-\n"
	.string "SURNOM ! Je suis le devin des noms !\p"
	.string "Je serais ravi d'évaluer le surnom\n"
	.string "de votre POKéMON.$"

SlateportCity_NameRatersHouse_Text_CritiqueWhichMonNickname:
	.string "Quel surnom de POKéMON dois-je\n"
	.string "évaluer ?$"

SlateportCity_NameRatersHouse_Text_FineNameSuggestBetterOne:
	.string "Hmm… {STR_VAR_1}, c'est bien ça ?\n"
	.string "C'est un très joli surnom.\p"
	.string "Mais ! Que diriez-vous si je vous\n"
	.string "suggérais un nom un peu meilleur ?$"

SlateportCity_NameRatersHouse_Text_WhatShallNewNameBe:
	.string "Ah, très bien. Alors, quel sera le\n"
	.string "nouveau surnom ?$"

SlateportCity_NameRatersHouse_Text_MonShallBeKnownAsName:
	.string "Voilà ! Désormais, ce POKéMON sera\n"
	.string "connu sous le nom de {STR_VAR_1} !\p"
	.string "C'est un meilleur nom qu'avant !\n"
	.string "Quelle chance pour vous !$"

SlateportCity_NameRatersHouse_Text_DoVisitAgain:
	.string "Je vois.\n"
	.string "Revenez me voir quand vous voulez.$"

SlateportCity_NameRatersHouse_Text_NameNoDifferentYetSuperior:
	.string "Voilà ! Désormais, ce POKéMON sera\n"
	.string "connu sous le nom de {STR_VAR_1} !\p"
	.string "Cela ne semble pas différent, et\n"
	.string "pourtant, c'est bien supérieur !\p"
	.string "Quelle chance pour vous !$"

SlateportCity_NameRatersHouse_Text_MagnificentName:
	.string "Hmm… {STR_VAR_1}, c'est bien ça !\p"
	.string "C'est un surnom magnifique !\n"
	.string "Il est irréprochable !\p"
	.string "Prenez bien soin de votre\n"
	.string "{STR_VAR_1} maintenant et toujours.$"

SlateportCity_NameRatersHouse_Text_ThatIsMerelyAnEgg:
	.string "Voyons, voyons.\n"
	.string "Ce n'est qu'un ŒUF !$"
