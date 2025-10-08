.set LOCALID_FAT_MAN, 1
.set LOCALID_MAN_1, 2
.set LOCALID_RICH_BOY, 3
.set LOCALID_GRUNT_1, 5
.set LOCALID_COOK, 6
.set LOCALID_OLD_WOMAN, 7
.set LOCALID_GIRL, 8
.set LOCALID_TY, 9
.set LOCALID_GABBY, 10
.set LOCALID_CAPT_STERN, 11
.set LOCALID_GRUNT_2, 18
.set LOCALID_GRUNT_3, 19
.set LOCALID_GRUNT_4, 26
.set LOCALID_GRUNT_5, 27
.set LOCALID_GRUNT_6, 28
.set LOCALID_GRUNT_7, 29
.set LOCALID_GRUNT_8, 30
.set LOCALID_GRUNT_9, 31
.set LOCALID_GRUNT_11, 33
.set LOCALID_SCOTT, 35

@ Note: LOCALID_SLATEPORT_ENERGY_GURU is a local id for this map used elsewhere. It's defined in event_objects.h

SlateportCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SlateportCity_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SlateportCity_OnFrame
	.byte 0

SlateportCity_OnTransition:
	setvar VAR_SLATEPORT_MUSEUM_1F_STATE, 0
	call SlateportCity_EventScript_EnterSlateport
	call_if_eq VAR_GARBAGEVAR, 1, SlateportCity_EventScript_MovePeopleForSternInterview
	call_if_eq VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 1, SlateportCity_EventScript_SetReadyForScottScene
	end

SlateportCity_EventScript_EnterSlateport::
	setflag FLAG_VISITED_MAHOGANY_TOWN
	setvar VAR_GARBAGEVAR, 0
	setflag FLAG_GARBAGEFLAG
	return

SlateportCity_EventScript_MovePeopleForSternInterview::
	setobjectxyperm LOCALID_CAPT_STERN, 28, 13
	setobjectxyperm LOCALID_OLD_WOMAN, 25, 13
	setobjectxyperm LOCALID_RICH_BOY, 25, 14
	setobjectxyperm LOCALID_COOK, 27, 16
	setobjectxyperm LOCALID_GIRL, 28, 16
	setobjectxyperm LOCALID_FAT_MAN, 29, 16
	setobjectxyperm LOCALID_MAN_1, 31, 14
	setobjectmovementtype LOCALID_CAPT_STERN, MOVEMENT_TYPE_FACE_DOWN
	setobjectmovementtype LOCALID_OLD_WOMAN, MOVEMENT_TYPE_FACE_DOWN_AND_RIGHT
	setobjectmovementtype LOCALID_RICH_BOY, MOVEMENT_TYPE_FACE_UP_AND_RIGHT
	setobjectmovementtype LOCALID_COOK, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype LOCALID_GIRL, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype LOCALID_FAT_MAN, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype LOCALID_MAN_1, MOVEMENT_TYPE_FACE_LEFT
	return

SlateportCity_EventScript_SetReadyForScottScene::
	setflag FLAG_HIDE_MAP_NAME_POPUP
	getplayerxy VAR_0x8004, VAR_0x8005
	goto_if_eq VAR_0x8004, 30, SlateportCity_EventScript_MoveScottLeft
	setobjectxyperm LOCALID_SCOTT, 23, 27
	setobjectmovementtype LOCALID_SCOTT, MOVEMENT_TYPE_FACE_RIGHT
	return

SlateportCity_EventScript_MoveScottLeft::
	setobjectxyperm LOCALID_SCOTT, 22, 27
	setobjectmovementtype LOCALID_SCOTT, MOVEMENT_TYPE_FACE_RIGHT
	return

SlateportCity_OnFrame:
	map_script_2 VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 1, SlateportCity_EventScript_ScottScene
	.2byte 0

SlateportCity_EventScript_ScottScene::
	lockall
	addobject LOCALID_SCOTT
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_Movement_PlayerFaceScott
	applymovement LOCALID_SCOTT, SlateportCity_Movement_ScottApproachPlayer
	waitmovement 0
	msgbox SlateportCity_Text_YouDroveTeamAquaAway, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SCOTT, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	delay 60
	msgbox SlateportCity_Text_MaybeThisTrainer, MSGBOX_DEFAULT
	applymovement LOCALID_SCOTT, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox SlateportCity_Text_LetsRegisterEachOther, MSGBOX_DEFAULT
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox SlateportCity_Text_RegisteredScott, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_SCOTT_MATCH_CALL
	msgbox SlateportCity_Text_KeepEyeOnTrainersBeSeeingYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SCOTT, SlateportCity_Movement_ScottExit
	waitmovement 0
	removeobject LOCALID_SCOTT
	setobjectxyperm LOCALID_SCOTT, 10, 12
	setobjectmovementtype LOCALID_SCOTT, MOVEMENT_TYPE_FACE_DOWN
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 2
	addvar VAR_SCOTT_STATE, 1
	releaseall
	end

SlateportCity_Movement_PlayerFaceScott:
	delay_16
	delay_8
	walk_in_place_faster_left
	step_end

SlateportCity_Movement_ScottApproachPlayer:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_Movement_ScottExit:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

SlateportCity_EventScript_EnergyGuru::
	lock
	faceplayer
	message SlateportCity_Text_EnergyGuruSellWhatYouNeed
	waitmessage
	pokemart SlateportCity_Pokemart_EnergyGuru
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_Pokemart_EnergyGuru:
	.2byte ITEM_PROTEIN
	.2byte ITEM_IRON
	.2byte ITEM_CARBOS
	.2byte ITEM_ZINC
	.2byte ITEM_CALCIUM
	.2byte ITEM_HP_UP
	.2byte ITEM_NONE
	release
	end

