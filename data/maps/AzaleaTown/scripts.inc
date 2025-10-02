.set LOCALID_AZALEA_TOWN_KURT_GS, 18
.set LOCALID_AZALEA_TOWN_SILVER, 6

AzaleaTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, AzaleaTown_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, AzaleaTown_OnFrame
	.byte 0

AzaleaTown_OnTransition::
	goto_if_eq VAR_AZALEA_TOWN_STATE, 5, AzaleaTown_MapScript_Hide_Silver
	end
	
AzaleaTown_OnFrame::
	map_script_2 VAR_AZALEA_TOWN_STATE, 8, AzaleaTown_EventScript_GSBall
	.2byte 0

AzaleaTown_MapScript_Hide_Silver:
	setflag FLAG_HIDE_AZALEA_TOWN_SILVER
	removeobject LOCALID_AZALEA_TOWN_SILVER
	end

AzaleaTown_EventScript_Trigger:: @flagheap
	setflag FLAG_VISITED_AZALEA_TOWN
	setflag FLAG_HIDE_AZALEA_TOWN_SLOWPOKE
	setflag FLAG_HIDE_AZALEA_TOWN_SILVER
	setflag FLAG_HIDE_KURT_2
	setflag FLAG_HIDE_ILEX_FOREST_APPRENTICE
	setflag FLAG_HIDE_ILEX_FOREST_MASTER
	setflag FLAG_HIDE_ILEX_FOREST_FARFETCHD_4
	setflag FLAG_HIDE_ILEX_FOREST_FARFETCHD_3
	setflag FLAG_HIDE_ILEX_FOREST_FARFETCHD_2
	setflag FLAG_HIDE_ILEX_FOREST_FARFETCHD_1
	setflag FLAG_HIDE_CELEBI
	setflag FLAG_HIDE_ILEX_FOREST_KURT
	setflag FLAG_HIDE_AZALEA_TOWN_KURT
	setflag FLAG_HIDE_AZALEA_ARIADOS_LEFT
	setflag FLAG_HIDE_AZALEA_ARIADOS_MID
	setflag FLAG_HIDE_AZALEA_ARIADOS_RIGHT
	

	clearflag FLAG_HIDE_ILEX_FOREST_KIMONO
	clearflag FLAG_ITEM_SLOWPOKE_WELL_RAIN_DANCE
	clearflag FLAG_HIDE_AZALEA_TOWN_ROCKETS
	clearflag FLAG_HIDE_AZALEA_TOWN_WELL_ROCKET
	clearflag FLAG_HIDE_KURT_1
	clearflag FLAG_GOT_CHARCOAL
	clearflag FLAG_HIDE_AZALEA_TOWN_FARFETCHD
	clearflag FLAG_HIDE_AZALEA_TOWN_CUT_MASTER
	clearflag FLAG_MOVE_TUTOR_TAUGHT_HEADBUTT

	removeitem ITEM_HM_SURF
	setvar VAR_AZALEA_TOWN_STATE, 1
	end

AzaleaTown_EventScript_Rocket1::
	lock
	faceplayer
	msgbox AzaleaTown_Text_Rocket1, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_EventScript_Rocket2::
	lock
	faceplayer
	msgbox AzaleaTown_Text_Rocket2, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_EventScript_Gramps::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_AZALEA_TOWN_ROCKETS, AzaleaTown_EventScript_Gramps2
	msgbox AzaleaTown_Text_GrampsBefore, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_EventScript_Gramps2::
	msgbox AzaleaTown_Text_GrampsAfter, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_EventScript_Lass::
	lock
	faceplayer
	msgbox AzaleaTown_Text_Teacher, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_EventScript_Youngster::
	lock
	faceplayer
	msgbox AzaleaTown_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_EventScript_Slowpoke::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SLOWPOKE, CRY_MODE_NORMAL
	msgbox AzaleaTown_Text_Slowpoke1, MSGBOX_DEFAULT
	waitmoncry
	release
	end


