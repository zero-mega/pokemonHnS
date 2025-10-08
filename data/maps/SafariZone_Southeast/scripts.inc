.set LOCALID_MANTYKEMAN, 7

SafariZone_Southeast_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	map_script MAP_SCRIPT_ON_TRANSITION, SetTimeEncounters
	.byte 0

SafariZone_Southeast_GliscorEvo::
	msgbox SafariZone_Southeast_GliscorEvo_Text, MSGBOX_NPC
	end

SafariZone_Southeast_GliscorEvo_Text:
	.string "J'adore les POKéMON de SINNOH !\p"
	.string "Je dois attraper un SCORPLANE, comme ça\n"
	.string "je pourrai avoir un SCORVOL !\p"
	.string "Ils évoluent seulement la nuit,\n"
	.string "comme FARFURET et CORBOSS.$"

SafariZone_Southeast_MantykeEvo::
	msgbox SafariZone_Southeast_MantykeEvo_Text, MSGBOX_SIGN
	waitmessage
	msgbox SafariZone_Southeast_MantykeEvo_Text2, MSGBOX_NPC
	applymovement LOCALID_MANTYKEMAN, SafariZone_Southeast_MantykeEvoMoves
	waitmovement 0
	end

SafariZone_Southeast_MantykeEvoMoves:
	face_right
	step_end

SafariZone_Southeast_MantykeEvo_Text:
	.string "OH!$"

SafariZone_Southeast_MantykeEvo_Text2:
	.string "TU AS VU ÇA ?\p"
	.string "Ce BABIMANTA essayait d'évoluer,\n"
	.string "alors il utilisait VIBRAQUA !\l"
	.string "La nature est magnifique !$"

@ Event scripts for SafariZone_Southeast are in SafariZone_South/scripts.inc
