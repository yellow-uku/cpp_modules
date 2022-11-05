#include "Harl.hpp"

Harl::Harl()
{
	handler[0] = &Harl::debug;
	handler[1] = &Harl::info;
	handler[2] = &Harl::warning;
	handler[3] = &Harl::error;
}

Harl::~Harl(){}

std::string Harl::levels[LIMIT_LEVEL] = {
	"DEBUG",
	"INFO",
	"WARNING",
	"ERROR"
};

void Harl::debug()
{
	std::cout << "Debug: I love having extra bacon. I really do!\n";
}

void Harl::info()
{
	std::cout << "Info: You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n";
}

void Harl::warning()
{
	std::cout << "Warning: I think I deserve to have some extra bacon for free.\n";
}

void Harl::error()
{
	std::cout << "Error: This is unacceptable! I want to speak to the manager now.\n";
}

void Harl::complain(std::string level)
{

	for (int i = 0; i < LIMIT_LEVEL; ++i)
	{
		if (this->levels[i] == level)
			(*this.*handler[i])();
	}
}