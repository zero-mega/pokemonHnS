.set LOCALID_CERULEAN_GYM_ROCKET, 5

CeruleanCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CeruleanCity_Gym_OnFrame
	.byte 0

CeruleanCity_Gym_OnFrame::
	map_script_2 VAR_KANTO_ROCKET_STORY_STATE, 2,  CeruleanCity_Gym_EventScript_RocketGrunt
	map_script_2 VAR_TEMP_0, 0,  CeruleanCity_Gym_EventScript_TryMachinePart
	.2byte 0

CeruleanCity_Gym_EventScript_RocketGrunt::
	lock
	applymovement LOCALID_CERULEAN_GYM_ROCKET, CeruleanCity_Gym_Movement_GruntBumpPlayer
	delay 20
	playse SE_BANG
	waitmovement 0
	
	msgbox CeruleanGym_Text_GruntIntro, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_CERULEAN_GYM_ROCKET, Common_Movement_ExclamationMark
	delay 60
	applymovement LOCALID_CERULEAN_GYM_ROCKET, CeruleanCity_Gym_Movement_GruntWalkBack
	waitmovement 0
	msgbox CeruleanGym_Text_GruntBigMistake, MSGBOX_DEFAULT
	applymovement LOCALID_CERULEAN_GYM_ROCKET, CeruleanCity_Gym_Movement_GruntWalkToPlayerAgain
	waitmovement 0
	msgbox CeruleanGym_Text_GruntBye, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, CeruleanCity_Gym_Movement_PlayerSlide
	delay 10
	applymovement LOCALID_CERULEAN_GYM_ROCKET, CeruleanCity_Gym_Movement_GruntLeave
	waitmovement 0
	fadescreenswapbuffers FADE_TO_BLACK
	playse SE_EXIT
	setflag FLAG_HIDE_CERULEAN_GYM_ROCKET
	removeobject LOCALID_CERULEAN_GYM_ROCKET
	fadescreenswapbuffers FADE_FROM_BLACK
	clearflag FLAG_HIDE_CERULEAN_CAPE_ROCKET
	setvar VAR_KANTO_ROCKET_STORY_STATE, 3
	release
	end

CeruleanCity_Gym_EventScript_TryMachinePart::
	goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 5, CeruleanCity_Gym_EventScript_MachinePart
	setvar VAR_TEMP_0, 1
	end

CeruleanCity_Gym_EventScript_MachinePart::
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, CeruleanCity_Movement_CameraPanUp
	waitmovement 0
	delay 30
	setvar VAR_0x8004, 5  @ x
	setvar VAR_0x8005, 13  @ y
	playse SE_PIN
	call Route110_TrickHouseEntrance_EventScript_DoHidingSpotSparkle
	delay 55
	applymovement OBJ_EVENT_ID_CAMERA, CeruleanCity_Movement_CameraPanDown
	waitmovement 0
	special RemoveCameraObject
	setvar VAR_TEMP_0, 1
	end

CeruleanCity_Gym_EventScript_MachinePartItem::
	goto_if_lt VAR_KANTO_ROCKET_STORY_STATE, 5, CeruleanCity_Gym_EventScript_DoNothing
	goto_if_ge VAR_KANTO_ROCKET_STORY_STATE, 6, CeruleanCity_Gym_EventScript_DoNothing
	finditem ITEM_MACHINE_PART
	setvar VAR_KANTO_ROCKET_STORY_STATE, 6
	setflag FLAG_HIDDEN_ITEM_MACHINE_PART
	end

CeruleanCity_Gym_EventScript_DoNothing::
	end

CeruleanCity_Movement_CameraPanUp:
	walk_up
	walk_up
	walk_up
	step_end

CeruleanCity_Movement_CameraPanDown:
	walk_down
	walk_down
	walk_down
	step_end

CeruleanCity_Gym_Movement_GruntBumpPlayer:
	walk_fast_down
	walk_fast_down
	walk_in_place_fast_down
	lock_facing_direction
	jump_up
	unlock_facing_direction
	delay_16
	walk_down
	step_end

CeruleanCity_Gym_Movement_GruntWalkBack:
	lock_facing_direction
	walk_slow_up
	walk_slow_up
	unlock_facing_direction
	step_end

CeruleanCity_Gym_Movement_GruntWalkToPlayerAgain:
	walk_down
	walk_down
	step_end

CeruleanCity_Gym_Movement_PlayerSlide:
	lock_facing_direction
	walk_fast_right
	unlock_facing_direction
	step_end

