.set LOCALID_SSAQUA_B1F_SAILORLOOKING, 10

SSAqua_B1F_MapScripts::
	.byte 0

SSAqua_B1F_EventScript_Trigger::
	lock
	turnobject LOCALID_SSAQUA_B1F_SAILORLOOKING, DIR_EAST
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	msgbox SSAqua_B1F_Text_FastShipOnDutySailor, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown1
	waitmovement 0 
	turnobject LOCALID_SSAQUA_B1F_SAILORLOOKING, DIR_SOUTH
	release
	end

SSAqua_B1F_EventScript_SailorLookingForBuddy::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_SSAQUA_SAILOR, SSAqua_B1F_EventScript_SailorLookingFoundBuddy
	msgbox SSAqua_B1F_Text_FastShipOnDutySailor, MSGBOX_DEFAULT
	closemessage
	release
	end

SSAqua_B1F_EventScript_SailorLookingFoundBuddy::
	msgbox SSAqua_B1F_Text_FastShipOnDutySailorThanks, MSGBOX_DEFAULT
	goto_if_lt VAR_SSAQUA_STATE, 5, SSAqua_B1F_EventScript_SailorGirl
	closemessage
	release
	end
SSAqua_B1F_EventScript_SailorGirl::
	msgbox SSAqua_B1F_Text_FastShipOnDutySailorSawGirl, MSGBOX_DEFAULT
	closemessage
	release
	end

SSAqua_B1F_EventScript_SleepySailor::
	msgbox SSAqua_B1F_Text_FastShipOnDutySailorDirections, MSGBOX_NPC
	end

SSAqua_B1F_EventScript_Barfcan::
	msgbox SSAqua_B1F_Text_BarfCan, MSGBOX_SIGN
	end

SSAqua_B1F_Text_BarfCan:
    .string "Beurk !\n"
    .string "J'aurais pas dû regarder !$"

SSAqua_B1F_Text_FastShipOnDutySailor:
	.string "Hé, gamin. Tu pourrais aller\n"
	.string "chercher mon collègue ?\p"
	.string "Il traîne quelque part,\n"
	.string "ce fainéant !\p"
	.string "Je voudrais aller le chercher,\n"
	.string "mais je suis de garde.$"

SSAqua_B1F_Text_FastShipOnDutySailorRefused:
	.string "Oh, mince…\p"
	.string "Le CAPITAINE va être furieux…$"

SSAqua_B1F_Text_FastShipOnDutySailorThanks:
	.string "Merci, gamin ! Je lui ai passé\n"
	.string "un savon, il va arrêter de glander !$"

SSAqua_B1F_Text_FastShipOnDutySailorSawGirl:
	.string "Une petite fille ?\p"
	.string "Je crois l'avoir vue passer ici.$"

SSAqua_B1F_Text_FastShipOnDutySailorDirections:
	.string "La salle à manger est juste devant.\p"
	.string "Les escaliers au bout mènent à la\n"
	.string "cabine du CAPITAINE.$"

SSAqua_B1F_EventScript_Jeff::
	trainerbattle_single TRAINER_JEFF SSAqua_B1F_Text_SailorJeffSeen, SSAqua_B1F_Text_SailorJeffBeaten
	msgbox SSAqua_B1F_Text_SailorJeffAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_SailorJeffSeen:
	.string "Rien de tel qu'un combat\n"
	.string "pendant ma pause !$"

SSAqua_B1F_Text_SailorJeffBeaten:
	.string "Gagné ou perdu, ma pause est finie !$"

SSAqua_B1F_Text_SailorJeffAfter:
	.string "Je ne peux pas gagner si je ne\n"
	.string "me donne pas à fond.$"

SSAqua_B1F_EventScript_Debra::
	trainerbattle_single TRAINER_DEBRA SSAqua_B1F_Text_PicnickerDebraSeen, SSAqua_B1F_Text_PicnickerDebraBeaten
	msgbox SSAqua_B1F_Text_PicnickerDebraAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_PicnickerDebraSeen:
	.string "Je m'ennuie trop. Tu veux te battre ?$"

SSAqua_B1F_Text_PicnickerDebraBeaten:
	.string "Ouille ! Tu es trop fort !$"

SSAqua_B1F_Text_PicnickerDebraAfter:
	.string "SAFRANIA, CELADOPOLE… J'ai entendu\n"
	.string "dire qu'il y a de grandes villes à KANTO.$"

SSAqua_B1F_EventScript_Fritz::
	trainerbattle_single TRAINER_FRITZ SSAqua_B1F_Text_JugglerFritzSeen, SSAqua_B1F_Text_JugglerFritzBeaten
	msgbox SSAqua_B1F_Text_JugglerFritzAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_JugglerFritzSeen:
	.string "Beurk… J'ai le mal de mer !$"

SSAqua_B1F_Text_JugglerFritzBeaten:
	.string "Je ne peux plus bouger…$"

SSAqua_B1F_Text_JugglerFritzAfter:
	.string "Plus jamais de bateaux pour moi.\n"
	.string "La prochaine fois,\p"
	.string "je prendrai le TRAIN MAGNÉTIQUE.$"

