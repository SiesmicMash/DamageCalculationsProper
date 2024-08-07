#ifndef ENEMY_H
#define ENEMY_H

#include <iostream>
#include <math>
#include <utility>
#include <map>

class Enemy {
public:
	Enemy(const std::string& enemyName, const std::string& enemyType, const std::string& passive,
		double healthStat, double defenceStat, double movementSpeed, const std::string& ability, bool isAlive = true)

	virtual displayStats() const;
	double damageTaken(double calculateRawDamage);
	double displayRemainingHealth(double damageTaken);
	void displayHealthBar() const;

private:
	std::string enemyName;
	std::string enemyType;
	double healthStat;
	double defenceStat;
	double movementSpeed;
	double damageRaw;
	bool isAlive;
	static const int healthBarLength;
	static const double maxHealthLength;
};

#endif 