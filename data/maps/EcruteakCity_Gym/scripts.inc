EcruteakCity_Gym_MapScripts::
	.byte 0

EcruteakCity_Gym_EventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_ECRUTEAK_CITY_GYM, EcruteakCity_Gym_EventScript_GymGuy2
	msgbox EcruteakCity_GymGuideText, MSGBOX_DEFAULT
	closemessage
	release
	end
	
EcruteakCity_Gym_EventScript_GymGuy2::
	msgbox EcruteakCity_GymGuideWinText, MSGBOX_DEFAULT
	release
	end	

EcruteakCity_Gym_EventScript_Jeffrey::
	trainerbattle_single TRAINER_JEFFREY SageJeffreySeenText, SageJeffreyBeatenText
	msgbox SageJeffreyAfterBattleText, MSGBOX_AUTOCLOSE
	end
EcruteakCity_Gym_EventScript_Ping::
	trainerbattle_single TRAINER_PING SagePingSeenText, SagePingBeatenText
	msgbox SagePingAfterBattleText, MSGBOX_AUTOCLOSE
	end

EcruteakCity_Gym_EventScript_Martha::
	trainerbattle_single TRAINER_MARTHA MediumMarthaSeenText, MediumMarthaBeatenText
	msgbox MediumMarthaAfterBattleText, MSGBOX_AUTOCLOSE
	end

EcruteakCity_Gym_EventScript_Grace::
	trainerbattle_single TRAINER_GRACE MediumGraceSeenText, MediumGraceBeatenText
	msgbox MediumGraceAfterBattleText, MSGBOX_AUTOCLOSE
	end

EcruteakCity_Gym_EventScript_Morty::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_ECRUTEAK_CITY_GYM, EcruteakCity_Gym_EventScript_Morty_Defeated
	msgbox MortyIntroText, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_MORTY_1, MortyWinLossText
	message Text_ReceivedFogBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox MortyText_FogBadgeSpeech, MSGBOX_DEFAULT
	setflag FLAG_BADGE04_GET
	setflag FLAG_DEFEATED_ECRUTEAK_CITY_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 4
	call Common_EventScript_SetGymTrainers
	giveitem ITEM_TM_SHADOW_BALL
	msgbox MortyText_ShadowBallSpeech, MSGBOX_DEFAULT
	setvar VAR_ECRUTEAK_CITY_STATE, 4
	closemessage
	release
	end

EcruteakCity_Gym_EventScript_Morty_Defeated::
	msgbox MortyFightDoneText, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_Gym_EventScript_Statue::
	lock
	goto_if_set FLAG_DEFEATED_ECRUTEAK_CITY_GYM, EcruteakCity_Gym_EventScript_Statue2
	msgbox EcruteakCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_Gym_EventScript_Statue2::
	msgbox EcruteakCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_Gym_Text_GymStatue:
	.string "ECRUTEAK CITY POKéMON GYM$"

EcruteakCity_Gym_Text_GymStatueCertified:
	.string "ECRUTEAK CITY POKéMON GYM\p"
	.string "MORTY'S CERTIFIED TRAINERS:\n"
	.string "{PLAYER}$"

MortyIntroText:
	.string "Je suis content que tu sois venu.\p"
	.string "Ici, à ROSALIA, les POKéMON ont\n"
	.string "toujours été vénérés.\p"
	.string "On dit qu’un POKéMON aux couleurs\n"
	.string "de l’arc-en-ciel descendrait\l"
	.string "devant un vrai Dresseur.\p"
	.string "J’ai cru à cette histoire, alors\n"
	.string "je me suis entraîné ici en secret.\p"
	.string "En conséquence, je peux voir ce\n"
	.string "que les autres ne voient pas.\p"
	.string "Encore un peu...\p"
	.string "Avec un peu plus, je pourrais voir\n"
	.string "un futur où je rencontre le\l"
	.string "POKéMON arc-en-ciel.\p"
	.string "Tu vas m’aider à atteindre\n"
	.string "ce niveau !$"

MortyWinLossText:
	.string "Je ne suis pas encore assez bon...\p"
	.string "Très bien. Ce BADGE est à toi.$"

Text_ReceivedFogBadge:
	.string "{PLAYER} reçoit le BRUMEBADGE.$"

