.set LOCALID_GOLDENROD_CITY_GYM_BRIDGET, 6

GoldenrodCity_Gym_MapScripts::
	.byte 0
@Carrie, Bridget, Victoria, Samantha, gym guy


GoldenrodCity_Gym_EventScript_Carrie::
	trainerbattle_single TRAINER_CARRIE GoldenrodCity_Gym_Text_LassCarrieSeen, GoldenrodCity_Gym_Text_LassCarrieBeaten
	msgbox GoldenrodCity_Gym_Text_LassCarrieAfter, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_Gym_EventScript_Bridget::
	trainerbattle_single TRAINER_BRIDGET GoldenrodCity_Gym_Text_LassBridgetSeen, GoldenrodCity_Gym_Text_LassBridgetBeaten
	msgbox GoldenrodCity_Gym_Text_LassBridgetAfter, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_Gym_EventScript_Victoria::
	trainerbattle_single TRAINER_VICTORIA GoldenrodCity_Gym_Text_BeautyVictoriaSeen, GoldenrodCity_Gym_Text_BeautyVictoriaBeaten
	msgbox GoldenrodCity_Gym_Text_BeautyVictoriaAfter, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_Gym_EventScript_Samantha::
	trainerbattle_single TRAINER_SAMANTHA GoldenrodCity_Gym_Text_BeautySamanthaSeen, GoldenrodCity_Gym_Text_BeautySamanthaBeaten
	msgbox GoldenrodCity_Gym_Text_BeautySamanthaAfter, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_Gym_EventScript_Gym_Guy::
	lock
	faceplayer
	goto_if_set FLAG_BADGE03_GET, GoldenrodCity_Gym_EventScript_Gym_Guy_After
	msgbox GoldenrodCity_Gym_Text_GymGuide, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_Gym_EventScript_Gym_Guy_After::
	msgbox GoldenrodCity_Gym_Text_GymGuideWin, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_Gym_EventScript_Whitney::
	lock
	faceplayer
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 3, GoldenrodCity_Gym_EventScript_WhitneyCrying
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 4, GoldenrodCity_Gym_EventScript_WhitneyBadge
	goto_if_set FLAG_DEFEATED_GOLDENROD_CITY_GYM, GoldenrodCity_Gym_EventScript_WhitneyDefeated
	msgbox GoldenrodCity_Gym_Text_WhitneyBefore, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_WHITNEY_1, GoldenrodCity_Gym_Text_WhitneyShouldntBeSoSerious
	msgbox GoldenrodCity_Gym_Text_WhitneyYouMeanie, MSGBOX_DEFAULT
	setvar VAR_GOLDENROD_CITY_STATE, 3
	closemessage
	release
	end

GoldenrodCity_Gym_EventScript_WhitneyCrying::
	lock
	faceplayer
	msgbox GoldenrodCity_Gym_Text_WhitneyYouMeanie, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_Gym_EventScript_WhitneyBadge::
	lock
	faceplayer
	msgbox GoldenrodCity_Gym_Text_WhitneyWhatDoYouWant, MSGBOX_DEFAULT
	closemessage
	message GoldenrodCity_Gym_Text_PlayerReceivedPlainBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox GoldenrodCity_Gym_Text_WhitneyPlainBadge, MSGBOX_DEFAULT
	setflag FLAG_BADGE03_GET
	setflag FLAG_DEFEATED_GOLDENROD_CITY_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 3
	call Common_EventScript_SetGymTrainers
	giveitem ITEM_TM_ATTRACT
	msgbox GoldenrodCity_Gym_Text_WhitneyAttract, MSGBOX_DEFAULT
	setvar VAR_GOLDENROD_CITY_STATE, 5
	closemessage
	release
	end

GoldenrodCity_Gym_EventScript_WhitneyDefeated::
	lock
	faceplayer
	msgbox GoldenrodCity_Gym_Text_WhitneyGoodCry, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_Gym_EventScript_Trigger::	
	turnobject LOCALID_GOLDENROD_CITY_GYM_BRIDGET DIR_WEST
	msgbox GoldenrodCity_Gym_Text_BridgetWhitneyCries, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp1
	waitmovement 0
	setvar VAR_GOLDENROD_CITY_STATE, 4
	closemessage
	release
	end


GoldenrodCity_Gym_EventScript_Statue::
	lock
	goto_if_set FLAG_DEFEATED_GOLDENROD_CITY_GYM, GoldenrodCity_Gym_EventScript_Statue2
	msgbox GoldenrodCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_Gym_EventScript_Statue2::
	msgbox GoldenrodCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_Gym_Text_GymStatue:
	.string "ARÈNE POKéMON DE DOUBLONVILLE$"

GoldenrodCity_Gym_Text_GymStatueCertified:
	.string "ARÈNE POKéMON DE DOUBLONVILLE\p"
	.string "DRESSEURS CERTIFIÉS PAR BLANCHE :\n"
	.string "{PLAYER}$"

GoldenrodCity_Gym_Text_WhitneyBefore:
    .string "Salut ! Je suis BLANCHE !\p"
    .string "Tout le monde aimait les POKéMON, alors\n"
    .string "je m'y suis mise aussi !\p"
    .string "Les POKéMON sont trop mignons !\p"
    .string "Tu veux te battre ? Je te préviens,\n"
    .string "je suis forte !$"

