.set LOCALID_GRUNT, 1

SeafloorCavern_Entrance_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, SeafloorCavern_Entrance_OnResume
	.byte 0

SeafloorCavern_Entrance_OnResume:
	setdivewarp MAP_UNDERWATER_SEAFLOOR_CAVERN, 6, 5
	setescapewarp MAP_UNDERWATER_SEAFLOOR_CAVERN, 6, 5
	end

SeafloorCavern_Entrance_EventScript_Grunt::
	lockall
	goto_if_eq VAR_HAS_TALKED_TO_SEAFLOOR_CAVERN_ENTRANCE_GRUNT, 1, SeafloorCavern_Entrance_EventScript_GruntSpeechShort
	waitse
	playse SE_PIN
	applymovement LOCALID_GRUNT, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_GRUNT, Common_Movement_Delay48
	waitmovement 0
	delay 20
	call_if_eq VAR_FACING, DIR_WEST, SeafloorCavern_Entrance_EventScript_GruntFacePlayerWest
	call_if_eq VAR_FACING, DIR_EAST, SeafloorCavern_Entrance_EventScript_GruntFacePlayerEast
	call_if_eq VAR_FACING, DIR_NORTH, SeafloorCavern_Entrance_EventScript_GruntFacePlayerNorth
	delay 30
	setvar VAR_HAS_TALKED_TO_SEAFLOOR_CAVERN_ENTRANCE_GRUNT, 1
	copyobjectxytoperm LOCALID_GRUNT
	msgbox SeafloorCavern_Entrance_Text_HearMagmaNearMossdeep, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	releaseall
	end

SeafloorCavern_Entrance_EventScript_GruntSpeechShort::
	call_if_eq VAR_FACING, DIR_WEST, SeafloorCavern_Entrance_EventScript_GruntFacePlayerWest
	call_if_eq VAR_FACING, DIR_EAST, SeafloorCavern_Entrance_EventScript_GruntFacePlayerEast
	call_if_eq VAR_FACING, DIR_NORTH, SeafloorCavern_Entrance_EventScript_GruntFacePlayerNorth
	msgbox SeafloorCavern_Entrance_Text_HearMagmaNearMossdeepShort, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	releaseall
	end

SeafloorCavern_Entrance_EventScript_GruntFacePlayerEast::
	applymovement LOCALID_GRUNT, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

SeafloorCavern_Entrance_EventScript_GruntFacePlayerWest::
	applymovement LOCALID_GRUNT, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

SeafloorCavern_Entrance_EventScript_GruntFacePlayerNorth::
	applymovement LOCALID_GRUNT, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

SeafloorCavern_Entrance_Text_HearMagmaNearMossdeep:
	.string "Hé !\n"
	.string "Je me souviens de ta tête !\p"
	.string "Si tu es là, ça veut dire que\n"
	.string "tu vas encore venir nous déranger !\p"
	.string "Un vaurien comme toi, tu crois vraiment\n"
	.string "pouvoir affronter la TEAM AQUA ?\p"
	.string "Je dirais qu'il te manque bien\n"
	.string "un milliard d'années !\p"
	.string "Tu serais bien mieux chez\n"
	.string "la TEAM MAGMA !\p"
	.string "En parlant de la TEAM MAGMA, j'ai entendu\n"
	.string "dire qu'ils ont été aperçus près d'ALGATIA.\p"
	.string "Cette bande de brutes, ils n'ont vraiment\n"
	.string "pas l'air à leur place près de la mer !$"

SeafloorCavern_Entrance_Text_HearMagmaNearMossdeepShort:
	.string "Un vaurien comme toi, tu crois vraiment\n"
	.string "pouvoir affronter la TEAM AQUA ?\p"
	.string "Je dirais qu'il te manque bien\n"
	.string "un milliard d'années !\p"
	.string "Tu serais bien mieux chez\n"
	.string "la TEAM MAGMA !\p"
	.string "En parlant de la TEAM MAGMA, j'ai entendu\n"
	.string "dire qu'ils ont été aperçus près d'ALGATIA.\p"
	.string "Cette bande de brutes, ils n'ont vraiment\n"
	.string "pas l'air à leur place près de la mer !$"

