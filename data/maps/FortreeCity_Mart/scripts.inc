FortreeCity_Mart_MapScripts::
	.byte 0

FortreeCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart 0
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

FortreeCity_Mart_EventScript_Clerk2::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart FortreeCity_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
FortreeCity_Mart_Pokemart:
	.2byte ITEM_WOOD_MAIL
	.2byte ITEM_NONE
	release
	end

FortreeCity_Mart_EventScript_Woman::
	msgbox FortreeCity_Mart_Text_SuperRepelBetter, MSGBOX_NPC
	end

FortreeCity_Mart_EventScript_Girl::
	msgbox FortreeCity_Mart_Text_StockUpOnItems, MSGBOX_NPC
	end

FortreeCity_Mart_EventScript_Boy::
	msgbox FortreeCity_Mart_Text_RareCandyMakesMonGrow, MSGBOX_NPC
	end

FortreeCity_Mart_Text_SuperRepelBetter:
	.string "Le SUPER REPOUSSE dure longtemps,\n"
	.string "et il fait bien son travail.\p"
	.string "C'est bien mieux qu'un REPOUSSE\n"
	.string "ordinaire.$"

FortreeCity_Mart_Text_StockUpOnItems:
	.string "Je fais toujours le plein d'objets,\n"
	.string "plus que ce dont j'ai besoin.\p"
	.string "On ne sait jamais ce qui peut arriver.\n"
	.string "Mieux vaut prévenir que guérir !$"

FortreeCity_Mart_Text_RareCandyMakesMonGrow:
	.string "Un BONBON RARE fait monter un POKéMON\n"
	.string "d'un niveau immédiatement.$"

