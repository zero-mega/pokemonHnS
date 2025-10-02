CherrygroveCity_House1_MapScripts::
	.byte 0

CherrygroveCity_House1_EventScript_Baldingman::
	lock
	faceplayer
	msgbox CherrygroveCity_GymSpeechHouse_Text_PokefanM, MSGBOX_DEFAULT
	closemessage
	release
	end

CherrygroveCity_House1_EventScript_Kid::
	lock
	faceplayer
	msgbox CherrygroveCity_GymSpeechHouse_Text_BugCatcher, MSGBOX_DEFAULT
	closemessage
	release
	end

CherrygroveCity_GymSpeechHouse_Text_PokefanM:
	.string "Tu essaies de voir à quel point\n"
	.string "tu es un bon DRESSEUR de POKéMON ?\p"
	.string "Tu devrais visiter les ARENES\n"
	.string "de tout JOHTO et collectionner\l"
	.string "les BADGES.$"

CherrygroveCity_GymSpeechHouse_Text_BugCatcher:
	.string "Quand je serai plus grand, je\n"
	.string "serai un CHAMPION D'ARENE !\p"
	.string "Je fais combattre mes POKéMON\n"
	.string "avec ceux de mes amis pour les\l"
	.string "rendre plus forts !$"
