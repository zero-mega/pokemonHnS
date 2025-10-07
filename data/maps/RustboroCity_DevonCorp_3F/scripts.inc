.set LOCALID_DEVON_EMPLOYEE, 2

RustboroCity_DevonCorp_3F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_DevonCorp_3F_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, RustboroCity_DevonCorp_3F_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RustboroCity_DevonCorp_3F_OnFrame
	.byte 0

RustboroCity_DevonCorp_3F_OnTransition:
	call_if_eq VAR_GARBAGEVAR, 0, RustboroCity_DevonCorp_3F_EventScript_SetEmployeePos
	end

RustboroCity_DevonCorp_3F_EventScript_SetEmployeePos::
	setobjectxyperm LOCALID_DEVON_EMPLOYEE, 3, 2
	setobjectmovementtype LOCALID_DEVON_EMPLOYEE, MOVEMENT_TYPE_FACE_LEFT
	return

RustboroCity_DevonCorp_3F_OnWarp:
	map_script_2 VAR_GARBAGEVAR, 0, RustboroCity_DevonCorp_3F_EventScript_PlayerFaceEast
	.2byte 0

RustboroCity_DevonCorp_3F_EventScript_PlayerFaceEast::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	end

RustboroCity_DevonCorp_3F_OnFrame:
	map_script_2 VAR_GARBAGEVAR, 0, RustboroCity_DevonCorp_3F_EventScript_MeetPresident
	.2byte 0

RustboroCity_DevonCorp_3F_EventScript_MeetPresident::
	lockall
	msgbox RustboroCity_DevonCorp_3F_Text_ThisIs3rdFloorWaitHere, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_DevonCorp_3F_Movement_EmployeeWalkOffscreen
	waitmovement 0
	delay 80
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_DevonCorp_3F_Movement_EmployeeReturnToPlayer
	waitmovement 0
	msgbox RustboroCity_DevonCorp_3F_Text_WordWithPresidentComeWithMe, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_FOLLOW_ME, FALSE
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_DevonCorp_3F_Movement_LeadPlayerToPresident
	applymovement OBJ_EVENT_ID_PLAYER, RustboroCity_DevonCorp_3F_Movement_PlayerFollowToPresident
	waitmovement 0
	msgbox RustboroCity_DevonCorp_3F_Text_PleaseGoAhead, MSGBOX_DEFAULT
	closemessage
	fadedefaultbgm
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_DevonCorp_3F_Movement_EmployeeFaceDesk
	applymovement OBJ_EVENT_ID_PLAYER, RustboroCity_DevonCorp_3F_Movement_PlayerApproachDesk
	waitmovement 0
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneIHaveFavor, MSGBOX_DEFAULT
	giveitem ITEM_LETTER
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneWantYouToHaveThis, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message RustboroCity_DevonCorp_3F_Text_ReceivedPokenav
	waitfanfare
	setflag FLAG_SYS_POKENAV_GET
	setflag FLAG_RECEIVED_POKENAV
	setflag FLAG_HIDE_RUSTBORO_CITY_POKEMON_SCHOOL_SCOTT
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneExplainPokenavRestUp, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneGoWithCautionAndCare, MSGBOX_DEFAULT
	setflag FLAG_GARBAGEFLAG
	clearflag FLAG_GARBAGEFLAG
	clearflag FLAG_GARBAGEFLAG
	clearflag FLAG_GARBAGEFLAG
	clearflag FLAG_GARBAGEFLAG
	setvar VAR_GARBAGEVAR, 1
	clearflag FLAG_GARBAGEFLAG
	setvar VAR_GARBAGEVAR, 1
	setvar VAR_GARBAGEVAR, 6
	releaseall
	end

RustboroCity_DevonCorp_3F_Movement_Unused:
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_left
	step_end

RustboroCity_DevonCorp_3F_Movement_LeadPlayerToPresident:
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_left
	step_end

RustboroCity_DevonCorp_3F_Movement_EmployeeFaceDesk:
	delay_16
	walk_in_place_faster_down
	step_end

