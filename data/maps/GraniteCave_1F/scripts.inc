GraniteCave_1F_MapScripts::
	.byte 0

GraniteCave_1F_EventScript_Hiker::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_FLASH, GraniteCave_1F_EventScript_ReceivedFlash
	msgbox GraniteCave_1F_Text_GetsDarkAheadHereYouGo, MSGBOX_DEFAULT
	giveitem ITEM_HM_FLASH
	setflag FLAG_RECEIVED_HM_FLASH
	msgbox GraniteCave_1F_Text_ExplainFlash, MSGBOX_DEFAULT
	release
	end

GraniteCave_1F_EventScript_ReceivedFlash::
	msgbox GraniteCave_1F_Text_ExplainFlash, MSGBOX_DEFAULT
	release
	end

GraniteCave_1F_Text_GetsDarkAheadHereYouGo:
	.string "Hé, toi.\n"
	.string "Il fait très sombre plus loin.\l"
	.string "Ce sera difficile d'explorer.\p"
	.string "Le gars qui est passé tout à l'heure…\n"
	.string "STEVEN, je crois.\p"
	.string "Il savait comment utiliser FLASH, donc il\n"
	.string "devrait s'en sortir, mais…\p"
	.string "Pour nous, les Randonneurs, aider ceux\n"
	.string "qu'on rencontre, c'est notre devise.\p"
	.string "Tiens, je te donne ceci.$"

GraniteCave_1F_Text_ExplainFlash:
	.string "Tu peux utiliser FLASH si tu as la CS dans\n"
	.string "le sac et un POKéMON qui peut l'apprendre.\l"
	.string "Pas besoin de l'enseigner.\p"
	.string "Mais pour l'utiliser, il te faut le BADGE\n"
	.string "d'ARENE de MYOKARA.\p"
	.string "Ça éclaire même l'obscurité la plus\n"
	.string "profonde des grottes.$"
