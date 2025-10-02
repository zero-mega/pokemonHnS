GoldenrodCity_UndergroundEntrance_MapScripts::
	.byte 0


GoldenrodUnderground_EventScript_SuperNerd::
	lock
	faceplayer
	msgbox GoldenrodUnderground1_Text_SuperNerd, MSGBOX_DEFAULT
	closemessage
	lock
	release
	end

GoldenrodUnderground_EventScript_Teacher::
	lock
	faceplayer
	msgbox GoldenrodUnderground1_Text_Teacher, MSGBOX_DEFAULT
	closemessage
	lock
	release
	end

GoldenrodUnderground1_Text_SuperNerd:
	.string "On m'a défié pour un combat\n"
	.string "en bas.\p"
	.string "C'est dur là-dessous. Tu ferais\n"
	.string "mieux de faire attention.$"


GoldenrodUnderground1_Text_Teacher:
	.string "Il y a quelques boutiques en bas…\n"
	.string "Mais il y a aussi des dresseurs.\p"
	.string "J'ai peur d'y descendre.$"