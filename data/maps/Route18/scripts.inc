Route18_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route18_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route18_OnTransition:
	callnative SetTimeBasedEncounters
	end

Route18_EventScript_Boris::
	trainerbattle_single TRAINER_BORIS Route18_Text_BirdKeeperBorisSeen, Route18_Text_BirdKeeperBorisBeaten
	msgbox Route18_Text_BirdKeeperBorisAfterBattle, MSGBOX_AUTOCLOSE
	end

Route18_EventScript_Bob::
	trainerbattle_single TRAINER_BOB Route18_Text_BirdKeeperBobSeen, Route18_Text_BirdKeeperBobBeaten
	msgbox Route18_Text_BirdKeeperBobAfterBattle, MSGBOX_AUTOCLOSE
	end

Route18_EventScript_Sign::
	msgbox Route18_Text_Sign, MSGBOX_SIGN
	end

Route18_Text_BirdKeeperBorisSeen:
	.string "Si tu cherches des POKéMON,\n"
	.string "il faut regarder dans les hautes herbes.$"

Route18_Text_BirdKeeperBorisBeaten:
	.string "Aïe !$"

Route18_Text_BirdKeeperBorisAfterBattle:
	.string "Puisque tu es si fort, ça doit être\n"
	.string "amusant de combattre.$"

Route18_Text_BirdKeeperBobSeen:
	.string "La ROUTE CYCLABLE est un raccourci\n"
	.string "rapide vers CELADOPOLIS.$"

Route18_Text_BirdKeeperBobBeaten:
	.string "…Ouf !$"

Route18_Text_BirdKeeperBobAfterBattle:
	.string "Si tu n'as pas de BICYCLETTE,\n"
	.string "tu ne peux pas utiliser le\n"
	.string "raccourci.$"

Route18_Text_Sign:
	.string "ROUTE 18\p"
	.string "CELADOPOLE - PARMANIE$"
