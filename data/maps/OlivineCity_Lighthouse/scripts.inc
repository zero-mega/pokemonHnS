.set LOCALID_LIGHTHOUSE_JASMINE, 12
.set LOCALID_LIGHTHOUSE_AMPHAROS, 13

OlivineCity_Lighthouse_MapScripts::
	.byte 0

OlivineLighthouse_EventScript_Item_Ether::
    finditem ITEM_ETHER
    end

OlivineLighthouse_EventScript_Item_RareCandy::
    finditem ITEM_RARE_CANDY
    end

OlivineLighthouse_EventScript_Item_TMBulkUp::
    finditem ITEM_TM_BULK_UP
    end

OlivineLighthouse_EventScript_Item_HyperPotion::
    finditem ITEM_HYPER_POTION
    end

OlivineLighthouse_EventScript_Item_Protein::
    finditem ITEM_PROTEIN
    end

OlivineLighthouse_EventScript_1FSailor::
	lock
	faceplayer
	msgbox OlivineLighthouse_Text_1FSailor, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineLighthouse_EventScript_1FPokefanF::
	lock
	faceplayer
	msgbox OlivineLighthouse_Text_1FPokefanF, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineLighthouse_Text_1FSailor:
	.string "Des gens s'entraînent dans ce PHARE.\p"
	.string "Ce n'est pas facile de monter avec\n"
	.string "tous les dresseurs qui attendent dedans.$"

OlivineLighthouse_Text_1FPokefanF:
	.string "Autrefois, des POKéMON illuminaient\n"
	.string "la mer autour d'OLIVINE la nuit.\p"
	.string "Le PHARE a été construit en l'honneur\n"
	.string "de ces nobles POKéMON.$"

@2nd floor==============================================================================================================================

OlivineLighthouse_EventScript_Huey::
	trainerbattle_single TRAINER_HUEY, OlivineLighthouse_Text_SailorHueySeen, OlivineLighthouse_Text_SailorHueyBeaten
	msgbox OlivineLighthouse_Text_SailorHueyAfter, MSGBOX_AUTOCLOSE
	end

OlivineLighthouse_EventScript_GentlemanAlfred::
    trainerbattle_single TRAINER_ALFRED, OlivineLighthouse_Text_GentlemanAlfredSeen, OlivineLighthouse_Text_GentlemanAlfredBeaten
    msgbox OlivineLighthouse_Text_GentlemanAlfredAfter, MSGBOX_AUTOCLOSE
    end

OlivineLighthouse_Text_SailorHueySeen:
	.string "Les hommes de la mer sont toujours\n"
	.string "prêts pour un bon combat !$"

OlivineLighthouse_Text_SailorHueyBeaten:
	.string "Ouf !\n"
	.string "J'ai perdu !$"

OlivineLighthouse_Text_SailorHueyAfter:
	.string "Quelle puissance ! Ça te dirait de\n"
	.string "naviguer sur les mers avec moi ?$"

OlivineLighthouse_Text_GentlemanAlfredSeen:
	.string "Hmm ? Ce n'est pas un endroit\n"
	.string "pour jouer.$"

OlivineLighthouse_Text_GentlemanAlfredBeaten:
	.string "Ah ! Je vois que tu es\n"
	.string "sérieux.$"

OlivineLighthouse_Text_GentlemanAlfredAfter:
	.string "Tout en haut, il y a un POKéMON qui\n"
	.string "garde le PHARE allumé.\p"
	.string "Mais j'ai entendu dire qu'il est\n"
	.string "malade et qu'on ne peut pas le soigner normalement.$"

@3rd floor==============================================================================================================================

OlivineLighthouse_EventScript_BirdKeeperTheo::
    trainerbattle_single TRAINER_THEO, OlivineLighthouse_Text_BirdKeeperTheoSeen, OlivineLighthouse_Text_BirdKeeperTheoBeaten
    msgbox OlivineLighthouse_Text_BirdKeeperTheoAfter, MSGBOX_AUTOCLOSE
    end

OlivineLighthouse_EventScript_SailorTerrell::
    trainerbattle_single TRAINER_TERRELL, OlivineLighthouse_Text_SailorTerrellSeen, OlivineLighthouse_Text_SailorTerrellBeaten
    msgbox OlivineLighthouse_Text_SailorTerrellAfter, MSGBOX_AUTOCLOSE
    end

