Route14_MapScripts::
	.byte 0

Route14_Trigger_Suicune::
	call_if_eq VAR_CERULEAN_CITY_STATE, 4, CeruleanCityGym_SetSuicuneScene
	closemessage
	release
	end

