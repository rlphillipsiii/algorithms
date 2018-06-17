/*
 * list.h
 *
 *  Created on: Jun 7, 2018
 *      Author: Robert Phillips III
 */

#ifndef LIST_H_
#define LIST_H_

#include <datastructure.h>

namespace dsa
{
	template <typename T>
	class list : public data_structure<T>
	{
	public:
		list();
		~list();

		void push(const T & value);
		void push_back(const T & value);

		void insert(int index, const T & value);

		T & front() const;
		T & back() const;

		T pop();
		T pop_back();

		T *find(const T & value) const;
		bool remove(const T & value);

	private:
		struct Node : public data_structure<T>::Container {
			Node() : data_structure<T>::Container() { }

			T m_value;

			Node *m_next;
			Node *m_prev;
		};

		Node *m_head;
		Node *m_tail;
	};

#include "list.cpp"

};

#endif /* LIST_H_ */
