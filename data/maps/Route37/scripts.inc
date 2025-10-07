Route37_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route37_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route37_OnTransition: 
	callnative SetTimeBasedEncounters
	end



Route37_EventScript_TwinAnn::
	trainerbattle_double TRAINER_ANN_AND_ANNE, Route37_Text_TwinsAnnAndAnne1_Seen, Route37_Text_TwinsAnnAndAnne1_Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox Route37_Text_TwinsAnnAndAnne1_After, MSGBOX_DEFAULT
	release
	end
	
Route37_EventScript_TwinAnne::
	trainerbattle_double TRAINER_ANN_AND_ANNE, Route37_Text_TwinsAnnAndAnne2_Seen, Route37_Text_TwinsAnnAndAnne2_Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox Route37_Text_TwinsAnnAndAnne2_After, MSGBOX_DEFAULT
	release
	end

Route37_EventScript_Greg::
	trainerbattle_single TRAINER_GREG Route37_Text_PsychicGreg_Seen, Route37_Text_PsychicGreg_Beaten
	msgbox Route37_Text_PsychicGreg_After, MSGBOX_AUTOCLOSE
	end


Route37_EventScript_Sunny::
	lock
	faceplayer
	goto_if_set FLAG_GOT_MAGNET, Route37_EventScript_SunnyCompleted
	msgbox Route37_Text_Sunny_Meet, MSGBOX_DEFAULT
	closemessage
	multichoice 20, 0, MULTI_DAYS_OF_WEEK, FALSE
	switch VAR_RESULT
	case 0, Route37_EventScript_SunnyYes
	case 1, Route37_EventScript_SunnyNope
	case 2, Route37_EventScript_SunnyNope
	case 3, Route37_EventScript_SunnyNope
	case 4, Route37_EventScript_SunnyNope
	case 5, Route37_EventScript_SunnyNope
	case 6, Route37_EventScript_SunnyNope
	case 7 Route37_EventScript_SunnyCancel
	case MULTI_B_PRESSED, Route37_EventScript_SunnyCancel
	closemessage
	release
	end
Route37_EventScript_SunnyYes::
	msgbox Route37_Text_Sunny_GiveGift2, MSGBOX_DEFAULT
	giveitem ITEM_MAGNET
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_MAGNET
	msgbox Route37_Text_Sunny_GaveGift, MSGBOX_DEFAULT
	closemessage
	release
	end
Route37_EventScript_SunnyNope::
	msgbox Route29_Text_TuscanyNope, MSGBOX_DEFAULT
	closemessage
	release
	end
Route37_EventScript_SunnyCancel::
	closemessage
	release
	end
Route37_EventScript_SunnyCompleted::
	msgbox Route37_Text_Sunny_Sunday, MSGBOX_DEFAULT
	closemessage
	release
	end

Route37_EventScript_Sign::
	lock
	msgbox Route37_Text_Sign, MSGBOX_SIGN
	closemessage
	release
	end

Route37_Text_TwinsAnnAndAnne1_Seen:
	.string "ANN : ANNE et moi, nous sommes\n"
	.string "ensemble dans cette aventure !$"

Route37_Text_TwinsAnnAndAnne1_Beaten:
	.string "ANN & ANNE : Nnn… Un peu trop\n"
	.string "fort.$"

Route37_Text_TwinsAnnAndAnne1_After:
	.string "ANN : Je peux deviner ce que ma sœur\n"
	.string "et mes POKéMON pensent.$"

Route37_Text_TwinsAnnAndAnne2_Seen:
	.string "ANNE : ANN et moi, nous sommes\n"
	.string "ensemble dans cette aventure !$"

Route37_Text_TwinsAnnAndAnne2_Beaten:
	.string "ANN & ANNE : Nnn… Un peu trop\n"
	.string "fort.$"

Route37_Text_TwinsAnnAndAnne2_After:
	.string "ANNE : Nous partageons les mêmes\n"
	.string "sentiments que nos POKéMON.$"

Route37_Text_PsychicGreg_Seen:
	.string "Les POKéMON ne peuvent rien faire\n"
	.string "s'ils dorment.\p"
	.string "Je vais te montrer à quel point c'est effrayant !$"

Route37_Text_PsychicGreg_Beaten:
	.string "J'ai perdu. C'est assez triste…$"

Route37_Text_PsychicGreg_After:
	.string "Endormir ou paralyser les POKéMON\n"
	.string "sont de bonnes techniques de combat.$"

Route37_Text_Sunny_Meet:
	.string "SUNNY : Salut !\p"
	.string "Je suis SUNNY de la famille des JOURS !\p"
	.string "Si tu devines mon jour préféré,\n"
	.string "je te donnerai une récompense.$"

Route37_Text_Sunny_GiveGift1:
	.string "On m'a dit de te donner ceci si je te\n"
	.string "voyais !$"

Route37_Text_Sunny_GiveGift2:
	.string "On m'a dit de te donner ceci si je te\n"
	.string "voyais !$"

Route37_Text_Sunny_GaveGift:
	.string "SUNNY : Cette chose…\p"
	.string "Euh…\p"
	.string "… Qu'est-ce que c'était déjà…\p"
	.string "…\p"
	.string "Oh ! Je m'en souviens !\p"
	.string "Un POKéMON qui connaît des attaques\n"
	.string "électriques devrait la tenir.\p"
	.string "Ma sœur MONICA a dit que ça rend\n"
	.string "les attaques électriques plus puissantes !$"

Route37_Text_Sunny_Sunday:
	.string "SUNNY : Mes sœurs et frères sont\n"
	.string "MONICA, TUSCANY, WESLEY, ARTHUR,\l"
	.string "FRIEDA et SANTOS.\p"
	.string "Ils sont tous plus âgés que moi !$"

Route37_Text_Sunny_NotSunday:
	.string "SUNNY : Ce n'est pas dimanche aujourd'hui ?\n"
	.string "Euh… J'ai oublié !$"

Route37_Text_Sign:
	.string "ROUTE 37\n"
	.string "ROSALIA PAR ICI$"
