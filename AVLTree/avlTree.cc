/*************************************************************************
  > File Name: avlTree.cc
  > Author: xuyue
  > Mail: xuyue0531@gmail.com 
  > Created Time: 2014年06月25日 星期三 11时16分43秒
 ************************************************************************/

#include<iostream>
#include"avlTree.h"
#include<sys/time.h>
using namespace std;

template <typename T>
AVLTreeNode<T>* AVLTree<T>::NIL = new AVLTreeNode<T>;


template <typename T>
AVLTreeNode<T>* AVLTree<T>::tree_search(const T& k) const {
	AVLTreeNode<T>* tmpnode_x = root;
	//	if(root != NIL) {
	while(tmpnode_x != NIL && tmpnode_x->key != k) {
		if(tmpnode_x->key < k)
			tmpnode_x = tmpnode_x->right;
		else
			tmpnode_x = tmpnode_x->left;
	}
	//	}
	if(tmpnode_x == NIL)
		cout << "NO the element!" << endl;
	return tmpnode_x;
}


template <typename T>
void AVLTree<T>::inorder_tree_walk(AVLTreeNode<T>* proot) {
//	AVLTreeNode<T>* tmpnode_x = proot;
	//	if(proot != NULL) {
	if(proot != NIL){
		inorder_tree_walk(proot->left);
		cout << proot->key << endl;
		inorder_tree_walk(proot->right);
	}
	//	}
//	else
//		cout << "The tree is empty!" << endl;
}


template <typename T>
int AVLTree<T>::getDepth(const AVLTreeNode<T>* pnode) const {
	unsigned int unDepthLeft;
	unsigned int unDepthRight;

	if(pnode != NIL) {
		unDepthLeft = getDepth(pnode->left);
		unDepthRight = getDepth(pnode->right);
		return 1+
			(unDepthLeft > unDepthRight ? unDepthLeft : unDepthRight);
	}
	return 0;
}


template <typename T>
AVLTreeNode<T>* AVLTree<T>::get_root() const {
	return root;
}

template <typename T>
void AVLTree<T>::singleRotateWithL(AVLTreeNode<T>* pnode) {
	AVLTreeNode<T> *tmpnode_x = pnode->right;
	pnode->right = tmpnode_x->left;
	if(tmpnode_x->left != NIL)
		tmpnode_x->left->parent = pnode;
	tmpnode_x->parent = pnode->parent;
	if(pnode->parent == NIL)
		root = tmpnode_x;
	else if(pnode == pnode->parent->left)
		pnode->parent->left = tmpnode_x;
	else
		pnode->parent->right = tmpnode_x;
	tmpnode_x->left = pnode;
	pnode->parent = tmpnode_x;
}


template <typename T>
void AVLTree<T>::singleRotateWithR(AVLTreeNode<T>* pnode) {
	AVLTreeNode<T> *tmpnode_x = pnode->left;
	pnode->left = tmpnode_x->right;
	if(tmpnode_x->right != NIL)
		tmpnode_x->right->parent = pnode;
	tmpnode_x->parent = pnode->parent;
	if(pnode->parent == NIL)
		root = tmpnode_x;
	else if(pnode == pnode->parent->left)
		pnode->parent->left = tmpnode_x;
	else
		pnode->parent->right = tmpnode_x;
	tmpnode_x->right = pnode;
	pnode->parent = tmpnode_x;
}


template <typename T>
void AVLTree<T>::rotateWithLR(AVLTreeNode<T>* pnode) {
	singleRotateWithL(pnode->left);
	return singleRotateWithR(pnode);
}


template <typename T>
void AVLTree<T>::rotateWithRL(AVLTreeNode<T>* pnode) {
	singleRotateWithR(pnode->right);
	return singleRotateWithL(pnode);
}


template <typename T>
void AVLTree<T>::make_empty(AVLTreeNode<T>* proot) {
	if(root != NIL) {
		AVLTreeNode<T>* pleft = proot->left;
		AVLTreeNode<T>* pright = proot->right;
		delete proot;
		if(pleft != NIL)
			make_empty(pleft);
		if(pright != NIL)
			make_empty(pright);
	}
}


template <typename T>
AVLTree<T>::~AVLTree() {
	make_empty(root);
}


