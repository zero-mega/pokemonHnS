Gate_GoldenrodCity_Route35_MapScripts::
	.byte 0

Gate_GoldenrodCity_Route35_EventScript_Randy::
	lock
	faceplayer
	goto_if_eq VAR_KENYA, 3, Gate_GoldenrodCity_Route35_EventScript_RandyPostKenya
	goto_if_eq VAR_KENYA, 2, Gate_GoldenrodCity_Route35_EventScript_RandyDeliveredKenya
	goto_if_eq VAR_KENYA, 1, Gate_GoldenrodCity_Route35_EventScript_RandyHaveKenya
	msgbox Route35GoldenrodGate_Text_RandyAskFavor, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, Gate_GoldenrodCity_Route35_EventScript_RandyCancel
	closemessage

	msgbox Route35GoldenrodGate_Text_RandyThanks, MSGBOX_DEFAULT

	@HnS named gift pokemon setup
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_SPEAROW
	bufferspeciesname STR_VAR_1, SPECIES_SPEAROW
	givenamedmon 1
	call Common_EventScript_GiftMonNamed

	setvar VAR_KENYA, 1
	release
	end

Gate_GoldenrodCity_Route35_EventScript_RandyCancel::
	msgbox Route35GoldenrodGate_Text_RandyNeverMind, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_GoldenrodCity_Route35_EventScript_RandyHaveKenya::
	msgbox Route35GoldenrodGate_Text_RandyWeirdTree, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_GoldenrodCity_Route35_EventScript_RandyDeliveredKenya::
	msgbox Route35GoldenrodGate_Text_ThanksForDelivery, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_HP_UP
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox Route35GoldenrodGate_Text_RandyMyPalSnoozing, MSGBOX_DEFAULT
	closemessage
	setvar VAR_KENYA, 3
	release
	end

Gate_GoldenrodCity_Route35_EventScript_RandyPostKenya::
	msgbox Route35GoldenrodGate_Text_RandyMyPalSnoozing, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_GoldenrodCity_Route35_EventScript_Lady::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_SUDOWOODO, Gate_GoldenrodCity_Route35_EventScript_Lady2
	msgbox Route35GoldenrodGate_Text_PokefanF_TreeBlocking, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_GoldenrodCity_Route35_EventScript_Lady2::
	msgbox Route35GoldenrodGate_Text_PokefanF_Lullaby, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_GoldenrodCity_Route35_EventScript_Fisher::
	lock
	faceplayer
	msgbox Route35GoldenrodGate_Text_Fisher, MSGBOX_DEFAULT
	closemessage
	release
	end

Route35GoldenrodGate_Text_RandyAskFavor:
	.string "Excuse-moi, gamin ! Tu peux rendre\n"
	.string "service à un gars ?\p"
	.string "Peux-tu emmener ce POKéMON avec une\n"
	.string "LETTRE à mon ami ?\p"
	.string "Il est sur la ROUTE 31.$"

Route35GoldenrodGate_Text_RandyThanks:
	.string "Tu veux bien ? Parfait ! Merci, gamin !\p"
	.string "Mon pote est un gars bien rond qui\n"
	.string "dort tout le temps.\p"
	.string "Tu le reconnaîtras tout de suite !$"

Route35GoldenrodGate_Text_ReceivedMonWithMail:
	.string "{PLAYER} reçoit un POKéMON avec une LETTRE.$"

Route35GoldenrodGate_Text_RandyWeirdTree:
	.string "Assure-toi de le mettre en tête de\n"
	.string "ton équipe quand tu trouveras mon ami !\p"
	.string "ROUTE 31 !\p"
	.string "Ah, oui. Il y avait un arbre étrange\n"
	.string "qui bloquait la route.\p"
	.string "Je me demande s'il a été dégagé.$"

Route35GoldenrodGate_Text_CantCarryMoreMon:
	.string "Tu ne peux pas porter un autre POKéMON…$"

Route35GoldenrodGate_Text_RandyNeverMind:
	.string "Oh… Laisse tomber, alors…$"

Route35GoldenrodGate_Text_ThanksForDelivery:
	.string "Merci, gamin ! Tu as fait la livraison\n"
	.string "pour moi !\p"
	.string "Tiens, c'est pour te remercier !$"

Route35GoldenrodGate_Text_RandyMyPalSnoozing:
	.string "Mon pote dormait, pas vrai ? Hé hé,\n"
	.string "qu'est-ce que je t'avais dit ?$"

Route35GoldenrodGate_Text_PokefanF_TreeBlocking:
	.string "Un arbre étrange bloque la route.\p"
	.string "A strange tree is blocking the road.\p"
	.string "It wriggles around if you talk to it.\p"
	.string "I heard it became wild when someone\n"
	.string "watered it with a SQUIRTBOTTLE.$"

Route35GoldenrodGate_Text_PokefanF_Lullaby:
	.string "I like the POKéMON Lullaby they play\n"
	.string "on the radio.$"

Route35GoldenrodGate_Text_Fisher:
	.string "I wonder how many kinds of POKéMON\n"
	.string "there are in the world.\p"
	.string "Three years ago, PROF.OAK said that\n"
	.string "there were 150 different kinds.\p"
	.string "But recently I heard there's\n"
	.string "over 400!$"
