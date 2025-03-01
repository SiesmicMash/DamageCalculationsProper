#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <string>
#include <map>
#include <utility>

class Character {
public:
    Character(const std::string& name, const std::string& character_type, const std::string& passive,
        double health_stat, double defence_stat, double movement_speed, const std::string& ability, bool is_alive = true);

    virtual double getWeaponMultiplier(const std::string& weapon_name) const;
    virtual std::pair<double, double> modifyCriticalStats(const std::string& weapon_name, double critical_chance, double critical_damage) const;
    void displayStats() const;
    double damageReduction(double damage);

protected:
    std::string name;
    std::string character_type;
    std::string passive;
    double health_stat;
    double defence_stat;
    double movement_speed;
    std::string ability;
    bool is_alive;
};

class Paladin : public Character {
public:
    Paladin(const std::string& name, const std::string& passive, double health_stat, double defence_stat, double movement_speed, const std::string& ability);
    double getWeaponMultiplier(const std::string& weapon_name) const override;
    std::pair<double, double> modifyCriticalStats(const std::string& weapon_name, double critical_chance, double critical_damage) const override;

private:
    std::map<std::string, double> weapon_multipliers;
};

class Knight : public Character {
public:
    Knight(const std::string& name, const std::string& passive, double health_stat, double defence_stat, double movement_speed, const std::string& ability);
    double getWeaponMultiplier(const std::string& weapon_name) const override;
    std::pair<double, double> modifyCriticalStats(const std::string& weapon_name, double critical_chance, double critical_damage) const override;

private:
    std::map<std::string, double> weapon_multipliers;
};

class Scout : public Character {
public:
    Scout(const std::string& name, const std::string& passive, double health_stat, double defence_stat, double movement_speed, const std::string& ability);
    double getWeaponMultiplier(const std::string& weapon_name) const override;
    std::pair<double, double> modifyCriticalStats(const std::string& weapon_name, double critical_chance, double critical_damage) const override;

private:
    std::map<std::string, double> weapon_multipliers;
};

#endif // CHARACTER_H

