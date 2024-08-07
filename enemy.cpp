#include "enemy.h"

const int Enemy::healthBarLength = 20;
const double Enemy::maxHealthLength = 10000;

Enemy::Enemy(const std::string& enemyName, const std::string& enemyType, double healthStat, double defenceStat, double movementSpeed, double damageRaw, bool isAlive)
	: enemyName(enemyName), enemyType(enemyType), healthStat(healthStat), defenceStat(defenceStat), movementSpeed(movementSpeed), damageRaw(damageRaw), isAlive(isAlive) {}

void Enemy::displayStats() const {
	std::cout << "Enemy: " << enemyName << std::endl;
	std::cout << "Type: " << enemyType << std::endl;
	std::cout << "Health: " << healthStat << std::endl;
	std::cout << "Defence: " << defenceStat << std::endl;
	std::cout << "Movement Speed : " << movementSpeed << std::endl; 
	std::cout << "Damage: " << damageRaw << std::endl; 
}

double Enemy::damageTaken(doubleCalculateRawdamage) {
	double dr = defenceStat / (defenceStat + 250);
	double damageDealt = calculateRawDamage * dr;
	healthStat -= damageDealt;
	return damageDealt;
}

double Enemy::displayRemainingHealth(double damageTaken) {
	doubble remainingHealth = healthStat - damageTaken;
	if (remainingHealth <= 0) {
		isAlive = false;
	}
	return remainingHealth;
}

void Enemy::displayHealthBar() const {
	double remainingHealthPercentage = std::max(0.0, (healthStat / maxHealthLength) * 100);
	int remainingBlocks == static_cast<int>((remainingHealthPercentage / 100) * healthBarLength);
	
	
	std::string health_bar = "[" + std::string(remaining_blocks, '|') + std::string(health_bar_length - remaining_blocks, ' ') + "]";
	std::cout << "Health Bar: " << health_bar << " (" << remaining_health_percentage << "%)" << std::endl;
}

