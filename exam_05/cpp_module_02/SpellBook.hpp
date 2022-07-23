#ifndef SpellBook_HPP
#define SpellBook_HPP

#include "ASpell.hpp"
#include "Fwoosh.hpp"
#include <map>

class SpellBook
{
	public:
		SpellBook();
		~SpellBook();
		void forgetSpell(std::string const & src);
		ASpell* createSpell(std::string const &);
		void	learnSpell(ASpell *ptr);
		std::map<std::string, ASpell*>::iterator begin();
		std::map<std::string, ASpell*>::iterator end();
		private:
			std::map<std::string, ASpell*>	book;
};

SpellBook::SpellBook()
{

}

SpellBook::~SpellBook()
{

}

void	SpellBook::learnSpell(ASpell *ptr)
{
	this->book.insert(std:: make_pair(ptr->getName(), ptr));
}

void	SpellBook::forgetSpell(std::string const & src)
{
	this->book.erase(src);
}

ASpell*	SpellBook::createSpell(std::string const &src)
{
	return (book[src]);
}

std::map<std::string, ASpell*>::iterator	SpellBook::begin()
{
	return (book.begin());
}

std::map<std::string, ASpell*>::iterator	SpellBook::end()
{
	return (book.end());
}

#endif
