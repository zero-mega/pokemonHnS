Route116_TunnelersRestHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route116_TunnelersRestHouse_OnTransition
	.byte 0

Route116_TunnelersRestHouse_OnTransition:
	setflag FLAG_LANDMARK_TUNNELERS_REST_HOUSE
	end

Route116_TunnelersRestHouse_EventScript_Tunneler1::
	msgbox Route116_TunnelersRestHouse_Text_WeHadToStopBoring, MSGBOX_NPC
	end

Route116_TunnelersRestHouse_EventScript_Tunneler2::
	msgbox Route116_TunnelersRestHouse_Text_ManDiggingHisWayToVerdanturf, MSGBOX_NPC
	end

Route116_TunnelersRestHouse_EventScript_Tunneler3::
	lock
	faceplayer
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, Route116_TunnelersRestHouse_EventScript_TunnelOpened
	msgbox Route116_TunnelersRestHouse_Text_GetToVerdanturfWithoutTunnel, MSGBOX_DEFAULT
	release
	end

Route116_TunnelersRestHouse_EventScript_TunnelOpened::
	msgbox Route116_TunnelersRestHouse_Text_TunnelHasGoneThrough, MSGBOX_DEFAULT
	release
	end

Route116_TunnelersRestHouse_Text_WeHadToStopBoring:
	.string "Ce tunnel de RUSTURF là-bas…\p"
	.string "Au début, nous avions une grande équipe\n"
	.string "qui creusait la roche avec les machines les plus modernes.\l"
	.string "Mais nous avons dû arrêter.\p"
	.string "Il s'est avéré que cela aurait eu\n"
	.string "un effet négatif sur les POKéMON sauvages\l"
	.string "de la région.\p"
	.string "Alors, nous n'avons plus rien à faire\n"
	.string "à part traîner ici sans rien faire.$"

Route116_TunnelersRestHouse_Text_ManDiggingHisWayToVerdanturf:
	.string "Il y a un homme qui creuse son chemin\n"
	.string "vers VERDANTURF tout seul.\l"
	.string "Il est déterminé à passer.\p"
	.string "Il dit que s'il creuse petit à petit\n"
	.string "sans utiliser de machines, il ne\l"
	.string "dérangera pas les POKéMON et il évitera\l"
	.string "d'abîmer l'environnement naturel.\p"
	.string "Je me demande s'il a déjà réussi.$"

Route116_TunnelersRestHouse_Text_GetToVerdanturfWithoutTunnel:
	.string "Pour aller à VERDANTURF sans utiliser\n"
	.string "ce tunnel, il faudrait traverser la mer\l"
	.string "jusqu'à POIVRESSEL, puis naviguer vers\l"
	.string "PORTUAL, et enfin passer par LAVANDIA.$"

Route116_TunnelersRestHouse_Text_TunnelHasGoneThrough:
	.string "Tu as entendu ? Le tunnel vers VERDANTURF\n"
	.string "est enfin terminé !\p"
	.string "Parfois, si on espère assez fort,\n"
	.string "les rêves deviennent réalité.$"
