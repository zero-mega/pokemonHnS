FortreeCity_House2_MapScripts::
	.byte 0

FortreeCity_House2_EventScript_HiddenPowerGiver::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_HIDDEN_POWER, FortreeCity_House2_EventScript_ExplainHiddenPower
	call_if_unset FLAG_MET_HIDDEN_POWER_GIVER, FortreeCity_House2_EventScript_Greeting
	msgbox FortreeCity_House2_Text_CoinInWhichHand, MSGBOX_DEFAULT
	multichoice 21, 8, MULTI_RIGHTLEFT, TRUE
	switch VAR_RESULT
	case 1, FortreeCity_House2_EventScript_WrongGuess
	msgbox FortreeCity_House2_Text_CorrectTryAgainWhichHand, MSGBOX_DEFAULT
	multichoice 21, 8, MULTI_RIGHTLEFT, TRUE
	switch VAR_RESULT
	case 1, FortreeCity_House2_EventScript_WrongGuess
	msgbox FortreeCity_House2_Text_CorrectTryAgainWhichHand2, MSGBOX_DEFAULT
	multichoice 21, 8, MULTI_RIGHTLEFT, TRUE
	switch VAR_RESULT
	case 0, FortreeCity_House2_EventScript_WrongGuess
	msgbox FortreeCity_House2_Text_YourHiddenPowerHasAwoken, MSGBOX_DEFAULT
	giveitem ITEM_TM_HIDDEN_POWER
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_HIDDEN_POWER
	msgbox FortreeCity_House2_Text_ExplainHiddenPower, MSGBOX_DEFAULT
	release
	end

FortreeCity_House2_EventScript_Greeting::
	msgbox FortreeCity_House2_Text_HiddenPowersArousedByNature, MSGBOX_DEFAULT
	setflag FLAG_MET_HIDDEN_POWER_GIVER
	return

FortreeCity_House2_EventScript_ExplainHiddenPower::
	msgbox FortreeCity_House2_Text_ExplainHiddenPower, MSGBOX_DEFAULT
	release
	end

FortreeCity_House2_EventScript_WrongGuess::
	msgbox FortreeCity_House2_Text_YouGuessedWrong, MSGBOX_DEFAULT
	release
	end

FortreeCity_House2_Text_HiddenPowersArousedByNature:
	.string "Les gens… Les POKéMON…\p"
	.string "Leurs pouvoirs cachés s’éveillent en\n"
	.string "vivant dans des environnements naturels…$"

FortreeCity_House2_Text_CoinInWhichHand:
	.string "Laisse cette vieille femme voir si ton\n"
	.string "pouvoir caché s’est éveillé…\p"
	.string "Je tiens une pièce dans ma main.\p"
	.string "Dis-moi, l’ai-je cachée dans la main\n"
	.string "droite ? Ou dans la gauche ?$"

FortreeCity_House2_Text_CorrectTryAgainWhichHand:
	.string "Oh ! Oui, c’est correct !\p"
	.string "Essayons encore une fois.\p"
	.string "Dans quelle main ai-je caché la pièce ?\n"
	.string "La droite ou la gauche ?$"

FortreeCity_House2_Text_CorrectTryAgainWhichHand2:
	.string "Oh ! Oui, c’est correct !\p"
	.string "Essayons encore une fois.\p"
	.string "Dans quelle main ai-je caché la pièce ?\n"
	.string "La droite ou la gauche ?$"

FortreeCity_House2_Text_YourHiddenPowerHasAwoken:
	.string "Oh ! Splendide !\n"
	.string "Ton pouvoir caché s’est éveillé !\p"
	.string "Tiens, prends ceci et éveille le pouvoir\n"
	.string "caché de ton POKéMON.$"

FortreeCity_House2_Text_ExplainHiddenPower:
	.string "PUISSANCE CACHÉE est une capacité qui\n"
	.string "change selon le POKéMON.$"

FortreeCity_House2_Text_YouGuessedWrong:
	.string "Non, dommage.\n"
	.string "Tu t’es trompé.$"
