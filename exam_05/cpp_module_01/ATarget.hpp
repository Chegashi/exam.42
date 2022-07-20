#ifndef ATARGET_HPP
#define ATARGET_HPP

#include <string>
#include <iostream>

#include "ASpell.hpp"

class ATarget
{
	private:
		std::string type;
	public:
		ATarget(std::string const & type);
		ATarget(ATarget const & src);
		ATarget & operator=(ATarget const & rhs);
		~ATarget();
		std::string const getType() const;
		virtual class ATarget * clone() const = 0;
		void getHitBySpell(ASpell const & as);
};

ATarget::ATarget(std::string const & type)
{
	this->type = type;
}

ATarget::ATarget(ATarget const & src)
{
	*this = src;
}

ATarget & ATarget::operator=(ATarget const & rhs)
{
	if (this != &rhs)
		this->type = rhs.type;
	return *this;
}

ATarget::~ATarget()
{

}

std::string const ATarget::getType() const
{
	return (this->type);
}

void ATarget::getHitBySpell(ASpell const & as)
{
	std::cout << this->type << " has been " << as.getEffects() << "!" << std::endl;
}

#endif