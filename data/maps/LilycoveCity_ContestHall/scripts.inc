@ VAR_LAST_TALKED would have made all these direct references unnecessary
.set LOCALID_SMART_MC, 4
.set LOCALID_SMART_JUDGE, 5
.set LOCALID_SMART_CONTESTANT_1, 6
.set LOCALID_SMART_CONTESTANT_2, 7
.set LOCALID_SMART_CONTESTANT_3, 8
.set LOCALID_SMART_CONTESTANT_4, 9
.set LOCALID_SMART_AUDIENCE_4, 11
.set LOCALID_SMART_AUDIENCE_2, 12
.set LOCALID_BEAUTY_MC, 13
.set LOCALID_BEAUTY_JUDGE, 14
.set LOCALID_BEAUTY_CONTESTANT_1, 15
.set LOCALID_BEAUTY_CONTESTANT_2, 16
.set LOCALID_BEAUTY_CONTESTANT_3, 17
.set LOCALID_BEAUTY_CONTESTANT_4, 18
.set LOCALID_BEAUTY_AUDIENCE_1, 19
.set LOCALID_BEAUTY_AUDIENCE_3, 20
.set LOCALID_BEAUTY_AUDIENCE_2, 21
.set LOCALID_SMART_AUDIENCE_3, 22
.set LOCALID_CUTE_MC, 23
.set LOCALID_CUTE_JUDGE, 24
.set LOCALID_CUTE_CONTESTANT_1, 25
.set LOCALID_CUTE_CONTESTANT_2, 26
.set LOCALID_CUTE_CONTESTANT_3, 27
.set LOCALID_CUTE_CONTESTANT_4, 28
.set LOCALID_CUTE_AUDIENCE_1, 29
.set LOCALID_CUTE_AUDIENCE_3, 30
.set LOCALID_CUTE_AUDIENCE_2, 31

LilycoveCity_ContestHall_MapScripts::
	.byte 0

LilycoveCity_ContestHall_EventScript_Boy1::
	msgbox LilycoveCity_ContestHall_Text_TodayWonSmartnessContest, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_Boy2::
	msgbox LilycoveCity_ContestHall_Text_EnteredBunchOfContests, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_Girl::
	msgbox LilycoveCity_ContestHall_Text_ManWhoWonEarlierHadPokeblocks, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_Sailor::
	msgbox LilycoveCity_ContestHall_Text_IsntThisPlaceHumongous, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_SmartContestMC::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_GiveItBestSmartAppeal, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_MC, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestJudge::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_AreYouEnjoyingThisContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_JUDGE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant1::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_EnteredWrongContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_CONTESTANT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_RaisedMonToBeSmart, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_CONTESTANT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_IfMonPullsSmartMoveNext, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_CONTESTANT_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant4::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_DontAppreciateCuteLeechLife, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_CONTESTANT_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience1::
	msgbox LilycoveCity_ContestHall_Text_YoureBeautifulGrandpa, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_AllSeemToUseDifferentMoves, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_AUDIENCE_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_PokemonSmarterThanTrainers, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_AUDIENCE_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience4::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_StillLoveSmartnessContests, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_AUDIENCE_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestMC::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_AreYouEnteringBeautyContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_MC, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestJudge::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_EveryPokemonPristineBeauty, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_JUDGE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant1::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_EyesWillBeGluedToMyBeauty, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_CONTESTANT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_OverdidGrooming, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_CONTESTANT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_JudgeWontSeeAuroraBeam, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_CONTESTANT_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant4::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_PokemonLooksLikeYoungerMe, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_CONTESTANT_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestAudience1::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_WinBeautyContestMakesMeHappy, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_AUDIENCE_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestAudience2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_GanderAtAllThosePrettyPokemon, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_AUDIENCE_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestAudience3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_CantWinOnBeautyAlone, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_AUDIENCE_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestMC::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_InTheMiddleOfContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_MC, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestJudge::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_SuchCharmingCuteAppeals, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_JUDGE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant1::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_MyAzurillWasDistracted, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_CONTESTANT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_NeverWonBattleButContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_CONTESTANT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_PetalDanceIsMarvel, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_CONTESTANT_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant4::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_MyMonAppealSoMuchCuter, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_CONTESTANT_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestAudience1::
	lockall
	applymovement LOCALID_CUTE_AUDIENCE_1, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_ContestHall_Text_MyChildIsInContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_AUDIENCE_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	delay 25
	msgbox LilycoveCity_ContestHall_Text_ComeOnDear, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_ContestHall_EventScript_CuteContestAudience2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_WantCuteMonOfMyOwn, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_AUDIENCE_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestAudience3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_ThatGirlThereIsCutest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_AUDIENCE_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyStageSign::
	msgbox LilycoveCity_ContestHall_Text_BeautyContestStage, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_EventScript_CuteStageSign::
	msgbox LilycoveCity_ContestHall_Text_CuteContestStage, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_EventScript_SmartStageSign::
	msgbox LilycoveCity_ContestHall_Text_SmartContestStage, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_Text_TodayWonSmartnessContest:
	.string "Ce POKéMON a déjà gagné le CONCOURS\n"
	.string "de BEAUTÉ ici.\p"
	.string "Eh bien, devine quoi ? Aujourd'hui, je lui ai\n"
	.string "fait gagner un CONCOURS d'INTELLIGENCE !\p"
	.string "Mes capacités me font même peur…$"

