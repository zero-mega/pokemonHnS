.set LOCALID_WALDAS_DAD, 6

RustboroCity_Flat1_2F_MapScripts::
	.byte 0

RustboroCity_Flat1_2F_EventScript_WaldasDad::
	lock
	faceplayer
	specialvar VAR_RESULT, TryBufferWaldaPhrase
	goto_if_eq VAR_RESULT, FALSE, RustboroCity_Flat1_2F_EventScript_WaldasDadFirstPhrase
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_Flat1_2F_EventScript_WaldasDadNewPhrase

RustboroCity_Flat1_2F_EventScript_GivePhrase::
	special DoWaldaNamingScreen
	waitstate
	goto_if_eq VAR_0x8004, 1, RustboroCity_Flat1_2F_EventScript_CancelGivePhrase
	goto_if_eq VAR_0x8004, 2, RustboroCity_Flat1_2F_EventScript_CancelGiveFirstPhrase
	specialvar VAR_RESULT, TryGetWallpaperWithWaldaPhrase
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_Flat1_2F_EventScript_WaldaLikesPhrase
	goto_if_eq VAR_RESULT, FALSE, RustboroCity_Flat1_2F_EventScript_WaldaDoesntLikePhrase
	end

RustboroCity_Flat1_2F_EventScript_WaldasDadFirstPhrase::
	msgbox RustboroCity_Flat1_2F_Text_HelloDoYouKnowFunnyPhrase, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_Flat1_2F_EventScript_DeclineGivePhrase
	msgbox RustboroCity_Flat1_2F_Text_WonderfulLetsHearSuggestion, MSGBOX_DEFAULT
	goto RustboroCity_Flat1_2F_EventScript_GivePhrase

RustboroCity_Flat1_2F_EventScript_WaldasDadNewPhrase::
	msgbox RustboroCity_Flat1_2F_Text_BeenSayingXDoYouKnowBetterPhrase, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_Flat1_2F_EventScript_DeclineGivePhrase
	msgbox RustboroCity_Flat1_2F_Text_WonderfulLetsHearSuggestion, MSGBOX_DEFAULT
	goto RustboroCity_Flat1_2F_EventScript_GivePhrase

RustboroCity_Flat1_2F_EventScript_DeclineGivePhrase::
	msgbox RustboroCity_Flat1_2F_Text_OhIsThatRight, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_CancelGivePhrase::
	msgbox RustboroCity_Flat1_2F_Text_OhYouDontKnowAny, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_CancelGiveFirstPhrase::
	msgbox RustboroCity_Flat1_2F_Text_ThinkOfMyOwnPhrase, MSGBOX_DEFAULT
	call RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda
	msgbox RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll2, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_WaldaLikesPhrase::
	msgbox RustboroCity_Flat1_2F_Text_LetsGiveItATry2, MSGBOX_DEFAULT
	call RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda
	msgbox RustboroCity_Flat1_2F_Text_OhShesLaughing, MSGBOX_DEFAULT
	applymovement LOCALID_WALDAS_DAD, Common_Movement_FacePlayer
	waitmovement 0
	msgbox RustboroCity_Flat1_2F_Text_ThankYouIllGiveYouWallpaper, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_WaldaDoesntLikePhrase::
	msgbox RustboroCity_Flat1_2F_Text_LetsGiveItATry, MSGBOX_DEFAULT
	call RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda
	msgbox RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda::
	turnobject LOCALID_WALDAS_DAD, DIR_EAST
	return

RustboroCity_Flat1_2F_EventScript_WaldasMom::
	msgbox RustboroCity_Flat1_2F_Text_ComingUpWithMealsIsHard, MSGBOX_NPC
	end

RustboroCity_Flat1_2F_EventScript_PokeDoll::
	msgbox RustboroCity_Flat1_2F_Text_ItsAPokemonPlushDoll, MSGBOX_SIGN
	end

RustboroCity_Flat1_2F_Text_ComingUpWithMealsIsHard:
	.string "Oh, c'est tellement difficile chaque jour…\p"
	.string "Qu'est-ce qui est difficile ?\n"
	.string "Tu dois demander ?\p"
	.string "C'est de trouver quoi préparer\n"
	.string "à manger chaque jour.\p"
	.string "Ce n'est vraiment pas facile de trouver\n"
	.string "des repas tous les jours.$"

