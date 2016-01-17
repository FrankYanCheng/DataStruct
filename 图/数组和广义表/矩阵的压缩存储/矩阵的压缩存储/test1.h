#include <iostream> #include <iomanip> using namespace std;   
template<class T> //三元组 
struct Trituple {   int row;  int col;  T val; }; //稀疏矩阵声明  
template<class T> 
class SparseMatrix
{ 
public:   SparseMatrix(int maxt=100);
           ~SparseMatrix(); 
		   bool TransposeTo(SparseMatrix &); 
		   bool AddTo(const SparseMatrix&);  
		   bool TransposeTo_Faster(SparseMatrix&);  
		   void Input();  
		   void Output();
private:   Trituple<T>* data; 
		   int rows,cols,terms; 
		   int maxterms;
};  
template<class T>  SparseMatrix<T>::SparseMatrix(int maxt) 
{  
	maxterms=maxt;  
	data=new Trituple<T>[maxterms];
	terms=rows=cols=0; 
} 
template<class T>  SparseMatrix<T>::~SparseMatrix() 
{ 
	if (data!=NULL)
	{    delete[] data; 
	}
}

