SlateportCity_SternsShipyard_2F_MapScripts::
	.byte 0

SlateportCity_SternsShipyard_2F_EventScript_Scientist1::
	msgbox SlateportCity_SternsShipyard_2F_Text_ShipDesignMoreLikeBuilding, MSGBOX_NPC
	end

SlateportCity_SternsShipyard_2F_EventScript_Scientist2::
	msgbox SlateportCity_SternsShipyard_2F_Text_FloatsBecauseBuoyancy, MSGBOX_NPC
	end

SlateportCity_SternsShipyard_2F_Text_ShipDesignMoreLikeBuilding:
	.string "Concevoir un grand navire, c'est en\n"
	.string "fait plus comme construire un immeuble\l"
	.string "que d'assembler un véhicule.$"

SlateportCity_SternsShipyard_2F_Text_FloatsBecauseBuoyancy:
	.string "Tu ne trouves pas ça étrange qu'un\n"
	.string "navire en fer lourd flotte ?\p"
	.string "Il flotte grâce à un principe\n"
	.string "appelé la poussée d'Archimède.$"
