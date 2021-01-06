//
// Created by musique88 on 8/28/20.
//

#pragma once

#include <array>
#define NUMBER_OF_SKILLS 21

namespace CC
{
	enum Skill {
		FLAT_ARMOR_SKILL, // reduction of incoming damage
		ELEMENTAL_RESIST_SKILL,

		FLAT_DAMAGE_SKILL, // additional damage increase
		ELEMENTAL_DAMAGE_SKILL, // additional damage increase if it is elemental
		ELEMENTAL_PIERCING_SKILL,

		SPELL_CASTING_SPEED_SKILL, // diminishes spell casting timer
		SPELL_CASTING_COST_SKILL, // diminishes spell casting cost in elemental

		MOVEMENT_SPEED_SKILL,
		RUNNING_SPEED_SKILL,
		CROUCHING_MOVEMENT_SKILL
	};

	class Progression
	{
		int level_;
		int xp_;
		int skillPoints_;
		std::array<int, NUMBER_OF_SKILLS> skills_;
		void levelUp();
	public:
		void resetSkills();
		int getLevel() const;
		static int neededXpFunction(int level);
		int neededXpToLevelUp() const;
		bool addXp(int xp);
		void addSkillPoints(int amount);
		void addPointToSkill(Skill skill, int amount);
		void enemyKilled(int xp);
	};
}