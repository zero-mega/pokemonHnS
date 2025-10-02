.set LOCALID_BURNED_TOWER_SILVER, 3
.set LOCALID_BURNED_TOWER_EUSINE, 1

BurnedTower_1F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, BurnedTower_1F_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BurnedTower_1F_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, BurnedTower_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

BurnedTower_1F_OnTransition: 
	callnative SetTimeBasedEncounters
	end

BurnedTower_1F_OnLoad::
	goto_if_ge VAR_ECRUTEAK_CITY_STATE, 4, BurnedTower_1F_MapScript_CreateHole
	end

BurnedTower_1F_MapScript_CreateHole::
	setmetatile 16, 12, 0x37E, FALSE
	end

BurnedTower_1F_OnFrame::
	map_script_2 VAR_ECRUTEAK_CITY_STATE, 1, BurnedTower_1F_EventScript_MeetEusine
	.2byte 0

BurnedTower_1F_EventScript_MeetEusine::
	lock
	playse SE_PIN
	applymovement LOCALID_BURNED_TOWER_EUSINE, Common_Movement_ExclamationMark
	delay 60
	applymovement LOCALID_BURNED_TOWER_EUSINE, BurnedTower_Movement_Eusine1
	waitmovement 0
	msgbox BurnedTower_1FEusineIntroText, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BURNED_TOWER_EUSINE, BurnedTower_Movement_Eusine2
	waitmovement 0
	setvar VAR_ECRUTEAK_CITY_STATE, 2
	release
	end

BurnedTower_Movement_Eusine1:
	walk_down
	walk_down
	step_end

BurnedTower_Movement_Eusine2:
	walk_up
	walk_up
	step_end


BurnedTower_1FEusineIntroText:
	.string "EUSINE : Je m'appelle EUSINE.\p"
	.string "Je suis sur la piste d'un POKéMON\n"
	.string "appelé SUICUNE.\p"
	.string "Et toi, qui es-tu... ?\p"
	.string "{PLAYER} ? Enchanté de te rencontrer !\p"
	.string "J'ai entendu dire que SUICUNE\n"
	.string "pourrait être dans cette TOUR BRÛLÉE,\l"
	.string "alors je suis venu jeter un œil.\p"
	.string "Mais où peut-il bien être exactement ?$"

BurnedTower_1F_EventScript_Item_HpUp::
	finditem ITEM_HP_UP
	end

BurnedTower_1F_EventScript_Item_Ether::
	finditem ITEM_ETHER
	end

BurnedTower_1F_EventScript_Eusine::
	lock
	faceplayer
	msgbox BurnedTower_1FEusineText, MSGBOX_DEFAULT
	closemessage
	release
	end

BurnedTower_1F_EventScript_Morty::
	lock
	faceplayer
	msgbox BurnedTower_1FMortyText, MSGBOX_DEFAULT
	closemessage
	release
	end

BurnedTower_1FEusineText:
	.string "EUSINE : J'ai entendu dire que\n"
	.string "SUICUNE pourrait être dans cette\l"
	.string "TOUR BRÛLÉE, alors je suis venu\l"
	.string "jeter un œil.\p"
	.string "Mais où peut-il bien être\n"
	.string "exactement ?$"

BurnedTower_1FMortyText:
	.string "MORTIMER : Le CHAMPION d'ECREUCREUX\n"
	.string "doit étudier ce que l'on dit être\l"
	.string "les POKéMON légendaires --\l"
	.string "SUICUNE, ENTEI et RAIKOU.\p"
	.string "EUSINE est ici, alors j'ai décidé\n"
	.string "d'enquêter sur la TOUR avec lui.$"

