Gate_Route31_VioletCity_MapScripts::
	.byte 0

Gate_Route31_VioletCity_EventScript_Policeman::
	lock
	faceplayer
	msgbox Gate_Route31_VioletCity_Text_Policeman, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_Route31_VioletCity_EventScript_CooltrainerF::
	lock
	faceplayer
	msgbox Gate_Route31_VioletCity_Text_CooltrainerF, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_Route31_VioletCity_Text_Policeman:
	.string "Bonjour ! As-tu visité\n"
	.string "la TOUR CHÊNE?$"

Gate_Route31_VioletCity_Text_CooltrainerF:
	.string "J'ai vu le POKéMON le plus mignon\n"
	.string "là-bas.\p"
	.string "Il ressemblait beaucoup à PIKACHU !$"
