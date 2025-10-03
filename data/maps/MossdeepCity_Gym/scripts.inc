MossdeepCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_Gym_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, MossdeepCity_Gym_OnLoad
	.byte 0

@ NOTE: Mossdeep Gym was redesigned between R/S and E. Leftover (and now functionally unused) scripts are commented below

MossdeepCity_Gym_OnTransition:
	setflag FLAG_TEMP_HIDE_FOLLOWER @ Hide follower since it can collide with moving statues
	end

@ All the below checks are leftover from RS. FLAG_MOSSDEEP_GYM_SWITCH_X is never set
MossdeepCity_Gym_OnLoad:
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_1, MossdeepCity_Gym_EventScript_SetSwitch1Metatiles
	goto MossdeepCity_Gym_EventScript_CheckSwitch2
	end

MossdeepCity_Gym_EventScript_CheckSwitch2::
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_2, MossdeepCity_Gym_EventScript_SetSwitch2Metatiles
	goto MossdeepCity_Gym_EventScript_CheckSwitch3
	end

MossdeepCity_Gym_EventScript_CheckSwitch3::
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_3, MossdeepCity_Gym_EventScript_SetSwitch3Metatiles
	goto MossdeepCity_Gym_EventScript_CheckSwitch4
	end

MossdeepCity_Gym_EventScript_CheckSwitch4::
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_4, MossdeepCity_Gym_EventScript_SetSwitch4Metatiles
	end

@ All the below set metatile scripts are leftover from RS and are functionally unused
MossdeepCity_Gym_EventScript_SetSwitch1Metatiles::
	setmetatile 5, 5, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 2, 7, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_CheckSwitch2
	end

MossdeepCity_Gym_EventScript_SetSwitch2Metatiles::
	setmetatile 8, 14, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 8, 10, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_CheckSwitch3
	end

MossdeepCity_Gym_EventScript_SetSwitch3Metatiles::
	setmetatile 15, 17, METATILE_RSMossdeepGym_RedArrow_Left, FALSE
	setmetatile 17, 15, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_CheckSwitch4
	end

MossdeepCity_Gym_EventScript_SetSwitch4Metatiles::
	setmetatile 1, 23, METATILE_RSMossdeepGym_RedArrow_Up, FALSE
	setmetatile 5, 24, METATILE_RSMossdeepGym_Switch_Down, TRUE
	end

MossdeepCity_Gym_EventScript_TateAndLiza::
	trainerbattle_double TRAINER_TATE_AND_LIZA_1, MossdeepCity_Gym_Text_TateAndLizaIntro, MossdeepCity_Gym_Text_TateAndLizaDefeat, MossdeepCity_Gym_Text_TateAndLizaNeedTwoMons, MossdeepCity_Gym_EventScript_TateAndLizaDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MossdeepCity_Gym_EventScript_TateAndLizaRematch
	goto_if_unset FLAG_RECEIVED_TM_CALM_MIND, MossdeepCity_Gym_EventScript_GiveCalmMind2
	msgbox MossdeepCity_Gym_Text_TateAndLizaPostBattle, MSGBOX_DEFAULT
	release
	end

MossdeepCity_Gym_EventScript_TateAndLizaDefeated::
	message MossdeepCity_Gym_Text_ReceivedMindBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox MossdeepCity_Gym_Text_ExplainMindBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_MAHOGANY_TOWN_GYM
	setflag FLAG_BADGE07_GET
	setflag FLAG_GARBAGEFLAG
	clearflag FLAG_GARBAGEFLAG
	clearflag FLAG_GARBAGEFLAG
	setvar VAR_0x8008, 7
	call Common_EventScript_SetGymTrainers
	clearflag FLAG_GARBAGEFLAG
	clearflag FLAG_GARBAGEFLAG
	clearflag FLAG_GARBAGEFLAG
	clearflag FLAG_GARBAGEFLAG
	clearflag FLAG_GARBAGEFLAG
	setvar VAR_GARBAGEVAR, 1
	setflag FLAG_GARBAGEFLAG
	setvar VAR_GARBAGEVAR, 1
	call MossdeepCity_Gym_EventScript_GiveCalmMind
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox MossdeepCity_Gym_Text_RegisteredTateAndLiza, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_TATE_AND_LIZA_MATCH_CALL
	release
	end

