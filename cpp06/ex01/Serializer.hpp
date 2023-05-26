#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>

typedef struct Data {
	int			int_obj;
	double		double_obj;
	std::string	str_obj;
} Data;

class	Serializer
{
	private:
		Serializer(void);
		Serializer(Serializer const &);
		Serializer	&operator=(Serializer const &);
		~Serializer(void);
	
	public:
		static uintptr_t	serialize(Data *);
		static Data*		deserialize(uintptr_t);
};

#endif