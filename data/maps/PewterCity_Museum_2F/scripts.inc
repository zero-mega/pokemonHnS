PewterCity_Museum_2F_MapScripts::
	.byte 0


PewterCity_Museum_2F_EventScript_Nerd::
	msgbox PewterCity_Museum_2F_Text_Nerd, MSGBOX_NPC
	end

PewterCity_Museum_2F_EventScript_Daughter::
	lock
	msgbox PewterCity_Museum_2F_Text_AskedDaddyToCatchPikachu, MSGBOX_DEFAULT
	release
	end

PewterCity_Museum_2F_EventScript_Dad::
	lock
	msgbox PewterCity_Museum_2F_Text_PikachuSoonIPromise, MSGBOX_DEFAULT
	release
	end

PewterCity_Museum_2F_EventScript_Meteor::
	msgbox PewterCity_Museum_2F_Text_MeteoriteThatFellOnMtMoon, MSGBOX_SIGN
	end

PewterCity_Museum_2F_Text_Nerd:
	.string "On dit que des météorites sont tombées\n"
	.string "sur l'ÎLE AUBE.\p"
	.string "Nous aimerions les exposer ici\n"
	.string "dans notre musée, mais...\p"
	.string "On dit que ces météorites émettent\n"
	.string "une énergie étrange et ne peuvent pas\l"
	.string "être emportées...$"

PewterCity_Museum_2F_Text_AskedDaddyToCatchPikachu::
    .string "Je veux un PIKACHU !\n"
    .string "Il est trop mignon !\p"
    .string "J'ai demandé à mon papa de m'en attraper un !$"

PewterCity_Museum_2F_Text_PikachuSoonIPromise::
    .string "Oui, un PIKACHU bientôt, je te le promets !$"

PewterCity_Museum_2F_Text_SpaceShuttle::
    .string "Navette spatiale$"

PewterCity_Museum_2F_Text_MeteoriteThatFellOnMtMoon::
    .string "Une météorite tombée sur le MT. SÉLÉNITE.\n"
    .string "On pense que c'est une PIERRE LUNE.$"
