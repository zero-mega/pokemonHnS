Route28_House_MapScripts::
	.byte 0

Route28House_EventScript_Celebrity::
	lock
	goto_if_set FLAG_GOT_TM_STEEL_WING Route28House_EventScript_CelebrityAfter
	msgbox Route28House_Text_Celebrity1, MSGBOX_NPC
	giveitem ITEM_TM_STEEL_WING
	setflag FLAG_GOT_TM_STEEL_WING
Route28House_EventScript_CelebrityAfter::
	msgbox Route28House_Text_Celebrity2, MSGBOX_NPC
	release
	end

Route28House_Text_Celebrity1:
	.string "Oh, mince. Tu m'as trouvé.\p"
	.string "S'il te plaît, ne dis à personne que je suis ici.\p"
	.string "Je vais te donner ceci pour garder mon\n"
	.string "secret. S'il te plaît?$"

Route28House_Text_Celebrity2:
	.string "C'est difficile d'être une grande célébrité.\p"
	.string "Où que j'aille, les gens me poursuivent.\p"
	.string "Je veux juste qu'on me laisse tranquille…$"

Route28House_Text_Fearow:
	.string "RAPASDEPIC : Raapa !$"

