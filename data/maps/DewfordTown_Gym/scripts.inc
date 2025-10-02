DewfordTown_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DewfordTown_Gym_OnTransition
	.byte 0

DewfordTown_Gym_OnTransition:
	call DewfordTown_Gym_EventScript_SetFlashLevel
	end

DewfordTown_Gym_EventScript_SetFlashLevel::
	goto_if_defeated TRAINER_DICK, DewfordTown_Gym_EventScript_SetLightsOn
	call DewfordTown_Gym_EventScript_CountTrainersDefeated
	copyvar VAR_0x8001, VAR_0x8000
	goto_if_eq VAR_0x8000, 0, DewfordTown_Gym_EventScript_SetFlashLevel7
	goto_if_eq VAR_0x8000, 1, DewfordTown_Gym_EventScript_SetFlashLevel6
	goto_if_eq VAR_0x8000, 2, DewfordTown_Gym_EventScript_SetFlashLevel5
	goto_if_eq VAR_0x8000, 3, DewfordTown_Gym_EventScript_SetFlashLevel4
	goto_if_eq VAR_0x8000, 4, DewfordTown_Gym_EventScript_SetFlashLevel3
	goto_if_eq VAR_0x8000, 5, DewfordTown_Gym_EventScript_SetFlashLevel2
	goto DewfordTown_Gym_EventScript_SetFlashLevel1

DewfordTown_Gym_EventScript_SetLightsOn::
	setflashlevel 0
	return

@ Brightest
DewfordTown_Gym_EventScript_SetFlashLevel1::
	setflashlevel 1
	return

DewfordTown_Gym_EventScript_SetFlashLevel2::
	setflashlevel 2
	return

DewfordTown_Gym_EventScript_SetFlashLevel3::
	setflashlevel 3
	return

DewfordTown_Gym_EventScript_SetFlashLevel4::
	setflashlevel 4
	return

DewfordTown_Gym_EventScript_SetFlashLevel5::
	setflashlevel 5
	return

DewfordTown_Gym_EventScript_SetFlashLevel6::
	setflashlevel 6
	return

@ Darkest
DewfordTown_Gym_EventScript_SetFlashLevel7::
	setflashlevel 7
	return

DewfordTown_Gym_EventScript_BrightenRoom::
	call DewfordTown_Gym_EventScript_CountTrainersDefeated
	nop1
	goto_if_eq VAR_0x8000, VAR_0x8001, DewfordTown_Gym_EventScript_NoLightChange
	copyvar VAR_0x8001, VAR_0x8000
	goto_if_eq VAR_0x8000, 1, DewfordTown_Gym_EventScript_AnimateFlash1Trainer
	goto_if_eq VAR_0x8000, 2, DewfordTown_Gym_EventScript_AnimateFlash2Trainers
	goto_if_eq VAR_0x8000, 3, DewfordTown_Gym_EventScript_AnimateFlash3Trainers
	goto_if_eq VAR_0x8000, 4, DewfordTown_Gym_EventScript_AnimateFlash4Trainers
	goto_if_eq VAR_0x8000, 5, DewfordTown_Gym_EventScript_AnimateFlash5Trainers
	goto_if_eq VAR_0x8000, 6, DewfordTown_Gym_EventScript_AnimateFlash6Trainers

DewfordTown_Gym_EventScript_NoLightChange::
	return

@ NOTE: A little confusingly, a larger animateflash param value is a smaller flash radius
DewfordTown_Gym_EventScript_AnimateFlash1Trainer::
	playse SE_SWITCH
	animateflash 6
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash2Trainers::
	playse SE_SWITCH
	animateflash 5
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash3Trainers::
	playse SE_SWITCH
	animateflash 4
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash4Trainers::
	playse SE_SWITCH
	animateflash 3
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash5Trainers::
	playse SE_SWITCH
	animateflash 2
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash6Trainers::
	playse SE_SWITCH
	animateflash 1
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlashFullBrightness::
	playse SE_SWITCH
	animateflash 0
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_CountTrainersDefeated::
	setvar VAR_0x8000, 0
	goto_if_not_defeated TRAINER_TAKAO, DewfordTown_Gym_EventScript_CheckJocelyn
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckJocelyn::
	goto_if_not_defeated TRAINER_JOCELYN, DewfordTown_Gym_EventScript_CheckLaura
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckLaura::
	goto_if_not_defeated TRAINER_LAURA, DewfordTown_Gym_EventScript_CheckBrenden
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckBrenden::
	goto_if_not_defeated TRAINER_BRENDEN, DewfordTown_Gym_EventScript_CheckCristian
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckCristian::
	goto_if_not_defeated TRAINER_HARVEY, DewfordTown_Gym_EventScript_CheckLilith
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckLilith::
	goto_if_not_defeated TRAINER_LILITH, DewfordTown_Gym_EventScript_StopCountingTrainers
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_StopCountingTrainers::
	return

