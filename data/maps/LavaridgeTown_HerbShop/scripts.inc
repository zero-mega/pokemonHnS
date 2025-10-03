LavaridgeTown_HerbShop_MapScripts::
	.byte 0

LavaridgeTown_HerbShop_EventScript_Clerk::
	lock
	faceplayer
	message LavaridgeTown_HerbShop_Text_WelcomeToHerbShop
	waitmessage
	pokemart LavaridgeTown_HerbShop_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LavaridgeTown_HerbShop_Pokemart:
	.2byte ITEM_ENERGY_POWDER
	.2byte ITEM_ENERGY_ROOT
	.2byte ITEM_HEAL_POWDER
	.2byte ITEM_REVIVAL_HERB
	.2byte ITEM_NONE
	release
	end

LavaridgeTown_HerbShop_EventScript_ExpertM::
	msgbox LavaridgeTown_HerbShop_Text_HerbalMedicineWorksButMonWillDislike, MSGBOX_NPC
	end

LavaridgeTown_HerbShop_EventScript_OldMan::
	lock
	faceplayer
	goto_if_set FLAG_GARBAGEFLAG, LavaridgeTown_HerbShop_EventScript_ExplainCharcoal
	msgbox LavaridgeTown_HerbShop_Text_YouveComeToLookAtHerbalMedicine, MSGBOX_DEFAULT
	giveitem ITEM_CHARCOAL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GARBAGEFLAG
	release
	end

LavaridgeTown_HerbShop_EventScript_ExplainCharcoal::
	msgbox LavaridgeTown_HerbShop_Text_ExplainCharcoal, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_HerbShop_Text_WelcomeToHerbShop:
	.string "Bienvenue à la BOUTIQUE D'HERBES, le lieu\n"
	.string "des remèdes efficaces et bon marché !$"

LavaridgeTown_HerbShop_Text_YouveComeToLookAtHerbalMedicine:
	.string "Tu es venu voir les remèdes à base d'herbes\n"
	.string "à LAVARIDGE ?\p"
	.string "C'est vraiment admirable.\p"
	.string "Tu me plais ! Prends ceci !$"

LavaridgeTown_HerbShop_Text_ExplainCharcoal:
	.string "Ce CHARBON que je t'ai donné, il sert\n"
	.string "à fabriquer des remèdes à base d'herbes.\p"
	.string "Il fait aussi des merveilles lorsqu'il est tenu\n"
	.string "par un POKéMON.\p"
	.string "Il intensifie la puissance des attaques\n"
	.string "de type FEU.$"

LavaridgeTown_HerbShop_Text_HerbalMedicineWorksButMonWillDislike:
	.string "Les remèdes à base d'herbes sont très efficaces.\n"
	.string "Mais tes POKéMON ne t'aimeront pas pour ça.\l"
	.string "Ça doit être affreusement amer !$"
