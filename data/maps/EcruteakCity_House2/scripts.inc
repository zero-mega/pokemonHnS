EcruteakCity_House2_MapScripts::
	.byte 0

Ecruteak_Text_ItemfinderAdventure:
	.string "Ah. Tu es en aventure avec\n"
	.string "tes POKéMON ?\p"
	.string "Eh bien, qu'est-ce qu'une aventure\n"
	.string "sans chasse au trésor ?\p"
	.string "N'est-ce pas ? Je me trompe ?$"

Ecruteak_Text_ItemfinderTrueSpirit:
	.string "Bien ! Tu comprends le vrai\n"
	.string "esprit d'aventure.\p"
	.string "J'aime ça ! Prends ceci avec toi.$"

Ecruteak_Text_ItemfinderExplanation:
	.string "Il y a beaucoup d'objets cachés\n"
	.string "qui ne sont pas évidents.\p"
	.string "Utilise l'ITEMFINDER pour vérifier\n"
	.string "s'il y a un objet près de toi.\p"
	.string "Il ne montre pas l'endroit exact,\n"
	.string "alors il faudra chercher toi-même.\p"
	.string "Ah oui—j'ai entendu dire qu'il y a\n"
	.string "des objets dans la TOUR BRÛLÉE d'ECRUTEAK.$"

Ecruteak_Text_ItemfinderToEachHisOwn:
	.string "Oh… Chacun ses goûts, je suppose…$"

EcruteakCity_House2_EventScript_ItemFinderMan::
	lock
	faceplayer
	msgbox Ecruteak_Text_ItemFinderMan, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_House2_EventScript_Book::
	lock
	msgbox Ecruteak_Text_HistoryBook, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, EcruteakCity_House2_EventScript_Book2
	closemessage
	release
	end

EcruteakCity_House2_EventScript_Book2::
	msgbox Ecruteak_Text_TwoTowers, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, EcruteakCity_House2_EventScript_Book3
	release
	end

EcruteakCity_House2_EventScript_Book3::
	msgbox Ecruteak_Text_ThreeMon, MSGBOX_DEFAULT
	closemessage
	release
	end

Ecruteak_Text_ItemFinderMan::
	.string "IRISIA est une ville très ancienne.\n"
	.string "De nombreuses générations ont\l"
	.string "transmis leur histoire dans des livres comme ceux-ci.$"

Ecruteak_Text_HistoryBook:
	.string "HISTOIRE D'IRISIA\p"
	.string "Veux-tu la lire?$"

Ecruteak_Text_TwoTowers:
	.string "À IRISIA, il y avait deux tours.\p"
	.string "Chaque tour était le perchoir de\n"
	.string "puissants POKéMON volants.\p"
	.string "Mais l'une des tours a brûlé\n"
	.string "jusqu'au sol.\p"
	.string "Les deux POKéMON n'ont plus été vus\n"
	.string "depuis…\p"
	.string "Continuer la lecture?$"

Ecruteak_Text_ThreeMon:
	.string "IRISIA abritait aussi trois POKéMON\n"
	.string "qui couraient autour de la ville.\p"
	.string "On disait qu'ils étaient nés de\n"
	.string "l'eau, de la foudre et du feu.\p"
	.string "Mais ils ne pouvaient contenir leur\n"
	.string "puissance excessive.\p"
	.string "On raconte que les trois se sont\n"
	.string "enfuis comme le vent dans la plaine.$"
