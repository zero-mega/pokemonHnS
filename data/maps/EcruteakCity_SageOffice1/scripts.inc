.set LOCALID_SAGEOFFICE_SAGE, 3

EcruteakCity_SageOffice1_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EcruteakCity_SageOffice1_OnTransition
	.byte 0

EcruteakCity_SageOffice1_OnTransition::
	goto_if_set FLAG_HIDE_TINTOWER_GUARD, EcruteakCity_SageOffice1_EventScript_SageAside
	end

EcruteakCity_SageOffice1_EventScript_SageAside::
	setobjectxyperm LOCALID_SAGEOFFICE_SAGE, 15, 2
	end

EcruteakCity_SageOffice1_EventScript_Sign::
	msgbox EcruteakCity_SageOffice1_Text_Sign, MSGBOX_SIGN
	end

EcruteakCity_SageOffice1_Text_Sign:
	.string "La cloche d'étain sonne clairement pour\n"
	.string "ceux sous l'aile de la tour.$"

EcruteakCity_SageOffice2_EventScript_SageA::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_TINTOWER_GUARD, EcruteakCity_SageOffice2_EventScript_SageA4
	checkitem ITEM_CLEAR_BELL
	goto_if_eq VAR_RESULT, TRUE, EcruteakCity_SageOffice2_EventScript_SageA2
	msgbox EcruteakTinTowerEntrance_Text_SageNoBadge, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_SageOffice2_EventScript_SageA2::
	msgbox EcruteakTinTowerEntrance_Text_SageHearsClearBell1, MSGBOX_DEFAULT
	waitmessage
	playse SE_M_PETAL_DANCE
	waitse
	playse SE_PIN
	applymovement LOCALID_SAGEOFFICE_SAGE, Common_Movement_ExclamationMark
	delay 60
	msgbox EcruteakTinTowerEntrance_Text_SageHearsClearBell2, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SAGEOFFICE_SAGE, EcruteakCity_SageOffice2_Movement_StandAside
	waitmovement 0
	setobjectxyperm LOCALID_SAGEOFFICE_SAGE, 15, 2
	setflag FLAG_HIDE_TINTOWER_GUARD
	release
	end

EcruteakCity_SageOffice2_EventScript_SageA3::
	msgbox EcruteakTinTowerEntrance_Text_SagePleaseDoGoOn, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_SageOffice2_EventScript_SageA4::
	msgbox EcruteakTinTowerEntrance_Text_SageDone, MSGBOX_DEFAULT
	closemessage
	release
	end
	
EcruteakCity_SageOffice2_EventScript_SageB::
	lock
	faceplayer
	goto_if_eq VAR_ECRUTEAK_CITY_STATE, 10, EcruteakCity_SageOffice2_EventScript_B2
	goto_if_eq VAR_ECRUTEAK_CITY_STATE, 11, EcruteakCity_SageOffice2_EventScript_B2
	msgbox EcruteakTinTowerEntrance_Text_WanderingSage, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_SageOffice2_EventScript_B2::
	msgbox EcruteakTinTowerEntrance_Text_WanderingSageClearBell, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_SageOffice2_EventScript_SageC::
	lock
	faceplayer
	msgbox EcruteakTinTowerEntrance_Text_Gramps, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_SageOffice2_Movement_StandAside:
	walk_left
	face_down
	step_end

EcruteakTinTowerEntrance_Text_SageNoBadge:
	.string "La TOUR FER est interdite aux\n"
	.string "indignes. Désolé, mais vous devez\l"
	.string "partir.$"

EcruteakTinTowerEntrance_Text_SageWithBadge:
	.string "La TOUR FER est interdite à toute\n"
	.string "personne sans le BADGE de l'ARÈNE\p"
	.string "d'IRISIA.\p"
	.string "Ah !\p"
	.string "Le BADGE de l'ARÈNE d'IRISIA !\n"
	.string "Veuillez passer, je vous en prie.$"

EcruteakTinTowerEntrance_Text_SageNoClearBell:
	.string "Un événement important s'est produit.\p"
	.string "Je vous prie de m'excuser, mais je\n"
	.string "dois vous demander de partir.\p"
	.string "…Ce qui apaise l'âme…\p"
	.string "Le TRIO SAGE dit des choses si\n"
	.string "difficiles à comprendre…$"

EcruteakTinTowerEntrance_Text_SageHearsClearBell1:
	.string "Un événement important s'est produit.\p"
	.string "Je vous prie de m'excuser, mais je\n"
	.string "dois vous demander de partir.\p"
	.string "..............................$"
EcruteakTinTowerEntrance_Text_SageHearsClearBell2:
	.string "Ah !\p"
	.string "Le son de cette CLOCHETTE TRANSPARENTE !\p"
	.string "C'est… C'est sublime !\p"
	.string "Je n'ai jamais entendu un son aussi\n"
	.string "beau !\p"
	.string "Le tintement de cette clochette\n"
	.string "reflète l'âme de celui qui la porte.\p"
	.string "Vous…\p"
	.string "Vous pourriez être capable de traverser\n"
	.string "la TOUR FER.\p"
	.string "Allez-y, je vous en prie.$"

EcruteakTinTowerEntrance_Text_SagePleaseDoGoOn:
	.string "Allez-y, je vous en prie.$"

EcruteakTinTowerEntrance_Text_SageDone:
	.string "Le tintement de cette clochette\n"
	.string "reflète l'âme de celui qui la porte.\p"
	.string "Vous…\n"
	.string "Vous êtes vraiment digne.$"

EcruteakTinTowerEntrance_Text_WanderingSage:
	.string "La TOUR FER devant est une tour de\n"
	.string "neuf étages d'une beauté divine.\p"
	.string "Elle apaise l'âme de tous ceux qui\n"
	.string "la contemplent.$"

EcruteakTinTowerEntrance_Text_WanderingSageClearBell:
	.string "La TOUR FER a tremblé ! Un POKéMON a\n"
	.string "dû revenir au sommet !$"

EcruteakTinTowerEntrance_Text_Gramps:
	.string "Deux tours… Deux POKéMON…\p"
	.string "Mais quand l'une a brûlé, les deux\n"
	.string "POKéMON se sont envolés, sans jamais revenir.$"
