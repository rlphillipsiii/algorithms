/*
 * datastructure.h
 *
 *  Created on: Jun 8, 2018
 *      Author: Robert Phillips III
 */

#ifndef LIBRARY_DATASTRUCTURE_H_
#define LIBRARY_DATASTRUCTURE_H_

#include <cstdint>
#include <index_exception.h>

namespace dsa
{
	template <typename T>
	class data_structure
	{
	public:
		data_structure() : m_size(0) { }
		virtual ~data_structure() { }

		virtual T *find(const T & value) const = 0;
		virtual bool remove(const T & value) = 0;

		virtual bool contains(const T & value)
		{
			return (find(value) != nullptr);
		}

		virtual inline uint32_t size() const { return m_size; }

	protected:
		uint32_t m_size;

		void check(uint32_t index = 0) const
		{
			if ((m_size == 0) || (index < 0) || (index >= m_size)) {
				throw dsa::index_exception(index);
			}
		}

		struct Container {
		public:
			Container()          { m_refs++; }
			virtual ~Container() { m_refs--; }

			inline static uint32_t count() { return m_refs; }

		private:
			static uint32_t m_refs;
		};
	};

	template <typename T>
	uint32_t data_structure<T>::Container::m_refs = 0;
};

#endif /* LIBRARY_DATASTRUCTURE_H_ */
