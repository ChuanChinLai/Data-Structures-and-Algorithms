#pragma once

#include <chrono>
#include <iostream>
#include <cassert>
#include <algorithm>
#include <random>

class Timer
{
public:

	Timer()
	{
		start = std::chrono::steady_clock::now();
	}

	void Update()
	{
		auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start);
		std::cout << "Milliseconds: " << elapsed.count() << '\n';
		start = std::chrono::steady_clock::now();
	}


	std::chrono::steady_clock::time_point start;
};


void SortingTest(std::vector<int>& mySort, const std::vector<int>& STLSort)
{
	if (mySort.size() != STLSort.size())
		assert(false);


	int size = mySort.size();

	for (int i = 0; i < size; i++)
	{
		if(mySort[i] != STLSort[i])
			assert(false);
	}

	auto rng = std::default_random_engine{};
	std::shuffle(std::begin(mySort), std::end(mySort), rng);
}