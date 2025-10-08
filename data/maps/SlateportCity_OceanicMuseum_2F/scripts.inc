.set LOCALID_CAPT_STERN, 1
.set LOCALID_ARCHIE, 2
.set LOCALID_GRUNT_1, 3
.set LOCALID_GRUNT_2, 4

SlateportCity_OceanicMuseum_2F_MapScripts::
	.byte 0

SlateportCity_OceanicMuseum_2F_EventScript_CaptStern::
	lock
	faceplayer
	msgbox SlateportCity_OceanicMuseum_2F_Text_ThankYouForTheParts, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_AQUA, TRUE
	addobject LOCALID_GRUNT_1
	applymovement LOCALID_GRUNT_1, SlateportCity_OceanicMuseum_2F_Movement_FirstGruntEnter
	waitmovement 0
	addobject LOCALID_GRUNT_2
	applymovement LOCALID_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_SecondGruntEnter
	waitmovement 0
	applymovement LOCALID_GRUNT_1, SlateportCity_OceanicMuseum_2F_Movement_FirstGruntApproach
	applymovement LOCALID_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_SecondGruntApproach
	waitmovement 0
	call_if_eq VAR_FACING, DIR_SOUTH, SlateportCity_OceanicMuseum_2F_EventScript_PlayerFaceGrunts
	call_if_eq VAR_FACING, DIR_EAST, SlateportCity_OceanicMuseum_2F_EventScript_PlayerFaceGrunts
	msgbox SlateportCity_OceanicMuseum_2F_Text_WellTakeThoseParts, MSGBOX_DEFAULT
	call_if_ne VAR_FACING, DIR_EAST, SlateportCity_OceanicMuseum_2F_EventScript_SternFaceGrunts
	msgbox SlateportCity_OceanicMuseum_2F_Text_SternWhoAreYou, MSGBOX_DEFAULT
	msgbox SlateportCity_OceanicMuseum_2F_Text_WereTeamAqua, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_GruntApproachToBattle
	waitmovement 0
	call_if_eq VAR_FACING, DIR_SOUTH, SlateportCity_OceanicMuseum_2F_EventScript_PlayerApproachGruntSouth
	call_if_eq VAR_FACING, DIR_WEST, SlateportCity_OceanicMuseum_2F_EventScript_PlayerApproachGruntWest
	trainerbattle_no_intro TRAINER_TODD, SlateportCity_OceanicMuseum_2F_Text_Grunt1Defeat
	msgbox SlateportCity_OceanicMuseum_2F_Text_BossGoingToBeFurious, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_GruntDefeated
	waitmovement 0
	applymovement LOCALID_GRUNT_1, SlateportCity_OceanicMuseum_2F_Movement_GruntApproachToBattle
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_LetMeTakeCareOfThis, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_TOM, SlateportCity_OceanicMuseum_2F_Text_Grunt2Defeat
	applymovement LOCALID_GRUNT_1, SlateportCity_OceanicMuseum_2F_Movement_GruntDefeated
	waitmovement 0
	applymovement LOCALID_GRUNT_1, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_GRUNT_2, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_MeddlingKid, MSGBOX_DEFAULT
	closemessage
	delay 35
	addobject LOCALID_ARCHIE
	applymovement LOCALID_ARCHIE, SlateportCity_OceanicMuseum_2F_Movement_ArchieEnter
	applymovement LOCALID_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_GruntMoveForArchie
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_CameToSeeWhatsTakingSoLong, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ARCHIE, SlateportCity_OceanicMuseum_2F_Movement_ArchieApproachPlayer
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_ArchieWarning, MSGBOX_DEFAULT
	closemessage
	savebgm MUS_DUMMY
	fadedefaultbgm
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_ARCHIE
	removeobject LOCALID_GRUNT_1
	removeobject LOCALID_GRUNT_2
	fadescreen FADE_FROM_BLACK
	delay 30
	setflag FLAG_GARBAGEFLAG
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_SternThankYouForSavingUs, MSGBOX_DEFAULT
	setvar VAR_0x8004, ITEM_DEVON_GOODS
	call Common_EventScript_PlayerHandedOverTheItem
	msgbox SlateportCity_OceanicMuseum_2F_Text_SternIveGotToGo, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	playfanfare MUS_HEAL
	waitfanfare
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	removeobject LOCALID_CAPT_STERN
	setflag FLAG_GARBAGEFLAG
	call_if_eq VAR_REGISTER_BIRCH_STATE, 0, SlateportCity_OceanicMuseum_2F_EventScript_ReadyRegisterBirch
	setflag FLAG_DELIVERED_DEVON_GOODS
	clearflag FLAG_GARBAGEFLAG
	setflag FLAG_GARBAGEFLAG
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 1
	fadescreen FADE_FROM_BLACK
	release
	end

