#include "../Common/GameTimer.h"
#include <iostream>
using namespace std;
//返回i的父节点,计算时数组从0开始
int Parent(int i)
{
	return (i - 1)>>1 ;
}

//返回i的左孩子
int Left(int i)
{
	return (i<<1) + 1;
}
//返回i的右孩子
int Right(int i ) 
{
	return (i<<1) + 2;
}

void swap(int& a,int& b)
{
	int t = a;
	a = b;
	b = t;
}

//递归。假定i的左子树和右子树已经是最大堆，调整arr[i],使i成为最大堆.
void MaxHeapifyRecursive(int* arr,int len,int i)
{
	int l = Left(i);
	int r = Right(i);
	int largest = i;
	if (l<len && arr[l] > arr[i])
	{
		largest = l;
	}
	if (r < len && arr[r] > arr[largest])
	{
		largest = r;
	}
	if (largest != i)
	{
		swap(arr[i],arr[largest]);
		MaxHeapifyRecursive(arr,len,largest);
	}
}
//循环 调整最大堆
void MaxHeapifyLoop(int* arr,int len,int i)
{
	int largest = i;
	do 
	{
		i = largest;
		int l = Left(i);
		int r = Right(i);
		if (l<len && arr[l] > arr[i])
		{
			largest = l;
		}
		if (r < len && arr[r] > arr[largest])
		{
			largest = r;
		}
		swap(arr[i],arr[largest]);

	} while (largest != i);
}

//#define  MaxHeapify MaxHeapifyLoop
#define  MaxHeapify MaxHeapifyRecursive

void BuildMaxHeap(int* arr,int len)
{
	for (int i = (len-1)/2;i>=0;--i)
	{
		MaxHeapify(arr,len,i);
	}
}

void HeapSort(int* arr,int len)
{
	BuildMaxHeap(arr,len);
	for (int i = len -1;i >0;--i)
	{
		swap(arr[0],arr[i]);
		MaxHeapify(arr,i,0);
	}
}

void PrintArr(int *arr, int nLen)
{
	for (int i = 0; i < nLen; i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

int main()
{
	int arr[] = {4,22,3,2,16,9,10,14,24,11};

	PrintArr(arr, sizeof(arr)/sizeof(arr[0]));;
	HeapSort(arr, sizeof(arr)/sizeof(arr[0]));

	PrintArr(arr, sizeof(arr)/sizeof(arr[0]));

	system("pause");
}