SlateportCity_EventScript_EffortRibbonWoman::
	lock
	faceplayer
	bufferleadmonspeciesname STR_VAR_1
	msgbox SlateportCity_Text_OhYourPokemon, MSGBOX_DEFAULT
	specialvar VAR_RESULT, LeadMonHasEffortRibbon
	call_if_eq VAR_RESULT, TRUE, SlateportCity_EventScript_MonHasEffortRibbon
	specialvar VAR_RESULT, Special_AreLeadMonEVsMaxedOut
	call_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_MonEVsNotMaxed
	msgbox SlateportCity_Text_PleaseGiveItThisEffortRibbon, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message SlateportCity_Text_ReceivedEffortRibbon
	waitfanfare
	msgbox SlateportCity_Text_PutEffortRibbonOnMon, MSGBOX_DEFAULT
	special GiveLeadMonEffortRibbon
	release
	end

SlateportCity_EventScript_MonEVsNotMaxed::
	msgbox SlateportCity_Text_GoForItLittleHarder, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_MonHasEffortRibbon::
	msgbox SlateportCity_Text_EffortRibbonLooksGoodOnIt, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Cook::
	lock
	faceplayer
	call_if_eq VAR_GARBAGEVAR, 1, SlateportCity_EventScript_CookSternInterview
	msgbox SlateportCity_Text_SeaweedFullOfLife, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_CookSternInterview::
	msgbox SlateportCity_Text_CaptainComeBackWithBigFish, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_OldWoman::
	lock
	faceplayer
	call_if_eq VAR_GARBAGEVAR, 1, SlateportCity_EventScript_OldWomanSternInterview
	msgbox SlateportCity_Text_HowTownIsBornAndGrows, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_OldWomanSternInterview::
	msgbox SlateportCity_Text_CaptSternBeingInterviewed, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Girl::
	lock
	faceplayer
	call_if_eq VAR_GARBAGEVAR, 1, SlateportCity_EventScript_GirlSternInterview
	goto_if_set FLAG_RECEIVED_SECRET_POWER, SlateportCity_EventScript_GirlSecretBase
	msgbox SlateportCity_Text_SlateportWonderfulPlace, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_GirlSternInterview::
	msgbox SlateportCity_Text_InterviewerSoCool, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_GirlSecretBase::
	msgbox SlateportCity_Text_BuyBricksSoDecorWontGetDirty, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_RichBoy::
	lock
	faceplayer
	call_if_eq VAR_GARBAGEVAR, 1, SlateportCity_EventScript_RichBoySternInterview
	msgbox SlateportCity_Text_GoingToCompeteInBattleTent, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_RichBoySternInterview::
	msgbox SlateportCity_Text_SternSaysDiscoveredSomething, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_FatMan::
	goto_if_eq VAR_GARBAGEVAR, 1, SlateportCity_EventScript_FatManSternInterview
	msgbox SlateportCity_Text_BushedHikingFromMauville, MSGBOX_NPC
	end

SlateportCity_EventScript_FatManSternInterview::
	msgbox SlateportCity_Text_AmIOnTV, MSGBOX_SIGN
	end

SlateportCity_EventScript_Man1::
	lock
	faceplayer
	call_if_eq VAR_GARBAGEVAR, 1, SlateportCity_EventScript_Man1SternInterview
	msgbox SlateportCity_Text_EveryoneCallsHimCaptStern, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Man1SternInterview::
	msgbox SlateportCity_Text_CaptainsACelebrity, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Woman1::
	lock
	faceplayer
	goto_if_set FLAG_DOCK_REJECTED_DEVON_GOODS, SlateportCity_EventScript_Woman1AquaGone
	msgbox SlateportCity_Text_WhatsLongLineOverThere, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Woman1AquaGone::
	msgbox SlateportCity_Text_VisitedMuseumOften, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_BattleTentSign::
	msgbox SlateportCity_Text_BattleTentSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_SternsShipyardSign::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_EventScript_SternsShipyardFerryComplete
	goto_if_set FLAG_BADGE07_GET, SlateportCity_EventScript_SternsShipyardNearsCompletion
	msgbox SlateportCity_Text_SternsShipyardWantedSign, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_SternsShipyardNearsCompletion::
	msgbox SlateportCity_Text_SternsShipyardNearsCompletion, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_SternsShipyardFerryComplete::
	msgbox SlateportCity_Text_SternsShipyardFerryComplete, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_PokemonFanClubSign::
	msgbox SlateportCity_Text_PokemonFanClubSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_OceanicMuseumSign::
	msgbox SlateportCity_Text_OceanicMuseumSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_CitySign::
	msgbox SlateportCity_Text_CitySign, MSGBOX_SIGN
	end

SlateportCity_EventScript_MarketSign::
	msgbox SlateportCity_Text_MarketSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_HarborSign::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_EventScript_HarborSignFerryComplete
	msgbox SlateportCity_Text_HarborFerryUnderConstruction, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_HarborSignFerryComplete::
	msgbox SlateportCity_Text_HarborSign, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_NameRatersHouseSign::
	msgbox SlateportCity_Text_NameRatersHouseSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_Maniac::
	lock
	faceplayer
	call_if_eq VAR_GARBAGEVAR, 1, SlateportCity_EventScript_ManiacSternInterview
	msgbox SlateportCity_Text_GetNameRaterToHelpYou, MSGBOX_DEFAULT
	release
	end

@ Unclear if the text here was meant to be different, but its not
SlateportCity_EventScript_ManiacSternInterview::
	msgbox SlateportCity_Text_GetNameRaterToHelpYou, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Woman2::
	msgbox SlateportCity_Text_CantChangeTradeMonName, MSGBOX_NPC
	end

SlateportCity_EventScript_Sailor1::
	msgbox SlateportCity_Text_SeaIsSoWet, MSGBOX_NPC
	end

SlateportCity_EventScript_Sailor2::
	msgbox SlateportCity_Text_SinkOldBoats, MSGBOX_NPC
	end

SlateportCity_EventScript_PokefanF::
	msgbox SlateportCity_Text_BuyTooMuch, MSGBOX_NPC
	end

SlateportCity_EventScript_Man2::
	msgbox SlateportCity_Text_BattleTentBuiltRecently, MSGBOX_NPC
	end

