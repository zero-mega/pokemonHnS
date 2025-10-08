.set LOCALID_DOCK, 1

SlateportCity_SternsShipyard_1F_MapScripts::
	.byte 0

SlateportCity_SternsShipyard_1F_EventScript_Dock::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_SternsShipyard_1F_EventScript_FerryReady
	goto_if_set FLAG_BADGE07_GET, SlateportCity_SternsShipyard_1F_EventScript_BrineyJoined
	goto_if_set FLAG_DELIVERED_DEVON_GOODS, SlateportCity_SternsShipyard_1F_EventScript_NeedVeteran
	goto_if_set FLAG_DOCK_REJECTED_DEVON_GOODS, SlateportCity_SternsShipyard_1F_EventScript_GoFindStern
	msgbox SlateportCity_SternsShipyard_1F_Text_CantMakeHeadsOrTails, MSGBOX_DEFAULT
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_MeetDockDeliverToStern, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DOCK, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setflag FLAG_DOCK_REJECTED_DEVON_GOODS
	setflag FLAG_GARBAGEFLAG
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_FerryReady::
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_FerryIsReady, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_BrineyJoined::
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_BrineyJoinedUs, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_GoFindStern::
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_CouldYouFindStern, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DOCK, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_NeedVeteran::
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_CouldUseAdviceFromVeteran, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_Scientist1::
	msgbox SlateportCity_SternsShipyard_1F_Text_SeaIsLikeLivingThing, MSGBOX_NPC
	end

SlateportCity_SternsShipyard_1F_EventScript_Scientist2::
	msgbox SlateportCity_SternsShipyard_1F_Text_GetSeasickEasily, MSGBOX_NPC
	end

SlateportCity_SternsShipyard_1F_EventScript_Briney::
	msgbox SlateportCity_SternsShipyard_1F_Text_DecidedToHelpDock, MSGBOX_NPC
	end

SlateportCity_SternsShipyard_1F_Text_CantMakeHeadsOrTails:
	.string "Euh… Si ceci va ici, et cela\n"
	.string "va là-bas…\p"
	.string "Alors, où va ce truc ?\n"
	.string "Et qu'est-ce que je fais de ce machin ?\p"
	.string "Aaaargh ! Je n'y comprends\n"
	.string "absolument rien !$"

SlateportCity_SternsShipyard_1F_Text_MeetDockDeliverToStern:
	.string "Hein ?\n"
	.string "Salut, je suis DOCK.\p"
	.string "Le CAPT. PORTUA m'a demandé de\n"
	.string "concevoir un ferry.\p"
	.string "Oh ! Ce que tu as là…\n"
	.string "Ce sont les MARCHANDISES DEVON ?\p"
	.string "Mais, hmm…\n"
	.string "Ça ne va pas…\p"
	.string "Le CAPT. PORTUA est parti quelque part.\n"
	.string "Il a dit qu'il avait du travail à faire.\p"
	.string "Peux-tu aller chercher le CAPT.\n"
	.string "PORTUA et lui remettre ça ?$"

SlateportCity_SternsShipyard_1F_Text_CouldYouFindStern:
	.string "DOCK : Où est donc passé le CAPT.\n"
	.string "PORTUA ?\p"
	.string "Peux-tu aller trouver le CAPT. PORTUA et\n"
	.string "lui remettre ce colis ?$"

SlateportCity_SternsShipyard_1F_Text_CouldUseAdviceFromVeteran:
	.string "DOCK : La construction navale est un art.\p"
	.string "Beaucoup de choses ne peuvent pas\n"
	.string "être résolues juste par des calculs.\p"
	.string "J'aurais vraiment besoin des conseils d'un\n"
	.string "vétéran qui connaît bien la mer…$"

SlateportCity_SternsShipyard_1F_Text_BrineyJoinedUs:
	.string "DOCK : Salut ! M. MARCO nous a rejoints\n"
	.string "pour nous prêter main-forte.\p"
	.string "Grâce à ce marin chevronné, le ferry\n"
	.string "avance bien.$"

SlateportCity_SternsShipyard_1F_Text_FerryIsReady:
	.string "DOCK : Le ferry est enfin prêt !\p"
	.string "Le nouveau M.S. MARÉE est vraiment\n"
	.string "une merveille de technologie !\p"
	.string "Mais, j'ai l'impression qu'on pourrait\n"
	.string "faire encore mieux.\p"
	.string "Tu sais, le progrès ne s'arrête jamais\n"
	.string "dans la technologie.$"

SlateportCity_SternsShipyard_1F_Text_DecidedToHelpDock:
	.string "M. MARCO : Ah, {PLAYER}{KUN} !\n"
	.string "Ça fait longtemps !\p"
	.string "Aye, depuis que je t'ai rencontré, ce vieux\n"
	.string "loup de mer a retrouvé la pêche !\p"
	.string "Alors j'ai décidé d'aider DOCK à\n"
	.string "construire un ferry.\p"
	.string "Aye, après tout, un ferry pourrait\n"
	.string "transporter beaucoup de monde.\p"
	.string "Mais tu sais, ce DOCK est vraiment\n"
	.string "quelqu'un de spécial.\p"
	.string "Avec son talent pour la technologie et\n"
	.string "mon expérience, je suis sûr qu'on peut\l"
	.string "construire un super navire, aye !$"

SlateportCity_SternsShipyard_1F_Text_SeaIsLikeLivingThing:
	.string "Les saisons, la météo, la position\n"
	.string "de la lune dans le ciel…\p"
	.string "Tout cela fait que la mer change\n"
	.string "d'aspect.\p"
	.string "C'est vrai !\n"
	.string "La mer est comme un être vivant !$"

SlateportCity_SternsShipyard_1F_Text_GetSeasickEasily:
	.string "J'ai facilement le mal de mer.\n"
	.string "Alors j'aide ici à la place.$"
