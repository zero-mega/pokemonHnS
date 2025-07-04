IcePath4_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, IcePath4_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

IcePath4_OnTransition: 
	callnative SetTimeBasedEncounters
	end
