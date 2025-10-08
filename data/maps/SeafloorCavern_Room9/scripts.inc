.set LOCALID_KYOGRE, 1
.set LOCALID_ARCHIE, 2
.set LOCALID_MAXIE, 3
.set LOCALID_GRUNT_1, 4
.set LOCALID_GRUNT_2, 5
.set LOCALID_KYOGRE_SLEEPING, 7

SeafloorCavern_Room9_MapScripts::
	.byte 0

SeafloorCavern_Room9_EventScript_ArchieAwakenKyogre::
	lockall
	setvar VAR_0x8004, LOCALID_ARCHIE
	setvar VAR_0x8005, LOCALID_MAXIE
	setvar VAR_0x8006, LOCALID_GRUNT_1
	setvar VAR_0x8007, LOCALID_GRUNT_2
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, SeafloorCavern_Room9_Movement_Delay32
	waitmovement 0
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	msgbox SeafloorCavern_Room9_Text_ArchieHoldItRightThere, MSGBOX_DEFAULT
	closemessage
	addobject VAR_0x8004
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	applymovement VAR_0x8004, SeafloorCavern_Room9_Movement_ArchieApproachPlayer
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_ArchieSoItWasYou, MSGBOX_DEFAULT
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_ArchieBeholdKyogre, MSGBOX_DEFAULT
	applymovement VAR_0x8004, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_ArchieYouMustDisappear, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_CASSIE, SeafloorCavern_Room9_Text_ArchieDefeat
	msgbox SeafloorCavern_Room9_Text_ArchieWithThisRedOrb, MSGBOX_DEFAULT
	setweather WEATHER_NONE
	doweather
	special Script_FadeOutMapMusic
	waitstate
	msgbox SeafloorCavern_Room9_Text_RedOrbShinesByItself, MSGBOX_DEFAULT
	special WaitWeather
	waitstate
	setvar VAR_RESULT, 1
	playse SE_M_DETECT
	dofieldeffectsparkle 16, 42, 0
	waitfieldeffect FLDEFF_SPARKLE
	closemessage
	setvar VAR_RESULT, 0
	playfanfare MUS_AWAKEN_LEGEND
	playse SE_ORB
	special DoOrbEffect
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterUp
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 150
	removeobject LOCALID_KYOGRE_SLEEPING
	addobject LOCALID_KYOGRE
	waitstate
	delay 60
	applymovement LOCALID_KYOGRE, SeafloorCavern_Room9_Movement_KyogreApproach
	waitmovement 0
	special FadeOutOrbEffect
	waitstate
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	applymovement LOCALID_KYOGRE, SeafloorCavern_Room9_Movement_KyogreExit
	waitmovement 0
	removeobject LOCALID_KYOGRE
	delay 4
	setvar VAR_0x8004, 2  @ vertical pan
	setvar VAR_0x8005, 2  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	delay 30
	setvar VAR_0x8004, LOCALID_ARCHIE
	setvar VAR_0x8005, LOCALID_MAXIE
	setvar VAR_0x8006, LOCALID_GRUNT_1
	setvar VAR_0x8007, LOCALID_GRUNT_2
	msgbox SeafloorCavern_Room9_Text_ArchieWhereDidKyogreGo, MSGBOX_DEFAULT
	playse SE_PC_LOGIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_ArchieAMessageFromOutside, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_0x8004, SeafloorCavern_Room9_Movement_ArchieListenMessage
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_ArchieWhatRainingTooHard, MSGBOX_DEFAULT
	closemessage
	playse SE_PC_OFF
	delay 20
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_ArchieWhyDidKyogreDisappear, MSGBOX_DEFAULT
	closemessage
	addobject VAR_0x8005
	addobject VAR_0x8006
	addobject VAR_0x8007
	applymovement VAR_0x8007, SeafloorCavern_Room9_Movement_MagmaGruntArrive
	applymovement VAR_0x8006, SeafloorCavern_Room9_Movement_MagmaGruntArrive
	applymovement VAR_0x8005, SeafloorCavern_Room9_Movement_MaxieArrive
	waitmovement 0
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_MaxieWhatHaveYouWrought, MSGBOX_DEFAULT
	playse SE_PIN
	applymovement VAR_0x8004, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_0x8004, Common_Movement_Delay48
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_ArchieDontGetAllHighAndMighty, MSGBOX_DEFAULT
	msgbox SeafloorCavern_Room9_Text_MaxieWeDontHaveTimeToArgue, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_0x8005, SeafloorCavern_Room9_Movement_MaxieExit
	applymovement VAR_0x8004, SeafloorCavern_Room9_Movement_ArchieExit
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_MaxieComeOnPlayer, MSGBOX_DEFAULT
	setvar VAR_GARBAGEVAR, 1
	setvar VAR_GARBAGEVAR, 1
	clearflag FLAG_GARBAGEFLAG
	clearflag FLAG_GARBAGEFLAG
	clearflag FLAG_GARBAGEFLAG
	clearflag FLAG_GARBAGEFLAG
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_GROUDON
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_KYOGRE
	setflag FLAG_GARBAGEFLAG
	setflag FLAG_GARBAGEFLAG
	clearflag FLAG_GARBAGEFLAG
	clearflag FLAG_GARBAGEFLAG
	setflag FLAG_SYS_WEATHER_CTRL
	setflag FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN
	setflag FLAG_GARBAGEFLAG
	setvar VAR_STEVENS_HOUSE_STATE, 2
	setvar VAR_SEAFLOOR_CAVERN_STATE, 1
	setflag FLAG_GARBAGEFLAG
	setflag FLAG_GARBAGEFLAG
	setflag FLAG_GARBAGEFLAG
	setflag FLAG_GARBAGEFLAG
	setflag FLAG_GARBAGEFLAG
	setflag FLAG_HIDE_MAP_NAME_POPUP
	warp MAP_ROUTE128, 38, 22
	waitstate
	releaseall
	end

