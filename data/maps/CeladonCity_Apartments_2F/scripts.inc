CeladonCity_Apartments_2F_MapScripts::
	.byte 0

CeladonCity_Apartments_2F_EventScript_Computer::
	lock
	playse SE_PC_ON
	msgbox CeladonMansion2F_Text_Computer
	playse SE_PC_OFF
	waitse
	release
	end

CeladonCity_Apartments_2F_EventScript_Sign::
	msgbox CeladonMansion2F_Text_DevOfficeSign, MSGBOX_SIGN
	end

CeladonMansion2F_Text_Computer:
	.string "{PLAYER} a allumé le PC.\p"
	.string "…\p"
	.string "Quelqu'un était en train de\n"
	.string "rédiger un e-mail.\p"
	.string "…J'espère que tu viendras visiter KANTO.\p"
	.string "Je pense que tu seras surpris de voir\n"
	.string "à quel point les choses ont changé ici.\p"
	.string "Tu verras aussi beaucoup de POKéMON qui\n"
	.string "ne sont pas natifs de JOHTO.\p"
	.string "Au PRODUCTEUR\p"
	.string "…$"

CeladonMansion2F_Text_DevOfficeSign:
	.string "HEART & SOUL DEVELOPMENT OFFICE$"

CeladonMansion2F_EventScript_LilDill::
	msgbox CeladonMansion2F_Text_LilDill, MSGBOX_NPC
	end

CeladonMansion2F_EventScript_InfiniteBacon::
	msgbox CeladonMansion2F_Text_InfiniteBacon, MSGBOX_NPC
	end

CeladonMansion2F_EventScript_TixoRebel::
	msgbox CeladonMansion2F_Text_TixoRebel, MSGBOX_NPC
	end

CeladonMansion2F_EventScript_Phant::
	msgbox CeladonMansion2F_Text_Phant, MSGBOX_NPC
	end

CeladonMansion2F_EventScript_Exclsior::
	msgbox CeladonMansion2F_Text_Exclsior, MSGBOX_NPC
	end

CeladonMansion2F_EventScript_DaniRainbow::
    msgbox CeladonMansion2F_Text_DaniRaibow, MSGBOX_NPC
    end

CeladonMansion2F_Text_LilDill:
	.string "Salut à tous, Patch 15--\p"
	.string "Pardon, je veux dire...\p"
	.string "Bonjour, je suis le DIRECTEUR DU JEU !\p"
	.string "J'ai créé les maps, les tilesets, les\n"
	.string "scripts, et bien plus encore.\p"
	.string "Mais je n'aurais pas pu le faire sans\n"
	.string "les autres développeurs et les testeurs.\p"
	.string "Merci d'avoir joué ! J'espère que vous\n"
	.string "avez apprécié POKéMON HEART & SOUL.$"

CeladonMansion2F_Text_InfiniteBacon:
	.string "Nous travaillons à reconstruire ce jeu\n"
	.string "dans pokeemerald expansion !$"

CeladonMansion2F_Text_TixoRebel:
	.string "As-tu entendu parler de THE EGGENING ?\n"
	.string "C'était un bug du playtest\l"
	.string "qui changeait aléatoirement des POKéMON\l"
	.string "en OEUFS !\p"
	.string "J'ai développé le correctif !$"

CeladonMansion2F_Text_Phant:
	.string "J'adore les DEMAKE !\p"
	.string "As-tu joué à SWORD AND SHIELD\n"
	.string "ULTIMATE PLUS - ENGLISH ?\l"
	.string "Je l'ai traduit !\p"
	.string "Pour mon prochain DEMAKE, je pense que\n"
	.string "je ferai ALOLA !$"

CeladonMansion2F_Text_Exclsior:
	.string "J'ai implémenté les sprites de surf\n"
	.string "uniques pour chaque POKéMON !\p"
	.string "Comme le projet est OPEN SOURCE,\n"
	.string "tu peux aussi ajouter tes propres idées !$"

CeladonMansion2F_Text_DaniRaibow:
	.string "Salut !\p"
	.string "Je suis plutôt doué pour trouver des\n"
	.string "problèmes, et je peux en corriger des petits.\p"
    .string "Tu veux entendre une blague ?\p"
    .string "LANCE a essayé d'apprendre à DRACOLOSSE\n"
    .string "l'attaque DRACO-SOUFFLE.\p"
    .string "Mais DRACOLOSSE allait trop vite avec\n"
    .string "VIT.EXTREME ; il n'a pas pu l'attraper !$"
