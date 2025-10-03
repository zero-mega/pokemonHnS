LavenderTown_RadioStation_MapScripts::
	.byte 0

LavenderTown_RadioStation_EventScript_Officer::
	msgbox LavenderTown_RadioStation_Text_Officer, MSGBOX_NPC
	end

LavenderTown_RadioStation_EventScript_Receptionist::
	msgbox LavenderTown_RadioStation_Text_Receptionist, MSGBOX_NPC
	end

LavenderTown_RadioStation_EventScript_SuperNerd::
	msgbox LavenderTown_RadioStation_Text_SuperNerd1, MSGBOX_NPC
	end

LavenderTown_RadioStation_EventScript_Director::
	lock
	faceplayer
	goto_if_set FLAG_KANTO_RADIO_GOT, LavenderTown_RadioStation_EventScript_DirectorGotRadio
	goto_if_set FLAG_RETURNED_MACHINE_PART, LavenderTown_RadioStation_EventScript_DirectorReturnedMachinePart
	msgbox LavenderTown_RadioStation_Text_Gentleman, MSGBOX_NPC
	end
LavenderTown_RadioStation_EventScript_DirectorReturnedMachinePart::
	msgbox LavenderTown_RadioStation_Text_Gentleman_ReturnedMachinePart, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	msgbox LavendertownRadioStation_Text_Upgraded_Radio, MSGBOX_DEFAULT
	waitfanfare
	msgbox LavenderTown_RadioStation_Text_Gentleman_GotExpnCard, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_KANTO_RADIO_GOT
	release
	end
LavenderTown_RadioStation_EventScript_DirectorGotRadio::	
	msgbox LavenderTown_RadioStation_Text_Gentleman_GotExpnCard, MSGBOX_NPC
	end

LavenderTown_RadioStation_EventScript_Host::
	goto_if_set FLAG_KANTO_RADIO_GOT, LavenderTown_RadioStation_EventScript_Host2
	msgbox LavenderTown_RadioStation_Text_SuperNerd2, MSGBOX_NPC
	end
LavenderTown_RadioStation_EventScript_Host2::
	msgbox LavenderTown_RadioStation_Text_SuperNerd2_GotExpnCard, MSGBOX_NPC
	end

LavenderTown_RadioStation_EventScript_Directory::
	msgbox LavenderTown_RadioStation_Text_Directory, MSGBOX_SIGN
	end
LavenderTown_RadioStation_EventScript_Sign::
	msgbox LavenderTown_RadioStation_Text_PokeFluteSign, MSGBOX_SIGN
	end
LavenderTown_RadioStation_EventScript_Library::
	msgbox LavenderTown_RadioStation_Text_ReferenceLibrary, MSGBOX_SIGN
	end

LavenderTown_RadioStation_Text_Receptionist:
	.string "Bienvenue ! N'hésitez pas à faire\n"
	.string "le tour de cet étage.$"

LavenderTown_RadioStation_Text_Officer:
	.string "Désolé, mais la visite est limitée\n"
	.string "au rez-de-chaussée.\p"
	.string "Depuis que la TOUR RADIO de JOHTO\n"
	.string "a été prise par une bande criminelle,\l"
	.string "nous avons dû renforcer la\l"
	.string "sécurité.$"

LavenderTown_RadioStation_Text_SuperNerd1:
	.string "Beaucoup de gens travaillent dur ici\n"
	.string "dans la TOUR RADIO.\p"
	.string "Ils font de leur mieux pour offrir\n"
	.string "de bonnes émissions.$"

LavenderTown_RadioStation_Text_Gentleman:
	.string "Oh, non, non, non !\p"
	.string "Nous sommes hors d'antenne depuis\n"
	.string "la panne de la CENTRALE.\p"
	.string "Tous mes efforts pour ouvrir cette\n"
	.string "station seraient vains si je ne peux\l"
	.string "pas émettre.\p"
	.string "Je suis ruiné !$"

LavenderTown_RadioStation_Text_Gentleman_ReturnedMachinePart:
	.string "Ah ! Tu es donc le fameux {PLAYER}\n"
	.string "qui a résolu le problème de la CENTRALE ?\p"
	.string "Grâce à toi, je n'ai pas perdu mon\n"
	.string "travail.\p"
	.string "Tu es vraiment un sauveur !\p"
	.string "Prends ceci pour te remercier.$"

LavendertownRadioStation_Text_Upgraded_Radio:
	.string "{PLAYER} obtient la\n"
	.string "CARTE EXPN !$"

LavenderTown_RadioStation_Text_Gentleman_GotExpnCard:
	.string "Avec ça, tu peux écouter les\n"
	.string "programmes radio de KANTO.\p"
	.string "Gahahahaha !$"

LavenderTown_RadioStation_Text_SuperNerd2:
	.string "Salut !\p"
	.string "Je suis le super DIRECTEUR MUSICAL !\p"
	.string "Hein ? Ta RADIO ne capte pas\n" @POKéGEAR
	.string "mes émissions musicales. Dommage !\p"
	.string "Si tu obtiens la CARTE EXPN,\n"
	.string "tu pourras écouter. Tu devrais en\l"
	.string "avoir une !$"

LavenderTown_RadioStation_Text_SuperNerd2_GotExpnCard:
	.string "Salut !\p"
	.string "Je suis le super DIRECTEUR MUSICAL !\p"
	.string "Je suis responsable des magnifiques\n"
	.string "mélodies diffusées à la radio.\p"
	.string "Ne sois pas ringard, écoute la\n"
	.string "musique sur les ondes !$"

LavenderTown_RadioStation_Text_Directory:
	.string "1F ACCUEIL 2F VENTES\p"
	.string "3F PERSONNEL 4F PRODUCTION\p"
	.string "5F BUREAU DU DIRECTEUR$"

LavenderTown_RadioStation_Text_PokeFluteSign:
	.string "Égaye tes POKéMON avec les sons\n"
	.string "doux de la POKé FLÛTE sur le\l"
	.string "CANAL 20$"

LavenderTown_RadioStation_Text_ReferenceLibrary:
	.string "Ouah ! Une étagère remplie de CD\n"
	.string "et de vidéos POKéMON.\p"
	.string "Ça doit être la bibliothèque\n"
	.string "de référence.$"
