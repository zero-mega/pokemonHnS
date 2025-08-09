MtSilver2_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtSilver2_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

MtSilver2_OnTransition: 
	callnative SetTimeBasedEncounters
	end