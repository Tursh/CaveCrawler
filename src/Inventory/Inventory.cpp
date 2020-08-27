//
// Created by musique88 on 8/22/20.
//

#include "Inventory.h"

namespace CC
{
	Inventory::Inventory(int *elemental)
	{
		for(int i = 0; i < NUMBER_OF_ELEMENTS; i++)
			elemental_[i] = elemental[i];
	}
	Inventory::Inventory()
	{
		for(int & i : elemental_)
			i = 0;
	}
}