.set LOCALID_COLE, 2
.set LOCALID_GERALD, 3
.set LOCALID_AXLE, 4
.set LOCALID_DANIELLE, 5

LavaridgeTown_Gym_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavaridgeTown_Gym_1F_OnTransition
	.byte 0

LavaridgeTown_Gym_1F_OnTransition:
	call LavaridgeTown_Gym_1F_EventScript_SetTrainerTempVars
	call LavaridgeTown_Gym_1F_EventScript_CheckBuryTrainers
	end

@ Unclear where/if these temp vars are getting checked
LavaridgeTown_Gym_1F_EventScript_SetTrainerTempVars::
	setvar VAR_TEMP_B, 0
	setvar VAR_TEMP_C, 0
	setvar VAR_TEMP_D, 0
	setvar VAR_TEMP_E, 0
	setvar VAR_TEMP_F, 0
	goto_if_defeated TRAINER_COLE, LavaridgeTown_Gym_1F_EventScript_SetGeraldTempVar
	setvar VAR_TEMP_B, 1
LavaridgeTown_Gym_1F_EventScript_SetGeraldTempVar::
	goto_if_defeated TRAINER_RUSSELL, LavaridgeTown_Gym_1F_EventScript_SetAxleTempVar
	setvar VAR_TEMP_C, 1
LavaridgeTown_Gym_1F_EventScript_SetAxleTempVar::
	goto_if_defeated TRAINER_COREY, LavaridgeTown_Gym_1F_EventScript_SetDanielleTempVar
	setvar VAR_TEMP_D, 1
LavaridgeTown_Gym_1F_EventScript_SetDanielleTempVar::
	goto_if_defeated TRAINER_JIM, LavaridgeTown_Gym_1F_EventScript_EndSetTrainerTempVars
	setvar VAR_TEMP_E, 1
LavaridgeTown_Gym_1F_EventScript_EndSetTrainerTempVars::
	return

LavaridgeTown_Gym_1F_EventScript_CheckBuryTrainers::
	goto_if_defeated TRAINER_COLE, LavaridgeTown_Gym_1F_EventScript_CheckBuryGerald
	setobjectmovementtype LOCALID_COLE, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_1F_EventScript_CheckBuryGerald::
	goto_if_defeated TRAINER_RUSSELL, LavaridgeTown_Gym_1F_EventScript_CheckBuryAxle
	setobjectmovementtype LOCALID_GERALD, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_1F_EventScript_CheckBuryAxle::
	goto_if_defeated TRAINER_COREY, LavaridgeTown_Gym_1F_EventScript_CheckBuryDanielle
	setobjectmovementtype LOCALID_AXLE, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_1F_EventScript_CheckBuryDanielle::
	goto_if_defeated TRAINER_JIM, LavaridgeTown_Gym_1F_EventScript_EndCheckBuryTrainers
	setobjectmovementtype LOCALID_DANIELLE, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_1F_EventScript_EndCheckBuryTrainers::
	return

LavaridgeTown_Gym_1F_EventScript_Flannery::
	trainerbattle_single TRAINER_PING, LavaridgeTown_Gym_1F_Text_FlanneryIntro, LavaridgeTown_Gym_1F_Text_FlanneryDefeat, LavaridgeTown_Gym_1F_EventScript_FlanneryDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, LavaridgeTown_Gym_1F_EventScript_FlanneryRematch
	goto_if_unset FLAG_RECEIVED_TM_OVERHEAT, LavaridgeTown_Gym_1F_EventScript_GiveOverheat2
	msgbox LavaridgeTown_Gym_1F_Text_FlanneryPostBattle, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_Gym_1F_EventScript_FlanneryDefeated::
	message LavaridgeTown_Gym_1F_Text_ReceivedHeatBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox LavaridgeTown_Gym_1F_Text_ExplainHeatBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_WHITEOUT_TO_LAVARIDGE
	setflag FLAG_DEFEATED_ECRUTEAK_CITY_GYM
	setflag FLAG_BADGE04_GET
	addvar VAR_GARBAGEVAR, 1
	call_if_eq VAR_GARBAGEVAR, 6, Common_EventScript_ReadyPetalburgGymForBattle
	setvar VAR_0x8008, 4
	call Common_EventScript_SetGymTrainers
	setflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLY
	setvar VAR_GARBAGEVAR, 1
	call LavaridgeTown_Gym_1F_EventScript_GiveOverheat
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox LavaridgeTown_Gym_1F_Text_RegisteredFlannery, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_FLANNERY_MATCH_CALL
	release
	end

LavaridgeTown_Gym_1F_EventScript_GiveOverheat2::
	giveitem ITEM_TM_OVERHEAT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox LavaridgeTown_Gym_1F_Text_ExplainOverheat, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_OVERHEAT
	release
	end

