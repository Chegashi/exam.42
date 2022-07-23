#ifndef ASPELL_HPP
#define ASPELL_HPP

#include <string>
#include <iostream>

class ASpell
{
	private:
		std::string name;
		std::string effects;
	public:
		ASpell(std::string const & name, std::string const & effects);
		ASpell(ASpell const & src);
		ASpell & operator=(ASpell const & rhs);
		~ASpell();
		std::string const getName() const;
		std::string const getEffects() const;
		virtual class ASpell * clone() const = 0;
};

ASpell::ASpell(std::string const & name, std::string const & effects)
{
	this->name = name;
	this->effects = effects;
}

ASpell::ASpell(ASpell const & src)
{
	*this = src;
}

ASpell & ASpell::operator=(ASpell const & rhs)
{
	if (this != &rhs)
	{
		this->name = rhs.name;
		this->effects = rhs.effects;
	}
	return *this;
}

ASpell::~ASpell()
{

}

std::string const ASpell::getEffects() const
{
	return (this->effects);
}

std::string const ASpell::getName() const
{
	return (this->name);
}

#endif