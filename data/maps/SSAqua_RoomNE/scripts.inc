SSAqua_RoomNE_MapScripts::
	.byte 0

SSAqua_RoomNE_EventScript_Noland::
	trainerbattle_single TRAINER_NOLAND SSAqua_RoomNE_Text_HikerNolandSeen, SSAqua_RoomNE_Text_HikerNolandBeaten
	msgbox SSAqua_RoomNE_Text_HikerNolandAfterBattle, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomNE_EventScript_Ethan::
	trainerbattle_single TRAINER_ETHAN SSAqua_RoomNE_Text_PokemaniacEthanSeen, SSAqua_RoomNE_Text_PokemaniacEthanBeaten
	msgbox SSAqua_RoomNE_Text_PokemaniacEthanAfterBattle, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomNE_Text_HikerNolandSeen:
    .string "Tu es seul(e) ?\n"
    .string "Alors, combattons !$"

SSAqua_RoomNE_Text_HikerNolandBeaten:
    .string "C'est trop pour moi !$"

SSAqua_RoomNE_Text_HikerNolandAfterBattle:
    .string "Je me demande s'il y a des\n"
    .string "montagnes à gravir à KANTO.$"

SSAqua_RoomNE_Text_PokemaniacEthanSeen:
    .string "Tu connais LORA ?\n"
    .string "C'est une DJ très connue à KANTO.$"

SSAqua_RoomNE_Text_PokemaniacEthanBeaten:
    .string "Gyaaaah !$"

SSAqua_RoomNE_Text_PokemaniacEthanAfterBattle:
    .string "LORA est sympa, mais\n"
    .string "BLANCHE est la meilleure !\n"
    .string "Je veux écouter\n"
    .string "les programmes radio\n"
    .string "de JOHTO !$"
