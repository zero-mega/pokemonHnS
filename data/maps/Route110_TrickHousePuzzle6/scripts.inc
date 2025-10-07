Route110_TrickHousePuzzle6_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route110_TrickHousePuzzle6_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Route110_TrickHousePuzzle6_OnWarp
	.byte 0

Route110_TrickHousePuzzle6_OnTransition:
	special RotatingGate_InitPuzzle
	end

Route110_TrickHousePuzzle6_OnWarp:
	map_script_2 VAR_TEMP_0, VAR_TEMP_0, Route110_TrickHousePuzzle6_EventScript_InitPuzzle
	.2byte 0

@ NOTE: This rotating gate puzzle makes use of VAR_TEMP_0 - VAR_TEMP_5
Route110_TrickHousePuzzle6_EventScript_InitPuzzle::
	special RotatingGate_InitPuzzleAndGraphics
	end

Route110_TrickHousePuzzle6_EventScript_Scroll::
	lockall
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_6_STATE, 0, Route110_TrickHousePuzzle6_EventScript_FoundScroll
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
	end

Route110_TrickHousePuzzle6_EventScript_FoundScroll::
	setvar VAR_TRICK_HOUSE_PUZZLE_6_STATE, 1
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
	end

Route110_TrickHousePuzzle6_EventScript_Sophia::
	trainerbattle_single TRAINER_SOPHIA, Route110_TrickHousePuzzle6_Text_SophiaIntro, Route110_TrickHousePuzzle6_Text_SophiaDefeat
	msgbox Route110_TrickHousePuzzle6_Text_SophiaPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle6_EventScript_Benny::
	trainerbattle_single TRAINER_BENNY, Route110_TrickHousePuzzle6_Text_BennyIntro, Route110_TrickHousePuzzle6_Text_BennyDefeat
	msgbox Route110_TrickHousePuzzle6_Text_BennyPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle6_EventScript_Sebastian::
	trainerbattle_single TRAINER_SEBASTIAN, Route110_TrickHousePuzzle6_Text_SebastianIntro, Route110_TrickHousePuzzle6_Text_SebastianDefeat
	msgbox Route110_TrickHousePuzzle6_Text_SebastianPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle6_Text_WroteSecretCodeLockOpened:
	.string "{PLAYER} a écrit le code secret\n"
	.string "sur la porte.\p"
	.string "« MAÎTRE DES PIÈGES, c'est ma vie. »\n"
	.string "… … … … … … … …\p"
	.string "La serrure s'est ouverte !$"

Route110_TrickHousePuzzle6_Text_SophiaIntro:
	.string "Quand j'ai entendu parler d'une maison\n"
	.string "étrange, j'ai dû venir voir.$"

Route110_TrickHousePuzzle6_Text_SophiaDefeat:
	.string "J'ai découvert un DRESSEUR coriace !$"

Route110_TrickHousePuzzle6_Text_SophiaPostBattle:
	.string "Je m'amuse vraiment à explorer\n"
	.string "cet endroit.\p"
	.string "C'est un défi que j'ai envie de\n"
	.string "relever encore et encore !$"

Route110_TrickHousePuzzle6_Text_BennyIntro:
	.string "Peut-être que mes POKéMON OISEAU\n"
	.string "pourraient voler par-dessus le mur…$"

Route110_TrickHousePuzzle6_Text_BennyDefeat:
	.string "Gwaaah ! J'ai tout raté !$"

Route110_TrickHousePuzzle6_Text_BennyPostBattle:
	.string "Ehehehe… Je suppose que j'ai perdu\n"
	.string "parce que j'ai essayé de tricher.$"

Route110_TrickHousePuzzle6_Text_SebastianIntro:
	.string "J'ai la tête qui tourne avec toutes\n"
	.string "ces portes rotatives…$"

Route110_TrickHousePuzzle6_Text_SebastianDefeat:
	.string "Tout tourne autour de moi.\n"
	.string "Je n'en peux plus…$"

Route110_TrickHousePuzzle6_Text_SebastianPostBattle:
	.string "Tu n'as pas l'air affecté du tout.\n"
	.string "Ou alors tu caches bien ton jeu ?$"
