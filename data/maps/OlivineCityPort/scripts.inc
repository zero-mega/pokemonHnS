OlivineCityPort_MapScripts::
	.byte 0

OlivineCityPort_EventScript_Fisherman1::
	lock
	faceplayer
	msgbox OlivineCityPort_Text_PortFisherman1, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCityPort_EventScript_Fisherman2::
	lock
	faceplayer
	msgbox OlivineCityPort_Text_Fisherman2, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCityPort_Text_PortFisherman1:
	.string "FAST SHIP S.S.AQUA used to sail to\n"
	.string "KANTO on Mondays and Fridays. But\l"
	.string "now, it sails almost constantly!$"

OlivineCityPort_Text_Fisherman2:
	.string "Aw yeah, I'm fishin'$"