DewfordTown_Gym_EventScript_Brawly::
	trainerbattle_single TRAINER_DICK, DewfordTown_Gym_Text_BrawlyIntro, DewfordTown_Gym_Text_BrawlyDefeat, DewfordTown_Gym_EventScript_BrawlyDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, DewfordTown_Gym_EventScript_BrawlyRematch
	goto_if_unset FLAG_RECEIVED_TM_BULK_UP, DewfordTown_Gym_EventScript_GiveBulkUp2
	msgbox DewfordTown_Gym_Text_BrawlyPostBattle, MSGBOX_DEFAULT
	release
	end

DewfordTown_Gym_EventScript_BrawlyDefeated::
	call DewfordTown_Gym_EventScript_AnimateFlashFullBrightness
	message DewfordTown_Gym_Text_ReceivedKnuckleBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox DewfordTown_Gym_Text_KnuckleBadgeInfoTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_AZALEA_TOWN_GYM
	setflag FLAG_BADGE02_GET
	addvar VAR_GARBAGEVAR, 1
	call_if_eq VAR_GARBAGEVAR, 6, Common_EventScript_ReadyPetalburgGymForBattle
	setvar VAR_0x8008, 2
	call Common_EventScript_SetGymTrainers
	call DewfordTown_Gym_EventScript_GiveBulkUp
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox DewfordTown_Gym_Text_RegisteredBrawly, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_BRAWLY_MATCH_CALL
	setvar VAR_ROXANNE_CALL_STEP_COUNTER, 0
	setflag FLAG_ENABLE_ROXANNE_FIRST_CALL
	release
	end

DewfordTown_Gym_EventScript_GiveBulkUp::
	giveitem ITEM_TM_BULK_UP
	goto_if_eq VAR_RESULT, 0, Common_EventScript_BagIsFull
	msgbox DewfordTown_Gym_Text_ExplainBulkUp, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_BULK_UP
	return

DewfordTown_Gym_EventScript_GiveBulkUp2:
	giveitem ITEM_TM_BULK_UP
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
	msgbox DewfordTown_Gym_Text_ExplainBulkUp, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_BULK_UP
	release
	end

DewfordTown_Gym_EventScript_BrawlyRematch::
	trainerbattle_rematch_double TRAINER_DICK, DewfordTown_Gym_Text_BrawlyPreRematch, DewfordTown_Gym_Text_BrawlyRematchDefeat, DewfordTown_Gym_Text_BrawlyRematchNeedTwoMons
	msgbox DewfordTown_Gym_Text_BrawlyPostRematch, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_Takao::
	trainerbattle_single TRAINER_TAKAO, DewfordTown_Gym_Text_TakaoIntro, DewfordTown_Gym_Text_TakaoDefeat, DewfordTown_Gym_EventScript_TakaoBrightenRoom
	msgbox DewfordTown_Gym_Text_TakaoPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_TakaoBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Jocelyn::
	trainerbattle_single TRAINER_JOCELYN, DewfordTown_Gym_Text_JocelynIntro, DewfordTown_Gym_Text_JocelynDefeat, DewfordTown_Gym_EventScript_JocelynBrightenRoom
	msgbox DewfordTown_Gym_Text_JocelynPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_JocelynBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Laura::
	trainerbattle_single TRAINER_LAURA, DewfordTown_Gym_Text_LauraIntro, DewfordTown_Gym_Text_LauraDefeat, DewfordTown_Gym_EventScript_LauraBrightenRoom
	msgbox DewfordTown_Gym_Text_LauraPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_LauraBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Brenden::
	trainerbattle_single TRAINER_BRENDEN, DewfordTown_Gym_Text_BrendenIntro, DewfordTown_Gym_Text_BrendenDefeat, DewfordTown_Gym_EventScript_BrendenBrightenRoom
	msgbox DewfordTown_Gym_Text_BrendenPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_BrendenBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Cristian::
	trainerbattle_single TRAINER_HARVEY, DewfordTown_Gym_Text_CristianIntro, DewfordTown_Gym_Text_CristianDefeat, DewfordTown_Gym_EventScript_CristianBrightenRoom
	msgbox DewfordTown_Gym_Text_CristianPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_CristianBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Lilith::
	trainerbattle_single TRAINER_LILITH, DewfordTown_Gym_Text_LilithIntro, DewfordTown_Gym_Text_LilithDefeat, DewfordTown_Gym_EventScript_LilithBrightenRoom
	msgbox DewfordTown_Gym_Text_LilithPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_LilithBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_AZALEA_TOWN_GYM, DewfordTown_Gym_EventScript_GymGuidePostVictory
	msgbox DewfordTown_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

