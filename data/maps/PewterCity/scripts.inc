PewterCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PewterCity_EventScript_CityEnter
	.byte 0

PewterCity_EventScript_CityEnter::
	setflag FLAG_VISITED_PEWTER_CITY
	end

PewterCity_EventScript_CooltrainerF::
	msgbox PewterCity_Text_CooltrainerF, MSGBOX_NPC
	end

PewterCity_EventScript_BugCatcher::
	msgbox PewterCity_Text_BugCatcher, MSGBOX_NPC
	end

PewterCity_EventScript_Gramps::
	lock
	faceplayer
	goto_if_eq VAR_LUGIA_OR_HOOH, 1, PewterCity_EventScript_GrampsRainbowWing
	goto_if_eq VAR_LUGIA_OR_HOOH, 2, PewterCity_EventScript_GrampsSilverWing
	end

PewterCity_EventScript_GrampsRainbowWing::
	checkitem ITEM_RAINBOW_WING
	goto_if_eq VAR_RESULT, TRUE, PewterCity_EventScript_GrampsDone
	msgbox PewterCity_Text_Gramps, MSGBOX_DEFAULT
	setvar VAR_COMPLETED_HO_OH, 4
	giveitem ITEM_RAINBOW_WING
	setflag FLAG_HIDE_TINTOWER_GUARD
	closemessage
	release
	end

PewterCity_EventScript_GrampsSilverWing::
	checkitem ITEM_SILVER_WING
	goto_if_eq VAR_RESULT, TRUE, PewterCity_EventScript_GrampsDone
	msgbox PewterCity_Text_Gramps, MSGBOX_DEFAULT
	setvar VAR_COMPLETED_LUGIA, 4
	giveitem ITEM_SILVER_WING
	setflag FLAG_HIDE_WHIRL_ISLANDS_TENTACRUEL
	closemessage
	release
	end

PewterCity_EventScript_GrampsDone::
	msgbox PewterCity_Text_Gramps_GotSilverWing, MSGBOX_DEFAULT
	closemessage
	release
	end

PewterCity_EventScript_Bugcatcher::
	msgbox PewterCity_Text_BugCatcher, MSGBOX_NPC
	end

PewterCity_EventScript_Cooltrainer::
	msgbox PewterCity_Text_CooltrainerF, MSGBOX_NPC
	end

PewterCity_Text_CooltrainerF:
	.string "As-tu visité l'ARÈNE D'ARGENTA ?\p"
	.string "Le CHAMPION utilise des POKéMON de type ROCHE.$"

PewterCity_Text_BugCatcher:
	.string "La nuit, les MÉLOFÉE sortent jouer au\n"
	.string "MT. SELENITE.\p"
	.string "Mais pas toutes les nuits.$"

PewterCity_Text_Gramps:
	.string "Ah, tu es venu jusqu'ici depuis\n"
	.string "JOHTO ?\p"
	.string "Ça me rappelle des souvenirs. Quand j'étais\n"
	.string "jeune, je suis allé à JOHTO pour m'entraîner.\p"
	.string "Tu me rappelles tellement ce que j'étais\n"
	.string "quand j'étais jeune homme.\p"
	.string "Tiens. Je veux que tu aies cet objet que j'ai\n"
	.string "trouvé à JOHTO.$"

PewterCity_Text_Gramps_GotSilverWing:
	.string "Aller dans de nouveaux endroits inconnus et voir\n"
	.string "de nouvelles personnes…\p"
	.string "Ce sont les joies du voyage.$"

PewterCity_EventScript_CitySign::
	msgbox PewterCity_Text_Sign, MSGBOX_NPC
	end

PewterCity_EventScript_GymSign::
	msgbox PewterCity_Text_GymSign, MSGBOX_NPC
	end

PewterCity_EventScript_MuseumSign::
	msgbox PewterCity_Text_MuseumSign, MSGBOX_NPC
	end

PewterCity_EventScript_MtMoonSign::
	msgbox PewterCity_Text_MtMoonGiftShopSign, MSGBOX_NPC
	end

PewterCity_EventScript_WelcomeSign::
	msgbox PewterCity_Text_WelcomeSign, MSGBOX_NPC
	end

PewterCity_Text_Sign:
	.string "ARGENTA\n"
	.string "Une Ville Gris Pierre$"

PewterCity_Text_GymSign:
	.string "ARÈNE POKéMON D'ARGENTA\n"
	.string "CHAMPION: PIERRE\p"
	.string "Le Dresseur POKéMON Solide comme un Roc$"

PewterCity_Text_MuseumSign:
	.string "Il y a un avis ici…\p"
	.string "Le MUSÉE DES SCIENCES D'ARGENTA est fermé pour\n"
	.string "rénovations…$"

PewterCity_Text_MtMoonGiftShopSign:
	.string "Il y a un avis ici…\p"
	.string "BOUTIQUE DE SOUVENIRS DU MT. SELENITE OUVERTE !$"

PewterCity_Text_WelcomeSign:
	.string "BIENVENUE À ARGENTA !$"

