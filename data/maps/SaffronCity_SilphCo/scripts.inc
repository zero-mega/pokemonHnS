.set LOCALID_SILPHCO_STEVEN, 2

SaffronCity_SilphCo_MapScripts::
	.byte 0

SaffronCity_SilphCo_EventScript_Steven::
	lock 
	msgbox SaffronCity_SilphCo_Text_Steven1, MSGBOX_DEFAULT
	closemessage
	delay 20
	faceplayer
	delay 20
	playse SE_PIN
	applymovement LOCALID_SILPHCO_STEVEN, Common_Movement_ExclamationMark
	delay 60
SaffronCity_SilphCo_EventScript_StevenChooseStone::
	message SaffronCity_SilphCo_Text_Steven2
	waitmessage
	multichoice 20, 0, MULTI_HOENN_STARTERS, FALSE
	switch VAR_RESULT
	case 0, SaffronCity_SilphCo_EventScript_TreeckoChosen
	case 1, SaffronCity_SilphCo_EventScript_TorchicChosen
	case 2, SaffronCity_SilphCo_EventScript_MudkipChosen
	case MULTI_B_PRESSED, SaffronCity_SilphCo_EventScript_Refused

SaffronCity_SilphCo_EventScript_Refused::
	msgbox SaffronCity_SilphCo_Text_Refused, MSGBOX_DEFAULT
	turnobject LOCALID_SILPHCO_STEVEN, DIR_NORTH
	closemessage
	release
	end

SaffronCity_SilphCo_Text_Refused:
	.string "Oh...$"

SaffronCity_SilphCo_EventScript_TreeckoChosen::
	closemessage
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_TREECKO
	bufferspeciesname STR_VAR_1, SPECIES_TREECKO
	msgbox SaffronCity_SilphCo_Text_Steven3, MSGBOX_DEFAULT
	givemon SPECIES_TREECKO, 5
	call Common_EventScript_GiftMon
	goto SaffronCity_SilphCo_EventScript_AfterStarterGiven
SaffronCity_SilphCo_EventScript_TorchicChosen::
	closemessage
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_TORCHIC
	bufferspeciesname STR_VAR_1, SPECIES_TORCHIC
	msgbox SaffronCity_SilphCo_Text_Steven3, MSGBOX_DEFAULT
	givemon SPECIES_TORCHIC, 5
	call Common_EventScript_GiftMon
	goto SaffronCity_SilphCo_EventScript_AfterStarterGiven
SaffronCity_SilphCo_EventScript_MudkipChosen::
	closemessage
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_MUDKIP
	bufferspeciesname STR_VAR_1, SPECIES_MUDKIP
	msgbox SaffronCity_SilphCo_Text_Steven3, MSGBOX_DEFAULT
	givemon SPECIES_MUDKIP, 5
	call Common_EventScript_GiftMon
	goto SaffronCity_SilphCo_EventScript_AfterStarterGiven

SaffronCity_SilphCo_EventScript_AfterStarterGiven::
	msgbox SaffronCity_SilphCo_Text_Steven4, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_NORTH, SaffronCity_SilphCo_EventScript_PlayerMove
	applymovement LOCALID_SILPHCO_STEVEN, SaffronCity_SilphCo_Movement_StevenLeave
	waitmovement 0
	playse SE_EXIT
	setflag FLAG_GOT_HOENN_STARTER
	removeobject LOCALID_SILPHCO_STEVEN
	release
	end

SaffronCity_SilphCo_EventScript_PlayerMove:
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight1
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	return

SaffronCity_SilphCo_Movement_StevenLeave:
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end


SaffronCity_SilphCo_Text_Steven1:
	.string "Allô...\n"
	.string "La connexion est mauvaise...\l"
	.string "Je crois que ça dépend de mon père.\l"
	.string "Je vois...\n"
	.string "Je vais y aller. À bientôt.$"
SaffronCity_SilphCo_Text_Steven2:
	.string "PIERRE : Tu es... Je me souviens de\n"
	.string "tes yeux.\p"
	.string "Quand je vois un Dresseur avec des\n"
	.string "yeux pétillants, je m'en souviens toujours.\p"
	.string "Tu as un Pokédex ! Donc tu es\n"
	.string "aussi à la recherche de Pokémon !\l"
	.string "Voyons voir...\p"
	.string "Je pense que je peux t'aider.\p"
	.string "Imaginons que tu as des pierres\n"
	.string "devant toi. Quelle couleur\l"
	.string "choisirais-tu ?$"
SaffronCity_SilphCo_Text_Steven3:
	.string "Tu as bien choisi ! Je vais te donner\n"
	.string "{STR_VAR_1} !$"
SaffronCity_SilphCo_Text_Steven4:
	.string "Prends-en bien soin. Savoir qu'il est\n"
	.string "entre de bonnes mains me rend très heureux.$"

SaffronCity_SilphCo_EventScript_Receptionist::
	msgbox SilphCo_Text_Receptionist, MSGBOX_NPC
	end
SaffronCity_SilphCo_EventScript_Officer::
	goto_if_set FLAG_GOT_UP_GRADE, SaffronCity_SilphCo_EventScript_OfficerAfter
	msgbox SilphCo_Text_Officer, MSGBOX_NPC
	giveitem ITEM_UP_GRADE
	setflag FLAG_GOT_UP_GRADE
SaffronCity_SilphCo_EventScript_OfficerAfter::
	msgbox SilphCo_Text_Officer_GotUpGrade, MSGBOX_NPC
	end

SaffronCity_SilphCo_EventScript_Sign1::
	msgbox SilphCo_Text_Sign1, MSGBOX_SIGN
	end

SaffronCity_SilphCo_EventScript_Sign2::
	msgbox SilphCo_Text_Sign2, MSGBOX_SIGN
	end

SilphCo_Text_Sign1:
	.string "SILPH SARL\n"
	.string "1er ÉTAGE ACCUEIL.$"

SilphCo_Text_Sign2:
	.string "SILPH SARL\n"
	.string "ASCENSEUR HORS SERVICE$"

SilphCo_Text_Receptionist:
	.string "Bienvenue. Vous êtes au SIÈGE\n"
	.string "SOCIAL de la SILPH SARL.$"

SilphCo_Text_Officer:
	.string "Seuls les employés sont autorisés à\n"
	.string "monter à l'étage.\p"
	.string "Mais puisque tu es venu de si loin,\p"
	.string "prends ce petit souvenir.$"

SilphCo_Text_Officer_GotUpGrade:
	.string "C'est le tout dernier produit de la SILPH SARL.\p"
	.string "Il n'est pas encore en vente.$"
