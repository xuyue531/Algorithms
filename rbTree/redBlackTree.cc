/*************************************************************************
    > File Name: redBlackTree.cc
    > Author: xuyue
    > Mail: xuyue0531@gmail.com 
    > Created Time: 2014年06月21日 星期六 14时39分54秒
 ************************************************************************/

#include<iostream>
#include "rbTree.h"
using namespace std;

template <typename T>
RedBlackTreeNode<T>* RedBlackTree<T>::NIL = new RedBlackTreeNode<T>;    //初始化private下的static成员，但不能对其赋值
                                                                        //见http://blog.chinaunix.net/uid-12664992-id-129804.html

template <typename T>
RedBlackTree<T>::RedBlackTreeNode() {
	root = NULL;
}

template <typename T>
RedBlackTreeNode<T>* RedBlackTree<T>::get_root() const {
	return root;
}

template <typename T>
RedBlackTreeNode<T>* RedBlackTree<T>::get_parent(RedBlackTreeNode<T>* rbtnode) const {
	return rbtnode->parent;
}

template <typename T>
RedBlackTreeNode<T>* RedBlackTree<T>::get_left(RedBlackTreeNode<T>* rbtnode) const {
	return rbtnode->left;
}


template <typename T>
RedBlackTreeNode<T>* RedBlackTree<T>::get_right(RedBlackTreeNode<T>* rbtnode) const {
	return rbtnode->right;
}


template <typename T>
T RedBlackTree::get_key(RedBlackTreeNode<T>* rbtnode) const {
	return rbtnode->key;
}


template <typename T>
int RedBlackTree<T>::get_color(RedBlackTreeNode<T>* rbtnode) const {
	return rbtnode->color;
}


template <typename T>
void RedBlackTree<T>::set_color(RedBlackTreeNode<T>* rbtnode, int color) {
	return rbtnode->color = color;
}


template <typename T>
void make_empty(RedBlackTreeNode<T>* root) {
	if(root) {
		RedBlackTreeNode<T>* pleft = root->left;
		RedBlackTreeNode<T>* pright = root->right;
		delete root;
		if(pleft != NIL)
			make_empty(pleft);
		if(pright != NIL)
			make_empty(pright);
	}
}


template <typename T>
int redBlackTree<T>::left_rotate(RedBlackTreeNode<T>* rbtnode) {
	RedBlackTreeNode<T>* rightnode = rbtnode->right;
	rbtnode->right = rightnode->left;
	if(rightnode->left != NIL)
		rightnode->left->parent = rbtnode;
	rightnode->parent = rbtnode->parent;
	if(rbtnode->parent == NIL)
		root = rightnode;
	else if(rbtnode == rbtnode->parent->left)
		rbtnode->parent->left = rightnode;
	else
		rbtnode->parent->right = rightnode;
	rightnode->left = rbtnode;
	rbtnode->parent = rightnode;
	return 0;
}


template <typename T>
RedBlackTree<T>::~RedBlackTree() {
	make_empty(root);
}


template <typename T>
int redBlackTree<T>::right_rotate(RedBlackTreeNode<T>* rbtnode) {
	RedBlackTreeNode<T>* leftnode = rbtnode->left;
	rbtnode->left = rightnode->right;
	if(leftnode->right != NIL)
		leftnode->right->parent = rbtnode;
	leftnode->parent = rbtnode->parent;
	if(rbtnode->parent == NIL)
		root = leftnode;
	else if(rbtnode == rbtnode->parent->left)
		rbtnode->parent->left = leftnode;
	else
		rbtnode->parent->right = leftnode;
	leftnode->right = rbtnode;
	rbtnode->parent = leftnode;
	return 0;
}


template <typename T>
int RedBlackTree<T>::insert_key(const T& k) {
	RedBlackTreeNode<T>* newnode = new RedBlackTreeNode<T>;
	newnode->key = k;
	newnode->color = RED;
	newnode->left = NULL;
	newnode->right = NULL;
	newnode->parent = NULL;

	RedBlackTreeNode<T>* tmpnode_y = NIL;
	RedBlackTreeNode<T>* tmpnode_x = root;
	while(tmpnode_x != NIL) {
		tmpnode_y = tmpnode_x;
		if(newnode->key < tmpnode_x->key)
			tmpnode_x = tmpnode_x->left;
		else
			tmpnode_x = tmpnode_x->right;
	}

	newnode->parent = tmpnode_y;
	if(tmpnode_y == NIL)
		root = newnode;
	else if(newnode->key < tmpnode_y->key)
		tmpnode_y->left = newnode;
	else
		tmpnode_y->right = newnode;

	newnode->left = NIL;
	newnode->right = NIL;
	newnode->color = RED;
	rb_insert_fixup(newnode);
	return 0;
}


template <typename T>
int RedBlackTree<T>::rb_insert_fixup(RedBlackTreeNode<T>* rbtnode) {
	RedBlackTreeNode<T>* tmpnode_y = NULL;
	while(rbtnode->parent->color == RED) {
		if(rbtnode->parent == rbtnode->parent->parent->left) {
			tmpnode_y = rbtnode->parent->parent->right;
			if(tmpnode_y->color == RED) {
				rbtnode->parent->color = BLACK;
				tmpnode_y->color = BLACK;
				rbtnode->parent->parent->color = RED;
				rbtnode = rbtnode->parent->parent;
			}
			else if(rbtnode == rbtnode->parent->right) {
				rbtnode = rbtnode->parent;
				left_rotate(rbtnode);
			}
			rbtnode->parent->color = BLACK;
			rbtnode->parent->parent->color = RED;
			right_rotate(rbtnode->parent->parent);
		}
		else {
			tmpnode_y = rbtnode->parent->parent->left;
			if(tmpnode_y->color == RED) {
				rbtnode->parent->color = BLACK;
				tmpnode_y->color = BLACK;
				rbtnode->parent->parent->color = RED;
				rbtnode = rbtnode->parent->parent;
			}
			else if(rbtnode == rbtnode->parent->left) {
				rbtnode = rbtnode->parent;
				left_rotate(rbtnode);
			}
			rbtnode->parent->color = BLACK;
			rbtnode->parent->parent->color = RED;
			right_rotate(rbtnode->parent->parent);
		}
	}
	return 0;
}


