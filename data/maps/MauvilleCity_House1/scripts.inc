MauvilleCity_House1_MapScripts::
	.byte 0

MauvilleCity_House1_EventScript_RockSmashDude::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_ROCK_SMASH, MauvilleCity_House1_EventScript_ReceivedRockSmash
	msgbox MauvilleCity_House1_Text_ImRockSmashDudeTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_HM_ROCK_SMASH
	setflag FLAG_RECEIVED_HM_ROCK_SMASH
	setflag FLAG_GARBAGEFLAG
	msgbox MauvilleCity_House1_Text_ExplainRockSmash, MSGBOX_DEFAULT
	release
	end

MauvilleCity_House1_EventScript_ReceivedRockSmash::
	msgbox MauvilleCity_House1_Text_MonCanFlyOutOfSmashedRock, MSGBOX_DEFAULT
	release
	end

MauvilleCity_House1_Text_ImRockSmashDudeTakeThis:
	.string "Youhou !\p"
	.string "On m'appelle le MEC ÉCLAT'ROC,\n"
	.string "mais je trouve ça un peu dégradant.\p"
	.string "Je pense mériter un peu plus de respect,\n"
	.string "genre, le DUDE ÉCLAT'ROC !\p"
	.string "Youhou !\p"
	.string "En tout cas, tes POKéMON ont l'air\n"
	.string "plutôt costauds.\p"
	.string "J'aime ça !\n"
	.string "Tiens, prends cette CS !$"

MauvilleCity_House1_Text_ExplainRockSmash:
	.string "Cette CS contient ÉCLAT'ROC.\p"
	.string "Si tu rencontres de gros rochers\n"
	.string "qui bloquent ton chemin…\p"
	.string "Eh bien, utilise cette CS et fracasse-les\n"
	.string "pour dégager la voie !\p"
	.string "Oui, monsieur ! Éclate les rochers, je dis !\n"
	.string "Youhou !$"

MauvilleCity_House1_Text_MonCanFlyOutOfSmashedRock:
	.string "Ah oui, si tu brises un rocher, un POKéMON\n"
	.string "peut surgir de sa cachette.\p"
	.string "Youhou !$"
