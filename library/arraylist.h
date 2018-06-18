/*
 * arraylist.h
 *
 *  Created on: Jun 9, 2018
 *      Author: Robert Phillips III
 */

#ifndef LIBRARY_ARRAYLIST_H_
#define LIBRARY_ARRAYLIST_H_

#include <datastructure.h>

namespace dsa
{
	template <typename T>
	class array_list : public data_structure<T>
	{
	public:
		array_list(uint64_t capacity = 8);
		~array_list();

		const T & at(int index) const;
		T get(int index) const;
		T & lookup(int index) const;

		void append(const T & value);
		bool removeIndex(int index);
		T pop_back();

		T *find(const T & value) const;
		bool remove(const T & value);

		T & operator[](int index);

		T *data() const;
	private:
		friend class dsa_test;

		uint64_t m_capacity;

		T *m_storage;
	};

#include "arraylist.cpp"
};

#endif /* LIBRARY_ARRAYLIST_H_ */
