BlackthornCity_Mart_MapScripts::
	.byte 0

BlackthornMart_EventScript_CoolTrainerM::
	msgbox BlackthornMart_Text_CooltrainerM, MSGBOX_NPC
	end

BlackthornMart_EventScript_BlackBelt::
	msgbox BlackthornMart_Text_BlackBelt, MSGBOX_NPC
	end

BlackthornMart_Text_CooltrainerM:
	.string "Tu ne peux pas acheter de RAPP. MAX,\n"
	.string "mais il ranime totalement un POKéMON K.O.\p"
	.string "Attention : il ne restaure pas les PP,\n"
	.string "les POINTS de PUISSANCE des capacités.$"

BlackthornMart_Text_BlackBelt:
	.string "Le MAX REPOUSSE éloigne les POKéMON\n"
	.string "faibles de toi.\p"
	.string "C'est le REPOUSSE qui dure le plus\n"
	.string "longtemps.$"
