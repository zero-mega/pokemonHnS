.set LOCALID_MATT, 1
.set LOCALID_SUBMARINE, 4

AquaHideout_B2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, AquaHideout_B2F_OnTransition
	.byte 0

AquaHideout_B2F_OnTransition:
	call_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, AquaHideout_B2F_EventScript_PreventMattNoticing
	end

AquaHideout_B2F_EventScript_PreventMattNoticing::
	setvar VAR_TEMP_1, 1
	return

AquaHideout_B2F_EventScript_MattNoticePlayer::
	lockall
	setvar VAR_0x8008, LOCALID_MATT
	playse SE_PIN
	applymovement VAR_0x8008, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_0x8008, Common_Movement_FacePlayer
	waitmovement 0
	setvar VAR_TEMP_1, 1
	releaseall
	end

AquaHideout_B2F_EventScript_Matt::
	trainerbattle_single TRAINER_MATT, AquaHideout_B2F_Text_MattIntro, AquaHideout_B2F_Text_MattDefeat, AquaHideout_B2F_EventScript_SubmarineEscape
	msgbox AquaHideout_B2F_Text_MattPostBattle, MSGBOX_DEFAULT
	release
	end

AquaHideout_B2F_EventScript_SubmarineEscape::
	setvar VAR_0x8008, LOCALID_MATT
	setvar VAR_0x8009, LOCALID_SUBMARINE
	applymovement VAR_0x8008, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	delay 20
	applymovement VAR_0x8008, Common_Movement_FacePlayer
	waitmovement 0
	msgbox AquaHideout_B2F_Text_OurBossGotThroughHisPreparations, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_0x8008, Common_Movement_WalkInPlaceFasterLeft
	applymovement VAR_0x8009, AquaHideout_B2F_Movement_SumbarineDepartLeft
	waitmovement 0
	removeobject VAR_0x8009
	delay 20
	applymovement VAR_0x8008, Common_Movement_FacePlayer
	waitmovement 0
	msgbox AquaHideout_B2F_Text_MattPostBattle, MSGBOX_DEFAULT
	setflag FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE
	setflag FLAG_GARBAGEFLAG
	release
	end

AquaHideout_B2F_Movement_SumbarineDepartLeft:
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

@ Unused
AquaHideout_B2F_Movement_SumbarineDepartRight:
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

AquaHideout_B2F_EventScript_Grunt4::
	trainerbattle_single TRAINER_SETH, AquaHideout_B2F_Text_Grunt4Intro, AquaHideout_B2F_Text_Grunt4Defeat, AquaHideout_B2F_EventScript_Grunt4Defeated
	msgbox AquaHideout_B2F_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B2F_EventScript_Grunt4Defeated::
	msgbox AquaHideout_B2F_Text_Grunt4PostBattle, MSGBOX_DEFAULT
	release
	end

AquaHideout_B2F_EventScript_Grunt6::
	trainerbattle_single TRAINER_STANLY, AquaHideout_B2F_Text_Grunt6Intro, AquaHideout_B2F_Text_Grunt6Defeat
	msgbox AquaHideout_B2F_Text_Grunt6PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B2F_EventScript_Grunt8::
	trainerbattle_single TRAINER_STEVE, AquaHideout_B2F_Text_Grunt8Intro, AquaHideout_B2F_Text_Grunt8Defeat
	msgbox AquaHideout_B2F_Text_Grunt8PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B2F_Text_MattIntro:
	.string "Héhéhé…\p"
	.string "Déjà arrivé, hein ?\n"
	.string "On t'a sous-estimé !\p"
	.string "Mais c'est la fin !\p"
	.string "Je suis d'un tout autre niveau que les\n"
	.string "SBIRRES que tu as vus jusqu'ici.\p"
	.string "Je ne fais pas que gagner du temps.\n"
	.string "Je vais t'écraser !$"

AquaHideout_B2F_Text_MattDefeat:
	.string "Héhéhé…\n"
	.string "Alors, moi aussi j'ai perdu…$"

AquaHideout_B2F_Text_OurBossGotThroughHisPreparations:
	.string "Héhéhé !\p"
	.string "Pendant que je te faisais perdre ton temps,\n"
	.string "notre BOSS a terminé ses préparatifs !$"

AquaHideout_B2F_Text_MattPostBattle:
	.string "Héhéhé !\p"
	.string "Notre BOSS est déjà parti vers une\n"
	.string "grotte sous la mer !\p"
	.string "Si tu veux le poursuivre, tu ferais mieux\n"
	.string "de chercher dans la vaste mer au-delà de\l"
	.string "NATURAMA.\p"
	.string "Mais arriveras-tu à la trouver ?\n"
	.string "Héhéhé !$"

AquaHideout_B2F_Text_Grunt4Intro:
	.string "Wahahah, j'en avais marre d'attendre !\n"
	.string "Tu me dois aussi un combat !$"

AquaHideout_B2F_Text_Grunt4Defeat:
	.string "Fatigué d'attendre…\n"
	.string "Perdu et sonné…$"

AquaHideout_B2F_Text_Grunt4PostBattle:
	.string "BOSS…\n"
	.string "Est-ce que ça suffit ?$"

AquaHideout_B2F_Text_Grunt6Intro:
	.string "Les panneaux de téléportation, la fierté\n"
	.string "et la joie du REPÈRE !\p"
	.string "Tu ne sais même pas où tu es,\n"
	.string "pas vrai ?\p"
	.string "Dérouter et épuiser l'ennemi, puis\n"
	.string "frapper fort ! Voilà notre plan !$"

AquaHideout_B2F_Text_Grunt6Defeat:
	.string "Qu'est-ce qui ne va pas chez toi ?\n"
	.string "Tu n'es même pas fatigué !$"

AquaHideout_B2F_Text_Grunt6PostBattle:
	.string "Ça me rappelle… Je ne sais plus où\n"
	.string "j'ai mis la MASTER BALL.\p"
	.string "Si je ne la surveille pas, notre BOSS va\n"
	.string "me passer un savon…$"

AquaHideout_B2F_Text_Grunt8Intro:
	.string "Quand j'ai rejoint la TEAM AQUA, la\n"
	.string "première chose à apprendre, c'était\l"
	.string "comment ces panneaux étaient reliés !$"

AquaHideout_B2F_Text_Grunt8Defeat:
	.string "J'étais trop occupé à penser aux\n"
	.string "panneaux de téléportation…$"

AquaHideout_B2F_Text_Grunt8PostBattle:
	.string "Il va falloir que j'apprenne à mieux\n"
	.string "me battre…$"
