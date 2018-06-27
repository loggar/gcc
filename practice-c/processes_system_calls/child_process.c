#include <stdio.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char *argv[])
{
	char *feeds[] = {
		"http://www.cnn.com/rss/celebs.xml",
		"http://some_rss_feed.xml"};

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
			if (execle("/usr/bin/python", "/usr/bin/python", "./rssgossip.py", phrase, NULL, vars) == -1)
			{
				fprintf(stderr, "Cannot run script : %s\n", strerror(errno));
				return 1;
			}
		}
	}
	return 0;
}