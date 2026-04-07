#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		std::string Name;
		AMateria* Materias[4];
	public:
	MateriaSource();
	MateriaSource(std::string nm);
	MateriaSource(const MateriaSource &copy);
	MateriaSource &operator=(const MateriaSource &src);
	~MateriaSource();
	void learnMateria(AMateria* M);
	AMateria* createMateria(std::string const & type);
};
