.set LOCALID_ATTENDANT, 1
.set LOCALID_NURSE, 2
.set LOCALID_GIRL, 4
.set LOCALID_MAN, 5

TrainerHill_Entrance_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, TrainerHill_Entrance_OnResume
	map_script MAP_SCRIPT_ON_RETURN_TO_FIELD, TrainerHill_Entrance_OnReturn
	map_script MAP_SCRIPT_ON_TRANSITION, TrainerHill_Entrance_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, TrainerHill_Entrance_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, TrainerHill_Entrance_OnFrame
	.byte 0

TrainerHill_Entrance_OnTransition:
	setflag FLAG_LANDMARK_TRAINER_HILL
	getplayerxy VAR_TEMP_D, VAR_RESULT
	end

@ Unused
TrainerHill_Entrance_OnWarp:
	end

TrainerHill_Entrance_OnResume:
	trainerhill_resumetimer
	setvar VAR_TEMP_0, 0
	trainerhill_getusingereader
	goto_if_eq VAR_RESULT, FALSE, TrainerHill_Entrance_EventScript_TryFaceAttendant  @ VAR_RESULT always FALSE here
	setobjectxy OBJ_EVENT_ID_PLAYER, 9, 6
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
	end

TrainerHill_Entrance_EventScript_TryFaceAttendant::
	trainerhill_getwon
	goto_if_eq VAR_RESULT, TRUE, TrainerHill_Entrance_EventScript_PlayerDontFaceAttendant
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
	end

TrainerHill_Entrance_EventScript_PlayerDontFaceAttendant::
	end

TrainerHill_Entrance_OnReturn:
	addobject LOCALID_NURSE
	addobject LOCALID_ATTENDANT
	addobject LOCALID_MAN
	addobject LOCALID_GIRL
	end

TrainerHill_Entrance_OnLoad:
	setflag FLAG_LIMIT_TO_50
	calculatemonstats
	call_if_eq VAR_TEMP_D, 17, TrainerHill_Entrance_EventScript_OpenCounterDoor
	end

TrainerHill_Entrance_EventScript_OpenCounterDoor::
	setmetatile 17, 10, METATILE_TrainerHill_GreenFloorTile, FALSE
	return

TrainerHill_Entrance_OnFrame:
	map_script_2 VAR_TEMP_0, 0, TrainerHill_Entrance_EventScript_ExitChallenge
	map_script_2 VAR_TEMP_D, 17, TrainerHill_Entrance_EventScript_ExitElevator
	map_script_2 VAR_TEMP_5, 1, TrainerHill_Entrance_EventScript_EntryTrigger
	map_script_2 VAR_TEMP_1, 1, TrainerHill_EventScript_WarpToEntranceCounter
	.2byte 0

TrainerHill_Entrance_EventScript_ExitElevator::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Entrance_Movement_PlayerExitElevator
	waitmovement 0
	setmetatile 17, 10, METATILE_TrainerHill_CounterDoor, TRUE
	special DrawWholeMapView
	playse SE_CLICK
	waitse
	setvar VAR_TEMP_D, 0
	releaseall
	end

TrainerHill_Entrance_EventScript_ExitChallenge::
	setvar VAR_TEMP_0, 1
	trainerhill_getstatus
	switch VAR_RESULT
	case TRAINER_HILL_PLAYER_STATUS_LOST, TrainerHill_Entrance_EventScript_ExitChallengeLost
	case TRAINER_HILL_PLAYER_STATUS_ECARD_SCANNED, TrainerHill_Entrance_EventScript_ExitChallengeECard
	case TRAINER_HILL_PLAYER_STATUS_NORMAL, TrainerHill_Entrance_EventScript_EndExitChallenge

TrainerHill_Entrance_EventScript_ExitChallengeLost::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
	msgbox TrainerHill_Entrance_Text_TooBadTremendousEffort, MSGBOX_DEFAULT
	goto TrainerHill_Entrance_EventScript_PlayerExitChallenge

