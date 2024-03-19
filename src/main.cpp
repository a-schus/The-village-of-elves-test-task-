#include "Elves.h"
#include <ctime>

int main()
{
	srand(time(NULL));
	Branch** tree = nullptr;
	tree = new Branch * [treesCount];
	
	for (int i = 0; i < treesCount; ++i) {
		tree[i] = new Branch();
	}

	for (int i = 0; i < treesCount; ++i) {
		tree[i]->show(i);
	}

	// Находим нужного эльфа
	std::cout << "Enter Elf's name: ";
	std::string eName;
	std::cin >> eName;
	Branch* elfAddress = nullptr;
	for (int i = 0; i < treesCount; ++i) {
		elfAddress = tree[i]->findElf(eName);
		if (elfAddress != nullptr) {
			break;
		}
	}

	// Если эльф найден, подсчитываем его соседей по большой ветке
	if (elfAddress == nullptr) {
		std::cout << "There is no such elf.\n";
	}
	else {
		std::cout << "Address: " << elfAddress << '\n';
		std::cout << "Number of neighbors: " << elfAddress->numberOfNeighbors() << '\n';
	}

	// Освобождаем память
	for (int i = 0; i < treesCount; ++i) {
		delete tree[i];
	}
	delete[] tree;

	return 0;
}