/*
 * array.h
 *
 *  Created on: Jun 17, 2018
 *      Author: Robert Phillips III
 */

#ifndef LIBRARY_ARRAY_H_
#define LIBRARY_ARRAY_H_

#include "implementation_exception.h"

namespace dsa
{
	template <typename T>
	class array : public data_structure<T>
	{
	public:
		array(uint64_t capacity);
		~array();

		T *data() const;

		T & operator[](int index);

		const T & at(int index) const;
		T get(int index) const;
		T & lookup(int index) const;

		T *find(const T & value) const;
		bool remove(const T & value);

	private:
		T *m_storage;
	};

#include "array.cpp"
};


#endif /* LIBRARY_ARRAY_H_ */
