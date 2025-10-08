SootopolisCity_Gym_1F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SootopolisCity_Gym_1F_OnFrame
	map_script MAP_SCRIPT_ON_RESUME, SootopolisCity_Gym_1F_OnResume
	map_script MAP_SCRIPT_ON_LOAD, SootopolisCity_Gym_1F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, SootopolisCity_Gym_1F_OnTransition
	.byte 0

SootopolisCity_Gym_1F_OnTransition:
	setvar VAR_ICE_STEP_COUNT, 1
	end

SootopolisCity_Gym_1F_OnResume:
	setstepcallback STEP_CB_SOOTOPOLIS_ICE
	end

SootopolisCity_Gym_1F_OnLoad:
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special SetSootopolisGymCrackedIceMetatiles
	end

SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles::
	goto_if_lt VAR_ICE_STEP_COUNT, 8, SootopolisCity_Gym_1F_EventScript_StopCheckingStairs  @ All stairs ice
	goto_if_lt VAR_ICE_STEP_COUNT, 28, SootopolisCity_Gym_1F_EventScript_OpenFirstStairs
	goto_if_lt VAR_ICE_STEP_COUNT, 67, SootopolisCity_Gym_1F_EventScript_OpenFirstAndSecondStairs
	setmetatile 8, 4, METATILE_SootopolisGym_Stairs, FALSE
	setmetatile 8, 5, METATILE_SootopolisGym_Stairs, FALSE
SootopolisCity_Gym_1F_EventScript_OpenFirstAndSecondStairs::
	setmetatile 8, 10, METATILE_SootopolisGym_Stairs, FALSE
	setmetatile 8, 11, METATILE_SootopolisGym_Stairs, FALSE
SootopolisCity_Gym_1F_EventScript_OpenFirstStairs::
	setmetatile 8, 15, METATILE_SootopolisGym_Stairs, FALSE
	setmetatile 8, 16, METATILE_SootopolisGym_Stairs, FALSE
SootopolisCity_Gym_1F_EventScript_StopCheckingStairs::
	return

SootopolisCity_Gym_1F_OnFrame:
	map_script_2 VAR_ICE_STEP_COUNT, 8, SootopolisCity_Gym_1F_EventScript_UnlockFirstStairs
	map_script_2 VAR_ICE_STEP_COUNT, 28, SootopolisCity_Gym_1F_EventScript_UnlockSecondStairs
	map_script_2 VAR_ICE_STEP_COUNT, 67, SootopolisCity_Gym_1F_EventScript_UnlockThirdStairs
	map_script_2 VAR_ICE_STEP_COUNT, 0, SootopolisCity_Gym_1F_EventScript_FallThroughIce
	.2byte 0

SootopolisCity_Gym_1F_EventScript_UnlockFirstStairs::
	addvar VAR_ICE_STEP_COUNT, 1
	delay 40
	playse SE_ICE_STAIRS
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special DrawWholeMapView
	end

SootopolisCity_Gym_1F_EventScript_UnlockSecondStairs::
	addvar VAR_ICE_STEP_COUNT, 1
	delay 40
	playse SE_ICE_STAIRS
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special DrawWholeMapView
	end

SootopolisCity_Gym_1F_EventScript_UnlockThirdStairs::
	addvar VAR_ICE_STEP_COUNT, 1
	delay 40
	playse SE_ICE_STAIRS
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special DrawWholeMapView
	end

SootopolisCity_Gym_1F_EventScript_FallThroughIce::
	lockall
	delay 20
	applymovement OBJ_EVENT_ID_PLAYER, SootopolisCity_Gym_1F_Movement_FallThroughIce
	waitmovement 0
	playse SE_FALL
	delay 60
	warphole MAP_SOOTOPOLIS_CITY_GYM_B1F
	waitstate
	end

SootopolisCity_Gym_1F_Movement_FallThroughIce:
	set_invisible
	step_end

SootopolisCity_Gym_1F_EventScript_Juan::
	trainerbattle_single TRAINER_JUAN_1, SootopolisCity_Gym_1F_Text_JuanIntro, SootopolisCity_Gym_1F_Text_JuanDefeat, SootopolisCity_Gym_1F_EventScript_JuanDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, SootopolisCity_Gym_1F_EventScript_JuanRematch
	goto_if_unset FLAG_RECEIVED_TM_WATER_PULSE, SootopolisCity_Gym_1F_EventScript_GiveWaterPulse2
	goto_if_unset FLAG_BADGE06_GET, SootopolisCity_Gym_1F_EventScript_GoGetFortreeBadge
	msgbox SootopolisCity_Gym_1F_Text_JuanPostBattle, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_JuanDefeated::
	message SootopolisCity_Gym_1F_Text_ReceivedRainBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox SootopolisCity_Gym_1F_Text_ExplainRainBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_BLACKTHORN_GYM
	setflag FLAG_BADGE08_GET
	setflag FLAG_GARBAGEFLAG
	setflag FLAG_GARBAGEFLAG
	setflag FLAG_GARBAGEFLAG
	setvar VAR_GARBAGEVAR, 6
	clearflag FLAG_GARBAGEFLAG
	setvar VAR_0x8008, 8
	call Common_EventScript_SetGymTrainers
	call SootopolisCity_Gym_1F_EventScript_GiveWaterPulse
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox SootopolisCity_Gym_1F_Text_RegisteredJuan, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_JUAN_MATCH_CALL
	release
	end

