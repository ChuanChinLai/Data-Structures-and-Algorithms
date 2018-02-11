#pragma once

#include <vector>
using namespace std;

int BinarySearch(const vector<int>& v, int num, int head, int rear)
{
	if (head > rear)
		return - 1;

	int mid = head + ((rear - head) >> 1);

	if (num == v[mid])
		return mid;

	if (num > v[mid])
		return BinarySearch(v, num, mid + 1, rear);

	if (num < v[mid])
		return BinarySearch(v, num, head, mid - 1);

	return -1;
}