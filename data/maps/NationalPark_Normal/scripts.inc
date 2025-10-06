NationalPark_Normal_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, NationalPark_Normal_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

NationalPark_Normal_OnTransition: 
	callnative SetTimeBasedEncounters
	end

NationalPark_Normal_EventScript_Lass::
	lock
	faceplayer
	msgbox NationalPark_Normal_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

NationalPark_Normal_EventScript_Youngster1::
	lock
	faceplayer
	msgbox NationalPark_Normal_Text_Youngster1, MSGBOX_DEFAULT
	closemessage
	release
	end

NationalPark_Normal_EventScript_Youngster2::
	lock
	faceplayer
	msgbox NationalPark_Normal_Text_Youngster2, MSGBOX_DEFAULT
	closemessage
	release
	end

NationalPark_Normal_EventScript_Teacher2::
	lock
	faceplayer
	msgbox NationalPark_Normal_Text_Teacher2, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	release
	end

NationalPark_Normal_EventScript_TeacherQuickclaw::
	lock
	faceplayer
	goto_if_set FLAG_GOT_QUICK_CLAW, NationalPark_Normal_EventScript_TeacherQuickclaw2
	msgbox NationalPark_Normal_Text_Teacher1, MSGBOX_DEFAULT
	giveitem ITEM_QUICK_CLAW
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	setflag FLAG_GOT_QUICK_CLAW
NationalPark_Normal_EventScript_TeacherQuickclaw2::
	msgbox NationalPark_Normal_Text_Teacher1_QuickClaw, MSGBOX_DEFAULT
	closemessage
	release
	end

NationalPark_Normal_EventScript_Persian::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PERSIAN, CRY_MODE_NORMAL
	msgbox NationalPark_Normal_Text_Persian, MSGBOX_DEFAULT
	waitmoncry
	release
	end



NationalPark_Normal_Text_Lass:
	.string "Regarde ! Jette un œil à mon sac !\p"
	.string "J'ai imprimé mes favoris de mon\n"
	.string "POKéDEX et je les ai collés sur mon sac.$"

NationalPark_Normal_Text_PokefanF:
	.string "Ceci est un COURRIER que j'ai reçu de ma fille.\n"
	.string "Ça me remonte le moral.$"

NationalPark_Normal_Text_Teacher1:
	.string "Attention, s'il vous plaît !\p"
	.string "…Oups, je dois arrêter de penser\n"
	.string "comme une enseignante tout le temps.\p"
	.string "Tu dois être un DRESSEUR de POKéMON.\p"
	.string "Puisque tu travailles si dur, je\n"
	.string "veux que tu prennes ceci.$"

NationalPark_Normal_Text_Teacher1_QuickClaw:
	.string "Fais tenir la GRIFFE RAPIDE à un POKéMON.\p"
	.string "Parfois, il attaquera en premier\n"
	.string "pendant le combat.$"

NationalPark_Normal_Text_Youngster1:
	.string "Je joue avec des autocollants que j'ai imprimés\n"
	.string "depuis mon POKéDEX.$"

NationalPark_Normal_Text_Youngster2:
	.string "Je prends l'autocollant POKéDEX de l'autre\n"
	.string "si je gagne.$"

NationalPark_Normal_Text_Teacher2:
	.string "Je me promène dans le PARC, mais je\n"
	.string "ne vais jamais dans l'herbe.\p"
	.string "Les dresseurs veulent toujours se battre…\p"
	.string "Tu as dû faire beaucoup de combats.\n"
	.string "Laisse-moi soigner tes POKéMON.$"

NationalPark_Normal_Text_Persian:
	.string "PERSIAN : Fufushaa !$"

NationalPark_Normal_EventScript_Jack::
	trainerbattle_single TRAINER_JACK NationalPark_Normal_Text_SchoolboyJack1_Seen, NationalPark_Normal_Text_SchoolboyJack1_Beaten
	msgbox NationalPark_Normal_Text_SchoolboyJack_After, MSGBOX_AUTOCLOSE
	end

