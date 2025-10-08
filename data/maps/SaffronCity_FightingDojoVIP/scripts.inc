SaffronCity_FightingDojoVIP_MapScripts::
	.byte 0

SaffronCity_FightingDojoVIP_EventScript_Declined::
	closemessage
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Falkner::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Falkner_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	trainerbattle_no_intro TRAINER_FALKNER_2, SaffronCity_FightingDojoVIP_Text_Falkner_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Bugsy::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Bugsy_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	trainerbattle_no_intro TRAINER_BUGSY_2, SaffronCity_FightingDojoVIP_Text_Bugsy_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Whitney::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Whitney_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	trainerbattle_no_intro TRAINER_WHITNEY_2, SaffronCity_FightingDojoVIP_Text_Whitney_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Morty::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Morty_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	trainerbattle_no_intro TRAINER_MORTY_2, SaffronCity_FightingDojoVIP_Text_Morty_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Chuck::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Chuck_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	trainerbattle_no_intro TRAINER_CHUCK_2, SaffronCity_FightingDojoVIP_Text_Chuck_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Jasmine::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Jasmine_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	trainerbattle_no_intro TRAINER_JASMINE_2, SaffronCity_FightingDojoVIP_Text_Jasmine_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Pryce::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Pryce_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	trainerbattle_no_intro TRAINER_PRYCE_2, SaffronCity_FightingDojoVIP_Text_Pryce_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Clair::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Clair_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	trainerbattle_no_intro TRAINER_CLAIR_2, SaffronCity_FightingDojoVIP_Text_Clair_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Brock::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Brock_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	trainerbattle_no_intro TRAINER_BROCK, SaffronCity_FightingDojoVIP_Text_Brock_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Misty::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Misty_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	trainerbattle_no_intro TRAINER_MISTY, SaffronCity_FightingDojoVIP_Text_Misty_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Surge::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Surge_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	trainerbattle_no_intro TRAINER_LTSURGE, SaffronCity_FightingDojoVIP_Text_Surge_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Erika::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Erika_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	trainerbattle_no_intro TRAINER_ERIKA, SaffronCity_FightingDojoVIP_Text_Erika_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Janine::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Janine_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	trainerbattle_no_intro TRAINER_JANINE, SaffronCity_FightingDojoVIP_Text_Janine_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Sabrina::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Sabrina_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	trainerbattle_no_intro TRAINER_SABRINA, SaffronCity_FightingDojoVIP_Text_Sabrina_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Blaine::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Blaine_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	trainerbattle_no_intro TRAINER_BLAINE, SaffronCity_FightingDojoVIP_Text_Blaine_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Blue::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Blue_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	trainerbattle_no_intro TRAINER_BLUE, SaffronCity_FightingDojoVIP_Text_Blue_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

@===============MONS===============================================================================================================

SaffronCity_FightingDojoVIP_EventScript_Scizor::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SCIZOR, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojoVIP_Text_Scizor, MSGBOX_DEFAULT
	waitmoncry
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
SaffronCity_FightingDojoVIP_Text_Scizor:
	.string "SCIZOR: Scii-zor!$"

SaffronCity_FightingDojoVIP_EventScript_Miltank::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MILTANK, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojoVIP_Text_Miltank, MSGBOX_DEFAULT
	waitmoncry
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
SaffronCity_FightingDojoVIP_Text_Miltank:
	.string "MILTANK: MooOOO!$"

SaffronCity_FightingDojoVIP_EventScript_Poliwhirl::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_POLIWHIRL, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojoVIP_Text_Poliwhirl, MSGBOX_DEFAULT
	waitmoncry
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
SaffronCity_FightingDojoVIP_Text_Poliwhirl:
	.string "POLIWHIRL: Whirl-whirl!$"

SaffronCity_FightingDojoVIP_EventScript_Dewgong::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_DEWGONG, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojoVIP_Text_Dewgong, MSGBOX_DEFAULT
	waitmoncry
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
SaffronCity_FightingDojoVIP_Text_Dewgong:
	.string "DEWGONG: Goooooong!$"

SaffronCity_FightingDojoVIP_EventScript_Steelix::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_STEELIX, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojoVIP_Text_Steelix, MSGBOX_DEFAULT
	waitmoncry
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
SaffronCity_FightingDojoVIP_Text_Steelix:
	.string "STEELIX: GraaAAANk!$"

SaffronCity_FightingDojoVIP_EventScript_Kingdra::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_KINGDRA, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojoVIP_Text_Kingdra, MSGBOX_DEFAULT
	waitmoncry
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
SaffronCity_FightingDojoVIP_Text_Kingdra:
	.string "KINGDRA: Draaa...$"

