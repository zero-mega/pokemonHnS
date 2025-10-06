PacifidlogTown_House2_MapScripts::
	.byte 0

PacifidlogTown_House2_EventScript_FanClubYoungerBrother::
	lock
	faceplayer
	dotimebasedevents
	call PacifidlogTown_House2_EventScript_UpdateFanClubTMFlag
	goto_if_set FLAG_RECEIVED_FANCLUB_TM_THIS_WEEK, PacifidlogTown_House2_EventScript_ComeBackInXDays
	call_if_set FLAG_MET_FANCLUB_YOUNGER_BROTHER, PacifidlogTown_House2_EventScript_MonAssessment
	call_if_unset FLAG_MET_FANCLUB_YOUNGER_BROTHER, PacifidlogTown_House2_EventScript_FirstMonAssessment
	setflag FLAG_MET_FANCLUB_YOUNGER_BROTHER
	goto_if_set FLAG_FINITE_TMS, PacifidlogTown_House2_EventScript_FanClubYoungerBrotherFinite
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	goto_if_ge VAR_RESULT, FRIENDSHIP_150_TO_199, PacifidlogTown_House2_EventScript_GiveReturn
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	goto_if_ge VAR_RESULT, FRIENDSHIP_50_TO_99, PacifidlogTown_House2_EventScript_PutInEffort
	goto PacifidlogTown_House2_EventScript_GiveFrustration
	end

PacifidlogTown_House2_EventScript_FanClubYoungerBrotherFinite::
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	goto_if_ge VAR_RESULT, FRIENDSHIP_150_TO_199, PacifidlogTown_House2_EventScript_GiveReturnFinite
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	goto_if_ge VAR_RESULT, FRIENDSHIP_50_TO_99, PacifidlogTown_House2_EventScript_PutInEffort
	goto PacifidlogTown_House2_EventScript_GiveFrustrationFinite
	end

PacifidlogTown_House2_EventScript_UpdateFanClubTMFlag::
	goto_if_unset FLAG_RECEIVED_FANCLUB_TM_THIS_WEEK, Common_EventScript_NopReturn
	specialvar VAR_RESULT, GetDaysUntilPacifidlogTMAvailable
	call_if_eq VAR_RESULT, 0, PacifidlogTown_House2_EventScript_ClearReceivedFanClubTM
	return

PacifidlogTown_House2_EventScript_MonAssessment::
	msgbox PacifidlogTown_House2_Text_AhYourPokemon, MSGBOX_DEFAULT
	return

PacifidlogTown_House2_EventScript_FirstMonAssessment::
	msgbox PacifidlogTown_House2_Text_ChairmansYoungerBrotherOnVacation, MSGBOX_DEFAULT
	msgbox PacifidlogTown_House2_Text_AhYourPokemon, MSGBOX_DEFAULT
	return

PacifidlogTown_House2_EventScript_ClearReceivedFanClubTM::
	clearflag FLAG_RECEIVED_FANCLUB_TM_THIS_WEEK
	return

PacifidlogTown_House2_EventScript_GiveReturnFinite::
	msgbox PacifidlogTown_House2_Text_AdoringPokemonTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_TM_RETURN
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_FANCLUB_TM_THIS_WEEK
	special SetPacifidlogTMReceivedDay
	msgbox PacifidlogTown_House2_Text_ExplainReturnFrustration, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_EventScript_GiveReturn::
	msgbox PacifidlogTown_House2_Text_AdoringPokemonTakeThis, MSGBOX_DEFAULT
	checkitem ITEM_TM27
	goto_if_eq VAR_RESULT, TRUE, PacifidlogTown_House2_EventScript_GiveReturnDone
	giveitem ITEM_TM27
	@goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_FANCLUB_TM_THIS_WEEK
	special SetPacifidlogTMReceivedDay
	msgbox PacifidlogTown_House2_Text_ExplainReturnFrustration, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_EventScript_GiveReturnDone::
	msgbox PacifidlogTown_House2_Text_GiveReturnDone, MSGBOX_NPC
	release
	end

PacifidlogTown_House2_Text_GiveReturnDone:
	.string "Oh, you already have it.$"

