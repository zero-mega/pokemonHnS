SproutTower_2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SproutTower_2F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

SproutTower_2F_OnTransition: 
	callnative SetTimeBasedEncounters
	end

SproutTower_2F_EventScript_SageNico::
	trainerbattle_single TRAINER_NICO SproutTower_Text_SageNico_Seen, SproutTower_Text_SageNico_Beaten
	msgbox SproutTower_Text_SageNico_AfterBattle, MSGBOX_AUTOCLOSE
	end

SproutTower_2F_EventScript_SageEdmond::
	trainerbattle_single TRAINER_EDMOND SproutTower_Text_SageEdmond_Seen, SproutTower_Text_SageEdmond_Beaten
	msgbox SproutTower_Text_SageEdmond_AfterBattle, MSGBOX_AUTOCLOSE
	end

SproutTower_2F_EventScript_Statue::
	lock
	msgbox SproutTower_Text_2F_Statue, MSGBOX_AUTOCLOSE
	release
	end

SproutTower_2F_EventScript_Xdefend::
	finditem ITEM_X_DEFEND
	end

SproutTower_Text_SageNico_Seen:
	.string "Peu importe l'intensité du combat,\n"
	.string "la TOUR restera solide.$"

SproutTower_Text_SageNico_Beaten:
	.string "Je me suis battu fort, mais je suis trop faible.$"

SproutTower_Text_SageNico_AfterBattle:
	.string "Le pilier flexible protège la\n"
	.string "TOUR, même des tremblements de terre.$"

SproutTower_Text_SageEdmond_Seen:
	.string "…Balance-toi comme des feuilles au vent…$"

SproutTower_Text_SageEdmond_Beaten:
	.string "Oh, je suis faible !$"

SproutTower_Text_SageEdmond_AfterBattle:
	.string "J'ai essayé d'imiter les mouvements\n"
	.string "doux de CHETIFLOR pour combattre…\p"
	.string "Mais je ne me suis pas assez entraîné.$"

SproutTower_Text_2F_Statue:
	.string "Une statue de POKéMON…\p"
	.string "Elle a l'air très distinguée.$"
