#pragma once
#include <vector>
#include <string>
#include "TaskQueue.h"

class Sorter
{
public:
	std::vector<std::vector<std::string>*>* sort(TaskQueue queue, std::vector<std::string>* strVector, int threadCount);
};

