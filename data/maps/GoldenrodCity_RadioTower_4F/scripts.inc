GoldenrodCity_RadioTower_4F_MapScripts::
	.byte 0

GoldenrodCity_RadioTower_4F4_EventScript_Sign1::
	lock
	msgbox GoldenrodCity_RadioTower_4F4_Text_Studio2Sign, MSGBOX_SIGN
	closemessage
	release
	end

GoldenrodCity_RadioTower_4F4_EventScript_Sign2::
	lock
	msgbox GoldenrodCity_RadioTower_4F4_Text_ProductionSign, MSGBOX_SIGN
	closemessage
	release
	end

GoldenrodRaidoTower4_EventScript_Grunt28::
	trainerbattle_single TRAINER_GRUNT_28 GoldenrodCity_RadioTower_4F4_Text_GruntF4Seen, GoldenrodCity_RadioTower_4F4_Text_GruntF4Beaten
	msgbox GoldenrodCity_RadioTower_4F4_Text_GruntF4After, MSGBOX_AUTOCLOSE
	end

GoldenrodRaidoTower4_EventScript_Grunt9::
	trainerbattle_single TRAINER_GRUNT_9 GoldenrodCity_RadioTower_4F4_Text_GruntM10Seen, GoldenrodCity_RadioTower_4F4_Text_GruntM10Beaten
	msgbox GoldenrodCity_RadioTower_4F4_Text_GruntM10After, MSGBOX_AUTOCLOSE
	end

GoldenrodRaidoTower4_EventScript_Proton::
	trainerbattle_single TRAINER_PROTON_2 GoldenrodCity_RadioTower_4F4_Text_Proton_Seen, GoldenrodCity_RadioTower_4F4_Text_Proton_Beaten
	msgbox GoldenrodCity_RadioTower_4F4_Text_Proton_After, MSGBOX_AUTOCLOSE
	end


GoldenrodCity_RadioTower_4F4_EventScript_Fisher::
	lock
	faceplayer
	msgbox GoldenrodCity_RadioTower_4F4_Text_Fisher, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_4F4_EventScript_Scientist::
	trainerbattle_single TRAINER_RICH GoldenrodCity_RadioTower_4F4_Text_ScientistRichSeen, GoldenrodCity_RadioTower_4F4_Text_ScientistRichBeaten
	msgbox GoldenrodCity_RadioTower_4F4_Text_ScientistRichAfter, MSGBOX_AUTOCLOSE
	end


GoldenrodCity_RadioTower_4F4_EventScript_Mary::
	lock
	faceplayer
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 6, GoldenrodCity_RadioTower_4F4_EventScript_Mary2
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 7, GoldenrodCity_RadioTower_4F4_EventScript_Mary2
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 8, GoldenrodCity_RadioTower_4F4_EventScript_Mary2
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 9, GoldenrodCity_RadioTower_4F4_EventScript_Mary2
	goto_if_unset FLAG_GOT_MARY_BRIGHT_POWDER, GoldenrodCity_RadioTower_4F4_EventScript_Mary3
	msgbox GoldenrodCity_RadioTower_4F4_Text_DJMaryAfter, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_4F4_EventScript_Mary2::
	msgbox GoldenrodCity_RadioTower_4F4_Text_DJMary, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_4F4_EventScript_Mary3::
	msgbox GoldenrodCity_RadioTower_4F4_Text_DJMaryCleared, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_BRIGHT_POWDER
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox GoldenrodCity_RadioTower_4F4_Text_DJMaryPinkBow, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_GOT_MARY_BRIGHT_POWDER
	closemessage
	release
	end

GoldenrodCity_RadioTower_4F4_EventScript_Meowth::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MEOWTH, CRY_MODE_NORMAL
	msgbox GoldenrodCity_RadioTower_4F4_Text_Meowth, MSGBOX_DEFAULT
	waitmoncry
	release
	end


GoldenrodCity_RadioTower_4F4_Text_Proton_Seen:
	.string "PROTON : Attends une seconde !\p"
	.string "N'es-tu pas celui qui nous a gênés\n"
	.string "au PUITS RAMOLLOS ?\p"
	.string "Je vois... Tu fais tout ça\n"
	.string "juste pour m'énerver, hein.\l"
	.string "Fais attention !\p"
	.string "Mais puisque tu sembles le vouloir,\n"
	.string "je vais te montrer toute la colère\l"
	.string "d'un ADMIN de la TEAM ROCKET !$"