SootopolisCity_Gym_1F_EventScript_GiveWaterPulse::
	giveitem ITEM_TM_WATER_PULSE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox SootopolisCity_Gym_1F_Text_ExplainWaterPulse, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_WATER_PULSE
	return

SootopolisCity_Gym_1F_EventScript_GiveWaterPulse2::
	giveitem ITEM_TM_WATER_PULSE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox SootopolisCity_Gym_1F_Text_ExplainWaterPulse, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_WATER_PULSE
	release
	end

SootopolisCity_Gym_1F_EventScript_GoGetFortreeBadge::
	msgbox SootopolisCity_Gym_1F_Text_GoGetFortreeBadge, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_JuanRematch::
	trainerbattle_rematch_double TRAINER_JUAN_1, SootopolisCity_Gym_1F_Text_JuanPreRematch, SootopolisCity_Gym_1F_Text_JuanRematchDefeat, SootopolisCity_Gym_1F_Text_JuanRematchNeedTwoMons
	msgbox SootopolisCity_Gym_1F_Text_JuanPostRematch, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_1F_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_BLACKTHORN_GYM, SootopolisCity_Gym_1F_EventScript_GymGuidePostVictory
	msgbox SootopolisCity_Gym_1F_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_GymGuidePostVictory::
	msgbox SootopolisCity_Gym_1F_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE08_GET, SootopolisCity_Gym_1F_EventScript_GymStatueCertified
	goto SootopolisCity_Gym_1F_EventScript_GymStatue
	end

SootopolisCity_Gym_1F_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE08_GET, SootopolisCity_Gym_1F_EventScript_GymStatueCertified
	goto SootopolisCity_Gym_1F_EventScript_GymStatue
	end

SootopolisCity_Gym_1F_EventScript_GymStatueCertified::
	msgbox SootopolisCity_Gym_1F_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_Gym_1F_EventScript_GymStatue::
	msgbox SootopolisCity_Gym_1F_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_Gym_1F_Text_GymGuideAdvice:
	.string "Yo ! Comment ça va, CHAMPION\n"
	.string "en herbe {PLAYER} ?\p"
	.string "Le CHAMPION de l'ARÈNE d'ATLANOPOLIS,\n"
	.string "JUAN, est un maître des POKéMON de type EAU.\p"
	.string "Et pour atteindre JUAN, un sol glacé\n"
	.string "va compliquer ta progression…\p"
	.string "Écoute, je suis désolé, mais c'est tout\n"
	.string "le conseil que j'ai pour toi.\p"
	.string "Pour la suite, tu devras te débrouiller\n"
	.string "par toi-même !$"

SootopolisCity_Gym_1F_Text_GymGuidePostVictory:
	.string "Ouah ! Tu as même battu JUAN, qui\n"
	.string "était censé être le meilleur de HOENN !\p"
	.string "Vérifie ta CARTE DRESSEUR.\p"
	.string "Si tu as tous les BADGES, tu es prêt\n"
	.string "pour le défi de la LIGUE POKéMON !$"

SootopolisCity_Gym_1F_Text_JuanIntro:
	.string "Permets-moi de te demander.\n"
	.string "Le savais-tu ?\l"
	.string "Ah, je ne devrais pas être si mystérieux.\p"
	.string "C'est moi qui ai tout appris à PIERRE\n"
	.string "sur les POKéMON.\p"
	.string "Un jour, j'ai abandonné ma place de\n"
	.string "CHAMPION d'ARÈNE.\p"
	.string "À ma place, j'ai confié l'ARÈNE à PIERRE.\p"
	.string "Cependant, une raison impérieuse m'a\n"
	.string "poussé à faire mon retour.\p"
	.string "Mais assez parlé.\n"
	.string "Commençons notre combat, veux-tu ?\p"
	.string "S'il te plaît, sois témoin de\n"
	.string "notre art.\p"
	.string "Une grande illusion d'eau sculptée\n"
	.string "par mes POKéMON et moi-même !$"

