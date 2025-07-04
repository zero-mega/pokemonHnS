IcePath3_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, IcePath3_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

IcePath3_OnTransition: 
	callnative SetTimeBasedEncounters
	end
