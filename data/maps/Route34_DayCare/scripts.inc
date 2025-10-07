.set LOCALID_DAYCARE_LADY, 1

Route34_DayCare_MapScripts::
	.byte 0

Route34_DayCare_Bookshelf1::
	msgbox Route34_DayCare_Text_Bookshelf1, MSGBOX_SIGN
	end

Route34_DayCare_Bookshelf2::
	msgbox Route34_DayCare_Text_Bookshelf2, MSGBOX_SIGN
	end

Route34_DayCare_Bookshelf3::
	msgbox Route34_DayCare_Text_Bookshelf3, MSGBOX_SIGN
	end

Route34_DayCare_Bookshelf4::
	msgbox Route34_DayCare_Text_Bookshelf4, MSGBOX_SIGN
	end

Route34_DayCare_Text_Bookshelf1:
	.string "Un dictionnaire !\p"
	.string "{PLAYER} ouvre le dictionnaire à\n"
	.string "une page au hasard.\p"
	.string "'BÉBÉ'\n"
	.string "Nom, signifiant nourrisson ou bébé.\p"
	.string "{PLAYER} range le dictionnaire.$"

Route34_DayCare_Text_Bookshelf2:
	.string "Un livre sur les POKéMON !\p"
	.string "{PLAYER} feuillette\n"
	.string "le livre.\p"
	.string "Il doit y avoir le mot\n"
	.string "POKéMON écrit sur chaque page.\p"
	.string "{PLAYER} range le livre.$"

Route34_DayCare_Text_Bookshelf3:
	.string "Un livre d'associations de mots !\p"
	.string "{PLAYER} feuillette\n"
	.string "le livre.\p"
	.string "PICHU -> MIGNON\l"
	.string "CLEFFA -> MIGNON\l"
	.string "IGGLYBUFF -> CHANSON\l"
	.string "TYROGUE -> COMBAT\l"
	.string "SMOOCHUM -> GLACE\l"
	.string "ELEKID -> ÉLECTRIQUE\l"
	.string "MAGBY -> FEU\p"
	.string "{PLAYER} range le livre.$"

Route34_DayCare_Text_Bookshelf4:
	.string "Un livre sur les natures des POKéMON !\p"
	.string "{PLAYER} feuillette\n"
	.string "le livre.\p"
	.string "PICHU -> STATIK\l"
	.string "CLEFFA -> JOLI SOURIRE\l"
	.string "IGGLYBUFF -> JOLI SOURIRE\l"
	.string "TYROGUE -> CRAN\l"
	.string "SMOOCHUM -> BENÊT\l"
	.string "ELEKID -> STATIK\l"
	.string "MAGBY -> CORPS ARDENT\p"
	.string "{PLAYER} range le livre.$"

Route34_DayCare_EventScript_Clerk::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_ODD_EGG, Route34_DayCare_EventScript_ClerkAfter
	msgbox Route34_DayCare_Text_ClerkBefore, MSGBOX_DEFAULT
	getpartysize
	goto_if_eq VAR_RESULT, PARTY_SIZE, Route34_DayCare_EventScript_ClerkPartyFull
	msgbox Route34_DayCare_Text_ClerkQuestion, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, EASY_CHAT_TYPE_INTERVIEW
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	switch VAR_RESULT
	case 0, Route34_DayCare_EventScript_ClerkRejection
	case 1, Route34_DayCare_EventScript_GivePichu
	case 2, Route34_DayCare_EventScript_GiveCleffa
	case 3, Route34_DayCare_EventScript_GiveIgglybuff
	case 4, Route34_DayCare_EventScript_GiveTyrogue
	case 5, Route34_DayCare_EventScript_GiveSmoochum
	case 6, Route34_DayCare_EventScript_GiveElekid
	case 7, Route34_DayCare_EventScript_GiveMagby
	closemessage
	release
	end

Route34_DayCare_EventScript_GivePichu::
	giveoddegg 1
	goto Route34_DayCare_EventScript_Clerk_GaveEgg

Route34_DayCare_EventScript_GiveCleffa::
	giveoddegg 2
	goto Route34_DayCare_EventScript_Clerk_GaveEgg

