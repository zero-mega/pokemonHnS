Route1_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route1_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route1_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route1_EventScript_SchoolboyDanny::
	trainerbattle_single TRAINER_DANNY, Route1_Text_SchoolboyDanny_Seen, Route1_Text_SchoolboyDanny_Beaten
	msgbox Route1_Text_SchoolboyDanny_AfterBattle, MSGBOX_AUTOCLOSE
	end

Route1_EventScript_Quinn::
	trainerbattle_single TRAINER_QUINN, Route1_Text_CooltrainerFQuinn_Seen, Route1_Text_CooltrainerFQuinn_Beaten
	msgbox Route1_Text_CooltrainerFQuinn_AfterBattle, MSGBOX_AUTOCLOSE
	end

Route1_EventScript_Sign::
	msgbox Route1_Text_Sign, MSGBOX_SIGN
	end

Route1_Text_SchoolboyDanny_Seen:
	.string "Quand des dresseurs se croisent,\n"
	.string "la première chose à faire, c'est combattre.$"

Route1_Text_SchoolboyDanny_Beaten:
	.string "Oh non… J'ai encore perdu…$"

Route1_Text_SchoolboyDanny_AfterBattle:
	.string "Pour les dresseurs, c'est normal de\n"
	.string "se battre à chaque rencontre.$"

Route1_Text_CooltrainerFQuinn_Seen:
	.string "Toi là-bas ! Tu veux te battre ?$"

Route1_Text_CooltrainerFQuinn_Beaten:
	.string "Je suis K.O.…$"

Route1_Text_CooltrainerFQuinn_AfterBattle:
	.string "Tu es fort.\p"
	.string "Tu as dû t'entraîner dur.$"

Route1_Text_Sign:
	.string "ROUTE 1\p"
	.string "BOURG PALETTE - JADIELLE$"
