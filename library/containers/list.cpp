/*
 * list.cpp
 *
 *  Created on: Jun 7, 2018
 *      Author: Robert Phillips III
 */

template <typename T>
list<T>::list()
	: data_structure<T>(),
	  m_head(nullptr),
	  m_tail(nullptr)
{

}

template <typename T>
list<T>::~list()
{
	Node *current = m_head;

	while (current != nullptr) {
		Node *temp = current;

		current = current->m_next;
		delete temp;
	}
}

template <typename T>
T & list<T>::front() const
{
	__check();

	return m_head->m_value;
}

template <typename T>
T & list<T>::back() const
{
	__check();

	return m_tail->m_value;
}

template <typename T>
T list<T>::pop()
{
	__check();

	T value = m_head->m_value;

	Node *temp = m_head;
	m_head = m_head->m_next;
	delete temp;

	__m_size--;
	if (__m_size == 0) {
        m_tail = nullptr;
    }

	return value;
}

template <typename T>
T list<T>::pop_back()
{
	__check();

	T value = m_tail->m_value;

	Node *temp = m_tail;
	m_tail = m_tail->m_prev;
	delete temp;

	__m_size--;
	if (__m_size == 0) {
        m_head = nullptr;
    }

	return value;
}

template <typename T>
void list<T>::add(const T & value)
{
    push(value);
}

template <typename T>
void list<T>::push(const T & value)
{
	Node *node = alloc<Node>();
	node->m_value = value;
	node->m_next  = m_head;
	node->m_prev  = nullptr;

	if (m_head) {
		m_head->m_prev = node;
	}

	m_head = node;
	if (m_tail == nullptr) {
		m_tail = m_head;
	}

	__m_size++;
}

template <typename T>
void list<T>::push_back(const T & value)
{
	Node *node = alloc<Node>();
	node->m_value = value;
	node->m_next  = nullptr;
	node->m_prev  = m_tail;

	if (m_tail) {
		m_tail->m_next = node;
	}

	m_tail = node;
	if (m_head == nullptr) {
		m_head = m_tail;
	}

	__m_size++;
}

template <typename T>
void list<T>::insert(uint64_t index, const T & value)
{
	__check(index);

	if (index == 0) {
		push(value);
	} else if (index == __m_size - 1) {
		push_back(value);
	} else {
		Node *node = alloc<Node>();
		node->m_value = value;

		Node *target = m_head;
		for (int i = 0; i < index; i++) {
			target = target->m_next;
		}

		node->m_next = target;
		node->m_prev = target->m_prev;

		target->m_prev = node;
		node->m_prev->m_next = node;

		__m_size++;
	}
}

template <typename T>
T *list<T>::find(const T & value) const
{
	Node *current = m_head;

	while (current != nullptr) {
		if (current->m_value == value) {
			return &current->m_value;
		}
		current = current->m_next;
	}

	return nullptr;
}

template <typename T>
bool list<T>::remove(const T & value)
{
	__check();

	Node *current = m_head;

	while (current != nullptr) {
		if (current->m_value == value) {
			if (current == m_head) {
				pop();
			} else if (current == m_tail) {
				pop_back();
			} else {
				Node *prev = current->m_prev;
				Node *next = current->m_next;

				prev->m_next = next;
				next->m_prev = prev;

				delete current;
				__m_size--;
			}

			return true;
		}
		current = current->m_next;
	}

	return false;
}

template <typename T>
void list<T>::clear()
{
    Node *current = m_head;

    while (current != nullptr) {
        Node *temp = current;

        current = current->m_next;
        delete temp;
    }

    __m_size = 0;
    m_head = nullptr;
    m_tail = nullptr;
}

template <typename T>
typename list<T>::iterator list<T>::begin() const
{
    return list<T>::iterator(*this);
}

template <typename T>
list<T>::iterator::iterator(const list<T> & parent)
    : m_parent(parent),
      m_index(0),
      m_current(parent.m_head)
{

}

template <typename T>
list<T>::iterator::~iterator()
{

}

template <typename T>
bool list<T>::iterator::hasNext() const
{
    return (m_current != nullptr);
}

template <typename T>
uint64_t list<T>::iterator::index() const
{
    return m_index;
}

template <typename T>
T & list<T>::iterator::next()
{
    T & value = m_current->m_value;

    m_index++;

    m_current = m_current->m_next;
    return value;
}
