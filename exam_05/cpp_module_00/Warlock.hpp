#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <string>
#include <iostream>

class Warlock
{
	private:
		std::string name;
		std::string title;
	public:
		Warlock(std::string const & name, std::string const & title);
		~Warlock();
		std::string const getName() const;
		std::string const getTitle() const;
		void setTitle(std::string const &title);
		void introduce() const;
};

Warlock::Warlock(std::string const & name, std::string const & title)
{
	this->name = name;
	this->title = title;
	std::cout << this->name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
	std::cout << this->name << ": My job here is done!" << std::endl;
}

std::string const Warlock::getTitle() const
{
	return (this->title);
}

std::string const Warlock::getName() const
{
	return (this->name);
}

void Warlock::setTitle(std::string const &title)
{
	this->title = title;
}

void Warlock::introduce() const
{
	std::cout << this->name << ": I am " << this->name << ", "<< this->title << "!" << std::endl;
}

#endif