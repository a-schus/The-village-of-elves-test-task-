#include "Elves.h"

Branch::Branch(Branch* inParent)
{
	parent = inParent;
	if (parent == nullptr) {
		branchesCount = rand() % 3 + 3;
	}
	else if (parent->parent == nullptr) {
		branchesCount = rand() % 2 + 2;
	}
	else {
		if ((rand() % residentRatio)) { // Заселяем (или нет) эльфа
			setNameOfResident(std::to_string(nextElvesName));
			++nextElvesName;
		}
		return;
	}
	
	if ((rand() % residentRatio)) { // Заселяем (или нет) эльфа
		setNameOfResident(std::to_string(nextElvesName));
		++nextElvesName;
	}
	branches = new Branch * [branchesCount];
	for (int i = 0; i < branchesCount; ++i) {
		branches[i] = new Branch(this);
	}
}

Branch::Branch(int inBranchesCount, Branch* inParent)
{
	branchesCount = inBranchesCount;
	branches = new Branch* [branchesCount];
	parent = inParent;
}

Branch::~Branch()
{
	for (int i = 0; i < branchesCount; ++i) {
		delete branches[i];
	}
	delete[] branches;
}

void Branch::setBranch(int index, Branch* branch)
{
	if (index >= 0 && index < branchesCount) {
		branches[index] = branch;
	}
}

void Branch::show(int index)
{
	if (parent == nullptr) {
		std::cout << "Tree " << index << " address: " << this << "\tparent: " << parent << '\n';
		for (int i = 0; i < branchesCount; ++i) {
			branches[i]->show(i);
		}

	}
	else if (parent->parent == nullptr) {
		std::cout << "\tBranch 0_" << index << " address: " << this
			<< "\tparent: " << parent 
			<< "\tName is " << nameOfResident << '\n';
		for (int i = 0; i < branchesCount; ++i) {
			branches[i]->show(i);
		}
	}
	else {
		std::cout << "\t\tBranch 1_" << index << " address: " << this
			<< "\tparent: " << getParent() 
			<< "\tName is " << nameOfResident << '\n';
	};
}

Branch* Branch::findElf(std::string elvesName)
{
	if (nameOfResident == elvesName) {
		return this;
	}
	for (int i = 0; i < branchesCount; ++i) {
		Branch* branch = branches[i]->findElf(elvesName);
		if (branch != nullptr) {
			return branch;
		}
	}
	return nullptr;
}

int Branch::numberOfNeighbors()
{
	// Если попытаться запустить объект из корневой ветви, метод вернет -1 и ничего считать не будет.
	// Проверка добавлена на всякий случай.
	if (parent == nullptr) {
		return -1;
	}
	int num = 0;

	// Чтобы подсчитать количество соседей, нужно запустить этот метод из большой ветви.
	// поэтому сначала проверяем где находится найденный эльф, и если это малая ветвь,
	// запускаем этот метод из предка.
	if (parent->getParent() != 0) {
		num = parent->numberOfNeighbors();

		// Если эльф на малой ветви и "выше" него никто не живет, нужно уменьшить счетчик на 1
		if (parent->getNameOfResident() == "none")
			--num;
	}
	else {
		// Если эльф на большой ветви, подсчитываем всех соседей "снизу"
		for (int i = 0; i < branchesCount; ++i) {
			if (branches[i]->getNameOfResident() != "none") {
				++num;
			}
		}
	}
	return num;
}
