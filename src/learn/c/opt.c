#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char* program_name;

void usage(int status)
{
	if (status != 0)
		fprintf(stderr, "Please recheck your arguments for %s.\n", program_name);
	else
		printf("heh\n");
	exit(status == 0 ? EXIT_SUCCESS : EXIT_FAILURE);
}

int main(int argc, char** argv)
{
	char c;
	program_name = argv[0];
	while ((c = getopt(argc, argv, ":a:b:c")) != -1) {
		switch(c){
		case 0:
			break;
		case 'a':
		case 'b':
			fprintf(stdout, "Arg: %s\n", optarg);
			break;
		case 'c':
			puts("Hello World!");
			break;
		case '?':
			puts("Invalid command!");
			break;
		default:
			usage(EXIT_FAILURE);
		}
	}

	printf("arcg -> %d\noptind -> %d\n", argc, optind);

	return 0;
}