SlateportCity_EventScript_AquaGrunt1::
	lock
	faceplayer
	msgbox SlateportCity_Text_QuitPushing, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt2::
	lock
	faceplayer
	msgbox SlateportCity_Text_AquaHasPolicy, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt3::
	lock
	faceplayer
	msgbox SlateportCity_Text_BossIsBrilliant, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt4::
	lock
	faceplayer
	msgbox SlateportCity_Text_WhatsNewSchemeIWonder, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt5::
	lock
	faceplayer
	msgbox SlateportCity_Text_ShouldTakeItAll, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_5, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt6::
	lock
	faceplayer
	msgbox SlateportCity_Text_DontButtIn, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_6, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt7::
	lock
	faceplayer
	msgbox SlateportCity_Text_RemindsMeOfLongLineForGames, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_7, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt8::
	lock
	faceplayer
	msgbox SlateportCity_Text_WhyAreWeLiningUp, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_8, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt9::
	lock
	faceplayer
	playse SE_PIN
	applymovement LOCALID_GRUNT_9, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_GRUNT_9, Common_Movement_Delay48
	waitmovement 0
	msgbox SlateportCity_Text_WhatDoYouWant, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_9, Common_Movement_FaceOriginalDirection
	waitmovement 0
	applymovement LOCALID_GRUNT_9, SlateportCity_Movement_DelayAquaGrunt
	waitmovement 0
	applymovement LOCALID_GRUNT_9, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_Text_IllReadSignForYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_9, Common_Movement_FaceOriginalDirection
	waitmovement 0
	applymovement LOCALID_GRUNT_9, SlateportCity_Movement_DelayAquaGrunt
	waitmovement 0
	msgbox SlateportCity_Text_SaysSomethingLikeSeaIsEndless, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_9, Common_Movement_FacePlayer
	waitmovement 0
	applymovement LOCALID_GRUNT_9, SlateportCity_Movement_DelayAquaGrunt
	waitmovement 0
	applymovement LOCALID_GRUNT_9, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_Movement_DelayAquaGrunt:
	delay_16
	delay_16
	step_end

SlateportCity_EventScript_AquaGrunt10::
	msgbox SlateportCity_Text_ShouldveBroughtMyGameBoy, MSGBOX_SIGN
	end

SlateportCity_EventScript_AquaGrunt11::
	lock
	faceplayer
	msgbox SlateportCity_Text_HotSpringsAfterOperation, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_11, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_DollClerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemartdecoration SlateportCity_PokemartDecor_Dolls
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_PokemartDecor_Dolls:
	.2byte DECOR_AZURILL_DOLL
	.2byte DECOR_MARILL_DOLL
	.2byte DECOR_SKITTY_DOLL
	.2byte DECOR_NONE
	release
	end

SlateportCity_EventScript_ComeBackWithSecretPower::
	msgbox gText_ComeBackWithSecretPower, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_DecorClerk::
	lock
	faceplayer
	goto_if_unset FLAG_RECEIVED_SECRET_POWER, SlateportCity_EventScript_ComeBackWithSecretPower
	message gText_HowMayIServeYou
	waitmessage
	pokemartdecoration SlateportCity_PokemartDecor
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_PokemartDecor:
	.2byte DECOR_RED_BRICK
	.2byte DECOR_BLUE_BRICK
	.2byte DECOR_YELLOW_BRICK
	.2byte DECOR_RED_BALLOON
	.2byte DECOR_BLUE_BALLOON
	.2byte DECOR_YELLOW_BALLOON
	.2byte DECOR_C_LOW_NOTE_MAT
	.2byte DECOR_D_NOTE_MAT
	.2byte DECOR_E_NOTE_MAT
	.2byte DECOR_F_NOTE_MAT
	.2byte DECOR_G_NOTE_MAT
	.2byte DECOR_A_NOTE_MAT
	.2byte DECOR_B_NOTE_MAT
	.2byte DECOR_C_HIGH_NOTE_MAT
	.2byte DECOR_NONE
	release
	end

SlateportCity_EventScript_PowerTMClerk::
	goto_if_set FLAG_FINITE_TMS, SlateportCity_EventScript_PowerTMClerkFinite
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart SlateportCity_Pokemart_PowerTMs
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_Pokemart_PowerTMs:
	.2byte ITEM_SEA_INCENSE
	.2byte ITEM_LAX_INCENSE
	.2byte ITEM_NONE
	release
	end

SlateportCity_EventScript_PowerTMClerkFinite::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart SlateportCity_Pokemart_PowerTMs2
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_Pokemart_PowerTMs2:
	.2byte ITEM_TM_HIDDEN_POWER
	.2byte ITEM_TM_SECRET_POWER
	.2byte ITEM_SEA_INCENSE
	.2byte ITEM_LAX_INCENSE
	.2byte ITEM_NONE
	release
	end