SaffronCity_FightingDojoVIP_EventScript_Onix::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ONIX, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojoVIP_Text_Onix, MSGBOX_DEFAULT
	waitmoncry
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
SaffronCity_FightingDojoVIP_Text_Onix:
	.string "ONIX: Oooonix!$"

SaffronCity_FightingDojoVIP_EventScript_Starmie::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_STARMIE, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojoVIP_Text_Starmie, MSGBOX_DEFAULT
	waitmoncry
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
SaffronCity_FightingDojoVIP_Text_Starmie:
	.string "STARMIE: Hyaaa!$"

SaffronCity_FightingDojoVIP_EventScript_Victreebel::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_VICTREEBEL, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojoVIP_Text_Victreebel, MSGBOX_DEFAULT
	waitmoncry
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
SaffronCity_FightingDojoVIP_Text_Victreebel:
	.string "VICTREEBEL: Vreeee!$"

SaffronCity_FightingDojoVIP_EventScript_Muk::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MUK, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojoVIP_Text_Muk, MSGBOX_DEFAULT
	waitmoncry
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
SaffronCity_FightingDojoVIP_Text_Muk:
	.string "MUK: Muuuk...$"

SaffronCity_FightingDojoVIP_EventScript_Kadabra::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_KADABRA, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojoVIP_Text_Kadabra, MSGBOX_DEFAULT
	waitmoncry
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
SaffronCity_FightingDojoVIP_Text_Kadabra:
	.string "KADABRA: Kadabra!$"

SaffronCity_FightingDojoVIP_EventScript_Magmar::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MAGMAR, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojoVIP_Text_Magmar, MSGBOX_DEFAULT
	waitmoncry
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
SaffronCity_FightingDojoVIP_Text_Magmar:
	.string "MAGMAR: Magmaaaar!$"

SaffronCity_FightingDojoVIP_EventScript_Raichu::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_RAICHU, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojoVIP_Text_Raichu, MSGBOX_DEFAULT
	waitmoncry
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
SaffronCity_FightingDojoVIP_Text_Raichu:
	.string "RAICHU: Rai-CHU!$"

SaffronCity_FightingDojoVIP_EventScript_Machamp::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MACHAMP, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojoVIP_Text_Machamp, MSGBOX_DEFAULT
	waitmoncry
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
SaffronCity_FightingDojoVIP_Text_Machamp:
	.string "MACHAMP: Maa-champ!$"

SaffronCity_FightingDojo_EventScript_Chased::
	msgbox SaffronCity_FightingDojoVIP_Text_Chased, MSGBOX_NPC
	end

SaffronCity_FightingDojoVIP_Text_Chased:
	.string "Help!$"

SaffronCity_FightingDojoVIP_EvetScript_Statue::
	msgbox SaffronCity_FightingDojoVIP_Text_Statue, MSGBOX_SIGN
	end

SaffronCity_FightingDojoVIP_Text_Statue:
	.string "SALON VIP DU DOJO KARATÉ$"

SaffronCity_FightingDojoVIP_Text_Falkner_Rematch:
	.string "Félicitations pour avoir vaincu\n"
	.string "le CONSEIL 4 !\p"
	.string "J'ai encore plus entraîné mes\n"
	.string "POKéMON de type VOL.\p"
	.string "Penses-tu pouvoir affronter à\n"
	.string "nouveau la puissance des cieux ?$"

SaffronCity_FightingDojoVIP_Text_Falkner_RematchDefeat:
	.string "Ouah… Tu m'as encore battu.\p"
	.string "Je vais m'entraîner encore plus\n"
	.string "pour devenir le plus grand maître des oiseaux !$"

SaffronCity_FightingDojoVIP_Text_Bugsy_Rematch:
	.string "Ouah, tu es maintenant le CHAMPION\n"
	.string "de JOHTO !\p"
	.string "Tes talents sont vraiment impressionnants !\p"
	.string "J'étais occupé par mes recherches.\p"
	.string "Je suis prêt à te montrer mes\n"
	.string "nouvelles découvertes.\p"
	.string "Veux-tu refaire un combat contre moi ?$"

SaffronCity_FightingDojoVIP_Text_Bugsy_RematchDefeat:
	.string "Ouah, tu dois être un Dresseur\n"
	.string "expert.\p"
	.string "Mes recherches ne sont pas encore\n"
	.string "terminées…$"