NationalPark_Normal_EventScript_Beverly::
	trainerbattle_single TRAINER_BEVERLY NationalPark_Normal_Text_PokefanFBeverly1_Seen, NationalPark_Normal_Text_PokefanFBeverly1_Beaten
	msgbox NationalPark_Normal_Text_PokefanFBeverly_After, MSGBOX_AUTOCLOSE
	end

NationalPark_Normal_EventScript_William::
	trainerbattle_single TRAINER_WILLIAM NationalPark_Normal_Text_PokefanmWilliam_Seen, NationalPark_Normal_Text_PokefanmWilliam_Beaten
	msgbox NationalPark_Normal_Text_PokefanmWilliam_After, MSGBOX_AUTOCLOSE
	end

NationalPark_Normal_EventScript_Krise::
	trainerbattle_single TRAINER_KRISE NationalPark_Normal_Text_LassKrise_Seen, NationalPark_Normal_Text_LassKrise_Beaten
	msgbox NationalPark_Normal_Text_LassKrise_After, MSGBOX_AUTOCLOSE
	end

NationalPark_Normal_EventScript_TM_Dig::
	finditem ITEM_TM_DIG
	end

NationalPark_Normal_EventScript_Item_Soothe_Bell::
	finditem ITEM_SOOTHE_BELL
	end

NationalPark_Normal_Text_SchoolboyJack1_Seen:
	.string "Le monde des POKéMON est profond.\p"
	.string "Il y a encore beaucoup de choses\n"
	.string "que nous ne savons pas.\p"
	.string "Mais j'en sais plus que toi !$"

NationalPark_Normal_Text_SchoolboyJack1_Beaten:
	.string "Qu-quoi ?$"

NationalPark_Normal_Text_SchoolboyJack_After:
	.string "Il y a beaucoup à apprendre.\p"
	.string "Par exemple…\p"
	.string "Il existe 50 types de CT.\p"
	.string "Les POKéMON échangés montent de niveau plus vite.$"

NationalPark_Normal_Text_PokefanFBeverly1_Seen:
	.string "Mes POKéMON sont tout simplement adorables.\p"
	.string "Laisse-moi te dire à quel point\n"
	.string "je suis fière de mes chéris.$"

NationalPark_Normal_Text_PokefanFBeverly1_Beaten:
	.string "Je peux te battre en fierté, mais…$"

NationalPark_Normal_Text_PokefanFBeverly_After:
	.string "Je dois dire, tes POKéMON sont aussi\n"
	.string "très mignons.$"

NationalPark_Normal_Text_PokefanmWilliam_Seen:
	.string "Nous adorons nos POKéMON, même s'ils\n"
	.string "ne nous aiment pas.\p"
	.string "C'est ça, être un FAN.$"

NationalPark_Normal_Text_PokefanmWilliam_Beaten:
	.string "M-mes POKéMON !$"

NationalPark_Normal_Text_PokefanmWilliam_After:
	.string "J'ai perdu le combat, mais mes POKéMON\n"
	.string "gagnent le prix des plus adorables.$"

NationalPark_Normal_Text_LassKrise_Seen:
	.string "Allô ? Pourquoi tu me regardes comme ça ?\p"
	.string "Oh, un combat ?$"

NationalPark_Normal_Text_LassKrise_Beaten:
	.string "…Hmmm…$"

NationalPark_Normal_Text_LassKrise_After:
	.string "Je croyais que tu me regardais\n"
	.string "parce que je suis mignonne !$"

NationalPark_Normal_Text_Sign_RelaxationSquare:
	.string "ESPACE DÉTENTE\n"
	.string "PARC NATIONAL$"

NationalPark_Normal_Text_Sign_BattleNotice:
	.string "Qu'est-ce que cet avis ?\p"
	.string "Merci de combattre uniquement dans l'herbe.\p"
	.string "BUREAU DU GARDIEN DU PARC NATIONAL$"

NationalPark_Normal_Text_TrainerTips:
	.string "ASTUCES DRESSEUR\p"
	.string "Imprimez un COURRIEL en l'ouvrant puis\n"
	.string "en appuyant sur START.$"
