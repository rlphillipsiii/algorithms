/*
 * exception.h
 *
 *  Created on: Jun 7, 2018
 *      Author: Robert Phillips III
 */

#ifndef EXCEPTION_H_
#define EXCEPTION_H_

namespace dsa
{
	class exception
	{
	public:
		exception(const char *message)
			: m_message(message)
		{ }

		virtual ~exception() { }

		virtual const char *message() const { return m_message; }

	protected:
		const char *m_message;
	};
};

#endif /* EXCEPTION_H_ */