TrainerHill_Entrance_EventScript_ExitChallengeECard::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
	msgbox TrainerHill_Entrance_Text_MovedReceptionHereForSwitch, MSGBOX_DEFAULT
TrainerHill_Entrance_EventScript_PlayerExitChallenge::
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Entrance_Movement_PushPlayerBackFromCounter
	waitmovement 0
	setvar VAR_TRAINER_HILL_IS_ACTIVE, 0
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	releaseall
TrainerHill_Entrance_EventScript_EndExitChallenge::
	end

TrainerHill_Entrance_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

TrainerHill_Entrance_EventScript_Attendant::
	lock
	faceplayer
	trainerhill_inchallenge
	goto_if_eq VAR_RESULT, FALSE, TrainerHill_Entrance_EventScript_ThanksForPlaying
	msgbox TrainerHill_Entrance_Text_HopeYouGiveItYourBest, MSGBOX_DEFAULT
	goto TrainerHill_Entrance_EventScript_AttendantEnd

TrainerHill_Entrance_EventScript_ThanksForPlaying::
	msgbox TrainerHill_Entrance_Text_ThankYouForPlaying, MSGBOX_DEFAULT
TrainerHill_Entrance_EventScript_AttendantEnd::
	release
	end

TrainerHill_Entrance_EventScript_EntryTrigger::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
	goto_if_unset FLAG_SYS_GAME_CLEAR, TrainerHill_Entrance_EventScript_Closed
	msgbox TrainerHill_Entrance_Text_WelcomeToTrainerHill, MSGBOX_DEFAULT
	trainerhill_getsaved
	call_if_eq VAR_RESULT, FALSE, TrainerHill_Entrance_EventScript_SaveGame
	trainerhill_allfloorsused
	goto_if_eq VAR_RESULT, TRUE, TrainerHill_Entrance_EventScript_AllFloorsUsed
	msgbox TrainerHill_Entrance_Text_TrainersUpToFloorX, MSGBOX_DEFAULT
	goto TrainerHill_Entrance_EventScript_AskChallengeTrainers

TrainerHill_Entrance_EventScript_AllFloorsUsed::
	msgbox TrainerHill_Entrance_Text_TrainersInEveryRoom, MSGBOX_DEFAULT
TrainerHill_Entrance_EventScript_AskChallengeTrainers::
	message TrainerHill_Entrance_Text_LikeToChallengeTrainers
	waitmessage
	multichoice 15, 6, MULTI_YESNOINFO, FALSE
	switch VAR_RESULT
	case 0, TrainerHill_Entrance_EventScript_ChooseChallenge
	case 1, TrainerHill_Entrance_EventScript_CancelEntry
	case 2, TrainerHill_Entrance_EventScript_Info
	case MULTI_B_PRESSED, TrainerHill_Entrance_EventScript_CancelEntry
	end

TrainerHill_Entrance_EventScript_Info::
	msgbox TrainerHill_Entrance_Text_ExplainTrainerHill, MSGBOX_DEFAULT
	goto TrainerHill_Entrance_EventScript_AskChallengeTrainers
	end

TrainerHill_Entrance_EventScript_ChooseChallenge::
	multichoice 13, 2, MULTI_TAG_MATCH_TYPE, FALSE
	switch VAR_RESULT
	case 4, TrainerHill_Entrance_EventScript_CancelEntry
	case MULTI_B_PRESSED, TrainerHill_Entrance_EventScript_CancelEntry
	trainerhill_setmode VAR_RESULT
	setvar VAR_TRAINER_HILL_IS_ACTIVE, 1
	setvar VAR_TEMP_5, 0
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	msgbox TrainerHill_Entrance_Text_TimeProgessGetSetGo, MSGBOX_DEFAULT
	trainerhill_start
	releaseall
	end

TrainerHill_Entrance_EventScript_CancelEntry::
	setvar VAR_TEMP_5, 0
	msgbox TrainerHill_Entrance_Text_PleaseVisitUsAgain, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Entrance_Movement_PushPlayerBackFromCounter
	waitmovement 0
	releaseall
	end

