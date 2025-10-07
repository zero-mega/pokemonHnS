Route3_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route3_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route3_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route3_EventScript_Otis::
	trainerbattle_single TRAINER_OTIS, Route3_Text_FirebreatherOtis_Seen, Route3_Text_FirebreatherOtis_Beaten
	msgbox Route3_Text_FirebreatherOtis_AfterBattle, MSGBOX_AUTOCLOSE
	end

Route3_EventScript_Warren::
	trainerbattle_single TRAINER_WARREN, Route3_Text_YoungsterWarren_Seen, Route3_Text_YoungsterWarren_Beaten
	msgbox Route3_Text_YoungsterWarren_AfterBattle, MSGBOX_AUTOCLOSE
	end

Route3_EventScript_Jimmy::
	trainerbattle_single TRAINER_JIMMY, Route3_Text_YoungsterJimmy_Seen, Route3_Text_YoungsterJimmy_Beaten
	msgbox Route3_Text_YoungsterJimmy_AfterBattle, MSGBOX_AUTOCLOSE
	end

Route3_EventScript_Burt::
	trainerbattle_single TRAINER_BURT, Route3_Text_FirebreatherBurt_Seen, Route3_Text_FirebreatherBurt_Beaten
	msgbox Route3_Text_FirebreatherBurt_AfterBattle, MSGBOX_AUTOCLOSE
	end

Route3_EventScript_Sign::
	msgbox Route3_Text_MtMoonSquareSign, MSGBOX_SIGN
	end

Route3_Text_FirebreatherOtis_Seen:
	.string "Ah ! Le temps est aussi beau que d'habitude.$"

Route3_Text_FirebreatherOtis_Beaten:
	.string "Il fait soleil, mais je suis tout mouillé…$"

Route3_Text_FirebreatherOtis_AfterBattle:
	.string "Quand il pleut, c'est difficile\nde faire une étincelle…$"

Route3_Text_YoungsterWarren_Seen:
	.string "Hmmm… Je ne sais pas quoi faire…$"

Route3_Text_YoungsterWarren_Beaten:
	.string "Je savais que j'allais perdre…$"

Route3_Text_YoungsterWarren_AfterBattle:
	.string "Tu avais l'air fort.\p"
	.string "J'avais peur de t'affronter…$"

Route3_Text_YoungsterJimmy_Seen:
	.string "Je peux courir comme le vent !$"

Route3_Text_YoungsterJimmy_Beaten:
	.string "Emporté par le vent !$"

Route3_Text_YoungsterJimmy_AfterBattle:
	.string "Je porte des shorts toute l'année.\p"
	.string "C'est ma politique de mode.$"

Route3_Text_FirebreatherBurt_Seen:
	.string "Approchez et regardez !$"

Route3_Text_FirebreatherBurt_Beaten:
	.string "Aïe ! Ça brûle !$"

Route3_Text_FirebreatherBurt_AfterBattle:
	.string "Le plus grand cracheur de feu de KANTO,\nc'est moi.\p"
	.string "Mais pas le meilleur dresseur…$"

Route3_Text_MtMoonSquareSign:
	.string "PLACE MT.MOON\p"
	.string "Montez simplement les escaliers.$"