LilycoveCity_ContestHall_Text_EnteredBunchOfContests:
	.string "J'ai participé à plein de CONCOURS,\n"
	.string "alors j'observe comment ça marche.\p"
	.string "Si tu es dans un CONCOURS de SANG-FROID,\n"
	.string "les attaques cool font bonne impression.\p"
	.string "Mais les attaques intelligentes ou mignonnes\n"
	.string "ne plaisent pas trop, par exemple.$"

LilycoveCity_ContestHall_Text_ManWhoWonEarlierHadPokeblocks:
	.string "Le jeune homme qui a gagné tout à l'heure\n"
	.string "avait plein de {POKEBLOCK}S différents.\p"
	.string "Peut-on gagner si on en a autant\n"
	.string "que lui ?$"

LilycoveCity_ContestHall_Text_IsntThisPlaceHumongous:
	.string "Ouah, cet endroit est immense !\p"
	.string "La tension dans l'air… Ce n'est pas\n"
	.string "comme une salle de CONCOURS de campagne.$"

LilycoveCity_ContestHall_Text_GiveItBestSmartAppeal:
	.string "MC : D'accord, POKéMON INTELLIGENTS et leurs\n"
	.string "DRESSEURS, êtes-vous prêts ?!\p"
	.string "Donnez le meilleur de vous-même !\n"
	.string "C'est l'heure de briller !$"

LilycoveCity_ContestHall_Text_AreYouEnjoyingThisContest:
	.string "JUGE : Tu apprécies ce CONCOURS ?\p"
	.string "Reviens avec trois amis, et\n"
	.string "vous pourrez tous participer à un CONCOURS !$"

LilycoveCity_ContestHall_Text_EnteredWrongContest:
	.string "Aïe aïe aïe…\n"
	.string "Je me suis trompé de CONCOURS.\p"
	.string "J'ai inscrit ce POKéMON costaud au\n"
	.string "CONCOURS d'INTELLIGENCE…\p"
	.string "Allez, impressionne-les avec un\n"
	.string "ÉCLATE-ROC intelligent !$"

LilycoveCity_ContestHall_Text_RaisedMonToBeSmart:
	.string "J'ai passé de nombreuses années, et toute\n"
	.string "ma sagesse, à élever ce POKéMON\l"
	.string "pour qu'il soit intelligent.\p"
	.string "Il ne sera pas facilement battu par le\n"
	.string "POKéMON d'un jeune débutant.\p"
	.string "Ma chère épouse, tu vois ça ?$"

