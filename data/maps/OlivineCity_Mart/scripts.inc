OlivineCity_Mart_MapScripts::
	.byte 0

OlivineCity_EventScript_Trainer1::
	lock
	faceplayer
	msgbox OlivineCity_Text_MartCooltrainerF, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_EventScript_Lass::
	lock
	faceplayer
	msgbox OlivineCity_Text_MartLass, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_Text_MartCooltrainerF:
	.string "Est-ce que tes POKéMON savent déjà\n"
	.string "l'attaque pour transporter des gens\l"
	.string "au-dessus de l'eau?$"

OlivineCity_Text_MartLass:
	.string "Mon PAPILUSION vient de mon\n"
	.string "petit ami à l'étranger.\p"
	.string "Il a apporté du COURRIER de sa part.\p"
	.string "Tu veux savoir ce qu'il dit ?\p"
	.string "Voyons voir... Non ! C'est un\n"
	.string "secret !$"
