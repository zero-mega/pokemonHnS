.set LOCALID_FAMILIAR_GRUNT, 13

SlateportCity_OceanicMuseum_1F_MapScripts::
	.byte 0

SlateportCity_OceanicMuseum_1F_EventScript_EntranceAttendant::
	msgbox SlateportCity_OceanicMuseum_1F_Text_PleaseEnjoyYourself, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFeeLeft::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFee
	end

SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFeeRight::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFee
	end

SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFee::
	showmoneybox 0, 0
	msgbox SlateportCity_OceanicMuseum_1F_Text_WouldYouLikeToEnter, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SlateportCity_OceanicMuseum_1F_EventScript_CheckMoneyForFee
	closemessage
	hidemoneybox
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_PushPlayerBackFromCounter
	waitmovement 0
	releaseall
	end

SlateportCity_OceanicMuseum_1F_EventScript_CheckMoneyForFee::
	checkmoney 50
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_OceanicMuseum_1F_EventScript_NotEnoughMoney
	playse SE_SHOP
	removemoney 50
	updatemoneybox
	msgbox SlateportCity_OceanicMuseum_1F_Text_PleaseEnjoyYourself, MSGBOX_DEFAULT
	setvar VAR_SLATEPORT_MUSEUM_1F_STATE, 1
	hidemoneybox
	releaseall
	end

SlateportCity_OceanicMuseum_1F_EventScript_NotEnoughMoney::
	goto_if_unset FLAG_DELIVERED_DEVON_GOODS, SlateportCity_OceanicMuseum_1F_EventScript_AllowEntranceAnyway
	msgbox SlateportCity_OceanicMuseum_1F_Text_NotEnoughMoney, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_PushPlayerBackFromCounter
	waitmovement 0
	releaseall
	end

SlateportCity_OceanicMuseum_1F_EventScript_AllowEntranceAnyway::
	msgbox SlateportCity_OceanicMuseum_1F_Text_CatchUpWithYourGroup, MSGBOX_DEFAULT
	setvar VAR_SLATEPORT_MUSEUM_1F_STATE, 1
	hidemoneybox
	releaseall
	end

SlateportCity_OceanicMuseum_1F_Movement_PushPlayerBackFromCounter:
	walk_down
	step_end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt1::
	msgbox SlateportCity_OceanicMuseum_1F_Text_AquaExistForGoodOfAll, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt2::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OurBossIsntHere, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt3::
	msgbox SlateportCity_OceanicMuseum_1F_Text_WouldStuffHereMakeMeRich, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt4::
	msgbox SlateportCity_OceanicMuseum_1F_Text_CanLearnForNefariousDeeds, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt5::
	msgbox SlateportCity_OceanicMuseum_1F_Text_RustboroBungled, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt6::
	msgbox SlateportCity_OceanicMuseum_1F_Text_DidntHaveMoney, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_WhirlpoolExperiment::
	msgbox SlateportCity_OceanicMuseum_1F_Text_WhirlpoolExperiment, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_WaterfallExperiment::
	msgbox SlateportCity_OceanicMuseum_1F_Text_WaterfallExperiment, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_OceanSoilDisplay::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OceanSoilDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_BeachSandDisplay::
	msgbox SlateportCity_OceanicMuseum_1F_Text_BeachSandDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_OceanicMinifact1::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact1, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_OceanicMinifact2::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact2, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_OceanicMinifact3::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact3, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_FossilDisplay::
	msgbox SlateportCity_OceanicMuseum_1F_Text_FossilDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_DepthMeasuringMachine::
	msgbox SlateportCity_OceanicMuseum_1F_Text_DepthMeasuringMachine, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron1::
	msgbox SlateportCity_OceanicMuseum_1F_Text_LearnAboutSeaForBattling, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron2::
	msgbox SlateportCity_OceanicMuseum_1F_Text_SternIsRoleModel, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron3::
	msgbox SlateportCity_OceanicMuseum_1F_Text_MustBePokemonWeDontKnow, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron4::
	msgbox SlateportCity_OceanicMuseum_1F_Text_WantSeaPokemon, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGrunt::
	lock
	faceplayer
	delay 8
	playse SE_PIN
	applymovement LOCALID_FAMILIAR_GRUNT, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_FAMILIAR_GRUNT, Common_Movement_Delay48
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_1F_Text_RememberMeTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_TM_THIEF
	goto_if_eq VAR_RESULT, 0, SlateportCity_OceanicMuseum_1F_EventScript_NoRoomForThief
	setflag FLAG_RECEIVED_TM_THIEF
	msgbox SlateportCity_OceanicMuseum_1F_Text_HopeINeverSeeYouAgain, MSGBOX_DEFAULT
	closemessage
	goto_if_eq VAR_FACING, DIR_NORTH, SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitNorth
	goto_if_eq VAR_FACING, DIR_SOUTH, SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitSouth
	goto_if_eq VAR_FACING, DIR_WEST, SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitWestEast
	goto_if_eq VAR_FACING, DIR_EAST, SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitWestEast
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitNorth::
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitNorth
	applymovement LOCALID_FAMILIAR_GRUNT, SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExitNorth
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExited
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitSouth::
	applymovement LOCALID_FAMILIAR_GRUNT, SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExit
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExited
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitWestEast::
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitWestEast
	applymovement LOCALID_FAMILIAR_GRUNT, SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExit
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExited
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExited::
	setflag FLAG_ITEM_GARBAGEFLAG
	playse SE_EXIT
	removeobject LOCALID_FAMILIAR_GRUNT
	release
	end

