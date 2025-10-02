DewfordTown_House2_MapScripts::
	.byte 0

DewfordTown_House2_EventScript_Man::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_SILK_SCARF, DewfordTown_House2_EventScript_ExplainSilkScarf
	msgbox DewfordTown_House2_Text_WantYouToHaveSilkScarf, MSGBOX_DEFAULT
	giveitem ITEM_SILK_SCARF
	goto_if_eq VAR_RESULT, FALSE, DewfordTown_House2_EventScript_NoRoomForScarf
	setflag FLAG_RECEIVED_SILK_SCARF
	release
	end

DewfordTown_House2_EventScript_NoRoomForScarf::
	msgbox DewfordTown_House2_Text_NoRoom, MSGBOX_DEFAULT
	release
	end

DewfordTown_House2_EventScript_ExplainSilkScarf::
	msgbox DewfordTown_House2_Text_ExplainSilkScarf, MSGBOX_DEFAULT
	release
	end

DewfordTown_House2_EventScript_Boy::
	msgbox DewfordTown_House2_Text_BrawlySoCool, MSGBOX_NPC
	end

DewfordTown_House2_Text_WantYouToHaveSilkScarf:
	.string "Ouvre grand les yeux sur ça !\p"
	.string "C'est un FOULARD SOIE. C'est le summum\n"
	.string "de la mode, tu vois !\p"
	.string "Oh, je vois tes yeux briller !\n"
	.string "Tu apprécies mon style éblouissant !\p"
	.string "Oh, tu es un vrai plaisir !\n"
	.string "Tiens, je veux que tu l'aies !$"

DewfordTown_House2_Text_NoRoom:
	.string "Oh, tu n'as pas de place ?\p"
	.string "Écoute bien, ce FOULARD est\n"
	.string "indispensable ! Moi, je vendrais tous mes objets\l"
	.string "pour l'obtenir !$"

DewfordTown_House2_Text_ExplainSilkScarf:
	.string "Le FOULARD SOIE augmente la puissance\n"
	.string "des attaques de type NORMAL.\p"
	.string "C'est un FOULARD merveilleux qui ira\n"
	.string "à presque tous les POKéMON !$"

DewfordTown_House2_Text_BrawlySoCool:
	.string "Waouh, tu as traversé la mer\n"
	.string "pour venir à POIVRESSEL ?\p"
	.string "Tu es peut-être venu parce que tu as\n"
	.string "entendu parler de BASTIEN ?\p"
	.string "Il est tellement cool…\n"
	.string "Tout le monde l'idolâtre.$"
