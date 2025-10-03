MahoganyTown_Gym_MapScripts::
	.byte 0


MahoganyTown_Gym_EventScript_Statue::
	lock
	goto_if_set FLAG_DEFEATED_MAHOGANY_TOWN_GYM,  MahoganyTown_Gym_EventScript_Statue2
	msgbox MahoganyTown_Gym_Text_GymStatue, MSGBOX_DEFAULT
	closemessage
	release
	end

MahoganyTown_Gym_EventScript_Statue2::
	msgbox MahoganyTown_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	closemessage
	release
	end

MahoganyTown_Gym_Text_GymStatue:
	.string "MAHOGANY TOWN POKéMON GYM$"

MahoganyTown_Gym_Text_GymStatueCertified:
	.string "MAHOGANY TOWN POKéMON GYM\p"
	.string "PRYCE'S CERTIFIED TRAINERS:\n"
	.string "{PLAYER}$"


MahoganyTown_GymEventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_MAHOGANY_TOWN_GYM, MahoganyTown_Gym_EventScript_GymGuy2
	msgbox MahoganyTown_Gym_Text_Guide, MSGBOX_DEFAULT
	closemessage
	release
	end
	
MahoganyTown_Gym_EventScript_GymGuy2::
	msgbox MahoganyTown_Gym_Text_GuideWin, MSGBOX_DEFAULT
	release
	end	

MahoganyTown_Gym_EventScript_Ronald::
	trainerbattle_single TRAINER_RONALD MahoganyTown_Gym_Text_BoarderRonaldSeen, MahoganyTown_Gym_Text_BoarderRonaldBeaten
	msgbox MahoganyTown_Gym_Text_BoarderRonaldAfter, MSGBOX_AUTOCLOSE
	end

MahoganyTown_Gym_EventScript_Brad::
	trainerbattle_single TRAINER_BRAD MahoganyTown_Gym_Text_BoarderBradSeen, MahoganyTown_Gym_Text_BoarderBradBeaten
	msgbox MahoganyTown_Gym_Text_BoarderBradAfter, MSGBOX_AUTOCLOSE
	end

MahoganyTown_Gym_EventScript_Douglas::
	trainerbattle_single TRAINER_DOUGLAS MahoganyTown_Gym_Text_BoarderDouglasSeen, MahoganyTown_Gym_Text_BoarderDouglasBeaten
	msgbox MahoganyTown_Gym_Text_BoarderDouglasAfter, MSGBOX_AUTOCLOSE
	end

MahoganyTown_Gym_EventScript_Roxanne::
	trainerbattle_single TRAINER_ROXANNE MahoganyTown_Gym_Text_SkierRoxanneSeen, MahoganyTown_Gym_Text_SkierRoxanneBeaten
	msgbox MahoganyTown_Gym_Text_SkierRoxanneAfter, MSGBOX_AUTOCLOSE
	end

MahoganyTown_Gym_EventScript_Clarissa::
	trainerbattle_single TRAINER_CLARISSA MahoganyTown_Gym_Text_SkierClarissaSeen, MahoganyTown_Gym_Text_SkierClarissaBeaten
	msgbox MahoganyTown_Gym_Text_SkierClarissaAfter, MSGBOX_AUTOCLOSE
	end

MahoganyTown_Gym_EventScript_Pryce::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_MAHOGANY_TOWN_GYM, MahoganyTown_Gym_EventScript_Pryce_Defeated
	msgbox MahoganyTown_Gym_Text_PryceIntro, MSGBOX_DEFAULT
	goto_if_set FLAG_DEFEATED_OLIVINE_CITY_GYM, MahoganyTown_Gym_EventScript_OlivineCheckCianwood
	goto_if_set FLAG_DEFEATED_CIANWOOD_GYM, MahoganyTown_Gym_EventScript_CianwoodCheckOlivine
	goto MahoganyTown_Gym_EventScript_Pryce_Battle1

