BattleTower_Outside_MapScripts::
	.byte 0

BattleTower_Outside_EventScript_BattleTowerSign::
	lock
	msgbox BattleTowerOutsideSignText, MSGBOX_SIGN	
	closemessage	
	release
	end
	
BattleTower_Outside_EventScript_Engineer::
	lock
	faceplayer
	msgbox BattleTowerOutsideText_Closed, MSGBOX_DEFAULT
	closemessage
	release
	end

BattleTower_Outside_EventScript_Youngster::
	lock
	faceplayer
	msgbox BattleTowerOutsideYoungsterText, MSGBOX_DEFAULT
	closemessage
	release
	end

BattleTower_Outside_EventScript_Beauty::
	lock
	faceplayer
	msgbox BattleTowerOutsideBeautyText, MSGBOX_DEFAULT
	closemessage
	release
	end

BattleTower_Outside_EventScript_Sailor::
	lock
	faceplayer
	msgbox BattleTowerOutsideSailorText, MSGBOX_DEFAULT
	closemessage
	release
	end

BattleTowerOutsideYoungsterText:
	.string "Wow, the BATTLE TOWER is huge!\p"
	.string "There must be many kinds of\n"
	.string "POKéMON in there!$"

BattleTowerOutsideBeautyText:
	.string "You can use only three POKéMON.\p"
	.string "It's so hard to decide which\n"
	.string "three should go into battle…$"

BattleTowerOutsideSailorText:
	.string "Hehehe, I snuck out from work.\p"
	.string "I can't bail out until I've won!\p"
	.string "I have to win it all. That I must!$"

BattleTowerOutsideSignText:
	.string "BATTLE TOWER\p"
	.string "Take the Ultimate Trainer\n"
	.string "Challenge!$"

BattleTowerOutsideText_Closed:
	.string "The BATTLE TOWER's is currently\n"
	.string "closed for repairs$"


BattleTower_Outside_EventScript_LeftMoveTutor::
	lock
	faceplayer
	setvar VAR_TEMP_C, SCROLL_MULTI_BF_MOVE_TUTOR_1
	goto_if_set FLAG_MET_FRONTIER_BEAUTY_MOVE_TUTOR, BattleTower_Outside_EventScript_AlreadyMetLeftTutor
	msgbox BattleTower_Outside_Text_LeftTutorIntro, MSGBOX_DEFAULT
	setflag FLAG_MET_FRONTIER_BEAUTY_MOVE_TUTOR
	goto BattleTower_Outside_EventScript_ChooseLeftTutorMove
	end

BattleTower_Outside_EventScript_AlreadyMetLeftTutor::
	msgbox BattleTower_Outside_Text_LeftTutorWelcomeBack, MSGBOX_DEFAULT
	goto BattleTower_Outside_EventScript_ChooseLeftTutorMove
	end

BattleTower_Outside_EventScript_ChooseLeftTutorMove::
	message BattleTower_Outside_Text_TeachWhichMove
	waitmessage
	special ShowBattlePointsWindow
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 0
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_1
	setvar VAR_0x8006, 0
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleTower_Outside_EventScript_Softboiled
	case 1, BattleTower_Outside_EventScript_SeismicToss
	case 2, BattleTower_Outside_EventScript_DreamEater
	case 3, BattleTower_Outside_EventScript_MegaPunch
	case 4, BattleTower_Outside_EventScript_MegaKick
	case 5, BattleTower_Outside_EventScript_BodySlam
	case 6, BattleTower_Outside_EventScript_RockSlide
	case 7, BattleTower_Outside_EventScript_Counter
	case 8, BattleTower_Outside_EventScript_ThunderWave
	case 9, BattleTower_Outside_EventScript_SwordsDance
	case 10, BattleTower_Outside_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, BattleTower_Outside_EventScript_ExitTutorMoveSelect
	end

