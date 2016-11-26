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

	//输出
	cout << "中序遍历输出结果为:";
	bsTree.InorderWalk();
	cout << endl;

	cout << "前序遍历输出结果为:";
	bsTree.PreorderWalk();
	cout << endl;

	cout << "后序遍历输出结果为:";
	bsTree.PostorderWalk();
	cout << endl;

	//前驱
	assert(nCount > 5);
	cout << "最小节点值为:" << bsTree.Minimum()->key << endl;
	cout << "最小节点值为(递归):" << bsTree.MinimumRecursive()->key << endl;
	cout << "最大节点值为:" << bsTree.Maximum()->key << endl;
	cout << "最大节点值为(递归):" << bsTree.MaximumRecursive()->key << endl;
	cout << "节点" << node[3].key << "的后继为"<<bsTree.Successor(&node[3])->key<<endl;
	cout << "节点" << node[2].key << "的前驱为" << bsTree.Predecessor(&node[2])->key << endl;
	assert(bsTree.Search(8) == nullptr);
	assert(bsTree.Search(4)->key == 4);
	assert(bsTree.Search(10) == nullptr);
	assert(bsTree.Search(9)->key == 9);
	//删除
	bsTree.Delete(&node[3]);
	cout << "删除节点"<<node[3].key<<"后,中序遍历输出结果为:";
	bsTree.InorderWalk();
	cout << endl;

	system("pause");
	return 0;
}