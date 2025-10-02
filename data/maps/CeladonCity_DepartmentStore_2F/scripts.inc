CeladonCity_DepartmentStore_2F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CeladonDeptElevator_OnFrame
	.byte 0

CeladonDept2_EventScript_Pokefan::
	msgbox CeladonDeptStore2F_Text_PokefanM, MSGBOX_NPC
	end

CeladonDept2_EventScript_Youngster::
	msgbox CeladonDeptStore2F_Text_Youngster, MSGBOX_NPC
	end

CeladonDept2_EventScript_Directory::
	msgbox CeladonDeptStore2F_Text_Directory, MSGBOX_SIGN
	end

CeladonDeptStore2F_Text_PokefanM:
	.string "Je viens tout juste de devenir DRESSEUR.\p"
	.string "C'est mon fils qui m'a encouragé à le faire.\p"
	.string "Je suis impressionné par le choix\l"
	.string "d'objets pratiques.$"

CeladonDeptStore2F_Text_Youngster:
	.string "Mon papa a du mal à retenir les noms\l"
	.string "des objets et à comprendre comment\l"
	.string "les utiliser…$"

CeladonDeptStore2F_Text_Directory:
	.string "Objets de première qualité pour DRESSEURS !\p"
	.string "2F : MARCHÉ DES DRESSEURS$"

