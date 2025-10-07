.set LOCALID_ROUTE32_BALDINGMAN, 1
.set LOCALID_SLOWPOKETAIL_MAN, 14


Route32_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route32_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route32_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route32_EventScript_FisherJustin::
	trainerbattle_single TRAINER_JUSTIN Route32_Text_FisherJustin_Seen, Route32_Text_FisherJustin_Beaten
	msgbox Route32_Text_FisherJustin_After, MSGBOX_AUTOCLOSE
	end

Route32_EventScript_FisherRalph::
	trainerbattle_single TRAINER_RALPH Route32_Text_FisherRalph1_Seen, Route32_Text_FisherRalph1_Beaten
	msgbox Route32_Text_FisherRalph1_After, MSGBOX_AUTOCLOSE
	end

Route32_EventScript_FisherHenry::
	trainerbattle_single TRAINER_HENRY Route32_Text_FisherHenry_Seen, Route32_Text_FisherHenry_Beaten
	msgbox Route32_Text_FisherHenry_After, MSGBOX_AUTOCLOSE
	end

Route32_EventScript_YoungsterAlbert::
	trainerbattle_single TRAINER_ALBERT Route32_Text_YoungsterAlbert_Seen, Route32_Text_YoungsterAlbert_Beaten
	msgbox Route32_Text_YoungsterAlbert_After, MSGBOX_AUTOCLOSE
	end

Route32_EventScript_YoungsterGordon::
	trainerbattle_single TRAINER_GORDON Route32_Text_YoungsterGordon_Seen, Route32_Text_YoungsterGordon_Beaten
	msgbox Route32_Text_YoungsterGordon_After, MSGBOX_AUTOCLOSE
	end

Route32_EventScript_CamperRoland::
	trainerbattle_single TRAINER_ROLAND Route32_Text_CamperRoland_Seen, Route32_Text_CamperRoland_Beaten
	msgbox Route32_Text_CamperRoland_After, MSGBOX_AUTOCLOSE
	end

Route32_EventScript_PicnickerLiz::
	trainerbattle_single TRAINER_LIZ Route32_Text_PicnickerLiz1_Seen, Route32_Text_PicnickerLiz1_Beaten
	msgbox Route32_Text_PicnickerLiz1_After, MSGBOX_AUTOCLOSE
	end

Route32_EventScript_BirdkeeperPeter::
	trainerbattle_single TRAINER_PETER Route32_Text_BirdKeeperPeter_Seen, Route32_Text_BirdKeeperPeter_Beaten
	msgbox Route32_Text_BirdKeeperPeter_After, MSGBOX_AUTOCLOSE
	end

Route32_EventScript_Roar::
	lock
	faceplayer
	checkitem ITEM_TM_ROAR
	goto_if_eq VAR_RESULT, TRUE, Route32_EventScript_Roar2
	msgbox Route32_Text_RoarIntro, MSGBOX_DEFAULT
	giveitem ITEM_TM_ROAR
	msgbox Route32_Text_RoarOutro, MSGBOX_DEFAULT
	closemessage
	release
	end
Route32_EventScript_Roar2::
	msgbox Route32_Text_RoarOutro, MSGBOX_DEFAULT
	closemessage
	release
	end

Route32_EventScript_SlowpokeTail_TriggerLeft::
	lock
	turnobject LOCALID_SLOWPOKETAIL_MAN, DIR_EAST
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	playse SE_PIN
	applymovement LOCALID_SLOWPOKETAIL_MAN, Common_Movement_ExclamationMark
	delay 60
	applymovement LOCALID_SLOWPOKETAIL_MAN, Route32_Movement_SlowpokeLeft
	waitmovement 0
	goto Route32_EventScript_SlowpokeTail_Trigger

Route32_EventScript_SlowpokeTail_TriggerMid::
	lock
	turnobject LOCALID_SLOWPOKETAIL_MAN, DIR_EAST
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	playse SE_PIN
	applymovement LOCALID_SLOWPOKETAIL_MAN, Common_Movement_ExclamationMark
	delay 60
	applymovement LOCALID_SLOWPOKETAIL_MAN, Route32_Movement_SlowpokeMid
	waitmovement 0
	goto Route32_EventScript_SlowpokeTail_Trigger

