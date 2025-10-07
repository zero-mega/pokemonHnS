.set LOCALID_ROCKETHIDEOUT3_LANCE, 3
.set LOCALID_ROCKETHIDEOUT3_DRAGONITE, 2
.set LOCALID_ROCKETHIDEOUT3_SILVER, 5
.set LOCALID_ROCKETHIDEOUT3_GIOVANNI, 16
.set LOCALID_ROCKETHIDEOUT3_PETREL, 15
.set LOCALID_ROCKETHIDEOUT3_MURKROW, 14
.set LOCALID_ROCKETHIDEOUT3_MURKROWSTAIRS, 17

RocketHideout_B3F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RocketHideout_B3F_OnFrame
	map_script MAP_SCRIPT_ON_LOAD, RocketHideout_B3F_OnLoad
	.byte 0

RocketHideout_B3F_OnLoad::
	call_if_set FLAG_HIDE_ROCKETHIDEOUT3_GATE, RocketHideout_B3F_HideGate
	call_if_eq VAR_ROCKET_PASSWORD, 2, RocketHideout_B3F_HidePetrel
	end
	
RocketHideout_B3F_HideGate::
	setmetatile 11, 11, 0x378, FALSE
	setmetatile 11, 12, 0x380, FALSE
	setmetatile 12, 11, 0x379, FALSE
	setmetatile 12, 12, 0x379, FALSE
	setmetatile 13, 11, 0x379, FALSE
	setmetatile 13, 12, 0x379, FALSE
	return
RocketHideout_B3F_HidePetrel::
	setflag FLAG_HIDE_ROCKETHIDEOUT3_PETREL
	clearflag FLAG_HIDE_ROCKETHIDEOUT3_GIOVANNI
	return

RocketHideout_B3F_OnFrame::
	map_script_2 VAR_MAHOGANY_TOWN_STATE, 6, RocketHideout_B3F_EventScript_LancePassword
	.2byte 0

RocketHideout_B3F_EventScript_LancePassword::
	lock
	delay 55
	playse SE_PIN
	applymovement LOCALID_ROCKETHIDEOUT3_LANCE, Common_Movement_ExclamationMark
	delay 20
	applymovement LOCALID_ROCKETHIDEOUT3_LANCE, Common_Movement_WalkRight1
	msgbox RocketHideout_B3F_Text_LanceGetPassword, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROCKETHIDEOUT3_LANCE, RocketHideout_B3F_Movement_LanceLeave
	applymovement LOCALID_ROCKETHIDEOUT3_DRAGONITE, RocketHideout_B3F_Movement_DragoniteLeave
	waitmovement LOCALID_ROCKETHIDEOUT3_LANCE
	waitmovement LOCALID_ROCKETHIDEOUT3_DRAGONITE
	setflag FLAG_HIDE_ROCKETHIDEOUT3_LANCE_DRAGONITE
	removeobject LOCALID_ROCKETHIDEOUT3_DRAGONITE
	removeobject LOCALID_ROCKETHIDEOUT3_LANCE
	setvar VAR_MAHOGANY_TOWN_STATE, 7
	release
	end

RocketHideout_B3F_Movement_LanceLeave:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	delay_2
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

RocketHideout_B3F_Movement_DragoniteLeave:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_8
	delay_8
	delay_8
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

RocketHideout_B3F_Text_LanceGetPassword:
    .string "LANCE : Il faut deux mots de passe\n"
    .string "pour entrer dans le bureau du boss.\p"
    .string "Seuls quelques ROCKETS connaissent\n"
    .string "ces mots de passe.\p"
    .string "Ce ROCKET là-bas me l'a gentiment\n"
    .string "révélé.\p"
    .string "{PLAYER}, allons chercher les\n"
    .string "mots de passe.$"

RocketHideout_B3F_EventScript_RocketKO::
	lock
	faceplayer
	msgbox RocketHideout_B3F_Text_B3FRocket, MSGBOX_DEFAULT
	release
	end

