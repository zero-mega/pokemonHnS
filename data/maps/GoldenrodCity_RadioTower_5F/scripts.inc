.set LOCALID_DIRECTOR_OFFICE, 1
.set LOCALID_GOLDENROD_ARCHER, 2
.set LOCALID_GOLDENROD_ARIANA, 3
.set LOCALID_PETREL_OFFICE, 4
.set LOCALID_DIRECTOR_STUDIO, 5

GoldenrodCity_RadioTower_5F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, GoldenrodCity_RadioTower_5F_OnLoad
	.byte 0

GoldenrodCity_RadioTower_5F_OnLoad::
	call_if_eq VAR_GOLDENROD_CITY_STATE, 6, GoldenrodCity_RadioTower_5F_MapScript_HidePetrel
	end

GoldenrodCity_RadioTower_5F_MapScript_HidePetrel::
	clearflag FLAG_HIDE_GOLDENROD_RADIOTOWER_DIRECTOR
	setflag FLAG_HIDE_GOLDENROD_RADIOTOWER_PETREL
	return


@=======[OFFICE]==============================================================================================================================

GoldenrodCity_RadioTower_5F_EventScript_Petrel::
	lock
	goto_if_ge VAR_GOLDENROD_CITY_STATE, 10, GoldenrodCity_RadioTower_5F_EventScript_Director
	goto_if_eq VAR_FACING, DIR_SOUTH, GoldenrodCity_RadioTower_5F_EventScript_PetrelNorth
	faceplayer
	msgbox GoldenrodCity_RadioTower_5F_Text_FakeDirector1, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DIRECTOR_OFFICE, GoldenrodCity_RadioTower_5F_Movement_Spin
	waitmovement 0
	setflag FLAG_HIDE_GOLDENROD_RADIOTOWER_DIRECTOR
	removeobject LOCALID_DIRECTOR_OFFICE
	clearflag FLAG_HIDE_GOLDENROD_RADIOTOWER_PETREL
	addobject LOCALID_PETREL_OFFICE
	applymovement LOCALID_PETREL_OFFICE, GoldenrodCity_RadioTower_5F_Movement_Spin2
	waitmovement 0
	msgbox GoldenrodCity_RadioTower_5F_Text_FakeDirector2, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_PETREL_2, GoldenrodCity_RadioTower_5F_Text_FakeDirectorWin
	msgbox GoldenrodCity_RadioTower_5F_Text_FakeDirectorAfter, MSGBOX_DEFAULT
	giveitem ITEM_BASEMENT_KEY
	setvar VAR_GOLDENROD_CITY_STATE, 7
	clearflag FLAG_HIDE_GOLDENROD_UNDERGROUND_KIMONO
	closemessage
	release
	end

GoldenrodCity_RadioTower_5F_EventScript_PetrelNorth::
	end

GoldenrodCity_RadioTower_5F_EventScript_Petrel2::
	lock
	faceplayer
	msgbox GoldenrodCity_RadioTower_5F_Text_FakeDirectorAfter2, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_5F_EventScript_Director::
	lock
	faceplayer
	msgbox GoldenrodCity_RadioTower_5F_Text_DirectorIntro, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_5F_Movement_Spin:
	face_right
	delay_8
	face_up
	delay_8
	face_left
	delay_8
	face_down
	delay_8
	face_right
	delay_4
	face_up
	delay_4
	face_left
	delay_4
	face_down
	delay_4
	face_right
	delay_2
	face_up
	delay_2
	face_left
	delay_2
	face_down
	step_end


GoldenrodCity_RadioTower_5F_Movement_Spin2:
	face_right
	delay_2
	face_up
	delay_2
	face_left
	delay_2
	face_down
	step_end


GoldenrodCity_RadioTower_5F_Text_FakeDirector1:
	.string "T-t-toi ! Tu es venu me sauver ?$"

GoldenrodCity_RadioTower_5F_Text_FakeDirector2:
	.string "C'est ce à quoi tu t'attendais ?\p"
	.string "Raté ! Je suis un imposteur !\p"
	.string "J'ai fait semblant d'être le vrai\n"
	.string "pour préparer notre prise de contrôle.\p"
	.string "Tu veux savoir où nous avons caché\n"
	.string "le vrai DIRECTEUR ?\p"
	.string "Bien sûr, je vais te le dire. Mais\n"
	.string "seulement si tu arrives à me battre !$"

GoldenrodCity_RadioTower_5F_Text_FakeDirectorWin:
	.string "OK, OK. Je vais te dire où il est.$"

