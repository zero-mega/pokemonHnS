.set LOCALID_ROUTE36_SUDOWOODO, 6
.set LOCALID_ROUTE36_ROCKSMASHGUY, 3

Route36_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route36_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route36_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route36_EventScript_RockSmashGuy::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_SUDOWOODO, Route36_EventScript_RockSmashGuy2
	msgbox Route36_Text_RockSmashGuy1, MSGBOX_DEFAULT
	closemessage
	release
	end
Route36_EventScript_RockSmashGuy2::
	goto_if_set FLAG_RECEIVED_HM_ROCK_SMASH, Route36_EventScript_RockSmashGuy3
	msgbox Route36_Text_RockSmashGuy2, MSGBOX_DEFAULT
	giveitem ITEM_HM_ROCK_SMASH
	setflag FLAG_RECEIVED_HM_ROCK_SMASH
Route36_EventScript_RockSmashGuy3::
	msgbox Route36_Text_RockSmashGuy3
	closemessage
	release
	end

Route36_EventScript_Lass::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_SUDOWOODO, Route36_EventScript_Lass2
	msgbox Route36_Text_Lass1, MSGBOX_DEFAULT
	closemessage
	release
	end
Route36_EventScript_Lass2::
	msgbox Route36_Text_Lass2_ClearedSudowoodo, MSGBOX_DEFAULT
	closemessage
	release
	end

Route36_EventScript_Arthur::
	lock
	faceplayer
	goto_if_set FLAG_GOT_HARD_STONE, Route36_EventScript_ArthurCompleted
	msgbox Route36_Text_MeetArthur, MSGBOX_DEFAULT
	closemessage
	multichoice 20, 0, MULTI_DAYS_OF_WEEK, FALSE
	switch VAR_RESULT
	case 0, Route36_EventScript_ArthurNope
	case 1, Route36_EventScript_ArthurNope
	case 2, Route36_EventScript_ArthurNope
	case 3, Route36_EventScript_ArthurNope
	case 4, Route36_EventScript_ArthurYes
	case 5, Route36_EventScript_ArthurNope
	case 6, Route36_EventScript_ArthurNope
	case 7, Route36_EventScript_ArthurCancel
	case MULTI_B_PRESSED, Route36_EventScript_ArthurCancel
	closemessage
	release
	end
Route36_EventScript_ArthurYes::
	msgbox Route36_Text_ArthurGivesGift, MSGBOX_DEFAULT
	giveitem ITEM_HARD_STONE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_HARD_STONE
	msgbox Route36_Text_ArthurGaveGift, MSGBOX_DEFAULT
	closemessage
	release
	end
Route36_EventScript_ArthurNope::
	msgbox Route36_Text_ArthurNope, MSGBOX_DEFAULT
	closemessage
	release
	end
Route36_EventScript_ArthurCancel::
	closemessage
	release
	end
Route36_EventScript_ArthurCompleted::
	msgbox Route36_Text_ArthurThursday, MSGBOX_DEFAULT
	closemessage
	release
	end


Route36_EventScript_SudoWoodo::
	lock
	msgbox Route36_Text_OddTree, MSGBOX_DEFAULT
	checkitem ITEM_SQUIRT_BOTTLE
	goto_if_eq VAR_RESULT, TRUE, Route36_EventScript_SudoWoodoChoice
	closemessage
	release
	end
Route36_EventScript_SudoWoodoChoice::
	msgbox Route36_Text_UseSquirtbottle, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, Route36_EventScript_SudoWoodoWater
	closemessage
	release
	end
Route36_EventScript_SudoWoodoWater::
	msgbox Route36_Text_UsedSquirtbottle, MSGBOX_DEFAULT
	playse SE_DOWNPOUR
	waitse
	closemessage
	playse SE_SUDOWOODO_SHAKE	
	applymovement LOCALID_ROUTE36_SUDOWOODO, Route36_Movement_SudoWoodo
	waitmovement 0
	faceplayer
	msgbox Route36_Text_SudowoodoAttacked	
	closemessage
	waitse
	playmoncry SPECIES_SUDOWOODO, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setvar VAR_LAST_TALKED, LOCALID_ROUTE36_SUDOWOODO
	setwildbattle SPECIES_SUDOWOODO, 20
	@setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	@clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Route36_EventScript_Defeated_Sudowoodo
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, Route36_EventScript_RanSudowoodo
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, Route36_EventScript_RanSudowoodo
Route36_EventScript_Defeated_Sudowoodo::
	setflag FLAG_HIDE_SUDOWOODO
	removeobject LOCALID_ROUTE36_SUDOWOODO
	checkitem ITEM_HM_ROCK_SMASH
	call_if_eq VAR_RESULT, FALSE, Route36_EventScript_RockSmashGuySudoWoodo
	release
	end

Route36_EventScript_RanSudowoodo::
	turnobject LOCALID_ROUTE36_SUDOWOODO, DIR_NORTH
	release
	end

Route36_EventScript_RockSmashGuySudoWoodo:
	playse SE_PIN
	applymovement LOCALID_ROUTE36_ROCKSMASHGUY, Common_Movement_ExclamationMark
	turnobject LOCALID_ROUTE36_ROCKSMASHGUY, DIR_WEST
	waitmovement 0
	applymovement LOCALID_ROUTE36_ROCKSMASHGUY, Route36_Movement_RockSmashGuy
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitmovement 0
	return

Route36_Movement_RockSmashGuy:
	jump_in_place_left
	delay_2
	jump_in_place_left
	delay_2
	jump_in_place_left
	delay_2
	jump_in_place_left
	step_end

