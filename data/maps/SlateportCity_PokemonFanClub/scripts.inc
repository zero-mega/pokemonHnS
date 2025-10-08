SlateportCity_PokemonFanClub_MapScripts::
	.byte 0

SlateportCity_PokemonFanClub_EventScript_Chairman::
	lock
	faceplayer
	goto_if_unset FLAG_ENTERED_CONTEST, SlateportCity_PokemonFanClub_EventScript_ChairmanNotEnteredContest
	call_if_unset FLAG_MET_SLATEPORT_FANCLUB_CHAIRMAN, SlateportCity_PokemonFanClub_EventScript_MeetChairman
	switch VAR_SLATEPORT_FAN_CLUB_STATE
	case 0, SlateportCity_PokemonFanClub_EventScript_ChairmanFirstAssessment
	case 1, SlateportCity_PokemonFanClub_EventScript_ChairmanTryAssessPokemon
	case 2, SlateportCity_PokemonFanClub_EventScript_NoMoreScarves
	release
	end

SlateportCity_PokemonFanClub_EventScript_ChairmanFirstAssessment::
	setvar VAR_SLATEPORT_FAN_CLUB_STATE, 1
	msgbox SlateportCity_PokemonFanClub_Text_AllowMeToExamineYourPokemon, MSGBOX_DEFAULT
	goto SlateportCity_PokemonFanClub_EventScript_ChairmanAssessLeadMon
	end

SlateportCity_PokemonFanClub_EventScript_ChairmanTryAssessPokemon::
	setvar VAR_TEMP_2, 0
	call_if_set FLAG_RECEIVED_YELLOW_SCARF, SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf
	call_if_set FLAG_RECEIVED_GREEN_SCARF, SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf
	call_if_set FLAG_RECEIVED_PINK_SCARF, SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf
	call_if_set FLAG_RECEIVED_BLUE_SCARF, SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf
	call_if_set FLAG_RECEIVED_RED_SCARF, SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf
	call_if_eq VAR_TEMP_2, CONTEST_CATEGORIES_COUNT, SlateportCity_PokemonFanClub_EventScript_ReceivedAllScarves
	goto_if_eq VAR_SLATEPORT_FAN_CLUB_STATE, 2, SlateportCity_PokemonFanClub_EventScript_NoMoreScarves
	msgbox SlateportCity_PokemonFanClub_Text_HowIsYourPokemonGrowing, MSGBOX_DEFAULT
	goto SlateportCity_PokemonFanClub_EventScript_ChairmanAssessLeadMon
	end

SlateportCity_PokemonFanClub_EventScript_NoMoreScarves::
	msgbox SlateportCity_PokemonFanClub_Text_NothingElseToGiveYou, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_ChairmanAssessLeadMon::
	msgbox SlateportCity_PokemonFanClub_Text_HmHmISee, MSGBOX_DEFAULT
	setvar VAR_TEMP_1, 0
	call_if_unset FLAG_RECEIVED_YELLOW_SCARF, SlateportCity_PokemonFanClub_EventScript_CheckMonTough
	call_if_unset FLAG_RECEIVED_GREEN_SCARF, SlateportCity_PokemonFanClub_EventScript_CheckMonSmart
	call_if_unset FLAG_RECEIVED_PINK_SCARF, SlateportCity_PokemonFanClub_EventScript_CheckMonCute
	call_if_unset FLAG_RECEIVED_BLUE_SCARF, SlateportCity_PokemonFanClub_EventScript_CheckMonBeauty
	call_if_unset FLAG_RECEIVED_RED_SCARF, SlateportCity_PokemonFanClub_EventScript_CheckMonCool
	bufferleadmonspeciesname STR_VAR_1
	switch VAR_TEMP_1
	case 0, SlateportCity_PokemonFanClub_EventScript_NoHighConditions
	case 1, SlateportCity_PokemonFanClub_EventScript_GiveRedScarf
	case 2, SlateportCity_PokemonFanClub_EventScript_GiveBlueScarf
	case 3, SlateportCity_PokemonFanClub_EventScript_GivePinkScarf
	case 4, SlateportCity_PokemonFanClub_EventScript_GiveGreenScarf
	case 5, SlateportCity_PokemonFanClub_EventScript_GiveYellowScarf
	release
	end

SlateportCity_PokemonFanClub_EventScript_ReceivedAllScarves::
	setvar VAR_SLATEPORT_FAN_CLUB_STATE, 2
	return

SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf::
	addvar VAR_TEMP_2, 1
	return

