.set LOCALID_SSAQUA_SLEEPYSAILOR, 1

SSAqua_RoomNW_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, SSAqua_RoomNW_OnTransition
	.byte 0

SSAqua_RoomNW_OnTransition::
    goto_if_ge VAR_SSAQUA_STATE, 3, SSAqua_RoomNW_SetTrainerPos
    end

SSAqua_RoomNW_SetTrainerPos::
    setobjectxyperm 2, 2, 6
    setobjectxyperm 3, 4, 3
    end

SSAqua_RoomNW_EventScript_Stanly::
    lock
    faceplayer
    msgbox SSAqua_RoomNW_Text_SailorStanlySeen, MSGBOX_DEFAULT
    trainerbattle_no_intro TRAINER_STANLY, SSAqua_RoomNW_Text_SailorStanlyBeaten
	msgbox SSAqua_RoomNW_Text_SailorStanlyAfterBattle, MSGBOX_DEFAULT
    closemessage
    fadescreenswapbuffers FADE_TO_BLACK
    delay 60
    playse SE_DOOR
    removeobject LOCALID_SSAQUA_SLEEPYSAILOR
    fadescreenswapbuffers FADE_FROM_BLACK
    setvar VAR_SSAQUA_STATE, 3
	end

SSAqua_RoomNW_EventScript_Edward::
    trainerbattle_single TRAINER_EDWARD SSAqua_RoomNW_Text_GentlemanEdwardSeen, SSAqua_RoomNW_Text_GentlemanEdwardBeaten
	msgbox SSAqua_RoomNW_Text_GentlemanEdwardAfterBattle, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomNW_EventScript_Corey::
    trainerbattle_single TRAINER_COREY SSAqua_RoomNW_Text_BurglarCoreySeen, SSAqua_RoomNW_Text_BurglarCoreyBeaten
	msgbox SSAqua_RoomNW_Text_BurglarCoreyAfterBattle, MSGBOX_AUTOCLOSE
	end


SSAqua_RoomNW_Text_SailorStanlySeen:
	.string "Oui, je suis bien un marin.\p"
	.string "Je ne faisais pas le paresseux !\p"
	.string "Cette cabine était libre, alors\n"
	.string "j'ai juste fait une petite sieste !\p"
	.string "Bon, laisse tomber ! Combattons !$"

SSAqua_RoomNW_Text_SailorStanlyBeaten:
	.string "Désolé ! Tout est de ma faute !$"

SSAqua_RoomNW_Text_SailorStanlyAfterBattle:
	.string "Être marin, c'est faire du\n"
	.string "travail physique. C'est épuisant !$"

SSAqua_RoomNW_Text_GentlemanEdwardSeen:
	.string "Oh non. J'ai perdu quelque chose\n"
	.string "de très important.$"

SSAqua_RoomNW_Text_GentlemanEdwardBeaten:
	.string "Je... Je n'arrive pas à le retrouver...$"

SSAqua_RoomNW_Text_GentlemanEdwardAfterBattle:
	.string "J'abandonne. Tu n'as pas besoin de\n"
	.string "chercher.\p"
	.string "Oublie ça !$"

SSAqua_RoomNW_Text_BurglarCoreySeen:
	.string "Youpi ! Quelle chance !$"

SSAqua_RoomNW_Text_BurglarCoreyBeaten:
	.string "Pas de chance ! J'ai perdu !$"

SSAqua_RoomNW_Text_BurglarCoreyAfterBattle:
	.string "J'ai trouvé une jolie pièce ici.\p"
	.string "Quelqu'un a dû la perdre...$"
