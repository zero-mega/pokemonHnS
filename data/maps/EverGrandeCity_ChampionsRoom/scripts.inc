.set LOCALID_WALLACE, 1
.set LOCALID_RIVAL, 2
.set LOCALID_BIRCH, 3

EverGrandeCity_ChampionsRoom_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_ChampionsRoom_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_ChampionsRoom_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_ChampionsRoom_OnFrame
	.byte 0

EverGrandeCity_ChampionsRoom_OnTransition:
	call Common_EventScript_SetupRivalGfxId
	end

EverGrandeCity_ChampionsRoom_OnWarp:
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_ChampionsRoom_EventScript_PlayerTurnNorth
	.2byte 0

EverGrandeCity_ChampionsRoom_EventScript_PlayerTurnNorth::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

EverGrandeCity_ChampionsRoom_OnFrame:
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_ChampionsRoom_EventScript_EnterRoom
	.2byte 0

EverGrandeCity_ChampionsRoom_EventScript_EnterRoom::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp4
	waitmovement 0
	delay 40
	applymovement OBJ_EVENT_ID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_PlayerApproachWallace
	waitmovement 0
	goto_if_set FLAG_WALLACE_REMATCH, EverGrandeCity_ChampionsRoom_EventScript_WallaceRematch
	setvar VAR_TEMP_1, 1
	goto EverGrandeCity_ChampionsRoom_EventScript_Wallace
	releaseall
	end

EverGrandeCity_ChampionsRoom_Movement_PlayerApproachWallace:
	walk_up
	walk_up
	step_end

EverGrandeCity_ChampionsRoom_EventScript_Wallace::
	playbgm MUS_ENCOUNTER_CHAMPION, FALSE
	msgbox EverGrandeCity_ChampionsRoom_Text_IntroSpeech, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_WALLACE, EverGrandeCity_ChampionsRoom_Text_Defeat
	goto EverGrandeCity_ChampionsRoom_EventScript_Defeated
	end

EverGrandeCity_ChampionsRoom_EventScript_WallaceRematch::
	playbgm MUS_ENCOUNTER_CHAMPION, FALSE
	msgbox EverGrandeCity_ChampionsRoom_Text_IntroSpeech2, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_WALLACE2, EverGrandeCity_ChampionsRoom_Text_Defeat2
	goto EverGrandeCity_ChampionsRoom_EventScript_Defeated2
	end

EverGrandeCity_ChampionsRoom_EventScript_Defeated::
	playse SE_DOOR
	setmetatile 6, 1, METATILE_EliteFour_OpenDoorChampion_Frame, FALSE
	setmetatile 6, 2, METATILE_EliteFour_OpenDoorChampion_Opening, FALSE
	special DrawWholeMapView
	msgbox EverGrandeCity_ChampionsRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	closemessage
	playse SE_DOOR
	checkplayergender
	call_if_eq VAR_RESULT, MALE, EverGrandeCity_ChampionsRoom_EventScript_PlayMayMusic
	call_if_eq VAR_RESULT, FEMALE, EverGrandeCity_ChampionsRoom_EventScript_PlayBrendanMusic
	addobject LOCALID_RIVAL
	call EverGrandeCity_ChampionsRoom_EventScript_RivalApproachPlayer
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, EverGrandeCity_ChampionsRoom_EventScript_MayAdvice
	goto_if_eq VAR_RESULT, FEMALE, EverGrandeCity_ChampionsRoom_EventScript_BrendanAdvice
	end

EverGrandeCity_ChampionsRoom_EventScript_Defeated2::
	playse SE_DOOR
	setmetatile 6, 1, METATILE_EliteFour_OpenDoorChampion_Frame, FALSE
	setmetatile 6, 2, METATILE_EliteFour_OpenDoorChampion_Opening, FALSE
	special DrawWholeMapView
	msgbox EverGrandeCity_ChampionsRoom_Text_PostBattleSpeech2, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_WALLACE, EverGrandeCity_ChampionsRoom_Movement_WallaceExit2
	applymovement OBJ_EVENT_ID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_PlayerExit2
	waitmovement 0
	setflag FLAG_GARBAGEFLAG
	setflag FLAG_STEVEN_REMATCH
	warp MAP_EVER_GRANDE_CITY_HALL_OF_FAME, 7, 16
	waitstate
	releaseall
	end

EverGrandeCity_ChampionsRoom_EventScript_PlayMayMusic::
	playbgm MUS_ENCOUNTER_MAY, FALSE
	return

EverGrandeCity_ChampionsRoom_EventScript_PlayBrendanMusic::
	playbgm MUS_ENCOUNTER_BRENDAN, FALSE
	return

