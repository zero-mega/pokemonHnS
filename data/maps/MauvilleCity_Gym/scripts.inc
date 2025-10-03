MauvilleCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, MauvilleCity_Gym_OnLoad
	.byte 0

MauvilleCity_Gym_OnLoad:
	goto_if_set FLAG_DEFEATED_GOLDENROD_CITY_GYM, MauvilleCity_Gym_EventScript_DeactivatePuzzle
	switch VAR_GARBAGEVAR
	case 0, MauvilleCity_Gym_EventScript_UpdateBarriers
	case 1, MauvilleCity_Gym_EventScript_Switch1Pressed
	case 2, MauvilleCity_Gym_EventScript_Switch2Pressed
	case 3, MauvilleCity_Gym_EventScript_Switch3Pressed
	case 4, MauvilleCity_Gym_EventScript_Switch4Pressed
	end

MauvilleCity_Gym_EventScript_UpdateBarriers::
	goto_if_set FLAG_MAUVILLE_GYM_BARRIERS_STATE, MauvilleCity_Gym_EventScript_SetAltBarriers
	end

MauvilleCity_Gym_EventScript_SetAltBarriers::
	setmetatile 3, 11, METATILE_MauvilleGym_RedBeamV1_On, TRUE
	setmetatile 3, 12, METATILE_MauvilleGym_RedBeamV2_On, TRUE
	setmetatile 3, 13, METATILE_MauvilleGym_PoleTop_On, TRUE
	setmetatile 4, 10, METATILE_MauvilleGym_RedBeamH1_On, FALSE
	setmetatile 5, 10, METATILE_MauvilleGym_RedBeamH2_On, FALSE
	setmetatile 4, 11, METATILE_MauvilleGym_RedBeamH3_On, TRUE
	setmetatile 5, 11, METATILE_MauvilleGym_RedBeamH4_On, TRUE
	setmetatile 7, 10, METATILE_MauvilleGym_RedBeamH1_On, FALSE
	setmetatile 8, 10, METATILE_MauvilleGym_RedBeamH2_On, FALSE
	setmetatile 7, 11, METATILE_MauvilleGym_RedBeamH3_On, TRUE
	setmetatile 8, 11, METATILE_MauvilleGym_RedBeamH4_On, TRUE
	setmetatile 4, 13, METATILE_MauvilleGym_GreenBeamH1_Off, FALSE
	setmetatile 5, 13, METATILE_MauvilleGym_GreenBeamH2_Off, FALSE
	setmetatile 4, 14, METATILE_MauvilleGym_GreenBeamH3_Off, FALSE
	setmetatile 5, 14, METATILE_MauvilleGym_GreenBeamH4_Off, FALSE
	setmetatile 1, 10, METATILE_MauvilleGym_GreenBeamH1_Off, FALSE
	setmetatile 2, 10, METATILE_MauvilleGym_GreenBeamH2_Off, FALSE
	setmetatile 1, 11, METATILE_MauvilleGym_GreenBeamH3_Off, FALSE
	setmetatile 2, 11, METATILE_MauvilleGym_GreenBeamH4_Off, FALSE
	setmetatile 6, 8, METATILE_MauvilleGym_PoleBottom_On, TRUE
	setmetatile 6, 9, METATILE_MauvilleGym_FloorTile, FALSE
	setmetatile 6, 10, METATILE_MauvilleGym_PoleTop_Off, FALSE
	setmetatile 4, 6, METATILE_MauvilleGym_GreenBeamH1_Off, FALSE
	setmetatile 5, 6, METATILE_MauvilleGym_GreenBeamH2_Off, FALSE
	setmetatile 4, 7, METATILE_MauvilleGym_GreenBeamH3_Off, FALSE
	setmetatile 5, 7, METATILE_MauvilleGym_GreenBeamH4_Off, FALSE
	end

MauvilleCity_Gym_EventScript_Switch1Pressed::
	setvar VAR_0x8004, 0
	special MauvilleGymPressSwitch
	goto MauvilleCity_Gym_EventScript_UpdateBarriers
	end