template <typename T>
int RedBlackTree<T>::delete_key(const T& k) {
	RedBlackTreeNode<T>* tmpnode_z = search_tree_node(k);
	if(tmpnode_z == NIL)
		return -1;

	RedBlackTreeNode<T>* tmpnode_y = tmpnode_z;
	RedBlackTreeNode<T>* tmpnode_x = NULL;
	int y_original_color = tmpnode_y->color;

	if(tmpnode_z->left == NIL) {
		tmpnode_x = tmpnode_z->right;
		rb_transpalnt(tmpnode_z, tmpnode_z->right);
	}
	else if(tmpnode_z->right == NIL)
		tmpnode_x = tmpnode_z->left;
	rb_transpalnt(tmpnode_z, tmpnode_z->left);
	else {
		tmpnode_y = tree_minimum(tmpnode_z->right);
		y_original_color = tmpnode_y->color;
		tmpnode_x = tmpnode_y->right;
		if(tmpnode_y->parent == tmpnode_z)
			tmpnode_x->parent = tmpnode_y;
		else {
			rb_transpalnt(tmpnode_y, tmpnode_y->right);
			tmpnode_y->right = tmpnode_z->right;
			tmpnode_y->right->parent = tmpnode_y;
		}
		rb_transpalnt(tmpnode_z, tmpnode_y);
		tmpnode_y->left = tmpnode_z->left;
		tmpnode_y->left->parent = tmpnode_y;
		tmpnode_y->color = tmpnode_z->color;
	}
	if(y_original_color == BLACK)
		rb_delete_fixup(tmpnode_x);
	return 0;
}


template <typename T>
int RedBlackTree<T>::rb_delete_fixup(RedBlackTreeNode<T>* rbtnode) {
	RedBlackTreeNode<T>* tmpnode_w = NULL;
	while(rbtnode != root && rbtnode->color == BLACK) {
		if(rbtnode == rbtnode->parent->left) {
			tmpnode_w = rbtnode->parent->right;
			if(tmpnode_w->color == RED) {
				tmpnode_w->color = BLACK;
				rbtnode->parent->color = RED;
				left_rotate(rbtnode->parent);
				tmpnode_w = rbtnode->parent->right;
			}
			if(tmpnode_w->left->color == BLACK && tmpnode_w->right->color == BLACK) {
				tmpnode_w->color = RED;
				rbtnode = rbtnode->parent;
			}
			else if(tmpnode_w->right->color == BLACK) {
				tmpnode_w->left->color = BLACK;
				tmpnode_w->color = RED;
				right_rotate(tmpnode_w);
				tmpnode_w = rbtnode->parent->right;
			}
			tmpnode_w->color = rbtnode->parent->color;
			rbtnode->parent->color = BLACK;
			tmpnode_w->right->color BLACK;
			left_rotate(rbtnode->parent);
			rbtnode = root;
		}
		else {
			tmpnode_w = rbtnode->parent->left;
			if(tmpnode_w->color == RED) {
				tmpnode_w->color = BLACK;
				rbtnode->parent->color = RED;
				right_rotate(rbtnode->parent);
				tmpnode_w = rbtnode->parent->left;
			}
			if(tmpnode_w->right->color == BLACK && tmpnode_w->left->color == BLACK) {
				tmpnode_w->color = RED;
				rbtnode = rbtnode->parent;
			}
			else if(tmpnode_w->left->color == BLACK) {
				tmpnode_w->right->color = BLACK;
				tmpnode_w->color = RED;
				left_rotate(tmpnode_w);
				tmpnode_w = rbtnode->parent->left;
			}
			tmpnode_w->color = rbtnode->parent->color;
			rbtnode->parent->color = BLACK;
			tmpnode_w->left->color BLACK;
			right_rotate(rbtnode->parent);
			rbtnode = root;
		}
	}
}


template <typename T>
RedBlackTreeNode<T>* RedBlackTree<T>::search_tree_node(const T& k) const {
	RedBlackTreeNode<T>* pnode = root;
	while(pnode != NIL) {
		if(pnode->key == k)
			break;
		else if(pnode->key < k)
			pnode = pnode->right;
		else
			pnode = pnode->left;
	}
	return pnode;
}


template <typename T>
void RedBlackTree<T>::rb_transpalnt(RedBlackTreeNode<T>* node_u, RedBlackTreeNode<T>* node_v) {
	if(node_u->parent == NIL)
		root = node_v;
	else if(node_u == node_u->parent->left)
		node_u->parent->left = node_v;
	else
		node_u->parent->right = node_v;
	node_v->parent = node_u->parent;
}


template <typename T>
RedBlackTreeNode<T>* RedBlackTree<T>::tree_minimum(RedBlackTreeNode<T>* root) {
	RedBlackTreeNode<T>* pnode = root;
	if(pnode == NIL)
		return NIL;
	while(pnode->left != NIL) {
		pnode = pnode->left;
	}
	return pnode;
}




