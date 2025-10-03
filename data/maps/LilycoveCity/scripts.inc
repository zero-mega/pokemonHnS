.set LOCALID_WOMAN_1, 19
.set LOCALID_MAN_1, 20

LilycoveCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, LilycoveCity_OnLoad
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

LilycoveCity_OnTransition:
	callnative SetTimeBasedEncounters
	setflag FLAG_VISITED_SAFFRON_CITY
	setvar VAR_GARBAGEVAR, 0
	setflag FLAG_GARBAGEFLAG
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
	call Common_EventScript_SetupRivalGfxId
	end

LilycoveCity_OnLoad:
	call_if_unset FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_SetWailmerMetatiles
	end

LilycoveCity_EventScript_SetWailmerMetatiles::
	setmetatile 76, 12, METATILE_Lilycove_Wailmer0, TRUE
	setmetatile 77, 12, METATILE_Lilycove_Wailmer1, TRUE
	setmetatile 76, 13, METATILE_Lilycove_Wailmer2, TRUE
	setmetatile 77, 13, METATILE_Lilycove_Wailmer3, TRUE
	setmetatile 76, 14, METATILE_Lilycove_Wailmer0_Alt, TRUE
	setmetatile 77, 14, METATILE_Lilycove_Wailmer1_Alt, TRUE
	setmetatile 76, 15, METATILE_Lilycove_Wailmer2, TRUE
	setmetatile 77, 15, METATILE_Lilycove_Wailmer3, TRUE
	setmetatile 77, 16, METATILE_Lilycove_Wailmer0_Alt, TRUE
	setmetatile 78, 16, METATILE_Lilycove_Wailmer1_Alt, TRUE
	setmetatile 77, 17, METATILE_Lilycove_Wailmer2, TRUE
	setmetatile 78, 17, METATILE_Lilycove_Wailmer3, TRUE
	return

LilycoveCity_EventScript_BerryGentleman::
	lock
	faceplayer
	dotimebasedevents
	goto_if_set FLAG_DAILY_LILYCOVE_RECEIVED_BERRY, LilycoveCity_EventScript_ReceivedBerry
	msgbox LilycoveCity_Text_BerrySuitsYou, MSGBOX_DEFAULT
	random 10
	addvar VAR_RESULT, FIRST_BERRY_INDEX
	giveitem VAR_RESULT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_LILYCOVE_RECEIVED_BERRY
	msgbox LilycoveCity_Text_BecauseYoureTrainer, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_ReceivedBerry::
	msgbox LilycoveCity_Text_PokeblocksSuitPokemon, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Man3::
	msgbox LilycoveCity_Text_ContestHallInTown, MSGBOX_NPC
	end

LilycoveCity_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_EventScript_GirlAquaGone
	msgbox LilycoveCity_Text_StrangeCaveInCove, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_GirlAquaGone::
	msgbox LilycoveCity_Text_GoingToMoveDeleterForHMs, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_RichBoy::
	msgbox LilycoveCity_Text_ImFromKanto, MSGBOX_NPC
	end

LilycoveCity_EventScript_Sailor2::
	lock
	faceplayer
	goto_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_Sailor2AquaGone
	msgbox LilycoveCity_Text_TeamAquaBeenTrainingWailmer, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Sailor2AquaGone::
	msgbox LilycoveCity_Text_SomeonePuntedTeamAquaOut, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Woman2::
	lock
	faceplayer
	goto_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_Woman2AquaGone
	msgbox LilycoveCity_Text_SomeoneStoleMyPokemon, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Woman2AquaGone::
	msgbox LilycoveCity_Text_MissingPokemonCameBack, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Man2::
	msgbox LilycoveCity_Text_ImArtDealer, MSGBOX_NPC
	end

LilycoveCity_EventScript_ExpertM1::
	msgbox LilycoveCity_Text_SeaRemainsForeverYoung, MSGBOX_SIGN
	end

LilycoveCity_EventScript_ExpertF::
	msgbox LilycoveCity_Text_SixtyYearsAgoHusbandProposed, MSGBOX_SIGN
	end