MahoganyTown_Gym_EventScript_PryceVictory::
	message MahoganyTown_Gym_Text_ReceivedBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox MahoganyTown_Gym_Text_GlacierBadgeSpeech, MSGBOX_DEFAULT
	setflag FLAG_BADGE07_GET
	setflag FLAG_DEFEATED_MAHOGANY_TOWN_GYM
    addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 7
	call Common_EventScript_SetGymTrainers
	giveitem ITEM_TM_HAIL
	msgbox MahoganyTown_Gym_Text_HailSpeech, MSGBOX_DEFAULT
	setvar VAR_MAHOGANY_TOWN_STATE, 15
    setrespawn HEAL_LOCATION_MAHOGANYTOWN
	closemessage
	release
	end

MahoganyTown_Gym_EventScript_OlivineCheckCianwood::
	goto_if_set FLAG_DEFEATED_CIANWOOD_GYM, MahoganyTown_Gym_EventScript_Pryce_Battle3
	goto MahoganyTown_Gym_EventScript_Pryce_Battle2

MahoganyTown_Gym_EventScript_CianwoodCheckOlivine::
	goto_if_set FLAG_DEFEATED_OLIVINE_CITY_GYM, MahoganyTown_Gym_EventScript_Pryce_Battle3
	goto MahoganyTown_Gym_EventScript_Pryce_Battle2
	
MahoganyTown_Gym_EventScript_Pryce_Battle1::
	trainerbattle_no_intro TRAINER_PRYCE_1, MahoganyTown_Gym_Text_PryceImpressed
	goto MahoganyTown_Gym_EventScript_PryceVictory

MahoganyTown_Gym_EventScript_Pryce_Battle2::
	trainerbattle_no_intro TRAINER_PRYCE_1_2, MahoganyTown_Gym_Text_PryceImpressed
	goto MahoganyTown_Gym_EventScript_PryceVictory

MahoganyTown_Gym_EventScript_Pryce_Battle3::
	trainerbattle_no_intro TRAINER_PRYCE_1_3, MahoganyTown_Gym_Text_PryceImpressed
	goto MahoganyTown_Gym_EventScript_PryceVictory

MahoganyTown_Gym_EventScript_Pryce_Defeated::
	msgbox MahoganyTown_Gym_Text_CherishPokemon, MSGBOX_DEFAULT
	closemessage
	release
	end

MahoganyTown_Gym_Text_PryceIntro:
    .string "Les POKéMON vivent de nombreuses expériences\n"
    .string "au cours de leur vie, tout comme nous.\p"
    .string "Moi aussi, j'ai vu et enduré\n"
    .string "beaucoup de choses dans ma vie.\p"
    .string "Puisque je suis ton aîné, laisse-moi\n"
    .string "te montrer ce que je veux dire.\p"
    .string "Je suis avec les POKéMON depuis\n"
    .string "avant ta naissance.\p"
    .string "Je ne perds pas facilement.\p"
    .string "Moi, PRYCE—l'entraîneur de l'hiver—\n"
    .string "vais te montrer ma puissance !$"

MahoganyTown_Gym_Text_PryceImpressed:
    .string "Ah, je suis impressionné par\n"
    .string "ta prouesse.\p"
    .string "Avec ta volonté forte, je sais que tu\n"
    .string "surmonteras tous les obstacles de la vie.\p"
    .string "Tu mérites ce BADGE !$"

MahoganyTown_Gym_Text_ReceivedBadge:
    .string "{PLAYER} reçoit le BADGE GLACE.$"

MahoganyTown_Gym_Text_GlacierBadgeSpeech:
    .string "Ce BADGE augmentera l'ATTAQUE\n"
    .string "SPÉCIALE de tes POKéMON.\p"
    .string "Il permet aussi à tes POKéMON d'utiliser\n"
    .string "SURF pour traverser de vrais\l"
    .string "tourbillons.\p"
    .string "Et ceci… C'est un cadeau de ma part !$"

MahoganyTown_Gym_Text_HailSpeech:
    .string "Cette CT contient GRÊLE.\p"
    .string "Elle inflige des dégâts à chaque\n"
    .string "tour pendant 5 tours.\p"
    .string "Elle montre la rudesse\n"
    .string "de l'hiver.$"

MahoganyTown_Gym_Text_CherishPokemon:
    .string "Quand la glace et la neige fondent,\n"
    .string "le printemps arrive.\p"
    .string "Toi et tes POKéMON serez\n"
    .string "ensemble pendant de nombreuses années.\p"
    .string "Chéris le temps passé ensemble !$"

