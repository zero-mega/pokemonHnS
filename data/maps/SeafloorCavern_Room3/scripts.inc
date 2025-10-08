SeafloorCavern_Room3_MapScripts::
	.byte 0

SeafloorCavern_Room3_EventScript_Shelly::
	trainerbattle_single TRAINER_GRANT, SeafloorCavern_Room3_Text_ShellyIntro, SeafloorCavern_Room3_Text_ShellyDefeat
	msgbox SeafloorCavern_Room3_Text_ShellyPostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room3_EventScript_Grunt5::
	trainerbattle_single TRAINER_VANCE, SeafloorCavern_Room3_Text_Grunt5Intro, SeafloorCavern_Room3_Text_Grunt5Defeat
	msgbox SeafloorCavern_Room3_Text_Grunt5PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room3_Text_ShellyIntro:
	.string "Ahahahaha!\p"
	.string "Comment as-tu réussi à arriver ici sans\n"
	.string "sous-marin ?\l"
	.string "Quel enfant impressionnant !\p"
	.string "Mais… Je ne peux pas te laisser\n"
	.string "fouiner ici.\p"
	.string "Et puis, je veux me venger de ce qui\n"
	.string "s'est passé à l'INSTITUT Météo…\p"
	.string "Je vais te donner un avant-goût\n"
	.string "de la douleur ! Prépare-toi !$"

SeafloorCavern_Room3_Text_ShellyDefeat:
	.string "Ahahahaha!\p"
	.string "Aïe !$"

SeafloorCavern_Room3_Text_ShellyPostBattle:
	.string "Ahahahaha!\n"
	.string "Tu es vraiment trop fort.\p"
	.string "C'est vraiment dommage que tu ne sois\n"
	.string "pas membre de la TEAM AQUA.\p"
	.string "Tu aurais pu profiter du monde\n"
	.string "fabuleux que notre CHEF a promis\l"
	.string "à ses membres…$"

SeafloorCavern_Room3_Text_Grunt5Intro:
	.string "Pour que notre rêve devienne réalité,\n"
	.string "nous avons besoin de la puissance des POKéMON.\p"
	.string "Mais des gêneurs comme toi utilisent la\n"
	.string "puissance des POKéMON pour nous contrarier\l"
	.string "même dans un endroit comme celui-ci !\p"
	.string "La vie ne se passe jamais comme\n"
	.string "on le voudrait !$"

SeafloorCavern_Room3_Text_Grunt5Defeat:
	.string "Gwah !$"

SeafloorCavern_Room3_Text_Grunt5PostBattle:
	.string "Tu sais, on n'oserait jamais remettre\n"
	.string "en question les motivations de notre chef.\p"
	.string "Mais toi, tu n'es qu'un gamin,\n"
	.string "et tu t'opposes à notre CHEF.\p"
	.string "Peut-être…\n"
	.string "Tu dois vraiment être spécial…$"