GoldenrodCity_RadioTower_4F4_Text_Proton_Beaten:
	.string "Ouf...$"

GoldenrodCity_RadioTower_4F4_Text_Proton_After:
	.string "PROTON : Tu as peut-être gagné cette\n"
	.string "fois... Mais tu n'as fait qu'augmenter\p"
	.string "la colère de la TEAM ROCKET !$"

GoldenrodCity_RadioTower_4F4_Text_Fisher:
	.string "J'ai écouté la radio pendant que\n"
	.string "j'étais aux RUINES.\p"
	.string "J'y ai entendu une étrange émission.$"

GoldenrodCity_RadioTower_4F4_Text_DJMary:
	.string "MARY : Pourquoi ? Pourquoi dois-je\n"
	.string "subir tout ça ?\p"
	.string "MIAOUSS, aide-moi !$"

GoldenrodCity_RadioTower_4F4_Text_DJMaryCleared:
	.string "MARY : Oh ! Tu es mon petit sauveur !\p"
	.string "Veux-tu prendre ceci en remerciement ?$"

GoldenrodCity_RadioTower_4F4_Text_DJMaryPinkBow:
	.string "MARY : C'est utile pour esquiver\n"
	.string "les attaques ennemies.$"

GoldenrodCity_RadioTower_4F4_Text_DJMaryAfter:
	.string "MARY : Écoute-moi dans l'émission\n"
	.string "de PROF. CHEN, PARLONS POKéMON !$"

GoldenrodCity_RadioTower_4F4_Text_Meowth:
	.string "MIAOUSS : Miaouss…$"

GoldenrodCity_RadioTower_4F4_Text_GruntM10Seen:
	.string "Tu comptes sauver le DIRECTEUR ?\p"
	.string "Ce ne sera pas possible car je vais\n"
	.string "te battre !$"

GoldenrodCity_RadioTower_4F4_Text_GruntM10Beaten:
	.string "Non ! Incroyable !$"

GoldenrodCity_RadioTower_4F4_Text_GruntM10After:
	.string "Je n'y crois pas ! J'ai perdu !$"

GoldenrodCity_RadioTower_4F4_Text_ExecutiveM2Seen:
	.string "Stop ! On m'appelle la forteresse\n"
	.string "de la TEAM ROCKET !\p"
	.string "Tu n'iras pas plus loin !$"

GoldenrodCity_RadioTower_4F4_Text_ExecutiveM2Beaten:
	.string "La forteresse est tombée !$"

GoldenrodCity_RadioTower_4F4_Text_ExecutiveM2After:
	.string "Tu as gagné mon respect, alors voici\n"
	.string "un conseil.\p"
	.string "Il n'est pas trop tard. Tu peux encore\n"
	.string "faire demi-tour.$"

GoldenrodCity_RadioTower_4F4_Text_GruntF4Seen:
	.string "Tu ne trouves pas les POKéMON mignons ?\p"
	.string "Je trouverai mes POKéMON mignons--\p"
	.string "après qu'ils auront battu les tiens !$"

GoldenrodCity_RadioTower_4F4_Text_GruntF4Beaten:
	.string "Oh, non ! Ils sont si inutiles !$"

GoldenrodCity_RadioTower_4F4_Text_GruntF4After:
	.string "J'adore ma beauté !\p"
	.string "Qui se soucie des POKéMON ?$"

GoldenrodCity_RadioTower_4F4_Text_ScientistRichSeen:
	.string "Excellent.\p"
	.string "Cette TOUR RADIO réalisera notre\n"
	.string "grand dessein.$"

GoldenrodCity_RadioTower_4F4_Text_ScientistRichBeaten:
	.string "Hmmm…\p"
	.string "Tous les grands plans ont des accrocs.$"

GoldenrodCity_RadioTower_4F4_Text_ScientistRichAfter:
	.string "Tu crois vraiment pouvoir arrêter\n"
	.string "la TEAM ROCKET ?$"

GoldenrodCity_RadioTower_4F4_Text_ProductionSign:
	.string "4F PRODUCTION$"

GoldenrodCity_RadioTower_4F4_Text_Studio2Sign:
	.string "4F STUDIO 2$"
