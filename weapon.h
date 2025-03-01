#ifndef WEAPON_H
#define WEAPON_H

#include <string>
#include <map>
#include "Character.h"

class Weapon {
public:
    Weapon(const std::string& weapon_name, const std::string& weapon_type, double raw_damage_normal, double raw_damage_heavy,
        double critical_damage, double status_chance, double attack_speed, double melee_range);

    double calculateRawDamage(Character& character, bool is_heavy_attack = false, bool is_finisher_attack = false);
    double calculateDPS(Character& character, bool is_heavy_attack = false, bool is_finisher_attack = false);
    void displayStats() const;

private:
    std::string weapon_name;
    std::string weapon_type;
    double raw_damage_normal;
    double raw_damage_heavy;
    double critical_damage;
    double status_chance;
    double attack_speed;
    double melee_range;
    static const std::map<std::string, double> CRITICAL_CHANCE_MAPPING;

    bool doesCrit(double critical_chance);
};

#endif // WEAPON_H