BattleTower_Outside_EventScript_ChooseNewLeftTutorMove::
	message BattleTower_Outside_Text_TeachWhichMove
	waitmessage
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 0
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_1
	setvar VAR_0x8006, 1
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleTower_Outside_EventScript_Softboiled
	case 1, BattleTower_Outside_EventScript_SeismicToss
	case 2, BattleTower_Outside_EventScript_DreamEater
	case 3, BattleTower_Outside_EventScript_MegaPunch
	case 4, BattleTower_Outside_EventScript_MegaKick
	case 5, BattleTower_Outside_EventScript_BodySlam
	case 6, BattleTower_Outside_EventScript_RockSlide
	case 7, BattleTower_Outside_EventScript_Counter
	case 8, BattleTower_Outside_EventScript_ThunderWave
	case 9, BattleTower_Outside_EventScript_SwordsDance
	case 10, BattleTower_Outside_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, BattleTower_Outside_EventScript_ExitTutorMoveSelect
	end

BattleTower_Outside_EventScript_Softboiled::
	setvar VAR_0x8008, 16
	goto BattleTower_Outside_EventScript_ConfirmMoveSelection
	end

BattleTower_Outside_EventScript_SeismicToss::
	setvar VAR_0x8008, 24
	goto BattleTower_Outside_EventScript_ConfirmMoveSelection
	end

BattleTower_Outside_EventScript_DreamEater::
	setvar VAR_0x8008, 24
	goto BattleTower_Outside_EventScript_ConfirmMoveSelection
	end

BattleTower_Outside_EventScript_MegaPunch::
	setvar VAR_0x8008, 24
	goto BattleTower_Outside_EventScript_ConfirmMoveSelection
	end

BattleTower_Outside_EventScript_MegaKick::
	setvar VAR_0x8008, 48
	goto BattleTower_Outside_EventScript_ConfirmMoveSelection
	end

BattleTower_Outside_EventScript_BodySlam::
	setvar VAR_0x8008, 48
	goto BattleTower_Outside_EventScript_ConfirmMoveSelection
	end

BattleTower_Outside_EventScript_RockSlide::
	setvar VAR_0x8008, 48
	goto BattleTower_Outside_EventScript_ConfirmMoveSelection
	end

BattleTower_Outside_EventScript_Counter::
	setvar VAR_0x8008, 48
	goto BattleTower_Outside_EventScript_ConfirmMoveSelection
	end

BattleTower_Outside_EventScript_ThunderWave::
	setvar VAR_0x8008, 48
	goto BattleTower_Outside_EventScript_ConfirmMoveSelection
	end

BattleTower_Outside_EventScript_SwordsDance::
	setvar VAR_0x8008, 48
	goto BattleTower_Outside_EventScript_ConfirmMoveSelection
	end

BattleTower_Outside_EventScript_RightMoveTutor::
	lock
	faceplayer
	setvar VAR_TEMP_C, SCROLL_MULTI_BF_MOVE_TUTOR_2
	goto_if_set FLAG_MET_FRONTIER_SWIMMER_MOVE_TUTOR, BattleTower_Outside_EventScript_AlreadyMetRightTutor
	msgbox BattleTower_Outside_Text_RightTutorIntro, MSGBOX_DEFAULT
	setflag FLAG_MET_FRONTIER_SWIMMER_MOVE_TUTOR
	goto BattleTower_Outside_EventScript_ChooseRightTutorMove
	end

BattleTower_Outside_EventScript_AlreadyMetRightTutor::
	msgbox BattleTower_Outside_Text_RightTutorWelcomeBack, MSGBOX_DEFAULT
	goto BattleTower_Outside_EventScript_ChooseRightTutorMove
	end

BattleTower_Outside_EventScript_ChooseRightTutorMove::
	message BattleTower_Outside_Text_TeachWhichMove
	waitmessage
	special ShowBattlePointsWindow
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 1
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_2
	setvar VAR_0x8006, 0
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleTower_Outside_EventScript_DefenseCurl
	case 1, BattleTower_Outside_EventScript_Snore
	case 2, BattleTower_Outside_EventScript_MudSlap
	case 3, BattleTower_Outside_EventScript_Swift
	case 4, BattleTower_Outside_EventScript_IcyWind
	case 5, BattleTower_Outside_EventScript_Endure
	case 6, BattleTower_Outside_EventScript_PsychUp
	case 7, BattleTower_Outside_EventScript_IcePunch
	case 8, BattleTower_Outside_EventScript_ThunderPunch
	case 9, BattleTower_Outside_EventScript_FirePunch
	case 10, BattleTower_Outside_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, BattleTower_Outside_EventScript_ExitTutorMoveSelect
	end

