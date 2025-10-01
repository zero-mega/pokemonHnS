ViridianCity_Gym_MapScripts::
	.byte 0

ViridianCity_Gym_EventScript_Blue::
	lock
	faceplayer
	goto_if_unset FLAG_HIDE_DOJO_BLUE, ViridianCity_Gym_EventScript_BlueAtDojo
	goto_if_set FLAG_DEFEATED_VIRIDIAN_GYM, ViridianCity_Gym_EventScript_BlueGotoDojo
	goto_if_set FLAG_DEFEATED_VIRIDIAN_GYM, ViridianCity_Gym_EventScript_Blue_Defeated
	msgbox ViridianCity_Gym_Text_LeaderBlue_Before, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_BLUE, ViridianCity_Gym_Text_LeaderBlue_Win
	message ViridianCity_Gym_Text_ReceivedEarthBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox ViridianCity_Gym_Text_LeaderBlue_After, MSGBOX_DEFAULT
	giveitem ITEM_TM_BULK_UP
	setflag FLAG_BADGE16_GET
	setflag FLAG_DEFEATED_VIRIDIAN_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 16
	call Common_EventScript_SetGymTrainers
	closemessage
	setflag FLAG_HIDE_LEAGUE_BLACKBELT
	setflag FLAG_HIDE_CERULEANCAVE_GUARD
	setflag FLAG_HIDE_SEAFOAM_BLAINE
	clearflag FLAG_HIDE_CINNABAR_BLAINE
	release
	end

ViridianCity_Gym_EventScript_Blue_Defeated::
	msgbox ViridianCity_Gym_Text_LeaderBlue_Epilogue, MSGBOX_DEFAULT
	closemessage
	release
	end

ViridianCity_Gym_EventScript_BlueGotoDojo::
	msgbox ViridianCity_Gym_Text_BlueGotoDojo, MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_HIDE_DOJO_BLUE
	release
	end

ViridianCity_Gym_Text_BlueGotoDojo:
	.string "BLEU: Déjà de retour pour plus ?\p"
	.string "Si tu veux une autre chance contre moi,\n"
	.string "viens au DOJO DE COMBAT !$"

ViridianCity_Gym_EventScript_BlueAtDojo::
	msgbox ViridianCity_Gym_Text_LeaderBlue_Epilogue, MSGBOX_DEFAULT
	closemessage
	release
	end

ViridianCity_Gym_Text_LeaderBlue_Before:
	.string "BLEU: Yo ! Tu es enfin arrivé, hein ?\p"
	.string "Je n'étais pas d'humeur à CANNELAGE,\p"
	.string "mais maintenant je suis prêt à te combattre.\p"
	.string "…\p"
	.string "Tu me dis que tu as conquis toutes\n"
	.string "les ARÈNES de JOHTO ?\p"
	.string "Heh ! Les ARÈNES de JOHTO doivent être\n"
	.string "plutôt pathétiques alors.\p"
	.string "Hé, ne t'inquiète pas pour ça.\p"
	.string "Je saurai si tu es bon ou pas en\n"
	.string "te combattant maintenant.\p"
	.string "Prêt, CHAMP de JOHTO ?$"

ViridianCity_Gym_Text_LeaderBlue_Win:
	.string "BLEU: Quoi ?\p"
	.string "Comment diable ai-je pu perdre contre toi ?\p"
	.string "…\p"
	.string "Tch, d'accord… Tiens, prends ça--c'est\n"
	.string "le BADGE TERRE.$"

ViridianCity_Gym_Text_ReceivedEarthBadge:
	.string "{PLAYER} a reçu le BADGE TERRE.$"

ViridianCity_Gym_Text_LeaderBlue_After:
	.string "BLEU: …\p"
	.string "D'accord, j'avais tort. Tu es\n"
	.string "le vrai. Tu es un bon dresseur.\p"
	.string "Mais je vais te battre un jour.\p"
	.string "Ne l'oublie pas !$"

ViridianCity_Gym_Text_LeaderBlue_Epilogue:
	.string "BLEU: Écoute, toi.\p"
	.string "Tu ferais mieux de ne pas perdre\n"
	.string "jusqu'à ce que je te batte. Compris ?$"


ViridianCity_Gym_EventScript_GymGuy::
	goto_if_set FLAG_DEFEATED_VIRIDIAN_GYM, ViridianCity_Gym_EventScript_GymGuyAfter
	msgbox ViridianCity_Gym_Text_Guide, MSGBOX_NPC
	end

ViridianCity_Gym_EventScript_GymGuyAfter::
	msgbox ViridianCity_Gym_Text_Guide_Win, MSGBOX_NPC
	end

ViridianCity_Gym_Text_Guide:
	.string "Yo, CHAMP en devenir !\p"
	.string "Comment ça va ? On dirait que tu es\n"
	.string "en pleine forme.\p"
	.string "Le CHAMPION D'ARÈNE est un gars qui a combattu\n"
	.string "le CHAMPION il y a trois ans.\p"
	.string "Ce n'est pas un amateur.\p"
	.string "Donne tout ce que tu as !$"

ViridianCity_Gym_Text_Guide_Win:
	.string "Mec, tu es vraiment coriace…\p"
	.string "C'était un combat vraiment inspirant.\n"
	.string "Ça m'a fait venir les larmes aux yeux.$"


ViridianCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE16_GET, ViridianCity_Gym_EventScript_GymStatuePostVictory
	msgbox ViridianCity_Gym_Text_GymStatue
	releaseall
	end

ViridianCity_Gym_EventScript_GymStatuePostVictory::
	msgbox ViridianCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end

ViridianCity_Gym_Text_GymStatue::
    .string "ARÈNE POKéMON DE JADIELLE\n"
    .string "CHAMPION: BLEU\p"
	.string "DRESSEURS VICTOIREUX:\n"
	.string "BLEU, ROUGE$"

ViridianCity_Gym_Text_GymStatuePlayerWon::
    .string "ARÈNE POKéMON DE JADIELLE\n"
    .string "CHAMPION: BLEU\p"
    .string "DRESSEURS VICTOIREUX:\n"
	.string "BLEU, ROUGE, {PLAYER}$"

