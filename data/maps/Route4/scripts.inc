Route4_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route4_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route4_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route4_EventScript_HpUp::
	finditem ITEM_HP_UP
	end

Route4_EventScript_UltraBall::
	finditem ITEM_ULTRA_BALL
	end

Route4_EventScript_Hank::
	trainerbattle_single TRAINER_HANK, Route4_Text_BirdKeeperHank_Seen, Route4_Text_BirdKeeperHank_Beaten
	msgbox Route4_Text_BirdKeeperHank_AfterBattle, MSGBOX_AUTOCLOSE
	end

Route4_EventScript_Hope::
	trainerbattle_single TRAINER_HOPE, Route4_Text_PicnickerHope_Seen, Route4_Text_PicnickerHope_Beaten
	msgbox Route4_Text_PicnickerHope_AfterBattle, MSGBOX_AUTOCLOSE
	end

Route4_EventScript_Sharon::
	trainerbattle_single TRAINER_SHARON, Route4_Text_PicnickerSharon_Seen, Route4_Text_PicnickerSharon_Beaten
	msgbox Route4_Text_PicnickerSharon_AfterBattle, MSGBOX_AUTOCLOSE
	end

Route4_EventScript_Sign::
	msgbox Route4_Text_MtMoonSquareSign, MSGBOX_SIGN
	end

Route4_Text_BirdKeeperHank_Seen:
	.string "J'élève mes POKéMON. Veux-tu te battre\n"
	.string "avec moi ?$"

Route4_Text_BirdKeeperHank_Beaten:
	.string "Aïe ! J'ai perdu celui-là…$"

Route4_Text_BirdKeeperHank_AfterBattle:
	.string "Si tu veux entraîner un POKéMON en\n"
	.string "particulier, mets-le en premier, puis\n"
	.string "change-le tout de suite.\p"
	.string "C'est comme ça qu'il faut faire.$"

Route4_Text_PicnickerHope_Seen:
	.string "J'ai le sentiment que je peux gagner.\p"
	.string "Voyons si j'ai raison !$"

Route4_Text_PicnickerHope_Beaten:
	.string "Oh, tu es trop fort.$"

Route4_Text_PicnickerHope_AfterBattle:
	.string "J'ai entendu dire que des MÉLOFÉE\n"
	.string "apparaissent au MT.SELENITE.\p"
	.string "Mais où peuvent-ils être ?$"

Route4_Text_PicnickerSharon_Seen:
	.string "Euh…\n"
	.string "Je…$"

Route4_Text_PicnickerSharon_Beaten:
	.string "…$"

Route4_Text_PicnickerSharon_AfterBattle:
	.string "……Je vais m'entraîner encore…$"

Route4_Text_MtMoonSquareSign:
	.string "PLACE MT.SELENITE\p"
	.string "Montez simplement les escaliers.$"