SootopolisCity_Gym_1F_Text_JuanDefeat:
	.string "Ahahaha, excellent !\n"
	.string "Très bien, tu es le vainqueur.\p"
	.string "Je sens en toi l'éclat brillant d'une\n"
	.string "compétence qui triomphera de tout.\p"
	.string "Cependant, comparé à moi ou même à\n"
	.string "PIERRE, il te manque de l'élégance.\p"
	.string "Peut-être devrais-je te prêter\n"
	.string "ma tenue ?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "Hahaha, je plaisante !\p"
	.string "Plutôt que mes vêtements, je vais te\n"
	.string "récompenser avec ceci, le BADGE PLUIE !$"

SootopolisCity_Gym_1F_Text_ReceivedRainBadge:
	.string "{PLAYER} reçoit le BADGE PLUIE\n"
	.string "de JUAN.$"

SootopolisCity_Gym_1F_Text_ExplainRainBadgeTakeThis:
	.string "Avoir le BADGE PLUIE garantit que tous\n"
	.string "tes POKéMON t'obéiront au doigt et à l'œil.\l"
	.string "\p"
	.string "Le BADGE PLUIE permet aussi d'utiliser\n"
	.string "la CS CASCADE pour gravir les murs\l"
	.string "d'eau en cascade.\p"
	.string "Et, pour que tu n'oublies jamais le\n"
	.string "combat que nous avons partagé, prends ceci…$"

SootopolisCity_Gym_1F_Text_ExplainWaterPulse:
	.string "La CT que je t'ai donnée contient\n"
	.string "VIBRAQUA.\p"
	.string "En combat, elle peut parfois rendre\n"
	.string "la cible confuse avec des ondes ultrasoniques.\p"
	.string "… … … … … …$"

SootopolisCity_Gym_1F_Text_RegisteredJuan:
	.string "CHAMPION d'ARÈNE JUAN enregistré\n"
	.string "dans le POKéNAV.$"

SootopolisCity_Gym_1F_Text_JuanPostBattle:
	.string "Les DRESSEURS qui ont réuni tous\n"
	.string "les BADGES d'ARÈNE de HOENN doivent\l"
	.string "se diriger vers la destination ultime.\p"
	.string "La LIGUE POKéMON.\p"
	.string "Voyage vers l'extrémité est de HOENN,\n"
	.string "vers l'île d'EVER GRANDE.\p"
	.string "Là-bas, tu trouveras la LIGUE\n"
	.string "POKéMON.$"

SootopolisCity_Gym_1F_Text_GoGetFortreeBadge:
	.string "Il ne te reste plus qu'un seul BADGE à\n"
	.string "obtenir à HOENN.\p"
	.string "Si tu veux défier la LIGUE POKéMON,\n"
	.string "tu dois obtenir le dernier BADGE\l"
	.string "de l'ARÈNE de CLEMENTI-VILLE.$"

SootopolisCity_Gym_1F_Text_GymStatue:
	.string "ARÈNE POKéMON D'ATLANOPOLIS$"

SootopolisCity_Gym_1F_Text_GymStatueCertified:
	.string "ARÈNE POKéMON D'ATLANOPOLIS\p"
	.string "DRESSEURS CERTIFIÉS PAR JUAN :\n"
	.string "{PLAYER}$"

SootopolisCity_Gym_1F_Text_JuanPreRematch:
	.string "JUAN : Ah, cette ARÈNE avait retrouvé\n"
	.string "son état habituel de sérénité…\p"
	.string "Mais notre jeune typhon est revenu\n"
	.string "pour nous mettre à l'épreuve à nouveau !\p"
	.string "Eh bien, mon ami, bien sûr !\p"
	.string "Je serai ravi de danser avec toi\n"
	.string "aussi souvent que tu le souhaites !$"

SootopolisCity_Gym_1F_Text_JuanRematchDefeat:
	.string "Ahahaha, tu es le vainqueur !\n"
	.string "Tu m'as encore battu !$"

SootopolisCity_Gym_1F_Text_JuanPostRematch:
	.string "JUAN : Si je te demandais de devenir\n"
	.string "mon apprenti, tu refuserais, j'en suis sûr.\p"
	.string "J'aimerais t'offrir mon manteau\n"
	.string "en cadeau.\p"
	.string "Mais encore une fois, tu refuserais.\n"
	.string "Je l'imagine bien.\p"
	.string "Et cela, mon ami, est un signe certain\n"
	.string "de noblesse !$"

SootopolisCity_Gym_1F_Text_JuanRematchNeedTwoMons:
	.string "JUAN : Ah, cette ARÈNE avait retrouvé\n"
	.string "son état habituel de sérénité…\p"
	.string "Mais notre jeune typhon est revenu\n"
	.string "pour nous mettre à l'épreuve à nouveau !\p"
	.string "Eh bien, mon ami, bien sûr !\n"
	.string "Je serai ravi de danser avec toi…\p"
	.string "Ah, non, non, non.\n"
	.string "Tu n'as qu'un seul POKéMON avec toi.\p"
	.string "J'aimerais que tu reviennes avec\n"
	.string "deux, voire plus, de POKéMON, s'il te plaît.$"
