.set LOCALID_MOM, 1
.set LOCALID_MOMS_FRIEND, 2

PlayersHouse1_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PlayersHouse1_OnTransition
	.byte 0

PlayersHouse1_OnTransition::
	call_if_eq VAR_NEWBARK_TOWN_STATE, 1, PlayersHouse1_SetMomStandingAtTable
	call_if_eq VAR_NEWBARK_TOWN_STATE, 2, PlayersHouse1_SetMomStandingAtTable
	call_if_eq VAR_NEWBARK_TOWN_STATE, 3, PlayersHouse1_SetMomStandingAtTable
	end

PlayersHouse1_SetMomStandingAtTable::
	setobjectxyperm LOCALID_MOM, 8, 4
	setobjectmovementtype LOCALID_MOM, MOVEMENT_TYPE_FACE_LEFT

	@add to newgame later
	clearflag FLAG_HIDE_MOMS_FRIEND
	clearflag FLAG_MOM_VISITED
	return

PlayersHouse1_EventScript_Mom::
	lock
	faceplayer
	goto_if_set FLAG_MOM_VISITED, PlayersHouse1_EventScript_Mom_Regular
	goto_if_set FLAG_ADVENTURE_STARTED, PlayersHouse1_MomEventScript_GoodLuck
	msgbox PlayersHouse1_Text_MomHurryUpElmIsWaiting, MSGBOX_DEFAULT
	applymovement LOCALID_MOM, PlayersHouse1_MovementFaceLeft
	waitmovement 0
	release
	end

PlayersHouse1_EventScript_MomsFriend::
	lock
	faceplayer
	msgbox PlayersHouse1_Text_MomsFriend, MSGBOX_DEFAULT
	applymovement LOCALID_MOMS_FRIEND, PlayersHouse1_MovementFaceRight
	waitmovement 0
	release
	end

PlayersHouse1_MomEventScript_GoodLuck::
	msgbox PlayersHouse1_Text_MomLeaving, MSGBOX_DEFAULT
	setflag FLAG_MOM_VISITED
	clearflag FLAG_HIDE_ROUTE_30_NPCS
	setvar VAR_NEWBARK_TOWN_STATE, 5
	release
	end


PlayersHouse1_EventScript_Mom_Regular::
	call PlayersHouse_1F_EventScript_MomHealsParty
	release
	end

PlayersHouse1_EventScript_MomsIntroTrigger1::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, PlayersHouse1_PlayerIntroMovement1
	waitmovement 0
	goto PlayersHouse1_EventScript_MomsIntro
	end

PlayersHouse1_EventScript_MomsIntroTrigger2::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, PlayersHouse1_PlayerIntroMovement2
	waitmovement 0
	goto PlayersHouse1_EventScript_MomsIntro
	end


PlayersHouse1_EventScript_MomsIntro::
	playse SE_PIN
	applymovement LOCALID_MOM, Common_Movement_ExclamationMark
	delay 60
	applymovement LOCALID_MOM, PlayersHouse1_MomMovement_1
	waitmovement 0
	msgbox PlayersHouse1_Text_ElmsLookingForYou, MSGBOX_DEFAULT
	call PlayersHouse1_EventScript_GivePokeGear
	call PlayersHouse1_EventScript_GiveRunningShoes
	applymovement LOCALID_MOM, PlayersHouse1_MomMovement_2
	waitmovement 0
	setvar VAR_NEWBARK_TOWN_STATE, 2
	setvar VAR_NEWBARKTOWN_LABSTATE, 0
	setflag FLAG_HIDE_LAB_POLICEMAN
	setflag FLAG_VISITED_NEWBARK_TOWN

	@FLAGHEAP1
	setflag FLAG_HIDE_MOMS_FRIEND2 
	setflag FLAG_HIDE_SILVER_CHERRYGROVE
	setflag FLAG_HIDE_ROUTE_30_NPCS
	setflag FLAG_HIDE_MRPOKEMON
	setflag FLAG_HIDE_TOHJO_GIOVANNI
	

	clearflag FLAG_COMPLETED_AERODACTYL_PUZZLE
	clearflag FLAG_COMPLETED_HOOH_PUZZLE
	clearflag FLAG_COMPLETED_KABUTO_PUZZLE
	clearflag FLAG_COMPLETED_OMANYTE_PUZZLE
	clearflag FLAG_GOT_SILK_SCARF
	clearflag FLAG_GOT_MYSTICWATER
	clearflag FLAG_HIDE_GUIDE_GENT_CHERRYGROVE
	clearflag FLAG_ADVENTURE_STARTED
	clearflag FLAG_DELIVERED_EGG
	clearflag FLAG_SHOWN_ELM_TOGEPI
	clearflag FLAG_ENABLE_RADIO
	clearflag FLAG_ENABLE_BAOBA_MATCH_CALL
	clearflag FLAG_HIDE_SSAQUA1_GRANDPA
	clearflag FLAG_CAUGHT_CELEBI
	
	setvar VAR_VIOLET_CITY_STATE, 0 @CITY STATES
	setvar VAR_CHERRYGROVE_CITY_STATE, 0
	setvar VAR_AZALEA_TOWN_STATE, 0
	setvar VAR_GOLDENROD_CITY_STATE, 0
	setvar VAR_ECRUTEAK_CITY_STATE, 0
	setvar VAR_MAHOGANY_TOWN_STATE, 0
	setvar VAR_OLIVINE_CITY_STATE, 0
	setvar VAR_CIANWOOD_CITY_STATE, 0
	setvar VAR_SAFARI_ZONE_GATE_STATE, 0
	setvar VAR_BLACKTHORN_CITY_STATE, 0
	setvar VAR_PALLET_TOWN_STATE, 0
	setvar VAR_VIRIDIAN_CITY_STATE, 0
	setvar VAR_PEWTER_CITY_STATE, 0
	setvar VAR_CERULEAN_CITY_STATE, 0
	setvar VAR_VERMILION_CITY_STATE, 0
	setvar VAR_LAVENDER_TOWN_STATE, 0
	setvar VAR_CELADON_CITY_STATE, 0
	setvar VAR_SAFFRON_CITY_STATE, 0
	setvar VAR_FUCHSIA_CITY_STATE, 0
	setvar VAR_ROUTE27_STATE, 0
	setvar VAR_LEAGUE_STATE, 0
	setvar VAR_SSAQUA_STATE, 0
	releaseall
	end