Route32_EventScript_SlowpokeTail_TriggerRight::
	lock
	turnobject LOCALID_SLOWPOKETAIL_MAN, DIR_EAST
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	playse SE_PIN
	applymovement LOCALID_SLOWPOKETAIL_MAN, Common_Movement_ExclamationMark
	delay 60
	applymovement LOCALID_SLOWPOKETAIL_MAN, Route32_Movement_SlowpokeRight
	waitmovement 0
	goto Route32_EventScript_SlowpokeTail_Trigger

Route32_EventScript_SlowpokeTail_Trigger::
	msgbox Route32_Text_SlowpokeTailOffer, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, Route32_EventScript_SlowpokeTail_Trigger2
	msgbox Route32_Text_RefusedSlowpokeTail, MSGBOX_DEFAULT
	closemessage
	setvar VAR_SLOWPOKE_TAIL, 1
	release
	end	
Route32_EventScript_SlowpokeTail_Trigger2::
	msgbox Route32_Text_ThoughtKidsLoaded, MSGBOX_DEFAULT
	closemessage
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	call_if_eq VAR_TEMP_0, 16, Route32_EventScript_Movement_Left
	call_if_eq VAR_TEMP_0, 17, 	Route32_EventScript_Movement_Right
	setvar VAR_SLOWPOKE_TAIL, 1
	release
	end

Route32_EventScript_Movement_Left::
	applymovement LOCALID_SLOWPOKETAIL_MAN, Common_Movement_WalkLeft1
	waitmovement 0
	turnobject LOCALID_SLOWPOKETAIL_MAN, DIR_EAST
	return 

Route32_EventScript_Movement_Right::
	applymovement LOCALID_SLOWPOKETAIL_MAN, Common_Movement_WalkLeft1
	waitmovement 0
	applymovement LOCALID_SLOWPOKETAIL_MAN, Common_Movement_WalkLeft1
	waitmovement 0
	turnobject LOCALID_SLOWPOKETAIL_MAN, DIR_EAST
	return 	

Route32_EventScript_SlowpokeTail::
	lock
	faceplayer
	msgbox Route32_Text_SlowpokeTailOffer, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, Route32_EventScript_SlowpokeTail2
	msgbox Route32_Text_RefusedSlowpokeTail, MSGBOX_DEFAULT
	closemessage
	release
	end
Route32_EventScript_SlowpokeTail2::
	msgbox Route32_Text_ThoughtKidsLoaded, MSGBOX_DEFAULT
	closemessage
	release
	end


Route32_EventScript_Frieda::
	lock
	faceplayer
	goto_if_set FLAG_GOT_POISON_BARB, Route32_EventScript_FriedaCompleted
	msgbox Route32_Text_MeetFrieda, MSGBOX_DEFAULT
	closemessage
	multichoice 20, 0, MULTI_DAYS_OF_WEEK, FALSE
	switch VAR_RESULT
	case 0, Route32_EventScript_FriedaNope
	case 1, Route32_EventScript_FriedaNope
	case 2, Route32_EventScript_FriedaNope
	case 3, Route32_EventScript_FriedaNope
	case 4, Route32_EventScript_FriedaNope
	case 5, Route32_EventScript_FriedaYes
	case 6, Route32_EventScript_FriedaNope
	case 7, Route32_EventScript_FriedaCancel
	case MULTI_B_PRESSED, Route32_EventScript_FriedaCancel
	closemessage
	release
	end
Route32_EventScript_FriedaYes::
	msgbox Route32_Text_FriedaGivesGift, MSGBOX_DEFAULT
	giveitem ITEM_POISON_BARB
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_POISON_BARB
	msgbox Route32_Text_FriedaGaveGift, MSGBOX_DEFAULT
	closemessage
	release
	end
Route32_EventScript_FriedaNope::
	msgbox Route32_Text_FriedaNope, MSGBOX_DEFAULT
	closemessage
	release
	end
Route32_EventScript_FriedaCancel::
	closemessage
	release
	end
