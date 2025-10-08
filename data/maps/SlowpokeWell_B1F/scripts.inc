.set LOCALID_WELL_KURT, 19

SlowpokeWell_B1F_MapScripts::
	.byte 0

SlowpokeWell_B1F_EventScript_Item_Super_Potion_1::
	finditem ITEM_SUPER_POTION
	end

SlowpokeWell_B1F_EventScript_Item_Super_Potion_2::
	finditem ITEM_SUPER_POTION
	end

SlowpokeWell_B1F_EventScript_Item_Great_Ball::
	finditem ITEM_GREAT_BALL
	end

SlowpokeWell_B1F_EventScript_Item_Full_Heal::
	finditem ITEM_FULL_HEAL
	end

SlowpokeWell_B1F_EventScript_Kurt::
	lock
	msgbox SlowpokeWell_B1F_Text_KurtIntro, MSGBOX_DEFAULT
	closemessage
	end

SlowpokeWell_B1F_EventScript_Grunt21::
	trainerbattle_single TRAINER_GRUNT_21, SlowpokeWell_B1F_Text_GruntM29Seen, SlowpokeWell_B1F_Text_GruntM29Beaten
	msgbox SlowpokeWell_B1F_Text_GruntM29After, MSGBOX_AUTOCLOSE
	end

SlowpokeWell_B1F_EventScript_Grunt22F::
	trainerbattle_single TRAINER_GRUNT_22, SlowpokeWell_B1F_Text_GruntF1Seen, SlowpokeWell_B1F_Text_GruntF1Beaten
	msgbox SlowpokeWell_B1F_Text_GruntF1After, MSGBOX_AUTOCLOSE
	end

SlowpokeWell_B1F_EventScript_Eto::
	trainerbattle_single TRAINER_ETO, SlowpokeWell_B1F_Text_GruntM2Seen, SlowpokeWell_B1F_Text_GruntM2Beaten
	msgbox SlowpokeWell_B1F_Text_GruntM2After, MSGBOX_AUTOCLOSE
	end

SlowpokeWell_B1F_EventScript_Proton::
	lock
	faceplayer
	msgbox SlowpokeWell_B1F_Text_ProtonSeen, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_PROTON_1, SlowpokeWell_B1F_Text_ProtonBeaten
	msgbox SlowpokeWell_B1F_Text_ProtonAfter, MSGBOX_AUTOCLOSE
	closemessage
	fadescreen FADE_TO_BLACK
	setflag FLAG_HIDE_AZALEA_TOWN_ROCKETS
	clearflag FLAG_HIDE_KURT_1
	addobject LOCALID_WELL_KURT
	removeobject 11
	removeobject 12
	removeobject 13
	delay 120
	fadescreen FADE_FROM_BLACK
	special DrawWholeMapView
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	applymovement LOCALID_WELL_KURT, SlowpokeWell_B1F_Movement_Kurt
	waitmovement 0
	msgbox SlowpokeWell_B1F_Text_KurtAfter, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	setflag FLAG_HIDE_SLOWPOKE_WELL_KURT
	setflag FLAG_HIDE_KURT_1
	clearflag FLAG_HIDE_KURT_2
	clearflag FLAG_HIDE_AZALEA_TOWN_SLOWPOKE
	setvar VAR_AZALEA_TOWN_STATE, 3
	warp MAP_AZALEA_TOWN_KURTS_HOUSE, 15, 4
	release
	end

SlowpokeWell_B1F_Movement_Kurt:
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	step_end

SlowpokeWell_B1F_Text_KurtIntro:
	.string "FARGAS : Salut, {PLAYER} !\p"
	.string "Le garde en haut s'est enfui\n"
	.string "quand je lui ai crié dessus.\p"
	.string "Mais ensuite, j'ai fait une chute\n"
	.string "dans le PUITS RAMOLOSS.\p"
	.string "Je suis tombé violemment sur le dos,\n"
	.string "je ne peux plus bouger.\p"
	.string "Zut ! Si j'étais en forme, mes POKéMON\n"
	.string "leur auraient donné une leçon…\p"
	.string "Ah, tant pis.\p"
	.string "{PLAYER}, montre-leur de quoi tu es\n"
	.string "capable à ma place !$"

