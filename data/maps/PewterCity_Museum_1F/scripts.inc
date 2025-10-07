.set LOCALID_MUSEUM_ROOTFOSSIL, 5
.set LOCALID_MUSEUM_CLAWFOSSIL, 6

PewterCity_Museum_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RuinsOfAlph_Lab_OnTransition
	.byte 0

PewterCity_Museum_1F_EventScript_RootFossil::
	finditem ITEM_ROOT_FOSSIL
	setflag FLAG_HIDE_PEWTER_ROOT_FOSSIL
	removeobject LOCALID_MUSEUM_ROOTFOSSIL
	end

PewterCity_Museum_1F_EventScript_ClawFossil::
	finditem ITEM_CLAW_FOSSIL
	setflag FLAG_HIDE_PEWTER_CLAW_FOSSIL
	removeobject LOCALID_MUSEUM_CLAWFOSSIL
	end

PewterCity_Museum_1F_EventScript_Receptionist::
	msgbox PewterCity_Museum_1F_Text_Recptionist, MSGBOX_NPC
	end

PewterCity_Museum_1F_EventScript_FossilWoman::
	goto_if_set FLAG_HIDE_PEWTER_CLAW_FOSSIL, PewterCity_Museum_1F_EventScript_FossilWoman2
	goto_if_set FLAG_HIDE_PEWTER_ROOT_FOSSIL, PewterCity_Museum_1F_EventScript_FossilWoman2
	goto_if_ge VAR_TEMP_2, 1, PewterCity_Museum_1F_EventScript_FossilWoman2
	msgbox PewterCity_Museum_1F_Text_FossilWoman, MSGBOX_NPC
	setvar VAR_TEMP_2, 1
	end

PewterCity_Museum_1F_EventScript_FossilWoman2::
	msgbox PewterCity_Museum_1F_Text_FossilWomanAfter, MSGBOX_NPC
	end

PewterCity_Museum_1F_EventScript_Oldman::
	msgbox PewterCity_Museum_1F_Text_Oldman, MSGBOX_NPC
	end

PewterCity_Museum_1F_EventScript_Bones::
	msgbox PewterCity_Museum_1F_Text_Bones, MSGBOX_SIGN
	end

PewterCity_Museum_1F_Text_Recptionist:
	.string "Bienvenue !\p"
	.string "Juste pour vous prévenir, tous les\n"
	.string "grands spécimens ont été envoyés\l"
	.string "dans d'autres musées pour exposition.\p"
	.string "Donc, pour l'instant, l'entrée est\n"
	.string "gratuite !\p"
	.string "Veuillez entrer, je vous en prie.$"

PewterCity_Museum_1F_Text_FossilWoman:
	.string "Tu dois être un dresseur fort.\p"
	.string "Nous n'avons plus vraiment besoin\n"
	.string "des fossiles sur le comptoir là-bas.\p"
	.string "Un homme étrange aux cheveux\n"
	.string "argentés en a déposé plein ici.\p"
	.string "Vas-y, prends-les si tu veux.$"

PewterCity_Museum_1F_Text_FossilWomanAfter:
	.string "Nous partageons souvent nos recherches\n"
	.string "avec les chercheurs des RUINES D'ALPH.\p"
	.string "Nous partageons même des fossiles\n"
	.string "avec eux via le PC !$"

PewterCity_Museum_1F_Text_Oldman:
	.string "Je devrais être reconnaissant pour ma\n"
	.string "longue vie.\p"
	.string "Je n'aurais jamais cru voir un jour\n"
	.string "les os d'un dragon !$"

PewterCity_Museum_1F_Text_Bones:
	.string "Os d'un ancien POKéMON\n"
	.string "dragon.$"
