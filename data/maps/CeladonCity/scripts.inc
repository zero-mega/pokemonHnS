.set LOCALID_CELADON_ERIKA, 15

CeladonCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeladonCity_EventScript_CityEnter
	.byte 0

CeladonCity_EventScript_CityEnter::
	setflag FLAG_VISITED_CELADON_CITY
	end

CeladonCity_EventScript_Erika::
    lock
    faceplayer
    msgbox CeladonCity_Text_Erika, MSGBOX_DEFAULT
    closemessage
    fadescreenswapbuffers FADE_TO_BLACK
    setflag FLAG_HIDE_FOUNTAIN_ERIKA
    removeobject LOCALID_CELADON_ERIKA
    fadescreenswapbuffers FADE_FROM_BLACK
    clearflag FLAG_HIDE_DOJO_ERIKA
    release
    end

CeladonCity_Text_Erika:
    .string "Oh, {PLAYER}.\n"
	.string "N'est-ce pas que la fontaine est belle aujourd'hui ?\p"
	.string "Si tu souhaites un autre combat,\n"
	.string "je serai au DOJO DE COMBAT.$"

CeladonCity_EventScript_Fatman::
	msgbox CeladonCity_Text_Fisher, MSGBOX_NPC
	end
CeladonCity_EventScript_Poliwrath::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_POLIWRATH, CRY_MODE_NORMAL
	msgbox CeladonCity_Text_Poliwrath, MSGBOX_DEFAULT
	waitmoncry
	release
	end

CeladonCity_EventScript_Teacher1::
	msgbox CeladonCity_Text_Teacher1, MSGBOX_NPC
	end

CeladonCity_EventScript_GrimerGramps::
	msgbox CeladonCity_Text_Gramps1, MSGBOX_NPC
	end

CeladonCity_EventScript_CreepGramps::
	msgbox CeladonCity_Text_Gramps2, MSGBOX_NPC
	end

CeladonCity_EventScript_Youngster::
	msgbox CeladonCity_Text_Youngster1, MSGBOX_NPC
	end

CeladonCity_EventScript_Youngster2::
	msgbox CeladonCity_Text_Youngster2, MSGBOX_NPC
	end

CeladonCity_EventScript_Teacher2::
	msgbox CeladonCity_Text_Teacher2, MSGBOX_NPC
	end

CeladonCity_EventScript_Lass::
	msgbox CeladonCity_Text_Lass, MSGBOX_NPC
	end

CeladonCity_Text_Fisher:
	.string "Ce TARTARD est mon partenaire.\p"
	.string "Je me demande s'il évoluera un jour\n"
	.string "en POKéMON grenouille.$"

CeladonCity_Text_Poliwrath:
	.string "TARTARD: Croac !$"

CeladonCity_Text_Teacher1:
	.string "J'ai encore perdu aux machines à sous…\p"
	.string "Nous les filles jouons aussi aux machines maintenant.\p"
	.string "Tu devrais y jeter un coup d'œil aussi.$"

CeladonCity_Text_Gramps1:
	.string "Des TADMORV apparaissent récemment.\p"
	.string "Tu vois cet étang devant la\n"
	.string "maison ? Les TADMORV y vivent maintenant.\p"
	.string "D'où viennent-ils ? C'est\n"
	.string "un problème sérieux…$"

CeladonCity_Text_Gramps2:
	.string "Nihihi ! Cette ARÈNE est géniale ! Seules\n"
	.string "les filles sont autorisées ici !$"

CeladonCity_Text_Youngster1:
	.string "Tu veux connaître un secret ?\p"
	.string "Le MANOIR CÉLADON a une porte arrière\n"
	.string "cachée.$"

CeladonCity_Text_Youngster2:
	.string "Ils organisent un concours de bouffe\n"
	.string "au restaurant.\p"
	.string "Rien qu'en les regardant, ça me\n"
	.string "donne l'impression d'être gonflé…$"

CeladonCity_Text_Teacher2:
	.string "Le MAGASIN CÉLADON a la plus grande\n"
	.string "et la meilleure sélection de marchandises.\p"
	.string "Si tu ne peux pas l'obtenir là-bas, tu\n"
	.string "ne peux l'obtenir nulle part.\p"
	.string "Bon sang… J'ai l'air d'une vendeuse.$"

CeladonCity_Text_Lass:
	.string "Regarder le sol pendant que je\n"
	.string "marchais m'a donné le vertige.$"

CeladonCity_EventScript_CitySign::
	msgbox CeladonCity_Text_Sign, MSGBOX_SIGN
	end

CeladonCity_EventScript_GymSign::
	msgbox CeladonGym_Text_Sign, MSGBOX_SIGN
	end

CeladonCity_EventScript_StoreSign::
	msgbox CeladonCity_Text_DeptStoreSign, MSGBOX_SIGN
	end

CeladonCity_EventScript_MansionSign::
	msgbox CeladonCity_Text_MansionSign, MSGBOX_SIGN
	end

CeladonCity_EventScript_GameCornerSign::
	msgbox CeladonCity_Text_GameCornerSign, MSGBOX_SIGN
	end

CeladonCity_EventScript_TrainerTips::
	msgbox CeladonCity_Text_TrainerTips, MSGBOX_SIGN
	end

CeladonCity_Text_Sign:
	.string "CÉLADON\p"
	.string "La Ville des Rêves Arc-en-Ciel$"

CeladonGym_Text_Sign:
	.string "CHAMPION DE L'ARÈNE POKéMON DE CÉLADON:\n"
	.string "ERIKA\p"
	.string "La Princesse Amoureuse de la Nature$"

CeladonCity_Text_DeptStoreSign:
	.string "Trouvez Ce Dont Vous Avez Besoin au\n"
	.string "MAGASIN CÉLADON !$"

CeladonCity_Text_MansionSign:
	.string "MANOIR CÉLADON$"

CeladonCity_Text_GameCornerSign:
	.string "Le Terrain de Jeu pour Tous--\n"
	.string "CASINO CÉLADON$"

CeladonCity_Text_TrainerTips:
	.string "CONSEILS DRESSEUR\p"
	.string "PROTÈGE-SPÉC. protège les POKéMON\n"
	.string "contre les attaques SPÉCIALES comme\n"
	.string "le feu et l'eau.\p"
	.string "Obtenez vos objets au MAGASIN\n"
	.string "CÉLADON !$"
