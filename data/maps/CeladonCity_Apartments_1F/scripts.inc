CeladonCity_Apartments_1F_MapScripts::
	.byte 0

CeladonCity_Apartments_1F_EventScript_Manager::
	msgbox CeladonMansion_Text_Manager, MSGBOX_NPC
	end

CeladonCity_Apartments_1F_EventScript_Sign::
	msgbox CeladonMansion_Text_ManagersSuiteSign, MSGBOX_SIGN
	end

CeladonMansion_Text_Manager:
	.string "Mes chers POKéMON me tiennent compagnie,\n"
	.string "alors je ne me sens jamais seul.\p"
	.string "MIAOUSS rapporte même de l'argent à la maison.$"

CeladonMansion_Text_ManagersSuiteSign:
	.string "CELADON MANSION MANAGER'S SUITE$"
