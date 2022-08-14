#ifndef Dummy_HPP
#define Dummy_HPP

#include <iostream>
#include <string>

// class ATarget;
#include "ATarget.hpp"

class Dummy : public ATarget
{	
	public:

		Dummy() : ATarget("Target Practice Dummy") { }

		virtual ~Dummy() { };

		class ATarget *clone() const { return (new Dummy); };
};

#endif