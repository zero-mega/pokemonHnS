SSTidalRooms_MapScripts::
	.byte 0

SSTidalRooms_EventScript_SnatchGiver::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_SNATCH, SSTidalRooms_EventScript_ExplainSnatch
	msgbox SSTidalRooms_Text_NotSuspiciousTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_TM_SNATCH
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_SNATCH
	msgbox SSTidalRooms_Text_ExplainSnatch, MSGBOX_DEFAULT
	release
	end

SSTidalRooms_EventScript_ExplainSnatch::
	msgbox SSTidalRooms_Text_ExplainSnatch, MSGBOX_DEFAULT
	release
	end

SSTidalRooms_EventScript_Bed::
	specialvar VAR_RESULT, IsPokecenterChallengeActivated
	goto_if_eq VAR_RESULT, TRUE, SSTidalRooms_EventScript_Bed_PokecenterChallenge
	lockall
	msgbox SSTidalRooms_Text_TakeRestOnBed, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	call SSTidalRooms_EventScript_ProgessCruiseAfterBed
	releaseall
	end

SSTidalRooms_EventScript_Bed_PokecenterChallenge::
	msgbox SSTidalRooms_Text_TakeRestOnBed_PokecenterChallenge, MSGBOX_DEFAULT
	closemessage
	end

SSTidalRooms_EventScript_Colton::
	trainerbattle_single TRAINER_GRUNT_26, SSTidalRooms_Text_ColtonIntro, SSTidalRooms_Text_ColtonDefeat
	msgbox SSTidalRooms_Text_ColtonPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Micah::
	trainerbattle_single TRAINER_MICAH, SSTidalRooms_Text_MicahIntro, SSTidalRooms_Text_MicahDefeat
	msgbox SSTidalRooms_Text_MicahPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Thomas::
	trainerbattle_single TRAINER_THOMAS, SSTidalRooms_Text_ThomasIntro, SSTidalRooms_Text_ThomasDefeat
	msgbox SSTidalRooms_Text_ThomasPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Jed::
	trainerbattle_double TRAINER_LEA_AND_JED, SSTidalRooms_Text_JedIntro, SSTidalRooms_Text_JedDefeat, SSTidalRooms_Text_JedNotEnoughMons
	msgbox SSTidalRooms_Text_JedPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Lea::
	trainerbattle_double TRAINER_LEA_AND_JED, SSTidalRooms_Text_LeaIntro, SSTidalRooms_Text_LeaDefeat, SSTidalRooms_Text_LeaNotEnoughMons
	msgbox SSTidalRooms_Text_LeaPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Garret::
	trainerbattle_single TRAINER_GARRET, SSTidalRooms_Text_GarretIntro, SSTidalRooms_Text_GarretDefeat
	msgbox SSTidalRooms_Text_GarretPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Naomi::
	trainerbattle_single TRAINER_NAOMI, SSTidalRooms_Text_NaomiIntro, SSTidalRooms_Text_NaomiDefeat
	msgbox SSTidalRooms_Text_NaomiPostBattle, MSGBOX_AUTOCLOSE
	end
	
SSTidalRooms_Text_TakeRestOnBed_PokecenterChallenge:
	.string "Désolé, vous jouez avec le\n"
	.string "défi CENTRE POKéMON !$"

SSTidalRooms_Text_TakeRestOnBed:
	.string "Il y a un lit…\n"
	.string "Reposons-nous.$"

SSTidalRooms_Text_ColtonIntro:
	.string "Je navigue souvent vers POIVRESSEL.\p"
	.string "J'aime assister aux CONCOURS,\n"
	.string "vous savez.$"

SSTidalRooms_Text_ColtonDefeat:
	.string "C'était un match agréable !$"

SSTidalRooms_Text_ColtonPostBattle:
	.string "Je m'excite à l'idée de voir quels\n"
	.string "POKéMON je verrai au prochain\l"
	.string "CONCOURS. L'attente me ravit !$"

SSTidalRooms_Text_MicahIntro:
	.string "Tes amis sont-ils forts ?$"

