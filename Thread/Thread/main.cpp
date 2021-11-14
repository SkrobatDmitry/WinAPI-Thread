#include <vector>
#include <string>
#include <fstream>
#include <iostream>

#define FILE_NAME "input.txt"

std::vector<std::string>* getFile(std::vector<std::string>* vec)
{
	std::ifstream inputFile(FILE_NAME);
	std::string line;

	while (std::getline(inputFile, line))
	{
		if (line.size() != 0)
			vec->push_back(line);
	}

	return vec;
}

int main()
{
	int threadCount;
	std::vector<std::string>* strVector = new std::vector<std::string>();

	strVector = getFile(strVector);
	if (strVector->empty()) {
		std::cout << "The file doesn't exist or is empty\n";
		return -1;
	}

	std::cout << "Thread count: ";
	std::cin >> threadCount;
	threadCount = threadCount > strVector->size() ? strVector->size() : threadCount;

	// Sort

	return 0;
}
