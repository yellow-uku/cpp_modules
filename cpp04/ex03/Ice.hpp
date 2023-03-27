#ifndef __ICE_H__
# define __ICE_H__

class AMateria;

class Ice
{
    public:
        Ice() {};
        ~Ice() {};
        AMateria* clone() const;
};

#endif