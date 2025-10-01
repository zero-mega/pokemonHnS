AbandonedShip_Rooms2_B1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SetTimeEncounters
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

AbandonedShip_Rooms2_B1F_EventScript_Camper::
	msgbox AbandonedShip_Rooms2_B1F_Text_PerfectPlaceToGoExploring, MSGBOX_NPC
	end

AbandonedShip_Rooms2_B1F_Text_PerfectPlaceToGoExploring:
	.string "C'est l'endroit parfait pour explorer !\n"
	.string "C'est tellement excitant ici !\p"
	.string "Je parie qu'il y a des trésors incroyables\n"
	.string "à bord.$"

