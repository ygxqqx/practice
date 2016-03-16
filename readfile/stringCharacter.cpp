#include "stringCharacter.h"


stringCharacter::stringCharacter():str("   i am student, you are teacher   "){
}

int stringCharacter::GetString(char *str2){

	if(str == NULL)
		return 0;

	char *p = str;
	int len = strlen(str);
	//printf("len: %d", len);
	int i;
	
	for(i = 0; i < len; ++i){
		
		if(isalpha(*(p+1+i)) && isspace(*(p+i))){
			str2[i] = *(p+i);
			str2[i+1] = toupper(*(p+i+1));
			i++;
		}
		else
			str2[i] = *(p+i);
	}
	return 1;
}


int stringCharacter::GetString_Adv(char **str2){
	if(str == NULL)
		return 0;

	int len = strlen(str);
	char *buf = (char *)malloc((len+1) * sizeof(str2));
	memset(buf, 0 ,(len+1) * sizeof(buf));
	char *p = str;
	
	//printf("len: %d", len);
	int i;
	
	for(i = 0; i < len; ++i){
		
		if(isalpha(*(p+1+i)) && isspace(*(p+i))){
			buf[i] = *(p+i);
			buf[i+1] = toupper(*(p+i+1));
			i++;
		}
		else
			buf[i] = *(p+i);
	}
	*str2 = buf;
	return 1;
}


int stringCharacter::GetString_Adv_Free1(char *str2){

	return 0;
}


int stringCharacter::GetString_Adv_Free2(char **str2){

	return 0;
}