OlivineLighthouse_EventScript_GentlemanPreston::
    trainerbattle_single TRAINER_PRESTON, OlivineLighthouse_Text_GentlemanPrestonSeen, OlivineLighthouse_Text_GentlemanPrestonBeaten
    msgbox OlivineLighthouse_Text_GentlemanPrestonAfter, MSGBOX_AUTOCLOSE
    end


OlivineLighthouse_Text_BirdKeeperTheoSeen:
	.string "Pourquoi es-tu ici ? Tu viens juste\n"
	.string "pour regarder ? Je te conseille de partir !$"

OlivineLighthouse_Text_BirdKeeperTheoBeaten:
	.string "Tu t'inquiètes vraiment pour le\n"
	.string "POKéMON malade…$"

OlivineLighthouse_Text_BirdKeeperTheoAfter:
	.string "Comment diable on monte là-haut ?\p"
	.string "Je veux rendre visite au POKéMON malade,\n"
	.string "mais je n'arrive pas à monter…$"

OlivineLighthouse_Text_SailorTerrellSeen:
	.string "Les marins sont à la fois gentils et forts.\n"
	.string "Et toi ?$"

OlivineLighthouse_Text_SailorTerrellBeaten:
	.string "Tu es à la fois gentil et fort…$"

OlivineLighthouse_Text_SailorTerrellAfter:
	.string "À chaque fois que je reviens à OLIVINE,\n"
	.string "je visite l'ARÈNE.\p"
	.string "Le type de POKéMON de la CHAMPIONNE\n"
	.string "a changé sans que je m'en rende compte.$"

OlivineLighthouse_Text_GentlemanPrestonSeen:
	.string "Je voyage dans le monde entier pour entraîner\n"
	.string "mes POKéMON. Je souhaite me battre avec toi.$"

OlivineLighthouse_Text_GentlemanPrestonBeaten:
	.string "…soupir… Je dois encore m'entraîner…$"

OlivineLighthouse_Text_GentlemanPrestonAfter:
	.string "JASMINE utilisait autrefois des POKéMON\n"
	.string "de type Roche comme ONIX.$"

@4th floor==============================================================================================================================

OlivineLighthouse_EventScript_SailorKent::
    trainerbattle_single TRAINER_KENT, OlivineLighthouse_Text_SailorKentSeen, OlivineLighthouse_Text_SailorKentBeaten
    msgbox OlivineLighthouse_Text_SailorKentAfter, MSGBOX_AUTOCLOSE
    end

OlivineLighthouse_EventScript_LassConnie::
    trainerbattle_single TRAINER_CONNIE, OlivineLighthouse_Text_LassConnieSeen, OlivineLighthouse_Text_LassConnieBeaten
    msgbox OlivineLighthouse_Text_LassConnieAfter, MSGBOX_AUTOCLOSE
    end


OlivineLighthouse_Text_SailorKentSeen:
	.string "JASMINE doit être morte d'inquiétude pour\n"
	.string "le POKéMON ici.\p"
	.string "Elle ne sourit même plus ces jours-ci.$"

OlivineLighthouse_Text_SailorKentBeaten:
	.string "Je n'arrive pas à sourire non plus…$"

OlivineLighthouse_Text_SailorKentAfter:
	.string "En parlant de maladie, j'ai entendu dire\n"
	.string "qu'il y a une bonne PHARMACIE à IRISIA.$"

OlivineLighthouse_Text_LassConnieSeen:
	.string "JASMINE est la CHAMPIONNE de cette ville.\p"
	.string "Je compte bien la ramener avec moi.\p"
	.string "Personne n'a intérêt à se mettre en travers de mon chemin !$"

OlivineLighthouse_Text_LassConnieBeaten:
	.string "Aaah ! Mes POKéMON !$"

OlivineLighthouse_Text_LassConnieAfter:
	.string "C'est vrai. Tout le monde serait inquiet si\n"
	.string "ses propres POKéMON étaient blessés.\p"
	.string "Je vais prier pour les POKéMON ici, pour que\n"
	.string "JASMINE puisse revenir à l'ARÈNE.$"

@5th floor==============================================================================================================================

OlivineLighthouse_EventScript_SailorErnest::
    trainerbattle_single TRAINER_ERNEST, OlivineLighthouse_Text_SailorErnestSeen, OlivineLighthouse_Text_SailorErnestBeaten
    msgbox OlivineLighthouse_Text_SailorErnestAfter, MSGBOX_AUTOCLOSE
    end

