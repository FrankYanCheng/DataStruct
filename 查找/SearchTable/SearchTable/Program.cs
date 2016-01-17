using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Timers;
namespace SearchTable
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] k = new int[99999999];
            for (int i = 1; i <k.Length; i++)
            {
                k[i] = new Random().Next(0,3);
            }
            int key=-1;
            k[98765432] = key;
            DateTime t1 = DateTime.Now;
           Console.WriteLine(SearchPrototyple(key, k));
           DateTime t2 = DateTime.Now;
           Console.WriteLine(((TimeSpan)(t2 - t1)).TotalMilliseconds);
           DateTime t3 = DateTime.Now;
           Console.WriteLine(Search(key, k));
           DateTime t4 = DateTime.Now;
           Console.WriteLine(((TimeSpan)(t4 - t3)).TotalMilliseconds); 

        }
        static int SearchPrototyple(int key,int[] k)
        {
            for (int i = 1; i < k.Length; i++)
            {
                if (k[i] == key)
                    return i;
             
            }
            return 0;
        }
        static int Search(int key,int []k)
        {
            k[0] = key;
            int i=1;
            while(k[0]!=k[i])
            {
                i++;
            }
            return i;

        }

    }
}
