#include "iostream"
using namespace std;

class HeroFighter {

public:
	virtual int Power() {

		return 10;
	}

};

class AdvHeroFighter : public HeroFighter {

public:
	int Power() {

		return 20;
	}
protected:
private:
};

class EnemyFighter {

public:
	int attack() {

		return 15;
	}
protected:
private:
};



void main01() {

	HeroFighter hf;
	EnemyFighter ef;
	AdvHeroFighter advHf;

	if (hf.Power() < ef.attack()) {

		cout<<"Ӣ�۹��ˡ�����"<<endl;
	} else {

		cout<<"Ӣ��win������"<<endl;
	}

	if (advHf.Power() < ef.attack()) {

		cout<<"Ӣ��2���ˡ�����"<<endl;
	} else {

		cout<<"Ӣ��2win������"<<endl;
	}
	system("pause");
}


//�൱����Ŀ�ܰѡ�������
void ObjPlay(HeroFighter *pHf, EnemyFighter *peEf) {

	//��̬�Ĵ���
	if (pHf->Power() < peEf->attack()) {

		cout<<"Ӣ�۹��ˡ�����"<<endl;
	} else {

		cout<<"Ӣ��win������"<<endl;
	}

}

void main() {
	HeroFighter hf;
	EnemyFighter  ef;
	AdvHeroFighter advHf;

	ObjPlay(&hf, &ef);
	ObjPlay(&advHf, &ef);
}