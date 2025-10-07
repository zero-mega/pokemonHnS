.set LOCALID_MRPOKEMON, 2
.set LOCALID_ROUTE30_OAK, 3
.set LOCALID_MRPOKEMON2, 1

Route30_MrPokemonsHouse_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MrPokemonHouse_OnFrame
	.byte 0

MrPokemonHouse_OnFrame::
	map_script_2 VAR_CHERRYGROVE_CITY_STATE, 1, MrPokemonHouse_EventScript_GiveEgg
	.2byte 0

MrPokemonHouse_EventScript_GiveEgg::
	lock
	playse SE_PIN
	applymovement LOCALID_MRPOKEMON, Common_Movement_ExclamationMark	
	delay 60
	turnobject LOCALID_MRPOKEMON, DIR_SOUTH
	msgbox MrPokemonHouse_Text_Intro1, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, MrPokemonHouse_Movement_MeetMrPokemon
	waitmovement 0
	msgbox MrPokemonHouse_Text_Intro2, MSGBOX_DEFAULT

	giveitem ITEM_MYSTERY_EGG

	msgbox MrPokemonHouse_Text_Intro3, MSGBOX_DEFAULT
	msgbox MrPokemonHouse_Text_Intro4, MSGBOX_DEFAULT
	turnobject LOCALID_ROUTE30_OAK, DIR_WEST
	msgbox MrPokemonHouse_Text_Intro5, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_HG_OAK, TRUE
	applymovement LOCALID_ROUTE30_OAK, MrPokemonHouse_Movement_OakToPlayer
	waitmovement 0 
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	msgbox MrPokemonHouse_Text_OakIntro, MSGBOX_DEFAULT
	

	playfanfare MUS_OBTAIN_ITEM
	message MrPokemonHouse_Text_GetDex
	waitfanfare

	
	msgbox MrPokemonHouse_Text_OakParting MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROUTE30_OAK, MrPokemonHouse_Movement_OakLeave
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_ROUTE30_OAK
	setflag FLAG_DELIVERED_EGG
	turnobject OBJ_EVENT_ID_PLAYER DIR_NORTH
	fadedefaultbgm
	msgbox MrPokemonHouse_Text_Heal, MSGBOX_DEFAULT
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox MrPokemonHouse_Text_DependingOnYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MRPOKEMON, MrPokemonHouse_Movement_MrPokemon_Leave
	waitmovement 0
	removeobject LOCALID_MRPOKEMON
	clearflag FLAG_HIDE_MRPOKEMON
	addobject LOCALID_MRPOKEMON2
	
	setvar VAR_NEWBARKTOWN_LABSTATE, 4
	setflag FLAG_HIDE_SILVER_NEWBARKTOWN
	setflag FLAG_SYS_POKEDEX_GET
	clearflag FLAG_HIDE_LAB_POLICEMAN
	setvar VAR_CHERRYGROVE_CITY_STATE, 2
	setrespawn HEAL_LOCATION_CHERRYGROVE_CITY
	clearflag FLAG_HIDE_SILVER_CHERRYGROVE
	setflag FLAG_HIDE_GUIDE_GENT_CHERRYGROVE
	clearflag FLAG_HIDE_CHERRYGROVE_GUIDE_GENT_HOUSE

	release
	end

MrPokemonHouse_EventScript_MrPokemon::
	lock
	faceplayer
	checkitem ITEM_RED_SCALE
	goto_if_eq VAR_RESULT, TRUE, MrPokemonHouse_EventScript_MrPokemon_RedScale
	msgbox MrPokemonHouse_Text_AlwaysNewDiscoveries, MSGBOX_DEFAULT
	closemessage
	release
	end

MrPokemonHouse_EventScript_MrPokemon_RedScale::
	msgbox MrPokemonHouse_Text_GimmeTheScale, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, MrPokemonHouse_EventScript_MrPokemon_RedScale_Accepted
	msgbox MrPokemonHouse_Text_Disappointed, MSGBOX_DEFAULT
	closemessage
	release
	end	

MrPokemonHouse_EventScript_MrPokemon_RedScale_Accepted::
	removeitem ITEM_RED_SCALE
	giveitem ITEM_EXP_SHARE_SMALL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	release
	end


MrPokemonHouse_EventScript_Computer::
	lock
	msgbox MrPokemonHouse_Text_BrokenComputer, MSGBOX_SIGN
	release
	end

MrPokemonHouse_EventScript_Magazine::
	lock
	msgbox MrPokemonHouse_Text_ForeignMagazines, MSGBOX_SIGN
	release
	end

MrPokemonHouse_EventScript_Coins::
	lock
	msgbox MrPokemonHouse_Text_StrangeCoins, MSGBOX_SIGN
	release
	end

MrPokemonHouse_Movement_MeetMrPokemon:
	walk_up
	walk_up
	walk_right
	walk_right
	face_up
	step_end

MrPokemonHouse_Movement_OakToPlayer:
	walk_down
	face_left
	step_end

MrPokemonHouse_Movement_OakLeave:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	walk_in_place_down
	step_end

MrPokemonHouse_Movement_MrPokemon_Leave:
	walk_up
	walk_left
	walk_left
	step_end

