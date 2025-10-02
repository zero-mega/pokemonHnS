.set LOCALID_DRAGONSDEN2_CLAIR, 5
.set LOCALID_DEN_CLAIR, 35

DragonsDen_Cavern_MapScripts::
	@map_script MAP_SCRIPT_ON_FRAME_TABLE, DragonsDen_Cavern_OnFrame
	.byte 0

DragonsDen_Cavern_OnFrame::
	map_script_2 VAR_BLACKTHORN_CITY_STATE, 3, DragonsDen_Cavern_EventScript_Clair
	.2byte 0

DragonsDen_EventScript_ClairRematch::
    lock
    faceplayer
    msgbox DragonsDen_Text_Clair, MSGBOX_DEFAULT
    closemessage
    fadescreenswapbuffers FADE_TO_BLACK
    setflag FLAG_HIDE_DEN_CLAIR
    removeobject LOCALID_DEN_CLAIR
    fadescreenswapbuffers FADE_FROM_BLACK
    clearflag FLAG_HIDE_DOJO_CLAIR
    release
    end

DragonsDen_Text_Clair:
    .string "{PLAYER}… So you're here.\p"
	.string "If you think you can keep up,\n"
	.string "with me, come to the FIGHTING\l"
	.string "DOJO in SAFFRON.$"

DragonsDen_Cavern_Trigger_ClairLeft::
	lock 
	playse SE_PIN
	applymovement2 LOCALID_DRAGONSDEN2_CLAIR, Common_Movement_ExclamationMark
	delay 60
	call DragonsDen_Cavern_EventScript_Clair
	applymovement2 LOCALID_DRAGONSDEN2_CLAIR, DragonsDen_Cavern_Movement_ClairLeaveLeft
	waitmovement 0
	setflag FLAG_HIDE_DRAGONS_DEN_CAVERN_CLAIR
	removeobject LOCALID_DRAGONSDEN2_CLAIR
	playse SE_EXIT
	setvar VAR_BLACKTHORN_CITY_STATE, 4
	setrespawn HEAL_LOCATION_BLACKTHORN_CITY
	release
	end

DragonsDen_Cavern_Trigger_ClairMid::
	lock 
	playse SE_PIN
	applymovement2 LOCALID_DRAGONSDEN2_CLAIR, Common_Movement_ExclamationMark
	delay 60
	applymovement2 LOCALID_DRAGONSDEN2_CLAIR, Common_Movement_WalkRight1
	call DragonsDen_Cavern_EventScript_Clair
	applymovement2 LOCALID_DRAGONSDEN2_CLAIR, DragonsDen_Cavern_Movement_ClairLeaveMid
	waitmovement 0
	setflag FLAG_HIDE_DRAGONS_DEN_CAVERN_CLAIR
	removeobject LOCALID_DRAGONSDEN2_CLAIR
	playse SE_EXIT
	setvar VAR_BLACKTHORN_CITY_STATE, 4
	release
	end

DragonsDen_Cavern_Trigger_ClairRight::
	lock 
	playse SE_PIN
	applymovement2 LOCALID_DRAGONSDEN2_CLAIR, Common_Movement_ExclamationMark
	delay 60
	applymovement2 LOCALID_DRAGONSDEN2_CLAIR, Common_Movement_WalkRight1
	waitmovement 0
	applymovement2 LOCALID_DRAGONSDEN2_CLAIR, Common_Movement_WalkRight1
	call DragonsDen_Cavern_EventScript_Clair
	applymovement2 LOCALID_DRAGONSDEN2_CLAIR, DragonsDen_Cavern_Movement_ClairLeaveRight
	waitmovement 0
	setflag FLAG_HIDE_DRAGONS_DEN_CAVERN_CLAIR
	removeobject LOCALID_DRAGONSDEN2_CLAIR
	playse SE_EXIT
	setvar VAR_BLACKTHORN_CITY_STATE, 4
	release
	end


DragonsDen_Cavern_EventScript_Clair::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	msgbox DragonsDen_Cavern_Text_ClairGiveDragonclaw, MSGBOX_DEFAULT
	giveitem ITEM_TM_DRAGON_CLAW
	msgbox DragonsDen_Cavern_Text_ClairDescribeDragonclaw, MSGBOX_DEFAULT
	closemessage
	delay 30
	msgbox DragonsDen_Cavern_Text_ClairWhatsTheMatter, MSGBOX_DEFAULT
	closemessage
	delay 10
	clearflag FLAG_GOT_DRATINI
	return

DragonsDen_Cavern_Movement_ClairLeaveLeft:
	walk_up
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

DragonsDen_Cavern_Movement_ClairLeaveMid:
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

DragonsDen_Cavern_Movement_ClairLeaveRight:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

DragonsDen_Cavern_Text_ClairGiveDragonclaw:
    .string "SANDRA : ATTENDS !\p"
    .string "Je suis désolée pour tout ça.\n"
    .string "Tiens, prends ceci en guise d'excuse.$"

DragonsDen_Cavern_Text_ClairDescribeDragonclaw:
    .string "Ceci contient DRACO-GRIFFE.\p"
    .string "Non, ça n'a rien à voir avec\n"
    .string "mes ongles.\p"
    .string "Si tu n'en veux pas, tu n'es pas\n"
    .string "obligé de le prendre.$"

