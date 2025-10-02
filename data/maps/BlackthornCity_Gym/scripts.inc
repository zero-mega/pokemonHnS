BlackthornCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, BlackthornGym_OnLoad
	.byte 0

BlackthornGym_OnLoad::
	call_if_eq VAR_BLACKTHORN_GYM_STATE, 1, BlackthornGym_MapScript_Var1
	call_if_eq VAR_BLACKTHORN_GYM_STATE, 2, BlackthornGym_MapScript_Var2
	call_if_eq VAR_BLACKTHORN_GYM_STATE, 3, BlackthornGym_MapScript_Var3
	call_if_eq VAR_BLACKTHORN_GYM_STATE, 4, BlackthornGym_MapScript_Var4
	end

BlackthornGym_MapScript_Var1::
	call BlackthornGym_MapScript_BuildBridge1
	end

BlackthornGym_MapScript_Var2::
	call BlackthornGym_MapScript_BuildBridge1
	call BlackthornGym_MapScript_BuildBridge2
	end

BlackthornGym_MapScript_Var3::
	call BlackthornGym_MapScript_BuildBridge1
	call BlackthornGym_MapScript_BuildBridge2
	call BlackthornGym_MapScript_BuildBridge3
	end

BlackthornGym_MapScript_Var4::
	call BlackthornGym_MapScript_BuildBridge1
	call BlackthornGym_MapScript_BuildBridge2
	call BlackthornGym_MapScript_BuildBridge3
	call BlackthornGym_MapScript_BuildBridge4
	end

BlackthornGym_TriggerBridge1::
	call BlackthornGym_MapScript_BuildBridge1
	playse SE_BANG
	special DrawWholeMapView
	setvar VAR_BLACKTHORN_GYM_STATE, 1
	end

BlackthornGym_MapScript_BuildBridge1::
	setmetatile 19, 47, 0x35A, FALSE
	setmetatile 19, 48, 0x35A, FALSE
	setmetatile 19, 49, 0x35A, FALSE
	setmetatile 19, 50, 0x35A, FALSE
	setmetatile 19, 51, 0x35A, FALSE
	setmetatile 19, 52, 0x35A, FALSE
	setmetatile 19, 53, 0x35A, FALSE
	setmetatile 19, 54, 0x35A, FALSE
	setmetatile 20, 47, 0x35A, FALSE
	setmetatile 20, 48, 0x35A, FALSE
	setmetatile 20, 49, 0x35A, FALSE
	setmetatile 20, 50, 0x35A, FALSE
	setmetatile 20, 51, 0x35A, FALSE
	setmetatile 20, 52, 0x35A, FALSE
	setmetatile 20, 53, 0x35A, FALSE
	setmetatile 20, 54, 0x35A, FALSE
	setmetatile 21, 47, 0x35A, FALSE
	setmetatile 21, 48, 0x35A, FALSE
	setmetatile 21, 49, 0x35A, FALSE
	setmetatile 21, 50, 0x35A, FALSE
	setmetatile 21, 51, 0x35A, FALSE
	setmetatile 21, 52, 0x35A, FALSE
	setmetatile 21, 53, 0x35A, FALSE
	setmetatile 21, 54, 0x35A, FALSE
	return

BlackthornGym_TriggerBridge2::
	call BlackthornGym_MapScript_BuildBridge2
	playse SE_BANG
	special DrawWholeMapView
	setvar VAR_BLACKTHORN_GYM_STATE, 2
	end

