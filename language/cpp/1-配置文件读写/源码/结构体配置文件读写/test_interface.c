#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "cfg_op.h"
#include "myop.h"


void main_menu()
{
	printf("\n1 Test AddTeacher(���Ա�����ʦ��Ϣ)	");
	printf("\n2 Test ModifyTeacher(������ʾ��ʦ��Ϣ)	");
	printf("\n0 exit(0)        (�����˳�)	    ");
	printf("\nplease enter your choice:[1/2/0]: ");
	return;
}

int  Test_AddTeacher()
{
	int		rv = 0; 
	char *pfileName = "c:/teacherinfo.ini";
	Teacher t1;
	memset(&t1, 0, sizeof(Teacher));
	t1.infoId = 1;
	t1.age = 11;
	strcpy(t1.name, "name");
	strcpy(t1.studentInfo, "s1,s2,s3,");
	
	//�����ʦ
	rv = AddTeacher(pfileName, &t1);
	if (rv != 0)
	{
		printf("fucn AddTeacher() err:%d \n", rv);
		return rv;
	}

	
	printf("��д�������̵Ʋ���ͨ��\n");

End:
	return rv;
	
}

int  Test_ModifyTeache()
{
	
	int rv;
	//��ʾ��ʦ
	//int ModifyTeacher(char *pfileName, Teacher *pTe);
	printf("\n��д�������̵Ʋ���ͨ��\n");

End:
	return rv;
	
}

int  main()
{
	int		rv = 0; 
	int		choice = 0;

	for(;;)
	{
		main_menu();
	    scanf("%d", &choice);
        switch (choice)
		{
		case 1:
			Test_AddTeacher();   break;
		case 2:
			Test_ModifyTeache();   break;
		case 0:
			exit(0);
		default:
			exit(0);
		}
	}

End:
	return rv;
	getchar();
}


