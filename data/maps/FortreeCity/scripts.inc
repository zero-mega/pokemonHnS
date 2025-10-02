FortreeCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCity_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, FortreeCity_OnResume
	.byte 0

FortreeCity_OnTransition:
	setflag FLAG_VISITED_VIRIDIAN_CITY
	end

FortreeCity_OnResume:
	setstepcallback STEP_CB_FORTREE_BRIDGE
	end

FortreeCity_EventScript_Man::
	msgbox FortreeCity_Text_SawGiganticPokemonInSky, MSGBOX_NPC
	end

FortreeCity_EventScript_Woman::
	lock
	faceplayer
	goto_if_set FLAG_KECLEON_FLED_FORTREE, FortreeCity_EventScript_WomanGymAccessible
	msgbox FortreeCity_Text_SomethingBlockingGym, MSGBOX_DEFAULT
	release
	end

FortreeCity_EventScript_WomanGymAccessible::
	msgbox FortreeCity_Text_ThisTimeIllBeatWinona, MSGBOX_DEFAULT
	release
	end

FortreeCity_EventScript_Girl::
	msgbox FortreeCity_Text_TreesGrowByDrinkingRainwater, MSGBOX_NPC
	end

FortreeCity_EventScript_OldMan::
	msgbox FortreeCity_Text_EveryoneHealthyAndLively, MSGBOX_NPC
	end

FortreeCity_EventScript_Boy::
	msgbox FortreeCity_Text_BugPokemonComeThroughWindow, MSGBOX_NPC
	end

FortreeCity_EventScript_GameboyKid::
	msgbox FortreeCity_Text_PokemonThatEvolveWhenTraded, MSGBOX_NPC
	end

FortreeCity_EventScript_CitySign::
	msgbox FortreeCity_Text_CitySign, MSGBOX_SIGN
	end

FortreeCity_EventScript_GymSign::
	msgbox FortreeCity_Text_GymSign, MSGBOX_SIGN
	end

FortreeCity_EventScript_Kecleon::
	lock
	faceplayer
	checkitem ITEM_DEVON_SCOPE
	goto_if_eq VAR_RESULT, TRUE, FortreeCity_EventScript_AskUseDevonScope
	msgbox FortreeCity_Text_SomethingUnseeable, MSGBOX_DEFAULT
	release
	end

FortreeCity_EventScript_AskUseDevonScope::
	msgbox FortreeCity_Text_UnseeableUseDevonScope, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, FortreeCity_EventScript_UseDevonScope
	release
	end

FortreeCity_EventScript_UseDevonScope::
	msgbox FortreeCity_Text_UsedDevonScopePokemonFled, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Movement_KecleonAppears
	waitmovement 0
	waitse
	playmoncry SPECIES_KECLEON, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	applymovement VAR_LAST_TALKED, FortreeCity_Movement_KecleonFlee
	waitmovement 0
	removeobject VAR_LAST_TALKED
	setflag FLAG_KECLEON_FLED_FORTREE
	release
	end

FortreeCity_Movement_KecleonFlee:
	walk_right
	step_end

FortreeCity_Text_SawGiganticPokemonInSky:
	.string "Personne ne me croit, mais j’ai vu un\n"
	.string "POKéMON gigantesque dans le ciel.\p"
	.string "Il semblait se tortiller en volant vers\n"
	.string "la ROUTE 131.\p"
	.string "Au fait… Snif…\n"
	.string "Euh… Tu sens un peu le brûlé…\p"
	.string "Tu étais près d’un volcan ou quoi?$"

FortreeCity_Text_SomethingBlockingGym:
	.string "Je veux aller à l’ARÈNE POKéMON,\n"
	.string "mais quelque chose bloque le passage.\p"
	.string "Après tous les efforts que j’ai faits\n"
	.string "en m’entraînant sur la ROUTE 120…$"

FortreeCity_Text_ThisTimeIllBeatWinona:
	.string "J’ai mon POKéMON préféré avec moi.\n"
	.string "Cette fois, je vais battre ALIZÉE.$"

FortreeCity_Text_TreesGrowByDrinkingRainwater:
	.string "Le sol absorbe l’eau de pluie, et\n"
	.string "les arbres grandissent en la buvant…\p"
	.string "Notre CLEMENTI-VILLE existe parce\n"
	.string "qu’il y a à la fois de l’eau et de la terre.$"

FortreeCity_Text_EveryoneHealthyAndLively:
	.string "La VILLE est composée de maisons\n"
	.string "construites sur les arbres.\p"
	.string "Peut-être que ce mode de vie fait que\n"
	.string "tout le monde est en pleine forme.\p"
	.string "Même moi—j’ai l’impression d’avoir\n"
	.string "rajeuni de trente ans.$"

FortreeCity_Text_BugPokemonComeThroughWindow:
	.string "Vivre au sommet des arbres, c’est bien.\p"
	.string "Mais parfois, des POKéMON INSECTE\n"
	.string "rentrent par les fenêtres.\l"
	.string "Ça peut vraiment surprendre.$"

FortreeCity_Text_PokemonThatEvolveWhenTraded:
	.string "Il y a des POKéMON qui évoluent quand\n"
	.string "on les échange ! C’est ce qu’on m’a dit.$"

FortreeCity_Text_SomethingUnseeable:
	.string "Quelque chose d’invisible bloque le passage.$"

FortreeCity_Text_UnseeableUseDevonScope:
	.string "Quelque chose d’invisible bloque le passage.\p"
	.string "Voulez-vous utiliser le DEVON SCOPE?$"

FortreeCity_Text_UsedDevonScopePokemonFled:
	.string "{PLAYER} utilise le DEVON SCOPE.\p"
	.string "Un POKéMON invisible devient\n"
	.string "complètement visible !\p"
	.string "Le POKéMON effrayé s’enfuit !$"

FortreeCity_Text_CitySign:
	.string "CLEMENTI-VILLE\n"
	.string "« La ville perchée qui s’amuse avec\l"
	.string "la nature. »$"

FortreeCity_Text_GymSign:
	.string "ARÈNE POKéMON DE CLEMENTI-VILLE\n"
	.string "CHAMPIONNE : ALIZÉE\p"
	.string "« La dresseuse d’oiseaux qui prend\n"
	.string "son envol vers le monde. »$"
