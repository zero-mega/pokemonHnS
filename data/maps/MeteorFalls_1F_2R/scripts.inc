MeteorFalls_1F_2R_MapScripts::
	.byte 0

MeteorFalls_1F_2R_EventScript_Nicolas::
	trainerbattle_single TRAINER_NICOLAS_1, MeteorFalls_1F_2R_Text_NicolasIntro, MeteorFalls_1F_2R_Text_NicolasDefeat, MeteorFalls_1F_2R_EventScript_RegisterNicolas
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MeteorFalls_1F_2R_EventScript_RematchNicolas
	msgbox MeteorFalls_1F_2R_Text_NicolasPostBattle, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_2R_EventScript_RegisterNicolas::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MeteorFalls_1F_2R_Text_NicolasRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_NICOLAS_1
	release
	end

MeteorFalls_1F_2R_EventScript_RematchNicolas::
	trainerbattle_rematch TRAINER_NICOLAS_1, MeteorFalls_1F_2R_Text_NicolasRematchIntro, MeteorFalls_1F_2R_Text_NicolasRematchDefeat
	msgbox MeteorFalls_1F_2R_Text_NicolasPostRematch, MSGBOX_AUTOCLOSE
	end

MeteorFalls_1F_2R_EventScript_John::
	trainerbattle_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_JohnIntro, MeteorFalls_1F_2R_Text_JohnDefeat, MeteorFalls_1F_2R_Text_JohnNotEnoughMons, MeteorFalls_1F_2R_EventScript_RegisterJohn
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MeteorFalls_1F_2R_EventScript_RematchJohn
	msgbox MeteorFalls_1F_2R_Text_JohnPostBattle, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_2R_EventScript_RegisterJohn::
	msgbox MeteorFalls_1F_2R_Text_JohnRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_JOHN_AND_JAY_1
	release
	end

MeteorFalls_1F_2R_EventScript_RematchJohn::
	trainerbattle_rematch_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_JohnRematchIntro, MeteorFalls_1F_2R_Text_JohnRematchDefeat, MeteorFalls_1F_2R_Text_JohnRematchNotEnoughMons
	msgbox MeteorFalls_1F_2R_Text_JohnPostRematch, MSGBOX_AUTOCLOSE
	end

MeteorFalls_1F_2R_EventScript_Jay::
	trainerbattle_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_JayIntro, MeteorFalls_1F_2R_Text_JayDefeat, MeteorFalls_1F_2R_Text_JayNotEnoughMons, MeteorFalls_1F_2R_EventScript_RegisterJay
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MeteorFalls_1F_2R_EventScript_RematchJay
	msgbox MeteorFalls_1F_2R_Text_JayPostBattle, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_2R_EventScript_RegisterJay::
	msgbox MeteorFalls_1F_2R_Text_JohnRegister, MSGBOX_DEFAULT  @ John speaks for both during register
	register_matchcall TRAINER_JOHN_AND_JAY_1
	release
	end

MeteorFalls_1F_2R_EventScript_RematchJay::
	trainerbattle_rematch_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_JayRematchIntro, MeteorFalls_1F_2R_Text_JayRematchDefeat, MeteorFalls_1F_2R_Text_JayRematchNotEnoughMons
	msgbox MeteorFalls_1F_2R_Text_JayPostRematch, MSGBOX_AUTOCLOSE
	end

MeteorFalls_1F_2R_Text_NicolasIntro:
	.string "C'est ici que nous, les dresseurs de\n"
	.string "DRAGON, faisons notre entraînement.\p"
	.string "Même le CHAMPION vient parfois.\n"
	.string "Tu vois maintenant à quel point cet endroit est spécial?$"

MeteorFalls_1F_2R_Text_NicolasDefeat:
	.string "Argh !\n"
	.string "Je ne m'attendais pas à ce que tu sois si fort !$"

MeteorFalls_1F_2R_Text_NicolasPostBattle:
	.string "La route devant nous reste longue et difficile.\p"
	.string "Quand mes POKéMON et moi deviendrons-nous\n"
	.string "les meilleurs ?$"

MeteorFalls_1F_2R_Text_NicolasRegister:
	.string "Je veux en savoir plus sur ta force.\n"
	.string "Laisse-moi t'enregistrer dans mon POKéNAV.$"

MeteorFalls_1F_2R_Text_NicolasRematchIntro:
	.string "Depuis notre rencontre, nous nous sommes\n"
	.string "entraînés dur pour devenir les meilleurs.\p"
	.string "Aide-nous à voir à quel point nous sommes\n"
	.string "devenus plus forts !$"

