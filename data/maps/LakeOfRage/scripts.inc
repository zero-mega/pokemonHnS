.set LOCALID_LAKEOFRAGE_GYARADOS, 8
.set LOCALID_LAKEOFRAGE_LANCE, 3
.set LOCALID_LAKEOFRAGE_DRAGONITE, 16
.set LOCALID_LAKEOFRAGE_OLDMAN, 4
.set LOCALID_LAKE_PRYCE, 17

LakeOfRage_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LakeOfRage_OnTransition
	.byte 0

LakeOfRage_OnTransition::
	setflag FLAG_VISITED_LAKE_OF_RAGE
	call_if_lt VAR_MAHOGANY_TOWN_STATE, 2, LakeOfRage_EventScript_HideLois
	goto_if_lt VAR_MAHOGANY_TOWN_STATE, 14, LakeOfRage_EventScript_SetHighTide
	special UpdateShoalTideFlag
	goto_if_set FLAG_SYS_LAKE_OF_RAGE_TIDE, LakeOfRage_EventScript_SetHighTide
	goto LakeOfRage_EventScript_SetLowTide

LakeOfRage_EventScript_SetLowTide::
	setweather WEATHER_NONE
	setmaplayoutindex LAYOUT_LAKE_OF_RAGE_LOW_TIDE
	end

LakeOfRage_EventScript_SetHighTide::
	setmaplayoutindex LAYOUT_LAKE_OF_RAGE
	goto_if_lt VAR_MAHOGANY_TOWN_STATE, 14, LakeOfRage_EventScript_ThunderStorm
	random 2
	goto_if_eq VAR_RESULT, 1, LakeOfRage_EventScript_ThunderStorm
	end

LakeOfRage_EventScript_HideLois::
	setflag FLAG_TEMP_1
	return

LakeOfRage_EventScript_ThunderStorm::
	setweather WEATHER_RAIN_THUNDERSTORM
	end

LakeOfRage_EventScript_Pryce::
    lock
    faceplayer
    msgbox LakeOfRage_Text_Pryce, MSGBOX_DEFAULT
    closemessage
    fadescreenswapbuffers FADE_TO_BLACK
    setflag FLAG_HIDE_LAKE_PRYCE
    removeobject LOCALID_LAKE_PRYCE
    fadescreenswapbuffers FADE_FROM_BLACK
    clearflag FLAG_HIDE_DOJO_PRYCE
    release
    end

LakeOfRage_Text_Pryce:
    .string "{PLAYER}.\p"
    .string "Même ici, le froid me garde alerte.\p"
    .string "Si tu veux te battre à nouveau, viens\n"
    .string "au DOJO DE COMBAT.$"

LakeOfRage_EventScript_Gramps::
	goto_if_ge VAR_MAHOGANY_TOWN_STATE, 14, LakeOfRage_EventScript_Gramps2
	msgbox LakeOfRage_Text_Gramps, MSGBOX_NPC
	end

LakeOfRage_EventScript_Gramps2::
	msgbox LakeOfRage_Text_GrampsCleared, MSGBOX_NPC
	end
LakeOfRage_EventScript_Lass::
	msgbox LakeOfRage_Text_CooltrainerF, MSGBOX_NPC
	end

LakeOfRage_EventScript_Nerd::
	msgbox LakeOfRage_Text_SuperNerd, MSGBOX_NPC
	end

LakeOfRage_EventScript_Andre::
	trainerbattle_single TRAINER_ANDRE LakeOfRage_Text_FisherAndreSeen, LakeOfRage_Text_FisherAndreBeaten
	msgbox LakeOfRage_Text_FisherAndreAfter, MSGBOX_AUTOCLOSE
	end

LakeOfRage_EventScript_Raymond::
	trainerbattle_single TRAINER_RAYMOND LakeOfRage_Text_FisherRaymondSeen, LakeOfRage_Text_FisherRaymondBeaten
	msgbox LakeOfRage_Text_FisherRaymondAfter, MSGBOX_AUTOCLOSE
	end

LakeOfRage_EventScript_Aaron::
	trainerbattle_single TRAINER_AARON LakeOfRage_Text_CooltrainermAaronSeen, LakeOfRage_Text_CooltrainermAaronBeaten
	msgbox LakeOfRage_Text_CooltrainermAaronAfter, MSGBOX_AUTOCLOSE
	end

LakeOfRage_EventScript_Lois::
	trainerbattle_single TRAINER_LOIS LakeOfRage_Text_CooltrainerfLoisSeen, LakeOfRage_Text_CooltrainerfLoisBeaten
	msgbox LakeOfRage_Text_CooltrainerfLoisAfter, MSGBOX_AUTOCLOSE
	end