DewfordTown_Gym_EventScript_GymGuidePostVictory::
	msgbox DewfordTown_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

DewfordTown_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE02_GET, DewfordTown_Gym_EventScript_GymStatueCertified
	goto DewfordTown_Gym_EventScript_GymStatue
	end

DewfordTown_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE02_GET, DewfordTown_Gym_EventScript_GymStatueCertified
	goto DewfordTown_Gym_EventScript_GymStatue
	end

DewfordTown_Gym_EventScript_GymStatueCertified::
	msgbox DewfordTown_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Gym_EventScript_GymStatue::
	msgbox DewfordTown_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Gym_Text_GymGuideAdvice:
	.string "Salut, comment ça va, FUTUR CHAMPION\n"
	.string "{PLAYER} ?\p"
	.string "Le CHAMPION de l'ARÈNE de MYOKARA, BASTIEN,\n"
	.string "utilise des POKéMON de type COMBAT.\p"
	.string "Affronter ce type avec des POKéMON de type\n"
	.string "NORMAL, c'est risqué.\p"
	.string "Les POKéMON de type COMBAT vont sérieusement\n"
	.string "malmener les POKéMON de type NORMAL,\l"
	.string "alors fais attention !\p"
	.string "En plus, l'ARÈNE est aussi sombre que\n"
	.string "le fond de l'océan.\p"
	.string "Mais elle s'éclaircira à mesure que tu bats\n"
	.string "les DRESSEURS sur ton chemin.\p"
	.string "Allez, vas-y, fonce !$"

DewfordTown_Gym_Text_GymGuidePostVictory:
	.string "Ouah ! Il fait trop clair ici maintenant !\p"
	.string "Ton avenir est lumineux aussi !$"

DewfordTown_Gym_Text_TakaoIntro:
	.string "La force fait la loi !\n"
	.string "Allez, viens !$"

DewfordTown_Gym_Text_TakaoDefeat:
	.string "Pas assez de puissance…$"

DewfordTown_Gym_Text_TakaoPostBattle:
	.string "Ta technique a surpassé ma force !\n"
	.string "Ta façon de combattre est remarquable !$"

DewfordTown_Gym_Text_JocelynIntro:
	.string "Pas besoin que BASTIEN intervienne !\p"
	.string "Je vais t'écraser !$"

DewfordTown_Gym_Text_JocelynDefeat:
	.string "Mais… Comment ?\n"
	.string "Comment ai-je pu perdre si facilement ?$"

DewfordTown_Gym_Text_JocelynPostBattle:
	.string "Je ne vais pas gaspiller cette défaite.\n"
	.string "Je vais m'en servir pour m'entraîner !\p"
	.string "Un jour, je deviendrai CHAMPIONNE D'ARÈNE…\p"
	.string "Non, je deviendrai la MAÎTRESSE de la\n"
	.string "LIGUE POKéMON !$"

DewfordTown_Gym_Text_LauraIntro:
	.string "N'essaie même pas de m'ignorer !\n"
	.string "Ce n'est pas ma faute si tu pleures !$"

DewfordTown_Gym_Text_LauraDefeat:
	.string "Ouin ouin ouin !\n"
	.string "J'ai perdu !$"

DewfordTown_Gym_Text_LauraPostBattle:
	.string "Je combats dans le noir pour renforcer\n"
	.string "mon cœur.\p"
	.string "Mais comme il fait si sombre, je ne vois\n"
	.string "jamais le visage de BASTIEN…$"

DewfordTown_Gym_Text_LilithIntro:
	.string "Ufufu…\n"
	.string "Tu te perds dans le noir ?$"

DewfordTown_Gym_Text_LilithDefeat:
	.string "Oh, toi…\n"
	.string "Je ne veux plus te connaître !$"

DewfordTown_Gym_Text_LilithPostBattle:
	.string "Tu mérites de rester perdu et de finir\n"
	.string "encore à l'entrée !$"

DewfordTown_Gym_Text_BrendenIntro:
	.string "Je vais te montrer la ténacité\n"
	.string "d'un marin !$"

