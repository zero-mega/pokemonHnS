Route26_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route26_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route26_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route26_EventScript_Jake::
	trainerbattle_single TRAINER_JAKE Route26_Text_CooltrainermJakeSeen, Route26_Text_CooltrainermJakeBeaten
	msgbox Route26_Text_CooltrainermJakeAfter, MSGBOX_AUTOCLOSE
	end

Route26_EventScript_Gaven::
	trainerbattle_single TRAINER_GAVEN Route26_Text_CooltrainermGavenSeen, Route26_Text_CooltrainermGavenBeaten
	msgbox Route26_Text_CooltrainermGavenAfter, MSGBOX_AUTOCLOSE
	end

Route26_EventScript_Joyce::
	trainerbattle_single TRAINER_JOYCE Route26_Text_CooltrainerfJoyceSeen, Route26_Text_CooltrainerfJoyceBeaten
	msgbox Route26_Text_CooltrainerfJoyceAfter, MSGBOX_AUTOCLOSE
	end

Route26_EventScript_Beth::
	trainerbattle_single TRAINER_BETH Route26_Text_CooltrainerfBethSeen, Route26_Text_CooltrainerfBethBeaten
	msgbox Route26_Text_CooltrainerfBethAfter, MSGBOX_AUTOCLOSE
	end

Route26_EventScript_Richard::
	trainerbattle_single TRAINER_RICHARD Route26_Text_PsychicRichardSeen, Route26_Text_PsychicRichardBeaten
	msgbox Route26_Text_PsychicRichardAfter, MSGBOX_AUTOCLOSE
	end

Route26_Text_CooltrainermJakeSeen:
    .string "Je fais mes dernières préparations\n"
    .string "pour la LIGUE POKéMON.$"

Route26_Text_CooltrainermJakeBeaten:
    .string "J'ai tout gâché !$"

Route26_Text_CooltrainermJakeAfter:
    .string "Ce sera difficile de gagner à la\n"
    .string "LIGUE.\p"
    .string "Je dois encore m'entraîner.\p"
    .string "J'ai entendu dire que le CONSEIL\n"
    .string "4 de la LIGUE est plus fort que les CHAMPIONS d'ARÈNE.$"

Route26_Text_CooltrainermGavenSeen:
    .string "En vivant des combats difficiles,\n"
    .string "on devient plus fort.$"

Route26_Text_CooltrainermGavenBeaten:
    .string "Aaah ! La vie est encore plus dure !$"

Route26_Text_CooltrainermGavenAfter:
    .string "Pour aller à la LIGUE POKéMON, tu\n"
    .string "dois passer la ROUTE VICTOIRE.\p"
    .string "Mais la ROUTE VICTOIRE est difficile.\p"
    .string "Presque personne n'y va !$"

Route26_Text_CooltrainerfJoyceSeen:
    .string "Si tu es arrivé jusqu'ici,\n"
    .string "tu dois être fort.\p"
    .string "Je vais donner tout ce que j'ai\n"
    .string "dans ce combat !$"

Route26_Text_CooltrainerfJoyceBeaten:
    .string "Non ! Je n'y crois pas !$"

Route26_Text_CooltrainerfJoyceAfter:
    .string "J'ai battu huit CHAMPIONS d'ARÈNE,\n"
    .string "alors j'étais confiante.\p"
    .string "Je devrai faire mieux la prochaine fois.$"

Route26_Text_CooltrainerfBethSeen:
    .string "J'ai perdu contre un dresseur nommé SILVER.\p"
    .string "Il était vraiment fort, mais…\p"
    .string "C'était comme s'il devait absolument\n"
    .string "gagner à tout prix.\p"
    .string "J'ai eu pitié de ses POKéMON.$"

Route26_Text_CooltrainerfBethBeaten:
    .string "Les POKéMON ne sont pas des outils de guerre.$"

Route26_Text_CooltrainerfBethAfter:
    .string "Les POKéMON sont des partenaires\n"
    .string "précieux pour la vie.$"

Route26_Text_PsychicRichardSeen:
    .string "Ouah, regarde tous ces BADGES !\n"
    .string "Je suis impressionné.\p"
    .string "Mais tu n'es pas satisfait de juste\n"
    .string "les collectionner, n'est-ce pas ?$"

Route26_Text_PsychicRichardBeaten:
    .string "Beau combat !$"

Route26_Text_PsychicRichardAfter:
    .string "Les gens et les POKéMON grandissent\n"
    .string "grâce à leurs expériences.\p"
    .string "Ne deviens pas paresseux ou complaisant.$"

Route26_Text_Sign:
    .string "ROUTE 26\p"
    .string "LIGUE POKéMON\n"
    .string "PORTAIL D'ACCUEIL$"
