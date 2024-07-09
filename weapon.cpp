#include <iostream>
#include <random>
#include "weapon.h"

const std::map<std::string, double> Weapon::CRITICAL_CHANCE_MAPPING = {
    {"Short Sword", 0.25},
    {"Glaive", 0.50},
    {"Long Sword", 0.30},
    {"Dagger", 0.50},
    {"Hammer", 0.40},
    {"Battle Axe", 0.35}
};

Weapon::weapon(const std::string& weapon_name, const std::string& weapon_type, double raw_damage_normal, double raw_damage_heavy, double critical_chance
    double critical_damage, double status_chance, double attack_speed, double melee_range)
    : weaponName(weapon_name), weaponType(weapon_type), rawDamageNormal(raw_damage_normal), rawDamageHeavy(raw_damage_heavy), criticalDamage(critical_damage),
    criticalChance(critical_damage), statusChance(status_chance), attackSpeed(attack_speed), meleeRange(melee_range); {}

double Weapon::weapon calculateRawDamage(Character& character, bool isHeavyAttack, bool isFininsherAttack) {
    double rawDamage = isHeavyAttack ? rawDamage
}