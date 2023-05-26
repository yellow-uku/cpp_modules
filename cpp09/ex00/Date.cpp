#include "Date.hpp"

Date::Date() { }

Date::~Date() { }

Date::Date(std::string raw_text)
{
	if (isValidRawDate(raw_text))
		// check format yyyy-mm-dd
		formatRawDate(raw_text);
	else
		throw InvalidDateFormatException();
}

Date::Date(const Date &src)
		: year(src.year), month(src.month), day(src.day) { }

bool	Date::isValidRawDate(std::string raw_text)
{
	std::string	last;
	// check for "-"
	if (raw_text.find("-") == std::string::npos)
		return false;
	else
	{
		last = raw_text.substr(raw_text.find("-") + 1);
		if (last.find("-") == std::string::npos)
			return false;
		else
		{
			// check count of "-"
			std::string	sub_last = last.substr(last.find("-") + 1);
			if (sub_last.find("-") != std::string::npos)
				return false;
		}
	}
	return true;
}

void	Date::formatRawDate(std::string& raw_text)
{
	eraseWhitespaces(raw_text);

	// extract y,m,d strings
	std::string str_y = raw_text.substr(0, raw_text.find("-"));
	std::string last_y = raw_text.substr(raw_text.find("-") + 1);
	std::string	str_m = last_y.substr(0, last_y.find("-"));
	std::string str_d = last_y.substr(last_y.find("-") + 1);

	if (str_y.size() != 4 || str_m.size() != 2 || str_d.size() != 2)
		throw InvalidDateFormatException();
	else
	{
		// check if y,m,d can be number
		if (isInteger(str_y) && isInteger(str_m) && isInteger(str_d))
		{
			int y = std::atoi(str_y.c_str());
			int m = std::atoi(str_m.c_str());
			int d = std::atoi(str_d.c_str());
			if (isValidDate(y, m, d))
			{
				year = y;
				month = m;
				day = d;
			}
			else
				throw InvalidDateValue();
		}
		else
			throw NotNumberDateException();
	}
}

void	Date::eraseWhitespaces(std::string& text)
{
	const char*	whitespaces = " \t\n\r\f\v";

	// get rid of whitespaces (trim left and right)
	text.erase(text.find_last_not_of(whitespaces) + 1);
	text.erase(0, text.find_first_not_of(whitespaces));
}

bool	Date::isInteger(std::string& formatted_text)
{
	std::string::const_iterator it = formatted_text.begin();
	while (it != formatted_text.end() && std::isdigit(*it))
		++it;

	return (!formatted_text.empty() && it == formatted_text.end());
}

bool	Date::isValidDate(int y, int m, int d)
{
	// bitcoin was first launched in 2009, you know?
	if (y <= 2008 || m <= 0 || m > 12 || d <= 0)
		return false;

	int isLongMonth = !(m == 4 || m == 6 || m == 9 || m == 11);

	//check for leap year
	if (m == 2)
	{
		int	isLeapYear = (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0));
		if (d > 28 + isLeapYear)
            return false;
	}
	// check for day counts
	else if (d > 30 + isLongMonth)
		return false;
	return true;
}

Date    Date::operator=(const Date &rhs)
{
    if (this != &rhs)
    {
        year = rhs.year;
        month = rhs.month;
        day = rhs.day;
    }
    return (*this);
}

bool    Date::operator<(const Date &rhs) const
{
    if (year < rhs.year)
        return (true);
    else if (year == rhs.year)
    {
        if (month < rhs.month)
            return true;
        else if (month == rhs.month)
            return (day < rhs.day);
    }
    return (false);
}

bool    Date::operator==(const Date &rhs) const
{
    return (year == rhs.year && month == rhs.month && day == rhs.day);
}

bool    Date::operator!=(const Date &rhs) const
{
    return !(*this == rhs);
}

void	Date::printDate() const
{
	if (month < 10)
		std::cout << year << "-0" << month;
	else
		std::cout << year << "-" << month;
	if (day < 10)
		std::cout << "-0" << day;
	else
		std::cout << '-' << day;
}

const char* Date::InvalidDateFormatException::what() const throw()
{
	return "Invalid date format.";
}

const char* Date::NotNumberDateException::what() const throw()
{
	return "This date can't be represented with integers.";
}

const char* Date::InvalidDateValue::what() const throw()
{
	return "This date doesn't exist.";
}