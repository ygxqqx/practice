
// myop.h
//ctrl+shift+u转大写
//ctrl+u 转小写
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

//添加老师
int AddTeacher(char *pfileName, Teacher *pTe);

//显示老师
int ModifyTeacher(char *pfileName, Teacher *pTe);


#ifdef  __cplusplus
}
#endif

#endif 