Route34_DayCare_EventScript_GiveIgglybuff::
	giveoddegg 3
	goto Route34_DayCare_EventScript_Clerk_GaveEgg

Route34_DayCare_EventScript_GiveTyrogue::
	giveoddegg 4
	goto Route34_DayCare_EventScript_Clerk_GaveEgg

Route34_DayCare_EventScript_GiveSmoochum::
	giveoddegg 5
	goto Route34_DayCare_EventScript_Clerk_GaveEgg

Route34_DayCare_EventScript_GiveElekid::
	giveoddegg 6
	goto Route34_DayCare_EventScript_Clerk_GaveEgg

Route34_DayCare_EventScript_GiveMagby::
	giveoddegg 7
	goto Route34_DayCare_EventScript_Clerk_GaveEgg

Route34_DayCare_EventScript_Clerk_GaveEgg::
	msgbox Route34_DayCare_Text_TakeCare, MSGBOX_DEFAULT
	closemessage
	delay 30
	setflag FLAG_RECEIVED_ODD_EGG
	playfanfare MUS_OBTAIN_ITEM
	message Route34_DayCare_Text_ReceivedOddEgg
	waitfanfare
	closemessage
	release
	end

Route34_DayCare_EventScript_ClerkPartyFull::
	msgbox Route34_DayCare_Text_ClerkNoRoom, MSGBOX_DEFAULT
	closemessage
	release
	end

Route34_DayCare_EventScript_ClerkRejection::
	msgbox Route34_DayCare_Text_Rejection, MSGBOX_DEFAULT
	closemessage
	release
	end

Route34_DayCare_EventScript_ClerkAfter::
	msgbox Route34_DayCare_Text_ClerkAfter, MSGBOX_DEFAULT
	closemessage
	release
	end

Route34_DayCare_Text_ClerkBefore:
	.string "Je suis le fils du couple de la PENSION.\p"
	.string "Un ŒUF ÉTRANGE a été trouvé avec le\n"
	.string "POKéMON d'un dresseur, mais il n'en voulait pas...\p"
	.string "Je pourrais te l'offrir...\n"
	.string "Mais comment savoir si tu t'en occuperas\l"
	.string "bien ?$"

Route34_DayCare_Text_ClerkNoRoom:
	.string "On dirait que tu ne peux pas porter\n"
	.string "un autre POKéMON de toute façon.$"

Route34_DayCare_Text_ClerkQuestion:
	.string "Réponds à cette question pour moi.\n"
	.string "Que penses-tu de cet ŒUF ÉTRANGE ?$"

Route34_DayCare_Text_Rejection:
	.string "Hmm, je pense que cet œuf n'est pas pour toi.$"

Route34_DayCare_Text_ReceivedOddEgg:
	.string "{PLAYER} a reçu l'ŒUF ÉTRANGE.$"

Route34_DayCare_Text_TakeCare:
	.string "Je savais que tu étais le bon dresseur\n"
	.string "pour ça. Prends-en bien soin !$"

Route34_DayCare_Text_ClerkAfter:
	.string "On voit beaucoup de ces œufs par ici.\n"
	.string "\p"
	.string "Mais celui-là était différent des autres.$"

Route34_DayCare_EventScript_Ditto::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_DITTO, CRY_MODE_NORMAL
	msgbox Route34_DayCare_Text_Ditto, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route34_DayCare_Text_Ditto:
	.string "DITTO: Tto!$"

Route34_EventScript_DaycareMan::
	lock
	faceplayer
	special GetDaycareMonNicknames
	specialvar VAR_RESULT, GetDaycareState
	goto_if_eq VAR_RESULT, DAYCARE_EGG_WAITING, Route34_EventScript_DaycareEggWaiting
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route34_EventScript_CheckOnOneMon
	goto_if_eq VAR_RESULT, DAYCARE_TWO_MONS, Route34_EventScript_CheckOnTwoMons
	msgbox Route34_Text_SeeWifeIfYoudLikeMeToRaiseMon, MSGBOX_DEFAULT
	release
	end

