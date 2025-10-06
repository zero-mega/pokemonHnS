.set LOCALID_NURSE, 1

OlivineCity_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OlivineCity_PokemonCenter_OnTransition
	.byte 0

OlivineCity_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_OLIVINE_CITY
	end

OlivineCity_EventScript_Fisher::
	lock
	faceplayer
	msgbox OlivineCity_Text_PokecenterFisher, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_EventScript_Teacher::
	lock
	faceplayer
	msgbox OlivineCity_Text_PokecenterTeacher, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_Text_PokecenterFisher:
	.string "Le MARIN du CAFÉ d'OLIVINE\n"
	.string "à côté est vraiment généreux.\p"
	.string "Il a appris FORCE à mon POKéMON.\p"
	.string "Maintenant, il peut déplacer de\n"
	.string "gros rochers sans effort.$"

OlivineCity_Text_PokecenterTeacher:
	.string "Il y a quelqu'un à IRISIA\n"
	.string "de l'autre côté de la mer.\p"
	.string "Je l'ai entendu se vanter tout le\n"
	.string "temps de ses POKéMON rares.$"
