/*
 * dequeue.h
 *
 *  Created on: Jun 10, 2018
 *      Author: Robert
 */

#ifndef LIBRARY_DEQUEUE_H_
#define LIBRARY_DEQUEUE_H_

#include <datastructure.h>
#include <list.h>

namespace dsa
{
	template <typename T>
	class dequeue : public data_structure<T>
	{
	public:
		dequeue();
		~dequeue();

		void enqueue_front(const T & value);
		void enqueue_back(const T & value);

		T peek_front();
		T peek_back();

		T dequeue_front(const T & value);
		T dequeue_back(const T & value);

		bool remove(const T & value) override;
		T *find(const T & value) const override;
		void add(const T & value) override;
		void clear() override;

		bool empty();

		inline uint64_t size() const override { return m_storage.size(); }

	private:
		list<T> m_storage;
	};

#include "dequeue.cpp"
};

#endif /* LIBRARY_DEQUEUE_H_ */
