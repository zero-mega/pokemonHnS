Route40_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OlivineCity_MapScript_OnTransition
	.byte 0

Route40_EventScript_Simon::
	trainerbattle_single TRAINER_SIMON, Route40_Text_SwimmermSimonSeen, Route40_Text_SwimmermSimonBeaten
	msgbox Route40_Text_SwimmermSimonAfter, MSGBOX_AUTOCLOSE
	end

Route40_Text_SwimmermSimonSeen:
	.string "Tu dois t'échauffer avant\n"
	.string "d'aller dans l'eau.\p"
	.string "C'est la base.$"

Route40_Text_SwimmermSimonBeaten:
	.string "OK ! J'abandonne !$"

Route40_Text_SwimmermSimonAfter:
	.string "IRISIA est assez loin\n"
	.string "d'ici.$"

Route40_EventScript_Randall::
	trainerbattle_single TRAINER_RANDALL, Route40_Text_SwimmermRandallSeen, Route40_Text_SwimmermRandallBeaten
	msgbox Route40_Text_SwimmermRandallAfter, MSGBOX_AUTOCLOSE
	end

Route40_Text_SwimmermRandallSeen:
	.string "Hé, tu es jeune et en forme !\p"
	.string "Ne monte pas sur ton POKéMON !\n"
	.string "Nage !$"

Route40_Text_SwimmermRandallBeaten:
	.string "Oh non. J'ai perdu…$"

Route40_Text_SwimmermRandallAfter:
	.string "Nager fait travailler tout\n"
	.string "le corps. C'est bon pour la santé.$"

Route40_EventScript_Elaine::
	trainerbattle_single TRAINER_ELAINE, Route40_Text_SwimmerfElaineSeen, Route40_Text_SwimmerfElaineBeaten
	msgbox Route40_Text_SwimmerfElaineAfter, MSGBOX_AUTOCLOSE
	end

Route40_Text_SwimmerfElaineSeen:
	.string "Tu vas à IRISIA ?\p"
	.string "Que dirais-tu d'un petit combat\n"
	.string "avant ?$"

Route40_Text_SwimmerfElaineBeaten:
	.string "J'ai perdu celui-là !$"

Route40_Text_SwimmerfElaineAfter:
	.string "Je dirais que je nage mieux\n"
	.string "que toi. Oui !$"

Route40_EventScript_Paula::
	trainerbattle_single TRAINER_PAULA, Route40_Text_SwimmerfPaulaSeen, Route40_Text_SwimmerfPaulaBeaten
	msgbox Route40_Text_SwimmerfPaulaAfter, MSGBOX_AUTOCLOSE
	end

Route40_Text_SwimmerfPaulaSeen:
	.string "Pas de bouée pour moi.\p"
	.string "Je m'accroche à un POKéMON\n"
	.string "marin !$"

Route40_Text_SwimmerfPaulaBeaten:
	.string "Ouh, j'ai la tête qui tourne !$"

Route40_Text_SwimmerfPaulaAfter:
	.string "Quand je flotte comme ça,\n"
	.string "les vagues me portent.$"

Route40_EventScript_Woman1::
	lock
	faceplayer
	msgbox Route40_Text_Lass1, MSGBOX_DEFAULT
	closemessage
	release
	end

Route40_Text_Lass1:
	.string "Même si tu ne peux pas le voir d'ici,\n"
	.string "IRISIA est de l'autre côté de la mer.$"

Route40_EventScript_Woman2::
	lock
	faceplayer
	msgbox Route40_Text_Lass2, MSGBOX_DEFAULT
	closemessage
	release
	end

Route40_Text_Lass2:
	.string "Je suis venue à OLIVILLE en bateau\n"
	.string "pour voir les sites et profiter\l"
	.string "de l'ambiance.\p"
	.string "Comme c'est un port, c'est très\n"
	.string "différent d'une grande ville.$"

Route40_EventScript_Youngster::
	lock
	faceplayer
	msgbox Route40_Text_StandingYoungster, MSGBOX_DEFAULT
	closemessage
	release
	end

Route40_Text_StandingYoungster:
	.string "Es-tu déjà allé à la TOUR\n"
	.string "BATAILLE ?\p"
	.string "Je pense que beaucoup de dresseurs\n"
	.string "forts s'y sont déjà rassemblés.\p"
	.string "Mais comme tu as tant de\n"
	.string "BADGES,\p"
	.string "tu ne devrais pas avoir de mal\n"
	.string "du tout.$"

Route40_Text_Monica:
	.string "MONICA : Ravie de te rencontrer.\n"
	.string "Je suis MONICA de la FAMILLE DES JOURS.\p"
	.string "Je parie que tu ne peux pas deviner\n"
	.string "mon jour préféré de la semaine !$"

Route40_Text_MonicaGivesGift:
	.string "C'est ça !\p"
	.string "En gage de notre amitié,\n"
	.string "j'ai un cadeau pour toi !$"

Route40_Text_MonicaGaveGift:
	.string "MONICA : C'est un objet qui augmente\n"
	.string "la puissance des attaques de type VOL.\p"
	.string "Tu devrais équiper cet objet à un\n"
	.string "POKéMON oiseau.$"

Route40_Text_MonicaMonday:
	.string "MONICA : Mes frères et sœurs sont\n"
	.string "partout dans la région.\p"
	.string "Essaie de tous les retrouver !$"

Route40_Text_MonicaNotMonday:
	.string "MONICA : Je ne pense pas qu'aujourd'hui\n"
	.string "soit lundi. Comme c'est triste…$"

Route40_Text_MonicaNope:
	.string "Non, ce n'est pas ça.$"

Rotue40_EventScript_Monica::
	lock
	faceplayer
	goto_if_set FLAG_GOT_SHARP_BEAK, Rotue40_EventScript_MonicaCompleted
	msgbox Route40_Text_Monica, MSGBOX_DEFAULT
	closemessage
	multichoice 20, 0, MULTI_DAYS_OF_WEEK, FALSE
	switch VAR_RESULT
	case 0, Rotue40_EventScript_MonicaNope
	case 1, Rotue40_EventScript_MonicaYes
	case 2, Rotue40_EventScript_MonicaNope
	case 3, Rotue40_EventScript_MonicaNope
	case 4, Rotue40_EventScript_MonicaNope
	case 5, Rotue40_EventScript_MonicaNope
	case 6, Rotue40_EventScript_MonicaNope
	case 7 Rotue40_EventScript_MonicaCancel
	case MULTI_B_PRESSED, Rotue40_EventScript_MonicaCancel
	closemessage
	release
	end
Rotue40_EventScript_MonicaYes::
	msgbox Route40_Text_MonicaGivesGift, MSGBOX_DEFAULT
	giveitem ITEM_SHARP_BEAK
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_SHARP_BEAK
	msgbox Route40_Text_MonicaGaveGift, MSGBOX_DEFAULT
	closemessage
	release
	end
Rotue40_EventScript_MonicaNope::
	msgbox Route40_Text_MonicaNope, MSGBOX_DEFAULT
	closemessage
	release
	end
Rotue40_EventScript_MonicaCancel::
	closemessage
	release
	end
Rotue40_EventScript_MonicaCompleted::
	msgbox Route40_Text_MonicaMonday, MSGBOX_DEFAULT
	closemessage
	release
	end
