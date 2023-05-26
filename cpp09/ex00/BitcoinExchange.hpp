#ifndef BITCOIN_HPP
# define BITCOIN_HPP

#include <iostream>
#include <fstream>
#include <map>

#define DELIM ","
#define	SRC_FILENAME "data.csv"	

#include "Date.hpp"

class BitcoinExchange
{
	private:
		std::map<Date, float>	rawData;

	public:

		BitcoinExchange(std::string filename);
		BitcoinExchange(const BitcoinExchange &src);
        ~BitcoinExchange();
		
		void	processRawData();
		void	processInputData(std::string filename);
		
		bool	isExponent(std::string val);
		bool	isValidValue(std::string val);

	class InvalidFileException: public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
	class NotFloatValueException: public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
	class TooLargeValueException: public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
	class NotPositiveValueException: public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
	class InvalidValueException: public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
	class InvalidDateException: public std::exception
	{
		public:
			virtual const char* what() const throw();
	};	
};

#endif