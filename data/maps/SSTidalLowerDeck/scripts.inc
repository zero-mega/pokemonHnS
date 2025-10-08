SSTidalLowerDeck_MapScripts::
	.byte 0

SSTidalLowerDeck_EventScript_Phillip::
	trainerbattle_single TRAINER_PHILLIP, SSTidalLowerDeck_Text_PhillipIntro, SSTidalLowerDeck_Text_PhillipDefeat
	msgbox SSTidalLowerDeck_Text_PhillipPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalLowerDeck_EventScript_Leonard::
	trainerbattle_single TRAINER_LEONARD, SSTidalLowerDeck_Text_LeonardIntro, SSTidalLowerDeck_Text_LeonardDefeat
	msgbox SSTidalLowerDeck_Text_LeonardPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalLowerDeck_Text_PhillipIntro:
	.string "Arrrgh ! J'en ai marre et je suis crevé\n"
	.string "de nettoyer cet immense endroit !\p"
	.string "Allons, faisons un petit combat !$"

SSTidalLowerDeck_Text_PhillipDefeat:
	.string "Petit frère, j'ai perdu !$"

SSTidalLowerDeck_Text_PhillipPostBattle:
	.string "Nous sommes les FRÈRES DU MÉNAGE !\p"
	.string "Le grand verse le détergent,\n"
	.string "et le petit frotte !$"

SSTidalLowerDeck_Text_LeonardIntro:
	.string "Ici, c'est la cale du navire.\n"
	.string "Il y a plein de place.\l"
	.string "C'est parfait pour un combat POKéMON.$"

SSTidalLowerDeck_Text_LeonardDefeat:
	.string "Grand frère, j'ai perdu !$"

SSTidalLowerDeck_Text_LeonardPostBattle:
	.string "Nous sommes les FRÈRES DU MÉNAGE !\p"
	.string "Le grand verse le détergent,\n"
	.string "et le petit frotte !$"

