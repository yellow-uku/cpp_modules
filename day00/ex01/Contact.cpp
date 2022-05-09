#include "Contact.hpp"

Contact::Contact(string	first_name,
				string	last_name,
				string	nickname,
				string	phone_number,
				string	darkest_secret):first_name(first_name), last_name(last_name), nickname(nickname), phone_number(phone_number), darkest_secret(darkest_secret)
				{
					std::cout << "Constructor called!" << std::endl;
				}
Contact::~Contact(void)
{
	std::cout << "Destructor called!" << std::endl;
}
