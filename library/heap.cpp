/*
 * heap.cpp
 *
 *  Created on: Jun 9, 2018
 *      Author: Robert Phillips III
 */

template <typename T>
heap<T>::heap(Strategy strategy)
	: data_structure<T>(),
	  m_strategy(strategy)
{

}

template <typename T>
heap<T>::~heap()
{

}

template <typename T>
void heap<T>::swap(uint64_t index1, uint64_t index2)
{
	__check(index1);
	__check(index2);

	T temp = m_tree[index1];
	m_tree[index1] = m_tree[index2];
	m_tree[index2] = temp;
}

template <typename T>
void heap<T>::add(const T & value)
{
	m_tree.append(value);

	constrain();
}

template <typename T>
void heap<T>::constrain()
{
	uint64_t index = m_tree.size() - 1;

	uint64_t pIndex = parent(index);
	while (pIndex > 0) {
		if ((m_strategy == HEAP_MIN) && (m_tree[index] >= m_tree[pIndex])) {
			break;
		}

		if ((m_strategy == HEAP_MAX) && (m_tree[index] <= m_tree[pIndex])) {
			break;
		}

		swap(index, pIndex);

		index  = pIndex;
		pIndex = parent(index);
	}
}

template <typename T>
uint64_t heap<T>::indexOf(const T & value, bool & found) const
{
	uint64_t size = m_tree.size();

	found = false;

	if (m_tree.at(0) == value) {
		return 0;
	} else if ((m_strategy == HEAP_MIN) && (value < m_tree.at(0))) {
		return 0;
	} else if ((m_strategy == HEAP_MAX) && (value > m_tree.at(0))) {
		return 0;
	}

	int nodes = 2;

	uint64_t current = 1;
	while (current < size) {
		bool possible = false;

		for (int i = 0; i < nodes; i++) {
			uint64_t index = current + i;

			if (index == size) { return 0; }

			if (m_tree.at(index) == value) {
				found = true;

				return index;
			}

			uint64_t pIndex = parent(index);
			if (m_strategy == HEAP_MIN) {
				possible |= !((value > m_tree.at(pIndex)) && (value < m_tree.at(index)));
			} else {
				possible |= !((value < m_tree.at(pIndex)) && (value > m_tree.at(index)));
			}
		}

		if (!possible) { return 0; }

		nodes *= 2;
	}

	return 0;
}

template <typename T>
T *heap<T>::find(const T & value) const
{
	bool found;
	uint64_t index = indexOf(value, found);

	return (found) ? &m_tree.lookup(index) : nullptr;
}

template <typename T>
bool heap<T>::broken(uint64_t index) const
{
	uint64_t lIndex = left(index);
	uint64_t rIndex = right(index);

	uint64_t size = m_tree.size();
	if (lIndex >= size) {
		return false;
	}

	if (m_strategy == HEAP_MIN) {
		return ((m_tree.at(index) > m_tree.at(lIndex)) || (m_tree.at(index) > m_tree.at(rIndex)));
	} else {
		return ((m_tree.at(index) < m_tree.at(lIndex)) || (m_tree.at(index) < m_tree.at(rIndex)));
	}
}

template <typename T>
bool heap<T>::remove(const T & value)
{
	bool found;
	uint64_t index = indexOf(value, found);
	if (!found) {
		return false;
	}

	T back = m_tree.pop_back();

	uint64_t lIndex = left(index);
	uint64_t rIndex = right(index);

	m_tree[index] = back;

	while (broken(index)) {
		uint64_t sIndex;

		if (m_strategy == HEAP_MIN) {
			sIndex = (m_tree[lIndex] < m_tree[rIndex]) ? lIndex : rIndex;
		} else {
			sIndex = (m_tree[lIndex] > m_tree[rIndex]) ? lIndex : rIndex;
		}

		swap(index, sIndex);

		index  = sIndex;
		lIndex = left(index);
		rIndex = right(index);
	}

	return true;
}
