LakeOfRage_House1_MapScripts::
	.byte 0

LakeOfRage_House1_EventScript_HiddenPowerGuy::
	lock
	faceplayer
	goto_if_set FLAG_GOT_HIDDEN_POWER, LakeOfRage_House1_EventScript_HiddenPowerGuyAfter
	msgbox HiddenPowerGuy_Text_Intro, MSGBOX_DEFAULT
	giveitem ITEM_TM_HIDDEN_POWER
	msgbox HiddenPowerGuy_Text_Explanation, MSGBOX_DEFAULT
	setflag FLAG_GOT_HIDDEN_POWER
	closemessage
	release
	end

LakeOfRage_House1_EventScript_HiddenPowerGuyAfter::
	msgbox HiddenPowerGuy_Text_Meditating, MSGBOX_DEFAULT
	closemessage
	release
	end

HiddenPowerGuy_Text_Intro:
    .string "…Tu es venu de loin…\p"
    .string "Ici, j'ai médité. En moi,\n"
    .string "un nouveau pouvoir s'est éveillé.\p"
    .string "Laisse-moi partager mon pouvoir avec\n"
    .string "tes POKéMON. Prends ceci, enfant.$"

HiddenPowerGuy_Text_Explanation:
    .string "Le vois-tu ? C'est PUISSANCE CACHÉE !\p"
    .string "Elle fait ressortir la force des\n"
    .string "POKéMON pour attaquer.\p"
    .string "Souviens-toi : son type et sa puissance\n"
    .string "dépendent du POKéMON qui l'utilise.$"

HiddenPowerGuy_Text_Meditating:
    .string "Je médite…$"
