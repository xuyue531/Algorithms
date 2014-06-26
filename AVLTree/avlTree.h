/*************************************************************************
    > File Name: avlTree.h
    > Author: xuyue
    > Mail: xuyue0531@gmail.com 
    > Created Time: 2014年06月25日 星期三 10时51分44秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define RH -1
#define LH 1
#define EH 0
#define RC 1
#define LC 0

template <typename T>
class AVLTreeNode {
public:
	T key;
	AVLTreeNode<T>* parent;
	AVLTreeNode<T>* left;
	AVLTreeNode<T>* right;
	AVLTreeNode():key(T()), parent(NULL), left(NULL), right(NULL) {}
};


template <typename T>
class AVLTree {
public:
	AVLTree():root(NIL) {};
	void inorder_tree_walk(AVLTreeNode<T>* proot);
	int insert_key(const T& k);
	int delete_key(const T& k);
	AVLTreeNode<T>* tree_search(const T& k) const;
	AVLTreeNode<T>* get_root() const;
	~AVLTree();

private:
	AVLTreeNode<T>* root;
	static AVLTreeNode<T>* NIL;
	int getDepth(const AVLTreeNode<T>* pnode) const;
	int insert_Key(const T& k, AVLTreeNode<T>* pnode);
	int delete_key(const T& k, AVLTreeNode<T>* pnode);
	AVLTreeNode<T>* tree_minimum(AVLTreeNode<T>* pnode);
	void make_empty(AVLTreeNode<T>* proot);
	void avl_translate(AVLTreeNode<T>* node_u, AVLTreeNode<T>* node_v);
	void singleRotateWithL(AVLTreeNode<T>* pnode);
	void singleRotateWithR(AVLTreeNode<T>* pnode);
	void avl_delete_fixup(AVLTreeNode<T>* pnode, int flag);
	inline void rotateWithLR(AVLTreeNode<T>* pnode);
	inline void rotateWithRL(AVLTreeNode<T>* pnode);
};


