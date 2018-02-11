#include "Heap.h"

#include <queue>
#include <cassert>

int main(int argc, char* argv[])
{
	priority_queue<int> pq;
	Heap heap;

	for (int i = 0; i < 10000; i++)
	{
		int key = rand() & INT_MAX;
		pq.push(key);
		heap.push(key);
	}

	while (!pq.empty())
	{
		assert(pq.top() == heap.m_heap[0]);

		pq.pop();
		heap.pop();
	}

	return 0;
}