ViridianForest_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ViridianForest_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

ViridianForest_OnTransition: 
	callnative SetTimeBasedEncounters
	end

ViridianForest_EventScript_MaxPotion::
    finditem ITEM_MAX_POTION
    end

ViridianForest_EventScript_DireHit::
    finditem ITEM_DIRE_HIT
    end

ViridianForest_EventScript_Elixir::
    finditem ITEM_ELIXIR
    end

ViridianForest_EventScript_Revive::
    finditem ITEM_REVIVE
    end

ViridianForest_EventScript_FullRestore::
    finditem ITEM_FULL_RESTORE
    end

ViridianForest_EventScript_MaxEther::
    finditem ITEM_MAX_ETHER
    end

ViridianForest_EventScript_FullHeal::
    finditem ITEM_FULL_HEAL
    end