@ Scene with Capt Sterns interview and Team Aqua announcing plans to steal Submarine
SlateportCity_EventScript_CaptStern::
	lockall
	msgbox SlateportCity_Text_SternMoveAheadWithExploration, MSGBOX_DEFAULT
	msgbox SlateportCity_Text_GabbyWonderfulThanksForInterview, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GABBY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 10
	applymovement LOCALID_TY, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 25
	applymovement LOCALID_CAPT_STERN, SlateportCity_Movement_SternWatchGabbyAndTyExit
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_Movement_PlayerFaceStern
	applymovement LOCALID_GABBY, SlateportCity_Movement_GabbyExit
	applymovement LOCALID_TY, SlateportCity_Movement_TyExit
	waitmovement 0
	removeobject LOCALID_GABBY
	removeobject LOCALID_TY
	msgbox SlateportCity_Text_SternWhewFirstInterview, MSGBOX_DEFAULT
	applymovement LOCALID_CAPT_STERN, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox SlateportCity_Text_OhPlayerWeMadeDiscovery, MSGBOX_DEFAULT
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	msgbox SlateportCity_Text_AquaWillAssumeControlOfSubmarine, MSGBOX_DEFAULT
	applymovement LOCALID_COOK, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_FAT_MAN, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_OLD_WOMAN, SlateportCity_Movement_OldWomanConcern
	applymovement LOCALID_RICH_BOY, Common_Movement_QuestionMark
	applymovement LOCALID_MAN_1, SlateportCity_Movement_ManConcern
	waitmovement 0
	applymovement LOCALID_CAPT_STERN, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox SlateportCity_Text_SternWhatWasAllThat, MSGBOX_DEFAULT
	playse SE_PIN
	applymovement LOCALID_CAPT_STERN, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_CAPT_STERN, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_CAPT_STERN, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox SlateportCity_Text_FromHarborTryingToTakeSub, MSGBOX_DEFAULT
	msgbox SlateportCity_Text_PleaseComeWithMe, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CAPT_STERN, SlateportCity_Movement_SternEnterHarbor
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_Movement_PlayerEnterHarbor
	waitmovement 0
	removeobject LOCALID_CAPT_STERN
	clearflag FLAG_GARBAGEFLAG
	clearflag FLAG_GARBAGEFLAG
	clearflag FLAG_GARBAGEFLAG
	clearflag FLAG_GARBAGEFLAG
	setvar VAR_GARBAGEVAR, 2
	warp MAP_SLATEPORT_CITY_HARBOR, 11, 14
	waitstate
	releaseall
	end

SlateportCity_Movement_OldWomanConcern:
	delay_16
	delay_16
	emote_question_mark
	walk_in_place_faster_right
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

SlateportCity_Movement_ManConcern:
	emote_question_mark
	walk_in_place_faster_up
	delay_16
	walk_in_place_faster_down
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

SlateportCity_Movement_GabbyExit:
	delay_16
	walk_left
	walk_left
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

SlateportCity_Movement_TyExit:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

SlateportCity_Movement_Unused:
	walk_down
	walk_in_place_faster_up
	step_end

SlateportCity_Movement_SternEnterHarbor:
	walk_right
	walk_up
	walk_up
	set_invisible
	step_end

SlateportCity_Movement_SternWatchGabbyAndTyExit:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_down
	walk_left
	step_end

SlateportCity_Movement_PlayerEnterHarbor:
	walk_in_place_faster_right
	delay_16
	delay_16
	walk_right
	walk_up
	step_end

SlateportCity_Movement_PlayerFaceStern:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_down
	step_end

SlateportCity_EventScript_Ty::
	msgbox SlateportCity_Text_BigSmileForCamera, MSGBOX_SIGN
	end

SlateportCity_EventScript_Gabby::
	msgbox SlateportCity_Text_MostInvaluableExperience, MSGBOX_SIGN
	end

SlateportCity_EventScript_Man3::
	msgbox SlateportCity_Text_WonderIfLighthouseStartlesPokemon, MSGBOX_NPC
	end

SlateportCity_EventScript_BerryPowderClerk::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_POWDER_JAR, SlateportCity_EventScript_ReceivedPowderJar
	msgbox SlateportCity_Text_ExplainBerries, MSGBOX_DEFAULT
	giveitem ITEM_POWDER_JAR
	setflag FLAG_RECEIVED_POWDER_JAR
	msgbox SlateportCity_Text_ExplainBerryPowder, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_ReceivedPowderJar::
	setvar VAR_0x8004, 1
	specialvar VAR_RESULT, HasEnoughBerryPowder
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_ExplainBerryPowder
	msgbox SlateportCity_Text_BroughtMeSomeBerryPowder, MSGBOX_DEFAULT
	special DisplayBerryPowderVendorMenu
	goto SlateportCity_EventScript_ChooseBerryPowderItem
	end

SlateportCity_EventScript_ExplainBerryPowder::
	msgbox SlateportCity_Text_ExplainBerryPowder, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_ChooseBerryPowderItem::
	message SlateportCity_Text_ExchangeWhatWithIt
	waitmessage
	setvar VAR_0x8004, SCROLL_MULTI_BERRY_POWDER_VENDOR
	special ShowScrollableMultichoice
	waitstate
	switch VAR_RESULT
	case 0, SlateportCity_EventScript_EnergyPowder
	case 1, SlateportCity_EventScript_EnergyRoot
	case 2, SlateportCity_EventScript_HealPowder
	case 3, SlateportCity_EventScript_RevivalHerb
	case 4, SlateportCity_EventScript_Protein
	case 5, SlateportCity_EventScript_Iron
	case 6, SlateportCity_EventScript_Carbos
	case 7, SlateportCity_EventScript_Calcium
	case 8, SlateportCity_EventScript_Zinc
	case 9, SlateportCity_EventScript_HPUp
	case 10, SlateportCity_EventScript_PPUp
	case 11, SlateportCity_EventScript_CancelPowderItemSelect
	case MULTI_B_PRESSED, SlateportCity_EventScript_CancelPowderItemSelect
	end