LavaridgeTown_Gym_1F_EventScript_GiveOverheat::
	giveitem ITEM_TM_OVERHEAT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox LavaridgeTown_Gym_1F_Text_ExplainOverheat, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_OVERHEAT
	return

LavaridgeTown_Gym_1F_EventScript_FlanneryRematch::
	trainerbattle_rematch_double TRAINER_PING, LavaridgeTown_Gym_1F_Text_FlanneryPreRematch, LavaridgeTown_Gym_1F_Text_FlanneryRematchDefeat, LavaridgeTown_Gym_1F_Text_FlanneryRematchNeedTwoMons
	msgbox LavaridgeTown_Gym_1F_Text_FlanneryPostRematch, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_Cole::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_COLE, LOCALID_COLE, LavaridgeTown_Gym_1F_Text_ColeIntro, LavaridgeTown_Gym_1F_Text_ColeDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_1F_Text_ColePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_EventScript_CheckTrainerScript::
	call LavaridgeTown_Gym_1F_EventScript_SetTrainerTempVars
	release
	special ShouldTryGetTrainerScript
	goto_if_eq VAR_RESULT, 1, EventScript_GotoTrainerScript
	end

LavaridgeTown_Gym_1F_EventScript_Axle::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_COREY, LOCALID_AXLE, LavaridgeTown_Gym_1F_Text_AxleIntro, LavaridgeTown_Gym_1F_Text_AxleDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_1F_Text_AxlePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Keegan::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_KEEGAN, LOCALID_KEEGAN, LavaridgeTown_Gym_B1F_Text_KeeganIntro, LavaridgeTown_Gym_B1F_Text_KeeganDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_B1F_Text_KeeganPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_Danielle::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_JIM, LOCALID_DANIELLE, LavaridgeTown_Gym_1F_Text_DanielleIntro, LavaridgeTown_Gym_1F_Text_DanielleDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_1F_Text_DaniellePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_Gerald::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_RUSSELL, LOCALID_GERALD, LavaridgeTown_Gym_1F_Text_GeraldIntro, LavaridgeTown_Gym_1F_Text_GeraldDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_1F_Text_GeraldPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Jace::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_KOGA_2, LOCALID_JACE, LavaridgeTown_Gym_B1F_Text_JaceIntro, LavaridgeTown_Gym_B1F_Text_JaceDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_B1F_Text_JacePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Jeff::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_JEFF, LOCALID_JEFF, LavaridgeTown_Gym_B1F_Text_JeffIntro, LavaridgeTown_Gym_B1F_Text_JeffDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_B1F_Text_JeffPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Eli::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_ELI, LOCALID_ELI, LavaridgeTown_Gym_B1F_Text_EliIntro, LavaridgeTown_Gym_B1F_Text_EliDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_B1F_Text_EliPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_ECRUTEAK_CITY_GYM, LavaridgeTown_Gym_1F_EventScript_GymGuidePostVictory
	msgbox LavaridgeTown_Gym_1F_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_Gym_1F_EventScript_GymGuidePostVictory::
	msgbox LavaridgeTown_Gym_1F_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_Gym_1F_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE04_GET, LavaridgeTown_Gym_1F_EventScript_GymStatueCertified
	goto LavaridgeTown_Gym_1F_EventScript_GymStatue
	end

LavaridgeTown_Gym_1F_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE04_GET, LavaridgeTown_Gym_1F_EventScript_GymStatueCertified
	goto LavaridgeTown_Gym_1F_EventScript_GymStatue
	end

LavaridgeTown_Gym_1F_EventScript_GymStatueCertified::
	msgbox LavaridgeTown_Gym_1F_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

LavaridgeTown_Gym_1F_EventScript_GymStatue::
	msgbox LavaridgeTown_Gym_1F_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

LavaridgeTown_Gym_1F_Text_GymGuideAdvice:
	.string "Salut, comment ça va, FUTUR\n"
	.string "CHAMPION {PLAYER} ?\p"
	.string "La CHAMPIONNE d'ARENE de VERMILAVA,\n"
	.string "FLANNERY, utilise des POKéMON de type FEU.\p"
	.string "Sa passion pour les POKéMON brûle plus fort\n"
	.string "et plus chaud qu'un volcan.\p"
	.string "Ne t'approche pas trop d'elle—tu vas te brûler !\n"
	.string "Arrose-la d'eau puis fonce !$"

LavaridgeTown_Gym_1F_Text_GymGuidePostVictory:
	.string "Aïe ! Quel combat brûlant !$"

LavaridgeTown_Gym_1F_Text_ColeIntro:
	.string "Aïe aïe aïe aïe !\n"
	.string "Ouh là, il fait chaud !$"

LavaridgeTown_Gym_1F_Text_ColeDefeat:
	.string "J'ai la sueur dans les yeux… Je ne vois plus !$"