BlackthornGym_MapScript_BuildBridge2::
	setmetatile 17, 35, 0x35A, FALSE
	setmetatile 17, 36, 0x35A, FALSE
	setmetatile 17, 37, 0x35A, FALSE
	setmetatile 17, 38, 0x35A, FALSE
	setmetatile 17, 39, 0x35A, FALSE
	setmetatile 17, 40, 0x35A, FALSE
	setmetatile 18, 35, 0x35A, FALSE
	setmetatile 18, 36, 0x35A, FALSE
	setmetatile 18, 37, 0x35A, FALSE
	setmetatile 18, 38, 0x35A, FALSE
	setmetatile 18, 39, 0x35A, FALSE
	setmetatile 18, 40, 0x35A, FALSE
	setmetatile 19, 35, 0x35A, FALSE
	setmetatile 19, 36, 0x35A, FALSE
	setmetatile 19, 37, 0x35A, FALSE
	setmetatile 19, 38, 0x35A, FALSE
	setmetatile 19, 39, 0x35A, FALSE
	setmetatile 19, 40, 0x35A, FALSE
	setmetatile 20, 32, 0x359, FALSE
	setmetatile 21, 32, 0x359, FALSE
	setmetatile 22, 32, 0x359, FALSE
	setmetatile 20, 35, 0x361, TRUE
	setmetatile 21, 35, 0x361, TRUE
	setmetatile 22, 35, 0x361, TRUE
	setmetatile 20, 33, 0x35A, FALSE
	setmetatile 20, 34, 0x35A, FALSE
	setmetatile 21, 33, 0x35A, FALSE
	setmetatile 21, 34, 0x35A, FALSE
	setmetatile 22, 33, 0x35A, FALSE
	setmetatile 22, 34, 0x35A, FALSE
	return

BlackthornGym_TriggerBridge3::
	call BlackthornGym_MapScript_BuildBridge3
	playse SE_BANG
	special DrawWholeMapView
	setvar VAR_BLACKTHORN_GYM_STATE, 3
	end

BlackthornGym_MapScript_BuildBridge3::
	setmetatile 17, 26, 0x359, FALSE
	setmetatile 18, 26, 0x359, FALSE
	setmetatile 19, 26, 0x359, FALSE
	setmetatile 20, 26, 0x359, FALSE
	setmetatile 21, 26, 0x359, FALSE
	setmetatile 22, 26, 0x359, FALSE
	setmetatile 23, 26, 0x359, FALSE

	setmetatile 17, 29, 0x361, TRUE
	setmetatile 18, 29, 0x361, TRUE
	setmetatile 19, 29, 0x361, TRUE
	setmetatile 20, 29, 0x361, TRUE
	setmetatile 21, 29, 0x361, TRUE
	setmetatile 22, 29, 0x361, TRUE
	setmetatile 23, 29, 0x361, TRUE

	setmetatile 17, 27, 0x35A, FALSE
	setmetatile 17, 28, 0x35A, FALSE
	setmetatile 18, 27, 0x35A, FALSE
	setmetatile 18, 28, 0x35A, FALSE
	setmetatile 19, 27, 0x35A, FALSE
	setmetatile 19, 28, 0x35A, FALSE
	setmetatile 20, 27, 0x35A, FALSE
	setmetatile 20, 28, 0x35A, FALSE
	setmetatile 21, 27, 0x35A, FALSE
	setmetatile 21, 28, 0x35A, FALSE
	setmetatile 22, 27, 0x35A, FALSE
	setmetatile 22, 28, 0x35A, FALSE
	setmetatile 23, 27, 0x35A, FALSE
	setmetatile 23, 28, 0x35A, FALSE
	return	

BlackthornGym_TriggerBridge4::
	call BlackthornGym_MapScript_BuildBridge4
	playse SE_BANG
	special DrawWholeMapView
	setvar VAR_BLACKTHORN_GYM_STATE, 4
	end

BlackthornGym_MapScript_BuildBridge4::
	setmetatile 19, 11, 0x35A, FALSE
	setmetatile 19, 12, 0x35A, FALSE
	setmetatile 19, 13, 0x35A, FALSE
	setmetatile 19, 14, 0x35A, FALSE
	setmetatile 19, 15, 0x35A, FALSE
	setmetatile 20, 11, 0x35A, FALSE
	setmetatile 20, 12, 0x35A, FALSE
	setmetatile 20, 13, 0x35A, FALSE
	setmetatile 20, 14, 0x35A, FALSE
	setmetatile 20, 15, 0x35A, FALSE
	setmetatile 21, 11, 0x35A, FALSE
	setmetatile 21, 12, 0x35A, FALSE
	setmetatile 21, 13, 0x35A, FALSE
	setmetatile 21, 14, 0x35A, FALSE
	setmetatile 21, 15, 0x35A, FALSE
	return