SlateportCity_PokemonFanClub_EventScript_NoHighConditions::
	msgbox SlateportCity_PokemonFanClub_Text_GiveMonMorePokeblocks, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_GiveRedScarf::
	checkitemspace ITEM_RED_SCARF
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf
	msgbox SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_RED_SCARF
	giveitem ITEM_RED_SCARF
	msgbox SlateportCity_PokemonFanClub_Text_ExplainRedScarf, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_GiveBlueScarf::
	checkitemspace ITEM_BLUE_SCARF
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf
	msgbox SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_BLUE_SCARF
	giveitem ITEM_BLUE_SCARF
	msgbox SlateportCity_PokemonFanClub_Text_ExplainBlueScarf, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_GivePinkScarf::
	checkitemspace ITEM_PINK_SCARF
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf
	msgbox SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_PINK_SCARF
	giveitem ITEM_PINK_SCARF
	msgbox SlateportCity_PokemonFanClub_Text_ExplainPinkScarf, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_GiveGreenScarf::
	checkitemspace ITEM_GREEN_SCARF
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf
	msgbox SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_GREEN_SCARF
	giveitem ITEM_GREEN_SCARF
	msgbox SlateportCity_PokemonFanClub_Text_ExplainGreenScarf, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_GiveYellowScarf::
	checkitemspace ITEM_YELLOW_SCARF
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf
	msgbox SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_YELLOW_SCARF
	giveitem ITEM_YELLOW_SCARF
	msgbox SlateportCity_PokemonFanClub_Text_ExplainYellowScarf, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf::
	msgbox SlateportCity_PokemonFanClub_Text_NoSpaceForReward, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_CheckMonCool::
	specialvar VAR_RESULT, CheckLeadMonCool
	call_if_eq VAR_RESULT, TRUE, SlateportCity_PokemonFanClub_EventScript_SetMonCool
	return

SlateportCity_PokemonFanClub_EventScript_SetMonCool::
	setvar VAR_TEMP_1, 1
	return

SlateportCity_PokemonFanClub_EventScript_CheckMonBeauty::
	specialvar VAR_RESULT, CheckLeadMonBeauty
	call_if_eq VAR_RESULT, TRUE, SlateportCity_PokemonFanClub_EventScript_SetMonBeauty
	return

SlateportCity_PokemonFanClub_EventScript_SetMonBeauty::
	setvar VAR_TEMP_1, 2
	return

SlateportCity_PokemonFanClub_EventScript_CheckMonCute::
	specialvar VAR_RESULT, CheckLeadMonCute
	call_if_eq VAR_RESULT, TRUE, SlateportCity_PokemonFanClub_EventScript_SetMonCute
	return

SlateportCity_PokemonFanClub_EventScript_SetMonCute::
	setvar VAR_TEMP_1, 3
	return

SlateportCity_PokemonFanClub_EventScript_CheckMonSmart::
	specialvar VAR_RESULT, CheckLeadMonSmart
	call_if_eq VAR_RESULT, TRUE, SlateportCity_PokemonFanClub_EventScript_SetMonSmart
	return

SlateportCity_PokemonFanClub_EventScript_SetMonSmart::
	setvar VAR_TEMP_1, 4
	return

SlateportCity_PokemonFanClub_EventScript_CheckMonTough::
	specialvar VAR_RESULT, CheckLeadMonTough
	call_if_eq VAR_RESULT, TRUE, SlateportCity_PokemonFanClub_EventScript_SetMonTough
	return

SlateportCity_PokemonFanClub_EventScript_SetMonTough::
	setvar VAR_TEMP_1, 5
	return

SlateportCity_PokemonFanClub_EventScript_ChairmanNotEnteredContest::
	goto_if_set FLAG_MET_SLATEPORT_FANCLUB_CHAIRMAN, SlateportCity_PokemonFanClub_EventScript_ChairmanEnterContest
	msgbox SlateportCity_PokemonFanClub_Text_MeetChairman, MSGBOX_DEFAULT
	setflag FLAG_MET_SLATEPORT_FANCLUB_CHAIRMAN
	release
	end

SlateportCity_PokemonFanClub_EventScript_ChairmanEnterContest::
	msgbox SlateportCity_PokemonFanClub_Text_LikeToSeeEnteredContestPokemon, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_MeetChairman::
	msgbox SlateportCity_PokemonFanClub_Text_MeetChairman, MSGBOX_DEFAULT
	setflag FLAG_MET_SLATEPORT_FANCLUB_CHAIRMAN
	return

SlateportCity_PokemonFanClub_EventScript_SootheBellWoman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_SOOTHE_BELL, SlateportCity_PokemonFanClub_EventScript_ReceivedSootheBell
	msgbox SlateportCity_PokemonFanClub_Text_ShowMePokemonThatLoveYou, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	goto_if_ge VAR_RESULT, FRIENDSHIP_150_TO_199, SlateportCity_PokemonFanClub_EventScript_GiveSootheBell
	release
	end

