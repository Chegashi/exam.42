#ifndef Fwoosh_HPP
#define Fwoosh_HPP

#include <iostream>
#include <string>

#include "ASpell.hpp"

class Fwoosh : public ASpell
{	
	public:

		Fwoosh() : ASpell("Fwoosh", "fwooshed") {}

		~Fwoosh() { }

		ASpell *clone() const { return (new Fwoosh);};
};

#endif