MrPokemonHouse_Text_Intro1:
	.string "Bonjour, bonjour ! Tu dois être\n"
	.string "{PLAYER}.\p"
	.string "Le PROF.ORME a dit que tu\n"
	.string "viendrais.$"

MrPokemonHouse_Text_Intro2:
	.string "C'est ce que je veux que le\n"
	.string "PROF.ORME examine.$"

MrPokemonHouse_Text_GotEgg:
	.string "{PLAYER} a reçu l'ŒUF MYSTÈRE.$"

MrPokemonHouse_Text_Intro3:
	.string "Je connais un couple qui tient\n"
	.string "une PENSION POKéMON.\p"
	.string "Ils m'ont donné cet ŒUF.\p"
	.string "J'étais intrigué, alors j'ai\n"
	.string "envoyé un courrier au PROF.ORME.\p"
	.string "Pour l'évolution des POKéMON,\n"
	.string "le PROF.ORME est l'autorité.$"

MrPokemonHouse_Text_Intro4:
	.string "Même le PROF.CHEN ici présent\n"
	.string "le reconnaît.$"

MrPokemonHouse_Text_Intro5:
	.string "Si mon hypothèse est correcte,\n"
	.string "le PROF.ORME le saura.$"

MrPokemonHouse_Text_Heal:
	.string "Tu retournes voir le PROF.ORME ?\p"
	.string "Tiens. Tes POKéMON devraient\n"
	.string "se reposer un peu.$"

MrPokemonHouse_Text_DependingOnYou:
	.string "Je compte sur toi !$"

MrPokemonHouse_Text_AlwaysNewDiscoveries:
	.string "La vie est merveilleuse !\n"
	.string "Toujours de nouvelles découvertes à faire.$"

MrPokemonHouse_Text_OakIntro:
	.string "CHEN : Ah ! Tu es donc {PLAYER} !\p"
	.string "Je suis CHEN ! Un chercheur POKéMON.\p"
	.string "Je rendais visite à mon vieil ami\n"
	.string "MR. POKéMON.\p"
	.string "J'ai entendu dire que tu faisais une course\n"
	.string "pour le PROF.ORME, alors je t'ai attendu ici.\p"
	.string "Oh ! Qu'est-ce que c'est ? Un POKéMON rare !\p"
	.string "Voyons voir…\n"
	.string "Hmm, je vois !\p"
	.string "Je comprends pourquoi le PROF.ORME t'a donné\n"
	.string "un POKéMON pour cette mission.\p"
	.string "Pour les chercheurs comme le PROF.ORME et moi,\n"
	.string "les POKéMON sont nos amis.\p"
	.string "Il a vu que tu traiterais ton POKéMON\n"
	.string "avec amour et soin.\p"
	.string "…Ah !\p"
	.string "Tu sembles digne de confiance. Est-ce que tu\n"
	.string "voudrais m'aider ?\p"
	.string "Regarde ! Voici la dernière version du\n"
	.string "POKéDEX.\p"
	.string "Il enregistre automatiquement les données sur\n"
	.string "les POKéMON que tu as vus ou attrapés.\p"
	.string "C'est une encyclopédie high-tech !\p"
	.string "Il montre leurs habitats, comment ils évoluent\n"
	.string "et leurs attaques.$"

MrPokemonHouse_Text_GetDex:
	.string "{PLAYER} a reçu le POKéDEX !$"

MrPokemonHouse_Text_OakParting:
	.string "Va rencontrer plein de POKéMON et\n"
	.string "complète ce POKéDEX !\p"
	.string "Mais je suis resté trop longtemps.\p"
	.string "Je dois aller à DOUBLONVILLE\n"
	.string "pour mon émission de radio habituelle.\p"
	.string "{PLAYER}, je compte sur toi !$"

MrPokemonHouse_Text_GimmeTheScale:
	.string "Hmm ? Cette ÉCAILLE ! Qu'est-ce que c'est ?\n"
	.string "Un LEVIATOR rouge ?\p"
	.string "C'est rare ! Je, je la veux…\p"
	.string "{PLAYER}, voudrais-tu\n"
	.string "l'échanger ?\p"
	.string "Je peux t'offrir ce MULTI.EXP\n"
	.string "que j'ai reçu du PROF.CHEN.$"

MrPokemonHouse_Text_Disappointed:
	.string "C'est décevant.\n"
	.string "C'est pourtant très rare.$"

MrPokemonHouse_Text_ExpShare:
	.string "J'ai aussi un objet spécial\n"
	.string "pour toi.$"

MrPokemonHouse_Text_ForeignMagazines:
	.string "C'est rempli de magazines\n"
	.string "étrangers.\p"
	.string "Je ne peux même pas lire les titres…$"

MrPokemonHouse_Text_BrokenComputer:
	.string "C'est un gros ordinateur.\n"
	.string "Hmm. Il est en panne.$"

MrPokemonHouse_Text_StrangeCoins:
	.string "Un tas de pièces étranges !\p"
	.string "Peut-être qu'elles viennent d'un\n"
	.string "autre pays…$"

MrPokemonHouse_Text_GotExpShare:
	.string "{PLAYER} a reçu le MULTI.EXP !$"