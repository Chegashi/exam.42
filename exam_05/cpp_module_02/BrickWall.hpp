#ifndef BrickWall_HPP
#define BrickWall_HPP

#include <iostream>
#include <string>

#include "ATarget.hpp"

class BrickWall : public ATarget
{	
	public:

		BrickWall() : ATarget("Inconspicuous Red-brick Wall") { }

		virtual ~BrickWall() { };

		class ATarget *clone() const { return (new BrickWall); };
};

#endif