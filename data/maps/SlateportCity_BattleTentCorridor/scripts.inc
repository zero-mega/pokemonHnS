.set LOCALID_ATTENDANT, 1

SlateportCity_BattleTentCorridor_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SlateportCity_BattleTentCorridor_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, SlateportCity_BattleTentCorridor_OnWarp
	.byte 0

	@ This is Slateport Tent's version of the Battle Factory Pre-Battle Room

SlateportCity_BattleTentCorridor_OnWarp:
	map_script_2 VAR_TEMP_1, 0, SlateportCity_BattleTentCorridor_EventScript_SetUpObjects
	.2byte 0

SlateportCity_BattleTentCorridor_EventScript_SetUpObjects::
	setvar VAR_TEMP_1, 1
	goto_if_ne VAR_0x8006, 1, SlateportCity_BattleTentCorridor_EventScript_TurnPlayerNorth
	setobjectxy LOCALID_ATTENDANT, 2, 2
	turnobject LOCALID_ATTENDANT, DIR_SOUTH
SlateportCity_BattleTentCorridor_EventScript_TurnPlayerNorth::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

SlateportCity_BattleTentCorridor_OnFrame:
	map_script_2 VAR_TEMP_0, 0, SlateportCity_BattleTentCorridor_EventScript_EnterCorridor
	.2byte 0

SlateportCity_BattleTentCorridor_EventScript_EnterCorridor::
	goto_if_eq VAR_0x8006, 1, SlateportCity_BattleTentCorridor_EventScript_ReturnToRoomFromBattle
	setvar VAR_TEMP_0, 1
	applymovement LOCALID_ATTENDANT, SlateportCity_BattleTentCorridor_Movement_AttendantEnter
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_BattleTentCorridor_Movement_PlayerEnter
	waitmovement 0
	goto_if_eq VAR_0x8006, 2, SlateportCity_BattleTentCorridor_EventScript_ResumeChallenge
	slateporttent_generaterentalmons
	slateporttent_generateopponentmons
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_HoldMonsChooseFromSelection, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	slateporttent_rentmons
	waitstate
SlateportCity_BattleTentCorridor_EventScript_EnterBattleRoom::
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_RightThisWay, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ATTENDANT, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	opendoor 2, 1
	waitdooranim
	applymovement LOCALID_ATTENDANT, SlateportCity_BattleTentCorridor_Movement_AttendantExit
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_BattleTentCorridor_Movement_PlayerExit
	waitmovement 0
	closedoor 2, 1
	waitdooranim
	warp MAP_SLATEPORT_CITY_BATTLE_TENT_BATTLE_ROOM, 4, 4
	waitstate
	end

SlateportCity_BattleTentCorridor_EventScript_ReturnToRoomFromBattle::
	factory_setopponentmons
	factory_resethelditems
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_LetUsRestoreMons, MSGBOX_DEFAULT
	playfanfare MUS_HEAL
	waitfanfare
	special HealPlayerParty
SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent::
	frontier_get FRONTIER_DATA_BATTLE_NUM
	call_if_eq VAR_RESULT, 1, SlateportCity_BattleTentCorridor_EventScript_ReadyFor2ndOpponent
	call_if_eq VAR_RESULT, 2, SlateportCity_BattleTentCorridor_EventScript_ReadyFor3rdOpponent
	multichoice 20, 6, MULTI_GO_ON_REST_RETIRE, TRUE
	switch VAR_RESULT
	case 0, SlateportCity_BattleTentCorridor_EventScript_AskSwapMon
	case 1, SlateportCity_BattleTentCorridor_EventScript_AskPauseChallenge
	case 2, SlateportCity_BattleTentCorridor_EventScript_AskRetireChallenge

SlateportCity_BattleTentCorridor_EventScript_AskPauseChallenge::
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_SaveAndQuitGame, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent
	case YES, SlateportCity_BattleTentCorridor_EventScript_PauseChallenge
	case MULTI_B_PRESSED, SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent

