#include <iostream>
#include <string>
#include <memory>

class Weapon;

class Character {
private:
    std::unique_ptr<Weapon> weapon;

public:
    Character() {}

    void SetWeapon(std::unique_ptr<Weapon> weapon) {
        this->weapon = std::move(weapon);
    }

    Weapon* GetWeapon() const {
        return weapon.get();
    }
};

class Weapon {
public:
    virtual float GetDamage() const = 0;
    virtual std::string GetName() const = 0;
};

class Sword : public Weapon {
public:
    float GetDamage() const override {
        return 20.0f;
    }

    std::string GetName() const override {
        return "Sword";
    }
};

class Gun : public Weapon {
public:
    float GetDamage() const override {
        return 40.0f;
    }

    std::string GetName() const override {
        return "Gun";
    }
};

int main() {
    Character character;
    std::unique_ptr<Weapon> sword = std::make_unique<Sword>();
    character.SetWeapon(std::move(sword));

    Weapon* equippedWeapon = character.GetWeapon();
    if (equippedWeapon) {
        std::cout << "Equipped weapon: " << equippedWeapon->GetName() << std::endl;
        std::cout << "Damage: " << equippedWeapon->GetDamage() << std::endl;
    }
    else {
        std::cout << "Character does not have a weapon." << std::endl;
    }

    return 0;
}
