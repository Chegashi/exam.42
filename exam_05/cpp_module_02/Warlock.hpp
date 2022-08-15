#ifndef WARLOCK_HPP
#define WARLOCK_HPP
#include <iostream>
#include <string>
#include <map>

#include "ASpell.hpp"
#include "ATarget.hpp"
#include "SpellBook.hpp"

class Warlock
{
	private:

		std::string	name;
		std::string	title;
		SpellBook	_map;
	
	public:

		std::string const getName() const { return this->name; }

		std::string const getTitle() const { return this->title; }

		void setTitle(std::string title) { this->title = title; }

		Warlock(std::string name, std::string title) : name(name), title(title) 
			{ std::cout << this->name << ": This looks like another boring day." << std::endl; }

		Warlock(void){};

		Warlock(const Warlock &rhs){ *this = rhs; }

		Warlock operator =(const Warlock &rhs){
			this->name = rhs.name;
			this->title = rhs.title;
			return *this;
		}

		~Warlock()
			{ std::cout << this->name << ": My job here is done!" << std::endl; }

		void introduce() const
			{ std::cout << this->name << ": I am " << this->name << ", " << this->title << "!" << std::endl; }

		void learnSpell(ASpell *as)
			{ _map.learnSpell(as); }

		void forgetSpell(std::string name)
		{ _map.forgetSpell(name); }

		void launchSpell(std::string name, ATarget &atrg){
			ASpell* as = _map.createSpell(name);
			as->launch(atrg);
		}
};

#endif
