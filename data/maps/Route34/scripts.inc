.set LOCALID_ROUTE34_DAYCAREMAN, 12

Route34_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route34_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route34_OnTransition: 
	specialvar VAR_RESULT, GetDaycareState
	call_if_eq VAR_RESULT, DAYCARE_EGG_WAITING, Route34_MapScript_EggReady
	callnative SetTimeBasedEncounters
	end	

Route34_MapScript_EggReady::
	setobjectxyperm LOCALID_ROUTE34_DAYCAREMAN, 30, 34
	return

Route34_EventScript_YoungsterSamuel::
	trainerbattle_single TRAINER_SAMUEL Route34_Text_YoungsterSamuel_Seen, Route34_Text_YoungsterSamuel_Beaten
	msgbox Route34_Text_YoungsterSamuel_After, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_YoungsterIan::
	trainerbattle_single TRAINER_IAN Route34_Text_YoungsterIan_Seen, Route34_Text_YoungsterIan_Beaten
	msgbox Route34_Text_YoungsterIan_After, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_CamperTodd::
	trainerbattle_single TRAINER_TODD Route34_Text_CamperTodd_Seen, Route34_Text_CamperTodd_Beaten
	msgbox Route34_Text_CamperTodd_After, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_PicnickerGina::
	trainerbattle_single TRAINER_GINA Route34_Text_PicnickerGina_Seen, Route34_Text_PicnickerGina_Beaten
	msgbox Route34_Text_PicnickerGina_After, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_OfficerKeith::
	trainerbattle_single TRAINER_KEITH Route34_Text_OfficerKeith_Seen, Route34_Text_OfficerKeith_Win
	msgbox Route34_Text_OfficerKeith_After, MSGBOX_AUTOCLOSE
	end


Route34_EventScript_PokefanMBrandon::
	trainerbattle_single TRAINER_BRANDON Route34_Text_PokefanBrandon_Seen, Route34_Text_PokefanBrandon_Beaten
	msgbox Route34_Text_PokefanBrandon_After, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_Irene::
	trainerbattle_single TRAINER_IRENE Route34_Text_CooltrainerIrene_Seen, Route34_Text_CooltrainerIrene_Beaten
	msgbox Route34_Text_CooltrainerIrene_After2, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_Jenn::
	trainerbattle_single TRAINER_JENN Route34_Text_CooltrainerJenn_Seen, Route34_Text_CooltrainerJenn_Beaten
	msgbox Route34_Text_CooltrainerJenn_After2, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_Kate::
	trainerbattle_single TRAINER_KATE Route34_Text_CooltrainerKate_Seen, Route34_Text_CooltrainerKate_Beaten
	msgbox Route34_Text_CooltrainerKate_After, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_Sign1::
	lock
	msgbox Route34_Text_Sign_Route34, MSGBOX_SIGN
	closemessage
	release
	end

Route34_EventScript_Sign2::
	lock
	msgbox Route34_Text_Sign_DayCare, MSGBOX_SIGN
	closemessage
	release
	end

Route34_EventScript_Sign3::
	lock
	msgbox Route34_Text_TrainerTips, MSGBOX_SIGN
	closemessage
	release
	end

Route34_EventScript_Item_SoftSand::
	finditem ITEM_SOFT_SAND
	end

Route34_EventScript_Item_RareCandy::
	finditem ITEM_RARE_CANDY
	end

Route34_EventScript_Item_SuperPotion::
	finditem ITEM_SUPER_POTION
	end


Route34_Text_YoungsterSamuel_Seen:
	.string "Hé ! Je cherche un FÉROSINGE !$"

Route34_Text_YoungsterSamuel_Beaten:
	.string "Battue par un inconnu de passage !$"

Route34_Text_YoungsterSamuel_After:
	.string "Je vais m'entraîner encore plus dur.\p"
	.string "Après tout, j'essaie de devenir\n"
	.string "CHAMPION D'ARÈNE.$"

Route34_Text_YoungsterIan_Seen:
	.string "Je suis le meilleur de ma classe\n"
	.string "en POKéMON.$"

Route34_Text_YoungsterIan_Beaten:
	.string "Non ! Il y a de meilleurs dresseurs…$"

Route34_Text_YoungsterIan_After:
	.string "Je fais de mon mieux pour être\n"
	.string "la star de ma classe.$"

Route34_Text_CamperTodd_Seen:
	.string "Je suis sûr de ma capacité à\n"
	.string "élever des POKéMON.\p"
	.string "Tu veux voir ?$"

