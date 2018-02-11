
#include "../Tool/Tool.h"
#include "BinarySearch.h"

#include <vector>
#include <cassert>
#include <algorithm>

int main(int argc, char* argv[])
{
	std::vector<int> mySort;
	std::vector<int> STLSort;

	for (int i = 0; i < 1000; i++)
	{
		mySort.push_back(rand() & INT_MAX);
	}

	STLSort = mySort;
	std::sort(mySort.begin(), mySort.end());
	std::sort(STLSort.begin(), STLSort.end());

	Timer T;

	for (int i = 0; i < mySort.size(); i++)
	{
		int index = BinarySearch(mySort, STLSort[i], 0, mySort.size() - 1);

		if (index != i)
		{
			std::cout << index << " " << i << std::endl;
			assert(mySort[index] == STLSort[i]);
		}
	}


	system("Pause");
	return 0;
}