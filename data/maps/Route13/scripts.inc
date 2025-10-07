Route13_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route13_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route13_OnTransition:
	callnative SetTimeBasedEncounters
	end

Route13_EventScript_Alex::
	trainerbattle_single TRAINER_ALEX Route13_Text_PokefanmAlexSeen, Route13_Text_PokefanmAlexBeaten
	msgbox Route13_Text_PokefanmAlexAfterBattle, MSGBOX_AUTOCLOSE
	end

Route13_EventScript_Joshua::
	trainerbattle_single TRAINER_JOSHUA Route13_Text_PokefanmJoshuaSeen, Route13_Text_PokefanmJoshuaBeaten
	msgbox Route13_Text_PokefanmJoshuaAfterBattle, MSGBOX_AUTOCLOSE
	end

Route13_EventScript_Perry::
	trainerbattle_single TRAINER_PERRY Route13_Text_BirdKeeperPerrySeen, Route13_Text_BirdKeeperPerryBeaten
	msgbox Route13_Text_BirdKeeperPerryAfterBattle, MSGBOX_AUTOCLOSE
	end

Route13_EventScript_Bret::
	trainerbattle_single TRAINER_BRET Route13_Text_BirdKeeperBretSeen, Route13_Text_BirdKeeperBretBeaten
	msgbox Route13_Text_BirdKeeperBretAfterBattle, MSGBOX_AUTOCLOSE
	end

Route13_EventScript_Kenny::
	trainerbattle_single TRAINER_KENNY Route13_Text_HikerKennySeen, Route13_Text_HikerKennyBeaten
	msgbox Route13_Text_HikerKennyAfterBattle, MSGBOX_AUTOCLOSE
	end

Route13_EventScript_TrainerTips::
	msgbox Route13_Text_TrainerTips, MSGBOX_SIGN
	end

Route13_EventScript_RouteSign::
	msgbox Route13_Text_Sign, MSGBOX_SIGN
	end

Route13_EventScript_DirectionsSign::
	msgbox Route13_Text_DirectionsSign, MSGBOX_SIGN
	end

Route13_Text_PokefanmAlexSeen:
	.string "Inclinez-vous devant mes POKéMON royaux !$"

Route13_Text_PokefanmAlexBeaten:
	.string "Comment... Comment osez-vous vous moquer de la royauté !$"

Route13_Text_PokefanmAlexAfterBattle:
	.string "Tout le monde ne rêve-t-il pas de devenir\n"
	.string "roi un jour ?$"

Route13_Text_PokefanmJoshuaSeen:
	.string "Nihihi ! Veux-tu affronter\n"
	.string "ma bande de PIKACHU ?$"

Route13_Text_PokefanmJoshuaBeaten:
	.string "PI-PIKACHU !$"

Route13_Text_PokefanmJoshuaAfterBattle:
	.string "On dirait que tu as beaucoup de\n"
	.string "POKéMON,\p"
	.string "mais PIKACHU reste le meilleur.$"

Route13_Text_BirdKeeperPerrySeen:
	.string "L'agilité est la qualité principale\n"
	.string "des POKéMON oiseaux.$"

Route13_Text_BirdKeeperPerryBeaten:
	.string "Tu m'as battu grâce à ta vitesse…$"

Route13_Text_BirdKeeperPerryAfterBattle:
	.string "Tes POKéMON sont remarquablement\n"
	.string "bien entraînés.$"

Route13_Text_BirdKeeperBretSeen:
	.string "Regarde mes POKéMON. Observe\n"
	.string "leurs couleurs et leur plumage.$"

Route13_Text_BirdKeeperBretBeaten:
	.string "Zut ! Pas assez bon !$"

Route13_Text_BirdKeeperBretAfterBattle:
	.string "Si tu les soignes, les POKéMON\n"
	.string "deviennent heureux.$"

Route13_Text_HikerKennySeen:
	.string "Je devrais aller à la GROTTE pour\n"
	.string "attraper un ONIX.$"

Route13_Text_HikerKennyBeaten:
	.string "J'ai perdu…$"

Route13_Text_HikerKennyAfterBattle:
	.string "Les formations géologiques semblent\n"
	.string "ne pas changer.\p"
	.string "Mais en fait, elles changent petit\n"
	.string "à petit.$"

Route13_Text_TrainerTips:
	.string "ASTUCES D'ENTRAÎNEUR\p"
	.string "Regarde ! Juste là, à gauche\n"
	.string "du panneau.$"

Route13_Text_Sign:
	.string "ROUTE 13\p"
	.string "NORD VERS LE PONT SILENCE$"

Route13_Text_DirectionsSign:
	.string "NORD VERS LAVANVILLE\p"
	.string "OUEST VERS PARMANIE$"