SlateportCity_OceanicMuseum_1F_EventScript_NoRoomForThief::
	msgbox SlateportCity_OceanicMuseum_1F_Text_YouHaveToTakeThis, MSGBOX_DEFAULT
	release
	end

SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitNorth:
	delay_16
	delay_8
	delay_4
	walk_in_place_faster_down
	step_end

SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitWestEast:
	delay_16
	walk_in_place_faster_down
	step_end

SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExit:
	face_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	delay_8
	step_end

SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExitNorth:
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	delay_8
	step_end

SlateportCity_OceanicMuseum_1F_Text_WouldYouLikeToEnter:
	.string "Bienvenue au MUSÉE OCÉANIQUE.\p"
	.string "L'entrée coûte 50¥.\n"
	.string "Voulez-vous entrer?$"

SlateportCity_OceanicMuseum_1F_Text_PleaseEnjoyYourself:
	.string "Profitez bien de votre visite.$"

SlateportCity_OceanicMuseum_1F_Text_NotEnoughMoney:
	.string "Oh ? Je suis désolé, mais il semble\n"
	.string "que vous n'ayez pas assez d'argent.$"

SlateportCity_OceanicMuseum_1F_Text_CatchUpWithYourGroup:
	.string "Oh ? Vous êtes avec ce groupe qui\n"
	.string "est entré tout à l'heure ?\p"
	.string "Vous êtes le seul en retard.\n"
	.string "Vous feriez mieux de les rattraper !$"

SlateportCity_OceanicMuseum_1F_Text_AquaExistForGoodOfAll:
	.string "Nous, la TEAM AQUA, existons pour\n"
	.string "le bien de tous !$"

SlateportCity_OceanicMuseum_1F_Text_OurBossIsntHere:
	.string "On nous a dit de nous rassembler ici,\n"
	.string "alors on l'a fait, mais…\p"
	.string "Notre CHEF, la pièce maîtresse, n'est pas là.$"

SlateportCity_OceanicMuseum_1F_Text_WouldStuffHereMakeMeRich:
	.string "Si je volais les objets ici,\n"
	.string "est-ce que je deviendrais riche ?$"

SlateportCity_OceanicMuseum_1F_Text_CanLearnForNefariousDeeds:
	.string "Ce que j'apprends ici, je peux\n"
	.string "l'utiliser pour des actes louches…$"

SlateportCity_OceanicMuseum_1F_Text_RustboroBungled:
	.string "Si nos sbires n'avaient pas tout raté\n"
	.string "à MÉTÉORVILLE, on ne serait pas là !$"

SlateportCity_OceanicMuseum_1F_Text_DidntHaveMoney:
	.string "Je n'avais pas 50¥, alors j'ai mis du\n"
	.string "temps à passer la réception.$"

SlateportCity_OceanicMuseum_1F_Text_LearnAboutSeaForBattling:
	.string "Je veux en apprendre plus sur la mer\n"
	.string "et utiliser ce savoir pour combattre.$"

SlateportCity_OceanicMuseum_1F_Text_SternIsRoleModel:
	.string "Je deviens tout excité quand je vois\n"
	.string "la mer !\p"
	.string "Pour moi, le CAPT. PORTO est le\n"
	.string "meilleur modèle !$"

SlateportCity_OceanicMuseum_1F_Text_MustBePokemonWeDontKnow:
	.string "La mer est vaste et infinie, et\n"
	.string "d'une profondeur sans fin…\p"
	.string "Il doit y avoir beaucoup de POKéMON\n"
	.string "que nous ne connaissons pas.$"

