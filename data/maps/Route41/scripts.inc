Route41_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route41_MapScript_OnTransition
	.byte 0

Route41_MapScript_OnTransition::
	goto_if_eq VAR_COMPLETED_LUGIA, 4, Route41_MapScript_DoNothing
	goto_if_ge VAR_OLIVINE_CITY_STATE, 5, OlivineCity_MapScript_ClearWeather
	end

Route41_MapScript_DoNothing::
	end

Route41_EventScript_Charlie::
	trainerbattle_single TRAINER_CHARLIE, Route41_Text_SwimmermCharlieSeen, Route41_Text_SwimmermCharlieBeaten
	msgbox Route41_Text_SwimmermCharlieAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmermCharlieSeen:
	.string "L'eau est chaude ici.\n"
	.string "Je suis détendu et souple.\p"
	.string "Bien sûr, je t'affronte !$"

Route41_Text_SwimmermCharlieBeaten:
	.string "Aïe ! J'ai la peau toute fripée !$"

Route41_Text_SwimmermCharlieAfter:
	.string "N'est-ce pas relaxant de juste\n"
	.string "flotter comme ça ?$"

Route41_EventScript_George::
	trainerbattle_single TRAINER_GEORGE, Route41_Text_SwimmermGeorgeSeen, Route41_Text_SwimmermGeorgeBeaten
	msgbox Route41_Text_SwimmermGeorgeAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmermGeorgeSeen:
	.string "Je suis un peu fatigué.\n"
	.string "Si je gagne, prête-moi ton POKéMON.$"

Route41_Text_SwimmermGeorgeBeaten:
	.string "Haletant, haletant…$"

Route41_Text_SwimmermGeorgeAfter:
	.string "C'est si loin jusqu'à IRISIA.\p"
	.string "Mais le retour à OLIVILLE\n"
	.string "n'est pas facile non plus.\p"
	.string "Qu'est-ce que je devrais faire ?$"

Route41_EventScript_Berke::
	trainerbattle_single TRAINER_BERKE, Route41_Text_SwimmermBerkeSeen, Route41_Text_SwimmermBerkeBeaten
	msgbox Route41_Text_SwimmermBerkeAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmermBerkeSeen:
	.string "Tu vois ces îles qui sont\n"
	.string "bloquées par des tourbillons ?\p"
	.string "Il doit forcément y avoir un secret !$"

Route41_Text_SwimmermBerkeBeaten:
	.string "Quel est le secret de ta\n"
	.string "force ?$"

Route41_Text_SwimmermBerkeAfter:
	.string "C'était une nuit sombre et orageuse…\p"
	.string "J'ai vu ce POKéMON géant voler\n"
	.string "depuis les îles.\p"
	.string "Il dispersait des plumes\n"
	.string "de ses ailes argentées.$"

Route41_EventScript_Kirk::
	trainerbattle_single TRAINER_KIRK, Route41_Text_SwimmermKirkSeen, Route41_Text_SwimmermKirkBeaten
	msgbox Route41_Text_SwimmermKirkAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmermKirkSeen:
	.string "Les vagues sont déchaînées ici.\p"
	.string "Elles t'épuisent pendant\n"
	.string "que tu nages.$"

Route41_Text_SwimmermKirkBeaten:
	.string "Je suis crevé !$"

Route41_Text_SwimmermKirkAfter:
	.string "Les courants m'empêchent\n"
	.string "d'atteindre cette île.$"

Route41_EventScript_Mathew::
	trainerbattle_single TRAINER_MATHEW, Route41_Text_SwimmermMathewSeen, Route41_Text_SwimmermMathewBeaten
	msgbox Route41_Text_SwimmermMathewAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmermMathewSeen:
	.string "Tu cherches les secrets\n"
	.string "des ÎLES TOURBILLON?$"

Route41_Text_SwimmermMathewBeaten:
	.string "Ooh, tu as une sacrée endurance !$"

Route41_Text_SwimmermMathewAfter:
	.string "Un secret sur les ÎLES TOURBILLON…\p"
	.string "C'est complètement sombre à l'intérieur !$"

Route41_EventScript_Kaylee::
	trainerbattle_single TRAINER_KAYLEE, Route41_Text_SwimmerfKayleeSeen, Route41_Text_SwimmerfKayleeBeaten
	msgbox Route41_Text_SwimmerfKayleeAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmerfKayleeSeen:
	.string "Je vais vers les ÎLES TOURBILLON.\p"
	.string "Je pars explorer avec des amis.$"

Route41_Text_SwimmerfKayleeBeaten:
	.string "C'est comme ça qu'on fait ?$"

Route41_Text_SwimmerfKayleeAfter:
	.string "Il paraît qu'il y a un grand\n"
	.string "POKéMON sous les ÎLES TOURBILLON.\p"
	.string "Je me demande ce que ça peut être.$"

Route41_EventScript_Susie::
	trainerbattle_single TRAINER_SUSIE, Route41_Text_SwimmerfSusieSeen, Route41_Text_SwimmerfSusieBeaten
	msgbox Route41_Text_SwimmerfSusieAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmerfSusieSeen:
	.string "Tu es si élégant(e),\n"
	.string "sur le dos de ton POKéMON.$"

Route41_Text_SwimmerfSusieBeaten:
	.string "Je suis anéantie…$"

Route41_Text_SwimmerfSusieAfter:
	.string "Il n'y avait pas une chanson célèbre\n"
	.string "sur un garçon chevauchant un LOKHLASS?$"

Route41_EventScript_Denise::
	trainerbattle_single TRAINER_DENISE, Route41_Text_SwimmerfDeniseSeen, Route41_Text_SwimmerfDeniseBeaten
	msgbox Route41_Text_SwimmerfDeniseAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmerfDeniseSeen:
	.string "Il fait si beau,\n"
	.string "je suis toute étourdie !$"