MauvilleCity_Gym_EventScript_Switch2Pressed::
	setvar VAR_0x8004, 1
	special MauvilleGymPressSwitch
	goto MauvilleCity_Gym_EventScript_UpdateBarriers
	end

MauvilleCity_Gym_EventScript_Switch3Pressed::
	setvar VAR_0x8004, 2
	special MauvilleGymPressSwitch
	goto MauvilleCity_Gym_EventScript_UpdateBarriers
	end

MauvilleCity_Gym_EventScript_Switch4Pressed::
	setvar VAR_0x8004, 3
	special MauvilleGymPressSwitch
	goto MauvilleCity_Gym_EventScript_UpdateBarriers
	end

MauvilleCity_Gym_EventScript_DeactivatePuzzle::
	special MauvilleGymDeactivatePuzzle
	end

MauvilleCity_Gym_EventScript_Wattson::
	trainerbattle_single TRAINER_WATTSON_1, MauvilleCity_Gym_Text_WattsonIntro, MauvilleCity_Gym_Text_WattsonDefeat, MauvilleCity_Gym_EventScript_WattsonDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_Gym_EventScript_WattsonRematch
	goto_if_unset FLAG_RECEIVED_TM_SHOCK_WAVE, MauvilleCity_Gym_EventScript_GiveShockWave2
	goto_if_eq VAR_NEW_MAUVILLE_STATE, 2, MauvilleCity_Gym_EventScript_CompletedNewMauville
	msgbox MauvilleCity_Gym_Text_WattsonPostBattle, MSGBOX_DEFAULT
	release
	end

MauvilleCity_Gym_EventScript_WattsonDefeated::
	message MauvilleCity_Gym_Text_ReceivedDynamoBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox MauvilleCity_Gym_Text_ExplainDynamoBadgeTakeThis, MSGBOX_DEFAULT
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 3
	clearflag FLAG_GARBAGEFLAG
	setflag FLAG_DEFEATED_GOLDENROD_CITY_GYM
	setflag FLAG_BADGE03_GET
	addvar VAR_GARBAGEVAR, 1
	call_if_eq VAR_GARBAGEVAR, 6, Common_EventScript_ReadyPetalburgGymForBattle
	setvar VAR_0x8008, 3
	call Common_EventScript_SetGymTrainers
	special MauvilleGymDeactivatePuzzle
	special DrawWholeMapView
	playse SE_UNLOCK
	call MauvilleCity_Gym_EventScript_GiveShockWave
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox MauvilleCity_Gym_Text_RegisteredWattson, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_WATTSON_MATCH_CALL
	release
	end

MauvilleCity_Gym_EventScript_GiveShockWave2::
	giveitem ITEM_TM_SHOCK_WAVE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox MauvilleCity_Gym_Text_ExplainShockWave, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_SHOCK_WAVE
	release
	end

MauvilleCity_Gym_EventScript_GiveShockWave::
	giveitem ITEM_TM_SHOCK_WAVE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox MauvilleCity_Gym_Text_ExplainShockWave, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_SHOCK_WAVE
	return

MauvilleCity_Gym_EventScript_CompletedNewMauville::
	msgbox MauvilleCity_Gym_Text_WattsonGoForthAndEndeavor, MSGBOX_DEFAULT
	release
	end

MauvilleCity_Gym_EventScript_WattsonRematch::
	trainerbattle_rematch_double TRAINER_WATTSON_1, MauvilleCity_Gym_Text_WattsonPreRematch, MauvilleCity_Gym_Text_WattsonRematchDefeat, MauvilleCity_Gym_Text_WattsonRematchNeedTwoMons
	msgbox MauvilleCity_Gym_Text_WattsonPostRematch, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_Switch1::
	lockall
	goto_if_set FLAG_DEFEATED_GOLDENROD_CITY_GYM, MauvilleCity_Gym_EventScript_SwitchDoNothing
	goto_if_eq VAR_GARBAGEVAR, 1, MauvilleCity_Gym_EventScript_SwitchDoNothing
	setvar VAR_GARBAGEVAR, 1
	setvar VAR_0x8004, 0
	goto MauvilleCity_Gym_EventScript_PressFloorSwitch
	end