SlateportCity_PokemonFanClub_EventScript_GiveSootheBell::
	playse SE_PIN
	applymovement VAR_LAST_TALKED, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_LAST_TALKED, Common_Movement_Delay48
	waitmovement 0
	msgbox SlateportCity_PokemonFanClub_Text_PokemonAdoresYou, MSGBOX_DEFAULT
	giveitem ITEM_SOOTHE_BELL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_SOOTHE_BELL
	release
	end

SlateportCity_PokemonFanClub_EventScript_ReceivedSootheBell::
	msgbox SlateportCity_PokemonFanClub_Text_TreatPokemonWithLove, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_Man::
	msgbox SlateportCity_PokemonFanClub_Text_PokemonDontLikeFainting, MSGBOX_NPC
	end

SlateportCity_PokemonFanClub_EventScript_Twin::
	msgbox SlateportCity_PokemonFanClub_Text_MonEnjoyedProtein, MSGBOX_NPC
	end

SlateportCity_PokemonFanClub_EventScript_Skitty::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SKITTY, CRY_MODE_NORMAL
	msgbox SlateportCity_PokemonFanClub_Text_Skitty, MSGBOX_DEFAULT
	waitmoncry
	release
	end

SlateportCity_PokemonFanClub_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox SlateportCity_PokemonFanClub_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

SlateportCity_PokemonFanClub_EventScript_Azumarill::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZUMARILL, CRY_MODE_NORMAL
	msgbox SlateportCity_PokemonFanClub_Text_Azumarill, MSGBOX_DEFAULT
	waitmoncry
	release
	end

SlateportCity_PokemonFanClub_Text_MeetChairman:
	.string "Hum-hum ! Je suis le PRÉSIDENT du\n"
	.string "CLUB POKéMON !\p"
	.string "En tant que PRÉSIDENT, je suis\n"
	.string "naturellement le plus important !\p"
	.string "Personne ne peut me surpasser quand il\n"
	.string "s'agit d'élever des POKéMON. Personne !\p"
	.string "Eh bien, laissez-moi vous parler des\n"
	.string "CONCOURS POKéMON.\p"
	.string "Ce sont des événements où l'on peut\n"
	.string "montrer ses POKéMON au monde entier !\p"
	.string "Cependant, ils ont lieu dans des villes\n"
	.string "lointaines, donc je ne peux pas y\n"
	.string "participer aussi souvent que je le\n"
	.string "voudrais.\p"
	.string "C'est pourquoi nous nous réunissons ici\n"
	.string "pour montrer nos POKéMON, et voir ceux\l"
	.string "des autres.$"

SlateportCity_PokemonFanClub_Text_LikeToSeeEnteredContestPokemon:
	.string "Le POKéMON d'un DRESSEUR qui a\n"
	.string "participé à un CONCOURS POKéMON…\l"
	.string "Voilà ce que j'aimerais voir.$"

SlateportCity_PokemonFanClub_Text_AllowMeToExamineYourPokemon:
	.string "Hum-hum ! Je vois que tu as participé à\n"
	.string "un CONCOURS POKéMON !\p"
	.string "S'il te plaît ! Permets-moi d'examiner\n"
	.string "comment tu as élevé ton POKéMON.\p"
	.string "Cela me ravit de voir des POKéMON\n"
	.string "élevés par d'autres DRESSEURS.\p"
	.string "L'expression heureuse des POKéMON\n"
	.string "élevés avec soin…\p"
	.string "Le regard bienveillant du DRESSEUR qui\n"
	.string "a choyé et élevé le POKéMON…\p"
	.string "Rien que d'y penser, mon cœur déborde\n"
	.string "de joie.\p"
	.string "Oh ! Je te prie de m'excuser !\n"
	.string "Pardonne-moi de bavarder ainsi !\p"
	.string "S'il te plaît ! Permets-moi d'examiner\n"
	.string "à quel point ton POKéMON a grandi !$"

SlateportCity_PokemonFanClub_Text_HowIsYourPokemonGrowing:
	.string "Comment ton POKéMON grandit-il ?\n"
	.string "Permets-moi de l'examiner.$"

SlateportCity_PokemonFanClub_Text_HmHmISee:
	.string "Hum, hum…\n"
	.string "Je vois…$"

SlateportCity_PokemonFanClub_Text_GiveMonMorePokeblocks:
	.string "Hmm… Ce n'est ni mauvais, ni\n"
	.string "vraiment bon…\p"
	.string "Toi, le DRESSEUR, tu dois faire plus\n"
	.string "d'efforts pour élever ce POKéMON !\p"
	.string "Par exemple, puis-je te suggérer de\n"
	.string "lui donner plus de {POKEBLOCK}S ?$"