RustboroCity_Flat1_2F_Text_HelloDoYouKnowFunnyPhrase:
	.string "Oh, bonjour !\n"
	.string "Bienvenue chez la famille POIVRE.\p"
	.string "J'ai une question pour toi.\n"
	.string "As-tu déjà fait du baby-sitting ?\p"
	.string "Tu vois, je suis un nouveau père, donc\n"
	.string "élever un enfant est tout nouveau pour moi.\p"
	.string "Et j'ai un problème. Ma fille\n"
	.string "WALDA ne rit pas assez.\p"
	.string "Je pense qu'elle rirait si je lui disais\n"
	.string "quelque chose de drôle.\p"
	.string "Connais-tu un mot ou une phrase drôle\n"
	.string "que tu pourrais me dire ?$"

RustboroCity_Flat1_2F_Text_BeenSayingXDoYouKnowBetterPhrase:
	.string "J'ai dit « {STR_VAR_1} »\n"
	.string "pour l'amuser récemment.\p"
	.string "Connais-tu un meilleur mot ou\n"
	.string "une phrase qui pourrait marcher ?$"

RustboroCity_Flat1_2F_Text_WonderfulLetsHearSuggestion:
	.string "Oh, c'est merveilleux.\n"
	.string "Alors, voyons ta suggestion.$"

RustboroCity_Flat1_2F_Text_OhIsThatRight:
	.string "Ah, c'est vrai ?\p"
	.string "Eh bien, si tu trouves une bonne\n"
	.string "suggestion, je suis tout ouïe.$"

RustboroCity_Flat1_2F_Text_LetsGiveItATry2:
	.string "Ah, je vois.\n"
	.string "Eh bien, essayons, d'accord ?$"

RustboroCity_Flat1_2F_Text_OhShesLaughing:
	.string "{STR_VAR_1}.\n"
	.string "{STR_VAR_1}.\p"
	.string "Oh, oui ! Elle rit !\n"
	.string "Oh, je suis aussi ravi qu'elle !$"

RustboroCity_Flat1_2F_Text_LetsGiveItATry:
	.string "Ah, je vois.\n"
	.string "Eh bien, essayons, d'accord ?$"

RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll:
	.string "{STR_VAR_1}.\n"
	.string "{STR_VAR_1}.\p"
	.string "Hmm… Elle ne sourit pas du tout.\n"
	.string "Peut-être que WALDA est une enfant très sérieuse…$"

RustboroCity_Flat1_2F_Text_ThinkOfMyOwnPhrase:
	.string "Oh, donc tu ne connais pas de bons mots.\n"
	.string "Je ferais mieux de réfléchir moi-même, alors.\p"
	.string "Hmm…\n"
	.string "Et si j'essayais « {STR_VAR_1} » ?\l"
	.string "Voyons si ça marche.$"

RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll2:
	.string "{STR_VAR_1}.\n"
	.string "{STR_VAR_1}.\p"
	.string "Hmm… Elle ne sourit pas du tout.\n"
	.string "Peut-être que WALDA est une enfant très sérieuse…$"

RustboroCity_Flat1_2F_Text_OhYouDontKnowAny:
	.string "Oh, donc tu ne connais pas de bons mots.\n"
	.string "Je vais essayer de l'amuser avec\l"
	.string "la phrase que j'ai utilisée avant.\p"
	.string "En tout cas, si tu as une bonne suggestion,\n"
	.string "n'hésite pas à me le dire, d'accord ?$"

RustboroCity_Flat1_2F_Text_ThankYouIllGiveYouWallpaper:
	.string "Merci !\p"
	.string "Grâce à toi, ma chère WALDA\n"
	.string "a ri pour moi !\p"
	.string "En fait, je n'en ai peut-être pas l'air,\n"
	.string "mais je suis l'un des meilleurs chercheurs\l"
	.string "de la DEVON SARL.\p"
	.string "Alors, que dirais-tu que je fasse\n"
	.string "quelque chose pour toi en retour ?\p"
	.string "Je sais, j'ajouterai de nouveaux motifs\n"
	.string "de papier peint pour les BOÎTES du PC\l"
	.string "du Système de Stockage POKéMON.\p"
	.string "Dans le menu des motifs de papier peint,\n"
	.string "sélectionne « AMIS ».\p"
	.string "Cela te donnera accès aux nouveaux\n"
	.string "motifs de papier peint.$"

RustboroCity_Flat1_2F_Text_ItsAPokemonPlushDoll:
	.string "C'est une peluche POKéMON !$"