BattleTower_Outside_EventScript_ChooseNewRightTutorMove::
	message BattleTower_Outside_Text_TeachWhichMove
	waitmessage
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 1
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_2
	setvar VAR_0x8006, 1
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleTower_Outside_EventScript_DefenseCurl
	case 1, BattleTower_Outside_EventScript_Snore
	case 2, BattleTower_Outside_EventScript_MudSlap
	case 3, BattleTower_Outside_EventScript_Swift
	case 4, BattleTower_Outside_EventScript_IcyWind
	case 5, BattleTower_Outside_EventScript_Endure
	case 6, BattleTower_Outside_EventScript_PsychUp
	case 7, BattleTower_Outside_EventScript_IcePunch
	case 8, BattleTower_Outside_EventScript_ThunderPunch
	case 9, BattleTower_Outside_EventScript_FirePunch
	case 10, BattleTower_Outside_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, BattleTower_Outside_EventScript_ExitTutorMoveSelect
	end

BattleTower_Outside_EventScript_DefenseCurl::
	setvar VAR_0x8008, 16
	goto BattleTower_Outside_EventScript_ConfirmMoveSelection
	end

BattleTower_Outside_EventScript_Snore::
	setvar VAR_0x8008, 24
	goto BattleTower_Outside_EventScript_ConfirmMoveSelection
	end

BattleTower_Outside_EventScript_MudSlap::
	setvar VAR_0x8008, 24
	goto BattleTower_Outside_EventScript_ConfirmMoveSelection
	end

BattleTower_Outside_EventScript_Swift::
	setvar VAR_0x8008, 24
	goto BattleTower_Outside_EventScript_ConfirmMoveSelection
	end

BattleTower_Outside_EventScript_IcyWind::
	setvar VAR_0x8008, 24
	goto BattleTower_Outside_EventScript_ConfirmMoveSelection
	end

BattleTower_Outside_EventScript_Endure::
	setvar VAR_0x8008, 48
	goto BattleTower_Outside_EventScript_ConfirmMoveSelection
	end

BattleTower_Outside_EventScript_PsychUp::
	setvar VAR_0x8008, 48
	goto BattleTower_Outside_EventScript_ConfirmMoveSelection
	end

BattleTower_Outside_EventScript_IcePunch::
	setvar VAR_0x8008, 48
	goto BattleTower_Outside_EventScript_ConfirmMoveSelection
	end

BattleTower_Outside_EventScript_ThunderPunch::
	setvar VAR_0x8008, 48
	goto BattleTower_Outside_EventScript_ConfirmMoveSelection
	end

BattleTower_Outside_EventScript_FirePunch::
	setvar VAR_0x8008, 48
	goto BattleTower_Outside_EventScript_ConfirmMoveSelection
	end

BattleTower_Outside_EventScript_ElementalMoveTutor::
	lock
	faceplayer
	setvar VAR_TEMP_C, SCROLL_MULTI_BF_MOVE_TUTOR_3
	goto_if_set FLAG_MET_FRONTIER_ELEMENTAL_MOVE_TUTOR, BattleTower_Outside_EventScript_AlreadyMetElementalTutor
	msgbox BattleTower_Outside_Text_ElementalTutorIntro, MSGBOX_DEFAULT
	setflag FLAG_MET_FRONTIER_ELEMENTAL_MOVE_TUTOR
	goto BattleTower_Outside_EventScript_ChooseElementalTutorMove
	end

BattleTower_Outside_EventScript_AlreadyMetElementalTutor::
	msgbox BattleTower_Outside_Text_ElementalTutorWelcomeBack, MSGBOX_DEFAULT
	goto BattleTower_Outside_EventScript_ChooseElementalTutorMove
	end

