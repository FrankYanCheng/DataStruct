using namespace std;
class Shell_Sort
{
public:
	//确定间距，和递进的距离
	Shell_Sort(int index,int destance);
	~Shell_Sort();
	int *Sort(int *k,int counts);


private:
	int index, destance;

};

