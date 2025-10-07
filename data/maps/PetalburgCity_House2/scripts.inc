PetalburgCity_House2_MapScripts::
	.byte 0

PetalburgCity_House2_EventScript_Woman::
	msgbox PetalburgCity_House2_Text_NormanBecameGymLeader, MSGBOX_NPC
	end

PetalburgCity_House2_EventScript_SchoolKid::
	msgbox PetalburgCity_House2_Text_BattledNormanOnce, MSGBOX_NPC
	end

PetalburgCity_House2_Text_NormanBecameGymLeader:
	.string "NORMAN est devenu le nouveau\n"
	.string "CHAMPION d'ARÈNE de notre ville.\p"
	.string "Je crois qu'il a fait venir sa famille\n"
	.string "de très loin.$"

PetalburgCity_House2_Text_BattledNormanOnce:
	.string "J'ai affronté NORMAN une fois, mais,\n"
	.string "ouah, il était bien trop fort.\p"
	.string "Comment dire ?\p"
	.string "J'ai juste l'impression qu'il vit\n"
	.string "pour les POKéMON.$"