DewfordTown_Gym_Text_BrendenDefeat:
	.string "Comment c'est arrivé ?\n"
	.string "Ce n'est pas mon genre de perdre ainsi !$"

DewfordTown_Gym_Text_BrendenPostBattle:
	.string "Oh, ouais ! Tu mérites de rencontrer\n"
	.string "notre CHAMPION D'ARÈNE !$"

DewfordTown_Gym_Text_CristianIntro:
	.string "Si tu veux passer, il faudra\n"
	.string "d'abord me battre !$"

DewfordTown_Gym_Text_CristianDefeat:
	.string "Grrrrr !\n"
	.string "Complètement dépassé !$"

DewfordTown_Gym_Text_CristianPostBattle:
	.string "Tu as gagné !\n"
	.string "Va chercher ce BADGE !$"

DewfordTown_Gym_Text_BrawlyIntro:
	.string "Je suis BASTIEN !\n"
	.string "CHAMPION de l'ARÈNE de MYOKARA !\p"
	.string "J'ai été forgé par les vagues déchaînées\n"
	.string "de cette région, et je suis devenu fort\l"
	.string "dans la grotte noire comme la nuit !\p"
	.string "Alors tu veux me défier ?\n"
	.string "Voyons de quoi tu es capable !$"

DewfordTown_Gym_Text_BrawlyDefeat:
	.string "Ouah, impressionnant ! Tu as fait une\n"
	.string "bien plus grosse vague que prévu !\p"
	.string "Tu m'as submergé !\p"
	.string "Ok, tu m'as eu.\n"
	.string "Prends ce BADGE D'ARÈNE !$"

DewfordTown_Gym_Text_ReceivedKnuckleBadge:
	.string "{PLAYER} reçoit le BADGE POING\n"
	.string "de BASTIEN.$"

DewfordTown_Gym_Text_KnuckleBadgeInfoTakeThis:
	.string "Le BADGE POING fait obéir tous les POKéMON\n"
	.string "jusqu'au niveau 30, même ceux échangés,\l"
	.string "sans discuter.\p"
	.string "Et tu pourras utiliser la CS FLASH\n"
	.string "en dehors des combats.\p"
	.string "Si tu veux, prends aussi cette\n"
	.string "CAPSULE TECHNIQUE.$"

DewfordTown_Gym_Text_ExplainBulkUp:
	.string "Cette CT08 contient GONFLET.\p"
	.string "C'est une capacité qui augmente à la fois\n"
	.string "l'ATTAQUE et la DÉFENSE.\p"
	.string "… … … … … …$"

DewfordTown_Gym_Text_RegisteredBrawly:
	.string "CHAMPION BASTIEN enregistré\n"
	.string "dans le POKéNAV.$"

DewfordTown_Gym_Text_BrawlyPostBattle:
	.string "Je vois ton talent devenir une immense\n"
	.string "vague qui étonnera tous les DRESSEURS\l"
	.string "un jour !$"

DewfordTown_Gym_Text_GymStatue:
	.string "ARÈNE POKéMON DE MYOKARA$"

DewfordTown_Gym_Text_GymStatueCertified:
	.string "ARÈNE POKéMON DE MYOKARA\p"
	.string "DRESSEURS CERTIFIÉS PAR BASTIEN :\n"
	.string "{PLAYER}$"

DewfordTown_Gym_Text_BrawlyPreRematch:
	.string "BASTIEN : Une vague peut se retirer, mais\n"
	.string "elle revient toujours sur la plage.\p"
	.string "Une vague de talent comme la tienne…\n"
	.string "Je savais que tu reviendrais !\p"
	.string "Montre-moi jusqu'où tu es allé !$"

DewfordTown_Gym_Text_BrawlyRematchDefeat:
	.string "Ouah !\n"
	.string "Encore submergé !$"

DewfordTown_Gym_Text_BrawlyPostRematch:
	.string "BASTIEN : Le combat est vaste et profond.\n"
	.string "On n'en voit pas le fond.\l"
	.string "C'est comme la mer de HOENN !$"

DewfordTown_Gym_Text_BrawlyRematchNeedTwoMons:
	.string "BASTIEN : Une vague peut se retirer, mais\n"
	.string "elle revient toujours sur la plage.\p"
	.string "Une vague de talent comme la tienne…\n"
	.string "Je savais que tu reviendrais !\p"
	.string "Oh ? Tu n'as qu'un seul POKéMON\n"
	.string "en état de combattre.\p"
	.string "Désolé, mais reviens avec au moins\n"
	.string "deux POKéMON.$"
