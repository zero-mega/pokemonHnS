GoldenrodCity_BikeShop_MapScripts::
	.byte 0

GoldenrodCity_BikeShop_EventScript_Clerk::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_BIKE, GoldenrodCity_BikeShop_EventScript_Clerk_BikeReceived
	msgbox GoldenrodCity_BikeShop_Text_ClerkIntro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, GoldenrodCity_BikeShop_EventScript_Clerk_BikeAgreed
	msgbox GoldenrodCity_BikeShop_Text_Refused, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_BikeShop_EventScript_Clerk_BikeAgreed::
	msgbox GoldenrodCity_BikeShop_Text_ClerkAgreed, MSGBOX_DEFAULT
	giveitem ITEM_MACH_BIKE
	setflag FLAG_RECEIVED_BIKE
	closemessage
	release
	end

GoldenrodCity_BikeShop_EventScript_Clerk_BikeReceived::
	msgbox GoldenrodCity_BikeShop_Text_Mainshop, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_BikeShop_EventScript_Clerk2::
	lock
	faceplayer
	msgbox GoldenrodCity_BikeShop_Text_Clerk2, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_BikeShop_EventScript_Bike::
	lock
	msgbox GoldenrodCity_BikeShop_Text_Bicycle, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_BikeShop_Text_Clerk2:
	.string "Faire du vélo, c'est aussi simple que\n"
	.string "d'appuyer sur un bouton si tu\l"
	.string "l'ENREGISTRES depuis le SAC.$"

GoldenrodCity_BikeShop_Text_ClerkIntro:
    .string "…soupir… J'ai déménagé ici, mais je\n"
    .string "n'arrive pas à vendre mes VÉLOS. Pourquoi ?\p"
    .string "Pourrais-tu rouler à vélo et\n"
    .string "faire de la pub pour moi ?$"

GoldenrodCity_BikeShop_Text_ClerkAgreed:
    .string "Vraiment ? Super !\p"
    .string "Donne-moi ton nom et ton numéro,\n"
    .string "et je te prête un VÉLO.$"

GoldenrodCity_BikeShop_Text_BorrowedBicycle:
    .string "{PLAYER} a emprunté un VÉLO.$"

GoldenrodCity_BikeShop_Text_Mainshop:
	.string "La boutique principale est à AZURIA,\n"
	.string "dans le KANTO.\p"
	.string "Salue le gérant si jamais tu\n"
	.string "passes là-bas !$"

GoldenrodCity_BikeShop_Text_Refused:
    .string "…soupir… Ah, la gentillesse des\n"
    .string "gens…$"

GoldenrodCity_BikeShop_Text_JustReleasedCompact:
    .string "Nouveau modèle !\p"
    .string "VÉLOS compacts de première qualité !$"

GoldenrodCity_BikeShop_Text_Bicycle:
    .string "C'est un VÉLO tout neuf et brillant !$"
