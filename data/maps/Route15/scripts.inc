Route15_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route15_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route15_OnTransition:
	callnative SetTimeBasedEncounters
	end

Route15_EventScript_Colette::
	trainerbattle_single TRAINER_COLETTE Route15_Text_TeacherColetteSeen, Route15_Text_TeacherColetteBeaten
	msgbox Route15_Text_TeacherColetteAfterBattle, MSGBOX_AUTOCLOSE
	end

Route15_EventScript_Hillary::
	trainerbattle_single TRAINER_HILLARY Route15_Text_TeacherHillarySeen, Route15_Text_TeacherHillaryBeaten
	msgbox Route15_Text_TeacherHillaryAfterBattle, MSGBOX_AUTOCLOSE
	end

Route15_EventScript_Kipp::
	trainerbattle_single TRAINER_KIPP Route15_Text_SchoolboyKippSeen, Route15_Text_SchoolboyKippBeaten
	msgbox Route15_Text_SchoolboyKippAfterBattle, MSGBOX_AUTOCLOSE
	end

Route15_EventScript_Tommy::
	trainerbattle_single TRAINER_TOMMY Route15_Text_SchoolboyTommySeen, Route15_Text_SchoolboyTommyBeaten
	msgbox Route15_Text_SchoolboyTommyAfterBattle, MSGBOX_AUTOCLOSE
	end

Route15_EventScript_Johnny::
	trainerbattle_single TRAINER_JOHNNY Route15_Text_SchoolboyJohnnySeen, Route15_Text_SchoolboyJohnnyBeaten
	msgbox Route15_Text_SchoolboyJohnnyAfterBattle, MSGBOX_AUTOCLOSE
	end

Route15_EventScript_Billy::
	trainerbattle_single TRAINER_BILLY Route15_Text_SchoolboyBillySeen, Route15_Text_SchoolboyBillyBeaten
	msgbox Route15_Text_SchoolboyBillyAfterBattle, MSGBOX_AUTOCLOSE
	end

Route15_EventScript_Sign::
	msgbox Route15_Text_Sign, MSGBOX_SIGN
	end

Route15_EventScript_PPup::
	finditem ITEM_PP_UP
	end

Route15_Text_TeacherColetteSeen:
	.string "As-tu oublié quelque chose ?$"

Route15_Text_TeacherColetteBeaten:
	.string "Kyaaah !$"

Route15_Text_TeacherColetteAfterBattle:
	.string "Avant de devenir enseignante, j'oubliais\n"
	.string "beaucoup de choses.$"

Route15_Text_TeacherHillarySeen:
	.string "Les jours ensoleillés, je pense que les\n"
	.string "enfants préfèrent jouer dans la cour\n"
	.string "plutôt qu'étudier en classe.$"

Route15_Text_TeacherHillaryBeaten:
	.string "Je ne voulais pas perdre…$"

Route15_Text_TeacherHillaryAfterBattle:
	.string "Étudier est important, mais\n"
	.string "l'exercice l'est tout autant.$"

Route15_Text_SchoolboyKippSeen:
	.string "Attends. Je dois appeler ma maman.$"

Route15_Text_SchoolboyKippBeaten:
	.string "Désolé, Maman ! J'ai perdu !$"

Route15_Text_SchoolboyKippAfterBattle:
	.string "Ma maman s'inquiète tellement pour moi,\n"
	.string "je dois l'appeler tout le temps.$"

Route15_Text_SchoolboyTommySeen:
	.string "Allons nous battre. Je ne perdrai pas !$"

Route15_Text_SchoolboyTommyBeaten:
	.string "J'ai oublié de faire mes devoirs !$"

Route15_Text_SchoolboyTommyAfterBattle:
	.string "Sayonara ! Je viens d'apprendre ça\n"
	.string "en cours de japonais.$"

Route15_Text_SchoolboyJohnnySeen:
	.string "Nous sommes en sortie scolaire à la\n"
	.string "TOUR RADIO LAVANVILLE pour les sciences sociales.$"

Route15_Text_SchoolboyJohnnyBeaten:
	.string "Tu es vraiment trop fort !$"

Route15_Text_SchoolboyJohnnyAfterBattle:
	.string "Je suis fatigué de marcher. J'ai besoin\n"
	.string "de faire une pause.$"

Route15_Text_SchoolboyBillySeen:
	.string "Ma matière préférée, c'est le sport !$"

Route15_Text_SchoolboyBillyBeaten:
	.string "Oh, non ! Comment ai-je pu perdre ?$"

Route15_Text_SchoolboyBillyAfterBattle:
	.string "Si les POKéMON étaient une matière à\n"
	.string "l'école, je serais le meilleur !$"

Route15_Text_Sign:
	.string "ROUTE 15\p"
	.string "PARMANIE - LAVANVILLE$"

