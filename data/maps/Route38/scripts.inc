Route38_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route38_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route38_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route38_EventScript_Toby::
	trainerbattle_single TRAINER_TOBY, Route38_Text_BirdKeeperTobySeen, Route38_Text_BirdKeeperTobyBeaten
	msgbox Route38_Text_BirdKeeperTobyAfter, MSGBOX_AUTOCLOSE
	end

Route38_EventScript_Chad::
	trainerbattle_single TRAINER_CHAD, Route38_Text_SchoolboyChad1Seen, Route38_Text_SchoolboyChad1Beaten
	msgbox Route38_Text_SchoolboyChadAfter, MSGBOX_AUTOCLOSE
	end

Route38_EventScript_Dana::
	trainerbattle_single TRAINER_DANA, Route38_Text_LassDana1Seen, Route38_Text_LassDana1Beaten
	msgbox Route38_Text_LassDanaAfter, MSGBOX_AUTOCLOSE
	end

Route38_EventScript_Valerie::
	trainerbattle_single TRAINER_VALERIE, Route38_Text_BeautyValerieSeen, Route38_Text_BeautyValerieBeaten
	msgbox Route38_Text_BeautyValerieAfter, MSGBOX_AUTOCLOSE
	end

Route38_EventScript_Harry::
	trainerbattle_single TRAINER_HARRY, Route38_Text_SailorHarrySeen, Route38_Text_SailorHarryBeaten
	msgbox Route38_Text_SailorHarryAfter, MSGBOX_AUTOCLOSE
	end

Route38_EventScript_Olivia::
	trainerbattle_single TRAINER_OLIVIA, Route38_Text_BeautyOliviaSeen, Route38_Text_BeautyOliviaBeaten
	msgbox Route38_Text_BeautyOliviaAfter, MSGBOX_AUTOCLOSE
	end

Route38_EventScript_Sign1::
	lock
	msgbox Route38_Text_Sign, MSGBOX_SIGN
	closemessage
	release
	end

Route38_EventScript_Sign2::
	lock
	msgbox Route38_Text_WaterSign, MSGBOX_SIGN
	closemessage
	release
	end

Route38_EventScript_Item_LaxIncense::
	finditem ITEM_LAX_INCENSE
	end

Route38_Text_BirdKeeperTobySeen:
	.string "Envole-toi haut dans le ciel,\n"
	.string "mes chers POKéMON oiseaux !$"

Route38_Text_BirdKeeperTobyBeaten:
	.string "J'ai envie de m'envoler\n"
	.string "loin maintenant.$"

Route38_Text_BirdKeeperTobyAfter:
	.string "Je compte m'entraîner à IRISIA\n"
	.string "pour apprendre VOL à mes POKéMON.$"

Route38_Text_SchoolboyChad1Seen:
	.string "Laisse-moi essayer quelque chose\n"
	.string "que j'ai appris aujourd'hui.$"

Route38_Text_SchoolboyChad1Beaten:
	.string "Je n'ai pas assez étudié,\n"
	.string "on dirait.$"

Route38_Text_SchoolboyChadAfter:
	.string "J'ai tellement de contrôles à passer\n"
	.string "que je n'ai pas beaucoup\l"
	.string "de temps pour les POKéMON.\p"
	.string "Alors quand je peux jouer,\n"
	.string "je me concentre vraiment.$"

Route38_Text_LassDana1Seen:
	.string "Tu sembles être doué(e) en\n"
	.string "POKéMON.\p"
	.string "Si c'est le cas, tu pourrais\n"
	.string "me donner des conseils ?$"

Route38_Text_LassDana1Beaten:
	.string "Je vois. Donc on peut se battre\n"
	.string "de cette façon.$"

Route38_Text_LassDanaAfter:
	.string "Je connais un bon truc !\p"
	.string "Le lait de la FERME MEUMEUMEU\n"
	.string "est célèbre pour sa saveur.$"

Route38_Text_BeautyValerieSeen:
	.string "Salut ! Tu n'es pas un(e) dresseur(se)\n"
	.string "mignon(ne) ?\p"
	.string "Je peux voir tes POKéMON ?$"

Route38_Text_BeautyValerieBeaten:
	.string "Je suis contente d'avoir vu\n"
	.string "tes POKéMON !$"

Route38_Text_BeautyValerieAfter:
	.string "Quand je vois des POKéMON, ça\n"
	.string "apaise mes nerfs.$"

Route38_Text_SailorHarrySeen:
	.string "J'ai voyagé à l'étranger, alors je\n"
	.string "connais toutes sortes de\l"
	.string "POKéMON !$"

Route38_Text_SailorHarryBeaten:
	.string "Ton talent est de classe mondiale !$"

Route38_Text_SailorHarryAfter:
	.string "Toutes sortes de gens dans le monde\n"
	.string "vivent heureux avec\l"
	.string "des POKéMON.$"

Route38_Text_BeautyOliviaSeen:
	.string "Tu ne trouves pas que mes POKéMON\n"
	.string "et moi sommes magnifiques ?$"

Route38_Text_BeautyOliviaBeaten:
	.string "On boit du LAIT MEUMEUMEU\n"
	.string "tous les jours.$"

Route38_Text_BeautyOliviaAfter:
	.string "Le LAIT MEUMEUMEU est bon pour\n"
	.string "la beauté et la santé,\p"
	.string "mais malheureusement, ils\n"
	.string "ne vendent qu'une bouteille à la fois.$"

Route38_Text_Sign:
	.string "ROUTE 38\p"
	.string "OLIVILLE - ROSALIA$"

Route38_Text_TrainerTips:
	.string "ASTUCES DRESSEUR\p"
	.string "Si un POKéMON essaie d'évoluer,\n"
	.string "tu peux l'en empêcher.\p"
	.string "Appuie sur le bouton B pendant\n"
	.string "l'évolution pour l'annuler.\p"
	.string "Cela surprend le POKéMON\n"
	.string "et arrête son évolution.$"

Route38_Text_WaterSign:
	.string "BAIGNADE ET PÊCHE INTERDITES.\n"
	.string "EAU RÉSERVÉE À L'AGRICULTURE.\p"
	.string "-CONSEIL DE ROSALIA$"
