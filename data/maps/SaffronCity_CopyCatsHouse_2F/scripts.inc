.set LOCALID_COPYCAT, 1
.set LOCALID_COPYCAT_CLEFAIRY, 4
.set LOCALID_GOLD, 7
.set LOCALID_KRIS, 6

SaffronCity_CopyCatsHouse_2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SaffronCity_CopyCatsHouse_2F_OnTransition
	.byte 0

SaffronCity_CopyCatsHouse_2F_OnTransition::
	setflag FLAG_TEMP_2
	setflag FLAG_TEMP_3
	end

@VAR_FAN_CLUB_CLEFAIRY

SaffronCity_CopyCatsHouse_2F_EventScript_Dodrio::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_DODRIO, CRY_MODE_NORMAL
	msgbox Copycat_Text_Dodrio1, MSGBOX_DEFAULT
	waitmoncry
	msgbox Copycat_Text_Dodrio2, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_CopyCatsHouse_2F_EventScript_Dolls::
	msgbox Copycat_Text_2FDoll, MSGBOX_SIGN
	end

SaffronCity_CopyCatsHouse_2F_EventScript_Copycat::
	lock
	faceplayer
	goto_if_ge VAR_FAN_CLUB_CLEFAIRY, 3, SaffronCity_CopyCatsHouse_2F_EventScript_CopycatAfterDollReturned
	goto_if_eq VAR_FAN_CLUB_CLEFAIRY, 2, SaffronCity_CopyCatsHouse_2F_EventScript_CopycatReturnDoll
	goto_if_set FLAG_RETURNED_MACHINE_PART, SaffronCity_CopyCatsHouse_2F_EventScript_CopycatReturnedMachinePart
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, SaffronCity_CopyCatsHouse_2F_EventScript_Copycat1_Male
	goto_if_eq VAR_RESULT, FEMALE, SaffronCity_CopyCatsHouse_2F_EventScript_Copycat1_Female

SaffronCity_CopyCatsHouse_2F_EventScript_Copycat1_Male::
	applymovement LOCALID_COPYCAT, GoldenrodCity_RadioTower_5F_Movement_Spin
	waitmovement 0
	removeobject LOCALID_COPYCAT
	clearflag FLAG_TEMP_3
	addobject LOCALID_GOLD
	applymovement LOCALID_GOLD, GoldenrodCity_RadioTower_5F_Movement_Spin2
	waitmovement 0
	applymovement LOCALID_GOLD, Common_Movement_FacePlayer
	waitmovement 0
	msgbox Copycat_Text_Male_1, MSGBOX_NPC
	applymovement LOCALID_GOLD, GoldenrodCity_RadioTower_5F_Movement_Spin
	waitmovement 0
	removeobject LOCALID_GOLD
	clearflag FLAG_TEMP_1
	addobject LOCALID_COPYCAT
	applymovement LOCALID_COPYCAT, GoldenrodCity_RadioTower_5F_Movement_Spin2
	waitmovement 0
	applymovement LOCALID_COPYCAT, Common_Movement_FacePlayer
	waitmovement 0
	msgbox Copycat_Text_QuickMimicking, MSGBOX_NPC
	closemessage
	end

SaffronCity_CopyCatsHouse_2F_EventScript_Copycat1_Female::
	applymovement LOCALID_COPYCAT, GoldenrodCity_RadioTower_5F_Movement_Spin
	waitmovement 0
	removeobject LOCALID_COPYCAT
	clearflag FLAG_TEMP_2
	addobject LOCALID_KRIS
	applymovement LOCALID_KRIS, GoldenrodCity_RadioTower_5F_Movement_Spin2
	waitmovement 0
	applymovement LOCALID_KRIS, Common_Movement_FacePlayer
	waitmovement 0
	msgbox Copycat_Text_Male_1, MSGBOX_NPC
	applymovement LOCALID_KRIS, GoldenrodCity_RadioTower_5F_Movement_Spin
	waitmovement 0
	removeobject LOCALID_KRIS
	clearflag FLAG_TEMP_1
	addobject LOCALID_COPYCAT
	applymovement LOCALID_COPYCAT, GoldenrodCity_RadioTower_5F_Movement_Spin2
	waitmovement 0
	applymovement LOCALID_COPYCAT, Common_Movement_FacePlayer
	waitmovement 0
	msgbox Copycat_Text_QuickMimicking, MSGBOX_NPC
	closemessage
	end

SaffronCity_CopyCatsHouse_2F_EventScript_CopycatReturnedMachinePart::
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, SaffronCity_CopyCatsHouse_2F_EventScript_CopycatReturnedMachinePart_Male
	goto_if_eq VAR_RESULT, FEMALE, SaffronCity_CopyCatsHouse_2F_EventScript_CopycatReturnedMachinePart_Female