MeteorFalls_1F_2R_Text_NicolasRematchDefeat:
	.string "Argh !\n"
	.string "Je ne m'attendais pas à ce que tu sois si fort !$"

MeteorFalls_1F_2R_Text_NicolasPostRematch:
	.string "Tu as clairement continué à entraîner tes\n"
	.string "POKéMON.\p"
	.string "Tant que tu restes fort, moi aussi,\n"
	.string "je peux devenir plus fort !$"

MeteorFalls_1F_2R_Text_JohnIntro:
	.string "JOHN : Nous avons toujours combattu les\n"
	.string "POKéMON ensemble, à deux.\l"
	.string "Nous avons confiance en nous.$"

MeteorFalls_1F_2R_Text_JohnDefeat:
	.string "JOHN : Oh là là.\n"
	.string "Nous avons perdu, chère épouse.$"

MeteorFalls_1F_2R_Text_JohnPostBattle:
	.string "JOHN : Nous sommes mariés depuis\n"
	.string "cinquante ans.\p"
	.string "En y repensant, je n'ai jamais battu\n"
	.string "ma chère épouse en combat.$"

MeteorFalls_1F_2R_Text_JohnNotEnoughMons:
	.string "JOHN : Eh bien, quel jeune DRESSEUR !\p"
	.string "Veux-tu combattre avec nous ? Si oui, tu\n"
	.string "devras revenir avec plus de POKéMON.$"

MeteorFalls_1F_2R_Text_JohnRegister:
	.string "JOHN : Jeune DRESSEUR, si l'occasion\n"
	.string "se présente, combattras-tu à nouveau avec nous ?$"

MeteorFalls_1F_2R_Text_JayIntro:
	.string "JAY : Nous sommes mariés depuis\n"
	.string "cinquante ans.\p"
	.string "Le lien que nous partageons en tant que couple\n"
	.string "ne pourra jamais être brisé.$"

MeteorFalls_1F_2R_Text_JayDefeat:
	.string "JAY : Oh, mon cher.\n"
	.string "Nous avons perdu, mon cher mari.$"

MeteorFalls_1F_2R_Text_JayPostBattle:
	.string "JAY : Cinquante ans de mariage…\p"
	.string "Si nous nous disputions, nous réglions\n"
	.string "toujours ça avec un combat POKéMON…$"

MeteorFalls_1F_2R_Text_JayNotEnoughMons:
	.string "JAY : Eh bien, n'es-tu pas un jeune\n"
	.string "DRESSEUR ?\p"
	.string "Si tu veux combattre avec nous, tu devras\n"
	.string "revenir avec plus de POKéMON.$"

MeteorFalls_1F_2R_Text_JohnRematchIntro:
	.string "JOHN : Nous avons toujours combattu les\n"
	.string "POKéMON ensemble, à deux.\l"
	.string "Nous avons confiance en nous.$"

MeteorFalls_1F_2R_Text_JohnRematchDefeat:
	.string "JOHN : Oh là là.\n"
	.string "Nous avons perdu, chère épouse.$"

MeteorFalls_1F_2R_Text_JohnPostRematch:
	.string "JOHN : Mariés depuis cinquante ans…\p"
	.string "En y repensant, la chère épouse et moi,\n"
	.string "nous avons combattu jour après jour…$"

MeteorFalls_1F_2R_Text_JohnRematchNotEnoughMons:
	.string "JOHN : Eh bien, quel jeune DRESSEUR !\p"
	.string "Veux-tu combattre avec nous ? Si oui, tu\n"
	.string "devras revenir avec plus de POKéMON.$"

MeteorFalls_1F_2R_Text_JayRematchIntro:
	.string "JAY : Nous sommes mariés depuis\n"
	.string "cinquante ans.\p"
	.string "Nous nous sommes soutenus tout ce temps.\n"
	.string "Nous sommes devenus forts ensemble.$"

MeteorFalls_1F_2R_Text_JayRematchDefeat:
	.string "JAY : Oh, mon cher.\n"
	.string "Nous avons perdu, mon cher mari.$"

MeteorFalls_1F_2R_Text_JayPostRematch:
	.string "JAY : Cinquante ans de mariage…\n"
	.string "Il s'est passé tant de choses.\p"
	.string "J'espère que nous continuerons à créer\n"
	.string "de beaux souvenirs ensemble.$"

MeteorFalls_1F_2R_Text_JayRematchNotEnoughMons:
	.string "JAY : Eh bien, n'es-tu pas un jeune\n"
	.string "DRESSEUR ?\p"
	.string "Si tu veux combattre avec nous, tu devras\n"
	.string "revenir avec plus de POKéMON.$"
