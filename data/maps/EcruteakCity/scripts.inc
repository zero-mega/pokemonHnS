.set LOCALID_ECRUTEAK_GRAMPS, 4
.set LOCALID_ECRUTEK_SILVER, 33

EcruteakCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EcruteakCity_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

EcruteakCity_OnTransition::
	callnative SetTimeBasedEncounters
	end

EcruteakCity_Test_Lugia::
	setvar VAR_LUGIA_OR_HOOH, 1
	end
EcruteakCity_Test_League::
	setvar VAR_COMPLETED_HO_OH, 4
	setvar VAR_COMPLETED_LUGIA, 4
	end


EcruteakCity_EventScript_Trigger::
	@flagheap
	clearflag FLAG_RELEASED_BEASTS
	clearflag FLAG_AMPHAROS_HEALED
	clearflag FLAG_HIDE_ECRUTEAK_BILL
	clearflag FLAG_DEFEATED_HO_OH
	clearflag FLAG_CAUGHT_HO_OH
	clearflag FLAG_DEFEATED_LUGIA
	clearflag FLAG_CAUGHT_LUGIA
	clearflag FLAG_HIDE_ECRUTEAK_ROCKET
	clearflag FLAG_HIDE_BURNED_TOWER_NPCS  
	clearflag FLAG_HIDE_BURNED_TOWER_BEASTS
	clearflag FLAG_HIDE_BURNED_TOWER_B1F_EUSINE
	clearflag FLAG_HIDE_ECRUTEAK_CITY_SAGE
	clearflag FLAG_CAUGHT_ENTEI
	clearflag FLAG_CAUGHT_RAIKOU
	clearflag FLAG_GOT_TM_SNATCH
	clearflag FLAG_HIDE_ROUTE42_SUICUNE
	clearflag FLAG_GOT_TYROGUE
	clearflag FLAG_BEAT_KIYO
	clearflag FLAG_ENABLE_BAOBA_MATCH_CALL
	clearflag FLAG_HIDE_ECRUTEAK_CITY_THEATER_NPCS
	clearflag FLAG_HIDE_ECRUTEAK_CITY_THEATER_ZUKI
	clearflag FLAG_HIDE_TINTOWER_GUARD
	clearflag FLAG_HIDE_WHIRL_ISLANDS_TENTACRUEL
	clearflag FLAG_HIDE_LUGIA
	clearflag FLAG_HIDE_HO_OH

	setflag FLAG_VISITED_ECRUTEAK_CITY
	setflag FLAG_HIDE_ROUTE42_EUSINE

	setflag FLAG_HIDE_TIN_TOWER_KIMONO_GIRLS
	setflag FLAG_HIDE_WHIRL_ISLANDS_KIMONO_GIRLS
	setflag FLAG_HIDE_ECRUTEAK_CITY_THEATER_KIMONOS
	setflag FLAG_HIDE_ROUTE39_SHADOW
	setflag FLAG_HIDE_ECRUTEAK_SILVER
	setvar VAR_COMPLETED_HO_OH, 0
	setvar VAR_COMPLETED_LUGIA, 0
	setvar VAR_ECRUTEAK_CITY_THEATER, 0 
	setvar VAR_ECRUTEAK_CITY_STATE, 1
	end

EcruteakCity_Trigger_Silver::
	lockall
	opendoor 39, 40
	waitdooranim
	delay 10
	clearflag FLAG_HIDE_ECRUTEAK_SILVER
	addobject LOCALID_ECRUTEK_SILVER
	playbgm MUS_HG_ENCOUNTER_RIVAL, TRUE
	playse SE_BANG
	applymovement LOCALID_ECRUTEK_SILVER, EcruteakCity_Movement_Silver1
	applymovement OBJ_EVENT_ID_PLAYER, EcruteakCity_Movement_Silver1
	message EcruteakCity_Text_Silver1
	
	waitmovement OBJ_EVENT_ID_PLAYER
	waitmovement LOCALID_ECRUTEK_SILVER
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	closedoor 39, 40
	waitdooranim
	msgbox EcruteakCity_Text_Silver2, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_ECRUTEK_SILVER, Common_Movement_ExclamationMark
	delay 60
	turnobject LOCALID_ECRUTEK_SILVER, DIR_SOUTH
	msgbox EcruteakCity_Text_Silver3, MSGBOX_DEFAULT
	closemessage

	applymovement LOCALID_ECRUTEK_SILVER, EcruteakCity_Movement_Silver2
	waitmovement LOCALID_ECRUTEK_SILVER


	setflag FLAG_HIDE_ECRUTEAK_SILVER
	removeobject LOCALID_ECRUTEK_SILVER
	fadedefaultbgm

	setvar VAR_ECRUTEAK_CITY_THEATER, 5
	releaseall
	end

