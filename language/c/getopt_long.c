#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <getopt.h>

static struct option long_options[] = {
	{"config", required_argument, 0, 0},
	{"group", required_argument, 0, 0},
	{"help", no_argument, 0, 'c'},
	{0, 0, 0, 0}
};

int main(int argc, char *argv[]) {
	
	int option_index = 0;
	int rec;
	while ((rec = getopt_long(argc, argv, "cgh:", long_options, &option_index)) != -1) {
	
		switch (rec) {
		
			case 'c':
				printf("select c\n");
				break;
			case 'g':
				printf("ggggggg\n");
				break;
			case 'h':
				printf("%s\n", optarg);
				break;
		}
	}

	return 0;
}




