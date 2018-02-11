#pragma once

#include <vector>
using namespace std;

class Heap
{
public:

	void push(int num)
	{
		m_heap.push_back(num);

		int index = m_heap.size() - 1;

		int parentIdx = (index - 1) >> 1;

		while (index > 0 && num > m_heap[parentIdx])
		{
			m_heap[index] = m_heap[parentIdx];
			index = parentIdx;
			parentIdx = (parentIdx - 1) >> 1;
		}

		m_heap[index] = num;
	};

	void pop() 
	{
		if (m_heap.size() == 0)
			return;

		int index = 0;
		int tmp = m_heap.back();
		m_heap[index] = tmp;
		m_heap.pop_back();

		int potentialIdx = 0;

		while (index < m_heap.size() / 2)
		{
			int L = index * 2 + 1;
			int R = L + 1;

			if (R < m_heap.size() && m_heap[R] > m_heap[L])
			{
				potentialIdx = R;
			}
			else
			{
				potentialIdx = L;
			}


			if (tmp > m_heap[potentialIdx])
				break;


			m_heap[index] = m_heap[potentialIdx];
			index = potentialIdx;
		}

		if (m_heap.size() != 0)
			m_heap[index] = tmp;
	}


	vector<int> m_heap;
};
