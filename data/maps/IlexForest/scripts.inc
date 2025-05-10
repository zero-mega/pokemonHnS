.set LOCALID_ILEX_FOREST_FARFETCHD_1, 3
.set LOCALID_ILEX_FOREST_FARFETCHD_2, 33
.set LOCALID_ILEX_FOREST_FARFETCHD_3, 35
.set LOCALID_ILEX_FOREST_FARFETCHD_4, 34

IlexForest_MapScripts::
	.byte 0
	
IlexForest_EventScript_Apprentice::
	lock
	faceplayer
	goto_if_eq VAR_ILEX_FOREST_FARFETCHD, 2, IlexForest_EventScript_Apprentice2
	msgbox IlexForest_Text_ApprenticeIntro, MSGBOX_DEFAULT
	closemessage
	release
	end

IlexForest_EventScript_Apprentice2::
	msgbox IlexForest_Text_ApprenticeAfter, MSGBOX_DEFAULT
	closemessage
	release
	end

IlexForest_EventScript_Boss::
	lock
	faceplayer
	msgbox IlexForest_Text_CharcoalMasterTalkAfter, MSGBOX_DEFAULT
	closemessage
	release
	end

IlexForest_EventScript_Farfetchd_1A::
	lock
	faceplayer
	playmoncry SPECIES_FARFETCHD, CRY_MODE_NORMAL
	msgbox IlexForest_Text_Kwaaaa, MSGBOX_DEFAULT
	waitmoncry
	closemessage
	goto_if_eq VAR_ILEX_FOREST_FARFETCHD, 3, IlexForest_EventScript_Farfetchd_Done
	goto_if_eq VAR_ILEX_FOREST_FARFETCHD, 2, IlexForest_EventScript_Farfetchd_Done
	goto_if_eq VAR_ILEX_FOREST_FARFETCHD, 1, IlexForest_EventScript_Farfetchd_Leave
	goto_if_eq VAR_FACING, DIR_SOUTH, IlexForest_EventScript_Farfetchd_1B
	applymovement LOCALID_ILEX_FOREST_FARFETCHD_1, IlexForest_Movement_Farfetchd_1A
	waitmovement 0
	setflag FLAG_HIDE_ILEX_FOREST_FARFETCHD_1
	removeobject LOCALID_ILEX_FOREST_FARFETCHD_1
	@add clockwise farfetchd
	clearflag FLAG_HIDE_ILEX_FOREST_FARFETCHD_2
	addobject LOCALID_ILEX_FOREST_FARFETCHD_2
	release
	end
IlexForest_EventScript_Farfetchd_1B::
	applymovement LOCALID_ILEX_FOREST_FARFETCHD_1, IlexForest_Movement_Farfetchd_1B
	waitmovement 0
	setvar VAR_ILEX_FOREST_FARFETCHD, 1
	release
	end

IlexForest_EventScript_Farfetchd_2A::
	lock
	faceplayer
	playmoncry SPECIES_FARFETCHD, CRY_MODE_NORMAL
	msgbox IlexForest_Text_Kwaaaa, MSGBOX_DEFAULT
	waitmoncry
	closemessage
	goto_if_eq VAR_FACING, DIR_SOUTH, IlexForest_EventScript_Farfetchd_2B
	applymovement LOCALID_ILEX_FOREST_FARFETCHD_2, IlexForest_Movement_Farfetchd_2A
	waitmovement 0
	setflag FLAG_HIDE_ILEX_FOREST_FARFETCHD_2
	removeobject LOCALID_ILEX_FOREST_FARFETCHD_2
	@add clockwise farfetchd
	clearflag FLAG_HIDE_ILEX_FOREST_FARFETCHD_3
	addobject LOCALID_ILEX_FOREST_FARFETCHD_3
	release
	end
IlexForest_EventScript_Farfetchd_2B::
	applymovement LOCALID_ILEX_FOREST_FARFETCHD_2, IlexForest_Movement_Farfetchd_2B
	waitmovement 0
	setflag FLAG_HIDE_ILEX_FOREST_FARFETCHD_2
	removeobject LOCALID_ILEX_FOREST_FARFETCHD_2
	@add counterclockwise farfetchd
	clearflag FLAG_HIDE_ILEX_FOREST_FARFETCHD_1
	addobject LOCALID_ILEX_FOREST_FARFETCHD_1
	release
	end