SSAqua_B1F_EventScript_Garrett::
	trainerbattle_single TRAINER_GARRETT SSAqua_B1F_Text_SailorGarrettSeen, SSAqua_B1F_Text_SailorGarrettBeaten
	msgbox SSAqua_B1F_Text_SailorGarrettAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_SailorGarrettSeen:
	.string "C'est ici que nous, les marins, travaillons !$"

SSAqua_B1F_Text_SailorGarrettBeaten:
	.string "J'ai perdu sur mon propre terrain…$"

SSAqua_B1F_Text_SailorGarrettAfter:
	.string "Nous avons des passagers différents\n"
	.string "entre CARMIN SUR MER et\p"
	.string "OLIVILLE.$"

SSAqua_B1F_EventScript_Jonah::
	trainerbattle_single TRAINER_JONAH SSAqua_B1F_Text_FisherJonahSeen, SSAqua_B1F_Text_FisherJonahBeaten
	msgbox SSAqua_B1F_Text_FisherJonahAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_FisherJonahSeen:
	.string "Même en étant en mer,\n"
	.string "je ne peux pas pêcher !\p"
	.string "C'est ennuyeux ! Combattons !$"

SSAqua_B1F_Text_FisherJonahBeaten:
	.string "Je… Je ne m'ennuie plus…$"

SSAqua_B1F_Text_FisherJonahAfter:
	.string "Je compte pêcher sur le quai\n"
	.string "de CARMIN SUR MER.$"

SSAqua_B1F_EventScript_Wai::
	trainerbattle_single TRAINER_WAI SSAqua_B1F_Text_BlackbeltWaiSeen, SSAqua_B1F_Text_BlackbeltWaiBeaten
	msgbox SSAqua_B1F_Text_BlackbeltWaiAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_BlackbeltWaiSeen:
	.string "Je me muscle les jambes en\n"
	.string "résistant\p"
	.string "au tangage du bateau !$"

SSAqua_B1F_Text_BlackbeltWaiBeaten:
	.string "J'ai été secoué et mis K.O. !$"

SSAqua_B1F_Text_BlackbeltWaiAfter:
	.string "Je n'ai pas trouvé le MAÎTRE KARATÉ\n"
	.string "à JOHTO.\p"
	.string "Il s'entraînerait dans une grotte\n"
	.string "quelque part.$"

SSAqua_B1F_EventScript_Kenneth::
	trainerbattle_single TRAINER_KENNETH SSAqua_B1F_Text_SailorKennethSeen, SSAqua_B1F_Text_SailorKennethBeaten
	msgbox SSAqua_B1F_Text_SailorKennethAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_SailorKennethSeen:
	.string "Je suis marin !\p"
	.string "Mais j'entraîne mes POKéMON pour\n"
	.string "devenir le MAÎTRE !$"

SSAqua_B1F_Text_SailorKennethBeaten:
	.string "Mon manque d'entraînement se voit…$"

SSAqua_B1F_Text_SailorKennethAfter:
	.string "Huit BADGES ! Ça prouve que tu as\n"
	.string "battu les\p"
	.string "CHAMPIONS d'ARÈNE.\p"
	.string "Pas étonnant que tu sois si fort !$"

SSAqua_B1F_EventScript_Shirley::
	trainerbattle_single TRAINER_SHIRLEY SSAqua_B1F_Text_TeacherShirleySeen, SSAqua_B1F_Text_TeacherShirleyBeaten
	msgbox SSAqua_B1F_Text_TeacherShirleyAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_TeacherShirleySeen:
	.string "Ne touche pas à mes élèves !$"

SSAqua_B1F_Text_TeacherShirleyBeaten:
	.string "Aaaah !$"

SSAqua_B1F_Text_TeacherShirleyAfter:
	.string "Nous sommes en sortie scolaire\n"
	.string "aux RUINES près de MAUVILLE.$"

SSAqua_B1F_EventScript_Nate::
	trainerbattle_single TRAINER_NATE SSAqua_B1F_Text_SchoolboyNateSeen, SSAqua_B1F_Text_SchoolboyNateBeaten
	msgbox SSAqua_B1F_Text_SchoolboyNateAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_SchoolboyNateSeen:
	.string "Tu connais les RUINES D'ALPHA ?$"

SSAqua_B1F_Text_SchoolboyNateBeaten:
	.string "Aaargh !$"

SSAqua_B1F_Text_SchoolboyNateAfter:
	.string "La radio capte d'étranges signaux\n"
	.string "dans les RUINES.$"

SSAqua_B1F_EventScript_Ricky::
	trainerbattle_single TRAINER_RICKY SSAqua_B1F_Text_SchoolboyRickySeen, SSAqua_B1F_Text_SchoolboyRickyBeaten
	msgbox SSAqua_B1F_Text_SchoolboyRickyAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_SchoolboyRickySeen:
	.string "Il y a d'étranges panneaux de pierre\n"
	.string "dans les RUINES D'ALPHA.$"

SSAqua_B1F_Text_SchoolboyRickyBeaten:
	.string "J'ai perdu !$"

SSAqua_B1F_Text_SchoolboyRickyAfter:
	.string "J'ai lu qu'il y a quatre de ces\n"
	.string "panneaux de pierre.$"