SSTidalRooms_Text_MicahDefeat:
	.string "Tes amis sont vraiment forts.$"

SSTidalRooms_Text_MicahPostBattle:
	.string "Les amis n'ont pas besoin d'être humains.\n"
	.string "Pour moi, les POKéMON sont des amis précieux !$"

SSTidalRooms_Text_ThomasIntro:
	.string "Enfant…\n"
	.string "As-tu frappé à la porte ?$"

SSTidalRooms_Text_ThomasDefeat:
	.string "Une défaite doit être acceptée sans hâte\n"
	.string "ni panique.$"

SSTidalRooms_Text_ThomasPostBattle:
	.string "Ne jamais perdre son calme en toute situation,\n"
	.string "c'est le code de conduite d'un GENTLEMAN.$"

SSTidalRooms_Text_JedIntro:
	.string "JED : Je suis un peu timide, mais…\n"
	.string "Nous allons te montrer notre pouvoir d'amoureux !$"

SSTidalRooms_Text_JedDefeat:
	.string "JED : Soupir…$"

SSTidalRooms_Text_JedPostBattle:
	.string "JED : C'est la première fois que notre\n"
	.string "pouvoir d'amoureux ne l'emporte pas !\l"
	.string "Tu dois être un DRESSEUR incroyable !$"

SSTidalRooms_Text_JedNotEnoughMons:
	.string "JED : Tu n'as qu'un seul POKéMON ?\n"
	.string "N'est-ce pas trop triste ?$"

SSTidalRooms_Text_LeaIntro:
	.string "LÉA : Je me sens un peu bête, mais…\n"
	.string "Nous allons te montrer notre pouvoir d'amoureux !$"

SSTidalRooms_Text_LeaDefeat:
	.string "LÉA : Oh, zut !$"

SSTidalRooms_Text_LeaPostBattle:
	.string "LÉA : Je n'arrive pas à y croire !\n"
	.string "Notre pouvoir d'amoureux a échoué…\l"
	.string "Tu dois être un DRESSEUR incroyable !$"

SSTidalRooms_Text_LeaNotEnoughMons:
	.string "LÉA : Je voulais me battre…\n"
	.string "Mais tu n'as même pas deux POKéMON…$"

SSTidalRooms_Text_GarretIntro:
	.string "Ah, tu arrives juste à temps.\p"
	.string "Je m'ennuyais, tu sais.\n"
	.string "Tu peux m'amuser.$"

SSTidalRooms_Text_GarretDefeat:
	.string "…Cela suffira.$"

SSTidalRooms_Text_GarretPostBattle:
	.string "Peut-être que je demanderai à Père de m'offrir\n"
	.string "un yacht.\l"
	.string "Un yacht pour moi et mes POKéMON !$"

SSTidalRooms_Text_NaomiIntro:
	.string "Oh, tu es un DRESSEUR adorable.\n"
	.string "Veux-tu prendre le thé ?\l"
	.string "Ou préfères-tu combattre ?$"

SSTidalRooms_Text_NaomiDefeat:
	.string "Je vois.\n"
	.string "Tu es du genre actif.$"

SSTidalRooms_Text_NaomiPostBattle:
	.string "Une croisière autour du monde sur un paquebot\n"
	.string "de luxe a son charme, je dois l'avouer…\p"
	.string "Mais, je reconnais qu'il y a un côté attrayant\n"
	.string "à parcourir HOENN en ferry.$"

SSTidalRooms_Text_NotSuspiciousTakeThis:
	.string "Euh… Salut ! Je… Je n'agis pas bizarrement !\n"
	.string "Euh… Tu peux prendre ça ! C'est gratuit !\p"
	.string "Je… Honnêtement, je n'ai pas VOLE ça à\n"
	.string "quelqu'un ! Je ne ferais jamais ça !\l"
	.string "C'est propre ! Tu peux l'utiliser !$"

SSTidalRooms_Text_ExplainSnatch:
	.string "VOLEUR vole les effets bénéfiques\n"
	.string "de certaines capacités avant qu'elles ne soient\l"
	.string "utilisées par un adversaire ou un allié.$"
