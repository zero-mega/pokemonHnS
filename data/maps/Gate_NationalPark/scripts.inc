Gate_NationalPark_MapScripts::
	.byte 0

Gate_NationalPark_EventScript_Attendant::
	lock
	faceplayer
	goto_if_set FLAG_DAILY_BUG_CONTEST_COMPLETED, Gate_NationalPark_EventScript_AttendantAlreadyPlayed
	msgbox Route35NationalParkGate_Text_OfficerAskToParticipate, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, Gate_NationalPark_EventScript_AttendantStart
	msgbox Route35NationalParkGate_Text_TakePartInFuture, MSGBOX_DEFAULT
	release
	end

Gate_NationalPark_EventScript_AttendantStart::
	msgbox Route35NationalParkGate_Text_OfficerAskToUseFirstMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, Gate_NationalPark_EventScript_AttendantCancel
	getpartysize
	call_if_eq VAR_RESULT, 1, Gate_NationalPark_EventScript_OnlyOneMon
	msgbox Route35NationalParkGate_Text_OfficerHoldYourMon, MSGBOX_DEFAULT
	closemessage
	special SavePlayerParty
	remove5mons
	goto_if_eq VAR_RESULT, MON_CANT_GIVE, Gate_NationalPark_EventScript_AttendantFaint
	playfanfare MUS_OBTAIN_ITEM
	message Route35NationalParkGate_Text_MonLeftWithHelper
	waitfanfare
	closemessage
	msgbox Route35NationalParkGate_Text_OfficerGiveParkBalls, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_SAFARI_BALL, 30
	closemessage
	msgbox Route35NationalParkGate_Text_OfficerExplainRules, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_WEST, Gate_NationalPark_EventScript_AttendantEnterTop
	call_if_eq VAR_FACING, DIR_NORTH, Gate_NationalPark_EventScript_AttendantEnterBot
	playse SE_EXIT
	clearflag FLAG_HIDE_BUG_CONTEST_ATTENDANT_SIDE
	special EnterBugContestMode
	warp MAP_NATIONAL_PARK_BUG_CONTEST, 1
	setvar VAR_BUG_CONTEST_STATE, 1
	release
	end

Gate_NationalPark_EventScript_OnlyOneMon::
	special SavePlayerParty
	msgbox Route35NationalParkGate_Text_OfficerGiveParkBalls, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_SAFARI_BALL, 30
	closemessage
	msgbox Route35NationalParkGate_Text_OfficerExplainRules, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_WEST, Gate_NationalPark_EventScript_AttendantEnterTop
	call_if_eq VAR_FACING, DIR_NORTH, Gate_NationalPark_EventScript_AttendantEnterBot
	playse SE_EXIT
	clearflag FLAG_HIDE_BUG_CONTEST_ATTENDANT_SIDE
	special EnterBugContestMode
	warp MAP_NATIONAL_PARK_BUG_CONTEST, 1
	setvar VAR_BUG_CONTEST_STATE, 1
	release
	end

Gate_NationalPark_EventScript_AttendantEnterTop::
	applymovement OBJ_EVENT_ID_PLAYER, Gate_NationalPark_Movement_Player_EnterParkTop
	waitmovement 0
	return

Gate_NationalPark_EventScript_AttendantEnterBot::
	applymovement OBJ_EVENT_ID_PLAYER, Gate_NationalPark_Movement_Player_EnterParkBot
	waitmovement 0
	return


Gate_NationalPark_EventScript_AttendantFaint::	
	msgbox Route35NationalParkGate_Text_FirstMonCantBattle, MSGBOX_DEFAULT
	closemessage
	release
	end	

Gate_NationalPark_EventScript_AttendantCancel::	
	msgbox Route35NationalParkGate_Text_TakePartInFuture, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_NationalPark_EventScript_AttendantAlreadyPlayed::
	msgbox Route35NationalParkGate_Text_ContestIsOver, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_NationalPark_EventScript_AttendantExit::
	special LoadPlayerParty
	setvar VAR_BUG_CONTEST_STATE, 0
	release
	end

Gate_NationalPark_Movement_Player_EnterParkTop:
	walk_down
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	step_end

Gate_NationalPark_Movement_Player_EnterParkBot:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	step_end

Gate_NationalPark_EventScript_BAttendant::
	lock
	faceplayer
	goto_if_set FLAG_DAILY_BUG_CONTEST_COMPLETED, Gate_NationalPark_EventScript_AttendantAlreadyPlayed
	msgbox Route35NationalParkGate_Text_OfficerAskToParticipate, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, Gate_NationalPark_EventScript_BAttendantStart
	msgbox Route35NationalParkGate_Text_TakePartInFuture, MSGBOX_DEFAULT
	release
	end

