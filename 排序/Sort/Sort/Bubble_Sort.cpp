#include "Bubble_Sort.h"


Bubble_Sort::Bubble_Sort()
{
}

int *Bubble_Sort::Sort(int *k, int counts)
{
	int temp; int *temp_array = k;
	for (int j = 0; j < counts;j++)
		for (int i = j; i < counts+1; i++)
		{
			if (k[i] >= k[i + 1])
			{
				temp = k[i];
				k[i] = k[i + 1];
				k[i + 1] = temp;
			}
		}
	
	return k;
}
Bubble_Sort::~Bubble_Sort()
{
}