SlateportCity_OceanicMuseum_2F_EventScript_ReadyRegisterBirch::
	setvar VAR_REGISTER_BIRCH_STATE, 1
	return

SlateportCity_OceanicMuseum_2F_EventScript_PlayerFaceGrunts::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

SlateportCity_OceanicMuseum_2F_EventScript_SternFaceGrunts::
	applymovement LOCALID_CAPT_STERN, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

SlateportCity_OceanicMuseum_2F_EventScript_PlayerApproachGruntSouth::
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_OceanicMuseum_2F_Movement_PlayerApproachGruntSouth
	waitmovement 0
	return

SlateportCity_OceanicMuseum_2F_EventScript_PlayerApproachGruntWest::
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_OceanicMuseum_2F_Movement_PlayerApproachGruntWest
	waitmovement 0
	return

SlateportCity_OceanicMuseum_2F_Movement_PlayerApproachGruntSouth:
	walk_left
	walk_down
	walk_in_place_faster_left
	step_end

SlateportCity_OceanicMuseum_2F_Movement_PlayerApproachGruntWest:
	walk_up
	walk_left
	walk_left
	walk_down
	walk_in_place_faster_left
	step_end

SlateportCity_OceanicMuseum_2F_Movement_Unused:
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_left
	walk_left
	walk_up
	walk_up
	delay_8
	step_end

SlateportCity_OceanicMuseum_2F_Movement_ArchieApproachPlayer:
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_ArchieEnter:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_GruntApproachToBattle:
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_FirstGruntEnter:
	walk_down
	walk_right
	walk_in_place_faster_down
	step_end

SlateportCity_OceanicMuseum_2F_Movement_FirstGruntApproach:
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_GruntDefeated:
	lock_facing_direction
	walk_left
	unlock_facing_direction
	step_end

SlateportCity_OceanicMuseum_2F_Movement_SecondGruntEnter:
	walk_down
	step_end

SlateportCity_OceanicMuseum_2F_Movement_SecondGruntApproach:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_GruntMoveForArchie:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_8
	walk_fast_down
	walk_in_place_faster_up
	step_end

SlateportCity_OceanicMuseum_2F_EventScript_WaterQualitySample1::
	msgbox SlateportCity_OceanicMuseum_2F_Text_WaterQualitySample1, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_WaterQualitySample2::
	msgbox SlateportCity_OceanicMuseum_2F_Text_WaterQualitySample2, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_PressureExperiment::
	msgbox SlateportCity_OceanicMuseum_2F_Text_PressureExperiment, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_HoennModel::
	msgbox SlateportCity_OceanicMuseum_2F_Text_HoennModel, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_DeepSeawaterDisplay::
	msgbox SlateportCity_OceanicMuseum_2F_Text_DeepSeawaterDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SurfaceSeawaterDisplay::
	msgbox SlateportCity_OceanicMuseum_2F_Text_SurfaceSeawaterDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SSTidalReplica::
	msgbox SlateportCity_OceanicMuseum_2F_Text_SSTidalReplica, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SubmarineReplica::
	msgbox SlateportCity_OceanicMuseum_2F_Text_SubmarineReplica, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SubmersibleReplica::
	msgbox SlateportCity_OceanicMuseum_2F_Text_SumbersibleReplica, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SSAnneReplica::
	msgbox SlateportCity_OceanicMuseum_2F_Text_SSAnneReplica, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_MuseumPatron1::
	msgbox SlateportCity_OceanicMuseum_2F_Text_RemindsMeOfAbandonedShip, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_2F_EventScript_MuseumPatron2::
	msgbox SlateportCity_OceanicMuseum_2F_Text_DontRunInMuseum, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_2F_EventScript_MuseumPatron3::
	lock
	faceplayer
	msgbox SlateportCity_OceanicMuseum_2F_Text_WantToRideSubmarine, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_OceanicMuseum_2F_Text_ThankYouForTheParts:
	.string "Oui ? Si tu cherches STERN,\n"
	.string "c'est moi.\p"
	.string "Ah ! Ce sont sûrement les pièces que\n"
	.string "j'ai commandées à M. PIERRE de DEVON.\p"
	.string "Merci ! C'est parfait !\n"
	.string "Nous pouvons préparer notre expédition maintenant.$"

