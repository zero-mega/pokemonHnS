.set LOCALID_SPROUT_TOWER_SILVER, 5

SproutTower_3F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SproutTower_3F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

SproutTower_3F_OnTransition: 
	callnative SetTimeBasedEncounters
	end


SproutTower_3F_EventScript_SageJin::
	trainerbattle_single TRAINER_JIN SproutTower_Text_SageJin_Seen, SproutTower_Text_SageJin_Beaten
	msgbox SproutTower_Text_SageJin_AfterBattle, MSGBOX_AUTOCLOSE
	end


SproutTower_3F_EventScript_SageNeal::
	trainerbattle_single TRAINER_NEAL SproutTower_Text_SageNeal_Seen, SproutTower_Text_SageNeal_Beaten
	msgbox SproutTower_Text_SageNeal_AfterBattle, MSGBOX_AUTOCLOSE
	end

SproutTower_3F_EventScript_SageTroy::
	trainerbattle_single TRAINER_TROY SproutTower_Text_SageTroy_Seen, SproutTower_Text_SageTroy_Beaten
	msgbox SproutTower_Text_SageTroy_AfterBattle, MSGBOX_AUTOCLOSE
	end

SproutTower_3F_EventScript_Painting::
	lock
	msgbox SproutTower_Text_3F_Painting, MSGBOX_AUTOCLOSE
	release
	end

SproutTower_3F_EventScript_Potion::
	finditem ITEM_POTION
	end

SproutTower_3F_EventScript_EscapeRope::
	finditem ITEM_ESCAPE_ROPE
	end

SproutTower_3F_EventScript_TriggerSceneLeft::
	lock
	playbgm MUS_HG_ENCOUNTER_RIVAL, TRUE
	applymovement LOCALID_SPROUT_TOWER_SILVER, SproutTower_3F_Movement_Silver1
	waitmovement 0
	msgbox SproutTower_Text_ElderLecturesRival, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_SPROUT_TOWER_SILVER, Common_Movement_ExclamationMark	
	delay 60
	applymovement LOCALID_SPROUT_TOWER_SILVER, SproutTower_3F_Movement_SilverLeft
	waitmovement 0
	msgbox SproutTower_Text_RivalOnlyCaresStrong, MSGBOX_DEFAULT
	delay 30
	msgbox SproutTower_Text_RivalUsedEscapeRope, MSGBOX_DEFAULT
	applymovement LOCALID_SPROUT_TOWER_SILVER SproutTower_3F_Movement_EscapeRope
	waitmovement 0
	closemessage
	fadescreen FADE_TO_BLACK
	playse SE_EXIT
	setflag FLAG_HIDE_SPROUT_TOWER_SILVER
	removeobject LOCALID_SPROUT_TOWER_SILVER
	delay 55
	fadescreen FADE_FROM_BLACK
	special DrawWholeMapView
	fadedefaultbgm
	setvar VAR_SPROUT_TOWER, 1
	release
	end

SproutTower_3F_EventScript_TriggerSceneRight::
	lock
	playbgm MUS_HG_ENCOUNTER_RIVAL, TRUE
	applymovement LOCALID_SPROUT_TOWER_SILVER, SproutTower_3F_Movement_Silver1
	waitmovement 0
	msgbox SproutTower_Text_ElderLecturesRival, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_SPROUT_TOWER_SILVER, Common_Movement_ExclamationMark	
	delay 60
	applymovement LOCALID_SPROUT_TOWER_SILVER, SproutTower_3F_Movement_SilverRight
	waitmovement 0
	waitmovement 0
	msgbox SproutTower_Text_RivalOnlyCaresStrong, MSGBOX_DEFAULT
	msgbox SproutTower_Text_RivalUsedEscapeRope, MSGBOX_DEFAULT
	applymovement LOCALID_SPROUT_TOWER_SILVER SproutTower_3F_Movement_EscapeRope
	waitmovement 0
	closemessage
	fadescreen FADE_TO_BLACK
	playse SE_EXIT
	setflag FLAG_HIDE_SPROUT_TOWER_SILVER
	removeobject LOCALID_SPROUT_TOWER_SILVER
	delay 55
	fadescreen FADE_FROM_BLACK
	special DrawWholeMapView
	fadedefaultbgm
	setvar VAR_SPROUT_TOWER, 1
	release
	end

SproutTower_3F_EventScript_SageLi::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_FLASH, SproutTower_3F_EventScript_SageLi_Beaten
	msgbox SproutTower_Text_SageLi_Seen, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_LI, SproutTower_Text_SageLi_Beaten
	msgbox SproutTower_Text_SageLi_TakeFlash, MSGBOX_DEFAULT
	giveitem ITEM_HM_FLASH
	setflag FLAG_RECEIVED_HM_FLASH
	msgbox SproutTower_Text_SageLi_FlashExplain, MSGBOX_DEFAULT
	closemessage
	release
	end

