LavenderTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavenderTown_EventScript_CityEnter
	.byte 0

LavenderTown_EventScript_CityEnter::
	setflag FLAG_VISITED_LAVENDER_TOWN
	end

LavenderTown_EventScript_PokefanM::
	msgbox LavenderTown_Text_PokefanM, MSGBOX_NPC
	end

LavenderTown_EventScript_Teacher::
	msgbox LavenderTown_Text_Teacher, MSGBOX_NPC
	end

LavenderTown_EventScript_Gramps::
	msgbox LavenderTown_Text_Gramps, MSGBOX_NPC
	end

LavenderTown_EventScript_Youngster::
	msgbox LavenderTown_Text_Youngster, MSGBOX_NPC
	end

LavenderTown_EventScript_TownSign::
	msgbox LavenderTown_Text_Sign, MSGBOX_SIGN
	end

LavenderTown_EventScript_RadioTowerSign::
	msgbox LavenderTown_Text_KantoRadioStationSign, MSGBOX_SIGN
	end

LavenderTown_EventScript_VolunteerSign::
	msgbox LavenderTown_Text_VolunteerPokemonHouseSign, MSGBOX_SIGN
	end

LavenderTown_EventScript_SoulHouseSign::
	msgbox LavenderTown_Text_SoulHouseSign, MSGBOX_SIGN
	end

LavenderTown_Text_PokefanM:
	.string "C'est un sacré bâtiment, hein ?\p"
	.string "C'est la TOUR RADIO de KANTO.$"

LavenderTown_Text_Teacher:
	.string "KANTO a beaucoup de bonnes émissions de radio.$"

LavenderTown_Text_Gramps:
	.string "Des gens viennent de partout pour rendre\n"
	.string "hommage aux âmes des POKéMON\l"
	.string "disparus.$"

LavenderTown_Text_Youngster:
	.string "Il te faut une POKé FLÛTE pour réveiller\n"
	.string "les POKéMON endormis.\p"
	.string "Tout dresseur doit savoir ça !$"

LavenderTown_Text_Sign:
	.string "LAVANVILLE\p"
	.string "La Noble Ville Pourpre$"

LavenderTown_Text_KantoRadioStationSign:
	.string "STATION RADIO DE KANTO\p"
	.string "Vos programmes favoris à l'antenne\n"
	.string "toute la journée !$"

LavenderTown_Text_VolunteerPokemonHouseSign:
	.string "MAISON DES BÉNÉVOLES POKéMON\n"
	.string "DE LAVANVILLE$"

LavenderTown_Text_SoulHouseSign:
	.string "MAISON DES ÂMES\p"
	.string "Que les âmes des POKéMON reposent\n"
	.string "en paix$"
