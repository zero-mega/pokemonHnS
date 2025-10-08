SSAqua_RoomSE_MapScripts::
	.byte 0

SSAqua_RoomSE_EventScript_Colin::
	trainerbattle_single TRAINER_COLIN SSAqua_RoomSE_Text_PokefanmColinSeen, SSAqua_RoomSE_Text_PokefanmColinBeaten
	msgbox SSAqua_RoomSE_Text_PokefanmColinAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomSE_EventScript_Meg::
	trainerbattle_double TRAINER_MEG_AND_PEG, SSAqua_RoomSE_Text_TwinsMegandpeg1Seen, SSAqua_RoomSE_Text_TwinsMegandpeg1Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox SSAqua_RoomSE_Text_TwinsMegandpeg1After, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomSE_EventScript_Peg::
	trainerbattle_double TRAINER_MEG_AND_PEG, SSAqua_RoomSE_Text_TwinsMegandpeg2Seen, SSAqua_RoomSE_Text_TwinsMegandpeg2Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox SSAqua_RoomSE_Text_TwinsMegandpeg2After, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomSE_Text_PokefanmColinSeen:
    .string "Hé, petit ! Tu veux te battre\n"
    .string "avec moi ?$"

SSAqua_RoomSE_Text_PokefanmColinBeaten:
    .string "Tu es fort !$"

SSAqua_RoomSE_Text_PokefanmColinAfter:
    .string "Tu voyages tout seul ?\n"
    .string "Ta maman n'est pas inquiète ?$"

SSAqua_RoomSE_Text_TwinsMegandpeg1Seen:
    .string "Tu crois que je suis un bébé ?\n"
    .string "C'est pas juste !$"

SSAqua_RoomSE_Text_TwinsMegandpeg1Beaten:
    .string "Oh ! On a perdu !$"

SSAqua_RoomSE_Text_TwinsMegandpeg1After:
    .string "Bébé, c'est méchant comme nom\n"
    .string "pour des filles !$"

SSAqua_RoomSE_Text_TwinsMegandpeg2Seen:
    .string "Je ne suis pas un bébé !\n"
    .string "Ce n'est pas gentil de dire ça à une dame !$"

SSAqua_RoomSE_Text_TwinsMegandpeg2Beaten:
    .string "Oh ! On a perdu !$"

SSAqua_RoomSE_Text_TwinsMegandpeg2After:
    .string "Parfois, les enfants sont plus malins\n"
    .string "que les adultes !$"
