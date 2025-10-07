Route109_SeashoreHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route109_SeashoreHouse_OnTransition
	.byte 0

Route109_SeashoreHouse_OnTransition:
	setflag FLAG_LANDMARK_SEASHORE_HOUSE
	end

Route109_SeashoreHouse_EventScript_Owner::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_6_SODA_POP, Route109_SeashoreHouse_EventScript_AlreadyReceivedSodaPop
	goto_if_set FLAG_DEFEATED_SEASHORE_HOUSE, Route109_SeashoreHouse_EventScript_DefeatedTrainers
	goto_if_set FLAG_TEMP_2, Route109_SeashoreHouse_EventScript_AlreadyGaveIntroduction
	msgbox Route109_SeashoreHouse_Text_SeashoreHouseIntro, MSGBOX_DEFAULT
	setflag FLAG_TEMP_2
	release
	end

Route109_SeashoreHouse_EventScript_AlreadyGaveIntroduction::
	msgbox Route109_SeashoreHouse_Text_ShowMeSomeHotMatches, MSGBOX_DEFAULT
	release
	end

Route109_SeashoreHouse_EventScript_DefeatedTrainers::
	msgbox Route109_SeashoreHouse_Text_TakeTheseSodaPopBottles, MSGBOX_DEFAULT
	giveitem ITEM_SODA_POP, 6
	goto_if_eq VAR_RESULT, FALSE, Route109_SeashoreHouse_EventScript_BagFull
	setflag FLAG_RECEIVED_6_SODA_POP
	release
	end

Route109_SeashoreHouse_EventScript_BagFull::
	msgbox Route109_SeashoreHouse_Text_BagFull, MSGBOX_DEFAULT
	release
	end

Route109_SeashoreHouse_EventScript_AlreadyReceivedSodaPop::
	showmoneybox 0, 0
	msgbox Route109_SeashoreHouse_Text_WantToBuySodaPop, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route109_SeashoreHouse_EventScript_BuySodaPop
	msgbox Route109_SeashoreHouse_Text_ThatsTooBad, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

Route109_SeashoreHouse_EventScript_BuySodaPop::
	checkmoney 300
	goto_if_eq VAR_RESULT, FALSE, Route109_SeashoreHouse_EventScript_NotEnoughMoney
	checkitemspace ITEM_SODA_POP
	goto_if_eq VAR_RESULT, FALSE, Route109_SeashoreHouse_EventScript_NotEnoughSpace
	msgbox Route109_SeashoreHouse_Text_HereYouGo, MSGBOX_DEFAULT
	removemoney 300
	updatemoneybox
	giveitem ITEM_SODA_POP
	hidemoneybox
	release
	end

Route109_SeashoreHouse_EventScript_NotEnoughMoney::
	msgbox Route109_SeashoreHouse_Text_NotEnoughMoney, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

Route109_SeashoreHouse_EventScript_NotEnoughSpace::
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

Route109_SeashoreHouse_EventScript_Dwayne::
	trainerbattle_single TRAINER_DWAYNE, Route109_SeashoreHouse_Text_DwayneIntro, Route109_SeashoreHouse_Text_DwayneDefeated, Route109_SeashoreHouse_EventScript_CheckTrainersCompletion
	msgbox Route109_SeashoreHouse_Text_DwaynePostBattle, MSGBOX_AUTOCLOSE
	end

Route109_SeashoreHouse_EventScript_Johanna::
	trainerbattle_single TRAINER_JOHANNA, Route109_SeashoreHouse_Text_JohannaIntro, Route109_SeashoreHouse_Text_JohannaDefeated, Route109_SeashoreHouse_EventScript_CheckTrainersCompletion
	msgbox Route109_SeashoreHouse_Text_JohannaPostBattle, MSGBOX_AUTOCLOSE
	end

Route109_SeashoreHouse_EventScript_Simon::
	trainerbattle_single TRAINER_SIMON, Route109_SeashoreHouse_Text_SimonIntro, Route109_SeashoreHouse_Text_SimonDefeated, Route109_SeashoreHouse_EventScript_CheckTrainersCompletion
	msgbox Route109_SeashoreHouse_Text_SimonPostBattle, MSGBOX_AUTOCLOSE
	end

