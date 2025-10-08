RustboroCity_Gym_MapScripts::
	.byte 0

RustboroCity_Gym_EventScript_Roxanne::
	trainerbattle_single TRAINER_ROXANNE_1, RustboroCity_Gym_Text_RoxanneIntro, RustboroCity_Gym_Text_RoxanneDefeat, RustboroCity_Gym_EventScript_RoxanneDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_Gym_EventScript_RoxanneRematch
	goto_if_unset FLAG_RECEIVED_TM_ROCK_TOMB, RustboroCity_Gym_EventScript_GiveRockTomb
	msgbox RustboroCity_Gym_Text_RoxannePostBattle, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_RoxanneDefeated::
	message RustboroCity_Gym_Text_ReceivedStoneBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox RustboroCity_Gym_Text_StoneBadgeInfoTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_VIOLET_GYM
	setflag FLAG_BADGE01_GET
	setvar VAR_GARBAGEVAR, 1
	addvar VAR_GARBAGEVAR, 1
	setvar VAR_0x8008, 1
	call Common_EventScript_SetGymTrainers
	call_if_eq VAR_GARBAGEVAR, 6, Common_EventScript_ReadyPetalburgGymForBattle
	goto RustboroCity_Gym_EventScript_GiveRockTomb
	end

RustboroCity_Gym_EventScript_GiveRockTomb::
	giveitem ITEM_TM_ROCK_TOMB
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_ROCK_TOMB
	goto_if_set FLAG_FINITE_TMS, RustboroCity_Gym_EventScript_GiveRockTombFinite
	msgbox RustboroCity_Gym_Text_ExplainRockTombInfinite, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_GiveRockTombFinite::
	msgbox RustboroCity_Gym_Text_ExplainRockTomb MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_RoxanneRematch::
	trainerbattle_rematch_double TRAINER_ROXANNE_1, RustboroCity_Gym_Text_RoxannePreRematch, RustboroCity_Gym_Text_RoxanneRematchDefeat, RustboroCity_Gym_Text_RoxanneRematchNeedTwoMons
	msgbox RustboroCity_Gym_Text_RoxannePostRematch, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_Josh::
	trainerbattle_single TRAINER_JOSH, RustboroCity_Gym_Text_JoshIntro, RustboroCity_Gym_Text_JoshDefeat
	msgbox RustboroCity_Gym_Text_JoshPostBattle, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_Tommy::
	trainerbattle_single TRAINER_TOMMY, RustboroCity_Gym_Text_TommyIntro, RustboroCity_Gym_Text_TommyDefeat
	msgbox RustboroCity_Gym_Text_TommyPostBattle, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_Marc::
	trainerbattle_single TRAINER_MARC, RustboroCity_Gym_Text_MarcIntro, RustboroCity_Gym_Text_MarcDefeat
	msgbox RustboroCity_Gym_Text_MarcPostBattle, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_VIOLET_GYM, RustboroCity_Gym_EventScript_GymGuidePostVictory
	msgbox RustboroCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_GymGuidePostVictory::
	msgbox RustboroCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE01_GET, RustboroCity_Gym_EventScript_GymStatueCertified
	goto RustboroCity_Gym_EventScript_GymStatue
	end

RustboroCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE01_GET, RustboroCity_Gym_EventScript_GymStatueCertified
	goto RustboroCity_Gym_EventScript_GymStatue
	end

RustboroCity_Gym_EventScript_GymStatueCertified::
	msgbox RustboroCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

RustboroCity_Gym_EventScript_GymStatue::
	msgbox RustboroCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

RustboroCity_Gym_EventScript_RegisterRoxanne::
	lockall
	pokenavcall RustboroCity_Gym_Text_RoxanneRegisterCall
	waitmessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox RustboroCity_Gym_Text_RegisteredRoxanne, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_ROXANNE_MATCH_CALL
	clearflag FLAG_ENABLE_ROXANNE_FIRST_CALL
	releaseall
	end

RustboroCity_Gym_Text_GymGuideAdvice:
	.string "Yo, comment ça va ?\p"
	.string "Écoute, mon ami !\n"
	.string "Tu veux devenir le CHAMPION ?\p"
	.string "Je ne suis pas un DRESSEUR, pas moi, mais\n"
	.string "je peux te donner des conseils pour gagner.\p"
	.string "C'est décidé alors ! On vise ensemble le\n"
	.string "CHAMPIONNAT POKéMON !\p"
	.string "Ton rôle en tant que DRESSEUR est de\n"
	.string "récupérer les BADGES d'ARÈNE, n'est-ce pas ?\p"
	.string "Mais les CHAMPIONS d'ARÈNE ne sont pas faciles !\p"
	.string "Et c'est là que j'interviens !\n"
	.string "Je suis là pour te donner des conseils d'expert !\p"
	.string "ROXANNE, la CHAMPIONNE d'ARÈNE, utilise\n"
	.string "des POKéMON de type ROCHE.\p"
	.string "Le type ROCHE est très résistant, mais\n"
	.string "il ne supporte pas les attaques de type EAU\l"
	.string "et PLANTE.\p"
	.string "Viens me voir après, si tu bats la\n"
	.string "CHAMPIONNE d'ARÈNE.\p"
	.string "Allez, fonce !$"

