.set LOCALID_OLIVINE_SABRINA, 3

OlivineCity_PortOutside_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OlivineCity_MapScript_OnTransition
	.byte 0

OlivineCity_PortOutside_EventScript_Sabrina::
    lock
    faceplayer
    msgbox OlivineCity_PortOutside_Text_Sabrina, MSGBOX_DEFAULT
    closemessage
    fadescreenswapbuffers FADE_TO_BLACK
    setflag FLAG_HIDE_OLIVINE_SABRINA
    removeobject LOCALID_OLIVINE_SABRINA
    fadescreenswapbuffers FADE_FROM_BLACK
    clearflag FLAG_HIDE_DOJO_SABRINA
    release
    end

OlivineCity_PortOutside_Text_Sabrina:
    .string "SABRINA : Sans raison apparente,\n"
    .string "j'ai envie de voir l'océan.\p"
    .string "On se retrouve au DOJO\n"
    .string "KARATÉ.$"

OlivineCity_PortOutside_EventScript_Fisherman1::
	lock
	faceplayer
	msgbox OlivineCity_PortOutside_Text_PortFisherman1, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_PortOutside_EventScript_Fisherman2::
	lock
	faceplayer
	msgbox OlivineCity_PortOutside_Text_Fisherman2, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_PortOutside_Text_PortFisherman1:
	.string "Le BATEAU RAPIDE S.S.AQUA allait\n"
	.string "à KANTO les lundis et vendredis.\l"
	.string "Mais maintenant, il navigue presque tout le temps !$"

OlivineCity_PortOutside_Text_Fisherman2:
	.string "Oh ouais, je pêche.$"