GoldenrodCity_RadioTower_5F_Text_FakeDirectorAfter:
	.string "Le boss a caché le DIRECTEUR dans\n"
	.string "l'ENTREPÔT SOUTERRAIN.\p"
	.string "C'est tout au fond du SOUS-SOL.\p"
	.string "Je suis sympa, je vais te donner\n"
	.string "la CLÉ SOUS-SOL pour y accéder.\p"
	.string "Mais je doute que tu ailles bien loin !$"

GoldenrodCity_RadioTower_5F_Text_FakeDirectorAfter2:
	.string "Le boss a caché le DIRECTEUR dans\n"
	.string "l'ENTREPÔT SOUTERRAIN.\p"
	.string "C'est tout au fond du SOUS-SOL.\p"
	.string "Tu peux utiliser la CLÉ SOUS-SOL pour\n"
	.string "accéder à l'ENTREPÔT SOUTERRAIN.\p"
	.string "Mais je doute que tu ailles bien loin !$"

@=======[STUDIO]==============================================================================================================================

GoldenrodCity_RadioTower_5F_EventScript_Ben::
	lock
	faceplayer
	msgbox GoldenrodCity_RadioTower_5F_Text_Ben, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodRaidoTower4_EventScript_ARIANA::
	trainerbattle_single TRAINER_ARIANA_2 GoldenrodCity_RadioTower_5F_Text_ExecutiveF1Seen, GoldenrodCity_RadioTower_5F_Text_ExecutiveF1Beaten
	msgbox GoldenrodCity_RadioTower_5F_Text_ExecutiveF1After, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_RadioTower_5F_EventScript_Archer::
	lock
	faceplayer
	msgbox GoldenrodCity_RadioTower_5F_Text_RocketBossSeen, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_ARCHER, GoldenrodCity_RadioTower_5F_Text_RocketBossBeaten
	msgbox GoldenrodCity_RadioTower_5F_Text_RocketBossAfter, MSGBOX_DEFAULT
	delay 55
	closemessage
	fadescreen FADE_TO_BLACK
	setflag FLAG_HIDE_GOLDENROD_ROCKETS
	playse SE_EXIT
	setvar VAR_GOLDENROD_CITY_STATE, 10
	removeobject LOCALID_GOLDENROD_ARCHER
	removeobject LOCALID_GOLDENROD_ARIANA
	setflag FLAG_HIDE_GOLDENROD_RADIOTOWER_PETREL
	clearflag FLAG_HIDE_GOLDENROD_RADIOTOWER_DIRECTOR
	removeobject LOCALID_PETREL_OFFICE
	addobject LOCALID_DIRECTOR_STUDIO
	playbgm MUS_HG_GOLDENROD, TRUE
	delay 120
	fadescreen FADE_FROM_BLACK
	goto_if_eq VAR_FACING, DIR_SOUTH, GoldenrodCity_RadioTower_5F_EventScript_WingTop
	goto_if_eq VAR_FACING, DIR_WEST, GoldenrodCity_RadioTower_5F_EventScript_WingMid
	goto_if_eq VAR_FACING, DIR_NORTH, GoldenrodCity_RadioTower_5F_EventScript_WingBot
	release
	end

GoldenrodCity_RadioTower_5F_EventScript_WingTop::
	applymovement LOCALID_DIRECTOR_STUDIO, GoldenrodCity_RadioTower_5F_Movement_WalkToPlayerTop
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	msgbox GoldenrodCity_RadioTower_5F_Text_DirectorThanks, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_LUGIA_OR_HOOH, 1,  GoldenrodCity_RadioTower_5F_EventScript_GiveTidalWing
	call_if_eq VAR_LUGIA_OR_HOOH, 2, GoldenrodCity_RadioTower_5F_EventScript_GiveClearWing
	applymovement LOCALID_DIRECTOR_STUDIO, GoldenrodCity_RadioTower_5F_Movement_LeaveTop
	waitmovement 0
	goto GoldenrodCity_RadioTower_5F_Fakeout
	end

GoldenrodCity_RadioTower_5F_EventScript_WingMid::
	applymovement LOCALID_DIRECTOR_STUDIO, GoldenrodCity_RadioTower_5F_Movement_WalkToPlayerMid
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	msgbox GoldenrodCity_RadioTower_5F_Text_DirectorThanks, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_LUGIA_OR_HOOH, 1,  GoldenrodCity_RadioTower_5F_EventScript_GiveTidalWing
	call_if_eq VAR_LUGIA_OR_HOOH, 2, GoldenrodCity_RadioTower_5F_EventScript_GiveClearWing
	applymovement LOCALID_DIRECTOR_STUDIO, GoldenrodCity_RadioTower_5F_Movement_LeaveMid
	waitmovement 0
	goto GoldenrodCity_RadioTower_5F_Fakeout
	end