BattleTower_Outside_EventScript_ChooseElementalTutorMove::
	message BattleTower_Outside_Text_TeachWhichMoveElemental
	waitmessage
	special ShowBattlePointsWindow
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 2
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_3
	setvar VAR_0x8006, 0
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleTower_Outside_EventScript_FrenzyPlant
	case 1, BattleTower_Outside_EventScript_BlastBurn
	case 2, BattleTower_Outside_EventScript_HydroCannon
	case 4, BattleTower_Outside_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, BattleTower_Outside_EventScript_ExitTutorMoveSelect
	end

BattleTower_Outside_EventScript_ChooseNewElementalTutorMove::
	message BattleTower_Outside_Text_TeachWhichMoveElemental
	waitmessage
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 2
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_3
	setvar VAR_0x8006, 1
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleTower_Outside_EventScript_FrenzyPlant
	case 1, BattleTower_Outside_EventScript_BlastBurn
	case 2, BattleTower_Outside_EventScript_HydroCannon
	case 4, BattleTower_Outside_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, BattleTower_Outside_EventScript_ExitTutorMoveSelect
	end

BattleTower_Outside_EventScript_FrenzyPlant::
	setvar VAR_0x8008, 64
	goto BattleTower_Outside_EventScript_ConfirmMoveSelection
	end

BattleTower_Outside_EventScript_BlastBurn::
	setvar VAR_0x8008, 64
	goto BattleTower_Outside_EventScript_ConfirmMoveSelection
	end

BattleTower_Outside_EventScript_HydroCannon::
	setvar VAR_0x8008, 64
	goto BattleTower_Outside_EventScript_ConfirmMoveSelection
	end

BattleTower_Outside_EventScript_ExitTutorMoveSelect::
	special CloseBattleFrontierTutorWindow
	special CloseBattlePointsWindow
	msgbox BattleTower_Outside_Text_YouDontWantTo, MSGBOX_DEFAULT
	release
	end

BattleTower_Outside_EventScript_CancelChooseMon::
	msgbox BattleTower_Outside_Text_YouDontWantTo, MSGBOX_DEFAULT
	release
	end

@ VAR_0x8008 is the price
@ VAR_TEMP_C is the scroll multichoice ID
@ VAR_TEMP_FRONTIER_TUTOR_SELECTION is the move selection
@ VAR_TEMP_FRONTIER_TUTOR_ID is which move tutor was spoken to
BattleTower_Outside_EventScript_ConfirmMoveSelection::
	copyvar VAR_0x8004, VAR_TEMP_FRONTIER_TUTOR_SELECTION
	copyvar VAR_0x8005, VAR_TEMP_FRONTIER_TUTOR_ID
	special BufferBattleFrontierTutorMoveName
	buffernumberstring STR_VAR_2, VAR_0x8008
	copyvar VAR_0x8004, VAR_TEMP_C
	msgbox BattleTower_Outside_Text_MoveWillBeXBattlePoints, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleTower_Outside_EventScript_ChooseNewMove
	specialvar VAR_TEMP_1, GetFrontierBattlePoints
	goto_if_ge VAR_TEMP_1, VAR_0x8008, BattleTower_Outside_EventScript_TeachTutorMove
	msgbox BattleTower_Outside_Text_HaventGotEnoughPoints, MSGBOX_DEFAULT
	goto BattleTower_Outside_EventScript_ChooseNewMove
	end

BattleTower_Outside_EventScript_TeachTutorMove::
	msgbox BattleTower_Outside_Text_TeachMoveToWhichMon, MSGBOX_DEFAULT
	special GetBattleFrontierTutorMoveIndex
	fadescreen FADE_TO_BLACK
	special CloseBattlePointsWindow
	special CloseBattleFrontierTutorWindow
	special ChooseMonForMoveTutor
	waitstate
	goto_if_eq VAR_RESULT, FALSE, BattleTower_Outside_EventScript_CancelChooseMon
	msgbox BattleTower_Outside_Text_IllTakeBattlePoints, MSGBOX_DEFAULT
	copyvar VAR_0x8004, VAR_0x8008
	special TakeFrontierBattlePoints
	release
	end

BattleTower_Outside_EventScript_ChooseNewMove::
	goto_if_eq VAR_TEMP_FRONTIER_TUTOR_ID, 0, BattleTower_Outside_EventScript_ChooseNewLeftTutorMove
	goto_if_eq VAR_TEMP_FRONTIER_TUTOR_ID, 2, BattleTower_Outside_EventScript_ChooseNewElementalTutorMove
	goto BattleTower_Outside_EventScript_ChooseNewRightTutorMove
	end

