ShoalCave_LowTideLowerRoom_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, ShoalCave_LowTideLowerRoom_OnLoad
	.byte 0

ShoalCave_LowTideLowerRoom_OnLoad:
	call ShoalCave_LowTideLowerRoom_EventScript_SetShoalItemMetatiles
	end

ShoalCave_LowTideLowerRoom_EventScript_SetShoalItemMetatiles::
	goto_if_set FLAG_GARBAGEFLAG, ShoalCave_LowTideLowerRoom_EventScript_SetShoalItemMetatilesEnd
	setmetatile 18, 2, METATILE_Cave_ShoalCave_DirtPile_Large, TRUE
	return

ShoalCave_LowTideLowerRoom_EventScript_SetShoalItemMetatilesEnd::
	return

ShoalCave_LowTideLowerRoom_EventScript_ShoalSalt4::
	lockall
	goto_if_set FLAG_GARBAGEFLAG, ShoalCave_LowTideLowerRoom_EventScript_ReceivedShoalSalt
	giveitem ITEM_SHOAL_SALT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setmetatile 18, 2, METATILE_Cave_ShoalCave_DirtPile_Small, FALSE
	special DrawWholeMapView
	setflag FLAG_GARBAGEFLAG
	releaseall
	end

ShoalCave_LowTideLowerRoom_EventScript_ReceivedShoalSalt::
	msgbox ShoalCave_Text_WasShoalSaltNowNothing, MSGBOX_DEFAULT
	releaseall
	end

ShoalCave_LowTideLowerRoom_EventScript_BlackBelt::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_FOCUS_BAND, ShoalCave_LowTideLowerRoom_EventScript_ReceivedFocusBand
	msgbox ShoalCave_LowTideLowerRoom_Text_CanOvercomeColdWithFocus, MSGBOX_DEFAULT
	giveitem ITEM_FOCUS_BAND
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_FOCUS_BAND
	release
	end

ShoalCave_LowTideLowerRoom_EventScript_ReceivedFocusBand::
	msgbox ShoalCave_LowTideLowerRoom_Text_EverythingStartsWithFocus, MSGBOX_DEFAULT
	release
	end

ShoalCave_LowTideLowerRoom_Text_CanOvercomeColdWithFocus:
	.string "Le froid pénétrant de ces lieux\n"
	.string "est un obstacle à l'entraînement.\p"
	.string "Mais avec de la concentration, on peut surmonter ça !\p"
	.string "Avec ce BANDEAU, concentre-toi et\n"
	.string "résiste au froid !$"

ShoalCave_LowTideLowerRoom_Text_EverythingStartsWithFocus:
	.string "Tout commence par la concentration !$"

