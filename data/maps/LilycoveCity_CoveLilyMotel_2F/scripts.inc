LilycoveCity_CoveLilyMotel_2F_MapScripts::
	.byte 0

LilycoveCity_CoveLilyMotel_2F_EventScript_GameDesigner::
	lock
	faceplayer
	call_if_unset FLAG_TEMP_2, LilycoveCity_CoveLilyMotel_2F_EventScript_ShowMeCompletedDex
	call_if_set FLAG_TEMP_2, LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma
	specialvar VAR_RESULT, HasAllHoennMons
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_CoveLilyMotel_2F_EventScript_AllHoennMonsFanfare
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_ShowMeCompletedDex::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ShowMeCompletedDex, MSGBOX_DEFAULT
	return

LilycoveCity_CoveLilyMotel_2F_EventScript_AllHoennMonsFanfare::
	setflag FLAG_TEMP_2
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma::
	message LilycoveCity_CoveLilyMotel_2F_Text_FilledPokedexGiveYouThis
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	special Special_ShowDiploma
	waitstate
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_Programmer::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ImTheProgrammer, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_GraphicArtist::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ImTheGraphicArtist, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_FatMan::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_GirlsAreCute, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_Woman::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_SeaBreezeTicklesHeart, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_GameBoyKid::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_NeverLeaveWithoutGameBoy, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_Scott::
	lock
	faceplayer
	goto_if_set FLAG_MET_SCOTT_IN_LILYCOVE, LilycoveCity_CoveLilyMotel_2F_EventScript_MetScott
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_SnoozingPreferBattles, MSGBOX_DEFAULT
	addvar VAR_SCOTT_STATE, 1
	setflag FLAG_MET_SCOTT_IN_LILYCOVE
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_MetScott::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ContestsDoTakeStrategy, MSGBOX_DEFAULT
	release
	end

LilycoveCity_CoveLilyMotel_2F_Text_ShowMeCompletedDex:
	.string "Je suis le GAME DESIGNER.\p"
	.string "Ah, c'est vrai ?\n"
	.string "Tu travailles sur un POKéDEX ?\p"
	.string "C'est difficile d'essayer de le compléter,\n"
	.string "mais n'abandonne pas.\p"
	.string "Si tu le complètes, viens me le\n"
	.string "montrer, s'il te plaît.$"

LilycoveCity_CoveLilyMotel_2F_Text_FilledPokedexGiveYouThis:
	.string "Waouh ! C'est génial !\n"
	.string "Oui, c'est vraiment génial !\p"
	.string "Ce POKéDEX est complètement rempli !\n"
	.string "Tu dois vraiment aimer les POKéMON !\p"
	.string "Je suis tellement impressionné !\p"
	.string "Laisse-moi te donner quelque chose en\n"
	.string "reconnaissance de ton exploit !$"

LilycoveCity_CoveLilyMotel_2F_Text_ImTheProgrammer:
	.string "Moi ? Tu me parles à moi ?\n"
	.string "Je suis le PROGRAMMEUR.\p"
	.string "Je me demande à quoi ressemblent\n"
	.string "les MACHINES À SOUS ici.$"

LilycoveCity_CoveLilyMotel_2F_Text_ImTheGraphicArtist:
	.string "Je suis le GRAPHISTE ! Les POKéMON\n"
	.string "de HOENN ne sont-ils pas intéressants ?$"

LilycoveCity_CoveLilyMotel_2F_Text_GirlsAreCute:
	.string "Les petites NAGEUSES, elles sont mignonnes, non ?\n"
	.string "Combattre contre une mignonne NAGEUSE…\p"
	.string "Ouah, c'est trop génial !\p"
	.string "Et les JUMELLES ! Elles ne sont pas mignonnes ?\n"
	.string "Un combat 2 contre 2 avec des JUMELLES…\p"
	.string "Ouah, c'est incroyablement amusant !$"

LilycoveCity_CoveLilyMotel_2F_Text_SeaBreezeTicklesHeart:
	.string "La brise marine me chatouille le cœur.\n"
	.string "C'est merveilleux ici !$"

LilycoveCity_CoveLilyMotel_2F_Text_NeverLeaveWithoutGameBoy:
	.string "On ne sait jamais quand et où\n"
	.string "quelqu'un va te défier.\p"
	.string "C'est pourquoi je ne pars jamais sans\n"
	.string "ma GAME BOY ADVANCE.$"

LilycoveCity_CoveLilyMotel_2F_Text_SnoozingPreferBattles:
	.string "SCOTT : … … … … …\n"
	.string "… … … … … Zzz…\p"
	.string "… … … … … Hein ?!\n"
	.string "Oh, désolé, désolé ! Je somnolais !\p"
	.string "Je suis venu jeter un œil à ce truc de\n"
	.string "CONCOURS POKéMON.\p"
	.string "Je dois admettre, ça a l'air assez\n"
	.string "divertissant, mais…\p"
	.string "Considère-moi comme un puriste -- je préfère\n"
	.string "les combats et les DRESSEURS coriaces.\p"
	.string "Mais c'est juste moi.\p"
	.string "{PLAYER}{KUN}, j'espère que tu profiteras de tout\n"
	.string "comme les ARÈNES, les CONCOURS, le BATTLE TENT,\l"
	.string "tout le reste !$"

LilycoveCity_CoveLilyMotel_2F_Text_ContestsDoTakeStrategy:
	.string "SCOTT : Je pense qu'il faut de la stratégie\n"
	.string "pour gagner un CONCOURS.\p"
	.string "Élaborer des stratégies de CONCOURS est une façon\n"
	.string "de devenir un meilleur DRESSEUR, je dirais.$"
