.set LOCALID_GOLDENROD_ROOF_NERD, 1

GoldenrodCity_DepartmentStore_7F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, GoldenrodCity_DepartmentStore_7F_OnTransition
	.byte 0

GoldenrodCity_DepartmentStore_7F_OnTransition:
	call_if_set FLAG_DAY_POKEMON, GoldenrodCity_DepartmentStore_7F_EventScript_SetNight
	call_if_unset FLAG_DAY_POKEMON, GoldenrodCity_DepartmentStore_7F_EventScript_SetDay
	end

GoldenrodCity_DepartmentStore_7F_EventScript_SetNight::
	setmaplayoutindex LAYOUT_GOLDENROD_CITY_DEPARTMENT_STORE_7FNIGHT
	return

GoldenrodCity_DepartmentStore_7F_EventScript_SetDay::
	setmaplayoutindex LAYOUT_GOLDENROD_CITY_DEPARTMENT_STORE_7F
	return


GoldenrodDeptStore7_EventScript_PokefanF::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_RoofPokefanF, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore7_EventScript_PokefanM::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_RoofPokefanM, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore7_EventScript_Twin::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_RoofTwin, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore7_EventScript_Nerd::
	lock
	msgbox GoldenrodDeptStore_Text_RoofSuperNerdOhWow, MSGBOX_DEFAULT
	closemessage
	PLAYSE SE_PIN
	applymovement LOCALID_GOLDENROD_ROOF_NERD, Common_Movement_ExclamationMark
	delay 20
	faceplayer
	msgbox GoldenrodDeptStore_Text_RoofSuperNerdQuitBotheringMe, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_GOLDENROD_ROOF_NERD, DIR_SOUTH
	release
	end

GoldenrodDeptStore7_EventScript_Teacher::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_RoofTeacher, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore7_EventScript_Bugcatcher::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_RoofBugCatcher, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore_Text_RoofPokefanF:
    .string "Ouf, je suis fatiguée.\p"
    .string "Je viens parfois sur le toit\n"
    .string "pour faire une pause après le shopping.$"

GoldenrodDeptStore_Text_RoofFisher:
    .string "Pardon ? Qui a dit qu'un adulte ne\n"
    .string "pouvait pas aimer ça ?\p"
    .string "Je reviendrai tous les jours pour\n"
    .string "collectionner toutes les poupées !$"

GoldenrodDeptStore_Text_RoofTwin:
    .string "Ils font des soldes ici de temps\n"
    .string "en temps.$"

GoldenrodDeptStore_Text_RoofSuperNerdOhWow:
    .string "Oh, waouh !$"

GoldenrodDeptStore_Text_RoofSuperNerdQuitBotheringMe:
    .string "Tu peux arrêter de me déranger ?$"

GoldenrodDeptStore_Text_RoofPokefanM:
    .string "Il y a quelque chose que je veux\n"
    .string "vraiment, mais je n'ai pas assez d'argent…\p"
    .string "Peut-être que je vais vendre les BAIES\n"
    .string "que j'ai récoltées…$"

GoldenrodDeptStore_Text_RoofTeacher:
    .string "Oh, tout est si bon marché !\p"
    .string "J'ai tellement acheté que mon SAC est plein !$"

GoldenrodDeptStore_Text_RoofBugCatcher:
    .string "Mes POKéMON sont toujours paralysés ou\n"
    .string "empoisonnés quand ça va mal…\p"
    .string "Alors je suis venu acheter des GUÉRISONS TOTALES.\p"
    .string "Je me demande s'il en reste ?$"
