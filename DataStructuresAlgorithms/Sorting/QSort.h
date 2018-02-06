#pragma once

#include <vector>

using namespace std;


int Partition(std::vector<int>& v, int head, int rear)
{
	int pivot = v[rear];

	int current_idx = head;

	for (int i = head; i < rear; i++)
	{
		if (v[i] < pivot)
		{
			swap(v[i], v[current_idx++]);
		}
	}

	swap(v[current_idx], v[rear]);

	return current_idx;
}

void QSort(std::vector<int>& v, int head, int rear)
{
	if (head >= rear)
		return;

	int pivot = Partition(v, head, rear);

	QSort(v, head, pivot - 1);
	QSort(v, pivot + 1, rear);
}

void QSort(std::vector<int>& v)
{
	QSort(v, 0, v.size() - 1);
}