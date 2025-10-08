SootopolisCity_House2_MapScripts::
	.byte 0

SootopolisCity_House2_EventScript_ExpertF::
	lock
	faceplayer
	msgbox SootopolisCity_House2_Text_DidYouKnowAboutMtPyreOrbs, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, SootopolisCity_House2_EventScript_KnowAboutOrbs
	call_if_eq VAR_RESULT, NO, SootopolisCity_House2_EventScript_DontKnowAboutOrbs
	release
	end

SootopolisCity_House2_EventScript_KnowAboutOrbs::
	msgbox SootopolisCity_House2_Text_YesTwoOrbsSideBySide, MSGBOX_DEFAULT
	return

SootopolisCity_House2_EventScript_DontKnowAboutOrbs::
	msgbox SootopolisCity_House2_Text_OughtToVisitAndSee, MSGBOX_DEFAULT
	return

SootopolisCity_House2_Text_DidYouKnowAboutMtPyreOrbs:
	.string "MONT MÉMORIA…\p"
	.string "À son sommet, deux orbes sont posées\n"
	.string "côte à côte. Le saviez-vous?$"

SootopolisCity_House2_Text_YesTwoOrbsSideBySide:
	.string "Oui, deux orbes côte à côte…\p"
	.string "Les voir ensemble…\n"
	.string "C'est d'une certaine façon apaisant…$"

SootopolisCity_House2_Text_OughtToVisitAndSee:
	.string "Ah bon ?\n"
	.string "Peut-être devriez-vous aller voir…$"
