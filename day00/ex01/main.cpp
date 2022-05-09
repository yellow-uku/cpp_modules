#include "PhoneBook.hpp"
#include "Contact.hpp"

int main(int argc, char **argv)
{
	const char* command;
	command = argv[1];

	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;
	Contact new_contact;

	if (!strcmp(command, "ADD")){
		std::cout << "Enter first_name: ";
		std::cin >> first_name;
		std::cout << "Enter last_name: ";
		std::cin >> last_name;
		std::cout << std::endl;
		std::cout << "Enter nickname: ";
		std::cin >> nickname;
		std::cout << std::endl;
		std::cout << "Enter phone_number: ";
		std::cin >> phone_number;
		std::cout << std::endl;
		std::cout << "Enter darkest_secret: ";
		std::cin >> darkest_secret;
		std::cout << std::endl;
		new_contact = Contact(first_name, last_name, nickname, phone_number, darkest_secret);
		std::cout << new_contact.first_name << std::endl;
	}
	else
		std::cout << "Can't add" << std::endl;
	return 0;
}

/*
ADD:
first_name: <>\n
last_name: <>\n
nickname: <>\n
phone_number: <>\n
darkest_secret: <>\n
*/