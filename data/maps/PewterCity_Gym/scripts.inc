PewterCity_Gym_MapScripts::
	.byte 0



PewterCity_Gym_EventScript_Jerry::
	trainerbattle_single TRAINER_JERRY, PewterCity_Gym_Text_CamperJerry_Seen, PewterCity_Gym_Text_CamperJerry_Beaten
	msgbox PewterCity_Gym_Text_CamperJerry_AfterBattle, MSGBOX_AUTOCLOSE
	end

PewterCity_Gym_EventScript_Brock::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_PEWTER_GYM, PewterCity_Gym_EventScript_Brock_Defeated
	msgbox PewterCity_Gym_Text_Brock_Intro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_BROCK, PewterCity_Gym_Text_Brock_WinLoss
	message PewterCity_Gym_Text_ReceivedBoulderBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox PewterCity_Gym_Text_Brock_FightDone, MSGBOX_DEFAULT
	giveitem ITEM_TM_EARTHQUAKE
	setflag FLAG_BADGE09_GET
	setflag FLAG_DEFEATED_PEWTER_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 9
	call Common_EventScript_SetGymTrainers
	clearflag FLAG_HIDE_DIGLETT_BROCK
	closemessage
	release
	end

PewterCity_Gym_EventScript_Brock_Defeated::
	msgbox PewterCity_Gym_Text_Brock_FightDone, MSGBOX_DEFAULT
	closemessage
	release
	end


PewterCity_Gym_Text_Brock_Intro:
	.string "PIERRE : Eh bien, ce n'est pas souvent que\n"
	.string "nous recevons un challenger de JOHTO.\p"
	.string "Je suis PIERRE, le CHAMPION de l'ARENE\n"
	.string "d'ARGENTA.\p"
	.string "Je suis un expert des POKéMON de type\n"
	.string "Roche.\p"
	.string "Mes POKéMON sont insensibles à la plupart\n"
	.string "des attaques physiques. Tu auras du mal\l"
	.string "à leur infliger des dégâts.\p"
	.string "Allez, viens !$"

PewterCity_Gym_Text_Brock_WinLoss:
	.string "PIERRE : Les attaques puissantes de tes\n"
	.string "POKéMON ont surmonté ma défense solide…\p"
	.string "Tu es plus fort que je ne le pensais…\p"
	.string "Vas-y, prends ce BADGE.$"

PewterCity_Gym_Text_ReceivedBoulderBadge:
	.string "{PLAYER} reçoit le BADGE ROCHE.$"

PewterCity_Gym_Text_Brock_BoulderBadge:
	.string "PIERRE : Merci, {PLAYER}. J'ai apprécié\n"
	.string "ce combat, même si je suis un peu déçu.\p"
	.string "Ce BADGE ROCHE rendra tes POKéMON encore\n"
	.string "plus puissants.$"

PewterCity_Gym_Text_Brock_FightDone:
	.string "PIERRE : Le monde est vaste. Il y a encore\n"
	.string "beaucoup de dresseurs forts comme toi.\p"
	.string "Attends un peu. Je vais devenir beaucoup\n"
	.string "plus fort moi aussi.$"

PewterCity_Gym_Text_CamperJerry_Seen:
	.string "Les dresseurs de cette ARENE utilisent des\n"
	.string "POKéMON de type Roche.\p"
	.string "Le type Roche a une DEFENSE élevée.\p"
	.string "Les combats pourraient durer longtemps.\n"
	.string "Es-tu prêt pour ça ?$"

PewterCity_Gym_Text_CamperJerry_Beaten:
	.string "Je dois gagner ces combats…$"

PewterCity_Gym_Text_CamperJerry_AfterBattle:
	.string "Hé, toi ! Dresseur de JOHTO ! PIERRE est\n"
	.string "costaud. Il te punira si tu ne le prends\l"
	.string "pas au sérieux.$"

PewterCity_Gym_Text_Guide:
	.string "Yo ! CHAMPION en devenir ! Tu assures\n"
	.string "vraiment.\p"
	.string "Tu affrontes les CHAMPIONS d'ARENE de\n"
	.string "KANTO ?\p"
	.string "Ils sont forts et dévoués, tout comme\n"
	.string "ceux de JOHTO.$"

PewterCity_Gym_Text_Guide_Win:
	.string "Yo ! CHAMPION en devenir ! Cette ARENE ne\n"
	.string "t'a pas posé de problème.\p"
	.string "La façon dont tu as mené le combat était\n"
	.string "vraiment inspirante. Je le pense vraiment.$"

PewterCity_Gym_EventScript_GymGuy::
	goto_if_set FLAG_DEFEATED_PEWTER_GYM, PewterCity_Gym_EventScript_GymGuyAfter
	msgbox PewterCity_Gym_Text_Guide, MSGBOX_NPC
	end

PewterCity_Gym_EventScript_GymGuyAfter::
	msgbox PewterCity_Gym_Text_Guide_Win, MSGBOX_NPC
	end


PewterCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE09_GET, PewterCity_Gym_EventScript_GymStatuePostVictory
	msgbox PewterCity_Gym_Text_GymStatue
	releaseall
	end

PewterCity_Gym_EventScript_GymStatuePostVictory::
	msgbox PewterCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end

PewterCity_Gym_Text_GymStatue::
    .string "ARENE POKéMON D'ARGENTA\n"
    .string "CHAMPION : PIERRE\p"
    .string "DRESSEURS VAINQUEURS :\n"
    .string "BLUE, RED$"

PewterCity_Gym_Text_GymStatuePlayerWon::
    .string "ARENE POKéMON D'ARGENTA\n"
    .string "CHAMPION : PIERRE\p"
    .string "DRESSEURS VAINQUEURS :\n"
    .string "BLUE, RED, {PLAYER}$"


