Route20_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route20_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route20_EventScript_ShellBell::
	finditem ITEM_SHELL_BELL
	end

Route20_OnTransition:
	callnative SetTimeBasedEncounters
	end

Route20_EventScript_Nicole::
	trainerbattle_single TRAINER_NICOLE Route20_Text_SwimmerfNicoleSeen, Route20_Text_SwimmerfNicoleBeaten
	msgbox Route20_Text_SwimmerfNicoleAfterBattle, MSGBOX_AUTOCLOSE
	end	

Route20_EventScript_Lori::
	trainerbattle_single TRAINER_LORI Route20_Text_SwimmerfLoriSeen, Route20_Text_SwimmerfLoriBeaten
	msgbox Route20_Text_SwimmerfLoriAfterBattle, MSGBOX_AUTOCLOSE
	end	

Route20_EventScript_Cameron::
	trainerbattle_single TRAINER_CAMERON Route20_Text_SwimmermCameronSeen, Route20_Text_SwimmermCameronBeaten
	msgbox Route20_Text_SwimmermCameronAfterBattle, MSGBOX_AUTOCLOSE
	end	

Route20_EventScript_SeafoamSign::
	msgbox Route20_Text_SeafoamSign, MSGBOX_SIGN
	end

Route20_EventScript_GymSign::
	msgbox Route20_Text_CinnabarIsland_GymUnusedSign, MSGBOX_SIGN
	end

Route20_EventScript_Seel::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SEEL, CRY_MODE_NORMAL
	msgbox Route20_Text_Seel, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route20_EventScript_Dewgong::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_DEWGONG, CRY_MODE_NORMAL
	msgbox Route20_Text_Dewgong, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route20_EventScript_Headlocker::
	msgbox Route20_Text_Headlocker, MSGBOX_NPC
	end

Route20_Text_Headlocker:
	.string "Il y a un POKéMON rare sur cette\n"
	.string "route.\p"
	.string "Et parfois, il porte un objet\n"
	.string "d'évolution rare.\p"
	.string "C'est doublement rare !\p"
	.string "Je dois finir mon POKéDEX, alors\n"
	.string "je pêche ici depuis des heures !$"

Route20_Text_Seel:
	.string "OTARIA : Otaria otaria !$"

Route20_Text_Dewgong:
	.string "LAMANTINE : Gooooong !$"

Route20_Text_SeafoamSign:
	.string "ÎLES ÉCUME$"

Route20_Text_SwimmerfNicoleSeen:
	.string "Je me sens tellement plus légère dans l'eau.$"

Route20_Text_SwimmerfNicoleBeaten:
	.string "Oh, non !$"

Route20_Text_SwimmerfNicoleAfterBattle:
	.string "Nager fait travailler tout le corps.\p"
	.string "C'est vraiment bon pour la santé.$"

Route20_Text_SwimmerfLoriSeen:
	.string "Quelle impressionnante collection de\n"
	.string "BADGES ! On devrait se battre !$"

Route20_Text_SwimmerfLoriBeaten:
	.string "Non !$"

Route20_Text_SwimmerfLoriAfterBattle:
	.string "SURF n'est plus la seule CS\n"
	.string "que tu utilises dans l'eau.$"

Route20_Text_SwimmermCameronSeen:
	.string "Je suppose qu'il est impossible de nager\n"
	.string "jusqu'à JOHTO.$"

Route20_Text_SwimmermCameronBeaten:
	.string "Aïe !$"

Route20_Text_SwimmermCameronAfterBattle:
	.string "En plus de la mer, je peux aussi nager\n"
	.string "dans les étangs et les rivières.$"

Route20_Text_CinnabarIsland_GymUnusedSign:
	.string "Que dit ce panneau ?\p"
	.string "CHAMPION DE L'ARÈNE DE CRAMOIS'ÎLE : AUGUSTE$"
