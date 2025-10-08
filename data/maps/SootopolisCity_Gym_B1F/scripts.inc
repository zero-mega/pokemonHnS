SootopolisCity_Gym_B1F_MapScripts::
	.byte 0

SootopolisCity_Gym_B1F_EventScript_Andrea::
	trainerbattle_single TRAINER_BRIAN, SootopolisCity_Gym_B1F_Text_AndreaIntro, SootopolisCity_Gym_B1F_Text_AndreaDefeat
	msgbox SootopolisCity_Gym_B1F_Text_AndreaPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Crissy::
	trainerbattle_single TRAINER_HARRY, SootopolisCity_Gym_B1F_Text_CrissyIntro, SootopolisCity_Gym_B1F_Text_CrissyDefeat
	msgbox SootopolisCity_Gym_B1F_Text_CrissyPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Brianna::
	trainerbattle_single TRAINER_ELLEN, SootopolisCity_Gym_B1F_Text_BriannaIntro, SootopolisCity_Gym_B1F_Text_BriannaDefeat
	msgbox SootopolisCity_Gym_B1F_Text_BriannaPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Connie::
	trainerbattle_single TRAINER_CONNIE, SootopolisCity_Gym_B1F_Text_ConnieIntro, SootopolisCity_Gym_B1F_Text_ConnieDefeat
	msgbox SootopolisCity_Gym_B1F_Text_ConniePostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Bridget::
	trainerbattle_single TRAINER_BRIDGET, SootopolisCity_Gym_B1F_Text_BridgetIntro, SootopolisCity_Gym_B1F_Text_BridgetDefeat
	msgbox SootopolisCity_Gym_B1F_Text_BridgetPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Olivia::
	trainerbattle_single TRAINER_OLIVIA, SootopolisCity_Gym_B1F_Text_OliviaIntro, SootopolisCity_Gym_B1F_Text_OliviaDefeat
	msgbox SootopolisCity_Gym_B1F_Text_OliviaPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Tiffany::
	trainerbattle_single TRAINER_TIFFANY, SootopolisCity_Gym_B1F_Text_TiffanyIntro, SootopolisCity_Gym_B1F_Text_TiffanyDefeat
	msgbox SootopolisCity_Gym_B1F_Text_TiffanyPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Bethany::
	trainerbattle_single TRAINER_BETHANY, SootopolisCity_Gym_B1F_Text_BethanyIntro, SootopolisCity_Gym_B1F_Text_BethanyDefeat
	msgbox SootopolisCity_Gym_B1F_Text_BethanyPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Annika::
	trainerbattle_single TRAINER_CARRIE, SootopolisCity_Gym_B1F_Text_AnnikaIntro, SootopolisCity_Gym_B1F_Text_AnnikaDefeat
	msgbox SootopolisCity_Gym_B1F_Text_AnnikaPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Daphne::
	trainerbattle_single TRAINER_JIMMY, SootopolisCity_Gym_B1F_Text_DaphneIntro, SootopolisCity_Gym_B1F_Text_DaphneDefeat
	msgbox SootopolisCity_Gym_B1F_Text_DaphnePostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_Text_AndreaIntro:
	.string "Je vais te montrer les techniques sublimes\n"
	.string "que j'ai apprises de notre CHAMPION JUAN !$"

SootopolisCity_Gym_B1F_Text_AndreaDefeat:
	.string "Pardonne-moi, JUAN…$"

SootopolisCity_Gym_B1F_Text_AndreaPostBattle:
	.string "Regarde ce qui se passe si tu fissures\n"
	.string "toutes les dalles du sol.$"

SootopolisCity_Gym_B1F_Text_CrissyIntro:
	.string "Tu es venu jusqu'ici, mais tu ne verras\n"
	.string "pas JUAN.\p"
	.string "Pas si tu perds contre moi !$"

SootopolisCity_Gym_B1F_Text_CrissyDefeat:
	.string "Tu es fort !\n"
	.string "Je me suis laissée tromper par ton air mignon !$"

SootopolisCity_Gym_B1F_Text_CrissyPostBattle:
	.string "Tu es peut-être assez fort pour éviter\n"
	.string "d'être mis K.O. en un coup par JUAN.$"

SootopolisCity_Gym_B1F_Text_DaphneIntro:
	.string "Voir JUAN diriger un combat…\p"
	.string "La beauté même de cela m'a poussée à\n"
	.string "devenir DRESSEUSE.$"

SootopolisCity_Gym_B1F_Text_DaphneDefeat:
	.string "Tu as combattu avec plus de grâce que\n"
	.string "je n'aurais pu en avoir…$"

