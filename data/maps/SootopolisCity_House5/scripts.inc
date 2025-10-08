SootopolisCity_House5_MapScripts::
	.byte 0

SootopolisCity_House5_EventScript_Maniac::
	msgbox SootopolisCity_House5_Text_SootopolisMtPyreConnection, MSGBOX_NPC
	end

SootopolisCity_House5_EventScript_Girl::
	msgbox SootopolisCity_House5_Text_BrotherUsedToStudySea, MSGBOX_NPC
	end

SootopolisCity_House5_Text_SootopolisMtPyreConnection:
	.string "Il semble y avoir un lien entre\n"
	.string "SOOTOPOLIS et le MONT MÉMORIA.\p"
	.string "Mes amis et moi avons fait des recherches\n"
	.string "à ce sujet au labo où je travaillais.$"

SootopolisCity_House5_Text_BrotherUsedToStudySea:
	.string "Mon grand frère étudiait la mer.$"
