#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <limits>

enum inputType {
    normal, //int char float double
    negInf, //-inf -inff
    posInf, //+inf +inff
    nan     //nan nanf
};

class ScalarConverter {
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &);
        ~ScalarConverter();
        ScalarConverter & operator=(const ScalarConverter &);

        static  inputType       _inputType;
        static  bool            _hasQuote;

        static  void    checkInfinity(const std::string &);
        static  bool    checkExponent(const std::string &);
        static  bool    checkQuote(const std::string &);
        static  bool    checkParse(const std::string &);

    public:
        static  char    convertToChar(const std::string &);
        static  int     convertToInt(const std::string &);
        static  float   convertToFloat(const std::string &);
        static  double  convertToDouble(const std::string &);

        static  bool    printChar(const std::string &);
        static  bool    printInt(const std::string &);
        static  bool    printFloat(const std::string &);
        static  bool    printDouble(const std::string &);
        static  bool    convertAll(const std::string &);


        class  DataIsNotDigit: public std::exception {
                public:
                    virtual const char * what( void ) const throw();
        };

        class  ImpossiblePrint: public std::exception {
                public:
                    virtual const char * what( void ) const throw();
        };

        class  NonPrintableChar : public std::exception {
                public:
                    virtual const char * what( void ) const throw();
        };

        class  OpenQuotes : public std::exception {
                public:
                    virtual const char * what( void ) const throw();
        };

        class  InvalidChar: public std::exception {
                public:
                    virtual const char * what( void ) const throw();
        };

        class  NumberOutsideRange : public std::exception {
                public:
                    virtual const char * what( void ) const throw();
        };
};

#endif