CianwoodHouse3_MapScripts::
	.byte 0

CianwoodCity_EventScript_Kirk::
	lock
	faceplayer
	goto_if_eq VAR_SHUCKIE, 1, CianwoodCity_EventScript_KirkGivenShuckie
	goto_if_eq VAR_SHUCKIE, 2, CianwoodCity_EventScript_KirkReturnShuckie
	goto_if_eq VAR_SHUCKIE, 3, CianwoodCity_EventScript_KirkReturnedShuckie
	msgbox CianwoodCity_Text_ManiacAskShuckle, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, CianwoodCity_EventScript_KirkDeclined

	@HnS named gift pokemon setup
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_SHUCKLE
	bufferspeciesname STR_VAR_1, SPECIES_SHUCKLE
	givenamedmon 2
	call Common_EventScript_GiftMonNamed

	setvar VAR_SHUCKIE, 1
	release
	end

CianwoodCity_EventScript_KirkDeclined::
	msgbox CianwoodCity_Text_ManiacIfHeComesBack, MSGBOX_DEFAULT
	closemessage
	end

CianwoodCity_EventScript_KirkGivenShuckie::
	msgbox CianwoodCity_Text_ManiacHowsdoing, MSGBOX_DEFAULT
	closemessage
	end

CianwoodCity_EventScript_KirkReturnShuckie::
	msgbox CianwoodCity_Text_ManiacAskReturn, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, CianwoodCity_EventScript_KirkDeclineReturnShuckie
	removenamedmon 2
	goto_if_eq VAR_RESULT, MON_CANT_GIVE, CianwoodCity_EventScript_KirkNotRight
	goto_if_eq VAR_RESULT, 3, CianwoodCity_EventScript_KirkKeepShuckie
	playse MUS_OBTAIN_ITEM
	callnative UpdateFollowingPokemon
	msgbox CianwoodCity_Text_ManiacReturnedMon, MSGBOX_DEFAULT
	waitse
	msgbox CianwoodCity_Text_ManiacThankYou, MSGBOX_DEFAULT
	setvar VAR_SHUCKIE, 3
	release
	end

CianwoodCity_EventScript_KirkDeclineReturnShuckie::
	msgbox CianwoodCity_Text_ManiacRobbed2, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodCity_EventScript_KirkNotRight::
	msgbox CianwoodCity_Text_ManiacRobbed, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodCity_EventScript_KirkKeepShuckie::
	msgbox CianwoodCity_Text_ManiacShuckleLikesYou, MSGBOX_DEFAULT
	closemessage
	setvar VAR_SHUCKIE, 3
	release
	end

CianwoodCity_EventScript_KirkReturnedShuckie::
	msgbox CianwoodCity_Text_ManiacHappinessSpeech, MSGBOX_DEFAULT
	closemessage
	end

CianwoodCity_Text_ManiacAskShuckle:
	.string "J-je suis sous le choc !\p"
	.string "Un garçon à peu près de ton âge,\n"
	.string "avec des yeux perçants et de longs cheveux,\p"
	.string "est entré. Il m'a fait tellement peur\n"
	.string "que je lui ai donné mon précieux POKéMON !\p"
	.string "Il m'en reste un, mais s'il revient ?\p"
	.string "Tu as l'air fort. Peux-tu garder\n"
	.string "mon POKéMON pendant un moment ?$"

CianwoodCity_Text_ManiacTakeCareShuckle:
	.string "Oh, merci !\p"
	.string "Prends-en bien soin, s'il te plaît !$"

CianwoodCity_Text_ManiacGotShuckle:
	.string "{PLAYER} a reçu un POKéMON.$"

CianwoodCity_Text_ManiacPartyFull:
	.string "Ton équipe de POKéMON est pleine.$"

CianwoodCity_Text_ManiacIfHeComesBack:
	.string "Oh, non… Que ferai-je s'il revient ?$"

CianwoodCity_Text_ManiacHowsdoing:
	.string "Salut ! Comment va mon POKéMON ?$"

CianwoodCity_Text_ManiacAskReturn:
	.string "Salut ! Comment va mon POKéMON ?\p"
	.string "Je pense que je suis en sécurité maintenant,\n"
	.string "alors puis-je le récupérer ?$"

CianwoodCity_Text_ManiacThankYou:
	.string "Merci !$"

CianwoodCity_Text_ManiacShuckleNotThere:
	.string "Hé, tu n'as pas mon POKéMON\n"
	.string "avec toi.$"

CianwoodCity_Text_ManiacShuckleLikesYou:
	.string "Mon POKéMON s'est attaché à toi.\p"
	.string "Très bien, tu devrais le garder.\p"
	.string "Mais promets-moi d'en prendre soin !$"

CianwoodCity_Text_ManiacRobbed:
	.string "Hein, quelque chose ne va pas.$"

CianwoodCity_Text_ManiacRobbed2:
	.string "Oh, non, non… C'est comme si\n"
	.string "on m'avait volé.$"

CianwoodCity_Text_ManiacHappinessSpeech:
	.string "Pour les POKéMON, le bonheur c'est d'être\n"
	.string "avec quelqu'un qui les traite bien.$"

CianwoodCity_Text_ManiacLastMon:
	.string "Si je reprends mon POKéMON,\n"
	.string "qu'utiliseras-tu pour te battre ?$"

CianwoodCity_Text_ManiacReturnedMon:
	.string "{PLAYER} a rendu SHUCKIE.$"
