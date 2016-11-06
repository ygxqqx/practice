#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

	
	int ret = unlink("/home/ygxqqx/cpp/simple_parse");
	printf("%d\n", ret);
	return 0;
}
