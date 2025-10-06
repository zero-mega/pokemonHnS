PacifidlogTown_House5_MapScripts::
	.byte 0

PacifidlogTown_House5_EventScript_MirageIslandWatcher::
	lock
	faceplayer
	specialvar VAR_RESULT, IsMirageIslandPresent
	goto_if_eq VAR_RESULT, TRUE, PacifidlogTown_House5_EventScript_MirageIslandPresent
	msgbox PacifidlogTown_House5_Text_CantSeeMirageIslandToday, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House5_EventScript_MirageIslandPresent::
	msgbox PacifidlogTown_House5_Text_CanSeeMirageIslandToday, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House5_EventScript_Gentleman::
	msgbox PacifidlogTown_House5_Text_MirageIslandAppearDependingOnWeather, MSGBOX_NPC
	end

PacifidlogTown_House5_Text_CantSeeMirageIslandToday:
	.string "Je ne peux pas voir l’ÎLE MIRAGE aujourd’hui…$"

PacifidlogTown_House5_Text_CanSeeMirageIslandToday:
	.string "Oh ! Oh là là !\n"
	.string "Je peux voir l’ÎLE MIRAGE aujourd’hui !$"

PacifidlogTown_House5_Text_MirageIslandAppearDependingOnWeather:
	.string "L’ÎLE MIRAGE…\p"
	.string "Elle doit devenir visible et invisible\n"
	.string "selon les conditions météo\l"
	.string "qui font apparaître des mirages.\p"
	.string "Ou est-ce qu’elle apparaît et disparaît\n"
	.string "vraiment ?\p"
	.string ". . .\p"
	.string "Et si c’était un POKéMON qui faisait\n"
	.string "apparaître et\l"
	.string "disparaître l’île ?\p"
	.string "Je suis sûr que c’est un POKéMON MYTHIQUE.$"
