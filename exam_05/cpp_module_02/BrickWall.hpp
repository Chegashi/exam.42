#ifndef BrickWall_HPP
#define BrickWall_HPP

#include "ATarget.hpp"

class BrickWall : public ATarget
{
	public:
		BrickWall();
		BrickWall * clone() const;
};

BrickWall::BrickWall() : ATarget("Inconspicuous Red-brick Wall")
{

}

BrickWall* BrickWall::clone() const
{
	return new BrickWall();
}

#endif