LavaridgeTown_Gym_1F_Text_ColePostBattle:
	.string "Être enterré dans le sable chaud favorise\n"
	.string "la circulation.\p"
	.string "C'est efficace pour soulager les douleurs\n"
	.string "articulaires.$"

LavaridgeTown_Gym_1F_Text_AxleIntro:
	.string "J'essaie de me détendre.\n"
	.string "Ne viens pas me stresser !$"

LavaridgeTown_Gym_1F_Text_AxleDefeat:
	.string "J'espère que FLANNERY va bien te brûler !$"

LavaridgeTown_Gym_1F_Text_AxlePostBattle:
	.string "Haaah… Ouf…\p"
	.string "Si tu restes trop longtemps enterré dans\n"
	.string "le sable chaud, tu finis épuisé…$"

LavaridgeTown_Gym_B1F_Text_KeeganIntro:
	.string "Tu dois commencer à être fatigué.\n"
	.string "Tu voudrais te reposer dans le sable chaud,\l"
	.string "n'est-ce pas ?\p"
	.string "Mais tu dois savoir que garder sa volonté\n"
	.string "est une capacité importante\l"
	.string "pour tous les DRESSEURS.$"

LavaridgeTown_Gym_B1F_Text_KeeganDefeat:
	.string "Qui joue avec le feu se brûle…$"

LavaridgeTown_Gym_B1F_Text_KeeganPostBattle:
	.string "Tu as du talent…\n"
	.string "Mais notre CHAMPIONNE FLANNERY est forte.\p"
	.string "Si tu ne fais pas attention, tu vas\n"
	.string "vraiment te brûler.$"

LavaridgeTown_Gym_1F_Text_GeraldIntro:
	.string "Tes POKéMON peuvent-ils supporter\n"
	.string "une chaleur de 392 degrés ?$"

LavaridgeTown_Gym_1F_Text_GeraldDefeat:
	.string "Ça n'a pas assez chauffé…$"

LavaridgeTown_Gym_1F_Text_GeraldPostBattle:
	.string "La température du magma est de\n"
	.string "392 degrés.\p"
	.string "Tes POKéMON m'ont battu, ils devraient\n"
	.string "survivre facilement dans le magma.$"

LavaridgeTown_Gym_1F_Text_DanielleIntro:
	.string "Euh…\n"
	.string "Bon, je vais me battre avec toi.$"

LavaridgeTown_Gym_1F_Text_DanielleDefeat:
	.string "Oh, mais tu es trop fort.$"

LavaridgeTown_Gym_1F_Text_DaniellePostBattle:
	.string "Je vais devenir une DRESSEUSE belle et forte\n"
	.string "comme FLANNERY.$"

LavaridgeTown_Gym_B1F_Text_JaceIntro:
	.string "Allez, dépêche-toi !\n"
	.string "Allons-y avant que mes ardeurs ne retombent !$"

LavaridgeTown_Gym_B1F_Text_JaceDefeat:
	.string "Il fait si chaud, et pourtant mon cœur\n"
	.string "est glacé…$"

LavaridgeTown_Gym_B1F_Text_JacePostBattle:
	.string "La façon dont l'esprit combatif brûle\n"
	.string "en toi, tu pourrais bien avoir une chance\l"
	.string "contre notre CHAMPIONNE.$"

LavaridgeTown_Gym_B1F_Text_JeffIntro:
	.string "Tu vois comme les flammes s'élèvent ?\n"
	.string "Elles flambent en attendant ma victoire !$"

LavaridgeTown_Gym_B1F_Text_JeffDefeat:
	.string "Quelque chose n'a pas marché.$"

LavaridgeTown_Gym_B1F_Text_JeffPostBattle:
	.string "Et alors ? Je dis et alors ?\n"
	.string "Je peux marcher pieds nus sur des braises !\p"
	.string "…N'essaie même pas !$"

LavaridgeTown_Gym_B1F_Text_EliIntro:
	.string "J'adore les montagnes,\n"
	.string "mais j'aime encore plus les volcans.$"

LavaridgeTown_Gym_B1F_Text_EliDefeat:
	.string "On dirait bien que j'ai perdu sans\n"
	.string "jamais avoir eu le contrôle.$"

LavaridgeTown_Gym_B1F_Text_EliPostBattle:
	.string "Je reste ici parce que je suis devenu fan\n"
	.string "de la puissance de FLANNERY.\p"
	.string "Hehehehe.$"