LilycoveCity_EventScript_ExpertM2::
	lock
	faceplayer
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_EventScript_ExpertM2AquaGone
	msgbox LilycoveCity_Text_TeamAquaRenovatedCavern, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_ExpertM2AquaGone::
	msgbox LilycoveCity_Text_TeamAquaLotGoneForGood, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Sailor1::
	msgbox LilycoveCity_Text_HeardTowerCalledSkyPillar, MSGBOX_NPC
	end

LilycoveCity_EventScript_FatMan::
	msgbox LilycoveCity_Text_SawTallTowerOnRoute131, MSGBOX_NPC
	end

LilycoveCity_EventScript_Man1::
	lockall
	msgbox LilycoveCity_Text_JustArrivedAndSawRarePokemon, MSGBOX_NPC
	applymovement LOCALID_MAN_1, Common_Movement_FaceOriginalDirection
	end

LilycoveCity_EventScript_Woman1::
	lockall
	msgbox LilycoveCity_Text_HoneymoonVowToSeeRarePokemon, MSGBOX_NPC
	applymovement LOCALID_WOMAN_1, Common_Movement_FaceOriginalDirection
	end

LilycoveCity_EventScript_CitySign::
	msgbox LilycoveCity_Text_CitySign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_GymSign::
	msgbox LilycoveCity_Text_GymSign, MSGBOX_SIGN
	end

LilycoveCity_Text_GymSign:
	.string "HYPER TRAINING GYM.\p"
	.string "Maximize the potential of your\n"
	.string "POKéMON easily!$"

LilycoveCity_EventScript_ContestHallSign::
	msgbox LilycoveCity_Text_ContestHallSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_MotelSign::
	msgbox LilycoveCity_Text_MotelSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_MuseumSign::
	lockall
	specialvar VAR_0x8004, CountPlayerMuseumPaintings
	switch VAR_0x8004
	case 0, LilycoveCity_EventScript_MuseumSignNoPaintings
	msgbox LilycoveCity_Text_MuseumSignPlayersExhibit, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_MuseumSignNoPaintings::
	msgbox LilycoveCity_Text_MuseumSign, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_HarborSign::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_HarborSignFerryReady
	msgbox LilycoveCity_Text_HarborSignUnderConstruction, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_HarborSignFerryReady::
	msgbox LilycoveCity_Text_HarborSign, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_TrainerFanClubSign::
	msgbox LilycoveCity_Text_TrainerFanClubSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_DepartmentStoreSign::
	msgbox LilycoveCity_Text_DepartmentStoreSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_MoveDeletersHouseSign::
	msgbox LilycoveCity_Text_MoveDeletersHouseSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_WailmerTrainerGrunt::
	lockall
	goto_if_set FLAG_MET_WAILMER_TRAINER, LilycoveCity_EventScript_MetWailmerTrainer
	msgbox LilycoveCity_Text_WailmerLeapOutOfWater, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_Text_GetLostMessingUpTraining, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setflag FLAG_MET_WAILMER_TRAINER
	releaseall
	end

LilycoveCity_EventScript_MetWailmerTrainer::
	msgbox LilycoveCity_Text_WailmerLeapOutOfWater, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_AquaGrunt1::
	msgbox LilycoveCity_Text_MovedLootIntoHideoutToday, MSGBOX_NPC
	end

LilycoveCity_EventScript_AquaGrunt2::
	msgbox LilycoveCity_Text_ChanceToDoBigThings, MSGBOX_NPC
	end

LilycoveCity_EventScript_AquaGrunt3::
	msgbox LilycoveCity_Text_DontGoNearCaveInCove, MSGBOX_NPC
	end

LilycoveCity_EventScript_AquaGrunt4::
	msgbox LilycoveCity_Text_IfWorldBecomesOurs, MSGBOX_NPC
	end

LilycoveCity_EventScript_Rival::
	lock
	faceplayer
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, LilycoveCity_EventScript_May
	goto_if_eq VAR_RESULT, FEMALE, LilycoveCity_EventScript_Brendan
	end

