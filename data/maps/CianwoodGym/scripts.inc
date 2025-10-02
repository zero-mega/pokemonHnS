.set LOCALID_CIANWOOD_CHUCK, 1
.set LOCALID_CIANWOOD_CHUCK_ROCK_LEFT, 10
.set LOCALID_CIANWOOD_CHUCK_ROCK_RIGHT, 9

CianwoodGym_MapScripts::
	.byte 0


CianwoodGym_EventScript_Statue::
	lock
	goto_if_set FLAG_DEFEATED_CIANWOOD_GYM, CianwoodGym_EventScript_Statue2
	msgbox CianwoodGym_Text_GymStatue, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodGym_EventScript_Statue2::
	msgbox CianwoodGym_Text_GymStatueCertified, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodGym_Text_GymStatue:
	.string "CIANWOOD CITY POKéMON GYM$"

CianwoodGym_Text_GymStatueCertified:
	.string "CIANWOOD CITY POKéMON GYM\p"
	.string "CHUCK'S CERTIFIED TRAINERS:\n"
	.string "{PLAYER}$"

CianwoodGym_EventScript_Chuck::
	lock
	faceplayer
	goto_if_unset FLAG_HIDE_DOJO_CHUCK, CianwoodGym_EventScript_ChuckAtDojo
	goto_if_set FLAG_VISITED_VERMILION_CITY, CianwoodGym_EventScript_ChuckGotoDojo
	goto_if_set FLAG_DEFEATED_CIANWOOD_GYM, CianwoodGym_EventScript_Chuck_Defeated
	msgbox CianwoodGym_Text_ChuckIntro1, MSGBOX_DEFAULT
	applymovement LOCALID_CIANWOOD_CHUCK, CianwoodGym_Movement_ChuckLeft
	waitmovement 0
	message CianwoodGym_Text_ChuckIntro2
	applymovement LOCALID_CIANWOOD_CHUCK_ROCK_LEFT, Movement_SmashRock
	playse SE_M_ROCK_THROW
	waitmovement 0

	delay 20

	applymovement LOCALID_CIANWOOD_CHUCK, CianwoodGym_Movement_ChuckRight
	waitmovement 0
	applymovement LOCALID_CIANWOOD_CHUCK_ROCK_RIGHT, Movement_SmashRock
	playse SE_M_ROCK_THROW
	waitmovement 0
	waitmessage
	turnobject LOCALID_CIANWOOD_CHUCK, DIR_SOUTH
	msgbox CianwoodGym_Text_ChuckIntro3, MSGBOX_DEFAULT
	goto_if_set FLAG_DEFEATED_OLIVINE_CITY_GYM, CianwoodGym_EventScript_OlivineCheckMahog
	goto_if_set FLAG_DEFEATED_MAHOGANY_TOWN_GYM, CianwoodGym_EventScript_MahogCheckOlivine
	goto CianwoodGym_EventScript_Chuck_Battle1

CianwoodGym_EventScript_ChuckVictory::
	message CianwoodGym_Text_GetStormBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox CianwoodGym_Text_ChuckBadgeSpeech, MSGBOX_DEFAULT
	setflag FLAG_BADGE05_GET
	setflag FLAG_DEFEATED_CIANWOOD_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 5
	call Common_EventScript_SetGymTrainers
	giveitem ITEM_TM_FOCUS_PUNCH
	msgbox CianwoodGym_Text_ChuckTMSpeech, MSGBOX_DEFAULT
	setvar VAR_GETFLY, 1
	setrespawn HEAL_LOCATION_CIANWOOD_CITY
	closemessage
	release
	end

CianwoodGym_EventScript_ChuckGotoDojo::
	msgbox CianwoodGym_Text_ChuckGotoDojo, MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_HIDE_DOJO_CHUCK
	release
	end

CianwoodGym_Text_ChuckGotoDojo:
	.string "WAHAHAHA {PLAYER} !\n"
	.string "Je suis en plein entraînement !\p"
	.string "Si tu veux une revanche, viens au\n"
	.string "DOJO KARATÉ à SAFRANIA !$"	

CianwoodGym_EventScript_ChuckAtDojo::
	msgbox CianwoodGym_Text_ChuckAtDojo, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodGym_Text_ChuckAtDojo:
	.string "Je te verrai au DOJO !\n"
	.string "WAHAHAHAHAHA$"

CianwoodGym_EventScript_OlivineCheckMahog::
	goto_if_set FLAG_DEFEATED_MAHOGANY_TOWN_GYM, CianwoodGym_EventScript_Chuck_Battle3
	goto CianwoodGym_EventScript_Chuck_Battle2

CianwoodGym_EventScript_MahogCheckOlivine::
	goto_if_set FLAG_DEFEATED_OLIVINE_CITY_GYM, CianwoodGym_EventScript_Chuck_Battle3
	goto CianwoodGym_EventScript_Chuck_Battle2
	
CianwoodGym_EventScript_Chuck_Battle1::
	trainerbattle_no_intro TRAINER_CHUCK_1, CianwoodGym_Text_ChuckIntro2
	goto CianwoodGym_EventScript_ChuckVictory

CianwoodGym_EventScript_Chuck_Battle2::
	trainerbattle_no_intro TRAINER_CHUCK_1_2, CianwoodGym_Text_ChuckIntro2
	goto CianwoodGym_EventScript_ChuckVictory

CianwoodGym_EventScript_Chuck_Battle3::
	trainerbattle_no_intro TRAINER_CHUCK_1_3, CianwoodGym_Text_ChuckIntro2
	goto CianwoodGym_EventScript_ChuckVictory

CianwoodGym_EventScript_Chuck_Defeated::
	msgbox CianwoodGym_Text_ChuckAfter, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodGym_Movement_ChuckLeft:
	jump_in_place_left
	step_end

