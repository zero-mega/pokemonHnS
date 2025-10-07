PalletTown_RedsHouse_2F_MapScripts::
	.byte 0

PalletTown_RedsHouse_2F_EventScript_NES::
	msgbox RedsHouse_Text_NES, MSGBOX_SIGN
	end

PalletTown_RedsHouse_2F_EventScript_PC::
	msgbox RedsHouse_Text_PC, MSGBOX_SIGN
	end

RedsHouse_Text_NES:
	.string "{PLAYER} a joué à la NES.\p"
	.string "Il vaut mieux y aller—pas de temps à perdre !$"

RedsHouse_Text_PC:
	.string "On dirait qu'elle n'a pas été utilisée\n"
	.string "depuis longtemps…$"
