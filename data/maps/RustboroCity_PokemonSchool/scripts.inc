RustboroCity_PokemonSchool_MapScripts::
	.byte 0

RustboroCity_PokemonSchool_EventScript_Blackboard::
	lockall
	msgbox RustboroCity_PokemonSchool_Text_BlackboardListsStatusChanges, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic::
	message RustboroCity_PokemonSchool_Text_ReadWhichTopic
	waitmessage
	multichoicegrid 8, 1, MULTI_STATUS_INFO, 3, FALSE
	switch VAR_RESULT
	case 0, RustboroCity_PokemonSchool_EventScript_Poison
	case 1, RustboroCity_PokemonSchool_EventScript_Paralysis
	case 2, RustboroCity_PokemonSchool_EventScript_Sleep
	case 3, RustboroCity_PokemonSchool_EventScript_Burn
	case 4, RustboroCity_PokemonSchool_EventScript_Freeze
	case 5, RustboroCity_PokemonSchool_EventScript_ExitTopicSelect
	case MULTI_B_PRESSED, RustboroCity_PokemonSchool_EventScript_ExitTopicSelect
	end

RustboroCity_PokemonSchool_EventScript_Poison::
	msgbox RustboroCity_PokemonSchool_Text_ExplainPoison, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Paralysis::
	msgbox RustboroCity_PokemonSchool_Text_ExplainParalysis, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Sleep::
	msgbox RustboroCity_PokemonSchool_Text_ExplainSleep, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Burn::
	msgbox RustboroCity_PokemonSchool_Text_ExplainBurn, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Freeze::
	msgbox RustboroCity_PokemonSchool_Text_ExplainFreeze, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_ExitTopicSelect::
	releaseall
	end

RustboroCity_PokemonSchool_EventScript_GameboyKid1::
	msgbox RustboroCity_PokemonSchool_Text_TradingRightNow, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_GameboyKid2::
	msgbox RustboroCity_PokemonSchool_Text_AlwaysWantedSeedot, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_RichBoy::
	msgbox RustboroCity_PokemonSchool_Text_PokemontCantUseManMadeItems, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_Lass::
	msgbox RustboroCity_PokemonSchool_Text_ConfusedPokemonAttacksItself, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_SchoolKidM::
	msgbox RustboroCity_PokemonSchool_Text_PokemonHealItselfWithBerry, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_StudentNotebook::
	msgbox RustboroCity_PokemonSchool_Text_StudentsNotes, MSGBOX_SIGN
	end

RustboroCity_PokemonSchool_EventScript_Teacher::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_QUICK_CLAW, RustboroCity_PokemonSchool_EventScript_GaveQuickClaw
	call_if_eq VAR_FACING, DIR_EAST, RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsEast
	call_if_eq VAR_FACING, DIR_WEST, RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsWest
	msgbox RustboroCity_PokemonSchool_Text_StudentsWhoDontStudyGetQuickClaw, MSGBOX_DEFAULT
	giveitem ITEM_QUICK_CLAW
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	setflag FLAG_RECEIVED_QUICK_CLAW
	release
	end

RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsEast::
	applymovement VAR_LAST_TALKED, RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsEast
	waitmovement 0
	return

RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsWest::
	applymovement VAR_LAST_TALKED, RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsWest
	waitmovement 0
	return

RustboroCity_PokemonSchool_EventScript_GaveQuickClaw::
	msgbox RustboroCity_PokemonSchool_Text_ExplainQuickClaw, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	release
	end

RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsWest:
	walk_left
	walk_down
	walk_down
	walk_right
	walk_in_place_faster_down
	delay_16
	delay_16
	delay_16
	walk_down
	walk_in_place_faster_left
	delay_16
	delay_16
	walk_right
	delay_16
	delay_16
	delay_8
	walk_up
	walk_left
	walk_left
	walk_up
	walk_up
	walk_right
	step_end

RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsEast:
	walk_right
	walk_right
	walk_down
	walk_down
	walk_left
	walk_left
	walk_in_place_faster_down
	delay_16
	delay_16
	delay_16
	walk_down
	walk_in_place_faster_left
	delay_16
	delay_16
	walk_right
	delay_16
	delay_16
	delay_8
	walk_up
	walk_right
	walk_up
	walk_up
	walk_left
	walk_left
	step_end