LilycoveCity_EventScript_May::
	playbgm MUS_ENCOUNTER_MAY, TRUE
	call_if_set FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_MayAskToBattleAgain
	call_if_unset FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_MayAskToBattle
	goto_if_eq VAR_RESULT, NO, LilycoveCity_EventScript_DeclineMayBattle
	msgbox LilycoveCity_Text_MayWontBeBeaten, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, LilycoveCity_EventScript_BattleMayTreecko
	case 1, LilycoveCity_EventScript_BattleMayTorchic
	case 2, LilycoveCity_EventScript_BattleMayMudkip
	end

LilycoveCity_EventScript_MayAskToBattleAgain::
	msgbox LilycoveCity_Text_MayBattleMe, MSGBOX_YESNO
	return

LilycoveCity_EventScript_MayAskToBattle::
	msgbox LilycoveCity_Text_MayShoppingLetsBattle, MSGBOX_YESNO
	return

LilycoveCity_EventScript_DeclineMayBattle::
	setflag FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE
	msgbox LilycoveCity_Text_MayNotRaisingPokemon, MSGBOX_DEFAULT
	savebgm MUS_DUMMY
	fadedefaultbgm
	release
	end

LilycoveCity_EventScript_Brendan::
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	call_if_set FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_BrendanAskToBattleAgain
	call_if_unset FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_BrendanAskToBattle
	goto_if_eq VAR_RESULT, NO, LilycoveCity_EventScript_DeclineBrendanBattle
	msgbox LilycoveCity_Text_BrendanWontBeBeaten, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, LilycoveCity_EventScript_BattleBrendanTreecko
	case 1, LilycoveCity_EventScript_BattleBrendanTorchic
	case 2, LilycoveCity_EventScript_BattleBrendanMudkip
	end

LilycoveCity_EventScript_BrendanAskToBattleAgain::
	msgbox LilycoveCity_Text_BrendanBattleMe, MSGBOX_YESNO
	return

LilycoveCity_EventScript_BrendanAskToBattle::
	msgbox LilycoveCity_Text_BrendanShoppingLetsBattle, MSGBOX_YESNO
	return

LilycoveCity_EventScript_DeclineBrendanBattle::
	setflag FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE
	msgbox LilycoveCity_Text_BrendanNoConfidence, MSGBOX_DEFAULT
	savebgm MUS_DUMMY
	fadedefaultbgm
	release
	end

LilycoveCity_EventScript_BattleMayTreecko::
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_TREECKO, LilycoveCity_Text_MayDefeat
	goto LilycoveCity_EventScript_DefeatedMay
	end

LilycoveCity_EventScript_BattleMayTorchic::
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_TORCHIC, LilycoveCity_Text_MayDefeat
	goto LilycoveCity_EventScript_DefeatedMay
	end

LilycoveCity_EventScript_BattleMayMudkip::
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_MUDKIP, LilycoveCity_Text_MayDefeat
	goto LilycoveCity_EventScript_DefeatedMay
	end

LilycoveCity_EventScript_BattleBrendanTreecko::
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_TREECKO, LilycoveCity_Text_BrendanDefeat
	goto LilycoveCity_EventScript_DefeatedBrendan
	end

LilycoveCity_EventScript_BattleBrendanTorchic::
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_TORCHIC, LilycoveCity_Text_BrendanDefeat
	goto LilycoveCity_EventScript_DefeatedBrendan
	end

LilycoveCity_EventScript_BattleBrendanMudkip::
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_MUDKIP, LilycoveCity_Text_BrendanDefeat
	goto LilycoveCity_EventScript_DefeatedBrendan
	end

LilycoveCity_EventScript_DefeatedMay::
	msgbox LilycoveCity_Text_MayGoingBackToLittleroot, MSGBOX_DEFAULT
	setvar VAR_RESULT, FALSE
	call_if_set FLAG_BADGE06_GET, LilycoveCity_EventScript_CheckFinalBadge
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_EventScript_MayCollectBadges
	call_if_eq VAR_RESULT, TRUE, LilycoveCity_EventScript_MayPokemonLeague
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_BEDROOM
	clearflag FLAG_GARBAGEFLAG
	goto LilycoveCity_EventScript_RivalFlyAway
	end

