#include <iostream>
using namespace std;

class stringCharacter{

private:
	char *str;

public:
	stringCharacter();
	int GetString(char *str2);
	int GetString_Adv(char **str2);
	int GetString_Adv_Free1(char *str2);
	int GetString_Adv_Free2(char **str2);

};