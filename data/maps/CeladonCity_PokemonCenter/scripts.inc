.set LOCALID_NURSE, 1

CeladonCity_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeladonCity_PokemonCenter_OnTransition
	.byte 0

CeladonCity_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_CELADON_CITY
	end

CeladonCity_PokemonCenter_EventScript_CooltrainerF::
	msgbox CeladonCity_PokemonCenter1F_Text_CooltrainerF, MSGBOX_NPC
	end

CeladonCity_PokemonCenter_EventScript_Pharmacist::
	msgbox CeladonCity_PokemonCenter1F_Text_Pharmacist, MSGBOX_NPC
	end

CeladonCity_PokemonCenter_EventScript_Eusine::
	msgbox Celadon_Text_Eusine1, MSGBOX_NPC
	end

CeladonCity_PokemonCenter1F_Text_CooltrainerF:
	.string "ERIKA est une maîtresse des\n"
	.string "POKéMON de type Plante.\p"
	.string "Elle te fera payer si tu ne fais\n"
	.string "pas attention.$"

CeladonCity_PokemonCenter1F_Text_Pharmacist:
	.string "La planque de la TEAM ROCKET est\n"
	.string "au sous-sol du CASINO.\p"
	.string "Oh, attends. C'était il y a trois\n"
	.string "ans.$"

Celadon_Text_Eusine1:
	.string "EUSINE : Salut !\p"
	.string "Je suis de retour dans ma ville\n"
	.string "natale.\p"
	.string "Ça fait un bon moment.$"

Celadon_Text_EusineLeaves:
	.string "{PLAYER}, tu as entendu ?\p"
	.string "Il y a de nouvelles rumeurs sur\n"
	.string "un POKéMON aux couleurs de l'arc-\n"
	.string "en-ciel au TOUR CENDRÉE.\p"
	.string "Je viens de soigner mon équipe,\n"
	.string "je pars donc pour IRISIA.\p"
	.string "À bientôt, {PLAYER} !$"

Celadon_Text_NoBeasts:
	.string "Au fait, {PLAYER}.\p"
	.string "As-tu attrapé les légendaires\n"
	.string "POKéMON RAIKOU et ENTEI ?\p"
	.string "<……><……><……>\p"
	.string "D'accord…\p"
	.string "Si tu en attrapes au moins un,\n"
	.string "j'espère que tu me le diras.\p"
	.string "Je compte sur toi, {PLAYER} !$"
