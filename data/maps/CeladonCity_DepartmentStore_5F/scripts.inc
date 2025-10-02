.set LOCALID_CELADON_FALKNER, 5

CeladonCity_DepartmentStore_5F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CeladonDeptElevator_OnFrame
	.byte 0

CeladonDept5_EventScript_Gent::
	msgbox CeladonDeptStore5F_Text_Gentleman, MSGBOX_NPC
	end
CeladonDept5_EventScript_Sailor::
	msgbox CeladonDeptStore5F_Text_Sailor, MSGBOX_NPC
	end
CeladonDept5_EventScript_Teacher::
	msgbox CeladonDeptStore5F_Text_Teacher, MSGBOX_NPC
	end
CeladonDept5_EventScript_Directory::
	msgbox CeladonDeptStore5F_Text_Directory, MSGBOX_SIGN
	end

CeladonDeptStore5_EventScript_Falkner::
	lock
	faceplayer
	msgbox CeladonDeptStore5_Text_Falkner, MSGBOX_DEFAULT
	closemessage
	fadescreenswapbuffers FADE_TO_BLACK
	setflag FLAG_HIDE_CELADON_FALKNER
	removeobject LOCALID_CELADON_FALKNER
	fadescreenswapbuffers FADE_FROM_BLACK
	clearflag FLAG_HIDE_DOJO_FALKNER
	release
	end

CeladonDeptStore5_Text_Falkner:
	.string "{PLAYER}. Je ne m'attendais pas à te\n"
	.string "voir ici.\p"
	.string "Je prends du matériel pour mes\n"
	.string "POKéMON oiseaux.\p"
	.string "Si tu veux m'affronter à nouveau, je\n"
	.string "serai au DOJO à SAFRANIA.$"

CeladonDeptStore5F_Text_Gentleman:
	.string "Je veux acheter des objets qui\n"
	.string "augmentent les stats des POKéMON,\l"
	.string "mais je n'ai pas assez d'argent…$"

CeladonDeptStore5F_Text_Sailor:
	.string "Je veux un PP PLUS, pour augmenter\n"
	.string "les PP des capacités. Mais on ne peut pas l'acheter…$"

CeladonDeptStore5F_Text_Teacher:
	.string "Utiliser des objets sur eux rend les\n"
	.string "POKéMON heureux.\p"
	.string "Mais ils détestent certains objets…$"

CeladonDeptStore5F_Text_Directory:
	.string "5F : PHARMACIE$"
