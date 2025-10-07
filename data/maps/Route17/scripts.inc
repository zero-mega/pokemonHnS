Route17_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route17_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route17_OnTransition:
	callnative SetTimeBasedEncounters
	end

Route17_EventScript_Riley::
	trainerbattle_single TRAINER_RILEY Route17_Text_BikerRileySeen, Route17_Text_BikerRileyBeaten
	msgbox Route17_Text_BikerRileyAfterBattle, MSGBOX_AUTOCLOSE
	end

Route17_EventScript_Joel::
	trainerbattle_single TRAINER_JOEL Route17_Text_BikerJoelSeen, Route17_Text_BikerJoelBeaten
	msgbox Route17_Text_BikerJoelAfterBattle, MSGBOX_AUTOCLOSE
	end

Route17_EventScript_Glenn::
	trainerbattle_single TRAINER_GLENN Route17_Text_BikerGlennSeen, Route17_Text_BikerGlennBeaten
	msgbox Route17_Text_BikerGlennAfterBattle, MSGBOX_AUTOCLOSE
	end

Route17_EventScript_Charles::
	trainerbattle_single TRAINER_CHARLES Route17_Text_BikerCharlesSeen, Route17_Text_BikerCharlesBeaten
	msgbox Route17_Text_BikerCharlesAfterBattle, MSGBOX_AUTOCLOSE
	end

Route17_Text_BikerRileySeen:
	.string "Hé, toi ! Tu viens de JOHTO, hein ?$"

Route17_Text_BikerRileyBeaten:
	.string "Ouah, tu assures !$"

Route17_Text_BikerRileyAfterBattle:
	.string "Ne prends pas la grosse tête, sale gosse de JOHTO !$"

Route17_Text_BikerJoelSeen:
	.string "Waouh. C'est un super VÉLO !$"

Route17_Text_BikerJoelBeaten:
	.string "Mais tu n'as pas juste l'air cool…$"

Route17_Text_BikerJoelAfterBattle:
	.string "J'ai l'air cool, mais je suis faible, donc\n"
	.string "je ne suis pas vraiment cool.\p"
	.string "Je dois m'entraîner plus dur…$"

Route17_Text_BikerGlennSeen:
	.string "Hé ! Tu veux faire une course de vitesse ?$"

Route17_Text_BikerGlennBeaten:
	.string "Aïe ! Tu as un couple incroyable !$"

Route17_Text_BikerGlennAfterBattle:
	.string "Rouler sans les mains, c'est considéré\n"
	.string "comme cool sur la ROUTE CYCLABLE.$"

Route17_Text_BikerCharlesSeen:
	.string "Nous sommes des stars intrépides de la route !$"

Route17_Text_BikerCharlesBeaten:
	.string "Arrrgh ! Je me suis écrasé !$"

Route17_Text_BikerCharlesAfterBattle:
	.string "La conduite imprudente cause des accidents !\n"
	.string "Vas-y doucement !$"
