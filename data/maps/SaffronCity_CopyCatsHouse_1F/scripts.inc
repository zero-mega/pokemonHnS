SaffronCity_CopyCatsHouse_1F_MapScripts::
	.byte 0

SaffronCity_CopyCatsHouse_1F_EventScript_Mom::
	goto_if_set FLAG_RETURNED_MACHINE_PART, SaffronCity_CopyCatsHouse_1F_EventScript_MomAfter
	msgbox CopycatsHouse1F_Text_PokefanF, MSGBOX_NPC
	end

SaffronCity_CopyCatsHouse_1F_EventScript_MomAfter::
	msgbox CopycatsHouse1F_Text_PokefanF_ReturnedPart, MSGBOX_NPC
	end

SaffronCity_CopyCatsHouse_1F_EventScript_Dad::
	msgbox CopycatsHouse1F_Text_PokefanM, MSGBOX_NPC
	end

SaffronCity_CopyCatsHouse_1F_EventScript_Blissey::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_BLISSEY, CRY_MODE_NORMAL
	msgbox CopycatsHouse1F_Text_Blissey, MSGBOX_DEFAULT
	waitmoncry
	release
	end

CopycatsHouse1F_Text_PokefanM:
	.string "Ma fille adore imiter les gens.\p"
	.string "Son talent pour l'imitation lui a\n"
	.string "valu le surnom de COPIEUSE ici.$"

CopycatsHouse1F_Text_PokefanF:
	.string "Ma fille est tellement égocentrique…\p"
	.string "Elle n'a que quelques amis.$"

CopycatsHouse1F_Text_PokefanF_ReturnedPart:
	.string "Elle a récemment perdu la POUPEE\n"
	.string "POKéMON qu'un garçon lui avait\l"
	.string "offerte il y a trois ans.\p"
	.string "Depuis, elle est devenue encore\n"
	.string "meilleure en imitation…$"

CopycatsHouse1F_Text_Blissey:
	.string "LEUPHORIE : Leuphooo!$"
