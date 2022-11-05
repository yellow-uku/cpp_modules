#ifndef __CONTACT_H__
# define __CONTACT_H__

# include <iostream>
# include <iomanip>
# include <string>

typedef std::string	string;

class Contact
{
	public:
		string	first_name_;
		string	last_name_;
		string	nickname_;
		string	phone_number_;
		string	darkest_secret_;

		Contact();

		bool	is_empty()const;	// возвращает true, если хотя бы одно поле контакта - пустое

		// getters
		string  get_first_name()const;
		string  get_last_name()const;
		string  get_nickname()const;
		string  get_phone_number()const;
		string  get_darkest_secret()const;
};

#endif