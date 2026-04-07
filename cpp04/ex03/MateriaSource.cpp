#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
    this->Name = "\0";
    for (int i = 0; i < 4; i++)
        this->Materias[i] = NULL; 
}

MateriaSource::MateriaSource(std::string nm) {
    this->Name = nm;
    for (int i = 0; i < 4; i++)
        this->Materias[i] = NULL; 
}

MateriaSource &MateriaSource::operator=(const MateriaSource &src) {
    if(this != &src)
    {
        this->Name = src.Name;
        for (int i = 0; i < 4; i++)
        {
            if (this->Materias[i])
            {
                delete this->Materias[i];
                this->Materias[i] = NULL;
            }
            if (src.Materias[i])
                this->Materias[i] = src.Materias[i]->clone();
        }
    }
    return *this;
}

MateriaSource::MateriaSource(const MateriaSource &copy) {
	*this = copy;
}

MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; i++)
    {
        delete Materias[i];
        Materias[i] = NULL;
    }
}

void MateriaSource::learnMateria(AMateria* M) {
    for (int i = 0; i < 4; i++)
    {
        if (!Materias[i])
        {
            Materias[i] = M;
            return ;
        }
    }
    delete M;
    M = NULL;
    std::cout << "Materia Source is full, cannot learn more Materia!" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (size_t i = 0; i < 4; i++)
    {
        if (this->Materias[i] && this->Materias[i]->getType() == type)
            return (this->Materias[i]->clone());
    }
    return 0;
}