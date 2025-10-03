.set LOCALID_HIDEOUT_GUARD, 5

JaggedPass_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, JaggedPass_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, JaggedPass_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, JaggedPass_OnLoad
	.byte 0

JaggedPass_OnResume:
	callnative SetTimeBasedEncounters
	setstepcallback STEP_CB_ASH
	call_if_eq VAR_JAGGED_PASS_STATE, 0, JaggedPass_EventScript_CheckHasMagmaEmblem
	end

JaggedPass_EventScript_CheckHasMagmaEmblem::
	checkitem ITEM_MAGMA_EMBLEM
	goto_if_eq VAR_RESULT, TRUE, JaggedPass_EventScript_SetReadyToOpenHideout
	return

JaggedPass_EventScript_SetReadyToOpenHideout::
	setvar VAR_JAGGED_PASS_STATE, 1
	return

JaggedPass_OnTransition:
	call_if_eq VAR_JAGGED_PASS_ASH_WEATHER, 1, JaggedPass_EventScript_SetWeatherAsh
	callnative SetTimeBasedEncounters
	end

JaggedPass_EventScript_SetWeatherAsh::
	setweather WEATHER_VOLCANIC_ASH
	doweather
	return

JaggedPass_OnLoad:
	goto_if_le VAR_JAGGED_PASS_STATE, 1, JaggedPass_EventScript_ConcealHideoutEntrance
	end

JaggedPass_EventScript_ConcealHideoutEntrance::
	setmetatile 16, 17, METATILE_Lavaridge_RockWall, TRUE
	setmetatile 16, 18, METATILE_Lavaridge_RockWall, TRUE
	end

JaggedPass_EventScript_OpenMagmaHideout::
	lockall
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	msgbox JaggedPass_Text_BoulderShakingInResponseToEmblem, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, 1   @ vertical pan
	setvar VAR_0x8005, 1   @ horizontal pan
	setvar VAR_0x8006, 16  @ num shakes
	setvar VAR_0x8007, 3   @ shake delay
	special ShakeCamera
	waitstate
	playse SE_EFFECTIVE
	setmetatile 16, 17, METATILE_Lavaridge_CaveEntrance_Top, TRUE
	setmetatile 16, 18, METATILE_Lavaridge_CaveEntrance_Bottom, FALSE
	special DrawWholeMapView
	delay 30
	setvar VAR_JAGGED_PASS_STATE, 2
	waitse
	releaseall
	end

JaggedPass_EventScript_MagmaHideoutGuard::
	lockall
	goto_if_set FLAG_BEAT_MAGMA_GRUNT_JAGGED_PASS, JaggedPass_EventScript_GuardDefeated
	waitse
	playse SE_PIN
	applymovement LOCALID_HIDEOUT_GUARD, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_HIDEOUT_GUARD, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_HIDEOUT_GUARD, Common_Movement_FacePlayer
	waitmovement 0
	msgbox JaggedPass_Text_GruntIntro, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_TERRELL, JaggedPass_Text_GruntDefeat
	setflag FLAG_BEAT_MAGMA_GRUNT_JAGGED_PASS
	applymovement LOCALID_HIDEOUT_GUARD, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

JaggedPass_EventScript_GuardDefeated::
	applymovement LOCALID_HIDEOUT_GUARD, Common_Movement_FacePlayer
	waitmovement 0
	msgbox JaggedPass_Text_GoWhereverYouWant, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_HIDEOUT_GUARD, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

JaggedPass_EventScript_Eric::
	trainerbattle_single TRAINER_ERIC, JaggedPass_Text_EricIntro, JaggedPass_Text_EricDefeat
	msgbox JaggedPass_Text_EricPostBattle, MSGBOX_AUTOCLOSE
	end

JaggedPass_EventScript_Diana::
	trainerbattle_single TRAINER_KAZU, JaggedPass_Text_DianaIntro, JaggedPass_Text_DianaDefeat, JaggedPass_EventScript_RegisterDiana
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, JaggedPass_EventScript_DianaRematch
	msgbox JaggedPass_Text_DianaPostBattle, MSGBOX_DEFAULT
	release
	end

JaggedPass_EventScript_RegisterDiana::
	special PlayerFaceTrainerAfterBattle
	msgbox JaggedPass_Text_DianaRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_KAZU
	release
	end

JaggedPass_EventScript_DianaRematch::
	trainerbattle_rematch TRAINER_KAZU, JaggedPass_Text_DianaRematchIntro, JaggedPass_Text_DianaRematchDefeat
	msgbox JaggedPass_Text_DianaPostRematch, MSGBOX_AUTOCLOSE
	end

JaggedPass_EventScript_Ethan::
	trainerbattle_single TRAINER_NAOKO, JaggedPass_Text_EthanIntro, JaggedPass_Text_EthanDefeat, JaggedPass_EventScript_RegisterEthan
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, JaggedPass_EventScript_EthanRematch
	msgbox JaggedPass_Text_EthanPostBattle, MSGBOX_DEFAULT
	release
	end

JaggedPass_EventScript_RegisterEthan::
	special PlayerFaceTrainerAfterBattle
	msgbox JaggedPass_Text_EthanRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_NAOKO
	release
	end

JaggedPass_EventScript_EthanRematch::
	trainerbattle_rematch TRAINER_NAOKO, JaggedPass_Text_EthanRematchIntro, JaggedPass_Text_EthanRematchDefeat
	msgbox JaggedPass_Text_EthanPostRematch, MSGBOX_AUTOCLOSE
	end

