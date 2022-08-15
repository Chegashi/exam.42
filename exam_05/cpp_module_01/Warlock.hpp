#ifndef WARLOCK_HPP
#define WARLOCK_HPP
#include <iostream>
#include <string>
#include <map>

#include "ASpell.hpp"
#include "ATarget.hpp"

class Warlock
{
	private:

		std::string name;
		std::string title;
		std::map<std::string , ASpell*> _map;
	
	public:

		std::string const getName() const { return this->name; }

		std::string const getTitle() const { return this->title; }

		void setTitle(std::string title) { this->title = title; }

		Warlock(std::string name, std::string title) : name(name), title(title) 
			{ std::cout << this->name << ": This looks like another boring day." << std::endl; }

		Warlock(void);

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
			{ _map.insert(std::make_pair(as->getName(), as)); }

		void forgetSpell(std::string name){
			std::map<std::string, ASpell*>::iterator it;
			it = _map.find(name);
			if (it != _map.end())
				_map.erase(it);
		}

		void launchSpell(std::string name, ATarget &atrg){
			std::map<std::string, ASpell*>::iterator it;
			it = _map.find(name);
			if (it != _map.end())
			it->second->launch(atrg);
		}
};

#endif
