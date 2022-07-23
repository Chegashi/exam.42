#ifndef TargetGenerator_HPP
#define TargetGenerator_HPP

#include "ATarget.hpp"
#include "Fwoosh.hpp"
#include <map>

class TargetGenerator
{
	public:
		TargetGenerator();
		~TargetGenerator();
		void forgetTargetType(std::string const & src);
		ATarget* createTarget(std::string const &);
		void	learnTargetType(ATarget *ptr);
		std::map<std::string, ATarget*>::iterator begin();
		std::map<std::string, ATarget*>::iterator end();
		private:
			std::map<std::string, ATarget*>	book;
};

TargetGenerator::TargetGenerator()
{

}

TargetGenerator::~TargetGenerator()
{

}

void	TargetGenerator::learnTargetType(ATarget *ptr)
{
	this->book.insert(std:: make_pair(ptr->getType(), ptr));
}

void	TargetGenerator::forgetTargetType(std::string const & src)
{
	this->book.erase(src);
}

ATarget*	TargetGenerator::createTarget(std::string const &src)
{
	return (book[src]);
}

std::map<std::string, ATarget*>::iterator	TargetGenerator::begin()
{
	return (book.begin());
}

std::map<std::string, ATarget*>::iterator	TargetGenerator::end()
{
	return (book.end());
}

#endif
