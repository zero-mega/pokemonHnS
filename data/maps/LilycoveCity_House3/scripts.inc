LilycoveCity_House3_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_House3_OnTransition
	.byte 0

LilycoveCity_House3_OnTransition:
	random 4
	copyvar VAR_TEMP_1, VAR_RESULT
	end

LilycoveCity_House3_EventScript_PokefanF::
	lock
	faceplayer
	msgbox LilycoveCity_House3_Text_LearnFromMasterOfPokeblocks, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LilycoveCity_House3_EventScript_DeclinePokeblockLearn
	msgbox LilycoveCity_House3_Text_ExplainPokeblocks, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_House3_EventScript_DeclinePokeblockLearn::
	msgbox LilycoveCity_House3_Text_OhAreYouSure, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_House3_EventScript_Man::
	lock
	faceplayer
	msgbox LilycoveCity_House3_Text_HappyToHaveQuadruplets, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_House3_EventScript_GameBoyKid1::
	lock
	faceplayer
	switch VAR_TEMP_1
	case 0, LilycoveCity_House3_EventScript_WereDoingMultiBattle
	case 1, LilycoveCity_House3_EventScript_WereMixingRecords
	case 2, LilycoveCity_House3_EventScript_WereBlendingBerries
	case 3, LilycoveCity_House3_EventScript_WereDoingContest
	end

LilycoveCity_House3_EventScript_GameBoyKid2::
	lock
	faceplayer
	switch VAR_TEMP_1
	case 0, LilycoveCity_House3_EventScript_WereDoingMultiBattle
	case 1, LilycoveCity_House3_EventScript_WereMixingRecords
	case 2, LilycoveCity_House3_EventScript_WereBlendingBerries
	case 3, LilycoveCity_House3_EventScript_WereDoingContest
	end

LilycoveCity_House3_EventScript_GameBoyKid3::
	lock
	faceplayer
	switch VAR_TEMP_1
	case 0, LilycoveCity_House3_EventScript_WereDoingMultiBattle
	case 1, LilycoveCity_House3_EventScript_WereMixingRecords
	case 2, LilycoveCity_House3_EventScript_WereBlendingBerries
	case 3, LilycoveCity_House3_EventScript_WereDoingContest
	end

LilycoveCity_House3_EventScript_GameBoyKid4::
	lock
	faceplayer
	switch VAR_TEMP_1
	case 0, LilycoveCity_House3_EventScript_WereDoingMultiBattle
	case 1, LilycoveCity_House3_EventScript_WereMixingRecords
	case 2, LilycoveCity_House3_EventScript_WereBlendingBerries
	case 3, LilycoveCity_House3_EventScript_WereDoingContest
	end

LilycoveCity_House3_EventScript_WereDoingMultiBattle::
	msgbox LilycoveCity_House3_Text_GoingToWinMultiBattles, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House3_EventScript_WereMixingRecords::
	msgbox LilycoveCity_House3_Text_LikeMixingAtRecordCorner, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House3_EventScript_WereBlendingBerries::
	msgbox LilycoveCity_House3_Text_MakePokeblocksWithBerryBlender, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House3_EventScript_WereDoingContest::
	msgbox LilycoveCity_House3_Text_GoingToEnterContest, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House3_Text_LearnFromMasterOfPokeblocks:
	.string "Oh là là ! Tu voyages seul ?\n"
	.string "Mais tu es si jeune ! Bravo à toi !\p"
	.string "Je suis sûr que mes enfants pourraient\n"
	.string "apprendre une ou deux choses de toi !\p"
	.string "Moi ? Je suis un maître des {POKEBLOCK}S.\p"
	.string "Si je me concentre un peu, tu sais,\n"
	.string "je peux concocter d’excellents {POKEBLOCK}S.\p"
	.string "Veux-tu apprendre de moi,\n"
	.string "un maître des {POKEBLOCK}S ?$"

LilycoveCity_House3_Text_OhAreYouSure:
	.string "Oh ? Tu es sûr ?\p"
	.string "Tu ne devrais pas toujours essayer de tout\n"
	.string "faire tout seul, mon cher !$"

LilycoveCity_House3_Text_ExplainPokeblocks:
	.string "Oh, bien ! Tu es très intelligent !\n"
	.string "C’est un peu long, alors écoute bien !\p"
	.string "Tu es prêt ?\p"
	.string "Si tu regardes les {POKEBLOCK}S, tu verras\n"
	.string "qu’ils sont notés selon leur douceur.\p"
	.string "Plus la douceur est basse,\n"
	.string "mieux c’est. N’oublie pas ça !\p"
	.string "Un bon {POKEBLOCK} a une faible douceur\n"
	.string "et un niveau élevé.\p"
	.string "Un POKéMON peut manger plus de bons\n"
	.string "{POKEBLOCK}S que des ordinaires aussi.\p"
	.string "Et c’est important.\p"
	.string "Si tu veux faire des {POKEBLOCK}S lisses,\n"
	.string "utilise différents types de BAIES.\p"
	.string "Ne sois pas avare—le type de BAIES\n"
	.string "influence la douceur des {POKEBLOCK}S.\p"
	.string "Et encore une chose.\p"
	.string "Plus il y a de gens qui mélangent des BAIES,\n"
	.string "plus les {POKEBLOCK}S sont lisses.\p"
	.string "C’est pour ça que tu dois parler aux autres\n"
	.string "et faire des {POKEBLOCK}S ensemble.\p"
	.string "C’est à peu près tout ce qu’il faut savoir\n"
	.string "pour faire de bons {POKEBLOCK}S.\p"
	.string "Si tout le monde avait des POKéMON qu’il aime,\n"
	.string "des {POKEBLOCK}S lisses et une famille aimante,\l"
	.string "le monde serait plus heureux.\p"
	.string "N’abandonne pas, mon cher !$"

LilycoveCity_House3_Text_HappyToHaveQuadruplets:
	.string "Quand ma femme a eu des quadruplés,\n"
	.string "tu paries que j’étais choqué.\p"
	.string "Mais maintenant, les voir jouer ensemble,\n"
	.string "ça me rend heureux.$"

LilycoveCity_House3_Text_GoingToWinMultiBattles:
	.string "On fait des COMBATS MULTI, mais je sais\n"
	.string "que je vais gagner.$"

LilycoveCity_House3_Text_LikeMixingAtRecordCorner:
	.string "On aime mélanger des trucs au\n"
	.string "COIN ENREGISTREMENT.\p"
	.string "Mais qu’est-ce qui se mélange vraiment ?$"

LilycoveCity_House3_Text_MakePokeblocksWithBerryBlender:
	.string "On va faire des super {POKEBLOCK}S\n"
	.string "avec un MÉLANGEUR DE BAIES !$"

LilycoveCity_House3_Text_GoingToEnterContest:
	.string "Je veux me vanter de la force de mon\n"
	.string "POKéMON, alors on va participer\l"
	.string "à un CONCOURS ensemble.$"
