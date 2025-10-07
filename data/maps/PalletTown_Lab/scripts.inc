PalletTown_Lab_MapScripts::
	.byte 0

PalletTown_Lab_EventScript_Oak::
	lock
	faceplayer
	call_if_unset FLAG_SYS_NATIONAL_DEX, PalletTown_Lab_EventScript_OakGiveNatDex_ForPlaytesters
	goto_if_eq VAR_PALLETTOWN_LABSTATE, 1, PalletTown_Lab_EventScript_OakBadgeCheck
	goto_if_eq VAR_PALLETTOWN_LABSTATE, 2, PalletTown_Lab_EventScript_OakDex
	msgbox PalletTown_Lab_Text_OakWelcomeKanto, MSGBOX_DEFAULT
	msgbox PalletTown_Lab_Text_OakLabGoodbye, MSGBOX_DEFAULT
	setvar VAR_PALLETTOWN_LABSTATE, 1
	closemessage
	release
	end

PalletTown_Lab_EventScript_OakGiveNatDex_ForPlaytesters::
	setflag FLAG_SYS_NATIONAL_DEX
	special EnableNationalPokedex
	return

PalletTown_Lab_EventScript_OakBadgeCheck::
	goto_if_ge VAR_NUM_BADGES, 16, PalletTown_Lab_EventScript_Oak16Badges
	goto_if_ge VAR_NUM_BADGES, 9, PalletTown_Lab_EventScript_Oak9Badges
	msgbox PalletTown_Lab_Text_OakNoKantoBadges, MSGBOX_DEFAULT
	closemessage
	release
	end

PalletTown_Lab_EventScript_Oak16Badges::
	msgbox PalletTown_Lab_Text_OakOpenMtSilver, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_INDIGOJUNCTION_HIDE_SILVER_GUARD
	setvar VAR_PALLETTOWN_LABSTATE, 2
	release
	end

PalletTown_Lab_EventScript_Oak9Badges::
	msgbox PalletTown_Lab_Text_OakYesKantoBadges, MSGBOX_DEFAULT
	closemessage
	release
	end

PalletTown_Lab_EventScript_OakDex::
	msgbox PalletTown_Lab_Text_OakLabDexCheck, MSGBOX_DEFAULT
	closemessage
	release
	end

PalletTown_Lab_EventScript_Assistant1::
	msgbox PalletTown_Lab_Text_OaksAssistant1, MSGBOX_NPC
	end

PalletTown_Lab_EventScript_Assistant2::
	msgbox PalletTown_Lab_Text_OaksAssistant2, MSGBOX_NPC
	end

PalletTown_Lab_EventScript_Assistant3::
	msgbox PalletTown_Lab_Text_OaksAssistant3, MSGBOX_NPC
	end

PalletTown_Lab_EventScript_PC::
	msgbox PalletTown_Lab_Text_OaksLabPC, MSGBOX_SIGN
	end

PalletTown_Lab_Text_OakLabDexCheck:
	.string "Comment avance ton POKéDEX ?$"

PalletTown_Lab_Text_OakWelcomeKanto:
	.string "CHEN : Ah, {PLAYER} !\n"
	.string "C'est bien que tu sois venu jusqu'à\l"
	.string "KANTO.\p"
	.string "Que penses-tu des dresseurs ici ?\n"
	.string "Ils sont coriaces, non ?$"

PalletTown_Lab_Text_OakLabGoodbye:
	.string "Si tu es dans le coin, j'espère que\n"
	.string "tu viendras me rendre visite à nouveau.$"

PalletTown_Lab_Text_OakOpenMtSilver:
	.string "CHEN : Waouh ! C'est excellent !\p"
	.string "Tu as récolté les BADGES des ARÈNES\n"
	.string "de KANTO. Bravo !\p"
	.string "Je ne me suis pas trompé sur toi.\p"
	.string "Écoute, {PLAYER}. Je vais faire en\n"
	.string "sorte que tu puisses aller au MT.SILVER.\p"
	.string "Le MT.SILVER est une grande montagne\n"
	.string "où vivent de nombreux POKéMON sauvages.\p"
	.string "C'est trop dangereux pour un dresseur\n"
	.string "ordinaire, donc c'est interdit. Mais\l"
	.string "on peut faire une exception pour toi,\l"
	.string "{PLAYER}.\p"
	.string "Monte au PLATEAU INDIGO. Tu pourras\n"
	.string "atteindre le MT.SILVER depuis là-bas.$"

PalletTown_Lab_Text_OakNoKantoBadges:
	.string "CHEN : Hmm ? Tu ne collectionnes pas\n"
	.string "les BADGES des ARÈNES de KANTO ?\p"
	.string "Les CHAMPIONS d'ARÈNE de KANTO sont\n"
	.string "aussi forts que ceux que tu as affrontés à JOHTO.\p"
	.string "Je te conseille de les défier.$"

PalletTown_Lab_Text_OakYesKantoBadges:
	.string "CHEN : Ah, tu collectionnes les BADGES\n"
	.string "des ARÈNES de KANTO.\p"
	.string "J'imagine que c'est difficile, mais\n"
	.string "l'expérience t'aidera sûrement.\p"
	.string "Viens me voir quand tu les auras tous.\p"
	.string "J'aurai un cadeau pour toi.\p"
	.string "Continue tes efforts, {PLAYER} !$"

PalletTown_Lab_Text_OaksAssistant1:
	.string "L'émission radio POKéMON TALK du PROF\n"
	.string "n'est pas diffusée ici à KANTO.\p"
	.string "C'est dommage—j'aimerais l'écouter.$"

PalletTown_Lab_Text_OaksAssistant2:
	.string "Grâce à ton travail sur le POKéDEX,\n"
	.string "les recherches du PROF avancent\l"
	.string "très bien.$"

PalletTown_Lab_Text_OaksAssistant3:
	.string "Ne le dis à personne, mais POKéMON TALK\n"
	.string "du PROF.CHEN n'est pas diffusé en direct.$"

PalletTown_Lab_Text_OaksLabPC:
	.string "Il y a un e-mail sur le PC.\p"
	.string "…\p"
	.string "PROF.CHEN, comment avancent vos recherches ?\p"
	.string "Je continue à travailler dur.\p"
	.string "J'ai entendu des rumeurs comme quoi {PLAYER}\n"
	.string "se fait une sacrée réputation.\p"
	.string "Je suis ravi de l'apprendre.\p"
	.string "ORME à BOURG-GEON 8-)$"