EverGrandeCity_ChampionsRoom_EventScript_MayAdvice::
	msgbox EverGrandeCity_ChampionsRoom_Text_MayAdvice, MSGBOX_DEFAULT
	delay 40
	playse SE_PIN
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	call EverGrandeCity_ChampionsRoom_EventScript_RivalLookBackAndForth
	msgbox EverGrandeCity_ChampionsRoom_Text_MayItsAlreadyOver, MSGBOX_DEFAULT
	goto EverGrandeCity_ChampionsRoom_EventScript_BirchArrivesExitForHoF
	end

EverGrandeCity_ChampionsRoom_EventScript_BrendanAdvice::
	msgbox EverGrandeCity_ChampionsRoom_Text_BrendanAdvice, MSGBOX_DEFAULT
	delay 40
	playse SE_PIN
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	call EverGrandeCity_ChampionsRoom_EventScript_RivalLookBackAndForth
	msgbox EverGrandeCity_ChampionsRoom_Text_BrendanYouveWon, MSGBOX_DEFAULT
	goto EverGrandeCity_ChampionsRoom_EventScript_BirchArrivesExitForHoF
	end

EverGrandeCity_ChampionsRoom_EventScript_BirchArrivesExitForHoF::
	closemessage
	addobject LOCALID_BIRCH
	applymovement LOCALID_BIRCH, EverGrandeCity_ChampionsRoom_Movement_BirchArrives
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox EverGrandeCity_ChampionsRoom_Text_BirchArriveRatePokedex, MSGBOX_DEFAULT
	call ProfBirch_EventScript_RatePokedex
	msgbox EverGrandeCity_ChampionsRoom_Text_BirchCongratulations, MSGBOX_DEFAULT
	applymovement LOCALID_WALLACE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 20
	applymovement LOCALID_WALLACE, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox EverGrandeCity_ChampionsRoom_Text_WallaceComeWithMe, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement LOCALID_WALLACE, EverGrandeCity_ChampionsRoom_Movement_WallaceExitStart
	applymovement OBJ_EVENT_ID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_PlayerExitStart
	applymovement LOCALID_BIRCH, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_RIVAL, EverGrandeCity_ChampionsRoom_Movement_RivalFollows
	waitmovement 0
	delay 20
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox EverGrandeCity_ChampionsRoom_Text_WallaceWaitOutside, MSGBOX_DEFAULT
	checkplayergender
	call_if_eq VAR_RESULT, MALE, EverGrandeCity_ChampionsRoom_EventScript_MayCongratulations
	call_if_eq VAR_RESULT, FEMALE, EverGrandeCity_ChampionsRoom_EventScript_BrendanCongratulations
	closemessage
	applymovement LOCALID_WALLACE, EverGrandeCity_ChampionsRoom_Movement_WallaceExit
	applymovement OBJ_EVENT_ID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_PlayerExit
	waitmovement 0
	setflag FLAG_GARBAGEFLAG
	warp MAP_EVER_GRANDE_CITY_HALL_OF_FAME, 7, 16
	waitstate
	releaseall
	end

EverGrandeCity_ChampionsRoom_EventScript_MayCongratulations::
	msgbox EverGrandeCity_ChampionsRoom_Text_MayCongratulations, MSGBOX_DEFAULT
	return

EverGrandeCity_ChampionsRoom_EventScript_BrendanCongratulations::
	msgbox EverGrandeCity_ChampionsRoom_Text_BrendanCongratulations, MSGBOX_DEFAULT
	return

EverGrandeCity_ChampionsRoom_EventScript_RivalApproachPlayer::
	applymovement LOCALID_RIVAL, EverGrandeCity_ChampionsRoom_Movement_RivalApproachPlayer
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

EverGrandeCity_ChampionsRoom_EventScript_RivalLookBackAndForth::
	applymovement LOCALID_RIVAL, EverGrandeCity_ChampionsRoom_Movement_RivalLookBackAndForth
	waitmovement 0
	return

EverGrandeCity_ChampionsRoom_Movement_PlayerExitStart:
	walk_up
	walk_up
	step_end

EverGrandeCity_ChampionsRoom_Movement_PlayerExit:
	walk_up
	delay_16
	walk_up
	delay_8
	set_invisible
	step_end

EverGrandeCity_ChampionsRoom_Movement_PlayerExit2:
	walk_up
	delay_16
	walk_up
	delay_8
	walk_up
	delay_8
	set_invisible
	step_end

EverGrandeCity_ChampionsRoom_Movement_RivalApproachPlayer:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_up
	walk_in_place_faster_right
	step_end

