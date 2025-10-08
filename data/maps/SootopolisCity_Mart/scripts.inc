SootopolisCity_Mart_MapScripts::
	.byte 0

SootopolisCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart 0
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Mart_EventScript_Clerk2::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart SootopolisCity_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SootopolisCity_Mart_Pokemart:
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFEND
	.2byte ITEM_SHADOW_MAIL
	.2byte ITEM_NONE
	release
	end

SootopolisCity_Mart_EventScript_FatMan::
	lock
	faceplayer
	goto_if_ge VAR_SKY_PILLAR_STATE, 2, SootopolisCity_Mart_EventScript_FatManNoLegendaries
	goto_if_unset FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, SootopolisCity_Mart_EventScript_FatManNoLegendaries
	msgbox SootopolisCity_Mart_Text_TooScaryOutside, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Mart_EventScript_FatManNoLegendaries::
	msgbox SootopolisCity_Mart_Text_PPUpIsGreat, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Mart_EventScript_Gentleman::
	lock
	faceplayer
	goto_if_ge VAR_SKY_PILLAR_STATE, 2, SootopolisCity_Mart_EventScript_GentlemanNoLegendaries
	goto_if_unset FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, SootopolisCity_Mart_EventScript_GentlemanNoLegendaries
	msgbox SootopolisCity_Mart_Text_DidSomethingAwaken, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Mart_EventScript_GentlemanNoLegendaries::
	msgbox SootopolisCity_Mart_Text_FullRestoreItemOfDreams, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Mart_Text_PPUpIsGreat:
	.string "Le PP MAX, c'est génial !\p"
	.string "Il augmente les POINTS DE POUVOIR,\n"
	.string "les PP, d'une capacité de POKéMON.$"

SootopolisCity_Mart_Text_TooScaryOutside:
	.string "Quoi…\n"
	.string "Que se passe-t-il ?\p"
	.string "J'aimerais vraiment savoir, mais il fait\n"
	.string "trop peur pour sortir.$"

SootopolisCity_Mart_Text_FullRestoreItemOfDreams:
	.string "Tu connais le GUÉRISON TOTAL ?\p"
	.string "Restaure tous les PV !\n"
	.string "Soigne tous les problèmes de statut !\p"
	.string "C'est vraiment l'objet de tes rêves !$"

SootopolisCity_Mart_Text_DidSomethingAwaken:
	.string "Ce temps…\n"
	.string "Est-ce que quelque chose s'est réveillé ?$"