LavaridgeTown_Gym_1F_Text_FlanneryIntro:
	.string "Bienvenue… Non, attends.\p"
	.string "Petit DRESSEUR, je suis ravie de voir\n"
	.string "que tu es arrivé jusqu'ici !\p"
	.string "On m'a confié le…\n"
	.string "Non, attends.\p"
	.string "Je suis FLANNERY, la CHAMPIONNE\n"
	.string "de cette ARÈNE !\p"
	.string "Euh…\n"
	.string "Ne me sous-estime pas, même si\l"
	.string "je ne suis CHAMPIONNE que depuis peu !\p"
	.string "Avec les compétences héritées de mon grand-\n"
	.string "père, je vais, euh… te montrer les\l"
	.string "attaques brûlantes que nous avons perfectionnées ici !$"

LavaridgeTown_Gym_1F_Text_FlanneryDefeat:
	.string "Oh…\n"
	.string "Je crois que j'en ai trop fait…\p"
	.string "Je… Je viens seulement de devenir\n"
	.string "CHAMPIONNE d'ARÈNE.\p"
	.string "J'ai trop essayé d'être quelqu'un\n"
	.string "d'autre.\p"
	.string "Je dois agir naturellement. Sinon,\n"
	.string "mes POKéMON seront perdus.\p"
	.string "Merci de m'avoir appris ça.\n"
	.string "Pour ça, tu mérites ceci.$"

LavaridgeTown_Gym_1F_Text_ReceivedHeatBadge:
	.string "{PLAYER} reçoit le BADGE CHALEUR\n"
	.string "de FLANNERY.$"

LavaridgeTown_Gym_1F_Text_ExplainHeatBadgeTakeThis:
	.string "Si tu as le BADGE CHALEUR, tous les POKéMON\n"
	.string "jusqu'au niveau 50, même ceux reçus\l"
	.string "par échange, t'obéiront complètement.\p"
	.string "Et il permet aux POKéMON d'utiliser la CS FORCE\n"
	.string "en dehors des combats.\p"
	.string "Ceci est un signe de ma gratitude.\n"
	.string "N'hésite pas à le prendre !$"

LavaridgeTown_Gym_1F_Text_ExplainOverheat:
	.string "La CT50 contient SURCHAUFFE.\p"
	.string "Cette attaque inflige de gros dégâts\n"
	.string "à l'adversaire.\p"
	.string "Mais elle baisse fortement l'ATQ. SPÉ.\n"
	.string "du POKéMON qui l'utilise. Ce n'est peut-être\l"
	.string "pas idéal pour les longs combats.$"

LavaridgeTown_Gym_1F_Text_RegisteredFlannery:
	.string "CHAMPIONNE d'ARÈNE FLANNERY\n"
	.string "enregistrée dans le POKéNAV.$"

LavaridgeTown_Gym_1F_Text_FlanneryPostBattle:
	.string "Ta puissance me rappelle quelqu'un…\p"
	.string "Oh ! Je sais ! Tu combats comme NORMAN,\n"
	.string "le CHAMPION d'ARÈNE de CLEMENTI-VILLE.$"

LavaridgeTown_Gym_1F_Text_GymStatue:
	.string "ARÈNE POKéMON DE VERMILAVA$"

LavaridgeTown_Gym_1F_Text_GymStatueCertified:
	.string "ARÈNE POKéMON DE VERMILAVA\p"
	.string "DRESSEURS CERTIFIÉS PAR FLANNERY :\n"
	.string "{PLAYER}$"

LavaridgeTown_Gym_1F_Text_FlanneryPreRematch:
	.string "FLANNERY : Perdre un combat ne va pas\n"
	.string "me décourager.\p"
	.string "J'aime les POKéMON.\n"
	.string "J'aime me battre.\l"
	.string "Et… j'adore cette ARÈNE !\p"
	.string "Échangeons des attaques brûlantes\n"
	.string "dans un autre combat !$"

LavaridgeTown_Gym_1F_Text_FlanneryRematchDefeat:
	.string "Ouf !\n"
	.string "Prête à exploser !$"

LavaridgeTown_Gym_1F_Text_FlanneryPostRematch:
	.string "FLANNERY : J'ai perdu le match,\n"
	.string "mais je suis complètement satisfaite.\p"
	.string "Ce n'est pas souvent que je peux profiter\n"
	.string "d'un combat aussi intense.\p"
	.string "Refaisons ça encore une fois\n"
	.string "un de ces jours !$"

LavaridgeTown_Gym_1F_Text_FlanneryRematchNeedTwoMons:
	.string "FLANNERY : Perdre un combat ne va pas\n"
	.string "me décourager.\p"
	.string "J'aime les POKéMON.\n"
	.string "J'aime me battre.\l"
	.string "Et… j'adore cette ARÈNE !\p"
	.string "Échangeons des attaques brûlantes\n"
	.string "dans un autre combat !\p"
	.string "Oh, attends. Tu n'as qu'un seul POKéMON\n"
	.string "en état de combattre ?\p"
	.string "Je déteste dire ça, mais quand tu viens\n"
	.string "me voir, amène au moins deux POKéMON.$"