BurnedTower_1F_EventScript_Silver::
	lock
	playse SE_PIN
	applymovement LOCALID_BURNED_TOWER_SILVER, Common_Movement_ExclamationMark
	delay 60
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight1
	applymovement LOCALID_BURNED_TOWER_SILVER, Common_Movement_WalkLeft1
	waitmovement 0
	waitmovement 0
	msgbox BurnedTowerSilver_BeforeText, MSGBOX_DEFAULT
	call_if_eq VAR_STARTER_MON, 0, BurnedTower_1F_Silver_Battle_Cyndaquil
	call_if_eq VAR_STARTER_MON, 1, BurnedTower_1F_Silver_Battle_Totodile
	call_if_eq VAR_STARTER_MON, 2, BurnedTower_1F_Silver_Battle_Chikorita
	playbgm MUS_HG_RIVAL_EXIT, TRUE
	msgbox BurnedTowerSilver_AfterText1, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 20  @ num shakes
	setvar VAR_0x8007, 6  @ shake delay
	special ShakeCamera
	waitstate
	playse SE_CLICK
	setmetatile 16, 12, 0x37E, FALSE
	special DrawWholeMapView
	waitse
	delay 60
	special SpawnCameraObject
	removeobject OBJ_EVENT_ID_PLAYER
	playse SE_FALL
	delay 60
	msgbox BurnedTowerSilver_AfterText2, MSGBOX_AUTOCLOSE
	waitmessage
	warphole MAP_BURNED_TOWER_B1F
	setvar VAR_ECRUTEAK_CITY_STATE, 3
	release
	end

BurnedTower_1F_Silver_Battle_Cyndaquil::
	trainerbattle_no_intro TRAINER_RIVAL_CYNDAQUIL_3, BurnedTowerSilver_WinText
	return

BurnedTower_1F_Silver_Battle_Totodile::
	trainerbattle_no_intro TRAINER_RIVAL_TOTODILE_3, BurnedTowerSilver_WinText
	return

BurnedTower_1F_Silver_Battle_Chikorita::
	trainerbattle_no_intro TRAINER_RIVAL_CHIKORITA_3, BurnedTowerSilver_WinText
	return

BurnedTowerSilver_BeforeText:
	.string "..............................\p"
	.string "...Oh, c'est toi.\p"
	.string "Je suis venu chercher des\n"
	.string "POKéMON légendaires qui, paraît-il,\l"
	.string "nichent ici.\p"
	.string "Mais il n'y a rien ici !\p"
	.string "Rien, après tout l'effort\n"
	.string "pour venir dans ce trou ?\l"
	.string "Pas possible !\p"
	.string "C'est entièrement ta faute !$"

BurnedTowerSilver_WinText:
	.string "...Pff !\p"
	.string "Je n'ai perdu que parce que mes\n"
	.string "POKéMON sont incroyablement faibles.\p"
	.string "Quelle honte.$"

BurnedTowerSilver_AfterText1:
	.string "...Bof, peu importe.\p"
	.string "De toute façon, tu ne pourrais\n"
	.string "jamais attraper un POKéMON légendaire.$"

BurnedTowerSilver_LossText:
	.string "...Pff !\p"
	.string "Voilà pourquoi je déteste me battre\n"
	.string "contre des mauviettes. C'est une perte de temps.$"

BurnedTowerSilver_AfterText2:
	.string "Pff !\p"
	.string "Qu'est-ce que tu fais à tomber\n"
	.string "dans un trou ? Quel génie !\p"
	.string "Bien fait pour toi !$"

BurnedTower_1F_EventScript_Nard::
	trainerbattle_single TRAINER_NARD BurnedTower_Text_NardSeen, BurnedTower_Text_NardBeaten
	msgbox BurnedTower_Text_NardAfter, MSGBOX_AUTOCLOSE
	end

BurnedTower_1F_EventScript_Richardo::
	trainerbattle_single TRAINER_RICHARDO BurnedTower_Text_RichardoSeen, BurnedTower_Text_RichardoBeaten
	msgbox BurnedTower_Text_RichardoAfter, MSGBOX_AUTOCLOSE
	end

BurnedTower_Text_NardSeen:
	.string "Ne t'inquiète pas !\p"
	.string "Nous, les cracheurs de feu, connaissons\n"
	.string "le vrai pouvoir du feu mieux que quiconque !$"
BurnedTower_Text_NardBeaten:
	.string "Merci pour ce combat brûlant !$"
BurnedTower_Text_NardAfter:
	.string "Si cette tour est brûlée, c'est parce\n"
	.string "qu'elle a été frappée par la foudre.\p"
	.string "Le feu que je crache est minuscule\n"
	.string "en comparaison...$"

BurnedTower_Text_RichardoSeen:
	.string "Je m'entraîne à voler dans la\n"
	.string "TOUR CENDRÉE ! N'essaye pas ça\p"
	.string "chez toi !$"
BurnedTower_Text_RichardoBeaten:
	.string "Pfffffffffffffff.$"
BurnedTower_Text_RichardoAfter:
	.string "Peut-être que la vie de criminel\n"
	.string "n'est pas faite pour moi...$"
