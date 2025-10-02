GoldenrodCity_DepartmentStore_5F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, GoldenrodDeptElevator_OnFrame
	.byte 0


GoldenrodDeptStore5_EventScript_Lass::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_5FLass, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore5_EventScript_PokefanM::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_5FPokefanM, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore5_EventScript_Girl::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_Girl, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore5_EventScript_Sign::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_5FDirectory, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore5_EventScript_Receptionist::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_5FReceptionistOhYourMon, MSGBOX_DEFAULT
	closemessage
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	goto_if_ge VAR_RESULT, FRIENDSHIP_150_TO_199, GoldenrodDeptStore5_EventScript_Receptionist_HighFriendship
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	goto_if_ge VAR_RESULT, FRIENDSHIP_50_TO_99, GoldenrodDeptStore5_EventScript_Receptionist_PutInEffort
	goto GoldenrodDeptStore5_EventScript_Receptionist_LowFriendship
	release
	end

GoldenrodDeptStore5_EventScript_Receptionist_HighFriendship::
	call_if_unset FLAG_GOT_RETURN, GoldenrodDeptStore5_EventScript_Receptionist_GiveReturn
	msgbox GoldenrodDeptStore_Text_5FReceptionistThisMoveShouldBePerfect, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore5_EventScript_Receptionist_LowFriendship::
	call_if_unset FLAG_GOT_FRUSTRATION, GoldenrodDeptStore5_EventScript_Receptionist_GiveFrustration
	msgbox GoldenrodDeptStore_Text_5FReceptionistItLooksEvilHowAboutThisTM, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore5_EventScript_Receptionist_GiveReturn::
	giveitem ITEM_TM_RETURN
	setflag FLAG_GOT_RETURN
	return

GoldenrodDeptStore5_EventScript_Receptionist_GiveFrustration::
	giveitem ITEM_TM_FRUSTRATION
	setflag FLAG_GOT_FRUSTRATION
	return

GoldenrodDeptStore5_EventScript_Receptionist_PutInEffort::
	msgbox GoldenrodDeptStore_Text_5FReceptionistPutInSomeMoreEffort, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore5_EventScript_Receptionist_Already::
	msgbox GoldenrodDeptStore_Text_5FReceptionistWait, MSGBOX_DEFAULT
	closemessage
	release
	end



GoldenrodDeptStore_Text_5FReceptionistOhYourMon:
    .string "Bonjour. Oh, ton POKéMON…$"

GoldenrodDeptStore_Text_5FReceptionistWait:
    .string "Attends, je t'ai déjà donné cette CT !$"

GoldenrodDeptStore_Text_5FReceptionistPutInSomeMoreEffort:
	.string "Hmm…\n"
	.string "Ce n'est pas mal, mais ce n'est pas bien non plus.\p"
	.string "Toi, en tant que DRESSEUR, tu dois faire\n"
	.string "un peu plus d'efforts.$"

GoldenrodDeptStore_Text_5FReceptionistThisMoveShouldBePerfect:
    .string "Il est très attaché à toi.\p"
    .string "Cette capacité devrait être parfaite\n"
    .string "pour un duo comme vous.$"

GoldenrodDeptStore_Text_5FReceptionistItLooksEvilHowAboutThisTM:
    .string "Il a l'air méchant. Que penses-tu de cette CT\n"
    .string "pour lui ?$"

GoldenrodDeptStore_Text_5FReceptionistThereAreTMsPerfectForMon:
    .string "Il doit bien y avoir des CT qui sont\n"
    .string "parfaites pour ton POKéMON.$"

GoldenrodDeptStore_Text_5FLass:
    .string "Pendant la journée, une dame vient voir\n"
    .string "les POKéMON.\p"
    .string "Elle donne même des CT !$"

GoldenrodDeptStore_Text_5FPokefanM:
    .string "Tu ne peux pas renommer un POKéMON que tu obtiens\n"
    .string "par échange.\p"
    .string "Le nom reflète les sentiments de son\n"
    .string "dresseur d'origine.$"

GoldenrodDeptStore_Text_Girl:
	.string "La dame m'a donné RETOUR !\n"
    .string "Mon POKéMON doit vraiment m'aimer !$"

GoldenrodDeptStore_Text_5FDirectory:
    .string "Personnalisez votre POKéMON\p"
    .string "5e Étage : Coin CT$"