GoldenrodCity_RadioTower_5F_EventScript_WingBot::
	applymovement LOCALID_DIRECTOR_STUDIO, GoldenrodCity_RadioTower_5F_Movement_WalkToPlayerBot
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	msgbox GoldenrodCity_RadioTower_5F_Text_DirectorThanks, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_LUGIA_OR_HOOH, 1,  GoldenrodCity_RadioTower_5F_EventScript_GiveTidalWing
	call_if_eq VAR_LUGIA_OR_HOOH, 2, GoldenrodCity_RadioTower_5F_EventScript_GiveClearWing
	applymovement LOCALID_DIRECTOR_STUDIO, GoldenrodCity_RadioTower_5F_Movement_LeaveBot
	waitmovement 0
	goto GoldenrodCity_RadioTower_5F_Fakeout
	end

GoldenrodCity_RadioTower_5F_EventScript_GiveTidalWing::
	giveitem ITEM_SILVER_WING
	msgbox GoldenrodCity_RadioTower_5F_Text_DirectorTidalWingExplanation, MSGBOX_DEFAULT
	closemessage
	release
	return

GoldenrodCity_RadioTower_5F_EventScript_GiveClearWing::
	giveitem ITEM_RAINBOW_WING
	msgbox GoldenrodCity_RadioTower_5F_Text_DirectorClearWingExplanation, MSGBOX_DEFAULT
	closemessage
	release
	return

GoldenrodCity_RadioTower_5F_Fakeout::
	playse SE_PIN
	applymovement LOCALID_DIRECTOR_STUDIO, Common_Movement_ExclamationMark
	delay 60
	turnobject LOCALID_DIRECTOR_STUDIO, DIR_WEST
	msgbox GoldenrodCity_RadioTower_5F_Text_DirectorLegendary, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DIRECTOR_STUDIO, GoldenrodCity_RadioTower_5F_Movement_Leave1
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_DIRECTOR_STUDIO, Common_Movement_ExclamationMark
	delay 60
	turnobject LOCALID_DIRECTOR_STUDIO, DIR_SOUTH
	msgbox GoldenrodCity_RadioTower_5F_Text_DirectorFakeout, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DIRECTOR_STUDIO, GoldenrodCity_RadioTower_5F_Movement_Leave2
	waitmovement 0
	setflag FLAG_HIDE_GOLDENROD_RADIOTOWER_DIRECTOR_2
	removeobject LOCALID_DIRECTOR_STUDIO
	setvar VAR_MAHOGANY_TOWN_STATE, 17
	release
	end

GoldenrodCity_RadioTower_5F_EventScript_Trigger_NPCS::
	clearflag FLAG_HIDE_GOLDENROD_NPCS
	setvar VAR_GOLDENROD_CITY_STATE, 11
	end

GoldenrodCity_RadioTower_5F_Movement_WalkToPlayerTop:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	step_end

GoldenrodCity_RadioTower_5F_Movement_LeaveTop:
	walk_right
	walk_right
	walk_right
	step_end

GoldenrodCity_RadioTower_5F_Movement_WalkToPlayerMid:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	step_end


GoldenrodCity_RadioTower_5F_Movement_LeaveMid:
	walk_right
	walk_right
	step_end

GoldenrodCity_RadioTower_5F_Movement_WalkToPlayerBot:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	step_end

GoldenrodCity_RadioTower_5F_Movement_LeaveBot:
	walk_right
	walk_right
	walk_right
	step_end

GoldenrodCity_RadioTower_5F_Movement_Leave1:
	walk_up
	walk_up
	step_end

GoldenrodCity_RadioTower_5F_Movement_Leave2:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

GoldenrodCity_RadioTower_5F_Text_ExecutiveF1Seen:
	.string "Tu te souviens de moi, la CACHETTE de\n"
	.string "ACAJOU ?\p"
	.string "Mon chef m'a grondée, mais je suis plus forte.\p"
	.string "J'ai perdu la dernière fois, mais pas cette fois.$"

GoldenrodCity_RadioTower_5F_Text_ExecutiveF1Beaten:
	.string "Ce n'est pas possible !\p"
	.string "Je me suis battue dur, mais j'ai quand même perdu…\p"
	.string "Je suis tellement désolée, GIOVANNI…$"

GoldenrodCity_RadioTower_5F_Text_ExecutiveF1After:
	.string "{PLAYER}, c'est bien ça ?\p"
	.string "Un morveux comme toi ne peut pas apprécier\n"
	.string "la magnificence de la TEAM ROCKET.\p"
	.string "Dommage. J'admire vraiment\n"
	.string "ta puissance.$"

