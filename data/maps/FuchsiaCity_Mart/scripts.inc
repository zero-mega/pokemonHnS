FuchsiaCity_Mart_MapScripts::
	.byte 0

FuchsiaCity_Mart_EventScript_Fisher::
	msgbox FuchsiaMart_Text_Fisher, MSGBOX_NPC
	end

FuchsiaCity_Mart_EventScript_Woman::
	msgbox FuchsiaMart_Text_CooltrainerF, MSGBOX_NPC
	end

FuchsiaMart_Text_Fisher:
	.string "L'ANCIENNE ZONE SAFARI avait de bien\n"
	.string "meilleurs souvenirs...$"

FuchsiaMart_Text_CooltrainerF:
	.string "La petite-fille de l'ANCIEN GARDIEN\n"
	.string "de la ZONE SAFARI vit en ville.$"
