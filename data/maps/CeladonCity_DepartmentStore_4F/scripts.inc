CeladonCity_DepartmentStore_4F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CeladonDeptElevator_OnFrame
	.byte 0

CeladonDept_EventScript_Supernerd::
	msgbox CeladonDeptStore4F_Text_SuperNerd, MSGBOX_NPC
	end
CeladonDept_EventScript_Youngster::
	msgbox CeladonDeptStore4F_Text_Youngster, MSGBOX_NPC
	end
CeladonDept_EventScript_Directory::
	msgbox CeladonDeptStore4F_Text_Directory, MSGBOX_NPC
	end

CeladonDeptStore4F_Text_SuperNerd:
	.string "Je suis ici pour acheter du COURRIER SURF\n"
	.string "à envoyer à ma petite amie.\p"
	.string "Attends, il n'y en a plus en stock !$"

CeladonDeptStore4F_Text_Youngster:
	.string "C'est le seul endroit où tu peux\n"
	.string "acheter du COURRIER JOLI.$"

CeladonDeptStore4F_Text_Directory:
	.string "Exprime-toi avec des cadeaux !\p"
	.string "4e : CADEAUX SAGE$"
