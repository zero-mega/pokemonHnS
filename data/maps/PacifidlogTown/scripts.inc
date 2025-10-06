PacifidlogTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PacifidlogTown_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, PacifidlogTown_OnResume
	.byte 0

PacifidlogTown_OnTransition:
	setflag FLAG_VISITED_CIANWOOD_CITY
	end

PacifidlogTown_OnResume:
	setstepcallback STEP_CB_PACIFIDLOG_BRIDGE
	end

PacifidlogTown_EventScript_NinjaBoy::
	msgbox PacifidlogTown_Text_NeatHousesOnWater, MSGBOX_NPC
	end

PacifidlogTown_EventScript_Girl::
	msgbox PacifidlogTown_Text_FastRunningCurrent, MSGBOX_NPC
	end

PacifidlogTown_EventScript_Fisherman::
	msgbox PacifidlogTown_Text_SkyPillarTooScary, MSGBOX_NPC
	end

PacifidlogTown_EventScript_TownSign::
	msgbox PacifidlogTown_Text_TownSign, MSGBOX_SIGN
	end

PacifidlogTown_Text_FastRunningCurrent:
	.string "La mer entre PACIFIDLOG et\n"
	.string "POIVRESSEL a un courant rapide.\p"
	.string "Si tu décides d'utiliser SURF, tu\n"
	.string "pourrais te retrouver emporté ailleurs.$"

PacifidlogTown_Text_NeatHousesOnWater:
	.string "Tu vois, c'est chouette, non ?\n"
	.string "Ces maisons sont sur l'eau !\p"
	.string "Je suis né ici !$"

PacifidlogTown_Text_SkyPillarTooScary:
	.string "La PILIER CELESTE ?\p"
	.string "…Oh, tu dois parler de cette tour\n"
	.string "très haute un peu plus loin.\p"
	.string "Si tu me demandais, je ne la gravirais pas.\n"
	.string "C'est trop effrayant d'aller si haut.\p"
	.string "La vie au niveau de la mer à PACIFIDLOG,\n"
	.string "ça me va très bien.$"

PacifidlogTown_Text_TownSign:
	.string "PACIFIVILLE\p"
	.string "« Là où le soleil du matin sourit\n"
	.string "aux eaux. »$"