RocketHideout_B3F_Text_B3FRocket:
    .string "Urrggh… Le gars avec la cape est\n"
    .string "incroyablement fort…$"


RocketHideout_B3F_Trigger_MurkrowStairs::
	lock
	applymovement LOCALID_ROCKETHIDEOUT3_MURKROWSTAIRS, RocketHideout_B3F_Movement_MurkrowStairs1
	waitmovement 0
	playmoncry SPECIES_MURKROW, CRY_MODE_NORMAL
	msgbox RocketHideout_B3F_Text_MurkrowSpeak1, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROCKETHIDEOUT3_MURKROWSTAIRS, RocketHideout_B3F_Movement_MurkrowStairs2
	waitmovement 0
	setflag FLAG_HIDE_ROCKETHIDEOUT3_MURKROWSTAIRS
	removeobject LOCALID_ROCKETHIDEOUT3_MURKROWSTAIRS
	clearflag FLAG_HIDE_ROCKETHIDEOUT2_MURKROWGATE
	setvar VAR_MAHOGANY_TOWN_STATE, 11
	release
	end

RocketHideout_B3F_Movement_MurkrowStairs1:
	jump_in_place_right
	jump_in_place_right
	step_end

RocketHideout_B3F_Movement_MurkrowStairs2:
	jump_in_place_right
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

RocketHideout_B3F_Trigger_Silver::
	lock
	clearflag FLAG_HIDE_ROCKETHIDEOUT3_SILVER
	addobject LOCALID_ROCKETHIDEOUT3_SILVER
	playbgm MUS_HG_ENCOUNTER_RIVAL, TRUE
	applymovement LOCALID_ROCKETHIDEOUT3_SILVER, RocketHideout_B3F_Movement_SilverEnter
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	msgbox RocketHideout_B3F_Text_Rival, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROCKETHIDEOUT3_SILVER, RocketHideout_B3F_Movement_SilverLeave
	waitmovement 0
	setflag FLAG_HIDE_ROCKETHIDEOUT3_SILVER
	removeobject LOCALID_ROCKETHIDEOUT3_SILVER
	setvar VAR_MAHOGANY_TOWN_STATE, 8
	fadedefaultbgm
	release
	end

RocketHideout_B3F_Movement_SilverEnter:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

RocketHideout_B3F_Movement_SilverLeave:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

RocketHideout_B3F_EventScript_Door::
	lock
	goto_if_set FLAG_HIDE_ROCKETHIDEOUT3_GATE, RocketHideout_B3F_EventScript_DoorIsOpen
	goto_if_eq VAR_ROCKET_PASSWORD, 2, RocketHideout_B3F_EventScript_OpenDoor
	msgbox RocketHideout_B3F_Text_B3FLockedDoorNeedsPassword, MSGBOX_DEFAULT
	closemessage
	release
	end

RocketHideout_B3F_EventScript_OpenDoor::
	msgbox RocketHideout_B3F_Text_B3FLockedDoorOpenSesame, MSGBOX_DEFAULT
	closemessage
	playse SE_CLICK
	setmetatile 11, 11, 0x378, FALSE
	setmetatile 11, 12, 0x380, FALSE
	setmetatile 12, 11, 0x379, FALSE
	setmetatile 12, 12, 0x379, FALSE
	setmetatile 13, 11, 0x379, FALSE
	setmetatile 13, 12, 0x379, FALSE
	special DrawWholeMapView
	setflag FLAG_HIDE_ROCKETHIDEOUT3_GATE
	release
	end

RocketHideout_B3F_EventScript_DoorIsOpen::
	end

RocketHideout_B3F_EventScript_GruntF5::
	trainerbattle_single TRAINER_GRUNT_29 RocketHideout_B3F_Text_GruntF5Seen, RocketHideout_B3F_Text_GruntF5Beaten
	msgbox RocketHideout_B3F_Text_GruntF5After, MSGBOX_NPC
	goto_if_unset FLAG_GOT_PASSWORD_FROM_GRUNTF, RocketHideout_B3F_EventScript_IncrementPasswordGruntF
	end

