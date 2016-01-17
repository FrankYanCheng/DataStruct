//¼òµ¥µÄ×Ö·ûÆ¥Åä
#include<iostream>
#include<string>
using namespace std;
int Index(string &word, string &index_word)
{
   string::size_type i = 0, j = 0;
   while (i <word.size()&&j <index_word.size())
   {
	   if (word[i]== index_word[j])
	   {
		   i++; j++;
	   }
	   else
	   {
		   i = i - j + 1; j = 0;
	   }
   }
   if (j < index_word.size())
	   return 0;
   else
	   return i - j;
}
//void main()
//{
//	string word;
//	string index_word;
//	cin >> word;
//	cin >> index_word;
//	cout << Index(word, index_word);
//
//}