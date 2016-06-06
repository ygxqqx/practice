#include <stdio.h>
#include <netdb.h>
#include <sys/utsname.h>
void main() {
	struct protoent *ent;
	struct utsname name;
	ent=getprotobyname("tcp");
	printf("%d\n",ent->p_proto);
	
	uname(&name);
	printf("%s\n",name.machine);
	printf("%s\n",name.nodename);
	printf("%s\n",name.sysname);
	printf("%s\n",name.domainname);
	return 0;
}
