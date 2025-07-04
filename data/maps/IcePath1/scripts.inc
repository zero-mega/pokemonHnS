IcePath1_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, IcePath1_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

IcePath1_OnTransition: 
	callnative SetTimeBasedEncounters
	end

