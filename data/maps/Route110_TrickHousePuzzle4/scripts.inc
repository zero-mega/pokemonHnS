Route110_TrickHousePuzzle4_MapScripts::
	.byte 0

Route110_TrickHousePuzzle4_EventScript_Scroll::
	lockall
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_4_STATE, 0, Route110_TrickHousePuzzle4_EventScript_FoundScroll
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
	end

Route110_TrickHousePuzzle4_EventScript_FoundScroll::
	setvar VAR_TRICK_HOUSE_PUZZLE_4_STATE, 1
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
	end

Route110_TrickHousePuzzle4_EventScript_Cora::
	trainerbattle_single TRAINER_GRUNT_28, Route110_TrickHousePuzzle4_Text_CoraIntro, Route110_TrickHousePuzzle4_Text_CoraDefeat
	msgbox Route110_TrickHousePuzzle4_Text_CoraPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle4_EventScript_Yuji::
	trainerbattle_single TRAINER_YUJI, Route110_TrickHousePuzzle4_Text_YujiIntro, Route110_TrickHousePuzzle4_Text_YujiDefeat
	msgbox Route110_TrickHousePuzzle4_Text_YujiPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle4_EventScript_Paula::
	trainerbattle_single TRAINER_PAULA, Route110_TrickHousePuzzle4_Text_PaulaIntro, Route110_TrickHousePuzzle4_Text_PaulaDefeat
	msgbox Route110_TrickHousePuzzle4_Text_PaulaPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle4_Text_WroteSecretCodeLockOpened:
	.string "{PLAYER} a écrit le code secret\n"
	.string "sur la porte.\p"
	.string "« MAÎTRE DES PIÈGES est génial. »\n"
	.string "… … … … … … … …\p"
	.string "La serrure s'est ouverte !$"

Route110_TrickHousePuzzle4_Text_CoraIntro:
	.string "C'est trop compliqué de réfléchir à ça.\n"
	.string "Je voulais juste me battre !$"

Route110_TrickHousePuzzle4_Text_CoraDefeat:
	.string "Même si j'ai perdu, j'aime toujours\n"
	.string "les combats plus que tout !$"

Route110_TrickHousePuzzle4_Text_CoraPostBattle:
	.string "Tu n'es pas d'accord ? Tu irais\n"
	.string "n'importe où s'il y avait des DRESSEURS.$"

Route110_TrickHousePuzzle4_Text_YujiIntro:
	.string "Hé ! Des rochers comme ça, je peux les\n"
	.string "pousser d'un seul doigt !$"

Route110_TrickHousePuzzle4_Text_YujiDefeat:
	.string "Je peux pousser des rochers, mais je\n"
	.string "n'arrive pas à résoudre l'énigme…$"

Route110_TrickHousePuzzle4_Text_YujiPostBattle:
	.string "Ce n'est pas suffisant d'être costaud…\n"
	.string "Il faut aussi réfléchir. Sois malin !$"

Route110_TrickHousePuzzle4_Text_PaulaIntro:
	.string "La MAISON PIÈGE devient de plus en plus\n"
	.string "difficile, non ?$"

Route110_TrickHousePuzzle4_Text_PaulaDefeat:
	.string "Aaah !$"

Route110_TrickHousePuzzle4_Text_PaulaPostBattle:
	.string "Est-ce que quelqu'un est déjà allé au bout ?$"
