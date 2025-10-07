Route33_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route33_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route33_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route33_EventScript_HikerAnthony::
	trainerbattle_single TRAINER_ANTHONY, Route33_Text_HikerAnthony2Seen, Route33_Text_HikerAnthony2Beaten
	msgbox Route33_Text_HikerAnthony2After, MSGBOX_AUTOCLOSE
	end

Route33_EventScript_Lass::
	lock
	faceplayer
	msgbox Route33_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

Route33_Text_HikerAnthony2Seen:
	.string "Je suis passé par le tunnel,\n"
	.string "mais il me reste encore\l"
	.string "beaucoup d'énergie.$"

Route33_Text_HikerAnthony2Beaten:
	.string "Ouah ! Tu as plus de peps\n"
	.string "que moi !$"

Route33_Text_HikerAnthony2After:
	.string "Nous, les Randonneurs, sommes\n"
	.string "au meilleur de notre forme\n"
	.string "dans les montagnes.$"

Route33_Text_HikerAnthonyDunsparce:
	.string "Hé, tu as eu un DUNSPARCE ?\p"
	.string "J'en ai attrapé un aussi.\p"
	.string "Regarde-le à la lumière.\n"
	.string "Il a une drôle de tête !$"

Route33_Text_Lass:
	.string "Huff, huff…\p"
	.string "Cette grotte était plus grande\n"
	.string "que ce que je pensais.\p"
	.string "Je me suis trop fatiguée à\n"
	.string "chercher un MARILL, alors je\n"
	.string "suis sortie.$"
