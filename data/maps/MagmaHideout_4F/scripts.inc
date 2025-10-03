.set LOCALID_GROUDON, 1
.set LOCALID_GRUNT_1, 2
.set LOCALID_GRUNT_2, 3
.set LOCALID_GRUNT_3, 4
.set LOCALID_TABITHA, 5
.set LOCALID_MAXIE, 6
.set LOCALID_GROUDON_SLEEPING, 7

MagmaHideout_4F_MapScripts::
	.byte 0

MagmaHideout_4F_EventScript_Maxie::
	lockall
	playbgm MUS_ENCOUNTER_MAGMA, FALSE
	msgbox MagmaHideout_4F_Text_MaxieAwakenGroudon, MSGBOX_DEFAULT
	closemessage
	delay 20
	setvar VAR_RESULT, 1
	playse SE_M_DETECT
	dofieldeffectsparkle 18, 42, 0
	waitfieldeffect FLDEFF_SPARKLE
	setvar VAR_RESULT, 1
	playfanfare MUS_AWAKEN_LEGEND
	playse SE_ORB
	special DoOrbEffect
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 150
	removeobject LOCALID_GROUDON_SLEEPING
	addobject LOCALID_GROUDON
	waitstate
	delay 60
	applymovement LOCALID_GROUDON, MagmaHideout_4F_Movement_GroudonApproach
	waitmovement 0
	special FadeOutOrbEffect
	waitstate
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	applymovement LOCALID_GROUDON, MagmaHideout_4F_Movement_GroudonExit
	waitmovement 0
	removeobject LOCALID_GROUDON
	delay 4
	setvar VAR_0x8004, 2  @ vertical pan
	setvar VAR_0x8005, 2  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	delay 30
	applymovement LOCALID_MAXIE, MagmaHideout_4F_Movement_MaxieLookAround
	waitmovement 0
	msgbox MagmaHideout_4F_Text_MaxieGroudonWhatsWrong, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 30
	applymovement LOCALID_MAXIE, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MagmaHideout_4F_Text_MaxieOhItWasYou, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_MAXIE_MAGMA_HIDEOUT, MagmaHideout_4F_Text_MaxieDefeat
	msgbox MagmaHideout_4F_Text_MaxieImGoingAfterGroudon, MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_GARBAGEFLAG
	clearflag FLAG_GARBAGEFLAG
	setvar VAR_GARBAGEVAR, 1
	setflag FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT
	setvar VAR_SLATEPORT_HARBOR_STATE, 1
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_MAXIE
	removeobject LOCALID_GRUNT_1
	removeobject LOCALID_GRUNT_2
	removeobject LOCALID_GRUNT_3
	removeobject LOCALID_TABITHA
	setflag FLAG_GARBAGEFLAG
	fadescreen FADE_FROM_BLACK
	releaseall
	end

MagmaHideout_4F_Movement_GroudonApproach:
	delay_16
	delay_16
	walk_slow_down
	delay_16
	delay_16
	delay_16
	walk_slow_down
	delay_16
	delay_16
	delay_16
	step_end

MagmaHideout_4F_Movement_GroudonExit:
	slide_up
	slide_up
	step_end

MagmaHideout_4F_Movement_MaxieLookAround:
	face_left
	delay_16
	face_right
	delay_16
	face_left
	delay_16
	face_right
	delay_16
	face_up
	delay_16
	delay_16
	step_end

MagmaHideout_4F_EventScript_Grunt11::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_11, MagmaHideout_4F_Text_Grunt11Intro, MagmaHideout_4F_Text_Grunt11Defeat
	msgbox MagmaHideout_4F_Text_Grunt11PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_EventScript_Grunt12::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_12, MagmaHideout_4F_Text_Grunt12Intro, MagmaHideout_4F_Text_Grunt12Defeat
	msgbox MagmaHideout_4F_Text_Grunt12PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_EventScript_Grunt13::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_13, MagmaHideout_4F_Text_Grunt13Intro, MagmaHideout_4F_Text_Grunt13Defeat
	msgbox MagmaHideout_4F_Text_Grunt13PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_EventScript_Tabitha::
	trainerbattle_single TRAINER_TABITHA_MAGMA_HIDEOUT, MagmaHideout_4F_Text_TabithaIntro, MagmaHideout_4F_Text_TabithaDefeat
	msgbox MagmaHideout_4F_Text_TabithaPostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_Text_Grunt11Intro:
	.string "Je veux voir GROUDON moi aussi, mais ils\n"
	.string "ne me laissent même pas voir sa queue…\p"
	.string "Ça me rend vraiment frustré.\p"
	.string "Oh, non !\n"
	.string "J'ai parlé de GROUDON sans faire exprès !$"

