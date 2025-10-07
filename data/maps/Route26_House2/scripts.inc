Route26_House2_MapScripts::
	.byte 0

Route26_House2_EventScript_Book::
	lock
	msgbox DayOfWeekSiblingsHouse_Text_Pokedex1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE,Route26_House2_EventScript_BookRead
	closemessage
	release
	end

Route26_House2_EventScript_BookRead::
	msgbox DayOfWeekSiblingsHouse_Text_Pokedex2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, Route26_House2_EventScript_BookRead2
	closemessage
	release
	end
	
Route26_House2_EventScript_BookRead2::
	msgbox DayOfWeekSiblingsHouse_Text_Pokedex3, MSGBOX_DEFAULT
	closemessage
	release
	end

DayOfWeekSiblingsHouse_Text_Pokedex1:
    .string "Quelque chose est écrit ici.\p"
    .string "Voulez-vous lire?$"

DayOfWeekSiblingsHouse_Text_Pokedex2:
    .string "À mes frères et sœurs :\p"
    .string "Nous sommes fiers d'aider les\n"
    .string "dresseurs de POKéMON.\p"
    .string "Quand un dresseur vous parle,\n"
    .string "donnez-lui quelque chose d'utile.\p"
    .string "Avec amour,\n"
    .string "MONICA\p"
    .string "Continuer la lecture?$"

DayOfWeekSiblingsHouse_Text_Pokedex3:
    .string "Lundi, MONICA\n"
    .string "ROUTE 40\p"
    .string "Mardi, TUSCANY\n"
    .string "ROUTE 29\p"
    .string "Mercredi, WESLEY\n"
    .string "LAC COLÈRE\p"
    .string "Jeudi, ARTHUR\n"
    .string "ROUTE 36\p"
    .string "Vendredi, FRIEDA\n"
    .string "ROUTE 32\p"
    .string "Samedi, SANTOS\n"
    .string "ÉBÈNELLE\p"
    .string "Dimanche, SUNNY\n"
    .string "ROUTE 37$"
