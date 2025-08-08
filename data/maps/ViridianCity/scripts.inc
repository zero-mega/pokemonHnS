ViridianCity_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, ViridianCity_OnFrame
	.byte 0

ViridianCity_OnFrame::
	map_script_2 VAR_VIRIDIAN_CITY_STATE, 0,  ViridianCity_EventScript_CityEnter
	.2byte 0

ViridianCity_EventScript_CityEnter::
	setflag FLAG_VISITED_VIRIDIAN_CITY
	setvar VAR_VIRIDIAN_CITY_STATE, 1
	end

