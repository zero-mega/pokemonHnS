PetalburgCity_Mart_MapScripts::
	.byte 0

PetalburgCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	@goto_if_set FLAG_PETALBURG_MART_EXPANDED_ITEMS, PetalburgCity_Mart_EventScript_ExpandedItems
	pokemart 0
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

PetalburgCity_Mart_EventScript_Clerk2::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart PetalburgCity_Mart_Pokemart_Extra
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
PetalburgCity_Mart_Pokemart_Extra:
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFEND
	.2byte ITEM_ORANGE_MAIL
	.2byte ITEM_NONE
	release
	end

@PetalburgCity_Mart_EventScript_ExpandedItems::
@	pokemart PetalburgCity_Mart_Pokemart_Expanded
@	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
@	release
@	end

@	.align 2
@PetalburgCity_Mart_Pokemart_Expanded:
@	.2byte ITEM_POKE_BALL
@	.2byte ITEM_GREAT_BALL
@	.2byte ITEM_POTION
@	.2byte ITEM_SUPER_POTION
@	.2byte ITEM_ANTIDOTE
@	.2byte ITEM_PARALYZE_HEAL
@	.2byte ITEM_AWAKENING
@	.2byte ITEM_ESCAPE_ROPE
@	.2byte ITEM_REPEL
@	.2byte ITEM_X_SPEED
@	.2byte ITEM_X_ATTACK
@	.2byte ITEM_X_DEFEND
@	.2byte ITEM_ORANGE_MAIL
@	.2byte ITEM_NONE
@	release
@	end

PetalburgCity_Mart_EventScript_Woman::
	msgbox PetalburgCity_Mart_Text_WeakWillGrowStronger, MSGBOX_NPC
	end

PetalburgCity_Mart_EventScript_Boy::
	msgbox PetalburgCity_Mart_Text_RepelIsUseful, MSGBOX_NPC
	end

PetalburgCity_Mart_EventScript_Man::
	msgbox PetalburgCity_Mart_Text_TakeSomeAntidotesWithYou, MSGBOX_NPC
	end

PetalburgCity_Mart_Text_WeakWillGrowStronger:
	.string "Même si un POKéMON est faible\n"
	.string "maintenant, il deviendra plus fort.\p"
	.string "Le plus important, c'est l'amour !\n"
	.string "Aime tes POKéMON !$"

PetalburgCity_Mart_Text_RepelIsUseful:
	.string "Utilises-tu des REPOUSSE ?\n"
	.string "Ça éloigne les POKéMON, donc c'est\l"
	.string "pratique quand tu es pressé.$"

PetalburgCity_Mart_Text_TakeSomeAntidotesWithYou:
	.string "As-tu des ANTIDOTES avec toi ?\n"
	.string "\p"
	.string "Si tu marches avec un POKéMON\n"
	.string "empoisonné, il perdra des PV jusqu'à\l"
	.string "s'évanouir.\p"
	.string "Prends des ANTIDOTES avec toi.$"