BlackthornGym_EventScript_Cody::
	trainerbattle_single TRAINER_CODY BlackthornGym_Text_CooltrainermCodySeenText, BlackthornGym_Text_CooltrainermCodyBeatenText
	msgbox BlackthornGym_Text_CooltrainermCodyAfterBattleText, MSGBOX_AUTOCLOSE
	end

BlackthornGym_EventScript_Fran::
	trainerbattle_single TRAINER_FRAN BlackthornGym_Text_CooltrainerfFranSeenText, BlackthornGym_Text_CooltrainerfFranBeatenText
	msgbox BlackthornGym_Text_CooltrainerfFranAfterBattleText, MSGBOX_AUTOCLOSE
	end

BlackthornGym_EventScript_Paul::
	trainerbattle_single TRAINER_PAUL BlackthornGym_Text_CooltrainermPaulSeenText, BlackthornGym_Text_CooltrainermPaulBeatenText
	msgbox BlackthornGym_Text_CooltrainermPaulAfterBattleText, MSGBOX_AUTOCLOSE
	end

BlackthornGym_EventScript_Mike::
	trainerbattle_single TRAINER_MIKE BlackthornGym_Text_CooltrainermMikeSeenText, BlackthornGym_Text_CooltrainermMikeBeatenText
	msgbox BlackthornGym_Text_CooltrainermMikeAfterBattleText, MSGBOX_AUTOCLOSE
	end

BlackthornGym_EventScript_Lola::
	trainerbattle_single TRAINER_LOLA BlackthornGym_Text_CooltrainerfLolaSeenText, BlackthornGym_Text_CooltrainerfLolaBeatenText
	msgbox BlackthornGym_Text_CooltrainerfLolaAfterBattleText, MSGBOX_AUTOCLOSE
	end


BlackthornGym_EventScript_Clair::
	lock
	faceplayer
	goto_if_set FLAG_IS_CHAMPION, BlackthornGym_EventScript_ClairAfterLeague
	goto_if_ge VAR_BLACKTHORN_CITY_STATE, 4, BlackthornGym_EventScript_Clair_Defeated
	goto_if_eq VAR_BLACKTHORN_CITY_STATE, 2, BlackthornGym_EventScript_ClairDuringChallenge
	msgbox BlackthornGym_Text_ClairIntroText, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_CLAIR_1, BlackthornGym_Text_ClairWinText
	msgbox BlackthornGym_Text_ClairText_GoToDragonsDen, MSGBOX_DEFAULT
	setvar VAR_0x8008, 8
	call Common_EventScript_SetGymTrainers
	setvar VAR_BLACKTHORN_CITY_STATE, 2
	closemessage
	release
	end

BlackthornGym_EventScript_ClairDuringChallenge::
	msgbox BlackthornGym_Text_ClairText_TooMuchToExpect, MSGBOX_DEFAULT
	closemessage
	release
	end

BlackthornGym_EventScript_Clair_Defeated::
	msgbox BlackthornGym_Text_ClairText_League, MSGBOX_DEFAULT
	closemessage
	release
	end

BlackthornGym_EventScript_ClairAfterLeague::
	msgbox BlackthornGym_Text_ClairAfterLeague, MSGBOX_DEFAULT
	closemessage
	release
	end

BlackthornGym_Text_ClairIntroText:
    .string "Je suis CLAIR.\p"
    .string "La meilleure maîtresse des dragons au monde.\p"
    .string "Je peux rivaliser même avec le\n"
    .string "CONSEIL 4 de la LIGUE POKéMON.\p"
    .string "Tu veux vraiment m'affronter ?\p"
    .string "…Très bien. Allons-y !\p"
    .string "En tant que CHAMPIONNE D'ARÈNE, je vais utiliser toute\n"
    .string "ma puissance contre n'importe quel adversaire !$"

