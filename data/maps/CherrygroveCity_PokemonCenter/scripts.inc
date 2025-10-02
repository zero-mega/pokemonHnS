.set LOCALID_NURSE, 1

CherrygroveCity_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CherryGrove_Pokecenter_OnTransition
	.byte 0

CherryGrove_Pokecenter_OnTransition::
	setrespawn HEAL_LOCATION_CHERRYGROVE_CITY
	end

CherryGrove_Pokecenter_EventScript_Fisher::
	lock
	faceplayer
	msgbox CherryGrove_Pokecenter_Text_Fisher, MSGBOX_DEFAULT
	closemessage
	release
	end

CherryGrove_Pokecenter_EventScript_Gentleman::
	lock
	faceplayer
	msgbox CherryGrove_Pokecenter_Text_Gentleman, MSGBOX_DEFAULT
	closemessage
	release
	end

CherryGrove_Pokecenter_EventScript_Lass::
	lock
	faceplayer
	msgbox CherryGrove_Pokecenter_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

CherryGrove_Pokecenter_Chansey::
	lock
	faceplayer
	playmoncry SPECIES_CHANSEY, CRY_MODE_NORMAL
	msgbox CherryGrove_Pokecenter_Text_Chansey, MSGBOX_DEFAULT
	delay 40
	waitmoncry
	closemessage
	end

CherryGrove_Pokecenter_Text_Fisher:
	.string "C'est génial. Je peux stocker autant\n"
	.string "de POKéMON que je veux, et c'est gratuit !$"

CherryGrove_Pokecenter_Text_Gentleman:
	.string "Ce PC est gratuit pour tous les\n"
	.string "dresseurs.$"

CherryGrove_Pokecenter_Text_Lass:
	.string "On dit qu'une marmite surveillée\n"
	.string "ne bout jamais. Mais regarder l'horloge\l"
	.string "du CENTRE POKéMON fait passer le temps !$"

CherryGrove_Pokecenter_Text_Chansey:
	.string "LEVEINARD : Chaan ! Sii !$"