Route34_EventScript_DaycareEggWaiting::
	msgbox Route34_Text_DoYouWantEgg, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route34_EventScript_DaycareAcceptEgg
	msgbox Route34_Text_IWillKeepDoYouWantIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route34_EventScript_DaycareAcceptEgg
	msgbox Route34_Text_IllKeepIt, MSGBOX_DEFAULT
	clearflag FLAG_PENDING_DAYCARE_EGG
	special RejectEggFromDayCare
	release
	end

Route34_EventScript_DaycareAcceptEgg::
	specialvar VAR_0x8004, GetMaxPartySize @ tx_randomizer_and_challenges
	specialvar VAR_RESULT, CalculatePlayerPartyCount
	goto_if_ne VAR_RESULT, VAR_0x8004, Route34_EventScript_DaycareReceiveEgg
	msgbox Route34_Text_YouHaveNoRoomForIt, MSGBOX_DEFAULT
	release
	end

Route34_EventScript_DaycareReceiveEgg::
	message Route34_Text_ReceivedEgg
	playfanfare MUS_LEVEL_UP
	waitfanfare
	waitbuttonpress
	msgbox Route34_Text_TakeGoodCareOfIt, MSGBOX_DEFAULT
	special GiveEggFromDaycare
	clearflag FLAG_PENDING_DAYCARE_EGG
	release
	end

Route34_EventScript_CheckMonReceivedMail::
	specialvar VAR_RESULT, CheckDaycareMonReceivedMail
	call_if_eq VAR_RESULT, 1, Route34_EventScript_MonReceivedMail
	return

Route34_EventScript_MonReceivedMail::
	msgbox Route34_Text_FriendlyWithOtherTrainersMon, MSGBOX_DEFAULT
	return

Route34_EventScript_CheckOnOneMon::
	special GetDaycareMonNicknames
	msgbox Route34_Text_YourMonIsDoingFine, MSGBOX_DEFAULT
	setvar VAR_0x8004, 0
	call Route34_EventScript_CheckMonReceivedMail
	release
	end

Route34_EventScript_CheckOnTwoMons::
	special GetDaycareMonNicknames
	msgbox Route34_Text_YourMonsAreDoingFine, MSGBOX_DEFAULT
	special SetDaycareCompatibilityString
	special ShowFieldMessageStringVar4
	waitmessage
	waitbuttonpress
	setvar VAR_0x8004, 0
	call Route34_EventScript_CheckMonReceivedMail
	setvar VAR_0x8004, 1
	call Route34_EventScript_CheckMonReceivedMail
	release
	end

Route34_DayCare_EventScript_DaycareWoman::
	lock
	faceplayer
	specialvar VAR_RESULT, GetDaycareState
	goto_if_eq VAR_RESULT, DAYCARE_EGG_WAITING, Route34_DayCare_EventScript_EggWaiting
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route34_DayCare_EventScript_OneMonInDaycare
	goto_if_eq VAR_RESULT, DAYCARE_TWO_MONS, Route34_DayCare_EventScript_TwoMonsInDaycare
	msgbox Route34_DayCare_Text_WouldYouLikeUsToRaiseAMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route34_DayCare_EventScript_GiveMonToRaise
	msgbox Route34_DayCare_Text_FineThenComeAgain, MSGBOX_DEFAULT
	release
	end

Route34_DayCare_EventScript_GiveMonToRaise::
	specialvar VAR_RESULT, CountPartyNonEggMons
	goto_if_eq VAR_RESULT, 1, Route34_DayCare_EventScript_OnlyOneMon
	specialvar VAR_RESULT, CountPartyAliveNonEggMons
	goto_if_eq VAR_RESULT, 2, Route34_DayCare_EventScript_OnlyTwoAliveMons
	msgbox Route34_DayCare_Text_WhichMonShouldWeRaise, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	special ChooseSendDaycareMon
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, Route34_DayCare_EventScript_ComeAgain
	specialvar VAR_RESULT, CountPartyAliveNonEggMons_IgnoreVar0x8004Slot
	goto_if_eq VAR_RESULT, 0, Route34_DayCare_EventScript_OnlyOneAliveMon
	specialvar VAR_0x8005, GetSelectedMonNicknameAndSpecies
	waitse
	playmoncry VAR_0x8005, CRY_MODE_NORMAL
	msgbox Route34_DayCare_Text_WellRaiseYourMon, MSGBOX_DEFAULT
	waitmoncry
	special StoreSelectedPokemonInDaycare
	callnative UpdateFollowingPokemon
	incrementgamestat GAME_STAT_USED_DAYCARE
	specialvar VAR_RESULT, GetDaycareState
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route34_DayCare_EventScript_CanRaiseOneMore
	release
	end