Route36_EventScript_Mark::
	trainerbattle_single TRAINER_MARK Route36_Text_PsychicMarkSeen, Route36_Text_PsychicMarkBeaten
	msgbox Route36_Text_PsychicMarkAfter, MSGBOX_AUTOCLOSE
	end

Route36_EventScript_Schoolboy::
	trainerbattle_single TRAINER_ALAN Route36_Text_SchoolboyAlan1Seen, Route36_Text_SchoolboyAlan1Beaten
	msgbox Route36_Text_SchoolboyAlanAfter, MSGBOX_AUTOCLOSE
	end

Route36_EventScript_Sign::
	lock
	msgbox Route36_Text_Sign_RuinsNorth, MSGBOX_SIGN
	closemessage
	release
	end

Route36_EventScript_Sign2::
	lock
	msgbox Route36_Text_Tips1, MSGBOX_SIGN
	closemessage
	release
	end

Route36_Movement_SudoWoodo:
	face_right
	delay_8
	face_down
	delay_8
	face_left
	delay_8
	face_down
	delay_8
	face_right
	delay_8
	face_down
	delay_8
	face_left
	delay_8
	face_down
	step_end

Route36_Text_UseSquirtbottle:
	.string "Utiliser la CARAPUCE?$"

Route36_Text_UsedSquirtbottle:
	.string "{PLAYER} utilise la CARAPUCE.$"

Route36_Text_SudowoodoAttacked:
	.string "L'arbre étrange n'aime pas la\n"
	.string "CARAPUCE !\p"
	.string "L'arbre étrange attaque !$"

Route36_Text_RockSmashGuy1:
	.string "Wa-hé !\p"
	.string "J'allais casser cet arbre\n"
	.string "avec mon coup de poing direct.\p"
	.string "Mais je n'ai pas pu ! Je suis nul !$"

Route36_Text_RockSmashGuy2:
	.string "Tu as dégagé ce fichu arbre ?\p"
	.string "Je suis impressionné !\n"
	.string "Je veux que tu prennes ça.$"

Route36_Text_RockSmashGuy3:
	.string "C'est ÉCLAT'ROC.\p"
	.string "Tu peux briser des rochers avec un\n"
	.string "seul coup bien placé.\p"
	.string "Si des rochers bloquent ton chemin,\n"
	.string "casse-les !$"

Route36_Text_OddTree:
	.string "Un arbre étrange bloque le passage.$"

Route36_Text_Lass1:
	.string "Fais attention la nuit sur cette route !\p"
	.string "J'ai vu un POKéMON qui ressemblait à\n"
	.string "CANINOS, mais il avait une aura effrayante\l"
	.string "autour de lui.$"

Route36_Text_Lass2_ClearedSudowoodo:
	.string "Cet arbre bizarre a disparu sans\n"
	.string "laisser de trace.\p"
	.string "Oh ! Cet arbre était en fait un\n"
	.string "POKéMON ?$"

Route36_Text_PsychicMarkSeen:
	.string "Je vais lire dans tes pensées !$"

Route36_Text_PsychicMarkBeaten:
	.string "Je t'ai mal compris !$"

Route36_Text_PsychicMarkAfter:
	.string "Je serais fort si seulement je pouvais\n"
	.string "savoir ce que pense mon adversaire.$"

Route36_Text_SchoolboyAlan1Seen:
	.string "Grâce à mes études, je suis prêt\n"
	.string "pour n'importe quel POKéMON !$"

Route36_Text_SchoolboyAlan1Beaten:
	.string "Oups ! Erreur de calcul !$"

Route36_Text_SchoolboyAlanAfter:
	.string "Zut. J'étudie aussi cinq heures par jour.\p"
	.string "Il y a plus à apprendre que de lire\n"
	.string "des livres.$"

Route36_Text_MeetArthur:
	.string "ARTHUR : Qui es-tu ?\n"
	.string "Je suis ARTHUR de la FAMILLE DES JOURS.\p"
	.string "Si tu devines mon jour préféré,\n"
	.string "je te donnerai une récompense.$"

Route36_Text_ArthurNope:
	.string "Pas tout à fait !$"

Route36_Text_ArthurGivesGift:
	.string "Tiens. Prends ceci.$"

Route36_Text_ArthurGaveGift:
	.string "ARTHUR : Un POKéMON qui utilise des\n"
	.string "attaques de type roche devrait garder ça.\p"
	.string "Ça renforce les attaques de type roche.$"

Route36_Text_ArthurThursday:
	.string "ARTHUR : Je suis ARTHUR du jeudi.\n"
	.string "Je suis le cinquième fils sur sept.$"

Route36_Text_Sign:
	.string "ROUTE 36$"

Route36_Text_Sign_RuinsNorth:
	.string "RUINES D'ALPH\n"
	.string "ENTRÉE NORD$"

Route36_Text_Tips1:
	.string "ASTUCES DRESSEUR\n"
	.string "Les stats des POKéMON varient, même\l"
	.string "au sein d'une même espèce.\p"
	.string "Leurs stats peuvent être similaires au début.\p"
	.string "Mais les différences deviendront\n"
	.string "marquées à mesure que les POKéMON grandissent.$"

Route36_Text_Tips2:
	.string "ASTUCES DRESSEUR\n"
	.string "Utilise CAVE pour retourner à l'entrée de\n"
	.string "n'importe quel endroit.\p"
	.string "C'est pratique pour explorer les grottes\n"
	.string "et autres lieux importants.$"
