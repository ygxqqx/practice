
// myop.h
//ctrl+shift+uת��д
//ctrl+u תСд
#ifndef _INC_MY_OP_H
#define _INC_MY_OP_H

#ifdef  __cplusplus
extern "C" {
#endif

typedef struct _Teacher
{
	int infoId;
	char name[64];
	int age;
	char studentInfo[1024]; //s1,s2,s3,
}Teacher;

//�����ʦ
int AddTeacher(char *pfileName, Teacher *pTe);

//��ʾ��ʦ
int ModifyTeacher(char *pfileName, Teacher *pTe);


#ifdef  __cplusplus
}
#endif

#endif 