SproutTower_3F_EventScript_SageLi_Beaten::
	msgbox SproutTower_Text_SageLi_AfterBattle, MSGBOX_DEFAULT
	closemessage
	release
	end

SproutTower_3F_Movement_Silver1:
	walk_fast_up
	walk_fast_up
	step_end

SproutTower_3F_Movement_SilverLeft:
	face_down
	delay_16
	walk_right
	walk_right
	walk_down
	walk_down
	step_end

SproutTower_3F_Movement_SilverRight:
	face_down
	delay_16
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	step_end

SproutTower_3F_Movement_EscapeRope:
	face_right
	face_up
	face_left
	face_down
	face_right
	face_up
	face_left
	face_down
	face_right
	face_up
	face_left
	face_down
	step_end

SproutTower_Text_ElderLecturesRival:
	.string "MAÎTRE : Tu es vraiment doué\n"
	.string "en tant que Dresseur.\p"
	.string "Comme promis, voici ta CS.\p"
	.string "Mais laisse-moi te dire ceci : tu\n"
	.string "devrais mieux traiter tes POKéMON.\p"
	.string "Ta façon de combattre est bien\n"
	.string "trop brutale.\p"
	.string "Les POKéMON ne sont pas des outils de guerre…$"

SproutTower_Text_RivalOnlyCaresStrong:
	.string "…\n"
	.string "…Humph !\p"
	.string "Il prétend être le MAÎTRE mais\n"
	.string "il est faible.\p"
	.string "C'est logique.\p"
	.string "Je ne perdrai jamais contre des idiots\n"
	.string "qui radotent sur la gentillesse envers les POKéMON.\p"
	.string "Je ne m'intéresse qu'aux POKéMON\n"
	.string "forts qui peuvent gagner.\p"
	.string "Les POKéMON faibles, je m'en fiche\n"
	.string "complètement.$"

SproutTower_Text_RivalUsedEscapeRope:
	.string "SILVER utilise une CORDE SORTIE !$"

SproutTower_Text_SageLi_Seen:
	.string "C'est bien que tu sois venu !\p"
	.string "La TOUR CHÉTIFLOR est un lieu\n"
	.string "d'entraînement.\p"
	.string "Les gens et les POKéMON testent leurs\n"
	.string "liens pour bâtir un avenir radieux\l"
	.string "ensemble.\p"
	.string "Je suis la dernière épreuve.\p"
	.string "Permets-moi de vérifier les liens\n"
	.string "entre toi et tes POKéMON !$"

SproutTower_Text_SageLi_Beaten:
	.string "Ah, excellent !$"

SproutTower_Text_SageLi_TakeFlash:
	.string "Toi et tes POKéMON ne devriez\n"
	.string "avoir aucun problème à utiliser cette capacité.\p"
	.string "Prends cette CS ÉCLAT LUMIÈRE.$"

SproutTower_Text_SageLi_FlashExplain:
	.string "ÉCLAT LUMIÈRE illumine même les\n"
	.string "endroits les plus sombres.\p"
	.string "Mais pour l'utiliser hors combat, il te\n"
	.string "faut le BADGE de l'ARÈNE de MAUVILLE.$"

SproutTower_Text_SageLi_AfterBattle:
	.string "J'espère que tu apprendras et\n"
	.string "grandiras au fil de ton voyage.$"

SproutTower_Text_SageJin_Seen:
	.string "Je m'entraîne pour trouver l'illumination\n"
	.string "grâce aux POKéMON !$"

SproutTower_Text_SageJin_Beaten:
	.string "Mon entraînement est incomplet…$"

SproutTower_Text_SageJin_AfterBattle:
	.string "Quand les POKéMON deviennent plus forts,\n"
	.string "le Dresseur aussi.\p"
	.string "Non, attends. Quand le Dresseur\n"
	.string "devient plus fort, les POKéMON\l"
	.string "aussi.$"

SproutTower_Text_SageTroy_Seen:
	.string "Voyons à quel point tu fais confiance\n"
	.string "à tes POKéMON !$"

SproutTower_Text_SageTroy_Beaten:
	.string "Oui, ta confiance est réelle !$"

SproutTower_Text_SageTroy_AfterBattle:
	.string "Le MAÎTRE n'est plus très loin.$"

SproutTower_Text_SageNeal_Seen:
	.string "La CS du MAÎTRE éclaire même\n"
	.string "l'obscurité la plus totale.$"

SproutTower_Text_SageNeal_Beaten:
	.string "C'est ma tête qui brille !$"

SproutTower_Text_SageNeal_AfterBattle:
	.string "Que la lumière éclaire ton\n"
	.string "voyage.$"

SproutTower_Text_3F_Painting:
	.string "C'est une puissante peinture d'un\n"
	.string "CHÉTIFLOR.$"
