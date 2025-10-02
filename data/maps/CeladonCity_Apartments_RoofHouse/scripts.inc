CeladonCity_Apartments_RoofHouse_MapScripts::
	.byte 0

CeladonCity_Apartments_RoofHouse_EventScript_BlackBelt::
	lock 
	faceplayer
	goto_if_set FLAG_GOT_TM_REST, CeladonCity_Apartments_RoofHouse_EventScript_BlackBeltAfter
	msgbox CeladonMansionRoofHouse_Text_PharmacistIntro, MSGBOX_DEFAULT	
	goto_if_set FLAG_NIGHT_POKEMON, CeladonCity_Apartments_RoofHouse_EventScript_BlackBeltRefused
	msgbox CeladonMansionRoofHouse_Text_PharmacistStory, MSGBOX_NPC
	giveitem ITEM_TM_REST
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_TM_REST
	msgbox CeladonMansionRoofHouse_Text_PharmacistCurse, MSGBOX_NPC
	closemessage
	release
	end

CeladonCity_Apartments_RoofHouse_EventScript_BlackBeltRefused::
	msgbox CeladonMansionRoofHouse_Text_PharmacistNotNight, MSGBOX_NPC
	closemessage
	release
	end

CeladonCity_Apartments_RoofHouse_EventScript_BlackBeltAfter::
	msgbox CeladonMansionRoofHouse_Text_PharmacistCurse, MSGBOX_NPC
	release
	end

CeladonMansionRoofHouse_Text_PharmacistIntro:
	.string "Laisse-moi te raconter une histoire terrifiante…$"

CeladonMansionRoofHouse_Text_PharmacistNotNight:
	.string "Mais bon, ce n'est pas aussi effrayant\n"
	.string "quand il fait encore jour dehors.\p"
	.string "Reviens après le coucher du soleil, d'accord?$"

CeladonMansionRoofHouse_Text_PharmacistStory:
	.string "Il était une fois un petit garçon\n"
	.string "à qui on avait offert un nouveau\l"
	.string "VÉLO…\p"
	.string "Il voulait l'essayer tout de suite…\p"
	.string "Il s'amusait tellement qu'il n'a pas\n"
	.string "remarqué que le soleil s'était couché…\p"
	.string "En rentrant chez lui dans la nuit\n"
	.string "noire, le vélo a soudainement\l"
	.string "ralenti !\p"
	.string "Les pédales sont devenues lourdes !\p"
	.string "Quand il a arrêté de pédaler, le\n"
	.string "vélo a commencé à reculer !\p"
	.string "C'était comme si le vélo était maudit\n"
	.string "et essayait de l'entraîner dans\l"
	.string "l'oubli !\p"
	.string "…\p"
	.string "…\p"
	.string "CRIIIIII !\p"
	.string "Le garçon montait en fait la\n"
	.string "PISTE CYCLABLE !\p"
	.string "…\n"
	.string "Ba-dum ba-dum !\p"
	.string "Pour avoir écouté si patiemment,\n"
	.string "tu peux prendre ceci--CT44 !$"

CeladonMansionRoofHouse_Text_PharmacistCurse:
	.string "La CT44, c'est REPOS.\p"
	.string "Elle permettra à ton POKéMON de faire\n"
	.string "une sieste en plein combat et de regagner de la santé.\p"
	.string "Mais bonne chance pour dormir après\n"
	.string "cette histoire terrifiante !$"
