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

		void insert(uint64_t index, const T & value);

		T & front() const;
		T & back() const;

		T pop();
		T pop_back();

		T *find(const T & value) const override;
		bool remove(const T & value) override;
		void clear() override;
		void add(const T & value) override;

		T & operator[](uint64_t index);
		const T & at(uint64_t index) const;

		class iterator
		{
		public:
		    ~iterator();

		    bool hasNext() const;
		    T & next();
		    uint64_t index() const;

		private:
		    friend class list;

		    iterator(const list<T> & parent);

		    const list<T> & m_parent;

		    uint64_t m_index;
		    struct list<T>::Node *m_current;
		    struct list<T>::Node *m_last;
		};

		iterator begin() const;
		bool remove(const list<T>::iterator & it);

	private:
		struct Node : public data_structure<T>::Container {
			Node() : data_structure<T>::Container() { }

			T m_value;

			Node *m_next;
			Node *m_prev;
		};

		Node *m_head;
		Node *m_tail;

		bool unlink(Node *node);
	};

#include "list.cpp"

};

#endif /* LIST_H_ */