RocketHideout_B3F_EventScript_IncrementPasswordGruntF::
	addvar VAR_ROCKET_PASSWORD, 1
	setflag FLAG_GOT_PASSWORD_FROM_GRUNTF
	end

RocketHideout_B3F_EventScript_Eto::
	trainerbattle_single TRAINER_ETO_2 RocketHideout_B3F_Text_GruntM28Seen, RocketHideout_B3F_Text_GruntM28Beaten
	msgbox RocketHideout_B3F_Text_GruntM28After, MSGBOX_NPC
	goto_if_unset FLAG_GOT_PASSWORD_FROM_ETO, RocketHideout_B3F_EventScript_IncrementPasswordEto
	end

RocketHideout_B3F_EventScript_IncrementPasswordEto::
	addvar VAR_ROCKET_PASSWORD, 1
	setflag FLAG_GOT_PASSWORD_FROM_ETO
	end

RocketHideout_B3F_EventScript_Ross::
	trainerbattle_single TRAINER_ROSS RocketHideout_B3F_Text_ScientistRossSeen, RocketHideout_B3F_Text_ScientistRossBeaten
	msgbox RocketHideout_B3F_Text_ScientistRossAfter, MSGBOX_AUTOCLOSE
	end

RocketHideout_B3F_EventScript_Mitch::
	trainerbattle_single TRAINER_MITCH RocketHideout_B3F_Text_ScientistMitchSeen, RocketHideout_B3F_Text_ScientistMitchBeaten
	msgbox RocketHideout_B3F_Text_ScientistMitchAfter, MSGBOX_AUTOCLOSE
	end

RocketHideout_B3F_EventScript_Item_IceHeal::
	finditem ITEM_ICE_HEAL
	end

RocketHideout_B3F_EventScript_Item_Protein::
	finditem ITEM_PROTEIN
	end

RocketHideout_B3F_EventScript_Item_FullHeal::
	finditem ITEM_FULL_HEAL
	end

RocketHideout_B3F_EventScript_Item_GuardSpec::
	finditem ITEM_GUARD_SPEC
	end

RocketHideout_B3F_EventScript_Item_HyperPotion::
	finditem ITEM_HYPER_POTION
	end

RocketHideout_B3F_Text_B3FLockedDoorNeedsPassword:
    .string "La porte est fermée…\p"
    .string "Il faut deux mots de passe pour l'ouvrir.$"

RocketHideout_B3F_Text_B3FLockedDoorOpenSesame:
    .string "La porte est fermée…\p"
    .string "{PLAYER} a entré les deux mots de passe.\p"
    .string "La porte s'est ouverte !$"

RocketHideout_B3F_Text_Rival:
    .string "…\p"
    .string "Je ne t'avais pas dit que j'allais\n"
    .string "détruire la TEAM ROCKET ?\p"
    .string "…Dis-moi, qui était ce type avec\n"
    .string "la cape qui utilisait des POKéMON dragons ?\p"
    .string "Mes POKéMON n'ont eu aucune chance.\p"
    .string "C'est ce qu'il a dit qui me dérange…\p"
    .string "Il m'a dit que je n'aimais pas et que\n"
    .string "je ne faisais pas assez confiance à mes POKéMON.\p"
    .string "Ce n'est pas ma faute si mon équipe est\n"
    .string "aussi inutile.\p"
    .string "Je suis furieux d'avoir perdu contre un\n"
    .string "sentimental comme lui.\p"
    .string "Mais ça me fait me remettre en question.\p"
    .string "Est-ce que je fais quelque chose de mal ?\p"
    .string "Est-ce que l'amour a rendu son équipe\n"
    .string "aussi puissante ?$"

@=======[PETREL]==============================================================================================================================

