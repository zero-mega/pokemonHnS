Route29_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route29_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route29_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route29_Trigger_Monview::
	special SpawnCameraObject
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkUp1 
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkUp1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkUp1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkUp1
	waitmovement 0
	message Route29_Text_PressAorB
	waitbuttonpress
	closemessage
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkDown1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkDown1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkDown1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkDown1
	waitmovement 0
	special RemoveCameraObject
	applymovement2 OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown1
	waitmovement 0
	end

Route29_Text_PressAorB:
	.string "Press A or B to stop viewing.$"

Route29_EventScript_OldMan::
	lock
	faceplayer
	goto_if_set FLAG_ADVENTURE_STARTED, Route29_EventScript_OldMan2
	msgbox Route29_Text_OldMan1, MSGBOX_DEFAULT
	closemessage
	release
	end

Route29_EventScript_OldMan2::
	msgbox Route29_Text_OldMan2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route29_EventScript_OldMan_Tutorial
	waitmessage
	msgbox Route29_Text_OldManDeclined, MSGBOX_DEFAULT
	closemessage
	release
	end

Route29_EventScript_OldMan_Tutorial::
	msgbox Route29_Text_OldManExplanation, MSGBOX_DEFAULT
	closemessage
	release
	end

Route29_EventScript_Lass::
	lock
	faceplayer
	msgbox Route29_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

Route29_EventScript_Youngster::
	lock
	faceplayer
	msgbox Route29_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end


Route29_EventScript_Tuscany::
	lock
	faceplayer
	goto_if_set FLAG_GOT_SILK_SCARF, Route29_EventScript_TuscanyCompleted
	msgbox Route29_Text_MeetTuscany, MSGBOX_DEFAULT
	closemessage
	multichoice 20, 0, MULTI_DAYS_OF_WEEK, FALSE
	switch VAR_RESULT
	case 0, Route29_EventScript_TuscanyNope
	case 1, Route29_EventScript_TuscanyNope
	case 2, Route29_EventScript_TuscanyYes
	case 3, Route29_EventScript_TuscanyNope
	case 4, Route29_EventScript_TuscanyNope
	case 5, Route29_EventScript_TuscanyNope
	case 6, Route29_EventScript_TuscanyNope
	case 7 Route29_EventScript_TuscanyCancel
	case MULTI_B_PRESSED, Route29_EventScript_TuscanyCancel
	closemessage
	release
	end
Route29_EventScript_TuscanyYes::
	msgbox Route29_Text_TuscanyGivesGift, MSGBOX_DEFAULT
	giveitem ITEM_SILK_SCARF
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_SILK_SCARF
	msgbox Route29_Text_TuscanyGaveGift, MSGBOX_DEFAULT
	closemessage
	release
	end
Route29_EventScript_TuscanyNope::
	msgbox Route29_Text_TuscanyNope, MSGBOX_DEFAULT
	closemessage
	release
	end
Route29_EventScript_TuscanyCancel::
	closemessage
	release
	end
Route29_EventScript_TuscanyCompleted::
	msgbox Route29_Text_TuscanyTuesday, MSGBOX_DEFAULT
	closemessage
	release
	end



Route29_EventScript_Girl::
	lock
	faceplayer
	msgbox Route29_Text_Girl, MSGBOX_DEFAULT
	closemessage
	release
	end

Route29_EventScript_Boy::
	lock
	faceplayer
	goto_if_set FLAG_NIGHT_POKEMON, Route29_EventScript_Boy2
	msgbox Route29_Text_Boy_WaitingForDay, MSGBOX_DEFAULT
	closemessage
	release
	end

Route29_EventScript_Boy2::
	msgbox Route29_Text_Boy_WaitingForNight, MSGBOX_DEFAULT
	closemessage
	release
	end

Route29_EventScript_Sign::
	lock
	msgbox Route29_Text_Sign1, MSGBOX_SIGN
	closemessage
	release
	end

Route29_EventScript_ItemPotion::
	finditem ITEM_POTION
	end

Route29_Text_OldMan1:
	.string "Les POKéMON se cachent dans l'herbe.\n"
	.string "Qui sait quand ils vont surgir…$"

Route29_Text_OldMan2:
	.string "Je t'ai vu plusieurs fois.\n"
	.string "Combien de POKéMON as-tu attrapé ?\p"
	.string "Veux-tu que je t'explique\n"
	.string "comment attraper des POKéMON ?$"

Route29_Text_OldManExplanation:
	.string "Si tu les affaiblis d'abord,\n"
	.string "les POKéMON sont plus faciles à attraper.\p"
	.string "Ensuite, lance une Poké Ball depuis\n"
	.string "ton sac ! N'importe laquelle fera l'affaire.\p"
	.string "Si tu veux en savoir plus,\n"
	.string "va à l'ACADÉMIE à MAUVILLE !\p"
	.string "Les élèves là-bas en savent beaucoup\n"
	.string "sur les POKéMON.$"

Route29_Text_OldManDeclined:
	.string "Oh. Très bien, alors.\p"
	.string "Explore chaque route pour trouver\n"
	.string "différents types de POKéMON.\p"
	.string "Ton POKéDEX montre aussi où\n"
	.string "tu peux les trouver !\p"
	.string "Si tu veux en savoir plus,\n"
	.string "va à l'ACADÉMIE à MAUVILLE !\p"
	.string "Les élèves en savent beaucoup\n"
	.string "sur les POKéMON.$"

Route29_Text_Youngster:
	.string "Yo. Comment vont tes POKéMON ?\p"
	.string "S'ils sont faibles et pas prêts\n"
	.string "pour le combat, évite l'herbe.$"

Route29_Text_Lass:
	.string "Tu vois ces rebords ?\n"
	.string "Ça fait peur de sauter de là.\p"
	.string "Mais tu peux aller à BOURG GEON\n"
	.string "sans traverser l'herbe.$"

Route29_Text_Girl:
	.string "Je voulais faire une pause,\n"
	.string "alors j'ai sauvegardé ma progression.$"

Route29_Text_Boy_WaitingForDay:
	.string "J'attends les POKéMON qui\n"
	.string "apparaissent seulement plus tard dans la journée.$"

Route29_Text_Boy_WaitingForNight:
	.string "J'attends les POKéMON qui\n"
	.string "apparaissent seulement la nuit.$"

Route29_Text_MeetTuscany:
	.string "TUSCANY : Je crois bien que c'est\n"
	.string "la première fois que nous nous rencontrons ?\p"
	.string "Je suis TUSCANY de la FAMILLE DES JOURS.\p"
	.string "Si tu devines mon jour préféré,\n"
	.string "je te donnerai une récompense.$"

Route29_Text_TuscanyNope:
	.string "Pas tout à fait !$"

Route29_Text_TuscanyGivesGift:
	.string "Oui ! Pour faire connaissance,\n"
	.string "accepte ce cadeau, une ÉCHARPE\l"
	.string "SOIE.$"

Route29_Text_TuscanyGaveGift:
	.string "TUSCANY : N'est-elle pas\n"
	.string "adorable ?\p"
	.string "Elle renforce les attaques de type\n"
	.string "NORMAL.\p"
	.string "Je suis sûre qu'elle te sera utile.$"

Route29_Text_TuscanyTuesday:
	.string "TUSCANY : As-tu rencontré MONICA,\n"
	.string "ma grande sœur ?\p"
	.string "Ou mon petit frère, WESLEY ?\p"
	.string "Je suis la troisième de sept\n"
	.string "enfants.$"

Route29_Text_Sign1:
	.string "ROUTE 29\p"
	.string "MAUVILLE - BOURG GEON$"
