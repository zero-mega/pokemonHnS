Route11_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route11_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route11_OnTransition:
	callnative SetTimeBasedEncounters
	end

Route11_EventScript_Owen::
	trainerbattle_single TRAINER_OWEN Route11_Text_YoungsterOwenSeen, Route11_Text_YoungsterOwenBeaten
	msgbox Route11_Text_YoungsterOwenAfterBattle, MSGBOX_AUTOCLOSE
	end

Route11_EventScript_Jason::
	trainerbattle_single TRAINER_JASON Route11_Text_YoungsterJasonSeen, Route11_Text_YoungsterJasonBeaten
	msgbox Route11_Text_YoungsterJasonAfterBattle, MSGBOX_AUTOCLOSE
	end

Route11_EventScript_Herman::
	trainerbattle_single TRAINER_HERMAN Route11_Text_PsychicHermanSeen, Route11_Text_PsychicHermanBeaten
	msgbox Route11_Text_PsychicHermanAfterBattle, MSGBOX_AUTOCLOSE
	end

Route11_EventScript_Fidel::
	trainerbattle_single TRAINER_FIDEL Route11_Text_PsychicFidelSeen, Route11_Text_PsychicFidelBeaten
	msgbox Route11_Text_PsychicFidelAfterBattle, MSGBOX_AUTOCLOSE
	end


Route11_EventScript_Engineer::
	msgbox Route11_Text_Engineer, MSGBOX_NPC
	end

Route11_Text_Engineer:
	.string "J'ai vu un POKéMON étrange grimper\n"
	.string "dans les arbres, mais il ne\l"
	.string "ressemblait pas à un FEROSINGE...$"

Route11_Text_YoungsterOwenSeen:
	.string "Il n'y a pas de triche dans POKéMON.\p"
	.string "Jouons honnêtement, d'accord !$"

Route11_Text_YoungsterOwenBeaten:
	.string "Hein ? Comment c'est arrivé ?$"

Route11_Text_YoungsterOwenAfterBattle:
	.string "J'ai combattu honnêtement avec\n"
	.string "honneur.\p"
	.string "Je ne regrette rien du tout.$"

Route11_Text_YoungsterJasonSeen:
	.string "Ça gratte et chatouille un peu quand\n"
	.string "je porte un short dans l'herbe.$"

Route11_Text_YoungsterJasonBeaten:
	.string "Aïe aïe aïe ! Je me suis fait écraser !$"

Route11_Text_YoungsterJasonAfterBattle:
	.string "Je vais attraper plus de POKéMON\n"
	.string "dans l'herbe.$"

Route11_Text_PsychicHermanSeen:
	.string "…$"

Route11_Text_PsychicHermanBeaten:
	.string "…$"

Route11_Text_PsychicHermanAfterBattle:
	.string "…\p"
	.string "J'ai perdu alors que j'avais les yeux fermés…$"

Route11_Text_PsychicFidelSeen:
	.string "Je peux le voir…\p"
	.string "Tout ce qu'il y a à voir sur toi…$"

Route11_Text_PsychicFidelBeaten:
	.string "Je n'ai pas pu prévoir ta puissance…$"

Route11_Text_PsychicFidelAfterBattle:
	.string "La force de la conviction…\p"
	.string "Tu es fort parce que tu crois\n"
	.string "en tes POKéMON.$"

Route11_Text_Sign:
	.string "ROUTE 11$"