GoldenrodCity_RadioTower_5F_Text_RocketBossSeen:
	.string "Oh ? Tu as réussi à venir jusqu'ici ?\p"
	.string "Tu dois être un sacré dresseur.\p"
	.string "Nous comptons prendre le contrôle de cette\n"
	.string "STATION RADIO et annoncer notre retour.\p"
	.string "Cela devrait faire revenir notre chef GIOVANNI\n"
	.string "de son entraînement solitaire.\p"
	.string "Nous allons retrouver notre gloire d'antan...\p"
	.string "Je ne te laisserai pas interférer avec\n"
	.string "nos plans méticuleux !$"

GoldenrodCity_RadioTower_5F_Text_RocketBossBeaten:
	.string "Non ! Pardonne-moi, GIOVANNI !$"

GoldenrodCity_RadioTower_5F_Text_RocketBossAfter:
	.string "Comment est-ce possible ?\p"
	.string "Nos rêves sont réduits à néant.\p"
	.string "Je n'étais pas à la hauteur finalement.\p"
	.string "Comme GIOVANNI avant moi, je vais\n"
	.string "dissoudre la TEAM ROCKET aujourd'hui.\p"
	.string "Adieu.$"

GoldenrodCity_RadioTower_5F_Text_DirectorThanks:
	.string "DIRECTEUR : Merci, {PLAYER} !\p"
	.string "Tes actions courageuses ont sauvé\n"
	.string "les POKéMON de tout le pays.\p"
	.string "Je sais que ce n'est pas grand-chose, mais\n"
	.string "prends ceci.$"

GoldenrodCity_RadioTower_5F_Text_DirectorClearWingExplanation:
	.string "Il y avait autrefois une tour ici même\n"
	.string "à DOUBLONVILLE.\p"
	.string "Mais elle était vieille et branlante.\p"
	.string "Alors nous l'avons remplacée par notre\n"
	.string "TOUR RADIO.\p"
	.string "On a trouvé cette aile pendant\n"
	.string "la construction.\p"
	.string "J'ai entendu dire que toutes sortes de POKéMON\n"
	.string "vivaient à DOUBLONVILLE autrefois.\p"
	.string "Peut-être…\p"
	.string "Cette aile a un lien avec la TOUR FER\n"
	.string "à IRISIA…\p"
	.string "Bon, je ferais mieux d'aller à mon BUREAU.$"

GoldenrodCity_RadioTower_5F_Text_DirectorTidalWingExplanation:
	.string "Il y avait autrefois une tour ici même\n"
	.string "à DOUBLONVILLE.\p"
	.string "Mais elle était vieille et branlante.\p"
	.string "Alors nous l'avons remplacée par notre\n"
	.string "TOUR RADIO.\p"
	.string "On a trouvé cette aile pendant\n"
	.string "la construction.\p"
	.string "J'ai entendu dire que toutes sortes de POKéMON\n"
	.string "vivaient à DOUBLONVILLE autrefois.\p"
	.string "Peut-être…\p"
	.string "Cette aile a un lien avec les ILES TOURBILLON\n"
	.string "près d'OLIVILLE…\p"
	.string "Bon, je ferais mieux d'aller à mon BUREAU.$"

GoldenrodCity_RadioTower_5F_Text_DirectorLegendary:
	.string "Ah !\p"
	.string "Ça me rappelle…\p"
	.string "Cette aile que je t'ai donnée... Je crois\n"
	.string "qu'elle est liée au POKéMON\l"
	.string "LÉGENDAIRE.\p"
	.string "Mais ! Le POKéMON LÉGENDAIRE n'apparaîtra\n"
	.string "pas avec seulement cette aile...\p"
	.string "Apparemment, il te faut autre chose...\n"
	.string "Ou quelque chose comme ça.\p"
	.string "Je me demande ce que c'était...\p"
	.string "Je ne m'en souviens plus.$"

GoldenrodCity_RadioTower_5F_Text_DirectorFakeout:
	.string "Tu t'attendais à quelque chose ?\n"
	.string "C'est ce qu'on appelle BLUFF.\p"
	.string "Je dois vraiment retourner à mon bureau\n"
	.string "cette fois. À bientôt !$"

GoldenrodCity_RadioTower_5F_Text_DirectorIntro:
	.string "DIRECTEUR : Bonjour, {PLAYER} !\p"
	.string "Tu sais, j'adore les POKéMON.\p"
	.string "J'ai construit cette TOUR RADIO pour\n"
	.string "pouvoir exprimer mon amour des POKéMON.\p"
	.string "Ce serait bien que les gens apprécient\n"
	.string "nos programmes.$"

GoldenrodCity_RadioTower_5F_Text_Ben:
	.string "BEN : Tu écoutes notre musique ?$"

GoldenrodCity_RadioTower_5F_Text_DirectorOfficeSign:
	.string "5F BUREAU DU DIRECTEUR$"

GoldenrodCity_RadioTower_5F_Text_Studio1Sign:
	.string "5F STUDIO 1$"
