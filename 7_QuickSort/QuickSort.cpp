#include <iostream>
using namespace std;

void swap(int& a,int& b)
{
	int t = a;
	a = b;
	b = t;
}

int Partition(int* arr,int len,int p,int r)
{
	int x = arr[r];
	int i = p - 1;
	for (int j=p;j <= r;++j)
	{
		if (arr[j] <= x)
		//if (arr[j] >= x)
		{
			++i;
			swap(arr[i],arr[j]);
		}
	}
	return i;
}

int RandomPartition(int* arr,int len,int p,int r)
{
	//随机版本的partition。获取随机函数时，没有使用种子，所以每次随机都是一样的
	int i = p + rand()%(r-p+1);
	swap(arr[r],arr[i]);
	return Partition(arr,len,p,r);
}

void PrintArr(int *arr, int nLen)
{
	for (int i = 0; i < nLen; i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

void QuickSort(int* arr,int len,int p,int r)
{
	if (p < r)
	{
		//int q = Partition(arr,len,p,r);
		int q = RandomPartition(arr,len,p,r);
		QuickSort(arr,len,p,q-1);
		QuickSort(arr,len,q+1,r);
		PrintArr(arr, len);
	}
}

int main()
{
	int arr[] = {13,19,9,5,12,8,7,4,21,2,6,11};

	int nSize = sizeof(arr)/sizeof(arr[0]);
	
	PrintArr(arr, nSize);

	QuickSort(arr, nSize,0,nSize-1);

	system("pause");
}