RustboroCity_Gym_Text_GymGuidePostVictory:
	.string "Ouah ! Quelle victoire époustouflante !\n"
	.string "Mes encouragements ont dû marcher !\p"
	.string "Génial !\n"
	.string "Vérifie ta CARTE DE DRESSEUR.\p"
	.string "Le BADGE PIERRE que tu as obtenu devrait\n"
	.string "y être correctement enregistré.\p"
	.string "En d'autres mots…\p"
	.string "Tu as gravi la première marche vers\n"
	.string "le CHAMPIONNAT !\p"
	.string "Ça doit être génial comme sensation !$"

RustboroCity_Gym_Text_JoshIntro:
	.string "Ne nous sous-estime pas, nous les DRESSEURS\n"
	.string "d'ARÈNE ! Je vais te montrer pourquoi on est meilleurs !$"

RustboroCity_Gym_Text_JoshDefeat:
	.string "Tu étais trop fort pour moi…$"

RustboroCity_Gym_Text_JoshPostBattle:
	.string "Tu n'as encore rien vu de la puissance\n"
	.string "terrifiante du type ROCHE !$"

RustboroCity_Gym_Text_TommyIntro:
	.string "Si tu ne peux pas me battre, tu n'auras\n"
	.string "aucune chance contre ROXANNE !$"

RustboroCity_Gym_Text_TommyDefeat:
	.string "Waouh ! Tu as du potentiel !$"

RustboroCity_Gym_Text_TommyPostBattle:
	.string "ROXANNE est bien plus forte que moi,\n"
	.string "plusieurs fois.\p"
	.string "Tu ferais mieux de faire attention !$"

RustboroCity_Gym_Text_MarcIntro:
	.string "On est peut-être en plein centre-ville,\n"
	.string "et alors ?\p"
	.string "Mes POKéMON de type ROCHE ont besoin\n"
	.string "d'espace pour se déchaîner !$"

RustboroCity_Gym_Text_MarcDefeat:
	.string "Oh là là !\n"
	.string "Notre challenger a du répondant !$"

RustboroCity_Gym_Text_MarcPostBattle:
	.string "Je dois féliciter notre CHAMPIONNE.\p"
	.string "Il fallait de l'intelligence et du bon sens\n"
	.string "pour choisir le type ROCHE à son jeune âge.$"

RustboroCity_Gym_Text_RoxanneIntro:
	.string "Bonjour, je suis ROXANNE, la CHAMPIONNE\n"
	.string "d'ARÈNE de MEROUVILLE.\p"
	.string "Je suis devenue CHAMPIONNE d'ARÈNE pour\n"
	.string "appliquer ce que j'ai appris à l'ÉCOLE\l"
	.string "des DRESSEURS POKéMON en combat.\p"
	.string "Pourrais-tu me montrer comment tu te bats,\n"
	.string "et avec quels POKéMON ?$"

RustboroCity_Gym_Text_RoxanneDefeat:
	.string "Alors…\n"
	.string "J'ai perdu…\p"
	.string "Il semble que j'ai encore beaucoup\n"
	.string "à apprendre…\p"
	.string "Je comprends.\p"
	.string "Les règles de la LIGUE POKéMON disent\n"
	.string "que les DRESSEURS reçoivent ceci\l"
	.string "s'ils battent une CHAMPIONNE d'ARÈNE.\p"
	.string "Merci d'accepter le BADGE PIERRE officiel\n"
	.string "de la LIGUE POKéMON.$"

RustboroCity_Gym_Text_ReceivedStoneBadge:
	.string "{PLAYER} reçoit le BADGE PIERRE\n"
	.string "de ROXANNE.$"

RustboroCity_Gym_Text_StoneBadgeInfoTakeThis:
	.string "Le BADGE PIERRE augmente la puissance\n"
	.string "d'ATTAQUE de tes POKéMON.\p"
	.string "Il leur permet aussi d'utiliser la CS\n"
	.string "COUPE en dehors des combats.\p"
	.string "Prends aussi ceci avec toi.$"

