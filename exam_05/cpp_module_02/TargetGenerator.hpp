#ifndef TargetGenerator_HPP
#define TargetGenerator_HPP

#include "ATarget.hpp"
#include "Fwoosh.hpp"
#include <map>

class TargetGenerator
{
	public:
		TargetGenerator(){};
		~TargetGenerator(){};
		void	learnTargetType(ATarget *ptr)
			{ book.insert(std::make_pair(ptr->getType(), ptr)); }
		void forgetTargetType(std::string const & src)
			{ book.erase(src); }
		ATarget* createTarget(std::string const &src)
			{ return book[src]; }
		private:
			std::map<std::string, ATarget*>	book;
};

#endif
