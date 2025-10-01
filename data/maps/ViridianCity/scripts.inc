ViridianCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ViridianCity_EventScript_CityEnter
	.byte 0

ViridianCity_EventScript_CityEnter::
	setflag FLAG_VISITED_VIRIDIAN_CITY
	end

ViridianCity_EventScript_Gramps::
	lock
	faceplayer
	msgbox ViridianCity_Text_CoffeeGramps_Question, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, ViridianCity_EventScript_GrampsDoubted
	msgbox ViridianCity_Text_CoffeeGramps_Believed, MSGBOX_DEFAULT
	closemessage
	release
	end

ViridianCity_EventScript_GrampsDoubted::
	msgbox ViridianCity_Text_CoffeeGramps_Doubted, MSGBOX_DEFAULT
	closemessage
	release
	end

VirianCity_EventScript_GymGramps::
	goto_if_set FLAG_HIDE_CINNABAR_BLUE, VirianCity_EventScript_GymGrampsBlue
	msgbox ViridianCity_Text_GrampsNearGym, MSGBOX_NPC
	end

VirianCity_EventScript_GymGrampsBlue::
	msgbox ViridianCity_Text_GrampsNearGym_BlueReturned, MSGBOX_NPC
	end

ViridianCity_EventScript_Fisher::
	goto_if_set FLAG_GOT_VIRIDIAN_TM_SLUDGE_BOMB, ViridianCity_EventScript_FisherAfter
	msgbox ViridianCity_Text_DreamEaterFisherNew, MSGBOX_NPC
	giveitem ITEM_TM_SLUDGE_BOMB
	setflag FLAG_GOT_VIRIDIAN_TM_SLUDGE_BOMB
	end

ViridianCity_EventScript_FisherAfter::
	msgbox ViridianCity_Text_DreamEaterFisher_GotTM, MSGBOX_NPC
	end

ViridianCity_EventScript_Youngster::
	msgbox ViridianCity_Text_Youngster, MSGBOX_NPC
	end

ViridianCity_EventScript_CitySign::
	msgbox ViridianCity_Text_WelcomeSign, MSGBOX_SIGN
	end

ViridianCity_EventScript_CitySign2::
	msgbox ViridianCity_Text_Sign, MSGBOX_SIGN
	end

ViridianCity_EventScript_GymSign::
	msgbox ViridianCity_Text_GymSign, MSGBOX_SIGN
	end

ViridianCity_Text_CoffeeGramps_Question:
	.string "Hé, petit ! Je viens de boire un double\n"
	.string "espresso et je suis survolté !\p"
	.string "J'ai besoin de parler à quelqu'un,\n"
	.string "alors tu feras l'affaire !\p"
	.string "Je n'ai peut-être pas l'air de grand-chose\n"
	.string "maintenant, mais j'étais expert pour\l"
	.string "attraper des POKéMON.\p"
	.string "Tu me crois ?$"

ViridianCity_Text_CoffeeGramps_Believed:
	.string "Bien, bien. Oui, j'étais quelqu'un\n"
	.string "d'extraordinaire, laisse-moi te\l"
	.string "le dire !$"

ViridianCity_Text_CoffeeGramps_Doubted:
	.string "Quoi ? Petit morveux !\p"
	.string "Si j'étais un peu plus jeune, je te\l"
	.string "montrerais deux ou trois choses. Humph !$"

ViridianCity_Text_GrampsNearGym:
	.string "Cette ARÈNE n'avait pas de CHAMPION\n"
	.string "jusqu'à récemment.\p"
	.string "Un jeune homme de BOURG PALETTE est\n"
	.string "devenu CHAMPION, mais il est souvent absent.$"

ViridianCity_Text_GrampsNearGym_BlueReturned:
	.string "Tu vas combattre le\n"
	.string "CHAMPION ?\p"
	.string "Bonne chance. Tu en auras besoin.$"

ViridianCity_Text_DreamEaterFisherNew:
	.string "…Zzzzz…\p" 
	.string "Bâillement !\p"
	.string "J'ai dû m'assoupir au soleil.\p"
	.string "Quoi ? Je te rappelle quelqu'un ?\p"
	.string "Je ne sais pas, tiens, prends ça.$"


ViridianCity_Text_DreamEaterFisher_GotTM::
	.string "…Zzzzz…$"

ViridianCity_Text_DreamEaterFisher:
	.string "Bâillement !\p"
	.string "J'ai dû m'assoupir au soleil.\p"
	.string "…J'ai fait ce rêve à propos d'un SOPORIFIK\n"
	.string "qui mangeait mon rêve. Bizarre, hein ?\p"
	.string "Hein ? Qu'est-ce que c'est ?\p"
	.string "D'où vient cette CT ?\p"
	.string "C'est flippant ! Tiens, tu peux avoir\n"
	.string "cette CT.$"

ViridianCity_Text_DreamEaterFisher_GotDreamEater:
	.string "CT42 contient DEVOREVE…\p"
	.string "…Zzzzz…$"

ViridianCity_Text_Youngster:
	.string "J'ai entendu dire qu'il y a beaucoup\n"
	.string "d'objets au sol dans la FORÊT DE JADE.$"

ViridianCity_Text_Sign:
	.string "JADIELLE\p"
	.string "Le Paradis Éternellement Vert$"

ViridianCity_Text_GymSign:
	.string "ARÈNE POKéMON DE JADIELLE\n"
	.string "CHAMPION: …\p"
	.string "Le reste du texte est illisible…$"

ViridianCity_Text_WelcomeSign:
	.string "BIENVENUE À JADIELLE,\p"
	.string "LA PORTE DU PLATEAU INDIGO$"

ViridianCity_Text_TrainerHouseSign:
	.string "MAISON DES DRESSEURS\p"
	.string "Le Club des Meilleurs Combats de Dresseurs$"
