MtSilver_SnowUnused_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtSilver_SnowUnused_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

MtSilver_SnowUnused_OnTransition: 
	callnative SetTimeBasedEncounters
	end
