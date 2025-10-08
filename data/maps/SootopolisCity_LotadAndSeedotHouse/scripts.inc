SootopolisCity_LotadAndSeedotHouse_MapScripts::
	.byte 0

SootopolisCity_LotadAndSeedotHouse_EventScript_SeedotBrother::
	special GetSeedotSizeRecordInfo
	lock
	faceplayer
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_PleaseShowMeBigSeedot, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	copyvar VAR_RESULT, VAR_0x8004
	goto_if_eq VAR_RESULT, PARTY_NOTHING_CHOSEN, SootopolisCity_LotadAndSeedotHouse_EventScript_CancelShowSeedot
	special CompareSeedotSize
	bufferunitsystemtext UNIT_TEXT_LENGTH_SMALL_PLURAL, 1
	goto_if_eq VAR_RESULT, 1, SootopolisCity_LotadAndSeedotHouse_EventScript_NotSeedot
	goto_if_eq VAR_RESULT, 2, SootopolisCity_LotadAndSeedotHouse_EventScript_SmallSeedot
	goto_if_eq VAR_RESULT, 3, SootopolisCity_LotadAndSeedotHouse_EventScript_BigSeedot
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_CancelShowSeedot::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_DontHaveBigSeedot, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_NotSeedot::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_ThatsNotSeedot, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_SmallSeedot::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_SeenBiggerSeedot, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_BigSeedot::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_GoshMightBeBiggerThanLotad, MSGBOX_DEFAULT
	giveitem ITEM_ELIXIR
	goto_if_eq VAR_RESULT, FALSE, SootopolisCity_LotadAndSeedotHouse_EventScript_NoRoomForElixir1
	closemessage
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_NoRoomForElixir1::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_BagCrammedFull1, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_LotadBrother::
	special GetLotadSizeRecordInfo
	lock
	faceplayer
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_PleaseShowMeBigLotad, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	copyvar VAR_RESULT, VAR_0x8004
	goto_if_eq VAR_RESULT, PARTY_NOTHING_CHOSEN, SootopolisCity_LotadAndSeedotHouse_EventScript_CancelShowLotad
	special CompareLotadSize
	bufferunitsystemtext UNIT_TEXT_LENGTH_SMALL_PLURAL, 1
	goto_if_eq VAR_RESULT, 1, SootopolisCity_LotadAndSeedotHouse_EventScript_NotLotad
	goto_if_eq VAR_RESULT, 2, SootopolisCity_LotadAndSeedotHouse_EventScript_SmallLotad
	goto_if_eq VAR_RESULT, 3, SootopolisCity_LotadAndSeedotHouse_EventScript_BigLotad
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_CancelShowLotad::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_DontHaveBigLotad, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_NotLotad::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_ThatsNotLotad, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_SmallLotad::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_SeenBiggerLotad, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_BigLotad::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_WowMightBeBiggerThanSeedot, MSGBOX_DEFAULT
	giveitem ITEM_ELIXIR
	goto_if_eq VAR_RESULT, FALSE, SootopolisCity_LotadAndSeedotHouse_EventScript_NoRoomForElixir2
	closemessage
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_NoRoomForElixir2::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_BagCrammedFull2, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_SeedotSizeRecord::
	special GetSeedotSizeRecordInfo
	lockall
	bufferunitsystemtext UNIT_TEXT_LENGTH_SMALL_SINGLE, 1
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_BiggestSeedotInHistory, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_LotadSizeRecord::
	special GetLotadSizeRecordInfo
	lockall
	bufferunitsystemtext UNIT_TEXT_LENGTH_SMALL_SINGLE, 1
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_BiggestLotadInHistory, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_LotadAndSeedotHouse_Text_PleaseShowMeBigSeedot:
	.string "Tu connais le POKéMON GRAINIPIOT ?\n"
	.string "On le voit rarement à ATALANOPOLIS.\p"
	.string "En tout cas, j'adore les gros GRAINIPIOT.\n"
	.string "Plus ils sont gros, mieux c'est.\p"
	.string "Mais mon petit frère dit que\n"
	.string "NÉNUPIOT est plus gros.\p"
	.string "C'est ridicule.\n"
	.string "GRAINIPIOT doit être plus gros que ça !\p"
	.string "Hein ? Tu as un GRAINIPIOT avec toi ?\n"
	.string "S-s-s'il te plaît, montre-le-moi !$"

SootopolisCity_LotadAndSeedotHouse_Text_GoshMightBeBiggerThanLotad:
	.string "{STR_VAR_2} {STR_VAR_1} !\n"
	.string "Oh là là, il est vraiment énorme !\p"
	.string "Il pourrait même battre le grand NÉNUPIOT\n"
	.string "que mon petit frère a vu !\p"
	.string "Merci de me l'avoir montré.\n"
	.string "Tiens, c'est pour toi !$"

