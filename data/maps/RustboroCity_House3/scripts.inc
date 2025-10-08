RustboroCity_House3_MapScripts::
	.byte 0

RustboroCity_House3_EventScript_OldMan::
	msgbox RustboroCity_House3_Text_IGivePerfectlySuitedNicknames, MSGBOX_NPC
	end

RustboroCity_House3_EventScript_OldWoman::
	msgbox RustboroCity_House3_Text_NamingPikachuPekachu, MSGBOX_NPC
	end

@ Misspelling on purpose, see nickname
RustboroCity_House3_EventScript_Pekachu::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PIKACHU, CRY_MODE_NORMAL
	msgbox RustboroCity_House3_Text_Pekachu, MSGBOX_DEFAULT
	waitmoncry
	release
	end

RustboroCity_House3_Text_IGivePerfectlySuitedNicknames:
	.string "Pour mes propres POKéMON, je leur donne\n"
	.string "des surnoms parfaitement adaptés !\p"
	.string "C'est ma façon d'exprimer, euh…\n"
	.string "l'originalité, oui, c'est ça !$"

RustboroCity_House3_Text_NamingPikachuPekachu:
	.string "Mais donner le nom PEKACHU à\n"
	.string "un PIKACHU ? Cela semble inutile.\p"
	.string "Je suppose que c'est bien d'utiliser un nom\n"
	.string "facile à comprendre, mais…$"

RustboroCity_House3_Text_Pekachu:
	.string "PEKACHU : Peka !$"

