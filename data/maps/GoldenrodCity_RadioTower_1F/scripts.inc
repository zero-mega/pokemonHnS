.set LOCALID_GOLDENROD_RADIOTOWER_WHITNEY, 6
.set LOCALID_GOLDENROD_RADIOTOWER_GRUNT, 3
.set LOCALID_LOTTERY_CLERK, 2

GoldenrodCity_RadioTower_1F_MapScripts::
	.byte 0

RadioTower1F_EventScript_Grunt::
	lock
	faceplayer
	msgbox RadioTower1F_Text_GruntM3Seen, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_2,  RadioTower1F_Text_GruntM3Beaten
	msgbox RadioTower1F_Text_GruntM3After, MSGBOX_AUTOCLOSE
	turnobject LOCALID_GOLDENROD_RADIOTOWER_GRUNT, DIR_EAST
	applymovement2 LOCALID_GOLDENROD_RADIOTOWER_GRUNT, RadioTower1F_Movement_Rocket
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_GOLDENROD_RADIOTOWER_GRUNT
	setflag FLAG_HIDE_ROCKET_GOLDENROD_RADIOTOWER_1
	release
	end

RadioTower1F_Movement_Rocket::
	walk_in_place_right
	step_end

RadioTower1F_EventScript_Lass::
	lock
	faceplayer
	msgbox RadioTower1F_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

RadioTower1F_EventScript_Youngster::
	lock
	faceplayer
	msgbox RadioTower1F_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end

RadioTower1F_EventScript_Whitney::
	lock
	faceplayer
	msgbox RadioTower1F_Text_Whitney1, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_GOLDENROD_RADIOTOWER_WHITNEY, DIR_SOUTH
	release
	end

RadioTower1F_Text_Whitney1::
	.string "BLANCHE : Salut !\p"
	.string "Je m'appelle BLANCHE !\p"
	.string "J'ai entendu parler du Quiz pour\n"
	.string "gagner une RADIO, alors je suis venue\l"
	.string "pour en avoir une...\p"
	.string "Mais ce Quiz est trop difficile !$"

RadioTower1F_Text_Whitney2::
	.string "BLANCHE : Waouh, tu as réussi !\p"
	.string "Je pensais que la réponse à la\n"
	.string "troisième question était sûrement les\l"
	.string "Noigrumes ! Oups !\p"
	.string "Il est temps de retourner à l'ARÈNE !$"

RadioTower1F_EventScript_Reception::
	lock
	faceplayer
	msgbox RadioTower1F_Text_ReceptionistWelcome, MSGBOX_DEFAULT
	goto_if_unset FLAG_ENABLE_RADIO, RadioTower1F_EventScript_ReceptionOfferQuiz
	msgbox RadioTower1F_Text_ReceptionistNoTours, MSGBOX_DEFAULT
	closemessage
	release
	end

RadioTower1F_EventScript_ReceptionOfferQuiz::
	msgbox RadioTower1F_Text_RadioCardWomanOfferQuiz, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, RadioTower1F_EventScript_ReceptionQuiz1
	msgbox RadioTower1F_Text_DeclineQuiz, MSGBOX_DEFAULT
	closemessage
	release
	end

RadioTower1F_EventScript_ReceptionQuiz1::
	msgbox RadioTower1F_Text_QuizQuestion1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, RadioTower1F_EventScript_ReceptionQuiz2
	msgbox RadioTower1F_Text_WrongAnswer, MSGBOX_DEFAULT
	closemessage
	release
	end

RadioTower1F_EventScript_ReceptionQuiz2::
	msgbox RadioTower1F_Text_QuizQuestion2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, RadioTower1F_EventScript_ReceptionQuiz3
	msgbox RadioTower1F_Text_WrongAnswer, MSGBOX_DEFAULT
	closemessage
	release
	end

RadioTower1F_EventScript_ReceptionQuiz3::
	msgbox RadioTower1F_Text_QuizQuestion3, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, RadioTower1F_EventScript_ReceptionQuiz4
	msgbox RadioTower1F_Text_WrongAnswer, MSGBOX_DEFAULT
	closemessage
	release
	end

