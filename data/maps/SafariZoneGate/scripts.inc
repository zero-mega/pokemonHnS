SafariZoneGate_MapScripts::
	.byte 0

SafariZoneGate_EventScript_Trigger::
	clearflag FLAG_SAFARI_ZONE_WEST_EXPANSION
	clearflag FLAG_SAFARI_ZONE_EAST_EXPANSION
	setflag FLAG_VISITED_SAFARI_ZONE_GATE
	setvar VAR_SAFARI_ZONE_GATE_STATE, 3
	end

SafariZoneGate_EventScript_WorkerM::
	lock
	faceplayer
	msgbox SafariZone_Text_ForeignFeeling, MSGBOX_DEFAULT
	closemessage
	release
	end

SafariZoneGate_EventScript_Silent::
	lock
	faceplayer
	msgbox SafariZone_Text_SilentNPC, MSGBOX_DEFAULT
	closemessage
	release
	end

SafariZoneGate_EventScript_Kangaskhan::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_KANGASKHAN, CRY_MODE_NORMAL
	msgbox SafariZone_Text_Kangaskhan, MSGBOX_DEFAULT
	waitmoncry
	release
	end

SafariZoneGate_EventScript_Engineer::
	lock
	faceplayer
	msgbox SafariZone_Text_JigglypuffTrainer, MSGBOX_DEFAULT
	closemessage
	release
	end

SafariZoneGate_EventScript_Girl::
	lock
	faceplayer
	msgbox SafariZone_Text_FirstCatch, MSGBOX_DEFAULT
	closemessage
	release
	end

SafariZoneGate_EventScript_SlowpokeLady::
	lock
	faceplayer
	msgbox SafariZone_Text_SlowpokeFan, MSGBOX_DEFAULT
	closemessage
	release
	end


SafariZone_Text_ForeignFeeling:
	.string "PARC SAFARI...\n"
	.string "J'ai l'impression d'être dans un\l"
	.string "pays étranger.\p"
	.string "Ça me fait une sensation étrange.$"

SafariZone_Text_SilentNPC:
	.string "..................\p"
	.string "(Je ne suis pas bavard.)$"

SafariZone_Text_Kangaskhan:
	.string "KANGOUROU: ..................$"

SafariZone_Text_JigglypuffTrainer:
	.string "Ce PARC SAFARI est génial !\n"
	.string "Je n'ai pas arrêté de poursuivre des POKéMON !\p"
	.string "Mais ça a contrarié mon RONDOUDOU.$"

SafariZone_Text_FirstCatch:
	.string "J'ai toujours voulu attraper mon premier\n"
	.string "POKéMON au PARC SAFARI.$"

SafariZone_Text_SlowpokeFan:
	.string "Il y a beaucoup de POKéMON à choisir,\n"
	.string "mais rien n'égale la mignonnerie de\l"
	.string "RAMOLOSS.\p"
	.string "On me dit souvent que je lui ressemble !$"

SafariZone_Text_CustomSystem:
	.string "Vous pensez peut-être qu'il y a un\n"
	.string "système sophistiqué pour\l"
	.string "personnaliser le PARC SAFARI, non ?\p"
	.string "La vérité, c'est que...$"

SafariZone_Text_Sign:
	.string "PARC SAFARI\n"
	.string "Ici, tout est palpitant.\p"
	.string "N'hésitez pas à venir vivre\n"
	.string "l'aventure sauvage !$"


SafariZoneGate_EventScript_IncenseClerk::
	goto_if_set FLAG_FINITE_TMS, SafariZoneGate_EventScript_IncenseClerkFinite
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart SafariZoneGate_Pokemart_Incenses
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SafariZoneGate_Pokemart_Incenses:
	.2byte ITEM_SEA_INCENSE
	.2byte ITEM_LAX_INCENSE
	.2byte ITEM_NONE
	release
	end


SafariZoneGate_EventScript_IncenseClerkFinite::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart SafariZoneGate_Pokemart_Incenses2
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SafariZoneGate_Pokemart_Incenses2:
	.2byte ITEM_TM_HIDDEN_POWER
	.2byte ITEM_TM_SECRET_POWER
	.2byte ITEM_SEA_INCENSE
	.2byte ITEM_LAX_INCENSE
	.2byte ITEM_NONE
	release
	end

SafariZoneGate_EventScript_VitaminGuru::
	lock
	faceplayer
	message SafariZoneGate_Text_VitaminGuruSellWhatYouNeed
	waitmessage
	pokemart SafariZoneGate_Pokemart_VitaminGuru
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SafariZoneGate_Pokemart_VitaminGuru:
	.2byte ITEM_PROTEIN
	.2byte ITEM_IRON
	.2byte ITEM_CARBOS
	.2byte ITEM_ZINC
	.2byte ITEM_CALCIUM
	.2byte ITEM_HP_UP
	.2byte ITEM_NONE
	release
	end


SafariZoneGate_Text_VitaminGuruSellWhatYouNeed:
	.string "I'm the ENERGY GURU! I'll go for it and\n"
	.string "sell you what you need!$"

