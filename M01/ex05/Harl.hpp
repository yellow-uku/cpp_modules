#ifndef __HARL_H__
# define __HARL_H__

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

		void complain( std::string level );

	private:
		static std::string levels[LIMIT_LEVEL];
};

#endif