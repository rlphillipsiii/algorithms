/*
 * exception.h
 *
 *  Created on: Jun 7, 2018
 *      Author: Robert Phillips III
 */

#ifndef EXCEPTION_H_
#define EXCEPTION_H_

#include <strings.h>

namespace dsa
{
	class exception
	{
	public:
	    exception(const string & message)
	        : m_message(message)
	    { }

		exception(const char *message)
			: m_message(message)
		{ }

		virtual ~exception() { }
		virtual string message() const { return m_message; }

	protected:
		string m_message;
	};
};

#endif /* EXCEPTION_H_ */
