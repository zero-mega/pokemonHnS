CianwoodHouse2_MapScripts::
	.byte 0

CianwoodHouse2_EventScript_Teacher::
	lock
	faceplayer
	msgbox CianwoodCity_Text_LugiaHouseTeacher, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodHouse2_EventScript_Lass::
	lock
	faceplayer
	msgbox CianwoodCity_Text_LugiaHouseLass, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodHouse2_EventScript_Twin::
	lock
	faceplayer
	msgbox CianwoodCity_Text_LugiaHouseTwin, MSGBOX_DEFAULT
	closemessage
	release
	end
	
CianwoodCity_Text_LugiaHouseTeacher:
	.string "Tu viens d'OLIVILLE ?\p"
	.string "Tu te souviens des quatre îles\n"
	.string "sur le chemin ?\p"
	.string "J'ai entendu dire qu'une créature\n"
	.string "mythique des mers s'y cache.$"

CianwoodCity_Text_LugiaHouseLass:
	.string "J'ai entendu dire qu'on ne peut la voir\n"
	.string "qu'avec une AILE ARGENTÉE.\p"
	.string "Elle doit avoir le même parfum que\n"
	.string "la créature.$"

CianwoodCity_Text_LugiaHouseTwin:
	.string "J'ai entendu que les tourbillons\n"
	.string "autour des îles sont causés par\l"
	.string "la créature marine.\p"
	.string "Il te faudra peut-être une capacité\n"
	.string "spéciale pour les traverser.$"
