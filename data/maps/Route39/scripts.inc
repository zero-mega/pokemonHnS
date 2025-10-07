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
	.string "BAOBA : BON SANG ! Cette ombre,\n"
	.string "c'était un POKéMON ?\p"
	.string "Tu as bien pu la voir ?\n"
	.string "Je n'arrive pas à distinguer sa couleur...$"

Route39_Text_BaobaIntro::
	.string "Comme c'est étrange...\p"
	.string "...Ohh !\n"
	.string "Ce que tu tiens, c'est...\l"
	.string "ce qu'on appelle... un POKéDEX !\p"
	.string "Je n'en ai pas vu depuis des lustres.\p"
	.string "Je m'appelle BAOBA !\n"
	.string "Je dirigeais autrefois le PARC SAFARI\l"
	.string "à PARMANIE, mais il est devenu\l"
	.string "obsolète avec toutes les nouvelles\l"
	.string "distractions qui sortent.\p"
	.string "J'ai décidé de partir à l'étranger pour\n"
	.string "apprendre les dernières technologies et\l"
	.string "ouvrir un PARC SAFARI ultra-moderne\l"
	.string "à IRISIA.\p"
	.string "Peut-être que ce n'est pas un hasard\n"
	.string "si nous discutons.\p"
	.string "Et si on enregistrait nos numéros\n"
	.string "dans le POKéNAV ?\p"
	.string "Je pourrai t'appeler dès que le\n"
	.string "PARC SAFARI ouvrira, avant tout le monde !$"

Route39_Text_Registered:
	.string "{PLAYER} a enregistré BAOBA\n"
	.string "dans le POKéNAV !$"

Route39_Text_WillCall:
	.string "BAOBA : Je te préviendrai\n"
	.string "bientôt sur le POKéNAV !$"

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
	.string "Mes POKéMON ont été attrapés et\n"
	.string "élevés à l'étranger.\p"
	.string "Ce sont mes compagnons lors de\n"
	.string "ces longs voyages.$"

Route39_EventScript_Derek::
	trainerbattle_single TRAINER_DEREK, Route39_Text_PokefanMDerekSeen, Route39_Text_PokefanMDerekBeaten
	msgbox Route39_Text_PokefanMDerekAfter, MSGBOX_AUTOCLOSE
	end

Route39_Text_PokefanMDerekSeen:
	.string "C'est le bon moment pour me vanter\n"
	.string "de mon PIKACHU !$"

Route39_Text_PokefanMDerekBeaten:
	.string "Je n'ai même pas eu le temps de\n"
	.string "montrer PIKACHU…$"

Route39_Text_PokefanMDerekAfter:
	.string "Je n'écoute pas tes vantardises !\p"
	.string "Nous, les FANS de POKéMON, avons\n"
	.string "pour règle de ne pas écouter les\n"
	.string "vantardises !$"

Route39_EventScript_Ruth::
	trainerbattle_single TRAINER_RUTH, Route39_Text_PokefanFRuthSeen, Route39_Text_PokefanFRuthBeaten
	msgbox Route39_Text_PokefanFRuthAfter, MSGBOX_AUTOCLOSE
	end

Route39_Text_PokefanFRuthSeen:
	.string "Quels adorables POKéMON.\p"
	.string "Montrons nos POKéMON\n"
	.string "ensemble en même temps !$"

Route39_Text_PokefanFRuthBeaten:
	.string "Ça ne me dérange pas de perdre.$"

Route39_Text_PokefanFRuthAfter:
	.string "Tu connais les bébés\n"
	.string "POKéMON ?\p"
	.string "Je parie qu'ils sont adorables !$"

Route39_EventScript_Norman::
	trainerbattle_single TRAINER_NORMAN, Route39_Text_PsychicNormanSeen, Route39_Text_PsychicNormanBeaten
	msgbox Route39_Text_PsychicNormanAfter, MSGBOX_AUTOCLOSE
	end

Route39_Text_PsychicNormanSeen:
	.string "Laisse-moi voir de quoi\n"
	.string "tes POKéMON sont capables.$"

Route39_Text_PsychicNormanBeaten:
	.string "Oh, tes POKéMON ont\n"
	.string "du potentiel.$"

Route39_Text_PsychicNormanAfter:
	.string "Tu sais que les POKéMON ont\n"
	.string "des capacités différentes ?\p"
	.string "Les gens aussi sont comme ça.\n"
	.string "Chacun a un potentiel\l"
	.string "différent.$"

Route39_EventScript_Jamie::
	trainerbattle_single TRAINER_JAMIE, Route39_Text_PokefanFJaimeSeen, Route39_Text_PokefanFJaimeBeaten
	msgbox Route39_Text_PokefanFJaimeAfter, MSGBOX_AUTOCLOSE
	end

Route39_Text_PokefanFJaimeSeen:
	.string "Tu arrives au bon moment.\p"
	.string "Allons nous battre !$"

Route39_Text_PokefanFJaimeBeaten:
	.string "Oh, quelle déception…$"

Route39_Text_PokefanFJaimeAfter:
	.string "J'ai rencontré NOCTALI la nuit\n"
	.string "ici même sur la ROUTE 39.\p"
	.string "Je ne sais pas pourquoi, mais\n"
	.string "il semble aimer quand je\l"
	.string "m'entraîne ici.\p"
	.string "Il devient plus amical en\n"
	.string "s'entraînant ici qu'ailleurs.$"

Route39_EventScript_Sign1::
	lock
	msgbox Route39_Text_Sign, MSGBOX_SIGN
	closemessage
	release
	end

Route39_Text_Sign:
	.string "ROUTE 39\p"
	.string "OLIVILLE - ROSALIA$"

Route39_EventScript_Sign2::
	lock
	msgbox Route39_Text_MoomooFarmSign, MSGBOX_SIGN
	closemessage
	release
	end

Route39_Text_MoomooFarmSign:
	.string "FERME MEUMEUH\p"
	.string "Savourez notre lait frais et délicieux$"

Route39_EventScript_Sign3::
	lock
	msgbox Route39_Text_TrainerTips, MSGBOX_SIGN
	closemessage
	release
	end

Route39_Text_TrainerTips:
	.string "ASTUCES DRESSEUR\p"
	.string "Utilisez COUP D'Boule sur les arbres\n"
	.string "pour en faire tomber des POKéMON.\p"
	.string "Différents types de POKéMON\n"
	.string "peuvent tomber des arbres.\p"
	.string "Essayez COUP D'Boule sur tous\n"
	.string "les arbres que vous voyez !$"