template <typename T>
int AVLTree<T>::insert_Key(const T& k, AVLTreeNode<T>* pnode) {
	if(root == NIL) {
		AVLTreeNode<T>* newnode = new AVLTreeNode<T>;
		newnode->key = k;
		newnode->left = NIL;
		newnode->right = NIL;
		newnode->parent = NIL;
		root = newnode;
	}
	else {
		if(k < pnode->key) {
			if(pnode->left == NIL) {
				AVLTreeNode<T>* newnode = new AVLTreeNode<T>;
				newnode->key = k;
				newnode->left = NIL;
				newnode->right = NIL;
				newnode->parent = pnode;
				pnode->left = newnode;
			}
			else
				insert_Key(k, pnode->left);
			if(2 == (getDepth(pnode->left) - getDepth(pnode->right))) {
				if(k < pnode->left->key)
					singleRotateWithR(pnode);
				else
					rotateWithLR(pnode);
			}
		}
		else {
			if(pnode->right == NIL) {
				AVLTreeNode<T>* newnode = new AVLTreeNode<T>;
				newnode->key = k;
				newnode->left = NIL;
				newnode->right = NIL;
				newnode->parent = pnode;
				pnode->right = newnode;
			}
			else
				insert_Key(k, pnode->right);
			if(2 == (getDepth(pnode->right) - getDepth(pnode->left))) {
				if(k > pnode->right->key)
					singleRotateWithL(pnode);
				else
					rotateWithRL(pnode);
			}
		}
	}
	return 0;
}


template <typename T>
int AVLTree<T>::insert_key(const T& k) {
	return insert_Key(k, root);
}


template <typename T>
int AVLTree<T>::delete_key(const T& k) {
	int flag;
	AVLTreeNode<T>* delnode = tree_search(k);
	AVLTreeNode<T>* tmpnode_x = delnode->parent;
	if(delnode == tmpnode_x->left)
		flag = LC;
	else
		flag = RC;
	if(delnode->left == NIL)
		avl_translate(delnode, delnode->right);
	else if(delnode->right == NIL)
		avl_translate(delnode, delnode->left);
	else {
		AVLTreeNode<T>* tmpnode_y = tree_minimum(delnode->right);
		tmpnode_x = tmpnode_y->parent;
		if(tmpnode_y == tmpnode_x->left)
			flag = LC;
		else
			flag = RC;
		if(tmpnode_y->parent != delnode) {
			avl_translate(tmpnode_y, tmpnode_y->right);
			tmpnode_y->right = delnode->right;
			tmpnode_y->right->parent = tmpnode_y;
		}
		avl_translate(delnode, tmpnode_y);
		tmpnode_y->left = delnode->left;
		tmpnode_y->left->parent = tmpnode_y;
	}
	avl_delete_fixup(tmpnode_x, flag);
	return 0;
}


template <typename T>
void AVLTree<T>::avl_delete_fixup(AVLTreeNode<T>* pnode, int flag) {
	int tmpflag = flag;
	AVLTreeNode<T>* tmpnode_x = pnode;
	while(tmpnode_x != NIL) {
		if(tmpflag == LC) {
			if(2 == (getDepth(tmpnode_x->right) - getDepth(tmpnode_x->left))) {
				if(LH == (getDepth(tmpnode_x->right->left) - getDepth(tmpnode_x->right->right)))
					rotateWithRL(tmpnode_x);
				else
					singleRotateWithL(tmpnode_x);
				break;
			}
		}
		else if(tmpflag == RC) {
			if(2 == (getDepth(tmpnode_x->left) - getDepth(tmpnode_x->right))) {
				if(RH == (getDepth(tmpnode_x->left->left) - getDepth(tmpnode_x->left->right)))
					rotateWithLR(tmpnode_x);
				else
					singleRotateWithR(tmpnode_x);
				break;
			}	
		}
		if(tmpnode_x == tmpnode_x->parent->left)
			tmpflag = LC;
		else if(tmpnode_x == tmpnode_x->parent->right)
			tmpflag = RC;
		tmpnode_x = tmpnode_x->parent;
	}
}


template <typename T>
void AVLTree<T>::avl_translate(AVLTreeNode<T>* node_u, AVLTreeNode<T>* node_v) {
	if(node_u->parent == NIL) {
		root = node_v;
	}
	else if(node_u == node_u->parent->left)
		node_u->parent->left = node_v;
	else
		node_u->parent->right = node_v;
	if(node_v != NIL)
		node_v->parent = node_u->parent;
}


template <typename T>
AVLTreeNode<T>* AVLTree<T>::tree_minimum(AVLTreeNode<T>* pnode) {
	AVLTreeNode<T>* tmpnode = pnode;
	if(tmpnode == NIL)
		return NIL;
	while(tmpnode->left != NIL)
		tmpnode = tmpnode->left;
	return tmpnode;
}


int main() {
	AVLTree<int> avlTree;
	clock_t start, end;

	start = clock();
	for(int i = 1; i <= 10000; ++i) {
		avlTree.insert_key(i);
	}
	end = clock();
	cout << "time: " << (static_cast<double>(end - start))/CLOCKS_PER_SEC << endl;



//	avlTree.insert_key(23);
//	avlTree.insert_key(12);
//	avlTree.insert_key(2);
//	avlTree.insert_key(16);
//	avlTree.insert_key(35);
//	avlTree.insert_key(25);

//	avlTree.delete_key(25);
//	avlTree.delete_key(2);
//	avlTree.delete_key(16);
//	avlTree.delete_key(35);

//	cout << "root: " << avlTree.get_root()->key << endl;
//	avlTree.inorder_tree_walk(avlTree.get_root());

	return 0;
}
