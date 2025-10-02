.set LOCALID_WINGULL, 3

FortreeCity_House4_MapScripts::
	.byte 0

FortreeCity_House4_EventScript_Woman::
	msgbox FortreeCity_House4_Text_BringsWorldCloserTogether, MSGBOX_NPC
	end

FortreeCity_House4_EventScript_Boy::
	lockall
	goto_if_set FLAG_RECEIVED_MENTAL_HERB, FortreeCity_House4_EventScript_ReceivedMentalHerb
	goto_if_set FLAG_WINGULL_DELIVERED_MAIL, FortreeCity_House4_EventScript_WingullReturned
	goto_if_set FLAG_WINGULL_SENT_ON_ERRAND, FortreeCity_House4_EventScript_WingullOnErrand
	msgbox FortreeCity_House4_Text_GoBirdPokemon, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_WINGULL_SENT_ON_ERRAND
	clearflag FLAG_GARBAGEFLAG
	applymovement LOCALID_WINGULL, FortreeCity_House4_Movement_WingullExit
	waitmovement 0
	removeobject LOCALID_WINGULL
	releaseall
	end

FortreeCity_House4_EventScript_WingullOnErrand::
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	msgbox FortreeCity_House4_Text_AskedWingullToRunErrand, MSGBOX_DEFAULT
	releaseall
	end

FortreeCity_House4_EventScript_WingullReturned::
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	msgbox FortreeCity_House4_Text_WelcomeWingullTakeMentalHerb, MSGBOX_DEFAULT
	giveitem ITEM_MENTAL_HERB
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_MENTAL_HERB
	releaseall
	end

FortreeCity_House4_EventScript_ReceivedMentalHerb::
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	msgbox FortreeCity_House4_Text_FriendsFarAwayThanksToWingull, MSGBOX_DEFAULT
	releaseall
	end

FortreeCity_House4_Movement_WingullExit:
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_in_place_faster_down
	delay_8
	step_end

FortreeCity_House4_EventScript_Wingull::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_WINGULL, CRY_MODE_NORMAL
	msgbox FortreeCity_House4_Text_Wingull, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FortreeCity_House4_Text_BringsWorldCloserTogether:
	.string "En étant avec des POKéMON,\n"
	.string "les gens se font de plus en plus d'amis.\p"
	.string "Et cela rapproche le monde,\n"
	.string "je trouve ça merveilleux !$"

FortreeCity_House4_Text_GoBirdPokemon:
	.string "Voilà !\n"
	.string "Vas-y, POKéMON OISEAU !$"

FortreeCity_House4_Text_AskedWingullToRunErrand:
	.string "Héhé, j'ai demandé à mon WINGULL\n"
	.string "de faire une course pour moi.$"

FortreeCity_House4_Text_WelcomeWingullTakeMentalHerb:
	.string "Bien !\n"
	.string "Bon retour, WINGULL !\p"
	.string "Hein ? Qu'est-ce que c'est ?\n"
	.string "Qu'est-ce qu'il tient ?\p"
	.string "Une HERBE MENTALE ?\n"
	.string "Il a dû la ramasser quelque part.\p"
	.string "Mais je ne suis pas DRESSEUR, alors tu\n"
	.string "peux la prendre.$"

FortreeCity_House4_Text_FriendsFarAwayThanksToWingull:
	.string "Grâce à mon WINGULL, j'ai des amis\n"
	.string "qui vivent très loin.$"

FortreeCity_House4_Text_Wingull:
	.string "WINGULL : Pihyoh !$"
