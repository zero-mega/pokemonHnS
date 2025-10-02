DarkCave_NorthSide_MapScripts::
	.byte 0

DarkCave2_EventScript_Item_BlackFlute::
	finditem ITEM_BLACK_FLUTE
	end

DarkCave2_EventScript_Item_StarPiece::
	finditem ITEM_STAR_PIECE
	end

DarkCave2_EventScript_BlackGlasses::
	lock
	faceplayer
	goto_if_set FLAG_GOT_BLACK_GLASSES, DarkCave2_EventScript_BlackGlassesGot
	msgbox DarkCave2_Text_Nerd, MSGBOX_DEFAULT
	giveitem ITEM_BLACK_GLASSES
	setflag FLAG_GOT_BLACK_GLASSES
	closemessage
	release
	end

DarkCave2_EventScript_BlackGlassesGot::
	msgbox DarkCave2_Text_Nerd2, MSGBOX_DEFAULT
	closemessage
	release
	end

DarkCave2_Text_Nerd:
    .string "Ouh ! Tu m'as fait sursauter !\p"
    .string "Je portais mes LUNETTES NOIRES, alors\n"
    .string "je ne t'ai pas vu du tout.\p"
    .string "Qu'est-ce que je fais ici ?\p"
    .string "Hé, ne t'en fais pas pour ça.\p"
    .string "Je vais te donner une paire de\n"
    .string "LUNETTES NOIRES, alors oublie que tu\n"
    .string "m'as vu, d'accord ?$"

DarkCave2_Text_Nerd2:
    .string "Les LUNETTES NOIRES augmentent la\n"
    .string "puissance des attaques de type TÉNÈBRES.$"
