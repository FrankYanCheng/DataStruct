#include "Test.h"
#include<iostream>
using namespace std;
Test::Test()
{
}
void Test::swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
	
}
int *Test::Sort(int *k, int counts)
{
	int j = 0, i = 0,n=counts-1;
	while (j<=n)
	{
		switch (k[j])
		{
		case 0:
			swap(k[i], k[j]);
			i++; j++;
			break;
		case 1:
			j++;
			break;
		case 2:
			swap(k[j], k[n]);
				n--;
				break;
		}
	}
	return k;
}
int *Test::Compare_Sort(int *k, int counts)
{
	int j = 0, i = 0, n = counts - 1;
	int index = k[(counts - 1) / 2]; int values;//用于值的比较
	std::cout << index << "------------------------"<<endl;
	while (j <= n)
	{
		values = k[j] - index;
		if (values < 0)
		{
			swap(k[i], k[j]);
			i++; j++;
		}
		if (values==0)
			j++;
		if (values>0)
		{
			swap(k[j], k[n]);
			n--;
		}
		
	}
	return k;
}

Test::~Test()
{
}