CianwoodGym_Movement_ChuckRight:
	jump_in_place_right
	step_end

CianwoodGym_Text_ChuckIntro1:
	.string "WAHAHAH !\p"
	.string "Alors, tu es venu jusqu'ici !\p"
	.string "Laisse-moi te dire, je suis coriace !\p"
	.string "Mes POKéMON brisent des pierres et\n"
	.string "écrasent des os !\p"
	.string "Regarde ça !$"

CianwoodGym_Text_ChuckIntro2:
	.string "CHUCK : Urggh !\n"
	.string "…\p"
	.string "Oooarrgh !$"

CianwoodGym_Text_ChuckIntro3:
	.string "Voilà ! Tu as peur maintenant ?\p"
	.string "Quoi ? Ça n'a rien à voir avec les\n"
	.string "POKéMON ?\p"
	.string "C'est vrai !\p"
	.string "Allez, battons-nous !$"

CianwoodGym_Text_ChuckLoss:
	.string "Hein ? Quoi ? J'ai perdu ?\p"
	.string "Eh bien !\n"
	.string "Tu mérites le BADGE TEMPÊTE !$"

CianwoodGym_Text_GetStormBadge:
	.string "{PLAYER} reçoit le BADGE TEMPÊTE.$"

CianwoodGym_Text_ChuckBadgeSpeech:
	.string "Le BADGE TEMPÊTE fait obéir tous les\n"
	.string "POKéMON jusqu'au N.70, même échangés.\p"
	.string "Il permet aussi à tes POKéMON d'utiliser VOL\n"
	.string "en dehors des combats.\p"
	.string "Tiens, prends aussi ceci !$"

CianwoodGym_Text_ChuckTMSpeech:
	.string "C'est POING-ÉCLAIR.\p"
	.string "C'est lent mais inflige d'énormes\n"
	.string "dégâts. Ne te fais pas toucher avant !$"

CianwoodGym_Text_ChuckAfter:
	.string "WAHAHAH ! J'ai aimé me battre contre toi !\p"
	.string "Mais une défaite reste une défaite !\p"
	.string "Désormais, je vais m'entraîner\n"
	.string "24 heures sur 24 !$"

CianwoodGym_Text_ChuckRematch:
	.string "WAHAHAH ! CHAMPION DE JOHTO !\p"
	.string "Tu es revenu pour un autre combat !\p"
	.string "Je vois que tes compétences se sont améliorées !\p"
	.string "Prêt à voir qui est le plus fort ?$"

CianwoodGym_Text_ChuckRematchDefeat:
	.string "Hein ? Quoi ? J'ai perdu ?\n"
	.string "Encore ?$"

CianwoodGym_EventScript_Yoshi::
	trainerbattle_single TRAINER_YOSHI CianwoodGym_Text_BlackbeltYoshiSeen, CianwoodGym_Text_BlackbeltYoshiBeaten
	msgbox CianwoodGym_Text_BlackbeltYoshiAfter, MSGBOX_AUTOCLOSE
	end

CianwoodGym_Text_BlackbeltYoshiSeen:
	.string "Mon POKéMON et moi sommes liés\n"
	.string "par l'amitié.\p"
	.string "Ce lien ne sera jamais brisé !$"

CianwoodGym_Text_BlackbeltYoshiBeaten:
	.string "Ce n'est pas possible !$"

CianwoodGym_Text_BlackbeltYoshiAfter:
	.string "On dirait que tu as aussi un lien fort\n"
	.string "avec tes POKéMON !$"

CianwoodGym_EventScript_Lao::
	trainerbattle_single TRAINER_LAO CianwoodGym_Text_BlackbeltLaoSeen, CianwoodGym_Text_BlackbeltLaoBeaten
	msgbox CianwoodGym_Text_BlackbeltLaoAfter, MSGBOX_AUTOCLOSE
	end

CianwoodGym_Text_BlackbeltLaoSeen:
	.string "Nous, artistes martiaux, ne craignons rien !$"

CianwoodGym_Text_BlackbeltLaoBeaten:
	.string "C'est choquant !$"

CianwoodGym_Text_BlackbeltLaoAfter:
	.string "Les POKéMON combat ont peur\n"
	.string "des psy…$"


CianwoodGym_EventScript_Nob::
	trainerbattle_single TRAINER_NOB CianwoodGym_Text_BlackbeltNobSeen, CianwoodGym_Text_BlackbeltNobBeaten
	msgbox CianwoodGym_Text_BlackbeltNobAfter, MSGBOX_AUTOCLOSE
	end

CianwoodGym_Text_BlackbeltNobSeen:
	.string "Les mots sont inutiles.\n"
	.string "Laisse parler tes poings !$"

CianwoodGym_Text_BlackbeltNobBeaten:
	.string "…$"

CianwoodGym_Text_BlackbeltNobAfter:
	.string "J'ai perdu ! Je reste sans voix !$"

CianwoodGym_EventScript_Lung::
	trainerbattle_single TRAINER_LUNG CianwoodGym_Text_BlackbeltLungSeen, CianwoodGym_Text_BlackbeltLungBeaten
	msgbox CianwoodGym_Text_BlackbeltLungAfter, MSGBOX_AUTOCLOSE
	end

CianwoodGym_Text_BlackbeltLungSeen:
	.string "Mes poings furieux vont briser tes\n"
	.string "POKéMON !$"

CianwoodGym_Text_BlackbeltLungBeaten:
	.string "J'ai été brisé !$"

CianwoodGym_Text_BlackbeltLungAfter:
	.string "Mes POKéMON ont perdu…\n"
	.string "Mon… mon honneur est brisé…$"

