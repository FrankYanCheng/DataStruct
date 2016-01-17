#include<iostream>
#include<string>
using namespace std;
int BinarySearch(int k[], int key, int lengths)
{
	int low = 0;
	int high = lengths;
	int mid;
	while (high >= low)
	{
		mid = (low + high) / 2;
		if (key == k[mid])
		{
			return mid;
		}
		if (key>k[mid])
		{
			low = mid + 1;
		}
		if (key < k[mid])
		{
			high = mid -1;
		}
	}
	return -1;
}
int BinarySearch_Recursion(int k[], int key, int start,int end)
{
	
	int mid;
	mid = (start+end) / 2;
	if (end < start)
		return -1;
	if (key == k[mid])
	{
		return mid;
	}
	if (key>k[mid])
	{
	return	BinarySearch_Recursion(k, key, mid+1, end);
	}
	if (key <k[mid])
	{
	return	BinarySearch_Recursion(k, key, start, mid-1);
	}

	
}
void main()
{
	const int length = 10000;
	int k[length];
	for (int i = 0; i < length; i++)
	{
		k[i] = i;
	}
	cout << BinarySearch(k, 789, length) << endl;
	cout << BinarySearch_Recursion(k, 789, 4000, length) << endl;
}
