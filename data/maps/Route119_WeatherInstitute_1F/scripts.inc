.set LOCALID_LITTLE_BOY, 5

Route119_WeatherInstitute_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route119_WeatherInstitute_1F_OnTransition
	.byte 0

Route119_WeatherInstitute_1F_OnTransition:
	call_if_eq VAR_WEATHER_INSTITUTE_STATE, 0, Route119_WeatherInstitute_1F_EventScript_SetLittleBoyPos
	end

Route119_WeatherInstitute_1F_EventScript_SetLittleBoyPos::
	setobjectxyperm LOCALID_LITTLE_BOY, 0, 5
	setobjectmovementtype LOCALID_LITTLE_BOY, MOVEMENT_TYPE_FACE_RIGHT
	return

Route119_WeatherInstitute_1F_EventScript_LittleBoy::
	lock
	faceplayer
	special GetPlayerBigGuyGirlString
	goto_if_eq VAR_WEATHER_INSTITUTE_STATE, 0, Route119_WeatherInstitute_1F_EventScript_LittleBoyTeamAquaHere
	msgbox Route119_WeatherInstitute_1F_Text_WowYoureStrong, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_LittleBoyTeamAquaHere::
	msgbox Route119_WeatherInstitute_1F_Text_EveryoneWentUpstairs, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_InstituteWorker1::
	lock
	faceplayer
	goto_if_unset FLAG_SYS_GAME_CLEAR, Route119_WeatherInstitute_1F_EventScript_StudyingRain
	setvar VAR_0x8004, 0
	call_if_set FLAG_DEFEATED_KYOGRE, Route119_WeatherInstitute_1F_EventScript_LegendaryDefeated
	call_if_set FLAG_DEFEATED_GROUDON, Route119_WeatherInstitute_1F_EventScript_LegendaryDefeated
	goto_if_eq VAR_0x8004, 2, Route119_WeatherInstitute_1F_EventScript_StudyingRain  @ Both defeated
	msgbox Route119_WeatherInstitute_1F_Text_NoticingAbnormalWeather, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_LegendaryDefeated::
	addvar VAR_0x8004, 1
	return

Route119_WeatherInstitute_1F_EventScript_StudyingRain::
	msgbox Route119_WeatherInstitute_1F_Text_ProfStudyingRain, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_InstituteWorker2::
	msgbox Route119_WeatherInstitute_1F_Text_WhatWereAquasUpTo, MSGBOX_NPC
	end

Route119_WeatherInstitute_1F_EventScript_Bed::
	specialvar VAR_RESULT, IsPokecenterChallengeActivated
	goto_if_eq VAR_RESULT, TRUE, Route119_WeatherInstitute_1F_EventScript_Bed_PokecenterChallenge
	lockall
	msgbox Route119_WeatherInstitute_1F_Text_TakeRestInBed, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	releaseall
	end

Route119_WeatherInstitute_1F_EventScript_Bed_PokecenterChallenge::
	msgbox Route119_WeatherInstitute_1F_Text_TakeRestInBed_PokecenterChallenge, MSGBOX_DEFAULT
	closemessage
	end

Route119_WeatherInstitute_1F_EventScript_Grunt1::
	trainerbattle_single TRAINER_ZEKE, Route119_WeatherInstitute_1F_Text_Grunt1Intro, Route119_WeatherInstitute_1F_Text_Grunt1Defeat
	msgbox Route119_WeatherInstitute_1F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_1F_EventScript_Grunt4::
	trainerbattle_single TRAINER_FALKNER_2, Route119_WeatherInstitute_1F_Text_Grunt4Intro, Route119_WeatherInstitute_1F_Text_Grunt4Defeat
	msgbox Route119_WeatherInstitute_1F_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_1F_Text_Grunt1Intro:
	.string "Le BOSS s'est intéressé à\n"
	.string "la recherche qu'ils font ici,\l"
	.string "alors il nous a envoyés.\p"
	.string "Arrête de te mêler de ça !$"

Route119_WeatherInstitute_1F_Text_Grunt1Defeat:
	.string "Zut alors…\n"
	.string "Battue par un gamin…$"

Route119_WeatherInstitute_1F_Text_Grunt1PostBattle:
	.string "Notre BOSS sait tout.\p"
	.string "Mais je ne suis qu'un SBIRE. Qu'est-ce que\n"
	.string "je saurais de ce qu'il pense ?$"

Route119_WeatherInstitute_1F_Text_Grunt4Intro:
	.string "Hein ?\n"
	.string "Qu'est-ce qu'un enfant fait ici ?$"

Route119_WeatherInstitute_1F_Text_Grunt4Defeat:
	.string "Hein ?\n"
	.string "J'ai perdu ?!$"

Route119_WeatherInstitute_1F_Text_Grunt4PostBattle:
	.string "Oh, non…\n"
	.string "Je vais me faire gronder pour avoir perdu contre un enfant…\p"
	.string "Je devrais juste faire une sieste dans le lit…$"

Route119_WeatherInstitute_1F_Text_EveryoneWentUpstairs:
	.string "Pendant que je dormais, tout le monde est\n"
	.string "monté à l'étage !$"

Route119_WeatherInstitute_1F_Text_WowYoureStrong:
	.string "Waouh, tu es vraiment fort !\p"
	.string "J'aimerais être un DRESSEUR de POKéMON\n"
	.string "comme toi !$"

Route119_WeatherInstitute_1F_Text_ProfStudyingRain:
	.string "Le PROFESSEUR adore la pluie.\n"
	.string "C'est un fait.\p"
	.string "Mais s'il continue de pleuvoir, les gens auront\n"
	.string "des problèmes. C'est aussi un fait.\p"
	.string "C'est pourquoi le PROFESSEUR étudie\n"
	.string "si la pluie peut être utilisée à bon escient.$"

Route119_WeatherInstitute_1F_Text_NoticingAbnormalWeather:
	.string "Au 2ème étage de l'INSTITUT,\n"
	.string "nous étudions les schémas météorologiques\l"
	.string "de la région de HOENN.\p"
	.string "Nous avons remarqué des cas temporaires et\n"
	.string "isolés de sécheresse et de fortes pluies\l"
	.string "ces derniers temps…$"

Route119_WeatherInstitute_1F_Text_WhatWereAquasUpTo:
	.string "Bonjour !\n"
	.string "Nous avons été sauvés grâce à toi !\p"
	.string "Ce que je ne comprends pas, c'est ce que\n"
	.string "les AQUAS voulaient faire ici.$"

Route119_WeatherInstitute_1F_Text_TakeRestInBed:
	.string "Il y a un lit…\n"
	.string "Allons nous reposer.$"

Route119_WeatherInstitute_1F_Text_TakeRestInBed_PokecenterChallenge:
	.string "Désolé, tu joues avec\n"
	.string "le défi du CENTRE POKéMON !$"