PacifidlogTown_House2_EventScript_PutInEffort::
	msgbox PacifidlogTown_House2_Text_PutInSomeMoreEffort, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_EventScript_GiveFrustrationFinite::
	msgbox PacifidlogTown_House2_Text_ViciousPokemonTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_TM_FRUSTRATION
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_FANCLUB_TM_THIS_WEEK
	special SetPacifidlogTMReceivedDay
	msgbox PacifidlogTown_House2_Text_ExplainReturnFrustration, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_EventScript_GiveFrustration::
	msgbox PacifidlogTown_House2_Text_ViciousPokemonTakeThis, MSGBOX_DEFAULT
	checkitem ITEM_TM21
	goto_if_eq VAR_RESULT, TRUE, PacifidlogTown_House2_EventScript_GiveReturnDone
	giveitem ITEM_TM21
	@goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_FANCLUB_TM_THIS_WEEK
	special SetPacifidlogTMReceivedDay
	msgbox PacifidlogTown_House2_Text_ExplainReturnFrustration, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_EventScript_ComeBackInXDays::
	specialvar VAR_RESULT, GetDaysUntilPacifidlogTMAvailable
	buffernumberstring STR_VAR_1, VAR_RESULT
	msgbox PacifidlogTown_House2_Text_GetGoodTMInXDays, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_EventScript_HappyAzurill::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZURILL, CRY_MODE_NORMAL
	msgbox PacifidlogTown_House2_Text_Rurii, MSGBOX_DEFAULT
	waitmoncry
	msgbox PacifidlogTown_House2_Text_VeryFriendlyWithTrainer, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_EventScript_UnhappyAzurill::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZURILL, CRY_MODE_ENCOUNTER
	msgbox PacifidlogTown_House2_Text_Rururi, MSGBOX_DEFAULT
	waitmoncry
	msgbox PacifidlogTown_House2_Text_DoesntLikeTrainerVeryMuch, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_Text_ChairmansYoungerBrotherOnVacation:
	.string "Hum-hum !\p"
	.string "Je suis la personne la plus importante\n"
	.string "du CLUB des FANS de POKéMON, le\l"
	.string "petit frère du PRÉSIDENT.\p"
	.string "Je profite de mes vacances ici avec\n"
	.string "des POKéMON, oui, en effet.$"

PacifidlogTown_House2_Text_AhYourPokemon:
	.string "Ah !\n"
	.string "Ton POKéMON…$"

PacifidlogTown_House2_Text_AdoringPokemonTakeThis:
	.string "Il t’aime vraiment beaucoup, c’est clair.\p"
	.string "Un POKéMON aussi adorable et affectueux\n"
	.string "mérite une CT comme celle-ci, non ?$"

PacifidlogTown_House2_Text_PutInSomeMoreEffort:
	.string "Hmm…\n"
	.string "Ce n’est pas mal, mais ce n’est pas bien non plus.\p"
	.string "Toi, en tant que DRESSEUR, tu dois faire\n"
	.string "plus d’efforts.$"

PacifidlogTown_House2_Text_ViciousPokemonTakeThis:
	.string "Il a un regard féroce.\p"
	.string "Un POKéMON aussi effrayant\n"
	.string "mérite une CT comme celle-ci.$"

PacifidlogTown_House2_Text_ExplainReturnFrustration:
	.string "Si un POKéMON t’aime beaucoup, la\n"
	.string "puissance de RETOUR augmente.\p"
	.string "S’il ne t’aime pas, la puissance de\n"
	.string "FRUSTRATION augmente.$"

PacifidlogTown_House2_Text_GetGoodTMInXDays:
	.string "Oh, oui. Dans environ {STR_VAR_1} jours,\n"
	.string "je devrais recevoir une ou deux bonnes CT.\p"
	.string "Tu devrais revenir me voir alors.\n"
	.string "Je te donnerai une CT adaptée à\l"
	.string "ton POKéMON.$"

PacifidlogTown_House2_Text_Rurii:
	.string "AZURILL : Rurii.$"

PacifidlogTown_House2_Text_VeryFriendlyWithTrainer:
	.string "Il semble être très attaché à son\n"
	.string "DRESSEUR.$"

PacifidlogTown_House2_Text_Rururi:
	.string "AZURILL : Rururi !$"

PacifidlogTown_House2_Text_DoesntLikeTrainerVeryMuch:
	.string "Il ne semble pas beaucoup aimer son\n"
	.string "DRESSEUR.$"
