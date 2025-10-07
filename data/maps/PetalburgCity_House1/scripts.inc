PetalburgCity_House1_MapScripts::
	.byte 0

PetalburgCity_House1_EventScript_Man::
	msgbox PetalburgCity_House1_Text_TravelingIsWonderful, MSGBOX_NPC
	end

PetalburgCity_House1_EventScript_Woman::
	msgbox PetalburgCity_House1_Text_GoOnAdventure, MSGBOX_NPC
	end

PetalburgCity_House1_Text_TravelingIsWonderful:
	.string "Voyager, c'est merveilleux !\p"
	.string "Quand j'étais jeune, j'ai parcouru les mers\n"
	.string "et les montagnes !$"

PetalburgCity_House1_Text_GoOnAdventure:
	.string "Soupir…\p"
	.string "J'aimerais tant partir à l'aventure\n"
	.string "avec des POKéMON…\p"
	.string "Ramper dans l'herbe humide…\n"
	.string "Gravir des montagnes rocheuses et escarpées…\p"
	.string "Traverser des mers déchaînées…\n"
	.string "Errer dans des grottes sombres…\p"
	.string "Et, parfois, avoir un peu le mal du pays…\p"
	.string "Ça doit être fabuleux de voyager !$"
