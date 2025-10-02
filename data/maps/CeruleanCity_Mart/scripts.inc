CeruleanCity_Mart_MapScripts::
	.byte 0

CeruleanCity_Mart_EventScript_Juggler::
	msgbox CeruleanMart_Text_CooltrainerM, MSGBOX_NPC
	end

CeruleanCity_Mart_EventScript_CooltrainerF::
	msgbox CeruleanMart_Text_CooltrainerF, MSGBOX_NPC
	end

CeruleanMart_Text_CooltrainerM:
	.string "Tu rencontreras de nombreux dresseurs\n"
	.string "en allant vers le CAP de CELADOPOLE.\p"
	.string "Ils veulent voir comment ils se\n"
	.string "mesurent aux autres dresseurs.$"

CeruleanMart_Text_CooltrainerF:
	.string "ONDINE est à peu près la seule personne\n"
	.string "en ville capable de battre les dresseurs\l"
	.string "du CAP de CELADOPOLE.$"
