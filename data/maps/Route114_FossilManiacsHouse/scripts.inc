Route114_FossilManiacsHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route114_FossilManiacsHouse_OnTransition
	.byte 0

Route114_FossilManiacsHouse_OnTransition:
	setflag FLAG_LANDMARK_FOSSIL_MANIACS_HOUSE
	end

Route114_FossilManiacsHouse_EventScript_FossilManiacsBrother::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_DIG, Route114_FossilManiacsHouse_EventScript_ReceivedDig
	msgbox Route114_FossilManiacsHouse_Text_HaveThisToDigLikeMyBrother, MSGBOX_DEFAULT
	giveitem ITEM_TM_DIG
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_DIG
	release
	end

Route114_FossilManiacsHouse_EventScript_ReceivedDig::
	msgbox Route114_FossilManiacsHouse_Text_DigReturnsYouToEntrance, MSGBOX_DEFAULT
	release
	end

Route114_FossilManiacsHouse_EventScript_RockDisplay::
	msgbox Route114_FossilManiacsHouse_Text_RocksFillDisplayCase, MSGBOX_SIGN
	end

Route114_FossilManiacsHouse_EventScript_Bookshelf::
	msgbox Route114_FossilManiacsHouse_Text_CrammedWithBooks, MSGBOX_SIGN
	end

Route114_FossilManiacsHouse_Text_HaveThisToDigLikeMyBrother:
	.string "Mon grand frère est le MANIAQUE DES FOSSILES…\n"
	.string "C'est un gars sympa qui adore les FOSSILES…\p"
	.string "Il adore aussi creuser des trous…\n"
	.string "Il a creusé ce trou tout seul…\p"
	.string "Tu peux prendre ça, comme ça tu pourras CREUSER\n"
	.string "des trous comme mon grand frère…$"

Route114_FossilManiacsHouse_Text_DigReturnsYouToEntrance:
	.string "Si tu fais CREUSER un POKéMON dans une\n"
	.string "grotte, tu seras ramené à l'entrée…$"

Route114_FossilManiacsHouse_Text_RocksFillDisplayCase:
	.string "Des roches aux formes étranges remplissent\n"
	.string "la vitrine…$"

Route114_FossilManiacsHouse_Text_CrammedWithBooks:
	.string "LA COMPOSITION DES COUCHES…\n"
	.string "COMMENT LA PLUIE FORME LE PAYSAGE…\l"
	.string "PIERRES, SOL ET ROCHE…\p"
	.string "C'est rempli de livres.$"
