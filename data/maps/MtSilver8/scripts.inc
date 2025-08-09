MtSilver8_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtSilver8_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

MtSilver8_OnTransition: 
	callnative SetTimeBasedEncounters
	end
