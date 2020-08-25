//
// Created by musique88 on 8/22/20.
//

#include "Inventory.h"

namespace CC
{
	Inventory::Inventory(int *elemental)
	{
		for(int i = 0; i < NUMBER_OF_ELEMENTS; i++)
			this->elemental[i] = elemental[i];
	}
	Inventory::Inventory()
	{
		int elemental[] = {0,0,0,0,0,0,0};
		for(int i = 0; i < NUMBER_OF_ELEMENTS; i++)
			this->elemental[i] = elemental[i];
	}
}