BlackthornGym_Text_ClairWinText:
    .string "J'ai perdu ?\p"
    .string "Je n'y crois pas. Il doit y avoir\n"
    .string "une erreur…$"

BlackthornGym_Text_ClairText_GoToDragonsDen:
    .string "Je ne l'admettrai pas.\p"
    .string "J'ai peut-être perdu, mais tu n'es\n"
    .string "pas encore prêt pour la LIGUE POKéMON.\p"
    .string "Je sais. Tu devrais passer l'épreuve\n"
    .string "des dresseurs de dragons.\p"
    .string "Derrière cette ARÈNE se trouve un lieu appelé\n"
    .string "ANTRE DU DRAGON.\p"
    .string "Il y a un petit sanctuaire en son\n"
    .string "centre. Va là-bas.\p"
    .string "Si tu peux prouver que tu as abandonné\n"
    .string "tes idéaux paresseux, je te reconnaîtrai\l"
    .string "comme un dresseur digne d'un BADGE\l"
    .string "D'ARÈNE !$"

BlackthornGym_Text_ClairText_TooMuchToExpect:
    .string "Qu'y a-t-il ?\p"
    .string "Est-ce trop te demander ?$"

BlackthornGym_Text_ClairText_YouKeptMeWaiting:
    .string "Tu m'as fait attendre !\p"
    .string "Tiens ! Prends ça !$"

BlackthornGym_Text_ClairText_DescribeTM:
    .string "Ceci contient DRACO-GRIFFE.\p"
    .string "Tu devineras bien ce que ça fait.$"

BlackthornGym_Text_ClairText_League:
    .string "Qu'y a-t-il ?\p"
    .string "Tu ne vas pas à la LIGUE POKéMON ?\p"
    .string "Tu ne sais pas où c'est ?\p"
    .string "D'ici, va à BOURG GEON.\p"
    .string "Puis SURFE vers l'est. La route est\n"
    .string "très difficile.\p"
    .string "N'ose pas perdre à la LIGUE POKéMON !\p"
    .string "Si tu perds, je me sentirai encore plus\n"
    .string "mal d'avoir perdu contre toi !\p"
    .string "Donne tout ce que tu as !$"

BlackthornGym_Text_ClairAfterLeague:
    .string "Tu l'as fait, hein ?\p"
    .string "Tu es maintenant le CHAMPION de JOHTO.$"

BlackthornGym_Text_ClairRematchText:
    .string "Tu l'as fait, hein ?\p"
    .string "Tu es maintenant le CHAMPION de JOHTO.\p"
    .string "Tu as prouvé ta force, mais peux-tu\n"
    .string "me battre à nouveau ?\p"
    .string "En tant que Maîtresse des Dragons, je ne me\n"
    .string "retiendrai pas.\p"
    .string "Pas cette fois.\p"
    .string "Veux-tu une revanche contre moi ?$"

BlackthornGym_Text_ClairRematchDefeatText:
    .string "J'ai perdu ?\p"
    .string "Encore ?\p"
    .string "Je n'y crois pas. Il doit y avoir\n"
    .string "une erreur…$"

BlackthornGym_Text_CooltrainermCodySeenText:
    .string "Je viens d'obtenir le droit d'utiliser des POKéMON\n"
    .string "de type DRAGON !$"

BlackthornGym_Text_CooltrainermCodyBeatenText:
    .string "Zut ! Si seulement j'avais un DRACOLOSSE !$"

BlackthornGym_Text_CooltrainermCodyAfterBattleText:
    .string "Les membres de notre clan de dresseurs de dragons\n"
    .string "ne peuvent utiliser des POKéMON dragons que lorsque\l"
    .string "notre MAÎTRE l'autorise.$"

BlackthornGym_Text_CooltrainerfFranSeenText:
    .string "Je ne peux pas laisser passer un dresseur\n"
    .string "sans nom !\p"
    .string "CLAIR serait furieuse si je le faisais !$"

