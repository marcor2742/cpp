#include <iostream>
#include <string>

class Weapon
{
private:
    std::string type;
public:
    Weapon();
    ~Weapon();
    const std::string& getType();
};

Weapon::Weapon(/* args */)
{
}

Weapon::~Weapon()
{
}
