.set LOCALID_STAIR_GUARD, 2

RustboroCity_DevonCorp_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_DevonCorp_1F_OnTransition
	.byte 0

RustboroCity_DevonCorp_1F_OnTransition:
	call_if_unset FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_BlockStairs
	end

RustboroCity_DevonCorp_1F_EventScript_BlockStairs::
	setobjectxyperm LOCALID_STAIR_GUARD, 14, 2
	setobjectmovementtype LOCALID_STAIR_GUARD, MOVEMENT_TYPE_FACE_DOWN
	return

RustboroCity_DevonCorp_1F_EventScript_Employee::
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_GoodsRecovered
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_DevonCorp_1F_EventScript_RobberWasntBright
	msgbox RustboroCity_DevonCorp_1F_Text_ThoseShoesAreOurProduct, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_RobberWasntBright::
	msgbox RustboroCity_DevonCorp_1F_Text_RobberWasntVeryBright, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_GoodsRecovered::
	msgbox RustboroCity_DevonCorp_1F_Text_SoundsLikeStolenGoodsRecovered, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_StairGuard::
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_AlwaysWelcome
	goto_if_set FLAG_RECOVERED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_GotRobbed
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_DevonCorp_1F_EventScript_GotRobbed
	msgbox RustboroCity_DevonCorp_1F_Text_OnlyAuthorizedPeopleEnter, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_AlwaysWelcome::
	msgbox RustboroCity_DevonCorp_1F_Text_YoureAlwaysWelcomeHere, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_GotRobbed::
	msgbox RustboroCity_DevonCorp_1F_Text_HowCouldWeGetRobbed, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_Greeter::
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_WelcomeToDevonCorp
	goto_if_set FLAG_RECOVERED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_StaffGotRobbed
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_DevonCorp_1F_EventScript_StaffGotRobbed
	msgbox RustboroCity_DevonCorp_1F_Text_WelcomeToDevonCorp, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_WelcomeToDevonCorp::
	msgbox RustboroCity_DevonCorp_1F_Text_WelcomeToDevonCorp, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_StaffGotRobbed::
	msgbox RustboroCity_DevonCorp_1F_Text_StaffGotRobbed, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_RocksMetalDisplay::
	msgbox RustboroCity_DevonCorp_1F_Text_RocksMetalDisplay, MSGBOX_SIGN
	end

RustboroCity_DevonCorp_1F_EventScript_ProductsDisplay::
	msgbox RustboroCity_DevonCorp_1F_Text_ProductDisplay, MSGBOX_SIGN
	end

RustboroCity_DevonCorp_1F_Text_WelcomeToDevonCorp:
	.string "Bonjour et bienvenue à la\n"
	.string "DEVON CORPORATION.\p"
	.string "Nous sommes fiers de produire des objets\n"
	.string "et des médicaments qui améliorent votre vie.$"

RustboroCity_DevonCorp_1F_Text_StaffGotRobbed:
	.string "Un de nos chercheurs s'est bêtement\n"
	.string "fait voler un colis important.$"

RustboroCity_DevonCorp_1F_Text_ThoseShoesAreOurProduct:
	.string "Hé, ces CHAUSSURES DE COURSE !\n"
	.string "Elles sont l'un de nos produits !\p"
	.string "Ça me rend heureux de voir quelqu'un\n"
	.string "utiliser quelque chose que nous avons fabriqué.$"

RustboroCity_DevonCorp_1F_Text_RobberWasntVeryBright:
	.string "Ce colis volé…\p"
	.string "Bon, c'est important, mais ce n'est pas\n"
	.string "quelque chose que n'importe qui peut utiliser.\p"
	.string "À mon avis, ce voleur ne devait pas être\n"
	.string "très malin.$"

RustboroCity_DevonCorp_1F_Text_SoundsLikeStolenGoodsRecovered:
	.string "On dirait qu'ils ont récupéré\n"
	.string "les MARCHANDISES DEVON volées.$"

RustboroCity_DevonCorp_1F_Text_OnlyAuthorizedPeopleEnter:
	.string "Je suis désolé, seules les personnes\n"
	.string "autorisées peuvent entrer ici.$"

RustboroCity_DevonCorp_1F_Text_HowCouldWeGetRobbed:
	.string "C'est au-delà de stupide.\n"
	.string "Comment avons-nous pu nous faire voler ?$"

RustboroCity_DevonCorp_1F_Text_YoureAlwaysWelcomeHere:
	.string "Salut !\n"
	.string "Tu es toujours le bienvenu ici !$"

RustboroCity_DevonCorp_1F_Text_RocksMetalDisplay:
	.string "Des échantillons de roches et de métal\n"
	.string "sont exposés dans la vitrine.\p"
	.string "Il y a un panneau avec une inscription…\p"
	.string "« La DEVON CORPORATION a commencé comme\n"
	.string "producteur de pierres de carrière.\p"
	.string "« L'entreprise produisait aussi du fer à\n"
	.string "partir de limaille de sable.\p"
	.string "« De ce début modeste comme producteur\n"
	.string "de matières premières, DEVON a évolué.\p"
	.string "« DEVON est maintenant un fabricant d'une\n"
	.string "large gamme de produits industriels. »$"

RustboroCity_DevonCorp_1F_Text_ProductDisplay:
	.string "Des prototypes et produits d'essai\n"
	.string "remplissent la vitrine.\p"
	.string "Il y a un panneau avec une description…\p"
	.string "« En plus des produits industriels,\n"
	.string "DEVON propose désormais des articles divers\l"
	.string "et des produits pharmaceutiques pour une\n"
	.string "meilleure qualité de vie.\p"
	.string "« Récemment, DEVON a commencé à proposer\n"
	.string "des outils pour DRESSEURS POKéMON, dont\l"
	.string "des POKé BALLS et des systèmes POKéNAV. »$"
