PewterCity_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PewterCity_OnFrame
	.byte 0

PewterCity_OnFrame::
	map_script_2 VAR_PEWTER_CITY_STATE, 0,  PewterCity_EventScript_CityEnter
	.2byte 0

PewterCity_EventScript_CityEnter::
	setflag FLAG_VISITED_PEWTER_CITY
	setvar VAR_PEWTER_CITY_STATE, 1
	end
