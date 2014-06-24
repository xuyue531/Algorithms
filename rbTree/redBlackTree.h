/*************************************************************************
    > File Name: redBlackTree.h
    > Author: xuyue
    > Mail: xuyue0531@gmail.com 
    > Created Time: 2014年06月21日 星期六 14时02分00秒
 ************************************************************************/

#ifndef RBTREE_H
#define RBTREE_H
#include<iostream>
using namespace std;

static const int RED = 1;
static const int BLACK = 0;

template <typename T>
class RedBlackTreeNode {
public:
	RedBlackTreeNode():key(T()),parent(NULL),left(NULL),right(NULL),color(BLACK) {}
	T key;
	RedBlackTreeNode<T> *left;
	RedBlackTreeNode<T> *right;
	RedBlackTreeNode<T> *parent;
	int color;
};

template <typename T>
class RedBlackTree {
public:
	RedBlackTree();
//	int search_element(const T& k) const;
	int insert_key(const T& k);
	int delete_key(const T& k);
	RedBlackTreeNode<T>* get_root() const;
	~RedBlackTree();

private:
	RedBlackTreeNode<T>* root;
	static RedBlackTreeNode<T>* NIL;

	RedBlackTreeNode<T>* get_parent(RedBlackTreeNode<T>* rbtnode) const;
	RedBlackTreeNode<T>* get_left(RedBlackTreeNode<T>* rbtnode) const;
	RedBlackTreeNode<T>* get_right(RedBlackTreeNode<T>* rbtnode) const;
	RedBlackTreeNode<T>* search_tree_node(const T& k) const;
	RedBlackTreeNode<T>* tree_minimum(RedBlackTreeNode<T>* proot);
	T get_key(RedBlackTreeNode<T>* rbtnode) const;
	int get_color(RedBlackTreeNode<T>* rbtnode) const;
	void set_color(RedBlackTreeNode<T>* rbtnode, int color);
	int left_rotate(RedBlackTreeNode<T>* rbtnode);
	int right_rotate(RedBlackTreeNode<T>* rbtnode);
	int rb_insert_fixup(RedBlackTreeNode<T>* rbtnode);
	int rb_delete_fixup(RedBlackTreeNode<T>* rbtnode);
	void rb_transpalnt(RedBlackTreeNode<T>* node_u, RedBlackTreeNode<T>* node_v);
	void make_empty(RedBlackTreeNode<T>* root);
};

#endif