LakeOfRage_EventScript_Gyarados::
	lock
	faceplayer
	msgbox LakeOfRage_Text_GyaradosCry, MSGBOX_DEFAULT
	waitse
	playmoncry SPECIES_GYARADOS, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattleshiny SPECIES_GYARADOS, 30
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, LakeOfRage_EventScript_Defeated_Gyarados
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, LakeOfRage_EventScript_Ran_Gyarados
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, LakeOfRage_EventScript_Ran_Gyarados
LakeOfRage_EventScript_Defeated_Gyarados::
	setflag FLAG_HIDE_LAKE_OF_RAGE_GYARADOS
	clearflag FLAG_TEMP_1
	removeobject LOCALID_LAKEOFRAGE_GYARADOS
	clearflag FLAG_HIDE_LAKE_OF_RAGE_LANCE
	addobject LOCALID_LAKEOFRAGE_LANCE
	giveitem ITEM_RED_SCALE
	setobjectxyperm LOCALID_LAKEOFRAGE_OLDMAN, 32, 38
	setvar VAR_MAHOGANY_TOWN_STATE, 2
	release
	end

LakeOfRage_EventScript_Ran_Gyarados::
	release
	end

LakeOfRage_EventScript_Item_Full_Restore::
	finditem ITEM_FULL_RESTORE
	end
LakeOfRage_EventScript_Item_Max_Revive::
	finditem ITEM_MAX_REVIVE
	end
LakeOfRage_EventScript_Item_Red_Flute::
	finditem ITEM_RED_FLUTE
	end

LakeOfRage_EventScript_Dragonite::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_DRAGONITE, CRY_MODE_NORMAL
	msgbox LakeOfRage_Text_Dragonite, MSGBOX_DEFAULT
	waitmoncry
	turnobject LOCALID_LAKEOFRAGE_DRAGONITE, DIR_WEST
	release
	end

LakeOfRage_EventScript_Lance::
	lock
	goto_if_eq VAR_MAHOGANY_TOWN_STATE, 3, LakeOfRage_EventScript_Lance_Return
	msgbox LakeOfRage_Text_LanceForcedToEvolve, MSGBOX_DEFAULT
	closemessage
	delay 20
	faceplayer
	turnobject LOCALID_LAKEOFRAGE_OLDMAN, DIR_WEST
	msgbox LakeOfRage_Text_LanceIntro2, MSGBOX_DEFAULT
	setvar VAR_MAHOGANY_TOWN_STATE, 3
	msgbox LakeOfRage_Text_LanceIntro3, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, LakeOfRage_EventScript_LancDeclined
LakeOfRage_EventScript_LanceAccept::
	lock
	msgbox LakeOfRage_Text_LanceRadioSignal, MSGBOX_DEFAULT
	closemessage
	goto_if_eq VAR_FACING, DIR_NORTH, LakeOfRage_EventScript_LanceDragoniteLeaveNorth
	applymovement LOCALID_LAKEOFRAGE_LANCE, LakeOfRage_Movement_LanceLeave
	applymovement LOCALID_LAKEOFRAGE_DRAGONITE, LakeOfRage_Movement_DragoniteLeave
	waitmovement LOCALID_LAKEOFRAGE_LANCE
	waitmovement LOCALID_LAKEOFRAGE_DRAGONITE
LakeOfRage_EventScript_EndScene::
	setflag FLAG_HIDE_LAKE_OF_RAGE_LANCE
	removeobject LOCALID_LAKEOFRAGE_LANCE
	removeobject LOCALID_LAKEOFRAGE_DRAGONITE
	setvar VAR_MAHOGANY_TOWN_STATE, 4
	clearflag FLAG_HIDE_MAHOGANY_TOWN_SHOP_NPCS
	release
	end

LakeOfRage_EventScript_Lance_Return::
	lock
	faceplayer
	msgbox LakeOfRage_Text_LanceAskHelp, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, LakeOfRage_EventScript_LanceAccept
	goto_if_eq VAR_RESULT, FALSE, LakeOfRage_EventScript_LancDeclined

LakeOfRage_EventScript_LancDeclined::
	msgbox LakeOfRage_Text_LanceRefused, MSGBOX_DEFAULT
	closemessage
	release
	end