RustboroCity_PokemonSchool_EventScript_Scott::
	lock
	faceplayer
	goto_if_set FLAG_MET_SCOTT_AFTER_OBTAINING_STONE_BADGE, RustboroCity_PokemonSchool_EventScript_ScottWatchStudents
	goto_if_set FLAG_MET_SCOTT_RUSTBORO, RustboroCity_PokemonSchool_EventScript_ScottSpokeAlready
	goto_if_set FLAG_BADGE01_GET, RustboroCity_PokemonSchool_EventScript_ScottGreetHasBadge
	msgbox RustboroCity_PokemonSchool_Text_ScottMetAlreadyCut, MSGBOX_DEFAULT
	addvar VAR_SCOTT_STATE, 1
	setflag FLAG_MET_SCOTT_RUSTBORO
	release
	end

RustboroCity_PokemonSchool_EventScript_ScottSpokeAlready::
	goto_if_set FLAG_BADGE01_GET, RustboroCity_PokemonSchool_EventScript_ScottNoticeBadge
	msgbox RustboroCity_PokemonSchool_Text_StudentTalentLevelUnknown, MSGBOX_DEFAULT
	release
	end

RustboroCity_PokemonSchool_EventScript_ScottGreetHasBadge::
	msgbox RustboroCity_PokemonSchool_Text_ScottMetAlreadyStoneBadge, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_MetScottAfterBadge
	end

RustboroCity_PokemonSchool_EventScript_ScottNoticeBadge::
	msgbox RustboroCity_PokemonSchool_Text_ScottStoneBadge, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_MetScottAfterBadge
	end

RustboroCity_PokemonSchool_EventScript_MetScottAfterBadge::
	addvar VAR_SCOTT_STATE, 1
	setflag FLAG_MET_SCOTT_AFTER_OBTAINING_STONE_BADGE
	release
	end

RustboroCity_PokemonSchool_EventScript_ScottWatchStudents::
	msgbox RustboroCity_PokemonSchool_Text_StudentTalentLevelUnknown, MSGBOX_DEFAULT
	release
	end

RustboroCity_PokemonSchool_Text_BlackboardListsStatusChanges:
	.string "Le tableau noir liste les altérations\n"
	.string "de statut qui peuvent affecter les POKéMON en combat.$"

RustboroCity_PokemonSchool_Text_ReadWhichTopic:
	.string "Quel sujet veux-tu lire ?$"

RustboroCity_PokemonSchool_Text_ExplainPoison:
	.string "Si un POKéMON est empoisonné, il perdra\n"
	.string "progressivement des PV.\p"
	.string "L'effet du poison persiste après le\n"
	.string "combat.\p"
	.string "Les PV d'un POKéMON empoisonné\n"
	.string "baissent même en marchant.\p"
	.string "Soigne-le avec un ANTIDOTE.$"

RustboroCity_PokemonSchool_Text_ExplainParalysis:
	.string "Si un POKéMON est paralysé,\n"
	.string "sa VITESSE diminue.\p"
	.string "Il se peut aussi qu'il ne puisse pas\n"
	.string "attaquer pendant le combat.\p"
	.string "La paralysie persiste après le combat.\n"
	.string "Soigne-la avec un ANTI-PARA.$"

RustboroCity_PokemonSchool_Text_ExplainSleep:
	.string "Si un POKéMON s'endort, il ne pourra\n"
	.string "plus attaquer.\p"
	.string "Un POKéMON peut se réveiller tout seul,\n"
	.string "mais s'il dort à la fin d'un combat,\l"
	.string "il restera endormi.\p"
	.string "Réveille-le avec un RÉVEIL.$"

RustboroCity_PokemonSchool_Text_ExplainBurn:
	.string "Une brûlure réduit l'ATTAQUE et fait\n"
	.string "perdre des PV petit à petit.\p"
	.string "La brûlure persiste après le combat.\n"
	.string "Soigne-la avec un ANTI-BRULE.$"

RustboroCity_PokemonSchool_Text_ExplainFreeze:
	.string "Si un POKéMON est gelé, il devient\n"
	.string "totalement impuissant.\p"
	.string "Il restera gelé après le combat.\n"
	.string "Soigne-le avec un ANTIGEL.$"

RustboroCity_PokemonSchool_Text_StudentsWhoDontStudyGetQuickClaw:
	.string "Les élèves qui ne travaillent pas ont\n"
	.string "droit à un petit goût de ma VIVE GRIFFE.\p"
	.string "Que tu sois un bon élève ou non\n"
	.string "se verra à la façon dont tu utilises\l"
	.string "cet objet.$"

RustboroCity_PokemonSchool_Text_ExplainQuickClaw:
	.string "Un POKéMON tenant la VIVE GRIFFE peut\n"
	.string "parfois attaquer avant son adversaire.\p"
	.string "Il existe beaucoup d'autres objets\n"
	.string "à faire tenir à un POKéMON.\p"
	.string "Rien qu'avec eux, tu as de quoi\n"
	.string "étudier pendant longtemps !$"

