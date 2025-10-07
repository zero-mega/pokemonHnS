.set LOCALID_WALLYS_DAD, 1

PetalburgCity_WallysHouse_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PetalburgCity_WallysHouse_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PetalburgCity_WallysHouse_OnWarp
	.byte 0

PetalburgCity_WallysHouse_OnWarp:
	map_script_2 VAR_GARBAGEVAR, 4, PetalburgCity_WallysHouse_EventScript_PlayerWallysDadFaceEachOther
	.2byte 0

PetalburgCity_WallysHouse_EventScript_PlayerWallysDadFaceEachOther::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	turnobject LOCALID_WALLYS_DAD, DIR_WEST
	end

PetalburgCity_WallysHouse_OnFrame:
	map_script_2 VAR_GARBAGEVAR, 4, PetalburgCity_WallysHouse_EventScript_GiveHMSurf
	.2byte 0

PetalburgCity_WallysHouse_EventScript_GiveHMSurf::
	lockall
	msgbox PetalburgCity_WallysHouse_Text_PleaseExcuseUs, MSGBOX_DEFAULT
	giveitem ITEM_HM_SURF
	setflag FLAG_RECEIVED_HM_SURF
	msgbox PetalburgCity_WallysHouse_Text_SurfGoAllSortsOfPlaces, MSGBOX_DEFAULT
	setvar VAR_GARBAGEVAR, 5
	releaseall
	end

PetalburgCity_WallysHouse_EventScript_WallysDad::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_WALLY_VICTORY_ROAD, PetalburgCity_WallysHouse_EventScript_DefeatedWallyInVictoryRoad
	goto_if_set FLAG_RECEIVED_HM_SURF, PetalburgCity_WallysHouse_EventScript_ReceievedHMSurf
	goto_if_set FLAG_THANKED_FOR_PLAYING_WITH_WALLY, PetalburgCity_WallysHouse_EventScript_PlayedWithWally
	msgbox PetalburgCity_WallysHouse_Text_ThanksForPlayingWithWally, MSGBOX_DEFAULT
	setflag FLAG_THANKED_FOR_PLAYING_WITH_WALLY
	release
	end

PetalburgCity_WallysHouse_EventScript_ReceievedHMSurf::
	msgbox PetalburgCity_WallysHouse_Text_WallyIsComingHomeSoon, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_DefeatedWallyInVictoryRoad::
	msgbox PetalburgCity_WallysHouse_Text_YouMetWallyInEverGrandeCity, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_PlayedWithWally::
	msgbox PetalburgCity_WallysHouse_Text_WonderHowWallyIsDoing, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_WallysMom::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_SURF, PetalburgCity_WallysHouse_EventScript_ReceivedHMSurf
	msgbox PetalburgCity_WallysHouse_Text_WallyWasReallyHappy, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_ReceivedHMSurf::
	msgbox PetalburgCity_WallysHouse_Text_WallyLeftWithoutTelling, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_Text_ThanksForPlayingWithWally:
	.string "Tu es…\n"
	.string "Ah, tu dois être {PLAYER}{KUN}, n'est-ce pas ?\p"
	.string "Merci d'avoir joué avec WALLY\n"
	.string "il y a quelque temps.\p"
	.string "Il a été fragile et malade\n"
	.string "depuis qu'il est bébé.\p"
	.string "Nous l'avons envoyé chez mes parents\n"
	.string "à VERGAZON pour un moment.\p"
	.string "L'air y est bien plus pur\n"
	.string "qu'ici.\p"
	.string "Quoi ? Où est WALLY ?\n"
	.string "Il est déjà parti, notre WALLY.\p"
	.string "Je me demande où il a bien pu\n"
	.string "aller maintenant.$"

PetalburgCity_WallysHouse_Text_WonderHowWallyIsDoing:
	.string "Je me demande comment va notre WALLY.$"

PetalburgCity_WallysHouse_Text_PleaseExcuseUs:
	.string "{PLAYER}{KUN} ! Excuse-nous de t'avoir\n"
	.string "fait venir ainsi.\p"
	.string "Mais notre WALLY est devenu très en\n"
	.string "forme depuis qu'il est à VERGAZON.\p"
	.string "C'est grâce à toi !\p"
	.string "Quand WALLY a quitté la ville, tu l'as\n"
	.string "aidé à attraper un POKéMON, non ?\p"
	.string "Je pense que ça a vraiment rendu\n"
	.string "WALLY heureux.\p"
	.string "En fait, pas seulement WALLY.\n"
	.string "Moi, son père, j'étais heureux aussi.\p"
	.string "Heureux qu'il ait un si bon ami\n"
	.string "comme toi.\p"
	.string "Ce n'est pas un pot-de-vin ou quoi,\n"
	.string "mais j'aimerais vraiment que tu prennes ça.$"

PetalburgCity_WallysHouse_Text_SurfGoAllSortsOfPlaces:
	.string "Si ton POKéMON peut utiliser SURF, tu\n"
	.string "pourras aller dans plein d'endroits.$"

PetalburgCity_WallysHouse_Text_WallyIsComingHomeSoon:
	.string "WALLY va bientôt rentrer à la maison.\n"
	.string "J'ai hâte de le revoir.$"

PetalburgCity_WallysHouse_Text_YouMetWallyInEverGrandeCity:
	.string "Oh ? Tu as rencontré WALLY à\n"
	.string "EVER GRANDE ?\p"
	.string "Oh, {PLAYER}{KUN}, ne dis pas de bêtises.\p"
	.string "Il est peut-être en meilleure santé, mais\n"
	.string "il ne peut pas aller si loin tout seul.$"

PetalburgCity_WallysHouse_Text_WallyWasReallyHappy:
	.string "WALLY était vraiment heureux quand il\n"
	.string "nous a dit qu'il avait attrapé un POKéMON.\p"
	.string "Ça faisait longtemps que je ne l'avais\n"
	.string "pas vu sourire comme ça.$"

PetalburgCity_WallysHouse_Text_WallyLeftWithoutTelling:
	.string "Je veux que tu gardes ça secret\n"
	.string "pour mon mari…\p"
	.string "Mais notre WALLY a quitté VERGAZON\n"
	.string "sans prévenir personne.\p"
	.string "Tu sais, WALLY est fragile, mais\n"
	.string "il a une volonté surprenante.\p"
	.string "Je suis sûr qu'il reviendra sain et\n"
	.string "sauf un jour !$"
