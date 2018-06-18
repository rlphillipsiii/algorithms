/*
 * heap.cpp
 *
 *  Created on: Jun 9, 2018
 *      Author: Robert Phillips III
 */


template <typename T>
const int heap<T>::VALUE_NOT_FOUND = -1;

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
void heap<T>::swap(int index1, int index2)
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
	uint32_t index = m_tree.size() - 1;

	int pIndex = parent(index);
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
int heap<T>::indexOf(const T & value) const
{
	int size = m_tree.size();

	if (m_tree.at(0) == value) {
		return 0;
	} else if ((m_strategy == HEAP_MIN) && (value < m_tree.at(0))) {
		return VALUE_NOT_FOUND;
	} else if ((m_strategy == HEAP_MAX) && (value > m_tree.at(0))) {
		return VALUE_NOT_FOUND;
	}

	int nodes = 2;

	int current = 1;
	while (current < size) {
		bool possible = false;

		for (int i = 0; i < nodes; i++) {
			int index = current + i;

			if (index == size) { return VALUE_NOT_FOUND; }

			if (m_tree.at(index) == value) {
				return index;
			}

			int pIndex = parent(index);
			if (m_strategy == HEAP_MIN) {
				possible |= !((value > m_tree.at(pIndex)) && (value < m_tree.at(index)));
			} else {
				possible |= !((value < m_tree.at(pIndex)) && (value > m_tree.at(index)));
			}
		}

		if (!possible) { return VALUE_NOT_FOUND; }

		nodes *= 2;
	}

	return VALUE_NOT_FOUND;
}

template <typename T>
T *heap<T>::find(const T & value) const
{
	int index = indexOf(value);

	return (index == VALUE_NOT_FOUND) ? nullptr : &m_tree.lookup(index);
}

template <typename T>
bool heap<T>::broken(int index)
{
	int lIndex = left(index);
	int rIndex = right(index);

	int size = m_tree.size();
	if (lIndex >= size) {
		return false;
	}

	if (m_strategy == HEAP_MIN) {
		return ((m_tree[index] > m_tree[lIndex]) || (m_tree[index] > m_tree[rIndex]));
	} else {
		return ((m_tree[index] < m_tree[lIndex]) || (m_tree[index] < m_tree[rIndex]));
	}
}

template <typename T>
bool heap<T>::remove(const T & value)
{
	int index = indexOf(value);
	if (index == VALUE_NOT_FOUND) {
		return false;
	}

	T back = m_tree.pop_back();

	int lIndex = left(index);
	int rIndex = right(index);

	m_tree[index] = back;

	while (broken(index)) {
		int sIndex;

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
