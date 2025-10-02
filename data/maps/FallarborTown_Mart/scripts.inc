FallarborTown_Mart_MapScripts::
	.byte 0

FallarborTown_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart 0
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

FallarborTown_Mart_EventScript_Clerk2::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart FallarborTown_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
FallarborTown_Mart_Pokemart:
	.2byte ITEM_X_SPECIAL
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFEND
	.2byte ITEM_DIRE_HIT
	.2byte ITEM_GUARD_SPEC
	.2byte ITEM_NONE
	release
	end

FallarborTown_Mart_EventScript_Woman::
	msgbox FallarborTown_Mart_Text_DecidingSkittyEvolve, MSGBOX_NPC
	end

FallarborTown_Mart_EventScript_PokefanM::
	msgbox FallarborTown_Mart_Text_SellNuggetIFound, MSGBOX_NPC
	end

FallarborTown_Mart_EventScript_Skitty::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SKITTY, CRY_MODE_NORMAL
	msgbox FallarborTown_Mart_Text_Skitty, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FallarborTown_Mart_Text_DecidingSkittyEvolve:
	.string "J'ai du mal à décider si je dois faire\n"
	.string "évoluer mon SKITTY ou non.\p"
	.string "Je dois juste utiliser cette PIERRE LUNE,\n"
	.string "mais c'est tellement difficile à décider…\p"
	.string "Si je le fais évoluer, il deviendra\n"
	.string "beaucoup plus fort.\p"
	.string "Mais il aura aussi l'air très différent.$"

FallarborTown_Mart_Text_Skitty:
	.string "SKITTY : Miaou?$"

FallarborTown_Mart_Text_SellNuggetIFound:
	.string "Ce NUGGET que j'ai trouvé ici…\n"
	.string "Je suppose que je vais devoir le vendre,\l"
	.string "puisqu'il n'a pas d'autre utilité.$"
