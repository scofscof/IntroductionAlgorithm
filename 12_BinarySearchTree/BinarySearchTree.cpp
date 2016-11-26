#include "BinarySearchTree.h"
#include "../common/utility.h"
#include <cassert>

using std::cout;
using std::endl;

BSTreeNode::BSTreeNode(int _key)
	:left(nullptr)
	, right(nullptr)
	,parent(nullptr)
	,key(_key)
{

}

BSTreeNode::~BSTreeNode()
{
	
}

std::ostream& operator<<(std::ostream& os, BSTreeNode* pNode)
{
	os << pNode->key;
	return os;
}

////////////////BinarySearchTree////////////////////////////////////////////////
BinarySearchTree::BinarySearchTree()
	:mRootNode(nullptr)
{

}

BinarySearchTree::~BinarySearchTree()
{
	
}

void BinarySearchTree::InorderWalk() const
{
	InorderWalkImpl(mRootNode);
}

void BinarySearchTree::PreorderWalk() const
{
	PreorderWalkImpl(mRootNode);
}

void BinarySearchTree::PostorderWalk() const
{
	PostorderWalkImpl(mRootNode);
}

BSTreeNode* BinarySearchTree::SearchRecursive(int key) const
{
	return SearchRecursiveImpl(mRootNode, key);
}

BSTreeNode* BinarySearchTree::Search(int key) const
{
	return SearchImpl(mRootNode, key);
}

BSTreeNode* BinarySearchTree::MinimumRecursive() const
{
	if (mRootNode == nullptr)
	{
		return nullptr;
	}
	return MinimumRecursiveImpl(mRootNode);
}

BSTreeNode* BinarySearchTree::Minimum() const
{
	if (mRootNode == nullptr)
	{
		return nullptr;
	}
	return MinimumImpl(mRootNode);
}

BSTreeNode* BinarySearchTree::MaximumRecursive() const
{
	if (mRootNode == nullptr)
	{
		return nullptr;
	}
	return MaximumRecursiveImpl(mRootNode);
}

BSTreeNode* BinarySearchTree::Maximum() const
{
	if (mRootNode == nullptr)
	{
		return nullptr;
	}
	return MaximumImpl(mRootNode);
}

BSTreeNode* BinarySearchTree::Successor(BSTreeNode* pNode) const
{
	if (pNode == nullptr)
	{
		return nullptr;
	}
	BSTreeNode* pRight = pNode->right;
	if (pRight != nullptr)
	{
		return MinimumImpl(pRight);
	}
	BSTreeNode* pParent = pNode->parent;
	while (pParent != nullptr && pNode == pParent->right)
	{
		pNode = pParent;
		pParent = pParent->parent;
	}
	return pParent;
}

BSTreeNode* BinarySearchTree::Predecessor(BSTreeNode* pNode) const
{
	if (pNode == nullptr)
	{
		return nullptr;
	}
	BSTreeNode* pLeft = pNode->left;
	if (pLeft != nullptr)
	{
		return MaximumImpl(pLeft);
	}
	BSTreeNode* pParent = pNode->parent;
	while (pParent != nullptr && pNode == pParent->left)
	{
		pNode = pParent;
		pParent = pParent->parent;
	}
	return pParent;
}

void BinarySearchTree::Insert(BSTreeNode* pNewNode)
{
	BSTreeNode* pNodeIterator = mRootNode;
	BSTreeNode* pNewParent = nullptr;
	while (pNodeIterator != nullptr)
	{
		pNewParent = pNodeIterator;
		if (pNewNode->key < pNodeIterator->key)
		{
			pNodeIterator = pNodeIterator->left;
		}
		else
		{
			pNodeIterator = pNodeIterator->right;
		}
	}
	pNewNode->parent = pNewParent;
	if (pNewParent == nullptr)
	{
		mRootNode = pNewNode;
	}
	else if (pNewNode->key < pNewParent->key)
	{
		pNewParent->left = pNewNode;
	}
	else
	{
		pNewParent->right = pNewNode;
	}
}

