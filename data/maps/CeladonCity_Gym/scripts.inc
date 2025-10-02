CeladonCity_Gym_MapScripts::
	.byte 0


CeladonCity_Gym_EventScript_Erika::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_CELADON_GYM, CeladonCity_Gym_EventScript_Erika_Defeated
	msgbox CeladonCity_Gym_Text_ErikaBeforeBattle, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_ERIKA, CeladonCity_Gym_Text_ErikaBeaten
	message CeladonCity_Gym_Text_PlayerReceivedRainbowBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox CeladonCity_Gym_Text_ErikaExplainTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_GIGA_DRAIN
	setflag FLAG_BADGE12_GET
	setflag FLAG_DEFEATED_CELADON_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 12
	call Common_EventScript_SetGymTrainers
	clearflag FLAG_HIDE_FOUNTAIN_ERIKA
	closemessage
	release
	end

CeladonCity_Gym_EventScript_Erika_Defeated::
	msgbox CeladonCity_Gym_Text_ErikaAfterBattle, MSGBOX_DEFAULT
	closemessage
	release
	end

CeladonCity_Gym_Text_ErikaBeforeBattle:
	.string "ERIKA : Bonjour… Quel temps\n"
	.string "magnifique, n'est-ce pas ? C'est si agréable…\p"
	.string "…J'ai peur de m'assoupir…\p"
	.string "Je m'appelle ERIKA. Je suis la CHAMPIONNE\n"
	.string "de l'ARÈNE de CELADOPOLE.\p"
	.string "…Oh ? Vous venez de JOHTO,\n"
	.string "vous dites ? Comme c'est charmant…\p"
	.string "Oh. Je suis désolée, je n'avais pas réalisé\n"
	.string "que vous vouliez me défier.\p"
	.string "Très bien, mais je ne perdrai pas.$"

CeladonCity_Gym_Text_ErikaBeaten:
	.string "ERIKA : Oh ! Je concède la défaite…\p"
	.string "Vous êtes remarquablement fort(e)…\p"
	.string "Je vais vous donner le BADGE PRISME…$"

CeladonCity_Gym_Text_PlayerReceivedRainbowBadge:
	.string "{PLAYER} reçoit le BADGE PRISME.$"

CeladonCity_Gym_Text_ErikaExplainTM:
	.string "ERIKA : Ce fut un match délicieux.\n"
	.string "\p"
	.string "Je me sens inspirée. S'il vous plaît, je\n"
	.string "souhaite que vous acceptiez cette CT.\p"
	.string "C'est GIGA-SANGSUE.\p"
	.string "C'est une capacité merveilleuse qui\n"
	.string "draine la moitié des dégâts infligés\l"
	.string "pour soigner votre POKéMON.\p"
	.string "Veuillez l'utiliser si cela vous plaît…$"

CeladonCity_Gym_Text_ErikaAfterBattle:
	.string "ERIKA : Perdre laisse un goût amer…\n"
	.string "\p"
	.string "Mais savoir qu'il existe des dresseurs\n"
	.string "forts me pousse à m'améliorer…$"

CeladonCity_Gym_Text_ErikaRematch:
	.string "ERIKA : Oh, bonjour.\p"
	.string "Quelle surprise, CHAMPION de KANTO !\p"
	.string "C'est si agréable de vous revoir.\p"
	.string "Votre voyage a dû être si\n"
	.string "excitant.\p"
	.string "Même les champions aiment un défi.\p"
	.string "Voulez-vous refaire un combat contre moi ?$"

CeladonCity_Gym_Text_ErikaRematchDefeat:
	.string "ERIKA : Perdre laisse toujours un\n"
	.string "goût amer…\p"
	.string "Mais savoir qu'il existe des dresseurs\n"
	.string "forts me pousse à m'améliorer…$"

CeladonCity_Gym_EventScript_Michelle::
	trainerbattle_single TRAINER_MICHELLE CeladonCity_Gym_Text_LassMichelleSeen, CeladonCity_Gym_Text_LassMichelleBeaten
	msgbox CeladonCity_Gym_Text_LassMichelleAfter, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_Text_LassMichelleSeen:
	.string "Tu trouves qu'une ARÈNE réservée\n"
	.string "aux filles, c'est rare ?$"

