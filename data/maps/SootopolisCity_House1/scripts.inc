SootopolisCity_House1_MapScripts::
	.byte 0

SootopolisCity_House1_EventScript_BrickBreakBlackBelt::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_BRICK_BREAK, SootopolisCity_House1_EventScript_ReceivedBrickBreak
	msgbox SootopolisCity_House1_Text_DevelopedThisTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_BRICK_BREAK
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_BRICK_BREAK
	msgbox SootopolisCity_House1_Text_ExplainBrickBreak, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House1_EventScript_ReceivedBrickBreak::
	msgbox SootopolisCity_House1_Text_ExplainBrickBreak, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House1_EventScript_Kecleon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_KECLEON, CRY_MODE_NORMAL
	msgbox SootopolisCity_House1_Text_Kecleon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

SootopolisCity_House1_Text_DevelopedThisTM:
	.string "Pendant trente ans, je suis resté à\n"
	.string "SOOTOPOLIS à perfectionner mes talents.\p"
	.string "J'ai mis au point une CT fracassante.\n"
	.string "Je te la lègue !$"

SootopolisCity_House1_Text_ExplainBrickBreak:
	.string "La CT31 contient DÉTRUIBRICK ! C'est une\n"
	.string "capacité si puissante que je ne peux la décrire.$"

SootopolisCity_House1_Text_Kecleon:
	.string "KECLEON : Puu puhyaah.$"

