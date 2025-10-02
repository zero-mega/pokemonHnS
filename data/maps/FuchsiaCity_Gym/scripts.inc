.set LOCALID_FUCHSIAGYM_JANINE, 5
.set LOCALID_FUCHSIAGYM_ALICE_J, 1
.set LOCALID_FUCHSIAGYM_LINDA_J, 2
.set LOCALID_FUCHSIAGYM_CINDY_J, 3
.set LOCALID_FUCHSIAGYM_BARRY_J, 4

.set LOCALID_FUCHSIAGYM_ALICE, 7
.set LOCALID_FUCHSIAGYM_LINDA, 8
.set LOCALID_FUCHSIAGYM_CINDY, 9
.set LOCALID_FUCHSIAGYM_BARRY, 10

FuchsiaCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FuchsiaCity_Gym_OnTransition
	.byte 0

FuchsiaCity_Gym_OnTransition::
	goto_if_set FLAG_DEFEATED_FUCHSIA_GYM, FuchsiaCity_Gym_OnTransitionAfter
	setflag FLAG_TEMP_1
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	setflag FLAG_TEMP_7
	call_if_defeated TRAINER_ALICE, FuchsiaCity_Gym_DefeatedAlice
	call_if_defeated TRAINER_LINDA, FuchsiaCity_Gym_DefeatedLinda
	call_if_defeated TRAINER_CINDY, FuchsiaCity_Gym_DefeatedCindy
	call_if_defeated TRAINER_BARRY, FuchsiaCity_Gym_DefeatedBarry
	end

FuchsiaCity_Gym_OnTransitionAfter::
	setflag FLAG_TEMP_2
	setflag FLAG_TEMP_4
	setflag FLAG_TEMP_6
	setflag FLAG_TEMP_8
	end

FuchsiaCity_Gym_DefeatedAlice::
	setflag FLAG_TEMP_2
	clearflag FLAG_TEMP_1
	return

FuchsiaCity_Gym_DefeatedLinda::
	setflag FLAG_TEMP_4
	clearflag FLAG_TEMP_3
	return

FuchsiaCity_Gym_DefeatedCindy::
	setflag FLAG_TEMP_6
	clearflag FLAG_TEMP_5
	return

FuchsiaCity_Gym_DefeatedBarry::
	setflag FLAG_TEMP_8
	clearflag FLAG_TEMP_7
	return

FuchsiaCity_Gym_EventScript_Janine::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_FUCHSIA_GYM, FuchsiaCity_Gym_EventScript_Janine_Defeated
	msgbox FuchsiaCity_Gym_Text_Janine_DisappointYou, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_JANINE, FuchsiaCity_Gym_Text_Janine_ToughOne
	message FuchsiaCity_Gym_Text_ReceivedSoulBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox FuchsiaCity_Gym_Text_Janine_ToxicSpeech, MSGBOX_DEFAULT
	giveitem ITEM_TM_TOXIC
	setflag FLAG_BADGE14_GET
	setflag FLAG_DEFEATED_FUCHSIA_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 14
	call Common_EventScript_SetGymTrainers
	removeobject LOCALID_FUCHSIAGYM_ALICE_J
	removeobject LOCALID_FUCHSIAGYM_CINDY_J
	removeobject LOCALID_FUCHSIAGYM_LINDA_J
	removeobject LOCALID_FUCHSIAGYM_BARRY_J
	setflag FLAG_TEMP_2
	setflag FLAG_TEMP_4
	setflag FLAG_TEMP_6
	setflag FLAG_TEMP_8
	addobject LOCALID_FUCHSIAGYM_ALICE
	addobject LOCALID_FUCHSIAGYM_CINDY
	addobject LOCALID_FUCHSIAGYM_LINDA
	addobject LOCALID_FUCHSIAGYM_BARRY
	clearflag FLAG_TEMP_1
	clearflag FLAG_TEMP_3
	clearflag FLAG_TEMP_5
	clearflag FLAG_TEMP_7
	clearflag FLAG_HIDE_ROUTE22_JANINE
	closemessage
	release
	end

FuchsiaCity_Gym_EventScript_Janine_Defeated::
	msgbox FuchsiaCity_Gym_Text_Janine_ApplyMyself, MSGBOX_DEFAULT
	closemessage
	release
	end

FuchsiaCity_Gym_Text_Janine_DisappointYou:
	.string "Fufufufu…\p"
	.string "Je suis désolée de te décevoir…\p"
	.string "Je plaisante !\p"
	.string "Je suis la vraie !\p"
	.string "JANINE de l'ARÈNE DE PARMANIE, c'est moi !$"

FuchsiaCity_Gym_Text_Janine_ToughOne:
	.string "JANINE : Tu es vraiment fort. Tu as\n"
	.string "vraiment gagné…\p"
	.string "Voici le BADGE ÂME. Prends-le.$"