CeladonCity_Gym_Text_LassMichelleBeaten:
	.string "Oh, beurk !$"

CeladonCity_Gym_Text_LassMichelleAfter:
	.string "J'ai juste été distraite, c'est tout !$"


CeladonCity_Gym_EventScript_Tanya::
	trainerbattle_single TRAINER_TANYA CeladonCity_Gym_Text_PicnickerTanyaSeen, CeladonCity_Gym_Text_PicnickerTanyaBeaten
	msgbox CeladonCity_Gym_Text_PicnickerTanyaAfter, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_Text_PicnickerTanyaSeen:
	.string "Oh, a battle? That's kind of scary,\n"
	.string "but OK!$"

CeladonCity_Gym_Text_PicnickerTanyaBeaten:
	.string "Oh, that's it?$"

CeladonCity_Gym_Text_PicnickerTanyaAfter:
	.string "Oh, look at all your BADGES. No\n"
	.string "wonder I couldn't win!$"

CeladonCity_Gym_EventScript_Julia::
	trainerbattle_single TRAINER_JULIA CeladonCity_Gym_Text_BeautyJuliaSeen, CeladonCity_Gym_Text_BeautyJuliaBeaten
	msgbox CeladonCity_Gym_Text_BeautyJuliaAfter, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_Text_BeautyJuliaSeen:
	.string "Were you looking at these flowers\n"
	.string "or at me?$"

CeladonCity_Gym_Text_BeautyJuliaBeaten:
	.string "How annoying!$"

CeladonCity_Gym_Text_BeautyJuliaAfter:
	.string "How do I go about becoming\n"
	.string "ladylike like ERIKA?$"

CeladonCity_Gym_EventScript_Jo::
	trainerbattle_double TRAINER_JO_AND_ZOE, CeladonCity_Gym_Text_TwinsJoAndZoe1Seen, CeladonCity_Gym_Text_TwinsJoAndZoe1Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox CeladonCity_Gym_Text_TwinsJoAndZoe1After, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_EventScript_Zoe::
	trainerbattle_double TRAINER_JO_AND_ZOE, CeladonCity_Gym_Text_TwinsJoAndZoe2Seen, CeladonCity_Gym_Text_TwinsJoAndZoe2Beaten, Route104_Text_GinaNotEnoughMons
	msgbox CeladonCity_Gym_Text_TwinsJoAndZoe2After, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_Text_TwinsJoAndZoe1Seen:
	.string "Nous allons te montrer les attaques\n"
	.string "POKéMON qu'ERIKA nous a apprises !$"

CeladonCity_Gym_Text_TwinsJoAndZoe1Beaten:
	.string "Oh… Nous avons perdu…$"

CeladonCity_Gym_Text_TwinsJoAndZoe1After:
	.string "ERIKA te fera payer pour nous !$"

CeladonCity_Gym_Text_TwinsJoAndZoe2Seen:
	.string "Nous allons protéger ERIKA !$"

CeladonCity_Gym_Text_TwinsJoAndZoe2Beaten:
	.string "Nous n'avons pas pu gagner…$"

CeladonCity_Gym_Text_TwinsJoAndZoe2After:
	.string "ERIKA est bien, bien plus forte !$"

CeladonCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE12_GET, CeladonCity_Gym_EventScript_GymStatuePostVictory
	msgbox CeladonCity_Gym_Text_GymStatue
	releaseall
	end

CeladonCity_Gym_EventScript_GymStatuePostVictory::
	msgbox CeladonCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end

CeladonCity_Gym_Text_GymStatue::
    .string "ARÈNE POKéMON DE CELADOPOLE\n"
    .string "CHAMPIONNE : ERIKA\p"
    .string "DRESSEURS VICTORIEUX :\n"
    .string "BLUE, RED$"

CeladonCity_Gym_Text_GymStatuePlayerWon::
    .string "ARÈNE POKéMON DE CELADOPOLE\n"
    .string "CHAMPIONNE : ERIKA\p"
    .string "DRESSEURS VICTORIEUX :\n"
    .string "BLUE, RED, {PLAYER}$"
