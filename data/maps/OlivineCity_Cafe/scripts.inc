.set LOCALID_CAFE_JASMINE, 4

OlivineCity_Cafe_MapScripts::
	.byte 0

OlivineCity_Cafe_EventScript_Jasmine::
	lock
	faceplayer
	msgbox OlivineCity_Cafe_Text_Jasmine, MSGBOX_DEFAULT
	closemessage
	fadescreenswapbuffers FADE_TO_BLACK
	setflag FLAG_HIDE_CAFE_JASMINE
	removeobject LOCALID_CAFE_JASMINE
	fadescreenswapbuffers FADE_FROM_BLACK
	clearflag FLAG_HIDE_DOJO_JASMINE
	release
	end

OlivineCity_Cafe_Text_Jasmine:
	.string "Oh... Bonjour, {PLAYER}.\p"
	.string "Ces plats devant moi ne sont\n"
	.string "pas tous à moi...\p"
	.string "Euh...\p"
	.string "En fait, la personne assise ici\n"
	.string "avant moi a beaucoup mangé...\p"
	.string "Si tu veux te battre à nouveau,\n"
	.string "viens me voir au DOJO de\l"
	.string "KARATÉ à SAFRANIA.$"

OlivineCity_EventScript_SailorA::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_STRENGTH, OlivineCity_EventScript_SailorA2
	msgbox OlivineCity_Text_CafeSailorStrength, MSGBOX_DEFAULT
	giveitem ITEM_HM_STRENGTH
	setflag FLAG_RECEIVED_HM_STRENGTH
OlivineCity_EventScript_SailorA2::
	msgbox OlivineCity_Text_CafeSailorGotStrength, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_EventScript_Cook::
	lock
	faceplayer
	msgbox OlivineCity_Text_CafeFishingGuru, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_EventScript_SailorB::
	lock
	faceplayer
	msgbox OlivineCity_Text_CafeSailor, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_Text_CafeSailorStrength:
	.string "Ha ! Tes POKéMON ont vraiment\n"
	.string "l'air de poids plumes !\p"
	.string "Ils n'ont pas la force de\n"
	.string "déplacer des rochers.\p"
	.string "Tiens, utilise ça et apprends-\n"
	.string "leur FORCE !$"

OlivineCity_Text_CafeSailorGotStrength:
	.string "En mer, la seule chose sur\n"
	.string "laquelle tu peux compter, c'est toi !\p"
	.string "Je suis si fier de mon corps musclé !\n"
	.string "Tu devrais t'entraîner comme moi !$"

OlivineCity_Text_CafeFishingGuru:
	.string "Le menu du CAFÉ OLIVINE est rempli\n"
	.string "de plats copieux pour les\l"
	.string "MARINS costauds comme moi !$"

OlivineCity_Text_CafeSailor:
	.string "À chaque fois que j'arrive en ville,\n"
	.string "je passe toujours au CAFÉ OLIVINE.\p"
	.string "Tout ce qu'il y a au menu me rend\n"
	.string "plus fort. Je ne peux pas m'arrêter !$"