Route34_DayCare_EventScript_ComeAgain::
	msgbox Route34_DayCare_Text_ComeAgain, MSGBOX_DEFAULT
	release
	end

Route34_DayCare_EventScript_CanRaiseOneMore::
	msgbox Route34_DayCare_Text_WeCanRaiseOneMore, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route34_DayCare_EventScript_GiveMonToRaise
	goto Route34_DayCare_EventScript_ComeAgain
	end

Route34_DayCare_EventScript_OnlyOneMon::
	msgbox Route34_DayCare_Text_YouHaveJustOneMon, MSGBOX_DEFAULT
	release
	end

Route34_DayCare_EventScript_OnlyOneAliveMon::
	msgbox Route34_DayCare_Text_WhatWillYouBattleWith, MSGBOX_DEFAULT
	release
	end

Route34_DayCare_EventScript_OnlyTwoAliveMons::
	msgbox Route34_DayCare_Text_YoullBeLeftWithJustOne, MSGBOX_DEFAULT
	release
	end

Route34_DayCare_EventScript_EggWaiting::
	msgbox Route34_DayCare_Text_HusbandWasLookingForYou, MSGBOX_DEFAULT
	release
	end

Route34_DayCare_EventScript_YourMonHasGrownXLevels::
	msgbox Route34_DayCare_Text_YourMonHasGrownXLevels, MSGBOX_DEFAULT
	return

Route34_DayCare_EventScript_DisplayLevelsGained::
	specialvar VAR_RESULT, GetNumLevelsGainedFromDaycare
	call_if_ne VAR_RESULT, 0, Route34_DayCare_EventScript_YourMonHasGrownXLevels
	return

Route34_DayCare_EventScript_OneMonInDaycare::
	msgbox Route34_DayCare_Text_GoodToSeeYou, MSGBOX_DEFAULT
	setvar VAR_0x8004, 0
	call Route34_DayCare_EventScript_DisplayLevelsGained
	msgbox Route34_DayCare_Text_WeCanRaiseOneMore, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route34_DayCare_EventScript_GiveMonToRaise
	msgbox Route34_DayCare_Text_TakeYourMonBack, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route34_DayCare_EventScript_TryRetrieveMon
	goto Route34_DayCare_EventScript_ComeAgain
	end

Route34_DayCare_EventScript_TryRetrieveMon::
	specialvar VAR_0x8004, GetMaxPartySize @ tx_randomizer_and_challenges
	specialvar VAR_RESULT, CalculatePlayerPartyCount
	goto_if_eq VAR_RESULT, VAR_0x8004, Route34_DayCare_EventScript_NoRoom
	specialvar VAR_RESULT, GetDaycareState
	setvar VAR_0x8004, 0
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route34_DayCare_EventScript_CostPrompt
	special ShowDaycareLevelMenu
	waitstate
	copyvar VAR_0x8004, VAR_RESULT
	goto_if_eq VAR_RESULT, DAYCARE_EXITED_LEVEL_MENU, Route34_DayCare_EventScript_ComeAgain
	goto Route34_DayCare_EventScript_CostPrompt
	end

Route34_DayCare_EventScript_CostPrompt::
	special GetDaycareCost
	msgbox Route34_DayCare_Text_ItWillCostX, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route34_DayCare_EventScript_CheckEnoughMoney
	goto Route34_DayCare_EventScript_ComeAgain
	end

Route34_DayCare_EventScript_CheckEnoughMoney::
	specialvar VAR_RESULT, IsEnoughForCostInVar0x8005
	goto_if_eq VAR_RESULT, 1, Route34_DayCare_EventScript_RetrieveMon
	msgbox Route34_DayCare_Text_NotEnoughMoney, MSGBOX_DEFAULT
	release
	end