LilycoveCity_ContestHall_Text_IfMonPullsSmartMoveNext:
	.string "Le voilà !\p"
	.string "Si mon POKéMON fait une attaque intelligente\n"
	.string "ensuite, l'excitation du public va atteindre son comble !$"

LilycoveCity_ContestHall_Text_DontAppreciateCuteLeechLife:
	.string "Oh non !\p"
	.string "La VAMPIGRAINE de mon adorable ZUBAT est\n"
	.string "si mignonne que je l'ai utilisée sans arrêt !\p"
	.string "Mais ces gens méchants ne l'apprécient\n"
	.string "pas du tout !$"

LilycoveCity_ContestHall_Text_YoureBeautifulGrandpa:
	.string "Kyaaaah ! Tu es magnifique, Papy !$"

LilycoveCity_ContestHall_Text_AllSeemToUseDifferentMoves:
	.string "Même quand les DRESSEURS présentent le même\n"
	.string "type de POKéMON, ils semblent tous utiliser\l"
	.string "des attaques différentes pour impressionner.\p"
	.string "C'est comme les styles de combat,\n"
	.string "chacun a le sien.$"

LilycoveCity_ContestHall_Text_PokemonSmarterThanTrainers:
	.string "Je trouve que les POKéMON ont l'air\n"
	.string "bien plus intelligents que leurs DRESSEURS.$"

LilycoveCity_ContestHall_Text_StillLoveSmartnessContests:
	.string "Au final, j'adore toujours les\n"
	.string "CONCOURS d'INTELLIGENCE.\p"
	.string "Cette couleur verte intellectuelle…\n"
	.string "C'est tellement… Tellement… Stylé !$"

LilycoveCity_ContestHall_Text_AreYouEnteringBeautyContest:
	.string "MC : Tu participes aussi au CONCOURS\n"
	.string "de BEAUTÉ ? Bonne chance !$"

LilycoveCity_ContestHall_Text_EveryPokemonPristineBeauty:
	.string "JUGE : Ah, chaque POKéMON ici est\n"
	.string "un modèle de beauté pure !\p"
	.string "J'en oublie presque de les noter !$"

LilycoveCity_ContestHall_Text_EyesWillBeGluedToMyBeauty:
	.string "Un POKéMON aussi beau…\n"
	.string "Il n'y en a pas d'autre comme lui.\p"
	.string "Tous les regards seront rivés sur\n"
	.string "ma beauté !$"

LilycoveCity_ContestHall_Text_OverdidGrooming:
	.string "Ouaaah !\p"
	.string "J'ai brossé et soigné mon POKéMON\n"
	.string "avec soin pour ce CONCOURS…\p"
	.string "Mais j'en ai trop fait…\n"
	.string "Son pelage est tout ébouriffé…\p"
	.string "Qu'est-ce que je dois faire ?$"

LilycoveCity_ContestHall_Text_JudgeWontSeeAuroraBeam:
	.string "Cette AURORA BEAM est si éblouissante\n"
	.string "que le JUGE ne pourra pas la voir.\p"
	.string "Euh, attends une seconde…\n"
	.string "Ça ne servira à rien, alors !$"

LilycoveCity_ContestHall_Text_PokemonLooksLikeYoungerMe:
	.string "Ce joli POKéMON me ressemble quand\n"
	.string "j'étais plus jeune.\p"
	.string "Dès que j'ai dit ça, mon mari a recraché\n"
	.string "le café qu'il buvait.\p"
	.string "Ai-je dit quelque chose de drôle ?$"

LilycoveCity_ContestHall_Text_WinBeautyContestMakesMeHappy:
	.string "Tu sais, si je gagne un CONCOURS\n"
	.string "de BEAUTÉ, ça me rend vraiment\l"
	.string "heureux. Plus que d'habitude, en tout cas.$"

