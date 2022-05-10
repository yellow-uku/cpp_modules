#include "PhoneBook.hpp"
#include "Contact.hpp"

int main(int argc, char **argv)
{
	std::string command;
	PhoneBook	phonebook;

	while(true)
	{
		std::cout << "Please, enter a command (ADD, SEARCH or EXIT):" << std::endl;
		std::cin >> command;
		if (command == "EXIT")
			return (0);
		if (command == "ADD" || command == "SEARCH")
		{
			Contact	contact;
			if (command == "ADD")
			{
				std::cout << "Enter first_name: ";
				std::cin >> contact.first_name_;
				std::cout << "Enter last_name: ";
				std::cin >> contact.last_name_;
				std::cout << "Enter nickname: ";
				std::cin >> contact.nickname_;
				std::cout << "Enter phone_number: ";
				std::cin >> contact.phone_number_;
				std::cout << "Enter darkest_secret: ";
				std::cin >> contact.darkest_secret_;

				phonebook.add_contact(contact);
				std::cout << std::endl;
			}
			else if (command == "SEARCH")
				phonebook.search_contact();
		}
		else
		{
			std::cout << "Error: Command doesn't exist." << std::endl;
			std::cout << std::endl;
		}
	}
}
