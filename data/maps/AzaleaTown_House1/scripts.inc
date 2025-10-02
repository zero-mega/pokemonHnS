AzaleaTown_House1_MapScripts::
	.byte 0

AzaleaTown_House1_EventScript_Boss::
	lock
	faceplayer
	goto_if_eq VAR_AZALEA_TOWN_STATE, 5, AzaleaTown_House1_EventScript_Boss3
	goto_if_eq VAR_AZALEA_TOWN_STATE, 6, AzaleaTown_House1_EventScript_Boss3
	goto_if_eq VAR_AZALEA_TOWN_STATE, 7, AzaleaTown_House1_EventScript_Boss4
	goto_if_set FLAG_HIDE_AZALEA_TOWN_ROCKETS, AzaleaTown_House1_EventScript_Boss2
	msgbox CharcoalKiln_Text_Boss1, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_House1_EventScript_Boss2::
	msgbox CharcoalKiln_Text_Boss2, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_House1_EventScript_Boss3::
	msgbox CharcoalKiln_Text_Boss3, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_House1_EventScript_Boss4::
	msgbox CharcoalKiln_Text_Boss4, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_House1_EventScript_Apprentice::
	lock
	faceplayer
	goto_if_ge VAR_AZALEA_TOWN_STATE, 7, AzaleaTown_House1_EventScript_Apprentice3
	goto_if_set FLAG_HIDE_AZALEA_TOWN_ROCKETS, AzaleaTown_House1_EventScript_Apprentice2
	msgbox CharcoalKiln_Text_Apprentice1, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_House1_EventScript_Apprentice2::
	msgbox CharcoalKiln_Text_Apprentice2, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_House1_EventScript_Apprentice3::
	goto_if_set FLAG_GOT_CHARCOAL, AzaleaTown_House1_EventScript_Apprentice4
	msgbox CharcoalKiln_Text_Apprentice3, MSGBOX_DEFAULT
	giveitem ITEM_CHARCOAL 
	setflag FLAG_GOT_CHARCOAL
	closemessage
	release
	end

AzaleaTown_House1_EventScript_Apprentice4::
	msgbox CharcoalKiln_Text_Apprentice4, MSGBOX_DEFAULT
	closemessage
	release
	end


AzaleaTown_House1_EventScript_Farfetchd::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_FARFETCHD, CRY_MODE_NORMAL
	msgbox CharcoalKiln_Text_Farfetchd, MSGBOX_DEFAULT
	waitmoncry
	release
	end
	


CharcoalKiln_Text_Boss1:
	.string "Tous les RAMOLOSS ont disparu\n"
	.string "de la ville…\p"
	.string "Le protecteur de la forêt est peut-être\n"
	.string "en colère contre nous…\p"
	.string "C'est peut-être un mauvais présage.\n"
	.string "On devrait rester à l'intérieur.$"

CharcoalKiln_Text_Boss2:
	.string "Les RAMOLOSS sont revenus…$"

CharcoalKiln_Text_Boss3:
	.string "Les RAMOLOSS sont revenus…\p"
	.string "Mais mon APPRENTI n'est pas encore\n"
	.string "revenu de la FORÊT DE CHÊNE.\p"
	.string "Où est donc passé ce fainéant ?$"

CharcoalKiln_Text_Boss4:
	.string "Tu as chassé la TEAM ROCKET et tu es\n"
	.string "allé dans la FORÊT DE CHÊNE tout seul ?\p"
	.string "Il faut du cran pour ça ! J'aime ça.\n"
	.string "Viens t'entraîner avec nous.$"

CharcoalKiln_Text_Apprentice1:
	.string "Où sont passés tous les RAMOLOSS ?\p"
	.string "Ils sont peut-être partis jouer quelque part ?$"

CharcoalKiln_Text_Apprentice2:
	.string "Les RAMOLOSS sont revenus !$"

CharcoalKiln_Text_Apprentice3:
	.string "Je suis désolé… J'ai oublié de te remercier.\p"
	.string "Voici du CHARBON que j'ai fabriqué.\p"
	.string "Les POKéMON de type FEU seraient ravis\n"
	.string "de tenir ça.$"

CharcoalKiln_Text_Apprentice4:
	.string "Les RAMOLOSS sont revenus, et tu as même\n"
	.string "retrouvé CANARTICHO.\p"
	.string "Tu es le meilleur, mec !$"

CharcoalKiln_Text_Farfetchd:
	.string "CANARTICHO : Kwaa !$"
