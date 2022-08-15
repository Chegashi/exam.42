#ifndef ATARGET_HPP
#define ATARGET_HPP
#include <iostream>
#include <string>

#include "ASpell.hpp"

class ATarget : public ASpell
{
	protected:
		std::string type;
	
	public:
		std::string const &getType() const { return this->type; }
		ATarget(std::string type) : type(type) { };

		ATarget(class ATarget &rhs) { *this = rhs; }

		ATarget();

		virtual ~ATarget(){}

		ATarget &operator =(ATarget &rhs)
		{
			this->type = rhs.getType();
			return *this;
		}

		void getHitBySpell(ASpell const &as) const
			{ std::cout << this->type << " has been " << as.getEffects() << "!" << std::endl; }

		virtual ATarget *clone(void) const = 0;
};


#endif