MortyText_FogBadgeSpeech:
	.string "Avec le BRUMEBADGE, les POKéMON\n"
	.string "jusqu’au niveau 50 t’obéiront.\p"
	.string "Aussi, tout POKéMON connaissant\n"
	.string "SURF pourra l’utiliser\l"
	.string "à tout moment.\p"
	.string "Je veux que tu aies ceci aussi.$"

MortyText_ShadowBallSpeech:
	.string "C’est BALL’OMBRE.\n"
	.string "Elle inflige des dégâts et peut\l"
	.string "baisser la DEF. SPÉ.\p"
	.string "Utilise-la si tu veux.$"

MortyFightDoneText:
	.string "Je vois...\p"
	.string "Ton voyage t’a mené dans des\n"
	.string "endroits lointains.\p"
	.string "Tu as vu plus de choses que moi.\p"
	.string "Je t’envie pour ça...$"

MortyRematchText:
	.string "Ah, le CHAMPION de JOHTO !\n"
	.string "Content de te voir.\p"
	.string "Tu as montré force et talent,\n"
	.string "mais as-tu progressé depuis notre\l"
	.string "dernier combat ?\p"
	.string "Je me suis entraîné avec mes\n"
	.string "POKéMON de type SPECTRE depuis.\p"
	.string "Voyons si tu peux vaincre\n"
	.string "les ombres à nouveau.\p"
	.string "Veux-tu un match revanche ?$"

Morty_RematchDefeatText:
	.string "Je ne suis pas encore assez bon...\p"
	.string "Tu as vu plus de choses que moi.\p"
	.string "Je t’envie pour ça...$"

SageJeffreySeenText:
	.string "J’ai passé le printemps avec mes\n"
	.string "POKéMON.\p"
	.string "Puis l’été, l’automne et l’hiver...\p"
	.string "Puis le printemps est revenu.\n"
	.string "Nous sommes ensemble depuis longtemps.$"

SageJeffreyBeatenText:
	.string "Victoires et défaites—j’ai connu\n"
	.string "les deux.$"

SageJeffreyAfterBattleText:
	.string "D’où viennent les POKéMON ?$"

SagePingSeenText:
	.string "Peux-tu infliger des dégâts\n"
	.string "à nos POKéMON ?$"

SagePingBeatenText:
	.string "Ah ! Bien joué !$"

SagePingAfterBattleText:
	.string "Nous utilisons des POKéMON de type SPECTRE.\p"
	.string "Aucune attaque de type NORMAL ne\n"
	.string "peut les blesser !$"

MediumMarthaSeenText:
	.string "Je vais gagner !$"

MediumMarthaBeatenText:
	.string "J... J... J’ai perdu !$"

MediumMarthaAfterBattleText:
	.string "Celui qui veut gagner le plus\n"
	.string "est celui qui gagnera !$"

MediumGraceSeenText:
	.string "Perdu dans nos couloirs sombres ?\n"
	.string "Bats-moi si tu veux un indice !$"

MediumGraceBeatenText:
	.string "Quoi—quoi ?$"

MediumGraceAfterBattleText:
	.string "D’accord. Je vais te dire le secret\n"
	.string "des ombres.\p"
	.string "Le chemin est juste devant\n"
	.string "tes yeux !$"

EcruteakCity_GymGuideText:
	.string "Hé CHAMPION ! Tu es presque\n"
	.string "à la moitié du chemin !\p"
	.string "Ici, les Dresseurs utilisent des\n"
	.string "POKéMON de type SPECTRE et TÉNÈBRES.\p"
	.string "MORTIMER est un expert SPECTRE,\n"
	.string "mais méfie-toi de son cerf mystique.\l"
	.string "On dit qu’il provoque de\n"
	.string "terribles cauchemars...$"

EcruteakCity_GymGuideWinText:
	.string "Ouf, {PLAYER}. Tu as assuré !\p"
	.string "Je me cachais dans un coin\n"
	.string "de pure terreur !$"

EcruteakCity_GymClosedText:
	.string "MORTIMER, le CHAMPION d’ARÈNE,\n"
	.string "est absent.\p"
	.string "Désolé, mais tu dois\n"
	.string "partir.\p"
	.string "Hohohoho.$"
