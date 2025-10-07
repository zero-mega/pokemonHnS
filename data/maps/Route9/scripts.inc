Route9_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route9_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route9_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route9_EventScript_Dean::
	trainerbattle_single TRAINER_DEAN Route9_Text_CamperDeanSeen, Route9_Text_CamperDeanBeaten
	msgbox Route9_Text_CamperDeanAfter, MSGBOX_AUTOCLOSE
	end

Route9_EventScript_Heidi::
	trainerbattle_single TRAINER_HEIDI Route9_Text_PicnickerHeidiSeen, Route9_Text_PicnickerHeidiBeaten
	msgbox Route9_Text_PicnickerHeidiAfter, MSGBOX_AUTOCLOSE
	end

Route9_EventScript_Edna::
	trainerbattle_single TRAINER_EDNA Route9_Text_PicnickerEdnaSeen, Route9_Text_PicnickerEdnaBeaten
	msgbox Route9_Text_PicnickerEdnaAfter, MSGBOX_AUTOCLOSE
	end

Route9_EventScript_Sid::
	trainerbattle_single TRAINER_SID Route9_Text_CamperSidSeen, Route9_Text_CamperSidBeaten
	msgbox Route9_Text_CamperSidAfter, MSGBOX_AUTOCLOSE
	end

Route9_EventScript_Tim::
	trainerbattle_single TRAINER_TIM Route9_Text_HikerTimSeen, Route9_Text_HikerTimBeaten
	msgbox Route9_Text_HikerTimAfter, MSGBOX_AUTOCLOSE
	end

Route9_EventScript_Sidney::
	trainerbattle_single TRAINER_SIDNEY Route9_Text_HikerSidneySeen, Route9_Text_HikerSidneyBeaten
	msgbox Route9_Text_HikerSidneyAfter, MSGBOX_AUTOCLOSE
	end

Route9_EventScript_Sign::
	msgbox Route9_Text_Sign, MSGBOX_SIGN
	end

Route9_Text_CamperDeanSeen:
	.string "Je suis venu explorer la GROTTE.$"

Route9_Text_CamperDeanBeaten:
	.string "Ouh là ! Danger, mec.$"

Route9_Text_CamperDeanAfter:
	.string "Mes POKéMON étaient blessés avant même\n"
	.string "d'entrer dans la GROTTE.\p"
	.string "Je ferais mieux de les emmener au\n"
	.string "CENTRE POKéMON tout de suite.$"

Route9_Text_PicnickerHeidiSeen:
	.string "As-tu déjà fait un pique-nique ?\p"
	.string "C'est tellement amusant !$"

Route9_Text_PicnickerHeidiBeaten:
	.string "Ohhhh !$"

Route9_Text_PicnickerHeidiAfter:
	.string "On prépare plein de gourmandises et on\n"
	.string "les partage avec tout le monde.\p"
	.string "C'est délicieux !$"

Route9_Text_CamperSidSeen:
	.string "Hé, toi ! Ne jette rien par terre !$"

Route9_Text_CamperSidBeaten:
	.string "Je voulais juste prévenir…$"

Route9_Text_CamperSidAfter:
	.string "Désolé. Tu ne jetais rien. C'était\n"
	.string "mon erreur.$"

Route9_Text_PicnickerEdnaSeen:
	.string "Les gens ne devraient rien laisser\n"
	.string "derrière eux.$"

Route9_Text_PicnickerEdnaBeaten:
	.string "Ohh… J'ai perdu…$"

Route9_Text_PicnickerEdnaAfter:
	.string "Économiser l'énergie est important,\n"
	.string "mais l'environnement l'est encore plus\l"
	.string "vital.$"

Route9_Text_HikerTimSeen:
	.string "Elle descendra le MONT ARGENTÉ\n"
	.string "quand elle viendra…\p"
	.string "Le MONT ARGENTÉ est à JOHTO, non ?$"

Route9_Text_HikerTimBeaten:
	.string "J'étais trop occupé à chanter…$"

Route9_Text_HikerTimAfter:
	.string "Les combats demandent de la concentration.$"

Route9_Text_HikerSidneySeen:
	.string "Je vais te révéler un secret.\p"
	.string "Mais d'abord, combattons !$"

Route9_Text_HikerSidneyBeaten:
	.string "Oh, mince ! J'ai perdu ça…$"

Route9_Text_HikerSidneyAfter:
	.string "La CENTRALE est de l'autre côté d'une\n"
	.string "petite rivière.$"

Route9_Text_Sign:
	.string "ROUTE 9\p"
	.string "AZURIA - GROTTE$"
