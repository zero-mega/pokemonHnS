SaffronCity_Gym_MapScripts::
	.byte 0

SaffronCity_Gym_EventScript_GymGuy::
	goto_if_set FLAG_DEFEATED_SAFFRON_GYM, SaffronCity_Gym_EventScript_GymGuy2
	msgbox SaffronCity_Gym_Text_GymGuideIntro, MSGBOX_NPC
	end

SaffronCity_Gym_EventScript_GymGuy2::
	msgbox SaffronCity_Gym_Text_GymGuideWin, MSGBOX_NPC
	end

SaffronCity_Gym_EventScript_Rebecca::
	trainerbattle_single TRAINER_REBECCA SaffronCity_Gym_Text_MediumRebeccaSeen, SaffronCity_Gym_Text_MediumRebeccaBeaten
	msgbox SaffronCity_Gym_Text_MediumRebeccaAfter, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Franklin::
	trainerbattle_single TRAINER_FRANKLIN SaffronCity_Gym_Text_PsychicFranklinSeen, SaffronCity_Gym_Text_PsychicFranklinBeaten
	msgbox SaffronCity_Gym_Text_PsychicFranklinAfter, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Doris::
	trainerbattle_single TRAINER_DORIS SaffronCity_Gym_Text_MediumDorisSeen, SaffronCity_Gym_Text_MediumDorisBeaten
	msgbox SaffronCity_Gym_Text_MediumDorisAfter, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Jared::
	trainerbattle_single TRAINER_JARED SaffronCity_Gym_Text_PsychicJaredSeen, SaffronCity_Gym_Text_PsychicJaredBeaten
	msgbox SaffronCity_Gym_Text_PsychicJaredAfter, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Sabrina::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_SAFFRON_GYM, SaffronCity_Gym_EventScript_Sabrina_Defeated
	msgbox SaffronCity_Gym_Text_SabrinaIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_SABRINA, SaffronCity_Gym_Text_SabrinaWinLoss
	message SaffronCity_Gym_Text_ReceivedMarshBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox SaffronCity_Gym_Text_MarshBadgeInfo, MSGBOX_DEFAULT
	setflag FLAG_BADGE13_GET
	setflag FLAG_DEFEATED_SAFFRON_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 13
	call Common_EventScript_SetGymTrainers
	closemessage
	clearflag FLAG_HIDE_OLIVINE_SABRINA
	release
	end

SaffronCity_Gym_EventScript_Sabrina_Defeated::
	msgbox SaffronCity_Gym_Text_SabrinaPostBattle, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_Gym_Text_SabrinaIntro:
	.string "SABRINA : Je savais que tu viendrais…\p"
	.string "Il y a trois ans, j'ai eu une vision\n"
	.string "de ton arrivée.\p"
	.string "Tu es venu pour mon BADGE.\p"
	.string "Je n'aime pas combattre, mais c'est\n"
	.string "mon devoir de CHAMPIONNE d'accorder\l"
	.string "des BADGES à ceux qui l'ont mérité.\p"
	.string "Puisque tu le souhaites, je vais te\n"
	.string "montrer mes pouvoirs psychiques !$"

SaffronCity_Gym_Text_SabrinaWinLoss:
	.string "SABRINA : Ta puissance…\p"
	.string "Elle dépasse de loin ce que j'avais prévu…\p"
	.string "Peut-être qu'il est impossible de\n"
	.string "prédire totalement l'avenir…\p"
	.string "D'accord, tu as gagné. Tu as mérité\n"
	.string "le BADGE MARAIS.$"

SaffronCity_Gym_Text_ReceivedMarshBadge:
	.string "{PLAYER} reçoit le BADGE MARAIS.$"

SaffronCity_Gym_Text_MarshBadgeInfo:
	.string "SABRINA : Le BADGE MARAIS fait ressortir\n"
	.string "tes pouvoirs cachés…\p"
	.string "Même si je n'ai pas su prédire\n"
	.string "ta force, je sais une chose.\p"
	.string "Tu deviendras un CHAMPION célèbre\n"
	.string "et aimé de tous !$"