OlivineLighthouse_EventScript_BirdKeeperDenis::
    trainerbattle_single TRAINER_DENIS, OlivineLighthouse_Text_BirdKeeperDenisSeen, OlivineLighthouse_Text_BirdKeeperDenisBeaten
    msgbox OlivineLighthouse_Text_BirdKeeperDenisAfter, MSGBOX_AUTOCLOSE
    end

OlivineLighthouse_Text_SailorErnestSeen:
	.string "Je voulais affronter JASMINE, mais elle\n"
	.string "n'est pas en état pour le moment.\p"
	.string "Alors, que dirais-tu d'un combat ?$"

OlivineLighthouse_Text_SailorErnestBeaten:
	.string "Ouh là là. Tu es vraiment trop fort !$"

OlivineLighthouse_Text_SailorErnestAfter:
	.string "Un CHAMPION d'ARÈNE ne doit pas seulement\n"
	.string "être fort.\p"
	.string "Un LEADER doit aussi faire preuve de\n"
	.string "compassion.$"

OlivineLighthouse_Text_BirdKeeperDenisSeen:
	.string "On est vraiment haut ici. Mes POKéMON\n"
	.string "oiseau sont en pleine forme !$"

OlivineLighthouse_Text_BirdKeeperDenisBeaten:
	.string "Oups… Ils se sont écrasés…$"

OlivineLighthouse_Text_BirdKeeperDenisAfter:
	.string "Mes POKéMON ont appris VOL à IRISIA.\p"
	.string "Bon, puisque j'ai perdu, je vais VOLER\n"
	.string "au-dessus de la mer…$"

@6th floor==============================================================================================================================

OlivineLighthouse_EventScript_Jasmine::
	lock
	faceplayer
	goto_if_eq VAR_OLIVINE_CITY_STATE, 3, OlivineLighthouse_EventScript_JasmineGoGetPotion
	goto_if_eq VAR_OLIVINE_CITY_STATE, 4, OlivineLighthouse_EventScript_JasmineDeliverPotion
	msgbox OlivineLighthouse_Text_JasmineCianwoodPharmacy, MSGBOX_DEFAULT
	msgbox OlivineLighthouse_Text_JasmineGetMedicine, MSGBOX_DEFAULT
	closemessage
	setvar VAR_OLIVINE_CITY_STATE, 3
	release
	end
OlivineLighthouse_EventScript_JasmineGoGetPotion::
	msgbox OlivineLighthouse_Text_JasmineGetMedicine2, MSGBOX_DEFAULT
	release
	end


OlivineLighthouse_EventScript_Ampharos::
	lock
	faceplayer
	goto_if_lt VAR_OLIVINE_CITY_STATE, 5, OlivineLighthouse_EventScript_AmpharosSick
	fadescreen FADE_TO_WHITE
	playse SE_M_THUNDERBOLT2
	waitse
	fadescreen FADE_FROM_WHITE
	playmoncry SPECIES_AMPHAROS, CRY_MODE_NORMAL
	msgbox OlivineLighthouse_Text_AmphyPaluPalulu, MSGBOX_DEFAULT
	waitmoncry
	setflag FLAG_AMPHAROS_HEALED
	release
	end

OlivineLighthouse_EventScript_AmpharosSick::
	playmoncry SPECIES_AMPHAROS, CRY_MODE_NORMAL
	msgbox OlivineLighthouse_Text_AmphyPalPaloo, MSGBOX_DEFAULT
	waitmoncry
	msgbox OlivineLighthouse_Text_AmphyBreathingLabored, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineLighthouse_Text_JasmineCianwoodPharmacy:
	.string "JASMINE : …Ce POKéMON a toujours\n"
	.string "éclairé la mer la nuit.\p"
	.string "…Mais il est soudainement tombé\n"
	.string "malade… Il a du mal à respirer…\p"
	.string "…Je sais qu'il y a une excellente\n"
	.string "PHARMACIE à IRISIA…\p"
	.string "Mais c'est de l'autre côté de la mer…\n"
	.string "Et je ne peux pas laisser AMPHY seul…$"

OlivineLighthouse_Text_JasmineGetMedicine:
	.string "…Pourrais-tu aller chercher des\n"
	.string "médicaments pour moi ? S'il te plaît.$"

OlivineLighthouse_Text_JasmineGetMedicine2:
	.string "Il y a une excellente PHARMACIE\n"
	.string "à IRISIA…\p"
	.string "Mais c'est de l'autre côté de la mer…\n"
	.string "Et je ne peux pas laisser AMPHY seul…\p"
	.string "…Pourrais-tu aller chercher des\n"
	.string "médicaments pour moi ? S'il te plaît.$"

