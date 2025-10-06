.set LOCALID_ARCHIE, 2
.set LOCALID_OLD_LADY, 3
.set LOCALID_GRUNT_1, 4
.set LOCALID_GRUNT_2, 5
.set LOCALID_GRUNT_3, 6
.set LOCALID_GRUNT_4, 7
.set LOCALID_MAXIE, 8

MtPyre_Summit_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtPyre_Summit_OnTransition
	.byte 0

MtPyre_Summit_OnTransition:
	call_if_eq VAR_MT_PYRE_STATE, 2, MtPyre_Summit_EventScript_SetArchieMaxiePositions
	end

MtPyre_Summit_EventScript_SetArchieMaxiePositions::
	setobjectxyperm LOCALID_MAXIE, 23, 6
	setobjectxyperm LOCALID_ARCHIE, 22, 6
	end

MtPyre_Summit_EventScript_TeamAquaTrigger0::
	lockall
	setvar VAR_0x8008, 0
	goto MtPyre_Summit_EventScript_TeamAquaExits
	end

MtPyre_Summit_EventScript_TeamAquaTrigger1::
	lockall
	setvar VAR_0x8008, 1
	goto MtPyre_Summit_EventScript_TeamAquaExits
	end

MtPyre_Summit_EventScript_TeamAquaTrigger2::
	lockall
	setvar VAR_0x8008, 2
	goto MtPyre_Summit_EventScript_TeamAquaExits
	end

MtPyre_Summit_EventScript_TeamAquaExits::
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	applymovement LOCALID_ARCHIE, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 50
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_ArchieFacePlayer0
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_ArchieFacePlayer1
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_ArchieFacePlayer2
	msgbox MtPyre_Summit_Text_ArchieWeGotTheOrbLetsGo, MSGBOX_DEFAULT
	closemessage
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_ARCHIE
	removeobject LOCALID_GRUNT_1
	removeobject LOCALID_GRUNT_2
	removeobject LOCALID_GRUNT_3
	removeobject LOCALID_GRUNT_4
	setflag FLAG_GARBAGEFLAG
	setflag FLAG_GARBAGEFLAG
	fadedefaultbgm
	fadescreenswapbuffers FADE_FROM_BLACK
	delay 20
	setvar VAR_MT_PYRE_STATE, 1
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_OldLadyApproachPlayer0
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_OldLadyApproachPlayer1
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_OldLadyApproachPlayer2
	msgbox MtPyre_Summit_Text_BothOrbsTakenMagmaLeftThis, MSGBOX_DEFAULT
	giveitem ITEM_MAGMA_EMBLEM
	setflag FLAG_RECEIVED_RED_OR_BLUE_ORB
	setflag FLAG_GARBAGEFLAG
	releaseall
	end

MtPyre_Summit_EventScript_ArchieFacePlayer0::
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieFacePlayer0
	waitmovement 0
	return

@ Archie is already facing player
MtPyre_Summit_EventScript_ArchieFacePlayer1::
	return

MtPyre_Summit_EventScript_ArchieFacePlayer2::
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieFacePlayer2
	waitmovement 0
	return

MtPyre_Summit_EventScript_OldLadyApproachPlayer0::
	applymovement LOCALID_OLD_LADY, MtPyre_Summit_Movement_OldLadyApproachPlayer0
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

MtPyre_Summit_EventScript_OldLadyApproachPlayer1::
	applymovement LOCALID_OLD_LADY, MtPyre_Summit_Movement_OldLadyApproachPlayer1
	waitmovement 0
	return

MtPyre_Summit_EventScript_OldLadyApproachPlayer2::
	applymovement LOCALID_OLD_LADY, MtPyre_Summit_Movement_OldLadyApproachPlayer2
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

MtPyre_Summit_Movement_OldLadyApproachPlayer0:
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

MtPyre_Summit_Movement_OldLadyApproachPlayer1:
	walk_down
	step_end

MtPyre_Summit_Movement_OldLadyApproachPlayer2:
	walk_down
	walk_down
	walk_in_place_faster_right
	step_end

MtPyre_Summit_Movement_ArchieFacePlayer0:
	walk_left
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_ArchieFacePlayer2:
	walk_right
	walk_in_place_faster_down
	step_end

