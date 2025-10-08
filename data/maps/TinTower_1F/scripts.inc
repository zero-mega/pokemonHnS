TinTower_1F_MapScripts::
	.byte 0

TinTower_1F_EventScript_SageA::
	lock
	faceplayer
	goto_if_eq VAR_ECRUTEAK_CITY_STATE, 11, TinTower_1F_EventScript_SageA_Hooh
	msgbox TinTower_1F_Sage4_Text2, MSGBOX_DEFAULT
	closemessage
	release
	end

TinTower_1F_EventScript_SageA_Hooh::
	msgbox TinTower_1F_Sage4_Text1, MSGBOX_DEFAULT
	closemessage
	release
	end

TinTower_1F_EventScript_SageB::
	lock
	faceplayer
	goto_if_eq VAR_ECRUTEAK_CITY_STATE, 11, TinTower_1F_EventScript_SageB_Hooh
	msgbox TinTower_1F_Sage2_Text, MSGBOX_DEFAULT
	closemessage
	release
	end

TinTower_1F_EventScript_SageB_Hooh::
	msgbox TinTower_1F_Sage1_Text, MSGBOX_DEFAULT
	closemessage
	release
	end

TinTower_1F_EventScript_SageC::
	lock
	faceplayer
	goto_if_eq VAR_ECRUTEAK_CITY_STATE, 11, TinTower_1F_EventScript_SageC_Hooh
	msgbox TinTower_1F_Sage6_Text2, MSGBOX_DEFAULT
	closemessage
	release
	end

TinTower_1F_EventScript_SageC_Hooh::
	msgbox TinTower_1F_Sage3_Text, MSGBOX_DEFAULT
	closemessage
	release
	end


TinTower_1F_Sage1_Text:
	.string "Selon la légende…\n"
	.string "Lorsque les âmes des POKéMON et des humains\p"
	.string "communiquent, un POKéMON aux couleurs de\n"
	.string "l’arc-en-ciel descend du ciel…\p"
	.string "Cela voudrait-il dire que les POKéMON\n"
	.string "légendaires nous mettent à l’épreuve?$"

TinTower_1F_Sage2_Text:
	.string "Quand la TOUR CENDRÉE a brûlé,\n"
	.string "on raconte que trois POKéMON sans nom\l"
	.string "ont péri. Ce fut tragique.\p"
	.string "Cependant…\p"
	.string "Un POKéMON aux couleurs de l’arc-en-ciel…\n"
	.string "En d’autres termes…\p"
	.string "HO-OH est descendu du ciel et a donné\n"
	.string "une nouvelle vie aux trois POKéMON.\p"
	.string "Ce sont…\n"
	.string "SUICUNE, ENTEI et RAIKOU.\p"
	.string "C’est ce qu’on raconte.$"

TinTower_1F_Sage3_Text:
	.string "On dit que les deux TOURS ont été\n"
	.string "construites pour favoriser l’amitié et\p"
	.string "l’espoir entre les POKéMON et les humains.\n"
	.string "C’était il y a 700 ans, mais cet idéal\p"
	.string "reste important aujourd’hui.$"

TinTower_1F_Sage4_Text1:
	.string "HO-OH semble être descendu\n"
	.string "sur cette TOUR FER!$"

TinTower_1F_Sage4_Text2:
	.string "On dit que les POKéMON légendaires\n"
	.string "incarnent trois pouvoirs…\p"
	.string "La foudre qui a frappé la TOUR.\n"
	.string "Le feu qui a brûlé la TOUR.\p"
	.string "Et la pluie qui a éteint le feu…$"

TinTower_1F_Sage6_Text2:
	.string "Parmi les POKéMON légendaires, SUICUNE\n"
	.string "serait le plus proche de HO-OH.\p"
	.string "J’ai entendu dire qu’il y aurait aussi un lien\n"
	.string "avec des POKéMON appelés ZARBI.\p"
	.string "Les POKéMON ZARBI doivent partager un lien\n"
	.string "de coopération avec SUICUNE.$"

TinTower_1F_EusineHoOh_Text:
	.string "Je le savais.\p"
	.string "Je savais que tu verrais le POKéMON\n"
	.string "aux couleurs de l’arc-en-ciel, <PLAYER>.\p"
	.string "Tout s’est passé comme je l’avais prévu.\n"
	.string "Ma recherche n’est pas mauvaise, je dois dire.\p"
	.string "Je vais continuer à étudier les POKéMON\n"
	.string "pour devenir un célèbre POKéMANIAQUE!$"

TinTower_1F_EusineSuicune_Text:
	.string "EUSINE : Génial ! Trop génial, même !\n"
	.string "Je n’ai jamais vu un combat aussi incroyable.\p"
	.string "C’était vraiment inspirant à voir.\n"
	.string "SUICUNE était fort, mais tu étais encore\p"
	.string "plus incroyable, <PLAYER>.\n"
	.string "J’ai entendu dire que le pouvoir mystique\p"
	.string "de SUICUNE invoque un POKéMON aux couleurs\n"
	.string "de l’arc-en-ciel.\n"
	.string "Peut-être, juste peut-être, que ce qui s’est passé\p"
	.string "aujourd’hui fera apparaître ce POKéMON.\n"
	.string "Je vais étudier davantage les légendes.\p"
	.string "Merci de m’avoir montré ce combat fantastique.\n"
	.string "\p"
	.string "À plus tard, <PLAYER>!$"