Gate_NationalPark_EventScript_BAttendantStart::
	msgbox Route35NationalParkGate_Text_OfficerAskToUseFirstMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, Gate_NationalPark_EventScript_AttendantCancel
	getpartysize
	call_if_eq VAR_RESULT, 1, Gate_NationalPark_EventScript_OnlyOneMonB
	msgbox Route35NationalParkGate_Text_OfficerHoldYourMon, MSGBOX_DEFAULT
	closemessage
	special SavePlayerParty
	remove5mons
	goto_if_eq VAR_RESULT, MON_CANT_GIVE, Gate_NationalPark_EventScript_AttendantFaint
	playfanfare MUS_OBTAIN_ITEM
	message Route35NationalParkGate_Text_MonLeftWithHelper
	waitfanfare
	closemessage
	msgbox Route35NationalParkGate_Text_OfficerGiveParkBalls, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_SAFARI_BALL, 30
	closemessage
	msgbox Route35NationalParkGate_Text_OfficerExplainRules, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_EAST, Gate_NationalPark_EventScript_AttendantBEnterTop
	call_if_eq VAR_FACING, DIR_NORTH, Gate_NationalPark_EventScript_AttendantBEnterBot
	playse SE_EXIT
	special EnterBugContestMode
	setflag FLAG_HIDE_BUG_CONTEST_ATTENDANT_SIDE
	warp MAP_NATIONAL_PARK_BUG_CONTEST, 2
	setvar VAR_BUG_CONTEST_STATE, 5
	release
	end

Gate_NationalPark_EventScript_OnlyOneMonB::
	special SavePlayerParty
	msgbox Route35NationalParkGate_Text_OfficerGiveParkBalls, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_SAFARI_BALL, 30
	closemessage
	msgbox Route35NationalParkGate_Text_OfficerExplainRules, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_EAST, Gate_NationalPark_EventScript_AttendantBEnterTop
	call_if_eq VAR_FACING, DIR_NORTH, Gate_NationalPark_EventScript_AttendantBEnterBot
	playse SE_EXIT
	special EnterBugContestMode
	setflag FLAG_HIDE_BUG_CONTEST_ATTENDANT_SIDE
	warp MAP_NATIONAL_PARK_BUG_CONTEST, 2
	setvar VAR_BUG_CONTEST_STATE, 5
	release
	end

Gate_NationalPark_EventScript_AttendantBEnterTop::
	applymovement OBJ_EVENT_ID_PLAYER, Gate_NationalPark_Movement_Player_EnterParkTopB
	waitmovement 0
	return

Gate_NationalPark_EventScript_AttendantBEnterBot::
	applymovement OBJ_EVENT_ID_PLAYER, Gate_NationalPark_Movement_Player_EnterParkBotB
	waitmovement 0
	return

Gate_NationalPark_Movement_Player_EnterParkTopB:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_in_place_left
	step_end

Gate_NationalPark_Movement_Player_EnterParkBotB:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_left
	step_end

Route35NationalParkGate_Text_OfficerAskToParticipate:
	.string "Bonjour Dresseur ! Le Concours de\n"
	.string "Capture d'Insectes a lieu aujourd'hui.\p"
	.string "Les règles sont simples.\p"
	.string "Avec l'un de vos POKéMON, capturez un\n"
	.string "POKéMON insecte qui sera jugé.\p"
	.string "Voulez-vous essayer ?$"

Route35NationalParkGate_Text_OfficerGiveParkBalls:
	.string "Voici les SAFARI BALLS pour le\n"
	.string "Concours.$"

Route35NationalParkGate_Text_ReceivedParkBalls:
	.string "{PLAYER} a reçu des SAFARI BALLS.$"

Route35NationalParkGate_Text_OfficerExplainRules:
	.string "La personne qui attrape le POKéMON\n"
	.string "insecte le plus fort est le gagnant.\p"
	.string "Si vous n'avez plus de SAFARI BALLS,\n"
	.string "c'est terminé.\p"
	.string "Vous pouvez attraper jusqu'à 5 POKéMON.\n"
	.string "Seul le dernier attrapé sera gardé\l"
	.string "et placé dans le concours.\p"
	.string "Allez et capturez le POKéMON insecte\n"
	.string "le plus fort que vous pouvez trouver !$"

