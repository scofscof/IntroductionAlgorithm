#pragma once
#include <iostream>

class BSTreeNode
{
	friend std::ostream& operator<<(std::ostream& os, BSTreeNode* pNode);
public:
	BSTreeNode(int _key);
	~BSTreeNode();
public:
	int key;
	BSTreeNode* left;
	BSTreeNode* right;
	BSTreeNode* parent;
};
std::ostream& operator<<(std::ostream& os, BSTreeNode* pNode);

class BinarySearchTree
{
public:
	BinarySearchTree();
	~BinarySearchTree();
public:
	//中序遍历
	void InorderWalk() const;
	//前序遍历
	void PreorderWalk() const;
	//后序遍历
	void PostorderWalk() const;
	//查找(递归版本)
	BSTreeNode* SearchRecursive(int key) const;
	//查找(迭代)
	BSTreeNode* Search(int key) const;
	//获取最小元素节点(递归)
	BSTreeNode* MinimumRecursive() const;
	//获取最小元素节点(迭代)
	BSTreeNode* Minimum() const;
	//获得最大元素(递归)
	BSTreeNode* MaximumRecursive() const;
	//获得最大元素(迭代)
	BSTreeNode* Maximum() const;
	//前驱
	BSTreeNode* Successor(BSTreeNode* pNode) const;
	//后继
	BSTreeNode* Predecessor(BSTreeNode* pNode) const;
	//插入一个节点
	void Insert(BSTreeNode* pNewNode);
	//删除一个节点
	void Delete(BSTreeNode* pNode);
private:
	void InorderWalkImpl(BSTreeNode* pNode) const;
	void PreorderWalkImpl(BSTreeNode* pNode) const;
	void PostorderWalkImpl(BSTreeNode* pNode) const;
	BSTreeNode* SearchRecursiveImpl(BSTreeNode* pNode, int key) const;
	BSTreeNode* SearchImpl(BSTreeNode* pNode, int key) const;
	BSTreeNode* MinimumRecursiveImpl(BSTreeNode* pNode) const;
	BSTreeNode* MinimumImpl(BSTreeNode* pNode) const;
	BSTreeNode* MaximumRecursiveImpl(BSTreeNode* pNode) const;
	BSTreeNode* MaximumImpl(BSTreeNode* pNode) const;
	//在二叉搜索树中，用节点V替换节点U，使节点V成为节点U双亲的孩子节点
	void Transplant(BSTreeNode* pNodeU, BSTreeNode* pNodeV);
private:
	BSTreeNode* mRootNode;
};