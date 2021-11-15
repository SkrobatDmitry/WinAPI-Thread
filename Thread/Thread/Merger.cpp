#include "Merger.h"

std::vector<std::string> Merger::mergeVectors(std::vector<std::vector<std::string>*>* partsVector)
{
	std::vector<std::string> vec;
	if (partsVector->size() > 0) 
	{
		vec = *(*partsVector)[0];
	}

	for (int i = 1; i < partsVector->size(); i++) 
	{
		vec = merge(vec, *(*partsVector)[i]);
	}
	return vec;
}

std::vector<std::string> Merger::merge(std::vector<std::string> vec1, std::vector<std::string> vec2)
{
	int vec1_size = vec1.size(); 
	int vec2_size = vec2.size();
 
	std::vector<std::string> vec;
	vec.reserve(vec1_size + vec2_size);

	int i = 0, j = 0;
	while (i < vec1_size && j < vec2_size) 
	{
		if (vec1[i] <= vec2[j])
		{
			vec.push_back(vec1[i++]);
		}
		else
		{
			vec.push_back(vec2[j++]);
		}
	}
 
	while (i < vec1_size)
	{
		vec.push_back(vec1[i++]);
	}
	while (j < vec2_size)
	{
		vec.push_back(vec2[j++]);
	}

	return vec;
}