LilycoveCity_EventScript_CheckFinalBadge::
	goto_if_set FLAG_BADGE08_GET, LilycoveCity_EventScript_HasFinalBadge
	return

LilycoveCity_EventScript_HasFinalBadge::
	setvar VAR_RESULT, TRUE
	return

LilycoveCity_EventScript_MayCollectBadges::
	msgbox LilycoveCity_Text_MayYouGoingToCollectBadges, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_MayPokemonLeague::
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_MayBattleFrontier
	msgbox LilycoveCity_Text_MayYouGoingToPokemonLeague, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_MayBattleFrontier::
	msgbox LilycoveCity_Text_MayYouGoingToBattleFrontier, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_DefeatedBrendan::
	msgbox LilycoveCity_Text_BrendanGoingBackToLittleroot, MSGBOX_DEFAULT
	setvar VAR_RESULT, FALSE
	call_if_set FLAG_BADGE06_GET, LilycoveCity_EventScript_CheckFinalBadge
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_EventScript_BrendanCollectBadges
	call_if_eq VAR_RESULT, TRUE, LilycoveCity_EventScript_BrendanPokemonLeague
	clearflag FLAG_GARBAGEFLAG
	clearflag FLAG_GARBAGEFLAG
	goto LilycoveCity_EventScript_RivalFlyAway
	end

LilycoveCity_EventScript_BrendanCollectBadges::
	msgbox LilycoveCity_Text_BrendanYouGoingToCollectBadges, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_BrendanPokemonLeague::
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_BrendanBattleFrontier
	msgbox LilycoveCity_Text_BrendanYouGoingToPokemonLeague, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_BrendanBattleFrontier::
	msgbox LilycoveCity_Text_BrendanYouGoingToBattleFrontier, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_RivalFlyAway::
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 50
	setfieldeffectargument 0, 1
	dofieldeffect FLDEFF_NPCFLY_OUT
	delay 15
	removeobject VAR_LAST_TALKED
	waitfieldeffect FLDEFF_NPCFLY_OUT
	savebgm MUS_DUMMY
	fadedefaultbgm
	setflag FLAG_MET_RIVAL_LILYCOVE
	release
	end

LilycoveCity_EventScript_SchoolKidM::
	lock
	faceplayer
	msgbox LilycoveCity_Text_DoYouKnowAboutBerryBlender, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, LilycoveCity_EventScript_KnowAboutBerryBlender
	call_if_eq VAR_RESULT, NO, LilycoveCity_EventScript_DontKnowAboutBerryBlender
	release
	end

LilycoveCity_EventScript_KnowAboutBerryBlender::
	msgbox LilycoveCity_Text_FasterSpinBetterPokeblocks, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_DontKnowAboutBerryBlender::
	msgbox LilycoveCity_Text_ExplainBerryBlender, MSGBOX_DEFAULT
	return

LilycoveCity_Text_MayShoppingLetsBattle:
	.string "FLORA : Oh, salut ?\n"
	.string "{PLAYER}{KUN}, tu fais du shopping toi aussi ?\p"
	.string "J'ai acheté plein de PELUCHES et\n"
	.string "d'AFFICHES.\p"
	.string "Bien sûr, j'ai aussi attrapé beaucoup de\n"
	.string "POKéMON, et je les élève\l"
	.string "correctement aussi.\p"
	.string "En fait, je me demande si tu élèves bien\n"
	.string "tes POKéMON, {PLAYER}{KUN}.\p"
	.string "Je vais me battre avec toi, comme ça tu\n"
	.string "pourras me montrer tes POKéMON, {PLAYER}{KUN}.$"

LilycoveCity_Text_MayNotRaisingPokemon:
	.string "FLORA : Oh, pourquoi ? {PLAYER}{KUN}, tu n'as\n"
	.string "pas élevé tes POKéMON ?\p"
	.string "Ce n'est pas très digne d'un\n"
	.string "DRESSEUR…$"

LilycoveCity_Text_MayBattleMe:
	.string "FLORA : Allez, combats-moi, que je puisse\n"
	.string "voir tes POKéMON !$"

