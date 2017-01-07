#include "./tiny/csapp.h"

#define QUERY_STRING "?13232&11111"


int main(void) {

	char *buf, *p;
	char arg1[1024], arg2[1024], content[1024];
	int n1 = 0, n2 = 0;
	if ((buf = getenv("QUERY_STRING")) != NULL) {
		
		p = strchr(buf, '&');
		*p = '\0';
		strcpy(arg1, buf);
		strcpy(arg2, p + 1);
		n1 = atoi(arg1);
		n2 = atoi(arg2);
	
		printf("%s\n", buf);
		printf("%s\n", arg1);
		printf("%s\n", arg2);
		printf("%d\n", n1);
		printf("%d\n", n2);
	}
	
	return 0;
}



