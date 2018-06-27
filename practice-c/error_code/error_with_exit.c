#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <error.h>
#include <string.h>

void error(char *msg)
{
	fprintf(stderr, "%s: %s\n", msg, strerror(errno));
}

int main()
{
	pid_t pid = fork();
	if (pid == -1)
	{
		error("Can't fork process");
	}
}