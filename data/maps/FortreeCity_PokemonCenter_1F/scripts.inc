.set LOCALID_NURSE, 1

FortreeCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

FortreeCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_FORTREE_CITY
	end

FortreeCity_PokemonCenter_1F_RhyperiorEvo::
	msgbox FortreeCity_PokemonCenter_1F_RhyperiorEvo_Text, MSGBOX_NPC
	end

FortreeCity_PokemonCenter_1F_RhyperiorEvo_Text:
	.string "RHYDON évolue par échange.\n"
	.string "Mais seulement s'il est échangé avec un objet.\p"
	.string "Quel objet, demandes-tu ?\p"
	.string "Eh bien… Ma mémoire n'est plus aussi bonne\n"
	.string "qu'il y a trente ans… C'était un…\l"
	.string "PIERRE… PIERRE… Ah.\p"
	.string "Je ne m'en souviens plus. Désolé.$"

FortreeCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

FortreeCity_PokemonCenter_1F_EventScript_Gentleman::
	msgbox FortreeCity_PokemonCenter_1F_Text_GoToSafariZone, MSGBOX_NPC
	end

FortreeCity_PokemonCenter_1F_EventScript_Man::
	msgbox FortreeCity_PokemonCenter_1F_Text_RecordCornerIsNeat, MSGBOX_NPC
	end

FortreeCity_PokemonCenter_1F_EventScript_Boy::
	msgbox FortreeCity_PokemonCenter_1F_Text_DoYouKnowAboutPokenav, MSGBOX_NPC
	end

FortreeCity_PokemonCenter_1F_Text_GoToSafariZone:
	.string "Dis-moi, gamin, tu travailles sur\n"
	.string "un POKéDEX ?\p"
	.string "Hmm… Va à la ZONE SAFARI.\n"
	.string "C'est mon conseil.$"

FortreeCity_PokemonCenter_1F_Text_RecordCornerIsNeat:
	.string "As-tu déjà fait quelque chose au\n"
	.string "COIN ENREGISTREMENT ?\p"
	.string "C'est plutôt sympa. Ça mélange et associe\n"
	.string "les données des DRESSEURS.\p"
	.string "Je ne sais pas trop comment ça marche,\n"
	.string "mais c'est cool. C'est même excitant ! $"

FortreeCity_PokemonCenter_1F_Text_DoYouKnowAboutPokenav:
	.string "Oh, waouh, tu as un POKéNAV !\n"
	.string "Et il est comme le mien !\p"
	.string "Tu connais le système\n"
	.string "APPEL MATCH du POKéNAV ?\p"
	.string "Accède-y, et tu peux discuter avec\n"
	.string "les DRESSEURS enregistrés à tout moment.\p"
	.string "Ça montre aussi quels DRESSEURS\n"
	.string "veulent un nouveau combat avec toi.\p"
	.string "C'est vraiment génial ! Ces gars de DEVON\n"
	.string "savent ce qu'ils font !$"