SlateportCity_EventScript_EnergyPowder::
	bufferitemname STR_VAR_1, ITEM_ENERGY_POWDER
	setvar VAR_0x8008, ITEM_ENERGY_POWDER
	setvar VAR_0x8009, 50
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_EnergyRoot::
	bufferitemname STR_VAR_1, ITEM_ENERGY_ROOT
	setvar VAR_0x8008, ITEM_ENERGY_ROOT
	setvar VAR_0x8009, 80
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_HealPowder::
	bufferitemname STR_VAR_1, ITEM_HEAL_POWDER
	setvar VAR_0x8008, ITEM_HEAL_POWDER
	setvar VAR_0x8009, 50
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_RevivalHerb::
	bufferitemname STR_VAR_1, ITEM_REVIVAL_HERB
	setvar VAR_0x8008, ITEM_REVIVAL_HERB
	setvar VAR_0x8009, 300
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Protein::
	bufferitemname STR_VAR_1, ITEM_PROTEIN
	setvar VAR_0x8008, ITEM_PROTEIN
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Iron::
	bufferitemname STR_VAR_1, ITEM_IRON
	setvar VAR_0x8008, ITEM_IRON
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Carbos::
	bufferitemname STR_VAR_1, ITEM_CARBOS
	setvar VAR_0x8008, ITEM_CARBOS
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Calcium::
	bufferitemname STR_VAR_1, ITEM_CALCIUM
	setvar VAR_0x8008, ITEM_CALCIUM
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Zinc::
	bufferitemname STR_VAR_1, ITEM_ZINC
	setvar VAR_0x8008, ITEM_ZINC
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_HPUp::
	bufferitemname STR_VAR_1, ITEM_HP_UP
	setvar VAR_0x8008, ITEM_HP_UP
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_PPUp::
	bufferitemname STR_VAR_1, ITEM_PP_UP
	setvar VAR_0x8008, ITEM_PP_UP
	setvar VAR_0x8009, 3000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_CancelPowderItemSelect::
	msgbox SlateportCity_Text_ComeBackToTradeBerryPowder, MSGBOX_DEFAULT
	special RemoveBerryPowderVendorMenu
	release
	end

SlateportCity_EventScript_TryBuyBerryPowderItem::
	msgbox SlateportCity_Text_ExchangeBerryPowderForItem, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SlateportCity_EventScript_ChooseBerryPowderItem
	copyvar VAR_0x8004, VAR_0x8009
	specialvar VAR_RESULT, HasEnoughBerryPowder
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_NotEnoughBerryPowder
	giveitem VAR_0x8008
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_NoRoomForBerryPowderItem
	copyvar VAR_0x8004, VAR_0x8009
	special TakeBerryPowder
	special PrintPlayerBerryPowderAmount
	msgbox SlateportCity_Text_FineBerryPowderTradeSomethingElse, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SlateportCity_EventScript_ChooseBerryPowderItem
	msgbox SlateportCity_Text_WhenYouGetMoreBringItToMe, MSGBOX_DEFAULT
	special RemoveBerryPowderVendorMenu
	release
	end

SlateportCity_EventScript_NoRoomForBerryPowderItem::
	msgbox gText_TheBagIsFull, MSGBOX_DEFAULT
	special RemoveBerryPowderVendorMenu
	release
	end

SlateportCity_EventScript_NotEnoughBerryPowder::
	msgbox SlateportCity_Text_DontHaveEnoughBerryPowder, MSGBOX_DEFAULT
	goto SlateportCity_EventScript_ChooseBerryPowderItem
	end

SlateportCity_EventScript_ScottBattleTentScene::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	opendoor 10, 12
	waitdooranim
	addobject LOCALID_SCOTT
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_Movement_PushPlayerDown
	applymovement LOCALID_SCOTT, SlateportCity_Movement_ScottExitBattleTent
	waitmovement 0
	closedoor 10, 12
	waitdooranim
	msgbox SlateportCity_Text_TakingBattleTentChallenge, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_Movement_PlayerWatchScottExit
	applymovement LOCALID_SCOTT, SlateportCity_Movement_ScottExitAfterBattleTent
	waitmovement 0
	removeobject LOCALID_SCOTT
	addvar VAR_SCOTT_STATE, 1
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 3
	releaseall
	end

SlateportCity_Movement_PushPlayerDown:
	lock_facing_direction
	walk_down
	unlock_facing_direction
	step_end

SlateportCity_Movement_PlayerWatchScottExit:
	delay_16
	walk_in_place_faster_right
	step_end

SlateportCity_Movement_ScottExitBattleTent:
	delay_8
	walk_down
	step_end

SlateportCity_Movement_ScottExitAfterBattleTent:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_EventScript_BerryCrushRankingsSign::
	lockall
	special ShowBerryCrushRankings
	waitstate
	releaseall
	end

SlateportCity_Text_EnergyGuruSellWhatYouNeed:
	.string "Je suis le GURU ÉNERGIE ! Je vais tout donner et\n"
	.string "te vendre ce dont tu as besoin !$"

SlateportCity_Text_OhYourPokemon:
	.string "Oh ?\n"
	.string "Ton {STR_VAR_1}…$"

SlateportCity_Text_PleaseGiveItThisEffortRibbon:
	.string "Il s'est donné à fond !\p"
	.string "En récompense, offre-lui ce\n"
	.string "RUBAN EFFORT.$"

SlateportCity_Text_ReceivedEffortRibbon:
	.string "{PLAYER} reçoit le RUBAN EFFORT.$"

SlateportCity_Text_PutEffortRibbonOnMon:
	.string "{PLAYER} met le RUBAN EFFORT\n"
	.string "à {STR_VAR_1}.$"

SlateportCity_Text_GoForItLittleHarder:
	.string "Il faut que tu te donnes un peu plus.\p"
	.string "Si tu le fais, j'offrirai à ton POKéMON\n"
	.string "quelque chose de sympa.$"

SlateportCity_Text_EffortRibbonLooksGoodOnIt:
	.string "Oh ! Ton {STR_VAR_1}, ce RUBAN EFFORT\n"
	.string "lui va très bien !$"

SlateportCity_Text_WonderIfLighthouseStartlesPokemon:
	.string "La lumière du phare porte à\n"
	.string "des dizaines de kilomètres.\p"
	.string "Je me demande si ça n'effraie pas les POKéMON\n"
	.string "dans la mer.$"

SlateportCity_Text_SeaweedFullOfLife:
	.string "Oh, regarde ça !\p"
	.string "Les algues qu'on trouve ici sont\n"
	.string "fraîches et pleines de vie.\p"
	.string "On dirait même qu'elles pourraient\n"
	.string "se dresser et attaquer !$"

SlateportCity_Text_HowTownIsBornAndGrows:
	.string "Là où l'eau est pure, les fruits\n"
	.string "d'une récolte abondante s'accumulent.\p"
	.string "Et là où les gens se rassemblent, un marché\n"
	.string "finit par s'installer.\p"
	.string "C'est ainsi qu'une ville naît et grandit.$"