Route32_EventScript_FriedaCompleted::
	msgbox Route32_Text_FriedaFriday, MSGBOX_DEFAULT
	closemessage
	release
	end

Route32_EventScript_BaldingMan::
	lock
	faceplayer
	msgbox Route32_Text_CooltrainerM_Experiences, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_ROUTE32_BALDINGMAN, DIR_EAST
	release
	end

Route32_EventScript_BaldingManTriggerLeft::
	lock
	playse SE_PIN
	applymovement LOCALID_ROUTE32_BALDINGMAN, Common_Movement_ExclamationMark
	delay 60
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	goto Route32_EventScript_BaldingManCheck
	end
Route32_EventScript_BaldingManTriggerMid::
	lock
	playse SE_PIN
	applymovement LOCALID_ROUTE32_BALDINGMAN, Common_Movement_ExclamationMark
	delay 60
	applymovement OBJ_EVENT_ID_PLAYER, Route32_Movement_StartMid
	waitmovement 0
	goto Route32_EventScript_BaldingManCheck
	end
Route32_EventScript_BaldingManTriggerRight::
	lock
	playse SE_PIN
	applymovement LOCALID_ROUTE32_BALDINGMAN, Common_Movement_ExclamationMark
	delay 60
	applymovement OBJ_EVENT_ID_PLAYER, Route32_Movment_StartRight
	waitmovement 0
	goto Route32_EventScript_BaldingManCheck
	end
Route32_EventScript_BaldingManCheck::
	goto_if_unset FLAG_HIDE_SPROUT_TOWER_SILVER, Route32_EventScript_BaldingManTower
	goto_if_unset FLAG_DEFEATED_VIOLET_GYM, Route32_EventScript_BaldingManGym
	goto_if_unset FLAG_RECEIVED_TOGEPI_EGG, Route32_EventScript_BaldingManEgg
	msgbox Route32_Text_CooltrainerM_HaveThisSeed, MSGBOX_DEFAULT
	giveitem ITEM_MIRACLE_SEED
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	closemessage
	setvar VAR_VIOLET_CITY_STATE, 5
	release
	end
Route32_EventScript_BaldingManTower::
	msgbox Route32_Text_CooltrainerM_WhatsTheHurry, MSGBOX_DEFAULT
	msgbox Route32_Text_CooltrainerM_SproutTower, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Route32_Movement_Turnback
	waitmovement 0
	release
	end
Route32_EventScript_BaldingManGym::
	msgbox Route32_Text_CooltrainerM_WhatsTheHurry, MSGBOX_DEFAULT
	msgbox Route32_Text_CooltrainerM_VioletGym, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Route32_Movement_Turnback
	waitmovement 0
	release
	end
Route32_EventScript_BaldingManEgg::
	msgbox Route32_Text_CooltrainerM_WhatsTheHurry, MSGBOX_DEFAULT
	msgbox Route32_Text_CooltrainerM_AideIsWaiting, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Route32_Movement_Turnback
	waitmovement 0
	release
	end

Route32_EventScript_Potion::
	finditem ITEM_POTION
	end
Route32_EventScript_GreatBall::
	finditem ITEM_GREAT_BALL
	end
Route32_EventScript_GreatBallII::
	finditem ITEM_GREAT_BALL
	end
Route32_EventScript_SuperPotion::
	finditem ITEM_SUPER_POTION
	end

Route32_EventScript_Sign1::
	lock
	msgbox Route32_Text_Sign1, MSGBOX_SIGN
	closemessage
	release
	end

Route32_EventScript_Sign2::
	lock
	msgbox Route32_Text_Sign2, MSGBOX_SIGN
	closemessage
	release
	end

Route32_EventScript_Sign3::
	lock
	msgbox Route32_Text_Sign3, MSGBOX_SIGN
	closemessage
	release
	end

Route32_Movement_Turnback:
	walk_up
	step_end

Route32_Movement_StartMid:
	walk_left
	step_end

Route32_Movment_StartRight:
	walk_left
	walk_left
	step_end

Route32_Movement_SlowpokeLeft::
	step_end

