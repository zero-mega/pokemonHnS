.set LOCALID_MOVE_RELEARNER, 1

FallarborTown_MoveRelearnersHouse_MapScripts::
	.byte 0

FallarborTown_MoveRelearnersHouse_EventScript_MoveRelearner::
	lockall
	faceplayer
	goto_if_set FLAG_TEMP_1, FallarborTown_MoveRelearnersHouse_EventScript_AskTeachMove
	msgbox FallarborTown_MoveRelearnersHouse_Text_ImTheMoveTutor, MSGBOX_DEFAULT
	setflag FLAG_TEMP_1
	goto FallarborTown_MoveRelearnersHouse_EventScript_AskTeachMove
	end

FallarborTown_MoveRelearnersHouse_EventScript_AskTeachMove::
	checkitem ITEM_HEART_SCALE
	goto_if_eq VAR_RESULT, FALSE, FallarborTown_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale
	msgbox FallarborTown_MoveRelearnersHouse_Text_ThatsAHeartScaleWantMeToTeachMove, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, FallarborTown_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale
	goto FallarborTown_MoveRelearnersHouse_EventScript_ChooseMon
	end

FallarborTown_MoveRelearnersHouse_EventScript_ChooseMon::
	msgbox FallarborTown_MoveRelearnersHouse_Text_TutorWhichMon, MSGBOX_DEFAULT
	special ChooseMonForMoveRelearner
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, FallarborTown_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, FallarborTown_MoveRelearnersHouse_EventScript_CantTeachEgg
	goto_if_eq VAR_0x8005, 0, FallarborTown_MoveRelearnersHouse_EventScript_NoMoveToTeachMon
	goto FallarborTown_MoveRelearnersHouse_EventScript_ChooseMove
	end

FallarborTown_MoveRelearnersHouse_EventScript_ChooseMove::
	msgbox FallarborTown_MoveRelearnersHouse_Text_TeachWhichMove, MSGBOX_DEFAULT
	special TeachMoveRelearnerMove
	waitstate
	goto_if_eq VAR_0x8004, 0, FallarborTown_MoveRelearnersHouse_EventScript_ChooseMon
	msgbox FallarborTown_MoveRelearnersHouse_Text_HandedOverHeartScale, MSGBOX_DEFAULT
	removeitem ITEM_HEART_SCALE
	goto FallarborTown_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale
	end

FallarborTown_MoveRelearnersHouse_EventScript_NoMoveToTeachMon::
	msgbox FallarborTown_MoveRelearnersHouse_Text_DontHaveMoveToTeachPokemon, MSGBOX_DEFAULT
	goto FallarborTown_MoveRelearnersHouse_EventScript_ChooseMon
	end

FallarborTown_MoveRelearnersHouse_EventScript_CantTeachEgg::
	msgbox FallarborTown_MoveRelearnersHouse_Text_CantTeachEgg, MSGBOX_DEFAULT
	goto FallarborTown_MoveRelearnersHouse_EventScript_ChooseMon
	end

FallarborTown_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale::
	msgbox FallarborTown_MoveRelearnersHouse_Text_ComeBackWithHeartScale, MSGBOX_DEFAULT
	releaseall
	end

FallarborTown_MoveRelearnersHouse_Text_ImTheMoveTutor:
	.string "Je suis le MAÎTRE DES CAPACITÉS.\p"
	.string "Je connais toutes les capacités que les POKéMON\n"
	.string "peuvent apprendre—toutes sans exception—et je peux\l"
	.string "les leur enseigner.\p"
	.string "Je peux apprendre une capacité à l’un de tes\n"
	.string "POKéMON si tu veux.\p"
	.string "Je le ferai contre une ÉCaille Cœur.\n"
	.string "J’en collectionne en ce moment.$"

FallarborTown_MoveRelearnersHouse_Text_ThatsAHeartScaleWantMeToTeachMove:
	.string "Oh ! C’est ça ! C’est bien une vraie\n"
	.string "ÉCAILLE CŒUR !\p"
	.string "Laisse-moi deviner, tu veux que j’enseigne\n"
	.string "une capacité ?$"

FallarborTown_MoveRelearnersHouse_Text_TutorWhichMon:
	.string "Quel POKéMON a besoin d’un cours ?$"

FallarborTown_MoveRelearnersHouse_Text_TeachWhichMove:
	.string "Quelle capacité dois-je enseigner ?$"

FallarborTown_MoveRelearnersHouse_Text_DontHaveMoveToTeachPokemon:
	.string "Désolé…\p"
	.string "Il ne semble pas que j’aie une capacité\n"
	.string "à enseigner à ce POKéMON.$"

FallarborTown_MoveRelearnersHouse_Text_HandedOverHeartScale:
	.string "{PLAYER} a donné une ÉCAILLE CŒUR\n"
	.string "en échange.$"

FallarborTown_MoveRelearnersHouse_Text_ComeBackWithHeartScale:
	.string "Si tes POKéMON doivent apprendre une capacité,\n"
	.string "reviens avec une ÉCAILLE CŒUR.$"

FallarborTown_MoveRelearnersHouse_Text_CantTeachEgg:
	.string "Hein ? Il n’y a aucune capacité que\n"
	.string "je puisse enseigner à un ŒUF.$"
