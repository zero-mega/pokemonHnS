.set LOCALID_ROUTE24_WOMAN, 4
.set LOCALID_ROUTE24_MAN, 3
.set LOCALID_ROUTE24_GRUNT, 1

Route24_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route24_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route24_OnTransition:
	call_if_eq VAR_KANTO_ROCKET_STORY_STATE, 4, Route24_MapScript_SetRocketScene
	callnative SetTimeBasedEncounters
	end

Route24_MapScript_SetRocketScene:
	setobjectxyperm LOCALID_ROUTE24_GRUNT, 10, 28
	setobjectxyperm LOCALID_ROUTE24_WOMAN, 10, 29
	setobjectmovementtype LOCALID_ROUTE24_GRUNT, MOVEMENT_TYPE_FACE_LEFT
	setobjectmovementtype LOCALID_ROUTE24_WOMAN, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype LOCALID_ROUTE24_MAN, MOVEMENT_TYPE_FACE_DOWN
	return

Route24_EventScript_Woman::
	goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 4, Route24_EventScript_WomanRocket
	goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 5, Route24_EventScript_WomanAfterRocket
	msgbox Route24_Text_Woman, MSGBOX_NPC
	end

Route24_EventScript_WomanRocket::
	msgbox Route24_Text_WomanRocket, MSGBOX_NPC
	end

Route24_EventScript_WomanAfterRocket::
	msgbox Route24_Text_WomanAfterRocket, MSGBOX_NPC
	end

Route24_EventScript_Man::
	goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 4, Route24_EventScript_ManRocket
		goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 5, Route24_EventScript_ManAfterRocket
	msgbox Route24_Text_Man, MSGBOX_NPC
	end

Route24_EventScript_ManRocket::
	msgbox Route24_Text_ManRocket, MSGBOX_NPC
	end

Route24_EventScript_ManAfterRocket::
	msgbox Route24_Text_ManAfterRocket, MSGBOX_NPC
	end

Route24_Trigger_GruntScene::
	lock
	playse SE_PIN
	applymovement2 LOCALID_ROUTE24_GRUNT Common_Movement_ExclamationMark
	delay 60
	applymovement2 LOCALID_ROUTE24_GRUNT, Route24_Movement_GruntHide
	delay 10
	applymovement2 LOCALID_ROUTE24_WOMAN, Route24_Movement_WomanMove
	waitmovement 0
	turnobject LOCALID_ROUTE24_MAN, DIR_SOUTH
	setvar VAR_KANTO_ROCKET_STORY_STATE, 4
	call Route24_MapScript_SetRocketScene
	release
	end

Route24_Movement_GruntHide:
	walk_fast_left
	walk_fast_left
	step_end

Route24_Movement_WomanMove:
	lock_facing_direction
	walk_fast_down
	unlock_facing_direction
	face_up
	step_end

Route24_EventScript_Grunt::
	lock
	faceplayer
	msgbox Route24_Text_RocketSeen, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_31, Route24_Text_RocketBeaten
	msgbox Route24_Text_RocketAfter, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement2 FLAG_HIDE_CERULEAN_CAPE_ROCKET, Common_Movement_QuestionMark
	delay 50
	msgbox Route24_Text_RocketDisappears, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Route24_Movement_PlayerSlide
	delay 20
	applymovement LOCALID_ROUTE24_GRUNT, Route24_Movement_GruntLeave
	waitmovement LOCALID_ROUTE24_GRUNT
	setflag FLAG_HIDE_CERULEAN_CAPE_ROCKET
	removeobject LOCALID_ROUTE24_GRUNT
	setvar VAR_KANTO_ROCKET_STORY_STATE, 5
	clearflag FLAG_HIDDEN_ITEM_MACHINE_PART
	release
	end

Route24_Movement_PlayerSlide:
	delay_16
	lock_facing_direction
	walk_fast_up
	unlock_facing_direction
	face_down
	step_end

Route24_Movement_GruntLeave:
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

Route24_Text_RocketSeen:
	.string "Hé, gamin ! Moi être un gars de\n"
	.string "la TEAM ROCKET !\p"
	.string "Venir d’un autre pays, moi être\n"
	.string "dresseur numéro un !\p"
	.string "Penser moi, si arrêter énergie,\n"
	.string "grosse panique pour gens ici !\p"
	.string "Secret c’est ma mission, alors\n"
	.string "dire à toi je ne fais pas !\p"
	.string "Mais ! Si toi gagner contre moi,\n"
	.string "homme je serai et mon secret à\l"
	.string "toi je dirai.\p"
	.string "Hé, gamin ! Combat commencer on fait !$"

Route24_Text_RocketBeaten:
	.string "Ayieeeh ! Non, non, non, croire\n"
	.string "je ne peux pas !\p"
	.string "Très fort tu es ! Match pour toi\n"
	.string "je ne suis pas !$"

Route24_Text_RocketAfter:
	.string "OK. Dire à toi mon secret je vais.\n"
	.string "PIÈCE MACHINE volée par moi, cachée\l"
	.string "je l’ai dans l’ARÈNE de CELADOPOLE.\p"
	.string "Dans l’eau je l’ai mise. Cherche\n"
	.string "au centre de l’eau dans l’ARÈNE.\p"
	.string "Mais toi, m’oublier tu ne dois pas !\p"
	.string "Battre toi sûrement la TEAM\n"
	.string "ROCKET va !\p"
	.string "Venir de JOHTO ils vont, mes\n"
	.string "amis, oui. Vengeance ils\l"
	.string "prendront.$"

Route24_Text_RocketDisappears:
	.string "…\p"
	.string "Tu dis quoi ? TEAM ROCKET bye-\n"
	.string "bye a go-go ? Cassée elle est,\l"
	.string "tu dis ?\p"
	.string "Oh, non ! Que faire maintenant\n"
	.string "moi dois ?$"



Route24_Text_Woman:
	.string "N’est-ce pas une vue magnifique ?$"
Route24_Text_Man:
	.string "Je pourrais rester ici toute la journée.$"

Route24_Text_WomanRocket:
	.string "Personne ne me pousse !$"
Route24_Text_ManRocket:
	.string "Personne ne pousse ma copine !$"

Route24_Text_WomanAfterRocket:
	.string "Qu’est-ce que c’était que ça ?$"
Route24_Text_ManAfterRocket:
	.string "C’était une ROCKET ?$"