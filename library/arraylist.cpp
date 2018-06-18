/*
 * arraylist.cpp
 *
 *  Created on: Jun 9, 2018
 *      Author: Robert Phillips III
 */

template <typename T>
array_list<T>::array_list(uint64_t capacity)
	: m_capacity(capacity)
{
	m_storage = new T[m_capacity];
}


template <typename T>
array_list<T>::~array_list()
{
	delete [] m_storage;
}

template <typename T>
T *array_list<T>::data() const
{
	return m_storage;
}

template <typename T>
T & array_list<T>::operator[](int index)
{
	__check(index);

	return m_storage[index];
}

template <typename T>
const T & array_list<T>::at(int index) const
{
	__check(index);

	return m_storage[index];
}

template <typename T>
T array_list<T>::get(int index) const
{
	__check(index);

	return m_storage[index];
}

template <typename T>
T & array_list<T>::lookup(int index) const
{
	__check(index);

	return m_storage[index];
}

template <typename T>
void array_list<T>::append(const T & value)
{
	__m_size++;

	if (m_capacity < __m_size) {
		m_capacity *= 2;

		T *temp = m_storage;

		m_storage = new T[m_capacity];
		for (uint64_t i = 0; i < __m_size - 1; i++) {
			m_storage[i] = temp[i];
		}

		delete [] temp;
	}

	m_storage[__m_size - 1] = value;
}

template <typename T>
T array_list<T>::pop_back()
{
	__check();

	uint32_t index = __m_size - 1;

	T value = m_storage[index];
	removeIndex(index);

	return value;
}

template <typename T>
bool array_list<T>::removeIndex(int index)
{
	__check(index);

	for (uint64_t i = index; i < __m_size - 1; i++) {
		m_storage[i] = m_storage[i + 1];
	}

	__m_size--;

	return true;
}

template <typename T>
T *array_list<T>::find(const T & value) const
{
	for (uint64_t i = 0; i < __m_size; i++) {
		if (value == m_storage[i]) {
			return &m_storage[i];
		}
	}
	return nullptr;
}

template <typename T>
bool array_list<T>::remove(const T & value)
{
	for (uint64_t i = 0; i < __m_size; i++) {
		if (value == m_storage[i]) {
			removeIndex(i);
			return true;
		}
	}

	return false;
}