Route32_Movement_SlowpokeMid::
	walk_right
	step_end

Route32_Movement_SlowpokeRight::
	walk_right
	walk_right
	step_end

Route32_Text_CooltrainerM_WhatsTheHurry:
	.string "Attends !\n"
	.string "Pourquoi tant de hâte ?$"

Route32_Text_CooltrainerM_AideIsWaiting:
	.string "{PLAYER}, c'est bien ça ?\n"
	.string "Un gars avec des lunettes\p"
	.string "te cherchait.\p"
	.string "Va voir par toi-même. Il t'attend\n"
	.string "au CENTRE POKéMON.$"

Route32_Text_CooltrainerM_SproutTower:
	.string "Es-tu allé à la TOUR CHÊNE ?\n"
	.string "Si tu vas à MAUVILLE,\p"
	.string "on s'attend à ce que tu t'entraînes là-bas.\n"
	.string "C'est la base pour les dresseurs.\p"
	.string "Va à la TOUR CHÊNE !$"

Route32_Text_CooltrainerM_VioletGym:
	.string "Es-tu allé à l'ARÈNE POKéMON ?\n"
	.string "Tu peux tester tes POKéMON et\p"
	.string "toi-même là-bas.\n"
	.string "C'est un rite de passage pour tous\p"
	.string "les dresseurs !$"

Route32_Text_CooltrainerM_HaveThisSeed:
	.string "Tu as de bons POKéMON avec toi.\n"
	.string "Ça doit venir de l'entraînement que\p"
	.string "tu leur as donné près de MAUVILLE.\n"
	.string "L'entraînement à l'ARÈNE a dû être\p"
	.string "particulièrement utile. Comme souvenir\n"
	.string "de MAUVILLE, prends ceci.\p"
	.string "Ça augmente la puissance des attaques\n"
	.string "de type PLANTE.$"

Route32_Text_CooltrainerM_Experiences:
	.string "Tes expériences à MAUVILLE\n"
	.string "seront utiles pour ton voyage.$"

Route32_Text_SlowpokeTailOffer:
	.string "Ça te dirait d'avoir cette\n"
	.string "queue de RAMOLOSS savoureuse et nutritive ?\p"
	.string "Pour toi, maintenant, seulement\n"
	.string "¥1 000 000 !\p"
	.string "Tu en veux, c'est sûr !$"

Route32_Text_ThoughtKidsLoaded:
	.string "Tch ! Je croyais que les gosses\n"
	.string "étaient riches de nos jours…$"

Route32_Text_RefusedSlowpokeTail:
	.string "Tu n'en veux pas ?\n"
	.string "Alors, ouste. Dégage !$"

Route32_Text_FisherJustin_Seen:
	.string "Ouah !\p"
	.string "Tu m'as fait perdre ce poisson !$"

Route32_Text_FisherJustin_Beaten:
	.string "Plouf !$"

Route32_Text_FisherJustin_After:
	.string "Calme, posé… L'essence de\n"
	.string "la pêche et des POKéMON est la même.$"

Route32_Text_FisherRalph1_Seen:
	.string "Je suis vraiment doué pour la pêche\n"
	.string "et les POKéMON.\p"
	.string "Je ne vais pas perdre contre un gamin !$"

Route32_Text_FisherRalph1_Beaten:
	.string "Tch ! J'ai voulu aller trop vite…$"

Route32_Text_FisherRalph1_After:
	.string "La pêche est une passion\n"
	.string "pour la vie.\p"
	.string "Les POKéMON sont des amis pour la vie !$"

Route32_Text_FisherHenry_Seen:
	.string "Mes POKéMON ? Fraîchement attrapés !$"

Route32_Text_FisherHenry_Beaten:
	.string "PLOUF ?$"

Route32_Text_FisherHenry_After:
	.string "Des POKéMON fraîchement attrapés\n"
	.string "ne valent pas ceux bien élevés.$"

Route32_Text_YoungsterAlbert_Seen:
	.string "Je ne t'ai jamais vu avant.\n"
	.string "Tu te crois fort, hein ?$"

Route32_Text_YoungsterAlbert_Beaten:
	.string "Tu es fort !$"

