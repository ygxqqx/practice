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
		cout<<"Ӣ�۹��ˡ�����"<<endl;
	}
	else
	{
		cout<<"Ӣ��win������"<<endl;
	}

	if (advHf.Power() < ef.attack())
	{
		cout<<"Ӣ��2���ˡ�����"<<endl;
	}
	else
	{
		cout<<"Ӣ��2win������"<<endl;
	}
	system("pause");
}


//д��һ����ܣ����Ե���
//�ҵĵ�3��ս��������ֵ�ʱ�����ڿ�ܳ��ֵ�ʱ�䡣������
//��� ��ʹ�ú����� д�Ĵ��������������
//�������3�����
/*
��װ
	ͻ����C���Ժ����ĸ����

�̳�
	���븴�� ���������Ҹ���ԭ��д�õĴ��롣����

��̬
	��̬����ʹ��δ������������80���д��һ����ܡ�����������90��д�Ĵ���
	��̬�����������ҵ׷Ѱ��һ��Ŀ�ꡣ����
////
*/


//��Ӹ�ֵ������3������
//1 ������������������
//2 �������� ��������
//3 *p 


//��̬��������������
//1 Ҫ�м̳�
//2 Ҫ�к�����д������C �麯��
//3 Ҫ�и���ָ�루�������ã�ָ���������
//

//�൱����Ŀ�ܰѡ�������
void ObjPlay(HeroFighter *pBase, EnemyFighter *peEf)
{
	//��̬�Ĵ���
	if (pBase->Power() < peEf->attack())
	{
		cout<<"Ӣ�۹��ˡ�����"<<endl;
	}
	else
	{
		cout<<"Ӣ��win������"<<endl;
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