LilycoveCity_Text_MayWontBeBeaten:
	.string "FLORA : Les POKéMON que j'ai élevés ne se\n"
	.string "laisseront pas battre par les tiens, {PLAYER}{KUN} !$"

LilycoveCity_Text_MayDefeat:
	.string "… … … … … … … …\p"
	.string "Je me souviens du combat qu'on a eu,\n"
	.string "{PLAYER}{KUN}, sur la ROUTE 103.\p"
	.string "Ce combat t'a aidé à devenir aussi\n"
	.string "fort, {PLAYER}{KUN}, n'est-ce pas ?$"

LilycoveCity_Text_MayGoingBackToLittleroot:
	.string "FLORA : Je pense retourner à\n"
	.string "BOURG-EN-VOL bientôt.\p"
	.string "J'ai attrapé un bon groupe de POKéMON,\n"
	.string "et mon POKéDEX avance bien, alors\l"
	.string "je rentre à la maison pour le montrer à mon père.$"

LilycoveCity_Text_MayYouGoingToCollectBadges:
	.string "{PLAYER}{KUN}, qu'est-ce que tu vas faire ?\p"
	.string "Rassembler tous les BADGES et tenter\n"
	.string "la LIGUE POKéMON ?\p"
	.string "Bon, pendant que tu collectionnes les BADGES,\n"
	.string "{PLAYER}{KUN}, je vais travailler sur mon\l"
	.string "POKéDEX. Je le compléterai avant toi !\p"
	.string "À bientôt !$"

LilycoveCity_Text_MayYouGoingToPokemonLeague:
	.string "{PLAYER}{KUN}, qu'est-ce que tu vas faire ?\p"
	.string "Tu vas tenter la LIGUE POKéMON ?\p"
	.string "Ou tu vas compléter ton\n"
	.string "POKéDEX ?\p"
	.string "J'ai peut-être perdu contre toi en combat,\n"
	.string "mais je finirai mon POKéDEX avant toi !\p"
	.string "À bientôt !$"

LilycoveCity_Text_MayYouGoingToBattleFrontier:
	.string "{PLAYER}{KUN}, qu'est-ce que tu vas faire ?\p"
	.string "Tu vas tenter le FRONTIÈRE DES COMBATS ?\p"
	.string "Ou tu vas compléter ton\n"
	.string "POKéDEX ?\p"
	.string "J'ai peut-être perdu contre toi en combat,\n"
	.string "mais je finirai mon POKéDEX avant toi !\p"
	.string "À bientôt !$"

LilycoveCity_Text_BrendanShoppingLetsBattle:
	.string "BRICE : Oh, salut, c'est {PLAYER}.\p"
	.string "Je fais une course pour mon père.\n"
	.string "Non, je n'achète pas de PELUCHES.\p"
	.string "Enfin bref, ça fait un moment.\p"
	.string "Tu veux te battre pour voir qui a\n"
	.string "mieux élevé ses POKéMON ?$"

LilycoveCity_Text_BrendanNoConfidence:
	.string "BRICE : Oh, qu'est-ce qu'il y a ?\n"
	.string "Tu manques de confiance ?$"

LilycoveCity_Text_BrendanBattleMe:
	.string "BRICE : Tu veux te battre pour voir qui\n"
	.string "a mieux élevé ses POKéMON ?$"

LilycoveCity_Text_BrendanWontBeBeaten:
	.string "BRICE : Oh, mais tu sais bien que je ne\n"
	.string "perdrai pas contre toi, {PLAYER} !$"

LilycoveCity_Text_BrendanDefeat:
	.string "Hum…\n"
	.string "Tu as bien entraîné tes POKéMON.\p"
	.string "Ça fait un peu mal—j'avais de l'avance\n"
	.string "sur toi en tant que DRESSEUR…$"

LilycoveCity_Text_BrendanGoingBackToLittleroot:
	.string "BRICE : Je…\n"
	.string "Je compte rentrer à BOURG-EN-VOL.\p"
	.string "Tu sais que j'aide mon père pour son\n"
	.string "POKéDEX. Il avance plutôt bien, alors\l"
	.string "je devrais aller lui montrer.$"