Route32_Text_YoungsterAlbert_After:
	.string "Je vais essayer d'être le\n"
	.string "meilleur avec mes préférés.\p"
	.string "Je n'utilise pas les mêmes POKéMON\n"
	.string "puissants que tout le monde.$"

Route32_Text_YoungsterGordon_Seen:
	.string "J'ai trouvé de bons POKéMON\n"
	.string "dans l'herbe !\p"
	.string "Je pense qu'ils feront l'affaire !$"

Route32_Text_YoungsterGordon_Beaten:
	.string "Zut. Je croyais pouvoir gagner.$"

Route32_Text_YoungsterGordon_After:
	.string "L'herbe est pleine de\n"
	.string "choses collantes.$"

Route32_Text_CamperRoland_Seen:
	.string "Ce regard… C'est intriguant.$"

Route32_Text_CamperRoland_Beaten:
	.string "Hmm. C'est décevant.$"

Route32_Text_CamperRoland_After:
	.string "Si tu ne veux pas te battre,\n"
	.string "évite juste le regard des autres.$"

Route32_Text_PicnickerLiz1_Seen:
	.string "Hmm hmm. Oui, tu sais…\p"
	.string "Pardon ? Un combat ? Je suis au téléphone.\n"
	.string "Bon, d'accord. Mais fais vite !$"

Route32_Text_PicnickerLiz1_Beaten:
	.string "Oh ! Je dois évacuer\n"
	.string "ma colère !$"

Route32_Text_PicnickerLiz1_After:
	.string "J'étais en pleine discussion aussi.$"

Route32_Text_BirdKeeperPeter_Seen:
	.string "Ce BADGE ! Il vient de MAUVILLE !\n"
	.string "Tu as battu ALFRED ?$"

Route32_Text_BirdKeeperPeter_Beaten:
	.string "Je connais mes faiblesses.$"

Route32_Text_BirdKeeperPeter_After:
	.string "Je devrais m'entraîner à nouveau\n"
	.string "à l'ARÈNE de MAUVILLE.$"

Route32_Text_RoarIntro:
	.string "WROOOOAR ! LES GENS FUIENT QUAND JE\n"
	.string "RUGIS ! MAIS TOI, TU ES VENU !\p"
	.string "ÇA ME FAIT PLAISIR ! PRENDS ÇA !$"

Route32_Text_RoarOutro:
	.string "WROOOOAR ! C'EST RUGISSEMENT !\p"
	.string "MÊME LES POKéMON FUIENT DEVANT UN BON\n"
	.string "RUGISSEMENT !$"

Route32_Text_MeetFrieda:
	.string "FRIEDA : Youpi !\p"
	.string "Je suis FRIEDA de la FAMILLE DES JOURS !\n"
	.string "Ravie de te rencontrer !\p"
	.string "Si tu devines mon jour préféré,\n"
	.string "je te donnerai une récompense.$"

Route32_Text_FriedaGivesGift:
	.string "Voici une POINTE TOXIK pour toi !$"

Route32_Text_FriedaGaveGift:
	.string "FRIEDA : Donne-la à un POKéMON\n"
	.string "qui a des attaques de type POISON.\p"
	.string "Oh !\p"
	.string "C'est super !\p"
	.string "Tu seras surpris de voir à quel point\n"
	.string "ça rend les attaques poison puissantes !$"

Route32_Text_FriedaFriday:
	.string "FRIEDA : Salut ! Quel jour\n"
	.string "préfères-tu ?\p"
	.string "J'adore le vendredi. Sans aucun doute !\n"
	.string "Tu ne trouves pas que c'est génial aussi ?$"

Route32_Text_FriedaNope:
	.string "FRIEDA : Pas celui-là !$"

Route32_Text_Sign1:
	.string "ROUTE 32\p"
	.string "MAUVILLE - ECORCIA$"

Route32_Text_Sign2:
	.string "RUINES D'ALPHA\n"
	.string "ENTRÉE EST$"

Route32_Text_Sign3:
	.string "GROTTE UNION\n"
	.string "EN AVANT$"
