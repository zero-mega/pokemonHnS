.set LOCALID_NURSE, 1

CianwoodPokecenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CianwoodPokecenter_OnTransition
	.byte 0

CianwoodPokecenter_OnTransition::
	setrespawn HEAL_LOCATION_CIANWOOD_CITY
	end

CianwoodPokemoncenter_EventScript_Fisher::
	lock
	faceplayer
	goto_if_set FLAG_TEMP_1, CianwoodPokemoncenter_EventScript_FisherNormal
	checkpartymove MOVE_SURF
	goto_if_eq VAR_RESULT, PARTY_SIZE, CianwoodPokemoncenter_EventScript_FisherGiveTentacool
CianwoodPokemoncenter_EventScript_FisherNormal::
	msgbox CianwoodPokemoncenter_Text_Fisher1, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodPokemoncenter_EventScript_FisherGiveTentacool::
	msgbox CianwoodPokemoncenter_Text_Fisher2, MSGBOX_DEFAULT
	@HnS gift pokemon setup
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_TENTACOOL
	bufferspeciesname STR_VAR_1, SPECIES_TENTACOOL
	givemon SPECIES_TENTACOOL, 25
	call Common_EventScript_GiftMon
	setflag FLAG_TEMP_1
	closemessage
	release
	end

CianwoodPokemoncenter_Text_Fisher1:
	.string "En ce qui concerne les POKéMON d'eau,\n"
	.string "Tentacool est le meilleur, et de loin !$"

CianwoodPokemoncenter_Text_Fisher2:
	.string "Tu sembles avoir besoin d'un POKéMON\n"
	.string "d'eau.\p"
	.string "Tiens, prends celui-ci, j'en ai plein.$"

CianwoodPokecenter_EventScript_Lass::
	lock
	faceplayer
	msgbox CianwoodCity_Text_PokecenterLass, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodCity_Text_PokecenterLass:
	.string "As-tu rencontré le POKéMANIAC ?\p"
	.string "Il se vante toujours de ses\n"
	.string "POKéMON rares.$"


CianwoodGym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_CIANWOOD_GYM, CianwoodGym_EventScript_GymGuideAfter
	msgbox CianwoodCity_Text_GymGuide, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodGym_EventScript_GymGuideAfter::
	msgbox CianwoodCity_Text_GymGuideWin, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodCity_Text_GymGuide:
	.string "Les dresseurs de l'ARÈNE POKéMON ici\n"
	.string "sont de vrais durs à cuire.\p"
	.string "Si je reste trop longtemps, ils\n"
	.string "pourraient s'en prendre à moi.\p"
	.string "Un conseil : le CHAMPION utilise\n"
	.string "le type COMBAT.\p"
	.string "Tu devrais le déstabiliser avec des\n"
	.string "POKéMON de type PSY.\p"
	.string "Mets K.O. ses POKéMON avant qu'ils\n"
	.string "puissent utiliser leur force physique.\p"
	.string "Et ces rochers au milieu de l'ARÈNE ?\p"
	.string "Si tu ne les déplaces pas correctement,\n"
	.string "tu n'atteindras pas le CHAMPION.\p"
	.string "Si tu es bloqué, sors et réessaie.$"

CianwoodCity_Text_GymGuideWin:
	.string "{PLAYER} ! Tu as gagné !\n"
	.string "Je l'avais deviné rien qu'en te regardant !$"

CianwoodPokecenter_EventScript_Nerd::
	lock
	faceplayer
	msgbox CianwoodCity_Text_PokecenterSuperNerd, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodCity_Text_PokecenterSuperNerd:
	.string "J'adore exhiber les POKéMON\n"
	.string "que j'ai élevés.\p"
	.string "Pas toi ?\p"
	.string "Je vais faire plein de combats\n"
	.string "pour montrer mes POKéMON !$"
