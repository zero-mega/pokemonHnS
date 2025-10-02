.set LOCALID_R39_SHADOW, 17
.set LOCALID_R39_BAOBA, 2

Route39_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route39_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route39_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route39_EventScript_Item_TM::
	finditem ITEM_TM_BRICK_BREAK
	end

Route39_EventScript_Item_Nugget::
	finditem ITEM_BIG_NUGGET
	end

Route39_EventScript_LegendaryTrigger::
	lock
	clearflag FLAG_HIDE_ROUTE39_SHADOW
	addobject LOCALID_R39_SHADOW
	playse SE_M_RAZOR_WIND
	applymovement LOCALID_R39_SHADOW, Route39_Movement_ShadowSlideDown
	waitmovement 0
	setflag FLAG_HIDE_ROUTE39_SHADOW
	removeobject LOCALID_R39_SHADOW
	playse SE_PIN
	applymovement LOCALID_R39_BAOBA, Common_Movement_QuestionMark
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_QuestionMark
	turnobject LOCALID_R39_BAOBA DIR_SOUTH
	turnobject OBJ_EVENT_ID_PLAYER DIR_SOUTH
	delay 60

	getplayerxy VAR_TEMP_0, VAR_TEMP_1

	call_if_eq VAR_TEMP_1, 20, Route39_EventScript_BaobaMovement1
	call_if_eq VAR_TEMP_1, 21, Route39_EventScript_BaobaMovement2
	call_if_eq VAR_TEMP_1, 22, Route39_EventScript_BaobaMovement3
	call_if_eq VAR_TEMP_1, 23, Route39_EventScript_BaobaMovement4

	turnobject LOCALID_R39_BAOBA DIR_EAST
	turnobject OBJ_EVENT_ID_PLAYER DIR_WEST
Route39_EventScript_ChooseLegend::
	msgbox Route39_Text_ChooseLegend, MSGBOX_DEFAULT
	multichoice 20, 8, MULTI_GOLDSILVER, FALSE
	switch VAR_RESULT
	case 0, Route39_EventScript_LegendaryTriggerGold
	case 1, Route39_EventScript_LegendaryTriggerSilver
	case MULTI_B_PRESSED, Route39_EventScript_ChooseLegend
	release
	end

Route39_EventScript_BaobaMovement1::
	applymovement LOCALID_R39_BAOBA, Route39_Movement_Baoba1
	waitmovement 0
	return
Route39_EventScript_BaobaMovement2::
	applymovement LOCALID_R39_BAOBA, Route39_Movement_Baoba2
	waitmovement 0
	return
Route39_EventScript_BaobaMovement3::
	applymovement LOCALID_R39_BAOBA, Route39_Movement_Baoba3
	waitmovement 0
	return
Route39_EventScript_BaobaMovement4::
	applymovement LOCALID_R39_BAOBA, Route39_Movement_Baoba4
	waitmovement 0
	return

Route39_Movement_Baoba1:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	step_end
Route39_Movement_Baoba2:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	step_end
Route39_Movement_Baoba3:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	step_end
Route39_Movement_Baoba4:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	step_end

Route39_EventScript_LegendaryTriggerGold::
	setvar VAR_LUGIA_OR_HOOH, 2
	goto Route39_EventScript_BaobaIntro

Route39_EventScript_LegendaryTriggerSilver::
	setvar VAR_LUGIA_OR_HOOH, 1
	goto Route39_EventScript_BaobaIntro

Route39_EventScript_BaobaIntro::
	msgbox Route39_Text_BaobaIntro, MSGBOX_DEFAULT
	playse MUS_HG_POKEGEAR_REGISTERED
	msgbox Route39_Text_Registered, MSGBOX_DEFAULT
	waitse
	msgbox Route39_Text_WillCall, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_R39_BAOBA, Route39_Movement_BaobaLeave
	waitmovement 0
	setflag FLAG_ENABLE_BAOBA_MATCH_CALL
	removeobject LOCALID_R39_BAOBA
	release
	end

Route39_Text_ChooseLegend::
	.string "BAOBA: BON DIEU ! Cette ombre\n"
	.string "appartenait-elle à un POKéMON ?\p"
	.string "As-tu bien pu la voir ?\n"
	.string "Je ne peux pas dire de quelle couleur elle était...$"

Route39_Text_BaobaIntro::
	.string "Comme c'est étrange...\p"
	.string "...Ohh !\n"
	.string "Ce que tu tiens est...\l"
	.string "ce qu'on appelle... un POKéDEX !\p"
	.string "Je n'en ai pas vu depuis des lustres.\p"
	.string "Mon nom est BAOBA !\n"
	.string "Je dirigeais une ZONE SAFARI à\l"
	.string "PARMANIE, mais elle devenait\l"
	.string "obsolète avec les nouvelles options\l"
	.string "de divertissement qui arrivent.\p"
	.string "J'ai décidé d'aller à l'étranger pour apprendre\n"
	.string "la technologie la plus récente et ouvrir une\l"
	.string "ZONE SAFARI de pointe\l"
	.string "à IRISIA.\p"
	.string "Ce n'est peut-être pas une coïncidence\n"
	.string "que nous bavardions.\p"
	.string "Pourquoi ne pas enregistrer nos\n"
	.string "numéros dans le POKéNAV ?\p"
	.string "Je peux t'appeler une fois que la\n"
	.string "ZONE SAFARI est ouverte avant d'appeler\l"
	.string "qui que ce soit d'autre !$"

Route39_Text_Registered:
	.string "{PLAYER} a enregistré BAOBA\n"
	.string "dans le POKéNAV !$"


Route39_Text_WillCall:
	.string "BAOBA: Je te ferai savoir\n"
	.string "sur le POKéNAV bientôt !$"

