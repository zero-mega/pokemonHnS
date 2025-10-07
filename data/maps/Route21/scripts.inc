Route21_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route21_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route21_OnTransition:
	callnative SetTimeBasedEncounters
	end

Route21_EventScript_Seth::
	trainerbattle_single TRAINER_SETH Route21_Text_SwimmermSethSeen, Route21_Text_SwimmermSethBeaten
	msgbox Route21_Text_SwimmermSethAfterBattle, MSGBOX_AUTOCLOSE
	end

Route21_EventScript_Nikki::
	trainerbattle_single TRAINER_NIKKI Route21_Text_SwimmerfNikkiSeen, Route21_Text_SwimmerfNikkiBeaten
	msgbox Route21_Text_SwimmerfNikkiAfterBattle, MSGBOX_AUTOCLOSE
	end

Route21_EventScript_Arnold::
	trainerbattle_single TRAINER_ARNOLD Route21_Text_FisherArnoldSeen, Route21_Text_FisherArnoldBeaten
	msgbox Route21_Text_FisherArnoldAfterBattle, MSGBOX_AUTOCLOSE
	end

Route21_Text_SwimmermSethSeen:
	.string "Terre en vue ! Faut continuer d'avancer !$"

Route21_Text_SwimmermSethBeaten:
	.string "Glou…$"

Route21_Text_SwimmermSethAfterBattle:
	.string "Ce type arrogant était au volcan\n"
	.string "de CRAMOIS'ÎLE.$"

Route21_Text_SwimmerfNikkiSeen:
	.string "Si je gagne, tu dois m'aider à mettre\n"
	.string "ma crème solaire !$"

Route21_Text_SwimmerfNikkiBeaten:
	.string "Je m'inquiète pour les coups de soleil…$"

Route21_Text_SwimmerfNikkiAfterBattle:
	.string "Je dois faire attention aux taches\n"
	.string "causées par le soleil.$"

Route21_Text_FisherArnoldSeen:
	.string "La pêche m'ennuie. Combattons !$"

Route21_Text_FisherArnoldBeaten:
	.string "Échec total…$"

Route21_Text_FisherArnoldAfterBattle:
	.string "Je vais juste retourner pêcher…$"