MossdeepCity_Gym_EventScript_GiveCalmMind2::
	giveitem ITEM_TM_CALM_MIND
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox MossdeepCity_Gym_Text_ExplainCalmMind, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_CALM_MIND
	release
	end

MossdeepCity_Gym_EventScript_GiveCalmMind::
	giveitem ITEM_TM_CALM_MIND
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox MossdeepCity_Gym_Text_ExplainCalmMind, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_CALM_MIND
	return

MossdeepCity_Gym_EventScript_TateAndLizaRematch::
	trainerbattle_rematch_double TRAINER_TATE_AND_LIZA_1, MossdeepCity_Gym_Text_TateAndLizaPreRematch, MossdeepCity_Gym_Text_TateAndLizaRematchDefeat, MossdeepCity_Gym_Text_TateAndLizaRematchNeedTwoMons
	msgbox MossdeepCity_Gym_Text_TateAndLizaPostRematch, MSGBOX_AUTOCLOSE
	end

@ All the below switch scripts are leftover from RS and are functionally unused
MossdeepCity_Gym_EventScript_Switch1::
	lockall
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_1, MossdeepCity_Gym_EventScript_ClearSwitch1
	setflag FLAG_MOSSDEEP_GYM_SWITCH_1
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 5, 5, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 2, 7, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed::
	special DrawWholeMapView
	playse SE_CLICK
	releaseall
	end

MossdeepCity_Gym_EventScript_ClearSwitch1::
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_1
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 5, 5, METATILE_RSMossdeepGym_RedArrow_Left, FALSE
	setmetatile 2, 7, METATILE_RSMossdeepGym_Switch_Up, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_Switch2::
	lockall
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_2, MossdeepCity_Gym_EventScript_ClearSwitch2
	setflag FLAG_MOSSDEEP_GYM_SWITCH_2
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 8, 14, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 8, 10, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_ClearSwitch2::
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_2
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 8, 14, METATILE_RSMossdeepGym_RedArrow_Down, FALSE
	setmetatile 8, 10, METATILE_RSMossdeepGym_Switch_Up, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_Switch3::
	lockall
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_3, MossdeepCity_Gym_EventScript_ClearSwitch3
	setflag FLAG_MOSSDEEP_GYM_SWITCH_3
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 15, 17, METATILE_RSMossdeepGym_RedArrow_Left, FALSE
	setmetatile 17, 15, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_ClearSwitch3::
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_3
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 15, 17, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 17, 15, METATILE_RSMossdeepGym_Switch_Up, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_Switch4::
	lockall
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_4, MossdeepCity_Gym_EventScript_ClearSwitch4
	setflag FLAG_MOSSDEEP_GYM_SWITCH_4
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 1, 23, METATILE_RSMossdeepGym_RedArrow_Up, FALSE
	setmetatile 5, 24, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_ClearSwitch4::
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_4
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 1, 23, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 5, 24, METATILE_RSMossdeepGym_Switch_Up, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_WarpToEntrance::
	lockall
	warpmossdeepgym MAP_MOSSDEEP_CITY_GYM, 7, 30
	waitstate
	releaseall
	end

