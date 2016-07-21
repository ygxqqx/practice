#include "stdlib.h"
#include "stdio.h"
#include "string.h"

//int * char *
//c语言里面没有字符串这种类型。。。。。
//通过字符数组来模拟字符串
//C风格字符串是以零结尾的字符串
//
void main11() {
	//字符数组初始化
	//指定长度 如果定义的长度剩余部分补充0
	char buf1[100] = {'a', 'b', 'c'};
	//不指定长度
	char buf2[] = {'a', 'b', 'c'};
	char buf3[] = {'a', 'b', 'c','\0'};

	//通过字符串初始化字符数组 并且追加\0
	char buf4[] = "abcdefg";

	printf("%s\n", buf4 );

	system("pause");
}

//sizeof
void main12() {
	//字符数组初始化
	//指定长度 如果定义的长度剩余部分补充0
	char buf1[100] = {'a', 'b', 'c'};
	//不指定长度
	char buf2[] = {'a', 'b', 'c'};
	char buf3[] = {'a', 'b', 'c','\0'};

	//通过字符串初始化字符数组 并且追加\0
	char buf4[] = "abcd";

	printf("%s\n", buf4 );
	printf("sizeof(buf4): %d\n ", sizeof(buf4)); //注意sizeof是对数组类型进行大小测量 包括了\0
	printf("strlen(buf4): %d \n", strlen(buf4));//strlen是求字符串的长度不包括\0

	system("pause");
}

//操作数组的方法
//下标法和指针法
void main() {
	int i = 0;
	char *p = NULL;
	//通过字符串初始化字符数组 并且追加\0
	char buf4[] = "abcd";
	
	for (i=0; i<strlen(buf4); i++) {
		printf("%c", buf4[i]); //p[]
	}
	
	//[] *的本质到底是什么？
	//*p 是我们程序员手工的（显示）去利用间接赋值
	//【】 只不过是，c/c++ 编译器帮我们做了一个*p的操作。。。。。。
	// buf4[i]======> buf4[0+i] ====>  *(buf4+i)
	//===*(buf4+i)   --> bu4[i];


	printf("\n");

	p = buf4;
	for (i=0; i<strlen(buf4); i++) {
		printf("%c", *(p+i)); //*p 
	}

	system("pause");
}