MtPyre_Summit_EventScript_OldMan::
	lock
	faceplayer
	goto_if_set FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE, MtPyre_Summit_EventScript_OldManAfterRayquaza
	msgbox MtPyre_Summit_Text_WillYouHearOutMyTale, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, MtPyre_Summit_EventScript_OldManTale
	call_if_eq VAR_RESULT, NO, MtPyre_Summit_EventScript_DeclineOldManTale
	release
	end

MtPyre_Summit_EventScript_OldManAfterRayquaza::
	msgbox MtPyre_Summit_Text_HearTheNewLegendOfHoenn, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, MtPyre_Summit_EventScript_OldManNewTale
	call_if_eq VAR_RESULT, NO, MtPyre_Summit_EventScript_DeclineOldManTale
	release
	end

MtPyre_Summit_EventScript_OldManTale::
	msgbox MtPyre_Summit_Text_GroudonKyogreTale, MSGBOX_DEFAULT
	return

MtPyre_Summit_EventScript_DeclineOldManTale::
	msgbox MtPyre_Summit_Text_WellThatTooIsFine, MSGBOX_DEFAULT
	return

MtPyre_Summit_EventScript_OldManNewTale::
	msgbox MtPyre_Summit_Text_HoennTrioTale, MSGBOX_DEFAULT
	return

MtPyre_Summit_EventScript_OldLady::
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_RED_OR_BLUE_ORB, MtPyre_Summit_EventScript_OldLadyAfterOrbsReturned
	call_if_ge VAR_MT_PYRE_STATE, 3, MtPyre_Summit_EventScript_OldLadyOrbsReturned
	goto_if_set FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, MtPyre_Summit_EventScript_OldLadyLegendariesAwake
	msgbox MtPyre_Summit_Text_OrbsHaveBeenTaken, MSGBOX_DEFAULT
	release
	end

MtPyre_Summit_EventScript_OldLadyOrbsReturned::
	msgbox MtPyre_Summit_Text_ThoseTwoMenReturnedOrbs, MSGBOX_DEFAULT
	setflag FLAG_RETURNED_RED_OR_BLUE_ORB
	release
	end

MtPyre_Summit_EventScript_OldLadyLegendariesAwake::
	msgbox MtPyre_Summit_Text_GroudonKyogreAwakened, MSGBOX_DEFAULT
	release
	end

MtPyre_Summit_EventScript_OldLadyAfterOrbsReturned::
	msgbox MtPyre_Summit_Text_SuperAncientPokemonTaughtUs, MSGBOX_DEFAULT
	release
	end

MtPyre_Summit_EventScript_ArchieMaxieTrigger0::
	lockall
	setvar VAR_0x8008, 0
	goto MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs
	end

MtPyre_Summit_EventScript_ArchieMaxieTrigger1::
	lockall
	setvar VAR_0x8008, 1
	goto MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs
	end

MtPyre_Summit_EventScript_ArchieMaxieTrigger2::
	lockall
	setvar VAR_0x8008, 2
	goto MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs
	end

MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 60
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_ArchieMaxieBeginExit0
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_ArchieMaxieBeginExit1
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_ArchieMaxieBeginExit2
	playse SE_PIN
	applymovement LOCALID_MAXIE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MAXIE, Common_Movement_Delay48
	waitmovement 0
	delay 30
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_MaxieApproachPlayer0
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_MaxieApproachPlayer1
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_MaxieApproachPlayer2
	msgbox MtPyre_Summit_Text_MaxieSilence, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_MaxieApproachArchie0
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_MaxieApproachArchie1
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_MaxieApproachArchie2
	delay 30
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieExit
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieExit
	waitmovement 0
	removeobject LOCALID_ARCHIE
	removeobject LOCALID_MAXIE
	setvar VAR_MT_PYRE_STATE, 3
	releaseall
	end

MtPyre_Summit_EventScript_ArchieMaxieBeginExit0::
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit0
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieExit
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieExit
	waitmovement 0
	return

MtPyre_Summit_EventScript_ArchieMaxieBeginExit1::
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit1
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieExit
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieExit
	waitmovement 0
	return