MossdeepCity_Gym_EventScript_Preston::
	trainerbattle_single TRAINER_PRESTON, MossdeepCity_Gym_Text_PrestonIntro, MossdeepCity_Gym_Text_PrestonDefeat
	msgbox MossdeepCity_Gym_Text_PrestonPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Virgil::
	trainerbattle_single TRAINER_VIRGIL, MossdeepCity_Gym_Text_VirgilIntro, MossdeepCity_Gym_Text_VirgilDefeat
	msgbox MossdeepCity_Gym_Text_VirgilPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Blake::
	trainerbattle_single TRAINER_BLAKE, MossdeepCity_Gym_Text_BlakeIntro, MossdeepCity_Gym_Text_BlakeDefeat
	msgbox MossdeepCity_Gym_Text_BlakePostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Hannah::
	trainerbattle_single TRAINER_PRYCE_2, MossdeepCity_Gym_Text_HannahIntro, MossdeepCity_Gym_Text_HannahDefeat
	msgbox MossdeepCity_Gym_Text_HannahPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Samantha::
	trainerbattle_single TRAINER_SAMANTHA, MossdeepCity_Gym_Text_SamanthaIntro, MossdeepCity_Gym_Text_SamanthaDefeat
	msgbox MossdeepCity_Gym_Text_SamanthaPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Maura::
	trainerbattle_single TRAINER_MAURA, MossdeepCity_Gym_Text_MauraIntro, MossdeepCity_Gym_Text_MauraDefeat
	msgbox MossdeepCity_Gym_Text_MauraPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Sylvia::
	trainerbattle_single TRAINER_SYLVIA, MossdeepCity_Gym_Text_SylviaIntro, MossdeepCity_Gym_Text_SylviaDefeat
	msgbox MossdeepCity_Gym_Text_SylviaPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Nate::
	trainerbattle_single TRAINER_NATE, MossdeepCity_Gym_Text_NateIntro, MossdeepCity_Gym_Text_NateDefeat
	msgbox MossdeepCity_Gym_Text_NatePostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Macey::
	trainerbattle_single TRAINER_MACEY, MossdeepCity_Gym_Text_MaceyIntro, MossdeepCity_Gym_Text_MaceyDefeat
	msgbox MossdeepCity_Gym_Text_MaceyPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Clifford::
	trainerbattle_single TRAINER_CLIFFORD, MossdeepCity_Gym_Text_CliffordIntro, MossdeepCity_Gym_Text_CliffordDefeat
	msgbox MossdeepCity_Gym_Text_CliffordPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Nicholas::
	trainerbattle_single TRAINER_NICHOLAS, MossdeepCity_Gym_Text_NicholasIntro, MossdeepCity_Gym_Text_NicholasDefeat
	msgbox MossdeepCity_Gym_Text_NicholasPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Kathleen::
	trainerbattle_single TRAINER_KATHLEEN, MossdeepCity_Gym_Text_KathleenIntro, MossdeepCity_Gym_Text_KathleenDefeat
	msgbox MossdeepCity_Gym_Text_KathleenPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_MAHOGANY_TOWN_GYM, MossdeepCity_Gym_EventScript_GymGuidePostVictory
	msgbox MossdeepCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

MossdeepCity_Gym_EventScript_GymGuidePostVictory::
	msgbox MossdeepCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

@ Leftover from RS, functionally unused
MossdeepCity_Gym_Movement_WaitAfterSwitchUse:
	delay_16
	delay_16
	step_end

MossdeepCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE07_GET, MossdeepCity_Gym_EventScript_GymStatueCertified
	goto MossdeepCity_Gym_EventScript_GymStatue
	end

MossdeepCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE07_GET, MossdeepCity_Gym_EventScript_GymStatueCertified
	goto MossdeepCity_Gym_EventScript_GymStatue
	end

MossdeepCity_Gym_EventScript_GymStatueCertified::
	msgbox MossdeepCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

MossdeepCity_Gym_EventScript_GymStatue::
	msgbox MossdeepCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

MossdeepCity_Gym_EventScript_YellowFloorSwitch::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 0
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_EventScript_BlueFloorSwitch::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 1
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_EventScript_GreenFloorSwitch::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 2
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_EventScript_PurpleFloorSwitch::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 3
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_EventScript_RedFloorSwitch::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 4
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_Text_GymGuideAdvice:
	.string "Yo, comment ça va, futur CHAMPION\n"
	.string "{PLAYER} ?\p"
	.string "Les CHAMPIONS d'ARÈNE ici utilisent\n"
	.string "des POKéMON de type PSY.\p"
	.string "Si tu les affrontes avec des POKéMON\n"
	.string "de type COMBAT ou POISON,\l"
	.string "ils te feront subir de terribles dégâts !\p"
	.string "En plus, ils t'attaqueront avec des\n"
	.string "combinaisons exceptionnelles.\p"
	.string "Si tu veux gagner, tu devras leur montrer\n"
	.string "à quel point tu es proche de tes\l"
	.string "POKéMON. Vas-y, fonce !$"

MossdeepCity_Gym_Text_GymGuidePostVictory:
	.string "Wow, tu es incroyable !\n"
	.string "Tu es un dresseur exceptionnel !$"

