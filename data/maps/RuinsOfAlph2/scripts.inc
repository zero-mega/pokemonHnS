RuinsOfAlph2_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, RuinsOfAlph2_OnLoad
	.byte 0

RuinsOfAlph2_OnLoad::
	call_if_set FLAG_COMPLETED_KABUTO_PUZZLE, RuinsOfAlph2_MapScript_KabutoHole
	call_if_set FLAG_COMPLETED_OMANYTE_PUZZLE, RuinsOfAlph2_MapScript_OmanyteHole
	call_if_set FLAG_COMPLETED_AERODACTYL_PUZZLE, RuinsOfAlph2_MapScript_AerodactylHole
	call_if_set FLAG_COMPLETED_HOOH_PUZZLE, RuinsOfAlph2_MapScript_HoohHole
	end

RuinsOfAlph2_MapScript_KabutoHole::
	setmetatile 20, 6, METATILE_TanobyRuins_69_Floor_Hole, FALSE
	setmetatile 21, 6, METATILE_TanobyRuins_69_Floor_Hole, FALSE
	return
RuinsOfAlph2_MapScript_OmanyteHole::
	setmetatile 4, 23, METATILE_TanobyRuins_69_Floor_Hole, FALSE
	setmetatile 5, 23, METATILE_TanobyRuins_69_Floor_Hole, FALSE
	return
RuinsOfAlph2_MapScript_AerodactylHole::
	setmetatile 20, 23, METATILE_TanobyRuins_69_Floor_Hole, FALSE
	setmetatile 21, 23, METATILE_TanobyRuins_69_Floor_Hole, FALSE
	return
RuinsOfAlph2_MapScript_HoohHole::
	setmetatile 4, 6, METATILE_TanobyRuins_69_Floor_Hole, FALSE
	setmetatile 5, 6, METATILE_TanobyRuins_69_Floor_Hole, FALSE
	return


RuinsOfAlph2_MapScript_KabutoDescripton::
	lock
	msgbox RuinsOfAlph2_Text_Kabuto, MSGBOX_DEFAULT
	release
	end
RuinsOfAlph2_MapScript_OmanyteDescription::
	lock
	msgbox RuinsOfAlph2_Text_Omanyte, MSGBOX_DEFAULT
	release
	end
RuinsOfAlph2_MapScript_AerodactylDescription::
	lock
	msgbox RuinsOfAlph2_Text_Aerodactyl, MSGBOX_DEFAULT
	release
	end
RuinsOfAlph2_MapScript_HoohDescription::
	lock
	msgbox RuinsOfAlph2_Text_Hooh, MSGBOX_DEFAULT
	release
	end
RuinsOfAlph2_MapScript_StatueDescription::
	lock
	msgbox RuinsOfAlph2_Text_Statue, MSGBOX_DEFAULT
	release
	end
RuinsOfAlph2_MapScript_UnownText::
	lock
	msgbox RuinsOfAlph2_Text_UnownText, MSGBOX_DEFAULT
	release
	end

RuinsOfAlph2_EventScript_Receptionist::
	lock
	faceplayer
	goto_if_set FLAG_COMPLETED_KABUTO_PUZZLE, RuinsOfAlph2_EventScript_Receptionist2
	msgbox RuinsOfAlph2_Text_Receptionist1, MSGBOX_DEFAULT
	release
	end
RuinsOfAlph2_EventScript_Receptionist2::
	msgbox RuinsOfAlph2_Text_Receptionist2, MSGBOX_DEFAULT
	release
	end


RuinsOfAlph2_EventScript_KabutoPuzzle::
	fadescreen FADE_TO_BLACK
	setvar VAR_0x8004, SLIDING_PUZZLE_KABUTO
	goto_if_set FLAG_COMPLETED_KABUTO_PUZZLE, RuinsOfAlph2_EventScript_KabutoPuzzleCompleted
	setvar VAR_0x8005, FALSE // or TRUE if you want to display the solved puzzle
	special DoSlidingPuzzle
	waitstate
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph2_MapScript_KabutoSuccess
	end
RuinsOfAlph2_EventScript_KabutoPuzzleCompleted::
	setvar VAR_0x8005, TRUE // or TRUE if you want to display the solved puzzle
	special DoSlidingPuzzle
	waitstate
	end
RuinsOfAlph2_MapScript_KabutoSuccess::
	setflag FLAG_COMPLETED_KABUTO_PUZZLE
	setmetatile 20, 6, METATILE_TanobyRuins_69_Floor_Hole, FALSE
	setmetatile 21, 6, METATILE_TanobyRuins_69_Floor_Hole, FALSE
	playse SE_CLICK
	special DrawWholeMapView
	end


