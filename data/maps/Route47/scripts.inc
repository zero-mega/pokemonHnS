Route47_MapScripts::
	.byte 0


Route47_EventScript_Hiker::
	trainerbattle_single TRAINER_DEVIN, Route47_Text_HikerSeen, Route47_Text_HikerBeaten
	msgbox Route47_Text_HikerAfter, MSGBOX_AUTOCLOSE
	end

Route47_Text_HikerSeen::
	.string "Avoir le mal du pays, c'est...\n"
	.string "ce que c'est. \p"
	.string "Mais un combat reste un combat,\n"
	.string "alors allons-y !$"

Route47_Text_HikerBeaten::
	.string "Wahaha !$"

Route47_Text_HikerAfter::
	.string "Après un combat, il faut toujours\n"
	.string "partir sur un éclat de rire !$"

Route47_EventScript_Camper::
	trainerbattle_single TRAINER_GRANT, Route47_Text_CamperSeen, Route47_Text_CamperBeaten
	msgbox Route47_Text_CamperAfter, MSGBOX_AUTOCLOSE
	end

Route47_Text_CamperSeen::
	.string "Je ne suis pas à l'aise dans la foule,\n"
	.string "alors je campe ici avec mes\l"
	.string "POKéMON !$"

Route47_Text_CamperBeaten::
	.string "Je devrais peut-être aller plus loin\n"
	.string "dans la montagne, je suppose...$"

Route47_Text_CamperAfter::
	.string "À plus !$"

Route47_EventScript_Thom::
	trainerbattle_double TRAINER_THOM_AND_KAE, Route47_Text_Couple1Seen, Route47_Text_Couple1Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox Route47_Text_Couple1After1, MSGBOX_AUTOCLOSE
	end

Route47_EventScript_Kae::
	trainerbattle_double TRAINER_THOM_AND_KAE, Route47_Text_Couple1Seen, Route47_Text_Couple1Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox Route47_Text_Couple1After2, MSGBOX_AUTOCLOSE
	end

Route47_Text_Couple1Seen::
	.string "THOM : Un plus un égale deux. Mais\n"
	.string "ensemble, nous sommes bien plus\l"
	.string "forts !\p"
	.string "KAE : Nous ne sommes pas juste un\n"
	.string "couple ennuyeux !$"

Route47_Text_Couple1Beaten::
	.string "THOM : Ce n'était pas ce à quoi je\n"
	.string "m'attendais.\l"
	.string "KAE : Toi aussi, tu es surprenant !$"

Route47_Text_Couple1After1::
	.string "THOM : On dirait que ta force est\n"
	.string "impossible à prévoir !$"

Route47_Text_Couple1After2::
	.string "KAE : Je pensais que tu étais un\n"
	.string "dresseur ordinaire et solitaire.\l"
	.string "Je me suis bien trompée !$"

Route47_EventScript_Duff::
	trainerbattle_double TRAINER_DUFF_AND_EDA, Route47_Text_Couple2Seen, Route47_Text_Couple2Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox Route47_Text_Couple2After1, MSGBOX_AUTOCLOSE
	end

Route47_EventScript_Eda::
	trainerbattle_double TRAINER_DUFF_AND_EDA, Route47_Text_Couple2Seen, Route47_Text_Couple2Beaten, Route104_Text_GinaNotEnoughMons
	msgbox Route47_Text_Couple2After2, MSGBOX_AUTOCLOSE
	end

Route47_Text_Couple2Seen::
	.string "DUFF : Veiller sur ma petite amie\n"
	.string "fait battre mon cœur à tout rompre !\p"
	.string "EDA : Les sentiments de mon cœur pour\n"
	.string "mon petit ami sont aussi vastes et\l"
	.string "profonds que l'océan !$"

Route47_Text_Couple2Beaten::
	.string "DUFF : Je n'étais pas de taille...\l"
	.string "EDA : Tu es vraiment impressionnant...$"

Route47_Text_Couple2After1::
	.string "DUFF : Merci pour ce combat\n"
	.string "époustouflant ! À bientôt !$"

Route47_Text_Couple2After2::
	.string "EDA : Toi aussi, tu devrais trouver\n"
	.string "un partenaire merveilleux !$"

Route47_EventScript_Sage::
	lock
	faceplayer
	msgbox EmbeddedTower_Text_OldManIntro, MSGBOX_DEFAULT
	closemessage
	release
	end

EmbeddedTower_Text_OldManIntro:
	.string "Eh bien, bonjour !\p"
	.string "On raconte qu'au-delà de ce trou se\n"
	.string "dressait autrefois une immense tour\l"
	.string "s'élevant haut dans le ciel.\p"
	.string "On dit que c'était une tour assez\n"
	.string "étrange, dont la moitié était\l"
	.string "enfouie dans la falaise.\p"
	.string "Ce n'était pas seulement une tour\n"
	.string "s'élevant vers le ciel, mais aussi\l"
	.string "plongeant profondément sous terre !\p"
	.string "La rumeur dit qu'elle atteignait même\n"
	.string "le fond de l'océan !\p"
	.string "En bref, les ruines reliaient autrefois\n"
	.string "le ciel, la terre et la mer entre eux...\p"
	.string "La majeure partie de la tour est\n"
	.string "désormais en ruines, et il ne reste\l"
	.string "plus que l'entrée et l'intérieur, où\l"
	.string "tu verras d'étranges motifs.$"

Route47_EventScript_Item_Pearl::
    finditem ITEM_PEARL
    end

Route47_EventScript_Item_Revive::
    finditem ITEM_REVIVE
    end

Route47_EventScript_Item_WhiteFlute::
    finditem ITEM_WHITE_FLUTE
    end

Route47_EventScript_Item_Stardust::
	finditem ITEM_STARDUST
	end

Route47_EventScript_Item_LuckyPunch::
	finditem ITEM_LUCKY_PUNCH
	end

Route47_EventScript_Chinchou::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_CHINCHOU, CRY_MODE_NORMAL
	msgbox Route47_Text_Chinchou, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route47_Text_Chinchou:
	.string "CHINCHOU : Chou !$"