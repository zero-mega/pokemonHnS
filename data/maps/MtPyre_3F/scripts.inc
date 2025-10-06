MtPyre_3F_MapScripts::
	.byte 0

MtPyre_3F_EventScript_William::
	trainerbattle_single TRAINER_WILLIAM, MtPyre_3F_Text_WilliamIntro, MtPyre_3F_Text_WilliamDefeat
	msgbox MtPyre_3F_Text_WilliamPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_3F_EventScript_Kayla::
	trainerbattle_single TRAINER_KAYLA, MtPyre_3F_Text_KaylaIntro, MtPyre_3F_Text_KaylaDefeat
	msgbox MtPyre_3F_Text_KaylaPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_3F_EventScript_Gabrielle::
	trainerbattle_single TRAINER_ROD, MtPyre_3F_Text_GabrielleIntro, MtPyre_3F_Text_GabrielleDefeat, MtPyre_3F_EventScript_RegisterGabrielle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MtPyre_3F_EventScript_RematchGabrielle
	msgbox MtPyre_3F_Text_GabriellePostBattle, MSGBOX_DEFAULT
	release
	end

MtPyre_3F_EventScript_RegisterGabrielle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MtPyre_3F_Text_GabrielleRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_ROD
	release
	end

MtPyre_3F_EventScript_RematchGabrielle::
	trainerbattle_rematch TRAINER_ROD, MtPyre_3F_Text_GabrielleRematchIntro, MtPyre_3F_Text_GabrielleRematchDefeat
	msgbox MtPyre_3F_Text_GabriellePostRematch, MSGBOX_AUTOCLOSE
	end

MtPyre_3F_Text_WilliamIntro:
	.string "L'atmosphère riche de la montagne\n"
	.string "a élevé mes pouvoirs psychiques !\p"
	.string "Un simple enfant comme toi…\n"
	.string "Tu rêves de gagner ?$"

MtPyre_3F_Text_WilliamDefeat:
	.string "Je me noie dans l'apitoiement…$"

MtPyre_3F_Text_WilliamPostBattle:
	.string "Mes pouvoirs psychiques ont sûrement\n"
	.string "beaucoup grandi, mais…$"

MtPyre_3F_Text_KaylaIntro:
	.string "Ahahahaha !\p"
	.string "Ce n'est pas un endroit pour les enfants,\n"
	.string "surtout pas pour toi !$"

MtPyre_3F_Text_KaylaDefeat:
	.string "J'ai perdu à plate couture…$"

MtPyre_3F_Text_KaylaPostBattle:
	.string "Cela veut dire que mon entraînement\n"
	.string "n'est toujours pas suffisant…\p"
	.string "Je dois continuer à travailler vers le\n"
	.string "sommet…\p"
	.string "Allez, moi !$"

MtPyre_3F_Text_GabrielleIntro:
	.string "Pourquoi es-tu venu ici ?$"

MtPyre_3F_Text_GabrielleDefeat:
	.string "C'était incroyable !\n"
	.string "Tu es un DRESSEUR très spécial.$"

MtPyre_3F_Text_GabriellePostBattle:
	.string "Des POKéMON qui ne sont plus de ce monde.\n"
	.string "Des POKéMON qui sont avec toi maintenant.\p"
	.string "Et les POKéMON que tu rencontreras\n"
	.string "dans le futur…\p"
	.string "Ils doivent tous être chéris de la même façon.\n"
	.string "S'il te plaît, souviens-t'en.$"

MtPyre_3F_Text_GabrielleRegister:
	.string "J'aimerais voir tes POKéMON\n"
	.string "quand ils auront encore grandi…\p"
	.string "S'il te plaît, j'ai besoin de voir ton POKéNAV.$"

MtPyre_3F_Text_GabrielleRematchIntro:
	.string "Oh, c'est toi…\p"
	.string "Es-tu venu me montrer tes POKéMON\n"
	.string "qui ont grandi ?$"

MtPyre_3F_Text_GabrielleRematchDefeat:
	.string "Comme c'est incroyable !\n"
	.string "Tu es une personne spéciale.$"

MtPyre_3F_Text_GabriellePostRematch:
	.string "Des POKéMON qui ne sont plus de ce monde.\n"
	.string "Des POKéMON qui sont avec toi maintenant.\p"
	.string "Et les POKéMON que tu rencontreras\n"
	.string "dans le futur…\p"
	.string "Ils doivent tous être chéris de la même façon.\n"
	.string "Je vois que tu t'en souviens.$"