Route35NationalParkGate_Text_OfficerAskToUseFirstMon:
	.string "Si vous avez plus d'un POKéMON,\n"
	.string "vous devrez utiliser le\l"
	.string "premier de votre équipe.\p"
	.string "Est-ce que cela vous convient ?$"

Route35NationalParkGate_Text_OfficerHoldYourMon:
	.string "Très bien, nous garderons vos autres\n"
	.string "POKéMON pendant que vous participez.$"

Route35NationalParkGate_Text_MonLeftWithHelper:
	.string "Les POKéMON de {PLAYER} ont été laissés\n"
	.string "auprès de l'AIDE DU CONCOURS.$"

Route35NationalParkGate_Text_ChooseMonAndComeBack:
	.string "Veuillez choisir le POKéMON à utiliser\n"
	.string "pour le Concours, puis revenez me voir.$"

Route35NationalParkGate_Text_TakePartInFuture:
	.string "D'accord. Nous espérons que vous\n"
	.string "participerez une prochaine fois.$"

Route35NationalParkGate_Text_FirstMonCantBattle:
	.string "Oh non… Le premier POKéMON de votre\n"
	.string "équipe ne peut pas se battre.\p"
	.string "Veuillez l'échanger avec le POKéMON\n"
	.string "que vous souhaitez utiliser, puis revenez me voir.$"

Route35NationalParkGate_Text_MakeRoom:
	.string "Oh non… Votre équipe et votre\n"
	.string "BOÎTE PC sont pleines.\p"
	.string "Vous n'avez pas de place pour le\n"
	.string "POKéMON insecte que vous attrapez.\p"
	.string "Veuillez libérer de la place dans votre équipe ou\n"
	.string "votre BOÎTE PC, puis revenez me voir.$"

Route35NationalParkGate_Text_EggAsFirstMon:
	.string "Oh non… Vous avez un ŒUF comme premier\n"
	.string "POKéMON dans votre équipe.\p"
	.string "Veuillez l'échanger avec le POKéMON\n"
	.string "que vous souhaitez utiliser, puis revenez me voir.$"

Route35NationalParkGate_Text_ContestIsOver:
	.string "Le Concours d'aujourd'hui est terminé.\n"
	.string "Nous espérons que vous participerez une prochaine fois.$"

Route35NationalParkGate_EventScript_Policeman::
	lock
	faceplayer
	msgbox Route35NationalParkGate_Text_WeHoldContests, MSGBOX_DEFAULT
	closemessage
	release
	end

Route35NationalParkGate_EventScript_BC1::
	lock
	faceplayer
	msgbox Route35NationalParkGate_Text_YoungsterWonders, MSGBOX_DEFAULT
	closemessage
	release
	end

Route35NationalParkGate_EventScript_BC2::
	lock
	faceplayer
	msgbox Route35NationalParkGate_Text_BC2, MSGBOX_DEFAULT
	closemessage
	release
	end

Route35NationalParkGate_EventScript_Rocker::
	lock
	faceplayer
	msgbox Route35NationalParkGate_Text_Rocker, MSGBOX_DEFAULT
	closemessage
	release
	end

Route35NationalParkGate_EventScript_Beauty::
	lock
	faceplayer
	msgbox Route35NationalParkGate_Text_Beauty, MSGBOX_DEFAULT
	closemessage
	release
	end

Route35NationalParkGate_Text_Rocker:
	.string "J'adore les POKéMON oiseaux ! J'ai trouvé\n"
	.string "un oiseau de type TÉNÈBRES dans le parc\l"
	.string "la nuit dernière !$"

Route35NationalParkGate_Text_BC2:
	.string "J'ai attrapé un énorme SCARABRUTE !$"

Route35NationalParkGate_Text_Beauty:
	.string "Il gagne toujours ces concours !$"

Route35NationalParkGate_Text_WeHoldContests:
	.string "Nous organisons des Concours régulièrement\n"
	.string "dans le PARC. Tu devrais essayer !$"

Route35NationalParkGate_Text_YoungsterWonders:
	.string "Quand aura lieu le prochain Concours de\n"
	.string "Capture d'Insectes ?$"

Route35NationalParkGate_Text_ContestExplanation:
	.string "Le Concours de Capture d'Insectes a lieu\n"
	.string "le mardi, jeudi et samedi.\p"
	.string "Non seulement tu gagnes un prix rien\n"
	.string "qu'en participant,\p"
	.string "mais tu peux aussi garder le POKéMON\n"
	.string "insecte que tu as à la fin du concours.$"