LilycoveCity_ContestHall_Text_GanderAtAllThosePrettyPokemon:
	.string "Wahahahah !\p"
	.string "Regarde-moi tous ces beaux\n"
	.string "POKéMON !\l"
	.string "J'adore tout ce clinquant !$"

LilycoveCity_ContestHall_Text_CantWinOnBeautyAlone:
	.string "On ne peut pas toujours gagner\n"
	.string "juste avec la beauté.\p"
	.string "Il faut soigner son POKéMON pour\n"
	.string "qu'il soit aussi brillant que le mien.$"

LilycoveCity_ContestHall_Text_InTheMiddleOfContest:
	.string "MC : Oh, euh ! Bonjour !\n"
	.string "Nous sommes en plein CONCOURS !\p"
	.string "Merci de vous inscrire au comptoir\n"
	.string "et de revenir, d'accord ?$"

LilycoveCity_ContestHall_Text_SuchCharmingCuteAppeals:
	.string "JUGE : Oh, quelles prestations\n"
	.string "charmantes et mignonnes !\p"
	.string "Oh là là ! Quelle attaque\n"
	.string "ÉCLOSION D'EAU adorable !$"

LilycoveCity_ContestHall_Text_MyAzurillWasDistracted:
	.string "Oh non… Mon adorable AZURILL a été\n"
	.string "distrait par un autre POKéMON.$"

LilycoveCity_ContestHall_Text_NeverWonBattleButContest:
	.string "Mon POKéMON n'a jamais gagné en combat,\n"
	.string "mais en CONCOURS, attention !$"

LilycoveCity_ContestHall_Text_PetalDanceIsMarvel:
	.string "La DANSE-FLEUR de mon POKéMON est\n"
	.string "un vrai spectacle d'élégance.\p"
	.string "Je ne laisserai personne gâcher\n"
	.string "sa prestation !$"

LilycoveCity_ContestHall_Text_MyMonAppealSoMuchCuter:
	.string "Les POKéMON de tout le monde sont très mignons.\p"
	.string "Mais si mon POKéMON faisait une\n"
	.string "prestation mignonne…\p"
	.string "Je suis sûr qu'il serait bien plus\n"
	.string "mignon que les autres !$"

LilycoveCity_ContestHall_Text_MyChildIsInContest:
	.string "Mon enfant participe à ce CONCOURS.$"

LilycoveCity_ContestHall_Text_ComeOnDear:
	.string "Allez, chéri(e). Vas-y !\n"
	.string "Ton POKéMON est le meilleur !$"

LilycoveCity_ContestHall_Text_ThatGirlThereIsCutest:
	.string "Je trouve que la fille là-bas est\n"
	.string "la plus mignonne de toutes.\p"
	.string "Comment ? Ils jugent les POKéMON\n"
	.string "sur leur apparence ?$"

LilycoveCity_ContestHall_Text_WantCuteMonOfMyOwn:
	.string "Ohh, voir tous ces POKéMON mignons,\n"
	.string "ça me donne envie d'en avoir un !\p"
	.string "Je vais aller en attraper !$"

LilycoveCity_ContestHall_Text_BeautyContestStage:
	.string "SCÈNE DU CONCOURS DE BEAUTÉ\n"
	.string "LAISSEZ-VOUS SÉDUIRE PAR DE BEAUX POKéMON !$"

LilycoveCity_ContestHall_Text_CuteContestStage:
	.string "SCÈNE DU CONCOURS DE MIGNONNERIE\n"
	.string "SOYEZ CHARMÉ PAR DES POKéMON MIGNONS !$"

LilycoveCity_ContestHall_Text_SmartContestStage:
	.string "SCÈNE DU CONCOURS D'INTELLIGENCE\n"
	.string "SOYEZ IMPRESSIONNÉ PAR DES POKéMON INTELLIGENTS !$"
