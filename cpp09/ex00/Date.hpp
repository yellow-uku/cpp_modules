#ifndef DATE_HPP
# define DATE_HPP

#include <iostream>
#include <sstream>
// #include "BitcoinExchange.hpp"

class BitcoinExchange;
class Date
{
	private:
		int  year;
		int  month;
		int  day;

	public:

		Date();
		Date(std::string raw_text);
		Date(const Date &src);
		~Date();

		void	formatRawDate(std::string& raw_text);
		void	printDate() const;
		static void	eraseWhitespaces(std::string& text);
	
		bool	isValidRawDate(std::string raw_text);
		bool	isValidDate(int y, int m, int d);
		static bool	isInteger(std::string& formatted_text);

		Date    operator=(const Date &rhs);
		bool    operator<(const Date &rhs) const;
		bool    operator==(const Date &rhs) const;
		bool    operator!=(const Date &rhs) const;

		class InvalidDateFormatException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class NotNumberDateException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class InvalidDateValue: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};



#endif