Route34_DayCare_EventScript_RetrieveMon::
	@applymovement LOCALID_DAYCARE_LADY, Route34_DayCare_Movement_RetrieveDaycareMon
	@waitmovement 0
	specialvar VAR_RESULT, TakePokemonFromDaycare
	special SubtractMoneyFromVar0x8005
	playse SE_SHOP
	msgbox Route34_DayCare_Text_HeresYourMon, MSGBOX_DEFAULT
	waitse
	playmoncry VAR_RESULT, CRY_MODE_NORMAL
	msgbox Route34_DayCare_Text_TookBackMon, MSGBOX_DEFAULT
	waitmoncry
	specialvar VAR_RESULT, GetDaycareState
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route34_DayCare_EventScript_AskRetrieveOtherMon
	goto Route34_DayCare_EventScript_ComeAgain
	end

Route34_DayCare_EventScript_AskRetrieveOtherMon::
	msgbox Route34_DayCare_Text_TakeOtherOneBackToo, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route34_DayCare_EventScript_TryRetrieveMon
	goto Route34_DayCare_EventScript_ComeAgain
	end

Route34_DayCare_EventScript_NoRoom::
	msgbox Route34_DayCare_Text_YourTeamIsFull, MSGBOX_DEFAULT
	release
	end

Route34_DayCare_Movement_RetrieveDaycareMon:
	delay_16
	delay_16
	face_left
	delay_16
	delay_16
	face_right
	delay_16
	delay_16
	face_up
	walk_slow_up
	set_invisible
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	face_down
	set_visible
	walk_slow_down
	step_end

@ Unused. Possibly a commented script, or a typo end added to the above Movement script
Route34_DayCare_EventScript_UnusedEnd::
	end

Route34_DayCare_EventScript_TwoMonsInDaycare::
	msgbox Route34_DayCare_Text_GoodToSeeYou, MSGBOX_DEFAULT
	setvar VAR_0x8004, 0
	call Route34_DayCare_EventScript_DisplayLevelsGained
	setvar VAR_0x8004, 1
	call Route34_DayCare_EventScript_DisplayLevelsGained
	msgbox Route34_DayCare_Text_TakeYourMonBack, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route34_DayCare_EventScript_TryRetrieveMon
	msgbox Route34_DayCare_Text_ComeAgain, MSGBOX_DEFAULT
	release
	end

Route34_Text_SeeWifeIfYoudLikeMeToRaiseMon:
	.string "Je suis le PENSIONNAIRE.\p"
	.string "J’aide à prendre soin des précieux\n"
	.string "POKéMON des DRESSEURS.\p"
	.string "Si tu veux que je m’occupe de ton POKéMON,\n"
	.string "parle à ma femme.$"

Route34_Text_DoYouWantEgg:
	.string "Ah, c’est toi !\p"
	.string "Nous élevions ton POKéMON,\n"
	.string "et quelle surprise nous avons eue !\p"
	.string "Ton POKéMON a pondu un ŒUF !\p"
	.string "Nous ne savons pas comment c’est arrivé,\n"
	.string "mais ton POKéMON l’a eu.\p"
	.string "Tu le veux, n’est-ce pas ?$"

Route34_Text_YourMonIsDoingFine:
	.string "Ah, c’est toi ! Content de te voir.\n"
	.string "Ton {STR_VAR_1} se porte bien.$"

Route34_Text_IllKeepIt:
	.string "Très bien, je vais le garder.\n"
	.string "Merci !$"

Route34_Text_YouHaveNoRoomForIt:
	.string "Tu n’as pas de place pour lui…\n"
	.string "Reviens quand tu auras fait de la place.$"

Route34_Text_ReceivedEgg:
	.string "{PLAYER} a reçu l’ŒUF de la part\n"
	.string "du PENSIONNAIRE.$"

Route34_Text_TakeGoodCareOfIt:
	.string "Prends-en bien soin.$"

Route34_Text_FriendlyWithOtherTrainersMon:
	.string "Au fait, à propos de ton {STR_VAR_1},\n"
	.string "il semblait être ami avec\l"
	.string "le {STR_VAR_3} de {STR_VAR_2}.\p"
	.string "Je l’ai même vu recevoir\n"
	.string "un morceau de COURRIER.$"

