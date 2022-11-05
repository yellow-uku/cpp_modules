#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	size_ = 0;
}

void	PhoneBook::add_contact(const Contact &contact)
{
	if (contact.is_empty())
		std::cout << "One of the contact fields is empty. Please, fill all the fields." << std::endl;
	else 
	{
		try
		{
			if (size_ == 8)
			{
				contacts[0] = contact;
				size_++;
			}
			else if (size_ < 8)
			{
				contacts[size_] = contact;
				size_++;
			}
			else
				throw (size_);
		}
		catch(int num)
		{
			std::cout << std::endl;
			std::cout << "Too many contacts!" << std::endl;
			std::cout << "Number of contacts in your Phonebook: " << num << std::endl;
		}
	}
}

void	PhoneBook::search_contact()
{
	if (size_ == 0)
		std::cout << "PhoneBook is empty. Please, add the first contact and try again." << std::endl;
	else
	{
		for (int i = 0; i < size_; i++)
		{
			std::cout << std::right << std::setw(10) << i << '|';
			if (contacts[i].first_name_.length() > 10)
				std::cout << std::right << contacts[i].first_name_.substr(0, 9) << '.' << '|';
			else
				std::cout << std::right << std::setw(10) << contacts[i].first_name_ << '|';
			if (contacts[i].last_name_.length()> 10)
				std::cout << std::right << contacts[i].last_name_.substr(0, 9) << '.' << '|';
			else
				std::cout << std::right << std::setw(10) << contacts[i].last_name_ << '|';
			if (contacts[i].nickname_.length()> 10)
				std::cout << std::right << contacts[i].nickname_.substr(0, 9) << '.' << std::endl;
			else
				std::cout << std::right << std::setw(10) << contacts[i].nickname_ << std::endl;
		}

		std::cout << "Please, enter an index of the contact" << std::endl;
		std::string input;
		std::cin >> input;
		int	j;
		try
		{
			j = std::stoi(input);
			if (j < size_ && j >= 0)
			{
				std::cout << contacts[j].first_name_ << std::endl;
				std::cout << contacts[j].last_name_ << std::endl;
				std::cout << contacts[j].nickname_ << std::endl;
				std::cout << contacts[j].phone_number_ << std::endl;
				std::cout << contacts[j].darkest_secret_ << std::endl;
			}
			else
				std::cout << "Wrong index. Please, enter an index in range from 0 to " << size_ - 1 << std::endl;	
		}
		catch(std::invalid_argument)
		{
			std::cout << "Wrong index. Please, enter an index in range from 0 to " << size_ - 1 << std::endl;
		}
	}
}