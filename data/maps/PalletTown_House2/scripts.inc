PalletTown_House2_MapScripts::
	.byte 0

PalletTown_House2_EventScript_Daisy::
	lock
	faceplayer
	goto_if_unset FLAG_HIDE_CINNABAR_BLUE, PalletTown_House2_EventScript_Blue
	goto_if_unset FLAG_DAILY_DAISY_GROOMED, PalletTown_House2_EventScript_DaisyGrooming
	msgbox PalletTown_House2_Text_AlreadyGroomed, MSGBOX_DEFAULT
	closemessage
	release
	end

PalletTown_House2_EventScript_Blue::
	msgbox PalletTown_House2_Text_Hello, MSGBOX_DEFAULT
	closemessage
	release
	end

PalletTown_House2_EventScript_DaisyDeclineGrooming::
	msgbox PalletTown_House2_Text_Refused, MSGBOX_DEFAULT
	closemessage
	release
	end
PalletTown_House2_EventScript_Egg::
	msgbox PalletTown_House2_Text_CantGroomEgg, MSGBOX_DEFAULT
	closemessage
	release
	end

PalletTown_House2_EventScript_DaisyGrooming::
	msgbox PalletTown_House2_Text_OfferGrooming, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, PalletTown_House2_EventScript_DaisyDeclineGrooming
	msgbox PalletTown_House2_Text_WhichMon, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	lock
	faceplayer
	bufferpartymonnick STR_VAR_1, VAR_0x8004
	goto_if_ge VAR_0x8004, PARTY_SIZE, PalletTown_House2_EventScript_DaisyDeclineGrooming
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, PalletTown_House2_EventScript_Egg
	goto_if_eq VAR_RESULT, FALSE, PalletTown_House2_EventScript_DaisyDeclineGrooming
	
	msgbox PalletTown_House2_Text_Alright
	closemessage
	fadescreen FADE_TO_BLACK
	playfanfare MUS_HEAL
	waitfanfare
	special HaircutBrother1
	fadescreen FADE_FROM_BLACK
	special BufferMonNickname
	msgbox PalletTown_House2_Text_AllDone
	setflag FLAG_DAILY_DAISY_GROOMED
	release
	end

PalletTown_House2_Text_Hello:
	.string "DAISY : Salut ! Mon petit frère est le\n"
	.string "CHAMPION d'ARENE à JADIEL.\p"
	.string "Mais il part si souvent en voyage\n"
	.string "que ça pose des problèmes aux\l"
	.string "dresseurs.$"

PalletTown_House2_Text_OfferGrooming:
	.string "DAISY : Salut ! Tu tombes bien. Je vais\n"
	.string "prendre un peu de thé.\p"
	.string "Veux-tu te joindre à moi ?\p"
	.string "Oh, tes POKéMON sont un peu sales.\p"
	.string "Veux-tu que j'en toilette un ?$"

PalletTown_House2_Text_WhichMon:
	.string "DAISY : Lequel veux-tu que je toilette ?$"

PalletTown_House2_Text_Alright:
	.string "DAISY : D'accord, je vais le rendre\n"
	.string "tout beau en un rien de temps.$"

PalletTown_House2_Text_AllDone:
	.string "DAISY : Voilà ! C'est terminé.\p"
	.string "Tu vois ? {STR_VAR_1} n'est-il pas\n"
	.string "joli ?\p"
	.string "C'est un POKéMON tellement mignon.$"

PalletTown_House2_Text_AlreadyGroomed:
	.string "DAISY : Je prends toujours le thé à\n"
	.string "cette heure-ci. Viens avec moi.$"

PalletTown_House2_Text_Refused:
	.string "DAISY : Tu ne veux pas que j'en\n"
	.string "toilette un ?\p"
	.string "D'accord, prenons juste le thé.$"

PalletTown_House2_Text_CantGroomEgg:
	.string "DAISY : Oh, désolée. Je ne peux\n"
	.string "vraiment pas toiletter un OEUF.$"
