Gate_SaffronCity_Route6_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SaffronCity_OnFrame
	.byte 0

Gate_SaffronCity_Route6_EventScript_Guard::
	goto_if_eq VAR_TEMP_0, 1, Gate_SaffronCity_Route6_EventScript_Guard2
	msgbox Route6_Text_SaffronGuardWelcome, MSGBOX_NPC
	setvar VAR_TEMP_0, 1
	end
Gate_SaffronCity_Route6_EventScript_Guard2::
	msgbox Route6_Text_SaffronGuardMagnetTrain, MSGBOX_NPC
	end

Route6_Text_SaffronGuardWelcome:
	.string "Bienvenue à SAFRANIA, la ville du\n"
	.string "MAGNET TRAIN !\p"
	.string "…C'est ce que je dirais d'habitude,\n"
	.string "mais le MAGNET TRAIN ne\l"
	.string "fonctionne pas en ce moment.\p"
	.string "Il ne reçoit pas d'électricité\n"
	.string "car il y a un problème\l"
	.string "à la CENTRALE ÉLECTRIQUE.$"

Route6_Text_SaffronGuardMagnetTrain:
	.string "Le MAGNET TRAIN est la chose la plus\n"
	.string "célèbre de SAFRANIA.$"