MossdeepCity_Gym_Text_PrestonIntro:
	.string "Les combats dépendent de la force de\n"
	.string "ton esprit ! Les faibles d'esprit ne gagnent jamais !$"

MossdeepCity_Gym_Text_PrestonDefeat:
	.string "J'ai perdu !\n"
	.string "Je dois renforcer mon esprit !$"

MossdeepCity_Gym_Text_PrestonPostBattle:
	.string "Les indécis perdent.\n"
	.string "C'est mon avertissement pour toi.$"

MossdeepCity_Gym_Text_VirgilIntro:
	.string "Montre-moi ton talent !$"

MossdeepCity_Gym_Text_VirgilDefeat:
	.string "Tu possèdes un talent spectaculaire !$"

MossdeepCity_Gym_Text_VirgilPostBattle:
	.string "S'il y a des prodiges dans le monde,\n"
	.string "alors nos CHAMPIONS d'ARÈNE en sont !\p"
	.string "Cependant, tu es peut-être encore plus\n"
	.string "talentueux qu'eux…$"

MossdeepCity_Gym_Text_BlakeIntro:
	.string "Fufufufu… Regarde-moi faire léviter une\n"
	.string "POKé BALL par télékinésie !\p"
	.string "Wrooooooooaaaar !\n"
	.string "… … … … … … …\p"
	.string "Parfois, je ne suis pas en phase…$"

MossdeepCity_Gym_Text_BlakeDefeat:
	.string "Mes talents de combat de POKéMON\n"
	.string "ne sont pas en phase non plus !$"

MossdeepCity_Gym_Text_BlakePostBattle:
	.string "Une POKé BALL était trop lourde à\n"
	.string "soulever par télékinésie. Mais ce mouton de poussière…\p"
	.string "Whoooooooooooooooh !\n"
	.string "… … … … … …\p"
	.string "Non, je ne triche pas !\n"
	.string "Je n'ai pas soufflé dessus ! Promis !$"

MossdeepCity_Gym_Text_HannahIntro:
	.string "Quand tu perdras contre moi, ne sois pas\n"
	.string "trop dur avec toi-même.\p"
	.string "Ce n'est pas que tu es faible--je suis\n"
	.string "juste trop forte !$"

MossdeepCity_Gym_Text_HannahDefeat:
	.string "Tu es juste trop fort !$"

MossdeepCity_Gym_Text_HannahPostBattle:
	.string "Je ne vais pas me décourager parce que\n"
	.string "j'ai perdu. Je dois juste m'entraîner plus.\p"
	.string "La pensée positive--c'est mon point fort !$"

MossdeepCity_Gym_Text_SamanthaIntro:
	.string "Je le vois…\n"
	.string "Je vois ton avenir…\p"
	.string "Si tu peux me battre, je te dirai\n"
	.string "ton avenir !$"

MossdeepCity_Gym_Text_SamanthaDefeat:
	.string "Je me rends !$"

MossdeepCity_Gym_Text_SamanthaPostBattle:
	.string "Tu livreras un combat terriblement intense\n"
	.string "contre nos CHAMPIONS d'ARÈNE…\p"
	.string "Le résultat…\n"
	.string "Tu ne l'entendras pas de moi !$"

MossdeepCity_Gym_Text_MauraIntro:
	.string "Les routes que tu as parcourues…\n"
	.string "Ce que tu as vécu…\p"
	.string "Affronte-moi avec tout ce que tu as\n"
	.string "appris !$"

MossdeepCity_Gym_Text_MauraDefeat:
	.string "Tu as parcouru un chemin de grandeur !$"

MossdeepCity_Gym_Text_MauraPostBattle:
	.string "Un avenir radieux attend ceux qui ont\n"
	.string "travaillé avec diligence.\p"
	.string "Pour ceux qui ont paressé, il n'y a\n"
	.string "que le désespoir à la fin.\p"
	.string "On récolte ce que l'on sème…$"

MossdeepCity_Gym_Text_SylviaIntro:
	.string "Même au risque de ma vie, je gagnerai\n"
	.string "ce combat !$"

MossdeepCity_Gym_Text_SylviaDefeat:
	.string "Ce que tu fais…\n"
	.string "Ça m'effraie…$"

