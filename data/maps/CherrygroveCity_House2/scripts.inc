CherrygroveCity_House2_MapScripts::
	.byte 0

CherrygroveCity_House2_EventScript_GuideGent::
	lock
	faceplayer
	msgbox CherrygroveCity_GuideHouse_Text_GuideGent, MSGBOX_DEFAULT
	closemessage
	release
	end

CherrygroveCity_GuideHouse_Text_GuideGent:
	.string "Quand j'étais un jeune garçon, j'étais\n"
	.string "un dresseur très doué !\p"
	.string "Voici un conseil :\n"
	.string "Attrape beaucoup de POKéMON !\p"
	.string "Traite-les tous avec gentillesse !$"