MagmaHideout_4F_Text_Grunt11Defeat:
	.string "Je suppose qu'il est impossible de gagner\n"
	.string "si on n'a pas l'esprit calme…$"

MagmaHideout_4F_Text_Grunt11PostBattle:
	.string "Je me demande si GROUDON a vraiment une queue ?$"

MagmaHideout_4F_Text_Grunt12Intro:
	.string "Fuhahaha !\n"
	.string "Bientôt ! Très bientôt !\l"
	.string "Notre grand objectif sera atteint !$"

MagmaHideout_4F_Text_Grunt12Defeat:
	.string "Grrr…\n"
	.string "Je suis allé si loin, et maintenant ça ?$"

MagmaHideout_4F_Text_Grunt12PostBattle:
	.string "MAX, monsieur !\n"
	.string "Un intrus se dirige vers vous !$"

MagmaHideout_4F_Text_Grunt13Intro:
	.string "Ce n'est pas encore fini !\n"
	.string "Tu ne passeras pas si facilement !$"

MagmaHideout_4F_Text_Grunt13Defeat:
	.string "J'étais si facile à battre que ça ?$"

MagmaHideout_4F_Text_Grunt13PostBattle:
	.string "A-allez, encore un combat…$"

MagmaHideout_4F_Text_TabithaIntro:
	.string "Hehehe !\n"
	.string "Tu es arrivé jusqu'ici, alors je vais te dire !\p"
	.string "C'est vrai !\n"
	.string "Juste devant, GROUDON dort !\p"
	.string "MAXIE est allé voir GROUDON il y a\n"
	.string "quelques secondes à peine !\p"
	.string "Il va bientôt se réveiller !\n"
	.string "Hehe ! Hehehe !$"

MagmaHideout_4F_Text_TabithaDefeat:
	.string "Encore battu…\n"
	.string "Hehe…$"

MagmaHideout_4F_Text_TabithaPostBattle:
	.string "…Et pendant que tu perdais du temps avec moi,\n"
	.string "MAXIE a sûrement réveillé GROUDON…$"

MagmaHideout_4F_Text_MaxieAwakenGroudon:
	.string "MAXIE : GROUDON…\p"
	.string "Rien ne pouvait te réveiller de ton\n"
	.string "sommeil baigné dans le magma…\p"
	.string "C'est l'ORBE BLEU que tu cherchais.\n"
	.string "N'est-ce pas ?\p"
	.string "Je t'ai apporté l'ORBE BLEU.\n"
	.string "Que sa lumière t'éveille !\p"
	.string "Et montre-moi…\n"
	.string "Montre-moi toute l'étendue de ta puissance !$"

MagmaHideout_4F_Text_MaxieGroudonWhatsWrong:
	.string "MAXIE : GROUDON !\n"
	.string "Qu'est-ce qui ne va pas ?\p"
	.string "L'ORBE BLEU n'était-il pas la clé ?\p"
	.string "GROUDON !\n"
	.string "Où es-tu passé…$"

MagmaHideout_4F_Text_MaxieOhItWasYou:
	.string "MAXIE : Oh, c'était donc toi ?\p"
	.string "Je t'ai vu rôder ici et là sans invitation…\p"
	.string "Je comprends maintenant !\n"
	.string "Tu as dû faire un sale coup !$"

MagmaHideout_4F_Text_MaxieDefeat:
	.string "Comment fais-tu pour si bien gérer\n"
	.string "les POKéMON ?$"

MagmaHideout_4F_Text_MaxieImGoingAfterGroudon:
	.string "MAXIE : Il doit bien y avoir une raison\n"
	.string "pour laquelle GROUDON s'est enfui…\p"
	.string "C'est ce que tu essaies de dire,\n"
	.string "n'est-ce pas ?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "Humph…\n"
	.string "Tu crois que je ne le savais pas ?\p"
	.string "Avec GROUDON parti, ce volcan n'a plus\n"
	.string "aucune utilité.\p"
	.string "Je pars à la poursuite de GROUDON, alors\n"
	.string "c'est ici que nos chemins se séparent !$"
