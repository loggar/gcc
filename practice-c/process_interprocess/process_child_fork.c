#include <stdio.h>
#include <errno.h>
#include <unistd.h>

/**
 * build this on Unix system or Cygwin (for fork())
 */

int main(int argc, char *argv[])
{
	char *feeds[] = {
		"https://www.smh.com.au/rss/world.xml",
		"https://www.smh.com.au/rss/technology.xml"};

	int times = 2;
	char *phrase = argv[1];
	int i;

	for (i = 0; i < times; i++)
	{
		char var[255];
		sprintf(var, "RSS_FEED=%s", feeds[i]);
		char *vars[] = {var, NULL};

		pid_t pid = fork();

		if (pid == -1)
		{
			fprintf(stderr, "Cannot fork process : %s\n", strerror(errno));
			return 1;
		}

		if (!pid)
		{
			if (execle("python", "python", "./rssgossip.py", phrase, NULL, vars) == -1)
			{
				fprintf(stderr, "Cannot run script : %s\n", strerror(errno));
				return 1;
			}
		}
	}
	return 0;
}