RocketHideout_B3F_EventScript_Giovanni::
	lock
	faceplayer
	msgbox RocketHideout_B3F_Text_PetrelIntro, MSGBOX_DEFAULT
	playse SE_PIN
	applymovement LOCALID_ROCKETHIDEOUT3_GIOVANNI, Common_Movement_QuestionMark
	delay 60
	msgbox RocketHideout_B3F_Text_PetrelDisbelief MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROCKETHIDEOUT3_GIOVANNI, RocketHideout_B3F_Movement_Spin
	waitmovement 0
	setflag FLAG_HIDE_ROCKETHIDEOUT3_GIOVANNI
	removeobject LOCALID_ROCKETHIDEOUT3_GIOVANNI
	clearflag FLAG_HIDE_ROCKETHIDEOUT3_PETREL
	addobject LOCALID_ROCKETHIDEOUT3_PETREL
	applymovement LOCALID_ROCKETHIDEOUT3_PETREL, RocketHideout_B3F_Movement_Spin2
	waitmovement 0
	call_if_eq VAR_FACING, DIR_EAST, RocketHideout_B3F_EventScript_FacingEast
	call_if_eq VAR_FACING, DIR_WEST, RocketHideout_B3F_EventScript_FacingWest
	msgbox RocketHideout_B3F_Text_PetrelReveal, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_PETREL_1, RocketHideout_B3F_Text_PetrelBeaten
	msgbox RocketHideout_B3F_Text_PetrelAfterBattle, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_EAST, RocketHideout_B3F_EventScript_LeaveEast
	call_if_eq VAR_FACING, DIR_WEST, RocketHideout_B3F_EventScript_LeaveWest
	call_if_eq VAR_FACING, DIR_NORTH, RocketHideout_B3F_EventScript_LeaveEast
	setflag FLAG_HIDE_ROCKETHIDEOUT3_PETREL
	playse SE_EXIT
	removeobject LOCALID_ROCKETHIDEOUT3_PETREL
	
	applymovement LOCALID_ROCKETHIDEOUT3_MURKROW, RocketHideout_B3F_Movement_Murkrow1

	delay 120

	call_if_eq VAR_FACING, DIR_EAST, RocketHideout_B3F_EventScript_FacingEastMurkrow
	call_if_eq VAR_FACING, DIR_WEST, RocketHideout_B3F_EventScript_FacingWestMurkrow

	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	waitmovement LOCALID_ROCKETHIDEOUT3_MURKROW
	playmoncry SPECIES_MURKROW, CRY_MODE_NORMAL
	msgbox RocketHideout_B3F_Text_MurkrowSpeak1, MSGBOX_DEFAULT
	msgbox RocketHideout_B3F_Text_MurkrowMimic, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROCKETHIDEOUT3_MURKROW, RocketHideout_B3F_Movement_Murkrow2
	waitmovement LOCALID_ROCKETHIDEOUT3_MURKROW

	setflag FLAG_HIDE_ROCKETHIDEOUT3_MURKROW
	playse SE_EXIT
	removeobject LOCALID_ROCKETHIDEOUT3_MURKROW
	clearflag FLAG_HIDE_ROCKETHIDEOUT2_MURKROWSTAIRS
	setflag FLAG_HIDE_ROCKETHIDEOUT2_MURKROWGATE
	setflag FLAG_HIDE_ROCKETHIDEOUT3_MURKROWSTAIRS
	setflag FLAG_HIDE_ROCKETHIDEOUT2_ARIANA_AND_GRUNT
	setvar VAR_ROCKET_PASSWORD, 3
	setvar VAR_MAHOGANY_TOWN_STATE, 9
	release
	end

RocketHideout_B3F_EventScript_FacingEastMurkrow::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight1
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown1
	waitmovement OBJ_EVENT_ID_PLAYER
	return

RocketHideout_B3F_EventScript_FacingWestMurkrow::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft1
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown1
	waitmovement OBJ_EVENT_ID_PLAYER
	return

RocketHideout_B3F_EventScript_FacingEast::
	turnobject LOCALID_ROCKETHIDEOUT3_PETREL, DIR_WEST
	return