RadioTower1F_EventScript_ReceptionQuiz4::
	msgbox RadioTower1F_Text_QuizQuestion4, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, RadioTower1F_EventScript_ReceptionQuiz5
	msgbox RadioTower1F_Text_WrongAnswer, MSGBOX_DEFAULT
	closemessage
	release
	end

RadioTower1F_EventScript_ReceptionQuiz5::
	msgbox RadioTower1F_Text_QuizQuestion5, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, RadioTower1F_EventScript_ReceptionGiveRadio
	msgbox RadioTower1F_Text_WrongAnswer, MSGBOX_DEFAULT
	closemessage
	release
	end

RadioTower1F_EventScript_ReceptionGiveRadio::
	msgbox RadioTower1F_Text_QuizWin, MSGBOX_DEFAULT
	closemessage
	playfanfare MUS_OBTAIN_ITEM
	giveitem ITEM_RADIO
	waitfanfare
	msgbox RadioTower1F_Text_TuneIn, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_GOLDENROD_RADIOTOWER_WHITNEY, Common_Movement_ExclamationMark
	delay 60
	turnobject LOCALID_GOLDENROD_RADIOTOWER_WHITNEY, DIR_EAST
	delay 20
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	msgbox RadioTower1F_Text_Whitney2, MSGBOX_DEFAULT
	closemessage
	applymovement2 LOCALID_GOLDENROD_RADIOTOWER_WHITNEY, GoldenrodCity_RadioTower_4F_Movement_WhitneyLeave
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_GOLDENROD_RADIOTOWER_WHITNEY
	setflag FLAG_ENABLE_RADIO
	setflag FLAG_HIDE_GOLDENROD_BEAUTY
	setvar VAR_GOLDENROD_CITY_STATE, 2
	release
	end

GoldenrodCity_RadioTower_4F_Movement_WhitneyLeave:
	face_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_in_place_down
	step_end

GoldenrodCity_RadioTower_1F_EventScript_Sign::
	lock
	msgbox RadioTower1F_Text_Directory, MSGBOX_SIGN
	closemessage
	release
	end

RadioTower1F_Text_ReceptionistWelcome:
    .string "Bienvenue !$"

RadioTower1F_Text_ReceptionistNoTours:
    .string "Bonjour. Je suis désolée, mais nous\n"
    .string "n'organisons pas de visites aujourd'hui.$"

RadioTower1F_Text_RadioCardWomanOfferQuiz:
    .string "Nous organisons un grand quiz en ce\n"
    .string "moment.\p"
    .string "Réponde correctement à cinq questions\n"
    .string "et tu gagneras une RADIO.\p"
    .string "Toi et tes POKéMON pourrez écouter de\n"
    .string "la musique partout, à tout moment.\p"
    .string "Veux-tu tenter le quiz ?$"

RadioTower1F_Text_QuizQuestion1:
    .string "Question 1 :\p"
    .string "Existe-t-il un POKéMON qui n'apparaît\n"
    .string "que le jour ?$"

RadioTower1F_Text_QuizQuestion2:
    .string "Correct !\n"
    .string "Question 2 :\p"
    .string "Cette affirmation est-elle correcte ?\p"
    .string "On ne peut pas acheter de BAIE dans une BOUTIQUE.$"

RadioTower1F_Text_QuizQuestion3:
    .string "Bravo !\n"
    .string "Question 3 :\p"
    .string "FARFELU, le créateur de POKé BALL,\n"
    .string "utilise-t-il des APRICORN comme ingrédients ?$"

RadioTower1F_Text_QuizQuestion4:
    .string "C'est bien parti !\n"
    .string "Question 4 :\p"
    .string "ALFRED est-il le CHAMPION de l'ARÈNE\n"
    .string "de MAUVILLE qui utilise des POKéMON oiseaux ?$"

RadioTower1F_Text_QuizQuestion5:
    .string "Wow ! Encore juste !\n"
    .string "Voici la dernière question :\p"
    .string "Y a-t-il des SALAMECHE sur les rouleaux\n"
    .string "des machines à sous du CASINO de DOUBLONVILLE ?$"