MtPyre_Summit_EventScript_ArchieMaxieBeginExit2::
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit2
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieExit
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieExit
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachPlayer0::
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerFaceMaxie0
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieWatchMaxie
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieApproachPlayer0
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachPlayer1::
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerFaceMaxie
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieWatchMaxie
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieApproachPlayer1
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachPlayer2::
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerFaceMaxie
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieWatchMaxie
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieApproachPlayer2
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachArchie0::
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerWatchMaxie
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieApproachArchie0
	waitmovement 0
	applymovement LOCALID_ARCHIE, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachArchie1::
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerWatchMaxie
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieApproachArchie1
	waitmovement 0
	applymovement LOCALID_ARCHIE, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachArchie2::
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerWatchMaxie
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieApproachArchie2
	waitmovement 0
	applymovement LOCALID_ARCHIE, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

MtPyre_Summit_Movement_PlayerFaceMaxie0:
	delay_16
	delay_16
	walk_in_place_faster_right
	step_end

MtPyre_Summit_Movement_PlayerFaceMaxie:
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

MtPyre_Summit_Movement_ArchieExit:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtPyre_Summit_Movement_MaxieExit:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit0:
	delay_16
	delay_8
	walk_left
	walk_in_place_faster_right
	delay_16
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit1:
	delay_16
	delay_8
	walk_right
	walk_in_place_faster_left
	delay_16
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit2:
	delay_16
	delay_8
	walk_in_place_faster_left
	delay_16
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_MaxieApproachPlayer0:
	walk_up
	walk_up
	walk_up
	walk_left
	step_end

MtPyre_Summit_Movement_MaxieApproachPlayer1:
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_right
	step_end

MtPyre_Summit_Movement_MaxieApproachPlayer2:
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_right
	step_end

MtPyre_Summit_Movement_ArchieWatchMaxie:
	delay_16
	walk_in_place_faster_up
	step_end

MtPyre_Summit_Movement_PlayerWatchMaxie:
	delay_16
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_MaxieApproachArchie0:
	walk_down
	walk_right
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

MtPyre_Summit_Movement_MaxieApproachArchie1:
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

MtPyre_Summit_Movement_MaxieApproachArchie2:
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

MtPyre_Summit_EventScript_Grunt1::
	trainerbattle_single TRAINER_THERESA, MtPyre_Summit_Text_Grunt1Intro, MtPyre_Summit_Text_Grunt1Defeat
	msgbox MtPyre_Summit_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_Summit_EventScript_Grunt2::
	trainerbattle_single TRAINER_TIM, MtPyre_Summit_Text_Grunt2Intro, MtPyre_Summit_Text_Grunt2Defeat
	msgbox MtPyre_Summit_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_Summit_EventScript_Grunt3::
	trainerbattle_single TRAINER_TIMOTHY, MtPyre_Summit_Text_Grunt3Intro, MtPyre_Summit_Text_Grunt3Defeat
	msgbox MtPyre_Summit_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_Summit_EventScript_Grunt4::
	trainerbattle_single TRAINER_TOBY, MtPyre_Summit_Text_Grunt4Intro, MtPyre_Summit_Text_Grunt4Defeat
	msgbox MtPyre_Summit_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_Summit_Text_Grunt1Intro:
	.string "Non ! Ces idiots de la TEAM MAGMA\n"
	.string "sont arrivés avant nous !\p"
	.string "On ne peut pas se laisser distancer !$"

MtPyre_Summit_Text_Grunt1Defeat:
	.string "Je croyais que tu étais un des MAGMA\n"
	.string "qui était revenu…$"

MtPyre_Summit_Text_Grunt1PostBattle:
	.string "Ouais, tu es fort…\n"
	.string "Mais nous sommes nombreux !$"

MtPyre_Summit_Text_Grunt2Intro:
	.string "Ha !\n"
	.string "Dommage pour toi !\p"
	.string "Si tu étais venu plus tôt, tu n'aurais\n"
	.string "eu qu'à affronter les faibles de MAGMA.\p"
	.string "Mais comme tu arrives maintenant, tu\n"
	.string "dois affronter les durs comme nous !$"

MtPyre_Summit_Text_Grunt2Defeat:
	.string "Argh… J'aurais dû te laisser affronter\n"
	.string "la TEAM MAGMA d'abord…$"

MtPyre_Summit_Text_Grunt2PostBattle:
	.string "Tu ne sais rien !\n"
	.string "Alors pourquoi tu t'en prends à nous ?$"

