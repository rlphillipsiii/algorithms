/*
 * bst.cpp
 *
 *  Created on: Jun 8, 2018
 *      Author: Robert Phillips III
 */

template <typename T>
bst<T>::bst()
	: data_structure<T>(),
	  m_root(nullptr)
{

}

template <typename T>
bst<T>::~bst()
{
	if (m_root != nullptr) {
		deleteNode(m_root);
	}
}

template <typename T>
void bst<T>::add(const T & value)
{
	Node *node = new Node();
	node->m_value = value;
	node->m_left  = nullptr;
	node->m_right = nullptr;

	if (m_root == nullptr) {
		m_root = node;
	} else {
		add(m_root, node);
	}

	data_structure<T>::m_size++;
}

template <typename T>
void bst<T>::add(Node *root, Node *insert)
{
	root->m_height++;

	if (insert->m_value > root->m_value) {
		if (root->m_right == nullptr) {
			root->m_right = insert;
		} else {
			add(root->m_right, insert);
		}
	} else {
		if (root->m_left == nullptr) {
			root->m_left = insert;
		} else {
			add(root->m_left, insert);
		}
	}
}

template <typename T>
T *bst<T>::find(const T & value) const
{
	return find(m_root, value);
}

template <typename T>
T *bst<T>::find(Node *node, const T & value) const
{
	if (node == nullptr) {
		return nullptr;
	}

	if (node->m_value == value) {
		return &node->m_value;
	}

	return (value > node->m_value) ?
			find(node->m_right, value) : find(node->m_left, value);
}

template <typename T>
bool bst<T>::remove(const T & value)
{
	__check();

	Node *parent = nullptr;
	Node *found  = nullptr;;

	findNode(parent, found, value);
	if (found == nullptr) {
		return false;
	}

	__m_size--;

	if ((found->m_right != nullptr) && (found->m_left != nullptr)) {
		Node *subtree = found;

		Node *biggest = found->m_left;
		while (biggest->m_right != nullptr) {
			subtree = biggest;

			biggest = biggest->m_right;
		}

		found->m_value = biggest->m_value;
		parent = subtree;
		found  = biggest;
	}

	remove(parent, found);
	return true;
}

template <typename T>
void bst<T>::remove(Node *parent, Node *found)
{
	if ((found->m_right == nullptr) && (found->m_left == nullptr)) {
		if (parent->m_right == found) {
			parent->m_right = nullptr;
		} else {
			parent->m_left = nullptr;
		}
	} else if ((found->m_right == nullptr) && (found->m_left != nullptr)) {
		if (parent->m_right == found) {
			parent->m_right = found->m_left;
		} else {
			parent->m_left = found->m_left;
		}
	} else if ((found->m_right != nullptr) && (found->m_left == nullptr)) {
		if (parent->m_right == found) {
			parent->m_right = found->m_right;
		} else {
			parent->m_left = found->m_right;
		}
	}

	found->m_right = nullptr;
	found->m_left  = nullptr;
	deleteNode(found);
}

template <typename T>
void bst<T>::deleteNode(Node *node)
{
	if (node->m_right != nullptr) { deleteNode(node->m_right); }
	if (node->m_left != nullptr)  { deleteNode(node->m_left);  }

	delete node;
}

template <typename T>
void bst<T>::findNode(Node *parent, Node *node, const T & value) const
{
	parent = nullptr;

	if (m_root->m_value == value) {
		node = m_root;
	} else {
		findNode(parent, node, m_root->m_left, value);
		if (node == nullptr) {
			findNode(parent, node, m_root->m_right, value);
		}
	}
}

template <typename T>
void bst<T>::findNode(Node *parent, Node *node, Node *root, const T & value) const
{
	if ((root->m_left == nullptr) && (root->m_right == nullptr)) {
		node = nullptr;
		return;
	}

	if (root->m_left != nullptr) {
		if (root->m_left->m_value == value) {
			node   = root->m_left;
			parent = root;
		} else {
			findNode(parent, node, root->m_left, value);
		}
	}

	if (node != nullptr) { return; }

	if (root->m_right != nullptr) {
		if (root->m_right->m_value == value) {
			node   = root->m_right;
			parent = root;
		} else {
			findNode(parent, node, root->m_right, value);
		}
	}
}