SeafloorCavern_Room9_Movement_ArchieApproachPlayer:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SeafloorCavern_Room9_Movement_Unused1:
	walk_left
	walk_left
	step_end

SeafloorCavern_Room9_Movement_ArchieListenMessage:
	walk_left
	delay_16
	step_end

SeafloorCavern_Room9_Movement_Unused2:
	walk_right
	step_end

SeafloorCavern_Room9_Movement_ArchieExit:
	face_up
	lock_facing_direction
	walk_down
	unlock_facing_direction
	walk_in_place_faster_right
	step_end

SeafloorCavern_Room9_Movement_KyogreApproach:
	delay_16
	delay_16
	walk_slow_down
	delay_16
	delay_16
	delay_16
	walk_slow_down
	delay_16
	delay_16
	delay_16
	step_end

SeafloorCavern_Room9_Movement_KyogreExit:
	slide_up
	slide_up
	step_end

SeafloorCavern_Room9_Movement_MaxieArrive:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

SeafloorCavern_Room9_Movement_MaxieExit:
	walk_right
	walk_right
	step_end

SeafloorCavern_Room9_Movement_MagmaGruntArrive:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

SeafloorCavern_Room9_Movement_Delay32:
	delay_16
	delay_16
	step_end

SeafloorCavern_Room9_Text_ArchieHoldItRightThere:
	.string "ARTHUR: Pas un geste !$"

SeafloorCavern_Room9_Text_ArchieSoItWasYou:
	.string "ARTHUR: Fufufu…\n"
	.string "C'était donc toi, finalement.$"

SeafloorCavern_Room9_Text_ArchieBeholdKyogre:
	.string "ARTHUR: Admire !\p"
	.string "Regarde comme il est magnifique, le\n"
	.string "POKéMON ancestral KYOGRE endormi !\p"
	.string "J'ai attendu si longtemps ce jour…$"

SeafloorCavern_Room9_Text_ArchieYouMustDisappear:
	.string "ARTHUR: Je suis surpris que tu aies\n"
	.string "réussi à me poursuivre jusqu'ici.\p"
	.string "Mais tout cela est terminé maintenant.\p"
	.string "Pour réaliser mon rêve,\n"
	.string "tu dois disparaître !$"

