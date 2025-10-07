Route27_House_MapScripts::
	.byte 0

Route27_House_EventScript_Woman::
	lock
	faceplayer
	goto_if_unset FLAG_GOT_TM_SANDSTORM, Route27_House_EventScript_WomanBeforeGiven
	msgbox SandstormHouse_Text_TM37Description, MSGBOX_DEFAULT
	closemessage
	release
	end

Route27_House_EventScript_WomanBeforeGiven::
	msgbox SandstormHouse_Text_Woman1, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	goto_if_ge VAR_RESULT, FRIENDSHIP_150_TO_199, Route27_House_EventScript_WomanHighFriendship
	playfirstmoncry
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerLookAway
	waitmovement OBJ_EVENT_ID_FOLLOWER
	applymovement OBJ_EVENT_ID_FOLLOWER Common_Movement_QuestionMark
	waitmovement 0
	msgbox SandstormHouse_Text_DisloyalMon, MSGBOX_DEFAULT
	closemessage
	release
	end

Route27_House_EventScript_WomanHighFriendship::
	playfirstmoncry
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerDance
	waitmovement 0
	applymovement OBJ_EVENT_ID_FOLLOWER ContestHall_Movement_Heart
	waitmovement 0
	msgbox SandstormHouse_Text_LoyalMon, MSGBOX_DEFAULT
	giveitem ITEM_TM_SANDSTORM
	setflag FLAG_GOT_TM_SANDSTORM
	msgbox SandstormHouse_Text_TM37Description, MSGBOX_DEFAULT
	closemessage
	release
	end

Route27_Movement_FollowerJump:
	jump_in_place_down
	jump_in_place_down
	step_end

SandstormHouse_Text_Woman1:
    .string "Où vas-tu avec tes\n"
    .string "POKéMON ?\p"
    .string "LA LIGUE POKéMON ?\p"
    .string "Tes POKéMON sont-ils assez loyaux\n"
    .string "pour que tu gagnes ?\p"
    .string "Laisse-moi voir…$"

SandstormHouse_Text_LoyalMon:
    .string "Ah ! Ton POKéMON te fait vraiment\n"
    .string "confiance.\p"
    .string "C'est agréable de voir un bon dresseur.\p"
    .string "Tiens. Un cadeau pour ton voyage.$"

SandstormHouse_Text_TM37Description:
    .string "La CT37, c'est TEMPÊTE DE SABLE.\p"
    .string "C'est une capacité qui inflige des\n"
    .string "dégâts aux deux combattants.\p"
    .string "C'est réservé aux dresseurs avancés.\p"
    .string "Utilise-la si tu l'oses. Bonne chance !$"

SandstormHouse_Text_DisloyalMon:
    .string "S'il ne te fait pas encore assez\n"
    .string "confiance, ce sera difficile.\p"
    .string "La confiance lie les POKéMON et\n"
    .string "leurs dresseurs.$"