SlateportCity_Text_SlateportWonderfulPlace:
	.string "Faire du shopping en respirant\n"
	.string "le parfum de l'océan…\p"
	.string "POURPREVILLE est un endroit merveilleux !$"

SlateportCity_Text_BuyBricksSoDecorWontGetDirty:
	.string "Si tu poses des POUPÉES ou des COUSSINS\n"
	.string "par terre, ils vont se salir.\p"
	.string "Je vais acheter des BRIQUES pour que mes\n"
	.string "POUPÉES et COUSSINS ne se salissent pas\l"
	.string "quand je les laisse dehors.$"

SlateportCity_Text_GoingToCompeteInBattleTent:
	.string "Wroooar ! Je vais participer aussi\n"
	.string "au DÔME DE COMBAT !\p"
	.string "Mais avant ça, je dois attraper\n"
	.string "des POKéMON !$"

SlateportCity_Text_BushedHikingFromMauville:
	.string "Ouf… Je suis épuisé…\p"
	.string "Je suis venu à pied depuis LAVANDIA.\n"
	.string "Mais, quelle grande ville !\p"
	.string "Si j'avais su, j'aurais pris\n"
	.string "mon VÉLO !$"

SlateportCity_Text_EveryoneCallsHimCaptStern:
	.string "STERN, le gars qui a construit le\n"
	.string "MUSÉE, est aussi le chef d'une équipe\l"
	.string "d'exploration sous-marine.\p"
	.string "C'est pour ça que tout le monde l'appelle CAPT. STERN.$"

SlateportCity_Text_WhatsLongLineOverThere:
	.string "Qu'est-ce que c'est là-bas ?\n"
	.string "Cette longue file d'attente…$"

SlateportCity_Text_VisitedMuseumOften:
	.string "Quand j'étais enfant, je visitais\n"
	.string "souvent le MUSÉE.\p"
	.string "Je rêvais des mystères de la mer\n"
	.string "après avoir vu les expositions.$"

SlateportCity_Text_QuitPushing:
	.string "Hé, toi ! Arrête de pousser !\n"
	.string "C'est la file, tu ne vois pas ?$"

SlateportCity_Text_AquaHasPolicy:
	.string "La TEAM AQUA a pour politique de\n"
	.string "se rassembler et de se disperser\l"
	.string "sur le lieu de l'opération.$"

SlateportCity_Text_BossIsBrilliant:
	.string "Notre BOSS est brillant.\p"
	.string "Que veut-il faire avec\n"
	.string "un MUSÉE maintenant ?$"

SlateportCity_Text_WhatsNewSchemeIWonder:
	.string "Quel est le nouveau plan, je me demande ?\p"
	.string "Notre BOSS fait peur quand il est en colère, alors\n"
	.string "je ferais mieux de ne pas tout gâcher…$"

SlateportCity_Text_ShouldTakeItAll:
	.string "S'il y a quelque chose dont on a besoin\n"
	.string "dans le MUSÉE, on devrait tout prendre !$"

SlateportCity_Text_DontButtIn:
	.string "Hé, toi là !\n"
	.string "Ne te mêle pas de ça !$"

SlateportCity_Text_RemindsMeOfLongLineForGames:
	.string "Une longue file, hein ?\p"
	.string "Ça me rappelle les fois où j'ai fait la queue\n"
	.string "pour acheter des jeux à succès…$"

SlateportCity_Text_WhyAreWeLiningUp:
	.string "Pourquoi on fait la queue et on paie ?\n"
	.string "On devrait juste entrer !$"

SlateportCity_Text_WhatDoYouWant:
	.string "Quoi ?\n"
	.string "Qu'est-ce que tu veux ?$"

SlateportCity_Text_IllReadSignForYou:
	.string "Tu veux lire ce panneau ?\n"
	.string "Je vais te le lire !$"

SlateportCity_Text_SaysSomethingLikeSeaIsEndless:
	.string "Voyons voir…\p"
	.string "Euh… Je crois que ça dit quelque chose comme\n"
	.string "« la vie dans la mer est sans fin ».\p"
	.string "Oui, je suis presque sûr que c'est\n"
	.string "ce qui est écrit.$"

SlateportCity_Text_ShouldveBroughtMyGameBoy:
	.string "Grompf…\p"
	.string "J'aurais dû prendre ma Game Boy\n"
	.string "Advance pour ne pas m'ennuyer dans la file…\p"
	.string "Grompf…$"

SlateportCity_Text_HotSpringsAfterOperation:
	.string "Quand cette opération sera terminée, je t'emmènerai\n"
	.string "dans une source chaude !\p"
	.string "C'est ce que notre chef a dit.\n"
	.string "J'ai hâte !$"

SlateportCity_Text_SeaIsSoWet:
	.string "La mer est si vaste…\p"
	.string "La mer aurait-elle été créée par\n"
	.string "les larmes versées par les POKéMON ?$"

SlateportCity_Text_SinkOldBoats:
	.string "Tu sais ce qu'on fait des vieux\n"
	.string "bateaux trop usés pour naviguer ?\p"
	.string "On les coule dans la mer pour qu'ils\n"
	.string "deviennent des habitats pour les POKéMON.$"

SlateportCity_Text_BuyTooMuch:
	.string "À chaque fois que je viens ici, je me laisse\n"
	.string "emporter et j'achète trop de choses.$"

SlateportCity_Text_GetNameRaterToHelpYou:
	.string "Si tu veux changer le surnom de ton POKéMON,\n"
	.string "il faut demander au JUGE-SURNOM\l"
	.string "de t'aider.$"

SlateportCity_Text_CantChangeTradeMonName:
	.string "Tout POKéMON reçu par échange,\n"
	.string "tu ne peux pas changer son surnom.\p"
	.string "L'amour de l'ORIGINAL DRESSEUR pour ce\n"
	.string "POKéMON est dans le surnom.$"

