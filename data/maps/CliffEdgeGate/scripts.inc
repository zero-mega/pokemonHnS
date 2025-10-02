CliffEdgeGate_MapScripts::
	.byte 0

CliffEdgeGate_EventScript_Woman::
	lock
	faceplayer
	msgbox CliffEdgeGate_Text_IntroOpen, MSGBOX_DEFAULT
	closemessage
	release
	end

CliffEdgeGate_EventScript_Picnicker::
	lock
	faceplayer
	msgbox CliffEdgeGate_Text_Expectations, MSGBOX_DEFAULT
	closemessage
	release
	end

CliffEdgeGate_Text_IntroOpen:
	.string "Tu savais ? Il y a une ZONE SAFARI\n"
	.string "juste à côté.\p"
	.string "C'est vraiment amusant !\n"
	.string "Tu verras plein de sortes de POKéMON,\l"
	.string "et tu peux tous les attraper !\p"
	.string "Il n'y a aucune raison de ne pas y aller, non ?\n"
	.string "C'est juste à côté.$"

CliffEdgeGate_Text_Expectations:
	.string "J'apprécie que tout le monde ait hâte\n"
	.string "d'y aller.\p"
	.string "Mais la dame à l'accueil a l'air\n"
	.string "un peu trop enthousiaste...\p"
	.string "Ne t'attends pas à trop !$"

CliffEdgeGate_EventScript_CaveSign::
	lock
	msgbox CliffEdgeGate_Text_SignOpen, MSGBOX_SIGN
	closemessage
	release
	end

CliffEdgeGate_Text_SignOpen:
	.string "Tout est palpitant !\n"
	.string "Explore pour trouver des POKéMON sauvages !\l"
	.string "La ZONE SAFARI du Gardien BAOBA\l"
	.string "est ouverte !$"

