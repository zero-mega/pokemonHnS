.set LOCALID_NURSE, 1

AzaleaTown_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, AzaleaTown_Pokecenter_OnTransition
	.byte 0

AzaleaTown_Pokecenter_OnTransition::
	setrespawn HEAL_LOCATION_AZALEA_TOWN
	end

AzaleaPokeCenter_EventScript_Gentleman::
	lock
	faceplayer
	msgbox AzaleaPokecenter_Text_Gentleman, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaPokeCenter_EventScript_Fisher::
	lock
	faceplayer
	msgbox AzaleaPokecenter_Text_FishingGuru, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaPokeCenter_EventScript_PokefanF::
	lock
	faceplayer
	msgbox AzaleaPokecenter_Text_PokefanF, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaPokecenter_Text_Gentleman:
	.string "Tes POKéMON connaissent-ils des CS ?\p"
	.string "Ces capacités peuvent être utilisées\n"
	.string "même si ton POKéMON est K.O.$"

AzaleaPokecenter_Text_UnusedPCExplanation:
	.string "Ce gars, LEO, a créé le système\n"
	.string "pour stocker les POKéMON sur PC.\p"
	.string "Le PC de LEO peut contenir jusqu'à 30\n"
	.string "POKéMON par BOÎTE.$"

AzaleaPokecenter_Text_FishingGuru:
	.string "Le PC de LEO peut contenir jusqu'à 30\n"
	.string "POKéMON par BOÎTE.$"

AzaleaPokecenter_Text_PokefanF:
	.string "Tu connais les BAIES ?\p"
	.string "Ouvre-en une, creuse-la et\n"
	.string "mets-y un dispositif spécial.\p"
	.string "Tu pourras alors attraper des POKéMON avec.\p"
	.string "Avant l'invention des POKé BALLS,\n"
	.string "tout le monde utilisait des BAIES.$"
