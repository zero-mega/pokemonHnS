MtPyre_1F_MapScripts::
	.byte 0

MtPyre_1F_DusknoirMisdreavusEvo::
	msgbox MtPyre_1F_DusknoirMisdreavusEvo_Text, MSGBOX_NPC
	end

MtPyre_1F_DusknoirMisdreavusEvo_Text:
	.string "Les DUSKULL sauvages tiennent parfois une SPELL TAG.\n"
	.string "Je me demande pourquoi. Que font-ils avec ?\l"
	.string "Peut-être s'en servent-ils pour évoluer ?\p"
	.string "Ce que je sais, c'est que MISDREAVUS\n"
	.string "évolue s'il la tient pendant la nuit.$"

MtPyre_1F_EventScript_CleanseTagWoman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_CLEANSE_TAG, MtPyre_1F_EventScript_ReceivedCleanseTag
	msgbox MtPyre_1F_Text_TakeThisForYourOwnGood, MSGBOX_DEFAULT
	giveitem ITEM_CLEANSE_TAG
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_CLEANSE_TAG
	release
	end

MtPyre_1F_EventScript_ReceivedCleanseTag::
	msgbox MtPyre_1F_Text_ExplainCleanseTag, MSGBOX_DEFAULT
	release
	end

MtPyre_1F_EventScript_PokefanF::
	msgbox MtPyre_1F_Text_ComeToPayRespects, MSGBOX_NPC
	end

MtPyre_1F_EventScript_Man::
	msgbox MtPyre_1F_Text_RestingPlaceOfZigzagoon, MSGBOX_NPC
	end

MtPyre_1F_Text_TakeThisForYourOwnGood:
	.string "Toutes sortes d'êtres errent sur les pentes\n"
	.string "du MT. PYRÉE…\p"
	.string "On ne sait jamais ce qui peut arriver.\n"
	.string "Prends ceci. C'est pour ton bien.$"

MtPyre_1F_Text_ExplainCleanseTag:
	.string "Fais tenir ce TALISMAN PUR à un POKéMON.\p"
	.string "Cela aidera à repousser les POKéMON sauvages.$"

MtPyre_1F_Text_ComeToPayRespects:
	.string "Es-tu venu rendre hommage aux esprits\n"
	.string "des POKéMON disparus ?\p"
	.string "Tu dois beaucoup tenir à tes POKéMON.$"

MtPyre_1F_Text_RestingPlaceOfZigzagoon:
	.string "Ici repose mon ZIGZAGOON.\n"
	.string "Je l'aimais beaucoup…$"