MossdeepCity_Gym_Text_SylviaPostBattle:
	.string "Comment oses-tu me battre…\p"
	.string "Ce ne sera pas ma faute si quelque\n"
	.string "chose d'horrible t'arrive…$"

MossdeepCity_Gym_Text_NateIntro:
	.string "Hohoho.\p"
	.string "Tu as besoin que je te montre à quel point\n"
	.string "le type PSY peut être tenace.$"

MossdeepCity_Gym_Text_NateDefeat:
	.string "Oh ! Oh là là !\n"
	.string "Ton style de combat est fantastique !$"

MossdeepCity_Gym_Text_NatePostBattle:
	.string "Je… Je ne me laisse pas troubler par la défaite,\n"
	.string "peu importe à quel point c'est dur.$"

MossdeepCity_Gym_Text_KathleenIntro:
	.string "Laisse-moi te montrer un moment\n"
	.string "parfaitement affreux et terrifiant !$"

MossdeepCity_Gym_Text_KathleenDefeat:
	.string "N-non ! !$"

MossdeepCity_Gym_Text_KathleenPostBattle:
	.string "Ta vitalité est contagieuse !\n"
	.string "Éloigne-toi vite de moi !$"

MossdeepCity_Gym_Text_CliffordIntro:
	.string "J'ai peut-être passé mon apogée, mais je te\n"
	.string "conseille de ne pas me sous-estimer.$"

MossdeepCity_Gym_Text_CliffordDefeat:
	.string "Ah, tu débordes de la puissance\n"
	.string "de la jeunesse !$"

MossdeepCity_Gym_Text_CliffordPostBattle:
	.string "Il semble que je n'ai pas pu surmonter\n"
	.string "ton énergie juvénile.$"

MossdeepCity_Gym_Text_MaceyIntro:
	.string "Tu n'iras pas jusqu'au bout !\n"
	.string "Pas si je peux l'empêcher !$"

MossdeepCity_Gym_Text_MaceyDefeat:
	.string "Comment peux-tu être aussi\n"
	.string "ridiculement fort ?$"

MossdeepCity_Gym_Text_MaceyPostBattle:
	.string "Humph ! Tu es peut-être fort, mais tu n'es\n"
	.string "pas fait pour le type PSY !\p"
	.string "Ta façon de combattre est un peu brutale !$"

MossdeepCity_Gym_Text_NicholasIntro:
	.string "Wroooar ! Goûte à la puissance de combat\n"
	.string "de mes super POKéMON !$"

MossdeepCity_Gym_Text_NicholasDefeat:
	.string "Oh !\n"
	.string "Fini !$"

MossdeepCity_Gym_Text_NicholasPostBattle:
	.string "Très bien ! Je pense que je vais développer\n"
	.string "un pouvoir spécial de POKéMON invincible maintenant.$"

MossdeepCity_Gym_Text_TateAndLizaIntro:
	.string "TATE : Hé hé hé… Tu es surpris ?\p"
	.string "LIZA : Fufufu… Tu es surpris ?\p"
	.string "TATE : Qu'il y ait deux CHAMPIONS d'ARÈNE ?\n"
	.string "LIZA : Qu'il y ait deux CHAMPIONS d'ARÈNE ?\p"
	.string "TATE : Nous sommes jumeaux !\n"
	.string "LIZA : Nous sommes jumelles !\p"
	.string "TATE : Nous n'avons pas besoin de parler car…\n"
	.string "LIZA : Nous pouvons chacune deviner ce que…\p"
	.string "TATE : L'autre pense…\n"
	.string "LIZA : Tout dans nos esprits !\p"
	.string "TATE : Cette combinaison à nous…\n"
	.string "LIZA : Peux-tu la battre ?$"

MossdeepCity_Gym_Text_TateAndLizaDefeat:
	.string "TATE : Quoi ?! Notre combinaison…\n"
	.string "LIZA : A été brisée !\p"
	.string "TATE : On n'y peut rien. Tu as gagné…\n"
	.string "LIZA : Donc, en reconnaissance, prends ceci.$"

MossdeepCity_Gym_Text_ReceivedMindBadge:
	.string "{PLAYER} a reçu le BADGE ESPRIT\n"
	.string "de TATE et LIZA.$"

