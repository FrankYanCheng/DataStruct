#include<iostream>
#include<string>
using namespace std;
void get_Next(string T,int next[])
{
	next[0] = 0;
	string::size_type i = 1, j = 0;
	while (i <= T.size()-1)
	{
		if (j == 0 || T[i] == T[j])
		{
			cout << next[i] << endl;
			++i; ++j;
			next[i] = j;
		}
		else
			j = next[j];
	}
}
void main()
{
	string word = "abaabcac";
	int *next = new int[9];
	get_Next(word, next);
}