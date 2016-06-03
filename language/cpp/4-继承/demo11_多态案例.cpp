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

		cout<<"Ó¢ÐÛ¹ÒÁË¡£¡£¡£"<<endl;
	} else {

		cout<<"Ó¢ÐÛwin¡£¡£¡£"<<endl;
	}

	if (advHf.Power() < ef.attack()) {

		cout<<"Ó¢ÐÛ2¹ÒÁË¡£¡£¡£"<<endl;
	} else {

		cout<<"Ó¢ÐÛ2win¡£¡£¡£"<<endl;
	}
	system("pause");
}


//Ïàµ±ÓÚÄãµÄ¿ò¼Ü°Ñ¡£¡£¡£¡£
void ObjPlay(HeroFighter *pHf, EnemyFighter *peEf) {

	//¶àÌ¬µÄ´æÔÚ
	if (pHf->Power() < peEf->attack()) {

		cout<<"Ó¢ÐÛ¹ÒÁË¡£¡£¡£"<<endl;
	} else {

		cout<<"Ó¢ÐÛwin¡£¡£¡£"<<endl;
	}

}

void main() {
	HeroFighter hf;
	EnemyFighter  ef;
	AdvHeroFighter advHf;

	ObjPlay(&hf, &ef);
	ObjPlay(&advHf, &ef);
}