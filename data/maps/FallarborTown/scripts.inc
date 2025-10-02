FallarborTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FallarborTown_OnTransition
	.byte 0

FallarborTown_OnTransition:
	setflag FLAG_VISITED_ECRUTEAK_CITY
	setvar VAR_GARBAGEVAR, 0
	clearflag FLAG_CONTEST_SKETCH_CREATED
	end

FallarborTown_EventScript_ExpertM::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, FallarborTown_EventScript_ExpertMNormal
	msgbox FallarborTown_Text_ShadyCharactersCozmosHome, MSGBOX_DEFAULT
	release
	end

FallarborTown_EventScript_ExpertMNormal::
	msgbox FallarborTown_Text_RegionKnownForMeteors, MSGBOX_DEFAULT
	release
	end

FallarborTown_EventScript_Girl::
	msgbox FallarborTown_Text_MyPreciousAzurill, MSGBOX_NPC
	end

FallarborTown_EventScript_Gentleman::
	msgbox FallarborTown_Text_HaveYouChallengedFlannery, MSGBOX_NPC
	end

FallarborTown_EventScript_Azurill::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZURILL, CRY_MODE_NORMAL
	msgbox FallarborTown_Text_Azurill, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FallarborTown_EventScript_BattleTentSign::
	msgbox FallarborTown_Text_BattleTentSign, MSGBOX_SIGN
	end

FallarborTown_EventScript_TownSign::
	msgbox FallarborTown_Text_TownSign, MSGBOX_SIGN
	end

FallarborTown_EventScript_MoveTutorSign::
	msgbox FallarborTown_Text_MoveTutorSign, MSGBOX_SIGN
	end

FallarborTown_Text_ShadyCharactersCozmosHome:
	.string "Il se passe quelque chose,\n"
	.string "et ça ne me plaît pas !\p"
	.string "J'ai vu des individus louches entrer\n"
	.string "et sortir de la maison du PROF. COZMO…$"

FallarborTown_Text_RegionKnownForMeteors:
	.string "Cette région est connue pour ses météores\n"
	.string "depuis la nuit des temps.\p"
	.string "On dit que la CHUTE-MÉTÉORE a été creusée\n"
	.string "par une météorite tombée il y a longtemps.$"

FallarborTown_Text_MyPreciousAzurill:
	.string "Regarde ! Jette un œil !\n"
	.string "C'est mon précieux AZURILL !\p"
	.string "Il est lisse, doux et tout moelleux aussi !$"

FallarborTown_Text_Azurill:
	.string "AZURILL : Rooreelooo.$"

FallarborTown_Text_HaveYouChallengedFlannery:
	.string "As-tu déjà défié ADRIENNE,\n"
	.string "la CHAMPIONNE de l'ARÈNE de VERFEUILLE ?\p"
	.string "Le grand-père de cette fille était célèbre.\n"
	.string "Il a fait partie du CONSEIL 4 de la\l"
	.string "LIGUE POKéMON à une époque.\p"
	.string "Je ne serais pas surpris de voir ADRIENNE\n"
	.string "devenir une grande DRESSEUSE à son tour.$"

FallarborTown_Text_BattleTentSign:
	.string "CHAPITEAU DE COMBAT DE VERFEUILLE\n"
	.string "« Que les meilleures équipes se rassemblent ! »$"

FallarborTown_Text_TownSign:
	.string "VERFEUILLE\n"
	.string "« Une communauté agricole avec de petits jardins. »$"

FallarborTown_Text_MoveTutorSign:
	.string "MAISON DU MAÎTRE DES CAPACITÉS\n"
	.string "« De nouvelles capacités enseignées aux POKéMON. »$"