MahoganyTown_Gym_Text_PryceRematch:
    .string "Ah, CHAMPION de JOHTO !\p"
    .string "Tes compétences sont vraiment\n"
    .string "remarquables.\p"
    .string "Je suis impressionné.\p"
    .string "Mais même maintenant, nous avons\n"
    .string "encore beaucoup à apprendre l'un de l'autre.\p"
    .string "Moi, PRYCE—l'entraîneur de l'hiver—\n"
    .string "j'ai encore quelques astuces.\p"
    .string "Veux-tu un match revanche contre moi ?$"

MahoganyTown_Gym_Text_PryceRematchDefeat:
    .string "Ah, encore une fois je suis impressionné par\n"
    .string "ta prouesse.\p"
    .string "Avec ta volonté forte, je sais que tu\n"
    .string "surmonteras tous les obstacles de la vie.$"

MahoganyTown_Gym_Text_Guide:
    .string "PRYCE est un vétéran qui entraîne\n"
    .string "des POKéMON depuis environ 50 ans.\p"
    .string "Il a une équipe solide de\n"
    .string "POKéMON pour contrer tout ce que\l"
    .string "tu pourrais lui opposer.\p"
    .string "Le feu est un bon début,\n"
    .string "mais attention à la pluie !$"

MahoganyTown_Gym_Text_GuideWin:
    .string "PRYCE est impressionnant, mais toi,\n"
    .string "tu l'es encore plus !\p"
    .string "C'était un combat intense qui a\n"
    .string "réuni les générations !$"

MahoganyTown_Gym_Text_BoarderRonaldSeen:
    .string "Je vais geler tes POKéMON,\n"
    .string "pour que tu ne puisses rien faire !$"

MahoganyTown_Gym_Text_BoarderRonaldBeaten:
    .string "Zut. Je n'ai rien pu faire.$"

MahoganyTown_Gym_Text_BoarderRonaldAfter:
    .string "Je pense qu'il existe une attaque\n"
    .string "qu'un POKéMON peut utiliser même\l"
    .string "quand il est gelé.$"

MahoganyTown_Gym_Text_BoarderBradSeen:
    .string "Ce CHAMPIONNAT a un sol glissant.\p"
    .string "C'est amusant, non ?\p"
    .string "Mais hé—on ne joue pas\n"
    .string "ici !$"

MahoganyTown_Gym_Text_BoarderBradBeaten:
    .string "Tu vois à quel point nous sommes sérieux ?$"

MahoganyTown_Gym_Text_BoarderBradAfter:
    .string "Ce GYM est génial.\n"
    .string "J'adore faire du snowboard avec mes\l"
    .string "POKéMON !$"

MahoganyTown_Gym_Text_BoarderDouglasSeen:
    .string "Je connais le secret de PRYCE.$"

MahoganyTown_Gym_Text_BoarderDouglasBeaten:
    .string "OK. Je vais te dire le secret de PRYCE.$"

MahoganyTown_Gym_Text_BoarderDouglasAfter:
    .string "Le secret de la force de PRYCE…\p"
    .string "Il médite sous une cascade\n"
    .string "chaque jour pour renforcer son esprit\l"
    .string "et son corps.$"

MahoganyTown_Gym_Text_SkierRoxanneSeen:
    .string "Pour atteindre PRYCE, notre CHAMPION,\n"
    .string "il faut réfléchir avant de glisser !$"

MahoganyTown_Gym_Text_SkierRoxanneBeaten:
    .string "Je ne perdrais pas contre toi au ski !$"

MahoganyTown_Gym_Text_SkierRoxanneAfter:
    .string "Si tu ne glisses pas avec précision,\n"
    .string "tu n'iras pas loin dans ce GYM !$"

MahoganyTown_Gym_Text_SkierClarissaSeen:
    .string "Regarde mon virage parallèle !$"

MahoganyTown_Gym_Text_SkierClarissaBeaten:
    .string "Non ! Tu m'as fait tomber !$"

MahoganyTown_Gym_Text_SkierClarissaAfter:
    .string "Je n'aurais pas dû me vanter\n"
    .string "de mon ski…$"

