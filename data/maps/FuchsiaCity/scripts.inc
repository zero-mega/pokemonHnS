FuchsiaCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FuchsiaCity_EventScript_CityEnter
	.byte 0

FuchsiaCity_OnFrame::
	map_script_2 VAR_FUCHSIA_CITY_STATE, 0,  FuchsiaCity_EventScript_BaobaCall
	.2byte 0

FuchsiaCity_EventScript_CityEnter::
	setflag FLAG_VISITED_FUCHSIA_CITY
	end

FuchsiaCity_EventScript_BaobaCall::
	pokenavcall FuchsiaCity_Text_Baoba
	waitmessage
	delay 30
	setvar VAR_BAOBA_QUEST_STATE, 1
	setvar VAR_FUCHSIA_CITY_STATE, 1
	end

FuchsiaCity_Text_Baoba:
	.string "GARDIEN BAOBA : {PLAYER} !\p"
	.string "C'est le GARDIEN BAOBA.\p"
	.string "Il s'est passé quelque chose de terrible !\n"
	.string "Mon ancien PARC SAFARI à PARMANIE\l"
	.string "a été racheté et a rouvert !\p"
	.string "Et apparemment, il y a de nouveaux\n"
	.string "POKéMON exotiques !\p"
	.string "Ça nuit à mon commerce !\p"
	.string "{PLAYER}, tu dois aller dans le\n"
	.string "nouveau PARC SAFARI et attraper un POKéMON\l"
	.string "pour me le montrer. Je dois en savoir plus\l"
	.string "sur ces POKéMON « exotiques ».\p"
	.string "S'il te plaît {PLAYER}, mon commerce dépend\n"
	.string "de toi !$"

FuchsiaCity_EventScript_Dratini::
	lock
	showmonpic SPECIES_DRATINI, 10, 3
	delay 60
	hidemonpic
	release
	end
FuchsiaCity_EventScript_Kangaskhan::
	lock
	showmonpic SPECIES_KANGASKHAN, 10, 3
	delay 60
	hidemonpic
	release
	end
FuchsiaCity_EventScript_Cubone::
	lock
	showmonpic SPECIES_CUBONE, 10, 3
	delay 60
	hidemonpic
	release
	end
FuchsiaCity_EventScript_Omanyte::
	lock
	showmonpic SPECIES_OMANYTE, 10, 3
	delay 60
	hidemonpic
	release
	end
FuchsiaCity_EventScript_Kabuto::
	lock
	showmonpic SPECIES_KABUTO, 10, 3
	delay 60
	hidemonpic
	release
	end

FuchsiaCity_EventScript_Youngster::
	msgbox FuchsiaCity_Text_Youngster, MSGBOX_NPC
	end

FuchsiaCity_EventScript_PokefanM::
	msgbox FuchsiaCity_Text_PokefanM, MSGBOX_NPC
	end

FuchsiaCity_EventScript_Teacher::
	msgbox FuchsiaCity_Text_Teacher, MSGBOX_NPC
	end

FuchsiaCity_EventScript_CitySign::
	msgbox FuchsiaCity_Text_Sign, MSGBOX_SIGN
	end

FuchsiaCity_EventScript_GymSign::
	msgbox FuchsiaCity_Text_GymSign, MSGBOX_SIGN
	end

FuchsiaCity_EventScript_SafariZone::
	msgbox FuchsiaCity_Text_SafariZone, MSGBOX_NPC
	end

FuchsiaCity_Text_Youngster:
	.string "L'un des QUATRE DRESSEURS D'ELITE était\n"
	.string "autrefois le CHAMPION de l'ARENE de PARMANIE.$"

FuchsiaCity_Text_PokefanM:
	.string "La fille de KOGA lui a succédé comme\n"
	.string "CHAMPIONNE d'ARENE après qu'il ait rejoint\l"
	.string "les QUATRE DRESSEURS D'ELITE.$"

FuchsiaCity_Text_Teacher:
	.string "Le PARC SAFARI est sous une nouvelle\n"
	.string "direction.\p"
	.string "Et il y a plein de nouveaux POKéMON !$"

FuchsiaCity_Text_Sign:
	.string "PARMANIE\p"
	.string "Admirez ! C'est le Rose Passion !$"

FuchsiaCity_Text_GymSign:
	.string "ARENE POKéMON DE PARMANIE\n"
	.string "CHAMPIONNE : JEANNINE\p"
	.string "La Maîtresse Ninja Empoisonnée$"

FuchsiaCity_Text_SafariZoneOfficeSign:
	.string "Il y a un avis ici…\p"
	.string "LE BUREAU DU PARC SAFARI est fermé\n"
	.string "jusqu'à nouvel ordre.$"

FuchsiaCity_Text_SafariZone:
	.string "PARC SAFARI\n"
	.string "MAINTENANT PROPRIÉTÉ DE\l"
	.string "DEVON SARL.$"

FuchsiaCity_Text_SafariZoneClosedSign:
	.string "Le GARDIEN voyage à l'étranger.\p"
	.string "Par conséquent, le PARC SAFARI est\n"
	.string "fermé.$"

FuchsiaCity_Text_NoLitteringSign:
	.string "Défense de jeter des déchets.\p"
	.string "Merci d'emporter vos déchets avec vous.$"