TrainerHill_Entrance_EventScript_SaveGame::
	msgbox TrainerHill_Entrance_Text_SaveGameBeforeEnter, MSGBOX_DEFAULT
	trainerhill_setsaved
	setvar VAR_TEMP_5, 1
	call Common_EventScript_SaveGame
	goto_if_eq VAR_RESULT, FALSE, TrainerHill_Entrance_EventScript_SaveFailed
	trainerhill_setsaved
	return

TrainerHill_Entrance_EventScript_SaveFailed::
	trainerhill_clearsaved
	goto TrainerHill_Entrance_EventScript_CancelEntry
	end

TrainerHill_Entrance_EventScript_Closed::
	msgbox TrainerHill_Entrance_Text_StillGettingReady, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, TrainerHill_Entrance_Movement_PushPlayerBackFromCounter
	waitmovement 0
	releaseall
	end

TrainerHill_Entrance_Movement_PlayerFaceAttendant:
	face_right
	step_end

TrainerHill_Entrance_Movement_PushPlayerBackFromCounter:
	walk_down
	step_end

@ Unused
TrainerHill_Entrance_Movement_FaceUp:
	face_up
	step_end

TrainerHill_Entrance_Movement_PlayerExitElevator:
	walk_down
	walk_down
	step_end

TrainerHill_Entrance_EventScript_Records::
	lockall
	fadescreen FADE_TO_BLACK
	special ShowTrainerHillRecords
	waitstate
	releaseall
	end

TrainerHill_Entrance_EventScript_Man::
	goto_if_unset FLAG_SYS_GAME_CLEAR, TrainerHill_Entrance_EventScript_ManTrainerHillClosed
	msgbox TrainerHill_Entrance_Text_WhatSortOfTrainersAreAhead, MSGBOX_NPC
	end

TrainerHill_Entrance_EventScript_ManTrainerHillClosed::
	msgbox TrainerHill_Entrance_Text_CantWaitToTestTheWaters, MSGBOX_NPC
	end

TrainerHill_Entrance_EventScript_Girl::
	goto_if_unset FLAG_SYS_GAME_CLEAR, TrainerHill_Entrance_EventScript_GirlTrainerHillClosed
	msgbox TrainerHill_Entrance_Text_FriendsTryingToReachTimeBoardTop, MSGBOX_NPC
	end

TrainerHill_Entrance_EventScript_GirlTrainerHillClosed::
	msgbox TrainerHill_Entrance_Text_DoYouKnowWhenTheyOpen, MSGBOX_NPC
	end

TrainerHill_Entrance_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	@goto_if_set FLAG_SYS_GAME_CLEAR, TrainerHill_Entrance_EventScript_ExpandedPokemart
	pokemart TrainerHill_Entrance_Pokemart_Basic
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

TrainerHill_Entrance_EventScript_Clerk2::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart 0
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
TrainerHill_Entrance_Pokemart_Basic:
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_SPECIAL
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFEND
	.2byte ITEM_DIRE_HIT
	.2byte ITEM_GUARD_SPEC
	.2byte ITEM_X_ACCURACY
	.2byte ITEM_NONE
	release
	end

@TrainerHill_Entrance_EventScript_ExpandedPokemart::
@	pokemart TrainerHill_Entrance_Pokemart_Expanded
@	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
@	release
@	end
@
@	.align 2
@TrainerHill_Entrance_Pokemart_Expanded:
@	.2byte ITEM_X_SPEED
@	.2byte ITEM_X_SPECIAL
@	.2byte ITEM_X_ATTACK
@	.2byte ITEM_X_DEFEND
@	.2byte ITEM_DIRE_HIT
@	.2byte ITEM_GUARD_SPEC
@	.2byte ITEM_X_ACCURACY
@	.2byte ITEM_NONE
@	release
@	end

