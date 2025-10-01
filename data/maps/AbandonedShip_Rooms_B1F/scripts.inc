AbandonedShip_Rooms_B1F_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, AbandonedShip_Rooms_B1F_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, SetTimeEncounters
	.byte 0

AbandonedShip_Rooms_B1F_OnResume:
	setdivewarp MAP_ABANDONED_SHIP_UNDERWATER2, 17, 4
	callnative SetTimeBasedEncounters
	end

AbandonedShip_Rooms_B1F_EventScript_FatMan::
	msgbox AbandonedShip_Rooms_B1F_Text_GettingQueasy, MSGBOX_NPC
	end

AbandonedShip_Rooms_B1F_Text_GettingQueasy:
	.string "Beuuuurk…\p"
	.string "J’ai la nausée rien qu’à être à bord\n"
	.string "de ce navire…\p"
	.string "Il ne bouge même pas, mais…$"

