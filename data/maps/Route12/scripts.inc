Route12_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route12_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route12_OnTransition:
	callnative SetTimeBasedEncounters
	end

Route12_EventScript_Martin::
	trainerbattle_single TRAINER_MARTIN Route12_Text_FisherMartinSeen, Route12_Text_FisherMartinBeaten
	msgbox Route12_Text_FisherMartinAfterBattle, MSGBOX_AUTOCLOSE
	end

Route12_EventScript_Stephen::
	trainerbattle_single TRAINER_STEPHEN Route12_Text_FisherStephenSeen, Route12_Text_FisherStephenBeaten
	msgbox Route12_Text_FisherStephenAfterBattle, MSGBOX_AUTOCLOSE
	end

Route12_EventScript_Barney::
	trainerbattle_single TRAINER_BARNEY Route12_Text_FisherBarneySeen, Route12_Text_FisherBarneyBeaten
	msgbox Route12_Text_FisherBarneyAfterBattle, MSGBOX_AUTOCLOSE
	end

Route12_EventScript_Kyle::
	trainerbattle_single TRAINER_KYLE Route12_Text_FisherKyleSeen, Route12_Text_FisherKyleBeaten
	msgbox Route12_Text_FisherKyleAfterBattle, MSGBOX_AUTOCLOSE
	end

Route12_EventScript_NewFisher::
	msgbox Route12_Text_NewFisher, MSGBOX_NPC
	end

Route12_EventScript_Elixir::
	finditem ITEM_ELIXIR
	end

Route12_EventScript_Calcium::
	finditem ITEM_CALCIUM
	end

Route12_EventScript_Tentacruel::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_TENTACRUEL, CRY_MODE_NORMAL
	msgbox Route41_Text_Tentacruel, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route12_Text_NewFisher:
	.string "Attention, quelque chose de dangereux vit\n"
	.string "dans ces eaux.$"

Route12_Text_FisherMartinSeen:
	.string "La patience est la clé pour la pêche\n"
	.string "et les POKéMON.$"

Route12_Text_FisherMartinBeaten:
	.string "Gwaaah !$"

Route12_Text_FisherMartinAfterBattle:
	.string "Je suis trop impatient pour pêcher…$"

Route12_Text_FisherStephenSeen:
	.string "Je me sens tellement bien, à pêcher tout en\n"
	.string "écoutant de la musique sur ma\l"
	.string "radio.$"

Route12_Text_FisherStephenBeaten:
	.string "Ma stupide radio m'a distrait !$"

Route12_Text_FisherStephenAfterBattle:
	.string "As-tu écouté les programmes radio de KANTO ?\n"
	.string "On a beaucoup de choix\l"
	.string "ici.$"

Route12_Text_FisherBarneySeen:
	.string "Qu'est-ce qui est le plus important dans\n"
	.string "notre vie quotidienne ?$"

Route12_Text_FisherBarneyBeaten:
	.string "La réponse arrive tout de suite !$"

Route12_Text_FisherBarneyAfterBattle:
	.string "Je pense que l'électricité est la chose la plus\n"
	.string "importante dans notre vie\l"
	.string "quotidienne.\p"
	.string "Sinon, les gens n'auraient pas fait\n"
	.string "autant d'histoires quand la\l"
	.string "CENTRALE ÉLECTRIQUE est tombée\l"
	.string "en panne.$"

Route12_Text_FisherKyleSeen:
	.string "Tu t'en souviens ?$"

Route12_Text_FisherKyleBeaten:
	.string "Tu t'en souviens vraiment ?$"

Route12_Text_FisherKyleAfterBattle:
	.string "La secousse que tu ressens sur la CANNE quand\n"
	.string "un POKéMON mord à l'hameçon…\p"
	.string "C'est la meilleure sensation pour\n"
	.string "un pêcheur comme moi.$"

Route12_EventScript_Sign::
	msgbox Route12_Text_Sign, MSGBOX_SIGN
	end

Route12_EventScript_FishingSign::
	msgbox Route12_Text_FishingSpotSign, MSGBOX_SIGN
	end

Route12_Text_Sign:
	.string "ROUTE 12\p"
	.string "NORD VERS LAVANVILLE$"

Route12_Text_FishingSpotSign:
	.string "COIN DE PÊCHE$"
