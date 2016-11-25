#include <iostream>
#include <time.h>
#include <sys/timeb.h>
#include <cassert>
#include "../Common/GameTimer.h"
using namespace std;

struct FindResult
{
	int low;
	int high;
	double sum;
};

FindResult FindMaxCrossSubArray(double* arr,int low,int mid,int high)
{
	FindResult result;
	double leftSum = DBL_MIN , sum = 0;
	for (int i = mid ; i >= low; --i)
	{
		sum += arr[i];
		if(sum > leftSum)
		{
			leftSum = sum;
			result.low = i;
		}
	}
	double rightSum = DBL_MIN;
	sum = 0;
	for (int i = mid + 1 ; i <= high; ++i)
	{
		sum += arr[i];
		if(sum > rightSum)
		{
			rightSum = sum;
			result.high = i;
		}
	}
	result.sum = leftSum + rightSum;

	return result;
}

//查找最大连续子数组-----分治法
FindResult FindMaxSubArray(double* arr,int low,int high)
{
	FindResult result;
	if (low == high)
	{
		result.low = result.high = low;
		result.sum = arr[low];
		return result;
	}
	else
	{
		int mid = (low+high)/2;
		FindResult leftResult = FindMaxSubArray(arr,low,mid);
		FindResult rightResult = FindMaxSubArray(arr,mid+1,high);
		FindResult crossResult = FindMaxCrossSubArray(arr,low,mid,high);
		if (leftResult.sum >= rightResult.sum && leftResult.sum >= crossResult.sum)
		{
			return leftResult;
		}
		else if (rightResult.sum >= leftResult.sum && rightResult.sum >= crossResult.sum)
		{
			return rightResult;
		}
		else
		{
			return crossResult;
		}
	}
}

//查找最大连续子数组，暴力求解法
FindResult FindMaxSubArray_2(double* arr,int low,int high)
{
	FindResult result;
	result.sum = DBL_MIN;
	for (int i = low; i <= high ;++i )
	{
		FindResult curResult;
		curResult.sum = 0;
		curResult.low = i;
		for(int j = i;j <= high;++j)
		{
			curResult.high = j;
			curResult.sum += arr[j];
			if (curResult.sum > result.sum)
			{
				result.low = curResult.low;
				result.high = curResult.high;
				result.sum = curResult.sum;
			}
		}
	}
	return result;
}

int main()
{
	srand(time(0));
	const int cnt = 200;
	GameTimer gameTimer;
	//gameTimer.Start();
	float time2 = 0.0f,time1 = 0.0f,time3 = 0.0f;
	for (int c = 0;c<=5000;++c)
	{
		gameTimer.Reset();
		double arr[cnt] ;
		for (int i=0;i<cnt;++i)
		{
			arr[i] = rand()%100 - 50.0;
		}
		gameTimer.Tick();
		time3 += gameTimer.DeltaTime();
		gameTimer.Reset();
		FindResult res1 = FindMaxSubArray_2(arr,0,sizeof(arr)/sizeof(arr[0]) - 1);
		gameTimer.Tick();
		time1 += gameTimer.DeltaTime();
		gameTimer.Reset();
		FindResult res2 = FindMaxSubArray(arr,0,sizeof(arr)/sizeof(arr[0]) - 1);
		gameTimer.Tick();
		time2 += gameTimer.DeltaTime();
		//assert(res1.low == res2.low);
		//assert(res1.high == res2.high);
		assert(res1.sum == res2.sum);
	}
	
	cout << "time1:"<<time1<<endl;
	cout << "time2:"<<time2<<endl;
	cout << "time3:"<<time3<<endl;
	//cout<<res1.sum<<endl;
	//cout<<res1.low<<endl;
	//cout<<res1.high<<endl;

	system("pause");
}
