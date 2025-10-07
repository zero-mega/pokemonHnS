Route10_PowerPlantBackRoom_MapScripts::
	.byte 0


Route10_PowerPlantBackRoom_EventScript_Manager::
	lock
	faceplayer
	goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 0, Route10_PowerPlantBackRoom_EventScript_ManagerInitial
	goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 1, Route10_PowerPlantBackRoom_EventScript_ManagerDuringRocket
	goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 2, Route10_PowerPlantBackRoom_EventScript_ManagerDuringRocket
	goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 3, Route10_PowerPlantBackRoom_EventScript_ManagerDuringRocket
	goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 4, Route10_PowerPlantBackRoom_EventScript_ManagerDuringRocket
	goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 5, Route10_PowerPlantBackRoom_EventScript_ManagerDuringRocket
	goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 6, Route10_PowerPlantBackRoom_EventScript_ManagerCheckPart
	goto_if_ge VAR_KANTO_ROCKET_STORY_STATE, 7, Route10_PowerPlantBackRoom_EventScript_ManagerDone
	msgbox Route10_PowerPlantBackRoom_Text_ManagerMyBelovedGenerator, MSGBOX_DEFAULT
	closemessage
	release
	end

Route10_PowerPlantBackRoom_EventScript_ManagerInitial::
	msgbox Route10_PowerPlantBackRoom_Text_ManagerWhoWouldRuinMyGenerator, MSGBOX_DEFAULT
	closemessage
	setvar VAR_KANTO_ROCKET_STORY_STATE, 1
	release
	end

Route10_PowerPlantBackRoom_EventScript_ManagerDuringRocket::
	msgbox Route10_PowerPlantBackRoom_Text_ManagerIWontForgiveCulprit, MSGBOX_DEFAULT
	closemessage
	release
	end

Route10_PowerPlantBackRoom_EventScript_ManagerCheckPart::
	checkitem ITEM_MACHINE_PART
	goto_if_eq VAR_RESULT, FALSE, Route10_PowerPlantBackRoom_EventScript_ManagerDuringRocket
	removeitem ITEM_MACHINE_PART
	msgbox Route10_PowerPlantBackRoom_Text_ManagerThatsThePart, MSGBOX_DEFAULT
	msgbox Route10_PowerPlantBackRoom_Text_ManagerTakeThisTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_THUNDER
	msgbox Route10_PowerPlantBackRoom_Text_ManagerTM07IsZapCannon, MSGBOX_DEFAULT
	closemessage
	setvar VAR_KANTO_ROCKET_STORY_STATE, 7
	clearflag FLAG_HIDE_ROUTE25_MISTY
	setvar VAR_CERULEAN_CITY_STATE, 2
	setflag FLAG_HIDE_POWER_PLANT_ENGINEER
	setflag FLAG_RETURNED_MACHINE_PART
	release
	end

Route10_PowerPlantBackRoom_EventScript_ManagerDone::
	msgbox Route10_PowerPlantBackRoom_Text_ManagerMyBelovedGenerator, MSGBOX_DEFAULT
	closemessage
	release
	end

Route10_PowerPlantBackRoom_EventScript_Engineer::
	msgbox Route10_PowerPlantBackRoom_Text_Engineer, MSGBOX_NPC
	end

Route10_PowerPlantBackRoom_Text_ManagerWhoWouldRuinMyGenerator:
	.string "DIRECTEUR : J-je suis prêt à exploser\n"
	.string "quelqu'un !\p"
	.string "Qui oserait abîmer mon\n"
	.string "générateur ?\p"
	.string "J'ai passé tellement de temps dessus !\p"
	.string "Si je l'attrape, il va goûter à mon\n"
	.string "ZAP CANON !$"

Route10_PowerPlantBackRoom_Text_ManagerIWontForgiveCulprit:
	.string "DIRECTEUR : Je ne lui pardonnerai pas !\p"
	.string "Le coupable peut pleurer et\n"
	.string "s'excuser,\p"
	.string "mais je vais quand même le punir !\p"
	.string "Gahahahah !$"

Route10_PowerPlantBackRoom_Text_ManagerThatsThePart:
	.string "DIRECTEUR : Ah ! Oui !\p"
	.string "C'est la PIÈCE manquante de mon\n"
	.string "précieux générateur ! Tu l'as trouvée ?$"

Route10_PowerPlantBackRoom_Text_ManagerTakeThisTM:
	.string "Wahah ! Merci !\p"
	.string "Tiens ! Prends cette CT en récompense !$"

Route10_PowerPlantBackRoom_Text_ManagerTM07IsZapCannon:
	.string "DIRECTEUR : Cette CT, c'est TONNERRE.\p"
	.string "C'est une technique puissante !\p"
	.string "Ce n'est pas ce qu'on appellerait\n"
	.string "précis, mais ça fait très mal !$"

Route10_PowerPlantBackRoom_Text_ManagerMyBelovedGenerator:
	.string "DIRECTEUR : Mon précieux générateur !\p"
	.string "Continue à produire de l'électricité !$"

Route10_PowerPlantBackRoom_Text_Engineer:
	.string "Cette porte est dangereuse sans courant.$"
