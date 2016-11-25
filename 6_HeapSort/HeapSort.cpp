#include "../Common/GameTimer.h"
#include <iostream>
using namespace std;
//����i�ĸ��ڵ�,����ʱ�����0��ʼ
int Parent(int i)
{
	return (i - 1)>>1 ;
}

//����i������
int Left(int i)
{
	return (i<<1) + 1;
}
//����i���Һ���
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

//�ݹ顣�ٶ�i�����������������Ѿ������ѣ�����arr[i],ʹi��Ϊ����.
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
//ѭ�� ��������
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