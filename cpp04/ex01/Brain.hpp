#ifndef __BRAIN_H__
# define __BRAIN_H__

#include <iostream>

class Brain
{

	private:
		std::string ideas[100];

	public:
		Brain();
		~Brain();
		Brain(const Brain&);	// need to implement

		Brain& operator=(const Brain &);	// need to implement

		void	setIdeas(std::string);
		std::string	getIdeas();
};

#endif