RustboroCity_CuttersHouse_MapScripts::
	.byte 0

RustboroCity_CuttersHouse_EventScript_Cutter::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_CUT, RustboroCity_CuttersHouse_EventScript_ExplainCut
	msgbox RustboroCity_CuttersHouse_Text_YouCanPutThisHMToGoodUse, MSGBOX_DEFAULT
	giveitem ITEM_HM_CUT
	setflag FLAG_RECEIVED_HM_CUT
	msgbox RustboroCity_CuttersHouse_Text_ExplainCut, MSGBOX_DEFAULT
	release
	end

RustboroCity_CuttersHouse_EventScript_ExplainCut::
	msgbox RustboroCity_CuttersHouse_Text_ExplainCut, MSGBOX_DEFAULT
	release
	end

RustboroCity_CuttersHouse_EventScript_Lass::
	msgbox RustboroCity_CuttersHouse_Text_DadHelpedClearLandOfTrees, MSGBOX_NPC
	end

RustboroCity_CuttersHouse_Text_YouCanPutThisHMToGoodUse:
	.string "Cette expression déterminée…\n"
	.string "Cette façon souple de bouger…\l"
	.string "Et tes POKéMON bien entraînés…\p"
	.string "Tu es clairement un DRESSEUR talentueux !\p"
	.string "Non, attends, ne dis rien.\n"
	.string "Je peux le voir rien qu'en te regardant.\p"
	.string "Je suis sûr que tu sauras bien utiliser\n"
	.string "cette CAPACITÉ SECRÈTE.\p"
	.string "Pas besoin d'être modeste ou timide.\n"
	.string "Allez, prends-la !$"

RustboroCity_CuttersHouse_Text_ExplainCut:
	.string "Cette CAPACITÉ SECRÈTE, ou CS pour\n"
	.string "faire court, c'est COUPE.\p"
	.string "Une CS est une capacité que les POKéMON\n"
	.string "peuvent utiliser en dehors des combats.\p"
	.string "Tout POKéMON pouvant apprendre COUPE peut\n"
	.string "abattre de petits arbres si le DRESSEUR\l"
	.string "a obtenu le BADGE PIERRE.\p"
	.string "Et le mieux, c'est que tu n'as même pas\n"
	.string "besoin d'enseigner la capacité. Ça marche tout seul.$"

RustboroCity_CuttersHouse_Text_DadHelpedClearLandOfTrees:
	.string "Quand ils agrandissaient la ville de\n"
	.string "RUSTBORO, mon père a aidé.\p"
	.string "Il a fait utiliser COUPE à ses POKéMON\n"
	.string "pour défricher le terrain.$"
