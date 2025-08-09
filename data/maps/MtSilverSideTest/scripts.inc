MtSilverSideTest_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtSilverSideTest_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

MtSilverSideTest_OnTransition: 
	callnative SetTimeBasedEncounters
	end