LilycoveCity_Text_BrendanYouGoingToCollectBadges:
	.string "{PLAYER}, qu'est-ce que tu vas faire ?\p"
	.string "Rassembler tous les BADGES et tenter\n"
	.string "la LIGUE POKéMON ?\p"
	.string "Peut-être que je ferai ça aussi…\p"
	.string "Bon, en tout cas, tiens bon !$"

LilycoveCity_Text_BrendanYouGoingToPokemonLeague:
	.string "{PLAYER}, qu'est-ce que tu vas faire ?\p"
	.string "Puisque tu es si fort, tu vas tenter\n"
	.string "la LIGUE POKéMON ?\p"
	.string "Hé, même moi—si j'entraînais mes POKéMON\n"
	.string "un peu plus, je devrais être plus fort que\l"
	.string "toi, {PLAYER}.\p"
	.string "Bon, en tout cas, tiens bon !$"

LilycoveCity_Text_BrendanYouGoingToBattleFrontier:
	.string "{PLAYER}, qu'est-ce que tu vas faire ?\p"
	.string "Tu vas tenter le FRONTIÈRE DES COMBATS ?\p"
	.string "Ou tu vas compléter ton\n"
	.string "POKéDEX ?\p"
	.string "Puisque tu es si fort, tu devrais\n"
	.string "essayer le FRONTIÈRE DES COMBATS.\p"
	.string "Hé, si j'entraîne mes POKéMON un peu plus,\n"
	.string "je deviendrai plus fort que toi, {PLAYER}.\p"
	.string "Peut-être que je devrais aller au\n"
	.string "FRONTIÈRE DES COMBATS.\p"
	.string "Bon, en tout cas, tiens bon !$"

LilycoveCity_Text_MovedLootIntoHideoutToday:
	.string "Fufufu…\p"
	.string "On a déplacé encore plus de butin dans\n"
	.string "notre Q.G. secret aujourd'hui…\p"
	.string "Q-qui es-tu ?!\n"
	.string "Je parlais juste tout seul !$"

LilycoveCity_Text_ChanceToDoBigThings:
	.string "Je ne suis qu'un SBIRE, alors je ne sais\n"
	.string "pas ce que pense le BOSS…\p"
	.string "Mais en étant dans la TEAM AQUA, je sais\n"
	.string "que j'aurai la chance de faire de grandes choses !\p"
	.string "Q-qui es-tu ?!\n"
	.string "Je parlais juste tout seul !$"

LilycoveCity_Text_DontGoNearCaveInCove:
	.string "Hé, toi !\p"
	.string "Ne t'approche pas de la grotte dans la crique !\p"
	.string "Pourquoi ? Tu n'as pas besoin de savoir !\n"
	.string "Je suis un adulte, alors tu m'écoutes !$"

LilycoveCity_Text_IfWorldBecomesOurs:
	.string "Si ce vaste monde devient le nôtre,\n"
	.string "celui de la TEAM AQUA, ce sera aussi un\l"
	.string "endroit plus heureux pour les POKéMON.$"

LilycoveCity_Text_WailmerLeapOutOfWater:
	.string "Là ! WAILMER !\n"
	.string "Sors de l'eau maintenant !$"

LilycoveCity_Text_GetLostMessingUpTraining:
	.string "Hein ? Qu'est-ce que tu veux ?\p"
	.string "Tu déranges notre entraînement,\n"
	.string "alors tu pourrais partir, s'il te plaît ?$"

LilycoveCity_Text_ContestHallInTown:
	.string "Il y a une SALLE DE CONCOURS POKéMON\n"
	.string "juste ici, dans cette ville. \p"
	.string "Ça veut dire que des POKéMON bien élevés\n"
	.string "viennent de tout le pays.\p"
	.string "Mon cœur déborde d'excitation !$"

LilycoveCity_Text_StrangeCaveInCove:
	.string "As-tu vu cette étrange grotte dans\n"
	.string "la crique au bout de la ville ?$"

