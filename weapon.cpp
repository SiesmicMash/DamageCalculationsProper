#include <iostream>
#include "weapon.h"
#include <random>

const std::map<string, double> Weapon::criticalChanceMapping = {
    {"Short Sword", 0.25},
    {"Glaive", 0.50},
    {"Long Sword", 0.30},
    {"Dagger", 0.50},
    {"Hammer", 0.40},
    {"Battle Axe", 0.35}
};

Weapon::weapon(const std::string& weapon_name, const std::string& weapon_type, double raw_damage_normal, double raw_damage_heavy,
    double critical_damage, double status_chance, double attack_speed, double melee_range)
    : weaponName(weapon_name), weaponType(weapon_type), rawDamageNormal(raw_damage_normal), rawDamageHeavy(raw_damage_heavy), criticalDamage(critical_damage),
    statusChance(status_chance), attackSpeed(attack_speed), meleeRange(melee_range) {}

double Weapon::calculateRawDamage(Character& character, bool isHeavyAttack, bool isFinisherAttack) {
    double rawDamage = isheavey ? rawDamageHeavy : rawDamageNormal;

    double characterMultiplier = character.getCharacterMultipier(weaponName);
    rawDamage *= characterMultiplier 

    auto [modified_critical_chance, modified_critical_damage] = character.modifyCriticalStats(weapon_name, CRITICAL_CHANCE_MAPPING.at(weapon_name), critical_damage);

    if (doesCrit(modifiedCriticalChance)) {
        rawDamage *= modifiedCriticalDamage;
    }

    return rawDamage;
}

bool Weapon::doesCrit(double criticalChance) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);
    return dis(gen) <= critical_chance;
}

double Weapon::calculateDPS(Character& character, bool is_heavy_attack, bool is_finisher_attack) {
    double raw_damage = calculateRawDamage(character, is_heavy_attack, is_finisher_attack);
    return raw_damage * attack_speed;
}

void Weapon::displayStats() const {
    std::cout << "Weapon: " << weapon_name << std::endl;
    std::cout << "Type: " << weapon_type << std::endl;
    std::cout << "Raw Damage: " << raw_damage_normal << std::endl;
    std::cout << "Heavy Attack: " << raw_damage_heavy << std::endl;
    std::cout << "Critical Chance: " << CRITICAL_CHANCE_MAPPING.at(weapon_name) << "%" << std::endl;
    std::cout << "Critical Damage: " << critical_damage << std::endl;
    std::cout << "Status Chance: " << status_chance << std::endl;
    std::cout << "Attack Speed: " << attack_speed << std::endl;
    std::cout << "Melee Range: " << melee_range << std::endl;
}