RocketHideout_B3F_EventScript_FacingWest::
	turnobject LOCALID_ROCKETHIDEOUT3_PETREL, DIR_EAST
	return

RocketHideout_B3F_EventScript_FacingNorth::
	turnobject LOCALID_ROCKETHIDEOUT3_PETREL, DIR_SOUTH
	return

RocketHideout_B3F_EventScript_LeaveEast::
	applymovement LOCALID_ROCKETHIDEOUT3_PETREL, RocketHideout_B3F_Movement_LeaveEast
	waitmovement 0
	return

RocketHideout_B3F_EventScript_LeaveWest::
	applymovement LOCALID_ROCKETHIDEOUT3_PETREL, RocketHideout_B3F_Movement_LeaveWest
	waitmovement 0
	return

RocketHideout_B3F_Movement_Murkrow1:
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	jump_in_place_right
	jump_in_place_left
	jump_in_place_down
	jump_in_place_up
	jump_in_place_up
	jump_in_place_up
	jump_in_place_up
	step_end

RocketHideout_B3F_Movement_Murkrow2:
	jump_in_place_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_right
	walk_faster_right
	step_end

RocketHideout_B3F_Movement_LeaveEast:
	lock_facing_direction
	walk_slow_right
	unlock_facing_direction
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_fast_right
	walk_fast_right
	step_end
RocketHideout_B3F_Movement_LeaveWest:
	lock_facing_direction
	walk_slow_left
	walk_slow_left
	unlock_facing_direction
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_fast_right
	walk_fast_right
	step_end

RocketHideout_B3F_Movement_Spin:
	face_right
	delay_8
	face_up
	delay_8
	face_left
	delay_8
	face_down
	delay_8
	face_right
	delay_4
	face_up
	delay_4
	face_left
	delay_4
	face_down
	delay_4
	face_right
	delay_2
	face_up
	delay_2
	face_left
	delay_2
	face_down
	step_end

RocketHideout_B3F_Movement_Spin2:
	face_right
	delay_2
	face_up
	delay_2
	face_left
	delay_2
	face_down
	step_end

RocketHideout_B3F_Text_PetrelIntro:
    .string "Muhahaha, nous t'attendions\n"
    .string "depuis longtemps. Donc, tu es {PLAYER}...\p"
    .string "Moi ? Tu ne sais pas qui je suis ?\n"
    .string "C'est moi, GIOVANNI.\p"
    .string "Le majestueux GIOVANNI en personne !\n"
    .string "Wahahaha !$"

RocketHideout_B3F_Text_PetrelDisbelief:
    .string "...Hein ?\n"
    .string "Je ne ressemble pas du tout à\l"
    .string "GIOVANNI ?\p"
    .string "Je ne ressemble même pas à GIOVANNI ?\n"
    .string "Comment ça ? J'ai tant travaillé\l"
    .string "pour l'imiter !$"

RocketHideout_B3F_Text_PetrelReveal:
    .string "PETREL : Je suis un Administrateur\n"
    .string "de la Team Rocket !\p"
    .string "Tu essaies de t'infiltrer dans la\n"
    .string "salle de l'émetteur radio.\p"
    .string "Eh bien, ça n'arrivera pas.\n"
    .string "Cette salle est protégée par un\l"
    .string "mot de passe spécial.\p"
    .string "Le mot de passe est « Vive GIOVANNI. »\n"
    .string "Surpris de l'entendre de ma bouche ?\p"
    .string "Mais connaître le mot de passe ne\n"
    .string "t'aidera pas.\p"
    .string "La porte ne s'ouvrira que si JE dis\n"
    .string "le mot de passe. Elle ne réagit qu'à\l"
    .string "ma voix.$"

RocketHideout_B3F_Text_PetrelBeaten:
    .string "Je... Je n'ai rien pu faire...\p"
    .string "GIOVANNI, pardonne-moi...$"

