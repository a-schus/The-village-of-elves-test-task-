#pragma once

#include <iostream>
#include <string>

const int treesCount = 5;
static int nextElvesName = 1; // используется для автоматического присвоения имени очередному эльфу
const int residentRatio = 2; // используется при "заселении" для определения будет ли кто-то жить на данной ветке


class Branch
{
	Branch* parent = nullptr;
	Branch** branches = nullptr;
	int branchesCount = 0;
	std::string nameOfResident = "none";

public:
	Branch(Branch* inParent = nullptr);
	Branch(int branchesCount, Branch* parent = nullptr);
	~Branch();

	void setParent(Branch* inParent = nullptr) { parent = inParent; }
	void setBranchesCount(int inBranchesCount) { branchesCount = inBranchesCount; }
	void setNameOfResident(std::string inNameOfResident) { nameOfResident = inNameOfResident; }
	void setBranch(int index, Branch* branch);

	Branch* getParent() { return parent; }
	int getBranchesCount() { return branchesCount; }
	Branch* getBranchAt(int index) { return branches[index]; }
	std::string getNameOfResident() { return nameOfResident; }
	void show(int index);

	Branch* findElf(std::string elvesName); // поиск эльфа по имени
	int numberOfNeighbors(); // подсчет соседей
};