@ Unused
SootopolisCity_LotadAndSeedotHouse_Text_ReceivedPotion1:
	.string "{PLAYER} reçoit une POTION.$"

SootopolisCity_LotadAndSeedotHouse_Text_BagCrammedFull1:
	.string "Hein ?\n"
	.string "Ton SAC est plein à craquer.$"

SootopolisCity_LotadAndSeedotHouse_Text_SeenBiggerSeedot:
	.string "{STR_VAR_2} {STR_VAR_1}, c'est ça ?\p"
	.string "Hmm… J'ai déjà vu un GRAINIPIOT\n"
	.string "plus gros que celui-ci.$"

SootopolisCity_LotadAndSeedotHouse_Text_ThatsNotSeedot:
	.string "Oh, c'est impressionnant…\n"
	.string "Mais ce n'est pas un GRAINIPIOT !$"

SootopolisCity_LotadAndSeedotHouse_Text_DontHaveBigSeedot:
	.string "Tu n'as pas de gros GRAINIPIOT ?\n"
	.string "C'est dommage…\p"
	.string "Si tu en trouves un gros, viens\n"
	.string "me le montrer, s'il te plaît.$"

SootopolisCity_LotadAndSeedotHouse_Text_BiggestSeedotInHistory:
	.string "Le plus grand GRAINIPIOT de l'histoire !\n"
	.string "Un géant de {STR_VAR_3}-{STR_VAR_1} de {STR_VAR_2} !\p"
	.string "Un GRAINIPIOT plus gros qu'un NÉNUPIOT,\n"
	.string "c'est tout ce que j'ai toujours voulu !$"

SootopolisCity_LotadAndSeedotHouse_Text_PleaseShowMeBigLotad:
	.string "Tu connais le POKéMON NÉNUPIOT ?\n"
	.string "On le voit rarement à ATALANOPOLIS.\p"
	.string "J'adore, mais alors j'adore, les gros NÉNUPIOT !\p"
	.string "Mon grand frère dit que GRAINIPIOT est\n"
	.string "plus gros.\p"
	.string "Mais c'est faux ! Tout le monde sait que\n"
	.string "NÉNUPIOT est bien plus gros.\p"
	.string "Hein ? Tu as un NÉNUPIOT ?\n"
	.string "S-s-s'il te plaît, montre-le-moi !$"

SootopolisCity_LotadAndSeedotHouse_Text_WowMightBeBiggerThanSeedot:
	.string "{STR_VAR_2} {STR_VAR_1} !\n"
	.string "Waouh, il est énorme !\p"
	.string "Il est peut-être même plus gros que le\n"
	.string "GRAINIPIOT géant que mon grand frère a vu.\p"
	.string "Merci de me l'avoir montré !\n"
	.string "Tiens, c'est pour toi !$"

@ Unused
SootopolisCity_LotadAndSeedotHouse_Text_ReceivedPotion2:
	.string "{PLAYER} reçoit une POTION.$"

SootopolisCity_LotadAndSeedotHouse_Text_BagCrammedFull2:
	.string "Hein ?\n"
	.string "Ton SAC est plein à craquer.$"

SootopolisCity_LotadAndSeedotHouse_Text_SeenBiggerLotad:
	.string "{STR_VAR_2} {STR_VAR_1} ?\p"
	.string "Hmm… J'ai déjà vu un NÉNUPIOT\n"
	.string "plus gros que celui-ci.$"

SootopolisCity_LotadAndSeedotHouse_Text_ThatsNotLotad:
	.string "Eh bien, c'est impressionnant !\n"
	.string "Mais ce n'est pas un NÉNUPIOT !$"

SootopolisCity_LotadAndSeedotHouse_Text_DontHaveBigLotad:
	.string "Tu n'as pas de gros NÉNUPIOT ?\n"
	.string "Comme c'est décevant…\p"
	.string "Si tu en trouves un gros, viens\n"
	.string "me le montrer, s'il te plaît !$"

SootopolisCity_LotadAndSeedotHouse_Text_BiggestLotadInHistory:
	.string "Le plus grand NÉNUPIOT de l'histoire !\n"
	.string "Un colosse de {STR_VAR_3}-{STR_VAR_1} de {STR_VAR_2} !\p"
	.string "Un NÉNUPIOT plus gros qu'un GRAINIPIOT,\n"
	.string "c'est tout ce que j'ai toujours voulu !$"