RadioTower1F_Text_QuizWin:
    .string "Bingo ! Tu as réussi !\n"
    .string "Félicitations !\p"
    .string "Voici ton prix, une RADIO !$"

RadioTower1F_Text_PokegearRadio:
    .string "Le POKéMATO de {PLAYER} fait aussi\n"
    .string "radio maintenant !$"

RadioTower1F_Text_TuneIn:
    .string "N'oublie pas d'écouter nos émissions !$"

RadioTower1F_Text_WrongAnswer:
    .string "Oh, mince.\n"
    .string "Désolé, ce n'est pas la bonne réponse.\p"
    .string "Réessaie encore !$"

RadioTower1F_Text_DeclineQuiz:
    .string "Oh, je vois. Reviens me voir si tu\n"
    .string "changes d'avis !$"

RadioTower1F_Text_Lass:
    .string "BEN est un DJ fabuleux.\p"
    .string "Sa voix douce me fait fondre !$"

RadioTower1F_Text_Youngster:
    .string "J'adore MARY, de POKéMON TALK.\p"
    .string "Je ne connais que sa voix,\n"
    .string "mais c'est suffisant !$"

RadioTower1F_Text_GruntM3Seen:
    .string "Nous avons enfin pris le contrôle de\n"
    .string "la TOUR RADIO !\p"
    .string "Tout le monde va découvrir la vraie\n"
    .string "terreur de la TEAM ROCKET !\p"
    .string "On va vous montrer à quel point on est terrifiants !$"

RadioTower1F_Text_GruntM3Beaten:
    .string "Trop fort ! Désolé, chef…$"

RadioTower1F_Text_GruntM3After:
    .string "Tu es trop fort.\p"
    .string "Notre plan pourrait échouer. Je dois\n"
    .string "prévenir les autres…$"

RadioTower1F_Text_Directory:
    .string "1F ACCUEIL\n"
    .string "2F VENTES\p"
    .string "3F PERSONNEL\n"
    .string "4F PRODUCTION\p"
    .string "5F BUREAU DU DIRECTEUR$"


GoldenrodCity_RadioTower_1F_EventScript_LotteryClerk::
	lock
	faceplayer
	dotimebasedevents
	goto_if_ne VAR_POKELOT_PRIZE_ITEM, ITEM_NONE, GoldenrodCity_RadioTower_1F_EventScript_GivePrizeFromEarlier
	goto_if_set FLAG_DAILY_PICKED_LOTO_TICKET, GoldenrodCity_RadioTower_1F_EventScript_ComeBackTomorrow
	msgbox GoldenrodCity_RadioTower_1F_Text_LotteryCornerDrawTicket, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, GoldenrodCity_RadioTower_1F_EventScript_PleaseVisitAgain
	setflag FLAG_DAILY_PICKED_LOTO_TICKET
	message GoldenrodCity_RadioTower_1F_Text_PleasePickTicket
	waitmessage
	special RetrieveLotteryNumber
	copyvar VAR_0x8008, VAR_RESULT
	special BufferLottoTicketNumber
	msgbox GoldenrodCity_RadioTower_1F_Text_TicketNumberIsXPleaseWait, MSGBOX_DEFAULT
	applymovement 4, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	playse SE_PC_ON
	@special DoLotteryCornerComputerEffect
	special PickLotteryCornerTicket
	delay 220
	@special EndLotteryCornerComputerEffect
	delay 10
	applymovement 4, Common_Movement_FacePlayer
	waitmovement 0
	goto_if_eq VAR_0x8004, 0, GoldenrodCity_RadioTower_1F_EventScript_NoMatch
	incrementgamestat GAME_STAT_WON_POKEMON_LOTTERY
	call_if_eq VAR_0x8006, 0, GoldenrodCity_RadioTower_1F_EventScript_TicketMatchPartyMon
	call_if_eq VAR_0x8006, 1, GoldenrodCity_RadioTower_1F_EventScript_TicketMatchPCMon
	bufferitemname STR_VAR_1, VAR_0x8005
	call_if_eq VAR_0x8004, 1, GoldenrodCity_RadioTower_1F_EventScript_TwoDigitMatch
	call_if_eq VAR_0x8004, 2, GoldenrodCity_RadioTower_1F_EventScript_ThreeDigitMatch
	call_if_eq VAR_0x8004, 3, GoldenrodCity_RadioTower_1F_EventScript_FourDigitMatch
	call_if_eq VAR_0x8004, 4, GoldenrodCity_RadioTower_1F_EventScript_FullMatch
	giveitem VAR_0x8005
	goto_if_eq VAR_RESULT, FALSE, GoldenrodCity_RadioTower_1F_EventScript_RecordPrizeNoRoom
	special TryPutLotteryWinnerReportOnAir
	goto GoldenrodCity_RadioTower_1F_EventScript_PleaseVisitAgain2
	end

