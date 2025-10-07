Route45_MapScripts::
	.byte 0

Route45_EventScript_Erik::
	trainerbattle_single TRAINER_ERIK Route45_Text_HikerErikSeen, Route45_Text_HikerErikBeaten
	msgbox Route45_Text_HikerErikAfter, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_Michael::
	trainerbattle_single TRAINER_MICHAEL Route45_Text_HikerMichaelSeen, Route45_Text_HikerMichaelBeaten
	msgbox Route45_Text_HikerMichaelAfter, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_Parry::
	trainerbattle_single TRAINER_PARRY Route45_Text_HikerParrySeen, Route45_Text_HikerParryBeaten
	msgbox Route45_Text_HikerParryAfter, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_Timothy::
	trainerbattle_single TRAINER_TIMOTHY Route45_Text_HikerTimothySeen, Route45_Text_HikerTimothyBeaten
	msgbox Route45_Text_HikerTimothyAfter, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_Kenji::
	trainerbattle_single TRAINER_KENJI Route45_Text_BlackbeltKenjiSeen, Route45_Text_BlackbeltKenjiBeaten
	msgbox Route45_Text_BlackbeltKenjiAfter, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_Ryan::
	trainerbattle_single TRAINER_RYAN Route45_Text_CooltrainermRyanSeen, Route45_Text_CooltrainermRyanBeaten
	msgbox Route45_Text_CooltrainermRyanAfter, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_Kelly::
	trainerbattle_single TRAINER_KELLY Route45_Text_CooltrainerfKellySeen, Route45_Text_CooltrainerfKellyBeaten
	msgbox Route45_Text_CooltrainerfKellyAfter, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_Quentin::
	trainerbattle_single TRAINER_QUENTIN Route45_Text_CamperQuentinSeen, Route45_Text_CamperQuentinBeaten
	msgbox Route45_Text_CamperQuentinAfter, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_Sign::
	msgbox Route45_Text_Sign, MSGBOX_SIGN
	end

Route45_EventScript_Item_Elixir::
	finditem ITEM_ELIXIR
	end

Route45_EventScript_Item_Max_Potion::
	finditem ITEM_MAX_POTION
	end

Route45_EventScript_Item_Full_Heal::
	finditem ITEM_FULL_HEAL
	end

Route45_EventScript_Item_Nugget::
	finditem ITEM_NUGGET
	end

Route45_Text_HikerErikSeen:
    .string "Prépare-toi à tout !\p"
    .string "Voyons si tes POKéMON ont été\n"
    .string "bien entraînés !$"

Route45_Text_HikerErikBeaten:
    .string "Oh, j'ai perdu !$"

Route45_Text_HikerErikAfter:
    .string "Je retourne à la GROTTE GLACÉE\n"
    .string "de ÉBÉNÉE pour m'entraîner encore.$"

Route45_Text_HikerMichaelSeen:
    .string "Hé ! Tu as du cran ! Mais tu sais\n"
    .string "quoi ?\p"
    .string "Quand il s'agit de cran pur,\n"
    .string "je suis le meilleur !$"

Route45_Text_HikerMichaelBeaten:
    .string "Mes POKéMON n'avaient pas assez de cran !$"

Route45_Text_HikerMichaelAfter:
    .string "Qu'est-ce que j'aime les PV PLUS ! Mmmm, miam !\p"
    .string "Je bois toujours ceux de mes POKéMON !\p"
    .string "Je n'arrive pas à m'en empêcher !$"

Route45_Text_HikerParrySeen:
    .string "Mes POKéMON sont pleins de puissance !$"

Route45_Text_HikerParryBeaten:
    .string "Wahahah ! Je suis le grand perdant !$"

Route45_Text_HikerParryAfter:
    .string "Je ne suis pas très doué pour réfléchir,\n"
    .string "tu vois ?\p"
    .string "Alors, j'avance juste avec la force !$"

Route45_Text_HikerTimothySeen:
    .string "Pourquoi j'escalade les montagnes ?\p"
    .string "Parce qu'elles sont là.\p"
    .string "Pourquoi j'entraîne des POKéMON ?\p"
    .string "Parce qu'ils sont là !$"

Route45_Text_HikerTimothyBeaten:
    .string "Les défaites... Elles sont là aussi !$"

Route45_Text_HikerTimothyAfter:
    .string "La meilleure chose qui me soit arrivée\n"
    .string "c'est de découvrir les POKéMON.$"

Route45_Text_HikerParryGivesIron:
    .string "Je n'arrive pas à trouver comment gagner !\p"
    .string "Continue comme ça !\p"
    .string "Oh, et prends ça -- c'est le cadeau\n"
    .string "que tu n'as pas pu prendre la dernière\n"
    .string "fois qu'on s'est vus.$"

Route45_Text_BlackbeltKenjiSeen:
    .string "Je m'entraînais ici tout seul.\p"
    .string "Admire les fruits de mon travail !$"

Route45_Text_BlackbeltKenjiBeaten:
    .string "Waaaargh !$"

Route45_Text_BlackbeltKenjiAfter:
    .string "Il faut prendre des mesures extrêmes.\p"
    .string "Je dois partir dans les collines et\n"
    .string "m'entraîner en solitaire.$"

Route45_Text_BlackbeltKenjiMorning:
    .string "Je vais m'entraîner un peu plus\n"
    .string "avant de faire une pause déjeuner.$"

Route45_Text_BlackbeltKenjiNight:
    .string "On s'est bien reposés au déjeuner, alors\p"
    .string "maintenant on est prêts à repartir !\p"
    .string "On va s'entraîner encore !$"

Route45_Text_CooltrainermRyanSeen:
    .string "Que penses-tu de l'élevage\n"
    .string "des POKéMON ?$"

Route45_Text_CooltrainermRyanBeaten:
    .string "Tu as gagné mon respect.$"

Route45_Text_CooltrainermRyanAfter:
    .string "Je vois que tu élèves tes POKéMON\n"
    .string "avec soin.\p"
    .string "Le lien que tu crées te sauvera\n"
    .string "dans les situations difficiles.$"

Route45_Text_CooltrainerfKellySeen:
    .string "Quelle est ta stratégie de combat ?\p"
    .string "C'est idiot d'utiliser des attaques\n"
    .string "puissantes sans réfléchir.$"

Route45_Text_CooltrainerfKellyBeaten:
    .string "D'accord. J'ai perdu.$"

Route45_Text_CooltrainerfKellyAfter:
    .string "Je ne suis pas pour les attaques\n"
    .string "trop puissantes.\p"
    .string "Je veux gagner, mais je ne veux pas\n"
    .string "non plus blesser les POKéMON.$"

Route45_Text_CamperQuentinSeen:
    .string "Je suis vraiment, vraiment fort !$"

Route45_Text_CamperQuentinBeaten:
    .string "J'étais fort à la TOUR DE COMBAT...$"

Route45_Text_CamperQuentinAfter:
    .string "As-tu déjà été à la TOUR DE COMBAT ?\p"
    .string "Je ne perds jamais là-bas, mais...$"

Route45_Text_Sign:
    .string "ROUTE 45\n"
    .string "ROUTE DE MONTAGNE EN AVANT$"
