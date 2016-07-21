#include "iostream"
#include "list"
using namespace std;




void main01() {
	list<int> l;

	cout<<l.size()<<endl;

	for (int i=0; i<5; i++) {
		l.push_back(i+1);
	}
	cout<<l.size()<<endl;

	
	list<int>::iterator current = l.begin();

	while (current != l.end()) {
		cout<<*current<<endl;
		current ++;
	}


	//��ȡ����Ŀ�ͷ����ֵ��������
	current = l.begin(); //0
	current ++; //1
	current ++; //2
	current ++; //3
	l.insert(current, 100);

	printf("\n����λ�ò��ԣ������ж��Ǵ�0λ�ÿ�ʼ�����Ǵ�1λ�ÿ�ʼ\n");
	for (list<int>::iterator p = l.begin(); p!= l.end(); p++) {
		cout<<*p<<" ";
	
	}
	system("pause");
}

struct Teacher {
	char name[64];
	int age;
};

void main02() {
	list<Teacher> l;

	Teacher t1, t2, t3;
	t1.age = 11;
	t2.age = 12;
	t3.age = 13;

	l.push_back(t1);
	l.push_back(t2);
	l.push_back(t3);

	for (list<Teacher>::iterator p = l.begin(); p!=l.end();p++) {
		printf("tmp:%d ", p->age);
	}
	system("pause");

}


void main() {
	list<Teacher *> l;

	Teacher t1, t2, t3;
	t1.age = 11;
	t2.age = 12;
	t3.age = 13;

	l.push_back(&t1);
	l.push_back(&t2);
	l.push_back(&t3);

	for (list<Teacher *>::iterator p = l.begin(); p!=l.end(); p++) {
		Teacher * tmp  = *p;
		printf("tmp:%d ", tmp->age);
	}

	system("pause");
}