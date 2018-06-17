/*
 * arraylist.cpp
 *
 *  Created on: Jun 9, 2018
 *      Author: Robert Phillips III
 */

template <typename T>
array_list<T>::array_list(uint32_t capacity)
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
	data_structure<T>::check(index);

	return m_storage[index];
}

template <typename T>
const T & array_list<T>::at(int index) const
{
	data_structure<T>::check(index);

	return m_storage[index];
}

template <typename T>
T & array_list<T>::get(int index) const
{
	data_structure<T>::check(index);

	return m_storage[index];
}

template <typename T>
void array_list<T>::append(const T & value)
{
	data_structure<T>::m_size++;

	if (m_capacity < data_structure<T>::m_size) {
		m_capacity *= 2;

		T *temp = m_storage;

		m_storage = new T[m_capacity];
		for (uint32_t i = 0; i < data_structure<T>::m_size - 1; i++) {
			m_storage[i] = temp[i];
		}

		delete [] temp;
	}

	m_storage[data_structure<T>::m_size - 1] = value;
}

template <typename T>
T array_list<T>::pop_back()
{
	data_structure<T>::check();

	uint32_t index = data_structure<T>::m_size - 1;

	T value = m_storage[index];
	removeIndex(index);

	return value;
}

template <typename T>
bool array_list<T>::removeIndex(int index)
{
	data_structure<T>::check(index);

	for (uint32_t i = index; i < data_structure<T>::m_size - 1; i++) {
		m_storage[i] = m_storage[i + 1];
	}

	data_structure<T>::m_size--;

	return true;
}

template <typename T>
T *array_list<T>::find(const T & value) const
{
	for (uint32_t i = 0; i < data_structure<T>::m_size; i++) {
		if (value == m_storage[i]) {
			return &m_storage[i];
		}
	}
	return nullptr;
}

template <typename T>
bool array_list<T>::remove(const T & value)
{
	for (uint32_t i = 0; i < data_structure<T>::m_size; i++) {
		if (value == m_storage[i]) {
			removeIndex(i);
			return true;
		}
	}

	return false;
}
