#include "Sorter.h"

std::vector<std::vector<std::string>*>* Sorter::sort(TaskQueue queue, std::vector<std::string>* strVector, int threadCount)
{
	std::vector<std::vector<std::string>*>* partsVector = new std::vector<std::vector<std::string>*>();
	std::vector<std::string>* vec = new std::vector<std::string>;

	int count = floor((((double)strVector->size()) / threadCount) + .5);
	for (int i = 0; i < strVector->size(); i += count) 
	{
		vec = new std::vector<std::string>;
		partsVector->push_back(vec);
		
		for (int j = i; j < i + count; j++) 
		{
			if (j < strVector->size()) 
			{
				std::string str = (*strVector)[j];
				vec->push_back(str);
			}
		}

		queue.pushTask([vec](){ std::vector<std::string>* copy = vec; std::sort(vec->begin(), vec->end()); });
	}

	return partsVector;
}
