MtMortar_1F_North_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtMortar_1F_North_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

MtMortar_1F_North_OnTransition: 
	callnative SetTimeBasedEncounters
	end

MtMortar_1F_North_EventScript_Item_MaxRepel::
    finditem ITEM_MAX_REPEL
    end

MtMortar_1F_North_EventScript_Item_EscapeRope::
    finditem ITEM_ESCAPE_ROPE
    end

MtMortar_1F_North_EventScript_Item_MaxPotion::
    finditem ITEM_MAX_POTION
    end

MtMortar_1F_North_EventScript_Item_Nugget::
    finditem ITEM_NUGGET
    end

MtMortar_1F_North_EventScript_Item_UltraBall::
    finditem ITEM_ULTRA_BALL
    end

MtMortar_1F_North_EventScript_Item_FullIncense::
    finditem ITEM_REVIVE
    end

MtMortar_1F_North_EventScript_Item_KingsRock::
    finditem ITEM_KINGS_ROCK
    end

MtMortar_1F_North_EventScript_Miller::
	trainerbattle_single TRAINER_MILLER MountMortar2_Text_PokemaniacMillerSeen, MountMortar2_Text_PokemaniacMillerBeaten
	msgbox MountMortar2_Text_PokemaniacMillerAfter, MSGBOX_AUTOCLOSE
	end

MtMortar_1F_North_EventScript_Markus::
	trainerbattle_single TRAINER_MARKUS MountMortar2_Text_SupernerdMarkusSeen, MountMortar2_Text_SupernerdMarkusBeaten
	msgbox MountMortar2_Text_SupernerdMarkusAfter, MSGBOX_AUTOCLOSE
	end

MountMortar2_Text_PokemaniacMillerSeen:
	.string "Je ne vais pas perdre cette fois !$"

MountMortar2_Text_PokemaniacMillerBeaten:
	.string "J'ai perdu contre un gamin... ?$"

MountMortar2_Text_PokemaniacMillerAfter:
	.string "Il y a quelque temps, un gars du karaté\n"
	.string "voulait se battre.\p"
	.string "Il était incroyablement fort.\n"
	.string "Il nous a complètement écrasés.\p"
	.string "Il est allé plus loin en disant que\n"
	.string "c'était pour son entraînement.\p"
	.string "Je me demande ce qu'il devient.$"

MountMortar2_Text_SupernerdMarkusSeen:
	.string "Hé ! HUGH !$"

MountMortar2_Text_SupernerdMarkusBeaten:
	.string "Je t'ai confondu avec quelqu'un\n"
	.string "d'autre…$"

MountMortar2_Text_SupernerdMarkusAfter:
	.string "Je suis venu explorer le MT.MORTAR,\n"
	.string "mais j'ai été séparé de mon\l"
	.string "partenaire…\p"
	.string "As-tu croisé un dresseur\n"
	.string "qui a un HYPOROI connaissant\l"
	.string "CASCADE ?$"
