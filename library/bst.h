/*
 * bst.h
 *
 *  Created on: Jun 8, 2018
 *      Author: Robert Phillips III
 */

#ifndef LIBRARY_BST_H_
#define LIBRARY_BST_H_

#include <datastructure.h>

namespace dsa
{
	template <typename T>
	class bst : public data_structure<T>
	{
	public:
		bst();
		virtual ~bst();

		virtual void add(const T & value);
		virtual bool remove(const T & value);

		T *find(const T & value) const;

	protected:
		struct Node : public data_structure<T>::Container {
			Node() : data_structure<T>::Container(), m_height(1) { }

			T m_value;

			uint32_t m_height;

			Node *m_left;
			Node *m_right;
		};

		Node *m_root;

		void deleteNode(Node *node);

		virtual void add(Node *root, Node *insert);
		virtual void remove(Node *parent, Node *found);

		T *find(Node *root, const T & value) const;
		void findNode(Node *parent, Node *node, const T & value) const;
		void findNode(Node *parent, Node *node, Node *root, const T & value) const;
	};

#include "bst.cpp"
};

#endif /* LIBRARY_BST_H_ */