GoldenrodCity_Gym_Text_WhitneyShouldntBeSoSerious:
    .string "Snif…\p"
    .string "…Ouaaah ! Tu es méchant !\p"
    .string "Tu ne devrais pas être si sérieux !\n"
    .string "Tu es qu'un enfant !$"

GoldenrodCity_Gym_Text_WhitneyYouMeanie:
    .string "Ouaaah !\p"
    .string "Ouaaah !\p"
    .string "…Snif, hic… …Tu es méchant !$"

GoldenrodCity_Gym_Text_WhitneyWhatDoYouWant:
    .string "…Snif…\p"
    .string "Quoi ? Que veux-tu ? Un BADGE ?\p"
    .string "Ah, oui. J'avais oublié. Voici\n"
    .string "le BADGE PLAINE.$"

GoldenrodCity_Gym_Text_PlayerReceivedPlainBadge:
    .string "{PLAYER} reçoit le BADGE PLAINE.$"

GoldenrodCity_Gym_Text_WhitneyPlainBadge:
    .string "Le BADGE PLAINE permet à tes POKéMON\n"
    .string "d'utiliser FORCE hors combat.\p"
    .string "Il augmente aussi la DÉFENSE de tes\n"
	.string "POKéMON.\p"
    .string "Oh, tu peux aussi avoir ça !$"

GoldenrodCity_Gym_Text_WhitneyAttract:
    .string "C'est ATTRACTION ! Ça utilise tout le\n"
    .string "charme d'un POKéMON.\p"
    .string "N'est-ce pas parfait pour une\n"
    .string "mignonne comme moi ?$"

GoldenrodCity_Gym_Text_WhitneyGoodCry:
    .string "Ah, ça fait du bien de pleurer !$"

GoldenrodCity_Gym_Text_WhitneyRematch:
    .string "Salut ! C'est toi !\p"
    .string "Wow, CHAMPION DE JOHTO maintenant ?\p"
    .string "Tu es vraiment incroyable !\p"
    .string "Je veux voir à quel point tu es fort.\p"
    .string "Tu veux refaire un combat contre moi ?$"

GoldenrodCity_Gym_Text_WhitneyRematchDefeat:
    .string "Ouaaah !\p"
    .string "Ouaaah !\p"
    .string "…Snif, hic… …Tu es méchant !$"

GoldenrodCity_Gym_Text_LassCarrieSeen:
    .string "Ne te laisse pas tromper par la mignonnerie\n"
    .string "de mes POKéMON.\p"
    .string "Ils peuvent te battre !$"

GoldenrodCity_Gym_Text_LassCarrieBeaten:
    .string "Zut… Je pensais que tu étais faible…$"

GoldenrodCity_Gym_Text_LassCarrieAfter:
    .string "Mes POKéMON me trouvent-ils mignonne ?$"

GoldenrodCity_Gym_Text_LassBridgetSeen:
    .string "Je préfère les POKéMON mignons aux\n"
    .string "POKéMON forts.\p"
    .string "Mais j'ai des POKéMON forts et mignons !$"

GoldenrodCity_Gym_Text_LassBridgetBeaten:
    .string "Oh, non, non, non !$"

GoldenrodCity_Gym_Text_LassBridgetAfter:
    .string "J'essaie de battre BLANCHE, mais…\n"
    .string "C'est déprimant.\p"
    .string "Ça va ! Si je perds, j'essaierai\n"
    .string "plus fort la prochaine fois !$"

GoldenrodCity_Gym_Text_BridgetWhitneyCries:
    .string "Oh, non. Tu as fait pleurer BLANCHE.\p"
    .string "Ce n'est rien. Elle va s'arrêter bientôt.\n"
    .string "Elle pleure toujours quand elle perd.$"

GoldenrodCity_Gym_Text_BeautyVictoriaSeen:
    .string "Oh, tu es un(e) dresseur(se) trop mignon(ne) !\p"
    .string "Je t'aime bien, mais je ne retiendrai pas mes coups !$"

GoldenrodCity_Gym_Text_BeautyVictoriaBeaten:
    .string "Voyons voir… Oups, c'est fini ?$"

GoldenrodCity_Gym_Text_BeautyVictoriaAfter:
    .string "Waouh, tu dois être fort(e) pour me battre !\n"
    .string "Continue comme ça !$"

GoldenrodCity_Gym_Text_BeautySamanthaSeen:
    .string "Donne tout ce que tu as, ou je vais\n"
    .string "t'écraser !$"

GoldenrodCity_Gym_Text_BeautySamanthaBeaten:
    .string "Non ! Oh, MIAOUSS, je suis désolée !$"

GoldenrodCity_Gym_Text_BeautySamanthaAfter:
    .string "J'ai appris à MIAOUSS des attaques pour\n"
    .string "affronter tous les types…$"

GoldenrodCity_Gym_Text_GymGuide:
    .string "Yo ! CHAMPION en herbe !\p"
    .string "Cette ARÈNE est dirigée par BLANCHE,\n"
    .string "la spécialiste des POKéMON de type NORMAL.\p"
    .string "Méfie-toi de son équipe trop mignonne.\p"
    .string "Certains POKéMON ici ont aussi le tout\n"
    .string "nouveau type FÉE.\p"
    .string "Va sur la ROUTE 34 si tu as besoin d'un\n"
    .string "POKéMON de type COMBAT ou POISON.$"

GoldenrodCity_Gym_Text_GymGuideWin:
    .string "Tu as gagné ? Génial ! J'étais occupé à\n"
    .string "admirer les dames ici.$"