MauvilleCity_Gym_EventScript_Switch2::
	lockall
	goto_if_set FLAG_DEFEATED_GOLDENROD_CITY_GYM, MauvilleCity_Gym_EventScript_SwitchDoNothing
	goto_if_eq VAR_GARBAGEVAR, 2, MauvilleCity_Gym_EventScript_SwitchDoNothing
	setvar VAR_GARBAGEVAR, 2
	setvar VAR_0x8004, 1
	goto MauvilleCity_Gym_EventScript_PressFloorSwitch
	end

MauvilleCity_Gym_EventScript_Switch3::
	lockall
	goto_if_set FLAG_DEFEATED_GOLDENROD_CITY_GYM, MauvilleCity_Gym_EventScript_SwitchDoNothing
	goto_if_eq VAR_GARBAGEVAR, 3, MauvilleCity_Gym_EventScript_SwitchDoNothing
	setvar VAR_GARBAGEVAR, 3
	setvar VAR_0x8004, 2
	goto MauvilleCity_Gym_EventScript_PressFloorSwitch
	end

MauvilleCity_Gym_EventScript_Switch4::
	lockall
	goto_if_set FLAG_DEFEATED_GOLDENROD_CITY_GYM, MauvilleCity_Gym_EventScript_SwitchDoNothing
	goto_if_eq VAR_GARBAGEVAR, 4, MauvilleCity_Gym_EventScript_SwitchDoNothing
	setvar VAR_GARBAGEVAR, 4
	setvar VAR_0x8004, 3
	goto MauvilleCity_Gym_EventScript_PressFloorSwitch
	end

MauvilleCity_Gym_EventScript_PressFloorSwitch::
	special MauvilleGymSetDefaultBarriers
	special MauvilleGymPressSwitch
	special DrawWholeMapView
	playse SE_UNLOCK
	goto_if_set FLAG_MAUVILLE_GYM_BARRIERS_STATE, MauvilleCity_Gym_EventScript_ClearBarriersAltState
	goto_if_unset FLAG_MAUVILLE_GYM_BARRIERS_STATE, MauvilleCity_Gym_EventScript_SetBarriersAltState
	releaseall
	end

MauvilleCity_Gym_EventScript_SwitchDoNothing::
	releaseall
	end

MauvilleCity_Gym_EventScript_SetBarriersAltState::
	setflag FLAG_MAUVILLE_GYM_BARRIERS_STATE
	releaseall
	end

MauvilleCity_Gym_EventScript_ClearBarriersAltState::
	clearflag FLAG_MAUVILLE_GYM_BARRIERS_STATE
	releaseall
	end

MauvilleCity_Gym_EventScript_Kirk::
	trainerbattle_single TRAINER_KIRK, MauvilleCity_Gym_Text_KirkIntro, MauvilleCity_Gym_Text_KirkDefeat
	msgbox MauvilleCity_Gym_Text_KirkPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_Shawn::
	trainerbattle_single TRAINER_SHAWN, MauvilleCity_Gym_Text_ShawnIntro, MauvilleCity_Gym_Text_ShawnDefeat
	msgbox MauvilleCity_Gym_Text_ShawnPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_Ben::
	trainerbattle_single TRAINER_BEN, MauvilleCity_Gym_Text_BenIntro, MauvilleCity_Gym_Text_BenDefeat
	msgbox MauvilleCity_Gym_Text_BenPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_Vivian::
	trainerbattle_single TRAINER_VIVIAN, MauvilleCity_Gym_Text_VivianIntro, MauvilleCity_Gym_Text_VivianDefeat
	msgbox MauvilleCity_Gym_Text_VivianPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_Angelo::
	trainerbattle_single TRAINER_CARLENE, MauvilleCity_Gym_Text_AngeloIntro, MauvilleCity_Gym_Text_AngeloDefeat
	msgbox MauvilleCity_Gym_Text_AngeloPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_GOLDENROD_CITY_GYM, MauvilleCity_Gym_EventScript_GymGuidePostVictory
	msgbox MauvilleCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

MauvilleCity_Gym_EventScript_GymGuidePostVictory::
	msgbox MauvilleCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

MauvilleCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE03_GET, MauvilleCity_Gym_EventScript_GymStatueCertified
	goto MauvilleCity_Gym_EventScript_GymStatue
	end

MauvilleCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE03_GET, MauvilleCity_Gym_EventScript_GymStatueCertified
	goto MauvilleCity_Gym_EventScript_GymStatue
	end

MauvilleCity_Gym_EventScript_GymStatueCertified::
	msgbox MauvilleCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

MauvilleCity_Gym_EventScript_GymStatue::
	msgbox MauvilleCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

MauvilleCity_Gym_Text_GymGuideAdvice:
	.string "Salut, comment ça va, FUTUR CHAMPION\n"
	.string "{PLAYER} ?\p"
	.string "WATTSON, le CHAMPION de l'ARÈNE de\n"
	.string "MAUVILLE, utilise des POKéMON de type ÉLECTRIQUE.\p"
	.string "Si tu le défies avec des POKéMON de type EAU,\n"
	.string "il va les griller ! Bzzt !\p"
	.string "Et il a installé des portes contrôlées par\n"
	.string "interrupteur partout dans son ARÈNE ! Quel excentrique !\p"
	.string "Allez, fonce !$"

MauvilleCity_Gym_Text_GymGuidePostVictory:
	.string "Ouah, tu es électrisant !\n"
	.string "Tu as ouvert la porte avec ta puissance !$"

MauvilleCity_Gym_Text_KirkIntro:
	.string "Mon âme électrique va briser tes\n"
	.string "rêves en morceaux, whoa-yeahah !$"

MauvilleCity_Gym_Text_KirkDefeat:
	.string "C'était branché, survolté,\n"
	.string "électrique à fond, mec !$"

MauvilleCity_Gym_Text_KirkPostBattle:
	.string "POKéMON et rock, tout est une question de cœur,\n"
	.string "whoa-yeah !$"

MauvilleCity_Gym_Text_ShawnIntro:
	.string "Je me suis entraîné avec WATTSON !\n"
	.string "Il n'y a aucune chance que je perde facilement !$"

MauvilleCity_Gym_Text_ShawnDefeat:
	.string "Débranché et éteint…$"

MauvilleCity_Gym_Text_ShawnPostBattle:
	.string "WATTSON, notre CHAMPION D'ARÈNE, est là\n"
	.string "depuis très, très longtemps.\p"
	.string "Il combattait même avant que ton\n"
	.string "papa ne soit né, ce vieux coriace !$"

MauvilleCity_Gym_Text_BenIntro:
	.string "Cette ARÈNE a des énigmes !\n"
	.string "C'est pas amusant ?$"

MauvilleCity_Gym_Text_BenDefeat:
	.string "Ce n'est pas drôle de perdre…$"

MauvilleCity_Gym_Text_BenPostBattle:
	.string "WATTSON dit qu'il aime installer\n"
	.string "des petits pièges avec des interrupteurs.$"

MauvilleCity_Gym_Text_VivianIntro:
	.string "Avec mon charme et les attaques de mes POKéMON,\n"
	.string "tu vas être choqué !$"

MauvilleCity_Gym_Text_VivianDefeat:
	.string "Je suis choquée par ta puissance !$"

MauvilleCity_Gym_Text_VivianPostBattle:
	.string "J'ai entendu dire que MAUVILLE a été fondée\n"
	.string "par WATTSON.\p"
	.string "Il était DRESSEUR bien avant que nous\n"
	.string "ne devenions DRESSEURS.\l"
	.string "Il doit tout savoir !$"

MauvilleCity_Gym_Text_AngeloIntro:
	.string "J'adore les choses qui brillent !$"

MauvilleCity_Gym_Text_AngeloDefeat:
	.string "Oh…\n"
	.string "Mes yeux sont éblouis…$"

MauvilleCity_Gym_Text_AngeloPostBattle:
	.string "WATTSON de l'ARÈNE de MAUVILLE a un front\n"
	.string "brillant. Ça me rend heureux !$"