TrainerHill_Entrance_Text_StillGettingReady:
	.string "Bienvenue à la TOUR DRESSEUR où\n"
	.string "vous pouvez participer à des combats\l"
	.string "en duo contre de nombreux DRESSEURS.\p"
	.string "Malheureusement, nous sommes encore\n"
	.string "en train de tout préparer. Revenez plus tard !$"

TrainerHill_Entrance_Text_WelcomeToTrainerHill:
	.string "Bienvenue !\p"
	.string "Ici, à la TOUR DRESSEUR, vous pouvez\n"
	.string "participer à des combats en duo contre\l"
	.string "de nombreux DRESSEURS !$"

TrainerHill_Entrance_Text_SaveGameBeforeEnter:
	.string "C'est votre première visite ici ?\p"
	.string "Avant d'entrer, veuillez sauvegarder\n"
	.string "votre partie.$"

TrainerHill_Entrance_Text_TrainersUpToFloorX:
	.string "Voyons voir…\n"
	.string "Les DRESSEURS présents sont…\p"
	.string "Jusqu'à l'étage n° {STR_VAR_1}.$"

TrainerHill_Entrance_Text_TrainersInEveryRoom:
	.string "Voyons voir…\n"
	.string "Les DRESSEURS présents sont…\p"
	.string "Il semble qu'il y ait des DRESSEURS\n"
	.string "dans chaque salle.$"

TrainerHill_Entrance_Text_LikeToChallengeTrainers:
	.string "Voulez-vous défier les DRESSEURS\n"
	.string "qui vous attendent ?$"

TrainerHill_Entrance_Text_TimeProgessGetSetGo:
	.string "Je vais chronométrer votre progression.\n"
	.string "Bonne chance !\p"
	.string "À vos marques…\p"
	.string "Prêts…\p"
	.string "Partez !$"

TrainerHill_Entrance_Text_PleaseVisitUsAgain:
	.string "Revenez nous voir !$"

TrainerHill_Entrance_Text_TooBadTremendousEffort:
	.string "Dommage…\p"
	.string "Je pense que vous avez fourni un effort\n"
	.string "remarquable lors de vos combats.\p"
	.string "Revenez essayer à nouveau !$"

TrainerHill_Entrance_Text_HopeYouGiveItYourBest:
	.string "J'espère que vous donnerez le meilleur de vous-même.$"

TrainerHill_Entrance_Text_MovedReceptionHereForSwitch:
	.string "Quand les DRESSEURS changent de place,\n"
	.string "cela peut devenir mouvementé.\p"
	.string "Pour éviter la cohue, nous avons déplacé\n"
	.string "le comptoir d'accueil ici.\p"
	.string "Désolé pour la gêne occasionnée.$"

TrainerHill_Entrance_Text_ThankYouForPlaying:
	.string "Merci d'avoir joué !$"

TrainerHill_Entrance_Text_ExplainTrainerHill:
	.string "Ici, à la TOUR DRESSEUR, nous organisons\n"
	.string "un événement appelé le Time Attack.\p"
	.string "C'est une course où l'on mesure le temps\n"
	.string "que vous mettez pour atteindre notre chef\l"
	.string "sur le toit depuis ce comptoir.\p"
	.string "Les meilleurs temps sont affichés sur\n"
	.string "le Tableau des Temps—essayez de battre\l"
	.string "vos amis.\p"
	.string "Dans les combats contre les DRESSEURS,\n"
	.string "ni Points Exp. ni argent ne seront\l"
	.string "attribués.$"

@ Unused
TrainerHill_Entrance_Text_NeedAtLeastTwoPokemon:
	.string "Oh, désolé, mais il semble que vous n'ayez\n"
	.string "qu'un seul POKéMON avec vous.\p"
	.string "Il vous faut au moins deux POKéMON\n"
	.string "pour participer à cet événement.$"

