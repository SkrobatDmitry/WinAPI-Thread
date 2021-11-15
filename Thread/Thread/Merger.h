#pragma once
#include <vector>
#include <string>

class Merger
{
public:
	std::vector<std::string> mergeVectors(std::vector<std::vector<std::string>*>* partsVector);

private:
	std::vector<std::string> merge(std::vector<std::string> vec1, std::vector<std::string> vec2);
};

