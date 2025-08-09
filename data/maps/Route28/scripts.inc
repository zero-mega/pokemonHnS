Route28_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route28_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route28_OnTransition: 
	callnative SetTimeBasedEncounters
	end
