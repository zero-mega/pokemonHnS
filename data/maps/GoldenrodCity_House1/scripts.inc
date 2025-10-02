GoldenrodCity_House1_MapScripts::
	.byte 0

GoldenrodCity_NameRatersHouse_EventScript_NameRater::
	lock
	faceplayer
	msgbox GoldenrodCity_NameRatersHouse_Text_PleasedToRateMonNickname, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, GoldenrodCity_NameRatersHouse_EventScript_ChooseMonToRate
	goto_if_eq VAR_RESULT, NO, GoldenrodCity_NameRatersHouse_EventScript_DeclineNameRate
	end

GoldenrodCity_NameRatersHouse_EventScript_ChooseMonToRate::
	msgbox GoldenrodCity_NameRatersHouse_Text_CritiqueWhichMonNickname, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	lock
	goto_if_ne VAR_0x8004, PARTY_NOTHING_CHOSEN, GoldenrodCity_NameRatersHouse_EventScript_RateMonNickname
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, GoldenrodCity_NameRatersHouse_EventScript_DeclineNameRate
	end

GoldenrodCity_NameRatersHouse_EventScript_DeclineNameRate::
	msgbox GoldenrodCity_NameRatersHouse_Text_DoVisitAgain, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_NameRatersHouse_EventScript_RateMonNickname::
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, GoldenrodCity_NameRatersHouse_EventScript_CantRateEgg
	special BufferMonNickname
	@special IsMonOTIDNotPlayers
	@goto_if_eq VAR_RESULT, TRUE, GoldenrodCity_NameRatersHouse_EventScript_PlayerNotMonsOT
	@specialvar VAR_RESULT, MonOTNameNotPlayer
	special BufferMonNickname
	@goto_if_eq VAR_RESULT, TRUE, GoldenrodCity_NameRatersHouse_EventScript_PlayerNotMonsOT
	msgbox GoldenrodCity_NameRatersHouse_Text_FineNameSuggestBetterOne, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, GoldenrodCity_NameRatersHouse_EventScript_ChangeNickname
	goto_if_eq VAR_RESULT, NO, GoldenrodCity_NameRatersHouse_EventScript_DeclineNameRate
	end

GoldenrodCity_NameRatersHouse_EventScript_CantRateEgg::
	msgbox GoldenrodCity_NameRatersHouse_Text_ThatIsMerelyAnEgg, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_NameRatersHouse_EventScript_PlayerNotMonsOT::
	msgbox GoldenrodCity_NameRatersHouse_Text_MagnificentName, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_NameRatersHouse_EventScript_ChangeNickname::
	msgbox GoldenrodCity_NameRatersHouse_Text_WhatShallNewNameBe, MSGBOX_DEFAULT
	call Common_EventScript_NameReceivedPartyMon
	specialvar VAR_RESULT, TryPutNameRaterShowOnTheAir
	special BufferMonNickname
	goto_if_eq VAR_RESULT, TRUE, GoldenrodCity_NameRatersHouse_EventScript_NewNameDifferent
	msgbox GoldenrodCity_NameRatersHouse_Text_NameNoDifferentYetSuperior, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_NameRatersHouse_EventScript_NewNameDifferent::
	msgbox GoldenrodCity_NameRatersHouse_Text_MonShallBeKnownAsName, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_NameRatersHouse_Text_PleasedToRateMonNickname:
	.string "Bonjour, bonjour ! Je suis le JUGE-SURNOM !\n"
	.string "Je suis le devin des noms !\p"
	.string "Je serais ravi d'évaluer le surnom\n"
	.string "de votre POKéMON.$"

GoldenrodCity_NameRatersHouse_Text_CritiqueWhichMonNickname:
	.string "Le surnom de quel POKéMON\n"
	.string "dois-je évaluer ?$"

GoldenrodCity_NameRatersHouse_Text_FineNameSuggestBetterOne:
	.string "Hmm… {STR_VAR_1}, c'est ça ? C'est\n"
	.string "un très joli nom que tu as donné.\p"
	.string "Mais ! Que dirais-tu si je proposais\n"
	.string "un nom un peu meilleur ?$"

GoldenrodCity_NameRatersHouse_Text_WhatShallNewNameBe:
	.string "Ah, très bien. Alors, quel sera\n"
	.string "le nouveau surnom ?$"

GoldenrodCity_NameRatersHouse_Text_MonShallBeKnownAsName:
	.string "Voilà ! Désormais, ce POKéMON\n"
	.string "s'appellera {STR_VAR_1} !\p"
	.string "C'est un meilleur nom qu'avant !\n"
	.string "Quelle chance pour toi !$"

GoldenrodCity_NameRatersHouse_Text_DoVisitAgain:
	.string "Je vois.\n"
	.string "Reviens me voir quand tu veux.$"

GoldenrodCity_NameRatersHouse_Text_NameNoDifferentYetSuperior:
	.string "Voilà ! Désormais, ce POKéMON\n"
	.string "s'appellera {STR_VAR_1} !\p"
	.string "Cela ne semble pas différent,\n"
	.string "et pourtant, c'est bien meilleur !\p"
	.string "Quelle chance pour toi !$"

GoldenrodCity_NameRatersHouse_Text_MagnificentName:
	.string "Hmm… {STR_VAR_1}, c'est ça !\p"
	.string "C'est un surnom magnifique !\n"
	.string "Il est absolument irréprochable !\p"
	.string "Prends bien soin de ton\n"
	.string "{STR_VAR_1} maintenant et toujours.$"

GoldenrodCity_NameRatersHouse_Text_ThatIsMerelyAnEgg:
	.string "Voyons, voyons.\n"
	.string "Ce n'est qu'un ŒUF !$"