EcruteakCity_Movement_Silver1:
	delay_16
	lock_facing_direction
	walk_down
	unlock_facing_direction
	step_end

EcruteakCity_Movement_Silver2:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

EcruteakCity_Text_Silver1:
	.string "THUD!!$"

EcruteakCity_Text_Silver2:
	.string "SILVER : Comment...? Comment est-ce\n"
	.string "possible ? Comment ai-je pu perdre\l"
	.string "face à de simples DANSEUSES KIMONO...?$"

EcruteakCity_Text_Silver3:
	.string "SILVER : Tu m'observais,\n"
	.string "{PLAYER}...\p"
	.string "Ouais, c'est ça !\p"
	.string "Je n'aurais jamais cru que battre\n"
	.string "cinq DANSEUSES KIMONO serait si dur...\p"
	.string "Je me suis fait écraser...\p"
	.string "...\p"
	.string "Tu es venu ici pour la même raison,\n"
	.string "pas vrai ?\p"
	.string "Ne prends pas la grosse tête juste\n"
	.string "parce que tu as vaincu la TEAM ROCKET !\p"
	.string "Ces DANSEUSES KIMONO sont\n"
	.string "incroyablement fortes.\p"
	.string "Voyons si tu peux les battre.\p"
	.string "Mais je ne reviendrai pas, je ne veux\n"
	.string "pas te voir gagner.$"

EcruteakCity_EventScript_Gramps::
	lock
	faceplayer
	msgbox EcruteakCity_Text_Gramps1, MSGBOX_DEFAULT
	closemessage
	release
	end
		
EcruteakCity_EventScript_Lass::
	lock
	faceplayer
	msgbox EcruteakCity_Text_Lass1, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_RELEASED_BEASTS, EcruteakCity_EventScript_Girl2
	msgbox EcruteakCity_Text_Lass2, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_EventScript_Girl2::
	msgbox EcruteakCity_Text_Lass2_ReleasedBeasts, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_EventScrip_Man::
	lock
	faceplayer
	goto_if_set FLAG_AMPHAROS_HEALED, EcruteakCity_EventScrip_Man2
	msgbox EcruteakCity_Text_Fisher, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_EventScrip_Man2::
	msgbox EcruteakCity_Text_Fisher_JasmineReturned, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_EventScript_Youngster::
	lock
	faceplayer
	msgbox EcruteakCity_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_EventScript_SageRight::
	lock
	faceplayer
	msgbox EcruteakCity_Text_Gramps2, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_EventScript_SageTower::
	lock
	faceplayer
	msgbox EcruteakCity_Text_Gramps3, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_EventScript_SageGym::
	lock
	faceplayer
	msgbox EcruteakCity_Text_SageGym, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_EventScript_TheaterSign::
	lock
	msgbox EcruteakCity_Text_DanceTheaterSign, MSGBOX_SIGN
	closemessage
	release
	end	

EcruteakCity_EventScript_OfficeSign::
	lock
	msgbox EcruteakCity_Text_OfficeSign, MSGBOX_SIGN
	closemessage
	release
	end	

EcruteakCity_EventScript_BurnedSign::
	lock
	msgbox EcruteakCity_Text_BurnedTowerSign, MSGBOX_SIGN
	closemessage
	release
	end	

EcruteakCity_EventScript_CitySign::
	lock
	msgbox EcruteakCity_Text_Sign, MSGBOX_SIGN
	closemessage
	release
	end	

EcruteakCity_EventScript_GymSign::
	lock
	msgbox EcruteakCity_Text_GymSign, MSGBOX_SIGN
	closemessage
	release
	end

EcruteakCity_EventScript_Eevee::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_EEVEE, CRY_MODE_NORMAL
	msgbox EcruteakCity_Text_Eevee, MSGBOX_DEFAULT
	waitmoncry
	release
	end

EcruteakCity_EventScript_Vulpix::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_VULPIX, CRY_MODE_NORMAL
	msgbox EcruteakCity_Text_Vulpix, MSGBOX_DEFAULT
	waitmoncry
	release
	end

EcruteakCity_EventScript_Item_RareCandy::
	finditem ITEM_RARE_CANDY
	end

EcruteakCity_Text_Eevee:
	.string "EEVEE: Veee!$"

