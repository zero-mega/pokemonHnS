.set LOCALID_NURSE, 1
.set LOCALID_ECRUTEAK_BILL, 6

EcruteakCity_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EcruteakCity_PokemonCenter_OnTransition
	.byte 0

EcruteakCity_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_ECRUTEAK_CITY
	end

EcruteakCity_PokemonCenter_EventScript_Bill::
	lock
	delay 30
	playse SE_PC_OFF
	delay 55
	faceplayer
	msgbox EcruteakCity_PokemonCenter1F_Text_Bill1, MSGBOX_DEFAULT
	msgbox EcruteakCity_PokemonCenter1F_Text_Bill2, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_NORTH, EcruteakCity_PokemonCenter_EventScript_BillLeaveBot
	call_if_eq VAR_FACING, DIR_WEST, EcruteakCity_PokemonCenter_EventScript_BillLeaveTop
	playse SE_EXIT
	setflag FLAG_HIDE_ECRUTEAK_BILL
	removeobject LOCALID_ECRUTEAK_BILL
	setflag FLAG_SYS_PC_BILL
	clearflag FLAG_HIDE_GOLDENROD_BILL
	release
	end

EcruteakCity_PokemonCenter_EventScript_BillFaceDown::
	turnobject LOCALID_ECRUTEAK_BILL, DIR_SOUTH
	return

EcruteakCity_PokemonCenter_EventScript_BillFaceRight::
	turnobject LOCALID_ECRUTEAK_BILL, DIR_EAST
	return

EcruteakCity_PokemonCenter_EventScript_BillLeaveTop::
	applymovement LOCALID_ECRUTEAK_BILL, EcruteakCity_PokemonCenter_Movement_BillTop
	waitmovement 0
	return

EcruteakCity_PokemonCenter_EventScript_BillLeaveBot::
	applymovement LOCALID_ECRUTEAK_BILL, EcruteakCity_PokemonCenter_Movement_BillBot
	waitmovement 0
	return

EcruteakCity_PokemonCenter_EventScript_Hiker::
	lock
	faceplayer
	msgbox EcruteakCity_PokemonCenter1F_Text_PokefanM, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_PokemonCenter_EventScript_Woman::
	lock
	faceplayer
	msgbox EcruteakCity_PokemonCenter1F_Text_CooltrainerF, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_PokemonCenter_EventScript_Nerd::
	lock
	faceplayer
	msgbox EcruteakCity_PokemonCenter1F_Text_GymGuide, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_PokemonCenter_Movement_BillTop:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

EcruteakCity_PokemonCenter_Movement_BillBot:
	walk_right
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end


EcruteakCity_PokemonCenter1F_Text_Bill1:
	.string "Salut, je suis BILL. Et toi, qui es-tu ?\p"
	.string "Hmm, {PLAYER}, hein ?\n"
	.string "Tu arrives au bon moment.$"

EcruteakCity_PokemonCenter1F_Text_Bill2:
	.string "Je viens juste de terminer les réglages\n"
	.string "de mon SYSTÈME DE STOCKAGE POKéMON.\p"
	.string "Tu sais, ce PC que tu utilises pour\n"
	.string "stocker tous tes POKéMON ?\p"
	.string "C'est moi qui l'ai développé !\p"
	.string "Maintenant que j'ai installé celui-ci,\n"
	.string "mon PC fonctionne dans tous les\l"
	.string "CENTRES POKéMON de JOHTO et KANTO.\p"
	.string "Je dois vite retourner à DOUBLONVILLE\n"
	.string "voir ma famille. N'hésite pas à venir\l"
	.string "me rendre visite quand tu veux !\p"
	.string "Salut !$"

EcruteakCity_PokemonCenter1F_Text_PokefanM:
	.string "La façon dont dansent les KIMONO GIRLS\n"
	.string "est merveilleuse.\p"
	.string "Tout comme la façon dont elles utilisent\n"
	.string "leurs POKéMON.$"

EcruteakCity_PokemonCenter1F_Text_PokefanM_Mobile:
	.string "Tu veux sûrement affronter plus de\n"
	.string "personnes, n'est-ce pas ?\p"
	.string "Il paraît qu'il existe un endroit où\n"
	.string "les dresseurs se rassemblent.\p"
	.string "Où, demandes-tu ?\p"
	.string "C'est un peu après IRISIA.$"

EcruteakCity_PokemonCenter1F_Text_CooltrainerF:
	.string "MORTIMER, le CHAMPION d'ARÈNE, est\n"
	.string "tellement cool.\p"
	.string "Ses POKéMON sont vraiment forts aussi.$"

EcruteakCity_PokemonCenter1F_Text_GymGuide:
	.string "LAC COLÈRE…\p"
	.string "L'apparition d'une nuée de LÉVIATOR…\p"
	.string "Je sens un complot. J'en suis sûr !$"