MossdeepCity_Gym_Text_ExplainMindBadgeTakeThis:
	.string "TATE : Le BADGE ESPRIT augmente\n"
	.string "l'ATQ. SPÉ et la DÉF. SPÉ des POKéMON.\p"
	.string "LIZA : Il te permet aussi d'utiliser la CS\n"
	.string "PLONGÉE en dehors des combats.\p"
	.string "TATE : Tu devrais aussi prendre ceci.$"

MossdeepCity_Gym_Text_ExplainCalmMind:
	.string "TATE : Cette CT04 contient…\n"
	.string "LIZA : CALM MIND !\p"
	.string "TATE : Elle augmente l'ATQ. SPÉ et…\n"
	.string "LIZA : Elle augmente la DÉF. SPÉ !\p"
	.string "TATE : C'est une capacité parfaite…\n"
	.string "LIZA : Pour les POKéMON de type PSY !\p"
	.string "… … … … … …$"

MossdeepCity_Gym_Text_RegisteredTateAndLiza:
	.string "CHAMPIONS d'ARÈNE TATE & LIZA\n"
	.string "enregistrés dans le POKéNAV.$"

MossdeepCity_Gym_Text_TateAndLizaPostBattle:
	.string "TATE : On dirait que le lien entre toi\n"
	.string "et tes POKéMON est bien plus fort que\l"
	.string "celui que nous partageons en tant que jumeaux.\p"
	.string "LIZA : Tu deviendras encore plus fort !\n"
	.string "Nous t'avons affronté, donc nous le savons.$"

MossdeepCity_Gym_Text_TateAndLizaNeedTwoMons:
	.string "TATE : Hé hé hé… Tu es surpris ?\p"
	.string "LIZA : Qu'il y ait deux CHAMPIONS d'ARÈNE ?\p"
	.string "TATE : Oups, tu n'as qu'un seul…\n"
	.string "LIZA : POKéMON en état de combattre.\p"
	.string "TATE : On ne peut pas combattre comme ça !\p"
	.string "LIZA : Si tu veux nous défier,\n"
	.string "ramène plus de POKéMON.$"

MossdeepCity_Gym_Text_GymStatue:
	.string "ARÈNE POKéMON DE MOSSDEEP$"

MossdeepCity_Gym_Text_GymStatueCertified:
	.string "ARÈNE POKéMON DE MOSSDEEP\p"
	.string "DRESSEURS CERTIFIÉS DE LIZA ET TATE :\n"
	.string "{PLAYER}$"

MossdeepCity_Gym_Text_TateAndLizaPreRematch:
	.string "TATE : POKéMON…\n"
	.string "LIZA : POKéMON…\p"
	.string "TATE : En changeant la composition de l'équipe…\n"
	.string "LIZA : Le style de combat change.\p"
	.string "TATE : Mais moi…\n"
	.string "LIZA : Mais moi…\p"
	.string "TATE : Je serai toujours avec LIZA !\n"
	.string "LIZA : Je serai toujours avec TATE !\p"
	.string "TATE : Notre combinaison…\n"
	.string "LIZA : Nous allons te la montrer encore et encore !$"

MossdeepCity_Gym_Text_TateAndLizaRematchDefeat:
	.string "TATE : Toi et tes POKéMON…\n"
	.string "LIZA : On dirait que vous êtes frères et sœurs !$"

MossdeepCity_Gym_Text_TateAndLizaPostRematch:
	.string "TATE : Tu peux nous faire tomber,\n"
	.string "mais nous ne resterons jamais à terre !\p"
	.string "LIZA : Parce que nous deux,\n"
	.string "on se soutient toujours !$"

MossdeepCity_Gym_Text_TateAndLizaRematchNeedTwoMons:
	.string "TATE : Tu es revenu…\n"
	.string "LIZA : Tu es revenu…\p"
	.string "TATE : Pour nous demander un revanche.\n"
	.string "LIZA : Pour nous demander un revanche.\p"
	.string "TATE : Mais…\n"
	.string "LIZA : Pour notre combat…\p"
	.string "TATE : Tu n'as amené qu'un seul POKéMON !\n"
	.string "LIZA : Tu n'as amené qu'un seul POKéMON !\p"
	.string "TATE : Il faut que tu en amènes au moins…\n"
	.string "LIZA : Deux POKéMON quand tu reviendras.$"
