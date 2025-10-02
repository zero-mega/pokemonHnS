GoldenrodCity_BillsHouse_MapScripts::
	.byte 0

GoldenrodCity_BillsHouse_EventScript_Sister::
	lock
	faceplayer
	msgbox BillHouse_Text_SisterStorageSystem, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_BillsHouse_EventScript_Mom::
	lock
	faceplayer
	goto_if_set FLAG_SYS_PC_BILL, GoldenrodCity_BillsHouse_EventScript_Mom2
	msgbox BillHouse_Text_MomBeforeEcruteak, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_BillsHouse_EventScript_Mom2::
	msgbox BillHouse_Text_MomAfterEcruteak, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_BillsHouse_EventScript_Bill::
	lock
	faceplayer
	goto_if_unset FLAG_GOT_EEVEE, GoldenrodCity_BillsHouse_EventScript_Bill_Eevee
	msgbox BillHouse_Text_PopWontWork, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_BillsHouse_EventScript_Bill_Eevee::
	msgbox BillHouse_Text_TakeThisEevee, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, GoldenrodCity_BillsHouse_EventScript_Bill_Refused
	msgbox BillHouse_Text_CountingOnYou, MSGBOX_DEFAULT

	@HnS named gift pokemon setup
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_EEVEE
	bufferspeciesname STR_VAR_1, SPECIES_EEVEE
	givenamedmon 3
	call Common_EventScript_GiftMonNamed

    

	setflag FLAG_GOT_EEVEE
	msgbox BillHouse_Text_EeveeMayEvolve, MSGBOX_DEFAULT
	closemessage
	release
	end


GoldenrodCity_BillsHouse_EventScript_Bill_Refused::
	msgbox BillHouse_Text_NoEevee, MSGBOX_DEFAULT
	closemessage
	release
	end

BillHouse_Text_TakeThisEevee:
    .string "LÉO : Salut, {PLAYER} ! Rends-moi service et\n"
    .string "prends cet ÉÉVUI.\p"
    .string "Il est arrivé pendant que je réglais\n"
    .string "la CAPSULE TEMPORELLE.\p"
    .string "Quelqu'un doit s'en occuper,\n"
    .string "mais je n'aime pas sortir.\p"
    .string "Je peux compter sur toi pour jouer avec lui,\n"
    .string "{PLAYER} ?$"

BillHouse_Text_CountingOnYou:
    .string "LÉO : Je savais que tu accepterais !\p"
    .string "Bravo ! Tu es vraiment génial !\p"
    .string "OK, je compte sur toi.\p"
    .string "Prends bien soin de lui !$"

BillHouse_Text_ReceivedEevee:
    .string "{PLAYER} a reçu ÉÉVUI !$"

BillHouse_Text_EeveeMayEvolve:
    .string "LÉO : Le PROF.ORME dit que ÉÉVUI peut\n"
    .string "évoluer de façons nouvelles et inconnues.$"

BillHouse_Text_PartyFull:
    .string "Oh, attends. Tu ne peux pas porter\n"
    .string "plus de POKéMON.$"

BillHouse_Text_NoEevee:
    .string "Oh… Que faire maintenant ?$"

BillHouse_Text_PopWontWork:
    .string "LÉO : Mon père, il ne travaille pas. Il\n"
    .string "passe ses journées à s'amuser.\p"
    .string "Il devient un vrai casse-tête…$"

BillHouse_Text_MomBeforeEcruteak:
    .string "Oh, tu collectionnes les POKéMON ? Mon fils\n"
    .string "LÉO est un expert.\p"
    .string "Il vient d'être appelé au CENTRE POKéMON\n"
    .string "à IRISIA.\p"
    .string "Mon mari est parti au CASINO sans\n"
    .string "qu'on l'appelle…$"

BillHouse_Text_MomAfterEcruteak:
    .string "Mon mari était autrefois connu comme un\n"
    .string "POKéMANIAQUE.\p"
    .string "LÉO doit tenir ça de son père.$"

BillHouse_Text_SisterUsefulNumber:
    .string "Tu es un DRESSEUR ?\p"
    .string "J'ai un numéro de téléphone utile\n"
    .string "pour toi.$"

BillHouse_Text_RecordedBillsNumber:
    .string "{PLAYER} a enregistré le numéro de LÉO.$"

BillHouse_Text_SisterRefusedNumber:
    .string "Mon frère a créé le système de stockage\n"
    .string "des POKéMON sur PC.\p"
    .string "J'allais te donner le numéro de LÉO…$"

BillHouse_Text_SisterPhoneFull:
    .string "Tu ne peux pas enregistrer plus de numéros.$"

BillHouse_Text_SisterStorageSystem:
    .string "Mon grand frère LÉO a créé le système de\n"
    .string "stockage des POKéMON sur PC.$"