@ Unused
Route34_Text_SeeWifeIfYouWantToPickUpMon:
	.string "Si tu veux récupérer ton POKéMON,\n"
	.string "parle à ma femme.$"

Route34_Text_YourMonsAreDoingFine:
	.string "Ah, c’est toi ! Tes {STR_VAR_1} et\n"
	.string "{STR_VAR_2} se portent bien.$"

Route34_Text_IWillKeepDoYouWantIt:
	.string "Je vais vraiment le garder.\n"
	.string "Tu le veux, n’est-ce pas ?$"

Route34_DayCare_Text_WouldYouLikeUsToRaiseAMon:
	.string "Je suis la PENSIONNAIRE.\p"
	.string "Nous pouvons élever un POKéMON pour toi.\p"
	.string "Veux-tu que nous en élevions un ?$"

Route34_DayCare_Text_WhichMonShouldWeRaise:
	.string "Quel POKéMON veux-tu que nous élevions\n"
	.string "pour toi ?$"

Route34_DayCare_Text_WellRaiseYourMon:
	.string "Très bien, nous allons élever ton {STR_VAR_1}\n"
	.string "pendant un moment.\p"
	.string "Reviens le chercher plus tard.$"

Route34_DayCare_Text_WeCanRaiseOneMore:
	.string "Nous pouvons élever deux de tes POKéMON.\n"
	.string "Veux-tu que nous en élevions un autre ?$"

Route34_DayCare_Text_HusbandWasLookingForYou:
	.string "Mon mari te cherchait.$"

Route34_DayCare_Text_FineThenComeAgain:
	.string "Bon, d’accord alors.\n"
	.string "Reviens nous voir.$"

Route34_DayCare_Text_NotEnoughMoney:
	.string "Tu n’as pas assez d’argent…$"

Route34_DayCare_Text_TakeOtherOneBackToo:
	.string "Veux-tu aussi récupérer l’autre ?$"

Route34_DayCare_Text_ComeAgain:
	.string "Très bien.\n"
	.string "Reviens nous voir.$"

Route34_DayCare_Text_GoodToSeeYou:
	.string "Ah, c’est toi ! Content de te voir.\n"
	.string "Tes POKéMON ne peuvent qu’aller bien !$"

Route34_DayCare_Text_YourMonHasGrownXLevels:
	.string "Ton {STR_VAR_1} a gagné\n"
	.string "{STR_VAR_2} niveaux.$"

Route34_DayCare_Text_YourTeamIsFull:
	.string "Ton équipe de POKéMON est pleine.\n"
	.string "Fais de la place, puis reviens me voir.$"

@ Unused
Route34_DayCare_Text_TakeBackWhichMon:
	.string "Quel POKéMON veux-tu récupérer ?$"

Route34_DayCare_Text_ItWillCostX:
	.string "Si tu veux récupérer ton {STR_VAR_1},\n"
	.string "cela coûtera ¥{STR_VAR_2}.$"

Route34_DayCare_Text_HeresYourMon:
	.string "Parfait !\n"
	.string "Voici ton POKéMON.$"

Route34_DayCare_Text_TookBackMon:
	.string "{PLAYER} a récupéré {STR_VAR_1} auprès\n"
	.string "de la PENSIONNAIRE.$"

Route34_DayCare_Text_YouHaveJustOneMon:
	.string "Oh ? Mais tu n’as qu’un seul\n"
	.string "POKéMON.\p"
	.string "Reviens une autre fois.$"

Route34_DayCare_Text_TakeYourMonBack:
	.string "Veux-tu récupérer ton POKéMON ?$"

Route34_DayCare_Text_WhatWillYouBattleWith:
	.string "Si tu me laisses ce POKéMON,\n"
	.string "avec quoi vas-tu combattre ?\p"
	.string "Reviens une autre fois.$"

Route34_DayCare_Text_YoullBeLeftWithJustOne:
	.string "Hein ?\n"
	.string "Allons, allons.\p"
	.string "Si tu me laisses ce POKéMON,\n"
	.string "il ne t’en restera qu’un.\p"
	.string "Tu ferais mieux d’en attraper d’autres,\n"
	.string "je pense.$"
