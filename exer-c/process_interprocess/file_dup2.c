#include <stdio.h>
#include <errno.h>
#include <unistd.h>

/**
 * build this on Unix system or Cygwin (for fork())
 */

int main(int argc, char *argv[])
{
	char *phrase = argv[1];
	char *feeds[] = {
		"https://www.smh.com.au/rss/world.xml",
		"https://www.smh.com.au/rss/technology.xml"};

	FILE *f = fopen("stories.txt", "w"); // open file for writing.
	if (!f)
	{
		fprintf(stderr, "Can't open stories.txt : %s\n", strerror(errno));
		return 1;
	}

	pid_t pid = fork();

	if (pid == -1)
	{
		fprintf(stderr, "Cannot fork process : %s\n", strerror(errno));
		return 1;
	}

	if (!pid)
	{
		if (dup2(fileno(f), 1) < 0) // this points file-descriptor #1 to the stories.txt file.
		{
			fprintf(stderr, "Can't redirect Standard Oupput : %s\n", strerror(errno));
			return 1;
		}
		if (execle("python", "python", "./rssgossip.py", phrase, NULL, feeds) == -1)
		{
			fprintf(stderr, "Cannot run script : %s\n", strerror(errno));
			return 1;
		}
	}

	return 0;
}