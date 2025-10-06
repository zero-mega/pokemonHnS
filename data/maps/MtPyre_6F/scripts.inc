MtPyre_6F_MapScripts::
	.byte 0

MtPyre_6F_EventScript_Valerie::
	trainerbattle_single TRAINER_VALERIE_1, MtPyre_6F_Text_ValerieIntro, MtPyre_6F_Text_ValerieDefeat, MtPyre_6F_EventScript_RegisterValerie
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MtPyre_6F_EventScript_RematchValerie
	msgbox MtPyre_6F_Text_ValeriePostBattle, MSGBOX_DEFAULT
	release
	end

MtPyre_6F_EventScript_RegisterValerie::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MtPyre_6F_Text_ValerieRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_VALERIE_1
	release
	end

MtPyre_6F_EventScript_RematchValerie::
	trainerbattle_rematch TRAINER_VALERIE_1, MtPyre_6F_Text_ValerieRematchIntro, MtPyre_6F_Text_ValerieRematchDefeat
	msgbox MtPyre_6F_Text_ValeriePostRematch, MSGBOX_AUTOCLOSE
	end

MtPyre_6F_EventScript_Cedric::
	trainerbattle_single TRAINER_GRUNT_8, MtPyre_6F_Text_CedricIntro, MtPyre_6F_Text_CedricDefeat
	msgbox MtPyre_6F_Text_CedricPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_6F_Text_ValerieIntro:
	.string "Quand je suis ici…\n"
	.string "Une étrange énergie m'envahit…$"

MtPyre_6F_Text_ValerieDefeat:
	.string "L'énergie s'estompe…$"

MtPyre_6F_Text_ValeriePostBattle:
	.string "Peut-être que cette énergie vient des esprits\n"
	.string "des POKéMON qui dorment ici…$"

MtPyre_6F_Text_ValerieRegister:
	.string "Fufufu… J'ai perdu le combat, mais…\n"
	.string "J'ai ce petit don…\p"
	.string "Sans jamais toucher à ton POKéNAV… Hiyah!$"

MtPyre_6F_Text_ValerieRematchIntro:
	.string "Derrière toi…\n"
	.string "Qu'est-ce que c'est…$"

MtPyre_6F_Text_ValerieRematchDefeat:
	.string "Quelque chose s'est dissipé…$"

MtPyre_6F_Text_ValeriePostRematch:
	.string "Les POKéMON qui reposent ici…\n"
	.string "Parfois, ils jouent…$"

MtPyre_6F_Text_CedricIntro:
	.string "Tu t'es perdu ?\n"
	.string "N'aie pas peur, je suis là !$"

MtPyre_6F_Text_CedricDefeat:
	.string "Tu n'étais pas perdu ?$"

MtPyre_6F_Text_CedricPostBattle:
	.string "Je pensais qu'un DRESSEUR perdu\n"
	.string "serait paniqué et facile à battre.\p"
	.string "C'est malhonnête, je ne le referai plus…$"
