#include "stdlib.h"
#include "stdio.h"
#include "string.h"
//include "cfg_op.h"

#include "myop.h"
//添加老师
int AddTeacher(char *pfileName, Teacher *pTe)
{
	
	int		ret = 0;
	//准备写配置文件的关键字 根据ID动态构建
	char		Teacher_InfoID[128];
	char 	Teacher_Name[128];
	char 	Teacher_Age[128];
	char 	Teacher_StudentInfo[1024];
	char		infoId[128];
	char		infoAge[128];

	sprintf(Teacher_InfoID, "%s%d", "Teacher_InfoID_",pTe->infoId);
	sprintf(Teacher_Name, "%s%d", "Teacher_Name_",pTe->infoId);
	sprintf(Teacher_Age, "%s%d", "Teacher_Age_",pTe->infoId);
	sprintf(Teacher_StudentInfo, "%s%d", "Teacher_StudentInfo_",pTe->infoId);

	sprintf(infoId, "%d", pTe->infoId);
	sprintf(infoAge, "%d", pTe->age);

	ret =SetCfgItem(pfileName, Teacher_InfoID, infoId , strlen(infoId));
	if (ret != 0)
	{
		printf("func WriteCfgItem() err: %d \n", ret);
		return ret;
	}

	ret =SetCfgItem(pfileName, Teacher_Name, pTe->name , strlen(pTe->name));
	if (ret != 0)
	{
		printf("func WriteCfgItem() err: %d \n", ret);
		return ret;
	}
	ret =SetCfgItem(pfileName, Teacher_Age, infoAge , strlen(infoAge));
	if (ret != 0)
	{
		printf("func WriteCfgItem() err: %d \n", ret);
		return ret;
	}
	ret =SetCfgItem(pfileName, Teacher_StudentInfo, pTe->studentInfo , strlen(Teacher_StudentInfo));
	if (ret != 0)
	{
		printf("func WriteCfgItem() err: %d \n", ret);
		return ret;
	}

	
	return 0;
}

//显示老师
int ModifyTeacher(char *pfileName, Teacher *pTe)
{
	return 0;
}
void mainxxx()
{
	system("pause");
}