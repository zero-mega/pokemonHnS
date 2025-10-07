RuinsOfAlph_Outside_MapScripts::
	.byte 0

RuinsOfAlph_Outside_EventScript_Quagsire::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_QUAGSIRE, CRY_MODE_NORMAL
	msgbox RuinsOfAlph_Outside_Text_Quagsire, MSGBOX_DEFAULT
	waitmoncry
	release
	end

RuinsOfAlph_Outside_Text_Quagsire:
	.string "QUAGSIRE: Quag Quag$"

RuinsOfAlph_Outside_EventScript_Stan::
	trainerbattle_single TRAINER_STAN, RuinsOfAlph_Outside_Text_SuperNerdStan_Seen, RuinsOfAlph_Outside_Text_SuperNerdStan_Beaten
	msgbox RuinsOfAlph_Outside_Text_SuperNerdStan_After, MSGBOX_AUTOCLOSE
	end

RuinsOfAlph_Outside_EventScript_Nathan::
	trainerbattle_single TRAINER_NATHAN, RuinsOfAlph_Outside_Text_PsychicNathan_Seen, RuinsOfAlph_Outside_Text_PsychicNathan_Beaten
	msgbox RuinsOfAlph_Outside_Text_PsychicNathan_After, MSGBOX_AUTOCLOSE
	end

RuinsOfAlph_Outside_EventScript_Youngster1::
	lock
	faceplayer
	msgbox RuinsOfAlph_Outside_Text_Youngster1, MSGBOX_DEFAULT
	closemessage
	release
	end

RuinsOfAlph_Outside_EventScript_Youngster2::
	lock
	faceplayer
	msgbox RuinsOfAlph_Outside_Text_Youngster2, MSGBOX_DEFAULT
	closemessage
	release
	end

RuinsOfAlph_Outside_EventScript_Fisher1::
	lock
	faceplayer
	msgbox RuinsOfAlph_Outside_Text_Fisher1, MSGBOX_DEFAULT
	closemessage
	release
	end

RuinsOfAlph_Outside_EventScript_Fisher2::
	lock
	faceplayer
	msgbox RuinsOfAlph_Outside_Text_Fisher2, MSGBOX_DEFAULT
	closemessage
	release
	end

RuinsOfAlph_Outside_EventScript_Sign1::
	lock
	msgbox RuinsOfAlph_Outside_Text_MainSign, MSGBOX_SIGN
	closemessage
	release
	end

RuinsOfAlph_Outside_EventScript_Sign2::
	lock
	msgbox RuinsOfAlph_Outside_Text_ResearchSign, MSGBOX_SIGN
	closemessage
	release
	end

RuinsOfAlph_Outside_EventScript_Sign3::
	lock
	msgbox RuinsOfAlph_Outside_Text_MysteryChamberSign, MSGBOX_SIGN
	closemessage
	release
	end

RuinsOfAlph_Outside_Text_Scientist:
	.string "Hm ? C'est un Pokédex, n'est-ce pas ?\n"
	.string "Puis-je le voir ?\p"
	.string "Il existe tant d'espèces de\n"
	.string "Pokémon.\p"
	.string "Hm ? Qu'est-ce que c'est ?\p"
	.string "Quel est ce Pokémon ?\p"
	.string "On dirait les étranges\n"
	.string "inscriptions sur les murs des\p"
	.string "RUINES.\p"
	.string "Si ces dessins sont vraiment des\n"
	.string "Pokémon, il devrait y en avoir\n"
	.string "beaucoup d'autres.\p"
	.string "Je sais ! Laisse-moi améliorer ton\n"
	.string "Pokédex. Suis-moi.$"

RuinsOfAlph_Outside_Text_SuperNerdStan_Seen:
	.string "Que veux-tu ? J'étudie--\n"
	.string "ne me dérange pas !$"

RuinsOfAlph_Outside_Text_SuperNerdStan_Beaten:
	.string "Désolé…\n"
	.string "Je suis frustré par notre manque de\p"
	.string "compréhension réelle…$"

RuinsOfAlph_Outside_Text_SuperNerdStan_After:
	.string "Les RUINES datent d'environ 1500\n"
	.string "ans.\p"
	.string "Personne ne sait qui les a construites.\p"
	.string "On ne sait pas non plus si les statues\n"
	.string "Pokémon ont une signification.\p"
	.string "Tout cela reste un grand mystère…$"

RuinsOfAlph_Outside_Text_PsychicNathan_Seen:
	.string "Hmmm… Cet endroit est étrange.$"

RuinsOfAlph_Outside_Text_PsychicNathan_Beaten:
	.string "…$"

RuinsOfAlph_Outside_Text_PsychicNathan_After:
	.string "J'aime réfléchir ici.$"

RuinsOfAlph_Outside_Text_MysteryChamberSign:
	.string "SALLE DU PANNEAU DE PIERRE MYSTÉRIEUX$"

RuinsOfAlph_Outside_Text_MainSign:
	.string "RUINES D'ALPH\n"
	.string "VISITEURS BIENVENUS$"

RuinsOfAlph_Outside_Text_ResearchSign:
	.string "CENTRE DE RECHERCHE DES RUINES D'ALPH\p"
	.string "L'AUTORITÉ SUR LES\n"
	.string "RUINES D'ALPH$"

RuinsOfAlph_Outside_Text_Fisher1:
	.string "En explorant les RUINES, nous avons\n"
	.string "soudain ressenti une étrange présence.\p"
	.string "Nous avons tous eu peur et nous sommes enfuis.\n"
	.string "Toi aussi, sois prudent.$"

RuinsOfAlph_Outside_Text_Fisher2:
	.string "Les RUINES cachent un énorme secret !\p"
	.string "…Je crois…$"

RuinsOfAlph_Outside_Text_Youngster1:
	.string "Il existe de nombreux types d'UNOWN, alors\n"
	.string "nous les utilisons pour nos codes secrets.$"

RuinsOfAlph_Outside_Text_Youngster2:
	.string "A… H… E… A… D… Hmm…\p"
	.string "Quoi ?\p"
	.string "Je déchiffre ce message !$"
