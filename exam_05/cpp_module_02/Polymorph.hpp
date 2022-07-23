#ifndef Polymorph_HPP
#define Polymorph_HPP

#include "ASpell.hpp"

class Polymorph : public ASpell
{
	public:
		Polymorph();
		Polymorph * clone() const;
};

Polymorph::Polymorph() : ASpell("Polymorph", "turned into a critter")
{

}

Polymorph* Polymorph::clone() const
{
	return new Polymorph();
}

#endif
