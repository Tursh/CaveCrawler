//
// Created by musique88 on 8/28/20.
//

#include <cmath>
#include "Skill/Progression.h"

#define FUNCTION_L 0.2f
#define FUNCTION_CONSTANT_ADDED 20
namespace CC
{
	int Progression::getLevel() const
	{
		return level_;
	}

// The function to get the needed xp for the next level is as follows:
// f(level) = (level * l)^2
	const int Progression::neededXpFunction(int level)
	{
		return std::floor((level * FUNCTION_L)*(level * FUNCTION_L)) + FUNCTION_CONSTANT_ADDED;
	}
//Leveling up adds one skillpoint to every skill
	void Progression::levelUp()
	{
		level_++;
	}

	bool Progression::addXp(int xp)
	{
		xp_ += xp;
		int neededXpToLevel = neededXpToLevelUp();
		if (neededXpToLevel >= 0)
		{
			levelUp();
			xp_ = neededXpToLevel;
			return true;
		}
		return false;
	}

	int Progression::neededXpToLevelUp() const
	{
		return xp_ - neededXpFunction(level_);
	}

	void Progression::addSkillPoints(int skillPoints)
	{
		skillPoints_ += skillPoints;
	}

	void Progression::addPointToSkill(Skill skill, int amountOfSkillpoints)
	{
		skills_[(int)skill] += amountOfSkillpoints;
	}

	void Progression::enemyKilled(int xp)
	{
		addSkillPoints(1);
		addXp(xp);
	}

	void Progression::resetSkills()
	{
		skills_ = std::array<int, NUMBER_OF_SKILLS>();
	}
}