LilycoveCity_Text_GoingToMoveDeleterForHMs:
	.string "Je vais apprendre de nouvelles capacités\n"
	.string "à mes POKéMON pour le CONCOURS.\p"
	.string "Alors, je vais voir le SUPPRIMEUR DE CAPACITÉS\n"
	.string "pour qu'il fasse oublier les CS.$"

LilycoveCity_Text_ImFromKanto:
	.string "Je viens de KANTO.\p"
	.string "La région de HOENN est magnifique avec\n"
	.string "toute son eau et sa nature verdoyante.\p"
	.string "Hein ? Attends une seconde…\p"
	.string "Est-ce qu'il y aurait des POKéMON rares\n"
	.string "qui vivent seulement ici ?$"

LilycoveCity_Text_TeamAquaBeenTrainingWailmer:
	.string "La TEAM AQUA entraîne ses\n"
	.string "WAILMER dans la crique.\p"
	.string "Nous, les MARINS, on ne peut pas sortir\n"
	.string "nos bateaux avec eux dans le passage !$"

LilycoveCity_Text_SomeonePuntedTeamAquaOut:
	.string "Ohé, tu sais quoi ?\p"
	.string "Quelqu'un a chassé la TEAM AQUA\n"
	.string "pour nous !\p"
	.string "Ça a fait partir les WAILMER de la crique,\n"
	.string "alors on peut ressortir nos bateaux !$"

LilycoveCity_Text_SomeoneStoleMyPokemon:
	.string "Je faisais une sieste relaxante à l'auberge\n"
	.string "au bord de la mer, bercé par les vagues…\p"
	.string "Quand quelqu'un a volé mon POKéMON !\p"
	.string "Qui est le ravisseur ?\n"
	.string "TEAM AQUA ? C'est la TEAM AQUA ?$"

LilycoveCity_Text_MissingPokemonCameBack:
	.string "Mon POKéMON disparu…\n"
	.string "Il est revenu sans que je m'en rende compte !$"

LilycoveCity_Text_ImArtDealer:
	.string "Je suis un MARCHAND D'ART.\p"
	.string "J'achète et je vends de l'art, surtout\n"
	.string "des tableaux.\p"
	.string "J'ai entendu dire que le MUSÉE ici expose\n"
	.string "des œuvres magnifiques…$"

LilycoveCity_Text_SeaRemainsForeverYoung:
	.string "Même en vieillissant et en se ridant,\n"
	.string "la mer reste éternellement jeune avec\l"
	.string "l'éclat vif de la vie…\p"
	.string "Fwohoho fwohohohoho…$"

LilycoveCity_Text_SixtyYearsAgoHusbandProposed:
	.string "C'était il y a soixante ans que mon mari\n"
	.string "m'a demandée en mariage ici.\l"
	.string "La mer est toujours aussi belle.\p"
	.string "Mufufufu mufufufufufu…$"

LilycoveCity_Text_TeamAquaRenovatedCavern:
	.string "Hm, tu connais la caverne étrange\n"
	.string "dans cette crique ?\p"
	.string "C'était une formation naturelle,\n"
	.string "mais cette TEAM AQUA est venue\l"
	.string "et a fait des travaux.\p"
	.string "Ils s'appellent eux-mêmes\n"
	.string "la « TEAM AQUA amie de la nature » !\p"
	.string "Mais ce qu'ils font et ce qu'ils disent\n"
	.string "ne correspondent pas du tout !$"

LilycoveCity_Text_TeamAquaLotGoneForGood:
	.string "Cette grotte dans la crique…\p"
	.string "Je ne l'ai pas remarqué tout de suite,\n"
	.string "mais elle est complètement vide maintenant.\p"
	.string "Cette TEAM AQUA, ils ont dû\n"
	.string "partir pour de bon.$"

LilycoveCity_Text_CitySign:
	.string "NÉNUCRIQUE VILLE\p"
	.string "« Là où la terre s'arrête et la\n"
	.string "mer commence. »$"

LilycoveCity_Text_ContestHallSign:
	.string "SALLE DE CONCOURS POKéMON\n"
	.string "« Le lieu de rassemblement des DRESSEURS ! »$"

