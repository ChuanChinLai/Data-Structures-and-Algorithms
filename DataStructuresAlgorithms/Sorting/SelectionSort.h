#pragma once

#include <vector>

void SelectionSort(std::vector<int>& v)
{
	for (int i = 0; i < v.size(); i++)
	{
		int min = i;

		for (int j = i + 1; j < v.size(); j++)
		{
			if (v[j] < v[min])
				min = j;
		}


		if (min != i)
			std::swap(v[min], v[i]);
	}
}
