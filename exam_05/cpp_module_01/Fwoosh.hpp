#ifndef FWoosh_HPP
#define FWoosh_HPP

#include "ASpell.hpp"

class Fwoosh : public ASpell
{
	public:
		Fwoosh();
		Fwoosh * clone() const;
};

Fwoosh::Fwoosh() : ASpell("Fwoosh", "fwooshed")
{

}

Fwoosh* Fwoosh::clone() const
{
	return new Fwoosh();
}

#endif
