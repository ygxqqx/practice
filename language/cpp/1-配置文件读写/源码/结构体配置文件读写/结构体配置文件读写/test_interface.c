#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "cfg_op.h"


#define  DB_sid			"oracle_sid"
#define  DB_User		"appuser"
#define  DB_PassWord	"appuser"
#define	 CFG_FILENAME	"c:/cfg.ini"

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


	printf("��д�������̵Ʋ���ͨ��\n");

End:
	return rv;
	
}

int  Test_ModifyTeache()
{
	
	int rv;
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