SaffronCity_FightingDojoVIP_Text_Whitney_Rematch:
	.string "Salut ! C'est toi !\p"
	.string "Ouah, CHAMPION de JOHTO maintenant ?\p"
	.string "Tu es vraiment incroyable !\p"
	.string "Je veux voir à quel point tu es fort.\p"
	.string "Veux-tu refaire un combat contre moi ?$"

SaffronCity_FightingDojoVIP_Text_Whitney_RematchDefeat:
	.string "Bouhouhou !\p"
	.string "Bouhouhou !\p"
	.string "…Snif, hic… …T'es méchant !$"

SaffronCity_FightingDojoVIP_Text_Morty_Rematch:
	.string "Ah, le CHAMPION de JOHTO !\n"
	.string "C'est bien que tu sois venu.\p"
	.string "Tu as montré ta force et ton\n"
	.string "talent, mais as-tu progressé\l"
	.string "depuis notre dernier combat ?\p"
	.string "Je me suis entraîné avec mes\n"
	.string "POKéMON de type SPECTRE.\p"
	.string "Voyons si tu peux à nouveau\n"
	.string "surmonter les ombres.\p"
	.string "Veux-tu refaire un combat contre moi ?$"

SaffronCity_FightingDojoVIP_Text_Morty_RematchDefeat:
	.string "Je ne suis pas encore assez bon…\p"
	.string "Tu as vu bien plus de choses\n"
	.string "que moi.\p"
	.string "Je t'envie pour cela…$"

SaffronCity_FightingDojoVIP_Text_Chuck_Rematch:
	.string "WAHAHAH ! CHAMPION de JOHTO !\p"
	.string "Tu es revenu pour plus !\p"
	.string "Je vois que tu t'es amélioré !\p"
	.string "Prêt à voir qui est le plus fort ?$"

SaffronCity_FightingDojoVIP_Text_Chuck_RematchDefeat:
	.string "Hein ? Quoi ? J'ai perdu ? Encore ?$"

SaffronCity_FightingDojoVIP_Text_Jasmine_Rematch:
	.string "…Félicitations, CHAMPION\n"
	.string "de JOHTO.\p"
	.string "Tu es devenu si fort…\p"
	.string "Je me demande si j'ai progressé.\p"
	.string "Voudrais-tu tester cela ?\p"
	.string "Veux-tu refaire un combat contre moi ?$"

SaffronCity_FightingDojoVIP_Text_Jasmine_RematchDefeat:
	.string "…Tu es un meilleur Dresseur que\n"
	.string "moi,\p"
	.string "en talent et en gentillesse.$"

SaffronCity_FightingDojoVIP_Text_Pryce_Rematch:
	.string "Ah, CHAMPION de JOHTO !\p"
	.string "Tes talents sont vraiment\n"
	.string "remarquables.\p"
	.string "Je suis impressionné.\p"
	.string "Mais il y a toujours à apprendre\n"
	.string "l'un de l'autre.\p"
	.string "Moi, PETER—le Dresseur de l'hiver—\p"
	.string "j'ai encore quelques tours en réserve.\p"
	.string "Veux-tu refaire un combat contre moi ?$"

SaffronCity_FightingDojoVIP_Text_Pryce_RematchDefeat:
	.string "Ah, encore une fois je suis\n"
	.string "impressionné par ta force.\p"
	.string "Avec ta volonté, je sais que tu\n"
	.string "surmonteras tous les obstacles\l"
	.string "de la vie.$"

SaffronCity_FightingDojoVIP_Text_Clair_Rematch:
	.string "Tu l'as fait, hein ?\p"
	.string "Tu es maintenant le CHAMPION de JOHTO.\p"
	.string "Tu as prouvé ta force mais\n"
	.string "peux-tu encore me battre ?\p"
	.string "En tant que Maître des Dragons, je ne retiendrai\n"
	.string "pas mes coups.\p"
	.string "Pas cette fois.\p"
	.string "Veux-tu refaire un combat contre moi ?$"

SaffronCity_FightingDojoVIP_Text_Clair_RematchDefeat:
	.string "J'ai perdu ?\p"
	.string "Encore ?\p"
	.string "Je n'y crois pas. Il doit y avoir\n"
	.string "une erreur…$"

SaffronCity_FightingDojoVIP_Text_Brock_Rematch:
	.string "PIERRE : Salut, {PLAYER} !\p"
	.string "J'ai entendu dire que tu es\n"
	.string "le CHAMPION de KANTO.\p"
	.string "C'est incroyable !\p"
	.string "Tu dois être encore plus fort maintenant.\p"
	.string "Veux-tu refaire un combat contre moi ?$"

