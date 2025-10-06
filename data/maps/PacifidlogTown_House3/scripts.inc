PacifidlogTown_House3_MapScripts::
	.byte 0

PacifidlogTown_House3_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_PACIFIDLOG_NPC_TRADE_COMPLETED, PacifidlogTown_House3_EventScript_TradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_HORSEA
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox PacifidlogTown_House3_Text_WillingToTradeIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, PacifidlogTown_House3_EventScript_DeclineTrade
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, PacifidlogTown_House3_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, VAR_0x8009, PacifidlogTown_House3_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox PacifidlogTown_House3_Text_ItsSubtlyDifferentThankYou, MSGBOX_DEFAULT
	setflag FLAG_PACIFIDLOG_NPC_TRADE_COMPLETED
	release
	end

PacifidlogTown_House3_EventScript_DeclineTrade::
	msgbox PacifidlogTown_House3_Text_NotDesperateOrAnything, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House3_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox PacifidlogTown_House3_Text_WontAcceptAnyLessThanRealMon, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House3_EventScript_TradeCompleted::
	msgbox PacifidlogTown_House3_Text_ReallyWantedToGetBagon, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House3_EventScript_Girl::
	msgbox PacifidlogTown_House3_Text_IsThatAPokedex, MSGBOX_NPC
	end

PacifidlogTown_House3_Text_WillingToTradeIt:
	.string "Regarde ce {STR_VAR_2} !\p"
	.string "C'est le {STR_VAR_2} que j'ai attrapé\n"
	.string "hier pour fêter mon anniversaire !\p"
	.string "Oh, je vois que tu le veux !\n"
	.string "Après tout, il n'a pas de prix !\p"
	.string "Voilà ce que je te propose. Je pourrais\n"
	.string "être prêt à l'échanger contre un {STR_VAR_1}.$"

PacifidlogTown_House3_Text_ItsSubtlyDifferentThankYou:
	.string "Oh, donc c'est un {STR_VAR_1} ?\p"
	.string "C'est un peu comme un {STR_VAR_2},\n"
	.string "mais il est subtilement différent.\p"
	.string "Merci !$"

PacifidlogTown_House3_Text_WontAcceptAnyLessThanRealMon:
	.string "Non, non, non ! Je n'accepterai rien\n"
	.string "d'autre qu'un vrai {STR_VAR_1} !$"

PacifidlogTown_House3_Text_NotDesperateOrAnything:
	.string "Oh, donc tu ne veux pas continuer\n"
	.string "cet échange ?\p"
	.string "Pas de souci. Je ne suis pas désespéré\n"
	.string "de faire un échange ou quoi que ce soit.$"

PacifidlogTown_House3_Text_ReallyWantedToGetBagon:
	.string "Je sais que je pourrais en chercher un\n"
	.string "par moi-même, mais…\p"
	.string "Mais je voulais vraiment obtenir un BAGON\n"
	.string "qu'un autre DRESSEUR a attrapé…$"

PacifidlogTown_House3_Text_IsThatAPokedex:
	.string "C'est un POKéDEX ?\p"
	.string "Tu as pu rencontrer beaucoup de\n"
	.string "POKéMON différents ?\p"
	.string "J'aimerais être comme toi.$"
