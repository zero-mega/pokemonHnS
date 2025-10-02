FortreeCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCity_Gym_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, FortreeCity_Gym_OnWarp
	.byte 0

FortreeCity_Gym_OnTransition:
	special RotatingGate_InitPuzzle
	setflag FLAG_TEMP_HIDE_FOLLOWER @ Hide follower bc of rotating gates
	end

FortreeCity_Gym_OnWarp:
	map_script_2 VAR_TEMP_0, VAR_TEMP_0, FortreeCity_Gym_EventScript_InitRotatingGates
	.2byte 0

@ NOTE: This rotating gate puzzle makes use of VAR_TEMP_0 - VAR_TEMP_3
FortreeCity_Gym_EventScript_InitRotatingGates::
	special RotatingGate_InitPuzzleAndGraphics
	end

FortreeCity_Gym_EventScript_Winona::
	trainerbattle_single TRAINER_WINONA_1, FortreeCity_Gym_Text_WinonaIntro, FortreeCity_Gym_Text_WinonaDefeat, FortreeCity_Gym_EventScript_WinonaDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, FortreeCity_Gym_EventScript_WinonaRematch
	goto_if_unset FLAG_RECEIVED_TM_AERIAL_ACE, FortreeCity_Gym_EventScript_GiveAerialAce2
	msgbox FortreeCity_Gym_Text_WinonaPostBattle, MSGBOX_DEFAULT
	release
	end

FortreeCity_Gym_EventScript_WinonaDefeated::
	message FortreeCity_Gym_Text_ReceivedFeatherBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox FortreeCity_Gym_Text_ExplainFeatherBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_OLIVINE_CITY_GYM
	setflag FLAG_BADGE06_GET
	setvar VAR_0x8008, 6
	call Common_EventScript_SetGymTrainers
	call FortreeCity_Gym_EventScript_GiveAerialAce
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox FortreeCity_Gym_Text_RegisteredWinona, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_WINONA_MATCH_CALL
	setvar VAR_SCOTT_FORTREE_CALL_STEP_COUNTER, 0
	setflag FLAG_SCOTT_CALL_FORTREE_GYM
	release
	end

FortreeCity_Gym_EventScript_GiveAerialAce2::
	giveitem ITEM_TM_AERIAL_ACE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox FortreeCity_Gym_Text_ExplainAerialAce, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_AERIAL_ACE
	release
	end

FortreeCity_Gym_EventScript_GiveAerialAce::
	giveitem ITEM_TM_AERIAL_ACE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox FortreeCity_Gym_Text_ExplainAerialAce, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_AERIAL_ACE
	return

FortreeCity_Gym_EventScript_WinonaRematch::
	trainerbattle_rematch_double TRAINER_WINONA_1, FortreeCity_Gym_Text_WinonaPreRematch, FortreeCity_Gym_Text_WinonaRematchDefeat, FortreeCity_Gym_Text_WinonaRematchNeedTwoMons
	msgbox FortreeCity_Gym_Text_WinonaPostRematch, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Jared::
	trainerbattle_single TRAINER_JARED, FortreeCity_Gym_Text_JaredIntro, FortreeCity_Gym_Text_JaredDefeat
	msgbox FortreeCity_Gym_Text_JaredPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Edwardo::
	trainerbattle_single TRAINER_LOIS, FortreeCity_Gym_Text_EdwardoIntro, FortreeCity_Gym_Text_EdwardoDefeat
	msgbox FortreeCity_Gym_Text_EdwardoPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Flint::
	trainerbattle_single TRAINER_RAY, FortreeCity_Gym_Text_FlintIntro, FortreeCity_Gym_Text_FlintDefeat
	msgbox FortreeCity_Gym_Text_FlintPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Ashley::
	trainerbattle_single TRAINER_CHARLES, FortreeCity_Gym_Text_AshleyIntro, FortreeCity_Gym_Text_AshleyDefeat
	msgbox FortreeCity_Gym_Text_AshleyPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Humberto::
	trainerbattle_single TRAINER_CHUCK_2, FortreeCity_Gym_Text_HumbertoIntro, FortreeCity_Gym_Text_HumbertoDefeat
	msgbox FortreeCity_Gym_Text_HumbertoPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Darius::
	trainerbattle_single TRAINER_JIN, FortreeCity_Gym_Text_DariusIntro, FortreeCity_Gym_Text_DariusDefeat
	msgbox FortreeCity_Gym_Text_DariusPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_OLIVINE_CITY_GYM, FortreeCity_Gym_EventScript_GymGuidePostVictory
	msgbox FortreeCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

FortreeCity_Gym_EventScript_GymGuidePostVictory::
	msgbox FortreeCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

FortreeCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE06_GET, FortreeCity_Gym_EventScript_GymStatueCertified
	goto FortreeCity_Gym_EventScript_GymStatue
	end

FortreeCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE06_GET, FortreeCity_Gym_EventScript_GymStatueCertified
	goto FortreeCity_Gym_EventScript_GymStatue
	end

FortreeCity_Gym_EventScript_GymStatueCertified::
	msgbox FortreeCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

FortreeCity_Gym_EventScript_GymStatue::
	msgbox FortreeCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

FortreeCity_Gym_Text_GymGuideAdvice:
	.string "Yo, comment ça va, CHAMPION\n"
	.string "en devenir {PLAYER} ?\p"
	.string "La CHAMPIONNE de l'ARÈNE de CLEMENTI-VILLE, WINONA,\n"
	.string "est une experte des POKéMON de type VOL.\p"
	.string "Elle t'attend au fond de cette ARÈNE,\n"
	.string "derrière les portes tournantes.\p"
	.string "Elle attend de nouveaux challengers\n"
	.string "qui veulent prendre leur envol !\p"
	.string "Allez, fonce !$"

FortreeCity_Gym_Text_GymGuidePostVictory:
	.string "Tu l'as fait !\n"
	.string "Tu as décollé !$"

FortreeCity_Gym_Text_JaredIntro:
	.string "Admire le style de combat élégant\n"
	.string "des POKéMON OISEAU !$"

FortreeCity_Gym_Text_JaredDefeat:
	.string "Toi…\n"
	.string "Tu es fort…$"

FortreeCity_Gym_Text_JaredPostBattle:
	.string "Un DRESSEUR doit être malin pour suivre\n"
	.string "le rythme des imprévus.\p"
	.string "As-tu l'intelligence pour atteindre\n"
	.string "notre CHAMPIONNE ?$"

FortreeCity_Gym_Text_EdwardoIntro:
	.string "Les amoureux des POKéMON OISEAU rêvent\n"
	.string "de rejoindre cette ARÈNE.\p"
	.string "En tant que membre de l'ARÈNE de CLEMENTI-VILLE,\n"
	.string "je n'ai pas le droit de perdre !$"

FortreeCity_Gym_Text_EdwardoDefeat:
	.string "C'était trop lourd à porter\n"
	.string "pour moi…$"

FortreeCity_Gym_Text_EdwardoPostBattle:
	.string "Le monde est vaste, et il y a\n"
	.string "d'innombrables DRESSEURS puissants.\p"
	.string "Je vais continuer à m'entraîner et devenir\n"
	.string "encore plus fort.$"

FortreeCity_Gym_Text_FlintIntro:
	.string "Pas besoin que WINONA, notre CHAMPIONNE,\n"
	.string "s'occupe de toi !\p"
	.string "Je suis largement assez bon pour toi !$"

FortreeCity_Gym_Text_FlintDefeat:
	.string "WINONA, je…\n"
	.string "J'ai perdu !$"

FortreeCity_Gym_Text_FlintPostBattle:
	.string "WINONA est mignonne et elle est forte.\n"
	.string "C'est la CHAMPIONNE ultime !\p"
	.string "Rougit…$"

FortreeCity_Gym_Text_AshleyIntro:
	.string "WINONA m'a formée personnellement !\n"
	.string "Tu ne me battras pas facilement !$"

FortreeCity_Gym_Text_AshleyDefeat:
	.string "J'ai été battue…$"

FortreeCity_Gym_Text_AshleyPostBattle:
	.string "Grâce à WINONA, les habitants de\n"
	.string "CLEMENTI-VILLE vivent sans crainte.$"

FortreeCity_Gym_Text_HumbertoIntro:
	.string "Quand WINONA se bat, son visage\n"
	.string "brille d'une belle détermination…\p"
	.string "Je ne te laisserai pas voir\n"
	.string "ce magnifique spectacle !$"

FortreeCity_Gym_Text_HumbertoDefeat:
	.string "Argh !\n"
	.string "Je n'ai pas pu t'arrêter.$"

FortreeCity_Gym_Text_HumbertoPostBattle:
	.string "Tu ferais mieux de faire attention !\n"
	.string "Ne te laisse pas distraire à regarder WINONA\l"
	.string "ou tu t'écraseras lamentablement !$"

FortreeCity_Gym_Text_DariusIntro:
	.string "Tu ferais mieux de savoir qu'il existe\n"
	.string "toutes sortes de POKéMON de type VOL.\p"
	.string "Tu le sais, n'est-ce pas ?$"

FortreeCity_Gym_Text_DariusDefeat:
	.string "On dirait que tu t'y connais !$"