SaffronCity_CopyCatsHouse_2F_EventScript_CopycatReturnedMachinePart_Male::
	applymovement LOCALID_COPYCAT, GoldenrodCity_RadioTower_5F_Movement_Spin
	waitmovement 0
	removeobject LOCALID_COPYCAT
	clearflag FLAG_TEMP_3
	addobject LOCALID_GOLD
	applymovement LOCALID_GOLD, GoldenrodCity_RadioTower_5F_Movement_Spin2
	waitmovement 0
	applymovement LOCALID_GOLD, Common_Movement_FacePlayer
	waitmovement 0
	msgbox Copycat_Text_Male_2, MSGBOX_NPC
	applymovement LOCALID_GOLD, GoldenrodCity_RadioTower_5F_Movement_Spin
	waitmovement 0
	removeobject LOCALID_GOLD
	clearflag FLAG_TEMP_1
	addobject LOCALID_COPYCAT
	applymovement LOCALID_COPYCAT, GoldenrodCity_RadioTower_5F_Movement_Spin2
	waitmovement 0
	applymovement LOCALID_COPYCAT, Common_Movement_FacePlayer
	waitmovement 0
	msgbox Copycat_Text_Worried, MSGBOX_NPC
	closemessage
	setvar VAR_FAN_CLUB_CLEFAIRY, 1
	end

SaffronCity_CopyCatsHouse_2F_EventScript_CopycatReturnedMachinePart_Female::
	applymovement LOCALID_COPYCAT, GoldenrodCity_RadioTower_5F_Movement_Spin
	waitmovement 0
	removeobject LOCALID_COPYCAT
	clearflag FLAG_TEMP_2
	addobject LOCALID_KRIS
	applymovement LOCALID_KRIS, GoldenrodCity_RadioTower_5F_Movement_Spin2
	waitmovement 0
	applymovement LOCALID_KRIS, Common_Movement_FacePlayer
	waitmovement 0
	msgbox Copycat_Text_Male_2, MSGBOX_NPC
	applymovement LOCALID_KRIS, GoldenrodCity_RadioTower_5F_Movement_Spin
	waitmovement 0
	removeobject LOCALID_KRIS
	clearflag FLAG_TEMP_1
	addobject LOCALID_COPYCAT
	applymovement LOCALID_COPYCAT, GoldenrodCity_RadioTower_5F_Movement_Spin2
	waitmovement 0
	applymovement LOCALID_COPYCAT, Common_Movement_FacePlayer
	waitmovement 0
	msgbox Copycat_Text_Worried, MSGBOX_NPC
	closemessage
	setvar VAR_FAN_CLUB_CLEFAIRY, 1
	end

SaffronCity_CopyCatsHouse_2F_EventScript_CopycatReturnDoll::
	msgbox Copycat_Text_GiveDoll, MSGBOX_DEFAULT
	fadescreenswapbuffers FADE_TO_BLACK
	removeitem ITEM_LOST_ITEM
	clearflag FLAG_HIDE_COPYCAT_CLEFAIRY_DOLL
	addobject LOCALID_COPYCAT_CLEFAIRY
	fadescreenswapbuffers FADE_FROM_BLACK
	msgbox Copycat_Text_GivePass, MSGBOX_DEFAULT
	giveitem ITEM_PASS
	msgbox Copycat_Text_ExplainPass, MSGBOX_DEFAULT
	closemessage
	setvar VAR_FAN_CLUB_CLEFAIRY, 3
	release
	end

SaffronCity_CopyCatsHouse_2F_EventScript_CopycatAfterDollReturned::
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, SaffronCity_CopyCatsHouse_2F_EventScript_CopycatAfterDollReturned_Male
	goto_if_eq VAR_RESULT, FEMALE, SaffronCity_CopyCatsHouse_2F_EventScript_CopycatAfterDollReturned_Female

SaffronCity_CopyCatsHouse_2F_EventScript_CopycatAfterDollReturned_Male::
	applymovement LOCALID_COPYCAT, GoldenrodCity_RadioTower_5F_Movement_Spin
	waitmovement 0
	removeobject LOCALID_COPYCAT
	clearflag FLAG_TEMP_3
	addobject LOCALID_GOLD
	applymovement LOCALID_GOLD, GoldenrodCity_RadioTower_5F_Movement_Spin2
	waitmovement 0
	applymovement LOCALID_GOLD, Common_Movement_FacePlayer
	waitmovement 0
	msgbox Copycat_Text_Male_3, MSGBOX_NPC
	applymovement LOCALID_GOLD, GoldenrodCity_RadioTower_5F_Movement_Spin
	waitmovement 0
	removeobject LOCALID_GOLD
	clearflag FLAG_TEMP_1
	addobject LOCALID_COPYCAT
	applymovement LOCALID_COPYCAT, GoldenrodCity_RadioTower_5F_Movement_Spin2
	waitmovement 0
	applymovement LOCALID_COPYCAT, Common_Movement_FacePlayer
	waitmovement 0
	msgbox Copycat_Text_ItsAScream, MSGBOX_NPC
	closemessage
	end

