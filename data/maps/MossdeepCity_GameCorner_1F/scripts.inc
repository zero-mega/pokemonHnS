MossdeepCity_GameCorner_1F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MossdeepCity_GameCorner_1F_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, MossdeepCity_GameCorner_1F_OnWarp
	map_script MAP_SCRIPT_ON_LOAD, CableClub_OnLoad
	.byte 0

MossdeepCity_GameCorner_1F_OnWarp:
	map_script_2 VAR_CABLE_CLUB_STATE, USING_MINIGAME, CableClub_EventScript_CheckTurnAttendant
	.2byte 0

MossdeepCity_GameCorner_1F_OnFrame:
	map_script_2 VAR_CABLE_CLUB_STATE, USING_MINIGAME, CableClub_EventScript_ExitMinigameRoom
	.2byte 0

@ Script is redundant, the label in the goto also does lock and faceplayer
MossdeepCity_GameCorner_1F_EventScript_InfoMan::
	lock
	faceplayer
	goto MossdeepCity_GameCorner_1F_EventScript_InfoMan2
	release
	end

@ Script is redundant, the label in the goto also does lock and faceplayer
MossdeepCity_GameCorner_1F_EventScript_OldMan::
	lock
	faceplayer
	goto MossdeepCity_GameCorner_1F_EventScript_OldMan2
	release
	end


@ Everything below is leftover from RS
@ The house that was here in RS was moved to Sootopolis and replaced by the Game Corner
@ The text below is unused and duplicated in its replacement in Sootopolis City
@ And the BG Door event was moved inaccessibly into a wall

RS_MysteryEventsHouse_EventScript_Door::
	msgbox RS_MysteryEventsHouse_Text_DoorIsLocked, MSGBOX_SIGN
	end

RS_MysteryEventsHouse_Text_OldManGreeting:
	.string "Quand j'étais jeune, j'ai parcouru le monde\n"
	.string "en tant que DRESSEUR de POKéMON.\p"
	.string "Maintenant que je suis devenu un vieux bougon,\n"
	.string "mon seul plaisir est de regarder les jeunes\l"
	.string "DRESSEURS s'affronter.$"

RS_MysteryEventsHouse_Text_DoorIsLocked:
	.string "La porte semble être verrouillée.$"

RS_MysteryEventsHouse_Text_ChallengeVisitingTrainer:
	.string "Un DRESSEUR nommé {STR_VAR_1} est\n"
	.string "en visite chez moi.\p"
	.string "Voulez-vous défier\n"
	.string "{STR_VAR_1} ?$"

RS_MysteryEventsHouse_Text_YouWontBattle:
	.string "Vous ne voulez pas combattre ? Je suis déçu\n"
	.string "de ne pas pouvoir vous voir vous battre…$"

RS_MysteryEventsHouse_Text_KeepItToA3On3:
	.string "Ah, très bien, très bien !\p"
	.string "Mais ma maison n'est pas très solide.\p"
	.string "Pourriez-vous limiter le combat à\n"
	.string "un match en 3 contre 3 ?$"

RS_MysteryEventsHouse_Text_SaveYourProgress:
	.string "Avant de vous affronter, vous devriez\n"
	.string "sauvegarder votre progression.$"

RS_MysteryEventsHouse_Text_HopeToSeeAGoodMatch:
	.string "J'espère voir un beau combat !$"

RS_MysteryEventsHouse_Text_BattleTie:
	.string "Alors, c'est resté bloqué.\p"
	.string "C'était un match brillant où\n"
	.string "aucun des deux n'a cédé !$"

RS_MysteryEventsHouse_Text_BattleWon:
	.string "C'était superbe !\p"
	.string "On aurait dit que je me voyais\n"
	.string "dans ma jeunesse !$"

RS_MysteryEventsHouse_Text_BattleLost:
	.string "Ah, dommage pour vous !\p"
	.string "Mais c'était un beau combat.\n"
	.string "J'espère que vous gagnerez la prochaine fois.$"
