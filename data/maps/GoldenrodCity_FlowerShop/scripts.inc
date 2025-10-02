GoldenrodCity_FlowerShop_MapScripts::
	.byte 0

GoldenrodCity_FlowerShop_EventScript_Owner::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_SUDOWOODO, GoldenrodCity_FlowerShop_EventScript_Normal
	goto_if_set FLAG_RECEIVED_SQUIRTBOTTLE, GoldenrodCity_FlowerShop_EventScript_GotSquirtBottle
	goto_if_set FLAG_BADGE03_GET, GoldenrodCity_FlowerShop_EventScript_GiveSquirtBottle
	msgbox GoldenrodCity_FlowerShop_Text_Owner1, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_FlowerShop_EventScript_GiveSquirtBottle::
	lock
	faceplayer
	msgbox GoldenrodCity_FlowerShop_Text_Owner2, MSGBOX_DEFAULT
	giveitem ITEM_SQUIRT_BOTTLE
	setflag FLAG_RECEIVED_SQUIRTBOTTLE
	closemessage
	release
	end

GoldenrodCity_FlowerShop_EventScript_GotSquirtBottle::
	lock
	faceplayer
	msgbox GoldenrodCity_FlowerShop_Text_Owner3, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_FlowerShop_EventScript_Normal::
	lock
	faceplayer
	msgbox GoldenrodCity_FlowerShop_Text_Owner4, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_FlowerShop_EventScript_Floria1::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_SUDOWOODO, GoldenrodCity_FlowerShop_EventScript_Floria3
	goto_if_set FLAG_BADGE03_GET, GoldenrodCity_FlowerShop_EventScript_Floria2
	msgbox GoldenrodCity_FlowerShop_Text_Floria, MSGBOX_DEFAULT
	closemessage
	release
	end
	
GoldenrodCity_FlowerShop_EventScript_Floria2::
	msgbox GoldenrodCity_FlowerShop_Text_FloriaYouBeatWhitney, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_FlowerShop_EventScript_Floria3::
	msgbox GoldenrodCity_FlowerShop_Text_FloriaItWasAMon, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_FlowerShop_Text_Floria:
	.string "Quand j'ai parlé à ma sœur de\n"
	.string "l'arbre qui bouge, elle a dit que\n"
	.string "c'était dangereux.\p"
	.string "Si je bats BLANCHE, je me demande\n"
	.string "si elle me prêtera sa bouteille\n"
	.string "d'eau…$"

GoldenrodCity_FlowerShop_Text_Owner1:
.string "Apparemment, il y a un arbre\n"
.string "bizarre sur la Route 36.\p"
.string "On dit qu'il danse quand on\n"
.string "l'arrose...\p"
.string "Oh, bien sûr que non !\p"
.string "C'est un magasin de fleurs, donc\n"
.string "nous avons des arrosoirs...\p"
.string "Mais je ne peux pas t'en donner !\n"
.string "C'est trop dangereux !\p"
.string "Eh bien, peut-être que si tu arrives\n"
.string "à battre la championne BLANCHE,\l"
.string "ce sera possible.$"

GoldenrodCity_FlowerShop_Text_Owner2:
.string "Apparemment, il y a un arbre\n"
.string "bizarre sur la Route 36.\p"
.string "On dit qu'il danse quand on\n"
.string "l'arrose...\p"
.string "Oh, c'est un BADGE PLAIN de\n"
.string "l'ARÈNE DE DOUBLONVILLE !\p"
.string "Tu as battu BLANCHE ?!\p"
.string "Alors il n'y a plus de raison de\n"
.string "s'inquiéter, n'est-ce pas ?\p"
.string "Je vais te laisser utiliser cette\n"
.string "BOUTEILLE D'EAU un moment.\l"
.string "...\p"
.string "Oh, finalement, garde-la !$"

GoldenrodCity_FlowerShop_Text_Owner3:
.string "L'arbre étrange est sur la ROUTE 36.\n"
.string "Fais attention !$"

GoldenrodCity_FlowerShop_Text_Owner4:
    .string "Lalala lalalala. Bois beaucoup\n"
    .string "d'eau, ma jolie !$"

GoldenrodCity_FlowerShop_Text_FloriaYouBeatWhitney:
    .string "Ouah, tu as battu BLANCHE ? Génial !$"

GoldenrodCity_FlowerShop_Text_FloriaItWasAMon:
    .string "Alors c'était vraiment un POKéMON !$"
