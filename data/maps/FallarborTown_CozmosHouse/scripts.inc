FallarborTown_CozmosHouse_MapScripts::
	.byte 0

FallarborTown_CozmosHouse_EventScript_ProfCozmo::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_RETURN, FallarborTown_CozmosHouse_EventScript_GaveMeteorite
	checkitem ITEM_METEORITE
	goto_if_eq VAR_RESULT, TRUE, FallarborTown_CozmosHouse_EventScript_PlayerHasMeteoriteCheck
	msgbox FallarborTown_CozmosHouse_Text_MeteoriteWillNeverBeMineNow, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_PlayerHasMeteoriteCheck::
	goto_if_set FLAG_FINITE_TMS, FallarborTown_CozmosHouse_EventScript_PlayerHasMeteoriteTM27
	goto_if_unset FLAG_FINITE_TMS, FallarborTown_CozmosHouse_EventScript_PlayerHasMeteorite
	end

FallarborTown_CozmosHouse_EventScript_PlayerHasMeteorite::
	call_if_unset FLAG_TEMP_2, FallarborTown_CozmosHouse_EventScript_NoticeMeteorite
	call_if_set FLAG_TEMP_2, FallarborTown_CozmosHouse_EventScript_AskForMeteorite
	goto_if_eq VAR_RESULT, NO, FallarborTown_CozmosHouse_EventScript_DeclineGiveMeteorite
	msgbox FallarborTown_CozmosHouse_Text_PleaseUseThisTM, MSGBOX_DEFAULT
	giveitem ITEM_NUGGET
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setvar VAR_0x8004, ITEM_METEORITE
	call Common_EventScript_PlayerHandedOverTheItem
	setflag FLAG_RECEIVED_TM_RETURN
	msgbox FallarborTown_CozmosHouse_Text_ReallyGoingToHelpMyResearch, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_PlayerHasMeteoriteTM27::
	call_if_unset FLAG_TEMP_2, FallarborTown_CozmosHouse_EventScript_NoticeMeteorite
	call_if_set FLAG_TEMP_2, FallarborTown_CozmosHouse_EventScript_AskForMeteorite
	goto_if_eq VAR_RESULT, NO, FallarborTown_CozmosHouse_EventScript_DeclineGiveMeteorite
	msgbox FallarborTown_CozmosHouse_Text_PleaseUseThisTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_RETURN
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setvar VAR_0x8004, ITEM_METEORITE
	call Common_EventScript_PlayerHandedOverTheItem
	setflag FLAG_RECEIVED_TM_RETURN
	msgbox FallarborTown_CozmosHouse_Text_ReallyGoingToHelpMyResearch, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_NoticeMeteorite::
	msgbox FallarborTown_CozmosHouse_Text_MeteoriteWillNeverBeMineNow, MSGBOX_DEFAULT
	msgbox FallarborTown_CozmosHouse_Text_IsThatMeteoriteMayIHaveIt, MSGBOX_YESNO
	return

FallarborTown_CozmosHouse_EventScript_AskForMeteorite::
	msgbox FallarborTown_CozmosHouse_Text_MayIHaveMeteorite, MSGBOX_YESNO
	return

FallarborTown_CozmosHouse_EventScript_DeclineGiveMeteorite::
	setflag FLAG_TEMP_2
	msgbox FallarborTown_CozmosHouse_Text_CrushedWithDisappointment, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_GaveMeteorite::
	msgbox FallarborTown_CozmosHouse_Text_ReallyGoingToHelpMyResearch, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_CozmosWife::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_RETURN, FallarborTown_CozmosHouse_EventScript_CozmoIsHappy
	goto_if_set FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, FallarborTown_CozmosHouse_EventScript_CozmoIsSad
	msgbox FallarborTown_CozmosHouse_Text_CozmoWentToMeteorFalls, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_CozmoIsSad::
	msgbox FallarborTown_CozmosHouse_Text_FeelSorryForCozmo, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_CozmoIsHappy::
	msgbox FallarborTown_CozmosHouse_Text_CozmoIsSoHappy, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_Text_MeteoriteWillNeverBeMineNow:
	.string "PROF. COZMO : Oh…\n"
	.string "Je n'aurais jamais dû me laisser\l"
	.string "berner et dire à la TEAM MAGMA où\l"
	.string "trouver des MÉTÉORITES…\p"
	.string "Cette MÉTÉORITE des CHUTES MÉTÉORE…\n"
	.string "Elle ne sera jamais à moi maintenant…$"

FallarborTown_CozmosHouse_Text_IsThatMeteoriteMayIHaveIt:
	.string "Oh !\n"
	.string "Hein ?\p"
	.string "Cet objet…\p"
	.string "Serait-ce… ?\p"
	.string "Est-ce la MÉTÉORITE que la TEAM MAGMA\n"
	.string "a prise aux CHUTES MÉTÉORE ?\p"
	.string "S'il te plaît, puis-je l'avoir ?\p"
	.string "Je ne la demande pas gratuitement.\n"
	.string "Que dirais-tu de l'échanger contre cette PÉPITE ?$"

FallarborTown_CozmosHouse_Text_PleaseUseThisTM:
	.string "PROF. COZMO : Cet objet représente\n"
	.string "ma gratitude.\l"
	.string "S'il te plaît, utilise-le !$"

FallarborTown_CozmosHouse_Text_ReallyGoingToHelpMyResearch:
	.string "PROF. COZMO : Oh, je n'arrive pas à y croire.\n"
	.string "C'est vraiment, vraiment génial !\p"
	.string "Cela va vraiment aider mes recherches !$"

FallarborTown_CozmosHouse_Text_CrushedWithDisappointment:
	.string "PROF. COZMO : Oh, mais…\n"
	.string "Je suis anéanti de déception…$"

FallarborTown_CozmosHouse_Text_MayIHaveMeteorite:
	.string "PROF. COZMO : S'il te plaît, puis-je avoir\n"
	.string "cette MÉTÉORITE ?\p"
	.string "Je ne la demande pas gratuitement.\n"
	.string "Que dirais-tu de l'échanger contre cette CT ?$"

FallarborTown_CozmosHouse_Text_CozmoWentToMeteorFalls:
	.string "PROF. COZMO est parti aux CHUTES MÉTÉORE\n"
	.string "sur la ROUTE 114 avec des gens de la\l"
	.string "TEAM MAGMA.$"

FallarborTown_CozmosHouse_Text_FeelSorryForCozmo:
	.string "Pauvre PROF. COZMO…\n"
	.string "Il est tellement déprimé… Je le plains.$"

FallarborTown_CozmosHouse_Text_CozmoIsSoHappy:
	.string "Regarde PROF. COZMO…\n"
	.string "Il est tellement heureux ! Je trouve ça mignon.$"