SlateportCity_BattleTentCorridor_EventScript_AskRetireChallenge::
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_RetireFromChallenge
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent
	case 0, SlateportCity_BattleTent_EventScript_WarpToLobbyLost
	case MULTI_B_PRESSED, SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent

SlateportCity_BattleTentCorridor_EventScript_AskSwapMon::
	slateporttent_generateopponentmons
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_LikeToSwapMon, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, SlateportCity_BattleTentCorridor_EventScript_EnterBattleRoom
	case YES, SlateportCity_BattleTentCorridor_EventScript_SwapMons
	case MULTI_B_PRESSED, SlateportCity_BattleTentCorridor_EventScript_EnterBattleRoom

SlateportCity_BattleTentCorridor_EventScript_SwapMons::
	fadescreen FADE_TO_BLACK
	slateporttent_swapmons
	waitstate
	goto_if_eq VAR_RESULT, 1, SlateportCity_BattleTentCorridor_EventScript_EnterBattleRoom
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_YourSwapIsComplete, MSGBOX_DEFAULT
	goto SlateportCity_BattleTentCorridor_EventScript_EnterBattleRoom

SlateportCity_BattleTentCorridor_EventScript_ReadyFor2ndOpponent::
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor2ndOpponent
	waitmessage
	return

SlateportCity_BattleTentCorridor_EventScript_ReadyFor3rdOpponent::
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor3rdOpponent
	waitmessage
	return

SlateportCity_BattleTentCorridor_EventScript_PauseChallenge::
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_SavingDataPleaseWait
	waitmessage
	slateporttent_save CHALLENGE_STATUS_PAUSED
	playse SE_SAVE
	waitse
	fadescreen FADE_TO_BLACK
	frontier_reset
	end

SlateportCity_BattleTentCorridor_EventScript_ResumeChallenge::
	special SavePlayerParty
	factory_setparties 0
	goto SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent

SlateportCity_BattleTentCorridor_Movement_PlayerEnter:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

SlateportCity_BattleTentCorridor_Movement_PlayerExit:
	walk_up
	walk_up
	set_invisible
	step_end

SlateportCity_BattleTentCorridor_Movement_AttendantEnter:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_down
	step_end

SlateportCity_BattleTentCorridor_Movement_AttendantExit:
	walk_up
	set_invisible
	step_end

@ Leftover text from when this was a Contest Hall in R/S
@ Unused
SlateportCity_ContestHall_Text_AdviceForContests:
	.string "Tu veux un petit conseil savoureux\n"
	.string "pour les CONCOURS ?\p"
	.string "Utiliser une certaine capacité après\n"
	.string "un certain type de capacité attire\l"
	.string "parfois plus l'attention.\p"
	.string "Si tu sais ce que tu fais,\n"
	.string "tu peux marquer beaucoup de points d'allure.\p"
	.string "Bien sûr, tes adversaires pourraient essayer\n"
	.string "de perturber la prestation de ton POKéMON.$"

@ Unused
SlateportCity_ContestHall_Text_MyPapaIsContestJudge:
	.string "Mon papa, c'est un JUGE de CONCOURS.\p"
	.string "Je me demande ce que je devrais devenir\n"
	.string "plus tard, un JUGE ou un CHAMPION D'ARÈNE ?$"

@ Unused
SlateportCity_ContestHall_Text_ImLikeMajorlyCheesed:
	.string "Hé, mec, je suis grave dégoûté,\n"
	.string "tu vois. Genre, tu vois, je voulais juste\l"
	.string "savoir pourquoi mon POKéMON\l"
	.string "n'a jamais gagné, tu vois, genre, hein ?\p"
	.string "Alors, genre, j'ai donné mon avis au JUGE,\n"
	.string "tu vois, c'est gratuit.\p"
	.string "Et il n'a même pas voulu m'écouter, genre, hein !\n"
	.string "Alors, c'est trop nul, mec !\p"
	.string "Hé, toi ! Chut, tu piges ?\n"
	.string "Tiens, prends ça !$"