void BinarySearchTree::Delete(BSTreeNode* pNode)
{
	if (pNode == nullptr)
	{
		return;
	}
	if (pNode->left == nullptr)
	{
		Transplant(pNode, pNode->right);
	}
	else if (pNode->right == nullptr)
	{
		Transplant(pNode, pNode->left);
	}
	else
	{
		BSTreeNode* pSuccessor = MinimumImpl(pNode->right);
		if (pSuccessor->parent != pNode)
		{
			Transplant(pSuccessor, pSuccessor->right);
			pSuccessor->right = pNode->right;
			pSuccessor->right->parent = pSuccessor;
		}
		Transplant(pNode, pSuccessor);
		pSuccessor->left = pNode->left;
		pSuccessor->left->parent = pSuccessor;
	}
}

///implement
void BinarySearchTree::InorderWalkImpl(BSTreeNode* pNode) const
{
	if (pNode != nullptr)
	{
		InorderWalkImpl(pNode->left);
		cout << pNode << "->";
		InorderWalkImpl(pNode->right);
	}
}

void BinarySearchTree::PreorderWalkImpl(BSTreeNode* pNode) const
{
	if (pNode != nullptr)
	{
		cout << pNode << "->";
		PreorderWalkImpl(pNode->left);
		PreorderWalkImpl(pNode->right);
	}
}

void BinarySearchTree::PostorderWalkImpl(BSTreeNode* pNode) const
{
	if (pNode != nullptr)
	{
		PostorderWalkImpl(pNode->left);
		PostorderWalkImpl(pNode->right);
		cout << pNode << "->";
	}
}

BSTreeNode* BinarySearchTree::SearchRecursiveImpl(BSTreeNode* pNode, int key) const
{
	if (pNode == nullptr || pNode->key == key)
	{
		return pNode;
	}
	if (key < pNode->key)
	{
		return SearchRecursiveImpl(pNode->left,key);
	}
	else
	{
		return SearchRecursiveImpl(pNode->right,key);
	}
}

BSTreeNode* BinarySearchTree::SearchImpl(BSTreeNode* pNode, int key) const
{
	while (pNode && key != pNode->key)
	{
		if (key < pNode->key)
		{
			pNode = pNode->left;
		}
		else
		{
			pNode = pNode->right;
		}
	}
	return pNode;
}

BSTreeNode* BinarySearchTree::MinimumRecursiveImpl(BSTreeNode* pNode) const
{
	if (pNode->left == nullptr)
	{
		return pNode;
	}
	return MinimumRecursiveImpl(pNode->left);
}

BSTreeNode* BinarySearchTree::MinimumImpl(BSTreeNode* pNode) const
{
	while (pNode->left != nullptr)
	{
		pNode = pNode->left;
	}
	return pNode;
}

BSTreeNode* BinarySearchTree::MaximumRecursiveImpl(BSTreeNode* pNode) const
{
	if (pNode->right == nullptr)
	{
		return pNode;
	}
	return MaximumRecursiveImpl(pNode->right);
}

BSTreeNode* BinarySearchTree::MaximumImpl(BSTreeNode* pNode) const
{
	while (pNode->right != nullptr)
	{
		pNode = pNode->right;
	}
	return pNode;
}

void BinarySearchTree::Transplant(BSTreeNode* pNodeU, BSTreeNode* pNodeV)
{
	if (pNodeU == nullptr)
	{
		return;
	}
	//节点u是根节点
	if (mRootNode == pNodeU)
	{
		mRootNode = pNodeV;
	}
	else if (pNodeU == pNodeU->parent->left)
	{
		pNodeU->parent->left = pNodeV;
	}
	else
	{
		pNodeU->parent->right = pNodeV;
	}
	//v可以是空节点，这样，相当于将u替换为空节点
	if (pNodeV != nullptr)
	{
		pNodeV->parent = pNodeU->parent;
	}
}