SlateportCity_OceanicMuseum_1F_Text_WantSeaPokemon:
	.string "Je veux un POKéMON marin.\p"
	.string "Je pense que ce serait agréable et\n"
	.string "rafraîchissant à câliner.$"

SlateportCity_OceanicMuseum_1F_Text_RememberMeTakeThis:
	.string "Aïe aïe aïe !\n"
	.string "Que fais-tu ici ?\p"
	.string "Moi ? Je suis le membre de la TEAM AQUA\n"
	.string "que tu as battu, tu te souviens ?\l"
	.string "Dans le TUNNEL MERAZON ?\p"
	.string "Tiens, prends ça !\n"
	.string "Tu dois me pardonner !$"

SlateportCity_OceanicMuseum_1F_Text_HopeINeverSeeYouAgain:
	.string "Cette CT, elle te va mieux qu'à moi.\n"
	.string "J'espère ne jamais te revoir !\n"
	.string "Wahahaha !$"

SlateportCity_OceanicMuseum_1F_Text_YouHaveToTakeThis:
	.string "Allez, s'il te plaît !\n"
	.string "Tu dois prendre ça et me laisser partir !$"

SlateportCity_OceanicMuseum_1F_Text_WhirlpoolExperiment:
	.string "Un liquide bleu tourbillonne dans\n"
	.string "un récipient en verre.\p"
	.string "« Ceci est une expérience pour créer\n"
	.string "un TOURBISABLE artificiellement avec du vent. »$"

SlateportCity_OceanicMuseum_1F_Text_WaterfallExperiment:
	.string "Une boule rouge monte et descend\n"
	.string "dans un récipient en verre.\p"
	.string "« Ceci est une expérience simulant une\n"
	.string "CASCADE grâce à la flottabilité de la boule. »$"

SlateportCity_OceanicMuseum_1F_Text_OceanSoilDisplay:
	.string "C'est un échantillon de sol du fond\n"
	.string "de l'océan.\p"
	.string "« Au fil des années, les restes des\n"
	.string "êtres vivants s'accumulent au fond\l"
	.string "de la mer, formant des couches sédimentaires.\p"
	.string "« En analysant ces couches, on peut\n"
	.string "découvrir le passé ancien. »$"

SlateportCity_OceanicMuseum_1F_Text_BeachSandDisplay:
	.string "C'est un échantillon de sable de plage.\p"
	.string "« Les pierres des montagnes sont\n"
	.string "emportées par les rivières où elles\l"
	.string "sont érodées et broyées.\p"
	.string "« Elles deviennent des grains et\n"
	.string "finissent en sable sur les plages. »$"

SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact1:
	.string "« MINI-INFO OCÉANIQUE 1\n"
	.string "Pourquoi l'eau de mer est-elle bleue ?\p"
	.string "« La lumière est composée de plusieurs couleurs.\p"
	.string "« Quand la lumière traverse l'eau,\n"
	.string "la plupart des couleurs disparaissent.\p"
	.string "« Cependant, la lumière bleue garde sa\n"
	.string "couleur, ce qui rend la mer bleue. »$"

SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact2:
	.string "« MINI-INFO OCÉANIQUE 2\n"
	.string "Pourquoi la mer est-elle salée ?\p"
	.string "« L'eau de mer contient du sel dissous\n"
	.string "sous forme d'ions sodium et chlore.\p"
	.string "« Ces ions proviennent des roches et\n"
	.string "sont emportés vers la mer par la pluie.\p"
	.string "« La concentration de sel dissous rend\n"
	.string "la mer salée. »$"

SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact3:
	.string "« MINI-INFO OCÉANIQUE 3\n"
	.string "Qu'est-ce qui est plus grand ? La mer ou la terre ?\p"
	.string "« La mer couvre environ 70 % de la planète,\n"
	.string "le reste étant la terre.\p"
	.string "« La mer est donc plus de deux fois\n"
	.string "plus grande que la terre. »$"

SlateportCity_OceanicMuseum_1F_Text_FossilDisplay:
	.string "C'est un fossile avec des crêtes ondulées.\p"
	.string "« Le sol du fond de l'océan est érodé\n"
	.string "par les marées.\p"
	.string "« L'eau de mer en mouvement marque le sol\n"
	.string "de petites crêtes et vallées.\p"
	.string "« Si ce sol se fossilise, on l'appelle\n"
	.string "une marque de rides. »$"

SlateportCity_OceanicMuseum_1F_Text_DepthMeasuringMachine:
	.string "Une étrange machine tourne sous\n"
	.string "un dôme de verre.\p"
	.string "Peut-être sert-elle à mesurer la\n"
	.string "profondeur de quelque chose…$"
