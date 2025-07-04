IcePath5_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, IcePath5_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

IcePath5_OnTransition: 
	callnative SetTimeBasedEncounters
	end
