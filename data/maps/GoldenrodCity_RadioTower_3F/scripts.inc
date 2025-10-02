GoldenrodCity_RadioTower_3F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, GoldenrodCity_RadioTower_3F_OnLoad
	.byte 0

GoldenrodCity_RadioTower_3F_OnLoad::
	call_if_set FLAG_HIDE_RADIOTOWER_GATE, GoldenrodCity_RadioTower_3F_HideGate
	end
	
GoldenrodCity_RadioTower_3F_HideGate::
	setmetatile 25, 8, 0x335, FALSE
	setmetatile 25, 9, 0x335, FALSE

	setmetatile 26, 8, 0X334, FALSE
	setmetatile 26, 9, 0X334, FALSE

	setmetatile 27, 8, 0X334, FALSE
	setmetatile 27, 9, 0X334, FALSE

	setmetatile 28, 8, 0X334, FALSE
	setmetatile 28, 9, 0X334, FALSE

	setmetatile 29, 8, 0X334, FALSE
	setmetatile 29, 9, 0X334, FALSE

	setmetatile 30, 8, 0X334, FALSE
	setmetatile 30, 9, 0X334, FALSE

	setmetatile 31, 8, 0X334, FALSE
	setmetatile 31, 9, 0X334, FALSE
	return


GoldenrodRaidoTower3_EventScript_Grunt6::
	trainerbattle_single TRAINER_GRUNT_6 GoldenrodCity_RadioTower_3F_Text_GruntM7Seen, GoldenrodCity_RadioTower_3F_Text_GruntM7Beaten
	msgbox GoldenrodCity_RadioTower_3F_Text_GruntM7After, MSGBOX_AUTOCLOSE
	end

GoldenrodRaidoTower3_EventScript_Grunt7::
	trainerbattle_single TRAINER_GRUNT_7 GoldenrodCity_RadioTower_3F_Text_GruntM8Seen, GoldenrodCity_RadioTower_3F_Text_GruntM8Beaten
	msgbox GoldenrodCity_RadioTower_3F_Text_GruntM8After, MSGBOX_AUTOCLOSE
	end

GoldenrodRaidoTower3_EventScript_Grunt8::
	trainerbattle_single TRAINER_GRUNT_8 GoldenrodCity_RadioTower_3F_Text_GruntM9Seen, GoldenrodCity_RadioTower_3F_Text_GruntM9Beaten
	msgbox GoldenrodCity_RadioTower_3F_Text_GruntM9After, MSGBOX_AUTOCLOSE
	end

GoldenrodRaidoTower3_EventScript_Scientist::
	trainerbattle_single TRAINER_MARC GoldenrodCity_RadioTower_3F_Text_ScientistMarcSeen, GoldenrodCity_RadioTower_3F_Text_ScientistMarcBeaten
	msgbox GoldenrodCity_RadioTower_3F_Text_ScientistMarcAfter, MSGBOX_AUTOCLOSE
	end


GoldenrodCity_RadioTower_3F_EventScript_Cooltrainer::
	lock
	faceplayer
	goto_if_set FLAG_GOT_SKILL_SWAP, GoldenrodCity_RadioTower_3F_EventScript_Cooltrainer3
	goto_if_ge VAR_GOLDENROD_CITY_STATE, 10, GoldenrodCity_RadioTower_3F_EventScript_Cooltrainer2

	msgbox GoldenrodCity_RadioTower_3F_Text_CooltrainerFPleaseSave, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_3F_EventScript_Cooltrainer2::
	lock
	faceplayer
	msgbox GoldenrodCity_RadioTower_3F_Text_CooltrainerFHeroGift, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_TM_SKILL_SWAP
	setflag FLAG_GOT_SKILL_SWAP
	msgbox GoldenrodCity_RadioTower_3F_Text_CooltrainerFSunnyDay, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_3F_EventScript_Cooltrainer3::
	msgbox GoldenrodCity_RadioTower_3F_Text_CooltrainerFMarvelous, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_3F_EventScript_Nerd::
	lock
	faceplayer
	msgbox GoldenrodCity_RadioTower_3F_Text_SuperNerd, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_3F_EventScript_Gate::
	lock
	msgbox GoldenrodCity_RadioTower_3F_Text_CardKeySlot, MSGBOX_SIGN
	goto_if_set FLAG_HIDE_RADIOTOWER_GATE, GoldenrodCity_RadioTower_3F_EventScript_GateOpened
	checkitem ITEM_CARD_KEY
	goto_if_eq VAR_RESULT, TRUE, GoldenrodCity_RadioTower_3F_EventScript_OpenGate
	closemessage
	release
	end


GoldenrodCity_RadioTower_3F_EventScript_GateOpened::
	msgbox GoldenrodCity_RadioTower_3F_Text_Open, MSGBOX_SIGN
	closemessage
	release
	end

GoldenrodCity_RadioTower_3F_EventScript_OpenGate::
	msgbox GoldenrodCity_RadioTower_3F_Text_InsertedCardKey, MSGBOX_SIGN
	call GoldenrodCity_RadioTower_3F_HideGate
	playse SE_CLICK
	special DrawWholeMapView
	msgbox GoldenrodCity_RadioTower_3F_Text_Open, MSGBOX_SIGN
	setflag FLAG_HIDE_RADIOTOWER_GATE
	closemessage
	release
	end

