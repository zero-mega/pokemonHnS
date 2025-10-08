SSAqua_RoomSW_MapScripts::
	.byte 0

SSAqua_RoomSW_EventScript_Cassie::
	trainerbattle_single TRAINER_CASSIE SSAqua_RoomSW_Text_BeautyCassieSeen, SSAqua_RoomSW_Text_BeautyCassieBeaten
	msgbox SSAqua_RoomSW_Text_BeautyCassieAfterBattle, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomSW_EventScript_Clyde::
	trainerbattle_single TRAINER_CLYDE SSAqua_RoomSW_Text_GuitaristClydeSeen, SSAqua_RoomSW_Text_GuitaristClydeBeaten
	msgbox SSAqua_RoomSW_Text_GuitaristClydeAfterBattle, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomSW_Text_BeautyCassieSeen:
    .string "J'essaie d'oublier mes peines.\n"
    .string "Combattons !$"

SSAqua_RoomSW_Text_BeautyCassieBeaten:
    .string "Mon cœur pleure…$"

SSAqua_RoomSW_Text_BeautyCassieAfterBattle:
    .string "Un voyage est idéal pour oublier\n"
    .string "un chagrin d'amour.\p"
    .string "Mais une traversée en LÉVIATOR\n"
    .string "EXPRESS est trop courte pour ça.$"

SSAqua_RoomSW_Text_GuitaristClydeSeen:
    .string "Je vais auditionner mes chansons\n"
    .string "à la STATION RADIO de DOUBLONVILLE.$"

SSAqua_RoomSW_Text_GuitaristClydeBeaten:
    .string "Ouille ! Distorsion totale !$"

SSAqua_RoomSW_Text_GuitaristClydeAfterBattleMobile:
    .string "Je voulais faire mes débuts à la\n"
    .string "TOUR BATAILLE…\p"
    .string "Je devrais retourner à CARAMELARBRE\n"
    .string "pour m'entraîner à nouveau…$"

SSAqua_RoomSW_Text_GuitaristClydeAfterBattle:
    .string "À propos de la STATION RADIO,\n"
    .string "quel est le numéro chanceux cette semaine ?$"