PlayersHouse1_EventScript_GivePokeGear::
	playfanfare MUS_OBTAIN_ITEM
	message PlayersHouse1_Text_ObtainedPokeGear
	waitfanfare
	setflag FLAG_SYS_POKENAV_GET
	setflag FLAG_RECEIVED_POKENAV
	setflag FLAG_ADDED_MATCH_CALL_TO_POKENAV
	setflag FLAG_REGISTER_RIVAL_POKENAV
	msgbox PlayersHouse1_Text_ExplainPokeGear, MSGBOX_DEFAULT
	closemessage
	delay 30
	return
	
PlayersHouse1_EventScript_GiveRunningShoes::
	msgbox PlayersHouse1_Text_WearTheseRunningShoes, MSGBOX_DEFAULT
	waitmessage
	closemessage
	playfanfare MUS_OBTAIN_ITEM
	msgbox PlayersHouse1_Text_SwitchShoesWithRunningShoes, MSGBOX_DEFAULT
	closemessage
	waitfanfare
	setflag FLAG_RECEIVED_RUNNING_SHOES
	setflag FLAG_SYS_B_DASH
	msgbox PlayersHouse1_Text_ExplainRunningShoes, MSGBOX_DEFAULT
	closemessage
	delay 30
	return

PlayersHouse1_PlayerIntroMovement1:
	delay_8
	walk_down
	walk_right
	walk_down
	face_left
	delay_8
	step_end

PlayersHouse1_PlayerIntroMovement2:
	delay_8
	walk_down
	face_left
	delay_8
	step_end

PlayersHouse1_MomMovement_1:
	face_right
	walk_right
	step_end

PlayersHouse1_MomMovement_2:
	face_left
	walk_left
	delay_8
	step_end

PlayersHouse1_MovementFaceRight:
	face_right
	step_end

PlayersHouse1_MovementFaceLeft:
	face_left
	step_end

PlayersHouse1_Text_ElmsLookingForYou:
	.string "Oh, {PLAYER}…! Our neighbor,\n"
	.string "PROF.ELM, was looking for you.\p"
	.string "He said he wanted you to do\n"
	.string "something for him.\p"
	.string "Oh! I almost forgot! Your POKéGEAR\n"
	.string "is back from the repair shop.\p"
	.string "Here you go!$"

PlayersHouse1_Text_ObtainedPokeGear:
	.string "{PLAYER} obtained the POKéGEAR.$"

PlayersHouse1_Text_ExplainPokeGear:
	.string "MOM: Phone numbers are stored\n"
	.string "in memory.\p"
	.string "Just choose a name you want to call.\p"
	.string "Gee, isn't that convenient?$"

PlayersHouse1_Text_WearTheseRunningShoes:
	.string "Oh and don't forget your\n"
	.string "RUNNING SHOES!$"

PlayersHouse1_Text_SwitchShoesWithRunningShoes:
	.string "{PLAYER} switched shoes with the\n"
	.string "RUNNING SHOES.$"

PlayersHouse1_Text_ExplainRunningShoes:
	.string "MOM: {PLAYER}, Press the B Button\n"
	.string "while wearing these to run fast!$"

PlayersHouse1_Text_MomHurryUpElmIsWaiting:
	.string "MOM: PROF.ELM is waiting for you.\p"
	.string "Hurry up, baby!$"

PlayersHouse1_Text_MomsFriend:
	.string "Hi, {PLAYER}!\p"
	.string "I'm visiting!\p"
	.string "Have you heard?\p"
	.string "My daughter is adamant about\n"
	.string "becoming PROF.ELM's assistant.\p"
	.string "She really loves POKéMON!$"

PlayersHouse1_Text_MomLeaving:
	.string "MOM: Wow, that's a cute POKéMON.\n"
	.string "Where did you get it?\p"
	.string "…\p"
	.string "So, you're leaving on an adventure...\n"
	.string "That does sound challenging...\p"
	.string "Just be careful.\p"
	.string "POKéMON are your friends.\n"
	.string "You need to work as a team.\p"
	.string "Now, go on!\n"
	.string "I'm behind you all the way!$"