SlateportCity_Text_BattleTentBuiltRecently:
	.string "Récemment, un DÔME DE COMBAT a été construit\n"
	.string "à POURPREVILLE.\p"
	.string "Les ARÈNES sont sympas, mais le DÔME DE COMBAT\n"
	.string "est génial à sa façon.\p"
	.string "Tu devrais trouver des POKéMON forts\n"
	.string "pour le DÔME DE COMBAT !$"

SlateportCity_Text_CaptSternBeingInterviewed:
	.string "J'espérais que ce soit une star célèbre\n"
	.string "pour avoir un autographe.\p"
	.string "Mais qui est-ce qu'on interviewe ?\n"
	.string "Ce n'est pas le CAPT. STERN ?$"

SlateportCity_Text_InterviewerSoCool:
	.string "Cette journaliste est tellement classe\n"
	.string "et jolie.\p"
	.string "Quand je serai grand, je veux devenir\n"
	.string "journaliste international !$"

SlateportCity_Text_SternSaysDiscoveredSomething:
	.string "Le CAPT. STERN dit qu'ils ont découvert\n"
	.string "quelque chose au fond de la mer.\p"
	.string "Je me demande ce que c'est ?\n"
	.string "Qu'est-ce que ça peut être ?$"

SlateportCity_Text_CaptainComeBackWithBigFish:
	.string "Que se passe-t-il ici ?\p"
	.string "Le bon CAPITAINE est-il revenu avec\n"
	.string "un gros poisson du fond de l'océan ?$"

SlateportCity_Text_AmIOnTV:
	.string "Hé ! Tu regardes ?\n"
	.string "Je passe à la télé ?$"

SlateportCity_Text_CaptainsACelebrity:
	.string "Une interview à la télé ! Ici !\n"
	.string "Le CAPITAINE est une célébrité !$"

SlateportCity_Text_BigSmileForCamera:
	.string "TY : Allez, CAPT. STERN, un grand sourire\n"
	.string "pour la caméra !$"

SlateportCity_Text_MostInvaluableExperience:
	.string "GABRIELLE : Je vois, je vois. Vous avez vécu une\n"
	.string "expérience des plus précieuses…$"

SlateportCity_Text_SternMoveAheadWithExploration:
	.string "CAPT. STERN : Oui, en effet. Nous comptons\n"
	.string "poursuivre notre exploration.$"

SlateportCity_Text_GabbyWonderfulThanksForInterview:
	.string "GABRIELLE : C'est merveilleux, CAPT. STERN !\n"
	.string "Merci d'avoir pris le temps de nous parler\l"
	.string "malgré votre emploi du temps chargé.\p"
	.string "Nous espérons pouvoir vous interviewer à nouveau\n"
	.string "avec d'autres découvertes !$"

SlateportCity_Text_SternWhewFirstInterview:
	.string "CAPT. STERN : Ouf…\p"
	.string "C'était la première fois que je passais à la télé.\n"
	.string "C'était stressant.$"

SlateportCity_Text_OhPlayerWeMadeDiscovery:
	.string "Oh ! {PLAYER}{KUN} !\n"
	.string "Tu as l'air en forme !\p"
	.string "Nous avons fait une grande découverte lors de notre\n"
	.string "dernière exploration sous-marine.\p"
	.string "Nous avons trouvé une caverne sous-marine sur\n"
	.string "la ROUTE 128.\p"
	.string "Nous pensons que c'est l'habitat d'un POKéMON\n"
	.string "qu'on dit disparu depuis longtemps.$"

SlateportCity_Text_AquaWillAssumeControlOfSubmarine:
	.string "Fufufu…\n"
	.string "CAPT. STERN, je présume.\p"
	.string "Nous, la TEAM AQUA, allons prendre\n"
	.string "le contrôle de votre sous-marin !\p"
	.string "Vos objections sont inutiles !\n"
	.string "Nous attendons votre entière coopération !\p"
	.string "Fufufu…\n"
	.string "Regardez et apprenez ce que la TEAM\l"
	.string "AQUA a prévu !$"

SlateportCity_Text_SternWhatWasAllThat:
	.string "CAPT. STERN : Que se passe-t-il ?\p"
	.string "On aurait dit quelqu'un qui utilisait\n"
	.string "un mégaphone…\p"
	.string "D'où ça vient ?$"

SlateportCity_Text_FromHarborTryingToTakeSub:
	.string "Ça vient du PORT !\p"
	.string "Le sous-marin !\n"
	.string "Ils essaient de le prendre !$"

SlateportCity_Text_PleaseComeWithMe:
	.string "{PLAYER}{KUN} !\n"
	.string "Viens avec moi, s'il te plaît !$"

SlateportCity_Text_BattleTentSign:
	.string "DÔME DE COMBAT DE POURPREVILLE\n"
	.string "« Trouve-le ! Le POKéMON ultime ! »$"

SlateportCity_Text_SternsShipyardWantedSign:
	.string "CHANTIER NAVAL STERN\p"
	.string "« Recherche : Marin capable de naviguer\n"
	.string "dans tous les courants. »$"

SlateportCity_Text_SternsShipyardNearsCompletion:
	.string "CHANTIER NAVAL STERN\p"
	.string "« Le ferry M.S. MARÉE touche à sa fin\n"
	.string "pour desservir les ports de\l"
	.string "POURPREVILLE et ALGATIA. »$"

SlateportCity_Text_SternsShipyardFerryComplete:
	.string "CHANTIER NAVAL STERN\p"
	.string "« L'embarquement du ferry POURPREVILLE-ALGATIA\n"
	.string "M.S. MARÉE se fait au\l"
	.string "PORT. »$"

SlateportCity_Text_PokemonFanClubSign:
	.string "CLUB DES FANS DE POKéMON\n"
	.string "« Appel à tous les fans de POKéMON ! »$"

SlateportCity_Text_OceanicMuseumSign:
	.string "« La mer sans fin nourrit\n"
	.string "toute vie. »\p"
	.string "MUSÉE OCÉANIQUE$"

