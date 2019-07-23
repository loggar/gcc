#include <stdio.h>
#include <unistd.h>

/**
 * $ process_args_options Anchovies
 * $ process_args_options Anchovies Pineapple
 * $ process_args_options -d now Anchovies Pineapple
 * $ process_args_options -d now -t Anchovies Pineapple
 * $ process_args_options -d // option required!
 */
int main(int argc, char *argv[])
{
	char *delivery = "";
	int thick = 0;
	int count = 0;
	char ch;
	while ((ch = getopt(argc, argv, "d:t")) != EOF)  // option 'd' and 't' are valid, option 'd' requires an argument.
		switch (ch)
		{
		case 'd':
			delivery = optarg;
			break;
		case 't':
			thick = 1;
			break;
		default:
			fprintf(stderr, "Unknown option: '%s'\n", optarg);
			return 1;
		}
	argc -= optind;
	argv += optind;
	if (thick)
		puts("Thick crust.");
	if (delivery[0])
		printf("To be delivered %s.\n", delivery);
	puts("Ingredients:");
	for (count = 0; count < argc; count++)
		puts(argv[count]);
	return 0;
}