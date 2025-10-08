SeafoamIslands_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SeafoamIslands_Gym_OnTransition
	.byte 0

SeafoamIslands_Gym_OnTransition: 
	setflag FLAG_TEMP_1
	end

SeafoamIslands_Gym_EventScript_Blaine::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_CINNABAR_ISLAND_GYM, SeafoamIslands_Gym_EventScript_Blaine_Defeated
	msgbox SeafoamIslands_Gym_Text_BlaineIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_BLAINE, SeafoamIslands_Gym_Text_BlaineWinLoss
	message SeafoamIslands_Gym_Text_ReceivedVolcanoBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox SeafoamIslands_Gym_Text_TM, MSGBOX_DEFAULT
	giveitem ITEM_TM_OVERHEAT
	setflag FLAG_BADGE15_GET
	setflag FLAG_DEFEATED_CINNABAR_ISLAND_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 15
	clearflag FLAG_HIDE_SEAFOAM_GYMGUY
	call Common_EventScript_SetGymTrainers
	closemessage
	release
	end

SeafoamIslands_Gym_EventScript_Blaine_Defeated::
	msgbox SeafoamIslands_Gym_Text_BlaineAfterBattle, MSGBOX_DEFAULT
	closemessage
	release
	end

SeafomIslands2_EventScript_GymGuide::
	goto_if_set FLAG_TEMP_2, SeafomIslands2_EventScript_GymGuide2
	msgbox SeafoamIslands_Gym_Text_GymGuideWin, MSGBOX_NPC
	setflag FLAG_TEMP_2
	end
SeafomIslands2_EventScript_GymGuide2::
	msgbox SeafoamIslands_Gym_Text_GymGuideWin2, MSGBOX_NPC
	end

SeafoamIslands_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE15_GET, SeafoamIslands_Gym_EventScript_GymStatuePostVictory
	msgbox SeafoamIslands_Gym_Text_GymStatue
	releaseall
	end

SeafoamIslands_Gym_EventScript_GymStatuePostVictory::
	msgbox SeafoamIslands_Gym_Text_GymStatuePlayerWon
	releaseall
	end

SeafoamIslands_Gym_Text_GymStatue::
    .string "ARÈNE POKéMON DE CRAMOIS'ÎLE\n"
    .string "CHAMPION : AUGUSTE\p"
	.string "DRESSEURS VICTORIEUX :\n"
	.string "BLUE, RED$"

SeafoamIslands_Gym_Text_GymStatuePlayerWon::
    .string "ARÈNE POKéMON DE CRAMOIS'ÎLE\n"
    .string "CHAMPION : AUGUSTE\p"
    .string "DRESSEURS VICTORIEUX :\n"
	.string "BLUE, RED, {PLAYER}$"

SeafoamIslands_Gym_Text_TM:
	.string "Prends ceci aussi. Cette CT contient\n"
	.string "la puissante SURCHAUFFE.\p"
	.string "J'espère que ton prochain adversaire\n"
	.string "aura une GUÉRISON FEU en plus ! Waaah !$"

SeafoamIslands_Gym_Text_BlaineIntro:
	.string "AUGUSTE : Waaah !\p"
	.string "Mon ARÈNE à CRAMOIS'ÎLE a brûlé.\p"
	.string "Mes POKéMON cracheurs de feu et moi\n"
	.string "sommes sans abri à cause du volcan.\p"
	.string "Waaah !\p"
	.string "Mais je reprends du service comme\n"
	.string "CHAMPION ici, dans cette grotte.\p"
	.string "Si tu me bats, je te donnerai\n"
	.string "un BADGE.\p"
	.string "Ha ! Tu ferais mieux d'avoir une GUÉRISON FEU !$"

SeafoamIslands_Gym_Text_BlaineWinLoss:
	.string "AUGUSTE : Incroyable. Je suis à sec…\p"
	.string "Tu as gagné le BADGE VOLCAN !$"

SeafoamIslands_Gym_Text_ReceivedVolcanoBadge:
	.string "{PLAYER} reçoit le BADGE VOLCAN.$"

SeafoamIslands_Gym_Text_BlaineAfterBattle:
	.string "AUGUSTE : J'ai perdu cette fois, mais\n"
	.string "je gagnerai la prochaine.\p"
	.string "Quand je reconstruirai mon ARÈNE DE\n"
	.string "CRAMOIS'ÎLE, on fera une revanche.$"

SeafoamIslands_Gym_Text_BlaineFightDone:
	.string "AUGUSTE : Mes POKéMON de feu seront\n"
	.string "encore plus forts.\p"
	.string "Tu verras !$"

SeafoamIslands_Gym_Text_BlaineRematch:
	.string "AUGUSTE : Oh !\p"
	.string "Je vois que tu es devenu le\n"
	.string "CHAMPION DE KANTO !\p"
	.string "C'est brûlant !\p"
	.string "Tes talents sont remarquables.\p"
	.string "Je suis toujours prêt pour un combat.\p"
	.string "Veux-tu une revanche contre moi ?$"

SeafoamIslands_Gym_Text_BlaineRematchDefeat:
	.string "AUGUSTE : Tes talents sont vraiment brûlants !\p"
	.string "Tu as percé mes défenses !$"

SeafoamIslands_Gym_Text_GymGuideWin:
	.string "Yo !\p"
	.string "… Hein ? C'est déjà fini ?\p"
	.string "Désolé, désolé !\p"
	.string "L'ARÈNE DE CRAMOIS'ÎLE avait disparu, alors\n"
	.string "je ne savais pas où te trouver.\p"
	.string "Mais, hé, tu es assez fort même sans\n"
	.string "mes conseils. Je savais que tu gagnerais !$"

SeafoamIslands_Gym_Text_GymGuideWin2:
	.string "Une ARÈNE POKéMON peut être n'importe où\n"
	.string "tant que le CHAMPION est là.\p"
	.string "Pas besoin de bâtiment.$"