IlexForest_EventScript_Farfetchd_3A::
	lock
	faceplayer
	playmoncry SPECIES_FARFETCHD, CRY_MODE_NORMAL
	msgbox IlexForest_Text_Kwaaaa, MSGBOX_DEFAULT
	waitmoncry
	closemessage
	goto_if_eq VAR_FACING, DIR_SOUTH, IlexForest_EventScript_Farfetchd_3B
	applymovement LOCALID_ILEX_FOREST_FARFETCHD_3, IlexForest_Movement_Farfetchd_3A
	waitmovement 0
	setflag FLAG_HIDE_ILEX_FOREST_FARFETCHD_3
	removeobject LOCALID_ILEX_FOREST_FARFETCHD_3
	@add clockwise farfetchd
	clearflag FLAG_HIDE_ILEX_FOREST_FARFETCHD_2
	addobject LOCALID_ILEX_FOREST_FARFETCHD_2
	release
	end
IlexForest_EventScript_Farfetchd_3B::
	applymovement LOCALID_ILEX_FOREST_FARFETCHD_3, IlexForest_Movement_Farfetchd_3B
	waitmovement 0
	setflag FLAG_HIDE_ILEX_FOREST_FARFETCHD_3
	removeobject LOCALID_ILEX_FOREST_FARFETCHD_3
	@add counterclockwise farfetchd
	clearflag FLAG_HIDE_ILEX_FOREST_FARFETCHD_4
	addobject LOCALID_ILEX_FOREST_FARFETCHD_4
	release
	end

IlexForest_EventScript_Farfetchd_4A::
	lock
	faceplayer
	playmoncry SPECIES_FARFETCHD, CRY_MODE_NORMAL
	msgbox IlexForest_Text_Kwaaaa, MSGBOX_DEFAULT
	waitmoncry
	closemessage
	goto_if_eq VAR_FACING, DIR_SOUTH, IlexForest_EventScript_Farfetchd_4B
	applymovement LOCALID_ILEX_FOREST_FARFETCHD_4, IlexForest_Movement_Farfetchd_4A
	waitmovement 0
	setflag FLAG_HIDE_ILEX_FOREST_FARFETCHD_4
	removeobject LOCALID_ILEX_FOREST_FARFETCHD_4
	@add clockwise farfetchd
	clearflag FLAG_HIDE_ILEX_FOREST_FARFETCHD_3
	addobject LOCALID_ILEX_FOREST_FARFETCHD_3
	release
	end
IlexForest_EventScript_Farfetchd_4B::
	applymovement LOCALID_ILEX_FOREST_FARFETCHD_4, IlexForest_Movement_Farfetchd_4B
	waitmovement 0
	setflag FLAG_HIDE_ILEX_FOREST_FARFETCHD_4
	removeobject LOCALID_ILEX_FOREST_FARFETCHD_4
	@add counterclockwise farfetchd
	clearflag FLAG_HIDE_ILEX_FOREST_FARFETCHD_1
	addobject LOCALID_ILEX_FOREST_FARFETCHD_1
	release
	end


IlexForest_EventScript_Farfetchd_Leave::
	goto_if_eq VAR_FACING, DIR_EAST, IlexForest_EventScript_Farfetchd_Return
	applymovement LOCALID_ILEX_FOREST_FARFETCHD_1, IlexForest_Movement_Farfetchd_Leave
	waitmovement 0
	setvar VAR_ILEX_FOREST_FARFETCHD, 2
	clearflag FLAG_HIDE_AZALEA_TOWN_FARFETCHD
	clearflag FLAG_HIDE_ILEX_FOREST_MASTER
	addobject 1
	release
	end
IlexForest_EventScript_Farfetchd_Return::
	setvar VAR_ILEX_FOREST_FARFETCHD, 0
	applymovement LOCALID_ILEX_FOREST_FARFETCHD_1, IlexForest_Movement_Farfetchd_Return
	waitmovement 0
	release
	end
IlexForest_EventScript_Farfetchd_Done::
	release
	end



IlexForest_EventScript_TriggerBot::
	lock
	applymovement OBJ_EVENT_ID_PLAYER Common_Movement_WalkUp
	waitmovement 0
IlexForest_EventScript_Trigger::
	lock
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	msgbox IlexForest_Text_CharcoalMasterIntro, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_HM_CUT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox IlexForest_Text_CharcoalMasterOutro, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_HM_CUT
	setflag FLAG_HIDE_ILEX_FOREST_MASTER
	setflag FLAG_HIDE_ILEX_FOREST_APPRENTICE
	setflag FLAG_HIDE_ILEX_FOREST_FARFETCHD_1
	setvar VAR_ILEX_FOREST_FARFETCHD, 3
	setvar VAR_AZALEA_TOWN_STATE, 7
	closemessage
	release
	end