AzaleaTown_EventScript_GymSign::
	lock
	msgbox AzaleaTown_Text_GymSign, MSGBOX_SIGN
	closemessage
	release
	end

AzaleaTown_EventScript_KurtSign::
	lock
	msgbox AzaleaTown_Text_KurtsHouseSign, MSGBOX_SIGN
	closemessage
	release
	end

AzaleaTown_EventScript_KilnSign::
	lock
	msgbox AzaleaTown_Text_CharcoalKilnSign, MSGBOX_SIGN
	closemessage
	release
	end

AzaleaTown_EventScript_IlexSign::
	lock
	msgbox AzaleaTown_Text_IlexForestSign, MSGBOX_SIGN
	closemessage
	release
	end

AzaleaTown_EventScript_WellSign::
	lock
	msgbox AzaleaTown_Text_SlowpokeWellSign, MSGBOX_SIGN
	closemessage
	release
	end

AzaleaTown_EventScript_AzaleaSign::
	lock
	msgbox AzaleaTown_Text_Sign, MSGBOX_SIGN
	closemessage
	release
	end

AzaleaTown_EventScript_SilverTriggerTop::
	lock
	clearflag FLAG_HIDE_AZALEA_TOWN_SILVER
	addobject LOCALID_AZALEA_TOWN_SILVER
	playbgm MUS_HG_ENCOUNTER_RIVAL, TRUE
	applymovement LOCALID_AZALEA_TOWN_SILVER, AzaleaTown_Movement_Silver_EnterTop
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	msgbox AzaleaTown_Text_RivalBefore, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_STARTER_MON, 0, AzaleaTown_Silver_Battle_Cyndaquil
	call_if_eq VAR_STARTER_MON, 1, AzaleaTown_Silver_Battle_Totodile
	call_if_eq VAR_STARTER_MON, 2, AzaleaTown_Silver_Battle_Chikorita
	msgbox AzaleaTown_Text_RivalAfter, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, AzaleaTown_Movement_Player_LeaveTop
	waitmovement 0
	applymovement LOCALID_AZALEA_TOWN_SILVER, AzaleaTown_Movement_Silver_LeaveTop
	waitmovement 0
	playse SE_EXIT
	setflag FLAG_HIDE_AZALEA_TOWN_SILVER
	removeobject LOCALID_AZALEA_TOWN_SILVER
	setvar VAR_AZALEA_TOWN_STATE, 6
	fadedefaultbgm
	release
	end

AzaleaTown_EventScript_SilverTriggerBot::
	lock
	clearflag FLAG_HIDE_AZALEA_TOWN_SILVER
	addobject LOCALID_AZALEA_TOWN_SILVER
	playbgm MUS_HG_ENCOUNTER_RIVAL, TRUE
	applymovement LOCALID_AZALEA_TOWN_SILVER, AzaleaTown_Movement_Silver_EnterBot
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	msgbox AzaleaTown_Text_RivalBefore, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_STARTER_MON, 0, AzaleaTown_Silver_Battle_Cyndaquil
	call_if_eq VAR_STARTER_MON, 1, AzaleaTown_Silver_Battle_Totodile
	call_if_eq VAR_STARTER_MON, 2, AzaleaTown_Silver_Battle_Chikorita
	playbgm MUS_HG_RIVAL_EXIT, TRUE
	msgbox AzaleaTown_Text_RivalAfter, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, AzaleaTown_Movement_Player_LeaveBot
	waitmovement 0
	applymovement LOCALID_AZALEA_TOWN_SILVER, AzaleaTown_Movement_Silver_LeaveBot
	waitmovement 0
	playse SE_EXIT
	setflag FLAG_HIDE_AZALEA_TOWN_SILVER
	removeobject LOCALID_AZALEA_TOWN_SILVER
	setvar VAR_AZALEA_TOWN_STATE, 6
	fadedefaultbgm
	release
	end

AzaleaTown_Silver_Battle_Cyndaquil::
	trainerbattle_no_intro TRAINER_RIVAL_CYNDAQUIL_2, AzaleaTown_Text_RivalWin
	return

