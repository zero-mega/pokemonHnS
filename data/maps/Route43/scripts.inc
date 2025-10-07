Route43_MapScripts::
	.byte 0

Route43_EventScript_Ben::
	trainerbattle_single TRAINER_BEN Route43_Text_PokemaniacBenSeen, Route43_Text_PokemaniacBenBeaten
	msgbox Route43_Text_PokemaniacBenAfter, MSGBOX_AUTOCLOSE
	end

Route43_EventScript_Brent::
	trainerbattle_single TRAINER_BRENT Route43_Text_PokemaniacBrentSeen, Route43_Text_PokemaniacBrentBeaten
	msgbox Route43_Text_PokemaniacBrentAfter, MSGBOX_AUTOCLOSE
	end

Route43_EventScript_Ron::
	trainerbattle_single TRAINER_RON Route43_Text_PokemaniacRonSeen, Route43_Text_PokemaniacRonBeaten
	msgbox Route43_Text_PokemaniacRonAfter, MSGBOX_AUTOCLOSE
	end

Route43_EventScript_Marvin::
	trainerbattle_single TRAINER_MARVIN Route43_Text_FisherMarvinSeen, Route43_Text_FisherMarvinBeaten
	msgbox Route43_Text_FisherMarvinAfter, MSGBOX_AUTOCLOSE
	end
	
Route43_EventScript_Spencer::
	trainerbattle_single TRAINER_SPENCER Route43_Text_CamperSpencerSeen, Route43_Text_CamperSpencerBeaten
	msgbox Route43_Text_CamperSpencerAfter, MSGBOX_AUTOCLOSE
	end

Route43_EventScript_Tiffany::
	trainerbattle_single TRAINER_TIFFANY Route43_Text_PicnickerTiffanySeen, Route43_Text_PicnickerTiffanyBeaten
	msgbox Route43_Text_PicnickerTiffanyWantsPicnic, MSGBOX_AUTOCLOSE
	end

Route43_EventScript_Sign1::
	msgbox Route43_Sign2, MSGBOX_SIGN
	end

Route43_EventScript_Sign2::
	msgbox Route43_TrainerTips, MSGBOX_SIGN
	end

Route43_EventScript_Item_Max_Ether::
	finditem ITEM_MAX_ETHER
	end

Route43_Text_PokemaniacBenSeen:
    .string "J'adore les POKéMON !\p"
    .string "C'est pour ça que j'ai commencé--et\n"
    .string "c'est pour ça que je continue à en collectionner !$"

Route43_Text_PokemaniacBenBeaten:
    .string "Comment as-tu pu me faire ça ?$"

Route43_Text_PokemaniacBenAfter:
    .string "Qu'est-ce que j'aime à part les\n"
    .string "POKéMON ?\p"
    .string "MARY à la radio. Je parie qu'elle\n"
    .string "est mignonne !$"

Route43_Text_PokemaniacBrentSeen:
    .string "Hé ! As-tu des POKéMON rares ?$"

Route43_Text_PokemaniacBrentBeaten:
    .string "Oh, mes pauvres POKéMON ! Mes chéris !$"

Route43_Text_PokemaniacBrentAfter:
    .string "Je serais heureux de posséder ne\n"
    .string "serait-ce qu'un seul POKéMON rare.$"

Route43_Text_PokemaniacRonSeen:
    .string "Tu peux croire ça ?\p"
    .string "Un gars appelé SILVER s'est moqué de\n"
    .string "mes POKéMON !\p"
    .string "Zut ! Mes POKéMON sont géniaux !$"

Route43_Text_PokemaniacRonBeaten:
    .string "Mon NIDOKING s'est bien défendu !$"

Route43_Text_PokemaniacRonAfter:
    .string "C'est normal que les gens aiment\n"
    .string "différents types de POKéMON.\p"
    .string "Les POKéMON, ce n'est pas juste avoir\n"
    .string "le plus puissant.$"

Route43_Text_FisherMarvinSeen:
    .string "Je suis dans une mauvaise passe.\p"
    .string "C'est peut-être mon matériel.\p"
    .string "Combattons pour changer un peu !$"

Route43_Text_FisherMarvinBeaten:
    .string "J'ai perdu, mais je me sens mieux quand même.$"

Route43_Text_FisherMarvinAfter:
    .string "La LURE BALL de KURT est la meilleure\n"
    .string "pour attraper les POKéMON pêchés.\p"
    .string "Elle est bien plus efficace qu'une\n"
    .string "ULTRA BALL.$"

Route43_Text_CamperSpencerSeen:
    .string "Je peux faire tellement de choses avec\n"
    .string "mes POKéMON--c'est super amusant !$"

Route43_Text_CamperSpencerBeaten:
    .string "Perdre, ce n'est pas amusant du tout…$"

Route43_Text_CamperSpencerAfter:
    .string "Que se passe-t-il au LAC COLÈRE ?\p"
    .string "On voulait camper là-bas.$"

Route43_Text_PicnickerTiffanySeen:
    .string "Tu vas aussi au LAC COLÈRE ?\p"
    .string "Jouons un peu ensemble !$"

Route43_Text_PicnickerTiffanyBeaten:
    .string "J'ai trop joué !$"

Route43_Text_PicnickerTiffanyWantsPicnic:
    .string "Je fais un pique-nique avec mes POKéMON.\p"
    .string "Tu veux te joindre à nous ?$"

Route43_Sign1:
    .string "ROUTE 43\p"
    .string "LAC COLÈRE - ACAJOU$"

Route43_Sign2:
    .string "ROUTE 43\p"
    .string "LAC COLÈRE - ACAJOU$"

Route43_TrainerTips:
    .string "CONSEILS D'ENTRAÎNEUR\p"
    .string "Tous les POKéMON ont des points forts\n"
    .string "et des faiblesses selon leur type.\p"
    .string "Si leurs types diffèrent, un POKéMON\n"
    .string "de niveau supérieur peut perdre.\p"
    .string "Apprends quels types sont forts ou\n"
    .string "faibles face à ceux de tes POKéMON.$"