BlackthornGym_Text_CooltrainerfFranBeatenText:
    .string "Oh non… J'ai perdu…$"

BlackthornGym_Text_CooltrainerfFranAfterBattleText:
    .string "Oh là là… CLAIR va être furieuse…$"

BlackthornGym_Text_CooltrainermPaulSeenText:
    .string "Ton premier combat contre des dragons ?\p"
    .string "Je vais te montrer à quel point ils sont forts !$"

BlackthornGym_Text_CooltrainermPaulBeatenText:
    .string "Mes POKéMON dragons ont perdu ?$"

BlackthornGym_Text_CooltrainermPaulAfterBattleText:
    .string "LANCE t'a dit qu'il aimerait te revoir ?\n"
    .string "Aucune chance !$"

BlackthornGym_Text_CooltrainermMikeSeenText:
    .string "Mes chances de perdre ? Même pas un\n"
    .string "pour cent !$"

BlackthornGym_Text_CooltrainermMikeBeatenText:
    .string "C'est étrange.$"

BlackthornGym_Text_CooltrainermMikeAfterBattleText:
    .string "Je connais maintenant mes faiblesses.\p"
    .string "Merci de me l'avoir montré !$"

BlackthornGym_Text_CooltrainerfLolaSeenText:
    .string "Les dragons sont des POKéMON sacrés.\p"
    .string "Ils débordent d'énergie vitale.\p"
    .string "Si tu n'es pas sérieux, tu ne pourras\n"
    .string "pas les battre.$"

BlackthornGym_Text_CooltrainerfLolaBeatenText:
    .string "Bravo !$"

BlackthornGym_Text_CooltrainerfLolaAfterBattleText:
    .string "Les dragons sont faibles face aux attaques\n"
    .string "de type DRAGON.$"

BlackthornGym_EventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_BLACKTHORN_GYM, EcruteakCity_Gym_EventScript_GymGuy2
	msgbox BlackthornGym_Text_GuideText, MSGBOX_DEFAULT
	closemessage
	release
	end
	
BlackthornGym_EventScript_GymGuy2::
	msgbox BlackthornGym_Text_GuideWinText, MSGBOX_DEFAULT
	release
	end	

BlackthornGym_Text_GuideText:
    .string "Yo ! CHAMPION en devenir !\p"
    .string "Le voyage a été long, mais nous\n"
    .string "y sommes presque ! Compte sur moi !\p"
    .string "Bien que CLAIR admire le Maître des\n"
    .string "Dragons, PETER, elle a su se forger\l"
    .string "sa propre identité avec une équipe\l"
    .string "de dragons venus de la mer.\p"
    .string "Les dragons sont censés être faibles\n"
    .string "face aux attaques de type GLACE,\l"
    .string "mais il te faudra aussi des attaques\l"
    .string "de type DRAGON ou FÉE si tu veux\l"
    .string "gagner.$"
    .string "Tu peux le faire !$"

BlackthornGym_Text_GuideWinText:
    .string "Tu as été incroyable en battant CLAIR !\p"
    .string "Il ne te reste plus que le défi de la\n"
    .string "LIGUE POKéMON.\p"
    .string "Tu es sur la voie pour devenir le\n"
    .string "CHAMPION POKéMON !$"


BlackthornGym_EventScript_Statue::
	lock
	goto_if_set FLAG_DEFEATED_BLACKTHORN_GYM, BlackthornGym_EventScript_Statue2
	msgbox BlackthornGym_Text_GymStatue, MSGBOX_DEFAULT
	closemessage
	release
	end

BlackthornGym_EventScript_Statue2::
	msgbox BlackthornGym_Text_GymStatueCertified, MSGBOX_DEFAULT
	closemessage
	release
	end

BlackthornGym_Text_GymStatue:
	.string "BLACKTHORN CITY POKéMON GYM$"

BlackthornGym_Text_GymStatueCertified:
	.string "BLACKTHORN CITY POKéMON GYM\p"
	.string "CLAIR'S CERTIFIED TRAINERS:\n"
	.string "{PLAYER}$"
