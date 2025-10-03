GoldenrodCity_UndergroundStorage_MapScripts::
	.byte 0

GoldenrodCity_UndergroundStorage_EventScript_Director::
    lock
    faceplayer
    checkitem ITEM_CARD_KEY
    goto_if_eq VAR_RESULT, TRUE, GoldenrodCity_UndergroundStorage_EventScript_Director2
    msgbox RadioTowerBasement_Text_DirectorIntro, MSGBOX_DEFAULT
    closemessage
    giveitem ITEM_CARD_KEY
    msgbox RadioTowerBasement_Text_DirectorCardKey, MSGBOX_DEFAULT
    closemessage
    release
    end

GoldenrodCity_UndergroundStorage_EventScript_Director2::
    msgbox RadioTowerBasement_Text_DirectorAfter, MSGBOX_DEFAULT
    closemessage
    release
    end

GoldenrodCity_UndergroundStorage_EventScript_Grunt19::
    trainerbattle_single TRAINER_GRUNT_19, RadioTowerBasement_Text_GruntM24Seen, RadioTowerBasement_Text_GruntM24Beaten
	msgbox RadioTowerBasement_Text_GruntM24After, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_UndergroundStorage_EventScript_Grunt12::
    trainerbattle_single TRAINER_GRUNT_12, RadioTowerBasement_Text_GruntM14Seen, RadioTowerBasement_Text_GruntM14Beaten
	msgbox RadioTowerBasement_Text_GruntM14After, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_UndergroundStorage_EventScript_Eto::
    trainerbattle_single TRAINER_ETO_3, RadioTowerBasement_Text_GruntM15Seen, RadioTowerBasement_Text_GruntM15Beaten
	msgbox RadioTowerBasement_Text_GruntM15After, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_UndergroundStorage_EventScript_Item_TM_CALM_MIND::
    finditem ITEM_TM_CALM_MIND
    end

GoldenrodCity_UndergroundStorage_EventScript_Item_UltraBall::
    finditem ITEM_ULTRA_BALL
    end

GoldenrodCity_UndergroundStorage_EventScript_Item_MaxEther::
    finditem ITEM_MAX_ETHER
    end

RadioTowerBasement_Text_GruntM24Seen:
    .string "Comment as-tu pu arriver jusqu'ici ?\p"
    .string "Je suppose que je n'ai pas le choix.\n"
    .string "Je vais me débarrasser de toi.$"

RadioTowerBasement_Text_GruntM24Beaten:
    .string "C'est moi qui me suis fait jeter…$"

RadioTowerBasement_Text_GruntM24After:
    .string "La TEAM ROCKET continuera, attendant\n"
    .string "le retour de GIOVANNI.\p"
    .string "On fera tout ce qu'il faut.$"

RadioTowerBasement_Text_GruntM14Seen:
    .string "Tu n'iras pas plus loin !\p"
    .string "Je ne montre aucune pitié à mes ennemis,\n"
    .string "même pas aux gamins !$"

RadioTowerBasement_Text_GruntM14Beaten:
    .string "Mince alors !$"

RadioTowerBasement_Text_GruntM14After:
    .string "J'ai perdu…\p"
    .string "Pardonne-moi, GIOVANNI !$"

RadioTowerBasement_Text_GruntM15Seen:
    .string "Hi-hin-hin ! Regarde qui voilà !\p"
    .string "Prêt ? Je suis vraiment fort maintenant !$"

RadioTowerBasement_Text_GruntM15Beaten:
    .string "Hi-hin-hin ! Tu es trop fort !\p"
    .string "Cette histoire de TEAM ROCKET, c'est juste\n"
    .string "un boulot, mais je vois que ça fait du mal aux autres.\p"
    .string "C'est fini, je m'en vais.\p"
    .string "Merci beaucoup. Désolé GIOVANNI !$"

RadioTowerBasement_Text_GruntM15After:
    .string "Hi-hin-hin ! C'était génial !\n"
    .string "Je me souviendrai de toi !$"

RadioTowerBasement_Text_DirectorIntro:
    .string "DIRECTEUR : Qui ? Quoi ? Tu es venu\n"
    .string "me sauver ?\p"
    .string "Merci !\p"
    .string "La TOUR RADIO !\p"
    .string "Que se passe-t-il là-bas ?\p"
    .string "Elle a été prise par la TEAM ROCKET ?\p"
    .string "Tiens. Prends cette CARTE MAGNÉTIQUE.$"

RadioTowerBasement_Text_DirectorCardKey:
    .string "DIRECTEUR : Utilise-la pour ouvrir\n"
    .string "les volets au 3e étage.$"

RadioTowerBasement_Text_DirectorAfter:
    .string "Je t'en supplie, aide-nous.\p"
    .string "On ne sait pas ce qu'ils feront s'ils\n"
    .string "contrôlent l'émetteur.\p"
    .string "Ils pourraient même contrôler les\n"
    .string "POKéMON avec un signal spécial !\p"
    .string "Tu es le seul sur qui je peux compter.\p"
    .string "S'il te plaît, sauve la TOUR RADIO…\p"
    .string "Et tous les POKéMON du pays !$"