CeruleanCity_Gym_Movement_GruntLeave:
	walk_fast_down
	walk_in_place_fast_down
	step_end

CeruleanCity_Gym_EventScript_Statue::
	lockall
	goto_if_set FLAG_BADGE10_GET, CeruleanCity_Gym_EventScript_GymStatuePostVictory
	msgbox CeruleanCity_Gym_Text_GymStatue
	releaseall
	end

CeruleanCity_Gym_EventScript_StatueDuringRocket::
	msgbox CeruleanGym_Text_Note, MSGBOX_SIGN
	end 

CeruleanCity_Gym_EventScript_GymStatuePostVictory::
	msgbox CeruleanCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end

CeruleanGym_EventScript_Diana::
	trainerbattle_single TRAINER_DIANA CeruleanGym_Text_SwimmerfDianaSeen, CeruleanGym_Text_SwimmerfDianaBeaten
	msgbox CeruleanGym_Text_SwimmerfDianaAfter, MSGBOX_AUTOCLOSE
	end

CeruleanGym_EventScript_Briana::
	trainerbattle_single TRAINER_BRIANA CeruleanGym_Text_SwimmerfBrianaSeen, CeruleanGym_Text_SwimmerfBrianaBeaten
	msgbox CeruleanGym_Text_SwimmerfBrianaAfter, MSGBOX_AUTOCLOSE
	end

CeruleanGym_EventScript_Parker::
	trainerbattle_single TRAINER_PARKER CeruleanGym_Text_SwimmermParkerSeen, CeruleanGym_Text_SwimmermParkerBeaten
	msgbox CeruleanGym_Text_SwimmermParkerAfter, MSGBOX_AUTOCLOSE
	end

CeruleanCity_Gym_EventScript_GymGuy::
	goto_if_set FLAG_DEFEATED_CERULEAN_GYM, CeruleanCity_Gym_EventScript_GymGuyAfter
	msgbox CeruleanGym_Text_GuideIntro, MSGBOX_NPC
	end

CeruleanCity_Gym_EventScript_GymGuyAfter::
	msgbox CeruleanGym_Text_GuideWin, MSGBOX_NPC
	end

CeruleanCity_Gym_Text_GymStatue::
    .string "ARÈNE POKéMON D'AZURIA\n"
    .string "CHAMPIONNE : ONDINE\p"
	.string "DRESSEURS VAINQUEURS :\n"
	.string "BLUE, RED$"

CeruleanCity_Gym_Text_GymStatuePlayerWon::
    .string "ARÈNE POKÉMON D'AZURIA\n"
    .string "CHAMPIONNE : ONDINE\p"
    .string "DRESSEURS VAINQUEURS :\n"
	.string "BLUE, RED, {PLAYER}$"

CeruleanGym_Text_Note:
	.string "Désolée, je serai absente un moment.\n"
	.string "ONDINE, CHAMPIONNE DE L'ARÈNE\p"
	.string "Puisqu'ONDINE est partie, nous\n"
	.string "partons aussi.\l"
	.string "DRESSEURS DE L'ARÈNE$"


CeruleanCity_Gym_EventScript_Misty::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_CERULEAN_GYM, CeruleanCity_Gym_EventScript_Misty_Defeated
	msgbox CeruleanGym_Text_MistyIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_MISTY, CeruleanGym_Text_MistyWinLoss
	message CeruleanGym_Text_ReceivedBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	setflag FLAG_BADGE10_GET
	setflag FLAG_DEFEATED_CERULEAN_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 10
	call Common_EventScript_SetGymTrainers
	msgbox CeruleanGym_Text_MistyTm, MSGBOX_DEFAULT
	giveitem ITEM_TM_WATER_PULSE
	clearflag FLAG_HIDE_CAPE_MISTY
	call_if_eq VAR_SUICUNE_ENCOUNTERS, 5, CeruleanCity_Gym_SetSuicuneScene
	closemessage
	release
	end

CeruleanCity_Gym_SetSuicuneScene::
	setvar VAR_SUICUNE_ENCOUNTERS, 6
	clearflag FLAG_HIDE_ROUTE25_SUICUNE
	return

CeruleanCity_Gym_EventScript_Misty_Defeated::
	msgbox CeruleanGym_Text_MistyFightDone, MSGBOX_DEFAULT
	closemessage
	release
	end

CeruleanGym_Text_GruntIntro:
	.string "Oups ! Je suis désolé ! Tu n'es pas blessé,\n"
	.string "ça va ?\p"
	.string "Je suis très occupé. Pas le temps de parler\n"
	.string "avec toi. Pas bon pour moi si\l"
	.string "quelqu'un me voit.$"

