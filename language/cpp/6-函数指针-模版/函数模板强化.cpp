#include "iostream"
using namespace std;

/*
int printArray(int *a, int num)
{

	for (int i=0; i<num; i++)
	{
		cout<<a[i]<<endl;
	}
	return 0;
}
*/

//template告诉编译器要进行泛型编程 typename告诉编译器T为参数会类型,你不要随便报错
template<typename T>
int printArray(T *a, int num) {
	for (int i=0; i<num; i++) {
		cout<<a[i]<<endl;
	}
	return 0;
}

//template<typename T>
template<class T>
int sortArray(T *a, int num) {
	T tmp ;
	for (int i=0; i<num; i++) {
		for (int j=i+1; j<num; j++) {
			if (a[i] < a[j]) {
				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
	}
	return 0;
}

//template<typename T>
template<typename T1, typename T2>
int sortArray2(T1 *a, T2 num) {
	T1 tmp ;
	for (int i=0; i<num; i++) {
		for (int j=i+1; j<num; j++) {
			if (a[i] < a[j]) {
				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
	}
	return 0;
}

void main() {
	/*
	int a[] = {1,3,3,4,45,5,5,5,51,5543,33};
	int num = sizeof(a)/sizeof(a[0]);
	printArray<int>(a, num);
	sortArray<int>(a, num);
	printArray<int>(a, num);
	*/
	char buf[] = "dfdsafdsafdsafdaaaaaaafffff";
	int buflen = strlen(buf);
	printArray<char>(buf, buflen);
	sortArray2<char, int>(buf, buflen);
	printArray<char>(buf, buflen);
	//printArray(a, num);
	system("pause");
}