MtPyre_Summit_Text_Grunt3Intro:
	.string "Toi…\n"
	.string "On t'a vu au MT. CHIMNÉE.\p"
	.string "Tu n'es d'aucune des deux TEAM,\n"
	.string "alors pourquoi es-tu ici ?$"

MtPyre_Summit_Text_Grunt3Defeat:
	.string "Si tu veux embêter quelqu'un,\n"
	.string "que ce soit la TEAM MAGMA…$"

MtPyre_Summit_Text_Grunt3PostBattle:
	.string "Heh, peu importe !\n"
	.string "On a gagné un peu de temps !\p"
	.string "Le BOSS a sûrement déjà pris ce\n"
	.string "qu'il voulait !$"

MtPyre_Summit_Text_Grunt4Intro:
	.string "Oh, je sais !\n"
	.string "Tu as essayé de rejoindre la TEAM MAGMA,\l"
	.string "mais ils n'ont pas voulu de toi !\p"
	.string "Eh bien, ne crois pas qu'on va te\n"
	.string "laisser rejoindre la TEAM AQUA !$"

MtPyre_Summit_Text_Grunt4Defeat:
	.string "Si tu veux tant rejoindre la TEAM AQUA,\n"
	.string "on peut y réfléchir…$"

MtPyre_Summit_Text_Grunt4PostBattle:
	.string "On fait une super équipe avec\n"
	.string "nos membres et notre chef.$"

MtPyre_Summit_Text_ArchieWeGotTheOrbLetsGo:
	.string "ARCHIE : MAXIE de la TEAM MAGMA est\n"
	.string "passé devant nous, mais on a aussi ce qu'on voulait.\p"
	.string "L'ORBE ROUGE conservé au MT. PYRÉE…\n"
	.string "Moi, ARCHIE, je l'ai maintenant !\p"
	.string "Fufufu… Maintenant, on va pouvoir\n"
	.string "réaliser notre objectif ultime !\p"
	.string "Allez, l'ÉQUIPE !\n"
	.string "On se retire !$"

MtPyre_Summit_Text_BothOrbsTakenMagmaLeftThis:
	.string "Oh, non…\n"
	.string "Ce n'est pas possible…\p"
	.string "Non seulement l'ORBE BLEUE, mais même\n"
	.string "l'ORBE ROUGE ont été prises…\p"
	.string "Les ORBES BLEUE et ROUGE ne doivent\n"
	.string "jamais être séparées. Elles vont ensemble.\p"
	.string "Que veulent faire ces hommes avec\n"
	.string "les deux ORBES ?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "Ah, oui. C'est la TEAM MAGMA qui est venue\n"
	.string "prendre l'ORBE BLEUE en premier ?\p"
	.string "Eh bien, dans leur précipitation, ils ont\n"
	.string "laissé ceci derrière eux.\p"
	.string "Je n'arrive pas à imaginer ce que\n"
	.string "cela peut être exactement.\p"
	.string "J'aimerais que tu le prennes.\n"
	.string "Peut-être que cela te sera utile.$"

MtPyre_Summit_Text_OrbsHaveBeenTaken:
	.string "Les ORBES BLEUE et ROUGE ont été prises\n"
	.string "par ces hommes sinistres…\p"
	.string "Elles ne doivent jamais être séparées…\n"
	.string "Je crains qu'il arrive quelque chose d'horrible…$"

MtPyre_Summit_Text_GroudonKyogreAwakened:
	.string "Oh, mon dieu…\p"
	.string "Tu dis que GROUDON et KYOGRE ont\n"
	.string "tous deux été réveillés ?\p"
	.string "On dit que l'ORBE BLEUE et\n"
	.string "l'ORBE ROUGE ont calmé la rage\l"
	.string "des deux POKéMON…\p"
	.string "On dit aussi que le véritable propriétaire\n"
	.string "des ORBES existe encore.\p"
	.string "Mais personne ne sait à qui, ou à quoi\n"
	.string "appartiennent vraiment les ORBES.\p"
	.string "Ce pourrait être un humain, ou peut-être\n"
	.string "un POKéMON, mais nul ne le sait.$"

