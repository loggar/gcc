#include <stdio.h>
#include <errno.h>
#include <unistd.h>

void error(char *msg)
{
	fprintf(stderr, "%s: %s\n", msg, strerror(errno));
	exit(1);
}

void open_url(char *url)
{
	char launch[255];

	// windows
	sprintf(launch, "cmd /c start %s", url);
	system(launch);

	// Linux
	sprintf(launch, "x-www-browser '%s' &", url);
	system(launch);

	// Mac
	sprintf(launch, "open '%s'", url);
	system(launch);
}

int main(int argc, char *argv[])
{
	const char *PYTHON = "python";
	const char *SCRIPT = "./rssgossip.py";

	char *phrase = argv[1];
	char *vars[] = {
		"https://www.smh.com.au/rss/world.xml",
		"https://www.smh.com.au/rss/technology.xml"};

	int fd[2];
	if (pipe(fd) == -1)
	{
		error("can't create the pipe");
	}

	pid_t pid = fork();
	if (pid == -1)
	{
		error("can't fork process");
	}

	// child process
	if (!pid)
	{
		dup2(fd[1], 1); // set the standard output to the write end of the pipe
		close(fd[0]);   // the child won't read from the pipe, so we'll close the read end

		if (execle(PYTHON, PYTHON, SCRIPT, phrase, NULL, vars) == -1)
		{
			error("Can't run script");
		}
	}

	// parent process
	dup2(fd[0], 0); // redirect the standard input to the read end of the pipe
	close(fd[1]);   // close the write end of the pipe, because the parent won't write to it

	char line[255];
	while (fgets(line, 255, stdin))
	{
		if (line[0] == '\t')
		{
			open_url(line + 1);
		}
	}

	return 0;
}