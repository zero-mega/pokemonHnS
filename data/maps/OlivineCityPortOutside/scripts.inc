.set LOCALID_OLIVINE_SABRINA, 3

OlivineCityPortOutside_MapScripts::
	.byte 0

OlivineCityPortOutside_EventScript_Sabrina::
    lock
    faceplayer
    msgbox OlivineCityPortOutside_Text_Sabrina, MSGBOX_DEFAULT
    closemessage
    fadescreenswapbuffers FADE_TO_BLACK
    setflag FLAG_HIDE_OLIVINE_SABRINA
    removeobject LOCALID_OLIVINE_SABRINA
    fadescreenswapbuffers FADE_FROM_BLACK
    clearflag FLAG_HIDE_DOJO_SABRINA
    release
    end

OlivineCityPortOutside_Text_Sabrina:
    .string "SABRINA: Out of the blue,\n"
	.string "I get the urge to see the ocean.\p"
	.string "I'll see you at the FIGHTING\n"
	.string "DOJO.$"

OlivineCityPortOutside_EventScript_Fisherman1::
	lock
	faceplayer
	msgbox OlivineCityPortOutside_Text_PortFisherman1, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCityPortOutside_EventScript_Fisherman2::
	lock
	faceplayer
	msgbox OlivineCityPortOutside_Text_Fisherman2, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCityPortOutside_Text_PortFisherman1:
	.string "FAST SHIP S.S.AQUA used to sail to\n"
	.string "KANTO on Mondays and Fridays. But\l"
	.string "now, it sails almost constantly!$"

OlivineCityPortOutside_Text_Fisherman2:
	.string "Aw yeah, I'm fishin'$"
