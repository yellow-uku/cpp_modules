#ifndef __HARLFILTER_H__
# define __HARLFILTER_H__

#include <iostream>

#define LIMIT_LEVEL 4

class Harl
{
	private:
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );
	
		void (Harl::*handler[LIMIT_LEVEL])(void);

	public:
		Harl();
		~Harl();

		void complain( std::string const &level );
		int get_level_id(std::string const &level);

	private:
		static std::string levels[LIMIT_LEVEL];
};

#endif