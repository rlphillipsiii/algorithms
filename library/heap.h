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

		inline uint64_t parent(uint64_t index) const { return ((index - 1) / 2); }
		inline uint64_t left(uint64_t index)   const { return ((2 * index) + 1); }
		inline uint64_t right(uint64_t index)  const { return ((2 * index) + 2); }

		inline uint64_t size() const override { return m_tree.size(); }

	private:
		array_list<T> m_tree;

		const Strategy m_strategy;

		void swap(uint64_t index1, uint64_t index2);
		void constrain();
		bool broken(uint64_t parent) const;

		uint64_t indexOf(const T & value, bool & found) const;
	};

#include "heap.cpp"
};

#endif /* LIBRARY_HEAP_H_ */