FuchsiaCity_Gym_Text_ReceivedSoulBadge:
	.string "{PLAYER} a reçu le BADGE ÂME.$"

FuchsiaCity_Gym_Text_Janine_ToxicSpeech:
	.string "JANINE : Tu es si fort ! J'ai un\n"
	.string "cadeau spécial !\p"
	.string "C'est TOXIK, un poison puissant qui\n"
	.string "draine peu à peu les PV de la victime.$"

FuchsiaCity_Gym_Text_Janine_ApplyMyself:
	.string "JANINE : Je vais vraiment m'appliquer\n"
	.string "et améliorer mes compétences.\p"
	.string "Je veux devenir meilleure que mon père\n"
	.string "et que toi !$"

FuchsiaCity_Gym_EventScript_Alice_J::
	lock
	faceplayer
	msgbox FuchsiaCity_PokemonCenter1F_Text_JanineImpersonator1, MSGBOX_DEFAULT
	applymovement LOCALID_FUCHSIAGYM_ALICE_J, GoldenrodCity_RadioTower_5F_Movement_Spin
	waitmovement 0
	removeobject LOCALID_FUCHSIAGYM_ALICE_J
	clearflag FLAG_TEMP_1
	addobject LOCALID_FUCHSIAGYM_ALICE
	applymovement LOCALID_FUCHSIAGYM_ALICE, GoldenrodCity_RadioTower_5F_Movement_Spin2
	waitmovement 0
	applymovement LOCALID_FUCHSIAGYM_ALICE, Common_Movement_FacePlayer
	waitmovement 0
	msgbox FuchsiaCity_Gym_Text_LassAlice_Before, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_ALICE, FuchsiaCity_Gym_Text_LassAlice_Beaten
	msgbox FuchsiaCity_Gym_Text_LassAlice_After, MSGBOX_DEFAULT
	closemessage
	release
	end

FuchsiaCity_Gym_EventScript_Alice::
	msgbox FuchsiaCity_Gym_Text_LassAlice_After, MSGBOX_NPC
	end


FuchsiaCity_Gym_EventScript_Linda_J::
	lock
	faceplayer
	msgbox FuchsiaCity_PokemonCenter1F_Text_JanineImpersonator1, MSGBOX_DEFAULT
	applymovement LOCALID_FUCHSIAGYM_LINDA_J, GoldenrodCity_RadioTower_5F_Movement_Spin
	waitmovement 0
	removeobject LOCALID_FUCHSIAGYM_LINDA_J
	clearflag FLAG_TEMP_3
	addobject LOCALID_FUCHSIAGYM_LINDA
	applymovement LOCALID_FUCHSIAGYM_LINDA, GoldenrodCity_RadioTower_5F_Movement_Spin2
	waitmovement 0
	applymovement LOCALID_FUCHSIAGYM_LINDA, Common_Movement_FacePlayer
	waitmovement 0
	msgbox FuchsiaCity_Gym_Text_LassLinda_Before, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_LINDA, FuchsiaCity_Gym_Text_LassLinda_Beaten
	msgbox FuchsiaCity_Gym_Text_LassLinda_After, MSGBOX_DEFAULT
	closemessage
	release
	end

FuchsiaCity_Gym_EventScript_Linda::
	msgbox FuchsiaCity_Gym_Text_LassLinda_After, MSGBOX_NPC
	end

FuchsiaCity_Gym_EventScript_Cindy_J::
	lock
	faceplayer
	msgbox FuchsiaCity_PokemonCenter1F_Text_JanineImpersonator1, MSGBOX_DEFAULT
	applymovement LOCALID_FUCHSIAGYM_CINDY_J, GoldenrodCity_RadioTower_5F_Movement_Spin
	waitmovement 0
	removeobject LOCALID_FUCHSIAGYM_CINDY_J
	clearflag FLAG_TEMP_5
	addobject LOCALID_FUCHSIAGYM_CINDY
	applymovement LOCALID_FUCHSIAGYM_CINDY, GoldenrodCity_RadioTower_5F_Movement_Spin2
	waitmovement 0
	applymovement LOCALID_FUCHSIAGYM_CINDY, Common_Movement_FacePlayer
	waitmovement 0
	msgbox FuchsiaCity_Gym_Text_PicnickerCindy_Before, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_CINDY, FuchsiaCity_Gym_Text_PicnickerCindy_Beaten
	msgbox FuchsiaCity_Gym_Text_PicnickerCindy_After, MSGBOX_DEFAULT
	closemessage
	release
	end

FuchsiaCity_Gym_EventScript_Cindy::
	msgbox FuchsiaCity_Gym_Text_PicnickerCindy_After, MSGBOX_NPC
	end