EcruteakCity_Text_Vulpix:
	.string "VULPIX: Vullll Pix!$"


EcruteakCity_Text_UnusedMissingDaughter:
	.string "Oh, non. Oh, non…\p"
	.string "Ma fille a disparu.\p"
	.string "Non… Elle n'aurait pas pu aller à la\n"
	.string "TOUR CENDRÉE.\p"
	.string "Je lui ai dit de ne pas s'en approcher…\p"
	.string "Des gens semblent disparaître là-bas…\p"
	.string "Oh, que dois-je faire…?$"

EcruteakCity_Text_Gramps1:
	.string "ECRUTEAK avait autrefois deux tours :\n"
	.string "une à l'est et une à l'ouest.$"

EcruteakCity_Text_Gramps2:
	.string "Ah, enfant. As-tu appris à danser\n"
	.string "comme les KIMONO GIRLS ?\p"
	.string "Si tu vas à leur SALLE DE DANSE,\n"
	.string "un vieil homme étrange te donnera\l"
	.string "quelque chose de sympa, j'ai entendu.$"

EcruteakCity_Text_Lass1:
	.string "Je vais m'entraîner à la SALLE DE\n"
	.string "DANSE. Tu veux venir avec moi ?$"

EcruteakCity_Text_Lass2:
	.string "La tour qui était ici autrefois…\p"
	.string "Ma grand-mère m'a dit qu'elle était\n"
	.string "beaucoup plus haute.\p"
	.string "J'ai entendu dire qu'il y a des\n"
	.string "fantômes dedans maintenant.$"

EcruteakCity_Text_Lass2_ReleasedBeasts:
	.string "Trois grands POKéMON sont partis dans\n"
	.string "des directions différentes. Qui étaient-ils ?$"

EcruteakCity_Text_Fisher:
	.string "J'ai entendu une rumeur sur le PHARE\n"
	.string "d'OLIVILLE.\p"
	.string "Le POKéMON qui sert de balise est\n"
	.string "tombé malade. Il paraît qu'ils\l"
	.string "ont des problèmes.$"

EcruteakCity_Text_Fisher_JasmineReturned:
	.string "Le POKéMON du PHARE d'OLIVILLE\n"
	.string "a été guéri.\p"
	.string "Les bateaux peuvent à nouveau sortir\n"
	.string "en mer la nuit sans danger.$"

EcruteakCity_Text_Youngster:
	.string "J'ai entendu dire que des POKéMON\n"
	.string "sont en furie au LAC COLÈRE. J'aimerais voir ça.$"

EcruteakCity_Text_Gramps3:
	.string "Dans un passé lointain…\p"
	.string "Cette tour a brûlé dans un incendie.\n"
	.string "Trois POKéMON sans nom y ont péri.\p"
	.string "Un POKéMON aux couleurs de l'arc-en-ciel\n"
	.string "est descendu du ciel et les a ressuscités…\p"
	.string "C'est une légende transmise par les\n"
	.string "CHAMPIONS de l'ARÈNE d'ECRUTEAK.\p"
	.string "Moi ?\p"
	.string "J'étais un dresseur il y a bien longtemps.\n"
	.string "Hohoho !$"

EcruteakCity_Text_SageGym:
	.string "Le Champion MORTIMER n'est pas ici\n"
	.string "en ce moment. Tu le trouveras peut-être\l"
	.string "à la TOUR CENDRÉE.$"

EcruteakCity_Text_Sign:
	.string "ECRUTEAK CITY\n"
	.string "Une ville historique\p"
	.string "Où le passé rencontre le présent$"

EcruteakCity_Text_TinTowerSign:
	.string "TOUR FER\p"
	.string "On dit qu'un POKéMON légendaire\n"
	.string "y niche.$"

EcruteakCity_Text_OfficeSign:
	.string "Poste de contrôle vers la TOUR FER\p"
	.string "Interdit aux indignes.$"

EcruteakCity_Text_GymSign:
	.string "ARÈNE POKéMON D'ECRUTEAK CITY\n"
	.string "CHAMPION : MORTIMER\p"
	.string "Le Voyant Mystique du Futur$"

EcruteakCity_Text_DanceTheaterSign:
	.string "SALLE DE DANSE D'ECRUTEAK$"

EcruteakCity_Text_BurnedTowerSign:
	.string "TOUR CENDRÉE\p"
	.string "Elle a été détruite par un mystérieux\n"
	.string "incendie.\p"
	.string "Veuillez rester à l'écart, c'est dangereux.$"
