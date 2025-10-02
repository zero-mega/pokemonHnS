.set LOCALID_WALLACE, 1

CaveOfOrigin_B1F_MapScripts::
	.byte 0

CaveOfOrigin_B1F_EventScript_Wallace::
	lock
	faceplayer
	msgbox CaveOfOrigin_B1F_Text_WallaceStory, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_WALLACE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 60
	playse SE_PIN
	applymovement LOCALID_WALLACE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_WALLACE, Common_Movement_Delay48
	waitmovement 0
	delay 30
	applymovement LOCALID_WALLACE, Common_Movement_FacePlayer
	waitmovement 0
	message CaveOfOrigin_B1F_Text_WhereIsRayquaza
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza

CaveOfOrigin_B1F_EventScript_WheresRayquaza::
	multichoice 0, 0, MULTI_WHERES_RAYQUAZA, FALSE
	switch VAR_RESULT
	case 0, CaveOfOrigin_B1F_EventScript_AtCaveOfOrigin
	case 1, CaveOfOrigin_B1F_EventScript_AtMtPyre
	case 2, CaveOfOrigin_B1F_EventScript_AtSkyPillar
	case 3, CaveOfOrigin_B1F_EventScript_DontRemember
	goto CaveOfOrigin_B1F_EventScript_DontRemember
	end

CaveOfOrigin_B1F_EventScript_AtCaveOfOrigin::
	message CaveOfOrigin_B1F_Text_ButWereInCaveOfOrigin
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza

CaveOfOrigin_B1F_EventScript_AtMtPyre::
	message CaveOfOrigin_B1F_Text_OldLadyDidntMentionThat
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza

CaveOfOrigin_B1F_EventScript_DontRemember::
	message CaveOfOrigin_B1F_Text_CantYouRememberSomehow
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza

CaveOfOrigin_B1F_EventScript_AtSkyPillar::
	msgbox CaveOfOrigin_B1F_Text_WellHeadToSkyPillar, MSGBOX_DEFAULT
	closemessage
	playse SE_EXIT
	fadescreenspeed FADE_TO_BLACK, 4
	setflag FLAG_WALLACE_GOES_TO_SKY_PILLAR
	setvar VAR_GARBAGEVAR, 3
	removeobject LOCALID_WALLACE
	clearflag FLAG_GARBAGEFLAG
	fadescreen FADE_FROM_BLACK
	release
	end

CaveOfOrigin_B1F_Text_WallaceStory:
	.string "Ah, c'est donc toi, {PLAYER}{KUN} ?\n"
	.string "J'ai entendu parler de tes exploits.\p"
	.string "Je m'appelle WALLACE.\p"
	.string "J'étais autrefois le CHAMPION d'ARENE de\n"
	.string "NENUCRIQUE, mais un événement est survenu.\p"
	.string "J'ai donc confié la gestion de l'ARENE à mon mentor JUAN.\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "GROUDON et KYOGRE, les deux POKéMON\n"
	.string "qui sèment le chaos ici, sont considérés\l"
	.string "comme des POKéMON super-anciens.\p"
	.string "Mais il n'y a pas que deux POKéMON\n"
	.string "super-anciens.\p"
	.string "Il y en a un autre quelque part.\p"
	.string "Quelque part, il y a un POKéMON super-ancien\n"
	.string "nommé RAYQUAZA.\p"
	.string "On dit que c'est RAYQUAZA qui a calmé\n"
	.string "les deux combattants dans un lointain passé.\p"
	.string "Mais même moi, je n'ai aucune idée\n"
	.string "d'où se trouve RAYQUAZA…$"

CaveOfOrigin_B1F_Text_WhereIsRayquaza:
	.string "WALLACE : {PLAYER}{KUN}, saurais-tu par hasard\n"
	.string "où se trouve RAYQUAZA en ce moment ?\p"
	.string "Si tu le sais, dis-le-moi, s'il te plaît.$"

CaveOfOrigin_B1F_Text_ButWereInCaveOfOrigin:
	.string "WALLACE : La GROTTE ORIGINE ?\p"
	.string "Mais c'est ici même !\n"
	.string "Il va falloir faire mieux que ça !\p"
	.string "S'il te plaît, réfléchis bien à\n"
	.string "l'endroit où RAYQUAZA pourrait être maintenant.$"

CaveOfOrigin_B1F_Text_OldLadyDidntMentionThat:
	.string "WALLACE : Le MONT MEMORIA ?\p"
	.string "Mais quand j'ai rencontré la vieille dame là-bas\n"
	.string "plus tôt, elle n'en a pas parlé.\p"
	.string "Je doute fort que la vieille dame\n"
	.string "me cache quelque chose…\p"
	.string "{PLAYER}{KUN}, pourrais-tu y réfléchir\n"
	.string "plus attentivement pour moi ?$"

CaveOfOrigin_B1F_Text_CantYouRememberSomehow:
	.string "WALLACE : Hein ? Tu ne t'en souviens pas ?\n"
	.string "Hmm… C'est embêtant…\p"
	.string "Tu ne peux vraiment pas t'en souvenir ?$"

CaveOfOrigin_B1F_Text_WellHeadToSkyPillar:
	.string "WALLACE : La PILIER CELESTE ?\p"
	.string "C'est ça !\n"
	.string "Ça doit être le PILIER CELESTE !\p"
	.string "{PLAYER}{KUN}, il n'y a pas une seconde à perdre !\n"
	.string "Allons-y tout de suite !$"