SaffronCity_CopyCatsHouse_2F_EventScript_CopycatAfterDollReturned_Female::
	applymovement LOCALID_COPYCAT, GoldenrodCity_RadioTower_5F_Movement_Spin
	waitmovement 0
	removeobject LOCALID_COPYCAT
	clearflag FLAG_TEMP_2
	addobject LOCALID_KRIS
	applymovement LOCALID_KRIS, GoldenrodCity_RadioTower_5F_Movement_Spin2
	waitmovement 0
	applymovement LOCALID_KRIS, Common_Movement_FacePlayer
	waitmovement 0
	msgbox Copycat_Text_Male_3, MSGBOX_NPC
	applymovement LOCALID_KRIS, GoldenrodCity_RadioTower_5F_Movement_Spin
	waitmovement 0
	removeobject LOCALID_KRIS
	clearflag FLAG_TEMP_1
	addobject LOCALID_COPYCAT
	applymovement LOCALID_COPYCAT, GoldenrodCity_RadioTower_5F_Movement_Spin2
	waitmovement 0
	applymovement LOCALID_COPYCAT, Common_Movement_FacePlayer
	waitmovement 0
	msgbox Copycat_Text_ItsAScream, MSGBOX_NPC
	closemessage
	end

Copycat_Text_Male_1:
	.string "{PLAYER} : Salut ! Tu aimes les POKéMON ?\p"
	.string "{PLAYER} : Euh, non, c'est moi qui viens de te le demander.\p"
	.string "{PLAYER} : Hein ? Tu es bizarre !$"

Copycat_Text_QuickMimicking:
	.string "COPIEUSE : Hein ? Arrêter d'imiter ?\p"
	.string "Mais c'est mon passe-temps préféré !$"

Copycat_Text_Male_2:
	.string "{PLAYER} : Salut ! J'ai entendu dire que tu\n"
	.string "as perdu ta peluche préférée de POKéMON.\p"
	.string "{PLAYER} : Si je la retrouve, tu me donnes\n"
	.string "un PASS TRAIN ?\p"
	.string "{PLAYER} : Je vais la chercher pour toi.\p"
	.string "Tu penses l'avoir perdue quand tu es\n"
	.string "allée à CARMIN SUR MER ?$"

Copycat_Text_Worried:
	.string "COPIEUSE : Pardon ?\p"
	.string "Je ne devrais pas décider à ta place ?\p"
	.string "Mais je m'inquiète vraiment… Et si\n"
	.string "quelqu'un la trouvait ?$"

Copycat_Text_GiveDoll:
	.string "COPIEUSE : Youpi ! C'est ma peluche de\n"
	.string "MELOFEE !\p"
	.string "Regarde la couture sur la jambe droite,\n"
	.string "c'est la preuve !$"

Copycat_Text_GivePass:
	.string "OK. Voici le PASS TRAIN MAGNETIQUE\n"
	.string "comme promis !$"

Copycat_Text_ExplainPass:
	.string "COPIEUSE : C'est le PASS pour le\n"
	.string "TRAIN MAGNETIQUE.\p"
	.string "L'homme de la compagnie ferroviaire\n"
	.string "me l'a donné quand ils ont détruit notre\l"
	.string "ancienne maison pour la GARE.$"

Copycat_Text_Male_3:
	.string "{PLAYER} : Salut ! Merci beaucoup pour le\n"
	.string "PASS TRAIN !\p"
	.string "{PLAYER} : Pardon ?\p"
	.string "{PLAYER} : C'est si amusant d'imiter\n"
	.string "tous mes gestes ?$"

Copycat_Text_ItsAScream:
	.string "COPIEUSE : Bien sûr ! C'est trop drôle !$"

Copycat_Text_Dodrio1:
	.string "DODRIO : Gii giii !$"

Copycat_Text_Dodrio2:
	.string "MIROIR, MIROIR, DIS-MOI,\n"
	.string "QUI EST LA PLUS BELLE ?$"

Copycat_Text_2FDoll:
	.string "C'est un POKéMON rare ! Hein ?\p"
	.string "Ce n'est qu'une peluche…$"
