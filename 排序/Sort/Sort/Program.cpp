#include<iostream>
#include<string>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#ifndef  Sort_H
#define Sort_H
#include "Straight_Insertion_Sort.h"
#include "Shell_Sort.h"
#include "Bubble_Sort.h"
#include "Test.h"
#include "Quick_Sort.h"
#endif
#define random(x) (rand()%x)
using namespace std;
void Array_intial(int *&k,int counts)
{
	for (int i = 0; i < counts; i++)
	{
		k[i] = random(1000);
	}
}
void main()
{
	const int counts =15;
	cout <<"排序情况含"<<counts<<"个元素"<< endl;
	//Straight_Insertion_Sort  sort;
	int *k = new int[counts];
	Array_intial(k, counts);
	////clock_t start_1, ends_1;
	////start_1 = clock(); 
	////int *test1_array = sort.Sort(counts, k);/*for (int i = 0; i < counts; i++)
	////cout << test1_array[i] << endl;*/
	////ends_1 = clock(); cout << "直接插入排序时间差：" << ends_1 - start_1 << endl; Array_intial(k, counts);
	////cout << "-----------------------" << endl; 
	////clock_t start, ends; start = clock();
	////Shell_Sort sorts(3,22);
	////int *test2_array = sorts.Sort(k,counts);
	////ends = clock();
	////cout << "希尔排序时间差："<<ends-start << endl; 
	////cout << "-----------------------" << endl; Array_intial(k, counts);
	////clock_t B_start, B_ends; B_start = clock();
	////Bubble_Sort bubble_sort;
 ////   int *test3_array=bubble_sort.Sort(k, counts);
	////B_ends = clock();
	////cout << "冒泡排序时间差：" << B_ends - B_start << endl; 
	////cout << "-----------------------" << endl; Array_intial(k, counts);
	////clock_t C_start, C_ends; C_start = clock();
	////int *test4_array = sort.binary_sort(counts, k);
	////C_ends = clock(); 
	////cout << "折半插入时间：" << C_ends - C_start << endl;
	////cout << "-----------------------" << endl; Array_intial(k, counts);
	//
	//Quick_Sort quick_sort; clock_t D_start, D_ends; D_start = clock();
	//quick_sort.sort(k, 0, counts-1); 
	//D_ends = clock();
	//cout << "快速排序时间：" << D_ends - D_start << endl;
	//for (int i = 0; i < counts; i++)
	//	cout << k[i] << endl;
	//int k[] = { 0, 1, 0, 0, 1, 1, 0, 1,2,2,2,1,0,0,0,1 };
	Test t;
	t.Compare_Sort(k, counts);
	for (int i = 0; i < counts; i++)
		cout << k[i] << endl;




}