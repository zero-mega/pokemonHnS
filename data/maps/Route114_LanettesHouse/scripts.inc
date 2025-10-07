Route114_LanettesHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route114_LanettesHouse_OnTransition
	.byte 0

Route114_LanettesHouse_OnTransition:
	setflag FLAG_LANDMARK_BillS_HOUSE
	end

Route114_LanettesHouse_EventScript_Bill::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_DOLL_Bill, Route114_LanettesHouse_EventScript_OfferAdvice
	setflag FLAG_SYS_PC_BILL
	msgbox Route114_LanettesHouse_Text_EverythingClutteredKeepThis, MSGBOX_DEFAULT
	givedecoration DECOR_LOTAD_DOLL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowNoRoomForDecor
	setflag FLAG_RECEIVED_DOLL_Bill
	release
	end

Route114_LanettesHouse_EventScript_OfferAdvice::
	msgbox Route114_LanettesHouse_Text_OrganizeYourBoxes, MSGBOX_DEFAULT
	release
	end

Route114_LanettesHouse_EventScript_Notebook::
	lockall
	msgbox Route114_LanettesHouse_Text_ResearchNotesPage1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route114_LanettesHouse_EventScript_NotebookPage2
	msgbox Route114_LanettesHouse_Text_ClosedTheNotebook, MSGBOX_DEFAULT
	releaseall
	end

Route114_LanettesHouse_EventScript_NotebookPage2::
	msgbox Route114_LanettesHouse_Text_ResearchNotesPage2, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, Route114_LanettesHouse_EventScript_NotebookPage3
	releaseall
	end

Route114_LanettesHouse_EventScript_NotebookPage3::
	msgbox Route114_LanettesHouse_Text_ResearchNotesPage3, MSGBOX_DEFAULT
	return

Route114_LanettesHouse_EventScript_PC::
	msgbox Route114_LanettesHouse_Text_EmailFromBill, MSGBOX_SIGN
	end

Route114_LanettesHouse_Text_EverythingClutteredKeepThis:
	.string "Léo : Oh ! {PLAYER}{KUN} !\p"
	.string "Je suis désolé pour tout ce désordre…\n"
	.string "Quand je me plonge dans la recherche,\l"
	.string "tout finit par devenir ainsi…\p"
	.string "C'est embarrassant… S'il te plaît,\n"
	.string "garde ça secret en échange de ceci.$"

Route114_LanettesHouse_Text_OrganizeYourBoxes:
	.string "Puis-je te donner un conseil sur mon\n"
	.string "système de stockage de POKéMON ?\p"
	.string "Tu devrais organiser tes BOÎTES pour\n"
	.string "savoir quels POKéMON s'y trouvent.$"

Route114_LanettesHouse_Text_ResearchNotesPage1:
	.string "Ce sont les notes de recherche de LÉO.\n"
	.string "Il y a des infos sur les BOÎTES.\p"
	.string "Concevoir des BOÎTES pour contenir 30\n"
	.string "POKéMON chacune.\p"
	.string "Chaque DRESSEUR devrait pouvoir stocker\n"
	.string "450 POKéMON sur le système PC.\p"
	.string "Continuer la lecture ?$"

Route114_LanettesHouse_Text_ResearchNotesPage2:
	.string "Un système de marquage devrait être\n"
	.string "ajouté pour faciliter l'organisation.\p"
	.string "Le nom et le fond de chaque BOÎTE\n"
	.string "pourront être changés pour plaire\l"
	.string "aux POKéMON stockés.\p"
	.string "Continuer la lecture ?$"

Route114_LanettesHouse_Text_ResearchNotesPage3:
	.string "Lorsqu'on stocke un POKéMON, il doit\n"
	.string "être envoyé dans la dernière BOÎTE\n"
	.string "consultée.\p"
	.string "Si cette BOÎTE est pleine, le POKéMON\n"
	.string "reçu est stocké dans la BOÎTE suivante.\p"
	.string "En d'autres termes, lorsqu'une BOÎTE\n"
	.string "est examinée, elle est automatiquement\l"
	.string "sélectionnée pour recevoir les POKéMON.$"

Route114_LanettesHouse_Text_ClosedTheNotebook:
	.string "{PLAYER} a refermé le carnet.$"

Route114_LanettesHouse_Text_EmailFromBill:
	.string "Il y a un e-mail de quelqu'un sur\n"
	.string "le PC.\p"
	.string "“… … … … … … …\p"
	.string "“Ton système de stockage est plus\n"
	.string "pratique que le mien.\p"
	.string "“Il possède de nombreuses fonctions\n"
	.string "conviviales qui le rendent amusant et\n"
	.string "utile aussi.\p"
	.string "“Je suis fier d'avoir participé à son\n"
	.string "développement.\p"
	.string "“J'espère que tu continueras la\n"
	.string "recherche sur les systèmes de stockage.\p"
	.string "“De la part de LÉO\n"
	.string "… … … … … … … …”$"
