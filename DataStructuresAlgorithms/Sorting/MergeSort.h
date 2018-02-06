#pragma once

#include <vector>
using namespace std;

void Merge(std::vector<int>& v, int head, int mid, int rear)
{
	int n1 = mid - head + 1;
	int n2 = rear - mid;

	vector<int> v1(n1);
	vector<int> v2(n2);

	int i = 0;
	int j = 0;

	for (; i < n1; i++)
	{
		v1[i] = v[head + i];
	}

	for (; j < n2; j++)
	{
		v2[j] = v[mid + 1 + j];
	}

	int k = head;

	i = j = 0;


	while (i < n1 && j < n2)
	{
		if (v1[i] < v2[j])
			v[k++] = v1[i++];
		else
			v[k++] = v2[j++];
	}

	while (i < n1)
	{
		v[k++] = v1[i++];
	}

	while (j < n2)
	{
		v[k++] = v2[j++];
	}
}


void MergeSort(std::vector<int>& v, int head, int rear)
{
	if (head >= rear)
		return;


	int mid = (head + rear) >> 1;

	MergeSort(v, head, mid);
	MergeSort(v, mid + 1, rear);

	Merge(v, head, mid, rear);
}


void MergeSort(std::vector<int>& v)
{
	MergeSort(v, 0, v.size() - 1);
}
