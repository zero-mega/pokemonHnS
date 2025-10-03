MtMortar_B1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtMortar_B1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

MtMortar_B1F_OnTransition: 
	callnative SetTimeBasedEncounters
	end

MtMortar_B1F_EventScript_Item_HyperPotion::
    finditem ITEM_HYPER_POTION
    end

MtMortar_B1F_EventScript_Item_Carbos::
    finditem ITEM_CARBOS
    end

MtMortar_B1F_EventScript_Item_PPUp::
    finditem ITEM_PP_UP
    end

MtMortar_B1F_EventScript_Item_MaxEther::
    finditem ITEM_MAX_ETHER
    end

MtMortar_B1F_EventScript_Item_MaxRevive::
    finditem ITEM_MAX_REVIVE
    end

MountMortar4_EventScript_Kiyo::
	lock
	faceplayer
	goto_if_set FLAG_GOT_TYROGUE, MountMortar4_EventScript_KiyoAfter
	goto_if_set FLAG_BEAT_KIYO, MountMortar4_EventScript_KiyoTryGiveTyrogue
	msgbox MountMortar4_Text_KiyoIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_KIYO, MountMortar4_Text_KiyoWin
	setflag FLAG_BEAT_KIYO
MountMortar4_EventScript_KiyoTryGiveTyrogue::
	msgbox MountMortar4_Text_KiyoTyrogueReward, MSGBOX_DEFAULT
	@HnS gift pokemon setup
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_TYROGUE
	bufferspeciesname STR_VAR_1, SPECIES_TYROGUE
	givemon SPECIES_TYROGUE, 25
	call Common_EventScript_GiftMon
	setflag FLAG_GOT_TYROGUE
MountMortar4_EventScript_KiyoAfter::
	msgbox MountMortar4_Text_KiyoGotTyrogue, MSGBOX_DEFAULT
	closemessage
	release
	end


MountMortar4_Text_KiyoIntro:
	.string "Hé !\p"
	.string "Je suis le ROI DU KARATÉ !\n"
	.string "Je m'entraîne seul ici dans le noir !\p"
	.string "Toi ! Bats-toi avec moi !\n"
	.string "Hwaaarggh !$"

MountMortar4_Text_KiyoWin:
	.string "Waaaarggh !\n"
	.string "J'ai perdu !$"

MountMortar4_Text_KiyoTyrogueReward:
	.string "Je... Je suis anéanti...\p"
	.string "Mon entraînement n'est\n"
	.string "pas encore suffisant...\p"
	.string "Mais une défaite est une défaite.\n"
	.string "Je l'admets.\p"
	.string "Pour prouver que tu m'as battu,\n"
	.string "je vais te donner un POKéMON\l"
	.string "rare de type COMBAT.$"

MountMortar4_Text_ReceiveTyrogue:
	.string "{PLAYER} reçoit un TYROGUE.$"

MountMortar4_Text_KiyoGotTyrogue:
	.string "TYROGUE est de type COMBAT.\p"
	.string "Il évolue en un POKéMON\n"
	.string "plus puissant.\p"
	.string "Continue à t'entraîner dur.\n"
	.string "Je vais continuer aussi.\p"
	.string "Adieu !$"

MountMortar4_Text_KiyoFullParty:
	.string "Tu n'as plus de place dans ton équipe !$"
