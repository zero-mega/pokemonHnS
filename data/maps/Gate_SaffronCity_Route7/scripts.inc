Gate_SaffronCity_Route7_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SaffronCity_OnFrame
	.byte 0

Gate_SaffronCity_Route7_EventScript_Guard::
	goto_if_set FLAG_RETURNED_MACHINE_PART, Gate_SaffronCity_Route7_EventScript_GuardReturnedPart
	msgbox Route7_Text_SaffronGuard_PowerPlant, MSGBOX_NPC
	end

Gate_SaffronCity_Route7_EventScript_GuardReturnedPart::
	msgbox Route7_Text_SaffronGuard_Serious, MSGBOX_NPC
	end

Route7_Text_SaffronGuard_PowerPlant:
	.string "As-tu entendu parler de l'accident\n"
	.string "à la CENTRALE ÉLECTRIQUE ?\p"
	.string "Elle se trouve à l'est, près\n"
	.string "de LAVANVILLE.$"

Route7_Text_SaffronGuard_Serious:
	.string "Je prends mon travail de GARDE au sérieux.\p"
	.string "Hé ! Tu as un POKéDEX.\p"
	.string "OK. Tu peux passer.$"
