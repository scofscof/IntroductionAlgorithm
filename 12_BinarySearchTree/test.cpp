#include "BinarySearchTree.h"
#include "../Common/Utility.h"
#include <cassert>

int main()
{
	using std::cout;
	using std::endl;

	BinarySearchTree bsTree;
	BSTreeNode node[] = { 2,1,7,3,6,5,9,15,4 };
	constexpr size_t nCount = SizeofArray(node);
	for (size_t i = 0u; i < nCount;++i)
	{
		bsTree.Insert(&node[i]);
	}

	//���
	cout << "�������������Ϊ:";
	bsTree.InorderWalk();
	cout << endl;

	cout << "ǰ�����������Ϊ:";
	bsTree.PreorderWalk();
	cout << endl;

	cout << "�������������Ϊ:";
	bsTree.PostorderWalk();
	cout << endl;

	//ǰ��
	assert(nCount > 5);
	cout << "��С�ڵ�ֵΪ:" << bsTree.Minimum()->key << endl;
	cout << "��С�ڵ�ֵΪ(�ݹ�):" << bsTree.MinimumRecursive()->key << endl;
	cout << "���ڵ�ֵΪ:" << bsTree.Maximum()->key << endl;
	cout << "���ڵ�ֵΪ(�ݹ�):" << bsTree.MaximumRecursive()->key << endl;
	cout << "�ڵ�" << node[3].key << "�ĺ��Ϊ"<<bsTree.Successor(&node[3])->key<<endl;
	cout << "�ڵ�" << node[2].key << "��ǰ��Ϊ" << bsTree.Predecessor(&node[2])->key << endl;
	assert(bsTree.Search(8) == nullptr);
	assert(bsTree.Search(4)->key == 4);
	assert(bsTree.Search(10) == nullptr);
	assert(bsTree.Search(9)->key == 9);
	//ɾ��
	bsTree.Delete(&node[3]);
	cout << "ɾ���ڵ�"<<node[3].key<<"��,�������������Ϊ:";
	bsTree.InorderWalk();
	cout << endl;

	system("pause");
	return 0;
}