BattleTower_Outside_Text_LeftTutorIntro:
	.string "Buhahaha!\p"
	.string "You couldn't tell it from looking now,\n"
	.string "but I used to be one tough TRAINER.\p"
	.string "I had a reputation as the toughest\n"
	.string "BEAUTY around, I tell you!\p"
	.string "… … … … … …\p"
	.string "What is it now?\n"
	.string "You don't believe me.\p"
	.string "I'm not like that blowhard woman over\n"
	.string "there. I'm actually talented!\p"
	.string "Let me prove it to you.\n"
	.string "I can teach your POKéMON special and\l"
	.string "yet cute moves.\p"
	.string "But my lessons don't come free.\n"
	.string "How about paying for the moves I teach\l"
	.string "with a wee bit of Battle Points?$"

BattleTower_Outside_Text_LeftTutorWelcomeBack:
	.string "Buhahaha!\p"
	.string "Are you back to learn special and\n"
	.string "yet cute POKéMON moves?$"

BattleTower_Outside_Text_TeachWhichMove:
	.string "Fine, fine, look here!\n"
	.string "Which move should I teach?$"

BattleTower_Outside_Text_MoveWillBeXBattlePoints:
	.string "The move {STR_VAR_1}, is it?\n"
	.string "That will be {STR_VAR_2} Battle Points, okay?$"

BattleTower_Outside_Text_TeachMoveToWhichMon:
	.string "Fine, fine, now pick the POKéMON\n"
	.string "I should teach the move to.$"

BattleTower_Outside_Text_HaventGotEnoughPoints:
	.string "What the…\n"
	.string "You haven't got enough Battle Points!$"

BattleTower_Outside_Text_IllTakeBattlePoints:
	.string "Do you see how skilled I am now?\n"
	.string "I'll take your Battle Points, thanks!$"

BattleTower_Outside_Text_YouDontWantTo:
	.string "What's that?\n"
	.string "You don't want to…\p"
	.string "If you want to see how skilled I am,\n"
	.string "you come see me anytime!$"

BattleTower_Outside_Text_RightTutorIntro:
	.string "Ihihihi!\p"
	.string "I know it's hard to see now, but I used\n"
	.string "to be one fantastic TRAINER.\p"
	.string "I had a reputation as the most\n"
	.string "invincible SWIMMER around, I tell you!\p"
	.string "… … … … … …\p"
	.string "What's wrong?\n"
	.string "You don't believe me.\p"
	.string "I'm not like that buffoonish woman over\n"
	.string "there. I'm actually experienced!\p"
	.string "I can prove it to you.\n"
	.string "I can teach your POKéMON hard and\l"
	.string "yet pretty moves.\p"
	.string "But my lessons don't come free.\n"
	.string "How about paying for the moves I teach\l"
	.string "with a wee bit of Battle Points?$"

BattleTower_Outside_Text_RightTutorWelcomeBack:
	.string "Ihihihi!\p"
	.string "Have you come to learn hard and\n"
	.string "yet pretty POKéMON moves?$"

BattleTower_Outside_Text_ThinkLadiesDontGetAlong:
	.string "Those ladies, the way they bad-mouth\n"
	.string "each other, you probably think that\l"
	.string "they don't get along.\p"
	.string "But if that were true, they wouldn't\n"
	.string "stay out here together, would they?$"

BattleTower_Outside_Text_LadiesWereStrongAndBeautiful:
	.string "When I was just a wee YOUNGSTER,\n"
	.string "those ladies were strong and beautiful.\p"
	.string "They were idols among us TRAINERS.\p"
	.string "Even now, age hasn't dulled their\n"
	.string "abilities.\p"
	.string "In fact, their POKéMON moves have\n"
	.string "grown even more polished.\p"
	.string "But… For some reason, I can't help\n"
	.string "but feel this…\p"
	.string "Time is so cruel…$"

BattleTower_Outside_Text_SoftboiledDesc::
	.string "Recovers up to\n"
	.string "half the user's\n"
	.string "maximum HP.$"