MtPyre_Summit_Text_ThoseTwoMenReturnedOrbs:
	.string "Les deux hommes qui ont pris les ORBES\n"
	.string "sont revenus les rendre d'eux-mêmes.\p"
	.string "Ces hommes…\n"
	.string "Peut-être ne sont-ils pas si mauvais finalement…$"

MtPyre_Summit_Text_SuperAncientPokemonTaughtUs:
	.string "Les incarnations de la terre, de la mer\n"
	.string "et du ciel…\p"
	.string "On dit que ce sont les identités des\n"
	.string "super-anciens POKéMON…\p"
	.string "De la même façon que nous, humains et\n"
	.string "POKéMON, avons la vie, notre monde aussi,\l"
	.string "est vivant…\p"
	.string "Les super-anciens POKéMON nous ont\n"
	.string "appris cela…$"

MtPyre_Summit_Text_WillYouHearOutMyTale:
	.string "Le MT. PYRÉE est l'endroit où nous apaisons\n"
	.string "les esprits des POKéMON disparus…\p"
	.string "C'est un lieu élevé d'où l'on peut voir\n"
	.string "toute la région de HOENN…\p"
	.string "Les esprits désincarnés des POKéMON\n"
	.string "doivent trouver la paix ici…\p"
	.string "Est-ce une coïncidence que tu sois ici…\p"
	.string "Veux-tu entendre mon histoire ? Une histoire\n"
	.string "racontée depuis longtemps à HOENN ?$"

MtPyre_Summit_Text_GroudonKyogreTale:
	.string "Cela s'est passé il y a très, très longtemps…\p"
	.string "Le monde était ravagé par un affrontement\n"
	.string "féroce entre le POKéMON de la terre\l"
	.string "et le POKéMON de la mer…\p"
	.string "Le POKéMON de la terre a soulevé\n"
	.string "des montagnes et créé des continents…\p"
	.string "Le POKéMON de la mer a soulevé d'énormes\n"
	.string "vagues et creusé les océans…\p"
	.string "Leur duel féroce n'avait pas de fin.\p"
	.string "Le monde était englouti dans d'immenses\n"
	.string "enfers et de violentes tempêtes.\p"
	.string "L'ORBE BLEUE et l'ORBE ROUGE mirent\n"
	.string "fin à la calamité.\p"
	.string "La lumière jaillit des deux ORBES et\n"
	.string "apaisa les adversaires enragés.\p"
	.string "Le duo, devenu docile, plongea au fond\n"
	.string "de la mer où, finalement, ils\l"
	.string "disparurent…$"

MtPyre_Summit_Text_WellThatTooIsFine:
	.string "Je vois…\n"
	.string "Eh bien, cela aussi, c'est bien…$"

MtPyre_Summit_Text_MaxieSilence:
	.string "MAXIE : {PLAYER}…\p"
	.string "… … … … … …\n"
	.string "… … … … … …$"

MtPyre_Summit_Text_HearTheNewLegendOfHoenn:
	.string "C'est mon rôle de transmettre les légendes\n"
	.string "de HOENN aux générations futures.\p"
	.string "Et la crise qui vient de se terminer à\n"
	.string "SOOTOPOLIS a réécrit une légende…\p"
	.string "As-tu le temps d'entendre la nouvelle\n"
	.string "légende de HOENN ?$"

MtPyre_Summit_Text_HoennTrioTale:
	.string "Cela s'est passé il y a très, très longtemps…\p"
	.string "Le monde était ravagé par un affrontement\n"
	.string "féroce entre le POKéMON de la terre\l"
	.string "et le POKéMON de la mer…\p"
	.string "Le POKéMON de la terre a soulevé\n"
	.string "des montagnes et créé des continents…\p"
	.string "Le POKéMON de la mer a soulevé d'énormes\n"
	.string "vagues et creusé les océans…\p"
	.string "Leur duel féroce n'avait pas de fin.\p"
	.string "Le monde était englouti dans d'immenses\n"
	.string "incendies et de violentes tempêtes.\p"
	.string "C'est alors que le POKéMON du ciel\n"
	.string "est descendu d'une tempête.\p"
	.string "Le POKéMON, brillant d'un vert éclatant,\n"
	.string "a calmé les deux POKéMON enragés.\p"
	.string "Puis, sa mission accomplie, le POKéMON vert\n"
	.string "s'est envolé vers l'horizon…$"