RustboroCity_Gym_Text_ExplainRockTomb:
	.string "Cette MACHINE TECHNIQUE, la CT39,\n"
	.string "contient TOMBEROCHE.\p"
	.string "Elle inflige des dégâts en faisant tomber\n"
	.string "des rochers, et baisse aussi la VITESSE.\p"
	.string "Si tu utilises une CT, elle apprend\n"
	.string "immédiatement la capacité à un POKéMON.$"
	.string "N'oublie pas, une CT ne peut être utilisée\n"
	.string "qu'une seule fois, alors réfléchis bien !$"

RustboroCity_Gym_Text_ExplainRockTombInfinite:
	.string "Cette MACHINE TECHNIQUE, la CT39,\n"
	.string "contient TOMBEROCHE.\p"
	.string "Elle inflige des dégâts en faisant tomber\n"
	.string "des rochers, et baisse aussi la VITESSE.\p"
	.string "Si tu utilises une CT, elle apprend\n"
	.string "immédiatement la capacité à un POKéMON.$"
	.string "Une CT peut être utilisée autant de fois\n"
	.string "que tu veux, alors profites-en !$"

RustboroCity_Gym_Text_RoxannePostBattle:
	.string "Puisque tu es si fort, tu devrais\n"
	.string "défier d'autres CHAMPIONS d'ARÈNE.\p"
	.string "En affrontant de nombreux DRESSEURS,\n"
	.string "tu apprendras beaucoup de choses.$"

RustboroCity_Gym_Text_GymStatue:
	.string "ARÈNE POKéMON DE MEROUVILLE$"

RustboroCity_Gym_Text_GymStatueCertified:
	.string "ARÈNE POKéMON DE MEROUVILLE\p"
	.string "DRESSEURS CERTIFIÉS PAR ROXANNE :\n"
	.string "{PLAYER}$"

RustboroCity_Gym_Text_RoxanneRegisterCall:
	.string "… … … … … …\n"
	.string "… … … … … Bip !\p"
	.string "ROXANNE : Oh, bonjour, {PLAYER} ?\n"
	.string "C'est ROXANNE de MEROUVILLE.\p"
	.string "J'ai entendu de BRAWLY que tu progresses\n"
	.string "à une vitesse incroyable parmi les\l"
	.string "DRESSEURS.\p"
	.string "Eh bien, je préfère ne pas penser que\n"
	.string "je ne peux pas te battre.\p"
	.string "Je promets d'améliorer mon ARÈNE\n"
	.string "pour que tu puisses nous défier à nouveau.\p"
	.string "J'espère que tu attendras cette occasion\n"
	.string "avec autant d'impatience que moi !\p"
	.string "… … … … … …\n"
	.string "… … … … … Clic !$"

RustboroCity_Gym_Text_RegisteredRoxanne:
	.string "CHAMPIONNE D'ARÈNE ROXANNE enregistrée\n"
	.string "dans le POKéNAV.$"

RustboroCity_Gym_Text_RoxannePreRematch:
	.string "ROXANNE : Je suis ravie de te revoir.\n"
	.string "Je suis ROXANNE, la CHAMPIONNE d'ARÈNE ici.\p"
	.string "Je suis sûre que nous avons tous les deux\n"
	.string "vécu de nombreux combats depuis notre dernière rencontre.\p"
	.string "J'aimerais voir à quel point nous avons\n"
	.string "progressé. Combattons !$"

RustboroCity_Gym_Text_RoxanneRematchDefeat:
	.string "Grr…\n"
	.string "Encore une fois, j'ai perdu…$"

RustboroCity_Gym_Text_RoxannePostRematch:
	.string "ROXANNE : J'ai encore beaucoup à apprendre\n"
	.string "en ce qui concerne les combats POKéMON.\p"
	.string "Cette prise de conscience me fait aimer\n"
	.string "les combats encore plus !$"

RustboroCity_Gym_Text_RoxanneRematchNeedTwoMons:
	.string "ROXANNE : Je suis ravie de te revoir.\n"
	.string "Je suis ROXANNE, la CHAMPIONNE d'ARÈNE ici.\p"
	.string "Je suis sûre que nous avons tous les deux\n"
	.string "vécu de nombreux combats depuis notre dernière rencontre.\p"
	.string "J'aimerais voir à quel point nous avons\n"
	.string "progressé…\p"
	.string "Oh, non…\n"
	.string "Tu n'as qu'un seul POKéMON avec toi ?\p"
	.string "Reviens avec au moins un autre\n"
	.string "POKéMON, s'il te plaît.$"