RustboroCity_DevonCorp_3F_Movement_EmployeeWalkOffscreen:
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

RustboroCity_DevonCorp_3F_Movement_EmployeeReturnToPlayer:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_left
	walk_left
	walk_left
	step_end

RustboroCity_DevonCorp_3F_Movement_PlayerFollowToPresident:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

RustboroCity_DevonCorp_3F_Movement_PlayerApproachDesk:
	delay_16
	delay_16
	walk_down
	walk_down
	walk_in_place_faster_right
	step_end

RustboroCity_DevonCorp_3F_EventScript_MrStone::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_EXP_SHARE, RustboroCity_DevonCorp_3F_EventScript_MrStoneAfterFavor
	goto_if_set FLAG_DELIVERED_STEVEN_LETTER, RustboroCity_DevonCorp_3F_EventScript_GiveExpShare
	msgbox RustboroCity_DevonCorp_3F_Text_CountingOnYou, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RustboroCity_DevonCorp_3F_EventScript_GiveExpShare::
	msgbox RustboroCity_DevonCorp_3F_Text_ThankYouForDeliveringLetter, MSGBOX_DEFAULT
	giveitem ITEM_EXP_SHARE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_EXP_SHARE
	msgbox RustboroCity_DevonCorp_3F_Text_ExplainExpShare, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RustboroCity_DevonCorp_3F_EventScript_MrStoneAfterFavor::
	msgbox RustboroCity_DevonCorp_3F_Text_NotFamiliarWithTrends, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RustboroCity_DevonCorp_3F_EventScript_Employee::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_REPEAT_BALL, RustboroCity_DevonCorp_3F_EventScript_EmployeeBalls
	msgbox RustboroCity_DevonCorp_3F_Text_VisitCaptSternShipyard, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_3F_EventScript_EmployeeBalls::
	msgbox RustboroCity_DevonCorp_3F_Text_RepeatAndTimerHugelyPopular, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_3F_EventScript_RareRocksDisplay::
	msgbox RustboroCity_DevonCorp_3F_Text_RareRocksDisplay, MSGBOX_SIGN
	end

RustboroCity_DevonCorp_3F_Text_MrStoneIHaveFavor:
	.string "Je suis M. PIERRE, le PRÉSIDENT de\n"
	.string "la DEVON SARL.\p"
	.string "Je viens d'apprendre qui tu es !\p"
	.string "Tu as sauvé notre personnel non pas une,\n"
	.string "mais deux fois !\p"
	.string "J'ai une faveur à demander à une\n"
	.string "personne incroyable comme toi.\p"
	.string "Je sais que tu dois livrer un colis\n"
	.string "au CHANTIER NAVAL de POIVRESSEL.\p"
	.string "Eh bien, pourrais-tu t'arrêter à\n"
	.string "MYOKARA en chemin ?\p"
	.string "J'espérais que tu pourrais remettre une\n"
	.string "LETTRE à PIERRE à MYOKARA.$"

RustboroCity_DevonCorp_3F_Text_MrStoneWantYouToHaveThis:
	.string "M. PIERRE : Maintenant, tu dois savoir\n"
	.string "que je suis un grand PRÉSIDENT.\p"
	.string "Je ne serais jamais assez mesquin pour\n"
	.string "demander une faveur sans rien offrir.\p"
	.string "C'est pourquoi je veux que tu prennes ça !$"

RustboroCity_DevonCorp_3F_Text_ReceivedPokenav:
	.string "{PLAYER} reçoit un NAVIGATRICE POKéMON.$"

RustboroCity_DevonCorp_3F_Text_MrStoneExplainPokenavRestUp:
	.string "M. PIERRE : Cet appareil…\p"
	.string "C'est un NAVIGATRICE POKéMON, ou NAVIGATRICE\n"
	.string "pour faire court.\p"
	.string "C'est un outil indispensable pour tout\n"
	.string "DRESSEUR en aventure.\p"
	.string "Il contient une carte de la région de HOENN.\p"
	.string "Tu peux facilement vérifier où se trouvent\n"
	.string "MYOKARA et POIVRESSEL !\p"
	.string "Au fait, j'ai entendu dire que des criminels\n"
	.string "sinistres—MAGMA et AQUA, je crois—\l"
	.string "sèment le trouble partout.\p"
	.string "Je pense qu'il serait préférable que tu te\n"
	.string "reposes avant de repartir.$"