@ Unused
SlateportCity_ContestHall_Text_ExplainTorment:
	.string "Ça, c'est la CT41, tu vois ?\n"
	.string "Hé, c'est TOURMENTE, tu m'entends ?\p"
	.string "Ça empêche l'autre d'utiliser\n"
	.string "deux fois de suite la même capacité, tu vois ?\p"
	.string "Hé, écoute-moi bien, hein,\n"
	.string "je ne te lance pas un tourmente, t'inquiète !$"

@ Unused
SlateportCity_ContestHall_Text_MCStepUpTakePartInContest:
	.string "MC : Oh là là !\n"
	.string "N'est-ce pas un superbe POKéMON ?\p"
	.string "Allez ! Approchez et participez\n"
	.string "à nos splendides CONCOURS !\p"
	.string "Vous allez réussir ! J'en suis sûr !\n"
	.string "Mes yeux ne m'ont jamais trompé !$"

@ Unused
SlateportCity_ContestHall_Text_JudgeWouldntDoToMissContest:
	.string "JUGE : Eh bien, bonjour !\n"
	.string "Je vois que tu es un DRESSEUR !\p"
	.string "Alors, il ne faudrait surtout pas\n"
	.string "que tu rates un CONCOURS POKéMON !\p"
	.string "Obtiens un PASS CONCOURS à VERDANUR\n"
	.string "et participe quand tu veux !$"

@ Unused
SlateportCity_ContestHall_Text_ItsAppealTime:
	.string "C'est l'heure de l'allure !\n"
	.string "Avec quoi devrais-je commencer ?$"

@ Unused
SlateportCity_ContestHall_Text_DidntPayAttentionToAppeal:
	.string "Ils n'ont pas vraiment fait attention à\n"
	.string "l'allure de mon POKéMON…\p"
	.string "Hum, ce JUGE, il ne sait pas\n"
	.string "reconnaître la qualité quand il la voit.$"

@ Unused
SlateportCity_ContestHall_Text_RewardWithSageAdvice:
	.string "Oh, salut ! Tu dois être un vrai fan pour\n"
	.string "être aussi près de l'action.\p"
	.string "Je vais récompenser ton enthousiasme\n"
	.string "par ce sage conseil.\p"
	.string "Si une capacité plaît beaucoup,\n"
	.string "le public va s'enthousiasmer.\p"
	.string "Le POKéMON qui fait son allure\n"
	.string "quand tout le monde est excité…\p"
	.string "Eh bien, tu penses bien qu'il va se\n"
	.string "passer quelque chose de bien !$"

@ Unused
SlateportCity_ContestHall_Text_MoreFreakedOutThanMon:
	.string "Je n'y arrive pas ! Je suis plus stressé\n"
	.string "que mon POKéMON.\p"
	.string "Je tremble et mon cœur bat la chamade !$"

@ Unused
SlateportCity_ContestHall_Text_BattleAndContestAlike:
	.string "Un combat et un CONCOURS, ce n'est pas\n"
	.string "pareil, mais il y a des ressemblances.\p"
	.string "Il faut travailler dur et croire\n"
	.string "en le POKéMON que tu as élevé.$"

@ Unused
SlateportCity_ContestHall_Text_MonLooksOnTopOfGame:
	.string "Ce POKéMON a l'air au top\n"
	.string "de sa forme, non ?\p"
	.string "Un POKéMON qui réussit bien au\n"
	.string "second jugement semble plus\l"
	.string "détendu lors des allures.$"

@ Unused
SlateportCity_ContestHall_Text_MyMonBetterThanThatLot:
	.string "Regarde-moi cette misère !\p"
	.string "Hé, mon POKéMON est bien meilleur\n"
	.string "que tous ceux-là !$"

@ Unused
SlateportCity_ContestHall_Text_GetUrgeToMoveWithMon:
	.string "T'as pas envie de bouger avec\n"
	.string "les POKéMON quand ils font une\l"
	.string "allure pleine d'énergie ?$"

@ Unused
SlateportCity_ContestHall_Text_HyperRankStage:
	.string "CONCOURS POKéMON\n"
	.string "SCÈNE CATÉGORIE ULTRA !$"