Route39_Movement_BaobaLeave:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Route39_Movement_ShadowSlideDown:
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	step_end

Route39_EventScript_Woman::
	lock
	faceplayer
	msgbox Route39_Text_Woman, MSGBOX_DEFAULT
	closemessage
	release
	end

Route39_Text_Woman:
	.string "Cette ombre... Peut-être que c'était un\n"
	.string "ROUCOUPS géant ?$"

Route39_EventScript_Miltank::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MILTANK, CRY_MODE_NORMAL
	msgbox Route39_Text_Miltank, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route39_Text_Miltank:
	.string "ÉCRÉMEUH: Mooo !$"

Route39_EventScript_Eugene::
	trainerbattle_single TRAINER_EUGENE, Route39_Text_SailorEugeneSeen, Route39_Text_SailorEugeneBeaten
	msgbox Route39_Text_SailorEugeneAfter, MSGBOX_AUTOCLOSE
	end

Route39_Text_SailorEugeneSeen:
	.string "Je viens de rentrer à OLIVILLE.\p"
	.string "Alors, que dirais-tu d'un combat POKéMON ?$"

Route39_Text_SailorEugeneBeaten:
	.string "Awaaargh !$"

Route39_Text_SailorEugeneAfter:
	.string "My POKéMON were caught and\n"
	.string "raised overseas.\p"
	.string "They're my companions on\n"
	.string "those long voyages.$"

Route39_EventScript_Derek::
	trainerbattle_single TRAINER_DEREK, Route39_Text_PokefanMDerekSeen, Route39_Text_PokefanMDerekBeaten
	msgbox Route39_Text_PokefanMDerekAfter, MSGBOX_AUTOCLOSE
	end

Route39_Text_PokefanMDerekSeen:
	.string "This is a good time to brag\n"
	.string "about my PIKACHU!$"

Route39_Text_PokefanMDerekBeaten:
	.string "I had no time to show off\n"
	.string "PIKACHU…$"

Route39_Text_PokefanMDerekAfter:
	.string "I'm not listening to your\n"
	.string "bragging!\p"
	.string "We POKé FANS have a policy\n"
	.string "of not listening to bragging!$"

Route39_EventScript_Ruth::
	trainerbattle_single TRAINER_RUTH, Route39_Text_PokefanFRuthSeen, Route39_Text_PokefanFRuthBeaten
	msgbox Route39_Text_PokefanFRuthAfter, MSGBOX_AUTOCLOSE
	end

Route39_Text_PokefanFRuthSeen:
	.string "Such darling POKéMON.\p"
	.string "Let's show our POKéMON\n"
	.string "together at the same time.$"

Route39_Text_PokefanFRuthBeaten:
	.string "I don't mind losing.$"

Route39_Text_PokefanFRuthAfter:
	.string "Do you know about baby\n"
	.string "POKéMON?\p"
	.string "I bet they're just adorable!$"

Route39_EventScript_Norman::
	trainerbattle_single TRAINER_NORMAN, Route39_Text_PsychicNormanSeen, Route39_Text_PsychicNormanBeaten
	msgbox Route39_Text_PsychicNormanAfter, MSGBOX_AUTOCLOSE
	end

Route39_Text_PsychicNormanSeen:
	.string "Let me see what your\n"
	.string "POKéMON are capable of.$"

Route39_Text_PsychicNormanBeaten:
	.string "Ooh, your POKéMON have\n"
	.string "potential.$"

Route39_Text_PsychicNormanAfter:
	.string "You know how POKéMON have\n"
	.string "different abilities?\p"
	.string "People are like that too.\n"
	.string "Everyone has different\l"
	.string "potential.$"

Route39_EventScript_Jamie::
	trainerbattle_single TRAINER_JAMIE, Route39_Text_PokefanFJaimeSeen, Route39_Text_PokefanFJaimeBeaten
	msgbox Route39_Text_PokefanFJaimeAfter, MSGBOX_AUTOCLOSE
	end

Route39_Text_PokefanFJaimeSeen:
	.string "You came at just the right\n"
	.string "time.\p"
	.string "Let's battle.$"

Route39_Text_PokefanFJaimeBeaten:
	.string "Oh, how disappointing…$"

Route39_Text_PokefanFJaimeAfter:
	.string "I met UMBREON at night right\n"
	.string "here on ROUTE 39.\p"
	.string "I'm not sure why, but it\n"
	.string "seems to like it when I\l"
	.string "train here.\p"
	.string "It seems to become friendlier\n"
	.string "by training here than\l"
	.string "anywhere else.$"

Route39_EventScript_Sign1::
	lock
	msgbox Route39_Text_Sign, MSGBOX_SIGN
	closemessage
	release
	end

Route39_Text_Sign:
	.string "ROUTE 39\p"
	.string "OLIVINE CITY - ECRUTEAK CITY$"

Route39_EventScript_Sign2::
	lock
	msgbox Route39_Text_MoomooFarmSign, MSGBOX_SIGN
	closemessage
	release
	end

Route39_Text_MoomooFarmSign:
	.string "MOOMOO FARM\p"
	.string "Enjoy Our Fresh and Tasty Milk$"

Route39_EventScript_Sign3::
	lock
	msgbox Route39_Text_TrainerTips, MSGBOX_SIGN
	closemessage
	release
	end

Route39_Text_TrainerTips:
	.string "TRAINER TIPS\p"
	.string "Use HEADBUTT on trees to shake\n"
	.string "POKéMON out.\p"
	.string "Different kinds of POKéMON\n"
	.string "drop out of trees.\p"
	.string "Use HEADBUTT on any tree\n"
	.string "you see!$"
