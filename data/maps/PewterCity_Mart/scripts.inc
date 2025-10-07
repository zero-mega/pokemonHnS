PewterCity_Mart_MapScripts::
	.byte 0

PewterCity_Mart_EventScript_Youngster::
	msgbox PewterCity_Mart_Text_Youngster, MSGBOX_NPC
	end

PewterCity_Mart_EventScript_Nerd::
	msgbox PewterCity_Mart_Text_SuperNerd, MSGBOX_NPC
	end

PewterCity_Mart_Text_Youngster:
	.string "Salut ! Regarde mon LÉVIATOR !\p"
	.string "Je l'ai élevé à partir d'un MAGICARPE. Je\n"
	.string "n'arrive pas à croire à quel point il est devenu fort.$"

PewterCity_Mart_Text_SuperNerd:
	.string "Il y avait autrefois un vieil homme bizarre\n"
	.string "qui vendait des MAGICARPE.\p"
	.string "Il disait que les MAGICARPE du\n"
	.string "LAC COLÈRE étaient excellents.$"