SootopolisCity_Gym_B1F_Text_DaphnePostBattle:
	.string "La grâce que tu apportes au combat est\n"
	.string "fabuleuse.\p"
	.string "Oh… J'ai tellement de chance d'avoir\n"
	.string "rencontré des POKéMON.$"

SootopolisCity_Gym_B1F_Text_ConnieIntro:
	.string "Je devrais t'apprendre à quel point les\n"
	.string "combats peuvent être durs.$"

SootopolisCity_Gym_B1F_Text_ConnieDefeat:
	.string "Oh.\n"
	.string "Tu es fort.$"

SootopolisCity_Gym_B1F_Text_ConniePostBattle:
	.string "Je vais te donner un bon conseil.\p"
	.string "Si tu veux atteindre JUAN, tu dois\n"
	.string "marcher sur chaque dalle une fois.$"

SootopolisCity_Gym_B1F_Text_BridgetIntro:
	.string "L'ARÈNE POKéMON la plus prestigieuse\n"
	.string "de la région de HOENN…\p"
	.string "C'est l'ARÈNE de SOOTOPOLIS.$"

SootopolisCity_Gym_B1F_Text_BridgetDefeat:
	.string "Quel niveau impressionnant tu as !$"

SootopolisCity_Gym_B1F_Text_BridgetPostBattle:
	.string "Plutôt que d'être satisfaite d'être dans\n"
	.string "une ARÈNE forte, je pense que s'entraîner\l"
	.string "ailleurs te rendra plus fort.\l"
	.string "Et puis, ça a l'air plus amusant.$"

SootopolisCity_Gym_B1F_Text_OliviaIntro:
	.string "J'entraîne mes POKéMON avec JUAN.\p"
	.string "Ne me sous-estime pas !$"

SootopolisCity_Gym_B1F_Text_OliviaDefeat:
	.string "J'ai perdu…$"

SootopolisCity_Gym_B1F_Text_OliviaPostBattle:
	.string "Je pense que tu as du potentiel.\n"
	.string "Pourquoi ne resterais-tu pas t'entraîner avec nous ?$"

SootopolisCity_Gym_B1F_Text_TiffanyIntro:
	.string "Glisser gracieusement sur la glace sans\n"
	.string "croiser de lignes…\p"
	.string "Un DRESSEUR qui ferait ça serait d'une\n"
	.string "élégance magnifique !$"

SootopolisCity_Gym_B1F_Text_TiffanyDefeat:
	.string "Eh bien, excuse-moi ?!$"

SootopolisCity_Gym_B1F_Text_TiffanyPostBattle:
	.string "C'est évident, mais la force d'un DRESSEUR\n"
	.string "n'a rien à voir avec l'âge.\l"
	.string "Que tu sois jeune ou vieux.$"

SootopolisCity_Gym_B1F_Text_BethanyIntro:
	.string "Quand je suis avec mes POKéMON, le temps\n"
	.string "passe avant même que je dise « Oups ! »$"

SootopolisCity_Gym_B1F_Text_BethanyDefeat:
	.string "Oups !$"

SootopolisCity_Gym_B1F_Text_BethanyPostBattle:
	.string "J'aimerais pouvoir oublier les causes perdues\n"
	.string "avant même de dire « Oups ! »$"

SootopolisCity_Gym_B1F_Text_AnnikaIntro:
	.string "Je peux combattre avec des POKéMON très rares\n"
	.string "si tu veux.$"

SootopolisCity_Gym_B1F_Text_AnnikaDefeat:
	.string "Oh, alors ! Tu as bien regardé\n"
	.string "mes POKéMON ?$"

SootopolisCity_Gym_B1F_Text_AnnikaPostBattle:
	.string "Je suis venue dans cette ARÈNE parce que JUAN\n"
	.string "a complimenté mes chers POKéMON.\p"
	.string "Oh, si seulement j'avais rencontré JUAN il y a\n"
	.string "des années, quand j'étais plus jeune…$"

SootopolisCity_Gym_B1F_Text_BriannaIntro:
	.string "Hi hi…\n"
	.string "Ton air sérieux est si charmant.$"

SootopolisCity_Gym_B1F_Text_BriannaDefeat:
	.string "Oh, mince.\n"
	.string "J'ai été bien trop gentille avec toi.$"

SootopolisCity_Gym_B1F_Text_BriannaPostBattle:
	.string "Tu ne pourrais même pas toucher JUAN,\n"
	.string "j'en suis sûre. Hi hi…$"