GoldenrodCity_RadioTower_3F_EventScript_Sign1::
	lock
	msgbox GoldenrodCity_RadioTower_3F_Text_PersonnelSign, MSGBOX_SIGN
	closemessage
	release
	end

GoldenrodCity_RadioTower_3F_EventScript_Sign2::
	lock
	msgbox GoldenrodCity_RadioTower_3F_Text_PokemonMusicSign, MSGBOX_SIGN
	closemessage
	release
	end

GoldenrodCity_RadioTower_3F_Text_CardKeySlot:
	.string "C'est l'emplacement de la CARTE MAGNÉTIQUE.$"

GoldenrodCity_RadioTower_3F_Text_InsertedCardKey:
	.string "{PLAYER} a inséré la CARTE MAGNÉTIQUE.$"
 
GoldenrodCity_RadioTower_3F_Text_Open:
	.string "La porte est ouverte.$"

GoldenrodCity_RadioTower_3F_Text_PersonnelSign:
	.string "3e ÉTAGE PERSONNEL$"

GoldenrodCity_RadioTower_3F_Text_PokemonMusicSign:
	.string "MUSIQUE POKéMON avec DJ BEN$"

GoldenrodCity_RadioTower_3F_Text_SuperNerd:
	.string "Nous avons des enregistrements des cris\n"
	.string "de tous les POKéMON découverts.\l"
	.string "On doit en avoir environ 400.\p"
	.string "Espèces différentes.$"

GoldenrodCity_RadioTower_3F_Text_GymGuideRockets:
	.string "Pour les dresseurs, les POKéMON sont\n"
	.string "leurs partenaires bien-aimés.\p"
	.string "C'est terrible que la TEAM ROCKET\n"
	.string "essaie de contrôler les POKéMON.$"

GoldenrodCity_RadioTower_3F_Text_GymGuide:
	.string "Nous diffusons des programmes\n"
	.string "divertissants 24h/24.\p"
	.string "Je vais faire de mon mieux pour tenir\n"
	.string "le rythme aussi !$"

GoldenrodCity_RadioTower_3F_Text_CooltrainerFPleaseSave:
	.string "Le boss de la TEAM ROCKET s'est enfermé.\p"
	.string "Mais le DIRECTEUR peut ouvrir la porte.\p"
	.string "Il est au cinquième étage.\p"
	.string "S'il vous plaît, sauvez-le !$"

GoldenrodCity_RadioTower_3F_Text_CooltrainerFDirectorSafe:
	.string "Le DIRECTEUR va-t-il bien ?$"

GoldenrodCity_RadioTower_3F_Text_CooltrainerFHeroGift:
	.string "Merci ! Tu es mon héros !\p"
	.string "Ceci est un petit cadeau pour toi.$"

GoldenrodCity_RadioTower_3F_Text_CooltrainerFSunnyDay:
	.string "C'est ÉCHANGE. Il échange la capacité\n"
	.string "d'un POKéMON avec celle d'un autre.$"

GoldenrodCity_RadioTower_3F_Text_CooltrainerFMarvelous:
	.string "Tu as été tout simplement merveilleux !$"

GoldenrodCity_RadioTower_3F_Text_GruntM7Seen:
	.string "J'ai reçu des ordres stricts.\p"
	.string "Je dois écraser quiconque défie\n"
	.string "la TEAM ROCKET !$"

GoldenrodCity_RadioTower_3F_Text_GruntM7Beaten:
	.string "Quoi ?!$"

GoldenrodCity_RadioTower_3F_Text_GruntM7After:
	.string "J'ai échoué dans ma mission…\p"
	.string "ARCHER va être furieux...$"

GoldenrodCity_RadioTower_3F_Text_GruntM8Seen:
	.string "C'est génial de donner des ordres aux\n"
	.string "POKéMON pour commettre des crimes.$"

GoldenrodCity_RadioTower_3F_Text_GruntM8Beaten:
	.string "Tu plaisantes !$"

GoldenrodCity_RadioTower_3F_Text_GruntM8After:
	.string "Je me sens nul d'avoir perdu !\p"
	.string "Zut ! Je déteste les POKéMON inutiles !$"

GoldenrodCity_RadioTower_3F_Text_GruntM9Seen:
	.string "Pourquoi la grille s'est-elle ouverte ?\n"
	.string "Tu y es pour quelque chose ?$"

GoldenrodCity_RadioTower_3F_Text_GruntM9Beaten:
	.string "C'est fini pour moi !$"

GoldenrodCity_RadioTower_3F_Text_GruntM9After:
	.string "Quoi ?! Tu as passé nos hommes dans\n"
	.string "le SOUTERRAIN ?\p"
	.string "Comment as-tu fait ?$"

GoldenrodCity_RadioTower_3F_Text_ScientistMarcSeen:
	.string "Un enfant inconnu qui traîne ici ?\p"
	.string "Qui es-tu ?$"

GoldenrodCity_RadioTower_3F_Text_ScientistMarcBeaten:
	.string "Tch ! Je t'ai sous-estimé !$"

GoldenrodCity_RadioTower_3F_Text_ScientistMarcAfter:
	.string "Bwahahaha…\p"
	.string "Je peux transmettre un signal aussi fort\n"
	.string "que nécessaire d'ici.$"