GoldenrodCity_RadioTower_1F_EventScript_TicketMatchPartyMon::
	msgbox GoldenrodCity_RadioTower_1F_Text_TicketMatchesPartyMon, MSGBOX_DEFAULT
	return

GoldenrodCity_RadioTower_1F_EventScript_TicketMatchPCMon::
	msgbox GoldenrodCity_RadioTower_1F_Text_TicketMatchesPCMon, MSGBOX_DEFAULT
	return

GoldenrodCity_RadioTower_1F_EventScript_ComeBackTomorrow::
	msgbox GoldenrodCity_RadioTower_1F_Text_ComeBackTomorrow, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_RadioTower_1F_EventScript_PleaseVisitAgain::
	msgbox GoldenrodCity_RadioTower_1F_Text_PleaseVisitAgain, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_RadioTower_1F_EventScript_NoMatch::
	msgbox GoldenrodCity_RadioTower_1F_Text_NoNumbersMatched, MSGBOX_DEFAULT
	goto GoldenrodCity_RadioTower_1F_EventScript_PleaseVisitAgain2
	end

GoldenrodCity_RadioTower_1F_EventScript_PleaseVisitAgain2::
	msgbox GoldenrodCity_RadioTower_1F_Text_PleaseVisitAgain2, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_RadioTower_1F_EventScript_TwoDigitMatch::
	msgbox GoldenrodCity_RadioTower_1F_Text_TwoDigitsMatched, MSGBOX_DEFAULT
	return

GoldenrodCity_RadioTower_1F_EventScript_ThreeDigitMatch::
	msgbox GoldenrodCity_RadioTower_1F_Text_ThreeDigitsMatched, MSGBOX_DEFAULT
	return

GoldenrodCity_RadioTower_1F_EventScript_FourDigitMatch::
	msgbox GoldenrodCity_RadioTower_1F_Text_FourDigitsMatched, MSGBOX_DEFAULT
	return

GoldenrodCity_RadioTower_1F_EventScript_FullMatch::
	msgbox GoldenrodCity_RadioTower_1F_Text_AllFiveDigitsMatched, MSGBOX_DEFAULT
	return

GoldenrodCity_RadioTower_1F_EventScript_RecordPrizeNoRoom::
	copyvar VAR_POKELOT_PRIZE_PLACE, VAR_0x8004
	copyvar VAR_POKELOT_PRIZE_ITEM, VAR_0x8005
	goto GoldenrodCity_RadioTower_1F_EventScript_NoRoomForPrize
	end

GoldenrodCity_RadioTower_1F_EventScript_NoRoomForPrize::
	msgbox GoldenrodCity_RadioTower_1F_Text_NoRoomForThis, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_RadioTower_1F_EventScript_GivePrizeFromEarlier::
	msgbox GoldenrodCity_RadioTower_1F_Text_PrizeWeveBeenHolding, MSGBOX_DEFAULT
	giveitem VAR_POKELOT_PRIZE_ITEM
	goto_if_eq VAR_RESULT, FALSE, GoldenrodCity_RadioTower_1F_EventScript_NoRoomForPrize
	copyvar VAR_0x8004, VAR_POKELOT_PRIZE_PLACE
	copyvar VAR_0x8005, VAR_POKELOT_PRIZE_ITEM
	special TryPutLotteryWinnerReportOnAir
	setvar VAR_POKELOT_PRIZE_ITEM, ITEM_NONE
	setvar VAR_POKELOT_PRIZE_PLACE, 0
	release
	end

