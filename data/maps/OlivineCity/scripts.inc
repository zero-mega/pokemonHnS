.set LOCALID_OLIVINE_SILVER, 4

OlivineCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OlivineCity_MapScript_OnTransition
	.byte 0

OlivineCity_MapScript_OnTransition::
	goto_if_ge VAR_OLIVINE_CITY_STATE, 5, OlivineCity_MapScript_ClearWeather @CHANGELATER
	end

OlivineCity_MapScript_ClearWeather::
	setweather WEATHER_NONE
	end

OlivineCity_EventScript_CityTrigger:: @FLAGHEAP
	setflag FLAG_HIDE_OLIVINE_GYM_JASMINE
	setflag FLAG_HIDE_OLIVINE_SILVER


	clearflag FLAG_HIDE_LIGHTHOUSE_JASMINE


	setvar VAR_OLIVINE_CITY_STATE, 1
	end

OlivineCity_EventScript_SilverTrigger::
	lock
	clearflag FLAG_HIDE_OLIVINE_SILVER
	opendoor 11, 27
	addobject LOCALID_OLIVINE_SILVER
	playbgm MUS_HG_ENCOUNTER_RIVAL, TRUE
	delay 20 
	closedoor 11, 27
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	call_if_eq VAR_TEMP_1, 28, OlivineCity_EventScript_SilverWalkToPlayer1
	call_if_eq VAR_TEMP_1, 29, OlivineCity_EventScript_SilverWalkToPlayer2
	call_if_eq VAR_TEMP_1, 30, OlivineCity_EventScript_SilverWalkToPlayer3
	msgbox OlivineCity_Text_SilverEncounter, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_TEMP_1, 28, OlivineCity_EventScript_SilverLeaveAdjust1
	call_if_eq VAR_TEMP_1, 29, OlivineCity_EventScript_SilverLeaveAdjust2
	call_if_eq VAR_TEMP_1, 30, OlivineCity_EventScript_SilverLeaveAdjust2
	applymovement LOCALID_OLIVINE_SILVER, OlivineCity_Movement_SilverLeave
	waitmovement 0
	setvar VAR_OLIVINE_CITY_STATE, 2
	setflag FLAG_HIDE_OLIVINE_SILVER
	fadedefaultbgm
	release
	end

OlivineCity_EventScript_SilverWalkToPlayer1::
	applymovement LOCALID_OLIVINE_SILVER OlivineCity_Movement_SilverWalkToPlayer1
	waitmovement 0
	return

OlivineCity_EventScript_SilverWalkToPlayer2::
	applymovement LOCALID_OLIVINE_SILVER OlivineCity_Movement_SilverWalkToPlayer2
	waitmovement 0
	return

OlivineCity_EventScript_SilverWalkToPlayer3::
	applymovement LOCALID_OLIVINE_SILVER OlivineCity_Movement_SilverWalkToPlayer3
	waitmovement 0
	return

OlivineCity_EventScript_SilverLeaveAdjust1::
	applymovement LOCALID_OLIVINE_SILVER Common_Movement_WalkDown1
	waitmovement 0
	return

OlivineCity_EventScript_SilverLeaveAdjust2::
	applymovement LOCALID_OLIVINE_SILVER Common_Movement_WalkUp1
	waitmovement 0
	return

OlivineCity_Movement_SilverWalkToPlayer1:
	walk_down
	walk_right
	walk_right
	walk_right
	step_end
OlivineCity_Movement_SilverWalkToPlayer2:
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	step_end
OlivineCity_Movement_SilverWalkToPlayer3:
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	step_end


OlivineCity_Movement_SilverLeave:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

OlivineCity_Text_SilverEncounter:
	.string "You again?\n"
	.string "There's no need to be alert.\p"
	.string "I don't bother with wimps\n"
	.string "like you.\p"
	.string "Speaking of weaklings, the\n"
	.string "city's Gym Leader isn't here,\l"
	.string "and is supposedly taking care\l"
	.string "of a sick POKéMON at the\l"
	.string "Lighthouse.\p"
	.string "Humph! Boo-hoo!\n"
	.string "Just let sick POKéMON go!\p"
	.string "A POKéMON that can't battle\n"
	.string "is worthless!\p"
	.string "Why don't you go train at the\n"
	.string "Lighthouse?\p"
	.string "Who knows? It may make you a\n"
	.string "bit of a better Trainer!$"

OlivineCity_EventScript_Sailor1::
	lock
	faceplayer
	msgbox OlivineCity_Text_Sailor1, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_EventScript_Sailor2::
	lock
	faceplayer
	msgbox OlivineCity_Text_Sailor2, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_EventScript_Youngster::
	lock
	faceplayer
	msgbox OlivineCity_Text_YoungsterPokegear, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_EventScript_Machoke::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MACHOKE, CRY_MODE_NORMAL
	msgbox OlivineCity_Text_Machoke, MSGBOX_DEFAULT
	waitmoncry
	release
	end

OlivineCity_EventScript_Sign::
	lock
	msgbox OlivineCity_Text_Sign, MSGBOX_SIGN
	end

OlivineCity_EventScript_PortSign::
	lock
	msgbox OlivineCity_Text_PortSign, MSGBOX_SIGN
	end

OlivineCity_EventScript_GymSign::
	lock
	msgbox OlivineCity_Text_GymSign, MSGBOX_SIGN
	end

OlivineCity_EventScript_LighthouseSign::
	lock
	msgbox OlivineCity_Text_LighthouseSign, MSGBOX_SIGN
	end

OlivineCity_Text_Sailor1:
	.string "Dark roads are dangerous\n"
	.string "at night.\p"
	.string "But in the pitch-black of\n"
	.string "night, the sea is even more\l"
	.string "treacherous!\p"
	.string "Without the beacon of the\n"
	.string "LIGHTHOUSE to guide it, no\l"
	.string "ship can sail.$"

OlivineCity_Text_YoungsterPokegear:
	.string "That thing you have--\n"
	.string "it's a POKéGEAR, right?\l"
	.string "Wow, that's cool.$"

OlivineCity_Text_YoungsterPokedex:
	.string "Wow, you have a POKéDEX!\p"
	.string "That is just so awesome.$"

OlivineCity_Text_Sailor2:
	.string "The league has JASMINE\n"
	.string "pegged as the sixth\l"
	.string "strongest GYM LEADER!\p"
	.string "Hah! That's a load of crud.\p"
	.string "There's no way PRYCE could\n"
	.string "hurt JASMINE's Steel-type\l"
	.string "POKéMON!\p"
	.string "Bureaucracy if you ask me.\p"
	.string "She's something to be feared,\n"
	.string "that's for sure!$"

OlivineCity_Text_Sign:
	.string "OLIVINE CITY\p"
	.string "The Port Closest to Foreign Lands$"

OlivineCity_Text_PortSign:
	.string "OLIVINE PORT\n"
	.string "FAST SHIP PIER$"

OlivineCity_Text_GymSign:
	.string "OLIVINE CITY POKéMON GYM\n"
	.string "LEADER: JASMINE\p"
	.string "The Steel-Clad Defense Girl$"

OlivineCity_Text_LighthouseSign:
	.string "OLIVINE LIGHTHOUSE\n"
	.string "Also known as the GLITTER\l"
	.string "LIGHTHOUSE$"

OlivineCity_Text_BattleTowerSign:
	.string "BATTLE TOWER AHEAD\n"
	.string "Opening Now!$"

OlivineCity_Text_Machoke:
	.string "MACHOKE: CHO!$"
