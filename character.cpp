#include <iostream>
#include <time>
#include <cmath>
#include <stdlib.h>
#include "Character.H"
#include <utility>

Character::Character(const std::string &characterName, const std::string &characterType, const std::string &passive, double healthPoint, double defence,
	double movementSpeed, const std::string &ability, bool isAlive;)
	: characterName(characterName), characterType(characterType),passive(passive), healthPoint(healthPoint), defence(defence), 
	movementSpeed(movementSpeed), ability(ability), isAlive(isAlive) {}

double Character::getWeaponCriticalMultiplier() const{
	return 1.0;
}
std::pair<double, double> modifyCriticalStat(double criticalChance, double criticalDamage) const {
	std::make_pair(criticalChance, criticalDamage); 
}
double Character::damagaReduction(double damage) {
	double dr = defence / (defence + 250); 
	double damageTaken = dr * damage;
	healthPoint -= damageTaken;

	if (healthPoint <= 0) {
		return isAlive = false; 
	}

	return damageTaken; 
	}
double Character::getHealthPoint() const{
	return healthPoint;
};