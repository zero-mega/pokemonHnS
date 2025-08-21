MtMoonOutside_MapScripts::
	.byte 0

MtMoon_EventScript_Moonstone::
	finditem ITEM_MOON_STONE
	end

MtMoonOutside_EventScript_Sign::
	msgbox MtMoonOutside_Text_DontLitterSign, MSGBOX_SIGN
	end

MtMoonOutside_EventScript_Clefairy::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_CLEFAIRY, CRY_MODE_NORMAL
	msgbox MtMoonOutside_Text_Clefairy, MSGBOX_DEFAULT
	waitmoncry
	release
	end

MtMoonOutside_Text_DontLitterSign:
	.string "MT.MOON SQUARE\n"
	.string "DON'T LITTER$"

MtMoonOutside_Text_Clefairy:
    .string "CLEFAIRY: Pi pippippi!$"

