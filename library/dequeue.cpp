/*
 * dequeue.cpp
 *
 *  Created on: Jun 10, 2018
 *      Author: Robert Phillips III
 */

template <typename T>
dequeue<T>::dequeue()
	: data_structure<T>()
{

}

template <typename T>
dequeue<T>::~dequeue()
{

}

template <typename T>
bool dequeue<T>::empty()
{
	return (m_storage.size() == 0);
}

template <typename T>
T dequeue<T>::peek_front()
{
	return m_storage.front();
}

template <typename T>
T dequeue<T>::peek_back()
{
	return m_storage.back();
}

template <typename T>
void dequeue<T>::enqueue_front(const T & value)
{
	m_storage.push(value);
}

template <typename T>
void dequeue<T>::enqueue_back(const T & value)
{
	m_storage.push_back(value);
}

template <typename T>
T dequeue<T>::dequeue_front(const T & value)
{
	return m_storage.pop();
}

template <typename T>
T dequeue<T>::dequeue_back(const T & value)
{
	return m_storage.pop_back();
}

template <typename T>
bool dequeue<T>::remove(const T & value)
{
	return m_storage.remove(value);
}

template <typename T>
T *dequeue<T>::find(const T & value)
{
	return m_storage.find(value);
}
