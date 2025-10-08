SeafloorCavern_Room1_MapScripts::
	.byte 0

SeafloorCavern_Room1_EventScript_Grunt1::
	trainerbattle_single TRAINER_TROY, SeafloorCavern_Room1_Text_Grunt1Intro, SeafloorCavern_Room1_Text_Grunt1Defeat
	msgbox SeafloorCavern_Room1_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room1_EventScript_Grunt2::
	trainerbattle_single TRAINER_TULLY, SeafloorCavern_Room1_Text_Grunt2Intro, SeafloorCavern_Room1_Text_Grunt2Defeat
	msgbox SeafloorCavern_Room1_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room1_Text_Grunt1Intro:
	.string "On n'a pas besoin d'un gamin ici !\n"
	.string "Rentre chez toi, allez !$"

SeafloorCavern_Room1_Text_Grunt1Defeat:
	.string "Je veux rentrer chez moi…$"

SeafloorCavern_Room1_Text_Grunt1PostBattle:
	.string "Je veux une promotion pour pouvoir\n"
	.string "donner des ordres aux SBIRE…$"

SeafloorCavern_Room1_Text_Grunt2Intro:
	.string "Ce sous-marin… Il est minuscule dedans.\n"
	.string "J'ai mal partout !$"

SeafloorCavern_Room1_Text_Grunt2Defeat:
	.string "Perdre, ça fait mal !$"

SeafloorCavern_Room1_Text_Grunt2PostBattle:
	.string "Ce sous-marin qu'on a volé, sérieux,\n"
	.string "c'est l'enfer comme trajet.\l"
	.string "C'est bien trop serré là-dedans !$"