SlateportCity_Text_CitySign:
	.string "POURPREVILLE\p"
	.string "« Le port où les gens et les POKéMON\n"
	.string "se croisent. »$"

SlateportCity_Text_MarketSign:
	.string "MARCHÉ DE POURPREVILLE\n"
	.string "« Des objets uniques introuvables ailleurs ! »$"

SlateportCity_Text_HarborFerryUnderConstruction:
	.string "PORT DE POURPREVILLE\p"
	.string "« Le ferry M.S. MARÉE est en\n"
	.string "construction au CHANTIER NAVAL.\p"
	.string "« Le service devrait commencer\n"
	.string "bientôt. »$"

SlateportCity_Text_HarborSign:
	.string "PORT DE POURPREVILLE\p"
	.string "« Profitez d'une croisière agréable à bord\n"
	.string "du ferry M.S. MARÉE. »$"

SlateportCity_Text_NameRatersHouseSign:
	.string "MAISON DU JUGE-SURNOM\n"
	.string "« Surnoms de POKéMON évalués. »$"

SlateportCity_Text_ExplainBerries:
	.string "Si un POKéMON sauvage est blessé, il se soigne\n"
	.string "en mâchant des BAIES.\p"
	.string "Tu le savais ?\p"
	.string "Quelqu'un a vu ça et a eu l'idée de faire\n"
	.string "des médicaments à partir des BAIES.\p"
	.string "Tu le savais ?\p"
	.string "Pour transformer les BAIES en médicaments,\n"
	.string "il faut les réduire en poudre.\p"
	.string "Tu le savais ?\p"
	.string "Tu sembles t'intéresser\n"
	.string "aux BAIES !\p"
	.string "J'ai quelque chose de bien pour quelqu'un\n"
	.string "comme toi.$"

SlateportCity_Text_ExplainBerryPowder:
	.string "J'ai récemment fait installer des machines dans les\n"
	.string "CENTRES POKéMON pour écraser les BAIES.\p"
	.string "Les machines ÉCRASE-BAIE sont au\n"
	.string "COIN DIRECT à l'étage.\p"
	.string "Tu le savais ?\p"
	.string "Peux-tu me faire de la POUDRE BAIE avec\n"
	.string "ces machines ?\p"
	.string "Je peux te faire toutes sortes de médicaments\n"
	.string "si tu m'apportes beaucoup de POUDRE BAIE.$"

SlateportCity_Text_BroughtMeSomeBerryPowder:
	.string "Tu m'as apporté de la\n"
	.string "POUDRE BAIE ?$"

SlateportCity_Text_ExchangeWhatWithIt:
	.string "Contre quoi veux-tu l'échanger ?$"

SlateportCity_Text_ExchangeBerryPowderForItem:
	.string "D'accord, tu veux échanger ta\n"
	.string "POUDRE BAIE contre un {STR_VAR_1} ?$"

SlateportCity_Text_DontHaveEnoughBerryPowder:
	.string "Oh, zut. Tu n'as pas assez de\n"
	.string "POUDRE BAIE.$"

SlateportCity_Text_FineBerryPowderTradeSomethingElse:
	.string "C'est de la POUDRE BAIE de qualité.\n"
	.string "Elle fera d'excellents médicaments.\p"
	.string "Veux-tu échanger plus de ta\n"
	.string "POUDRE BAIE contre autre chose ?$"

SlateportCity_Text_WhenYouGetMoreBringItToMe:
	.string "D'accord ! Quand tu auras plus de\n"
	.string "POUDRE BAIE, apporte-m'en, s'il te plaît !$"

SlateportCity_Text_ComeBackToTradeBerryPowder:
	.string "Reviens si tu veux échanger ta\n"
	.string "POUDRE BAIE contre des médicaments.\p"
	.string "Je tiens toujours un bazar ici.\p"
	.string "Tu le savais ?$"

SlateportCity_Text_YouDroveTeamAquaAway:
	.string "SCOTT : Hein ?\n"
	.string "Je suis sûr de t'avoir déjà vu quelque part.\p"
	.string "Je me suis déjà présenté ?\n"
	.string "Sinon, je m'appelle SCOTT.\p"
	.string "Je viens de voir la TEAM AQUA s'enfuir d'ici\n"
	.string "comme s'ils avaient été piqués.\p"
	.string "Laisse-moi deviner : c'est toi qui les as fait fuir ?$"

SlateportCity_Text_MaybeThisTrainer:
	.string "SCOTT : Hmm…\n"
	.string "Peut-être, juste peut-être, ce DRESSEUR…$"

SlateportCity_Text_LetsRegisterEachOther:
	.string "SCOTT : Très bien ! Je pense que tu vas\n"
	.string "devenir un bon ami.\p"
	.string "Alors, enregistrons-nous mutuellement dans nos\n"
	.string "POKéNAV.\p"
	.string "… … … … … …$"

SlateportCity_Text_RegisteredScott:
	.string "SCOTT a été enregistré\n"
	.string "dans le POKéNAV.$"

SlateportCity_Text_KeepEyeOnTrainersBeSeeingYou:
	.string "SCOTT : J'aimerais bien te suivre\n"
	.string "mais je veux aussi observer d'autres\l"
	.string "dresseurs talentueux.\p"
	.string "Je vais donc aller explorer d'autres villes\n"
	.string "encore un peu.\p"
	.string "À bientôt, {PLAYER}{KUN} !$"

SlateportCity_Text_TakingBattleTentChallenge:
	.string "SCOTT : Oh, salut !\n"
	.string "Mais c'est {PLAYER}{KUN} !\p"
	.string "{PLAYER}{KUN}, laisse-moi deviner : tu vas\n"
	.string "participer au DÔME DE COMBAT ?\p"
	.string "Oui ! C'est une bonne idée !\n"
	.string "C'est vraiment une excellente idée !\p"
	.string "Après tout, un DRESSEUR fort est\n"
	.string "parfait pour le DÔME DE COMBAT !\p"
	.string "Donne le meilleur de toi-même !$"