RocketHideout_B3F_Text_PetrelAfterBattle:
    .string "PETREL : Depuis la dissolution de la\n"
    .string "Team Rocket il y a trois ans, notre\l"
    .string "Giovanni a disparu.\p"
    .string "Mais nous sommes certains qu'il\n"
    .string "attend le bon moment pour notre\l"
    .string "retour... Wahahaha !\p"
    .string "Perdre contre toi ne changera pas le\n"
    .string "fait que tu ne peux pas entrer dans\l"
    .string "la salle de l'émetteur radio !\p"
    .string "Tu as besoin de ma voix pour l'ouvrir !$"

RocketHideout_B3F_EventScript_Murkrow::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MURKROW, CRY_MODE_NORMAL
	msgbox RocketHideout_B3F_Text_MurkrowSpeak1, MSGBOX_DEFAULT
	waitmoncry
	release
	end

RocketHideout_B3F_Text_MurkrowSpeak1:
    .string "CORNEBRE : Vive GIOVANNI.$"

RocketHideout_B3F_Text_MurkrowMimic:
    .string "CORNEBRE imite\n"
    .string "la voix de PETREL !\p"
    .string "Peut-être que tu pourrais...!?$"

RocketHideout_B3F_Text_Murkrow:
    .string "CORNEBRE : Le mot de passe est…\p"
    .string "VIVE GIOVANNI.$"

RocketHideout_B3F_Text_GruntF5Seen:
    .string "Je connais le mot de passe ?\p"
    .string "Peut-être.\p"
    .string "Mais aucun faible ne l'obtiendra !$"

RocketHideout_B3F_Text_GruntF5Beaten:
    .string "D'accord. Stop. Je vais te le dire.$"

RocketHideout_B3F_Text_GruntF5After:
    .string "Le mot de passe de la salle du boss\n"
    .string "est QUEUDEKARPUCE.\p"
    .string "Mais ça ne sert à rien si tu n'as\n"
    .string "pas deux mots de passe.$"

RocketHideout_B3F_Text_GruntM28Seen:
    .string "Hyuck-hyuck-hyuck !\p"
    .string "Je me souviens de toi au Puits !\p"
    .string "Tu veux encore m'affronter ?\p"
    .string "Ha ! T'es fou, mais t'as du cran !\p"
    .string "Je te préviens, je me suis amélioré !\p"
    .string "Si tu me bats, je te donnerai\l"
    .string "un mot de passe pour la salle du boss !$"

RocketHideout_B3F_Text_GruntM28Beaten:
    .string "Hyuck-hyuck-hyuck ! T'es fort !$"

RocketHideout_B3F_Text_GruntM28After:
    .string "Hyuck-hyuck-hyuck !\p"
    .string "Le mot de passe de la salle du boss…\p"
    .string "Euh..., je crois que c'est QUEUERATATTA.$"

RocketHideout_B3F_Text_ScientistRossSeen:
    .string "Je travaillais pour SILPH, mais\n"
    .string "maintenant je fais des recherches\l"
    .string "pour la TEAM ROCKET.\p"
    .string "Un enfant aussi gênant que toi doit\n"
    .string "être puni.$"

RocketHideout_B3F_Text_ScientistRossBeaten:
    .string "Une simple erreur tactique m'a coûté…$"

RocketHideout_B3F_Text_ScientistRossAfter:
    .string "Un signal radio qui rend les\n"
    .string "POKéMON fous…\p"
    .string "Mon expérience est un succès\n"
    .string "total.\p"
    .string "Ma promotion est assurée. Cette\n"
    .string "défaite ne signifie absolument rien.$"

RocketHideout_B3F_Text_ScientistMitchSeen:
    .string "Je me fiche que les POKéMON soient\n"
    .string "blessés par notre expérience.$"

RocketHideout_B3F_Text_ScientistMitchBeaten:
    .string "Réfléchir est mon point fort, pas\n"
    .string "le combat.$"

RocketHideout_B3F_Text_ScientistMitchAfter:
    .string "Si on augmente la puissance de notre\n"
    .string "signal radio pour le diffuser\l"
    .string "dans tout le pays…\p"
    .string "Rien que d'y penser, ça m'excite !$"