FuchsiaCity_Gym_EventScript_Barry_J::
	lock
	faceplayer
	msgbox FuchsiaCity_PokemonCenter1F_Text_JanineImpersonator1, MSGBOX_DEFAULT
	applymovement LOCALID_FUCHSIAGYM_BARRY_J, GoldenrodCity_RadioTower_5F_Movement_Spin
	waitmovement 0
	removeobject LOCALID_FUCHSIAGYM_BARRY_J
	clearflag FLAG_TEMP_7
	addobject LOCALID_FUCHSIAGYM_BARRY
	applymovement LOCALID_FUCHSIAGYM_BARRY, GoldenrodCity_RadioTower_5F_Movement_Spin2
	waitmovement 0
	applymovement LOCALID_FUCHSIAGYM_BARRY, Common_Movement_FacePlayer
	waitmovement 0
	msgbox FuchsiaCity_Gym_Text_CamperBarry_Before, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_BARRY, FuchsiaCity_Gym_Text_CamperBarry_Beaten
	msgbox FuchsiaCity_Gym_Text_CamperBarry_After, MSGBOX_DEFAULT
	closemessage
	release
	end

FuchsiaCity_Gym_EventScript_Barry::
	msgbox FuchsiaCity_Gym_Text_CamperBarry_After, MSGBOX_NPC
	end

FuchsiaCity_Gym_Text_LassAlice_Before:
	.string "Fufufu !\p"
	.string "Je suis JANINE, la CHAMPIONNE d'ARÈNE !\p"
	.string "Non, ce n'est pas vrai ! Je t'ai eu !$"

FuchsiaCity_Gym_Text_LassAlice_Beaten:
	.string "Je t'ai bien eu…$"

FuchsiaCity_Gym_Text_LassAlice_After:
	.string "Comment vas-tu reconnaître notre\n"
	.string "vraie CHAMPIONNE ?$"

FuchsiaCity_Gym_Text_LassLinda_Before:
	.string "Je t'ai trompé ! Hahaha !$"

FuchsiaCity_Gym_Text_LassLinda_Beaten:
	.string "Ooh… J'ai perdu… Tu n'es pas faible…$"

FuchsiaCity_Gym_Text_LassLinda_After:
	.string "Alors ? Mon déguisement n'était-il\n"
	.string "pas parfait ?$"

FuchsiaCity_Gym_Text_PicnickerCindy_Before:
	.string "Je suis JANINE !\p"
	.string "Comment as-tu su que j'étais la vraie ?\p"
	.string "Allons nous battre !$"

FuchsiaCity_Gym_Text_PicnickerCindy_Beaten:
	.string "Zut ! Je voulais gagner !$"

FuchsiaCity_Gym_Text_PicnickerCindy_After:
	.string "Tu dois commencer à fatiguer.$"

FuchsiaCity_Gym_Text_CamperBarry_Before:
	.string "Wahahaha !\p"
	.string "Bien sûr ! Je suis JANINE !$"

FuchsiaCity_Gym_Text_CamperBarry_Beaten:
	.string "Mon déguisement était parfait ! Mince !$"

FuchsiaCity_Gym_Text_CamperBarry_After:
	.string "Hé, toi. Mon déguisement était mignon\n"
	.string "ou pas, hein ?$"

FuchsiaCity_Gym_EventScript_GymGuy::
	goto_if_set FLAG_DEFEATED_FUCHSIA_GYM, FuchsiaCity_Gym_EventScript_GymGuyAfter
	msgbox FuchsiaCity_Gym_Text_Guide, MSGBOX_NPC
	end

FuchsiaCity_Gym_EventScript_GymGuyAfter::
	msgbox FuchsiaCity_Gym_Text_GuideWin, MSGBOX_NPC
	end

FuchsiaCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_DEFEATED_FUCHSIA_GYM, FuchsiaCity_Gym_EventScript_GymStatuePostVictory
	msgbox FuchsiaCity_Gym_Text_GymStatue
	releaseall
	end

FuchsiaCity_Gym_EventScript_GymStatuePostVictory::
	msgbox FuchsiaCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end

FuchsiaCity_Gym_Text_GymStatue::
    .string "ARÈNE POKéMON DE PARMANIE\n"
    .string "CHAMPIONNE : JEANNINE\p"
    .string "DRESSEURS VICTORIEUX :\n"
    .string "BLUE, RED$"

FuchsiaCity_Gym_Text_GymStatuePlayerWon::
    .string "ARÈNE POKéMON DE PARMANIE\n"
    .string "CHAMPIONNE : JEANNINE\p"
    .string "DRESSEURS VICTORIEUX :\n"
    .string "BLUE, RED, {PLAYER}$"

FuchsiaCity_Gym_Text_Guide:
	.string "Yo, CHAMPION en herbe !\p"
	.string "Oups ! Regarde bien autour de toi.\p"
	.string "Tous les DRESSEURS ressemblent à la\n"
	.string "CHAMPIONNE, JEANNINE.\p"
	.string "Laquelle est la vraie JEANNINE ?$"

FuchsiaCity_Gym_Text_GuideWin:
	.string "C'était un super combat, DRESSEUR\n"
	.string "de JOHTO !$"
