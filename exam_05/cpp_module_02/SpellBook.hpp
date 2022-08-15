#ifndef SpellBook_HPP
#define SpellBook_HPP

#include "ASpell.hpp"
#include "Fwoosh.hpp"
#include <map>

class SpellBook
{
	private:
		std::map<std::string, ASpell*>	book;

	public:
		SpellBook(){};

		~SpellBook(){};

		void	learnSpell(ASpell *ptr)
			{ this->book.insert(std:: make_pair(ptr->getName(), ptr)); }

		void forgetSpell(std::string const & src)
			{ this->book.erase(src); }

		ASpell* createSpell(std::string const &src)
			{ return (book[src]); }
};

#endif
