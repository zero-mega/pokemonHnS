.set LOCALID_STORE_WHITNEY, 4

GoldenrodCity_DepartmentStore_6F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, GoldenrodDeptElevator_OnFrame
	.byte 0

GoldenrodDeptStore6_EventScript_Whitney::
	lock
	faceplayer
	msgbox GoldenrodDeptStore6_Text_Whitney, MSGBOX_DEFAULT
	closemessage
	fadescreenswapbuffers FADE_TO_BLACK
	setflag FLAG_HIDE_DEPTSTORE_WHITNEY
	removeobject LOCALID_STORE_WHITNEY
	fadescreenswapbuffers FADE_FROM_BLACK
	clearflag FLAG_HIDE_DOJO_WHITNEY
	release
	end

GoldenrodDeptStore6_Text_Whitney:
	.string "{PLAYER} ! Quelle surprise de te voir ici !\p"
	.string "J'achète quelque chose pour\n"
	.string "mon ÉCREMEUH.\p"
	.string "Si tu veux un autre combat, viens\n"
	.string "au DOJO DE COMBAT !$"

GoldenrodCity_DepartmentStore_6F_EventScript_Jose::
	lock
	faceplayer
	goto_if_set FLAG_GOLDENROD_NPC_TRADE_COMPLETED, GoldenrodCity_DepartmentStore_6F_EventScript_TradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_MACHOP
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox GoldenrodCity_DepartmentStore_6F_Text_YouWillTradeWontYou, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, GoldenrodCity_DepartmentStore_6F_EventScript_DeclineTrade
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, GoldenrodCity_DepartmentStore_6F_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, VAR_0x8009, GoldenrodCity_DepartmentStore_6F_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox GoldenrodCity_DepartmentStore_6F_Text_MonYouTakeCare, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_GOLDENROD_NPC_TRADE_COMPLETED
	release
	end

GoldenrodCity_DepartmentStore_6F_EventScript_DeclineTrade::
	msgbox GoldenrodCity_DepartmentStore_6F_Text_YouWontTradeMe, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_DepartmentStore_6F_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox GoldenrodCity_DepartmentStore_6F_Text_ThisIsntAMon, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_DepartmentStore_6F_EventScript_TradeCompleted::
	msgbox GoldenrodCity_DepartmentStore_6F_Text_After, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_DepartmentStore_6F_Text_YouWillTradeWontYou:
	.string "Je collectionne les POKéMON !\n"
	.string "As-tu un {STR_VAR_1} ?\p"
	.string "Veux-tu l'échanger contre mon\n"
	.string "{STR_VAR_2} ?$"

GoldenrodCity_DepartmentStore_6F_Text_MonYouTakeCare:
	.string "Youpi ! J'ai eu un {STR_VAR_1} !\p"
	.string "{STR_VAR_2}, prends-en soin !$"

GoldenrodCity_DepartmentStore_6F_Text_ThisIsntAMon:
	.string "Euh, non, je ne crois pas.\n"
	.string "Ce n'est pas un {STR_VAR_1}.$"

GoldenrodCity_DepartmentStore_6F_Text_YouWontTradeMe:
	.string "Tu ne veux pas échanger ? Oh...$"

GoldenrodCity_DepartmentStore_6F_Text_After:
	.string "Salut, comment va mon ancien MACHOPEUR ?$"


GoldenrodDeptStore6_EventScript_Lass::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_6FLass, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore6_EventScript_Nerd::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_6FSuperNerd, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore6_EventScript_Sign::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_6FDirectory, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore_Text_6FLass:
    .string "Tu écoutes le LUCKY CHANNEL ?\p"
    .string "Si tu veux gagner, échange des POKéMON\n"
    .string "avec un maximum de personnes pour\l"
    .string "avoir différents numéros d'ID.$"

GoldenrodDeptStore_Text_6FSuperNerd:
    .string "Si tu es fatigué, essaie les boissons\n"
    .string "des distributeurs.\p"
    .string "Tes POKéMON vont les adorer aussi.$"

GoldenrodDeptStore_Text_6FDirectory:
    .string "Fais une pause dans ton shopping !\p"
    .string "6e ÉTAGE : COIN TRANQUILLE$"
