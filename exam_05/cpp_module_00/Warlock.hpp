#ifndef WARLOCK_HPP
#define WARLOCK_HPP
#include <iostream>
#include <string>
class Warlock
{
	private:

		std::string name;
		std::string title;
	
	public:

		std::string const getName() const { return this->name; }

		std::string const getTitle() const { return this->title; }

		void setTitle(std::string title) { this->title = title; }

		Warlock(std::string name, std::string title) : name(name), title(title) 
		{
			std::cout << this->name << ": This looks like another boring day." << std::endl;
		}

		~Warlock()
		{
			std::cout << this->name << ": My job here is done!" << std::endl;
		}

		void introduce() const
		{
			std::cout << this->name << ": I am " << this->name << ", " << this->title << "!" << std::endl;
		}
};

#endif
