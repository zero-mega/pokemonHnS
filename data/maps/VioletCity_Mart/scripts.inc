VioletCity_Mart_MapScripts::
	.byte 0

VioletCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart 0
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

VioletCity_Mart_EventScript_Granny::
	lock
	faceplayer
	msgbox VioletCity_Mart_Text_Granny, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_Mart_EventScript_Rocker::
	lock
	faceplayer
	msgbox VioletCity_Mart_Text_CooltrainerM, MSGBOX_DEFAULT
	closemessage
	release
	end
	
VioletCity_Mart_Text_Granny:
	.string "Quand tu attrapes un POKéMON pour la première fois,\n"
	.string "il peut être faible.\p"
	.string "Mais il finira par grandir pour\n"
	.string "devenir fort.\p"
	.string "Il est important de traiter les POKéMON\n"
	.string "avec amour.$"

VioletCity_Mart_Text_CooltrainerM:
	.string "Les POKéMON peuvent tenir des objets comme\n"
	.string "POTION et ANTIDOTE.\p"
	.string "Mais ils ne semblent pas savoir\n"
	.string "comment utiliser les objets fabriqués par l'homme.$"
