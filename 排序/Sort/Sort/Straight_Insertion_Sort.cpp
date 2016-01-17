#include "Straight_Insertion_Sort.h";
int *Straight_Insertion_Sort::Sort(int counts, int *k)
{
	int *temp_array = k;
	int temp = 0;
	for (int i = 0; i <counts-1; i++)
	{
		int j = i + 1; temp = k[j];
		while (j>0&&temp<k[i])
		{
			k[j] = k[j - 1];
			j--;
		}
		k[j]= temp;
	
	}
	
	return k;
};

int *Straight_Insertion_Sort::binary_sort(int counts, int *k)
{
	int temp = 0,mid, high,low;
	
		for (int i = 1; i <counts; i++)
		{

			low = 0; high = i-1;
			temp = k[i];
			while (low<=high)
			{
				mid = (low + high) / 2;
				if (k[mid]>k[i])
				{
					high = mid - 1;
				}
				else
					low = mid + 1;
			}
			for (int s = i-1; s >high; s--)
			{
				k[s+1] = k[s];
			}
			k[low] = temp;
		}
	
	return k;
}

