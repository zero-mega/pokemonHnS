CaveOfOrigin_UnusedRubySapphireMap1_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, CaveOfOrigin_UnusedRubySapphireMap1_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, SetTimeEncounters
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

CaveOfOrigin_UnusedRubySapphireMap1_OnLoad:
	call_if_unset FLAG_REGI_DOORS_OPENED, CaveOfOrigin_UnusedRubySapphireMap1_CloseRegiEntrance
	end

CaveOfOrigin_UnusedRubySapphireMap1_CloseRegiEntrance::
	setmetatile 14, 14, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 14, 15, METATILE_General_RockWall_SandBase, TRUE
	return

CaveOfOrigin_UnusedRubySapphireMap1_Scientist1::
	msgbox CaveOfOrigin_UnusedRubySapphireMap1_Scientist1_Text, MSGBOX_NPC
	release
	end

CaveOfOrigin_UnusedRubySapphireMap1_Scientist2::
	msgbox CaveOfOrigin_UnusedRubySapphireMap1_Scientist2_Text, MSGBOX_NPC
	release
	end

CaveOfOrigin_UnusedRubySapphireMap1_Scientist3::
	msgbox CaveOfOrigin_UnusedRubySapphireMap1_Scientist3_Text, MSGBOX_NPC
	release
	end

CaveOfOrigin_UnusedRubySapphireMap1_Kirlia::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_KIRLIA, CRY_MODE_NORMAL
	msgbox CaveOfOrigin_UnusedRubySapphireMap1_Kirlia_Text, MSGBOX_DEFAULT
	waitmoncry
	release
	end

CaveOfOrigin_UnusedRubySapphireMap1_Scientist1_Text:
	.string "J'ai déjà vu ce genre de structure rocheuse\n"
	.string "à d'autres endroits, comme sur la ROUTE 132.\p"
	.string "Quelle est la signification de ces\n"
	.string "formations rocheuses ?\p"
	.string "Je suis absolument certain qu'elles sont\n"
	.string "d'origine humaine. As-tu une idée ?$"

CaveOfOrigin_UnusedRubySapphireMap1_Scientist2_Text:
	.string "À chaque orage, certains éclairs finissent\n"
	.string "par frapper cette petite île. N'est-ce pas\l"
	.string "suspect ?\p"
	.string "Nous pensons qu'il y a un POKéMON qui vit\n"
	.string "ici et qui ne se nourrit que de coups\l"
	.string "de foudre.$"

CaveOfOrigin_UnusedRubySapphireMap1_Scientist3_Text:
	.string "Nous étudions un étrange phénomène\n"
	.string "qui se produit depuis quelques mois.\l"
	.string "Cette île n'est habitée par aucun humain,\l"
	.string "donc quelque chose qui s'y passe est\l"
	.string "extrêmement mystérieux, pour le moins.\p"
	.string "KIRI cherche aussi des indices.\n"
	.string "Nous devons élucider ce mystère.$"

CaveOfOrigin_UnusedRubySapphireMap1_Kirlia_Text:
	.string "KIRI : Kir !$"
