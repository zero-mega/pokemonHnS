CianwoodHouse1_MapScripts::
	.byte 0

CianwoodHouse1_EventScript_Hermit::
	lock
	faceplayer
	msgbox CianwoodCity_Text_OldManIntro MSGBOX_DEFAULT
	goto_if_eq VAR_LUGIA_OR_HOOH, 2, CianwoodHouse1_EventScript_HermitHooh
	checkitem ITEM_TIDAL_BELL
	goto_if_eq VAR_RESULT, TRUE, CianwoodHouse1_EventScript_HermitTidalBell
	msgbox CianwoodCity_Text_WhirlIslandsStory, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodHouse1_EventScript_HermitTidalBell::
	msgbox CianwoodCity_Text_TidalBellReaction, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodHouse1_EventScript_HermitHooh::
	checkitem ITEM_CLEAR_BELL
	goto_if_eq VAR_RESULT, TRUE, CianwoodHouse1_EventScript_HermitClearBell
	msgbox CianwoodCity_Text_BellTowerStory, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodHouse1_EventScript_HermitClearBell::
	msgbox CianwoodCity_Text_ClearBellReaction, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodCity_Text_OldManIntro:
	.string "Je ne me souviens plus de la dernière\n"
	.string "fois que quelqu'un est venu me voir.\p"
	.string "Quand j'étais jeune, j'étais aussi un\n"
	.string "dresseur de POKéMON.\l"
	.string "J'ai essayé d'atteindre la tour et\n"
	.string "de plonger dans l'océan.\p"
	.string "J'ai mis beaucoup d'efforts dans\n"
	.string "beaucoup de choses.\p"
	.string "Maintenant, je prends la vie plus\n"
	.string "tranquillement, en écoutant les vagues\l"
	.string "et le vent sur cette plage.$"

CianwoodCity_Text_BellTowerStory:
	.string "As-tu entendu parler de la TOUR FER\n"
	.string "à ROSALIA ?\p"
	.string "Il y a ce qu'on appelle des Cloches\n"
	.string "Transparente au sommet de la tour.\p"
	.string "Elles ne font aucun bruit, même dans\n"
	.string "les vents les plus forts.\p"
	.string "Il n'y a qu'une seule façon de les\n"
	.string "faire sonner.\p"
	.string "Il faut obtenir une autre Cloche\n"
	.string "Transparente, comme celles au sommet\l"
	.string "de la tour.\p"
	.string "J'ai essayé d'en avoir une quand\n"
	.string "j'étais jeune. Mais je n'y suis jamais\n"
	.string "parvenu...$"

CianwoodCity_Text_WhirlIslandsStory:
	.string "As-tu entendu parler des TOURB'ÎLES ?\p"
	.string "Il y a ce qu'on appelle des Cloches\n"
	.string "Marée au bassin de la cascade.\p"
	.string "Elles ne font aucun bruit, même dans\n"
	.string "le fracas des vagues.\p"
	.string "Il n'y a qu'une seule façon de les\n"
	.string "faire sonner.\p"
	.string "Il faut obtenir une autre Cloche Marée,\n"
	.string "comme celles au bassin de la cascade.\l"
	.string "\p"
	.string "J'ai essayé d'en avoir une quand\n"
	.string "j'étais jeune. Mais je n'y suis jamais\n"
	.string "parvenu...$"

CianwoodCity_Text_ClearBellReaction:
	.string "Oh ! Tu as réussi à obtenir une\n"
	.string "Cloche Transparente ?\p"
	.string "Le rêve de ma jeunesse...\n"
	.string "Je vois...\p"
	.string "Tu l'as fait...\n"
	.string "...\l"
	.string "...Je l'entends !\p"
	.string "Le tintement des cloches porté par le\n"
	.string "vent venant de la direction de la\l"
	.string "TOUR FER...$"

CianwoodCity_Text_TidalBellReaction:
	.string "Oh ! Tu as réussi à obtenir une\n"
	.string "Cloche Marée ?\p"
	.string "Le rêve de ma jeunesse...\n"
	.string "Je vois...\p"
	.string "Tu l'as fait...\n"
	.string "...\l"
	.string "...Je l'entends !\p"
	.string "Le tintement des cloches porté par la\n"
	.string "brise marine venant de la direction des\l"
	.string "TOURB'ÎLES...$"
