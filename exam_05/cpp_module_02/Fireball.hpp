#ifndef Fireball_HPP
#define Fireball_HPP

#include "ASpell.hpp"

class Fireball : public ASpell
{
	public:
		Fireball();
		Fireball * clone() const;
};

Fireball::Fireball() : ASpell("Fireball", "burnt to a crisp")
{

}

Fireball* Fireball::clone() const
{
	return new Fireball();
}

#endif