RuinsOfAlph2_EventScript_OmanytePuzzle::
	fadescreen FADE_TO_BLACK
	setvar VAR_0x8004, SLIDING_PUZZLE_OMANYTE
	goto_if_set FLAG_COMPLETED_OMANYTE_PUZZLE, RuinsOfAlph2_EventScript_OmanytePuzzleCompleted
	setvar VAR_0x8005, FALSE // or TRUE if you want to display the solved puzzle
	special DoSlidingPuzzle
	waitstate
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph2_MapScript_OmanyteSuccess
	end
RuinsOfAlph2_EventScript_OmanytePuzzleCompleted::
	setvar VAR_0x8005, TRUE // or TRUE if you want to display the solved puzzle
	special DoSlidingPuzzle
	waitstate
	end
RuinsOfAlph2_MapScript_OmanyteSuccess::
	setflag FLAG_COMPLETED_OMANYTE_PUZZLE
	setmetatile 4, 23, METATILE_TanobyRuins_69_Floor_Hole, FALSE
	setmetatile 5, 23, METATILE_TanobyRuins_69_Floor_Hole, FALSE
	playse SE_CLICK
	special DrawWholeMapView
	end


RuinsOfAlph2_EventScript_AerodactylPuzzle::
	fadescreen FADE_TO_BLACK
	setvar VAR_0x8004, SLIDING_PUZZLE_AERODACTYL
	goto_if_set FLAG_COMPLETED_AERODACTYL_PUZZLE, RuinsOfAlph2_EventScript_AerodactylPuzzleCompleted
	setvar VAR_0x8005, FALSE // or TRUE if you want to display the solved puzzle
	special DoSlidingPuzzle
	waitstate
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph2_MapScript_AerodactylSuccess
	end
RuinsOfAlph2_EventScript_AerodactylPuzzleCompleted::
	setvar VAR_0x8005, TRUE // or TRUE if you want to display the solved puzzle
	special DoSlidingPuzzle
	waitstate
	end
RuinsOfAlph2_MapScript_AerodactylSuccess::
	setflag FLAG_COMPLETED_AERODACTYL_PUZZLE
	setmetatile 20, 23, METATILE_TanobyRuins_69_Floor_Hole, FALSE
	setmetatile 21, 23, METATILE_TanobyRuins_69_Floor_Hole, FALSE
	playse SE_CLICK
	special DrawWholeMapView
	end


RuinsOfAlph2_EventScript_HooHPuzzle::
	fadescreen FADE_TO_BLACK
	setvar VAR_0x8004, SLIDING_PUZZLE_HO_OH
	goto_if_set FLAG_COMPLETED_HOOH_PUZZLE, RuinsOfAlph2_EventScript_HoohPuzzleCompleted
	setvar VAR_0x8005, FALSE // or TRUE if you want to display the solved puzzle
	special DoSlidingPuzzle
	waitstate
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph2_MapScript_HoohSuccess
	end
RuinsOfAlph2_EventScript_HoohPuzzleCompleted::
	setvar VAR_0x8005, TRUE // or TRUE if you want to display the solved puzzle
	special DoSlidingPuzzle
	waitstate
	end
RuinsOfAlph2_MapScript_HoohSuccess::
	setflag FLAG_COMPLETED_HOOH_PUZZLE
	setmetatile 4, 6, METATILE_TanobyRuins_69_Floor_Hole, FALSE
	setmetatile 5, 6, METATILE_TanobyRuins_69_Floor_Hole, FALSE
	playse SE_CLICK
	special DrawWholeMapView
	end

RuinsOfAlph2_EventScript_CheckHooh::
	lock
	goto_if_set FLAG_HOOH_BROUGHT, RuinsOfAlph2_EventScript_RewardGotten
	specialvar VAR_RESULT, CheckHooh
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph2_EventScript_RewardHooh
	msgbox RuinsOfAlph2_Text_Mon, MSGBOX_SIGN
	closemessage
	release
	end
RuinsOfAlph2_EventScript_RewardHooh::
	setvar VAR_0x8006, 4  @ num shakes
	setvar VAR_0x8007, 2  @ shake delay
	special ShakeCamera
	delay 30
	waitse
	msgbox RuinsOfAlph2_Text_Reward, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_LUM_BERRY
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_HOOH_BROUGHT
	giveitem ITEM_CHARCOAL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	giveitem ITEM_MAX_REVIVE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	giveitem ITEM_SITRUS_BERRY
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_HOOH_BROUGHT
	release
	end

RuinsOfAlph2_EventScript_CheckAerodactyl::
	lock
	goto_if_set FLAG_AERODACTYL_BROUGHT, RuinsOfAlph2_EventScript_RewardGotten
	specialvar VAR_RESULT, CheckAerodactyl
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph2_EventScript_RewardAerodactyl
	msgbox RuinsOfAlph2_Text_Mon, MSGBOX_SIGN
	closemessage
	release
	end
