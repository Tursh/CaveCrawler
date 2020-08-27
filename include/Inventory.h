//
// Created by musique88 on 8/22/20.
//
#pragma once

namespace CC
{
	static const int NUMBER_OF_ELEMENTS = 7;
	class Inventory
	{
	public:
		Inventory();
		Inventory(int *elemental);
		int elemental_[NUMBER_OF_ELEMENTS];
	};
}