RustboroCity_PokemonSchool_Text_TradingRightNow:
	.string "J'échange des POKéMON avec mon ami\n"
	.string "en ce moment.$"

RustboroCity_PokemonSchool_Text_AlwaysWantedSeedot:
	.string "J'ai toujours voulu un GRAINIPIOT, et\n"
	.string "je vais enfin en avoir un !$"

RustboroCity_PokemonSchool_Text_PokemontCantUseManMadeItems:
	.string "Les POKéMON peuvent tenir des objets,\n"
	.string "mais ils ne savent pas utiliser les objets\l"
	.string "fabriqués comme les POTIONS ou les ANTIDOTES.$"

RustboroCity_PokemonSchool_Text_ConfusedPokemonAttacksItself:
	.string "Tu sais que certaines capacités peuvent\n"
	.string "rendre confus un POKéMON ?\p"
	.string "Un POKéMON confus peut parfois\n"
	.string "s'attaquer lui-même sans le vouloir.\p"
	.string "Mais une fois le combat terminé, il\n"
	.string "redevient normal.$"

RustboroCity_PokemonSchool_Text_PokemonHealItselfWithBerry:
	.string "Un POKéMON tenant une BAIE peut se\n"
	.string "soigner tout seul…\p"
	.string "Il existe de nombreux objets que\n"
	.string "les POKéMON peuvent tenir…\p"
	.string "Ohlala, c'est dur de tout noter…$"

RustboroCity_PokemonSchool_Text_StudentsNotes:
	.string "C'est le cahier de cet élève…\p"
	.string "On attrape les POKéMON avec des\n"
	.string "POKé BALLS.\p"
	.string "Un DRESSEUR peut avoir jusqu'à six\n"
	.string "POKéMON avec lui.\p"
	.string "Un DRESSEUR est quelqu'un qui attrape\n"
	.string "des POKéMON, les élève et combat\l"
	.string "avec eux.\p"
	.string "La mission d'un DRESSEUR est de battre\n"
	.string "les DRESSEURS puissants qui attendent\l"
	.string "les challengers dans les ARÈNES.$"

RustboroCity_PokemonSchool_Text_ScottMetAlreadyCut:
	.string "Bonjour ? On ne s'est pas déjà rencontrés ?\n"
	.string "Je crois que c'était à CLÉMENTI-VILLE.\p"
	.string "Laisse-moi me présenter.\n"
	.string "Je m'appelle PIERRE.\p"
	.string "Je voyage partout à la recherche de\n"
	.string "DRESSEURS exceptionnels.\p"
	.string "Plus précisément, je cherche des experts\n"
	.string "en combat POKéMON.\p"
	.string "Alors, qu'est-ce qui t'amène à cette ÉCOLE ?\n"
	.string "Tu es DRESSEUR, toi aussi ?\p"
	.string "La première chose à faire, c'est d'apprendre\n"
	.string "la capacité COUPE à un POKéMON.\p"
	.string "Si je me souviens bien, quelqu'un en ville\n"
	.string "possède COUPE.$"

RustboroCity_PokemonSchool_Text_StudentTalentLevelUnknown:
	.string "PIERRE : Hmm…\p"
	.string "Le niveau des élèves ici est inconnu.\n"
	.string "Mais leur potentiel est là.$"

RustboroCity_PokemonSchool_Text_ScottStoneBadge:
	.string "PIERRE : Oh, qu'est-ce que c'est ?\p"
	.string "C'est un BADGE PIERRE, non ?\n"
	.string "C'est impressionnant, je trouve.\p"
	.string "Mais tu sais, j'aurais aimé te voir\n"
	.string "combattre.\p"
	.string "C'est difficile de juger un DRESSEUR\n"
	.string "juste avec un BADGE.$"

RustboroCity_PokemonSchool_Text_ScottMetAlreadyStoneBadge:
	.string "Bonjour ? On ne s'est pas déjà rencontrés ?\n"
	.string "Je crois que c'était à CLÉMENTI-VILLE.\p"
	.string "Laisse-moi me présenter.\n"
	.string "Je m'appelle PIERRE.\p"
	.string "Je voyage partout à la recherche de\n"
	.string "DRESSEURS exceptionnels.\p"
	.string "Plus précisément, je cherche des experts\n"
	.string "en combat POKéMON.\p"
	.string "Oh, qu'est-ce que c'est ?\n"
	.string "C'est un BADGE PIERRE, non ?\p"
	.string "C'est impressionnant, je trouve, pour\n"
	.string "un DRESSEUR débutant comme toi.\p"
	.string "Mais tu sais, j'aurais aimé te voir\n"
	.string "combattre.\p"
	.string "C'est difficile de juger un DRESSEUR\n"
	.string "juste avec un BADGE.$"
