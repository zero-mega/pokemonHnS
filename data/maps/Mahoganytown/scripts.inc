Mahoganytown_MapScripts::
	.byte 0

MahoganyTown_EventScript_TownTrigger::

	setvar VAR_MAHOGANY_TOWN_STATE, 1
	end

Mahoganytown_EventScript_RocketTrigger::
	lock
	setvar VAR_GOLDENROD_CITY_STATE, 6
	clearflag FLAG_HIDE_GOLDENROD_ROCKETS
	setflag FLAG_HIDE_GOLDENROD_ROCKET_SCOUT
	setflag FLAG_HIDE_GOLDENROD_NPCS
	clearflag FLAG_HIDE_ROCKET_GOLDENROD_RADIOTOWER_1
	setvar VAR_TEMP_0, 1
	release
	end