BattleTower_Outside_Text_SeismicTossDesc::
	.string "Inflicts damage\n"
	.string "identical to the\n"
	.string "user's level.$"

BattleTower_Outside_Text_DreamEaterDesc::
	.string "Recovers half the\n"
	.string "damage inflicted\n"
	.string "on a sleeping foe.$"

BattleTower_Outside_Text_MegaPunchDesc::
	.string "A strong punch\n"
	.string "thrown with\n"
	.string "incredible power.$"

BattleTower_Outside_Text_MegaKickDesc::
	.string "An extremely\n"
	.string "powerful kick with\n"
	.string "intense force.$"

BattleTower_Outside_Text_BodySlamDesc::
	.string "A full-body slam\n"
	.string "that may cause\n"
	.string "paralysis.$"

BattleTower_Outside_Text_RockSlideDesc::
	.string "Large boulders\n"
	.string "are hurled. May\n"
	.string "cause flinching.$"

BattleTower_Outside_Text_CounterDesc::
	.string "Retaliates any\n"
	.string "physical hit with\n"
	.string "double the power.$"

BattleTower_Outside_Text_ThunderWaveDesc::
	.string "A weak jolt of\n"
	.string "electricity that\n"
	.string "paralyzes the foe.$"

BattleTower_Outside_Text_SwordsDanceDesc::
	.string "A fighting dance\n"
	.string "that sharply\n"
	.string "raises ATTACK.$"

BattleTower_Outside_Text_DefenseCurlDesc::
	.string "Curls up to con-\n"
	.string "ceal weak spots\n"
	.string "and raise DEFENSE.$"

BattleTower_Outside_Text_SnoreDesc::
	.string "A loud attack\n"
	.string "that can be used\n"
	.string "only while asleep.$"

BattleTower_Outside_Text_MudSlapDesc::
	.string "Hurls mud in the\n"
	.string "foe's face to re-\n"
	.string "duce its accuracy.$"

BattleTower_Outside_Text_SwiftDesc::
	.string "Sprays star-\n"
	.string "shaped rays\n"
	.string "that never miss.$"

BattleTower_Outside_Text_IcyWindDesc::
	.string "A chilling attack\n"
	.string "that lowers the\n"
	.string "foe's SPEED.$"

BattleTower_Outside_Text_EndureDesc::
	.string "Endures any at-\n"
	.string "tack for 1 turn,\n"
	.string "leaving 1HP.$"

BattleTower_Outside_Text_PsychUpDesc::
	.string "Copies the foe's\n"
	.string "effect(s) and\n"
	.string "gives to the user.$"

BattleTower_Outside_Text_IcePunchDesc::
	.string "An icy punch\n"
	.string "that may\n"
	.string "freeze the foe.$"

BattleTower_Outside_Text_ThunderPunchDesc::
	.string "An electrified\n"
	.string "punch that may\n"
	.string "paralyze the foe.$"

BattleTower_Outside_Text_FirePunchDesc::
	.string "A fiery punch\n"
	.string "that may burn\n"
	.string "the foe.$"

BattleTower_Outside_Text_ElementalTutorIntro::
	.string "Zzzzzz…\p"
	.string "What, how, what?\p"
	.string "Oh, sorry, I was snoozing a bit.\p"
	.string "I'm the ELEMENTAL TUTOR.\p"
	.string "I have the power to teach the most\n"
	.string "powerful moves to GRASS, FIRE and\l"
	.string "WATER TYPE POKéMON.\p"
	.string "Did you come to learn such a strong\n"
	.string "power?$"

BattleTower_Outside_Text_ElementalTutorWelcomeBack:
	.string "Zzzzzz…\p"
	.string "What, how, what, who?\p"
	.string "Oh, did you come to learn the\n"
	.string "power of my strongest moves?$"

BattleTower_Outside_Text_TeachWhichMoveElemental::
	.string "Which move do you think is suitable\n"
	.string "for your POKéMON?$"

BattleTower_Outside_Text_StrongElementalMoveDesc::
	.string "Powerful, but\n"
	.string "leaves the user\n"
	.string "immobile one turn.$"

