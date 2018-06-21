/*
 * avl_tree.h
 *
 *  Created on: Jun 10, 2018
 *      Author: Robert Phillips III
 */

#ifndef LIBRARY_AVLTREE_H_
#define LIBRARY_AVLTREE_H_

#include <bst.h>

namespace dsa
{
	template <typename T>
	class avl_tree : public bst<T>
	{
	public:
		avl_tree();
		~avl_tree();

	private:
		enum Direction {
			DIR_RIGHT,
			DIR_LEFT,
		};

		void rotate(Direction dir);
		void balance(struct bst<T>::Node *root);
	};

#include "avltree.cpp"
};

#endif /* LIBRARY_AVLTREE_H_ */