AzaleaTown_Silver_Battle_Totodile::
	trainerbattle_no_intro TRAINER_RIVAL_TOTODILE_2, AzaleaTown_Text_RivalWin
	return

AzaleaTown_Silver_Battle_Chikorita::
	trainerbattle_no_intro TRAINER_RIVAL_CHIKORITA_2, AzaleaTown_Text_RivalWin
	return


AzaleaTown_EventScript_GSBall::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, AzaleaTown_Movement_PlayerGSBall
	waitmovement 0
	clearflag FLAG_HIDE_AZALEA_TOWN_KURT
	addobject LOCALID_AZALEA_TOWN_KURT_GS
	opendoor 19, 11
	waitdooranim
	waitmovement 0
	closedoor 19, 11
	waitdooranim
	applymovement LOCALID_AZALEA_TOWN_KURT_GS, AzaleaTown_Movement_Kurt2
	playse SE_M_PETAL_DANCE
	waitmovement 0
	msgbox AzaleaTown_Text_Kurt1, MSGBOX_DEFAULT
	closemessage
	playse SE_M_PETAL_DANCE
	msgbox AzaleaTown_Text_Kurt2, MSGBOX_DEFAULT
	giveitem ITEM_GS_BALL
	waitse
	playse SE_M_PETAL_DANCE
	turnobject LOCALID_AZALEA_TOWN_KURT_GS, DIR_WEST
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	playse SE_M_PETAL_DANCE
	waitse
	turnobject LOCALID_AZALEA_TOWN_KURT_GS, DIR_SOUTH
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	msgbox AzaleaTown_Text_Kurt3, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_AZALEA_TOWN_KURT_GS, AzaleaTown_Movement_KurtLeave
	delay 60
	opendoor 19, 11
	waitdooranim
	waitmovement 0
	setflag FLAG_HIDE_AZALEA_TOWN_KURT
	removeobject LOCALID_AZALEA_TOWN_KURT_GS
	closedoor 19, 11
	waitdooranim
	setvar VAR_AZALEA_TOWN_STATE, 9
	release
	end

AzaleaTown_Movement_Silver_EnterTop:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

AzaleaTown_Movement_Silver_EnterBot:
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

AzaleaTown_Movement_Silver_LeaveTop:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

AzaleaTown_Movement_Silver_LeaveBot:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_left
	step_end

AzaleaTown_Movement_Player_LeaveTop:
	lock_facing_direction
	walk_fast_down
	unlock_facing_direction
	face_up
	step_end

AzaleaTown_Movement_Player_LeaveBot:
	lock_facing_direction
	walk_fast_up
	unlock_facing_direction
	face_down
	step_end

AzaleaTown_Movement_Kurt1:
	walk_down
	step_end

AzaleaTown_Movement_Kurt2:
	walk_down
	walk_down
	walk_down
	face_right
	delay_8
	face_left
	delay_8
	face_down
	step_end

AzaleaTown_Movement_PlayerGSBall:
	walk_down
	walk_down
	walk_down
	face_left
	face_right
	face_down
	delay_8
	face_up
	step_end

AzaleaTown_Movement_KurtLeave:
	walk_up
	walk_up
	walk_up
	step_end

AzaleaTown_Text_RivalBefore:
	.string "…Dis-moi quelque chose.\p"
	.string "Est-ce vrai que la TEAM ROCKET\n"
	.string "est revenue ?\p"
	.string "Quoi ? Tu les as battus ? Hah ! Arrête\n"
	.string "de mentir.\p"
	.string "Tu ne plaisantes pas ?\n"
	.string "Alors montrons à quel point tu es bon.$"

AzaleaTown_Text_RivalWin:
	.string "…Humph ! POKéMON inutiles !\p"
	.string "Écoute, toi. Tu n'as gagné que parce que\n"
	.string "mes POKéMON étaient faibles.$"

