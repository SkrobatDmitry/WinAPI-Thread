#include <vector>
#include <string>
#include <fstream>
#include <iostream>

#include "Sorter.h"
#include "Merger.h"
#include "TaskQueue.h"
#include "Handler.h"

#define FILE_INPUT "input.txt"
#define FILE_OUTPUT "output.txt"

std::vector<std::string>* getFile(std::vector<std::string>* vec)
{
	std::ifstream inputFile(FILE_INPUT);
	std::string line;

	while (std::getline(inputFile, line))
	{
		if (line.size() != 0)
			vec->push_back(line);
	}

	return vec;
}

void outputVector(std::vector<std::string> vec)
{
	std::ofstream stream(FILE_OUTPUT);
	for (std::string str : vec)
	{
		str += "\n";
		const char* cstr = str.c_str();

		std::cout << cstr;
		stream.write(cstr, strlen(cstr));
	}

	stream.close();
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
	std::cout << "\n";
	threadCount = threadCount > strVector->size() ? strVector->size() : threadCount;

	Sorter sorter;
	TaskQueue taskQueue;

	Handler handler(taskQueue, threadCount);
	Merger merger;

	std::vector<std::vector<std::string>*>* partsVector = sorter.sort(taskQueue, strVector, threadCount);
	handler.startProcessing();

	std::vector<std::string> vec = merger.mergeVectors(partsVector);
	outputVector(vec);

	return 0;
}
