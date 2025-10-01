AbandonedShip_Rooms2_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SetTimeEncounters
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

AbandonedShip_Rooms2_1F_EventScript_Dan::
	trainerbattle_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_DanIntro, AbandonedShip_Rooms2_1F_Text_DanDefeat, AbandonedShip_Rooms2_1F_Text_DanNotEnoughMons, AbandonedShip_Rooms2_1F_EventScript_RegisterDan
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, AbandonedShip_Rooms2_1F_EventScript_DanRematch
	msgbox AbandonedShip_Rooms2_1F_Text_DanPostBattle, MSGBOX_DEFAULT
	release
	end

AbandonedShip_Rooms2_1F_EventScript_RegisterDan::
	msgbox AbandonedShip_Rooms2_1F_Text_KiraRegister, MSGBOX_DEFAULT  @ Kira speaks for both when registering KiraAndDan
	register_matchcall TRAINER_KIRA_AND_DAN_1
	release
	end

AbandonedShip_Rooms2_1F_EventScript_DanRematch::
	trainerbattle_rematch_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_DanRematchIntro, AbandonedShip_Rooms2_1F_Text_DanRematchDefeat, AbandonedShip_Rooms2_1F_Text_DanRematchNotEnoughMons
	msgbox AbandonedShip_Rooms2_1F_Text_DanPostRematch, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_EventScript_Kira::
	trainerbattle_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_KiraIntro, AbandonedShip_Rooms2_1F_Text_KiraDefeat, AbandonedShip_Rooms2_1F_Text_KiraNotEnoughMons, AbandonedShip_Rooms2_1F_EventScript_RegisterKira
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, AbandonedShip_Rooms2_1F_EventScript_KiraRematch
	msgbox AbandonedShip_Rooms2_1F_Text_KiraPostBattle, MSGBOX_DEFAULT
	release
	end

AbandonedShip_Rooms2_1F_EventScript_RegisterKira::
	msgbox AbandonedShip_Rooms2_1F_Text_KiraRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_KIRA_AND_DAN_1
	release
	end

AbandonedShip_Rooms2_1F_EventScript_KiraRematch::
	trainerbattle_rematch_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_KiraRematchIntro, AbandonedShip_Rooms2_1F_Text_KiraRematchDefeat, AbandonedShip_Rooms2_1F_Text_KiraRematchNotEnoughMons
	msgbox AbandonedShip_Rooms2_1F_Text_KiraPostRematch, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_EventScript_Jani::
	trainerbattle_single TRAINER_JANI, AbandonedShip_Rooms2_1F_Text_JaniIntro, AbandonedShip_Rooms2_1F_Text_JaniDefeat
	msgbox AbandonedShip_Rooms2_1F_Text_JaniPostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_EventScript_Garrison::
	trainerbattle_single TRAINER_RUSS, AbandonedShip_Rooms2_1F_Text_GarrisonIntro, AbandonedShip_Rooms2_1F_Text_GarrisonDefeat
	msgbox AbandonedShip_Rooms2_1F_Text_GarrisonPostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_Text_DanIntro:
	.string "DAN : En cherchant des trésors,\n"
	.string "on a trouvé un DRESSEUR !$"

AbandonedShip_Rooms2_1F_Text_DanDefeat:
	.string "DAN : On n’a pas pu gagner même\n"
	.string "en s’y mettant à deux…$"

AbandonedShip_Rooms2_1F_Text_DanPostBattle:
	.string "DAN : On ne trouve aucun trésor…\n"
	.string "Je me demande si quelqu’un les a déjà pris.$"

AbandonedShip_Rooms2_1F_Text_DanNotEnoughMons:
	.string "DAN : Tu n’as même pas deux POKéMON.\n"
	.string "Tu ne peux pas espérer nous battre comme ça.$"

AbandonedShip_Rooms2_1F_Text_KiraIntro:
	.string "KIRA : Oh ?\n"
	.string "On cherchait des trésors.\l"
	.string "Mais on a trouvé un DRESSEUR à la place !$"