SlowpokeWell_B1F_Text_KurtAfter:
	.string "FARGAS : Bravo, {PLAYER} !\p"
	.string "La TEAM ROCKET s'est enfuie.\p"
	.string "Mon dos va mieux aussi.\n"
	.string "Sortons d'ici.$"

SlowpokeWell_B1F_Text_GruntM29Seen:
	.string "Zut ! Je montais la garde en haut\n"
	.string "quand un vieux fou m'a crié dessus.\l"
	.string "\p"
	.string "Il m'a tellement surpris que\n"
	.string "je suis tombé ici.\p"
	.string "Je vais passer mes nerfs sur toi !$"

SlowpokeWell_B1F_Text_GruntM29Beaten:
	.string "Argh ! C'est vraiment pas mon jour !$"

SlowpokeWell_B1F_Text_GruntM29After:
	.string "Ouais, on coupe les QUEUES des\n"
	.string "RAMOLOSS et on les vend.\l"
	.string "\p"
	.string "Tout ce qu'on fait, c'est pour le profit.\p"
	.string "C'est ça ! On est la TEAM ROCKET,\n"
	.string "et on ferait tout pour de l'argent !$"

SlowpokeWell_B1F_Text_ProtonSeen:
	.string "Qu'est-ce que tu veux ?\p"
	.string "Si tu déranges notre travail,\n"
	.string "n'attends aucune pitié !$"

SlowpokeWell_B1F_Text_ProtonBeaten:
	.string "Tu t'es bien débrouillé aujourd'hui,\n"
	.string "mais attends la prochaine fois !$"

SlowpokeWell_B1F_Text_ProtonAfter:
	.string "Ouais, la TEAM ROCKET a été dissoute\n"
	.string "il y a trois ans.\p"
	.string "Le boss s'est caché.\p"
	.string "Mais on a continué nos activités\n"
	.string "dans l'ombre !\p"
	.string "Un petit obstacle comme toi ne sera\n"
	.string "pas un problème pour notre mission.\p"
	.string "Je te conseille d'avoir très peur de\n"
	.string "ce qui va arriver !$"

SlowpokeWell_B1F_Text_GruntM2Seen:
	.string "Héhéhé !\n"
	.string "Arrêter de prendre des QUEUES DE RAMOLOSS ?\p"
	.string "T'es fou !\n"
	.string "Si on t'écoutait, la réputation de la\l"
	.string "TEAM ROCKET serait ruinée !$"

SlowpokeWell_B1F_Text_GruntM2Beaten:
	.string "Hé…\n"
	.string "Trop fort…$"

SlowpokeWell_B1F_Text_GruntM2After:
	.string "On a besoin d'argent,\n"
	.string "mais vendre des QUEUES DE RAMOLOSS ?\p"
	.string "C'est dur d'être un SBIRE ROCKET !$"

SlowpokeWell_B1F_Text_GruntF1Seen:
	.string "Arrêter de prendre des QUEUES ?\p"
	.string "Ouais, essaie donc de tous\n"
	.string "nous battre !$"

SlowpokeWell_B1F_Text_GruntF1Beaten:
	.string "Espèce de sale gosse !$"

SlowpokeWell_B1F_Text_GruntF1After:
	.string "Les QUEUES DE RAMOLOSS repoussent vite !\p"
	.string "Qu'est-ce qu'il y a de mal à les vendre ?$"

SlowpokeWell_B1F_Text_SlowpokeWithMail:
	.string "Un RAMOLOSS avec la QUEUE coupée…\p"
	.string "Hein ? Il a du COURRIER.\n"
	.string "Lire ?$"

SlowpokeWell_B1F_Text_SlowpokeMail:
	.string "{PLAYER} lit le COURRIER.\p"
	.string "Sois sage et veille sur la maison\n"
	.string "avec Papi et RAMOLOSS.\p"
	.string "Papa qui t'aime$"

SlowpokeWell_B1F_Text_TaillessSlowpoke:
	.string "Un RAMOLOSS avec la QUEUE coupée…$"