SeafloorCavern_Room9_Text_ArchieDefeat:
	.string "Quoi ?!\n"
	.string "J'ai perdu face à un simple enfant comme toi ?!$"

SeafloorCavern_Room9_Text_ArchieWithThisRedOrb:
	.string "ARTHUR: Fufufu…\p"
	.string "Je te félicite. Je dois reconnaître que\n"
	.string "tu es vraiment doué.\p"
	.string "Mais !\n"
	.string "J'ai ceci en ma possession !\p"
	.string "Avec cette ORBE ROUGE, je peux contrôler KYOGRE…$"

SeafloorCavern_Room9_Text_RedOrbShinesByItself:
	.string "L'ORBE ROUGE s'est soudainement mise\n"
	.string "à briller toute seule !$"

SeafloorCavern_Room9_Text_ArchieWhereDidKyogreGo:
	.string "ARTHUR: Quoi ?!\p"
	.string "Je n'ai rien fait.\n"
	.string "Pourquoi l'ORBE ROUGE…\p"
	.string "Où est passé KYOGRE ?$"

SeafloorCavern_Room9_Text_ArchieAMessageFromOutside:
	.string "ARTHUR: Hein ? Un message de nos\n"
	.string "membres à l'extérieur…$"

SeafloorCavern_Room9_Text_ArchieWhatRainingTooHard:
	.string "ARTHUR: Oui, que se passe-t-il ?\p"
	.string "Hmm…\n"
	.string "Il pleut beaucoup ?\p"
	.string "Bien… C'est ce qui devait arriver.\n"
	.string "C'est pour cela que nous avons réveillé KYOGRE,\l"
	.string "pour réaliser le rêve de la TEAM AQUA :\l"
	.string "étendre la mer.\p"
	.string "Quoi ?!\p"
	.string "Il pleut bien plus fort que prévu ?\n"
	.string "Vous êtes en danger ?\p"
	.string "Ce n'est pas possible…\n"
	.string "C'est impossible…\p"
	.string "Restez en position et surveillez\n"
	.string "la situation !$"

SeafloorCavern_Room9_Text_ArchieWhyDidKyogreDisappear:
	.string "ARTHUR: Il y a un problème…\p"
	.string "L'ORBE ROUGE est censée réveiller\n"
	.string "et contrôler KYOGRE…\p"
	.string "Mais… Pourquoi ?\n"
	.string "Pourquoi KYOGRE a-t-il disparu ?\p"
	.string "Pourquoi ?!$"

SeafloorCavern_Room9_Text_MaxieWhatHaveYouWrought:
	.string "MAX: Qu'as-tu fait ?\p"
	.string "ARTHUR… Tu as finalement réveillé KYOGRE,\n"
	.string "n'est-ce pas ?\p"
	.string "Que va-t-il arriver au monde si cette\n"
	.string "pluie diluvienne ne s'arrête jamais ?\p"
	.string "Les terres du monde seront englouties\n"
	.string "par la mer qui monte…$"

SeafloorCavern_Room9_Text_ArchieDontGetAllHighAndMighty:
	.string "ARTHUR: Q-quoi ?!\n"
	.string "Ne prends pas cet air supérieur avec moi !\p"
	.string "N'est-ce pas vous, la TEAM MAGMA,\n"
	.string "qui avez mis GROUDON en colère ?\p"
	.string "Tant que j'ai cette ORBE ROUGE,\n"
	.string "je devrais pouvoir contrôler KYOGRE…\p"
	.string "Je devrais pouvoir le contrôler…$"

SeafloorCavern_Room9_Text_MaxieWeDontHaveTimeToArgue:
	.string "MAX: Nous n'avons pas le temps de\n"
	.string "nous disputer ici !\p"
	.string "Sors et va voir par toi-même !\p"
	.string "Regarde si ce que tu as provoqué est\n"
	.string "le monde que nous désirions !$"

SeafloorCavern_Room9_Text_MaxieComeOnPlayer:
	.string "MAX: {PLAYER}, viens, toi aussi tu dois\n"
	.string "sortir d'ici !$"
