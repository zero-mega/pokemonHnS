CeruleanCity_House2_MapScripts::
	.byte 0

CeruleanCity_House2_EventScript_Woman::
	msgbox CeruleanPolice_Text_PokefanF, MSGBOX_NPC
	end

CeruleanCity_House2_EventScript_Man::
	msgbox CeruleanPolice_Text_FishingGuru, MSGBOX_NPC
	end

CeruleanCity_House2_EventScript_Diglett::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_DIGLETT, CRY_MODE_NORMAL
	msgbox CeruleanPolice_Text_Diglett, MSGBOX_DEFAULT
	waitmoncry
	release
	end

CeruleanPolice_Text_FishingGuru:
	.string "J'ai entendu dire qu'un individu louche\n"
	.string "rôde dans les environs.\p"
	.string "Je ne le tolérerai pas s'il s'avère\n"
	.string "que c'est un voleur.$"

CeruleanPolice_Text_PokefanF:
	.string "Nous avons déjà été victimes de voleurs.$"

CeruleanPolice_Text_Diglett:
	.string "TAUPIQUEUR : Dug dug.$"
