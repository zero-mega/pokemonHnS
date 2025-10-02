.set LOCALID_NURSE, 1

GoldenrodCity_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, GoldenrodCity_PokemonCenter_OnTransition
	.byte 0

GoldenrodCity_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_GOLDENROD_CITY
	end

GoldenrodCity_PokemonCenter_EventScript_GbaKid1::
	lock
	faceplayer
	msgbox GoldenrodCity_PokemonCenter_GameboyKidText1, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_PokemonCenter_EventScript_GbaKid2::
	lock
	faceplayer
	msgbox GoldenrodCity_PokemonCenter_GameboyKidText2, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_PokemonCenter_EventScript_Granny::
	lock
	faceplayer
	msgbox GoldenrodCity_PokemonCenter_GrannyText, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_PokemonCenter_EventScript_Lass::
	lock
	faceplayer
	msgbox GoldenrodCity_PokemonCenter_LassText, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_PokemonCenter_GrannyText:
    .string "J'adore vivre dans la grande ville !\n"
    .string "Je suis venue ici quand j'étais une\l"
    .string "jeune dresseuse, comme toi !$"

GoldenrodCity_PokemonCenter_GameboyKidText1:
    .string "Ceci est un CENTRE POKéMON spécial.\n"
    .string "Le toit est en or !$"

GoldenrodCity_PokemonCenter_GameboyKidText2:
    .string "J'ai dit à mon frère que le toit est\n"
    .string "en vrai or. Il croit\l"
    .string "n'importe quoi !$"

GoldenrodCity_PokemonCenter_LassText:
    .string "Un POKéMON de niveau plus élevé ne\n"
    .string "gagne pas toujours.\p"
    .string "Après tout, il peut avoir un\n"
    .string "désavantage de type.\p"
    .string "Je ne pense pas qu'il existe un seul\n"
    .string "POKéMON qui soit le plus fort.$"

GoldenrodPokeCenter_LinkReceptionistPleaseAcceptGSBallText:
    .string "{PLAYER}, n'est-ce pas ?\p"
    .string "Félicitations !\p"
    .string "En offre spéciale, une GS BALL a été\n"
    .string "envoyée juste pour toi !\p"
    .string "Veuillez l'accepter !$"

GoldenrodPokeCenter_LinkReceptionistPleaseDoComeAgainText:
    .string "Revenez nous voir !$"

GoldenrodCity_PokemonCenter_PokefanFDoYouHaveEonMailText:
    .string "Oh là là, ton sac a l'air si lourd !\p"
    .string "Oh ! Tu aurais quelque chose\n"
    .string "appelé COURRIER ÉON ?\p"
    .string "Ma fille en cherche un.\p"
    .string "Tu pourrais t'en séparer, non ?$"

GoldenrodCity_PokemonCenter_AskGiveAwayAnEonMailText:
    .string "Donner un COURRIER ÉON ?$"

GoldenrodCity_PokemonCenter_PokefanFThisIsForYouText:
    .string "Oh, c'est super ! Merci,\n"
    .string "mon chou !\p"
    .string "Tiens, ceci est pour toi en retour !$"

GoldenrodCity_PokemonCenter_PokefanFDaughterWillBeDelightedText:
    .string "Ma fille sera ravie !$"

GoldenrodCity_PokemonCenter_PokefanFTooBadText:
    .string "Oh ? Tu n'en as pas ? Dommage.$"

GoldenrodCity_PokemonCenter_PokefanFAnotherTimeThenText:
    .string "Oh… Bon, une autre fois alors.$"

GoldenrodCity_PokemonCenter_PlayerGaveAwayTheEonMailText:
    .string "{PLAYER} a donné le COURRIER ÉON.$"
