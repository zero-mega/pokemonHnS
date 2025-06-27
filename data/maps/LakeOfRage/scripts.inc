LakeOfRage_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LakeOfRage_OnTransition
	.byte 0

LakeOfRage_OnTransition:
	goto_if_set FLAG_HIDE_LAKE_OF_RAGE_LANCE, LakeOfRage_EventScript_SetLowTide
	goto LakeOfRage_EventScript_SetHighTide

LakeOfRage_EventScript_SetLowTide::
	setweather WEATHER_NONE
	setmaplayoutindex LAYOUT_LAKE_OF_RAGE_LOW_TIDE
	end

LakeOfRage_EventScript_SetHighTide::
	setweather WEATHER_RAIN_THUNDERSTORM
	setmaplayoutindex LAYOUT_LAKE_OF_RAGE
	end

LakeOfRage_EventScript_Lance::
	setflag FLAG_HIDE_LAKE_OF_RAGE_LANCE
	end

LakeOfRage_EventScript_Lass::
	clearflag FLAG_HIDE_LAKE_OF_RAGE_LANCE
	end