Route41_Text_SwimmerfDeniseBeaten:
	.string "Ohhh !$"

Route41_Text_SwimmerfDeniseAfter:
	.string "Un coup de soleil, c'est terrible pour la peau.\p"
	.string "Mais je n'utilise pas de crème solaire.\p"
	.string "Je ne veux pas polluer l'eau.$"

Route41_EventScript_Kara::
	trainerbattle_single TRAINER_KARA, Route41_Text_SwimmerfKaraSeen, Route41_Text_SwimmerfKaraBeaten
	msgbox Route41_Text_SwimmerfKaraAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmerfKaraSeen:
	.string "Si tu as besoin de te reposer,\n"
	.string "fais du surplace dans l'eau.\p"
	.string "Tu reprendras ton souffle,\n"
	.string "et tu pourras continuer à nager fort !$"

Route41_Text_SwimmerfKaraBeaten:
	.string "Oh ! Tu as plus d'énergie que moi.$"

Route41_Text_SwimmerfKaraAfter:
	.string "J'ai entendu des rugissements\n"
	.string "provenant du fond des ÎLES.$"

Route41_EventScript_Wendy::
	trainerbattle_single TRAINER_WENDY, Route41_Text_SwimmerfWendySeen, Route41_Text_SwimmerfWendyBeaten
	msgbox Route41_Text_SwimmerfWendyAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmerfWendySeen:
	.string "La nuit, les STARYU se rassemblent\n"
	.string "près de la surface de l'eau.$"

Route41_Text_SwimmerfWendyBeaten:
	.string "Oh, mince…$"

Route41_Text_SwimmerfWendyAfter:
	.string "Les groupes de STARYU s'illuminent\n"
	.string "tous en même temps.\p"
	.string "C'est si beau que ça fait peur.$"

Route41_EventScript_Tentacruel1::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_TENTACRUEL, CRY_MODE_NORMAL
	goto_if_ge VAR_TEMP_0, 2, Route41_EventScript_TentacruelAttack1
	msgbox Route41_Text_Tentacruel, MSGBOX_DEFAULT
	waitmoncry
	addvar VAR_TEMP_0, 1
	release
	end
Route41_EventScript_TentacruelAttack1::
	msgbox Route41_Text_TentacruelAttack, MSGBOX_DEFAULT
	waitmessage
	setwildbattle SPECIES_TENTACRUEL, 100, ITEM_NONE
	dowildbattle
	closemessage
	playse SE_USE_ITEM
	msgbox Route41_Text_TentacruelHeal, MSGBOX_DEFAULT
	setvar VAR_TEMP_0, 0
	closemessage
	release
	end

Route41_EventScript_Tentacruel2::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_TENTACRUEL, CRY_MODE_NORMAL
	goto_if_ge VAR_TEMP_1, 2, Route41_EventScript_TentacruelAttack2
	msgbox Route41_Text_Tentacruel, MSGBOX_DEFAULT
	waitmoncry
	addvar VAR_TEMP_1, 1
	release
	end
Route41_EventScript_TentacruelAttack2::
	msgbox Route41_Text_TentacruelAttack, MSGBOX_DEFAULT
	waitmessage
	setwildbattle SPECIES_TENTACRUEL, 100, ITEM_NONE
	dowildbattle
	closemessage
	playse SE_USE_ITEM
	msgbox Route41_Text_TentacruelHeal, MSGBOX_DEFAULT
	setvar VAR_TEMP_1, 0
	closemessage
	release
	end

Route41_EventScript_Tentacruel3::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_TENTACRUEL, CRY_MODE_NORMAL
	goto_if_ge VAR_TEMP_2, 2, Route41_EventScript_TentacruelAttack3
	msgbox Route41_Text_Tentacruel, MSGBOX_DEFAULT
	waitmoncry
	addvar VAR_TEMP_2, 1
	release
	end
Route41_EventScript_TentacruelAttack3::
	msgbox Route41_Text_TentacruelAttack, MSGBOX_DEFAULT
	waitmessage
	setwildbattle SPECIES_TENTACRUEL, 100, ITEM_NONE
	dowildbattle
	closemessage
	playse SE_USE_ITEM
	msgbox Route41_Text_TentacruelHeal, MSGBOX_DEFAULT
	setvar VAR_TEMP_2, 0
	closemessage
	release
	end

Route41_EventScript_Tentacruel4::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_TENTACRUEL, CRY_MODE_NORMAL
	goto_if_ge VAR_TEMP_3, 2, Route41_EventScript_TentacruelAttack4
	msgbox Route41_Text_Tentacruel, MSGBOX_DEFAULT
	waitmoncry
	addvar VAR_TEMP_3, 1
	release
	end
Route41_EventScript_TentacruelAttack4::
	msgbox Route41_Text_TentacruelAttack, MSGBOX_DEFAULT
	waitmessage
	setwildbattle SPECIES_TENTACRUEL, 100, ITEM_NONE
	dowildbattle
	closemessage
	playse SE_USE_ITEM
	msgbox Route41_Text_TentacruelHeal, MSGBOX_DEFAULT
	setvar VAR_TEMP_3, 0
	closemessage
	release
	end

Route41_Text_Tentacruel:
	.string "TENTACRUEL : Cruooo...$"

Route41_Text_TentacruelAttack:
	.string "TENTACRUEL : CRUOOOOOO !$"

Route41_Text_TentacruelHeal:
	.string "Le TENTACRUEL a utilisé SOIN !\n"
	.string "Il est complètement rétabli !$"