AzaleaTown_Text_RivalAfter:
	.string "Je déteste les faibles.\p"
	.string "POKéMON, dresseurs. Peu importe\n"
	.string "qui ou quoi.\p"
	.string "Je vais devenir fort et éliminer\n"
	.string "les faibles.\p"
	.string "Ça vaut aussi pour la TEAM ROCKET.\p"
	.string "Ils font les durs en groupe.\p"
	.string "Mais seuls, ils sont faibles.\n"
	.string "Je les déteste tous.\p"
	.string "Reste hors de mon chemin. Un faible\n"
	.string "comme toi n'est qu'une distraction.$"

AzaleaTown_Text_RivalLoss:
	.string "…Humph! I knew you were lying.$"

AzaleaTown_Text_Rocket1:
	.string "C'est dangereux d'aller là-dedans,\n"
	.string "alors je monte la garde.\p"
	.string "Ne suis-je pas un bon Samaritain ?$"

AzaleaTown_Text_Rocket2:
	.string "Tu connais la QUEUE RAMOLOSS ?\n"
	.string "J'ai entendu dire que c'est savoureux !\p"
	.string "Tu n'es pas content que je t'aie dit ça ?$"

AzaleaTown_Text_GrampsBefore:
	.string "Les RAMOLOSS ont disparu\n"
	.string "de la ville…\p"
	.string "J'ai entendu dire que leurs QUEUES\n"
	.string "sont vendues quelque part.$"

AzaleaTown_Text_GrampsAfter:
	.string "Les RAMOLOSS sont revenus.\p"
	.string "Les connaissant, ils étaient peut-être\n"
	.string "juste en train de traîner quelque part.$"

AzaleaTown_Text_Teacher:
	.string "Tu es venu voir FARGAS pour qu'il te\n"
	.string "fabrique des BALLS ?\p"
	.string "Beaucoup de gens font ça.$"

AzaleaTown_Text_Youngster:
	.string "Traversez ÉCORCIA et vous serez\n"
	.string "dans la FORÊT DE CHÊNE.\p"
	.string "Mais ces arbres fins rendent le\n"
	.string "passage impossible.\p"
	.string "Le POKéMON du CHARBONNIER\n"
	.string "peut COUPER les arbres.$"

AzaleaTown_Text_Slowpoke1:
	.string "RAMOLOSS : ..........\p"
	.string "...............BAILLE?$"

AzaleaTown_Text_Kurt1:
	.string "La FORÊT DE CHÊNE est agitée !\p"
	.string "Que se passe-t-il ?$"

AzaleaTown_Text_Kurt2:
	.string "{PLAYER}, voici ta GS BALL !$"

AzaleaTown_Text_Kurt3:
	.string "Peux-tu aller voir pourquoi la FORÊT\n"
	.string "DE CHÊNE est si agitée ?$"

AzaleaTown_Text_Sign:
	.string "ÉCORCIA\n"
	.string "Où les gens et les POKéMON vivent\p"
	.string "en parfaite harmonie.$"

AzaleaTown_Text_KurtsHouseSign:
	.string "MAISON DE FARGAS$"

AzaleaTown_Text_GymSign:
	.string "ÉCORCIA\n"
	.string "ARÈNE POKéMON\p"
	.string "CHAMPION : HECTOR\p"
	.string "L'encyclopédie vivante des POKéMON\n"
	.string "insectes$"

AzaleaTown_Text_SlowpokeWellSign:
	.string "PUITS RAMOLOSS\p"
	.string "Aussi appelé le PUITS FAISSEUR DE PLUIE.\p"
	.string "Les habitants croient qu'un bâillement\n"
	.string "de RAMOLOSS fait tomber la pluie.\p"
	.string "On raconte qu'un bâillement de RAMOLOSS\n"
	.string "a mis fin à une sécheresse il y a 400 ans.$"

AzaleaTown_Text_CharcoalKilnSign:
	.string "FOUR À CHARBON$"

AzaleaTown_Text_IlexForestSign:
	.string "FORÊT DE CHÊNE\p"
	.string "Entrez par la porte.$"
