#include <stdio.h>
#include <netdb.h>
main()
{
	struct hostent *ent;
	/*�������������ݿ��ļ�*/
	sethostent(1);
	while(1)
	{
		ent=gethostent();
		if(ent==0) break;
		
		printf("������:%s\t",ent->h_name);
		printf("IP��ַ:%hhu.%hhu.%hhu.%hhu\t",
				ent->h_addr[0],
				ent->h_addr[1],
				ent->h_addr[2],
				ent->h_addr[3]);
		printf("����:%s\n",ent->h_aliases[0]);
	}
	endhostent();
}
