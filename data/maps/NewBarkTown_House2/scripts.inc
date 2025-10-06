NewBarkTown_House2_MapScripts::
	.byte 0


NewBarkTown_House2_EventScript_ElmsWife::
	lock
	faceplayer
	msgbox NewBarkTown_House2_Text_ElmsWife, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_House2_EventScript_ElmsSon::
	lock
	faceplayer
	msgbox NewBarkTown_House2_Text_ElmsSon, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_House2_Text_ElmsWife:
	.string "Salut, {PLAYER} ! Mon mari est\n"
	.string "toujours si occupé... J'espère qu'il va bien.\p"
	.string "Quand il est plongé dans ses\n"
	.string "recherches sur les POKéMON, il\l"
	.string "oublie même de manger.$"

NewBarkTown_House2_Text_ElmsSon:
	.string "Quand je serai grand, j'aiderai\n"
	.string "mon papa !\p"
	.string "Je deviendrai un super\n"
	.string "professeur POKéMON !$"