RustboroCity_DevonCorp_3F_Text_MrStoneGoWithCautionAndCare:
	.string "M. PIERRE : Eh bien, {PLAYER}{KUN},\n"
	.string "va avec prudence et attention !$"

RustboroCity_DevonCorp_3F_Text_CountingOnYou:
	.string "M. PIERRE : Je compte sur toi !$"

RustboroCity_DevonCorp_3F_Text_ThankYouForDeliveringLetter:
	.string "M. PIERRE : Tu as remis ma LETTRE ?\n"
	.string "Merci beaucoup !\p"
	.string "Voici ma façon de te remercier.\n"
	.string "Cela devrait t'aider, toi, un DRESSEUR.$"

RustboroCity_DevonCorp_3F_Text_ExplainExpShare:
	.string "M. PIERRE : Si tu actives le MULTI EXP.,\n"
	.string "tous les POKéMON de l'équipe gagneront\l"
	.string "la moitié des Points EXP du combat.\p"
	.string "Je dirais que le MULTI EXP. est très utile\n"
	.string "pour entraîner les POKéMON faibles.$"

RustboroCity_DevonCorp_3F_Text_NotFamiliarWithTrends:
	.string "M. PIERRE : Depuis ma jeunesse, je me suis\n"
	.string "plongé dans le travail.\p"
	.string "Du coup, je ne suis pas très au courant\n"
	.string "des modes et de ce genre de choses.\p"
	.string "Mais est-ce que tous les jeunes veulent\n"
	.string "devenir DRESSEURS à la LIGUE POKéMON ?$"

RustboroCity_DevonCorp_3F_Text_ThisIs3rdFloorWaitHere:
	.string "Voici le troisième étage de la\n"
	.string "DEVON SARL.\p"
	.string "Le BUREAU de notre PRÉSIDENT est à\n"
	.string "cet étage.\p"
	.string "En tout cas, je ne peux pas te dire à\n"
	.string "quel point je suis reconnaissant.\p"
	.string "Euh… Au fait, ce colis\n"
	.string "que tu as récupéré pour nous…\p"
	.string "Pourrais-tu le livrer au\n"
	.string "CHANTIER NAVAL de POIVRESSEL ?\p"
	.string "Ce serait terrible si ces voleurs\n"
	.string "essayaient de le reprendre.\p"
	.string "Euh… Héhéhé, alors, est-ce que je peux\n"
	.string "compter sur toi pour ça ?\p"
	.string "Ah, c'est vrai.\n"
	.string "Peux-tu attendre ici un instant ?$"

RustboroCity_DevonCorp_3F_Text_WordWithPresidentComeWithMe:
	.string "Notre PRÉSIDENT voudrait te parler.\p"
	.string "Viens avec moi, s'il te plaît.$"

RustboroCity_DevonCorp_3F_Text_PleaseGoAhead:
	.string "Vas-y, je t'en prie.$"

RustboroCity_DevonCorp_3F_Text_VisitCaptSternShipyard:
	.string "Si tu vas au CHANTIER NAVAL de POIVRESSEL,\n"
	.string "tu devrais voir le CAPT. PORTUAIRE.$"

RustboroCity_DevonCorp_3F_Text_RepeatAndTimerHugelyPopular:
	.string "Les nouveaux produits de DEVON, la HONOR BALL\n"
	.string "et la TEMPO BALL, sont devenus très\l"
	.string "populaires parmi les DRESSEURS.$"

RustboroCity_DevonCorp_3F_Text_RareRocksDisplay:
	.string "C'est une collection de pierres rares\n"
	.string "assemblée par le PRÉSIDENT.$"
