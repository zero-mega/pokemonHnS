.set LOCALID_NURSE, 1

SafariZoneGate_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SafariZoneGate_PokemonCenter_OnTransition
	.byte 0

SafariZoneGate_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_SAFARI_ZONE_GATE
	end

SafariZoneGate_PokemonCenter_EventScript_NPC1::
	lock
	faceplayer
	msgbox SafariZoneGate_PokemonCenter_Text_NPC1, MSGBOX_DEFAULT
	closemessage
	release
	end

SafariZoneGate_PokemonCenter_EventScript_NPC2::
	lock
	faceplayer
	msgbox SafariZoneGate_PokemonCenter_Text_NPC2, MSGBOX_DEFAULT
	closemessage
	release
	end

SafariZoneGate_PokemonCenter_Text_Boy::
	lock
	faceplayer
	msgbox SafariZoneGate_PokemonCenter_Text_SafariSong, MSGBOX_DEFAULT
	closemessage
	release
	end

SafariZoneGate_PokemonCenter_Text_NPC1:
	.string "Ceux qui viennent dans un CENTRE POKéMON\n"
	.string "prennent souvent bien soin de leurs POKéMON.\p"
	.string "N'es-tu pas d'accord?$"

SafariZoneGate_PokemonCenter_Text_NPC2:
	.string "Après une longue marche dans la montagne\n"
	.string "pour trouver un CENTRE POKéMON, quand tu es\l"
	.string "sur le point de t'effondrer...\p"
	.string "Alors, on se sent comme au paradis !$"

SafariZoneGate_PokemonCenter_Text_SafariSong:
	.string "Safari, safari, c'est tellement amusant.\n"
	.string "Safari, safari, c'est passionnant, hein !\p"
	.string "Tant de POKéMON nous attendent là-bas !\p"
	.string "...C'est une chanson que j'ai inventée.\n"
	.string "Je la chante quand je suis dans la ZONE SAFARI.$"