JaggedPass_EventScript_Julio::
	trainerbattle_single TRAINER_JULIO, JaggedPass_Text_JulioIntro, JaggedPass_Text_JulioDefeat
	msgbox JaggedPass_Text_JulioPostBattle, MSGBOX_AUTOCLOSE
	end

JaggedPass_EventScript_Autumn::
	trainerbattle_single TRAINER_COLETTE, JaggedPass_Text_AutumnIntro, JaggedPass_Text_AutumnDefeat
	msgbox JaggedPass_Text_AutumnPostBattle, MSGBOX_AUTOCLOSE
	end

JaggedPass_Text_EricIntro:
	.string "LE PASSAGE ESCARPÉ DU MT. CHIMNEY…\p"
	.string "C'est exactement ce que j'ai toujours voulu\n"
	.string "dans une montagne.\p"
	.string "Ces bosses irrégulières…\n"
	.string "Ça fait vibrer mon âme !$"

JaggedPass_Text_EricDefeat:
	.string "Perdre m'a laissé amer !$"

JaggedPass_Text_EricPostBattle:
	.string "Oui, j'ai perdu au POKéMON…\p"
	.string "Mais, quand il s'agit d'aimer la montagne,\n"
	.string "je te bats !$"

JaggedPass_Text_DianaIntro:
	.string "Cet endroit n'est pas une promenade de santé.\n"
	.string "Ce n'est pas fait pour un pique-nique.$"

JaggedPass_Text_DianaDefeat:
	.string "Ohhh, non !\n"
	.string "Le sol est trop accidenté…$"

JaggedPass_Text_DianaPostBattle:
	.string "Le savais-tu ?\p"
	.string "Certaines personnes montent habilement\n"
	.string "leur vélo sur ce passage affreusement bosselé.$"

JaggedPass_Text_DianaRegister:
	.string "Reviendras-tu un jour dans cette région ?\n"
	.string "Si tu reviens, j'aimerais une revanche.$"

JaggedPass_Text_DianaRematchIntro:
	.string "Les pique-niques sont amusants partout.\n"
	.string "Comme les POKéMON !$"

JaggedPass_Text_DianaRematchDefeat:
	.string "Je n'ai perdu que parce que le sol\n"
	.string "est trop accidenté !$"

JaggedPass_Text_DianaPostRematch:
	.string "Je vais oublier ma défaite et simplement\n"
	.string "profiter de cette randonnée bosselée.$"

JaggedPass_Text_EthanIntro:
	.string "LE PASSAGE ESCARPÉ est difficile à marcher.\n"
	.string "C'est un bon endroit pour s'entraîner.$"

JaggedPass_Text_EthanDefeat:
	.string "Tout était fini alors qu'on essayait encore\n"
	.string "de trouver un bon appui…$"

JaggedPass_Text_EthanPostBattle:
	.string "Si j'avais un VÉLO ACRO, je pourrais\n"
	.string "sauter les rebords.$"

JaggedPass_Text_EthanRegister:
	.string "Quand je serai plus habitué à ces bosses,\n"
	.string "je gagnerai, c'est sûr !\p"
	.string "Peux-tu m'enregistrer dans ton POKéNAV ?$"

JaggedPass_Text_EthanRematchIntro:
	.string "Je me suis habitué à ces bosses.\n"
	.string "Je chante en grimpant maintenant.$"

JaggedPass_Text_EthanRematchDefeat:
	.string "Ce n'est toujours pas facile de combattre\n"
	.string "sur ce sol accidenté…$"

JaggedPass_Text_EthanPostRematch:
	.string "Je devrais acheter un VÉLO ACRO chez RYDEL\n"
	.string "à LAVANDIA…$"

JaggedPass_Text_GruntIntro:
	.string "Wah !\n"
	.string "Que fais-tu ici ?\p"
	.string "Que fais-je dans un endroit pareil ?\p"
	.string "En quoi ça te regarde ?$"

JaggedPass_Text_GruntDefeat:
	.string "Urrrgh…\p"
	.string "J'aurais dû me cacher dans notre Q.G.\n"
	.string "tout de suite…$"

JaggedPass_Text_GoWhereverYouWant:
	.string "D'accord, d'accooord !\n"
	.string "J'avoue--tu es fort !\p"
	.string "Ne t'inquiète pas pour moi.\n"
	.string "Va où tu veux !$"

JaggedPass_Text_BoulderShakingInResponseToEmblem:
	.string "Oh ! Ce rocher tremble en réponse\n"
	.string "à l'EMBLÈME MAGMA !$"

JaggedPass_Text_JulioIntro:
	.string "Aiyeeh ! C'est vraiment effrayant de dévaler\n"
	.string "la montagne d'un seul coup !$"

JaggedPass_Text_JulioDefeat:
	.string "J'ai l'impression de tomber en morceaux…$"

JaggedPass_Text_JulioPostBattle:
	.string "Mon vélo a tellement rebondi que\n"
	.string "j'ai mal aux fesses…$"

JaggedPass_Text_AutumnIntro:
	.string "Je grimpe cette colline tous les jours.\n"
	.string "J'ai confiance en ma force !$"

JaggedPass_Text_AutumnDefeat:
	.string "Hmm…\n"
	.string "Qu'est-ce qui n'a pas marché ?$"

JaggedPass_Text_AutumnPostBattle:
	.string "C'est quoi cette étrange roche qui dépasse\n"
	.string "un peu plus haut sur la colline ?$"
