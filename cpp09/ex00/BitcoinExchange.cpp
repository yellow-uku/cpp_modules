#include "BitcoinExchange.hpp"
#include "Date.hpp"

BitcoinExchange::BitcoinExchange(std::string filename)
{

	processRawData();
	processInputData(filename);
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) 
				: rawData(src.rawData) {}

void	BitcoinExchange::processRawData()
{
	std::ifstream   src_file;

	std::string	line;
	std::string	str_date;
	std::string	str_val;
	
	src_file.open(SRC_FILENAME);

	std::getline(src_file, line);

	while(std::getline(src_file, line))
	{
		str_date = line.substr(0, line.find(DELIM));
		Date	date(str_date);
		str_val = line.substr(line.find(DELIM) + 1, line.find("\n"));
		
		if (str_date[0] && str_val[0])
		{
			float	float_val = std::atof(str_val.c_str());
			std::pair<Date, float> pair(date, float_val);
			rawData.insert(pair);	
		}
		else
		{
			std::cout << "Empty value in database. Skipping.\n";
		}
	}
}

void	BitcoinExchange::processInputData(std::string filename)
{
	std::ifstream	input;
	std::string		line;
	std::string		str_date;
	std::string		str_val;

	input.open(filename);


	// check 1st line
	std::getline(input, line);

	str_date = line.substr(0, line.find("|"));
	str_val = line.substr(line.find('|') + 1, line.find("\n"));

	Date::eraseWhitespaces(str_date);
	Date::eraseWhitespaces(str_val);

	if (str_date != "date" || str_val != "value")
		std::cout << "Error: it must be date | value format.\n";

	while (std::getline(input, line))
	{
		try
		{
			str_date = line.substr(0, line.find("|"));
			Date	date(str_date);
			str_val = line.substr(line.find('|') + 1, line.find("\n"));

			if (isValidValue(str_val) )
			{
				float val = std::atof(str_val.c_str());
				
				std::map<Date, float>::iterator	it = rawData.lower_bound(date);
				if (date != it->first)
				{
					if (it == rawData.begin())
						throw InvalidDateException();
					--it;
				}
				date.printDate();
				std::cout << " => " << val << " = " << val * it->second << "\n";
			}
			else
				throw NotFloatValueException();
		}
		catch(const std::exception& e)
		{
			std::cout << "Bad Input: " << e.what() << '\n';
		}
	}
}

bool	BitcoinExchange::isValidValue(std::string text)
{
	Date::eraseWhitespaces(text);

	if (text == "0" || text == "0.0")
		return true;
	if (text.find("e") != std::string::npos || text.find("E") != std::string::npos)
		return (isExponent(text));
	else if (!std::atof(text.c_str())
			|| std::atof(text.c_str()) > 1000)
		throw InvalidValueException();
	else if (std::atof(text.c_str()) < 0)
		throw NotPositiveValueException();
	else if (text.find(".") != std::string::npos)
	{
		if (text.find_first_of(".") == text.find_last_of("."))
		{
			std::string beforeDot = text.substr(0, text.find("."));
			std::string afterDot = text.substr(text.find(".") + 1);
			return (std::atof(text.c_str())
				&& Date::isInteger(beforeDot) && Date::isInteger(afterDot));
		}
		else
			throw NotFloatValueException();
	}
	else if (!Date::isInteger(text))
		throw InvalidValueException();
	return true;
}

bool	BitcoinExchange::isExponent(std::string val)
{

	if (std::atof(val.c_str())
		&& (val.find("+") != std::string::npos || val.find("-") != std::string::npos))
	{
		// cast "E" -> "e" (to deal only with "e")
		if (val.find("E") != std::string::npos)
			val[val.find("E")] = std::tolower(val[val.find("E")]);

		std::string	before_e = val.substr(0, val.find("e"));
		if (!Date::isInteger(before_e))
			return false;
		// avoid "+"
		std::string	after_e = val.substr(val.find("e") + 2);
		if (!Date::isInteger(after_e))
			return false;
	}
	else
		return false;
	return true;
}


const char* BitcoinExchange::InvalidFileException::what() const throw()
{
	return "Invalid file.";
}

const char* BitcoinExchange::NotFloatValueException::what() const throw()
{
	return "Invalid value - it must be float or integer.";
}

const char* BitcoinExchange::TooLargeValueException::what() const throw()
{
	return "Invalid value - too large number.";
}

const char* BitcoinExchange::NotPositiveValueException::what() const throw()
{
	return "Invalid value - not positive integer or float.";
}

const char* BitcoinExchange::InvalidValueException::what() const throw()
{
	return "Invalid value - it must be in range from 0 to 1000.";
}

const char* BitcoinExchange::InvalidDateException::what() const throw()
{
	return "Invalid date - it's older then the lowest one in database.";
}