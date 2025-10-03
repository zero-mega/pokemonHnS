.set LOCALID_STEVEN, 1

MeteorFalls_StevensCave_MapScripts::
	.byte 0

MeteorFalls_StevensCave_EventScript_Steven::
	lock
	goto_if_set FLAG_STEVEN_REMATCH, MeteorFalls_StevensCave_EventScript_StevenRematch
	goto_if_set FLAG_DEFEATED_RED, MeteorFalls_StevensCave_EventScript_Defeated
	waitse
	playse SE_PIN
	applymovement LOCALID_STEVEN, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_STEVEN, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_STEVEN, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MeteorFalls_StevensCave_Text_ShouldKnowHowGoodIAmExpectWorst, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_STEVEN, MeteorFalls_StevensCave_Text_StevenDefeat
	msgbox MeteorFalls_StevensCave_Text_MyPredictionCameTrue, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_RED
	setflag FLAG_SIDNEY_REMATCH
	setflag FLAG_PHOEBE_REMATCH
	setflag FLAG_GLACIA_REMATCH
	setflag FLAG_DRAKE_REMATCH
	setflag FLAG_WALLACE_REMATCH
	release
	end

MeteorFalls_StevensCave_EventScript_StevenRematch::
	waitse
	playse SE_PIN
	applymovement LOCALID_STEVEN, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_STEVEN, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_STEVEN, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MeteorFalls_StevensCave_Text_ShouldKnowHowGoodIAmExpectWorst2, MSGBOX_DEFAULT
	setflag FLAG_SYS_SET_BATTLE_BGM
	setvar VAR_TEMP_F, MUS_HG_VS_CHAMPION
	trainerbattle_no_intro TRAINER_STEVEN2, MeteorFalls_StevensCave_Text_StevenDefeat2
	msgbox MeteorFalls_StevensCave_Text_MyPredictionCameTrue2, MSGBOX_DEFAULT
	clearflag FLAG_STEVEN_REMATCH
	goto_if_unset FLAG_ARCEUS_EGG_GIVE MeteorFalls_StevensCave_EventScript_StevenArceusEvent
	release
	end

MeteorFalls_StevensCave_EventScript_Defeated::
	applymovement LOCALID_STEVEN, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MeteorFalls_StevensCave_Text_MyPredictionCameTrue, MSGBOX_DEFAULT
	release
	end

MeteorFalls_StevensCave_EventScript_StevenArceusEvent::
	msgbox MeteorFalls_StevensCave_Text_ArceusEvent1, MSGBOX_DEFAULT
	setflag FLAG_ARCEUS_EGG_GIVE
	playfanfare MUS_OBTAIN_ITEM
	message LavaridgeTown_Text_ReceivedTheEgg
	waitfanfare
	giveegg SPECIES_ARCEUS
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, MeteorFalls_StevensCave_EventScript_StevenArceusEventToParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, MeteorFalls_StevensCave_EventScript_StevenArceusEventToPC
	release
	end

MeteorFalls_StevensCave_EventScript_StevenArceusEventToParty::
	call Common_EventScript_GetGiftMonPartySlot
	msgbox MeteorFalls_StevensCave_Text_ArceusEvent2, MSGBOX_DEFAULT
	release
	end

MeteorFalls_StevensCave_EventScript_StevenArceusEventToPC::
	call Common_EventScript_TransferredToPC
	msgbox MeteorFalls_StevensCave_Text_ArceusEvent2, MSGBOX_DEFAULT
	release
	end

MeteorFalls_StevensCave_Text_ArceusEvent1:
	.string "Et… j’aimerais te donner\n"
	.string "quelque chose que j’ai trouvé en\l"
	.string "fouillant. C’est un œuf étrange.\p"
	.string "Je l’ai porté pendant des semaines\n"
	.string "mais il n’a jamais éclos.\p"
	.string "Tu es un meilleur Dresseur que moi,\n"
	.string "alors peut-être que tu pourras le faire éclore.$"

MeteorFalls_StevensCave_Text_ArceusEvent2:
	.string "Je me demande quel POKéMON pond ses\n"
	.string "œufs entre les rochers puis s’en va…\p"
	.string "Peut-être que c’est un POKéMON ancien ?\p"
	.string "Fufufu… qui sait…$"

MeteorFalls_StevensCave_Text_ShouldKnowHowGoodIAmExpectWorst:
	.string "PIERRE : Oh, waouh, {PLAYER}{KUN}.\n"
	.string "Je suis impressionné que tu aies su où me trouver.\p"
	.string "Est-ce que tu, euh… me considères\n"
	.string "juste comme un maniaque des pierres ?\p"
	.string "Non, ça ne peut pas être ça.\p"
	.string "Nous avons combattu ensemble au\n"
	.string "CENTRE SPATIAL de SOOTOPOLIS.\p"
	.string "Tu devrais bien savoir à quel point\n"
	.string "je suis fort.\p"
	.string "Bon, {PLAYER}{KUN}, si tu veux vraiment\n"
	.string "me défier, attends-toi au pire !$"

MeteorFalls_StevensCave_Text_ShouldKnowHowGoodIAmExpectWorst2:
	.string "PIERRE : Oh, salut, {PLAYER}{KUN}.\p"
	.string "Tu es de retour. WALLACE m’a dit que\n"
	.string "tu l’as battu, lui et tout le\l"
	.string "CONSEIL 4 à nouveau. C’est incroyable !\p"
	.string "Je suis devenu plus fort aussi. Peux-tu\n"
	.string "me lancer un vrai défi encore une fois ?\p"
	.string "Bon, {PLAYER}{KUN}, allons-y !$"

MeteorFalls_StevensCave_Text_StevenDefeat:
	.string "Toi…\n"
	.string "Je n’aurais jamais cru que tu deviendrais si fort…$"

MeteorFalls_StevensCave_Text_StevenDefeat2:
	.string "Toi…\n"
	.string "Personne ne peut te surpasser maintenant.$"

MeteorFalls_StevensCave_Text_MyPredictionCameTrue:
	.string "PIERRE : Maintenant que j’y pense, depuis\n"
	.string "notre première rencontre à la GROTTE\l"
	.string "GRANITE à MYOKARA, j’avais ce pressentiment.\p"
	.string "Je pensais que tu deviendrais un jour\n"
	.string "le CHAMPION.\p"
	.string "Mes prédictions se réalisent souvent.\p"
	.string "Et maintenant, que vas-tu faire ?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "Fufufu, que dirais-tu de ça ?\p"
	.string "Tu devrais commencer par défier à\n"
	.string "nouveau le CONSEIL 4. J’ai entendu dire\l"
	.string "qu’ils sont devenus bien plus forts. Qu’en penses-tu ?$"

MeteorFalls_StevensCave_Text_MyPredictionCameTrue2:
	.string "PIERRE : Maintenant que j’y pense, depuis\n"
	.string "notre première rencontre à la GROTTE\l"
	.string "GRANITE à MYOKARA, j’avais ce pressentiment.\p"
	.string "Je pensais que tu finirais par devenir\n"
	.string "plus fort que moi.\p"
	.string "Mes prédictions se réalisent souvent.\p"
	.string "Et maintenant, que vas-tu faire ?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "Fufufu, même moi je ne pourrais pas te le dire.$"
