SootopolisCity_House3_MapScripts::
	.byte 0

SootopolisCity_House3_EventScript_Woman::
	lock
	faceplayer
	msgbox SootopolisCity_House3_Text_JuanHasManyFansDoYou, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SootopolisCity_House3_EventScript_HaveFans
	msgbox SootopolisCity_House3_Text_LonesomeTryWorkingHarder, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House3_EventScript_HaveFans::
	msgbox SootopolisCity_House3_Text_YouMustBePrettyStrong, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House3_EventScript_Girl::
	msgbox SootopolisCity_House3_Text_TrainerFanClubWasWild, MSGBOX_NPC
	end

SootopolisCity_House3_Text_JuanHasManyFansDoYou:
	.string "Tu es un DRESSEUR POKéMON, n'est-ce pas ?\p"
	.string "JUAN de SOOTOPOLIS a beaucoup de fans.\n"
	.string "Même plus que son élève, ALBAN !\p"
	.string "En as-tu toi aussi ?$"

SootopolisCity_House3_Text_YouMustBePrettyStrong:
	.string "Oh, alors tu dois être très fort.$"

SootopolisCity_House3_Text_LonesomeTryWorkingHarder:
	.string "Oh, mince…\n"
	.string "C'est un peu triste.\p"
	.string "Essaie de travailler un peu plus pour\n"
	.string "avoir des admirateurs.$"

SootopolisCity_House3_Text_TrainerFanClubWasWild:
	.string "Des fans dévoués viennent même de\n"
	.string "l'extérieur de HOENN.\p"
	.string "C'était vraiment animé quand je suis allé\n"
	.string "au CLUB DES FANS à NENCRIQUE.$"