RuinsOfAlph2_EventScript_RewardAerodactyl::
	setvar VAR_0x8006, 4  @ num shakes
	setvar VAR_0x8007, 2  @ shake delay
	special ShakeCamera
	delay 30
	waitse
	msgbox RuinsOfAlph2_Text_Reward, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_HEAL_POWDER
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_AERODACTYL_BROUGHT
	giveitem ITEM_ENERGY_ROOT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	giveitem ITEM_SITRUS_BERRY
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	giveitem ITEM_MOON_STONE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_AERODACTYL_BROUGHT
	release
	end

RuinsOfAlph2_EventScript_CheckKabuto::
	lock
	goto_if_set FLAG_KABUTO_BROUGHT, RuinsOfAlph2_EventScript_RewardGotten
	specialvar VAR_RESULT, CheckKabuto
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph2_EventScript_RewardKabuto
	msgbox RuinsOfAlph2_Text_Mon, MSGBOX_SIGN
	closemessage
	release
	end
RuinsOfAlph2_EventScript_RewardKabuto::
	setvar VAR_0x8006, 4  @ num shakes
	setvar VAR_0x8007, 2  @ shake delay
	special ShakeCamera
	delay 30
	waitse
	msgbox RuinsOfAlph2_Text_Reward, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_HEAL_POWDER
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_KABUTO_BROUGHT
	giveitem ITEM_ENERGY_POWDER
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	giveitem ITEM_ORAN_BERRY
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	giveitem ITEM_PECHA_BERRY
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_KABUTO_BROUGHT
	release
	end

RuinsOfAlph2_EventScript_CheckOmanyte::
	lock
	goto_if_set FLAG_OMANYTE_BROUGHT, RuinsOfAlph2_EventScript_RewardGotten
	specialvar VAR_RESULT, CheckOmanyte
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph2_EventScript_RewardOmanyte
	msgbox RuinsOfAlph2_Text_Mon, MSGBOX_SIGN
	closemessage
	release
	end
RuinsOfAlph2_EventScript_RewardOmanyte::
	setvar VAR_0x8006, 4  @ num shakes
	setvar VAR_0x8007, 2  @ shake delay
	special ShakeCamera
	delay 30
	waitse
	msgbox RuinsOfAlph2_Text_Reward, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_STARDUST
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_OMANYTE_BROUGHT
	giveitem ITEM_STAR_PIECE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	giveitem ITEM_LUM_BERRY
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	giveitem ITEM_WATER_STONE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_OMANYTE_BROUGHT
	release
	end

RuinsOfAlph2_EventScript_RewardGotten::
	msgbox RuinsOfAlph2_Text_Solved, MSGBOX_DEFAULT
	closemessage
	release
	end

RuinsOfAlph2_EventScript_HelixFossil::
	finditem ITEM_HELIX_FOSSIL
	end

RuinsOfAlph2_EventScript_DomeFossil::
	finditem ITEM_DOME_FOSSIL
	end

RuinsOfAlph2_EventScript_OldAmber::
	finditem ITEM_OLD_AMBER
	end

RuinsOfAlph2_EventScript_GSBALL::
	finditem ITEM_GS_BALL
	end

RuinsOfAlph2_Text_Reward:
	.string "The chamber reacts!\n"
	.string "Ancient ITEMS fall at your feet.$"

RuinsOfAlph2_Text_Mon:
	.string "This seems important...\n"
	.string "What could it mean?$"

RuinsOfAlph2_Text_Solved:
	.string "You solved this mystery already.$"

RuinsOfAlph2_Text_Receptionist1:
	.string "Welcome to this chamber.\p"
	.string "There are sliding panels that depict\n"
	.string "a POKéMON drawn by the ancients.\p"
	.string "Slide the panels around to form\n"
	.string "the picture.\p"
	.string "To the right is a description of\n"
	.string "the POKéMON.\p"
	.string "Scientists in the lab are examin-\n"
	.string "-ing some newly found patterns.$"

RuinsOfAlph2_Text_Receptionist2:
	.string "A hole just opened up in the floor!\n"
	.string "I'd better tell the others.$"

RuinsOfAlph2_Text_Kabuto:
	.string "A POKéMON that hid on the sea floor\n"
	.string "Eyes on its back scanned the area.$"

RuinsOfAlph2_Text_UnownText:
	.string "It's UNOWN text!$"

RuinsOfAlph2_Text_Statue:
	.string "It's a replica of an ancient\n"
	.string "POKéMON.$"

RuinsOfAlph2_Text_Aerodactyl:
	.string "This flying POKéMON attacked its\n"
	.string "prey with saw-like fangs.$"

RuinsOfAlph2_Text_Omanyte:
	.string "This POKéMON drifted in the sea\n"
	.string "by twisting its ten tentacles.$"

RuinsOfAlph2_Text_Hooh:
	.string "A POKéMON that flew gracefully on\n"
	.string "rainbow-colored wings.$"
