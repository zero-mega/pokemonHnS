.set LOCALID_OWNER, 1

LilycoveCity_CoveLilyMotel_1F_MapScripts::
	.byte 0

LilycoveCity_CoveLilyMotel_1F_EventScript_MotelOwner::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_CoveLilyMotel_1F_EventScript_GameClear
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_CoveLilyMotel_1F_EventScript_AquaHideoutBusted
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_GuestsDoubledByMascot, MSGBOX_DEFAULT
	applymovement LOCALID_OWNER, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_NoGuestsWithTeamAqua, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_OWNER, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

LilycoveCity_CoveLilyMotel_1F_EventScript_AquaHideoutBusted::
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_MonFoundLostItem, MSGBOX_DEFAULT
	applymovement LOCALID_OWNER, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_HeardAquaHideoutBusted, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_OWNER, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

LilycoveCity_CoveLilyMotel_1F_EventScript_GameClear::
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_HouseSittingMonCaughtBurglar, MSGBOX_DEFAULT
	applymovement LOCALID_OWNER, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_BetterGetWorkingOnGuestsDinner, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_OWNER, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

LilycoveCity_CoveLilyMotel_1F_EventScript_BlockingTV::
	lockall
	playse SE_PIN
	applymovement LOCALID_OWNER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_OWNER, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_CantSeeTheTV, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, LilycoveCity_CoveLilyMotel_1F_Movement_PlayerPushFromTV
	applymovement LOCALID_OWNER, LilycoveCity_CoveLilyMotel_1F_Movement_OwnerPushPlayer
	waitmovement 0
	applymovement LOCALID_OWNER, LilycoveCity_CoveLilyMotel_1F_Movement_OwnerReturn
	waitmovement 0
	release
	end

LilycoveCity_CoveLilyMotel_1F_Movement_PlayerPushFromTV:
	face_right
	lock_facing_direction
	walk_left
	unlock_facing_direction
	step_end

LilycoveCity_CoveLilyMotel_1F_Movement_OwnerPushPlayer:
	walk_up
	step_end

LilycoveCity_CoveLilyMotel_1F_Movement_OwnerReturn:
	face_down
	walk_down
	face_up
	step_end

LilycoveCity_CoveLilyMotel_1F_Text_GuestsDoubledByMascot:
	.string "Hmm, alors ils ont doublé le nombre de clients\n"
	.string "en utilisant des POKéMON comme attractions ?\p"
	.string "Hmm, peut-être que je devrais faire d’un POKéMON\n"
	.string "mignon la mascotte de notre auberge.\p"
	.string "Je me demande si cela attirera plus de clients\n"
	.string "chez nous.$"

LilycoveCity_CoveLilyMotel_1F_Text_NoGuestsWithTeamAqua:
	.string "Oh, pardon, pardon !\n"
	.string "J’étais trop absorbé par la télévision !\p"
	.string "Depuis que la TEAM AQUA est arrivée en ville,\n"
	.string "les touristes évitent de venir.$"

LilycoveCity_CoveLilyMotel_1F_Text_CantSeeTheTV:
	.string "Hé, baisse-toi devant !\n"
	.string "Je ne vois pas la télé !$"

LilycoveCity_CoveLilyMotel_1F_Text_MonFoundLostItem:
	.string "Incroyable ! Tu me dis qu’un POKéMON\n"
	.string "a retrouvé un objet perdu ?\p"
	.string "C’est impressionnant. Si nous avions des POKéMON\n"
	.string "aussi malins…\p"
	.string "Nous pourrions retrouver tout ce que nos clients\n"
	.string "égarent…$"

LilycoveCity_CoveLilyMotel_1F_Text_HeardAquaHideoutBusted:
	.string "Oh, pardon, pardon !\n"
	.string "J’étais trop absorbé par la télévision !\p"
	.string "J’ai entendu dire que quelqu’un a démantelé\n"
	.string "la planque de la TEAM AQUA.\p"
	.string "Grâce à ça, nous venons de recevoir une\n"
	.string "réservation d’un grand groupe.\p"
	.string "C’était une entreprise appelée… Euh…\n"
	.string "GAME quelque chose…$"

LilycoveCity_CoveLilyMotel_1F_Text_HouseSittingMonCaughtBurglar:
	.string "Incroyable ! Un POKéMON gardien de maison\n"
	.string "a attrapé un cambrioleur ?\p"
	.string "C’est impressionnant. Si nous avions un POKéMON\n"
	.string "costaud comme garde de sécurité…\p"
	.string "Nous pourrions offrir à nos clients\n"
	.string "une sécurité accrue.$"

LilycoveCity_CoveLilyMotel_1F_Text_BetterGetWorkingOnGuestsDinner:
	.string "Oh, pardon, pardon !\n"
	.string "J’étais trop absorbé par la télévision.\p"
	.string "Oh, oui. Un grand groupe de clients est arrivé\n"
	.string "il y a peu de temps.\p"
	.string "Ils se sont inscrits sous le nom de GAME FREAK,\n"
	.string "alors je suppose qu’ils font des jeux.\p"
	.string "Oh là là, je ferais mieux de préparer\n"
	.string "leur dîner !$"