GoldenrodCity_RadioTower_1F_Text_LotteryCornerDrawTicket:
	.string "Bienvenue au COIN LOTERIE POKéMON.\p"
	.string "Si le numéro de votre TICKET LOTO\n"
	.string "correspond à l'ID d'un de vos POKéMON,\l"
	.string "vous recevrez un fabuleux cadeau.\p"
	.string "Voulez-vous tirer un TICKET LOTO\n"
	.string "POKéMON ?$"

GoldenrodCity_RadioTower_1F_Text_ComeBackTomorrow:
	.string "Veuillez revenir demain.$"

GoldenrodCity_RadioTower_1F_Text_PleaseVisitAgain:
	.string "Revenez nous voir !$"

GoldenrodCity_RadioTower_1F_Text_PleasePickTicket:
	.string "Veuillez choisir un TICKET LOTO.\n"
	.string "…{PAUSE 0x0F}{PAUSE 0x0F}{PAUSE 0x0F}{PAUSE 0x0F}…{PAUSE 0x0F}{PAUSE 0x0F}{PAUSE 0x0F}{PAUSE 0x0F}…{PAUSE 0x0F}{PAUSE 0x0F}{PAUSE 0x0F}{PAUSE 0x0F}$"

GoldenrodCity_RadioTower_1F_Text_TicketNumberIsXPleaseWait:
	.string "Le numéro du TICKET LOTO est {STR_VAR_1}.\p"
	.string "Je vais vérifier si ce numéro\n"
	.string "correspond à l'ID d'un de vos\l"
	.string "POKéMON. Veuillez patienter.$"

GoldenrodCity_RadioTower_1F_Text_TicketMatchesPartyMon:
	.string "Félicitations !\p"
	.string "L'ID de votre {STR_VAR_1} dans\n"
	.string "l'équipe correspond au numéro\l"
	.string "de votre TICKET LOTO !$"

GoldenrodCity_RadioTower_1F_Text_TicketMatchesPCMon:
	.string "Félicitations !\p"
	.string "L'ID de votre {STR_VAR_1} dans le PC\n"
	.string "correspond au numéro de votre\l"
	.string "TICKET LOTO !$"

GoldenrodCity_RadioTower_1F_Text_NoNumbersMatched:
	.string "Je suis désolée.\n"
	.string "Aucun numéro ne correspond.$"

GoldenrodCity_RadioTower_1F_Text_TwoDigitsMatched:
	.string "Deux chiffres correspondent, vous gagnez\n"
	.string "le troisième prix !\l"
	.string "Vous avez gagné {STR_VAR_1} !$"

GoldenrodCity_RadioTower_1F_Text_ThreeDigitsMatched:
	.string "Trois chiffres correspondent, vous gagnez\n"
	.string "le deuxième prix !\l"
	.string "Vous avez gagné {STR_VAR_1} !$"

GoldenrodCity_RadioTower_1F_Text_FourDigitsMatched:
	.string "Quatre chiffres correspondent, vous gagnez\n"
	.string "le premier prix !\l"
	.string "Vous avez gagné {STR_VAR_1} !$"

GoldenrodCity_RadioTower_1F_Text_AllFiveDigitsMatched:
	.string "Oh, incroyable, les cinq chiffres\n"
	.string "correspondent !\p"
	.string "Vous avez gagné le gros lot !\n"
	.string "Vous avez gagné {STR_VAR_1} !$"

GoldenrodCity_RadioTower_1F_Text_NoRoomForThis:
	.string "Oh ?\n"
	.string "Vous n'avez plus de place pour cela.\p"
	.string "Veuillez faire de la place dans votre SAC\n"
	.string "et revenez me voir.$"

GoldenrodCity_RadioTower_1F_Text_PrizeWeveBeenHolding:
	.string "{PLAYER} ?\n"
	.string "Oui, je vous attendais.\p"
	.string "Voici le prix que nous gardions\n"
	.string "pour vous.$"

GoldenrodCity_RadioTower_1F_Text_PleaseVisitAgain2:
	.string "Revenez nous voir !$"