EverGrandeCity_ChampionsRoom_Movement_RivalLookBackAndForth:
	walk_in_place_faster_up
	delay_16
	walk_in_place_faster_right
	delay_16
	walk_in_place_faster_up
	delay_8
	walk_in_place_faster_right
	delay_16
	step_end

EverGrandeCity_ChampionsRoom_Movement_RivalFollows:
	walk_right
	walk_up
	step_end

EverGrandeCity_ChampionsRoom_Movement_WallaceExitStart:
	walk_up
	walk_up
	walk_in_place_faster_down
	step_end

EverGrandeCity_ChampionsRoom_Movement_WallaceExit:
	walk_up
	delay_8
	set_invisible
	step_end

EverGrandeCity_ChampionsRoom_Movement_WallaceExit2:
	walk_up
	delay_8
	walk_up
	delay_8
	set_invisible
	step_end

EverGrandeCity_ChampionsRoom_Movement_BirchArrives:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	walk_in_place_faster_left
	step_end

EverGrandeCity_ChampionsRoom_Text_IntroSpeech:
	.string "WALLACE : Bienvenue, {PLAYER}{KUN}.\p"
	.string "Cet incident à NENUCRIQUE…\n"
	.string "C'était un travail superbe, mettre fin\l"
	.string "à cette crise tout(e) seul(e).\p"
	.string "Oups !\p"
	.string "Ce ne serait pas juste de dire que tu\n"
	.string "as mis fin à la crise seul(e).\p"
	.string "Tu as surmonté cette situation difficile\n"
	.string "en travaillant en harmonie avec tes POKéMON.\p"
	.string "Nous, DRESSEURS, élevons les POKéMON en leur\n"
	.string "donnant des objets et en leur enseignant de\l"
	.string "nouvelles techniques de combat.\p"
	.string "Mais nous apprenons aussi beaucoup\n"
	.string "de choses de nos POKéMON.\p"
	.string "Et c'est ici que tes exploits\n"
	.string "sont mis à l'épreuve face à ceux\l"
	.string "d'autres comme toi.\p"
	.string "Maintenant !\p"
	.string "Qui peut danser le plus élégamment avec\n"
	.string "ses POKéMON à HOENN ?\p"
	.string "Montre-le-moi ici et maintenant !$"

EverGrandeCity_ChampionsRoom_Text_IntroSpeech2:
	.string "WALLACE : Bienvenue, {PLAYER}{KUN}.\n"
	.string "Je suis vraiment ravi de te revoir.\p"
	.string "À première vue, tu sembles différent(e).\n"
	.string "Tu es devenu(e) plus fort(e) ?\p"
	.string "Oui… Oui, c'est le cas. Oh…\n"
	.string "Ce regard que tu me lances…\p"
	.string "D'accord, je vois que tu es déjà\n"
	.string "prêt(e) pour ce combat.\p"
	.string "Voyons si tu peux\n"
	.string "danser à mon rythme.\p"
	.string "Montre-moi que tu es le/la plus fort(e)\n"
	.string "dresseur(se) de POKéMON à HOENN !$"

EverGrandeCity_ChampionsRoom_Text_Defeat:
	.string "Moi, le CHAMPION, je tombe vaincu…\p"
	.string "C'était un travail merveilleux.\n"
	.string "Tu étais élégant(e), terriblement même.\l"
	.string "Et pourtant, c'était absolument glorieux !\p"
	.string "Bravo à toi, {PLAYER}{KUN} !\p"
	.string "Tu es vraiment un(e) DRESSEUR(SE) de\n"
	.string "POKéMON noble !$"

EverGrandeCity_ChampionsRoom_Text_Defeat2:
	.string "Moi, le CHAMPION, je tombe vaincu…\p"
	.string "Encore ! Incroyable. Travail merveilleux.\n"
	.string "Tu étais élégant(e), terriblement même.\l"
	.string "Et pourtant, c'était absolument glorieux !\p"
	.string "Encore bravo à toi, {PLAYER}{KUN} !\p"
	.string "Tu es vraiment le/la meilleur(e) DRESSEUR(SE)\n"
	.string "de POKéMON de HOENN !$"

EverGrandeCity_ChampionsRoom_Text_PostBattleSpeech:
	.string "WALLACE : Les POKéMON que tu as envoyés\n"
	.string "au combat…\p"
	.string "Parfois, ils dansaient comme une brise\n"
	.string "de printemps, parfois ils frappaient\l"
	.string "comme la foudre.\p"
	.string "C'est avec une élégance légère mais assurée\n"
	.string "que tu as mené tes POKéMON.\p"
	.string "Même moi, j'ai été ébloui par ta\n"
	.string "prestation magistrale !\p"
	.string "Tu te tiens maintenant au sommet glorieux\n"
	.string "de la LIGUE POKéMON.\p"
	.string "Je te proclame maintenant nouveau/nouvelle\n"
	.string "CHAMPION/CHAMPIONNE de la région HOENN…$"