LakeOfRage_EventScript_LanceDragoniteLeaveNorth::
	applymovement LOCALID_LAKEOFRAGE_LANCE, LakeOfRage_Movement_LanceLeaveNorth
	applymovement LOCALID_LAKEOFRAGE_DRAGONITE, LakeOfRage_Movement_DragoniteLeaveNorth
	waitmovement LOCALID_LAKEOFRAGE_LANCE
	waitmovement LOCALID_LAKEOFRAGE_DRAGONITE
	goto LakeOfRage_EventScript_EndScene

LakeOfRage_Movement_LanceLeaveNorth:
	walk_left
	walk_down
	delay_8
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

LakeOfRage_Movement_DragoniteLeaveNorth:
	delay_16
	delay_16
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

LakeOfRage_Movement_LanceLeave:
	walk_down
	delay_8
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

LakeOfRage_Movement_DragoniteLeave:
	delay_16
	delay_16
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

LakeOfRage_Text_Dragonite:
	.string "DRAGONITE: Gyafooha!$"

LakeOfRage_Text_LanceForcedToEvolve:
    .string "Ce lac est rempli de LÉVIATOR\n"
    .string "mais rien d'autre…\p"
    .string "Les MAGICARPE sont donc forcés\n"
    .string "d'évoluer…$"

LakeOfRage_Text_LanceIntro1:
    .string "Es-tu venu ici à cause des\n"
    .string "rumeurs ?\p"
    .string "Tu es {PLAYER} ? Je suis PETER,\n"
    .string "un dresseur comme toi.$"

LakeOfRage_Text_LanceIntro2:
    .string "Cet homme ici m'a parlé de\n"
    .string "certaines rumeurs.\p"
    .string "Nous sommes donc venus enquêter…$"

LakeOfRage_Text_LanceIntro3:
    .string "J'ai vu comment tu t'es battu\n"
    .string "tout à l'heure, {PLAYER}.\p"
    .string "Je peux dire que tu es un dresseur\n"
    .string "avec beaucoup de talent.\p"
    .string "Si cela ne te dérange pas, pourrais-\n"
    .string "tu nous aider à enquêter ?$"

LakeOfRage_Text_LanceRadioSignal:
    .string "PETER : Excellent !\p"
    .string "Il semble que les MAGICARPE du LAC\n"
    .string "soient forcés d'évoluer.\p"
    .string "Un mystérieux signal radio venant\n"
    .string "de MAHOGANIE en est la cause.\p"
    .string "Nous t'attendrons,\n"
    .string "{PLAYER}.$"

LakeOfRage_Text_LanceRefused:
    .string "Oh… Eh bien, si tu changes d'avis,\n"
    .string "aide-nous s'il te plaît.$"

LakeOfRage_Text_LanceAskHelp:
    .string "PETER : Hmm ? Tu vas nous aider\n"
    .string "?$"

LakeOfRage_Text_GyaradosCry:
    .string "LÉVIATOR : Gyashaa !$"

LakeOfRage_Text_Gramps:
    .string "Les LÉVIATOR sont en colère !\p"
    .string "C'est un mauvais présage !$"

LakeOfRage_Text_GrampsCleared:
    .string "Hahah ! Les MAGICARPE mordent !$"

LakeOfRage_Text_SuperNerd:
    .string "J'ai entendu dire que ce lac a été\n"
    .string "créé par des LÉVIATOR déchaînés.\p"
    .string "Je me demande s'il y a un lien\n"
    .string "avec leur apparition massive\n"
    .string "maintenant ?$"

LakeOfRage_Text_CooltrainerF:
    .string "Mes yeux m'ont-ils trompé ? J'ai vu\n"
    .string "un LÉVIATOR rouge dans le LAC…\p"
    .string "Mais je croyais que les LÉVIATOR\n"
    .string "étaient normalement bleus !$"


LakeOfRage_Text_FisherAndreSeen:
    .string "Laisse-moi combattre avec les\n"
    .string "POKéMON que je viens d'attraper !$"

LakeOfRage_Text_FisherAndreBeaten:
    .string "Je suis peut-être un expert pêcheur,\n"
    .string "mais je suis nul comme dresseur…$"

LakeOfRage_Text_FisherAndreAfter:
    .string "Je ne perdrai pas comme pêcheur !\n"
    .string "J'attrape des POKéMON toute la journée.$"


LakeOfRage_Text_FisherRaymondSeen:
    .string "Peu importe ce que je fais, je ne\n"
    .string "pêche que les mêmes POKéMON…$"

LakeOfRage_Text_FisherRaymondBeaten:
    .string "Ma ligne est toute emmêlée…$"

LakeOfRage_Text_FisherRaymondAfter:
    .string "Pourquoi je n'arrive pas à attraper\n"
    .string "de bons POKéMON ?$"

