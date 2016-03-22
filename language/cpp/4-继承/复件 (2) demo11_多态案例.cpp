#include "iostream"
using namespace std;

class HeroFighter
{
public:
	virtual int Power()
	{
		return 10;
	}

};

class AdvHeroFighter : public HeroFighter
{
public:
	int Power()
	{
		return 20;
	}
protected:
private:
};

class Adv2HeroFighter : public HeroFighter
{
public:
	int Power()
	{
		return 30;
	}
protected:
private:
};

class EnemyFighter
{
public:
	int attack()
	{
		return 15;
	}
protected:
private:
};



void main01()
{
	HeroFighter hf;
	EnemyFighter  ef;
	AdvHeroFighter advHf;
	

	if (hf.Power() < ef.attack())
	{
		cout<<"英雄挂了。。。"<<endl;
	}
	else
	{
		cout<<"英雄win。。。"<<endl;
	}

	if (advHf.Power() < ef.attack())
	{
		cout<<"英雄2挂了。。。"<<endl;
	}
	else
	{
		cout<<"英雄2win。。。"<<endl;
	}
	system("pause");
}


//写了一个框架，可以调用
//我的第3代战机代码出现的时间晚于框架出现的时间。。。。
//框架 有使用后来人 写的代码的能力。。。
//面向对象3大概念
/*
封装
	突破了C语言函数的概念。。

继承
	代码复用 。。。。我复用原来写好的代码。。。

多态
	多态可以使用未来。。。。。80年代写了一个框架。。。。。。90人写的代码
	多态是我们软件行业追寻的一个目标。。。
////
*/


//间接赋值成立的3个条件
//1 定义两个变量。。。
//2 建立关联 。。。。
//3 *p 


//多态成立的三个条件
//1 要有继承
//2 要有函数重写。。。C 虚函数
//3 要有父类指针（父类引用）指向子类对象
//

//相当于你的框架把。。。。
void ObjPlay(HeroFighter *pBase, EnemyFighter *peEf)
{
	//多态的存在
	if (pBase->Power() < peEf->attack())
	{
		cout<<"英雄挂了。。。"<<endl;
	}
	else
	{
		cout<<"英雄win。。。"<<endl;
	}
}

void main()
{
	HeroFighter hf;
	EnemyFighter  ef;
	AdvHeroFighter advHf;
	Adv2HeroFighter  adv3Hf;

	ObjPlay(&hf, &ef);
	ObjPlay(&advHf, &ef);
	ObjPlay(&adv3Hf, &ef);

}