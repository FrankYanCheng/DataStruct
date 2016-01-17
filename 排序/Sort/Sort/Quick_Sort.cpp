#include "Quick_Sort.h"


Quick_Sort::Quick_Sort()
{
	
}
int Quick_Sort::partition(int *&k, int low, int high)
{
	int key = k[low];
	while (low < high)
	{
		while (low<high&&k[high]>=key)
			high--;
			k[low] = k[high];
		while (low < high&&k[low]<=key)
			low++;
		k[high] = k[low];
	}
	k[low] = key;
	return low;
}
void Quick_Sort::sort(int *k, int low, int high)
{
	if (low < high)
	{
		int key = partition(k, low, high);
		sort(k,low, key - 1);
		sort(k,key + 1, high);
	}

}


Quick_Sort::~Quick_Sort()
{
}
