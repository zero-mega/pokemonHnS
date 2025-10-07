.set LOCALID_FOSSIL_MANIAC, 1

Route114_FossilManiacsTunnel_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route114_FossilManiacsTunnel_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, Route114_FossilManiacsTunnel_OnLoad
	.byte 0

Route114_FossilManiacsTunnel_OnTransition:
	call_if_set FLAG_SYS_GAME_CLEAR, Route114_FossilManiacsTunnel_EventScript_MoveFossilManiac
	end

Route114_FossilManiacsTunnel_EventScript_MoveFossilManiac::
	setobjectxyperm LOCALID_FOSSIL_MANIAC, 6, 5
	setobjectmovementtype LOCALID_FOSSIL_MANIAC, MOVEMENT_TYPE_FACE_DOWN
	return

Route114_FossilManiacsTunnel_OnLoad:
	call_if_unset FLAG_SYS_GAME_CLEAR, Route114_FossilManiacsTunnel_EventScript_CloseDesertUnderpass
	end

Route114_FossilManiacsTunnel_EventScript_CloseDesertUnderpass::
	setmetatile 6, 1, METATILE_Fallarbor_RedRockWall, TRUE
	setmetatile 6, 2, METATILE_Fallarbor_RedRockWall, TRUE
	return

Route114_FossilManiacsTunnel_EventScript_ManiacMentionCaveIn::
	lockall
	applymovement LOCALID_FOSSIL_MANIAC, Common_Movement_WalkInPlaceFasterUp
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox Route114_FossilManiacsTunnel_Text_NotSafeThatWay, MSGBOX_DEFAULT
	setvar VAR_FOSSIL_MANIAC_STATE, 2
	releaseall
	end

Route114_FossilManiacsTunnel_EventScript_FossilManiac::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_REVIVED_FOSSIL_MON, Route114_FossilManiacsTunnel_EventScript_PlayerRevivedFossil
	checkitem ITEM_ROOT_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, Route114_FossilManiacsTunnel_EventScript_PlayerHasFossil
	checkitem ITEM_CLAW_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, Route114_FossilManiacsTunnel_EventScript_PlayerHasFossil
	msgbox Route114_FossilManiacsTunnel_Text_LookInDesertForFossils, MSGBOX_DEFAULT
	release
	end

Route114_FossilManiacsTunnel_EventScript_PlayerHasFossil::
	msgbox Route114_FossilManiacsTunnel_Text_DevonCorpRevivingFossils, MSGBOX_DEFAULT
	release
	end

Route114_FossilManiacsTunnel_EventScript_PlayerRevivedFossil::
	msgbox Route114_FossilManiacsTunnel_Text_FossilsAreWonderful, MSGBOX_DEFAULT
	release
	end

Route114_FossilManiacsTunnel_Text_LookInDesertForFossils:
	.string "Je suis le MANIAQUE DES FOSSILES…\n"
	.string "Je suis un gars sympa qui adore les FOSSILES…\p"
	.string "Tu veux un FOSSILE ?\p"
	.string "Mais les FOSSILES d'ici m'appartiennent\n"
	.string "tous… Aucun pour toi…\p"
	.string "Si tu ne peux pas te passer d'un FOSSILE,\n"
	.string "cherche dans un désert où il y a des rochers\l"
	.string "et du sable qui pourraient cacher des\l"
	.string "FOSSILES…$"

Route114_FossilManiacsTunnel_Text_DevonCorpRevivingFossils:
	.string "Tu as trouvé un FOSSILE, n'est-ce pas ?\n"
	.string "C'est super… C'est tellement merveilleux…\p"
	.string "Qu'est-ce que tu vas faire avec ce\n"
	.string "FOSSILE ?\p"
	.string "D'après ce que j'ai entendu, DEVON fait\n"
	.string "des recherches pour ressusciter des POKéMON\l"
	.string "à partir de FOSSILES…\p"
	.string "J'aime trop mes FOSSILES, alors je ne ferais\n"
	.string "jamais quelque chose comme ça…$"

Route114_FossilManiacsTunnel_Text_FossilsAreWonderful:
	.string "Les FOSSILES sont si… Merveilleux…\n"
	.string "C'est tellement merveilleux…$"

Route114_FossilManiacsTunnel_Text_NotSafeThatWay:
	.string "Oh…\n"
	.string "Ce n'est pas sûr par là…\p"
	.string "Je creusais, tu vois…\n"
	.string "Quand tout le mur s'est effondré…\p"
	.string "Je pense qu'il y a maintenant une énorme\n"
	.string "caverne en dessous…\p"
	.string "Mais je l'ai laissée tranquille car je ne\n"
	.string "pense pas qu'il y ait de FOSSILES là-bas…$"