SlateportCity_PokemonFanClub_Text_NoSpaceForReward:
	.string "Oh, là là…\p"
	.string "Ton POKéMON grandit très bien, tu\n"
	.string "mérites une récompense.\p"
	.string "Malheureusement, tu n'as pas de place\n"
	.string "pour cela dans ton SAC.$"

SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis:
	.string "Ton {STR_VAR_1}, il grandit d'une\n"
	.string "façon vraiment impressionnante !\l"
	.string "C'est un superbe spécimen !\p"
	.string "Mais ! Si tu lui donnais ceci,\n"
	.string "il grandirait encore mieux ! Vraiment !$"

SlateportCity_PokemonFanClub_Text_ExplainRedScarf:
	.string "Fais tenir ce FOULARD ROUGE à un\n"
	.string "POKéMON.\p"
	.string "Tout le monde reconnaîtra la classe\n"
	.string "de ce POKéMON !$"

SlateportCity_PokemonFanClub_Text_ExplainBlueScarf:
	.string "Fais tenir ce FOULARD BLEU à un\n"
	.string "POKéMON.\p"
	.string "Sa beauté sera encore plus mise\n"
	.string "en valeur !$"

SlateportCity_PokemonFanClub_Text_ExplainPinkScarf:
	.string "Fais tenir ce FOULARD ROSE à un\n"
	.string "POKéMON.\p"
	.string "Cela fera ressortir encore plus la\n"
	.string "mignonnerie du POKéMON !$"

SlateportCity_PokemonFanClub_Text_ExplainGreenScarf:
	.string "Fais tenir ce FOULARD VERT à un\n"
	.string "POKéMON.\p"
	.string "Cela augmentera l'intelligence\n"
	.string "de ton POKéMON !$"

SlateportCity_PokemonFanClub_Text_ExplainYellowScarf:
	.string "Fais tenir ce FOULARD JAUNE à un\n"
	.string "POKéMON.\p"
	.string "Cela renforcera la robustesse de\n"
	.string "ton POKéMON !$"

SlateportCity_PokemonFanClub_Text_NothingElseToGiveYou:
	.string "Je suis désolé, mais je n'ai plus rien\n"
	.string "à te donner ! Plus rien du tout !\p"
	.string "Après tout, tu as le don d'élever des\n"
	.string "POKéMON sans utiliser d'objets !$"

SlateportCity_PokemonFanClub_Text_ShowMePokemonThatLoveYou:
	.string "J'adore voir des POKéMON qui aiment\n"
	.string "leur DRESSEUR.\p"
	.string "Les POKéMON sont très sensibles aux\n"
	.string "sentiments de leur DRESSEUR.\p"
	.string "Si tu traites ton POKéMON avec amour\n"
	.string "et attention, il t'aimera en retour.\p"
	.string "Quand ton POKéMON t'aimera vraiment,\n"
	.string "viens me le montrer.$"

SlateportCity_PokemonFanClub_Text_PokemonAdoresYou:
	.string "Ton POKéMON t'adore vraiment.\p"
	.string "Pour toi, DRESSEUR si attentionné,\n"
	.string "un cadeau du CLUB POKéMON !$"

SlateportCity_PokemonFanClub_Text_TreatPokemonWithLove:
	.string "Les POKéMON sont très sensibles aux\n"
	.string "sentiments de leur DRESSEUR.\p"
	.string "Si tu traites ton POKéMON avec amour\n"
	.string "et attention, il t'aimera en retour.$"

SlateportCity_PokemonFanClub_Text_PokemonDontLikeFainting:
	.string "Si tu laisses souvent un POKéMON\n"
	.string "tomber K.O. en combat, il finira par\n"
	.string "t'en vouloir.\p"
	.string "Bientôt, il te fera moins confiance\n"
	.string "en tant que DRESSEUR.\p"
	.string "En d'autres termes, il ne t'aimera\n"
	.string "vraiment pas beaucoup.$"

SlateportCity_PokemonFanClub_Text_MonEnjoyedProtein:
	.string "Les POKéMON aiment-ils qu'on utilise\n"
	.string "des objets sur eux ?\p"
	.string "Le mien avait l'air très content quand\n"
	.string "je lui ai donné des PROTÉINES.$"

SlateportCity_PokemonFanClub_Text_Skitty:
	.string "SKITTY : Fffnyaaaah…$"

SlateportCity_PokemonFanClub_Text_Zigzagoon:
	.string "ZIGZATON : Kyuuu…$"

SlateportCity_PokemonFanClub_Text_Azumarill:
	.string "AZUMARILL : Marimari ?$"
