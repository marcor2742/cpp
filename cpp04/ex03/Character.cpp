#include "Character.hpp"

ICharacter()
{

}

ICharacter(std::string str)
{

}

ICharacter(ICharacter const &copychar)
{

}

ICharacter &operator=(ICharacter const &copychar)
{

}

virtual ~Character()
{

}

virtual std::string const & getName() const
{

}

virtual void equip(AMateria* m)
{

}

virtual void unequip(int idx)
{

}

virtual void use(int idx, ICharacter& target)
{

}
