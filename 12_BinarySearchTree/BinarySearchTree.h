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
	//�������
	void InorderWalk() const;
	//ǰ�����
	void PreorderWalk() const;
	//�������
	void PostorderWalk() const;
	//����(�ݹ�汾)
	BSTreeNode* SearchRecursive(int key) const;
	//����(����)
	BSTreeNode* Search(int key) const;
	//��ȡ��СԪ�ؽڵ�(�ݹ�)
	BSTreeNode* MinimumRecursive() const;
	//��ȡ��СԪ�ؽڵ�(����)
	BSTreeNode* Minimum() const;
	//������Ԫ��(�ݹ�)
	BSTreeNode* MaximumRecursive() const;
	//������Ԫ��(����)
	BSTreeNode* Maximum() const;
	//ǰ��
	BSTreeNode* Successor(BSTreeNode* pNode) const;
	//���
	BSTreeNode* Predecessor(BSTreeNode* pNode) const;
	//����һ���ڵ�
	void Insert(BSTreeNode* pNewNode);
	//ɾ��һ���ڵ�
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
	//�ڶ����������У��ýڵ�V�滻�ڵ�U��ʹ�ڵ�V��Ϊ�ڵ�U˫�׵ĺ��ӽڵ�
	void Transplant(BSTreeNode* pNodeU, BSTreeNode* pNodeV);
private:
	BSTreeNode* mRootNode;
};