SlateportCity_OceanicMuseum_2F_Text_WellTakeThoseParts:
	.string "Héhéhé, pas si vite !\n"
	.string "On va prendre ces pièces !$"

SlateportCity_OceanicMuseum_2F_Text_SternWhoAreYou:
	.string "CAPT. STERN : Qu-quoi ?\n"
	.string "Qui êtes-vous ?$"

SlateportCity_OceanicMuseum_2F_Text_WereTeamAqua:
	.string "Nous sommes la TEAM AQUA !\p"
	.string "Notre CHEF veut ces pièces !\n"
	.string "Ferme-la et donne-les-nous !$"

SlateportCity_OceanicMuseum_2F_Text_Grunt1Defeat:
	.string "Aaaah !\n"
	.string "Un gamin m'a battu !$"

SlateportCity_OceanicMuseum_2F_Text_BossGoingToBeFurious:
	.string "Oh non, quelle catastrophe…\n"
	.string "Le CHEF va être furieux…$"

SlateportCity_OceanicMuseum_2F_Text_LetMeTakeCareOfThis:
	.string "Pff, pleurnichard !\n"
	.string "Laisse-moi m'en occuper !$"

SlateportCity_OceanicMuseum_2F_Text_Grunt2Defeat:
	.string "Quoi ?!\n"
	.string "J'ai perdu aussi !$"

SlateportCity_OceanicMuseum_2F_Text_MeddlingKid:
	.string "Et maintenant ? Si on n'a pas les pièces,\n"
	.string "on est fichus !\p"
	.string "Grrr, je ne pensais pas être dérangé\n"
	.string "par un sale gosse ! $"

SlateportCity_OceanicMuseum_2F_Text_CameToSeeWhatsTakingSoLong:
	.string "Je suis venu voir pourquoi ça prenait\n"
	.string "autant de temps de voler ces pièces, et vous\l"
	.string "vous faites arrêter par un simple enfant ?$"

SlateportCity_OceanicMuseum_2F_Text_ArchieWarning:
	.string "Nous sommes la TEAM AQUA,\n"
	.string "et nous aimons la mer !\p"
	.string "Et je suis le chef de la TEAM AQUA,\n"
	.string "ARCHIE !\p"
	.string "Pourquoi interviens-tu dans nos affaires ?\p"
	.string "…Non ! Ce n'est pas possible !\n"
	.string "Tu n'es pas de la TEAM MAGMA ?\p"
	.string "Attends, ça ne peut pas être ça.\n"
	.string "Tu n'es pas habillé comme eux.\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "POKéMON, humains… Toute vie dépend\n"
	.string "de la mer.\p"
	.string "C'est pourquoi la TEAM AQUA se consacre\n"
	.string "à l'expansion de la mer.\p"
	.string "Tu n'es pas d'accord ? Ce que nous faisons\n"
	.string "est une entreprise magnifique.\p"
	.string "Bon, tant pis…\n"
	.string "Tu es encore trop jeune pour comprendre\l"
	.string "notre noble objectif.\p"
	.string "Mais je te préviens, n'essaie même pas\n"
	.string "d'interférer à nouveau avec nos plans.\p"
	.string "Les conséquences te coûteront\n"
	.string "cher !\p"
	.string "Et n'oublie pas ça !$"

SlateportCity_OceanicMuseum_2F_Text_SternThankYouForSavingUs:
	.string "CAPT. STERN : Tu es…\n"
	.string "Ah, d'accord, tu es {PLAYER}{KUN}…\p"
	.string "En tout cas, c'était une situation tendue !\n"
	.string "Merci de nous avoir sauvés !\p"
	.string "Oh, oui, j'allais oublier que tu as\n"
	.string "même apporté les pièces de DEVON !$"