Route34_Text_CamperTodd_Beaten:
	.string "J'ai raté mon entraînement ?$"

Route34_Text_CamperTodd_After:
	.string "Je devrais peut-être en laisser un à la PENSION,\n"
	.string "ou utiliser quelques objets…$"

Route34_Text_PicnickerGina_Seen:
	.string "Tu es dresseur ?\p"
	.string "Faisons un combat d'entraînement.$"

Route34_Text_PicnickerGina_Beaten:
	.string "Oh, non ! Je n'arrive jamais à gagner…$"

Route34_Text_PicnickerGina_After:
	.string "Tu es trop fort pour être un\n"
	.string "partenaire d'entraînement.$"

Route34_Text_OfficerKeith_Seen:
	.string "Qui va là ?\n"
	.string "Que fais-tu ici ?$"

Route34_Text_OfficerKeith_Win:
	.string "Tu es un sacré petit costaud.$"

Route34_Text_OfficerKeith_After:
	.string "Oui, rien d'anormal aujourd'hui.\p"
	.string "Sois sage et évite les ennuis.$"

Route34_Text_OfficerKeith_Daytime:
	.string "Je patrouille à la recherche de\n"
	.string "personnes suspectes.$"

Route34_Text_PokefanBrandon_Seen:
	.string "Je viens de récupérer mon POKéMON\n"
	.string "de la PENSION.\p"
	.string "Voyons s'il est devenu plus fort !$"

Route34_Text_PokefanBrandon_Beaten:
	.string "Pourquoi ça finit comme ça ?$"

Route34_Text_PokefanBrandon_After:
	.string "Mon POKéMON est revenu avec de nouvelles attaques.\p"
	.string "Ça m'a complètement déconcerté !$"

Route34_Text_Sign_IlexForest:
	.string "FORÊT DE CHÊNE\n"
	.string "PAR LA PORTE$"

Route34_Text_Sign_Route34:
	.string "ROUTE 34\n"
	.string "DOUBLONVILLE - ECORCIA\p"
	.string "FORÊT DE CHÊNE ENTRE LES DEUX$"

Route34_Text_TrainerTips:
	.string "ASTUCE DRESSEUR\p"
	.string "Les arbres à BAIES donnent de nouvelles BAIES\n"
	.string "plusieurs fois par jour.\p"
	.string "Note quels arbres donnent quelles\n"
	.string "BAIES.$"

Route34_Text_CooltrainerIrene_Seen:
	.string "IRENE : Kyaaah ! Quelqu'un nous a trouvées !$"

Route34_Text_CooltrainerIrene_Beaten:
	.string "IRENE : Ohhh ! Tu es trop fort !$"

Route34_Text_CooltrainerIrene_After1:
	.string "IRENE : Ma sœur KATE va te le faire payer\n"
	.string "pour ça !$"

Route34_Text_CooltrainerIrene_After2:
	.string "IRENE : Cette plage n'est-elle pas géniale ?\p"
	.string "C'est notre petit coin secret !$"

Route34_Text_CooltrainerJenn_Seen:
	.string "JENN : Tu ne peux pas battre IRENE et\n"
	.string "t'en tirer comme ça !$"

Route34_Text_CooltrainerJenn_Beaten:
	.string "JENN : Désolée, IRENE ! Ma chère sœur !$"

Route34_Text_CooltrainerJenn_After1:
	.string "JENN : Ne prends pas la grosse tête !\n"
	.string "Ma sœur KATE est coriace !$"

Route34_Text_CooltrainerJenn_After2:
	.string "JENN : Le soleil rend ton corps\n"
	.string "plus fort.$"

Route34_Text_CooltrainerKate_Seen:
	.string "KATE : Tu as été vraiment méchant avec\n"
	.string "mes petites sœurs !$"

Route34_Text_CooltrainerKate_Beaten:
	.string "KATE : Non ! Je n'arrive pas à croire que j'ai perdu.$"

Route34_Text_CooltrainerKate_GiveSoftSand:
	.string "KATE : Tu es trop fort. Je n'avais\n"
	.string "aucune chance. Tiens, tu mérites\n"
	.string "ça.$"

Route34_Text_CooltrainerKate_After:
	.string "KATE : Désolée de t'avoir attaqué.\p"
	.string "On ne s'attendait pas à ce que quelqu'un\n"
	.string "nous trouve ici. Tu nous as vraiment surprises.$"


Route34_Text_Sign_DayCare:
	.string "PENSION\p"
	.string "CONFIEZ-NOUS VOS POKéMON !$"
