/*
 * heap.h
 *
 *  Created on: Jun 9, 2018
 *      Author: Robert Phillips III
 */

#ifndef LIBRARY_HEAP_H_
#define LIBRARY_HEAP_H_

#include <arraylist.h>

namespace dsa
{
	template <typename T>
	class heap : public data_structure<T>
	{
	public:
		enum Strategy {
			HEAP_MIN,
			HEAP_MAX,
		};

		heap(Strategy strategy = HEAP_MIN);
		~heap();

		void add(const T & value);

		T *find(const T & value) const;
		bool remove(const T & value);

		inline int parent(int index) const { return ((index - 1) / 2); }
		inline int left(int index)   const { return ((2 * index) + 1); }
		inline int right(int index)  const { return ((2 * index) + 2); }

		inline uint64_t size() const override { return m_tree.size(); }

	private:
		static const int VALUE_NOT_FOUND;

		array_list<T> m_tree;

		const Strategy m_strategy;

		void swap(int index1, int index2);
		void constrain();
		bool broken(int parent);

		int indexOf(const T & value) const;
	};

#include "heap.cpp"
};

#endif /* LIBRARY_HEAP_H_ */
