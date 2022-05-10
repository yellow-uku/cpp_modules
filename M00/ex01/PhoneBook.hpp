#ifndef __PHONEBOOK_H__
# define __PHONEBOOK_H__

# include "Contact.hpp"

class PhoneBook
{

	public:
		PhoneBook();

		void add_contact(const Contact &contact);
		void search_contact();

	private:
		Contact contacts[8];
		int	size_;
};
#endif