OlivineLighthouse_Text_JasmineCureAmphy:
	.string "JASMINE : …Ce médicament va-t-il\n"
	.string "guérir AMPHY ?$"


OlivineLighthouse_EventScript_JasmineDeliverPotion::
	msgbox OlivineLighthouse_Text_JasmineCureAmphy, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, OlivineLighthouse_EventScript_JasmineRefuse
	playse SE_USE_ITEM
	removeitem ITEM_SECRET_POTION
	msgbox OlivineLighthouse_Text_PlayerHandedSecretpotion, MSGBOX_DEFAULT
	waitse
	msgbox OlivineLighthouse_Text_JasmineDontBeOffended, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_LIGHTHOUSE_JASMINE, DIR_NORTH
	delay 20
	turnobject LOCALID_LIGHTHOUSE_AMPHAROS, DIR_SOUTH
	playse MUS_HEAL
	waitse
	msgbox OlivineLighthouse_Text_JasmineAmphyHowFeeling, MSGBOX_DEFAULT
	fadescreen FADE_TO_WHITE
	playse SE_M_THUNDERBOLT2
	waitse
	fadescreen FADE_FROM_WHITE
	playmoncry SPECIES_AMPHAROS, CRY_MODE_NORMAL
	msgbox OlivineLighthouse_Text_AmphyPaluPalulu, MSGBOX_DEFAULT
	waitmoncry
	closemessage
	applymovement LOCALID_LIGHTHOUSE_AMPHAROS, OlivineLighthouse_Movement_Amphy
	waitmovement 0
	applymovement LOCALID_LIGHTHOUSE_JASMINE, OlivineLighthouse_Movement_Jasmine
	msgbox OlivineLighthouse_Text_JasmineThankYou, MSGBOX_DEFAULT
	closemessage

	fadescreen FADE_TO_BLACK
	playse SE_EXIT
	setflag FLAG_HIDE_LIGHTHOUSE_JASMINE
	removeobject LOCALID_LIGHTHOUSE_JASMINE
	waitse
	delay 50
	fadescreen FADE_FROM_BLACK
	setvar VAR_SAFARI_ZONE_GATE_STATE, 1
	setvar VAR_OLIVINE_CITY_STATE, 5
	setflag FLAG_AMPHAROS_HEALED
	clearflag FLAG_HIDE_OLIVINE_CITY_GYM_JASMINE
	release
	end

OlivineLighthouse_Movement_Jasmine:
	face_player
	step_end

OlivineLighthouse_Movement_Amphy:
	walk_up
	jump_in_place_down
	jump_in_place_left
	jump_in_place_right
	jump_in_place_up
	face_down
	step_end


OlivineLighthouse_EventScript_JasmineRefuse::
	msgbox OlivineLighthouse_Text_JasmineISee, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineLighthouse_Text_PlayerHandedSecretpotion:
	.string "{PLAYER} a donné la SECRETPOTION à\n"
	.string "JASMINE.$"

OlivineLighthouse_Text_JasmineDontBeOffended:
	.string "JASMINE : …Euh, s'il te plaît, ne sois\n"
	.string "pas offensé…\p"
	.string "…AMPHY n'acceptera rien de\n"
	.string "personne sauf de moi…$"

OlivineLighthouse_Text_JasmineAmphyHowFeeling:
	.string "JASMINE : …\p"
	.string "AMPHY, comment te sens-tu ?$"

OlivineLighthouse_Text_JasmineThankYou:
	.string "JASMINE : …Oh, je suis tellement soulagée…\p"
	.string "C'est vraiment merveilleux…\p"
	.string "Merci beaucoup, vraiment.\p"
	.string "…Je vais retourner à l'ARÈNE…\p"
	.string "Je te préviens aussi, les types acier\n"
	.string "sont puissants.$"

OlivineLighthouse_Text_JasmineISee:
	.string "JASMINE : …Je vois…\n"
	.string "…AMPHY, tiens bon !$"

OlivineLighthouse_Text_AmphyPalPaloo:
	.string "AMPHY : …\n"
	.string "…Pa… paloo…$"

OlivineLighthouse_Text_AmphyBreathingLabored:
	.string "Sa respiration est très\n"
	.string "difficile…$"

OlivineLighthouse_Text_AmphyPaluPalulu:
	.string "AMPHY : Palu ! Palulu !$"


