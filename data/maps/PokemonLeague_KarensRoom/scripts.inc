PokemonLeague_KarensRoom_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EliteFourRoom_OnFrame
	map_script MAP_SCRIPT_ON_RESUME, PokemonLeague_KarensRoom_OnResume
	map_script MAP_SCRIPT_ON_LOAD, EliteFourRoom_OnLoad
	.byte 0

PokemonLeague_KarensRoom_OnResume::
	setvar VAR_0x8004, 3
	special DoPokemonLeagueLightingEffect
	end

PokemonLeague_KarensRoom_EventScript_Karen::
	lock 
	faceplayer
	goto_if_ge VAR_LEAGUE_STATE, 5, PokemonLeague_KarensRoom_EventScript_KarenDefeated
	goto_if_set FLAG_IS_CHAMPION, PokemonLeague_KarensRoom_EventScript_KarenRematch
	msgbox PokemonLeague_KarensRoom_Text_Before, MSGBOX_DEFAULT
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	trainerbattle_no_intro TRAINER_KAREN_1, PokemonLeague_KarensRoom_Text_Beaten
	goto PokemonLeague_KarensRoom_EventScript_KarenOnDefeat

PokemonLeague_KarensRoom_EventScript_KarenRematch::
	msgbox PokemonLeague_KarensRoom_Text_RematchBefore, MSGBOX_DEFAULT
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	trainerbattle_no_intro TRAINER_KAREN_2, PokemonLeague_KarensRoom_Text_Beaten
	goto PokemonLeague_KarensRoom_EventScript_KarenOnDefeat

PokemonLeague_KarensRoom_EventScript_KarenOnDefeat::
    clearflag FLAG_TEMP_5
	msgbox PokemonLeague_KarensRoom_Text_Defeat, MSGBOX_DEFAULT
	closemessage
	setmetatile 6, 1, 0x28E, FALSE
	setmetatile 6, 2, 0x296, FALSE	
	playse SE_BANG
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 4  @ num shakes
	setvar VAR_0x8007, 4  @ shake delay
	special ShakeCamera
	waitstate
	special DrawWholeMapView
	setvar VAR_LEAGUE_STATE, 5
	release
	end

PokemonLeague_KarensRoom_EventScript_KarenDefeated::
	msgbox PokemonLeague_KarensRoom_Text_Defeat, MSGBOX_DEFAULT
	closemessage
	release
	end

PokemonLeague_KarensRoom_Text_RematchBefore:
    .string "KAREN : Ah, c'est encore toi.\p"
    .string "J'espère que tu n'as pas oublié\n"
    .string "ma conviction :\p"
    .string "La vraie force naît de la confiance\n"
    .string "en ses POKéMON.\p"
    .string "Depuis notre dernière rencontre, mon\n"
    .string "lien avec mes POKéMON s'est\l"
    .string "encore renforcé.\p"
    .string "Es-tu prêt à affronter une équipe\n"
    .string "unie par un lien incassable ?\p"
    .string "Montre-moi la puissance du lien\n"
    .string "avec tes POKéMON.$"

PokemonLeague_KarensRoom_Text_Before:
    .string "Je suis KAREN du CONSEIL 4.\p"
    .string "Tu es {PLAYER} ? Comme c'est amusant.\p"
    .string "J'adore les POKéMON de type TÉNÈBRES.\p"
    .string "Je trouve leur image sauvage et forte\n"
    .string "très attirante. Et ils sont\l"
    .string "si puissants.\p"
    .string "Tu penses pouvoir les battre ?\n"
    .string "Essaie juste de m'amuser.\p"
    .string "Allons-y.$"

PokemonLeague_KarensRoom_Text_Beaten:
    .string "Eh bien, tu es doué. J'aime ça\n"
    .string "chez un dresseur.$"

PokemonLeague_KarensRoom_Text_Defeat:
    .string "POKéMON forts.\p"
    .string "POKéMON faibles.\p"
    .string "Ce n'est que la perception égoïste\n"
    .string "des gens.\p"
    .string "Les vrais dresseurs devraient\n"
    .string "essayer de gagner avec leurs préférés.\p"
    .string "J'aime ton style. Tu comprends\n"
    .string "ce qui est important.\p"
    .string "Vas-y—le CHAMPION t'attend.$"
