AbandonedShip_Corridors_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SetTimeEncounters
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

AbandonedShip_Corridors_1F_EventScript_Youngster::
	msgbox AbandonedShip_Corridors_1F_Text_IsntItFunHere, MSGBOX_NPC
	end

AbandonedShip_Corridors_1F_EventScript_Charlie::
	trainerbattle_single TRAINER_CHARLIE, AbandonedShip_Corridors_1F_Text_CharlieIntro, AbandonedShip_Corridors_1F_Text_CharlieDefeat
	msgbox AbandonedShip_Corridors_1F_Text_CharliePostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Corridors_1F_Text_CharlieIntro:
	.string "Qu’est-ce qu’il y a de drôle à avoir\n"
	.string "ma bouée à bord du navire?$"

AbandonedShip_Corridors_1F_Text_CharlieDefeat:
	.string "Ouh là, tu m’as surpassé !$"

AbandonedShip_Corridors_1F_Text_CharliePostBattle:
	.string "Ce n’est pas facile de lancer des\n"
	.string "POKé BALL en tenant une bouée !$"

AbandonedShip_Corridors_1F_Text_IsntItFunHere:
	.string "C’est pas génial ici ?\n"
	.string "Je suis tout excité d’être là !$"