FortreeCity_Gym_Text_DariusPostBattle:
	.string "C'est vrai, tu m'as battu.\n"
	.string "Mais fais attention ! Les POKéMON de\l"
	.string "notre CHAMPIONNE WINONA sont redoutables.$"

FortreeCity_Gym_Text_WinonaIntro:
	.string "Je suis WINONA. Je suis la CHAMPIONNE de\n"
	.string "l'ARÈNE POKéMON de CLEMENTI-VILLE.\p"
	.string "Je ne fais qu'un avec les POKéMON OISEAU\n"
	.string "et j'ai survolé les cieux…\p"
	.string "Aussi éprouvant que soit le combat, nous avons\n"
	.string "triomphé avec grâce…\p"
	.string "Assiste à la chorégraphie élégante\n"
	.string "des POKéMON OISEAU et de moi !$"

FortreeCity_Gym_Text_WinonaDefeat:
	.string "Jamais encore je n'avais vu un DRESSEUR\n"
	.string "diriger ses POKéMON avec plus de grâce\l"
	.string "que moi…\p"
	.string "En reconnaissance de ta prouesse,\n"
	.string "je te remets ce BADGE D'ARÈNE.$"

FortreeCity_Gym_Text_ReceivedFeatherBadge:
	.string "{PLAYER} reçoit le BADGE PLUME\n"
	.string "de WINONA.$"

FortreeCity_Gym_Text_ExplainFeatherBadgeTakeThis:
	.string "Avec le BADGE PLUME, tous les POKéMON\n"
	.string "jusqu'au N.70, même ceux reçus par\l"
	.string "échange, t'obéiront sans discuter.\p"
	.string "Tu pourras aussi utiliser la CS VOL\n"
	.string "en dehors des combats,\p"
	.string "même si le POKéMON ne la connaît pas.\p"
	.string "La seule condition est que le\n"
	.string "POKéMON soit de type VOL.\p"
	.string "Et ceci…\n"
	.string "C'est un cadeau de ma part.$"

FortreeCity_Gym_Text_ExplainAerialAce:
	.string "La CT40 contient AÉRO-ACROBATIE.\p"
	.string "Sa vitesse…\n"
	.string "Aucun POKéMON ne devrait pouvoir l'éviter.\p"
	.string "… … … … … …$"

FortreeCity_Gym_Text_RegisteredWinona:
	.string "CHAMPIONNE WINONA enregistrée\n"
	.string "dans le POKéNAV.$"

FortreeCity_Gym_Text_WinonaPostBattle:
	.string "Même si j'ai perdu contre toi, je resterai\n"
	.string "dévouée aux POKéMON OISEAU.$"

FortreeCity_Gym_Text_GymStatue:
	.string "ARÈNE POKéMON DE CLEMENTI-VILLE$"

FortreeCity_Gym_Text_GymStatueCertified:
	.string "ARÈNE POKéMON DE CLEMENTI-VILLE\p"
	.string "DRESSEURS CERTIFIÉS PAR WINONA :\n"
	.string "{PLAYER}$"

FortreeCity_Gym_Text_WinonaPreRematch:
	.string "WINONA : Nous, humains, ne pouvons jamais\n"
	.string "échapper à l'attraction de la gravité.\p"
	.string "Mais en visant l'excellence,\n"
	.string "nous avons le pouvoir de nous élever !\p"
	.string "Tu as atteint le sommet en tant que\n"
	.string "CHAMPION en titre.\p"
	.string "S'il te plaît, permets-moi de voir ta puissance\n"
	.string "à son apogée !$"

FortreeCity_Gym_Text_WinonaRematchDefeat:
	.string "Je n'ai pas réussi à atteindre ta hauteur…$"

FortreeCity_Gym_Text_WinonaPostRematch:
	.string "WINONA : Même si j'ai perdu,\n"
	.string "les ailes de mon cœur restent intactes.\p"
	.string "Je peux m'élever et voler encore\n"
	.string "et encore.\p"
	.string "J'en suis convaincue !$"

FortreeCity_Gym_Text_WinonaRematchNeedTwoMons:
	.string "WINONA : Nous, humains, ne pouvons jamais\n"
	.string "échapper à l'attraction de la gravité.\p"
	.string "Mais en visant l'excellence,\n"
	.string "nous avons le pouvoir de nous élever !\p"
	.string "Tu as atteint le sommet en tant que\n"
	.string "CHAMPION en titre.\p"
	.string "S'il te plaît, permets-moi de voir ta puissance\n"
	.string "à son apogée !\p"
	.string "Oh, non… Tu n'as qu'un seul\n"
	.string "POKéMON avec toi ?\p"
	.string "Reviens avec au moins deux POKéMON\n"
	.string "s'il te plaît.$"