DragonsDen_Cavern_Text_ClairWhatsTheMatter:
    .string "Qu'est-ce qu'il y a ? Tu ne vas\n"
    .string "pas à la LIGUE POKéMON ?\p"
    .string "Après être devenu CHAMPION, tu\n"
    .string "pourras affronter à nouveau\l"
    .string "n'importe quel CHAMPION d'ARÈNE.\p"
    .string "Va à la LIGUE POKéMON.\p"
    .string "Tu sais comment y aller ?\p"
    .string "D'ici, va à BOURG GEON.\p"
    .string "Puis SURFE vers l'est jusqu'à la LIGUE POKéMON.\p"
    .string "La route est très difficile.\p"
    .string "N'ose pas perdre à la LIGUE POKéMON !\p"
    .string "Si tu perds, je me sentirai encore\n"
    .string "plus mal d'avoir perdu contre toi !\p"
    .string "Donne tout ce que tu as !$"

DragonsDen_Cavern_EventScript_Darin::
	trainerbattle_single TRAINER_DARIN DragonsDen_Cavern_Text_CooltrainermDarinSeen, DragonsDen_Cavern_Text_CooltrainermDarinBeaten
	msgbox DragonsDen_Cavern_Text_CooltrainermDarinAfter, MSGBOX_AUTOCLOSE
	end

DragonsDen_Cavern_EventScript_Cara::
	trainerbattle_single TRAINER_CARA DragonsDen_Cavern_Text_CooltrainerfCaraSeen, DragonsDen_Cavern_Text_CooltrainerfCaraBeaten
	msgbox DragonsDen_Cavern_Text_CooltrainerfCaraAfter, MSGBOX_AUTOCLOSE
	end

DragonsDen_Cavern_EventScript_TwinLea::
	trainerbattle_double TRAINER_LEA_AND_PIA, DragonsDen_Cavern_Text_TwinsLeaandPia1Seen, DragonsDen_Cavern_Text_TwinsLeaandPia1Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox DragonsDen_Cavern_Text_TwinsLeaandPia1After, MSGBOX_DEFAULT
	release
	end
	
DragonsDen_Cavern_EventScript_TwinPia::
	trainerbattle_double TRAINER_LEA_AND_PIA, DragonsDen_Cavern_Text_TwinsLeaandPia2Seen, DragonsDen_Cavern_Text_TwinsLeaandPia2Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox DragonsDen_Cavern_Text_TwinsLeaandPia2After, MSGBOX_DEFAULT
	release
	end

DragonsDen_Cavern_EventScript_Item_Dragon_Fang::
	finditem ITEM_DRAGON_FANG
	end
DragonsDen_Cavern_EventScript_Item_Max_Potion::
	finditem ITEM_MAX_POTION
	end
DragonsDen_Cavern_EventScript_Item_PP_Max::
	finditem ITEM_PP_MAX
	end



DragonsDen_Cavern_Text_DragonShrineSign:
    .string "SANCTUAIRE DRAGON\p"
    .string "Un sanctuaire honorant les\n"
    .string "POKéMON dragons\p"
    .string "qui auraient vécu dans l'ANTRE\n"
    .string "DU DRAGON.$"

DragonsDen_Cavern_Text_SilverTraining1:
    .string "…\n"
    .string "Quoi ? {PLAYER} ?\p"
    .string "…Non, je ne me battrai pas contre toi maintenant…\p"
    .string "Mes POKéMON ne sont pas prêts à te\n"
    .string "battre.\p"
    .string "Je ne peux pas trop les pousser maintenant.\p"
    .string "Je dois être discipliné pour devenir\n"
    .string "le meilleur dresseur de POKéMON…$"

DragonsDen_Cavern_Text_SilverTraining2:
    .string "…\p"
    .string "Ouf…\p"
    .string "Apprends à rester hors de mon chemin…$"

DragonsDen_Cavern_Text_CooltrainermDarinSeen:
    .string "Toi ! Comment oses-tu entrer\n"
    .string "sans invitation !$"

DragonsDen_Cavern_Text_CooltrainermDarinBeaten:
    .string "T-tellement fort !$"

DragonsDen_Cavern_Text_CooltrainermDarinAfter:
    .string "Le SANCTUAIRE devant abrite le\n"
    .string "MAÎTRE de notre clan de dresseurs de dragons.\p"
    .string "Tu n'as pas le droit d'y entrer comme ça !$"

DragonsDen_Cavern_Text_CooltrainerfCaraSeen:
    .string "Tu ne devrais pas être ici !$"

DragonsDen_Cavern_Text_CooltrainerfCaraBeaten:
    .string "Oh mince, j'ai perdu !$"

DragonsDen_Cavern_Text_CooltrainerfCaraAfter:
    .string "Bientôt, j'aurai la permission de\n"
    .string "notre MAÎTRE pour utiliser des dragons.\p"
    .string "Quand ce sera fait, je deviendrai une\n"
    .string "dresseuse de dragons admirable et j'aurai\l"
    .string "l'approbation de notre MAÎTRE.$"

DragonsDen_Cavern_Text_TwinsLeaandPia1Seen:
    .string "C'est un inconnu qu'on ne connaît pas.$"

DragonsDen_Cavern_Text_TwinsLeaandPia1Beaten:
    .string "Aïe aïe aïe.$"

DragonsDen_Cavern_Text_TwinsLeaandPia1After:
    .string "C'était comme devoir combattre\n"
    .string "PETER.$"

DragonsDen_Cavern_Text_TwinsLeaandPia2Seen:
    .string "Qui es-tu ?$"

DragonsDen_Cavern_Text_TwinsLeaandPia2Beaten:
    .string "Pas gentil.$"

DragonsDen_Cavern_Text_TwinsLeaandPia2After:
    .string "On va le dire à quelqu'un.\p"
    .string "Le MAÎTRE sera fâché contre toi.$"