MauvilleCity_Gym_Text_WattsonIntro:
	.string "J'ai abandonné mes plans pour transformer\n"
	.string "la ville, oui.\p"
	.string "Alors, j'ai passé mon temps à créer\n"
	.string "des pièges à portes dans mon ARÈNE.\p"
	.string "Oh ? Que fais-tu ici ?\p"
	.string "Quoi ? Tu dis que tu as passé\n"
	.string "toutes mes portes piégées ?\p"
	.string "Wahahahah !\n"
	.string "Ça, c'est amusant !\p"
	.string "Alors, moi, WATTSON, le CHAMPION de\n"
	.string "l'ARÈNE de MAUVILLE, vais t'électriser !$"

MauvilleCity_Gym_Text_WattsonDefeat:
	.string "Wahahahah !\n"
	.string "Bon, j'ai perdu !\p"
	.string "Tu m'as vraiment donné des sensations !\n"
	.string "Prends ce BADGE !$"

MauvilleCity_Gym_Text_ReceivedDynamoBadge:
	.string "{PLAYER} reçoit le BADGE DYNAMO\n"
	.string "de WATTSON.$"

MauvilleCity_Gym_Text_ExplainDynamoBadgeTakeThis:
	.string "Avec le BADGE DYNAMO, tes POKéMON peuvent\n"
	.string "utiliser ÉCLATE-ROC hors combat.\p"
	.string "Et ça rendra aussi tes POKéMON un peu\n"
	.string "plus rapides.\p"
	.string "Hmm…\n"
	.string "Tu devrais prendre ça aussi !$"

MauvilleCity_Gym_Text_ExplainShockWave:
	.string "La CT34 là contient ONDE DE CHOC.\p"
	.string "C'est une attaque fiable qui ne rate jamais !\n"
	.string "Tu peux compter dessus !\p"
	.string "… … … … … …$"

MauvilleCity_Gym_Text_RegisteredWattson:
	.string "CHAMPION D'ARÈNE WATTSON enregistré\n"
	.string "dans le POKéNAV.$"

MauvilleCity_Gym_Text_WattsonPostBattle:
	.string "Je déborde d'optimisme en voyant un jeune\n"
	.string "DRESSEUR prometteur comme toi !$"

MauvilleCity_Gym_Text_WattsonGoForthAndEndeavor:
	.string "Wahahahah !\n"
	.string "Va de l'avant et persévère, jeune !$"

MauvilleCity_Gym_Text_GymStatue:
	.string "ARÈNE POKéMON DE MAUVILLE$"

MauvilleCity_Gym_Text_GymStatueCertified:
	.string "ARÈNE POKéMON DE MAUVILLE\p"
	.string "DRESSEURS CERTIFIÉS PAR WATTSON :\n"
	.string "{PLAYER}$"

MauvilleCity_Gym_Text_WattsonPreRematch:
	.string "WATTSON : Ah-ha ! Enfin te voilà !\n"
	.string "Je sais ce que tu veux.\l"
	.string "Tu veux combattre mes POKéMON !\p"
	.string "Wahahahaha !\p"
	.string "Je vais faire jaillir des étincelles de toi !\n"
	.string "Ne dis pas que je ne t'ai pas prévenu !$"

MauvilleCity_Gym_Text_WattsonRematchDefeat:
	.string "Ouf…\n"
	.string "Nos batteries sont à plat…$"

MauvilleCity_Gym_Text_WattsonPostRematch:
	.string "WATTSON : Nous devrons recharger nos\n"
	.string "batteries à nouveau.\p"
	.string "Quand nous serons à bloc, nous accepterons\n"
	.string "volontiers ton défi.\p"
	.string "Alors, reviens nous voir un de ces jours,\n"
	.string "d'accord ?$"

MauvilleCity_Gym_Text_WattsonRematchNeedTwoMons:
	.string "WATTSON : Ah-ha ! Enfin te voilà !\n"
	.string "Je sais ce que tu veux.\l"
	.string "Tu veux combattre mes POKéMON !\p"
	.string "Wahahahaha !\p"
	.string "Oups ! Attends !\n"
	.string "Tu n'as qu'un seul POKéMON avec toi !\p"
	.string "Reviens me voir avec deux POKéMON ou plus,\n"
	.string "d'accord ?$"