CeruleanGym_Text_GruntBigMistake:
	.string "Oh non ! Tu m'as déjà vu !\n"
	.string "J'ai fait une grosse erreur !$"

CeruleanGym_Text_GruntBye:
	.string "Hé, toi ! Oublie que tu m'as vu,\n"
	.string "d'accord ?\p"
	.string "Tu n'as rien vu, rien entendu, rien su,\p"
	.string "d'accord ? Salut, gamin ! Rien !\p"
	.string "Bye-bye a go-go !$"

CeruleanGym_Text_Note1:
	.string "Désolée, je serai absente un moment.\n"
	.string "ONDINE, CHAMPIONNE DE L'ARÈNE\p"
	.string "Puisqu'ONDINE est partie, nous partons\n"
	.string "aussi. DRESSEURS DE L'ARÈNE$"

CeruleanGym_Text_MistyIntro:
	.string "ONDINE : Je t'attendais, sale\n"
	.string "canaille !\p"
	.string "Tu as peut-être beaucoup de BADGES\n"
	.string "d'arène de JOHTO, mais tu ferais mieux\l"
	.string "de ne pas me sous-estimer.\p"
	.string "Mes POKéMON de type EAU sont\n"
	.string "costauds !$"

CeruleanGym_Text_MistyWinLoss:
	.string "ONDINE : Tu es vraiment fort…\p"
	.string "J'admets que tu es doué…\p"
	.string "Tiens, voilà. C'est le BADGE CASCADE.$"

CeruleanGym_Text_ReceivedBadge:
	.string "{PLAYER} reçoit le BADGE CASCADE.$"

CeruleanGym_Text_MistyFightDone:
	.string "ONDINE : Y a-t-il beaucoup de\n"
	.string "dresseurs forts à JOHTO ? Comme toi,\l"
	.string "je veux dire.\p"
	.string "Un jour, je voyagerai pour pouvoir\n"
	.string "affronter des dresseurs talentueux.$"

CeruleanGym_Text_MistyRematch:
	.string "ONDINE : Waouh, tu es le CHAMPION\n"
	.string "de KANTO maintenant !\p"
	.string "C'est incroyable ! Tu as fait un\n"
	.string "sacré chemin, {PLAYER}.\p"
	.string "Mais je ne vais pas abandonner.\p"
	.string "Tu veux refaire un combat contre moi ?$"

CeruleanGym_Text_MistyRematchDefeat:
	.string "ONDINE : Tu es vraiment fort…$"

CeruleanGym_Text_SwimmerfDianaSeen:
	.string "Désolée d'avoir été absente. On peut\n"
	.string "commencer !$"

CeruleanGym_Text_SwimmerfDianaBeaten:
	.string "J'abandonne ! Tu as gagné !$"

CeruleanGym_Text_SwimmerfDianaAfter:
	.string "Je vais nager tranquillement.$"

CeruleanGym_Text_SwimmerfBrianaSeen:
	.string "Ne te laisse pas impressionner par\n"
	.string "ma nage élégante.$"

CeruleanGym_Text_SwimmerfBrianaBeaten:
	.string "Ooh, tu t'es débarrassé de moi calmement…$"

CeruleanGym_Text_SwimmerfBrianaAfter:
	.string "Ne sois pas trop fier de m'avoir battue.\p"
	.string "ONDINE te détruira si tu deviens\n"
	.string "trop confiant.$"

CeruleanGym_Text_SwimmermParkerSeen:
	.string "Glou…\p"
	.string "Je suis le premier ! Viens m'affronter !$"

CeruleanGym_Text_SwimmermParkerBeaten:
	.string "Ce n'est pas possible…$"

CeruleanGym_Text_SwimmermParkerAfter:
	.string "ONDINE est devenue bien meilleure\n"
	.string "ces dernières années.\p"
	.string "Ne baisse pas ta garde, ou tu seras\n"
	.string "écrasé !$"

CeruleanGym_Text_GuideIntro:
	.string "Yo ! CHAMPION en herbe !\p"
	.string "Comme ONDINE était partie, je suis sorti\p"
	.string "m'amuser aussi. Hi-hi-hi !$"

CeruleanGym_Text_GuideWin:
	.string "Hou, tu m'as montré à quel point tu es\n"
	.string "fort.\p"
	.string "Comme toujours, c'était un sacré\n"
	.string "super combat !$"

CeruleanGym_Text_MistyTm:
	.string "Tiens, prends aussi ceci.$"