EverGrandeCity_ChampionsRoom_Text_PostBattleSpeech2:
	.string "WALLACE : Les POKéMON que tu as envoyés\n"
	.string "au combat…\p"
	.string "Ils me rappellent les nombreuses danses\n"
	.string "que j'ai apprises à travers le monde.\p"
	.string "Leurs mouvements étaient éblouissants et\n"
	.string "leur performance encore meilleure.\p"
	.string "Tu te tiens à nouveau au sommet glorieux\n"
	.string "de la LIGUE POKéMON !\p"
	.string "Je te proclame maintenant nouveau/nouvelle\n"
	.string "CHAMPION/CHAMPIONNE de HOENN… !\p"
	.string "C'est ce que je dirais\n"
	.string "si tu ne l'étais pas déjà !$"

EverGrandeCity_ChampionsRoom_Text_MayAdvice:
	.string "FLORA : {PLAYER}{KUN} !\p"
	.string "Voici quelques conseils avant d'affronter\n"
	.string "le CHAMPION…$"

EverGrandeCity_ChampionsRoom_Text_MayItsAlreadyOver:
	.string "FLORA : Hein ?\n"
	.string "Quoi, quoi, quoi ?\p"
	.string "{PLAYER}{KUN}…\n"
	.string "Se pourrait-il que…\l"
	.string "Ce soit déjà fini ?$"

EverGrandeCity_ChampionsRoom_Text_BrendanAdvice:
	.string "BRICE : {PLAYER} !\p"
	.string "Tu veux des conseils avant d'affronter\n"
	.string "le CHAMPION ?…$"

EverGrandeCity_ChampionsRoom_Text_BrendanYouveWon:
	.string "BRICE : {PLAYER}…\p"
	.string "Tu essaies de me dire que…\n"
	.string "Tu as battu le CHAMPION ?$"

EverGrandeCity_ChampionsRoom_Text_BirchArriveRatePokedex:
	.string "PROF. SEKO : Tu vois ?\n"
	.string "Qu'est-ce que je t'avais dit, SILVER ?\p"
	.string "Je t'avais bien dit que tu n'avais pas à\n"
	.string "t'inquiéter pour {PLAYER}{KUN} !\p"
	.string "… … … … … … … …\n"
	.string "{PLAYER}{KUN}, tu l'as enfin fait.\p"
	.string "Quand j'ai appris que tu avais battu ton\n"
	.string "propre père à l'ARÈNE DE CLÉMENTI-VILLE,\l"
	.string "je me suis dit que tu avais peut-être une chance…\p"
	.string "Mais penser que tu es vraiment devenu(e)\n"
	.string "CHAMPION/CHAMPIONNE !\p"
	.string "Ah, oui !\p"
	.string "Qu'est-il advenu de ton POKéDEX ?\n"
	.string "Allez, montre-le-moi.$"

EverGrandeCity_ChampionsRoom_Text_BirchCongratulations:
	.string "PROF. SEKO : En tout cas,\n"
	.string "félicitations !\p"
	.string "Maintenant, va fièrement dans la dernière salle !$"

EverGrandeCity_ChampionsRoom_Text_WallaceComeWithMe:
	.string "WALLACE : {PLAYER}{KUN}…\p"
	.string "Non, laisse-moi reformuler correctement.\p"
	.string "Le/la nouveau/nouvelle CHAMPION/CHAMPIONNE !\p"
	.string "Viens avec moi.$"

EverGrandeCity_ChampionsRoom_Text_WallaceWaitOutside:
	.string "WALLACE : Je suis désolé, mais…\p"
	.string "À partir d'ici, seuls les DRESSEURS qui\n"
	.string "sont devenus CHAMPIONS peuvent entrer.\p"
	.string "Tu devras attendre dehors avec\n"
	.string "le PROF. SEKO.$"

EverGrandeCity_ChampionsRoom_Text_MayCongratulations:
	.string "FLORA : Oh là là…\p"
	.string "… … … … … … … …\n"
	.string "… … … … … … … …\p"
	.string "Je plaisante ! Ce n'est pas grave !\n"
	.string "C'est la règle !\p"
	.string "{PLAYER}{KUN} !\n"
	.string "Sincèrement, félicitations !$"

EverGrandeCity_ChampionsRoom_Text_BrendanCongratulations:
	.string "BRICE : Quoiiiii ?! … … … … …\n"
	.string "… … … … … … … …\p"
	.string "On n'y peut rien, c'est la règle.\p"
	.string "{PLAYER}, bravo !\n"
	.string "Félicitations !$"
