Route19_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route19_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route19_OnTransition:
	callnative SetTimeBasedEncounters
	end

Route19_EventScript_Harold::
	trainerbattle_single TRAINER_HAROLD Route19_Text_SwimmermHaroldSeen, Route19_Text_SwimmermHaroldBeaten
	msgbox Route19_Text_SwimmermHaroldAfterBattle, MSGBOX_AUTOCLOSE
	end

Route19_EventScript_Tucker::
	trainerbattle_single TRAINER_TUCKER Route19_Text_SwimmermTuckerSeen, Route19_Text_SwimmermTuckerBeaten
	msgbox Route19_Text_SwimmermTuckerAfterBattle, MSGBOX_AUTOCLOSE
	end

Route19_EventScript_Dawn::
	trainerbattle_single TRAINER_DAWN Route19_Text_SwimmerfDawnSeen, Route19_Text_SwimmerfDawnBeaten
	msgbox Route19_Text_SwimmerfDawnAfterBattle, MSGBOX_AUTOCLOSE
	end

Route19_EventScript_Jerome::
	trainerbattle_single TRAINER_JEROME Route19_Text_SwimmermJeromeSeen, Route19_Text_SwimmermJeromeBeaten
	msgbox Route19_Text_SwimmermJeromeAfterBattle, MSGBOX_AUTOCLOSE
	end

Route19_EventScript_Fatman::
	goto_if_unset FLAG_DEFEATED_CINNABAR_ISLAND_GYM, Route19_EventScript_FatmanBefore
	msgbox Route19_Text_Fisher1_RocksCleared, MSGBOX_NPC
	end

Route19_EventScript_FatmanBefore::
	msgbox Route19_Text_Fisher2, MSGBOX_NPC
	end

Route19_EventScript_Sign::
	msgbox Route19_Text_Sign, MSGBOX_SIGN
	end

Route19_EventScript_SwimSign::
	msgbox Route19_Text_CarefulSwimmingSign, MSGBOX_SIGN
	end

CherryGroveCity_EventScript_Kingler::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_KINGLER, CRY_MODE_NORMAL
	msgbox Route19_Text_Kingler, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route19_EventScript_Fisher::
	goto_if_unset FLAG_DEFEATED_CINNABAR_ISLAND_GYM, Route19_EventScript_FisherBefore
	msgbox Route19_Text_Fisher2_RocksCleared, MSGBOX_NPC
	end

Route19_EventScript_FisherBefore::
	msgbox Route19_Text_FisherBefore, MSGBOX_NPC
	end

Route19_Text_SwimmermHaroldSeen:
	.string "As-tu déjà nagé dans la mer\n"
	.string "la nuit ?$"

Route19_Text_SwimmermHaroldBeaten:
	.string "Glou…$"

Route19_Text_SwimmermHaroldAfterBattle:
	.string "La nuit, la mer devient noire. On\n"
	.string "dirait qu'elle va t'engloutir.$"

Route19_Text_SwimmermTuckerSeen:
	.string "Huff, huff… Encore… un peu…\p"
	.string "plus loin… jusqu'à… PARMANIE…$"

Route19_Text_SwimmermTuckerBeaten:
	.string "Je me noie !$"

Route19_Text_SwimmermTuckerAfterBattle:
	.string "J'ai… demandé à ma copine de nager\n"
	.string "jusqu'à PARMANIE… Ouf…$"

Route19_Text_SwimmerfDawnSeen:
	.string "Les gens faibles me dégoûtent !$"

Route19_Text_SwimmerfDawnBeaten:
	.string "Je pourrais te battre à la nage…$"

Route19_Text_SwimmerfDawnAfterBattle:
	.string "C'est une courte nage entre\n"
	.string "PARMANIE et les ÎLES ÉCUME…\p"
	.string "Pff, quel homme mon copain !\n"
	.string "Quel froussard !$"

Route19_Text_SwimmermJeromeSeen:
	.string "Nager ? Je suis nul à ça.\p"
	.string "Je fais juste des éclaboussures\n"
	.string "dans ces eaux peu profondes.$"

Route19_Text_SwimmermJeromeBeaten:
	.string "Je croyais pouvoir gagner.$"

Route19_Text_SwimmermJeromeAfterBattle:
	.string "Je ne suis peut-être pas bon nageur,\n"
	.string "mais j'adore la mer.$"

Route19_Text_Fisher1:
	.string "Désolé. Cette route est fermée\n"
	.string "pour travaux.\p"
	.string "Si tu veux aller à CRAMOIS'ÎLE,\n"
	.string "mieux vaut passer par le sud depuis\n"
	.string "BOURG PALETTE.$"

Route19_Text_Kingler:
	.string "KRABBOSS : KÉÉÉÉÉÉÉÉÉÉ$"

Route19_Text_Fisher1_RocksCleared:
	.string "Je suis en sueur. Il est temps de nager !$"

Route19_Text_Fisher2:
	.string "Oh non, KRABBOSS bloque la\n"
	.string "plage.$"

Route19_Text_FisherBefore:
	.string "Pas de pêche tant que ces KRABBOSS\n"
	.string "ne sont pas partis.$"

Route19_Text_Fisher2_RocksCleared:
	.string "Ces KRABBOSS sont enfin partis !\p"
	.string "Je peux enfin pêcher à nouveau.$"

Route19_Text_Sign:
	.string "ROUTE 19\p"
	.string "PARMANIE - ÎLES ÉCUME$"

Route19_Text_CarefulSwimmingSign:
	.string "Veuillez faire attention si vous\n"
	.string "nagez vers les ÎLES ÉCUME.\p"
	.string "POLICE DE PARMANIE$"
