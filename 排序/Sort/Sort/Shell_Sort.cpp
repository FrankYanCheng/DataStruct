#include "Shell_Sort.h"
#include "Straight_Insertion_Sort.h"
Shell_Sort::Shell_Sort(int index, int destance)
{
	this->destance = destance;
	this->index = index;
}

//index��ÿ�μ�С�ľ��룬destance�ǽ���ʱ��ľ���
int *Shell_Sort::Sort(int *k,int counts)
{
	int temp;
	while (destance >= 0)
	{
		for (int i = 0; i < counts - destance; i++)
		{
			if (k[i]>k[i + destance])
			{
				temp = k[i + destance];
				k[i + destance] = k[i];
				k[i] = temp;
				
			}
		}
		destance = destance - index;
	}
	
	Straight_Insertion_Sort sorts;
	return sorts.Sort(counts,k);
    
}
Shell_Sort::~Shell_Sort()
{
}