SaffronCity_FightingDojoVIP_Text_Brock_RematchDefeat:
	.string "PIERRE : Tes POKéMON ont encore\n"
	.string "surmonté ma défense de fer…$"

SaffronCity_FightingDojoVIP_Text_Misty_Rematch:
	.string "ONDINE : Ouah, tu es maintenant\n"
	.string "le CHAMPION de KANTO !\p"
	.string "C'est génial ! Tu as fait beaucoup\n"
	.string "de chemin, {PLAYER}.\p"
	.string "Mais je ne vais pas abandonner.\p"
	.string "Veux-tu refaire un combat contre moi ?$"

SaffronCity_FightingDojoVIP_Text_Misty_RematchDefeat:
	.string "ONDINE : Tu es vraiment fort…$"

SaffronCity_FightingDojoVIP_Text_Surge_Rematch:
	.string "MAJOR BOB : Alors, tu es maintenant\n"
	.string "le CHAMPION de KANTO !\p"
	.string "Beau travail, gamin ! Mais ne crois\n"
	.string "pas que j'en ai fini !\p"
	.string "On se refait un combat ?$"

SaffronCity_FightingDojoVIP_Text_Surge_RematchDefeat:
	.string "MAJOR BOB : Arrrgh ! Tu es toujours\n"
	.string "aussi fort !$"

SaffronCity_FightingDojoVIP_Text_Erika_Rematch:
	.string "Érika : Oh, bonjour.\p"
	.string "Quelle surprise, CHAMPION !\p"
	.string "C'est si agréable de te revoir.\p"
	.string "Ton voyage a dû être passionnant.\p"
	.string "Même les champions aiment un défi.\p"
	.string "Veux-tu refaire un combat contre moi ?$"

SaffronCity_FightingDojoVIP_Text_Erika_RematchDefeat:
	.string "Érika : Perdre laisse toujours un\n"
	.string "goût amer…\p"
	.string "Mais savoir qu'il y a des Dresseurs\n"
	.string "forts me motive à m'améliorer…$"

SaffronCity_FightingDojoVIP_Text_Sabrina_Rematch:
	.string "MORGANE : Ah, le CHAMPION.\p"
	.string "J'ai senti ton retour.\p"
	.string "Ta puissance a énormément grandi.\p"
	.string "Je ressens ton aura même maintenant.\p"
	.string "Veux-tu refaire un combat contre moi ?$"

SaffronCity_FightingDojoVIP_Text_Sabrina_RematchDefeat:
	.string "MORGANE : Ton amour pour tes\n"
	.string "POKéMON a encore surpassé ma\l"
	.string "puissance psychique…$"

SaffronCity_FightingDojoVIP_Text_Janine_Rematch:
	.string "Fufufufu…\p"
	.string "Ouah, tu l'as fait !\p"
	.string "Tu es maintenant le CHAMPION !\p"
	.string "Je suis si fière de toi ! Mais ne crois\n"
	.string "pas que je vais te ménager.\p"
	.string "Veux-tu refaire un combat contre moi ?$"

SaffronCity_FightingDojoVIP_Text_Janine_RematchDefeat:
	.string "Ariane : Tu es toujours aussi\n"
	.string "fort !\p"
	.string "Tu as vraiment gagné…$"

SaffronCity_FightingDojoVIP_Text_Blaine_Rematch:
	.string "AUGUSTE : Ouh là !\p"
	.string "Je vois que tu es devenu le\n"
	.string "CHAMPION de KANTO !\p"
	.string "C'est brûlant !\p"
	.string "Tes talents sont de haut niveau.\p"
	.string "Je suis toujours partant pour un combat.\p"
	.string "Veux-tu refaire un combat contre moi ?$"

SaffronCity_FightingDojoVIP_Text_Blaine_RematchDefeat:
	.string "AUGUSTE : Tes talents sont vraiment\n"
	.string "incandescents !\p"
	.string "Tu as brûlé mes défenses.$"

SaffronCity_FightingDojoVIP_Text_Blue_Rematch:
	.string "BLUE : Eh bien, CHAMPION !\p"
	.string "On dirait que tu as fait du chemin.\p"
	.string "J'ai eu ce titre aussi, tu sais.\n"
	.string "Mais je ne vais pas te ménager.\p"
	.string "Voyons si tu peux continuer comme ça.\p"
	.string "Veux-tu refaire un combat contre moi ?$"

SaffronCity_FightingDojoVIP_Text_Blue_RematchDefeat:
	.string "BLUE : Quoi ?\p"
	.string "Comment ai-je encore pu perdre ?$"
