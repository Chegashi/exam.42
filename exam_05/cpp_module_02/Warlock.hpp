#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <string>
#include <iostream>

#include"ASpell.hpp"
#include"ATarget.hpp"
#include"Fwoosh.hpp"
#include"LittleKid.hpp"
#include "Dummy.hpp"
#include "SpellBook.hpp"


class Warlock
{
	private:
		std::string	name;
		std::string	title;
		SpellBook	book;

	public:
		Warlock(std::string const & name, std::string const & title);
		~Warlock();
		std::string const getName() const;
		std::string const getTitle() const;
		void	setTitle(std::string const &title);
		void	introduce() const;
		void	learnSpell(ASpell *ptr);
		void	forgetSpell(std::string name);
		void	launchSpell(std::string name, ATarget & targt);
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

void	Warlock::learnSpell(ASpell *ptr)
{
	book.learnSpell(ptr);
}

void	Warlock::forgetSpell(std::string name)
{
	book.forgetSpell(name);
}

void	Warlock::launchSpell(std::string name, ATarget &target)
{
	ASpell *as = book.createSpell(name);
	if ( as != (*book.end()).second)
		target.getHitBySpell(*as);
}

#endif
