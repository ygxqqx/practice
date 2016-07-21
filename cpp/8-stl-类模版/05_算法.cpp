#include "iostream"
#include "vector"
#include "cmath"
#include "algorithm"
using namespace std;



/*

void sort(_RanIt _First, _RanIt _Last, _Pr _Pred)

	void _Sort(_RanIt _First, _RanIt _Last, _Diff _Ideal, _Pr _Pred)

	void _Insertion_sort(_BidIt _First, _BidIt _Last, _Pr _Pred)

	void _Insertion_sort1(_BidIt _First, _BidIt _Last, _Pr _Pred, _Ty *)

	_Debug_lt_pred  _DEBUG_LT_PRED(_Pred, _Val, *_First))
	_Pred（比较函数）
	*/

void myPrintFunc(int &v) {
	cout<<v<<endl;
}

int mycompare(const int &a, const int &b) {
	return a<b;
}
struct Teacher {
	char name[100];
	int age;
};
void main() {
	vector<int> v(10);

	for (int i=0; i<10; i++) {
		v[i] = rand() % 10;
	}

	for (int i=0; i<10; i++) {
		printf("%d ", v[i]);
	}

	for_each(v.begin(), v.end(), myPrintFunc);

	//stl对数组进行排序的时候，stl实现了排序算法，但是排序的标准，可以有用户自己来定义
	sort(v.begin(),v.end(),mycompare);

	for (int i=0; i<10; i++) {
		printf("%d ", v[i]);
	}


	system("pause");
}