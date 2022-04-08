#ifndef CONTACTS_H
# define CONTACTS_H

# include <iostream>
# include <iomanip>
# include <string>

typedef std::string	string;

class Contacts
{
	private:
		string	first_name;
		string	last_name;
		string	nickname;
		string	phone_number;
		string	darkest_secret;
	public:
		Contact(string first_name,
				string last_name,
				string nickname,
				string phone_number,
				string darkest_secret);
		~Contact();

		int		index;
		bool	set_info();	// возвращает true, если контактов <= 8

		// Getters
		string  get_first_name()const;
		string  get_last_name()const;
		string  get_nickname()const;
		string  get_phone_number()const;
		string  get_darkest_secret()const;

};

#endif CONTACTS_H