LakeOfRage_Text_CooltrainermAaronSeen:
    .string "Si un dresseur en croise un autre,\n"
    .string "il doit le défier.\p"
    .string "C'est notre destin.$"

LakeOfRage_Text_CooltrainermAaronBeaten:
    .string "Ouf… Beau combat.$"

LakeOfRage_Text_CooltrainermAaronAfter:
    .string "Les POKéMON et leur dresseur\n"
    .string "deviennent forts en combattant\n"
    .string "sans cesse.$"

LakeOfRage_Text_CooltrainerfLoisSeen:
    .string "Qu'est-il arrivé au LÉVIATOR\n"
    .string "rouge ?\p"
    .string "Il est parti ?\p"
    .string "Oh, zut. Je suis venue pour rien ?\p"
    .string "Je sais—combattons !$"

LakeOfRage_Text_CooltrainerfLoisBeaten:
    .string "Bien joué !$"

LakeOfRage_Text_CooltrainerfLoisAfter:
    .string "En y repensant, j'ai déjà vu un\n"
    .string "PAPILUSION rose.$"


LakeOfRage_EventScript_Wesley::
	lock
	faceplayer
	goto_if_set FLAG_GOT_BLACK_BELT, LakeOfRage_EventScript_WesleyCompleted
	msgbox LakeOfRage_Text_MeetWesley, MSGBOX_DEFAULT
	closemessage
	multichoice 20, 0, MULTI_DAYS_OF_WEEK, FALSE
	switch VAR_RESULT
	case 0, LakeOfRage_EventScript_WesleyNope
	case 1, LakeOfRage_EventScript_WesleyNope
	case 2, LakeOfRage_EventScript_WesleyNope
	case 3, LakeOfRage_EventScript_WesleyYes
	case 4, LakeOfRage_EventScript_WesleyNope
	case 5, LakeOfRage_EventScript_WesleyNope
	case 6, LakeOfRage_EventScript_WesleyNope
	case 7 LakeOfRage_EventScript_WesleyCancel
	case MULTI_B_PRESSED, LakeOfRage_EventScript_WesleyCancel
	closemessage
	release
	end
LakeOfRage_EventScript_WesleyYes::
	msgbox LakeOfRage_Text_WesleyGivesGift, MSGBOX_DEFAULT
	giveitem ITEM_BLACK_BELT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_BLACK_BELT
	msgbox LakeOfRage_Text_WesleyGaveGift, MSGBOX_DEFAULT
	closemessage
	release
	end
LakeOfRage_EventScript_WesleyNope::
	msgbox LakeOfRage_Text_WesleyNotWednesday, MSGBOX_DEFAULT
	closemessage
	release
	end
LakeOfRage_EventScript_WesleyCancel::
	closemessage
	release
	end
LakeOfRage_EventScript_WesleyCompleted::
	msgbox LakeOfRage_Text_WesleyWednesday, MSGBOX_DEFAULT
	closemessage
	release
	end

LakeOfRage_Text_MeetWesley:
    .string "WESLEY : Bonjour, comment ça va ?\p"
    .string "Je fais partie de la famille des JOURS\n"
    .string "DE LA SEMAINE ! Peux-tu deviner mon\n"
    .string "jour préféré ?$"

LakeOfRage_Text_WesleyGivesGift:
    .string "Ravi de faire ta connaissance. Prends\n"
    .string "ce souvenir, s'il te plaît.$"

LakeOfRage_Text_WesleyGaveGift:
    .string "WESLEY : La CEINTURE NOIRE augmente\n"
    .string "la puissance des attaques combat.$"

LakeOfRage_Text_WesleyWednesday:
    .string "WESLEY : Puisque tu m'as trouvé, tu as\n"
    .string "dû rencontrer mes frères et sœurs.\p"
    .string "Ou alors tu as eu de la chance ?$"

LakeOfRage_Text_WesleyNotWednesday:
    .string "WESLEY : Pas exactement...$"

LakeOfRage_EventScript_Sign1::
	msgbox LakeOfRage_Text_Sign, MSGBOX_SIGN
	end

LakeOfRage_EventScript_Sign2::
	msgbox LakeOfRage_Text_FishingGuruSign, MSGBOX_SIGN
	end

LakeOfRage_Text_Sign:
    .string "LAC COLÈRE,\n"
    .string "aussi appelé LAC LÉVIATOR.$"

LakeOfRage_Text_FishingGuruSign:
    .string "FISHING GURU'S HOUSE$"
