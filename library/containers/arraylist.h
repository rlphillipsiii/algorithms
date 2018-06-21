/*
 * arraylist.h
 *
 *  Created on: Jun 9, 2018
 *      Author: Robert Phillips III
 */

#ifndef LIBRARY_ARRAYLIST_H_
#define LIBRARY_ARRAYLIST_H_

#include <datastructure.h>
#include <memory_exception.h>

namespace dsa
{
	template <typename T>
	class array_list : public data_structure<T>
	{
	public:
		array_list(uint64_t capacity = 8);
		~array_list();

		const T & at(uint64_t index) const;
		T get(uint64_t index) const;

		void append(const T & value);
		bool removeIndex(uint64_t index);
		T pop_back();

		T & operator[](uint64_t index) const;

		T *data() const;

		T *find(const T & value) const override;
        bool remove(const T & value) override;
        void add(const T & value) override;
        void clear() override;

	private:
		uint64_t m_initial;
		uint64_t m_capacity;

		T *m_storage;
	};

#include "arraylist.cpp"
};

#endif /* LIBRARY_ARRAYLIST_H_ */
