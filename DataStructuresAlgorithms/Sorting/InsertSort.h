#pragma once

#include <vector>


void InsertSort(std::vector<int>& v)
{
	for (int i = 1; i < v.size(); i++)
	{
		int tmp = v[i];
		int min_idx = i;


		while (min_idx > 0 && v[min_idx - 1] > tmp)
		{
			v[min_idx] = v[min_idx - 1];

			min_idx--;
		}


		v[min_idx] = tmp;
	}
}