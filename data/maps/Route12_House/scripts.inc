Route12_House_MapScripts::
	.byte 0

Route12_House_EventScript_SuperRod::
	lock
	faceplayer
	goto_if_set FLAG_GOT_SUPER_ROD, Route12_House_EventScript_SuperRodGot
	msgbox Route12_House_Text_OfferSuperRod, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, Route12_House_EventScript_SuperRodRefused
	msgbox Route12_House_Text_GiveSuperRod, MSGBOX_DEFAULT
	giveitem ITEM_SUPER_ROD
	msgbox Route12_House_Text_GaveSuperRod, MSGBOX_DEFAULT
	setflag FLAG_GOT_SUPER_ROD
	closemessage
	release
	end

Route12_House_EventScript_SuperRodRefused::
	msgbox Route12_House_Text_DontWantSuperRod, MSGBOX_DEFAULT
	closemessage
	release
	end

Route12_House_EventScript_SuperRodGot::
	msgbox Route12_House_Text_GaveSuperRod, MSGBOX_NPC
	release
	end

Route12_House_Text_OfferSuperRod:
	.string "Je suis le petit frère du GURU\n"
	.string "de la PÊCHE.\p"
	.string "Je vois que tu aimes la pêche.\p"
	.string "Je n'ai aucun doute là-dessus !\p"
	.string "Alors ? Je sais que j'ai raison.$"

Route12_House_Text_GiveSuperRod:
	.string "Oui, oui. C'est bien ce que je\n"
	.string "pensais !\p"
	.string "Tiens, fan de pêche ! Prends ceci--\n"
	.string "c'est une SUPER CANNE.$"

Route12_House_Text_GaveSuperRod:
	.string "Essaie de pêcher partout où il y a\n"
	.string "de l'eau.\p"
	.string "Souviens-toi : tu peux attraper\n"
	.string "différents POKéMON avec différentes\n"
	.string "CANNES.$"

Route12_House_Text_DontWantSuperRod:
	.string "Hein ? Mes yeux m'ont trompé ?$"
