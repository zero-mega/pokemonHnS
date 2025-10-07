Route8_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route8_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route8_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route8_EventScript_Dwayne::
	trainerbattle_single TRAINER_DWAYNE, Route8_Text_BikerDwayneSeen, Route8_Text_BikerDwayneBeaten
	msgbox Route8_Text_BikerDwayneAfter, MSGBOX_AUTOCLOSE
	end

Route8_EventScript_Harris::
	trainerbattle_single TRAINER_HARRIS, Route8_Text_BikerHarrisSeen, Route8_Text_BikerHarrisBeaten
	msgbox Route8_Text_BikerHarrisAfter, MSGBOX_AUTOCLOSE
	end

Route8_EventScript_Zeke::
	trainerbattle_single TRAINER_ZEKE, Route8_Text_BikerZekeSeen, Route8_Text_BikerZekeBeaten
	msgbox Route8_Text_BikerZekeAfter, MSGBOX_AUTOCLOSE
	end

Route8_EventScript_Sam::
	trainerbattle_single TRAINER_SAM, Route8_Text_SupernerdSamSeen, Route8_Text_SupernerdSamBeaten
	msgbox Route8_Text_SupernerdSamAfter, MSGBOX_AUTOCLOSE
	end

Route8_EventScript_Tom::
	trainerbattle_single TRAINER_TOM, Route8_Text_SupernerdTomSeen, Route8_Text_SupernerdTomBeaten
	msgbox Route8_Text_SupernerdTomAfter, MSGBOX_AUTOCLOSE
	end

Route8_Text_BikerDwayneSeen:
	.string "Nous sommes le groupe de dresseurs\n"
	.string "de la FÉDÉRATION POKéMON DE KANTO.\p"
	.string "On va t'écraser sous nos roues !$"

Route8_Text_BikerDwayneBeaten:
	.string "D-désolé !$"

Route8_Text_BikerDwayneAfter:
	.string "La FÉDÉRATION POKéMON DE KANTO ne\n"
	.string "tombera jamais !$"

Route8_Text_BikerHarrisSeen:
	.string "Les flics ont fermé notre\n"
	.string "PASSAGE SOUTERRAIN !\p"
	.string "Ça me met vraiment en colère !$"

Route8_Text_BikerHarrisBeaten:
	.string "P-pardonne-moi !$"

Route8_Text_BikerHarrisAfter:
	.string "Battus par un gamin de JOHTO…$"

Route8_Text_BikerZekeSeen:
	.string "Nous sommes la FÉDÉRATION POKéMON\n"
	.string "DE KANTO !\n"
	.string "C'est parti !$"

Route8_Text_BikerZekeBeaten:
	.string "Oups ! Désolé !$"

Route8_Text_BikerZekeAfter:
	.string "On va essayer de ne plus déranger\n"
	.string "personne désormais…$"

Route8_Text_SupernerdSamSeen:
	.string "Comment fonctionne le TRAIN MAGNÉTIQUE ?$"

Route8_Text_SupernerdSamBeaten:
	.string "Je veux juste voir le TRAIN\n"
	.string "MAGNÉTIQUE…$"

Route8_Text_SupernerdSamAfter:
	.string "La puissance des aimants est géniale !$"

Route8_Text_SupernerdTomSeen:
	.string "Hm… Tu as beaucoup de BADGES d'ARÈNE.$"

Route8_Text_SupernerdTomBeaten:
	.string "Comme je le pensais… Tu es fort !$"

Route8_Text_SupernerdTomAfter:
	.string "Les BADGES d'ARÈNE donnent des avantages\n"
	.string "en combat.$"

Route8_Text_LockedDoor:
	.string "C'est fermé…$"

Route8_Text_UndergroundPathSign:
	.string "Le flyer est déchiré.\p"
	.string "C'est impossible à lire…$"
