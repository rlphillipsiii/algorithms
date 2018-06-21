/*
 * array.cpp
 *
 *  Created on: Jun 17, 2018
 *      Author: Robert Phillips III
 */

template <typename T>
array<T>::array(uint64_t capacity)
	: data_structure<T>()
{
	m_storage = alloc<T>(capacity);

	__m_size = capacity;
}

template <typename T>
array<T>::~array()
{
	delete [] m_storage;
}

template <typename T>
T *array<T>::data() const
{
	return m_storage;
}

template <typename T>
T & array<T>::operator[](uint64_t index) const
{
	__check(index);

	return m_storage[index];
}

template <typename T>
const T & array<T>::at(uint64_t index) const
{
	__check(index);

	return m_storage[index];
}

template <typename T>
T array<T>::get(uint64_t index) const
{
	__check(index);

	return m_storage[index];
}

template <typename T>
T *array<T>::find(const T & value) const
{
	for (uint64_t i = 0; i < __m_size; i++) {
		if (value == m_storage[i]) {
			return &m_storage[i];
		}
	}

	return nullptr;
}

template <typename T>
bool array<T>::remove(const T & value)
{
    DSA_NOT_IMPLEMENTED

	return true;
}
