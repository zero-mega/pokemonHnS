LakeOfRage_House2_MapScripts::
	.byte 0

LakeOfRage_House2_EventScript_Fisher::
	lock
	faceplayer
	goto_if_ge VAR_MAHOGANY_TOWN_STATE, 14, LakeOfRage_House2_EventScript_FisherAfterRockets
	goto_if_eq VAR_LAKE_OF_RAGE_FISHERMAN, 0, LakeOfRage_House2_EventScript_FisherFirstMeeting
	msgbox LakeOfRage_House2_Text_MenInBlack, MSGBOX_DEFAULT
	closemessage
	release
	end	

LakeOfRage_House2_EventScript_FisherFirstMeeting::
	msgbox LakeOfRage_House2_Text_LakeHistory, MSGBOX_DEFAULT
	msgbox LakeOfRage_House2_Text_MenInBlack, MSGBOX_DEFAULT
	setvar VAR_LAKE_OF_RAGE_FISHERMAN, 1
	closemessage
	release
	end

LakeOfRage_House2_EventScript_FisherAfterRockets::
	goto_if_eq VAR_LAKE_OF_RAGE_FISHERMAN, 2, LakeOfRage_House2_EventScript_FisherAnotherMagikarp
	msgbox LakeOfRage_House2_Text_WorldsLargest, MSGBOX_DEFAULT
	msgbox LakeOfRage_House2_Text_ForMe, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, LakeOfRage_House2_EventScript_FisherNo
	getpartysize
	goto_if_eq VAR_RESULT, 1, LakeOfRage_House2_EventScript_LastMon
	special ChoosePartyMon
	waitstate
	lock
	showmoneybox 0, 0
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, LakeOfRage_House2_EventScript_FisherNoMoneyBox
	removegenericmon SPECIES_MAGIKARP
	goto_if_eq VAR_RESULT, FALSE, LakeOfRage_House2_EventScript_FisherNotMagikarp
	goto_if_eq VAR_RESULT, MON_SATISFACTORY, LakeOfRage_House2_EventScript_FisherSatisfied
	goto_if_eq VAR_RESULT, MON_UNSATISFACTORY, LakeOfRage_House2_EventScript_FisherSmallMagikarp

LakeOfRage_House2_EventScript_FisherNo::
	msgbox LakeOfRage_House2_Text_Refused, MSGBOX_DEFAULT
	closemessage
	release
	end

LakeOfRage_House2_EventScript_FisherNoMoneyBox::
	msgbox LakeOfRage_House2_Text_Refused, MSGBOX_DEFAULT
	hidemoneybox
	closemessage
	release
	end

LakeOfRage_House2_EventScript_FisherNotMagikarp::
	msgbox LakeOfRage_House2_Text_NotMagikarp, MSGBOX_DEFAULT
	hidemoneybox
	closemessage
	release
	end

LakeOfRage_House2_EventScript_FisherSmallMagikarp::
	setvar VAR_LAKE_OF_RAGE_FISHERMAN, 2
	msgbox LakeOfRage_House2_Text_TooShort, MSGBOX_DEFAULT
	addmoney 2000
	updatemoneybox
	playse SE_SHOP
	waitse
	hidemoneybox
	closemessage
	release
	end

LakeOfRage_House2_EventScript_FisherAnotherMagikarp::
	msgbox LakeOfRage_House2_Text_ForMe, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, LakeOfRage_House2_EventScript_FisherNo
	getpartysize
	goto_if_eq VAR_RESULT, 1, LakeOfRage_House2_EventScript_LastMon
	special ChoosePartyMon
	waitstate
	lock
	showmoneybox 0, 0
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, LakeOfRage_House2_EventScript_FisherNoMoneyBox
	removegenericmon SPECIES_MAGIKARP
	goto_if_eq VAR_RESULT, FALSE, LakeOfRage_House2_EventScript_FisherNotMagikarp
	goto_if_eq VAR_RESULT, MON_SATISFACTORY, LakeOfRage_House2_EventScript_FisherSatisfied
	goto_if_eq VAR_RESULT, MON_UNSATISFACTORY, LakeOfRage_House2_EventScript_FisherSmallMagikarp

LakeOfRage_House2_EventScript_LastMon::
	msgbox LakeOfRage_House2_Text_LastMon, MSGBOX_DEFAULT
	closemessage
	release
	end

LakeOfRage_House2_EventScript_FisherSatisfied::
	setvar VAR_LAKE_OF_RAGE_FISHERMAN, 2
	msgbox LakeOfRage_House2_Text_BigPayout, MSGBOX_DEFAULT
	addmoney 100000
	updatemoneybox
	playse SE_SHOP
	waitse
	hidemoneybox
	closemessage
	release
	end

LakeOfRage_House2_Text_LakeHistory:
    .string "Le LAC COLÈRE est en fait un cratère\n"
    .string "créé par des LÉVIATOR déchaînés.\p"
    .string "Le cratère s'est rempli d'eau de pluie\n"
    .string "et le LAC s'est formé.\p"
    .string "C'est l'histoire transmise par l'arrière-\n"
    .string "arrière-grand-père de mon grand-père.\p"
    .string "Avant, on pouvait y pêcher des MAGIKARPE\n"
    .string "pleins de vie, mais…\p"
    .string "Je ne comprends pas ce qui se passe.$"

LakeOfRage_House2_Text_MenInBlack:
    .string "Le LAC n'est plus normal depuis que\n"
    .string "ces hommes en noir sont arrivés.$"

LakeOfRage_House2_Text_LastMon:
    .string "Je ne vais quand même pas prendre\n"
    .string "ton dernier POKéMON !$"

LakeOfRage_House2_Text_WorldsLargest:
    .string "Le LAC COLÈRE est redevenu normal.\p"
    .string "Les MAGIKARPE sont revenus.\p"
    .string "Je vais peut-être enfin réaliser mon rêve :\n"
    .string "posséder le plus grand MAGIKARPE du monde.\p"
    .string "D'ailleurs... Je te paierai 2000¥ pour\n"
    .string "chaque MAGIKARPE que tu me donnes, et\l"
    .string "100 000¥ pour un MAGIKARPE GÉANT !$"

LakeOfRage_House2_Text_ForMe:
    .string "Alors... Tu as un MAGIKARPE pour\n"
    .string "moi ?$"

LakeOfRage_House2_Text_HaveMagikarp:
    .string "Ah, tu as un MAGIKARPE ! Voyons\n"
    .string "voir à quel point il est gros.$"

LakeOfRage_House2_Text_BigPayout:
    .string "Ouah ! Celui-ci est exceptionnel !\p"
    .string "Je te tire mon chapeau !\p"
    .string "Voici une petite récompense pour\n"
    .string "te remercier.$"

LakeOfRage_House2_Text_Bonus:
    .string "Le record, c'est ce qui compte.\p"
    .string "Considère ça comme un bonus !$"

LakeOfRage_House2_Text_TooShort:
    .string "Ouah ! Celui-ci est exceptionnel !\p"
    .string "…J'aimerais pouvoir dire ça, mais j'en\n"
    .string "ai déjà vu un plus gros.\p"
    .string "Mais il vaut quand même quelque chose.$"

LakeOfRage_House2_Text_NotMagikarp:
    .string "Quoi ? Ce n'est pas un MAGIKARPE !$"

LakeOfRage_House2_Text_Refused:
    .string "Oh… Donc tu n'en as pas un assez bon\n"
    .string "à me montrer ? Peut-être la prochaine fois.$"