SlateportCity_OceanicMuseum_2F_Text_SternIveGotToGo:
	.string "CAPT. STERN : Oups !\n"
	.string "Nous n'avons pas une minute à perdre !\p"
	.string "Nous devons bientôt partir pour notre\n"
	.string "expédition sous-marine.\p"
	.string "Merci encore, mais je dois\n"
	.string "y aller !\p"
	.string "N'hésite pas à visiter nos installations.$"

SlateportCity_OceanicMuseum_2F_Text_RemindsMeOfAbandonedShip:
	.string "J'ai vu une maquette de bateau ici.\p"
	.string "Ça m'a rappelé l'ÉPAVE\n"
	.string "près de POIVRESSEL…$"

SlateportCity_OceanicMuseum_2F_Text_DontRunInMuseum:
	.string "Ne t'avise pas de courir dans\n"
	.string "le MUSÉE !$"

SlateportCity_OceanicMuseum_2F_Text_WantToRideSubmarine:
	.string "Ouah, le sous-marin est génial !\n"
	.string "Je veux faire un tour !$"

SlateportCity_OceanicMuseum_2F_Text_WaterQualitySample1:
	.string "« ÉCHANTILLON D'EAU 1 », indique\n"
	.string "l'étiquette.\p"
	.string "La mer est reliée partout, mais l'eau\n"
	.string "semble différente selon la région.$"

SlateportCity_OceanicMuseum_2F_Text_WaterQualitySample2:
	.string "« ÉCHANTILLON D'EAU 2 », indique\n"
	.string "l'étiquette.\p"
	.string "La salinité de l'eau de mer varie-t-elle\n"
	.string "aussi selon la région ?$"

SlateportCity_OceanicMuseum_2F_Text_PressureExperiment:
	.string "Une balle en caoutchouc gonfle et\n"
	.string "se dégonfle.\p"
	.string "« Dans la mer, le poids de l'eau exerce\n"
	.string "une pression.\p"
	.string "« En eau peu profonde, la pression n'est\n"
	.string "pas très forte.\p"
	.string "« Mais dans les grandes profondeurs,\n"
	.string "la pression peut atteindre des dizaines de\l"
	.string "milliers de tonnes sur une petite surface. »$"

SlateportCity_OceanicMuseum_2F_Text_HoennModel:
	.string "« MAQUETTE DE HOENN »\p"
	.string "C'est une maquette miniature de la\n"
	.string "région de HOENN.\p"
	.string "Où se trouve BOURG-EN-VOL là-dessus ?$"

SlateportCity_OceanicMuseum_2F_Text_DeepSeawaterDisplay:
	.string "C'est un panneau sur le courant marin.\p"
	.string "« Près du fond de la mer, l'eau circule\n"
	.string "à cause de différences de température\l"
	.string "et de salinité. »$"

SlateportCity_OceanicMuseum_2F_Text_SurfaceSeawaterDisplay:
	.string "C'est un panneau sur le courant marin.\p"
	.string "« Près de la surface, l'eau de mer circule\n"
	.string "sous l'effet des vents. »$"

SlateportCity_OceanicMuseum_2F_Text_SSTidalReplica:
	.string "« LE FERRY M.S. MARÉE\p"
	.string "« Une maquette du navire en\n"
	.string "construction au CHANTIER NAVAL DE STERN. »$"

SlateportCity_OceanicMuseum_2F_Text_SubmarineReplica:
	.string "« SOUS-MARIN EXPLORER 1\p"
	.string "« Une réplique du sous-marin d'exploration\n"
	.string "océanique haute performance. »$"

SlateportCity_OceanicMuseum_2F_Text_SumbersibleReplica:
	.string "« MODULE SOUS-MARIN\p"
	.string "« Une réplique d'un module compact et\n"
	.string "télécommandé pour l'exploration sous-marine. »$"

SlateportCity_OceanicMuseum_2F_Text_SSAnneReplica:
	.string "« M.S. ANNE\p"
	.string "« Une réplique du paquebot de luxe qui\n"
	.string "fait le tour du monde. »$"
