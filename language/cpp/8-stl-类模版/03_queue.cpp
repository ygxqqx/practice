#include "iostream"
#include "queue"
using namespace std;

void main1() {
	queue<int> q;
	for (int i=0; i<5; i++) {
		q.push(i+1);
	}

	while (!q.empty()) {
		//获取队列的第一个元素
		int tmp = q.front();
		printf("tmp:%d ", tmp);
		q.pop();
	}
	
	system("pause");
}

struct Teacher {
	char name[64];
	int age ;
};

void printQ(queue<Teacher *>  &myq) {
	while (!myq.empty()) {
		Teacher *tmp = myq.front();
		if (tmp != NULL) {
			printf("tmp:age : %d ", tmp->age);
		}
		myq.pop();
	}
}

void main() {
	queue<Teacher *> q;
	Teacher t1, t2, t3;
	t1.age = 32;
	t2.age = 33;
	t3.age = 34;

	q.push(&t1);
	q.push(&t2);
	q.push(&t3);

	printQ(q);
	system("pause");
}