LilycoveCity_Text_MotelSign:
	.string "HÔTEL NÉNUCRIQUE\p"
	.string "« Souvenez-vous de nous comme NÉNUCRIQUE de\n"
	.string "NÉNUCRYPTE VILLE. »$"

LilycoveCity_Text_MuseumSign:
	.string "MUSÉE DE NÉNUCRYPTE\p"
	.string "« Collection de chefs-d'œuvre POKéMON\n"
	.string "en exposition ! »$"

LilycoveCity_Text_MuseumSignPlayersExhibit:
	.string "MUSÉE DE NÉNUCRIQUE\p"
	.string "« Collection de POKéMON de {PLAYER}\n"
	.string "en exposition ! »$"

LilycoveCity_Text_HarborSignUnderConstruction:
	.string "PORT DE NÉNUCRIQUE\p"
	.string "« Le ferry S.S. TIDAL est en\n"
	.string "construction à POIVRESSEL.\p"
	.string "« Le service devrait commencer\n"
	.string "bientôt. »$"

LilycoveCity_Text_HarborSign:
	.string "PORT DE NÉNUCRIQUE\p"
	.string "« Profitez d'une croisière agréable sur\n"
	.string "le ferry S.S. TIDAL. »$"

LilycoveCity_Text_TrainerFanClubSign:
	.string "CLUB DES FANS DE DRESSEURS POKéMON\p"
	.string "Les noms des DRESSEURS sont griffonnés\n"
	.string "partout sur le panneau…$"

LilycoveCity_Text_DepartmentStoreSign:
	.string "GRAND MAGASIN DE NÉNUCRIQUE\p"
	.string "« Débordant de superbes articles\n"
	.string "et d'excitation !\p"
	.string "« L'endroit idéal pour trouver ce qu'il\n"
	.string "vous faut ! »$"

LilycoveCity_Text_MoveDeletersHouseSign:
	.string "MAISON DU SUPPRIMEUR DE CAPACITÉS\p"
	.string "« Capacités indésirables de POKéMON effacées. »$"

LilycoveCity_Text_DoYouKnowAboutBerryBlender:
	.string "Tu connais la machine\n"
	.string "MÉLANGEUR DE BAIES ?$"

LilycoveCity_Text_FasterSpinBetterPokeblocks:
	.string "Il faut travailler ensemble pour la faire\n"
	.string "tourner plus vite.\p"
	.string "Plus tu la fais tourner vite, meilleurs\n"
	.string "{POKEBLOCK}S tu obtiens, paraît-il.$"

LilycoveCity_Text_ExplainBerryBlender:
	.string "Elle sert à fabriquer une sorte de bonbon\n"
	.string "appelé {POKEBLOCK}.\p"
	.string "Si tu donnes un bon {POKEBLOCK} à un POKéMON,\n"
	.string "sa condition s'améliorera beaucoup.$"

LilycoveCity_Text_HeardTowerCalledSkyPillar:
	.string "J'ai entendu dire qu'il y a une tour\n"
	.string "quelque part sur les routes maritimes.\p"
	.string "On l'appelle la PILIER CÉLESTE, il paraît.$"

LilycoveCity_Text_SawTallTowerOnRoute131:
	.string "J'ai vu une grande tour quelque part\n"
	.string "près de la ROUTE 131.\p"
	.string "Est-ce que ça pourrait être…?$"

LilycoveCity_Text_JustArrivedAndSawRarePokemon:
	.string "On vient d'arriver ici pour notre\n"
	.string "voyage de noces.\p"
	.string "On a aperçu un POKéMON de type DRAGON\n"
	.string "volant très haut dans le ciel.\p"
	.string "Est-ce que des POKéMON aussi cool vivent\n"
	.string "dans la région de HOENN ?$"

LilycoveCity_Text_HoneymoonVowToSeeRarePokemon:
	.string "Pour notre lune de miel, on s'est promis de voir\n"
	.string "autant de POKéMON rares que possible.\p"
	.string "Alors on était ravis d'en voir un dès\n"
	.string "notre arrivée.\p"
	.string "On est vraiment super heureux !$"
