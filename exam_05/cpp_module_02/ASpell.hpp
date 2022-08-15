#ifndef ASPELL_HPP
#define ASPELL_HPP
#include <iostream>
#include <string>

class ATarget;

class ASpell
{
	protected:
		std::string name;
		std::string effects;

	public:

		std::string const getName() const { return this->name; }
		std::string const getEffects() const { return this->effects; }
		ASpell(std::string name, std::string effects) : name(name), effects(effects) { }
		ASpell(ASpell &rhs) { *this = rhs; }
		ASpell() { };
		virtual ~ASpell() { };
		virtual ASpell *clone() const = 0;
		void launch(ATarget const &rhs) const;
};

#endif