TrainerHill_Roof_Text_YouFinallyCameBravo:
	.string "Hm ! Hm !\p"
	.string "Vous êtes enfin arrivé !\n"
	.string "Oui, vous êtes là !\p"
	.string "Attendez ! Ne dites rien !\n"
	.string "Je sais pourquoi vous êtes venu\l"
	.string "jusqu'ici tout seul !\p"
	.string "Vous vouliez me voir, moi, le propriétaire\n"
	.string "de la TOUR DRESSEUR, parce que…\p"
	.string "Vous voulez former une équipe avec moi !\n"
	.string "Wa-hou !\p"
	.string "…Hein ?\n"
	.string "Ce n'est pas ça ?\p"
	.string "En tout cas, je vous ai observé pendant votre ascension.\n"
	.string "Des combats splendides ! Bravo, vraiment !$"

TrainerHill_Roof_Text_HaveTheMostMarvelousGift:
	.string "Pour quelqu'un d'aussi formidable que vous,\n"
	.string "j'ai le plus merveilleux des cadeaux !$"

TrainerHill_Roof_Text_FullUpBeBackLaterForThis:
	.string "Oh non, votre sac est plein !\n"
	.string "Revenez plus tard pour ceci !$"

TrainerHill_Roof_Text_GotHereMarvelouslyQuickly:
	.string "Oh, attendez ! Serait-il possible que vous soyez\n"
	.string "arrivé ici incroyablement vite ?\p"
	.string "Splendide ! Vous n'aviez pas besoin de\n"
	.string "vous presser autant pour me voir !\p"
	.string "C'est fantastique. Je vais faire mettre à jour\n"
	.string "le Tableau des Temps à l'accueil !$"

TrainerHill_Roof_Text_YouWerentVeryQuick:
	.string "Mais, oh…\n"
	.string "Vous n'avez pas été très rapide pour arriver ici.$"

TrainerHill_Roof_Text_ArriveZippierNextTime:
	.string "Peut-être que cela me plairait davantage si vous\n"
	.string "arriviez plus vite la prochaine fois.\p"
	.string "Alors, je serais ravi de former\n"
	.string "une équipe avec vous !\p"
	.string "À la prochaine, amigo !$"

@ Unused
TrainerHill_Roof_Text_BuiltTrainerHillToFindPartner:
	.string "J'ai fait construire la TOUR DRESSEUR pour une\n"
	.string "seule et unique raison !\p"
	.string "Trouver le partenaire idéal avec qui\n"
	.string "former une équipe !$"

TrainerHill_Entrance_Text_ChallengeTime:
	.string "{STR_VAR_1} min. {STR_VAR_2}.{STR_VAR_3} sec.$"

TrainerHill_Entrance_Text_WhatSortOfTrainersAreAhead:
	.string "Qui sait quels types de DRESSEURS\n"
	.string "et de duos de POKéMON vous attendent ?\p"
	.string "Tout ce que je sais, c'est que j'écarterai\n"
	.string "quiconque se mettra en travers de mon chemin !$"

TrainerHill_Entrance_Text_CantWaitToTestTheWaters:
	.string "J'ai entendu dire que des DRESSEURS puissants\n"
	.string "viennent à cette TOUR DRESSEUR de partout.\p"
	.string "J'ai hâte de me mesurer à eux !\p"
	.string "J'écarterai quiconque se mettra\n"
	.string "en travers de mon chemin !$"

TrainerHill_Entrance_Text_FriendsTryingToReachTimeBoardTop:
	.string "Vous voyez le Tableau des Temps là-bas ?\p"
	.string "Mes amis et moi essayons de voir qui\n"
	.string "peut atteindre le sommet le plus rapidement.$"

TrainerHill_Entrance_Text_DoYouKnowWhenTheyOpen:
	.string "Savez-vous quand ce lieu va ouvrir ?\p"
	.string "J'attends ici pour être le tout premier\n"
	.string "challenger !$"

TrainerHill_Elevator_Text_ReturnToReception:
	.string "Voulez-vous retourner au\n"
	.string "comptoir d'accueil ?$"