Route109_SeashoreHouse_EventScript_CheckTrainersCompletion::
	goto_if_not_defeated TRAINER_DWAYNE, Route109_SeashoreHouse_EventScript_TrainersNotCompleted
	goto_if_not_defeated TRAINER_JOHANNA, Route109_SeashoreHouse_EventScript_TrainersNotCompleted
	goto_if_not_defeated TRAINER_SIMON, Route109_SeashoreHouse_EventScript_TrainersNotCompleted
	setflag FLAG_DEFEATED_SEASHORE_HOUSE
	release
	end

Route109_SeashoreHouse_EventScript_TrainersNotCompleted::
	release
	end

Route109_SeashoreHouse_Text_SeashoreHouseIntro:
	.string "Je suis le propriétaire de la MAISON DU BORD DE MER.\n"
	.string "Mais tu peux m'appeler M. MER !\p"
	.string "Ce que j'aime par-dessus tout, c'est voir des\n"
	.string "combats de POKéMON enflammés.\p"
	.string "Montre-moi que ton cœur brûle d'ardeur !\p"
	.string "Si tu bats tous les DRESSEURS ici,\n"
	.string "je récompenserai tes efforts.$"

Route109_SeashoreHouse_Text_ShowMeSomeHotMatches:
	.string "Montre-moi des combats brûlants !\p"
	.string "Je gère cette MAISON DU BORD DE MER\n"
	.string "juste pour cette raison !$"

Route109_SeashoreHouse_Text_TakeTheseSodaPopBottles:
	.string "Tu es brûlant !\n"
	.string "Ces combats étaient enflammés !\l"
	.string "Je suis plus que satisfait !\p"
	.string "Pour te remercier de ta série de victoires,\n"
	.string "je veux que tu prennes ceci.\p"
	.string "C'est une demi-douzaine de bouteilles de SODA COOL !$"

Route109_SeashoreHouse_Text_BagFull:
	.string "Oh, mais ton SAC est complètement plein.\n"
	.string "Je vais les garder pour toi.$"

Route109_SeashoreHouse_Text_WantToBuySodaPop:
	.string "Tu veux acheter du SODA COOL ?\n"
	.string "Les POKéMON adorent ça !\p"
	.string "Seulement 300¥ la bouteille !\n"
	.string "Achètes-en !$"

Route109_SeashoreHouse_Text_HereYouGo:
	.string "Voilà !$"

Route109_SeashoreHouse_Text_NotEnoughMoney:
	.string "Tu n'as pas assez d'argent.$"

Route109_SeashoreHouse_Text_ThatsTooBad:
	.string "Non ?\n"
	.string "Dommage.$"

Route109_SeashoreHouse_Text_DwayneIntro:
	.string "Si tu cherches un combat dans la\n"
	.string "MAISON DU BORD DE MER, tu ne trouveras\l"
	.string "pas de DRESSEUR plus brûlant que moi, moussaillon !$"

Route109_SeashoreHouse_Text_DwayneDefeated:
	.string "C'était un combat brûlant !\n"
	.string "Je peux accepter cette défaite, moussaillon !$"

Route109_SeashoreHouse_Text_DwaynePostBattle:
	.string "À chaque fois que je suis à POIVRESSEL, j'apprécie\n"
	.string "les combats enflammés et un SODA COOL bien frais !$"

Route109_SeashoreHouse_Text_JohannaIntro:
	.string "Les combats ennuyeux ne valent pas la peine.\p"
	.string "Seuls les combats brûlants endurcissent\n"
	.string "les DRESSEURS et les POKéMON !$"

Route109_SeashoreHouse_Text_JohannaDefeated:
	.string "C'est brûlant !$"

Route109_SeashoreHouse_Text_JohannaPostBattle:
	.string "Ouf, j'ai soif.\n"
	.string "Je vais peut-être prendre un SODA COOL.$"

Route109_SeashoreHouse_Text_SimonIntro:
	.string "Je vais te montrer à quel point mes\n"
	.string "POKéMON sont formidables, mais ne pleure pas !$"

Route109_SeashoreHouse_Text_SimonDefeated:
	.string "…J'ai perdu, mais je ne pleurerai pas…$"

Route109_SeashoreHouse_Text_SimonPostBattle:
	.string "Si l'un de mes POKéMON connaissait la capacité\n"
	.string "pour me porter sur l'eau, je pourrais me débarrasser\l"
	.string "de cette bouée.$"
