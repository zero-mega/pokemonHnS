.set LOCALID_VIVI, 1
.set LOCALID_VICTOR, 2
.set LOCALID_VICTORIA, 3
.set LOCALID_VICKY, 4

Route111_WinstrateFamilysHouse_MapScripts::
	.byte 0

Route111_WinstrateFamilysHouse_EventScript_Victor::
	lock
	faceplayer
	setvar VAR_0x8008, LOCALID_VICTOR
	msgbox Route111_WinstrateFamilysHouse_Text_MySonIsStrongerThanYou, MSGBOX_DEFAULT
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_Victoria::
	lock
	faceplayer
	setvar VAR_0x8008, LOCALID_VICTORIA
	goto_if_set FLAG_RECEIVED_MACHO_BRACE, Route111_WinstrateFamilysHouse_EventScript_ReceivedMachoBrace
	msgbox Route111_WinstrateFamilysHouse_Text_LikeYouToHaveMachoBrace, MSGBOX_DEFAULT
	giveitem ITEM_MACHO_BRACE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_MACHO_BRACE
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_ReceivedMachoBrace::
	msgbox Route111_WinstrateFamilysHouse_Text_PassionateAboutBattles, MSGBOX_DEFAULT
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_Vivi::
	lock
	faceplayer
	setvar VAR_0x8008, LOCALID_VIVI
	msgbox Route111_WinstrateFamilysHouse_Text_StrongerFamilyMembers, MSGBOX_DEFAULT
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_Vicky::
	lock
	faceplayer
	setvar VAR_0x8008, LOCALID_VICKY
	goto_if_set FLAG_TEMP_4, Route111_WinstrateFamilysHouse_EventScript_AlreadySpokenTo
	msgbox Route111_WinstrateFamilysHouse_Text_GrandsonStrong, MSGBOX_DEFAULT
	setflag FLAG_TEMP_4
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_AlreadySpokenTo::
	msgbox Route111_WinstrateFamilysHouse_Text_GrandsonStrongShort, MSGBOX_DEFAULT
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection::
	closemessage
	applymovement VAR_0x8008, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Route111_WinstrateFamilysHouse_Text_MySonIsStrongerThanYou:
	.string "Tu es le premier DRESSEUR que je vois\n"
	.string "qui utilise ses POKéMON avec autant\l"
	.string "de maîtrise.\p"
	.string "Mais, je dois te dire—mon fils est\n"
	.string "plus fort que toi.\p"
	.string "Il a même relevé le défi de la LIGUE\n"
	.string "POKéMON, tu sais.$"

Route111_WinstrateFamilysHouse_Text_LikeYouToHaveMachoBrace:
	.string "Nous utilisons ce BRACELET MACHO pour\n"
	.string "renforcer plus efficacement nos POKéMON\l"
	.string "à l'entraînement.\p"
	.string "Puisque tu nous as tous battus ici,\n"
	.string "je ne sais pas si tu en as besoin, mais\l"
	.string "nous aimerions t'offrir notre BRACELET MACHO.$"

Route111_WinstrateFamilysHouse_Text_PassionateAboutBattles:
	.string "Quand il s'agit de combats POKéMON,\n"
	.string "nous sommes plutôt passionnés.$"

Route111_WinstrateFamilysHouse_Text_StrongerFamilyMembers:
	.string "Maman est plus forte que Papa.\p"
	.string "Je suis plus forte que Maman.\p"
	.string "Et Mamie est plus forte que moi !\p"
	.string "Mais mon grand frère est encore plus\n"
	.string "fort que Mamie.$"

Route111_WinstrateFamilysHouse_Text_GrandsonStrong:
	.string "Il ne fait aucun doute que tu es fort.\p"
	.string "Mais si tu affrontais mon petit-fils,\n"
	.string "tu finirais en larmes de frustration.\p"
	.string "Il est bien plus fort que n'importe\n"
	.string "quel DRESSEUR que notre famille connaît.\p"
	.string "Il doit être en train de défier le\n"
	.string "CHAMPION DE LA LIGUE POKéMON en ce moment.\p"
	.string "Connaissant mon petit-fils, il est peut-être\n"
	.string "déjà le CHAMPION !$"

Route111_WinstrateFamilysHouse_Text_GrandsonStrongShort:
	.string "Mon petit-fils doit être en train de défier\n"
	.string "le CHAMPION DE LA LIGUE POKéMON en ce moment.\p"
	.string "Connaissant mon petit-fils, il est peut-être\n"
	.string "déjà le CHAMPION !$"
