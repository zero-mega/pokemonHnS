MossdeepCity_House1_MapScripts::
	.byte 0

MossdeepCity_House1_EventScript_BlackBelt::
	lock
	faceplayer
	bufferleadmonspeciesname STR_VAR_1
	msgbox MossdeepCity_House1_Text_HmmYourPokemon, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GetPokeblockNameByMonNature
	goto_if_eq VAR_RESULT, 0, MossdeepCity_House1_EventScript_NeutralNature
	msgbox MossdeepCity_House1_Text_ItLikesXPokeblocks, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House1_EventScript_NeutralNature::
	msgbox MossdeepCity_House1_Text_DoesntLikeOrDislikePokeblocks, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House1_EventScript_Woman::
	msgbox MossdeepCity_House1_Text_HusbandCanTellPokeblockMonLikes, MSGBOX_NPC
	end

MossdeepCity_House1_Text_HmmYourPokemon:
	.string "Hmm !\n"
	.string "Ton {STR_VAR_1}…$"

MossdeepCity_House1_Text_ItLikesXPokeblocks:
	.string "Il aime les {STR_VAR_1}S,\n"
	.string "n'est-ce pas ?\p"
	.string "Non, j'en suis certain ! Il aime\n"
	.string "vraiment les {STR_VAR_1}S !$"

MossdeepCity_House1_Text_DoesntLikeOrDislikePokeblocks:
	.string "Il ne semble ni aimer ni détester\n"
	.string "aucun {POKEBLOCK}.$"

MossdeepCity_House1_Text_HusbandCanTellPokeblockMonLikes:
	.string "Mon mari peut dire d'un coup d'œil\n"
	.string "quel type de {POKEBLOCK} un POKéMON aime.$"

