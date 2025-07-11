.set LOCALID_INDIGOJUNCTION_POLICEMAN, 1

IndigoJunction_MapScripts::
	.byte 0

IndigoJunction_EventScript_Officer::
    msgbox VictoryRoadGate_Text_EightBadges, MSGBOX_NPC
    end

IndigoJunction_Trigger::
    lock
    playse SE_PIN
    applymovement LOCALID_INDIGOJUNCTION_POLICEMAN, Common_Movement_ExclamationMark
    delay 20
    msgbox VictoryRoadGate_Text_Officer, MSGBOX_DEFAULT
    goto_if_lt NUM_BADGES, 7, IndigoJunction_EventScript_NotEnough
    msgbox VictoryRoadGate_Text_EightBadges, MSGBOX_DEFAULT
    closemessage
    setvar VAR_ROUTE27_STATE, 2
    release
    end

IndigoJunction_EventScript_NotEnough::
    msgbox VictoryRoadGate_Text_NotEnoughBadges, MSGBOX_DEFAULT
    closemessage
    applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown1
    waitmovement 0
    release
    end

IndigoJunction_EventScript_SilverGuard::
    msgbox VictoryRoadGate_Text_LeftBlackBelt, MSGBOX_NPC
    end
IndigoJunction_EventScript_KantoGuard::
    msgbox VictoryRoadGate_Text_RightBlackBelt, MSGBOX_NPC
    end

VictoryRoadGate_Text_Officer:
    .string "Only trainers who have proven them-\n"
    .string "selves may pass.$"

VictoryRoadGate_Text_NotEnoughBadges:
    .string "You don't have all the GYM BADGES\n"
    .string "of JOHTO.\p"
    .string "I'm sorry, but I can't let you go\n"
    .string "through.$"

VictoryRoadGate_Text_EightBadges:
    .string "Oh! The eight BADGES of JOHTO!\p"
    .string "Please, go right on through!$"

VictoryRoadGate_Text_LeftBlackBelt:
    .string "This way leads to MT.SILVER.\p"
    .string "You'll see scary-strong POKéMON out\n"
    .string "there.$"

VictoryRoadGate_Text_RightBlackBelt:
    .string "Off to the POKéMON LEAGUE, are you?\p"
    .string "The ELITE FOUR are so strong it's\n"
    .string "scary, and they're ready for you!$"
