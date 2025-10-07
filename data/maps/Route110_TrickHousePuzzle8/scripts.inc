Route110_TrickHousePuzzle8_MapScripts::
	.byte 0

Route110_TrickHousePuzzle8_EventScript_Scroll::
	lockall
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_8_STATE, 0, Route110_TrickHousePuzzle8_EventScript_FoundScroll
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
	end

Route110_TrickHousePuzzle8_EventScript_FoundScroll::
	setvar VAR_TRICK_HOUSE_PUZZLE_8_STATE, 1
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
	end

Route110_TrickHousePuzzle8_EventScript_Vincent::
	trainerbattle_single TRAINER_VINCENT, Route110_TrickHousePuzzle8_Text_VincentIntro, Route110_TrickHousePuzzle8_Text_VincentDefeat
	msgbox Route110_TrickHousePuzzle8_Text_VincentPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle8_EventScript_Keira::
	trainerbattle_single TRAINER_KEIRA, Route110_TrickHousePuzzle8_Text_KeiraIntro, Route110_TrickHousePuzzle8_Text_KeiraDefeat
	msgbox Route110_TrickHousePuzzle8_Text_KeiraPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle8_EventScript_Leroy::
	trainerbattle_single TRAINER_LEROY, Route110_TrickHousePuzzle8_Text_LeroyIntro, Route110_TrickHousePuzzle8_Text_LeroyDefeat
	msgbox Route110_TrickHousePuzzle8_Text_LeroyPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle8_Text_WroteSecretCodeLockOpened::
	.string "{PLAYER} a écrit le code secret\n"
	.string "sur la porte.\p"
	.string "« MAÎTRE DES PIÈGES je t'aime. »\n"
	.string "… … … … … … … …\p"
	.string "La serrure s'est ouverte !$"

Route110_TrickHousePuzzle8_Text_VincentIntro:
	.string "Peu de DRESSEURS sont arrivés\n"
	.string "aussi loin.$"

Route110_TrickHousePuzzle8_Text_VincentDefeat:
	.string "Ça veut dire que tu es fort, toi aussi…$"

Route110_TrickHousePuzzle8_Text_VincentPostBattle:
	.string "Tu as battu le CHAMPION de la LIGUE\n"
	.string "POKéMON ? C'est incroyable !$"

Route110_TrickHousePuzzle8_Text_KeiraIntro:
	.string "Considère-toi chanceux de\n"
	.string "m'affronter !$"

Route110_TrickHousePuzzle8_Text_KeiraDefeat:
	.string "Ce n'est pas possible !\n"
	.string "Je ne peux pas perdre !$"

Route110_TrickHousePuzzle8_Text_KeiraPostBattle:
	.string "C'est un miracle que tu m'aies battue.\n"
	.string "Tu peux t'en vanter.$"

Route110_TrickHousePuzzle8_Text_LeroyIntro:
	.string "Toi aussi, tu as traversé le défi\n"
	.string "de la MAISON PIÈGE.$"

Route110_TrickHousePuzzle8_Text_LeroyDefeat:
	.string "Je vois…\n"
	.string "Tu as un style extraordinaire.$"

Route110_TrickHousePuzzle8_Text_LeroyPostBattle:
	.string "Voir quelqu'un comme toi devrait\n"
	.string "plaire au MAÎTRE DES PIÈGES.$"