SaffronCity_Gym_Text_SabrinaPostBattle:
	.string "SABRINA : Ton amour pour tes\n"
	.string "POKéMON a surpassé mon pouvoir\l"
	.string "psychique…\p"
	.string "L'amour est aussi, je pense, une\n"
	.string "forme de pouvoir psychique…$"

SaffronCity_Gym_Text_SabrinaRematch:
	.string "SABRINA : Ah, le CHAMPION de KANTO.\p"
	.string "J'ai ressenti ton retour.\p"
	.string "Ta puissance a énormément grandi.\p"
	.string "Même maintenant, je sens ton aura.\p"
	.string "Veux-tu refaire un combat contre moi ?$"

SaffronCity_Gym_Text_SabrinaRematchDefeat:
	.string "SABRINA : Ton amour pour tes\n"
	.string "POKéMON a encore surpassé mon\l"
	.string "pouvoir psychique…$"

SaffronCity_Gym_Text_MediumRebeccaSeen:
	.string "Le pouvoir de tous ceux que tu as\n"
	.string "vaincus m'est transmis !$"

SaffronCity_Gym_Text_MediumRebeccaBeaten:
	.string "Fort… Bien trop fort…$"

SaffronCity_Gym_Text_MediumRebeccaAfter:
	.string "Quelle est la source de ta puissance ?$"

SaffronCity_Gym_Text_PsychicFranklinSeen:
	.string "Le pouvoir psychique est le pouvoir\n"
	.string "de ton âme.$"

SaffronCity_Gym_Text_PsychicFranklinBeaten:
	.string "Ton âme est plus puissante que\n"
	.string "la mienne !$"

SaffronCity_Gym_Text_PsychicFranklinAfter:
	.string "Tu as renforcé ton âme, pas seulement\n"
	.string "tes capacités.$"

SaffronCity_Gym_Text_MediumDorisSeen:
	.string "Fufufufu… Je le vois clairement.\p"
	.string "Je peux voir dans ton âme !$"

SaffronCity_Gym_Text_MediumDorisBeaten:
	.string "Même si je t'ai lu, j'ai quand même perdu…$"

SaffronCity_Gym_Text_MediumDorisAfter:
	.string "Zut ! J'ai oublié que j'avais prédit\n"
	.string "que je perdrais contre toi.$"

SaffronCity_Gym_Text_PsychicJaredSeen:
	.string "Le DOJO KARATÉ à côté était autrefois\n"
	.string "l'ARÈNE de cette ville.$"

SaffronCity_Gym_Text_PsychicJaredBeaten:
	.string "Je n'étais pas de taille…$"

SaffronCity_Gym_Text_PsychicJaredAfter:
	.string "Le MAÎTRE KARATÉ, chef du DOJO KARATÉ,\n"
	.string "a été vaincu par SABRINA.$"

SaffronCity_Gym_Text_GymGuideIntro:
	.string "Yo, futur CHAMPION !\p"
	.string "Un dresseur aussi doué que toi\n"
	.string "n'a pas besoin qu'on lui explique\l"
	.string "comment battre les POKéMON de type PSY,\l"
	.string "n'est-ce pas ?\p"
	.string "J'attends de grandes choses de toi !\p"
	.string "Bonne chance !$"

SaffronCity_Gym_Text_GymGuideWin:
	.string "C'était encore un combat fantastique !$"

SaffronCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE13_GET, SaffronCity_Gym_EventScript_GymStatuePostVictory
	msgbox SaffronCity_Gym_Text_GymStatue
	releaseall
	end

SaffronCity_Gym_EventScript_GymStatuePostVictory::
	msgbox SaffronCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end


SaffronCity_Gym_Text_GymStatue::
    .string "SAFRANIA ARÈNE POKéMON\n"
    .string "CHAMPIONNE : SABRINA\p"
	.string "DRESSEURS VICTORIEUX :\n"
	.string "BLUE, RED$"

SaffronCity_Gym_Text_GymStatuePlayerWon::
    .string "SAFRANIA ARÈNE POKéMON\n"
    .string "CHAMPIONNE : SABRINA\p"
    .string "DRESSEURS VICTORIEUX :\n"
	.string "BLUE, RED, {PLAYER}$"
