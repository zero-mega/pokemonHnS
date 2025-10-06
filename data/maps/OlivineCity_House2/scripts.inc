OlivineCity_House2_MapScripts::
	.byte 0

OlivineCity_EventScript_Punisher::
	lock
	faceplayer
	msgbox OlivineCity_Text_PunishmentBro, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_EventScript_PunisherBoy::
	lock
	faceplayer
	msgbox OlivineCity_Text_PunishmentBoy, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_Text_PunishmentBro:
	.string "Sur le chemin de IRISIA,\n"
	.string "il y a quatre îles désertes.\p"
	.string "Les enfants méchants sont emmenés\n"
	.string "sur ces îles comme punition !$"

OlivineCity_Text_PunishmentBoy:
	.string "Quand je fais une bêtise,\n"
	.string "mon grand frère me fait toujours peur.$"
