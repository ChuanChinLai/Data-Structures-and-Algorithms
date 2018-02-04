#include "BubbleSort.h"
#include "SelectionSort.h"
#include "InsertSort.h"
#include "Tool.h"

#include <stdio.h>
#include <iostream>
#include <vector>


int main(int argc, char* argv[])
{
	std::vector<int> mySort;
	std::vector<int> STLSort;

	for (int i = 0; i < 1000; i++)
	{
		mySort.push_back(rand() & INT_MAX);
	}

	STLSort = mySort;

	std::sort(STLSort.begin(), STLSort.end());


	Timer T;

	BubbleSort(mySort);	
	SortingTest(mySort, STLSort);
	T.Update();
	std::cout << "B" << std::endl;

	SelectionSort(mySort);
	SortingTest(mySort, STLSort);
	T.Update();
	std::cout << "S" << std::endl;


	InsertSort(mySort);
	SortingTest(mySort, STLSort);
	T.Update();
	std::cout << "I" << std::endl;

	std::cout << "sort" << std::endl;


	system("Pause");
	return 0;
}