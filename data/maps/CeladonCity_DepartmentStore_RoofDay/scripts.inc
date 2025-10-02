CeladonCity_DepartmentStore_RoofDay_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeladonCity_DepartmentStore_RoofDay_OnTransition
	.byte 0

CeladonCity_DepartmentStore_RoofDay_OnTransition:
	call_if_set FLAG_DAY_POKEMON, CeladonCity_DepartmentStore_RoofDay_EventScript_SetNight
	call_if_unset FLAG_DAY_POKEMON, CeladonCity_DepartmentStore_RoofDay_EventScript_SetDay
	end

CeladonCity_DepartmentStore_RoofDay_EventScript_SetNight::
	setmaplayoutindex LAYOUT_CELADON_CITY_DEPARTMENT_STORE_ROOF_NIGHT
	return

CeladonCity_DepartmentStore_RoofDay_EventScript_SetDay::
	setmaplayoutindex LAYOUT_CELADON_CITY_DEPARTMENT_STORE_ROOF_DAY
	return

CeladonDept6_EventScript_Nerd::
	msgbox CeladonDeptStore6F_Text_SuperNerd, MSGBOX_NPC
	end
CeladonDept6_EventScript_Youngster::
	msgbox CeladonDeptStore6F_Text_Youngster, MSGBOX_NPC
	end
CeladonDept6_EventScript_Directory::
	msgbox CeladonDeptStore6F_Text_Directory, MSGBOX_SIGN
	end


CeladonDeptStore6F_Text_Vending:
	.string "Un distributeur automatique ! Voici le menu.$"

CeladonDeptStore6F_Text_Clang:
	.string "Clang !\p"
	.string "{STRING} est tombé.$"

CeladonDeptStore6F_Text_VendingNoMoney:
	.string "Oups, pas assez d'argent…$"

CeladonDeptStore6F_Text_VendingNoSpace:
	.string "Il n'y a plus de place pour d'autres objets…$"

CeladonDeptStore6F_Text_SuperNerd:
	.string "Un distributeur avec une loterie de prix…\p"
	.string "On n'en voit plus de nos jours.$"

CeladonDeptStore6F_Text_Youngster:
	.string "Oh non ! Il n'y a pas de jeux ici !\p"
	.string "Je voulais jouer…$"

CeladonDeptStore6F_Text_Directory:
	.string "6F : TERRASSE - DISTRIBUTEURS AUTOMATIQUES$"
