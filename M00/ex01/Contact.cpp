#include "Contact.hpp"

Contact::Contact(){}

string Contact::get_first_name()const {return this->first_name_;};
string Contact::get_last_name()const {return this->last_name_;};
string Contact::get_nickname()const {return this->nickname_;};
string Contact::get_phone_number()const {return this->phone_number_;};
string Contact::get_darkest_secret()const {return this->darkest_secret_;};

bool	Contact::is_empty()const
{
	if (this->first_name_.empty() || this->last_name_.empty() || this->nickname_.empty() ||
		this->phone_number_.empty() || this->darkest_secret_.empty())
		return true;
	else return false;
}