IlexForest_Movement_Farfetchd_1A:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end
IlexForest_Movement_Farfetchd_1B:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end
IlexForest_Movement_Farfetchd_2A:
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end
IlexForest_Movement_Farfetchd_2B:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end
IlexForest_Movement_Farfetchd_3A:
	walk_fast_up
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end
IlexForest_Movement_Farfetchd_3B:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end
IlexForest_Movement_Farfetchd_4A:
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end
IlexForest_Movement_Farfetchd_4B:
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

IlexForest_Movement_Farfetchd_Leave:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	face_down
	step_end
IlexForest_Movement_Farfetchd_Return:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up	
	step_end

IlexForest_Text_ApprenticeIntro:
	.string "Oh, man… My boss is going to be\n"
	.string "steaming…\p"
	.string "The FARFETCH'D that CUTS trees\n"
	.string "for charcoal took off on me.\p"
	.string "I can't go looking for it here\n"
	.string "in the ILEX FOREST.\p"
	.string "It's too big, dark and scary\n"
	.string "for me…$"

IlexForest_Text_ApprenticeAfter:
	.string "Wow! Thanks a whole bunch!\p"
	.string "My boss's POKéMON won't obey me\n"
	.string "because I don't have a BADGE.$"

IlexForest_Text_ItsTheMissingPokemon:
	.string "It's the missing POKéMON!$"

IlexForest_Text_Kwaaaa:
	.string "FARFETCH'D: Kwaa!$"

IlexForest_Text_CharcoalMasterIntro:
	.string "Ah! My FARFETCH'D!\p"
	.string "You found it for us, kid?\p"
	.string "Without it, we wouldn't be able\n"
	.string "to CUT trees for charcoal.\p"
	.string "Thanks, kid!\p"
	.string "Now, how can I thank you…\p"
	.string "I know! Here, take this.$"

IlexForest_Text_CharcoalMasterOutro:
	.string "That's the CUT HM.\n"
	.string "Teach that to a POKéMON to clear\n"
	.string "small trees.\p"
	.string "Of course, you have to have the\n"
	.string "GYM BADGE from AZALEA to use it.$"

IlexForest_Text_CharcoalMasterTalkAfter:
	.string "Do you want to apprentice as a\n"
	.string "charcoal maker with me?\p"
	.string "You'll be first-rate in ten years!$"

IlexForest_Text_HeadbuttIntro:
	.string "What am I doing?\p"
	.string "I'm shaking trees using HEADBUTT.\p"
	.string "It's fun. Here, you try it too!$"

IlexForest_Text_HeadbuttOutro:
	.string "Rattle trees with HEADBUTT.\n"
	.string "Sometimes, sleeping POKéMON fall out.$"

IlexForest_Text_Lass:
	.string "Did something happen to the\n"
	.string "forest's guardian?$"

IlexForest_Text_Signpost:
	.string "ILEX FOREST is so overgrown with\n"
	.string "trees that you can't see the sky.\p"
	.string "Please watch out for items that may\n"
	.string "have been dropped.$"

IlexForest_Text_Shrine:
	.string "ILEX FOREST SHRINE…\p"
	.string "It's in honor of the forest's\n"
	.string "protector…$"

IlexForest_Text_ShrineCelebiEvent:
	.string "ILEX FOREST SHRINE…\p"
	.string "It's in honor of the forest's\n"
	.string "protector…\p"
	.string "Oh? What is this?\p"
	.string "It's a hole.\n"
	.string "It looks like the GS BALL would fit\n"
	.string "inside it.\p"
	.string "Want to put the GS BALL here?$"

IlexForest_Text_InsertGSBall:
	.string "{PLAYER} put in the GS BALL.$"

IlexForest_Text_KurtCaughtCelebi:
	.string "Whew, wasn't that something!\p"
	.string "{PLAYER}, that was fantastic. Thanks!\p"
	.string "The legends about that SHRINE were\n"
	.string "real after all.\p"
	.string "I feel inspired by what I just saw.\p"
	.string "It motivates me to make better BALLS!\p"
	.string "I'm going!$"

IlexForest_Text_BugCatcherWayneSeen:
	.string "Don't sneak up on me like that!\p"
	.string "You frightened a POKéMON away!$"

IlexForest_Text_BugCatcherWayneBeaten:
	.string "I hadn't seen that POKéMON before…$"

IlexForest_Text_BugCatcherWayneAfter:
	.string "A POKéMON I've never seen before\n"
	.string "fell out of the tree when I used\p"
	.string "HEADBUTT.\p"
	.string "I ought to use HEADBUTT in other\n"
	.string "places too.$"