AbandonedShip_Rooms2_1F_Text_KiraDefeat:
	.string "KIRA : Ooh, si fort !$"

AbandonedShip_Rooms2_1F_Text_KiraPostBattle:
	.string "KIRA : Où sont passés les trésors ?\p"
	.string "J’ai déjà décidé ce que j’achèterai\n"
	.string "quand on les trouvera !$"

AbandonedShip_Rooms2_1F_Text_KiraNotEnoughMons:
	.string "KIRA : Oh, tu n’as pas deux POKéMON ?\n"
	.string "On devra combattre une autre fois !$"

AbandonedShip_Rooms2_1F_Text_KiraRegister:
	.string "KIRA : Oh, tu m’énerves tellement !\n"
	.string "Je vais t’enregistrer pour ça !$"

AbandonedShip_Rooms2_1F_Text_DanRematchIntro:
	.string "DAN : On cherche des trésors\n"
	.string "depuis tout ce temps.\p"
	.string "Nos POKéMON sont devenus plus forts aussi.\n"
	.string "Laisse-nous te montrer, d’accord ?$"

AbandonedShip_Rooms2_1F_Text_DanRematchDefeat:
	.string "DAN : Tu es fort, comme toujours !$"

AbandonedShip_Rooms2_1F_Text_DanPostRematch:
	.string "DAN : On ne trouve aucun trésor,\n"
	.string "on perd en POKéMON…\p"
	.string "Je veux rentrer chez moi… Mais si je le dis,\n"
	.string "elle se fâche contre moi…$"

AbandonedShip_Rooms2_1F_Text_DanRematchNotEnoughMons:
	.string "DAN : Tu n’as même pas deux POKéMON.\n"
	.string "Tu ne peux pas espérer nous battre comme ça.$"

AbandonedShip_Rooms2_1F_Text_KiraRematchIntro:
	.string "KIRA : Oh ? On se retrouve !\p"
	.string "Comme nous, tu n’as toujours pas abandonné\n"
	.string "la recherche des trésors, hein ?\p"
	.string "On fait que le perdant doive arrêter\n"
	.string "de chercher ?$"

AbandonedShip_Rooms2_1F_Text_KiraRematchDefeat:
	.string "KIRA : Oh, on a encore perdu…$"

AbandonedShip_Rooms2_1F_Text_KiraPostRematch:
	.string "KIRA : On ne partira pas avant d’avoir\n"
	.string "encore entraîné nos POKéMON et trouvé\l"
	.string "les trésors ici !$"

AbandonedShip_Rooms2_1F_Text_KiraRematchNotEnoughMons:
	.string "KIRA : Oh, tu n’as pas deux POKéMON ?\n"
	.string "On devra combattre une autre fois !$"

AbandonedShip_Rooms2_1F_Text_JaniIntro:
	.string "Je ne suis pas douée pour nager,\n"
	.string "mais je suis forte en combat !$"

AbandonedShip_Rooms2_1F_Text_JaniDefeat:
	.string "Oups.\n"
	.string "Ça ne s’est pas très bien passé.$"

AbandonedShip_Rooms2_1F_Text_JaniPostBattle:
	.string "Marcher pieds nus dans ce navire,\n"
	.string "c’est un peu dégoûtant.$"

AbandonedShip_Rooms2_1F_Text_GarrisonIntro:
	.string "La force et la compassion…\n"
	.string "Ce sont les trésors d’un DRESSEUR !$"

AbandonedShip_Rooms2_1F_Text_GarrisonDefeat:
	.string "Ah, il y a quelque chose chez toi\n"
	.string "qui brille.$"

AbandonedShip_Rooms2_1F_Text_GarrisonPostBattle:
	.string "Dans une cabine quelque part à bord,\n"
	.string "j’ai vu quelque chose briller.$"
